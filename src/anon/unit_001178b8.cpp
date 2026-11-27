// Linked unit 0x00117778-0x00119bf8.
#include "../naka/libkn/stitch.hpp"
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 001178b8 (was src/anon/batch_w1666.cpp)
namespace n001178b8 {
/*TARGET 001178b8*/
// 0x00113420: definition moved into src/anon/unit_001117d8.cpp
u8* func_001178b8(u8* d, u8* s) asm("func_001178b8");
// 0x00113420: definition moved into src/anon/unit_001117d8.cpp
u8* func_001178b8(u8* d, u8* s) {
    s += 1600;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    return d;
}
}  // namespace n001178b8

// 001178d0 (was src/anon/tiny_auto80_queue.cpp)
namespace n001178d0 {
/*TARGET 001178d0*/
// 0x0011a750: definition moved into src/anon/unit_0011a660.cpp

u32 func_001178d0(u32 a0) asm("_Z13func_001178d0j");
// 0x0011a750: definition moved into src/anon/unit_0011a660.cpp

u32 func_001178d0(u32 a0) {
    u32 v0 = 0u;
    u32 t6 = (u32)((s32)a0 + (32));
    u32 t5;
    u32 t7;
L_check:
    t7 = *(u32*)((u32)t6 + (s32)(4));
    t5 = (u32)((u32)v0 << 6);
    if ((s32)t7 < 0) {
        t7 = *(u32*)((u32)t6 + (s32)(8));
        if (t7 == 0u) goto L_done;
    }
    v0 = (u32)(v0 + 1u);
    if ((s32)v0 < 24) {
        t6 = (u32)((s32)t6 + (64));
        goto L_check;
    }
    t5 = (u32)((u32)v0 << 6);
L_done:
    t7 = (u32)(t5 + a0);
    *(u32*)((u32)t7 + (s32)(32)) = 0u;
    return v0;
}
}  // namespace n001178d0

// 00117910 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00117910 {
/*TARGET 00117910*/
// 0x001157a8: definition moved into src/anon/unit_00114a90.cpp

void func_00117910(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00117910jjjj");
// 0x001157a8: definition moved into src/anon/unit_00114a90.cpp

void func_00117910(u32 a0, u32 a1, u32 a2, u32 a3) {  // entry64_clear_fields
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15;
    r5 = (u32)(r5 << 6);
    r15 = (u32)((s32)0u + (-1));
    r5 = (u32)(r5 + r4);
    r5 = (u32)((s32)r5 + (32));
    *(u32*)((u32)r5 + (s32)(4)) = r15;
    *(u32*)((u32)r5 + (s32)(8)) = 0u;
}
}  // namespace n00117910

// 00117930 (was gap)
namespace g00117930 {
// Slot index holding handle h (24 when none does).
s32 f(u8* o, u32 h) asm("func_00117930");
s32 f(u8* o, u32 h) {
    u8* p = o + 40;
    s32 i;
    for (i = 0; i < 24; i++) {
        if (*(u32*)p == h) break;
        p += 64;
    }
    return i;
}
}  // namespace g00117930

// 00117960 (was gap)
namespace g00117960 {
struct Slot { u8 pad[40]; u32 h; u8 pad2[20]; };
u32 f(u8* o, s32 i) asm("func_00117960");
u32 f(u8* o, s32 i) { return ((Slot*)o)[i].h; }
}  // namespace g00117960

// 00117970 (was src/anon/batch_w3831.cpp)
namespace n00117970 {
// 00117970: takes a free 64-byte slot from the manager, fills its header and parameter
// block, clears its two vectors (VU0) and sets the owner/attribute flags.
struct W3831SlotH { u32 flags; s32 a; s32 pad8; s32 c; };
struct W3831SlotP { s32 d; s32 w; s32 z; s32 pad; };
struct W3831Slot64 { u8 pad[32]; W3831SlotH h; W3831SlotP p; f32 v0[4]; f32 v1[4]; };
struct W3831Slot { W3831SlotH h; W3831SlotP p; f32 v0[4]; f32 v1[4]; };
struct W3831SlotMgr { s32 pad0; s32 owner; u8 pad8[24]; W3831Slot slot[24]; };
s32 func_001178d0(W3831SlotMgr*) asm("func_001178d0");
s32 func_00111e38(s32) asm("func_00111e38");
/*TARGET 00117970*/
s32 kn__Stitch__startEffect(W3831SlotMgr* m, s32 a, s32 y, s32 z, s32 w, u8 b, s32 c, s32 d) asm("kn__Stitch__startEffect");
s32 kn__Stitch__startEffect(W3831SlotMgr* m, s32 a, s32 y, s32 z, s32 w, u8 b, s32 c, s32 d)
{
    // Pins/empty asm (no code): w and d keep s0/s2, h stays a register in t5, and the
    // empty ties order the parameter stores like the original.
    register s32 w_ asm("$16") = w;
    register s32 d_ asm("$18") = d;
    asm("" : "+r"(d_));
    s32 i = func_001178d0(m);
    W3831Slot64* s = (W3831Slot64*)((i << 6) + (u32)m);
    W3831SlotP* p = &s->p;
    register W3831SlotH* h asm("$13") = &s->h;
    asm("" : "+r"(h), "+r"(w_) : "r"(p));
    p->w = w_;
    p->d = d_;
    h->c = c;
    asm("" : "+r"(s) : "r"(w_));
    p->z = z;
    s->h.flags = 0;
    h->a = a;
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(s->v0) : "memory");
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(s->v1) : "memory");
    if (y != 0) {
        s32 o = func_00111e38(0);
        if (y == m->owner) {
            s->h.flags |= 1;
            if (a == 0) s->h.flags |= 0x20;
        } else if (y == o) {
            s->h.flags |= 2;
        }
    }
    if (b) m->slot[i].h.flags |= 8;
    return i;
}
}  // namespace n00117970

// 00117aa8 (was src/anon/tiny_leaf.cpp)
namespace n00117aa8 {
/*TARGET 00117aa8*/
// 0x00111040: definition moved into src/anon/unit_00110b00.cpp

void func_00117aa8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00117aa8jjjj");
// 0x00111040: definition moved into src/anon/unit_00110b00.cpp

void func_00117aa8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r5 = (u32)(r5 << 6);
    r14 = (u32)(0x4000u << 16);
    r5 = (u32)(r5 + r4);
    r15 = *(u32*)((u32)r5 + (s32)(32));
    r15 = (u32)(r15 | r14);
    *(u32*)((u32)r5 + (s32)(32)) = r15;
}
}  // namespace n00117aa8

// 00117ac8 (was gap)
namespace g00117ac8 {
struct Q {
    f32 x, y, z, w;
    Q& operator=(const Q& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// Slot i's position (w = 1).
void f(u8* o, s32 i, const Q* v) asm("func_00117ac8");
void f(u8* o, s32 i, const Q* v) {
    Q* d = (Q*)(o + (i << 6) + 80);
    *d = *v;
    d->w = 1.0f;
}
}  // namespace g00117ac8

// 00117af8 (was gap)
namespace g00117af8 {
struct Q {
    f32 x, y, z, w;
    Q& operator=(const Q& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// Slot i's direction (w = 0).
void f(u8* o, s32 i, const Q* v) asm("func_00117af8");
void f(u8* o, s32 i, const Q* v) {
    Q* d = (Q*)(o + (i << 6) + 64);
    *d = *v;
    d->w = 0.0f;
}
}  // namespace g00117af8

// 00117b20 (was src/anon/tiny_leaf.cpp)
namespace n00117b20 {
/*TARGET 00117b20*/
void func_00117b20(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00117b20jjjj");
void func_00117b20(u32 a0, u32 a1, u32 a2, u32 a3) {  // entry64_set_bit10
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r15 = 0u;
    r5 = (u32)(r5 << 6);
    r5 = (u32)(r5 + r4);
    r15 = *(u32*)((u32)r5 + (s32)(32));
    r15 = (u32)(r15 | 0x0010u);
    *(u32*)((u32)r5 + (s32)(32)) = r15;
}
}  // namespace n00117b20

// 00117b38 (was src/anon/batch_w86.cpp)
namespace n00117b38 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void Zero(V4* v) { asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(v) : "memory"); }
union FU { f32 f; s32 i; };
struct Obj {
    void* vt; u8 p4[8]; s32 f12; void* f16; FU* f20; u8 p24[8]; u8 sub32[1536]; s32 f1568; u8 p1572[4];
    f32 f1576; f32 f1580; s32 f1584; u8 p1588[12]; V4 a; V4 b; u8 p1632[16]; s32 f1648; f32 f1652; u8 p1656[72];
    u8 sub1728[200]; s32 f1928;
};
extern u8 D_003476f0[] asm("D_003476f0");
extern u8 D_00347588[] asm("D_00347588");
void func_00113628(Obj*) asm("func_00113628");
void func_0031a060(void*) asm("func_0031a060");
FU* func_00114490(Obj*, s32) asm("func_00114490");
void func_0011b6a8(void*) asm("func_0011b6a8");
void func_00117910(Obj*, s32) asm("func_00117910");
/*TARGET 00117b38*/
// entry64_clear_fields
void func_00117b38(Obj* o) asm("func_00117b38");
// entry64_clear_fields
void func_00117b38(Obj* o)
{
    func_00113628(o);
    o->vt = D_003476f0;
    func_0031a060(o->sub32);
    o->f12 = 7;
    o->f16 = D_00347588;
    o->f20 = func_00114490(o, 128);
    o->f1584 = 0;
    o->f1648 = 0;
    o->f1652 = o->f20[1].f;
    Zero(&o->a);
    Zero(&o->b);
    o->b.z = 1024.0f;
    o->a.z = 1024.0f;
    o->f1576 = 15.0f;
    o->f1580 = 0.19634955f;
    func_0011b6a8(o->sub1728);
    for (s32 i = 0; i < 24; i++) func_00117910(o, i);  // entry64_clear_fields
    o->f1568 = 0;
    o->f1928 = 0;
}
}  // namespace n00117b38

// 00117c28 (was src/anon/batch_w87.cpp)
namespace n00117c28 {
// 0x0010e6e0: definition moved into src/anon/unit_0010dee8.cpp

// ---- 0x117c28: constructor ----
union FU { f32 f; s32 i; };
void func_00113628(void*) asm("func_00113628");
void func_0031a060(void*) asm("func_0031a060");
void* func_00114490(void*, s32) asm("func_00114490");
void func_0011b6a8(void*) asm("func_0011b6a8");
void func_00117910(void*, s32) asm("func_00117910");
// entry64_clear_fields
extern u8 D_003476f0[] asm("D_003476f0");
extern u8 D_00347588 asm("D_00347588");
/*TARGET 00117c28*/
void func_00117c28(u8* p) asm("func_00117c28");
void func_00117c28(u8* p) {
    func_00113628(p);
    *(u32*)p = (u32)D_003476f0;
    func_0031a060(p + 32);
    *(s32*)(p + 12) = 7;
    *(void**)(p + 16) = &D_00347588;
    FU* v = (FU*)func_00114490(p, 128);
    *(FU**)(p + 20) = v;
    ((FU*)(p + 1584))->i = 0;
    ((FU*)(p + 1648))->i = 0;
    ((FU*)(p + 1652))->f = v[1].f;
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 1600) : "memory");
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 1616) : "memory");
    *(f32*)(p + 1608) = *(f32*)(p + 1624) = 1024.0f;
    *(f32*)(p + 1576) = 15.0f;
    *(f32*)(p + 1580) = 0.19634954631328583f;
    func_0011b6a8(p + 1728);
    for (s32 i = 0; i < 24; i++) func_00117910(p, i);  // entry64_clear_fields
    *(s32*)(p + 1568) = 0;
    *(s32*)(p + 1928) = 0;
}
}  // namespace n00117c28

// 00117d18 (was src/anon/batch_w84.cpp)
namespace n00117d18 {
struct NoTail { ~NoTail() {} };
struct E64 { u8 d[64]; ~E64() {} };
struct Arr24 { E64 e[24]; };
// 001051b8: moved to src/common/area.cpp

// Destructor: release the 24 slot objects, then the member array and base.
extern void* D_003476f0[] asm("D_003476f0");
void func_001dc920(void*) asm("func_001dc920");
void func_00117910(void*, s32) asm("func_00117910");
// entry64_clear_fields
void func_0018f028(void*) asm("func_0018f028");
void func_00113668(void*) asm("func_00113668");
/*TARGET 00117d18*/
void func_00117d18(u8* p) asm("func_00117d18");
void func_00117d18(u8* p) {
    NoTail nt;
    *(void**)p = D_003476f0;
    s32 i = 0;
    void** e = (void**)(p + 40);
    do {
        void* o = *e;
        e += 16;
        if (o) func_001dc920(o);
        func_00117910(p, i);  // entry64_clear_fields
        i++;
    } while (i < 24);
    void* x = *(void**)(p + 1568);
    if (x) {
        func_0018f028(x);
        *(void**)(p + 1568) = 0;
    }
    ((Arr24*)(p + 32))->~Arr24();
    func_00113668(p);
}
}  // namespace n00117d18

// 00117dd8 (was src/anon/batch_w85.cpp)
namespace n00117dd8 {
// local with an empty destructor: keeps the final call a jal
struct NoTail { ~NoTail() {} };
struct Slot117 { u32 a, b; void* p; u8 pad[52]; ~Slot117() {} } __attribute__((aligned(16)));
struct SlotArr117 { Slot117 s[24]; };
struct Obj117 {
    void* vtbl; u8 pad[28];
    SlotArr117 slots;
    void* f1568;
};
// 0x001123f0: definition moved into src/anon/unit_001117d8.cpp

void func_001dc920(void*) asm("func_001dc920");
void func_00117910(void*, s32) asm("func_00117910");
// entry64_clear_fields
void func_0018f028(void*) asm("func_0018f028");
void func_00113668(void*) asm("func_00113668");
extern u8 D_003476f0[] asm("D_003476f0");
/*TARGET 00117dd8*/
// destructor body: release the 24 slots, then the base part
void func_00117dd8(Obj117* o) asm("func_00117dd8");
// destructor body: release the 24 slots, then the base part
void func_00117dd8(Obj117* o) {
    NoTail g;
    s32 i;
    o->vtbl = D_003476f0;
    for (i = 0; i < 24; i++) {
        if (o->slots.s[i].p) func_001dc920(o->slots.s[i].p);
        func_00117910(o, i);  // entry64_clear_fields
    }
    if (o->f1568) { func_0018f028(o->f1568); o->f1568 = 0; }
    o->slots.~SlotArr117();
    func_00113668(o);
}
}  // namespace n00117dd8

// 00117e98 (was src/anon/batch_w87.cpp)
namespace n00117e98 {
void func_00117910(void*, s32) asm("func_00117910");
// entry64_clear_fields
extern u8 D_003476f0[] asm("D_003476f0");
// 0x002b3df8: definition moved into src/anon/unit_002b3ac8.cpp

// ---- 0x117e98: deleting destructor ----
struct Elem64 { u8 p8[8]; void* h; u8 d[52]; ~Elem64() {} } __attribute__((aligned(16)));
struct Obj117 { void* vt; u8 pad[28]; Elem64 e[24]; void* f1568; };
void func_001dc920(void*) asm("func_001dc920");
void func_0018f028(void*) asm("func_0018f028");
void func_00113668(void*) asm("func_00113668");
void func_00105110(void*) asm("func_00105110");
/*TARGET 00117e98*/
void func_00117e98(u8* p) asm("func_00117e98");
void func_00117e98(u8* p) {
    *(u32*)p = (u32)D_003476f0;
    s32 i = 0;
    do {
        void* o = ((Obj117*)p)->e[i].h;
        if (o) func_001dc920(o);
        func_00117910(p, i);  // entry64_clear_fields
    } while (++i < 24);
    if (*(void**)(p + 1568)) {
        func_0018f028(*(void**)(p + 1568));
        *(void**)(p + 1568) = 0;
    }
    Elem64* b = ((Obj117*)p)->e;
    if (b) {
        Elem64* e = b + 24;
        for (;;) {
            if (b == e) break;
            e--;
            e->~Elem64();
        }
    }
    func_00113668(p);
    func_00105110(p);
}
}  // namespace n00117e98


// 00117f60, 00118108: two never-written friend action handlers (same shape as 0x118998).
namespace n00117f60 {
struct V117f60 {
    f32 x, y, z, w;
    V117f60() {}
    V117f60& operator=(const V117f60& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V117f60 operator-(const V117f60& b) const
    {
        V117f60 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    void zero() { asm volatile(".set noreorder\n\tvsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this) : "memory"); }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct Tgt117f60;
void func_00190128(Tgt117f60*) asm("_ZN2YS6TARGETC1Ev");
struct Tgt117f60 {
    s32 f0, f4, f8, f12, f16;
    Tgt117f60() { func_00190128(this); }
};
struct Model117f60 { u8 pad0[268]; u32 f268; };
struct Cam117f60 { u8 pad[112]; f32 x, y; };
struct Who117f60 {
    u8 pad0[4];
    Model117f60* model;
    Cam117f60* cam;
    u8 pad1[1576 - 12];
    f32 maxSpeed;
    u8 pad2[1600 - 1580];
    V117f60 from;
    V117f60 to;
    V117f60 dir;
};
extern f32 D_00349e18 asm("D_00349e18");
void func_00190878(Tgt117f60*, s32, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
s32 func_001b58a8(void) asm("_ZN2YS5LIMIT6IsExecEv");
s32 func_0010ef48(Model117f60*) asm("func_0010ef48");
s32 func_0010f8c0(Model117f60*) asm("func_0010f8c0");
f32 func_0010f8a8(Model117f60*) asm("func_0010f8a8");
void func_0010f880(Model117f60*, f32, f32) asm("func_0010f880");
s32 func_0010f9e0(Model117f60*, s32) asm("func_0010f9e0");
s32 func_001917c0(void) asm("_ZN2YS6STATUS12IsBattleModeEv");
f32 func_0017ce10(f32) asm("_ZN2YS4MATH9FixRadianEf");
f32 func_002f8870(f32) asm("fabsf");
void func_0017f540(void*, s32, f32, f32) asm("_ZN2YS6MOTION6changeEiff");
s32 func_00116d08(Who117f60*) asm("func_00116d08");
void kn__Stitch__calc_move_target(Who117f60*, s32) asm("kn__Stitch__calc_move_target");
void func_001168c0(Who117f60*) asm("func_001168c0");

s32 func_00117f60(Who117f60* w, void* e, Tgt117f60* t, s32* score, u8 check) asm("func_00117f60");
s32 func_00117f60(Who117f60* w, void* e, Tgt117f60* t, s32* score, u8 check)
{
    if (check) {
        *score = 0;
        Tgt117f60 tmp;
        func_00190878(&tmp, 0, 0);
        *t = tmp;
        if (func_001b58a8()) return 0;
        if (w->model->f268 & 0x800) return 0;
        if (func_0010ef48(w->model)) return 0;
        if (!func_0010f8c0(w->model)) return 1;
        if (func_0010f8a8(w->model) <= 0.0f) return 0;
        return 1;
    }
    if (!func_0010f8c0(w->model)) {
        f32 x = w->cam->x;
        f32 y = w->cam->y;
        if (func_001917c0()) {
            x = x * 2.0f + 60.0f;
            y = y * 2.0f + 60.0f;
        }
        if (0.7853982f < func_002f8870(func_0017ce10(*(f32*)((u8*)w + 1612)))) {
            x *= 0.3f;
            y *= 0.3f;
        }
        func_0010f880(w->model, x, y);
    }
    func_0017f540((u8*)w->model + 320, 0, 4.0f, 0.0f);
    w->dir.zero();
    return 1;
}

s32 func_00118108(Who117f60* w, s32 a1, Tgt117f60* t, s32* score, u8 check) asm("func_00118108");
s32 func_00118108(Who117f60* w, s32 a1, Tgt117f60* t, s32* score, u8 check)
{
    if (check) {
        *score = 0;
        Tgt117f60 tmp;
        func_00190878(&tmp, 0, 0);
        *t = tmp;
        if (func_001b58a8()) return 0;
        if (w->model->f268 & 0x800) return 0;
        if (func_0010ef48(w->model)) return 0;
        if (func_0010f8c0(w->model)) {
            if (func_00116d08(w)) goto no;
        } else if (func_0010f9e0(w->model, a1)) goto no;
        return 1;
    no:
        return 0;
    }
    if (!func_0010f8c0(w->model)) {
        kn__Stitch__calc_move_target(w, -1);
        func_0017f540((u8*)w->model + 320, 161, 4.0f, 0.0f);
    }
    w->dir = w->to - w->from;
    f32 sp = w->dir.normalize() * D_00349e18;
    w->dir.w = sp;
    if (w->maxSpeed < sp) w->dir.w = w->maxSpeed;
    func_001168c0(w);
    return 1;
}
}  // namespace n00117f60
