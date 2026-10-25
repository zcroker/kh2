#include "status.hpp"

// YS::STATUS (0x191758-0x191f20): the player's battle state (field, battle, boss), its
// switch timers, the lock-on ratios and the status flags.

struct V4 {
    f32 x, y, z, w;
    V4() {}
    V4(const V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4& operator=(const V4& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline V4 operator-(const V4& a, const V4& b) {
    V4 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Length(const V4* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline u8 IsMode2(u8* e) { return *(s32*)(e + 944) == 2; }

struct StatusFlags {
    u32 bits;
    StatusFlags() { bits = 0; }
};

StatusFlags D_0034f240;  // status flags

static u32 D_01c61958 __attribute__((aligned(4)));  // mode (0 field, 1 battle, 2 forced)
static f32 D_01c6195c __attribute__((aligned(4)));  // battle hold time
static f32 D_01c61960 __attribute__((aligned(4)));  // mode switch delay
static f32 D_01c61964 __attribute__((aligned(4)));  // prize ratio
static f32 D_01c61968 __attribute__((aligned(4)));  // lock-on ratio
static f32 D_01c6196c __attribute__((aligned(4)));  // lock-out range

struct P191e40 { u8 pad[0x160]; u32 flags; u8 pad2[0xb50 - 0x164]; s32 state; };

extern "C" {
extern f32 D_00349e10;  // frame time
extern u8* D_0034e948;  // player
extern u8 D_00351ec0[];
extern u8 D_00351ec8[];
extern u8* D_00352130;
extern u16 D_0032bae0;  // room
s32 func_0019ba60(u8*);
s32 func_001b58a8(void);
s32 func_001a6850(void);
void func_001c11a8(s32);
void func_001c1130(s32);
void func_001a3710(void);
s32 func_00197920(void);
s32 func_001c8db8(u8*, s32) asm("_Z16ctarget_001c8db8jjjj");
u8* func_00176b20(s32);
s32 func_00185ac0(void*);
u8* func_00177860(u8*);
V4* func_0016c028(u8*);  // obj_get_attach_or_alt
u8* func_00185da8(u8*);
s32 func_0019c8a8(u8*);
s32 CanOpenCampMenu_191e40() asm("_ZN2YS8PROGRESS15CanOpenCampMenuEv");

void func_00191938(s32 v);
void func_00191bf0(f32 x);
void func_00191c30(f32 a);
s32 func_001918c8(void);
void func_00191cd8(void);
void u_tail0_001917d0(void) asm("_Z16u_tail0_001917d0v");

void func_00191758(void) {
    D_0034f240.bits = 0;
    func_00191938(0);
    f32 a = 1.0f;
    D_01c61960 = 0;
    D_01c6195c = 30.0f;
    D_01c61964 = a;
    func_00191bf0(a);
}

}

namespace YS {

u32 STATUS::GetMode() { return D_01c61958; }

u32 STATUS::IsBattleMode() { return D_01c61958 != 0; }

}  // namespace YS

extern "C" {

void u_tail0_001917d0(void) {
    func_00191cd8();
    if (D_01c61958 == 2) return;
    s32 n = func_001918c8();
    if (0.0f < D_01c6195c) D_01c6195c -= D_00349e10;
    if (D_01c61958 != n) {
        if (0.0f < D_01c6195c || (D_01c61960 -= D_00349e10) <= 0.0f) func_00191938(n);
    }
    if (D_01c61958 == n) {
        if (n == 1) D_01c61960 = 120.0f;
        else D_01c61960 = 45.0f;
    }
    if (D_01c61958 == 0) func_001a3710();
}

s32 func_001918c8(void) {
    if (!func_0019ba60(D_0034e948)) {
        D_01c61960 = 0;
        return 0;
    }
    if (func_001b58a8()) return 1;
    if (D_0034f240.bits & 0x10000) return 1;
    return func_001a6850() != 0;
}

void func_00191938(s32 v) {
    switch (v) {
    case 0: func_001c11a8(6); break;
    case 1: case 2: func_001c1130(6); break;
    }
    D_01c61958 = v;
}

}

namespace YS {

void STATUS::CageOn() { func_00191938(2); }

}  // namespace YS

extern "C" {

void func_001919a8(void) {
    func_00191938(0);
    D_01c61960 = 0;
    u_tail0_001917d0();
}

u32 func_001919d0(void) {
    u32 v = 0;
    if (D_0034f240.bits & 0x0008) v = 0 < (u32)D_0034e948;
    return v;
}

u32 func_001919f8(void) {
    u32 v = 0;
    if (D_0034f240.bits & 0x0800) v = 0 < (u32)D_0034e948;
    return v;
}

void func_00191a20(void) { D_0034f240.bits |= 0x20; }
void func_00191a38(void) { D_0034f240.bits &= ~0x20; }

s32 func_00191a50(void) {
    u32 f = D_0034f240.bits;
    s32 r = 0;
    if (f & 0x100) goto one;
    if (f & 2) { r = 1; goto out; }
    if (func_00197920()) goto one;
    if (!func_001c8db8(D_00351ec8, 0)) goto out;
one:
    r = 1;
out:
    return r;
}

s32 func_00191ab8(void) {
    s32 i, j;
    for (i = 0; i < 3; i++) {
        u8* p = func_00176b20(i);
        if (!func_0019ba60(p)) continue;
        void** q = (void**)(p + 2808);
        for (j = 0; j < 2; j++) {
            void* c = *q++;
            if (func_0019ba60((u8*)c) && !func_00185ac0(c)) return 1;
        }
    }
    return 0;
}

}

namespace YS {

void STATUS::SetPrizeRatio(f32 value) { D_01c61964 = value; }

}  // namespace YS

extern "C" {

f32 func_00191b70() {
    s32 i = 0;
    f32 s = D_01c61964;
    do {
        u8* o = func_00176b20(i);
        i++;
        if (func_0019ba60(o) && *(u32*)(o + 1164)) s += *(f32*)(func_00177860(o) + 100);
    } while (i < 3);
    return s;
}

void func_00191bf0(f32 x) {
    D_01c61968 = x;
    func_00191c30(*(f32*)(D_00352130 + 80) * x);
}

}

namespace YS {

f32 STATUS::GetLockOnRatio() { return D_01c61968; }

}  // namespace YS

extern "C" void func_00191c30(f32 a) { D_01c6196c = a; }

namespace YS {

f32 STATUS::GetLockOutRange() { return D_01c6196c; }

}  // namespace YS

extern "C" {

u32 func_00191c50(void) {
    u32 r = 0;
    if (D_0032bae0 == 5906 || (D_0034f240.bits & 0x2000)) r = 1;
    return r;
}

u32 func_00191c88(void) {
    u32 r = 0;
    if (!(D_0034f240.bits & 0x8000)) {
        u32 m = YS::STATUS::GetMode();
        m ^= 2;
        if (m == 0) r = 1;
    } else {
        r = 1;
    }
    return r;
}

// Sets flag 0x10000 when an enemy is close to the player (or forces it).
void func_00191cd8(void) {
    D_0034f240.bits &= ~0x10000;
    u8* pl = D_0034e948;
    if (!func_0019ba60(pl)) return;
    V4 a = *func_0016c028(pl);
    u8* e = 0;
    while ((e = func_00185da8(e)) != 0) {
        if (*(u32*)(e + 1416) & 0x400) { D_0034f240.bits |= 0x10000; return; }
        if (!IsMode2(e)) continue;
        if (func_0019c8a8(e)) { D_0034f240.bits |= 0x10000; return; }
        V4 d = *func_0016c028(e) - a;
        d.y = 0.0f;
        if (Length(&d) < 1200.0f) { D_0034f240.bits |= 0x10000; return; }
    }
}

s32 func_00191e40() {
    if (func_00191ab8() || func_001c8db8(D_00351ec0, 0) || !CanOpenCampMenu_191e40()) return 1;
    P191e40* p = (P191e40*)D_0034e948;
    if (!func_0019ba60((u8*)p) || p->state == 12 || (p->flags & 0x4000)) return 1;
    return func_001a6850() != 0;
}

}
