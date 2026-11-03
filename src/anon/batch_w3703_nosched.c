// Built with -O2 -fno-schedule-insns (_nosched).
#include "../common/types.h"

typedef unsigned int u128 __attribute__((mode(TI)));
typedef struct Pk20e { u8 pad[16]; u64 tag; u64 regs; union { u128 q; struct { u8 b[8]; u64 reg; } s; } m; u128 col; u128 v64; u128 v80; } Pk20e;
typedef struct Cnt20e { u32 x0; u32 x4; u32 x8; u32 xc; u32 x10; u32 x14; u32 x18; } Cnt20e;
extern u64 D_00370780;
extern u128 D_00370790;
extern u128 D_003707a0;
extern Cnt20e D_01da8cd0;
void func_0020e800(void*, s32, s32, s32);

// Fills a GS packet (tag, two-byte register pair, colour widened from RGBA bytes, two fixed qwords),
// sends it and bumps the packet counters. Returns the end of the packet.
// Partial asm: sq $0 (zero qword), pextlb/pextlh (MMI) and the sq of their result; keeping that sq inside the
// asm block lets sched2 issue li a1,6 right after it like the original.
u8* func_0020e8b0(Pk20e* p, u32 rgba, u8 a, u8 b)
{
    u128 c;
    p->tag = D_00370780;
    p->regs = 0x441e;
    asm volatile("sq $0,%0" : "=m"(p->m.q));
    p->m.s.b[0] = a;
    p->m.s.b[4] = b;
    p->m.s.reg = 0x42;
    asm volatile("pextlb %0,$0,%0\n\tpextlh %0,$0,%0\n\tsq %0,%1" : "=r"(c), "=m"(p->col) : "0"(rgba));
    { u128* g = &D_00370790; p->v64 = *g; }
    { u128* g = &D_003707a0; p->v80 = *g; }
    func_0020e800(p, 6, 0, 0);
    D_01da8cd0.x8++;
    D_01da8cd0.x18++;
    return (u8*)p + 96;
}
typedef f32 FVEC208[4] __attribute__((aligned(16)));
typedef f32 FMTX208[4][4] __attribute__((aligned(16)));
typedef struct Obj208 { u8 pad0[0x26]; u8 mode; u8 pad27[0xde]; u8 useMatrix; } Obj208;
typedef struct Xform208 { FMTX208 m; u8 pad40[8]; s32 rot[3]; u8 pad54[0x18]; f32 scale[3]; } Xform208;
extern FMTX208 D_01d9e730;
extern FMTX208 D_01d9e840;
extern FMTX208 D_01d9e880;
extern FMTX208 D_01d9e8c0;
extern u8* D_01d9e6e8;
void func_002f3cd8(f32* out, f32 (*m)[4], f32* in);       // sceVu0ApplyMatrix
void func_002f3d08(f32 (*out)[4], f32 (*a)[4], f32 (*b)[4]); // sceVu0MulMatrix
void func_002f3f40(f32* out, f32* in, f32 s);           // sceVu0ScaleVector
void func_002f3f88(f32* out, f32* in);                  // sceVu0CopyVector
void func_002f3f98(f32 (*out)[4], f32 (*in)[4]);         // sceVu0CopyMatrix
void func_002f4000(f32 (*m)[4]);                        // sceVu0UnitMatrix
void func_002f4298(f32 (*out)[4], f32 (*in)[4], f32* rot); // sceVu0RotMatrix


// Builds an object's local matrix (copy or unit + translation, optional rotation from 16-bit angles, per-axis scale),
// then places it with the view, the parent bone or the billboard matrix and optionally saves it.
// Register pins on call arguments only reproduce the original's argument-move order (no asm instructions).
void func_00208a30(f32 (*view)[4], f32 (*m)[4], Obj208* o, Xform208* x, f32 (*parent)[4], f32 (*save)[4], u8 doSave) {
    FVEC208 v;
    FMTX208 tmp;
    FMTX208 rot;
    FVEC208 r;
    s32 i;
    struct { f32 (*p)[4]; u32 pad; } vw;
    u8 um = o->useMatrix;
    vw.p = view;
    if (um) {
        func_002f3f98(m, x->m);
    } else {
        register f32 (*a0)[4] asm("$4") = m;
        f32* m3 = m[3];
        func_002f4000(a0);
        func_002f3f88(m3, x->m[3]);
    }
    if (*(u64*)x->rot != 0 || x->rot[2] != 0) {
        for (i = 0; i < 3; i++) r[i] = x->rot[i] * 3.1415927f * 3.0517578125e-05f;
        func_002f4000(rot);
        { register f32 (*q4)[4] asm("$4") = rot; register f32* q6 asm("$6") = r; register f32 (*q5)[4] asm("$5") = rot;
        func_002f4298(q4, q5, q6); }
        func_002f3d08(m, m, rot);
    }
    for (i = 0; i < 3; i++) func_002f3f40(m[i], m[i], x->scale[i]);
    switch (o->mode) {
    default:
        if (parent == 0) {
            func_002f3f88(v, m[3]);
            func_002f3d08(m, D_01d9e840, m);
            func_002f3cd8(m[3], vw.p, v);
        } else {
            { register f32 (*w5)[4] asm("$5") = parent; register f32 (*w4)[4] asm("$4") = tmp; register f32 (*w6)[4] asm("$6") = (f32 (*)[4])(D_01d9e6e8 + 16);
            func_002f3d08(w4, w5, w6); }
            func_002f3d08(tmp, D_01d9e730, tmp);
            func_002f3f88(v, m[3]);
            func_002f3d08(m, D_01d9e840, m);
            func_002f3cd8(m[3], tmp, v);
        }
        break;
    case 1: case 3: case 5: case 7: case 9:
        func_002f3cd8(v, vw.p, m[3]);
        func_002f3d08(m, D_01d9e880, m);
        func_002f3f88(m[3], v);
        break;
    }
    if (doSave) func_002f3f98(save, m);
    func_002f3d08(m, D_01d9e8c0, m);
}
