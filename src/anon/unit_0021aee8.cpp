// Linked unit 0x0021aee8-0x0021d048: first part of draw/shape.c (the shape packet builders before whole-asm 0x21d048).
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
typedef unsigned int w1807_u128 __attribute__((mode(TI)));

// 0021aee8 (was src/anon/batch_w3830_nsa.c)
namespace n0021aee8 {
typedef union A64 { u64 v; u8 c; } A64;
typedef union A32 { u32 v; s32 s; u8 c; } A32;
typedef union A128 { u128 v; u8 c; } A128;
typedef union APtr { u8* p; void* v; u8 c; } APtr;
/* Model header (the object the draw command list belongs to). */
typedef struct MdlHdr {
    u32 flags;   /* 0x00: bit 2 = no fog */
    s32 cmdOfs;  /* 0x04: offset of the draw command list */
    s32 posOfs;  /* 0x08: offset of the positions (s16 x3) */
    s32 nrmOfs;  /* 0x0c: offset of the normals (s16 x3) */
    u16 f10;
    s16 nVtx;    /* 0x12 */
    s16 nNrm;    /* 0x14 */
    u8 tex0;     /* 0x16 */
    u8 tex1;     /* 0x17 */
} MdlHdr;
/* One draw command (16 bytes header, followed by the primitives). */
typedef struct DrawCmd {
    u8 f0;
    s8 type;     /* 0..7: primitive kind, odd = invalid */
    s16 count;
    u32 f4;
    u32 tex;
    u32 clut;
} DrawCmd;
/* Draw parameters, copied to scratchpad 0x300 (5 qwords). */
typedef struct DrawParam {
    u32 flags;      /* 0x00: bit 3 = alternate fog colour */
    u8* vtxBuf;     /* 0x04 */
    union { s16 texSet; struct { u8 tex0, tex1; } t; } tx; /* 0x08 */
    u16 f0a;
    u16 texOfs;     /* 0x0c */
    u16 clutOfs;    /* 0x0e */
    s32 texW;       /* 0x10 */
    s32 texH;       /* 0x14 */
    union { u8 rgba[4]; u32 word; } color;  /* 0x18 */
    u32 color2;     /* 0x1c */
    void* mtx0;     /* 0x20 */
    void* mtx1;     /* 0x24 */
    void* mtx2;     /* 0x28 */
    void* mtx3;     /* 0x2c */
    u32 f30;
    A32 pktEnd;     /* 0x34 */
    APtr pos;       /* 0x38 */
    APtr nrm;       /* 0x3c */
    u32 f40;
    APtr mtxSave;   /* 0x44 */
    u32 f48[2];
} DrawParam;
/* Scratchpad work area. */
typedef struct SprWork {
    u8 pad000[0x100];
    A64 tag100, tag108, tag110, tag118;
    A32 tex, clut; A64 tag128;
    A32 tex0, tex1; A64 tag138;
    A128 q140;
    A64 tag150, tag158;
    A64 tag160, tag168;
    u8 pad170[0x10];
    APtr f180;
    u8 pad184[0x1e0 - 0x184];
    union { u128 q; u32 w[4]; } cnt;
    A64 tag1f0, tag1f8;
    u8 pad200[0x2e0 - 0x200];
    A64 tag2e0, tag2e8;
    u8 pad2f0[0x10];
    DrawParam dp;
    u8 pad350[0x44];
    APtr vtxBase;   /* 0x394 */
    u8 pad398[4];
    APtr fogBase;   /* 0x39c */
} SprWork;
#define QCOPY(d, s) asm volatile("lq $2, 0(%1)\n\tsq $2, 0(%0)" : : "r"(d), "r"(s) : "$2", "memory")
extern A32 D_00359780 asm("D_00359780");
extern SprWork* D_00359788[] asm("D_00359788");
extern A32 D_00352c38 asm("D_00352c38");
extern u8 D_00359110[] asm("D_00359110");
extern u8 D_00359180[] asm("D_00359180");
extern u8 D_00359970[] asm("D_00359970");
extern u128 D_01da8bb0[] asm("D_01da8bb0");
extern u128 D_01da8c40[] asm("D_01da8c40");
extern A32 D_01da8cd0[] asm("D_01da8cd0");
/*TARGET 0021aee8*/
u32 func_0021aee8(MdlHdr* obj, u128* param) asm("func_0021aee8");
u32 func_0021aee8(MdlHdr* obj, u128* param)
{
    asm volatile("");
    register SprWork* spr asm("$24") = D_00359788[D_00359780.s++];
    register DrawParam* h asm("$22") = &spr->dp;
    D_00359788[D_00359780.s] = (SprWork*)((u8*)spr + 0x1800);
    QCOPY(h, param);
    QCOPY((u8*)spr + 0x310, param + 1);
    QCOPY((u8*)spr + 0x320, param + 2);
    QCOPY((u8*)spr + 0x330, param + 3);
    QCOPY((u8*)spr + 0x340, param + 4);
    asm volatile("sq $0, %0" : "=m"(spr->cnt.q));
    {
        u8* p1 = h->pos.p;
        u8* pos;
        u8* nrm;
        if (p1 == 0) pos = (u8*)obj + obj->posOfs;
        else pos = p1;
        nrm = h->nrm.p;
        if (nrm == 0) nrm = (u8*)obj + obj->nrmOfs;
        h->nrm.p = nrm;
        h->pos.p = pos;
    }
    if (D_00352c38.s != 0) {
        s32 g = (s32)(h->color.rgba[0] * 0.3f + h->color.rgba[1] * 0.59f + h->color.rgba[2] * 0.11f);
        h->color.rgba[0] = g;
        h->color.rgba[1] = g;
        h->color.rgba[2] = g;
    }
    asm volatile(".set noreorder\n.set noat\n"
        "move $2,%[r_t7]\n"
        "pextlb $2,$0,$2\n"
        "pextlh $2,$0,$2\n"
        "qmtc2 $2,$vf31\n"
        "lui $3,0x3c00\n"
        "pextlw $3,$3,$3\n"
        "pextlw $3,$3,$3\n"
        "qmtc2 $3,$vf30\n"
        "vitof0.wxyz $vf31,$vf31\n"
        "vmul.wxyz $vf31,$vf31,$vf30\n"
        "sqc2 $vf31,848(%[r_t8])\n"
        ".set at\n.set reorder"
        :
        : [r_t7] "r" (h->color.word), [r_t8] "r" (spr)
        : "$2", "$3", "memory");
    asm volatile(".set noreorder\n.set noat\n"
        "lw $2,0(%[r_t6])\n"
        "pextlb $2,$0,$2\n"
        "pextlh $2,$0,$2\n"
        "qmtc2 $2,$vf31\n"
        "vitof0.wxyz $vf31,$vf31\n"
        "sqc2 $vf31,880(%[r_t8])\n"
        ".set at\n.set reorder"
        :
        : [r_t6] "r" (&h->color2), [r_t8] "r" (spr)
        : "$2", "memory");
    {
    register u8* vtx asm("$20") = h->vtxBuf;
    u8* tbl = D_00359110;
    register u8* vend asm("$21");
    spr->vtxBase.p = vtx;
    u8* e = h->vtxBuf + obj->nVtx * 16;
    spr->fogBase.p = e;
    asm volatile(".set noreorder\n.set noat\n"
        "vmove.wxyz $vf28,$vf0\n"
        "lui $9,0xffff\n"
        "dsrl32 $9,$9,0x0\n"
        "lw $2,32(%[r_s6])\n"
        "lqc2 $vf24,0($2)\n"
        "lqc2 $vf25,16($2)\n"
        "lqc2 $vf26,32($2)\n"
        "lqc2 $vf27,48($2)\n"
        "lhu $10,18(%[r_s0])\n"
        "lwu $8,56(%[r_s6])\n"
        "lw $2,0(%[r_s6])\n"
        "lqc2 $vf16,0(%[r_t6])\n"
        "andi $3,$2,0x200\n"
        "bnez $3,1f\n"
        "nop\n"
        "lqc2 $vf16,16(%[r_t6])\n"
        "1:\n"
        "lqc2 $vf17,32(%[r_t6])\n"
        "andi $3,$2,0x100\n"
        "bnez $3,2f\n"
        "nop\n"
        "lqc2 $vf17,48(%[r_t6])\n"
        "2:\n"
        "lui $2,0x3c00\n"
        "qmtc2 $2,$vf18\n"
        "lwu $7,916(%[r_t8])\n"
        "lw $2,68(%[r_s6])\n"
        "bnez $2,3f\n"
        "lwu $6,924(%[r_t8])\n"
        "lw $2,32(%[r_s6])\n"
        "sw $2,68(%[r_s6])\n"
        "blez $10,4f\n"
        "7:\n"
        "lh $2,4($8)\n"
        "and $2,$2,$9\n"
        "lh $3,2($8)\n"
        "lh $4,0($8)\n"
        "and $4,$4,$9\n"
        "dsll32 $3,$3,0x0\n"
        "or $3,$3,$4\n"
        "pcpyld $2,$2,$3\n"
        "qmtc2 $2,$vf29\n"
        "vitof0.xyz $vf28,$vf29\n"
        "vmulax.wxyz ACC,$vf24,$vf28x\n"
        "vmadday.wxyz ACC,$vf25,$vf28y\n"
        "vmaddaz.wxyz ACC,$vf26,$vf28z\n"
        "vmaddw.wxyz $vf31,$vf27,$vf28w\n"
        "vnop\n"
        "vnop\n"
        "vnop\n"
        "vdiv Q,$vf0w,$vf31w\n"
        "cfc2.ni $2,$vi17\n"
        "andi $2,$2,0x11\n"
        "beqz $2,5f\n"
        "sqc2 $vf0,0($7)\n"
        "b 6f\n"
        "5:\n"
        "vmulx.w $vf2,$vf31,$vf17x\n"
        "vmulay.w ACC,$vf0,$vf16y\n"
        "vmulx.w $vf1,$vf0,$vf16x\n"
        "vmaddw.w $vf1,$vf1,$vf31w\n"
        "vminiz.w $vf1,$vf1,$vf16z\n"
        "vmaxw.w $vf1,$vf1,$vf16w\n"
        "vaddy.w $vf2,$vf2,$vf17y\n"
        "vminiz.w $vf2,$vf2,$vf17z\n"
        "vmaxw.w $vf2,$vf2,$vf17w\n"
        "vmulx.w $vf2,$vf2,$vf18x\n"
        "vmr32.z $vf1,$vf2\n"
        "vwaitq\n"
        "vmulq.xyz $vf29,$vf31,Q\n"
        "vmulq.w $vf29,$vf0,Q\n"
        "sqc2 $vf29,0($7)\n"
        "sqc2 $vf1,0($6)\n"
        "6:\n"
        "addi $10,$10,-1\n"
        "addiu $8,$8,6\n"
        "addiu $6,$6,16\n"
        "bgtz $10,7b\n"
        "addiu $7,$7,16\n"
        "b 4f\n"
        "nop\n"
        "3:\n"
        "lqc2 $vf20,0($2)\n"
        "lqc2 $vf21,16($2)\n"
        "lqc2 $vf22,32($2)\n"
        "lqc2 $vf23,48($2)\n"
        "blez $10,4f\n"
        "10:\n"
        "lh $2,4($8)\n"
        "and $2,$2,$9\n"
        "lh $3,2($8)\n"
        "lh $4,0($8)\n"
        "and $4,$4,$9\n"
        "dsll32 $3,$3,0x0\n"
        "or $3,$3,$4\n"
        "pcpyld $2,$2,$3\n"
        "qmtc2 $2,$vf29\n"
        "vitof0.xyz $vf28,$vf29\n"
        "vmulax.wxyz ACC,$vf24,$vf28x\n"
        "vmadday.wxyz ACC,$vf25,$vf28y\n"
        "vmaddaz.wxyz ACC,$vf26,$vf28z\n"
        "vmaddw.wxyz $vf31,$vf27,$vf28w\n"
        "vnop\n"
        "vnop\n"
        "vnop\n"
        "vdiv Q,$vf0w,$vf31w\n"
        "cfc2.ni $2,$vi17\n"
        "andi $2,$2,0x11\n"
        "beqz $2,8f\n"
        "sqc2 $vf0,0($7)\n"
        "b 9f\n"
        "8:\n"
        "vmulx.w $vf2,$vf31,$vf17x\n"
        "vmulay.w ACC,$vf0,$vf16y\n"
        "vmulx.w $vf1,$vf0,$vf16x\n"
        "vmaddw.w $vf1,$vf1,$vf31w\n"
        "vmulax.wxyz ACC,$vf20,$vf28x\n"
        "vmadday.wxyz ACC,$vf21,$vf28y\n"
        "vmaddaz.wxyz ACC,$vf22,$vf28z\n"
        "vmaddw.wxyz $vf30,$vf23,$vf28w\n"
        "vwaitq\n"
        "vmulq.xyz $vf29,$vf31,Q\n"
        "vmulq.w $vf29,$vf0,Q\n"
        "vdiv Q,$vf0w,$vf30w\n"
        "vminiz.w $vf1,$vf1,$vf16z\n"
        "vmaxw.w $vf1,$vf1,$vf16w\n"
        "vaddy.w $vf2,$vf2,$vf17y\n"
        "vminiz.w $vf2,$vf2,$vf17z\n"
        "vmaxw.w $vf2,$vf2,$vf17w\n"
        "vmulx.w $vf2,$vf2,$vf18x\n"
        "vmr32.z $vf1,$vf2\n"
        "vwaitq\n"
        "vmulq.z $vf29,$vf30,Q\n"
        "sqc2 $vf29,0($7)\n"
        "sqc2 $vf1,0($6)\n"
        "9:\n"
        "addi $10,$10,-1\n"
        "addiu $8,$8,6\n"
        "addiu $6,$6,16\n"
        "bgtz $10,10b\n"
        "addiu $7,$7,16\n"
        "4:\n"
        ".set at\n.set reorder"
        :
        : [r_t6] "r" (tbl), [r_t8] "r" (spr), [r_s6] "r" (h), [r_s0] "r" (obj)
        : "$2", "$3", "$4", "$6", "$7", "$8", "$9", "$10", "memory");
    {
    s32 cofs = obj->cmdOfs;
    register DrawCmd* cmd asm("$25");
    spr->tag108.v = 0;
    spr->tag100.v = 0x70000005;
    spr->tag110.v = 0x4000000000008001ULL;
    spr->tag118.v = 0xeeee;
    spr->tag128.v = 6;
    DrawCmd* c0 = (DrawCmd*)((u8*)obj + cofs);
    if (h->tx.texSet != 0) {
        spr->tex0.v = h->tx.t.tex0;
        spr->tex1.v = h->tx.t.tex1;
    } else {
        spr->tex0.v = obj->tex0;
        spr->tex1.v = obj->tex1;
    }
    cmd = c0;
    spr->tag138.v = 66;
    {
    u128* qt = (h->flags & 8) ? D_01da8c40 : D_01da8bb0;
    asm volatile("lq $14,48(%0)\n\tsq $14,320(%1)" : : "r"(qt), "r"(spr) : "$14", "memory");
    }
    if (obj->flags & 4) spr->tag150.v = 0;
    else spr->tag150.v = 5;
    { register u64 k asm("$14") = 8; spr->tag158.v = k; }
    vend = e;
    {
    u8* ft = D_00359970;
    asm volatile(".set noreorder\n.set noat\n"
        "lqc2 $vf27,48(%[r_t7])\n"
        "lqc2 $vf28,64(%[r_t7])\n"
        "lqc2 $vf29,80(%[r_t7])\n"
        ".set at\n.set reorder"
        :
        : [r_t7] "r" (ft)
        : "memory");
    }
next:
    {
        switch (cmd->type) {
        case 0: {
            register s32 left asm("$19");
            {
            register u64 tag asm("$9") = 0x6035c00000008001ULL;
            u32 k = 0x414141;
            asm volatile(".set noreorder\n.set noat\n"
                "sd %[r_k],504(%[r_t8])\n"
                "sd %[r_t1],496(%[r_t8])\n"
                "lui $2,0x1000\n"
                "ori $2,$2,0xa000\n"
                "1:\n"
                "lw $3,0($2)\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "andi $3,$3,0x100\n"
                "bne $0,$3,1b\n"
                "addi $4,%[r_t8],256\n"
                "lui $5,0x8000\n"
                "or $4,$5,$4\n"
                "li $5,-1\n"
                "lw $6,48($2)\n"
                "bnel $6,$5,2f\n"
                "sw $4,48($2)\n"
                "2:\n"
                "lui $4,0xffff\n"
                "ori $4,$4,0xfff3\n"
                "sw $0,32($2)\n"
                "and $4,$4,$3\n"
                "ori $4,$4,0x105\n"
                "sw $4,0($2)\n"
                ".set at\n.set reorder"
                :
                : [r_t1] "r" (tag), [r_t8] "r" (spr), [r_k] "r" (k)
                : "$2", "$3", "$4", "$5", "$6", "memory");
            }
            left = cmd->count;
            D_01da8cd0[1].s += left;
            cmd++;
            asm volatile(".set noreorder\n.set noat\n"
                "sq $16,1008(%[r_t8])\n"
                "sq $17,992(%[r_t8])\n"
                "sq $18,976(%[r_t8])\n"
                ".set at\n.set reorder" : : [r_t8] "r" (spr) : "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "lw $18,768(%[r_t8])\n"
                "move $17,%[r_s4]\n"
                "li $12,4096\n"
                "lui $10,0xffff\n"
                "dsrl32 $10,$10,0x0\n"
                "dsll32 $11,$10,0x0\n"
                "or $11,$11,$10\n"
                "pcpyld $11,$10,$11\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "lbu $2,503(%[r_t8])\n"
                "srl $2,$2,0x4\n"
                "addiu $2,$2,2\n"
                "sh $2,706(%[r_t8])\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "sll $2,$2,0x4\n"
                "sh $2,704(%[r_t8])\n"
                "move $13,$0\n"
                "lui $2,0x100\n"
                "lui $3,0xffff\n"
                "ori $3,$3,0xffff\n"
                "pextlb $2,$0,$2\n"
                "pextlh $2,$0,$2\n"
                "pextlb $3,$0,$3\n"
                "pextlh $3,$0,$3\n"
                "qmtc2 $2,$vf19\n"
                "qmtc2 $3,$vf20\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "vitof0.wxyz $vf19,$vf19\n"
                "vitof0.wxyz $vf20,$vf20\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "6:\n"
                "beqz %[r_s3],1f\n"
                "addi $13,$13,1\n"
                "andi $13,$13,0x1\n"
                "lq $2,496(%[r_t8])\n"
                "sll $3,$13,0xb\n"
                "add $15,%[r_t8],$3\n"
                "addi $15,$15,2080\n"
                "sq $2,-16($15)\n"
                "move $14,$0\n"
                "5:\n"
                "move $9,$0\n"
                "lhu $2,12(%[r_t9])\n"
                "lhu $3,14(%[r_t9])\n"
                "lhu $4,16(%[r_t9])\n"
                "dsll $2,$2,0x4\n"
                "dsll $3,$3,0x4\n"
                "dsll $4,$4,0x4\n"
                "add $2,$2,$17\n"
                "add $3,$3,$17\n"
                "add $4,$4,$17\n"
                "lqc2 $vf15,0($2)\n"
                "lqc2 $vf16,0($3)\n"
                "lqc2 $vf17,0($4)\n"
                "andi $2,$18,0x10\n"
                "beqz $2,2f\n"
                "nop\n"
                "vsub.wxyz $vf7,$vf15,$vf16\n"
                "vsub.wxyz $vf8,$vf17,$vf16\n"
                "vopmula.xyz ACC,$vf7,$vf8\n"
                "vopmsub.xyz $vf9,$vf8,$vf7\n"
                "vftoi4.z $vf9,$vf9\n"
                "qmfc2 $6,$vf9\n"
                "pextuw $2,$0,$6\n"
                "sll $2,$2,0x0\n"
                "bgez $2,3f\n"
                "nop\n"
                "2:\n"
                "move $8,$0\n"
                "vsub.xyz $vf1,$vf15,$vf27\n"
                "vsub.xyz $vf2,$vf16,$vf27\n"
                "vsub.xyz $vf3,$vf17,$vf27\n"
                "vnop\n"
                "vmax.xyz $vf5,$vf1,$vf2\n"
                "vmax.xyz $vf5,$vf5,$vf3\n"
                "vmini.xyz $vf6,$vf1,$vf2\n"
                "vmini.xyz $vf6,$vf6,$vf3\n"
                "vclipw.xy $vf5,$vf28w\n"
                "vclipw.xy $vf6,$vf28w\n"
                "vclipw.xy $vf5,$vf29w\n"
                "vclipw.xy $vf6,$vf29w\n"
                "lui $2,0x28\n"
                "ori $2,$2,0x514a\n"
                "li $3,2064\n"
                "vnop\n"
                "vnop\n"
                "vnop\n"
                "vnop\n"
                "cfc2.ni $4,$vi18\n"
                "vclipw.z $vf5,$vf27w\n"
                "vclipw.z $vf6,$vf27w\n"
                "and $4,$4,$2\n"
                "bnez $4,3f\n"
                "nop\n"
                "vnop\n"
                "vnop\n"
                "vnop\n"
                "vnop\n"
                "cfc2.ni $4,$vi18\n"
                "and $4,$4,$3\n"
                "bnez $4,3f\n"
                "nop\n"
                "qmfc2 $6,$vf21\n"
                "lw $2,0(%[r_t9])\n"
                "lw $3,4(%[r_t9])\n"
                "lw $4,8(%[r_t9])\n"
                "pextlb $2,$0,$2\n"
                "pextlb $3,$0,$3\n"
                "pextlb $4,$0,$4\n"
                "pextlh $2,$0,$2\n"
                "pextlh $3,$0,$3\n"
                "pextlh $4,$0,$4\n"
                "qmtc2 $2,$vf4\n"
                "qmtc2 $3,$vf5\n"
                "qmtc2 $4,$vf6\n"
                "lhu $2,12(%[r_t9])\n"
                "lhu $3,14(%[r_t9])\n"
                "lhu $4,16(%[r_t9])\n"
                "dsll $2,$2,0x4\n"
                "dsll $3,$3,0x4\n"
                "dsll $4,$4,0x4\n"
                "add $2,$2,%[r_s5]\n"
                "add $3,$3,%[r_s5]\n"
                "add $4,$4,%[r_s5]\n"
                "lqc2 $vf22,0($2)\n"
                "lqc2 $vf23,0($3)\n"
                "lqc2 $vf24,0($4)\n"
                "lqc2 $vf9,880(%[r_t8])\n"
                "lqc2 $vf10,848(%[r_t8])\n"
                "vitof0.wxyz $vf4,$vf4\n"
                "vitof0.wxyz $vf5,$vf5\n"
                "vitof0.wxyz $vf6,$vf6\n"
                "vmul.wxyz $vf1,$vf4,$vf10\n"
                "vmul.wxyz $vf2,$vf5,$vf10\n"
                "vmul.wxyz $vf3,$vf6,$vf10\n"
                "vadd.wxyz $vf1,$vf1,$vf9\n"
                "vadd.wxyz $vf2,$vf2,$vf9\n"
                "vadd.wxyz $vf3,$vf3,$vf9\n"
                "vmulz.wxyz $vf1,$vf1,$vf22z\n"
                "vmulz.wxyz $vf2,$vf2,$vf23z\n"
                "vmulz.wxyz $vf3,$vf3,$vf24z\n"
                "vmini.wxyz $vf1,$vf1,$vf20\n"
                "vmini.wxyz $vf2,$vf2,$vf20\n"
                "vmini.wxyz $vf3,$vf3,$vf20\n"
                "vmax.wxyz $vf1,$vf1,$vf19\n"
                "vmax.wxyz $vf2,$vf2,$vf19\n"
                "vmax.wxyz $vf3,$vf3,$vf19\n"
                "vftoi0.wxyz $vf1,$vf1\n"
                "vftoi0.wxyz $vf2,$vf2\n"
                "vftoi0.wxyz $vf3,$vf3\n"
                "sqc2 $vf1,0($15)\n"
                "sqc2 $vf2,32($15)\n"
                "sqc2 $vf3,64($15)\n"
                "vmove.w $vf15,$vf22\n"
                "vmove.w $vf16,$vf23\n"
                "vmove.w $vf17,$vf24\n"
                "vftoi4.wxyz $vf15,$vf15\n"
                "vftoi4.wxyz $vf16,$vf16\n"
                "vftoi4.wxyz $vf17,$vf17\n"
                "qmfc2 $2,$vf15\n"
                "qmfc2 $3,$vf16\n"
                "qmfc2 $4,$vf17\n"
                "sqc2 $vf15,16($15)\n"
                "sqc2 $vf16,48($15)\n"
                "sqc2 $vf17,80($15)\n"
                "addi $15,$15,96\n"
                "addi $14,$14,1\n"
                "3:\n"
                "addi %[r_s3],%[r_s3],-1\n"
                "addi $2,$14,-8\n"
                "addi %[r_t9],%[r_t9],20\n"
                "bgez $2,4f\n"
                "addi $3,$3,1\n"
                "bgtz %[r_s3],5b\n"
                "nop\n"
                "4:\n"
                "lw $2,480(%[r_t8])\n"
                "add $2,$2,$14\n"
                "sw $2,480(%[r_t8])\n"
                "beqz $14,6b\n"
                "sll $4,$13,0xb\n"
                "add $4,%[r_t8],$4\n"
                "addi $4,$4,2048\n"
                "lui $2,0x1000\n"
                "ori $2,$2,0xa000\n"
                "7:\n"
                "lw $3,0($2)\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "andi $3,$3,0x100\n"
                "bne $0,$3,7b\n"
                "lbu $6,23($4)\n"
                "srl $6,$6,0x4\n"
                "multu $6,$14\n"
                "sb $14,16($4)\n"
                "sq $0,0($4)\n"
                "li $7,112\n"
                "sb $7,3($4)\n"
                "mflo $6\n"
                "addi $6,$6,1\n"
                "sh $6,0($4)\n"
                "lui $5,0x8000\n"
                "or $4,$5,$4\n"
                "li $5,-1\n"
                "lw $6,48($2)\n"
                "bnel $6,$5,8f\n"
                "sw $4,48($2)\n"
                "8:\n"
                "lui $4,0xffff\n"
                "ori $4,$4,0xfff3\n"
                "sw $0,32($2)\n"
                "and $4,$4,$3\n"
                "ori $4,$4,0x105\n"
                "sw $4,0($2)\n"
                "b 6b\n"
                "nop\n"
                "1:\n"
                "lq $18,976(%[r_t8])\n"
                "lq $17,992(%[r_t8])\n"
                "lq $16,1008(%[r_t8])\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            goto next;
        }
        case 2: {
            register s32 left asm("$19");
            register u8* tb asm("$19") = D_00359180;
            register s32 tw asm("$8");
            register s32 th asm("$9");
            spr->tag1f0.v = 0x903dc00000008001ULL;
            spr->tag1f8.v = 0x412412412ULL;
            spr->tex.v = cmd->tex + h->texOfs;
            spr->clut.v = cmd->clut + (h->clutOfs << 5);
            tw = h->texW;
            th = h->texH;
            asm volatile(".set noreorder\n.set noat\n"
                "sq $0,864(%[r_t8])\n"
                "ld $2,288(%[r_t8])\n"
                "dsra $2,$2,0x18\n"
                "andi $3,$2,0x3c\n"
                "dsra $2,$2,0x4\n"
                "andi $4,$2,0x3c\n"
                "add $3,$3,%[r_s3]\n"
                "add $4,$4,%[r_s3]\n"
                "lw $3,0($3)\n"
                "lw $4,0($4)\n"
                "dsll $5,$3,0x10\n"
                "bnez $5,1f\n"
                "div $0,%[r_t0],$5\n"
                "break 7\n"
                "1:\n"
                "li $1,-1\n"
                "bne $5,$1,2f\n"
                "lui $1,0x8000\n"
                "bne %[r_t0],$1,2f\n"
                "nop\n"
                "break 7\n"
                "2:\n"
                "mflo %[r_t0]\n"
                "mfhi $5\n"
                "dsra $5,$5,0x4\n"
                "bnez $3,3f\n"
                "div $0,$5,$3\n"
                "break 7\n"
                "3:\n"
                "li $1,-1\n"
                "bne $3,$1,4f\n"
                "lui $1,0x8000\n"
                "bne $5,$1,4f\n"
                "nop\n"
                "break 7\n"
                "4:\n"
                "mflo $5\n"
                "mflo $5\n"
                "sw $5,864(%[r_t8])\n"
                "dsll $5,$4,0x10\n"
                "bnez $5,5f\n"
                "div $0,%[r_t1],$5\n"
                "break 7\n"
                "5:\n"
                "li $1,-1\n"
                "bne $5,$1,6f\n"
                "lui $1,0x8000\n"
                "bne %[r_t1],$1,6f\n"
                "nop\n"
                "break 7\n"
                "6:\n"
                "mflo %[r_t1]\n"
                "mfhi $5\n"
                "dsra $5,$5,0x4\n"
                "bnez $4,7f\n"
                "div $0,$5,$4\n"
                "break 7\n"
                "7:\n"
                "li $1,-1\n"
                "bne $4,$1,8f\n"
                "lui $1,0x8000\n"
                "bne $5,$1,8f\n"
                "nop\n"
                "break 7\n"
                "8:\n"
                "mflo $5\n"
                "mflo $5\n"
                "sw $5,868(%[r_t8])\n"
                "lui $2,0x1000\n"
                "ori $2,$2,0xa000\n"
                "9:\n"
                "lw $3,0($2)\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "andi $3,$3,0x100\n"
                "bne $0,$3,9b\n"
                "addi $4,%[r_t8],256\n"
                "lui $5,0x8000\n"
                "or $4,$5,$4\n"
                "li $5,-1\n"
                "lw $6,48($2)\n"
                "bnel $6,$5,10f\n"
                "sw $4,48($2)\n"
                "10:\n"
                "lui $4,0xffff\n"
                "ori $4,$4,0xfff3\n"
                "sw $0,32($2)\n"
                "and $4,$4,$3\n"
                "ori $4,$4,0x105\n"
                "sw $4,0($2)\n"
                ".set at\n.set reorder"
                : [r_t0] "+r" (tw), [r_t1] "+r" (th)
                : [r_s3] "r" (tb), [r_t8] "r" (spr)
                : "$2", "$3", "$4", "$5", "$6", "memory");
            left = cmd->count;
            D_01da8cd0[1].s += left;
            cmd++;
            asm volatile(".set noreorder\n.set noat\n"
                "sq $16,1008(%[r_t8])\n"
                "sq $17,992(%[r_t8])\n"
                "sq $18,976(%[r_t8])\n"
                ".set at\n.set reorder" : : [r_t8] "r" (spr) : "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "lw $18,768(%[r_t8])\n"
                "move $17,%[r_s4]\n"
                "li $12,4096\n"
                "lui $10,0xffff\n"
                "dsrl32 $10,$10,0x0\n"
                "dsll32 $11,$10,0x0\n"
                "or $11,$11,$10\n"
                "pcpyld $11,$10,$11\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "lbu $2,503(%[r_t8])\n"
                "srl $2,$2,0x4\n"
                "addiu $2,$2,2\n"
                "sh $2,706(%[r_t8])\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "sll $2,$2,0x4\n"
                "sh $2,704(%[r_t8])\n"
                "move $13,$0\n"
                "lui $2,0x100\n"
                "lui $3,0xffff\n"
                "ori $3,$3,0xffff\n"
                "pextlb $2,$0,$2\n"
                "pextlh $2,$0,$2\n"
                "pextlb $3,$0,$3\n"
                "pextlh $3,$0,$3\n"
                "qmtc2 $2,$vf19\n"
                "qmtc2 $3,$vf20\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "vitof0.wxyz $vf19,$vf19\n"
                "vitof0.wxyz $vf20,$vf20\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "6:\n"
                "beqz %[r_s3],1f\n"
                "addi $13,$13,1\n"
                "andi $13,$13,0x1\n"
                "lq $2,496(%[r_t8])\n"
                "sll $3,$13,0xb\n"
                "add $15,%[r_t8],$3\n"
                "addi $15,$15,2080\n"
                "sq $2,-16($15)\n"
                "move $14,$0\n"
                "5:\n"
                "move $9,$0\n"
                "lhu $2,12(%[r_t9])\n"
                "lhu $3,14(%[r_t9])\n"
                "lhu $4,16(%[r_t9])\n"
                "dsll $2,$2,0x4\n"
                "dsll $3,$3,0x4\n"
                "dsll $4,$4,0x4\n"
                "add $2,$2,$17\n"
                "add $3,$3,$17\n"
                "add $4,$4,$17\n"
                "lqc2 $vf15,0($2)\n"
                "lqc2 $vf16,0($3)\n"
                "lqc2 $vf17,0($4)\n"
                "andi $2,$18,0x10\n"
                "beqz $2,2f\n"
                "nop\n"
                "vsub.wxyz $vf7,$vf15,$vf16\n"
                "vsub.wxyz $vf8,$vf17,$vf16\n"
                "vopmula.xyz ACC,$vf7,$vf8\n"
                "vopmsub.xyz $vf9,$vf8,$vf7\n"
                "vftoi4.z $vf9,$vf9\n"
                "qmfc2 $6,$vf9\n"
                "pextuw $2,$0,$6\n"
                "sll $2,$2,0x0\n"
                "bgez $2,3f\n"
                "nop\n"
                "2:\n"
                "move $8,$0\n"
                "vsub.xyz $vf1,$vf15,$vf27\n"
                "vsub.xyz $vf2,$vf16,$vf27\n"
                "vsub.xyz $vf3,$vf17,$vf27\n"
                "vnop\n"
                "vmax.xyz $vf5,$vf1,$vf2\n"
                "vmax.xyz $vf5,$vf5,$vf3\n"
                "vmini.xyz $vf6,$vf1,$vf2\n"
                "vmini.xyz $vf6,$vf6,$vf3\n"
                "vclipw.xy $vf5,$vf28w\n"
                "vclipw.xy $vf6,$vf28w\n"
                "vclipw.xy $vf5,$vf29w\n"
                "vclipw.xy $vf6,$vf29w\n"
                "lui $2,0x28\n"
                "ori $2,$2,0x514a\n"
                "li $3,2064\n"
                "vnop\n"
                "vnop\n"
                "vnop\n"
                "vnop\n"
                "cfc2.ni $4,$vi18\n"
                "vclipw.z $vf5,$vf27w\n"
                "vclipw.z $vf6,$vf27w\n"
                "and $4,$4,$2\n"
                "bnez $4,3f\n"
                "nop\n"
                "vnop\n"
                "vnop\n"
                "vnop\n"
                "vnop\n"
                "cfc2.ni $4,$vi18\n"
                "and $4,$4,$3\n"
                "bnez $4,3f\n"
                "nop\n"
                "qmfc2 $6,$vf21\n"
                "lw $2,0(%[r_t9])\n"
                "lw $3,4(%[r_t9])\n"
                "lw $4,8(%[r_t9])\n"
                "pextlb $2,$0,$2\n"
                "pextlb $3,$0,$3\n"
                "pextlb $4,$0,$4\n"
                "pextlh $2,$0,$2\n"
                "pextlh $3,$0,$3\n"
                "pextlh $4,$0,$4\n"
                "qmtc2 $2,$vf4\n"
                "qmtc2 $3,$vf5\n"
                "qmtc2 $4,$vf6\n"
                "lhu $2,12(%[r_t9])\n"
                "lhu $3,14(%[r_t9])\n"
                "lhu $4,16(%[r_t9])\n"
                "dsll $2,$2,0x4\n"
                "dsll $3,$3,0x4\n"
                "dsll $4,$4,0x4\n"
                "add $2,$2,%[r_s5]\n"
                "add $3,$3,%[r_s5]\n"
                "add $4,$4,%[r_s5]\n"
                "lqc2 $vf22,0($2)\n"
                "lqc2 $vf23,0($3)\n"
                "lqc2 $vf24,0($4)\n"
                "lqc2 $vf9,880(%[r_t8])\n"
                "lqc2 $vf10,848(%[r_t8])\n"
                "vitof0.wxyz $vf4,$vf4\n"
                "vitof0.wxyz $vf5,$vf5\n"
                "vitof0.wxyz $vf6,$vf6\n"
                "vmul.wxyz $vf1,$vf4,$vf10\n"
                "vmul.wxyz $vf2,$vf5,$vf10\n"
                "vmul.wxyz $vf3,$vf6,$vf10\n"
                "vadd.wxyz $vf1,$vf1,$vf9\n"
                "vadd.wxyz $vf2,$vf2,$vf9\n"
                "vadd.wxyz $vf3,$vf3,$vf9\n"
                "vmulz.wxyz $vf1,$vf1,$vf22z\n"
                "vmulz.wxyz $vf2,$vf2,$vf23z\n"
                "vmulz.wxyz $vf3,$vf3,$vf24z\n"
                "vmini.wxyz $vf1,$vf1,$vf20\n"
                "vmini.wxyz $vf2,$vf2,$vf20\n"
                "vmini.wxyz $vf3,$vf3,$vf20\n"
                "vmax.wxyz $vf1,$vf1,$vf19\n"
                "vmax.wxyz $vf2,$vf2,$vf19\n"
                "vmax.wxyz $vf3,$vf3,$vf19\n"
                "vftoi0.wxyz $vf1,$vf1\n"
                "vftoi0.wxyz $vf2,$vf2\n"
                "vftoi0.wxyz $vf3,$vf3\n"
                "sqc2 $vf1,16($15)\n"
                "sqc2 $vf2,64($15)\n"
                "sqc2 $vf3,112($15)\n"
                "lq $6,864(%[r_t8])\n"
                "lw $2,20(%[r_t9])\n"
                "lw $3,24(%[r_t9])\n"
                "lw $4,28(%[r_t9])\n"
                "and $2,$2,$10\n"
                "and $3,$3,$10\n"
                "and $4,$4,$10\n"
                "pextlh $2,$0,$2\n"
                "pextlh $3,$0,$3\n"
                "pextlh $4,$0,$4\n"
                "pcpyld $2,$12,$2\n"
                "pcpyld $3,$12,$3\n"
                "pcpyld $4,$12,$4\n"
                "paddw $2,$2,$6\n"
                "paddw $3,$3,$6\n"
                "paddw $4,$4,$6\n"
                "qmtc2 $2,$vf1\n"
                "qmtc2 $3,$vf2\n"
                "qmtc2 $4,$vf3\n"
                "vitof12.xyz $vf1,$vf1\n"
                "vitof12.xyz $vf2,$vf2\n"
                "vitof12.xyz $vf3,$vf3\n"
                "vmulw.xyz $vf4,$vf1,$vf15w\n"
                "vmulw.xyz $vf5,$vf2,$vf16w\n"
                "vmulw.xyz $vf6,$vf3,$vf17w\n"
                "sqc2 $vf4,0($15)\n"
                "sqc2 $vf5,48($15)\n"
                "sqc2 $vf6,96($15)\n"
                "vmove.w $vf15,$vf22\n"
                "vmove.w $vf16,$vf23\n"
                "vmove.w $vf17,$vf24\n"
                "vftoi4.wxyz $vf15,$vf15\n"
                "vftoi4.wxyz $vf16,$vf16\n"
                "vftoi4.wxyz $vf17,$vf17\n"
                "qmfc2 $2,$vf15\n"
                "qmfc2 $3,$vf16\n"
                "qmfc2 $4,$vf17\n"
                "sqc2 $vf15,32($15)\n"
                "sqc2 $vf16,80($15)\n"
                "sqc2 $vf17,128($15)\n"
                "addi $15,$15,144\n"
                "addi $14,$14,1\n"
                "3:\n"
                "addi %[r_s3],%[r_s3],-1\n"
                "addi $2,$14,-8\n"
                "addi %[r_t9],%[r_t9],32\n"
                "bgez $2,4f\n"
                "addi $3,$3,1\n"
                "bgtz %[r_s3],5b\n"
                "nop\n"
                "4:\n"
                "lw $2,480(%[r_t8])\n"
                "add $2,$2,$14\n"
                "sw $2,480(%[r_t8])\n"
                "beqz $14,6b\n"
                "sll $4,$13,0xb\n"
                "add $4,%[r_t8],$4\n"
                "addi $4,$4,2048\n"
                "lui $2,0x1000\n"
                "ori $2,$2,0xa000\n"
                "7:\n"
                "lw $3,0($2)\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "andi $3,$3,0x100\n"
                "bne $0,$3,7b\n"
                "lbu $6,23($4)\n"
                "srl $6,$6,0x4\n"
                "multu $6,$14\n"
                "sb $14,16($4)\n"
                "sq $0,0($4)\n"
                "li $7,112\n"
                "sb $7,3($4)\n"
                "mflo $6\n"
                "addi $6,$6,1\n"
                "sh $6,0($4)\n"
                "lui $5,0x8000\n"
                "or $4,$5,$4\n"
                "li $5,-1\n"
                "lw $6,48($2)\n"
                "bnel $6,$5,8f\n"
                "sw $4,48($2)\n"
                "8:\n"
                "lui $4,0xffff\n"
                "ori $4,$4,0xfff3\n"
                "sw $0,32($2)\n"
                "and $4,$4,$3\n"
                "ori $4,$4,0x105\n"
                "sw $4,0($2)\n"
                "b 6b\n"
                "nop\n"
                "1:\n"
                "lq $18,976(%[r_t8])\n"
                "lq $17,992(%[r_t8])\n"
                "lq $16,1008(%[r_t8])\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            goto next;
        }
        case 4: {
            register s32 left asm("$19");
            {
            register u64 tag asm("$9") = 0x8036400000008001ULL;
            u32 k = 0x41414141;
            asm volatile(".set noreorder\n.set noat\n"
                "sd %[r_k],504(%[r_t8])\n"
                "sd %[r_t1],496(%[r_t8])\n"
                "lui $2,0x1000\n"
                "ori $2,$2,0xa000\n"
                "1:\n"
                "lw $3,0($2)\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "andi $3,$3,0x100\n"
                "bne $0,$3,1b\n"
                "addi $4,%[r_t8],256\n"
                "lui $5,0x8000\n"
                "or $4,$5,$4\n"
                "li $5,-1\n"
                "lw $6,48($2)\n"
                "bnel $6,$5,2f\n"
                "sw $4,48($2)\n"
                "2:\n"
                "lui $4,0xffff\n"
                "ori $4,$4,0xfff3\n"
                "sw $0,32($2)\n"
                "and $4,$4,$3\n"
                "ori $4,$4,0x105\n"
                "sw $4,0($2)\n"
                ".set at\n.set reorder"
                :
                : [r_t1] "r" (tag), [r_t8] "r" (spr), [r_k] "r" (k)
                : "$2", "$3", "$4", "$5", "$6", "memory");
            }
            asm volatile(".set noreorder\n.set noat\n"
                "lui $9,%%hi(D_01da8cd0)\n"
                "lh %[r_s3],2(%[r_t9])\n"
                "lw $15,%%lo(D_01da8cd0)($9)\n"
                "addiu %[r_t9],%[r_t9],16\n"
                "addu $15,$15,%[r_s3]\n"
                "sw $15,%%lo(D_01da8cd0)($9)\n"
                "sq $16,1008(%[r_t8])\n"
                "sq $17,992(%[r_t8])\n"
                "sq $18,976(%[r_t8])\n"
                ".set at\n.set reorder" : [r_t9] "+r" (cmd), [r_s3] "=r" (left) : [r_t8] "r" (spr) : "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "lw $18,768(%[r_t8])\n"
                "move $17,%[r_s4]\n"
                "li $12,4096\n"
                "lui $10,0xffff\n"
                "dsrl32 $10,$10,0x0\n"
                "dsll32 $11,$10,0x0\n"
                "or $11,$11,$10\n"
                "pcpyld $11,$10,$11\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "lbu $2,503(%[r_t8])\n"
                "srl $2,$2,0x4\n"
                "addiu $2,$2,2\n"
                "sh $2,706(%[r_t8])\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "sll $2,$2,0x4\n"
                "sh $2,704(%[r_t8])\n"
                "move $13,$0\n"
                "lui $2,0x100\n"
                "lui $3,0xffff\n"
                "ori $3,$3,0xffff\n"
                "pextlb $2,$0,$2\n"
                "pextlh $2,$0,$2\n"
                "pextlb $3,$0,$3\n"
                "pextlh $3,$0,$3\n"
                "qmtc2 $2,$vf19\n"
                "qmtc2 $3,$vf20\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "vitof0.wxyz $vf19,$vf19\n"
                "vitof0.wxyz $vf20,$vf20\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "6:\n"
                "beqz %[r_s3],1f\n"
                "addi $13,$13,1\n"
                "andi $13,$13,0x1\n"
                "lq $2,496(%[r_t8])\n"
                "sll $3,$13,0xb\n"
                "add $15,%[r_t8],$3\n"
                "addi $15,$15,2080\n"
                "sq $2,-16($15)\n"
                "move $14,$0\n"
                "5:\n"
                "move $9,$0\n"
                "lhu $2,16(%[r_t9])\n"
                "lhu $3,18(%[r_t9])\n"
                "lhu $4,20(%[r_t9])\n"
                "lhu $5,22(%[r_t9])\n"
                "dsll $2,$2,0x4\n"
                "dsll $3,$3,0x4\n"
                "dsll $4,$4,0x4\n"
                "dsll $5,$5,0x4\n"
                "add $2,$2,$17\n"
                "add $3,$3,$17\n"
                "add $4,$4,$17\n"
                "add $5,$5,$17\n"
                "lqc2 $vf15,0($2)\n"
                "lqc2 $vf16,0($3)\n"
                "lqc2 $vf17,0($4)\n"
                "lqc2 $vf18,0($5)\n"
                "andi $2,$18,0x10\n"
                "beqz $2,2f\n"
                "nop\n"
                "vsub.wxyz $vf7,$vf15,$vf16\n"
                "vsub.wxyz $vf8,$vf17,$vf16\n"
                "vopmula.xyz ACC,$vf7,$vf8\n"
                "vopmsub.xyz $vf9,$vf8,$vf7\n"
                "vftoi4.z $vf9,$vf9\n"
                "qmfc2 $6,$vf9\n"
                "pextuw $2,$0,$6\n"
                "sll $2,$2,0x0\n"
                "bgez $2,3f\n"
                "nop\n"
                "2:\n"
                "move $8,$0\n"
                "vsub.xyz $vf1,$vf15,$vf27\n"
                "vsub.xyz $vf2,$vf16,$vf27\n"
                "vsub.xyz $vf3,$vf17,$vf27\n"
                "vsub.xyz $vf4,$vf18,$vf27\n"
                "vmax.xyz $vf5,$vf1,$vf2\n"
                "vmax.xyz $vf5,$vf5,$vf3\n"
                "vmax.xyz $vf5,$vf5,$vf4\n"
                "vmini.xyz $vf6,$vf1,$vf2\n"
                "vmini.xyz $vf6,$vf6,$vf3\n"
                "vmini.xyz $vf6,$vf6,$vf4\n"
                "vclipw.xy $vf5,$vf28w\n"
                "vclipw.xy $vf6,$vf28w\n"
                "vclipw.xy $vf5,$vf29w\n"
                "vclipw.xy $vf6,$vf29w\n"
                "lui $2,0x28\n"
                "ori $2,$2,0x514a\n"
                "li $3,2064\n"
                "vnop\n"
                "vnop\n"
                "vnop\n"
                "vnop\n"
                "cfc2.ni $4,$vi18\n"
                "vclipw.z $vf5,$vf27w\n"
                "vclipw.z $vf6,$vf27w\n"
                "and $4,$4,$2\n"
                "bnez $4,3f\n"
                "nop\n"
                "vnop\n"
                "vnop\n"
                "vnop\n"
                "vnop\n"
                "cfc2.ni $4,$vi18\n"
                "and $4,$4,$3\n"
                "bnez $4,3f\n"
                "nop\n"
                "qmfc2 $6,$vf21\n"
                "lw $2,0(%[r_t9])\n"
                "lw $3,4(%[r_t9])\n"
                "lw $4,8(%[r_t9])\n"
                "lw $5,12(%[r_t9])\n"
                "pextlb $2,$0,$2\n"
                "pextlb $3,$0,$3\n"
                "pextlb $4,$0,$4\n"
                "pextlb $5,$0,$5\n"
                "pextlh $2,$0,$2\n"
                "pextlh $3,$0,$3\n"
                "pextlh $4,$0,$4\n"
                "pextlh $5,$0,$5\n"
                "qmtc2 $2,$vf5\n"
                "qmtc2 $3,$vf6\n"
                "qmtc2 $4,$vf7\n"
                "qmtc2 $5,$vf8\n"
                "lhu $2,16(%[r_t9])\n"
                "lhu $3,18(%[r_t9])\n"
                "lhu $4,20(%[r_t9])\n"
                "lhu $5,22(%[r_t9])\n"
                "dsll $2,$2,0x4\n"
                "dsll $3,$3,0x4\n"
                "dsll $4,$4,0x4\n"
                "dsll $5,$5,0x4\n"
                "add $2,$2,%[r_s5]\n"
                "add $3,$3,%[r_s5]\n"
                "add $4,$4,%[r_s5]\n"
                "add $5,$5,%[r_s5]\n"
                "lqc2 $vf22,0($2)\n"
                "lqc2 $vf23,0($3)\n"
                "lqc2 $vf24,0($4)\n"
                "lqc2 $vf25,0($5)\n"
                "lqc2 $vf9,880(%[r_t8])\n"
                "lqc2 $vf10,848(%[r_t8])\n"
                "vitof0.wxyz $vf5,$vf5\n"
                "vitof0.wxyz $vf6,$vf6\n"
                "vitof0.wxyz $vf7,$vf7\n"
                "vitof0.wxyz $vf8,$vf8\n"
                "vmul.wxyz $vf1,$vf5,$vf10\n"
                "vmul.wxyz $vf2,$vf6,$vf10\n"
                "vmul.wxyz $vf3,$vf7,$vf10\n"
                "vmul.wxyz $vf4,$vf8,$vf10\n"
                "vadd.wxyz $vf1,$vf1,$vf9\n"
                "vadd.wxyz $vf2,$vf2,$vf9\n"
                "vadd.wxyz $vf3,$vf3,$vf9\n"
                "vadd.wxyz $vf4,$vf4,$vf9\n"
                "vmulz.wxyz $vf1,$vf1,$vf22z\n"
                "vmulz.wxyz $vf2,$vf2,$vf23z\n"
                "vmulz.wxyz $vf3,$vf3,$vf24z\n"
                "vmulz.wxyz $vf4,$vf4,$vf25z\n"
                "vmini.wxyz $vf1,$vf1,$vf20\n"
                "vmini.wxyz $vf2,$vf2,$vf20\n"
                "vmini.wxyz $vf3,$vf3,$vf20\n"
                "vmini.wxyz $vf4,$vf4,$vf20\n"
                "vmax.wxyz $vf1,$vf1,$vf19\n"
                "vmax.wxyz $vf2,$vf2,$vf19\n"
                "vmax.wxyz $vf3,$vf3,$vf19\n"
                "vmax.wxyz $vf4,$vf4,$vf19\n"
                "vftoi0.wxyz $vf1,$vf1\n"
                "vftoi0.wxyz $vf2,$vf2\n"
                "vftoi0.wxyz $vf3,$vf3\n"
                "vftoi0.wxyz $vf4,$vf4\n"
                "sqc2 $vf1,0($15)\n"
                "sqc2 $vf2,32($15)\n"
                "sqc2 $vf3,64($15)\n"
                "sqc2 $vf4,96($15)\n"
                "vmove.w $vf15,$vf22\n"
                "vmove.w $vf16,$vf23\n"
                "vmove.w $vf17,$vf24\n"
                "vmove.w $vf18,$vf25\n"
                "vftoi4.wxyz $vf15,$vf15\n"
                "vftoi4.wxyz $vf16,$vf16\n"
                "vftoi4.wxyz $vf17,$vf17\n"
                "vftoi4.wxyz $vf18,$vf18\n"
                "qmfc2 $2,$vf15\n"
                "qmfc2 $3,$vf16\n"
                "qmfc2 $4,$vf17\n"
                "qmfc2 $5,$vf18\n"
                "sqc2 $vf15,16($15)\n"
                "sqc2 $vf16,48($15)\n"
                "sqc2 $vf17,80($15)\n"
                "sqc2 $vf18,112($15)\n"
                "lw $6,28($15)\n"
                "lw $7,60($15)\n"
                "ori $6,$6,0x8000\n"
                "ori $7,$7,0x8000\n"
                "sw $6,28($15)\n"
                "sw $7,60($15)\n"
                "addi $15,$15,128\n"
                "addi $14,$14,1\n"
                "3:\n"
                "addi %[r_s3],%[r_s3],-1\n"
                "addi $2,$14,-8\n"
                "addi %[r_t9],%[r_t9],24\n"
                "bgez $2,4f\n"
                "addi $3,$3,1\n"
                "bgtz %[r_s3],5b\n"
                "nop\n"
                "4:\n"
                "lw $2,484(%[r_t8])\n"
                "add $2,$2,$14\n"
                "sw $2,484(%[r_t8])\n"
                "beqz $14,6b\n"
                "sll $4,$13,0xb\n"
                "add $4,%[r_t8],$4\n"
                "addi $4,$4,2048\n"
                "lui $2,0x1000\n"
                "ori $2,$2,0xa000\n"
                "7:\n"
                "lw $3,0($2)\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "andi $3,$3,0x100\n"
                "bne $0,$3,7b\n"
                "lbu $6,23($4)\n"
                "srl $6,$6,0x4\n"
                "multu $6,$14\n"
                "sb $14,16($4)\n"
                "sq $0,0($4)\n"
                "li $7,112\n"
                "sb $7,3($4)\n"
                "mflo $6\n"
                "addi $6,$6,1\n"
                "sh $6,0($4)\n"
                "lui $5,0x8000\n"
                "or $4,$5,$4\n"
                "li $5,-1\n"
                "lw $6,48($2)\n"
                "bnel $6,$5,8f\n"
                "sw $4,48($2)\n"
                "8:\n"
                "lui $4,0xffff\n"
                "ori $4,$4,0xfff3\n"
                "sw $0,32($2)\n"
                "and $4,$4,$3\n"
                "ori $4,$4,0x105\n"
                "sw $4,0($2)\n"
                "b 6b\n"
                "nop\n"
                "1:\n"
                "lq $18,976(%[r_t8])\n"
                "lq $17,992(%[r_t8])\n"
                "lq $16,1008(%[r_t8])\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            goto next;
        }
        case 6: {
            register s32 left asm("$19");
            register u8* tb asm("$19") = D_00359180;
            register s32 tw asm("$8");
            register s32 th asm("$9");
            spr->tag1f0.v = 0xc03e400000008001ULL;
            spr->tag1f8.v = 0x412412412412ULL;
            spr->tex.v = cmd->tex + h->texOfs;
            spr->clut.v = cmd->clut + (h->clutOfs << 5);
            tw = h->texW;
            th = h->texH;
            asm volatile(".set noreorder\n.set noat\n"
                "sq $0,864(%[r_t8])\n"
                "ld $2,288(%[r_t8])\n"
                "dsra $2,$2,0x18\n"
                "andi $3,$2,0x3c\n"
                "dsra $2,$2,0x4\n"
                "andi $4,$2,0x3c\n"
                "add $3,$3,%[r_s3]\n"
                "add $4,$4,%[r_s3]\n"
                "lw $3,0($3)\n"
                "lw $4,0($4)\n"
                "dsll $5,$3,0x10\n"
                "bnez $5,1f\n"
                "div $0,%[r_t0],$5\n"
                "break 7\n"
                "1:\n"
                "li $1,-1\n"
                "bne $5,$1,2f\n"
                "lui $1,0x8000\n"
                "bne %[r_t0],$1,2f\n"
                "nop\n"
                "break 7\n"
                "2:\n"
                "mflo %[r_t0]\n"
                "mfhi $5\n"
                "dsra $5,$5,0x4\n"
                "bnez $3,3f\n"
                "div $0,$5,$3\n"
                "break 7\n"
                "3:\n"
                "li $1,-1\n"
                "bne $3,$1,4f\n"
                "lui $1,0x8000\n"
                "bne $5,$1,4f\n"
                "nop\n"
                "break 7\n"
                "4:\n"
                "mflo $5\n"
                "mflo $5\n"
                "sw $5,864(%[r_t8])\n"
                "dsll $5,$4,0x10\n"
                "bnez $5,5f\n"
                "div $0,%[r_t1],$5\n"
                "break 7\n"
                "5:\n"
                "li $1,-1\n"
                "bne $5,$1,6f\n"
                "lui $1,0x8000\n"
                "bne %[r_t1],$1,6f\n"
                "nop\n"
                "break 7\n"
                "6:\n"
                "mflo %[r_t1]\n"
                "mfhi $5\n"
                "dsra $5,$5,0x4\n"
                "bnez $4,7f\n"
                "div $0,$5,$4\n"
                "break 7\n"
                "7:\n"
                "li $1,-1\n"
                "bne $4,$1,8f\n"
                "lui $1,0x8000\n"
                "bne $5,$1,8f\n"
                "nop\n"
                "break 7\n"
                "8:\n"
                "mflo $5\n"
                "mflo $5\n"
                "sw $5,868(%[r_t8])\n"
                "lui $2,0x1000\n"
                "ori $2,$2,0xa000\n"
                "9:\n"
                "lw $3,0($2)\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "andi $3,$3,0x100\n"
                "bne $0,$3,9b\n"
                "addi $4,%[r_t8],256\n"
                "lui $5,0x8000\n"
                "or $4,$5,$4\n"
                "li $5,-1\n"
                "lw $6,48($2)\n"
                "bnel $6,$5,10f\n"
                "sw $4,48($2)\n"
                "10:\n"
                "lui $4,0xffff\n"
                "ori $4,$4,0xfff3\n"
                "sw $0,32($2)\n"
                "and $4,$4,$3\n"
                "ori $4,$4,0x105\n"
                "sw $4,0($2)\n"
                ".set at\n.set reorder"
                : [r_t0] "+r" (tw), [r_t1] "+r" (th)
                : [r_s3] "r" (tb), [r_t8] "r" (spr)
                : "$2", "$3", "$4", "$5", "$6", "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "lui $9,%%hi(D_01da8cd0)\n"
                "lh %[r_s3],2(%[r_t9])\n"
                "lw $15,%%lo(D_01da8cd0)($9)\n"
                "addiu %[r_t9],%[r_t9],16\n"
                "addu $15,$15,%[r_s3]\n"
                "sw $15,%%lo(D_01da8cd0)($9)\n"
                "sq $16,1008(%[r_t8])\n"
                "sq $17,992(%[r_t8])\n"
                "sq $18,976(%[r_t8])\n"
                ".set at\n.set reorder" : [r_t9] "+r" (cmd), [r_s3] "=r" (left) : [r_t8] "r" (spr) : "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "lw $18,768(%[r_t8])\n"
                "move $17,%[r_s4]\n"
                "li $12,4096\n"
                "lui $10,0xffff\n"
                "dsrl32 $10,$10,0x0\n"
                "dsll32 $11,$10,0x0\n"
                "or $11,$11,$10\n"
                "pcpyld $11,$10,$11\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "lbu $2,503(%[r_t8])\n"
                "srl $2,$2,0x4\n"
                "addiu $2,$2,2\n"
                "sh $2,706(%[r_t8])\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "sll $2,$2,0x4\n"
                "sh $2,704(%[r_t8])\n"
                "move $13,$0\n"
                "lui $2,0x100\n"
                "lui $3,0xffff\n"
                "ori $3,$3,0xffff\n"
                "pextlb $2,$0,$2\n"
                "pextlh $2,$0,$2\n"
                "pextlb $3,$0,$3\n"
                "pextlh $3,$0,$3\n"
                "qmtc2 $2,$vf19\n"
                "qmtc2 $3,$vf20\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "vitof0.wxyz $vf19,$vf19\n"
                "vitof0.wxyz $vf20,$vf20\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            asm volatile(".set noreorder\n.set noat\n"
                "6:\n"
                "beqz %[r_s3],1f\n"
                "addi $13,$13,1\n"
                "andi $13,$13,0x1\n"
                "lq $2,496(%[r_t8])\n"
                "sll $3,$13,0xb\n"
                "add $15,%[r_t8],$3\n"
                "addi $15,$15,2080\n"
                "sq $2,-16($15)\n"
                "move $14,$0\n"
                "5:\n"
                "move $9,$0\n"
                "lhu $2,16(%[r_t9])\n"
                "lhu $3,18(%[r_t9])\n"
                "lhu $4,20(%[r_t9])\n"
                "lhu $5,22(%[r_t9])\n"
                "dsll $2,$2,0x4\n"
                "dsll $3,$3,0x4\n"
                "dsll $4,$4,0x4\n"
                "dsll $5,$5,0x4\n"
                "add $2,$2,$17\n"
                "add $3,$3,$17\n"
                "add $4,$4,$17\n"
                "add $5,$5,$17\n"
                "lqc2 $vf15,0($2)\n"
                "lqc2 $vf16,0($3)\n"
                "lqc2 $vf17,0($4)\n"
                "lqc2 $vf18,0($5)\n"
                "andi $2,$18,0x10\n"
                "beqz $2,2f\n"
                "nop\n"
                "vsub.wxyz $vf7,$vf15,$vf16\n"
                "vsub.wxyz $vf8,$vf17,$vf16\n"
                "vopmula.xyz ACC,$vf7,$vf8\n"
                "vopmsub.xyz $vf9,$vf8,$vf7\n"
                "vftoi4.z $vf9,$vf9\n"
                "qmfc2 $6,$vf9\n"
                "pextuw $2,$0,$6\n"
                "sll $2,$2,0x0\n"
                "bgez $2,3f\n"
                "nop\n"
                "2:\n"
                "move $8,$0\n"
                "vsub.xyz $vf1,$vf15,$vf27\n"
                "vsub.xyz $vf2,$vf16,$vf27\n"
                "vsub.xyz $vf3,$vf17,$vf27\n"
                "vsub.xyz $vf4,$vf18,$vf27\n"
                "vmax.xyz $vf5,$vf1,$vf2\n"
                "vmax.xyz $vf5,$vf5,$vf3\n"
                "vmax.xyz $vf5,$vf5,$vf4\n"
                "vmini.xyz $vf6,$vf1,$vf2\n"
                "vmini.xyz $vf6,$vf6,$vf3\n"
                "vmini.xyz $vf6,$vf6,$vf4\n"
                "vclipw.xy $vf5,$vf28w\n"
                "vclipw.xy $vf6,$vf28w\n"
                "vclipw.xy $vf5,$vf29w\n"
                "vclipw.xy $vf6,$vf29w\n"
                "lui $2,0x28\n"
                "ori $2,$2,0x514a\n"
                "li $3,2064\n"
                "vnop\n"
                "vnop\n"
                "vnop\n"
                "vnop\n"
                "cfc2.ni $4,$vi18\n"
                "vclipw.z $vf5,$vf27w\n"
                "vclipw.z $vf6,$vf27w\n"
                "and $4,$4,$2\n"
                "bnez $4,3f\n"
                "nop\n"
                "vnop\n"
                "vnop\n"
                "vnop\n"
                "vnop\n"
                "cfc2.ni $4,$vi18\n"
                "and $4,$4,$3\n"
                "bnez $4,3f\n"
                "nop\n"
                "qmfc2 $6,$vf21\n"
                "lw $2,0(%[r_t9])\n"
                "lw $3,4(%[r_t9])\n"
                "lw $4,8(%[r_t9])\n"
                "lw $5,12(%[r_t9])\n"
                "pextlb $2,$0,$2\n"
                "pextlb $3,$0,$3\n"
                "pextlb $4,$0,$4\n"
                "pextlb $5,$0,$5\n"
                "pextlh $2,$0,$2\n"
                "pextlh $3,$0,$3\n"
                "pextlh $4,$0,$4\n"
                "pextlh $5,$0,$5\n"
                "qmtc2 $2,$vf5\n"
                "qmtc2 $3,$vf6\n"
                "qmtc2 $4,$vf7\n"
                "qmtc2 $5,$vf8\n"
                "lhu $2,16(%[r_t9])\n"
                "lhu $3,18(%[r_t9])\n"
                "lhu $4,20(%[r_t9])\n"
                "lhu $5,22(%[r_t9])\n"
                "dsll $2,$2,0x4\n"
                "dsll $3,$3,0x4\n"
                "dsll $4,$4,0x4\n"
                "dsll $5,$5,0x4\n"
                "add $2,$2,%[r_s5]\n"
                "add $3,$3,%[r_s5]\n"
                "add $4,$4,%[r_s5]\n"
                "add $5,$5,%[r_s5]\n"
                "lqc2 $vf22,0($2)\n"
                "lqc2 $vf23,0($3)\n"
                "lqc2 $vf24,0($4)\n"
                "lqc2 $vf25,0($5)\n"
                "lqc2 $vf9,880(%[r_t8])\n"
                "lqc2 $vf10,848(%[r_t8])\n"
                "vitof0.wxyz $vf5,$vf5\n"
                "vitof0.wxyz $vf6,$vf6\n"
                "vitof0.wxyz $vf7,$vf7\n"
                "vitof0.wxyz $vf8,$vf8\n"
                "vmul.wxyz $vf1,$vf5,$vf10\n"
                "vmul.wxyz $vf2,$vf6,$vf10\n"
                "vmul.wxyz $vf3,$vf7,$vf10\n"
                "vmul.wxyz $vf4,$vf8,$vf10\n"
                "vadd.wxyz $vf1,$vf1,$vf9\n"
                "vadd.wxyz $vf2,$vf2,$vf9\n"
                "vadd.wxyz $vf3,$vf3,$vf9\n"
                "vadd.wxyz $vf4,$vf4,$vf9\n"
                "vmulz.wxyz $vf1,$vf1,$vf22z\n"
                "vmulz.wxyz $vf2,$vf2,$vf23z\n"
                "vmulz.wxyz $vf3,$vf3,$vf24z\n"
                "vmulz.wxyz $vf4,$vf4,$vf25z\n"
                "vmini.wxyz $vf1,$vf1,$vf20\n"
                "vmini.wxyz $vf2,$vf2,$vf20\n"
                "vmini.wxyz $vf3,$vf3,$vf20\n"
                "vmini.wxyz $vf4,$vf4,$vf20\n"
                "vmax.wxyz $vf1,$vf1,$vf19\n"
                "vmax.wxyz $vf2,$vf2,$vf19\n"
                "vmax.wxyz $vf3,$vf3,$vf19\n"
                "vmax.wxyz $vf4,$vf4,$vf19\n"
                "vftoi0.wxyz $vf1,$vf1\n"
                "vftoi0.wxyz $vf2,$vf2\n"
                "vftoi0.wxyz $vf3,$vf3\n"
                "vftoi0.wxyz $vf4,$vf4\n"
                "sqc2 $vf1,16($15)\n"
                "sqc2 $vf2,64($15)\n"
                "sqc2 $vf3,112($15)\n"
                "sqc2 $vf4,160($15)\n"
                "lq $6,864(%[r_t8])\n"
                "lw $2,24(%[r_t9])\n"
                "lw $3,28(%[r_t9])\n"
                "lw $4,32(%[r_t9])\n"
                "lw $5,36(%[r_t9])\n"
                "and $2,$2,$10\n"
                "and $3,$3,$10\n"
                "and $4,$4,$10\n"
                "and $5,$5,$10\n"
                "pextlh $2,$0,$2\n"
                "pextlh $3,$0,$3\n"
                "pextlh $4,$0,$4\n"
                "pextlh $5,$0,$5\n"
                "pcpyld $2,$12,$2\n"
                "pcpyld $3,$12,$3\n"
                "pcpyld $4,$12,$4\n"
                "pcpyld $5,$12,$5\n"
                "paddw $2,$2,$6\n"
                "paddw $3,$3,$6\n"
                "paddw $4,$4,$6\n"
                "paddw $5,$5,$6\n"
                "qmtc2 $2,$vf1\n"
                "qmtc2 $3,$vf2\n"
                "qmtc2 $4,$vf3\n"
                "qmtc2 $5,$vf4\n"
                "vitof12.xyz $vf1,$vf1\n"
                "vitof12.xyz $vf2,$vf2\n"
                "vitof12.xyz $vf3,$vf3\n"
                "vitof12.xyz $vf4,$vf4\n"
                "vmulw.xyz $vf5,$vf1,$vf15w\n"
                "vmulw.xyz $vf6,$vf2,$vf16w\n"
                "vmulw.xyz $vf7,$vf3,$vf17w\n"
                "vmulw.xyz $vf8,$vf4,$vf18w\n"
                "sqc2 $vf5,0($15)\n"
                "sqc2 $vf6,48($15)\n"
                "sqc2 $vf7,96($15)\n"
                "sqc2 $vf8,144($15)\n"
                "vmove.w $vf15,$vf22\n"
                "vmove.w $vf16,$vf23\n"
                "vmove.w $vf17,$vf24\n"
                "vmove.w $vf18,$vf25\n"
                "vftoi4.wxyz $vf15,$vf15\n"
                "vftoi4.wxyz $vf16,$vf16\n"
                "vftoi4.wxyz $vf17,$vf17\n"
                "vftoi4.wxyz $vf18,$vf18\n"
                "qmfc2 $2,$vf15\n"
                "qmfc2 $3,$vf16\n"
                "qmfc2 $4,$vf17\n"
                "qmfc2 $5,$vf18\n"
                "sqc2 $vf15,32($15)\n"
                "sqc2 $vf16,80($15)\n"
                "sqc2 $vf17,128($15)\n"
                "sqc2 $vf18,176($15)\n"
                "lw $6,44($15)\n"
                "lw $7,92($15)\n"
                "ori $6,$6,0x8000\n"
                "ori $7,$7,0x8000\n"
                "sw $6,44($15)\n"
                "sw $7,92($15)\n"
                "addi $15,$15,192\n"
                "addi $14,$14,1\n"
                "3:\n"
                "addi %[r_s3],%[r_s3],-1\n"
                "addi $2,$14,-8\n"
                "addi %[r_t9],%[r_t9],40\n"
                "bgez $2,4f\n"
                "addi $3,$3,1\n"
                "bgtz %[r_s3],5b\n"
                "nop\n"
                "4:\n"
                "lw $2,484(%[r_t8])\n"
                "add $2,$2,$14\n"
                "sw $2,484(%[r_t8])\n"
                "beqz $14,6b\n"
                "sll $4,$13,0xb\n"
                "add $4,%[r_t8],$4\n"
                "addi $4,$4,2048\n"
                "lui $2,0x1000\n"
                "ori $2,$2,0xa000\n"
                "7:\n"
                "lw $3,0($2)\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "nop\n"
                "andi $3,$3,0x100\n"
                "bne $0,$3,7b\n"
                "lbu $6,23($4)\n"
                "srl $6,$6,0x4\n"
                "multu $6,$14\n"
                "sb $14,16($4)\n"
                "sq $0,0($4)\n"
                "li $7,112\n"
                "sb $7,3($4)\n"
                "mflo $6\n"
                "addi $6,$6,1\n"
                "sh $6,0($4)\n"
                "lui $5,0x8000\n"
                "or $4,$5,$4\n"
                "li $5,-1\n"
                "lw $6,48($2)\n"
                "bnel $6,$5,8f\n"
                "sw $4,48($2)\n"
                "8:\n"
                "lui $4,0xffff\n"
                "ori $4,$4,0xfff3\n"
                "sw $0,32($2)\n"
                "and $4,$4,$3\n"
                "ori $4,$4,0x105\n"
                "sw $4,0($2)\n"
                "b 6b\n"
                "nop\n"
                "1:\n"
                "lq $18,976(%[r_t8])\n"
                "lq $17,992(%[r_t8])\n"
                "lq $16,1008(%[r_t8])\n"
                ".set at\n.set reorder"
                : [r_t9] "+r" (cmd), [r_s3] "+r" (left)
                : [r_t8] "r" (spr), [r_s4] "r" (vtx), [r_s5] "r" (vend)
                : "$16", "$17", "$18", "memory");
            goto next;
        }
        default:
            goto done;
        }
    }
    }
    }
done:
    D_01da8cd0[5].s += spr->cnt.w[0];
    D_01da8cd0[4].s += spr->cnt.w[1];
    while (*(volatile u32*)0x1000a000 & 0x100) ;
    D_00359780.s--;
    return spr->dp.pktEnd.v;
}
}  // namespace n0021aee8

// 0021c810 (was src/anon/batch_w325.c)
namespace n0021c810 {
typedef union { u128 q; u64 d[2]; u32 w[4]; f32 f[4]; } Q128;
/*TARGET 0021c810*/
Q128* func_0021c810(Q128* p, s32 a, s32 b) asm("func_0021c810");
Q128* func_0021c810(Q128* p, s32 a, s32 b) {
    s32 i;
    p->q = 0;
    if (a == 0) p->w[3] = 0x6c40004f; else p->w[3] = 0x6c40023f;
    p++;
    for (i = 8; i != 0; i--) {
        p[0].d[0] = b ? 0x703b400000008001ULL : 0x702b400000008001ULL;
        p[0].d[1] = 0x042412e6;
        p[1].q = 0;
        p[2].d[0] = 0;
        p[2].d[1] = 66;
        p[3].q = 0;
        p[4].q = 0;
        p[5].q = 0;
        p[6].q = 0;
        p[7].q = 0;
        p[5].w[3] = 0x8000;
        p[6].f[2] = 1.0f;
        p[3].f[2] = 1.0f;
        p += 8;
    }
    return p;
}
}  // namespace n0021c810

// 0021c8c8 (was src/anon/batch_w1807_nsa.cpp)
namespace n0021c8c8 {
// ---- 0021c8c8: DMA header + 8 GIF packets (tag, TEX0, A+D, 4 x ST/RGBAQ/XYZ)
union W1807Q { w1807_u128 q; struct { f32 x, y, z; u32 w; } f; u32 w[4]; u64 d[2]; };
/*TARGET 0021c8c8*/
W1807Q* func_0021c8c8(W1807Q* p, s32 a1, s32 a2) asm("func_0021c8c8");
W1807Q* func_0021c8c8(W1807Q* p, s32 a1, s32 a2) {
    p->q = 0;
    if (!a1) p->w[3] = 0x6c78008f;
    else p->w[3] = 0x6c78027f;
    p++;
    for (s32 i = 8; i != 0; i--) {
        if (a2) p[0].d[0] = 0xe03a400000008001ULL; else p[0].d[0] = 0xe02a400000008001ULL;
        p[0].d[1] = 0x00412412412412e6ULL;
        p[1].q = 0;
        p[2].d[0] = 0; p[2].d[1] = 0x42;
        p[14].q = 0;
        p[13].q = 0;
        p[12].q = 0;
        p[11].q = 0;
        p[10].q = 0;
        p[9].q = 0;
        p[8].q = 0;
        p[7].q = 0;
        p[6].q = 0;
        p[5].q = 0;
        p[4].q = 0;
        p[3].q = 0;
        p[8].w[3] = 0x8000;
        p[5].w[3] = 0x8000;
        p[12].f.z = 1.0f;
        p[9].f.z = 1.0f;
        p[6].f.z = 1.0f;
        p[3].f.z = 1.0f;
        p += 15;
    }
    return p;
}
}  // namespace n0021c8c8

// 0021c9b0 (was src/anon/batch_w3827_nsa.c)
namespace n0021c9b0 {
typedef union { u128 q; u64 d[2]; u32 w[4]; f32 f[4]; } Q128;
typedef struct { u16 qwc; u8 mark; u8 id; u32 next; u32 p[2]; } DmaTag;
extern u64 D_0032afc0[8] asm("D_0032afc0");
extern u64 D_0032b000[6] asm("D_0032b000");
extern u64 D_0032b040[6] asm("D_0032b040");
extern u64 D_0032b080[6] asm("D_0032b080");
extern DmaTag D_0032b0d0 asm("D_0032b0d0");
extern u64 D_0032b7c0[8] asm("D_0032b7c0");
extern u64 D_0032b800[6] asm("D_0032b800");
extern u64 D_0032b840[6] asm("D_0032b840");
extern u64 D_0032b880[6] asm("D_0032b880");
extern f32 D_0032b8c0[4] asm("D_0032b8c0");
extern DmaTag D_0032b8e0 asm("D_0032b8e0");
extern f32 D_00359110[4] asm("D_00359110");
extern s32 D_00352bf4 asm("D_00352bf4");
extern u64 D_01da9010[] asm("D_01da9010");
extern u64 D_01daa930[] asm("D_01daa930");
Q128* func_0021c810(Q128* p, s32 a, s32 b) asm("func_0021c810");
Q128* func_0021c8c8(Q128* p, s32 a, s32 b) asm("func_0021c8c8");
void func_003058a0(s32) asm("func_003058a0");
/*TARGET 0021c9b0*/
void func_0021c9b0(void) asm("func_0021c9b0");
void func_0021c9b0(void) {
    s32* zbp = &D_00352bf4;
    u32 vif;
    DmaTag* t;
    u64* p;
    Q128* q;

    p = D_0032afc0;
    p[0] = 0x702b400000000001ULL;
    p[1] = 0x042412e6;
    p[2] = 0x702b400000008001ULL;
    p[3] = 0x042412e6;
    p[4] = 0xe02a400000000001ULL;
    p[5] = 0x00412412412412e6ULL;
    p[6] = 0xe02a400000008001ULL;
    p[7] = 0x00412412412412e6ULL;
    p = D_0032b000;
    p[0] = 0x2000000000008001ULL;
    p[1] = 0xee;
    p[2] = 0x7000d;
    p[3] = 0x47;
    p[4] = (u64)(*zbp | 0x31000000) | (1ULL << 32);
    p[5] = 0x4e;
    vif = 0x51000000;
    vif |= 2;
    p = D_0032b040;
    p[0] = 0x2000000000008001ULL;
    p[1] = 0xee;
    p[2] = 0x3000d;
    p[3] = 0x47;
    p[4] = (u64)(*zbp | 0x31000000) | (1ULL << 32);
    p[5] = 0x4e;
    p = D_0032b080;
    p[0] = 0x2000000000008001ULL;
    p[1] = 0xee;
    p[2] = 0x7000d;
    p[3] = 0x47;
    p[4] = (u64)(*zbp | 0x31000000) | (0ULL << 32);
    p[5] = 0x4e;
    t = &D_0032b0d0;
    t->id = 0x30;
    t->next = (u32)D_01da9010;
    t->qwc = 374;
    t->p[0] = 0;
    t->p[1] = vif;
    p = D_01da9010;
    p[0] = 0x1000000000008001ULL;
    p[1] = 14;
    p[2] = 5;
    p[3] = 8;
    p += 4;
    q = func_0021c810((Q128*)p, 0, 0);
    q = func_0021c810(q, 1, 0);
    q = func_0021c8c8(q, 0, 0);
    q = func_0021c8c8(q, 1, 0);

    p = D_0032b7c0;
    p[0] = 0x703b400000000001ULL;
    p[1] = 0x042412e6;
    p[2] = 0x703b400000008001ULL;
    p[3] = 0x042412e6;
    p[4] = 0xe03a400000000001ULL;
    p[5] = 0x00412412412412e6ULL;
    p[6] = 0xe03a400000008001ULL;
    p[7] = 0x00412412412412e6ULL;
    p = D_0032b800;
    p[0] = 0x2000000000008001ULL;
    p[1] = 0xee;
    p[2] = 0x7000d;
    p[3] = 0x47;
    p[4] = (u64)(*zbp | 0x31000000) | (1ULL << 32);
    p[5] = 0x4e;
    p = D_0032b840;
    p[0] = 0x2000000000008001ULL;
    p[1] = 0xee;
    p[2] = 0x3000d;
    p[3] = 0x47;
    p[4] = (u64)(*zbp | 0x31000000) | (1ULL << 32);
    p[5] = 0x4e;
    p = D_0032b880;
    p[0] = 0x2000000000008001ULL;
    p[1] = 0xee;
    p[2] = 0x7000d;
    p[3] = 0x47;
    p[4] = (u64)(*zbp | 0x31000000) | (0ULL << 32);
    p[5] = 0x4e;
    p = (u64*)D_0032b8c0;
    ((f32*)p)[0] = D_00359110[0];
    ((f32*)p)[1] = D_00359110[1];
    ((f32*)p)[2] = D_00359110[2];
    ((f32*)p)[3] = D_00359110[3];
    D_0032b8e0.qwc = 374;
    D_0032b8e0.id = 0x30;
    D_0032b8e0.next = (u32)D_01daa930;
    D_0032b8e0.p[0] = 0;
    D_0032b8e0.p[1] = vif;
    p = D_01daa930;
    p[0] = 0x1000000000008001ULL;
    p[1] = 14;
    p[2] = 5;
    p[3] = 8;
    p += 4;
    q = func_0021c810((Q128*)p, 0, 1);
    q = func_0021c810(q, 1, 1);
    q = func_0021c8c8(q, 0, 1);
    q = func_0021c8c8(q, 1, 1);
    func_003058a0(0);
}
}  // namespace n0021c9b0

// 0021cda0 (was src/anon/batch_w9.cpp)
namespace n0021cda0 {
void func_001e72a8(void*) asm("func_001e72a8");
extern u8 D_0032b100[] asm("D_0032b100");
extern u8 D_0032a980[] asm("D_0032a980");
/*TARGET 0021cda0*/
void func_0021cda0(s32 a) asm("func_0021cda0");
void func_0021cda0(s32 a) {
    if (a == 0) func_001e72a8(D_0032a980);
    else func_001e72a8(D_0032b100);
}
}  // namespace n0021cda0

// .rodata 0x370aa0-0x370b00: shape.c assertion strings (in place)
extern const u32 R_00370aa0[6] asm("D_00370aa0") __attribute__((aligned(4))) = { 0x65737341, 0x6f697472, 0x6166206e, 0x64656c69, 0x7325203a, 0xa };
extern const u32 R_00370ab8[8] asm("D_00370ab8") __attribute__((aligned(4))) = { 0x3e2d6873, 0x6e756f63, 0x20726574, 0x4d203d3c, 0x535f5841, 0x535f5048, 0x54495250, 0x45 };
extern const u32 R_00370ad8[4] asm("D_00370ad8") __attribute__((aligned(4))) = { 0x77617264, 0x6168732f, 0x632e6570, 0x0 };
extern const u32 R_00370ae8[6] asm("D_00370ae8") __attribute__((aligned(4))) = { 0x46202020, 0x20656c69, 0x202c7325, 0x656e694c, 0xa752520, 0x0 };

// 0021cdd0 (was src/anon/batch_w2406_nsa.c)
namespace n0021cdd0 {
typedef struct { u16 qwc; u8 mark; u8 id; u32 addr; u32 vif[2]; } Tag21cdd0;
typedef struct { s16 flags; s16 counter; u32 dataOff; u8 pad8[8]; u64 tex; u8 pad24[8]; u8 data[1]; } Shape21cdd0;
typedef struct {
    u8 pad0[16];
    s32 r, g, b;
    u8 pad28[4];
    u64 tex;
    s32 flags;
    s32 counter;
    u8 pad48[112 - 48];
    u64 spr[1];
} ShpWork21cdd0;
typedef struct { u8 pad0[8]; s32 sprites; s32 masked; } ShpStat21cdd0;
extern s32 D_00352c38 asm("D_00352c38");
extern ShpStat21cdd0 D_01da8cd0 asm("D_01da8cd0");
extern char D_00370aa0[] asm("D_00370aa0");
extern char D_00370ab8[] asm("D_00370ab8");
extern char D_00370ad8[] asm("D_00370ad8");
extern char D_00370ae8[] asm("D_00370ae8");
void func_002fdfc8(const char*, ...) asm("func_002fdfc8");
void func_001e75a8(u32) asm("func_001e75a8");
static inline void shpAssert(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_00370aa0, e);
    func_002fdfc8(D_00370ae8, f, l);
    asm volatile("break");
}
/*TARGET 0021cdd0*/
void func_0021cdd0(Shape21cdd0* sh, ShpWork21cdd0* w) asm("func_0021cdd0");
void func_0021cdd0(Shape21cdd0* sh, ShpWork21cdd0* w)
{
    s32 n, q, q1;
    u64* spr;
    u64* src;
    u64* dst;
    Tag21cdd0* t;
    Tag21cdd0* p;
    if (!(sh->counter <= 8)) {
        shpAssert(D_00370ab8, D_00370ad8, 338);
    }
    if (D_00352c38) {
        w->b = w->g = w->r = (s32)((f32)w->r * 0.30000001192092896f + (f32)w->g * 0.5899999737739563f + (f32)w->b * 0.10999999940395355f);
    }
    w->flags = sh->flags;
    w->counter = sh->counter;
    w->tex = sh->tex;
    src = (u64*)((u8*)sh + sh->dataOff);
    spr = w->spr;
    dst = spr;
    n = sh->counter;
    while (n--) *dst++ = *src++;
    q = (s32)(((u64)(sh->counter * 8) + 15) & ~15) / 16;
    t = (Tag21cdd0*)((u8*)spr + q * 16);
    p = t;
    p->qwc = 7;
    p->id = 0x30;
    p->addr = (u32)w | 0x80000000;
    p->vif[0] = 0;
    p->vif[1] = 0x6c078000;
    p = t + 1;
    q1 = (s32)(((u64)sh->dataOff - 32 + 15) & ~15) / 16;
    p->qwc = q1;
    p->id = 0x30;
    p->addr = (u32)sh->data;
    p->vif[0] = 0;
    p->vif[1] = (q1 << 17) | 0x6d008007;
    p = t + 2;
    p->qwc = q;
    p->id = 0x30;
    p->addr = (u32)spr | 0x80000000;
    p->vif[0] = 0;
    p->vif[1] = (q << 18) | 0x6e00c01f;
    p = t + 3;
    p->qwc = 0;
    p->id = 0x70;
    p->addr = 0;
    p->vif[0] = 0x13000000;
    p->vif[1] = 0x17000000;
    func_001e75a8((u32)t | 0x80000000);
    if (sh->flags & 8) D_01da8cd0.masked += sh->counter;
    D_01da8cd0.sprites += sh->counter;
}
}  // namespace n0021cdd0

