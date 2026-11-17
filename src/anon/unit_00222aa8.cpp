// Linked unit 0x00222aa8-0x00224780.
#include "../common/types.h"
#include <stdarg.h>
asm("fptodp = func_00313b80");
typedef unsigned int u128 __attribute__((mode(TI)));
typedef f32 FMTX[4][4] __attribute__((aligned(16)));

// 00222aa8 (was src/anon/batch_w2353.cpp)
namespace n00222aa8 {
typedef struct { s8 v[32]; } __attribute__((aligned(16))) Swz222aa8;
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V222aa8;
extern Swz222aa8 D_0035da40 asm("D_0035da40");
extern s8 D_0035da60[] asm("D_0035da60");
void* func_0020eaf8(s32) asm("func_0020eaf8");
void func_0020ebd8(s32) asm("func_0020ebd8");
void sceVu0SubVector(V222aa8*, V222aa8*, V222aa8*) asm("sceVu0SubVector");
void sceVu0DivVector(V222aa8*, V222aa8*, f32) asm("sceVu0DivVector");
void sceVu0AddVector(V222aa8*, V222aa8*, V222aa8*) asm("sceVu0AddVector");
u32 __fixunssfsi(f32) asm("__fixunssfsi");
/*TARGET 00222aa8*/
/* __fixunssfsi in the game image */
void func_00222aa8(u32 colA, u32 colB, u32* clut, f32 pos) asm("func_00222aa8");
/* __fixunssfsi in the game image */
void func_00222aa8(u32 colA, u32 colB, u32* clut, f32 pos)
{
    Swz222aa8* sw = (Swz222aa8*)func_0020eaf8(32);
    s32 n, i;
    u32* p;
    f32 len;
    V222aa8 d, c;
    ((u128*)sw)[0] = ((u128*)&D_0035da40)[0];
    ((u128*)sw)[1] = ((u128*)&D_0035da40)[1];
    n = pos;
    if (n < 0) {
        if (n < -256) n = -256;
        n += 256;
        p = clut + (n & 0xe0) + D_0035da60[n & 31];
        for (i = n; i < 256; i++) {
            *p = colA;
            p += sw->v[i & 31];
        }
        len = n;
        p = clut;
        i = 0;
    } else {
        if (!(n < 256)) n = 255;
        p = clut;
        for (i = 0; i < n; i++) {
            *p = colB;
            p += sw->v[i & 31];
        }
        len = 256.0f - n;
        n = 256;
    }
    c.x = ((u8*)&colB)[0];
    c.y = ((u8*)&colB)[1];
    c.z = ((u8*)&colB)[2];
    c.w = ((u8*)&colB)[3];
    d.x = ((u8*)&colA)[0];
    d.y = ((u8*)&colA)[1];
    d.z = ((u8*)&colA)[2];
    d.w = ((u8*)&colA)[3];
    sceVu0SubVector(&d, &d, &c);
    sceVu0DivVector(&d, &d, len);
    for (; i < n; i++) {
        *p = (__fixunssfsi(c.w) << 24 | __fixunssfsi(c.y) << 8) | (__fixunssfsi(c.x) | __fixunssfsi(c.z) << 16);
        sceVu0AddVector(&c, &c, &d);
        p += sw->v[i & 31];
    }
    func_0020ebd8(32);
}
}  // namespace n00222aa8

// 00222d40 (was src/anon/batch_w2352_nsa.cpp)
namespace n00222d40 {
/* ---- 00222d40 ---- */

struct Ent24 { u8 pad[0x1c]; u32* data; s32 f20; };
struct Tbl { u8 pad[0x10]; Ent24* ents; };
struct Ctx { u8 pad[0x10]; u8 a[0x40]; u8 b[0x40]; s32 f90; s32 f94; };
struct Param {
    u32 flags;      /* 00 */
    void* p04;      /* 04 */
    u16 h08;        /* 08 */
    u8 b0a;         /* 0a */
    u8 pad0b;
    s16 h0c;        /* 0c */
    s16 h0e;        /* 0e */
    s32 x;          /* 10 */
    s32 y;          /* 14 */
    u8 c[4];        /* 18 */
    s32 f1c;        /* 1c */
    void* p20;      /* 20 */
    void* p24;      /* 24 */
    void* p28;      /* 28 */
    void* p2c;      /* 2c */
    void* p30;      /* 30 */
    s32 prev;       /* 34 */
    s32 f38;        /* 38 */
    s32 f3c;        /* 3c */
    s32 f40;        /* 40 */
    s32 f44;        /* 44 */
    u8 pad48[0x18];
};
extern Tbl* D_01d9e6e4 asm("D_01d9e6e4");
extern Ctx* D_01d9e6e8 asm("D_01d9e6e8");
extern u8 D_01d9e840[] asm("D_01d9e840");
extern u8 D_01d9e980[] asm("D_01d9e980");
extern u8 D_01d9e9c0[] asm("D_01d9e9c0");
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
extern u8 D_01d9eac0[] asm("D_01d9eac0");
void sceVu0MulMatrix(void*, void*, void*) asm("sceVu0MulMatrix");
s32 func_0020f1e0(u32*, Param*, s32) asm("func_0020f1e0");
/*TARGET 00222d40*/
/* 00222d40: builds a draw parameter block for sprite idx (colour col, position x/y, flags fl) and submits it. */
void func_00222d40(s32 idx, u16* col, s32 z, s32 x, s32 y, u8 fl, s32 extra) asm("func_00222d40");
/* 00222d40: builds a draw parameter block for sprite idx (colour col, position x/y, flags fl) and submits it. */
void func_00222d40(s32 idx, u16* col, s32 z, s32 x, s32 y, u8 fl, s32 extra)
{
    Ent24* e;
    u32* d;
    u8 buf[0x40];
    Param p;
    if (idx == 0xffff) return;
    e = &D_01d9e6e4->ents[idx];
    d = e->data;
    p.flags = 0;
    if (fl & 2) {
        p.flags = 4;
        if ((*d & 1) == 0) p.flags |= 8;
    } else {
        if ((bool)(fl & 1)) p.flags = 0x80;
        if ((*d & 1) == 0) p.flags |= 8;
    }
    if ((*d & 2) == 0) p.flags |= 0x10;
    if (fl & 4) p.flags |= 0x200;
    if (fl & 8) p.flags |= 0x100;
    if (fl & 0x10) {
        p.flags |= 0x2000;
        p.p30 = buf;
        sceVu0MulMatrix(buf, D_01d9e840, D_01d9e6e8->a);
    }
    p.f44 = (fl & 0x20) ? extra : 0;
    /* These two go through casts: as field stores gcc lets the global loads below move above them. */
    *(u16*)((u8*)&p + 8) = ((u16*)d)[0x16 / 2];
    *(s32*)((u8*)&p + 0x1c) = 0;
    p.f38 = D_01d9e6e8->f90;
    p.f3c = D_01d9e6e8->f94;
    p.h0e = z;
    p.p04 = D_01d9eac0;
    p.x = x << 16;
    p.y = y << 16;
    p.c[0] = col[0] >> 7;
    p.c[1] = col[1] >> 7;
    p.c[2] = col[2] >> 7;
    p.c[3] = col[3] >> 7;
    p.p20 = D_01d9e6e8->b;
    p.p24 = D_01d9e9c0;
    p.p28 = D_01d9e980;
    p.p2c = D_01d9e6e8->a;
    p.prev = D_01d9eaa4;
    p.h0c = 0;
    p.f40 = 0;
    p.b0a = 0;
    D_01d9eaa4 = func_0020f1e0(d, &p, e->f20);
}
}  // namespace n00222d40

// 00222f88 (was src/anon/batch_w2042_nsa.cpp)
namespace n00222f88 {
// ---- 00222f88: GS packet setup, then VU0 register preload (VU0 macro asm) ----
struct W2042A { u8 p0[0x20]; void* m20; u8 p24[4]; void* m28; u8 p2c[0x10]; s32 m3c; u64 m40; u64 m48; u16 m50; u16 p52; u16 m54; };
struct W2042P { u64 a0, a8, a10, a18, a20, a28, a30, a38, a40, a48, a50, a58, a60, a68; s32 b70, b74; u64 a78; s32 b80, b84; };
extern s32 D_01da8bf0 asm("D_01da8bf0");
extern s32 D_01da8bf4 asm("D_01da8bf4");
void* func_0020eaf8(s32) asm("func_0020eaf8");
void func_0020ebd8(s32) asm("func_0020ebd8");
/*TARGET 00222f88*/
void func_00222f88(W2042A* a) asm("func_00222f88");
void func_00222f88(W2042A* a) {
    W2042P* p = (W2042P*)func_0020eaf8(0x90);
    p->a0 = (1ULL << 62) | 1;
    p->a8 = 0xeeee;
    p->a10 = (a->m40 & ~(0xffULL << 26)) | (0x55ULL << 27);
    p->a18 = 6;
    if (a->m3c & 4) p->a20 = 0x31001; else p->a20 = 0x71001;
    p->a28 = 0x47;
    p->a30 = 0x44;
    p->a38 = 0x42;
    u64 v = a->m48;
    p->a40 = ((v & 0x7ff) << 4) | (((v >> 32) & 0x7ff) << 24) | ((((v >> 16) & 0x7ff) - 1) << 14) | 0xa | ((((v >> 48) & 0x7ff) - 1) << 34);
    p->a48 = 8;
    p->a50 = (0xc0bbULL << 46) | 0xa;
    p->a58 = 0x412;
    p->a60 = (1ULL << 60) | 0x8001;
    p->a68 = 0xe;
    p->b70 = D_01da8bf0;
    p->b74 = D_01da8bf4;
    p->a78 = 0x47;
    u64 x = a->m50; p->b80 = (s32)(x - 8);
    u64 y = a->m54; p->b84 = (s32)(y - 8);
    void* q28 = a->m28;
    void* q20 = a->m20;
    asm volatile(
        "lqc2 $vf25,0(%0)\n\tlqc2 $vf27,16(%0)\n\tlqc2 $vf29,32(%0)\n\tlqc2 $vf21,48(%0)\n\t"
        "lqc2 $vf14,64(%0)\n\tlqc2 $vf20,80(%0)\n\tlqc2 $vf9,96(%0)\n\tlqc2 $vf3,112(%0)\n\t"
        "lqc2 $vf2,0(%1)\n\tlqc2 $vf31,16(%1)\n\tvadd.y $vf2,$vf0,$vf31\n\t"
        "lui $2,0x3a80\n\tqmtc2 $2,$vf24\n\t"
        "lqc2 $vf4,0(%2)\n\tlqc2 $vf5,16(%2)\n\tlqc2 $vf6,32(%2)\n\tlqc2 $vf7,48(%2)\n\t"
        "lqc2 $vf11,128(%0)\n\tvitof4.wxyz $vf11,$vf11\n\t"
        "lqc2 $vf31,80(%3)\n\tvmove.x $vf15,$vf0\n\tvaddw.y $vf15,$vf0,$vf31w\n\tvaddz.x $vf17,$vf0,$vf31z\n\tvmove.y $vf17,$vf0\n\t"
        "lui $2,0x3f35\n\tori $2,$2,0x4f3\n\tdsll $2,$2,0x10\n\tori $2,$2,0x3f35\n\tdsll $2,$2,0x10\n\tori $2,$2,0x4f3\n\t"
        "qmtc2 $2,$vf16\n\tvmul.xy $vf16,$vf16,$vf2\n\tlqc2 $vf1,48(%3)\n\tvmul.xy $vf1,$vf2,$vf1\n\t"
        "vmulz.xy $vf18,$vf2,$vf1z\n\tvmulz.xy $vf19,$vf16,$vf1z\n\tvmul.x $vf16,$vf16,$vf17\n\tvmul.y $vf16,$vf16,$vf15\n\t"
        "vmul.y $vf15,$vf15,$vf2\n\tvmul.x $vf17,$vf17,$vf2\n\t"
        "lui $2,0x4580\n\tqmtc2 $2,$vf28\n\tvaddx.y $vf28,$vf0,$vf28x\n\tvaddw.z $vf26,$vf0,$vf0w\n\tvsubw.w $vf30,$vf0,$vf0w"
        : : "r"(p), "r"(q20), "r"(q28), "r"(a) : "$2", "memory");
    func_0020ebd8(0x90);
}
}  // namespace n00222f88

// 002231b8 (was src/anon/batch_w3690.cpp)
namespace n002231b8 {
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
/*TARGET 002231b8*/
s32 func_002231b8(Req* r) asm("func_002231b8");
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
}  // namespace n002231b8

// .rodata strings 0x370bd8-0x370c98 (debug print formats; read below as extern D_)
extern const u32 R_00370bd8[8] asm("D_00370bd8") __attribute__((aligned(4))) = { 0x41707070, 0x72657373, 0x6e6f6974, 0x69616620, 0x3a64656c, 0xa732520, 0x0, 0x0 };
extern const u32 R_00370bf8[6] asm("D_00370bf8") __attribute__((aligned(4))) = { 0x46202020, 0x20656c69, 0x202c7325, 0x656e694c, 0xa752520, 0x0 };
extern const u32 R_00370c10[4] asm("D_00370c10") __attribute__((aligned(4))) = { 0x22202020, 0xa227325, 0x0, 0x0 };
extern const u32 R_00370c20[18] asm("D_00370c20") __attribute__((aligned(4))) = { 0x3d207325, 0x25207b0a, 0x66252066, 0x20662520, 0x7d206625, 0x25207b0a, 0x66252066, 0x20662520, 0x7d206625, 0x25207b0a, 0x66252066, 0x20662520, 0x7d206625, 0x25207b0a, 0x66252066, 0x20662520, 0x7d206625, 0xa0a };
extern const u32 R_00370c68[6] asm("D_00370c68") __attribute__((aligned(4))) = { 0x3d207325, 0x25202820, 0x66252066, 0x20662520, 0x29206625, 0xa };
extern const u32 R_00370c80[6] asm("D_00370c80") __attribute__((aligned(4))) = { 0x3d207325, 0x25202820, 0x64252064, 0x20642520, 0x29206425, 0xa };

// 002233f0 (was src/anon/batch_w31.cpp)
namespace n002233f0 {
extern char D_00370bd8[] asm("D_00370bd8");
extern char D_00370bf8[] asm("D_00370bf8");
void func_002fdfc8(const char*, ...) asm("func_002fdfc8");
/*TARGET 002233f0*/
// 0x001e2998: definition moved into src/anon/unit_001e0cb8.cpp

// Print two messages and trap.
void func_002233f0(u32 a, u32 b, u32 c) asm("func_002233f0");
// 0x001e2998: definition moved into src/anon/unit_001e0cb8.cpp

// Print two messages and trap.
void func_002233f0(u32 a, u32 b, u32 c) {
    func_002fdfc8(D_00370bd8, a);  // device_vprintf_va
    func_002fdfc8(D_00370bf8, b, c);  // device_vprintf_va
    asm volatile("break");
}
}  // namespace n002233f0

// 00223448 (was src/anon/batch_w41.cpp)
namespace n00223448 {
// 0x001e3898: definition moved into src/anon/unit_001e0cb8.cpp

void func_002fdfc8(const char*, ...) asm("func_002fdfc8");
// device_vprintf_va
extern char D_00370bd8[] asm("D_00370bd8");
extern char D_00370bf8[] asm("D_00370bf8");
extern char D_00370c10[] asm("D_00370c10");
/*TARGET 00223448*/
void func_00223448(u32 a, u32 b, u32 c, u32 d) asm("func_00223448");
void func_00223448(u32 a, u32 b, u32 c, u32 d) {
    func_002fdfc8(D_00370bd8, a);  // device_vprintf_va
    func_002fdfc8(D_00370bf8, b, c);  // device_vprintf_va
    func_002fdfc8(D_00370c10, d);  // device_vprintf_va
    asm volatile("break");
}
}  // namespace n00223448

// 002234c0 (was src/anon/batch_w100.cpp)
namespace n002234c0 {
extern char D_00370c20[] asm("D_00370c20");
s32 func_002fdfc8(const char*, ...) asm("func_002fdfc8");
/*TARGET 002234c0*/
// device_vprintf_va
void func_002234c0(const char* name, f32* m) asm("func_002234c0");
// device_vprintf_va
void func_002234c0(const char* name, f32* m) {
    func_002fdfc8(D_00370c20, name, m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8], m[9], m[10], m[11], m[12], m[13], m[14], m[15]);  // device_vprintf_va
}
}  // namespace n002234c0

// 00223608 (was src/anon/batch_w50.cpp)
namespace n00223608 {
double func_00313b80(f32) asm("func_00313b80");
// float_to_double
void func_002fdfc8(const char*, u32, double, double, double, double) asm("func_002fdfc8");
// device_vprintf_va
extern const char D_00370c68[] asm("D_00370c68");
/*TARGET 00223608*/
// Debug print of a vec4 (floats promoted through the soft-double helper).
void func_00223608(u32 x, f32* v) asm("func_00223608");
// Debug print of a vec4 (floats promoted through the soft-double helper).
void func_00223608(u32 x, f32* v) {
    func_002fdfc8(D_00370c68, x, func_00313b80(v[0]), func_00313b80(v[1]), func_00313b80(v[2]), func_00313b80(v[3]));  // device_vprintf_va
}
}  // namespace n00223608

// 00223698: gap (unwritten before): debug print of an int vec4
namespace n00223698 {
s32 func_002fdfc8(const char*, ...) asm("func_002fdfc8");
extern char D_00370c80[] asm("D_00370c80");
void func_00223698(const char* name, s32* v) asm("func_00223698");
void func_00223698(const char* name, s32* v) {
    func_002fdfc8(D_00370c80, name, v[0], v[1], v[2], v[3]);
}
}  // namespace n00223698

// 002236d0 (was src/anon/batch_w2357_nsa.cpp)
namespace n002236d0 {
// Shared render-work types (same layout as batch_w1674_nsa.cpp).
struct PrtMtx { f32 m[4][4]; } __attribute__((aligned(16)));
struct PrtWork { u8 pad0[0x10]; FMTX world; u128 view[4]; };
struct PrtState { u8 pad0[0xa8]; u64 flags; };
struct PrtFrame { s16 dataOfs; s16 duration; s8 flags; u8 pad5[3]; };
struct PrtAnim { u8 pad0[6]; s16 count; u8 pad8[8]; PrtFrame frames[1]; };
struct PrtAnimRef { PrtAnim* anim; s32 x4; };
struct PrtBank { u8 pad0[0x14]; PrtAnimRef* anims; };
// Draw request (scratchpad packet header).
struct PrtReq { s32 type; s32 w4; f32 f8; s32 w12; s32 rgba[4]; u8 pad32[16]; u128 mtx[4]; };
// Shadow/marker entry: position; w is either 1.0f or 4 control bytes
// (alpha, frame, angle, scale).
struct PrtEnt { f32 pos[3]; f32 w; } __attribute__((aligned(16)));
extern PrtWork* D_01d9e6e8 asm("D_01d9e6e8");
extern PrtBank* D_01d9e6e4 asm("D_01d9e6e4");
extern PrtState* D_01d9e6e0 asm("D_01d9e6e0");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern FMTX D_01d9e730 asm("D_01d9e730");
extern FMTX D_01d9e8c0 asm("D_01d9e8c0");
extern PrtMtx D_01d9ea40 asm("D_01d9ea40");
extern f32 D_00359a20[] asm("D_00359a20");
extern PrtEnt* D_00354680 asm("D_00354680");
extern s32 D_00354684 asm("D_00354684");
void func_0021cda0(s32) asm("func_0021cda0");
PrtReq* func_0021e988(void) asm("func_0021e988");
PrtReq* func_0021e998(void) asm("func_0021e998");
PrtReq* func_0021e9a8(void) asm("func_0021e9a8");
void func_0021cdd0(u8*, PrtReq*) asm("func_0021cdd0");
void func_001e7538(void) asm("func_001e7538");
void func_0020e0a0(void) asm("func_0020e0a0");
/*TARGET 002236d0*/
// Draws animation idx once per entry of the D_00354680 list: rotated about Z
// and scaled by the entry's control bytes, then steps the entry's frame.
void func_002236d0(u32 idx, u8* rgba, u8 mode) asm("func_002236d0");
// Draws animation idx once per entry of the D_00354680 list: rotated about Z
// and scaled by the entry's control bytes, then steps the entry's frame.
void func_002236d0(u32 idx, u8* rgba, u8 mode) {
    func_0021cda0(mode);
    PrtReq* r0 = func_0021e988();
    PrtReq* r1 = func_0021e998();
    if (rgba[3] >= 255) r0->type = r1->type = 2;
    else r0->type = r1->type = 0;
    r0->f8 = r1->f8 = 0.0f;
    r0->rgba[0] = r1->rgba[0] = rgba[0];
    r0->rgba[1] = r1->rgba[1] = rgba[1];
    r0->rgba[2] = r1->rgba[2] = rgba[2];
    r0->rgba[3] = r1->rgba[3] = rgba[3];
    if (idx == 0xffff) return;
    for (s32 i = 0; i < D_00354684; i++) {
        PrtMtx m;
        u8* ctl = 0;
        u32 ang = 0;
        u32 frame = 0;
        f32 sc = 1.0f;
        PrtEnt* e = (PrtEnt*)(i * 16 + (u32)D_00354680);
        u8* w = (u8*)&e->w;
        if (e->w != sc) ctl = w;
        if (ctl && !ctl[0]) continue;
        PrtReq* r = func_0021e9a8();
        if (ctl) {
            r->rgba[3] = ctl[0];
            sc = ctl[3];
            sc *= 0.1f;
            frame = ctl[1];
            if (ctl[2]) {
                ang = ctl[2];
                ang <<= 8;
            }
        }
        if (ang == 0) {
            // 128-bit copy of the unit matrix
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(&m), "r"(&D_01d9ea40) : "$8", "$9", "$10", "$11", "memory");
        } else {
            f32 s = D_00359a20[ang >> 4];
            f32 c = D_00359a20[((ang + 0x4000) >> 4) & 0xfff];
            m.m[0][0] = c; m.m[1][0] = -s; m.m[2][0] = 0.0f; m.m[3][0] = 0.0f;
            m.m[0][1] = s; m.m[1][1] = c; m.m[2][1] = 0.0f; m.m[3][1] = 0.0f;
            m.m[0][2] = 0.0f; m.m[1][2] = 0.0f; m.m[2][2] = 1.0f; m.m[3][2] = 0.0f;
            m.m[0][3] = 0.0f; m.m[1][3] = 0.0f; m.m[2][3] = 0.0f; m.m[3][3] = 1.0f;
        }
        u32 ofs = idx * 8;
        PrtAnim* anim = ((PrtAnimRef*)((u8*)D_01d9e6e4->anims + ofs))->anim;
        PrtFrame* fr = &anim->frames[frame];
        u8* data = (u8*)anim + fr->dataOfs;
        // VU0: scale the rotation, local = A * pos, view = B * [rot | local]
        asm volatile(
            "lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
            "qmtc2 %1, $vf7\n\tvmulx.xyz $vf1, $vf1, $vf7x\n\tvmulx.xyz $vf2, $vf2, $vf7x\n\tvmulx.xyz $vf3, $vf3, $vf7x\n\t"
            "lqc2 $vf4, 0(%2)\n\tvmove.w $vf4, $vf0\n\t"
            "lqc2 $vf9, 0(%3)\n\tlqc2 $vf10, 16(%3)\n\tlqc2 $vf11, 32(%3)\n\tlqc2 $vf12, 48(%3)\n\t"
            "lqc2 $vf13, 0(%4)\n\tlqc2 $vf14, 16(%4)\n\tlqc2 $vf15, 32(%4)\n\tlqc2 $vf16, 48(%4)\n\t"
            "vmulax.wxyz ACC, $vf9, $vf4x\n\tvmadday.wxyz ACC, $vf10, $vf4y\n\tvmaddaz.wxyz ACC, $vf11, $vf4z\n\tvmaddw.wxyz $vf4, $vf12, $vf4w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf1x\n\tvmadday.wxyz ACC, $vf14, $vf1y\n\tvmaddaz.wxyz ACC, $vf15, $vf1z\n\tvmaddw.wxyz $vf1, $vf16, $vf1w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf2x\n\tvmadday.wxyz ACC, $vf14, $vf2y\n\tvmaddaz.wxyz ACC, $vf15, $vf2z\n\tvmaddw.wxyz $vf2, $vf16, $vf2w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf3x\n\tvmadday.wxyz ACC, $vf14, $vf3y\n\tvmaddaz.wxyz ACC, $vf15, $vf3z\n\tvmaddw.wxyz $vf3, $vf16, $vf3w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf4x\n\tvmadday.wxyz ACC, $vf14, $vf4y\n\tvmaddaz.wxyz ACC, $vf15, $vf4z\n\tvmaddw.wxyz $vf4, $vf16, $vf4w\n\t"
            "sqc2 $vf1, 0(%5)\n\tsqc2 $vf2, 16(%5)\n\tsqc2 $vf3, 32(%5)\n\tsqc2 $vf4, 48(%5)"
            : : "r"(&m), "r"(sc), "r"(&D_00354680[i]), "r"(D_01d9e730), "r"(D_01d9e8c0), "r"(D_01d9e6e8->view) : "memory");
        // An empty one-trip loop: the original has a basic-block boundary here
        // (the view-pointer lui after the VU0 block is not shared with the copies).
        for (s32 k = 0; k < 1; k++) ;
        r->mtx[0] = D_01d9e6e8->view[0];
        r->mtx[1] = D_01d9e6e8->view[1];
        r->mtx[2] = D_01d9e6e8->view[2];
        r->mtx[3] = D_01d9e6e8->view[3];
        func_0021cdd0(data, r);
        r->type = 10;
        if (ctl && D_01d9ea9c == 0 && (D_01d9e6e0->flags & 0xff0000ff00ULL) == 0) {
            if (++ctl[1] >= anim->count) {
                if (fr->flags & 0x80) {
                    ctl[1] = 0;
                } else {
                    ctl[0] = 0;
                    ctl[1] = 0;
                }
            }
        }
    }
    func_001e7538();
    func_0020e0a0();
}
}  // namespace n002236d0

// 00223af8 (was src/anon/batch_w3910_nsa.cpp)
namespace n00223af8 {
struct PrtWork { u8 pad0[0x10]; FMTX world; u128 view[4]; };
struct PrtState { u8 pad0[0xa8]; u64 flags; };
struct PrtFrame { s16 dataOfs; s16 duration; s8 flags; u8 pad5[3]; };
struct PrtAnim { u8 pad0[6]; s16 count; u8 pad8[8]; PrtFrame frames[1]; };
struct PrtAnimRef { PrtAnim* anim; s32 x4; };
struct PrtBank { u8 pad0[0x14]; PrtAnimRef* anims; };
// Draw request (scratchpad packet header).
struct PrtReq { s32 type; s32 w4; f32 f8; s32 w12; s32 rgba[4]; u8 pad32[16]; u128 mtx[4]; };
extern PrtWork* D_01d9e6e8 asm("D_01d9e6e8");
extern PrtBank* D_01d9e6e4 asm("D_01d9e6e4");
extern PrtState* D_01d9e6e0 asm("D_01d9e6e0");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern FMTX D_01d9e730 asm("D_01d9e730");
extern FMTX D_01d9e8c0 asm("D_01d9e8c0");
struct PrtEnt64 { u8 pad0[48]; f32 pos[3]; f32 w; } __attribute__((aligned(16)));
extern PrtEnt64* D_00354688 asm("D_00354688");
extern s32 D_0035468c asm("D_0035468c");
void func_0021cda0(s32) asm("func_0021cda0");
PrtReq* func_0021e988(void) asm("func_0021e988");
PrtReq* func_0021e998(void) asm("func_0021e998");
PrtReq* func_0021e9a8(void) asm("func_0021e9a8");
void func_0021cdd0(u8*, PrtReq*) asm("func_0021cdd0");
void func_001e7538(void) asm("func_001e7538");
void func_0020e0a0(void) asm("func_0020e0a0");
/*TARGET 00223af8*/
void func_00223af8(u32 idx, u8* rgba, u8 mode) asm("func_00223af8");
void func_00223af8(u32 idx, u8* rgba, u8 mode) {
    func_0021cda0(mode);
    PrtReq* r0 = func_0021e988();
    PrtReq* r1 = func_0021e998();
    if (rgba[3] >= 255) r0->type = r1->type = 2;
    else r0->type = r1->type = 0;
    r0->f8 = r1->f8 = 0.0f;
    r0->rgba[0] = r1->rgba[0] = rgba[0];
    r0->rgba[1] = r1->rgba[1] = rgba[1];
    r0->rgba[2] = r1->rgba[2] = rgba[2];
    r0->rgba[3] = r1->rgba[3] = rgba[3];
    if (idx == 0xffff) return;
    for (s32 i = 0; i < D_0035468c; i++) {
        u8* ctl = 0;
        f32 tenth = 0.1f;
        u32 fv = 0;
        f32 sc = 1.0f;
        u32 av = i * 64;
        PrtEnt64* e = (PrtEnt64*)(av + (u32)D_00354688);
        u8* w = (u8*)&e->w;
        if (e->w != sc) ctl = w;
        if (ctl && !ctl[0]) continue;
        PrtReq* r = func_0021e9a8();
        if (ctl) {
            r->rgba[3] = ctl[0];
            sc = ctl[3];
            fv = ctl[1];
            sc *= tenth;
        }
        u32 ofs = idx * 8;
        u32 eo = (u32)&D_00354688[i];
        { register u8* ab asm("$14") = (u8*)D_01d9e6e4->anims + ofs; av = (u32)((PrtAnimRef*)ab)->anim; }
#define anim ((PrtAnim*)av)
        fv = (u32)&anim->frames[fv];
        u8* data = (u8*)anim + ((PrtFrame*)fv)->dataOfs;
        register f32 sci asm("$14") = sc;
        asm volatile(
            "vsub.wxyz $vf4, $vf0, $vf0\n\tvadd.w $vf4, $vf4, $vf0\n\t"
            "vmr32.wxyz $vf3, $vf4\n\tvmr32.wxyz $vf2, $vf3\n\tvmr32.wxyz $vf1, $vf2\n\t"
            "qmtc2 %0, $vf7\n\tvmulx.xyz $vf1, $vf1, $vf7x\n\tvmulx.xyz $vf2, $vf2, $vf7x\n\tvmulx.xyz $vf3, $vf3, $vf7x\n\t"
            "lqc2 $vf8, 48(%1)\n\tvmove.w $vf8, $vf0\n\tvmove.wxyz $vf4, $vf8\n\t"
            "lqc2 $vf9, 0(%2)\n\tlqc2 $vf10, 16(%2)\n\tlqc2 $vf11, 32(%2)\n\tlqc2 $vf12, 48(%2)\n\t"
            "lqc2 $vf13, 0(%3)\n\tlqc2 $vf14, 16(%3)\n\tlqc2 $vf15, 32(%3)\n\tlqc2 $vf16, 48(%3)\n\t"
            "vmulax.wxyz ACC, $vf9, $vf4x\n\tvmadday.wxyz ACC, $vf10, $vf4y\n\tvmaddaz.wxyz ACC, $vf11, $vf4z\n\tvmaddw.wxyz $vf4, $vf12, $vf4w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf1x\n\tvmadday.wxyz ACC, $vf14, $vf1y\n\tvmaddaz.wxyz ACC, $vf15, $vf1z\n\tvmaddw.wxyz $vf1, $vf16, $vf1w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf2x\n\tvmadday.wxyz ACC, $vf14, $vf2y\n\tvmaddaz.wxyz ACC, $vf15, $vf2z\n\tvmaddw.wxyz $vf2, $vf16, $vf2w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf3x\n\tvmadday.wxyz ACC, $vf14, $vf3y\n\tvmaddaz.wxyz ACC, $vf15, $vf3z\n\tvmaddw.wxyz $vf3, $vf16, $vf3w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf4x\n\tvmadday.wxyz ACC, $vf14, $vf4y\n\tvmaddaz.wxyz ACC, $vf15, $vf4z\n\tvmaddw.wxyz $vf4, $vf16, $vf4w\n\t"
            "sqc2 $vf1, 0(%4)\n\tsqc2 $vf2, 16(%4)\n\tsqc2 $vf3, 32(%4)\n\tsqc2 $vf4, 48(%4)"
            : : "r"(sci), "r"(eo), "r"(D_01d9e730), "r"(D_01d9e8c0), "r"(D_01d9e6e8->view) : "memory");
        for (s32 k = 0; k < 1; k++) ;
        r->mtx[0] = D_01d9e6e8->view[0];
        r->mtx[1] = D_01d9e6e8->view[1];
        r->mtx[2] = D_01d9e6e8->view[2];
        r->mtx[3] = D_01d9e6e8->view[3];
        func_0021cdd0(data, r);
        asm("" :: "r"(ctl)); // extra use of ctl: it takes s1 like the original
        r->type = 10;
        if (ctl && D_01d9ea9c == 0 && (D_01d9e6e0->flags & 0xff0000ff00ULL) == 0) {
            if (++ctl[1] >= anim->count) {
                if (((PrtFrame*)fv)->flags & 0x80) {
                    ctl[1] = 0;
                } else {
                    ctl[0] = 0;
                    ctl[1] = 0;
                }
            }
        }
    }
    func_001e7538();
    func_0020e0a0();
}
#undef anim
}  // namespace n00223af8

// 00223e98 (was src/anon/batch_w2466_nsa.cpp)
namespace n00223e98 {
// Shared render-work types (same layout as batch_w1674_nsa.cpp).
struct PrtMtx { f32 m[4][4]; } __attribute__((aligned(16)));
struct PrtWork { u8 pad0[0x10]; FMTX world; u128 view[4]; };
struct PrtState { u8 pad0[0xa8]; u64 flags; };
struct PrtFrame { s16 dataOfs; s16 duration; s8 flags; u8 pad5[3]; };
struct PrtAnim { u8 pad0[6]; s16 count; u8 pad8[8]; PrtFrame frames[1]; };
struct PrtAnimRef { PrtAnim* anim; s32 x4; };
struct PrtBank { u8 pad0[0x14]; PrtAnimRef* anims; };
// Draw request (scratchpad packet header).
struct PrtReq { s32 type; s32 w4; f32 f8; s32 w12; s32 rgba[4]; u8 pad32[16]; u128 mtx[4]; };
extern PrtWork* D_01d9e6e8 asm("D_01d9e6e8");
extern PrtBank* D_01d9e6e4 asm("D_01d9e6e4");
extern PrtState* D_01d9e6e0 asm("D_01d9e6e0");
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern FMTX D_01d9e730 asm("D_01d9e730");
extern FMTX D_01d9e8c0 asm("D_01d9e8c0");
extern PrtMtx* D_00354688 asm("D_00354688");
extern s32 D_0035468c asm("D_0035468c");
void func_0021cda0(s32) asm("func_0021cda0");
PrtReq* func_0021e988(void) asm("func_0021e988");
PrtReq* func_0021e998(void) asm("func_0021e998");
PrtReq* func_0021e9a8(void) asm("func_0021e9a8");
void func_0021cdd0(u8*, PrtReq*) asm("func_0021cdd0");
void func_001e7538(void) asm("func_001e7538");
void func_0020e0a0(void) asm("func_0020e0a0");
/*TARGET 00223e98*/
// VU0 macro code below is hand-written (no memory clobber, as in the original).
void func_00223e98(u32 idx, u8* rgba, u8 mode, s32 unused, u32 n, f32 scale, f32 len) asm("func_00223e98");
// VU0 macro code below is hand-written (no memory clobber, as in the original).
void func_00223e98(u32 idx, u8* rgba, u8 mode, s32 unused, u32 n, f32 scale, f32 len) {
    PrtAnim* anim; PrtFrame* fr;
    f32 step = len / n;
    func_0021cda0(mode);
    PrtReq* r0 = func_0021e988();
    PrtReq* r1 = func_0021e998();
    if (rgba[3] >= 255) r0->type = r1->type = 2;
    else r0->type = r1->type = 0;
    r0->f8 = r1->f8 = 0.0f;
    r0->rgba[0] = r1->rgba[0] = rgba[0];
    r0->rgba[1] = r1->rgba[1] = rgba[1];
    r0->rgba[2] = r1->rgba[2] = rgba[2];
    r0->rgba[3] = r1->rgba[3] = rgba[3];
    if (idx == 0xffff) return;
    for (s32 i = 0; i < D_0035468c; i++) {
u8* ctl = 0; f32 sc = 1.0f; f32 off = -(n * 0.5f * step); u32 frame = 0;
        PrtMtx* e = (PrtMtx*)(i * 64 + (u32)D_00354688);
        u8* w = (u8*)&e->m[3][3];
        if (e->m[3][3] != 1.0f) ctl = w;
        if (ctl && !ctl[0]) continue;
        for (u32 j = 0; j < n; j++) {
            PrtReq* r = func_0021e9a8();
            if (ctl) {
                r->rgba[3] = ctl[0];
                sc = ctl[3];
                frame = ctl[1];
                sc *= scale * 0.1f;
            }
            u32 ofs = idx * 8;
            anim = ((PrtAnimRef*)((u8*)D_01d9e6e4->anims + ofs))->anim;
            fr = &anim->frames[frame];
            u8* data = (u8*)anim + fr->dataOfs;
            asm volatile(
            "vsub.wxyz $vf4, $vf0, $vf0\n\tvadd.w $vf4, $vf4, $vf0\n\t"
            "vmr32.wxyz $vf3, $vf4\n\tvmr32.wxyz $vf2, $vf3\n\tvmr32.wxyz $vf1, $vf2\n\t"
            "qmtc2 %0, $vf7\n\tvmulx.xyz $vf1, $vf1, $vf7x\n\tvmulx.xyz $vf2, $vf2, $vf7x\n\tvmulx.xyz $vf3, $vf3, $vf7x\n\t"
            "lqc2 $vf8, 48(%1)\n\tvmove.w $vf8, $vf0\n\t"
            "qmtc2 %2, $vf5\n\tlqc2 $vf6, 32(%1)\n\tvmulx.xyz $vf6, $vf6, $vf5x\n\tvadd.wxyz $vf8, $vf8, $vf6\n\tvmove.wxyz $vf4, $vf8\n\t"
            "lqc2 $vf9, 0(%3)\n\tlqc2 $vf10, 16(%3)\n\tlqc2 $vf11, 32(%3)\n\tlqc2 $vf12, 48(%3)\n\t"
            "lqc2 $vf13, 0(%4)\n\tlqc2 $vf14, 16(%4)\n\tlqc2 $vf15, 32(%4)\n\tlqc2 $vf16, 48(%4)\n\t"
            "vmulax.wxyz ACC, $vf9, $vf4x\n\tvmadday.wxyz ACC, $vf10, $vf4y\n\tvmaddaz.wxyz ACC, $vf11, $vf4z\n\tvmaddw.wxyz $vf4, $vf12, $vf4w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf1x\n\tvmadday.wxyz ACC, $vf14, $vf1y\n\tvmaddaz.wxyz ACC, $vf15, $vf1z\n\tvmaddw.wxyz $vf1, $vf16, $vf1w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf2x\n\tvmadday.wxyz ACC, $vf14, $vf2y\n\tvmaddaz.wxyz ACC, $vf15, $vf2z\n\tvmaddw.wxyz $vf2, $vf16, $vf2w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf3x\n\tvmadday.wxyz ACC, $vf14, $vf3y\n\tvmaddaz.wxyz ACC, $vf15, $vf3z\n\tvmaddw.wxyz $vf3, $vf16, $vf3w\n\t"
            "vmulax.wxyz ACC, $vf13, $vf4x\n\tvmadday.wxyz ACC, $vf14, $vf4y\n\tvmaddaz.wxyz ACC, $vf15, $vf4z\n\tvmaddw.wxyz $vf4, $vf16, $vf4w\n\t"
            "sqc2 $vf1, 0(%5)\n\tsqc2 $vf2, 16(%5)\n\tsqc2 $vf3, 32(%5)\n\tsqc2 $vf4, 48(%5)"
            : : "r"(sc), "r"(&D_00354688[i]), "r"(off), "r"(D_01d9e730), "r"(D_01d9e8c0), "r"(D_01d9e6e8->view) );
            r->mtx[0] = D_01d9e6e8->view[0];
            r->mtx[1] = D_01d9e6e8->view[1];
            r->mtx[2] = D_01d9e6e8->view[2];
            r->mtx[3] = D_01d9e6e8->view[3];
            off += step;
            func_0021cdd0(data, r);
            r->type = 10;
        }
        if (ctl && D_01d9ea9c == 0 && (D_01d9e6e0->flags & 0xff0000ff00ULL) == 0) {
            if (++ctl[1] >= anim->count) {
                if (fr->flags & 0x80) {
                    ctl[1] = 0;
                } else {
                    ctl[0] = 0;
                    ctl[1] = 0;
                }
            }
        }
    }
    func_001e7538();
    func_0020e0a0();
}
}  // namespace n00223e98

// 00224358 (was src/anon/batch_w3681_nsa.cpp)
namespace n00224358 {
struct Prm224358 {
    s32 flags; void* p4; u16 h8; u8 b10; u8 pad11; s32 w12; s64 d16;
    u8 c24, c25, c26, c27; s32 w28; void* p32; void* p36; void* p40; void* p44; s32 w48; s32 w52; s32 w56; s32 w60; s32 w64; s32 w68; s32 w72; s32 w76; s32 pad80[4];
};
struct Hdr224358 { u32 b0 : 1; u32 b1 : 1; u32 rest : 30; u8 pad4[18]; u16 h22; };
struct Slot224358 { u8 pad[28]; Hdr224358* h; s32 w32; };
struct Sys224358 { u8 pad[16]; Slot224358* slots; };
struct Sys2224358 { u8 pad[16]; u8 a16[64]; u8 a80[64]; s32 w144; s32 w148; };
struct Mtx224358 { f32 m[15]; f32 w; } __attribute__((aligned(16)));
extern Sys224358* D_01d9e6e4 asm("D_01d9e6e4");
extern Sys2224358* D_01d9e6e8 asm("D_01d9e6e8");
extern s32 D_01d9eaa4 asm("D_01d9eaa4");
extern u8 D_01d9eac0[] asm("D_01d9eac0");
extern Mtx224358 D_01d9ea00 asm("D_01d9ea00");
extern Mtx224358* D_00354688 asm("D_00354688");
extern s32 D_0035468c asm("D_0035468c");
s32 func_0020f1e0(Hdr224358*, Prm224358*, s32) asm("func_0020f1e0");
/*TARGET 00224358*/
void func_00224358(u32 idx, u8* rgba, u8 b2, u8 b3) asm("func_00224358");
void func_00224358(u32 idx, u8* rgba, u8 b2, u8 b3) {
    Prm224358 prm;
    if (idx == 0xffff) return;
    Sys224358* sys = D_01d9e6e4; Slot224358* s = &sys->slots[idx];
    Hdr224358* h = s->h; asm("" : "=r"(h) : "0"(h), "r"(sys));
    Sys2224358* g = D_01d9e6e8;
    prm.w68 = 0;
    prm.p44 = 0;
    prm.p40 = 0;
    prm.p36 = 0;
    prm.b10 = 0;
    prm.w28 = 0;
    prm.w56 = g->w144;
    prm.w60 = g->w148;
    prm.p4 = D_01d9eac0;
    prm.p32 = g->a80;
    prm.flags = 36;
    prm.w12 = 0;
    prm.d16 = 0;
    prm.w64 = 0;
    if (!h->b0) prm.flags = 44;
    if (!h->b1) prm.flags |= 0x10;
    if (b2) prm.flags |= 0x200;
    if (b3) prm.flags |= 0x100;
    *(u16*)((u8*)&prm + 8) = h->h22;
    prm.c24 = rgba[0];
    prm.c25 = rgba[1];
    prm.c26 = rgba[2];
    prm.c27 = rgba[3];
    for (s32 i = 0; i < D_0035468c; i++) {
        Mtx224358* e = (Mtx224358*)((u8*)(i * 64) + (u32)D_00354688);
        u8* p = (u8*)&e->w;
        u8* col = 0;
        f32 sc = 1.0f;
        if (e->w != 1.0f) col = p;
        if (col) {
            if (!col[0]) continue;
            prm.c27 = col[0];
            sc = col[3];
            sc *= 0.1f;
        }
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\tvmove.w $vf4, $vf0\n\t"
                     "lqc2 $vf5, 0(%1)\n\tlqc2 $vf6, 16(%1)\n\tlqc2 $vf7, 32(%1)\n\tlqc2 $vf8, 48(%1)\n\t"
                     "qmtc2 %3, $vf9\n\tvmulx.xyz $vf1, $vf1, $vf9x\n\tvmulx.xyz $vf2, $vf2, $vf9x\n\tvmulx.xyz $vf3, $vf3, $vf9x\n\t"
                     "vmulax.wxyz ACC, $vf5, $vf1x\n\tvmadday.wxyz ACC, $vf6, $vf1y\n\tvmaddaz.wxyz ACC, $vf7, $vf1z\n\tvmaddw.wxyz $vf1, $vf8, $vf1w\n\t"
                     "vmulax.wxyz ACC, $vf5, $vf2x\n\tvmadday.wxyz ACC, $vf6, $vf2y\n\tvmaddaz.wxyz ACC, $vf7, $vf2z\n\tvmaddw.wxyz $vf2, $vf8, $vf2w\n\t"
                     "vmulax.wxyz ACC, $vf5, $vf3x\n\tvmadday.wxyz ACC, $vf6, $vf3y\n\tvmaddaz.wxyz ACC, $vf7, $vf3z\n\tvmaddw.wxyz $vf3, $vf8, $vf3w\n\t"
                     "vmulax.wxyz ACC, $vf5, $vf4x\n\tvmadday.wxyz ACC, $vf6, $vf4y\n\tvmaddaz.wxyz ACC, $vf7, $vf4z\n\tvmaddw.wxyz $vf4, $vf8, $vf4w\n\t"
                     "sqc2 $vf1, 0(%2)\n\tsqc2 $vf2, 16(%2)\n\tsqc2 $vf3, 32(%2)\n\tsqc2 $vf4, 48(%2)"
                     : : "r"(e), "r"(&D_01d9ea00), "r"(D_01d9e6e8->a80), "r"(sc) : "memory");
        prm.w52 = D_01d9eaa4;
        D_01d9eaa4 = func_0020f1e0(h, &prm, s->w32);
    }
}
}  // namespace n00224358

// 00224600 (was src/anon/batch_wcx2.cpp)
namespace n00224600 {
/*TARGET 00224600*/
// func_001affe0: not yet matching (scheduling around the game's 64-bit divide calls); left as asm.

// Entire body is hand-written VU0 macro code in the original.
void func_00224600(void* out, const void* m, const void* v) asm("func_00224600");
// func_001affe0: not yet matching (scheduling around the game's 64-bit divide calls); left as asm.

// Entire body is hand-written VU0 macro code in the original.
void func_00224600(void* out, const void* m, const void* v)
{
    asm volatile(".set noreorder\n\tmove $13,$4\n\tmove $14,$5\n\tmove $15,$6\n\tlui $2,0xbf80\n\tqmtc2 $2,$vf19\n\tlqc2 $vf28,0($14)\n\tlqc2 $vf29,16($14)\n\tlqc2 $vf30,32($14)\n\tlqc2 $vf31,48($14)\n\tvmulx.xyz $vf28,$vf28,$vf19x\n\tvmulx.xyz $vf29,$vf29,$vf19x\n\tvmulx.xyz $vf30,$vf30,$vf19x\n\tvmulx.xyz $vf31,$vf31,$vf19x\n\tvmul.xyz $vf18,$vf28,$vf28\n\tvaddy.x $vf18,$vf18,$vf18y\n\tvaddz.x $vf18,$vf18,$vf18z\n\tvsqrt Q,$vf18x\n\tvwaitq\n\tvaddq.x $vf18,$vf0,Q\n\tvdiv Q,$vf0w,$vf18x\n\tvwaitq\n\tvmulq.xyz $vf28,$vf28,Q\n\tvmul.xyz $vf18,$vf29,$vf29\n\tvaddy.x $vf18,$vf18,$vf18y\n\tvaddz.x $vf18,$vf18,$vf18z\n\tvsqrt Q,$vf18x\n\tvwaitq\n\tvaddq.x $vf18,$vf0,Q\n\tvdiv Q,$vf0w,$vf18x\n\tvwaitq\n\tvmulq.xyz $vf29,$vf29,Q\n\tvmul.xyz $vf18,$vf30,$vf30\n\tvaddy.x $vf18,$vf18,$vf18y\n\tvaddz.x $vf18,$vf18,$vf18z\n\tvsqrt Q,$vf18x\n\tvwaitq\n\tvaddq.x $vf18,$vf0,Q\n\tvdiv Q,$vf0w,$vf18x\n\tvwaitq\n\tvmulq.xyz $vf30,$vf30,Q\n\tvmul.xyz $vf18,$vf31,$vf31\n\tvaddy.x $vf18,$vf18,$vf18y\n\tvaddz.x $vf18,$vf18,$vf18z\n\tvsqrt Q,$vf18x\n\tvwaitq\n\tvaddq.x $vf18,$vf0,Q\n\tvdiv Q,$vf0w,$vf18x\n\tvwaitq\n\tvmulq.xyz $vf31,$vf31,Q\n\tqmtc2 $0,$vf18\n\tvmulw.xyz $vf28,$vf28,$vf28w\n\tvmulw.xyz $vf29,$vf29,$vf29w\n\tvmulw.xyz $vf30,$vf30,$vf30w\n\tvmulw.xyz $vf31,$vf31,$vf31w\n\tvmove.w $vf28,$vf18\n\tvmove.w $vf29,$vf18\n\tvmove.w $vf30,$vf18\n\tvmove.w $vf31,$vf18\n\tqmfc2 $2,$vf28\n\tqmfc2 $3,$vf29\n\tqmfc2 $4,$vf30\n\tqmfc2 $5,$vf31\n\tpextlw $6,$3,$2\n\tpextuw $7,$3,$2\n\tpextlw $8,$5,$4\n\tpextuw $9,$5,$4\n\tpcpyld $2,$8,$6\n\tpcpyud $3,$6,$8\n\tpcpyld $4,$9,$7\n\tpcpyud $5,$7,$9\n\tqmtc2 $2,$vf28\n\tqmtc2 $3,$vf29\n\tqmtc2 $4,$vf30\n\tqmtc2 $5,$vf31\n\tlqc2 $vf24,0($15)\n\tlqc2 $vf25,16($15)\n\tlqc2 $vf26,32($15)\n\tvmove.w $vf24,$vf18\n\tvmove.w $vf25,$vf18\n\tvmove.w $vf26,$vf18\n\tvmulax.wxyz ACC,$vf28,$vf24x\n\tvmadday.wxyz ACC,$vf29,$vf24y\n\tvmaddz.wxyz $vf20,$vf30,$vf24z\n\tvmulax.wxyz ACC,$vf28,$vf25x\n\tvmadday.wxyz ACC,$vf29,$vf25y\n\tvmaddz.wxyz $vf21,$vf30,$vf25z\n\tvmulax.wxyz ACC,$vf28,$vf26x\n\tvmadday.wxyz ACC,$vf29,$vf26y\n\tvmaddz.wxyz $vf22,$vf30,$vf26z\n\tsqc2 $vf20,0($13)\n\tsqc2 $vf21,16($13)\n\tsqc2 $vf22,32($13)\n\tsqc2 $vf31,48($13)\n\t.set reorder"
                 : : : "$2", "$3", "$4", "$5", "$6", "$7", "$8", "$9", "$13", "$14", "$15", "memory");
}
}  // namespace n00224600

