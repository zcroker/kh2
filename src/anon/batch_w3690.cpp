/* 002231b8 (w3690): hand-written VU0 packet builder (VF regs preloaded by 00222f88, lb v0 scratch, nops,
   trapping add). The VU0 stretch stays one asm block; its end also loads the 128 clip-flag constant into t6
   (li $14,128), so gcc's p+608 lands in t7 and dbr puts it in the beq delay slot like the original.
   Asm share 132/142 instructions. */
#include "../common/types.h"
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Req {
    V4 a;           /* 00 position */
    V4 col;         /* 10 colour */
    void* p32;      /* 20 */
    u8* pkt;        /* 24 packet write pointer */
    void* p40;      /* 28 */
    s32 w44;        /* 2c */
    V4 b;           /* 30 */
};
extern "C" {

s32 func_002231b8(Req* r)
{
    register u8* p asm("$15") = r->pkt;
    register s32 clip asm("$13");
    register s32 ret asm("$2");
    register s32 k asm("$14");
    V4 tmp;
    asm volatile(".set noreorder\n"
        "lqc2 $vf8,0(%4)\n"
        "vmulax.wxyz ACC,$vf4,$vf8x\n"
        "vmadday.wxyz ACC,$vf5,$vf8y\n"
        "vmaddaz.wxyz ACC,$vf6,$vf8z\n"
        "vmaddw.wxyz $vf12,$vf7,$vf8w\n"
        "vdiv Q,$vf0w,$vf12w\n"
        "vwaitq\n"
        "vmulq.xyz $vf12,$vf12,Q\n"
        "vmulq.y $vf15,$vf15,Q\n"
        "vmulq.xy $vf16,$vf16,Q\n"
        "vmulq.x $vf17,$vf17,Q\n"
        "vmove.wz $vf10,$vf12\n"
        "vsub.x $vf10,$vf12,$vf17\n"
        "vsub.y $vf10,$vf12,$vf15\n"
        "vadd.x $vf13,$vf17,$vf17\n"
        "vadd.y $vf13,$vf15,$vf15\n"
        "vsub.xy $vf13,$vf28,$vf13\n"
        "ctc2.ni $0,$vi16\n"
        "vsub.wxy $vf0,$vf10,$vf0\n"
        "vsub.xy $vf0,$vf13,$vf10\n"
        "vnop\n"
        "vnop\n"
        "vnop\n"
        "vnop\n"
        "vnop\n"
        "cfc2.ni $13,$vi16\n"
        "andi $13,$13,0x80\n"
        "bnez $13,1f\n"
        "nop\n"
        "vnop\n"
        "vmulq.xy $vf22,$vf18,Q\n"
        "vmulq.xy $vf23,$vf19,Q\n"
        "vmulq.xy $vf31,$vf1,Q\n"
        "vadd.xy $vf11,$vf11,$vf31\n"
        "lqc2 $vf31,16(%4)\n"
        "vftoi0.wxyz $vf31,$vf31\n"
        "sqc2 $vf31,112(%5)\n"
        "lb $2,60(%4)\n"
        "andi $2,$2,0x1\n"
        "bnez $2,2f\n"
        "nop\n"
        "nop\n"
        "vsub.w $vf31,$vf0,$vf0\n"
        "2:\n"
        "sqc2 $vf25,0(%5)\n"
        "sqc2 $vf27,16(%5)\n"
        "sqc2 $vf29,32(%5)\n"
        "sqc2 $vf21,48(%5)\n"
        "sqc2 $vf14,64(%5)\n"
        "sqc2 $vf20,80(%5)\n"
        "sqc2 $vf31,160(%5)\n"
        "sqc2 $vf31,208(%5)\n"
        "sqc2 $vf31,256(%5)\n"
        "sqc2 $vf31,304(%5)\n"
        "sqc2 $vf31,352(%5)\n"
        "sqc2 $vf31,400(%5)\n"
        "sqc2 $vf31,448(%5)\n"
        "sqc2 $vf31,496(%5)\n"
        "sqc2 $vf31,544(%5)\n"
        "sqc2 $vf9,576(%5)\n"
        "sqc2 $vf3,592(%5)\n"
        "vftoi4.xyz $vf30,$vf12\n"
        "sqc2 $vf30,128(%5)\n"
        "vsub.xy $vf30,$vf12,$vf11\n"
        "vmulx.xy $vf26,$vf30,$vf24x\n"
        "sqc2 $vf26,96(%5)\n"
        "vadd.xy $vf10,$vf12,$vf15\n"
        "vftoi4.xyz $vf30,$vf10\n"
        "sqc2 $vf30,176(%5)\n"
        "sqc2 $vf30,560(%5)\n"
        "vsub.xy $vf30,$vf10,$vf11\n"
        "vadd.y $vf30,$vf30,$vf22\n"
        "vmulx.xy $vf26,$vf30,$vf24x\n"
        "sqc2 $vf26,144(%5)\n"
        "sqc2 $vf26,528(%5)\n"
        "vadd.xy $vf10,$vf12,$vf16\n"
        "vftoi4.xyz $vf30,$vf10\n"
        "sqc2 $vf30,224(%5)\n"
        "vsub.xy $vf30,$vf10,$vf11\n"
        "vadd.xy $vf30,$vf30,$vf23\n"
        "vmulx.xy $vf26,$vf30,$vf24x\n"
        "sqc2 $vf26,192(%5)\n"
        "vadd.xy $vf10,$vf12,$vf17\n"
        "vftoi4.xyz $vf30,$vf10\n"
        "sqc2 $vf30,272(%5)\n"
        "vsub.xy $vf30,$vf10,$vf11\n"
        "vadd.x $vf30,$vf30,$vf22\n"
        "vmulx.xy $vf26,$vf30,$vf24x\n"
        "sqc2 $vf26,240(%5)\n"
        "vadd.x $vf10,$vf12,$vf16\n"
        "vsub.y $vf10,$vf12,$vf16\n"
        "vftoi4.xyz $vf30,$vf10\n"
        "sqc2 $vf30,320(%5)\n"
        "vsub.xy $vf30,$vf10,$vf11\n"
        "vadd.x $vf30,$vf30,$vf23\n"
        "vsub.y $vf30,$vf30,$vf23\n"
        "vmulx.xy $vf26,$vf30,$vf24x\n"
        "sqc2 $vf26,288(%5)\n"
        "vsub.xy $vf10,$vf12,$vf15\n"
        "vftoi4.xyz $vf30,$vf10\n"
        "sqc2 $vf30,368(%5)\n"
        "vsub.xy $vf30,$vf10,$vf11\n"
        "vsub.y $vf30,$vf30,$vf22\n"
        "vmulx.xy $vf26,$vf30,$vf24x\n"
        "sqc2 $vf26,336(%5)\n"
        "vsub.xy $vf10,$vf12,$vf16\n"
        "vftoi4.xyz $vf30,$vf10\n"
        "sqc2 $vf30,416(%5)\n"
        "vsub.xy $vf30,$vf10,$vf11\n"
        "vsub.xy $vf30,$vf30,$vf23\n"
        "vmulx.xy $vf26,$vf30,$vf24x\n"
        "sqc2 $vf26,384(%5)\n"
        "vsub.xy $vf10,$vf12,$vf17\n"
        "vftoi4.xyz $vf30,$vf10\n"
        "sqc2 $vf30,464(%5)\n"
        "vsub.xy $vf30,$vf10,$vf11\n"
        "vsub.x $vf30,$vf30,$vf22\n"
        "vmulx.xy $vf26,$vf30,$vf24x\n"
        "sqc2 $vf26,432(%5)\n"
        "vsub.x $vf10,$vf12,$vf16\n"
        "vadd.y $vf10,$vf12,$vf16\n"
        "vftoi4.xyz $vf30,$vf10\n"
        "sqc2 $vf30,512(%5)\n"
        "vsub.xy $vf30,$vf10,$vf11\n"
        "vsub.x $vf30,$vf30,$vf23\n"
        "vadd.y $vf30,$vf30,$vf23\n"
        "vmulx.xy $vf26,$vf30,$vf24x\n"
        "sqc2 $vf26,480(%5)\n"
        "sqc2 $vf12,%1\n"
        "add $13,$0,$0\n"
        "1:\n"
        "li $2,1\n"
        "li $14,128\n"
        ".set reorder"
        : "=r"(clip), "=m"(tmp), "=r"(ret), "=r"(k) : "r"(r), "r"(p) : "memory");
    if (clip != k) {
        p += 608;
        r->pkt = p;
        r->w44 = ((s32*)&tmp)[2];
    } else {
        ret = 0;
    }
    return ret;
}


}
