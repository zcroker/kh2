#include "../common/types.h"

// Disables sibling-call optimisation where the original keeps jal + epilogue.
struct NoTail82 { ~NoTail82() {} };

struct E0013 { u32 b; u32 a; };
struct Tbl0013 { u32 res; s32 count; E0013 e[1]; };
extern Tbl0013 D_00347fd8;
extern u8 D_004193c0[];

struct Alloc0014 { struct VT { void* (*alloc)(void*, u32, u32); }* vt; };
struct Mgr0014 { u8 pad[20]; Alloc0014* heap; };
extern Mgr0014* D_00347f80;

extern u8 D_0034d850[];

struct Node0017 { u8 pad[40]; s32 val; u8 pad2[16]; Node0017* next; };
struct Q0017 { Node0017* head; Node0017* tail; };
extern Q0017 D_0034dcb8;
extern struct { Node0017* first; } D_0034dca0;

extern u8* D_00352130;
extern u8 D_0032bb30[];
union FU82 { f32 f; u32 u; };
// 16-byte vector whose assignment is a 128-bit copy.
struct Vec82 {
    f32 x, y, z, w;
    Vec82& operator=(const Vec82& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

extern u8 D_0032e020[];
struct V82z { f32 v[4]; } __attribute__((aligned(16)));
static inline void VZero82(void* p) { asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p) : "memory"); }

extern "C" {
s32 func_00181a70(u8*);
void func_00189228(u8*, u16);
s32 func_001ba028(u32);
void func_00177a28(u8*);
void func_0016bae8(u32, u8*, u16, u8*);
void func_0016bd60(u8*, s32);
u32 func_00177860(u8*);
s32 func_001c3618(u32, s32);
u8* func_001ce300(s32);
void func_0017f488(u8*, s32, f32, f32);
void func_001c97b0(u16, f32);
u32 func_001c88a8(u32, f32);
s32 func_001c9958(u8, u16);
void* func_001050d8(u32);
void func_0010c078(void*, u8*, u32, f32);
s32 func_00168aa0(void*, s32);
u8* func_00168b38(void*, s32, s32);
s32 func_0013d498(void);
void func_0013b3f8(void);
void func_0013a4a8(void);
s32 func_00158450(void*);
s32 func_001584a0(void*);
void func_0013fda0(void*);
void func_0013fdc8(void*);
void func_0031bc58(void*);
void func_0014fe00(void*, u32, u32, u32, u32, u32, u32, u32, u32);
void func_001a17c8(u32);
void func_001b78b8(u32);
void func_002cb708(u32);
void func_00105110(u32);
void func_001b3098(void*);
void func_001a9350(void*);
void func_001a6d68(void*);
void func_00187b90(void*);
void func_0017eb98(void*);
void func_001ddd88(void*);
u32 func_0016e920(void);
u32 func_0016f470(u32, u32);
u32 func_0016f4b8(u32, u32);
u32 func_0016f520(u32, u32, u32);
s32 func_00170978(u32);
s32 func_0016f6f8(u32);
s32 func_0016f770(u32);
s32 func_0016f460(u32);
void func_0031e328(void*, Node0017*);
void func_00170188(Node0017*);

// Builds the table of (25, 24) resource entries from the resource at D_004193c0.
void func_0013a368(void)
{
    s32 i;
    D_00347fd8.res = (u32)D_004193c0;
    D_00347fd8.count = func_00168aa0(D_004193c0, 25);
    for (i = 0; i < D_00347fd8.count; i++) {
        D_00347fd8.e[i].a = *(u32*)(func_00168b38((void*)D_00347fd8.res, 25, i) + 8);
        if (func_00168b38((void*)D_00347fd8.res, 24, 0))
            D_00347fd8.e[i].b = *(u32*)(func_00168b38((void*)D_00347fd8.res, 24, i) + 8);
        else
            D_00347fd8.e[i].b = 0;
    }
    if (func_0013d498()) return;
    func_0013b3f8();
    func_0013a4a8();
}

void func_0013fdf0(u8* o, u8* p, f32 s)
{
    if (func_00158450(p)) {
        *(f32*)(o + 72) -= *(f32*)(p + 44) * 8.0f * s;
        func_0013fda0(o);
    } else if (func_001584a0(p)) {
        *(f32*)(o + 72) += *(f32*)(p + 44) * 8.0f * s;
        func_0013fdc8(o);
    }
}

// Allocates a 6192-byte object from the global heap and constructs it.
void* func_0014f8d0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h)
{
    Alloc0014* hp = D_00347f80->heap;
    void* p = hp->vt->alloc(hp, 6192, 0);
    func_0031bc58(p);
    func_0014fe00(p, a, b, c, d, e, f, g, h);
    return p;
}

static inline s32 FlagOff0016(u32 a) { return !(*(u8*)(a + 72) & 1); }

static inline bool Expired0017(Node0017* p) { return !(p->val < 10000); }

static inline Node0017* Step0017(Node0017* c)
{
    Node0017* n = c->next;
    func_00170188(c);
    return n;
}

// Moves nodes whose value reached 10000 to the pending queue, then processes them.
void func_001705a8(void)
{
    Node0017* p;
    Node0017* n;
    D_0034dcb8.head = 0;
    D_0034dcb8.tail = 0;
    p = D_0034dca0.first;
    if (p) {
        do {
            n = p->next;
            if (Expired0017(p)) {
                func_0031e328(&D_0034dca0, p);
                if (!D_0034dcb8.tail) {
                    D_0034dcb8.tail = p;
                    D_0034dcb8.head = p;
                    p->next = 0;
                } else {
                    D_0034dcb8.tail->next = p;
                    p->next = 0;
                    D_0034dcb8.tail = p;
                }
            }
            p = n;
        } while (n);
    }
    for (p = D_0034dcb8.head; p; ) p = Step0017(p);
}

static inline bool Reacts0017(u8* a1) { return (*(u32*)(*(u8**)(a1 + 12) + 8) & 2) || (*(u32*)(a1 + 352) & 0x40); }

// Picks the reaction motion for the hit described by a0.
void func_0017a9e8(u8* a0, u8* a1)
{
    u32 f = *(u32*)(a0 + 8);
    if (f & 0x20) {
        func_0016bd60(a1, 21);
    } else if (f & 0x1000) {
        func_0016bd60(a1, 45);
    } else {
        bool x = Reacts0017(a1);
        if (x) {
            ((FU82*)(a1 + 36))->f *= *(f32*)(D_00352130 + 68);
            if (*(u32*)(a0 + 8) & 0x400) func_0016bd60(a1, 33);
            else func_0016bd60(a1, 8);
        } else {
            func_0016bd60(a1, 4);
        }
    }
    *(u32*)(a1 + 252) = *(u32*)(a1 + 340);
}

void func_0017cd20(u8* a0, u8* a1)
{
    Vec82 v;
    u8* r;
    s32 n = func_001c3618(func_00177860(a1), 2);
    if (n < 5) {
        if (!n) return;
        if (!(*(u32*)(a1 + 268) & 2)) return;
    }
    r = func_001ce300(n);
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

u32 func_0017e418(u8* a0, u32 a1, f32 f)
{
    void* p;
    if (D_0032bb30[13605]) {
        func_001c97b0(*(u16*)(a0 + 76), 15.0f);
        return func_001c88a8(a1, f);
    }
    if (func_001c9958(D_0032bb30[13604], *(u16*)(a0 + 76))) {
        func_001c97b0(*(u16*)(a0 + 76), 15.0f);
        return 0;
    }
    p = func_001050d8(3328);
    func_0010c078(p, a0, a1, f);
    return (u32)p;
}

void func_00178bf0(u8* a0, u8* a1)
{
    u8* t;
    if (*(u16*)(a1 + 38) && func_00181a70(a0))
        func_00189228(D_0032e020, *(u16*)(a1 + 38));
    if (!func_001ba028(*(u32*)(*(u8**)(a0 + 2884) + 12))) return;
    func_00177a28(a0);
    switch (a1[37]) {
    case 0:
        break;
    case 1:
        if (*(u32*)(*(u8**)(a0 + 12) + 4)) func_0016bd60(a0, 0);
        VZero82(a0 + 2768);
        break;
    case 2: {
        V82z tmp;
        VZero82(a0 + 32);
        VZero82(&tmp);
        {
            u8* o = *(u8**)(a0 + 12);
            (*(void (**)(u8*, u8*, V82z*))(*(u8**)o + 8))(o, a0, &tmp);
        }
        VZero82(a0 + 2768);
        break;
    }
    }
    t = *(u8**)(a0 + 2884);
    func_0016bae8(*(u32*)(t + 12), a0, *(u16*)(t + 4), t + 12);
}

void u_call4_0016a358(u32, u32, u32, u32) asm("_Z16u_call4_0016a358jjjj");
u32 ctarget_0016f7d0(u32, u32, u32, u32) asm("_Z16ctarget_0016f7d0jjjj");
}

void u_call4_0016a358(u32 a0, u32, u32, u32)
{
    NoTail82 nt;
    u8* o = (u8*)a0;
    u32 p;
    *(u32*)o = (u32)D_0034d850;
    if (*(u32*)(o + 1164)) func_001a17c8(*(u32*)(o + 1164));
    if (*(u32*)(o + 2088)) func_001b78b8(*(u32*)(o + 2088));
    if (*(u32*)(o + 1296)) func_001b78b8(*(u32*)(o + 1296));
    p = *(u32*)(o + 1288);
    if (p) {
        func_002cb708(p);
        func_00105110(p);
    }
    func_001b3098(o + 2048);
    func_001a9350(o + 1952);
    func_001a6d68(o + 1280);
    func_00187b90(o + 768);
    func_0017eb98(o + 320);
    func_001ddd88(o + 156);
    func_001ddd88(o + 128);
}

u32 ctarget_0016f7d0(u32 a0, u32 a1, u32, u32)
{
    u32 mask;
    if (!a1) a1 = func_0016e920();
    mask = 1 << func_00170978(func_0016f470(a1, 0));
    if (!func_0016f6f8(a0) && !func_0016f770(a0) && FlagOff0016(a1))
        mask |= 1 << func_00170978(func_0016f4b8(a1, 0));
    if (!func_0016f6f8(a0) && func_0016f460(a1))
        mask |= 1 << func_00170978(func_0016f520(a1, a0, 0));
    return mask;
}

extern const f32 D_0036cd18;

static inline f32 Dot82(const void* a, const void* b)
{
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(d) : "r"(a), "r"(b) : "$8", "memory");
    return d;
}

extern "C" {
void func_0018a958(u8*, u32, f32, f32);
s32 func_0019ba60(u32);
u32 func_00190208(u8*, u32);
void func_0018a818(u8*, u32, u32);
Vec82* func_0016c028(u32);
s32 func_001b9d40(u8*, u8*);
void func_0016af58(void*, u8*);

void func_001902a8(u8* a0, u8* a1)
{
    u8* o = *(u8**)(a0 + 8);
    if (o) {
        func_0018a958(a1, 0, *(f32*)(o + 256), *(f32*)(o + 260));
        *(Vec82*)(a1 + 16) = *(Vec82*)(*(u8**)(a0 + 8) + 224);
    } else if (func_0019ba60(*(u32*)a0)) {
        u32 v = func_00190208(a0, 1);
        if (v) func_0018a818(a1, *(u32*)a0, v);
        else *(Vec82*)(a1 + 16) = *func_0016c028(*(u32*)a0);
    } else {
        // identity row (0,0,0,1) from vf0
        asm volatile("sqc2 $vf0, 0(%0)" : : "r"(a1 + 16) : "memory");
    }
    {
        // 1.0f read through its pool address; the original repeats the %hi in every branch,
        // which the literal-pool retargeting cannot pair, so name the constant directly.
        const f32* k;
        asm("" : "=r"(k) : "0"(&D_0036cd18));
        *(f32*)(a1 + 28) = *k;
    }
}

// True when a0 is active and both its facing vectors point along a1 (cos >= 0.7).
s32 func_0019c778(u8* a0, u8* a1)
{
    s32 r = 0;
    Vec82 t;
    if (func_001b9d40(a0, a1) && 0.0f < *(f32*)(a0 + 28)) {
        func_0016af58(&t, a0);
        if (Dot82(a1, &t) >= 0.7f && Dot82(a1, a0 + 16) >= 0.7f) r = 1;
    }
    return r;
}
}

struct Mat82 { f32 m[16]; } __attribute__((aligned(16)));
struct Lst001b { u8 pad[4]; s32 count; struct { u32 item; u32 x; } e[1]; };
struct Bones001b { Lst001b* t; u8* arr; s32 idx; };

// 64-byte quadword copy (four lq then four sq).
static inline void Copy64_82(void* d, const void* s)
{
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
        : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}

extern "C" {
void func_0016b0e0(u32, u32, u8*);
void func_00165830(u32, Mat82*);

// Updates each bone matrix into the current double-buffer half, then flips halves.
void func_001b3118(Bones001b* b, u32 a1)
{
    s32 i;
    if (!b->t) return;
    for (i = 0; i < b->t->count; i++) {
        Mat82 m;
        func_0016b0e0(a1, b->t->e[i].item, b->arr + i * 144 + b->idx * 64);
        Copy64_82(&m, b->arr + i * 144 + b->idx * 64);
        func_00165830(*(u32*)(b->arr + i * 144 + 128), &m);
    }
    b->idx ^= 1;
}
}

extern f32 D_00349e10;
union FU001d { f32 f; s32 i; };
struct Q001d { u32 a; FU001d f; };
struct S001d { s32 end; s32 cur; Q001d e[3]; u32 cur_a; f32 cur_f; f32 timer; };

extern "C" {
void func_001bc778(u8*);
u8* func_001bc780(u8*, s32, s32, s32);
s32 func_001cf998(void);
void func_001cf9e0(u8*, s32);
s32 func_001d8898(s32);
void func_00190128(void*);
void func_00190878(void*, u8*, s32);
void func_001bd3e0(u32, s32, s32, void*, s32, s32);
void func_00178888(u8*);
s32 func_00197920(S001d*);
void func_001d2668(S001d*, u32, f32);

void func_001cf7d8(u8* a0)
{
    u8 tmp[32] __attribute__((aligned(16)));
    u8* s = *(u8**)(a0 + 2884) + 1660;
    u8* v;
    func_001bc778(s);
    v = func_001bc780(s, 411, 0, 1);
    v[6] = 1;
    if (func_001cf998()) {
        func_001cf9e0(a0, 0);
    } else {
        func_001cf9e0(a0, 1);
        v[5] = 5;
    }
    if (func_001d8898(1)) {
        func_00190128(tmp);
        func_00190878(tmp, a0, 0);
        func_001bd3e0(*(u32*)(a0 + 2884), 1, 412, tmp, 1, 100);
    }
    func_00178888(a0);
}

// Advances a 3-entry ring of queued requests once the current one's timer has run out.
void func_001d2750(S001d* a0)
{
    u32 w;
    s32 i;
    if (func_00197920(a0)) return;
    w = a0->cur_a;
    if (w) {
        a0->timer -= D_00349e10;
        if (a0->timer <= 0.0f) w = 0;
        if (w) return;
    }
    i = a0->cur;
    if (i != a0->end) {
        Q001d* q = &a0->e[i];
        a0->cur = (i + 1) % 3;
        func_001d2668(a0, q->a, q->f.f);
    } else if (a0->cur_a) {
        func_001d2668(a0, a0->cur_a, a0->cur_f);
    }
}
}

extern s32 D_01d9eab4;
extern s32 D_01d9ea9c;
extern u8* D_01d9e6e0;
struct Ev001f { u8 pad[4]; s16 f4; u8 pad2[6]; u8 f12; u8 f13; u8 f14; u8 pad3; s32 f16; s32 f20; s32 f24; };

extern "C" {
void func_001e0e40(u8*);
s32 func_00222568(void);
void func_001f5cc8(void);
void func_0021ee48(u8*, Ev001f*, void*, u8*, s16, u8, u8);

// Drains queued entries in 0.25 steps of the accumulated time.
void func_001e1d20(u8* a0)
{
    if (*(f32*)(a0 + 3560) < 140.0f) {
        *(f32*)(a0 + 3556) = 25.0f;
        return;
    }
    if (0.25f <= *(f32*)(a0 + 3556)) {
        do {
            s32 n = *(s32*)(a0 + 3564);
            if (n <= 0) {
                *(f32*)(a0 + 3560) = 0;
                *(f32*)(a0 + 3556) = 0;
                *(s32*)(a0 + 3520) = 2;
                return;
            }
            {
                s32 m = n - 1;
                *(s32*)(a0 + 3564) = m;
                func_001e0e40(*(u8**)(a0 + 3528) + m * 48);
            }
            *(f32*)(a0 + 3556) -= 0.25f;
        } while (0.25f <= *(f32*)(a0 + 3556));
    }
}

void func_001f5df8(u8* a0, Ev001f* e, u8* a2)
{
    if (D_01d9eab4) return;
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    if (e->f13 == 255) return;
    if ((func_00222568() >> 8) & e->f13) return;
    if (e->f16 == -1) return;
    if (e->f24 == -1) return;
    func_0021ee48(a0, e, (void*)func_001f5cc8, a0 + **(u32**)(a2 + 12) + 160, e->f4, e->f14, e->f12);
}
}

extern f32 D_00354be0[3];
extern u8 D_01d9e840[];
extern u8 D_01d9e8c0[];
extern f32 D_00354bd0[3];
extern f32 D_00354bc0[3];
extern u8* D_01d9e6e8;

extern "C" {
void func_002f3f40(u8*, u8*, f32);
void func_002f3cd8(u8*, u8*, u8*);
void func_002f3f98(u8*, u8*);
void func_002f3d08(u8*, u8*, u8*);
void func_0021ec80(u8*, s32*);

void func_001fcb90(u8* a0, u32, u8* a2)
{
    u8* p = a0 + *(u32*)(*(u8**)(a2 + 12) + 4) + 160;
    func_002f3f40(D_01d9e6e8 + 80, D_01d9e6e8 + 16, D_00354be0[0]);
    func_002f3f40(D_01d9e6e8 + 96, D_01d9e6e8 + 32, D_00354be0[1]);
    func_002f3f40(D_01d9e6e8 + 112, D_01d9e6e8 + 48, D_00354be0[2]);
    func_002f3cd8(D_01d9e6e8 + 128, D_01d9e840, D_01d9e6e8 + 64);
    func_002f3f98(p, D_01d9e6e8 + 80);
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
}

// Converts the global euler angles (radians) to 16-bit fixed angles and applies them.
void func_00200fd8(u8* a0, u8* a1)
{
    s32 v[4];
    u8* p;
    p = a0 + *(u32*)(*(u8**)(a1 + 12) + 12) + 160;
    v[0] = (s32)(D_00354bd0[0] * 32768.0f / 3.14159274f);
    v[1] = (s32)(D_00354bd0[1] * 32768.0f / 3.14159274f);
    v[2] = (s32)(D_00354bd0[2] * 32768.0f / 3.14159274f);
    func_0021ec80(p, v);
    *(f32*)(p + 48) = D_00354bc0[0];
    *(f32*)(p + 52) = D_00354bc0[1];
    *(f32*)(p + 56) = D_00354bc0[2];
}

}

struct VObj82 { struct VT { void* f[8]; }* vt; };
extern VObj82* D_0035edb0;
extern VObj82* D_0035edb8;
extern VObj82* D_0035edb4;
extern u8* D_0035eda8;
extern u8* D_0035edac;
extern u8 D_00373110[];
extern u8* D_0035f01c;
static inline void VCall5_82(VObj82* o) { ((void (*)(VObj82*))o->vt->f[5])(o); }
extern "C" {
s32 func_00139d78(void*);
s32 func_0028acc8(u8*);
void func_0028abe0(u8*);
void func_0024c828(void);
void func_0028ce38(void);
s32 func_00287cd0(void);
s32 func_002b4fb8(void);
s32 func_00287c10(void);
void func_00233e70(s32);
s32 func_00233e60(void);
void func_00287c30(void);
void func_00287d20(s32);
s32 func_00287bc0(void);
void func_002b5188(u8*, s32);
void func_00287cc0(s32);
void func_00240bb0(s32);
void func_002417a0(void);
void func_002b4ee0(void);
void func_00287c00(s32);
u8* func_00257770(void);
void func_002634d8(s32);
void func_00257140(s32);
u32 func_00257130(void);
u32 func_00281f30(u32);
s32 func_00281f18(u32);
void func_002827f0(u32, s32, s32);
void func_00138c10(u8*, u32);
void func_00139510(u8*);

void func_0024bcb8(void)
{
    if (func_00139d78(D_0035edb0)) VCall5_82(D_0035edb0);
    if (func_00139d78(D_0035edb8)) VCall5_82(D_0035edb8);
    if (func_00139d78(D_0035edb4)) VCall5_82(D_0035edb4);
    if (func_0028acc8(D_0035eda8)) func_0028abe0(D_0035eda8);
    if (func_0028acc8(D_0035edac)) func_0028abe0(D_0035edac);
    func_0024c828();
    func_0028ce38();
}

void func_0025e370(void)
{
    s32 v = func_00287cd0();
    if (v == 2) {
        if (func_002b4fb8()) return;
        if (func_00287c10() == 1) {
            func_00233e70(0);
            if (!func_00233e60()) return;
        }
        func_00287c30();
        func_00287d20(0);
        if (func_00287bc0() == 12) func_002b5188(D_00373110, 1);
        return;
    }
    if (v == 0) func_00287cc0(1);
    func_00240bb0(8000);
    func_002417a0();
    func_002b4ee0();
    func_00287c00(12);
    func_00287cc0(2);
}

void func_002655e8(void)
{
    u8* base = func_00257770();
    s32 i;
    if (func_00139d78(base)) func_00139510(base);
    for (i = 0; i < 20; i++) {
        u8* e = base + i * 436;
        if (func_00139d78(e + 13840)) VCall5_82((VObj82*)(e + 13840));
        if (func_00139d78(e + 24304)) VCall5_82((VObj82*)(e + 24304));
    }
    if (func_0028acc8(D_0035f01c)) func_0028abe0(D_0035f01c);
}
}

extern u32 D_0035f0ec;
extern u32 D_0035f264;
extern u32 D_0035f250;

extern "C" {
u32 func_00257130(void);
u8* func_00281f20(u32);
u8* func_001a80c8(u32);
s32 func_00281f18(u32);
void func_0028d980(u8*, s32, s32, s32, u32, s32, s32, s32, s32);
void func_00139620(u8*);
void func_001395f8(u8*);
u32 func_00192048(s32);
void wt82(u8*, u32, u32) asm("_Z16wtarget_002fde18jjjj");

// Looks up entry idx of the current table (mode 2 = active slot) and returns its item record.
u8* func_0026a178(s32 idx, s32 mode)
{
    u8* tbl;
    s32 ok;
    if (mode < 0) mode = func_00287bc0();
    if (mode == 2) {
        tbl = func_00281f20(func_00257130());
        ok = func_00281f18(func_00257130());
    } else {
        tbl = func_00281f20(D_0035f0ec);
        ok = func_00281f18(D_0035f0ec);
    }
    if (ok) {
        u16 id = *(u16*)(tbl + idx * 6);
        if (id) return func_001a80c8(id);
    }
    return 0;
}

void func_00280148(void)
{
    u8* p = (u8*)D_0035f264 + 24;
    func_0028d980(p, 30045, 0, 0, D_0035f250, 7, 8, -1, 0);
    func_00139620(p);
    func_001395f8(p);
    *(u32*)(p + 432) = 2;
    *(u32*)(p + 408) = func_00192048(18691);
    p = (u8*)D_0035f264 + 460;
    func_0028d980(p, 30046, 0, 0, D_0035f250, 10, 11, -1, 0);
    wt82((u8*)D_0035f264 + 1304, 0, 8);
    func_00139620(p);
    func_001395f8(p);
    *(u32*)(p + 432) = 2;
    *(u32*)(p + 408) = D_0035f264 + 1304;
}
}

extern u32* D_0035f2e4;
extern s16 D_00374410[][5];

extern "C" {
s32 func_00286058(u8);
u32 func_0023f9c8(u8*, s32);
void func_001386e0(u32, s32, u32, u32, s32, s32);
void func_0028d8c0(u8*, u32, u32, u32, u32, u32, s32, s32);
void func_0028b4c0(u8*, u32);
void func_0028b4f0(u8*, u32);
u8* func_0023f1b0(u32);
u32 func_0023c3e0(u8*, s16, s32);
void func_0028dd28(u8*, u32);

static inline s32 Bit0028(s32 i) { return (D_0035f2e4[(u32)i >> 5] & (1 << (i & 31))) != 0; }

// id >= 0: whether item id is flagged and usable; id < 0: whether any of the 640 is.
s32 func_00286068(s32 id)
{
    s32 r = 0;
    if (id >= 0) {
        if (id != 0 && func_00286058(func_001a80c8(id)[2])) r = Bit0028(id);
    } else {
        s32 i;
        for (i = 0; i < 640; i++) {
            if (Bit0028(i) && func_00286058(func_001a80c8(i)[2])) {
                r = 1;
                break;
            }
        }
    }
    return r;
}
void func_002877a0(u8* a0, s32 a1, s32 a2)
{
    u32* slot = (u32*)(a1 * 4 + (u32)a0);
    if (func_00139d78((void*)slot[1])) {
        func_00138c10((u8*)slot[1], D_00374410[a1][a2]);
        return;
    }
    func_001386e0(slot[1], 26006, func_0023f9c8(a0 + 12, 0), *(u32*)a0 + 32, D_00374410[a1][a2], 0);
}


void func_0028b300(u8* a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2, u32 t3)
{
    s32 cur;
    s32 i;
    *(u32*)(a0 + 408) = t0;
    func_0028d8c0(a0, a1, a2, a3, t0, t3, -1, 0);
    func_0028b4c0(a0, t1);
    func_0028b4f0(a0, t2);
    cur = *(s32*)(func_0023f1b0(*(u32*)(a0 + 408)) + 76);
    {
        u8* p = a0;
        for (i = 0; i < 3; i++, p += 2) {
            if (cur == *(s16*)(p + 416))
                func_0028dd28(a0, func_0023c3e0(func_0023f1b0(*(u32*)(a0 + 408)), *(s16*)(p + 422), 0));
        }
    }
    *(s16*)(a0 + 428) = cur;
}
}

extern u8 D_00347e60[];

extern "C" {
void func_00239700(u8*);
void func_0028dfe8(void*);
void func_00258d40(u32, u32);

static inline void* Alloc82(u32 n) { Alloc0014* h = D_00347f80->heap; return h->vt->alloc(h, n, 0); }

void func_0028fc78(Mgr0014** a0, u32 a1, u32 a2, u16* a3)
{
    u8* o = (u8*)Alloc82(408);
    s32 i;
    *(u32*)(o + 12) = 0;
    *(u32*)o = (u32)D_00347e60;
    func_00239700(o + 24);
    a0[0] = (Mgr0014*)o;
    o = (u8*)Alloc82(60);
    func_0028dfe8(o);
    a0[1] = (Mgr0014*)o;
    for (i = 0; i < 3; i++) ((u16*)(a0 + 2))[i] = a3[i];
    *(u32*)(a0 + 4) = a1;
    func_00258d40(a1, a2);
}

}

static inline void QCopy82(void* d, const void* s) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory"); }
static inline void VSub82(void* d, const void* a, const void* b) { asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }
static inline f32 VLen82(const void* v)
{
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(d) : "r"(v) : "$8", "memory");
    return d;
}
union PU82 { u8* p; u32 u; f32 f; };
extern u8 D_00361da8[];
extern u8 D_00361dc8[];
extern u8 D_01e2bdd0[];
extern u8 D_01e2bdc0[];
extern PU82 D_00361db8;

extern "C" {
void func_002c6420(u8*);
u8* func_002d1260(u8*);
u8* func_0016bc20(u32, s32, s32);
void func_0017f540(u8*, s32, f32, f32);
s32 func_001c0cd8(u32);

void func_002c66b8(u8* a0, u32 a1, u32 a2)
{
    *(u32*)(a0 + 84) = 0;
    *(u32*)a0 = (u32)D_00361da8;
    *(u32*)(a0 + 92) = 0;
    func_002c6420(a0);
    *(u32*)(a0 + 96) = a1;
    *(u32*)a0 = (u32)D_00361dc8;
    *(u32*)(a0 + 100) = a2;
    QCopy82(a0 + 112, D_01e2bdd0);
    QCopy82(a0 + 128, D_01e2bdc0);
    D_00361db8.p = a0;
    *(u32*)(a0 + 84) |= 1;
    *(f32*)(a0 + 144) = 65.0f;
    *(f32*)(a0 + 92) = 60.0f;
    *(f32*)(a0 + 88) = 60.0f;
}

// Returns the target in slot a1 if it is within its own reach radius of this object.
u32 func_002d2660(u8* a0, s32 a1)
{
    u32* slot = (u32*)(a1 * 4 + (u32)a0 + 320);
    u8* o;
    f32 r;
    u8 a[16] __attribute__((aligned(16)));
    u8 b[16] __attribute__((aligned(16)));
    u8 d[16] __attribute__((aligned(16)));
    if (!slot[1]) return 0;
    o = func_002d1260(a0);
    r = *(s16*)(func_0016bc20(slot[1], 5, -1) + 16);
    QCopy82(a, func_0016c028((u32)o));
    QCopy82(b, func_0016c028(slot[1]));
    VSub82(d, a, b);
    if (VLen82(d) < r) return slot[1];
    return 0;
}

void func_002da040(u8* a0)
{
    s32 i;
    a0[3077] = 0;
    a0[3068] = 1;
    if (*(u8**)(a0 + 3060)) func_0017f540(*(u8**)(a0 + 3060) + 320, 0, 0.0f, 0.0f);
    if (*(u32*)(a0 + 3056)) {
        if (func_001c0cd8(*(u32*)(a0 + 3056))) func_0017f540(*(u8**)(a0 + 3056) + 320, 0, 0.0f, 0.0f);
        else func_0017f540(*(u8**)(a0 + 3056) + 320, 153, 0.0f, 0.0f);
    }
    func_0017f540(a0 + 320, 0, 0.0f, 0.0f);
    for (i = 0; i < 8; i++) ((Vec82*)(a0 + 3232))[i] = *func_0016c028((u32)a0);
}
}

static inline void VAdd82(void* d, const void* a, const void* b) { asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory"); }

extern "C" {
void func_002e2a30(u8*, Vec82*, u8*, u8*);
f32 func_002edd20(u32);
f32 func_002f8870(f32);
double func_00313b80(f32);
double func_00313e80(double, double);
s32 func_003142e0(double, double);

void func_002e2940(u8* a0, u8* a1, Vec82* a2, Vec82* a3)
{
    Vec82 b, a, e, d;
    if (func_00197920((S001d*)a0)) return;
    if (!a0[88]) return;
    if (!(*(u32*)(a1 + 1416) & 0x80)) return;
    VAdd82(&a, func_0016c028((u32)a1), a2);
    VAdd82(&b, &a, a3);
    QCopy82(&a, &b);
    func_002e2a30(a0, &a, a0 + 288, a0 + 304);
    VSub82(&d, &a, &b);
    VAdd82(&e, &d, a3);
    *a3 = e;
}

// Copies a2 into a0 and nudges its y toward the target height by one step.
Vec82* func_002ede48(Vec82* a0, u32 a1, Vec82* a2, f32 f12, f32 f13)
{
    f32 diff = func_002edd20(a1) - f12;
    f32 step;
    double dx;
    *a0 = *a2;
    dx = func_00313b80(func_002f8870(diff));
    step = f13 * D_00349e10;
    if (func_003142e0(func_00313e80(func_00313b80(step), 10.0), dx) < 0) {
        if (func_003142e0(func_00313b80(diff), 0.0) < 0) a0->y -= step;
        else a0->y += step;
    }
    return a0;
}
}

typedef union { f32 value; u32 word; } ieee_float_shape82;
#define GET_FLOAT_WORD82(i,d) do { ieee_float_shape82 gf_u; gf_u.value = (d); (i) = gf_u.word; } while (0)
#define SET_FLOAT_WORD82(d,i) do { ieee_float_shape82 sf_u; sf_u.word = (i); (d) = sf_u.value; } while (0)
static const f32 huge82 = 9.9999994e29f; // 1.0e30 as stored in the original

extern "C" {
typedef s32 (*Cmp82)(const void*, const void*);

// floorf (newlib, no-denormal / largest-exponent-is-normal configuration).
f32 func_002f8888(f32 x)
{
    s32 i0, j0;
    u32 i, ix;
    GET_FLOAT_WORD82(i0, x);
    ix = (i0 & 0x7fffffff);
    j0 = (ix >> 23) - 0x7f;
    if (j0 < 23) {
        if (j0 < 0) {
            if (huge82 + x > (f32)0.0) {
                if (i0 >= 0) { i0 = 0; }
                else if (!(ix < 0x00800000)) { i0 = 0xbf800000; }
            }
        } else {
            i = (0x007fffff) >> j0;
            if ((i0 & i) == 0) return x;
            if (huge82 + x > (f32)0.0) {
                if (i0 < 0) i0 += (0x00800000) >> j0;
                i0 &= (~i);
            }
        }
    } else {
        if (!1) return x + x;
        else return x;
    }
    SET_FLOAT_WORD82(x, i0);
    return x;
}

// bsearch
void* func_002fd248(const void* key, const u8* base, u32 n, u32 size, Cmp82 cmp)
{
    u32 lo = 0;
    u32 hi = n;
    if (n == 0 || size == 0) return 0;
    while (lo < hi) {
        u32 mid = (lo + hi) >> 1;
        const u8* p = base + mid * size;
        s32 c = cmp(key, p);
        if (c < 0) hi = mid;
        else if (c > 0) lo = mid + 1;
        else return (void*)p;
    }
    return 0;
}

}
