#include "../common/types.h"

// 0x17c400-0x17d968: the rest of the file before YS::FRIEND after the never-written VU0 method 0x17c290:
// the two motor/flag classes (vtable 0x34eb88: incl. the never-written entries 0x17cbf8 and 0x17cd08)
// and the YS::MATH helpers (FixRadian, RotToDir, axis rotations, vector angles, digit count).
// Each function keeps the declarations of the source it was matched in (namespace xN); every symbol
// is bound by asm label.

// 0017c400 (src/anon/auto200_999.cpp)
namespace x6 {
typedef void (*Fn_00322908)(u32, u32);
extern u8 D_004f3700 asm("D_004f3700");
void dk_MapColor_getOnColorTable(u32, u32) asm(
    "_ZN2dk8MapColor15getOnColorTableEPhi");
void dk_RectParamBase_setColor(u32, u32, u32, u32,
                               u32) asm("_ZN2dk13RectParamBase8setColorEhhhh");

void func_0017c400(u32 a0, u32 a1) {
    register u32 v asm("$13") = *(u32 *)(a0 + 268);
    register u32 m asm("$15") = (u32)-2;
    register u32 neg asm("$14") = (u32)-1;
    asm volatile("" : "+r"(v), "+r"(m), "+r"(neg));
    *(volatile u8 *)(a0 + 1300) = a1;
    v &= m;
    asm volatile("" ::: "memory");
    *(volatile u32 *)(a0 + 256) = neg;
    m = 5;
    *(volatile u32 *)(a0 + 268) = v;
    *(volatile u32 *)(a0 + 260) = m;
    *(volatile u32 *)(a0 + 204) = 0;
}
}  // namespace x6

// 0017c430 (src/anon/batch_w1552.cpp)
namespace x7 {
f32 func_0017d130(f32) asm("func_0017d130");
void func_0017c400(u8*, s32) asm("func_0017c400");
struct J_17c430 { u8 pad[0xd0]; f32 d0, d4, d8, dc; };

void func_0017c430(J_17c430* a0, f32 x) {
    if (0.0f <= x) {
        a0->d0 = 0.0f;
        a0->d8 = 0.0f;
        a0->dc = -x;
        a0->d4 = func_0017d130(x);
    } else {
        a0->dc = 0.0f;
        a0->d0 = __builtin_sqrtf(x * -2.0f / 0.40816325f);
        a0->d8 = x;
        a0->d4 = 0.0f;
    }
    func_0017c400((u8*)a0, 1);
}
}  // namespace x7

// 0017c4c8 (src/anon/batch_w1784.cpp)
namespace x8 {
#define W1784_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define W1784_QCOPY4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct W1784QV {
    f32 x, y, z, w;
    W1784QV() {}
    W1784QV(const W1784QV& o) { W1784_QCOPY(this, &o); }
    W1784QV& operator=(const W1784QV& o) { if (this != &o) W1784_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline f32 w1784_norm(W1784QV* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline W1784QV w1784_scale(const W1784QV* v, f32 s) {
    W1784QV r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(v), "f"(s) : "$8", "memory");
    return r;
}
struct W1784C4 { u8 pad[0xc0]; W1784QV dir; };
void func_0017c430(W1784C4*, f32) asm("func_0017c430");

void func_0017c4c8(W1784C4* c, W1784QV* v) {
    func_0017c430(c, v->y);
    v->y = 0.0f;
    f32 w = v->w;
    w1784_norm(v);
    c->dir = w1784_scale(v, w);
    c->dir.w = 1.0f;
}
}  // namespace x8

// 0017c578 (src/anon/batch_w76.cpp)
namespace x9 {
f32* func_0016c028(u8*) asm("func_0016c028");  // obj_get_attach_or_alt
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
s32 func_00114620(u32) asm("func_00114620");
u32 func_0016a070(u32) asm("func_0016a070");
s32 func_001a35f8(s32, u32) asm("func_001a35f8");
u8* func_001058e8(void) asm("func_001058e8");
u8* func_00188fe0(u8*, u32) asm("func_00188fe0");
struct Entry { u16 id : 15; u16 on : 1; };
u32 ctarget_0010f7b0(u32, u32, s32, u32) asm("_Z16ctarget_0010f7b0jjjj");
typedef void (*VFn)(void*);
typedef void (*VFn2)(void*, u32);
typedef void (*VFn4)(void*, u32, u32, u32);
struct Bits8 { u32 b0 : 1; u32 hi : 31; };
static inline bool InfoFlag(u8* info) { return ((Bits8*)(info + 8))->b0; }

void flagupd_0017c578(void*, u8* o) asm("_Z13func_0017c578Pv");
void flagupd_0017c578(void*, u8* o)
{
    u32 fl = *(u32*)(o + 264);
    if (fl & 0x10000) *(u32*)(o + 264) = fl | 0x20000;
    else *(u32*)(o + 264) = fl & ~0x20000;
    *(u32*)(o + 264) &= ~0x10000;
    f32* v = func_0016c028(o);  // obj_get_attach_or_alt
    *(f32*)(o + 216) += v[1];
    if (0.0f < *(f32*)(o + 204)) {
        Q16* d = (Q16*)(o + 32);
        Q16* s = (Q16*)(o + 192);
        if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    }
    *(u32*)(o + 264) &= ~0x800000;
    *(u32*)(o + 268) |= 1;
    *(u32*)(o + 264) &= ~0x1000000;
    if (!InfoFlag(*(u8**)(o + 12))) *(u32*)(o + 268) |= 2;
}
}  // namespace x9

// 0017c660 (src/anon/tiny_auto80_fptr4.cpp)
namespace x10 {

void func_0017c660(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r12, r13, r14, r15;
    r15 = *(u32*)((u32)r5 + (s32)(264));
    r13 = (u32)(0xfffeu << 16);
    r13 = (u32)(r13 | 0xffffu);
    r14 = (u32)(0xfffdu << 16);
    r12 = (u32)(0xfffbu << 16);
    r15 = (u32)(r15 & r13);
    r14 = (u32)(r14 | 0xffffu);
    r12 = (u32)(r12 | 0xffffu);
    r15 = (u32)(r15 & r14);
    r15 = (u32)(r15 & r12);
    *(u32*)((u32)r5 + (s32)(264)) = r15;
}
}  // namespace x10

// 0017c690 (src/anon/batch_w111.cpp)
namespace x11 {
typedef unsigned int u128  asm("u128")__attribute__((mode(TI)));
struct Mtx11 { u128 q[4]; };
struct VObj11 { void** vt; };
#define MCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t" \
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" \
                         : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
typedef void (*Fn11a)(VObj11*, u8*, Mtx11*, u32, u32, f32);
typedef void (*Fn11b)(VObj11*, u8*);
#define QCOPY12(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define MCOPY12(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t" \
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" \
                         : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct V12 { f32 x, y, z, w;
    V12& operator=(const V12& o) { if (this != &o) QCOPY12(this, &o); return *this; }
} __attribute__((aligned(16)));
struct M12 { V12 r[4];
    M12& operator=(const M12& o) { if (this != &o) MCOPY12(this, &o); return *this; }
};
struct Heap12 { void** vt; };
struct Src12Info { u8 pad[4]; s32 kind; };
struct Src12Sub { void** vt; Src12Info* info; };
struct Src12Tbl { u8 pad[8]; s32 n; u8 pad2[4]; u8 data[1]; };
struct Src12 {
    u8 pad[12]; u32 flags; u8 pad2[4]; Src12Sub* shape; Src12Sub* sub; V12* pos; V12* scl; u8 pad3[4]; union { M12* mtx; f32 fx; };
};
struct Dst12 { V12* pos; union { M12* mtx; f32 fx; }; u8 pad[4]; union { s32 f12; Src12Sub* f12p; }; void* tbl; Src12Sub* shape; u8 b24; u8 b25; };
void func_00124828(Dst12*) asm("func_00124828");
void* func_00124c48(Src12Sub*, s32) asm("func_00124c48");
void memcpy(void*, void*, s32) asm("memcpy");
Dst12* func_00127a88(Src12* o, Heap12* heap) asm("_Z13func_00127a88Pv");
typedef s32 (*CountFn12)(Src12Sub*);
typedef s32 (*SubFn12)(Src12Sub*, Src12*, Heap12*);
struct NoTail14 { ~NoTail14() {} };
struct SObj14 { void** vt; u8 pad[268]; };
extern SObj14 D_003493a0 asm("D_003493a0");
extern SObj14 D_003494b0 asm("D_003494b0");
extern SObj14 D_003495c0 asm("D_003495c0");
extern SObj14 D_003496d0 asm("D_003496d0");
extern SObj14 D_003497e0 asm("D_003497e0");
extern SObj14 D_003498f0 asm("D_003498f0");
extern SObj14 D_00349a00 asm("D_00349a00");
extern void* D_00349b40[] asm("D_00349b40");
void func_0014a950(SObj14*) asm("func_0014a950");
void func_0031bb08(SObj14*) asm("func_0031bb08");  // set_vtbl_3486a8
void func_0014aed0(int init, int prio) asm("_Z13func_0014aed0ii");
extern u8 D_00349e20 asm("D_00349e20");
extern u32 D_00349e1c asm("D_00349e1c");
extern u32 D_00349e08 asm("D_00349e08");
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_00349e0c asm("D_00349e0c");
extern f32 D_00349e14 asm("D_00349e14");
extern f32 D_00349e18 asm("D_00349e18");
void func_0014d478(void) asm("func_0014d478");
void u_tail0_0014d060(void) asm("_Z16u_tail0_0014d060v");
struct Motor17 { void** vt; };
struct Info17 { u8 pad[4]; f32 f4; };
struct Obj17 {
    u8 pad[12]; Motor17* motor; u8 pad2[192]; f32 t; f32 end; u8 pad3[48]; union { u32 flags; struct { u32 b0:17; u32 b17:1; u32 b18:1; u32 rest:13; } fb; };
    u8 pad4[1148]; u32 mode; u8 pad5[1060]; f32 f2480;
};
typedef void (*MotorFn17)(Motor17*, Obj17*, f32);
extern Info17* D_00352130 asm("D_00352130");
s32 func_0017ca88(void*, Obj17*) asm("func_0017ca88");
s32 func_001958d0(Obj17*) asm("func_001958d0");
s32 func_0017cb48(void*, Obj17*) asm("func_0017cb48");  // can_run_when_268_bit0
void func_0017cb78(void*, Obj17*) asm("func_0017cb78");  // handle_field256_eq4

// Animation-window step: fires the motor callbacks when the play time enters / leaves the active windows.
void func_0017c690(void* self, Obj17* o)
{
    u64 unused[2]; // keeps the original's 48-byte frame
    if ((o->mode & 4) && func_0017ca88(self, o) && func_001958d0(o)) return;
    if (6.0f < o->t && o->t < o->end) {
        if (o->flags & 0x400000) {
            if (func_0017cb48(self, o)) func_0017cb78(self, o);  // can_run_when_268_bit0
            ((MotorFn17)o->motor->vt[3])(o->motor, o, 0.0f);
            o->fb.b17 = 0;
            o->fb.b18 = 0;
            if (o->mode & 4) o->f2480 = D_00352130->f4;
        }
    }
    if ((o->flags & 0x40000) && 6.0f < o->t && o->t < o->end - 5.0f) {
        if (func_0017cb48(self, o)) func_0017cb78(self, o);  // can_run_when_268_bit0
        ((MotorFn17)o->motor->vt[3])(o->motor, o, 5.10204f);
        o->fb.b18 = 0;
    } else if (o->end <= o->t + 5.0f) {
        if (func_0017cb48(self, o)) func_0017cb78(self, o);  // can_run_when_268_bit0
        o->fb.b17 = 0;
    }
}
}  // namespace x11

// 0017c870 (src/anon/batch_w53.cpp)
namespace x12 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct NoTail { ~NoTail() {} };
struct S349 { u8 pad[736]; u8 a[16]; u8 b[480]; u8 c; };
typedef void (*Fn0)(u8*);
typedef void (*Fn1)(void*, void*);
typedef void (*Fn3)(u32, u32, u32);
typedef u32 (*Fn8)(u8*, u32, u32, u32, u32, u32, u8, u32);
typedef void (*VFn)(u8*);
typedef void (*VFn0)(void);
void wtarget_0011e9a8(u32, u32, u32, u32, f32) asm("_Z16wtarget_0011e9a8jjjj");
void func_0014e1f0(s32, s32) asm("_Z13func_0014e1f0ii");
void ctarget0_00187b90(u8*) asm("_Z17ctarget0_00187b90v");
extern S349 D_00349f00 asm("D_00349f00");
extern f32 D_00349e10 asm("D_00349e10");
void* func_0011e7e0(u32, void*, u32, u32, u32) asm("func_0011e7e0");
void func_00132370(void*, f32) asm("func_00132370");
void func_00166930(u8*) asm("func_00166930");
void func_0014dc08(u8*) asm("func_0014dc08");
void func_0014dd10(u8*) asm("func_0014dd10");
void func_00184540(Q16*, u8*) asm("func_00184540");
f32 func_0017c930(u8*, u8*) asm("func_0017c930");
void func_001002a0(s32) asm("func_001002a0") __attribute__((noreturn));

Q16* func_0017c870(Q16* ret, u8* a1, u8* a2) {
    union UF { u32 u; f32 f; };
    ((UF*)(a2 + 208))->f += D_00349e10;
    ((UF*)(a2 + 20))->u = 0;
    Q16 t;
    func_00184540(&t, a2);
    if (ret != &t) QCOPY(ret, &t);
    *(f32*)&ret->w[1] = func_0017c930(a1, a2);
    return ret;
}
}  // namespace x12

// 0017c8f0 (src/anon/batch_wlit.cpp)
namespace x13 {
void func_0017c870(u8* p, f32 a, f32 b) asm("func_0017c870");

u8* func_0017c8f0(u8* p) { func_0017c870(p, 0.9f, 0.95f); return p; }
}  // namespace x13

// 0017c930 (src/anon/batch_w2388.cpp)
namespace x14 {
struct V4c17c930 { f32 x, y, z, w; };
struct Obj17c930 {
    u8 pad0[0xd0];
    f32 t, len, base, amp;
    u8 pade0[0x120 - 0xe0];
    f32 scale;
    u8 pad124[0x160 - 0x124];
    u32 flags;
};
V4c17c930* func_0016c028(Obj17c930*) asm("func_0016c028");
f32 sinf(f32) asm("sinf");
extern f32 D_00349e10 asm("D_00349e10");
static inline u32 flag20(Obj17c930* o) { return o->flags & 0x20; }
static inline u32 flag1000000(Obj17c930* o) { return o->flags & 0x1000000; }
static inline u32 flag40(Obj17c930* o) { return o->flags & 0x40; }
static inline bool frozen(Obj17c930* o) { return flag20(o) || flag1000000(o); }
static inline bool stopped(Obj17c930* o) { return frozen(o) || flag40(o); }
static inline bool moving(Obj17c930* o) { return !stopped(o); }

/* 0017c930: offset that follows sinf(sinf(t*pi/2)*pi/2) while t < len and a parabola
   after it, measured from the current position (func_0016c028()->y) and clamped to scale * D_00349e10. */
f32 func_0017c930(void* self, Obj17c930* o) {
    if (moving(o)) {
        f32 r;
        f32 a = o->t; f32 b = o->len;
        if (a < b) {
            f32 t = a / b;
            t = sinf(sinf(t * 3.14159274f * 0.5f) * 3.14159274f * 0.5f);
            r = o->base + o->amp * t;
        } else {
            f32 t = a - b;
            r = o->base + o->amp + t * 0x1.a1f58cp-2f * t * 0.5f;
        }
        f32 v = r - func_0016c028(o)->y;
        f32 lim = o->scale * D_00349e10;
        if (v < lim) return r - func_0016c028(o)->y;
        return lim;
    }
    return 0.0f;
}
}  // namespace x14

// 0017ca88 (src/anon/batch_w2373.cpp)
namespace x15 {
static inline u8 ca88_anyFlag(u32 fl) {
    u8 r = 0;
    if (fl & 4) goto set;
    if (fl & 8) goto set;
    if (!(fl & 0x10)) goto out;
set:
    r = 1;
out:
    return r;
}

/* 0017ca88: true when p has state flag 4/8/0x10, is not blocked (1416&2 && 2040&4), and the height at +208
   exceeds 15 (or the reference at +212 plus 6 when that is set). */
s32 func_0017ca88(void* self, u8* p)
{
    u8 m = ca88_anyFlag(*(u32*)(p + 352));
    if (!m) return 0;
    if ((*(u32*)(p + 1416) & 2) && (*(u32*)(p + 2040) & 4)) return 0;
    f32 h = *(f32*)(p + 212);
    if (h == 0.0f) return 15.0f < *(f32*)(p + 208);
    return h + 6.0f < *(f32*)(p + 208);
}
}  // namespace x15

// 0017cb48 (src/anon/tiny_auto80_queue.cpp)
namespace x16 {
typedef u32  (*Fn_002cf1b8)(u32, u32);

u32 func_0017cb48(u32 a0, u32 a1) {  // can_run_when_268_bit0
    u32 v0 = 0u;
    u32 t7 = *(u32*)((u32)a1 + (s32)(268));
    t7 = (u32)(t7 & 1u);
    if (t7 != 0u) {
        t7 = *(u32*)((u32)a1 + (s32)(256));
        if ((s32)t7 >= 0) {
            t7 = *(u32*)((u32)a1 + (s32)(360));
            t7 = (u32)(t7 & 0x10u);
            v0 = (u32)(t7 < 1u);
        }
    }
    return v0;
}
}  // namespace x16

// 0017cb78 (src/anon/batch_w56.cpp)
namespace x17 {
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_00180c88(u8*, s32, f32) asm("func_00180c88");

void func_0017cb78(void* unused, u8* p)
{
    s32 s = *(s32*)(p + 256);
    if (s == 4) func_0017f488(p + 320, 4, 8.0f, 0.0f);
    else if (s >= 0) func_00180c88(p + 320, s, 8.0f);
    *(u32*)(p + 268) &= ~1;
}
}  // namespace x17

// 0017cbf8: virtual (vtable at 0x34eb88): run 0x17cb78, then set flag 0x4000000 on the target (never written before)
namespace x_cbf8 {
void func_0017cb78(u8*, u8*) asm("func_0017cb78");

void func_0017cbf8(u8* a, u8* b) asm("func_0017cbf8");
void func_0017cbf8(u8* a, u8* b) {
    func_0017cb78(a, b);
    *(u32*)(b + 264) |= 0x4000000;
}
}  // namespace x_cbf8

// 0017cc30 (src/anon/batch_w1800.cpp)
namespace x18 {
struct Cc30Obj { u8 pad[0x104]; s32 action; u32 flags108; u8 pad2[0x140 - 0x10c]; u8 mot[0x28]; u32 flags168; };
/* 0017cc30 */
void func_00180c88(u8*, s32, f32) asm("func_00180c88");
void cc30_17f488(u8*, s32, f32, f32) asm("_Z13func_0017f488iiff");
void cc30_push(u8*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
s32 cc30_is_exist(u8*, s32) asm("_ZN2YS6MOTION8is_existEi");
void cc30_change_action(Cc30Obj*, u32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");

void wtarget_0017cc30(u32, Cc30Obj*, u32, u32) asm("_Z16wtarget_0017cc30jjjj");
void wtarget_0017cc30(u32 a0, Cc30Obj* o, u32 act, u32 a3) {
    u8* m = o->mot;
    s32 a = o->action;
    if (a >= 0 && !(o->flags168 & 0x10)) {
        if (a != 5) {
            func_00180c88(m, a, 0.0f);
            cc30_push(m, 0, 0.0f, 0.0f, 0);
        } else if (cc30_is_exist(m, 5)) {
            cc30_17f488(m, 5, 0.0f, 0.0f);
            cc30_push(m, 0, 0.0f, 0.0f, 0);
        }
    }
    cc30_change_action(o, act);
    o->flags108 |= 0x8000000;
}
}  // namespace x18

// 0017cd08: virtual (vtable at 0x34eb88): 0x17cc30 with a2 = 0 (never written before)
namespace x_cd08 {
void func_0017cc30(u8*, u8*, u32) asm("_Z16wtarget_0017cc30jjjj");

void func_0017cd08(u8* a, u8* b) asm("func_0017cd08");
void func_0017cd08(u8* a, u8* b) {
    func_0017cc30(a, b, 0);
}
}  // namespace x_cd08

// 0017cd20 (src/anon/batch_w82.cpp)
namespace x19 {
struct Vec82 {
    f32 x, y, z, w;
    Vec82& operator=(const Vec82& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
u32 func_00177860(u8*) asm("func_00177860");
s32 func_001c3618(u32, s32) asm("func_001c3618");
u8* func_001ce300(s32) asm("func_001ce300");  // to_1ce2a0_index_minus1
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");

void func_0017cd20(u8* a0, u8* a1)
{
    Vec82 v;
    u8* r;
    s32 n = func_001c3618(func_00177860(a1), 2);
    if (n < 5) {
        if (!n) return;
        if (!(*(u32*)(a1 + 268) & 2)) return;
    }
    r = func_001ce300(n);  // to_1ce2a0_index_minus1
    v = *(Vec82*)(a1 + 16);
    if (0.0f < v.w) v.w = *(f32*)(r + 8);
    v.y = *(f32*)(r + 4);
    func_0017f488(a1 + 320, 202, 0.0f, 0.0f);
    {
        u8* o = *(u8**)(a1 + 12);
        (*(void (**)(u8*, u8*, Vec82*))(*(u8**)o + 8))(o, a1, &v);
    }
    *(u32*)(a1 + 264) |= 0x10000;
    *(u32*)(a1 + 256) = 4;
    *(u32*)(a1 + 260) = 5;
    *(u32*)(a1 + 268) &= ~2;
}
}  // namespace x19

// 0017ce10 (src/anon/batch_w46.cpp)
namespace x20 {
void operator delete[](void*) asm("func_00106450");
void wtarget_0011c828(u8* o, u32 a1, u32, u32) asm("_Z16wtarget_0011c828jjjj");
void wtarget_00160de0(u32 id, u32, u32, u32) asm("_Z16wtarget_00160de0jjjj");
u8* ctarget_001947c0(s32 a, s32 b, u32, u32) asm("_Z16ctarget_001947c0jjjj");
void wtarget_001e0750(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001e0750jjjj");
void ctarget_0028e350(u8* p, u32, u32, u32) asm("_Z16ctarget_0028e350jjjj");
void func_001397d8_i(s32 id) asm("_Z13func_001397d8i");
f32 FixRadian46(f32 x) asm("_ZN2YS4MATH9FixRadianEf");
void Activate46(char*) asm("_ZN2YS4UNIT8ActivateEPc");
struct VObj11c { void (**vt)(VObj11c*, u32, u32); };
s32 func_0011f078(VObj11c*, u32) asm("func_0011f078");
struct Node139 { void (**vt)(Node139*); Node139* next; u32 pad[2]; s32 id; };
struct Head139 { u32 pad; Node139* first; };
extern Head139* D_00347f80 asm("D_00347f80");
static inline Node139* Next139(Node139* n) {
    Head139* h = D_00347f80;
    if (!n) return h->first;
    return n->next;
}
struct Node160 { u8 pad[128]; Node160* next; u8 pad2[292]; u32 id; };
extern Node160* D_004f3b38 asm("D_004f3b38");
void func_00160d28(Node160*) asm("func_00160d28");
static inline Node160* Next160(Node160* n) {
    if (!n) return D_004f3b38;
    return n->next;
}
f32 func_002f8b00(f32, f32) asm("func_002f8b00");  // to_2f9a38

f32 FixRadian46(f32 x) {
    if (0.0f < x) return func_002f8b00(x + 3.1415927f, 6.2831855f) - 3.1415927f;
    return 3.1415927f - func_002f8b00(3.1415927f - x, 6.2831855f);  // to_2f9a38
}
}  // namespace x20

// 0017ce80 (src/anon/batch_w54.cpp)
namespace x21 {
f32 func_0017ce10(f32) asm("func_0017ce10");

f32 func_0017ce80(f32 a, f32 b, f32 c) {
    f32 d = b - a;
    f32 x;
    if (func_0017ce10(d) < -c) x = a - c;
    else if (c < func_0017ce10(d)) x = a + c;
    else x = a + func_0017ce10(d);
    return func_0017ce10(x);
}
}  // namespace x21

// 0017cf00 (src/anon/batch_w268.cpp)
namespace x22 {
struct W268Mtx { f32 m[16]; } __attribute__((aligned(16)));
struct W268V4 {
    f32 v[4];
    W268V4() {}
    W268V4(const W268V4& o) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    W268V4& operator=(const W268V4& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline void W268MulMtx(W268Mtx* d, const W268Mtx* a, const W268Mtx* b) {
    asm volatile(
        "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
        "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
        "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
        "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void W268Apply(W268V4* pr, const W268Mtx* m, const W268V4* v) {
    W268V4& r = *pr;
    asm volatile(
        "lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
        "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
        "sqc2 $vf5, 0(%0)"
        : : "r"(&r), "r"(m), "r"(v) : "memory");
}
W268Mtx* func_00106a18(s32) asm("func_00106a18");  // buffer_get_256
u8* func_00106a60(s32) asm("func_00106a60");  // buffer_get_by_index

W268V4 func_0017cf00(const W268V4& in)
{
    W268V4 r(in);
    f32 one = 1.0f;
    r.v[3] = one;
    W268Mtx* a = func_00106a18(1);  // buffer_get_256
    u8* c = func_00106a60(1);  // buffer_get_by_index
    W268Mtx* b = c ? (W268Mtx*)(c + 16) : 0;
    W268V4 tmp;
    W268Mtx t;
    W268MulMtx(&t, a, b);
    W268Apply(&tmp, &t, &r);
    r = tmp;
    f32 s = one / r.v[3];
    r.v[3] = one;
    r.v[0] *= s;
    r.v[1] *= s;
    r.v[2] *= s;
    return r;
}
}  // namespace x22

// 0017d050 (src/anon/batch_w50.cpp)
namespace x23 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
typedef unsigned int u128  asm("u128")__attribute__((mode(TI)));
typedef void (*VFn)(void*);
typedef void (*VFn3)(void*, void*, void*);
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(const Vec4& o) { QCOPY(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct Ctl0 { void* p; u32 f4; u8 f8; u8 pad[11]; u32 f20; u32 f24; u32 f28; u32 f32; u32 f36; u32 f40; };
struct Ctl1 { u16 a; u16 b; u16 c; };
extern Ctl0 D_0032b9e8 asm("D_0032b9e8");
extern u8 D_0032b930[] asm("D_0032b930");
extern Ctl1 D_0032ba3c asm("D_0032ba3c");
void wtarget_00103ec0(u32, u32, u32, u32) asm("_Z16wtarget_00103ec0jjjj");
void ctarget0_001a5a48(void) asm("_Z17ctarget0_001a5a48v");
Vec4 func_0016bda8(void*) asm("func_0016bda8");
s32 func_001d35e0(Vec4*, Vec4*, Vec4*, s32) asm("func_001d35e0");
void func_001a55a8(Vec4*, s32) asm("func_001a55a8");
void YS_OBJ_scatter_prize(u8*, s32) asm("_ZN2YS3OBJ13scatter_prizeEi");
f32 func_002f8ad0(f32, f32) asm("func_002f8ad0");

// Direction vector -> (pitch, yaw, 0, 1) angles.
Vec4* func_0017d050(Vec4* out, Vec4* in) {
    Vec4 t;
    t = *in;
    f32 len;
    t.y = 0;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(len) : "r"(&t) : "$8", "memory");
    out->x = func_002f8ad0(-in->y, len);
    out->y = func_002f8ad0(in->x, in->z);
    out->z = 0;
    out->w = 1.0f;
    return out;
}
}  // namespace x23

// 0017d0e8 (src/anon/tiny_auto80_queue.cpp)
namespace x24 {
typedef u32  (*Fn_002cf1b8)(u32, u32);
extern "C" u32 func_0017ce10(...) asm("func_0017ce10");
extern "C" u32 cosf(...) asm("cosf");
extern "C" u32 sinf(...) asm("sinf");

u32 func_0017d0e8(u32 a0) {
    u32 s0 = a0;
    f32 f12 = ((f32(*)(u32))func_0017ce10)(a0);
    *(f32*)((u32)s0 + (s32)(12)) = f12;
    f32 f0 = ((f32(*)(f32))sinf)(f12);
    *(f32*)((u32)s0 + (s32)(0)) = f0;
    *(u32*)((u32)s0 + (s32)(4)) = 0u;
    f0 = ((f32(*)(f32))cosf)(*(f32*)((u32)s0 + (s32)(12)));
    *(f32*)((u32)s0 + (s32)(8)) = f0;
    return s0;
}
}  // namespace x24

extern "C" const f32 D_0036c554 = 0.40816324949264526f;  // read by 0x17d130 through its address

// 0017d130 (src/anon/auto200_999.cpp)
namespace x25 {
typedef void (*Fn_00322908)(u32, u32);
extern u8 D_01c60d50 asm("D_01c60d50");
extern f32 D_0036c554 asm("D_0036c554");
extern u8 D_004f3700 asm("D_004f3700");
void dk_MapColor_getOnColorTable(u32, u32) asm(
    "_ZN2dk8MapColor15getOnColorTableEPhi");
void dk_RectParamBase_setColor(u32, u32, u32, u32,
                               u32) asm("_ZN2dk13RectParamBase8setColorEhhhh");
void YS_TARGET_free(u32 a0) asm("_ZN2YS6TARGET4freeEv");

f32 func_0017d130(f32 a0) {  // sqrt_scaled_double
    f32 v = a0 + a0;
    asm volatile("" : "+f"(v));
    u32 p = (u32)&D_0036c554;
    asm volatile("" : "+r"(p));
    f32 d = *(f32 *)p;
    v = v / d;
    return __builtin_sqrtf(v);
}
}  // namespace x25

// 0017d160 (src/anon/batch_w42.cpp)
namespace x26 {
void LoadDataFree(...) asm("_ZN2Tz12LoadDataFreeEz");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void change_action(void*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
void vm_call(u32, s32, void*, s32) asm("_ZN2YS2VM4callEiP8BD_VALUEi");
void vm_callback(u32, s32, void*, s32, void*) asm("_ZN2YS2VM8callbackEiP8BD_VALUEiPS0_");
u32 vm_start(void*, void*) asm("_ZN2YS2VM5StartEPvPNS_3OBJE");
void btlobj_pre_exec(void*) asm("_ZN2YS6BTLOBJ13_OVR_pre_execEv");
void collision_make(void*, s32, f32, f32) asm("_ZN2YS9COLLISION4makeEiff");
s32 has_ansem_entry(u32) asm("_ZN2Tz6JmInfo13HasAnsemEntryEj");
u8* item_each(void*) asm("_ZN2YS10ITEM_TABLE4EachEPKS0_");
void command_menu_clear(void*) asm("_ZN2YS12COMMAND_MENU5clearEv");
void mission_add_count(s32, s32) asm("_ZN2YS7MISSION8AddCountEii");
void wtarget_00239bf8(void*, s32) asm("_Z16wtarget_00239bf8jjjj");
void menu_help_leave(void) asm("_ZN2Tz9CMenuHelp5LeaveEv");
void wtarget_002b7078(void) asm("_Z16wtarget_002b7078jjjj");
u8* oarashi_config(void*) asm("_ZN2Ti9MGOarashi6configEv");
f32 acos_2f8aa0(f32) asm("_ZN3Axa15InnerProductXYZERKNS_8FVECTOR4ES2_");
void lay_file_build_data(void*, void*) asm("_ZN2Tz16LayFileBuildDataEPvj");
void select_begin_leave(void*) asm("_ZN2Tz6Select10BeginLeaveEz");
void select_set_flag(void*, s32) asm("_ZN2Tz6Select7SetFlagEz");

// 0017d160: angle between two vectors (VU0 dot product, clamped acos)
f32 func_0017d160(void* a, void* b)
{
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(d) : "r"(a), "r"(b) : "$8");
    if (1.0f <= d) return 0.0f;
    if (d <= -1.0f) return 3.1415927f;
    return acos_2f8aa0(d);
}
}  // namespace x26

// 0017d1d8 (src/anon/batch_w275.cpp)
namespace x27 {
struct V4b { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void nrm(V4b* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
}
f32 sinf(f32) asm("sinf");
f32 cosf(f32) asm("cosf");

f32* func_0017d1d8(f32* m, f32* a, f32 ang) {
    V4b v;
    v.x = a[0]; v.y = a[1]; v.z = a[2];
    nrm(&v);
    f32 x = v.x, y = v.y, z = v.z;
    f32 s = sinf(ang);
    f32 c = cosf(ang);
    f32 t = 1.0f - c;
    m[0] = x * x * t + c;
    m[1] = x * y * t + z * s;
    m[2] = x * z * t - y * s;
    m[3] = 0;
    m[4] = x * y * t - z * s;
    m[5] = y * y * t + c;
    m[6] = y * z * t + x * s;
    m[7] = 0;
    m[8] = x * z * t + y * s;
    m[9] = y * z * t - x * s;
    m[10] = z * z * t + c;
    m[11] = 0;
    m[12] = 0; m[13] = 0; m[14] = 0;
    m[15] = 1.0f;
    return m;
}
}  // namespace x27

// 0017d348 (src/anon/batch_w1975_nsa.cpp)
namespace x28 {
#define W1975_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define W1975_QCOPY4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct W1975V {
    f32 x, y, z, w;
    W1975V() {}
    W1975V(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1975V(const W1975V& o) { W1975_QCOPY(this, &o); }
    W1975V& operator=(const W1975V& o) { if (this != &o) W1975_QCOPY(this, &o); return *this; }
    void scale(f32 s) {
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(this), "f"(s) : "$8", "memory");
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    void zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
static inline W1975V W1975_cross(const W1975V& a, const W1975V& b) {
    W1975V o;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\t.set noreorder\n\tsqc2 $vf3, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(&a), "r"(&b) : "memory");
    return o;
}
struct W1975M {
    W1975V r[4];
    W1975M() {}
    W1975M& operator=(const W1975M& o) { if (this != &o) W1975_QCOPY4(this, &o); return *this; }
    W1975V operator*(const W1975V& v) const {
        W1975V o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t.set noreorder\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    W1975V apply3(const W1975V& v) const {
        W1975V o;
        asm volatile("lqc2 $vf4, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tvmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tsqc2 $vf4, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
void W1975_identity(W1975M*) asm("_Z13func_0011b6a8Pv");
void W1975_rotateX(W1975M*, f32) asm("_ZN2kn7FMatrix7rotateXEf");
void W1975_rotateY(W1975M*, f32) asm("_ZN2kn7FMatrix7rotateYEf");
void W1975_rotateZ(W1975M*, f32) asm("_ZN2kn7FMatrix7rotateZEf");
f32 W1975_FixRadian(f32) asm("_ZN2YS4MATH9FixRadianEf");
struct W1975Slot {
    u8 b0, b1; u16 id; u8 b4; u8 type; u16 pad6; s32 arg;
    bool small() { return type < 4; }
};
struct W1975Wk { u64 d0; u64 d8; u8 pad[32]; W1975V v; };
struct W1975Ai { void** vt; };
struct W1975Self {
    void** vt;
    u8 sub4[4];
    u32 f8;
    u8 pad12[20];
    u32 flags;
    bool isB0() { u32 f = flags; u8 b = f & 1; return b; }
    u8 pad36[2528 - 36];
    W1975Ai* ai;
    W1975Wk* wk;
    u8 pad2536[16];
    u8 sub2552[36];
    W1975Slot slot;
    u8 pad2600[8];
    W1975V v;
};
s32 W1975_Slot_is_exist(W1975Slot*) asm("_ZN2YS12COMMAND_SLOT8is_existEv");
s32 W1975_Slot_is_beep(const W1975Slot*) asm("_ZNK2YS12COMMAND_SLOT7is_beepEv");
s32 W1975_u_call4_001b8e88(u32) asm("_Z16u_call4_001b8e88jjjj");
s32 W1975_ctarget_001c8db8(void*, u32) asm("_Z16ctarget_001c8db8jjjj");
void W1975_systemSePlay(s32, s32) asm("_ZN5SOUND12systemSePlayEii");
typedef void (*W1975VFn)(W1975Self*);
typedef s32 (*W1975AFn)(W1975Ai*);
struct W1975Work { u8 pad[8]; u8* p8; };
f32 W1975_Ev_get_float(void*) asm("_ZN2sa5EVENT9get_floatEPv");
W1975Work* W1975_Ev_entry_work_get(s32) asm("_ZN2sa5EVENT14entry_work_getEi");
void W1975_LookAt_release(u8*, f32, W1975V*) asm("_ZN2YS6LOOKAT7releaseEf");
extern f32 D_00349e10 asm("D_00349e10");
f32 func_0017d160(const W1975V*, const W1975V*) asm("func_0017d160");
W1975M func_0017d1d8(const W1975V&, f32) asm("func_0017d1d8");
void func_002fd188(void (*)(void)) asm("func_002fd188");
static inline f32 W1975_clampf(f32 v, f32 lo, f32 hi) { if (hi < v) v = hi; else if (v < lo) v = lo; return v; }

// Rotates a toward b by at most t * D_00349e10 radians.
W1975V func_0017d348(const W1975V& a, const W1975V& b, f32 t) {
    W1975V axis;
    W1975V na;
    W1975V nb;
    W1975M m;
    na = a;
    na.normalize();
    nb = b;
    nb.normalize();
    f32 ang;
    { W1975V c1 = na; W1975V c2 = nb; ang = func_0017d160(&c1, &c2); }
    t = t * D_00349e10;
    ang = W1975_clampf(ang, -t, t);
    axis = W1975_cross(na, nb);
    axis.normalize();
    m = func_0017d1d8(axis, ang);
    return m.apply3(na);
}
}  // namespace x28

// 0017d538 .. 0017d5e8 (src/anon/batch_wcx.cpp): rotate a vector about an axis by an angle
namespace x_d538 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4 { V4 r[4]; };
static inline void VCopyChk(V4* d, V4* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline f32 VNormalize(V4* d, V4* s)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%2)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(d), "r"(s) : "$8", "memory");
    return r;
}
static inline void VScale(V4* d, V4* s, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
static inline void CopyM(M4* d, M4* s)
{
    if (d != s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
static inline void ApplyM(V4* d, M4* m, V4* v)
{
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(d), "r"(m), "r"(v) : "memory");
}
void func_0011b6a8(M4*) asm("func_0011b6a8");
M4* func_0011b6d8(M4*, f32) asm("func_0011b6d8");
M4* func_0011b720(M4*, f32) asm("func_0011b720");
f32 func_0017ce10(f32) asm("_ZN2YS4MATH9FixRadianEf");
V4* func_0017d538(V4* out, V4* in, f32 ang) asm("func_0017d538");
V4* func_0017d538(V4* out, V4* in, f32 ang)
{
    M4 m;
    func_0011b6a8(&m);
    CopyM(&m, func_0011b720(&m, func_0017ce10(ang)));
    ApplyM(out, &m, in);
    return out;
}
V4* func_0017d5e8(V4* out, V4* in, f32 ang) asm("func_0017d5e8");
V4* func_0017d5e8(V4* out, V4* in, f32 ang)
{
    M4 m;
    func_0011b6a8(&m);
    CopyM(&m, func_0011b6d8(&m, func_0017ce10(ang)));
    ApplyM(out, &m, in);
    return out;
}
}  // namespace x_d538

// 0017d698 (src/anon/batch_w1784.cpp)
namespace x31 {
#define W1784_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define W1784_QCOPY4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct W1784QV {
    f32 x, y, z, w;
    W1784QV() {}
    W1784QV(const W1784QV& o) { W1784_QCOPY(this, &o); }
    W1784QV& operator=(const W1784QV& o) { if (this != &o) W1784_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1784QM {
    W1784QV r[4];
    W1784QM() {}
    W1784QM(const W1784QM& o) { W1784_QCOPY4(this, &o); }
    W1784QM& operator=(const W1784QM& o) { if (this != &o) W1784_QCOPY4(this, &o); return *this; }
    W1784QV operator*(const W1784QV& v) const {
        W1784QV o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
f32 func_0017ce10(void) asm("func_0017ce10");
W1784QM func_0017d1d8(f32, void*) asm("func_0017d1d8");

W1784QV func_0017d698(const W1784QV& v, void* p) {
    W1784QM m;
    m = func_0017d1d8(func_0017ce10(), p);
    return m * v;
}
}  // namespace x31

// 0017d748 (src/anon/batch_w1937_nsa.cpp)
namespace x32 {
struct W1937V4 { f32 v[4]; };
f32 func_002f8b30(f32, f32) asm("func_002f8b30");

f32* func_0017d748(f32* out, W1937V4* p, f32 t) {
    s32 i = 0;
    f32* p0 = p[0].v; f32* p1 = p[1].v; f32* p2 = p[2].v; f32* p3 = p[3].v;
    f32 u = 1.0f - t;
    for (; i < 3; i++) {
        f32* o = &out[i];
        *o = p0[i] * func_002f8b30(u, 3.0f)
               + p1[i] * 3.0f * func_002f8b30(u, 2.0f) * t
               + p2[i] * 3.0f * u * func_002f8b30(t, 2.0f)
               + p3[i] * func_002f8b30(t, 3.0f);
    }
    return out;
}
}  // namespace x32

// 0017d8c0 (src/anon/batch_w8007.cpp)
namespace x33 {
#define W8007_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
/* 0017d8c0: 16-byte copy through lq/sq (asm, no C equivalent). */
struct W8007V4 {
    f32 x, y, z, w;
    W8007V4& operator=(const W8007V4& s) {
        if (__builtin_expect(this != &s, 0)) W8007_QCOPY(this, &s);
        return *this;
    }
} __attribute__((aligned(16)));
struct W8007Obj { u8 pad[0x30]; W8007V4 v; };
void func_0011b6a8(void*) asm("func_0011b6a8");
void func_0011b7b0(void*, u32) asm("func_0011b7b0");
W8007Obj* func_0017d8c0(W8007Obj* a0, W8007V4* v, W8007V4* a2) asm("func_0017d8c0");
W8007Obj* func_0017d8c0(W8007Obj* a0, W8007V4* v, W8007V4* a2) {
    func_0011b6a8(a0);
    u32 t = (u32)v;
    v = &a0->v;
    func_0011b7b0(a0, t);
    *v = *a2;
    v->w = 1.0f;
    return a0;
}
#undef W8007_QCOPY
}  // namespace x33

// 0017d930 (src/anon/batch_w14.cpp)
namespace x34 {

// Number of decimal digits of n (0 for n <= 0).
s32 func_0017d930(s32 n) {  // digit_count
    s32 c = 0;
    s32 t = 1;
    while (t <= n) {
        t *= 10;
        c++;
    }
    return c;
}
}  // namespace x34
