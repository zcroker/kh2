#include "../common/types.h"

// YS::PRIZE (prize effect set) and YS::PRIZE_CA, first part (0x1cc048-0x1cc868): the effect set's
// constructor and destructors, prize spawning, the pick-up hand-over, the ring burst spawner
// (0x1cc3b8) and the prize transfer between two objects (0x1cc5c8). unit_001cc868.cpp and
// unit_001cd078.cpp continue the file.

struct Vn1cc0 {
    f32 x, y, z, w;
    void set(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    Vn1cc0& operator=(const Vn1cc0& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct PrizeSet;
struct PrizeSetVt { void* f[22]; void (*take)(PrizeSet*, u8*); };
struct PrizeSet { PrizeSetVt* vt; };

struct O1cc220 { u8 pad[0x588]; u32 flags; u8 pad2[0x7f8 - 0x58c]; u32 flags2; };

extern "C" {
extern u8 D_00352060;
extern void* D_00352050;
extern f32 D_0036e228[];   // prize effect parameters ([1]: height above the ground)
extern u32 D_003638d0;
extern f32 D_0036d4a8;
u32 func_001a4db0(u32, u32, u32, u32);
u32 func_001a4e30(...);
void func_001a4e30_v(void*) asm("func_001a4e30");
void func_00105110(void*);
u8* func_001a5420(void*, u8*, void*);
Vn1cc0 func_0016bda8(u8*);
s32 o1cc220_get_entry_id(void*) asm("_ZN2YS3OBJ12get_entry_idEv");
O1cc220* func_00186078(O1cc220*);
s32 c1cc220_00186ce8(O1cc220*) asm("_Z16ctarget_00186ce8jjjj");
s32 func_00186d18(O1cc220*);
s32 func_001c7950(void*, O1cc220*, f32, f32);
void func_001c79a0(void*, O1cc220*, s32);
s32 func_001991a8(s32, s32);
void func_001c71f8(u8*, f32);
s32 func_001cc358(void);

// 0x1cc008: C2 constructor copy (same body as the C1 at 0x1cc048).
u32 func_001cc008(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r6 = (u32)((s32)0u + (256));
    r7 = (u32)((s32)0u + (96));
    r16 = r4;
    r2 = func_001a4db0(r4, r5, r6, r7);
    r15 = (u32)&D_00352060;
    r14 = (u32)(0x0035u << 16);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r14 + (s32)(8272)) = r16;
    return r2;
}

u32 func_001cc048(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r6 = (u32)((s32)0u + (256));
    r7 = (u32)((s32)0u + (96));
    r16 = r4;
    r2 = func_001a4db0(r4, r5, r6, r7);
    r15 = (u32)&D_00352060;
    r14 = (u32)(0x0035u << 16);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r14 + (s32)(8272)) = r16;
    return r2;
}

u32 func_001cc088(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r13, r14;
    r14 = (u32)&D_00352060;
    *(u32*)((u32)r4 + (s32)(0)) = r14;
    r13 = (u32)(0x0035u << 16);
    *(u32*)((u32)r13 + (s32)(8272)) = 0u;
    u32 (*fp_call4_001a4e30)(u32, u32, u32, u32) = func_001a4e30;
    r2 = fp_call4_001a4e30(r4, r5, r6, r7);
    return r2;
}

u32 func_001cc0b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r13, r14;
    r14 = (u32)&D_00352060;
    *(u32*)((u32)r4 + (s32)(0)) = r14;
    r13 = (u32)(0x0035u << 16);
    *(u32*)((u32)r13 + (s32)(8272)) = 0u;
    u32 (*fp_call4_001a4e30)(u32, u32, u32, u32) = func_001a4e30;
    r2 = fp_call4_001a4e30(r4, r5, r6, r7);
    return r2;
}

void func_001cc0e8(void** self) {
    *self = &D_00352060;
    D_00352050 = 0;
    func_001a4e30_v(self);
    func_00105110(self);
}

u8* PrizeSetAppear(void* self, void* pos) asm("_ZN2YS5PRIZE6appearEPKNS_11PRIZEEFFECT5PARAMERKN2kn7FVectorE");
u8* PrizeSetAppear(void* self, void* pos)
{
    u8* p = func_001a5420(self, (u8*)D_0036e228, pos);
    if (p) *(u32*)(p + 40) |= 4;
    return p;
}

// Spawn up to n prizes at the object's position.
void PrizeAppear(u8* obj, s32 n) asm("_ZN2YS8PRIZE_CA6AppearEPNS_6BTLOBJEi");
void PrizeAppear(u8* obj, s32 n)
{
    if (*(s32*)(obj + 2760) < n) n = *(s32*)(obj + 2760);
    if (!D_00352050) return;
    if (n == 0) return;
    Vn1cc0 pos;
    pos = func_0016bda8(obj);
    s32 i;
    for (i = 0; i < n; i++) {
        u8* p = PrizeSetAppear(D_00352050, &pos);
        if (!p) return;
        *(u32*)(p + 16) = (u32)func_001cc358;
        (*(s32*)(obj + 2760))--;
    }
}

s32 func_001cc310(O1cc220* p, void* target);

// Find the first object in range that can be targeted and hand it over.
s32 func_001cc220(void* self, void* target)
{
    bool special = o1cc220_get_entry_id(self) == 0x898;
    O1cc220* p = 0;
    while ((p = func_00186078(p)) != 0) {
        if (!(p->flags & 0x80)) {
            if (!(p->flags & 0x10)) continue;
            if (!special) continue;
        }
        if (p->flags2 & 4) continue;
        if (c1cc220_00186ce8(p)) continue;
        if (func_00186d18(p)) continue;
        if (!func_001c7950(target, p, D_0036d4a8, 0.0f)) continue;
        return func_001cc310(p, target);
    }
}

s32 func_001cc310(O1cc220* o, void* b)
{
    func_001c79a0(b, o, 0);
    (*(s32*)((u8*)o + 0xac8))++;
    return func_001991a8(0x11, 0);
}

// The prize's per-frame callback (set by PRIZE_CA::Appear).
s32 func_001cc358(void)
{
    u8* p;
    func_001c71f8(p, -0.5f);
    if (p[68] >= 2) { PrizeSet* s = (PrizeSet*)D_00352050; s->vt->take(s, p); }
    return 1;
}

struct Prize1cc3b8 { u8 pad[16]; void (*func)(Prize1cc3b8*); u8 pad2[28]; Vn1cc0 vel; };
f32 func_002f8960(f32);
f32 func_002f87c0(f32);
void func_001a7610(Vn1cc0*, Vn1cc0*, s32, f32, f32);
void func_001c7520(Prize1cc3b8*);

// The game's random generator (seed at D_003638d0), written with arithmetic helpers: the
// multiplier and the 1/2^32 scale are helper arguments, which is what decides the loop hoisting.
static inline u32 Mulu(u32 a, u32 b) { return a * b; }
static inline f32 Mulf(f32 a, f32 b) { return a * b; }
static inline f32 Rand(f32 range)
{
    D_003638d0 = Mulu(D_003638d0, 0x10dcd);
    return Mulf((f32)D_003638d0, 2.3283064e-10f) * range;
}

// Spawn n prizes on a ring around pos: random radius (0..300) and angle, dropped to the ground.
void func_001cc3b8(Vn1cc0* pos, s32 n)
{
    if (!D_00352050) return;
    Vn1cc0 off;
    off.w = off.z = off.y = off.x = 0.0f;
    for (s32 i = 0; i < n; i++) {
        Vn1cc0 g;
        Vn1cc0 p;
        f32 r = Rand(300.0f);
        f32 a = Rand(6.2831855f);
        off.x = func_002f8960(a) * r;
        off.z = func_002f87c0(a) * r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&p), "r"(pos), "r"(&off) : "memory");
        func_001a7610(&p, &g, 4, 1000.0f, 200.0f);
        g.y -= D_0036e228[1];
        Prize1cc3b8* fx = (Prize1cc3b8*)PrizeSetAppear(D_00352050, &g);
        fx->func = func_001c7520;
        asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(&fx->vel) : "memory");
    }
}

struct Prize1cc5c8 { u8 pad0[16]; void (*phase)(void); u8 pad14[28]; Vn1cc0 pos; u8 pad40[8]; u8* target; };
extern s8 D_01d49990;      // guard of the function-static offset below
extern Vn1cc0 D_01d499a0;  // static FVector(0, -100, -80, 1)
void func_001ccdf0(void);
void func_001cc868(void);
void func_002fd188(void (*)(void));

// Random number in [lo, hi). The range and the scale are helper arguments again (see Rand above);
// the range is computed after the unsigned->float branch, which lets the loop hoist it.
static inline f32 Addf(f32 a, f32 b) { return b + a; }
static inline f32 RandRange(f32 lo, f32 hi)
{
    D_003638d0 = Mulu(D_003638d0, 0x10dcd);
    return lo + Mulf(Mulf((f32)D_003638d0, 2.3283064e-10f), hi - lo);
}
// The prize effect set, taken by reference (the loop hoists its address first because of this).
static inline void*& PrizeSet1cc5c8() { return D_00352050; }

// Moves up to n prizes from one object to another: each one appears at a fixed offset
// (0, -100, -80) in the source's local frame and flies to a random spot around the target.
// Returns 1 when the source runs out or no prize could be made.
s32 func_001cc5c8(u8* from, u8* to, s32 n)
{
    if (D_01d49990 == 0) {
        D_01d49990 = 1;
        D_01d499a0.set(0.0f, -100.0f, -80.0f, 1.0f);
        func_002fd188(func_001ccdf0);
    }
    Vn1cc0 ofs;
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&ofs), "r"(from + 64), "r"(&D_01d499a0) : "memory");
    const Vn1cc0 pos = func_0016bda8(to);
    for (s32 i = 0; i < n; i++) {
        if (*(s32*)(from + 2760) == 0) return 1;
        Prize1cc5c8* p = (Prize1cc5c8*)PrizeSetAppear(PrizeSet1cc5c8(), &ofs);
        if (!p) return 1;
        p->target = to;
        p->phase = func_001cc868;
        p->pos.set(Addf(RandRange(-50.0f, 50.0f), pos.x), -4.0f, Addf(RandRange(-20.0f, 20.0f), pos.z), 0.0f);
        (*(s32*)(from + 2760))--;
        (*(s32*)(to + 2760))++;
    }
    return 0;
}
}
