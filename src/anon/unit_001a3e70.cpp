#include "../common/types.h"

// YS attack objects (0x1a3e70-0x1a4db0): a track attack (vtable 0x350758: C2/C1, D2/D1/D0 and
// make_work 0x1a40d0) and YS::ATTACK_MAGIC (vtable 0x350778). Each function keeps the declarations
// of the source it was matched in (namespace nADDR); every external symbol is bound by asm label.
// The vtables stay retail data. Its .rodata (float literals) starts at 0x36d490.

// 001a3f08 (from anon/batch_wcx2.cpp)
namespace n001a3f08 {
typedef int qs_cmp_t(const void*, const void*);
extern u8 D_00350758[] asm("D_00350758");
void func_0018d050(u8*, u8*, u32, u32, u32, s32, u32) asm("func_0018d050");
static inline u32 K1a3f08(u8* p)
{
    u8* q;
    if (p != 0 && (q = *(u8**)(p + 0x48c)) != 0) return q[0x24c];
    return 0;
}
void func_001a3e70(u8* o, u8* p, u32 a2, u32 a3, u32 x, u32 y, u32 z) asm("func_001a3e70");
void func_001a3e70(u8* o, u8* p, u32 a2, u32 a3, u32 x, u32 y, u32 z)
{
    func_0018d050(o, p, a2, a3, K1a3f08(p), -1, y);
    *(u32*)(o + 0xc4) = z;
    *(u32*)(o + 0x2d0) = x;
    *(u32*)o = (u32)D_00350758;
    if (!(*(*(u8**)(o + 0x28) + 0x12) & 0xa)) *(u32*)(o + 0x24) = *(u32*)(o + 0x10) + 128;
}
void func_001a3f08(u8* o, u8* p, u32 a2, u32 a3, u32 x, u32 y, u32 z) asm("func_001a3f08");
void func_001a3f08(u8* o, u8* p, u32 a2, u32 a3, u32 x, u32 y, u32 z)
{
    func_0018d050(o, p, a2, a3, K1a3f08(p), -1, y);
    *(u32*)(o + 0xc4) = z;
    *(u32*)(o + 0x2d0) = x;
    *(u32*)o = (u32)D_00350758;
    if (!(*(*(u8**)(o + 0x28) + 0x12) & 0xa)) *(u32*)(o + 0x24) = *(u32*)(o + 0x10) + 128;
}
}  // namespace n001a3f08

// 001a4060 (from anon/batch_w38.cpp)
namespace n001a4060 {
struct E16 { u8 d[16]; ~E16() {} };
extern void func_00105110(void*) asm("_ZN4AREA4FreeEPv");
extern void func_0018d420(void*) asm("func_0018d420");
extern void* D_00350758[] asm("D_00350758");
struct Head18d420 { u32 vt; ~Head18d420() { func_0018d420(this); } };
struct Obj1a4060 {
    Head18d420 head;
    u8 pad4[204];
    E16 arr[32];
    u32* f720;
    ~Obj1a4060() { *(void**)this = D_00350758; *f720 = 0; }
    static void operator delete(void* p) { func_00105110(p); }
};
void func_001a3fa0(Obj1a4060* p) asm("func_001a3fa0");
void func_001a3fa0(Obj1a4060* p) { p->~Obj1a4060(); }
void func_001a4000(Obj1a4060* p) asm("func_001a4000");
void func_001a4000(Obj1a4060* p) { p->~Obj1a4060(); }
void func_001a4060(Obj1a4060* p) asm("func_001a4060");
void func_001a4060(Obj1a4060* p) {
    p->~Obj1a4060();
    Obj1a4060::operator delete(p);
}
}  // namespace n001a4060

// 001a40d0: make_work(ATTACK_WORK_MANAGER*) of the track attack (vtable 0x350758, slot 4).
// Never written before: one collision per tracked point, with in-between collisions
// along the way from the previous point.
namespace n001a40d0 {
struct Vec {
    f32 x, y, z, w;
    Vec() {}
    Vec& operator=(const Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Col {
    s32 type;
    f32 a, b;
    s32 c;
    Vec pos;
    Col() { c = 0; }
};
struct Atk;
struct Work {
    Atk* owner;
    s32 pad[3];
    Col col;
};
struct Atk {
    void* vt;
    u32 flags;       // 0x04
    u8 pad8[4];
    u8* target;      // 0x0c
    u8* obj;         // 0x10
    u8 pad14[0xc4 - 0x14];
    u32 id;          // 0xc4
    s32 count;       // 0xc8
    s32 padcc;
    Vec pts[32];     // 0xd0
};
s32 YS__OBJ__is_exist(u8*) asm("YS__OBJ__is_exist");
s32 YS__OBJ__is_stop(u8*) asm("YS__OBJ__is_stop");
s32 func_0019f550(u8*, u32) asm("func_0019f550");
u8* func_0016bc98(u8*, s32, u8*) asm("func_0016bc98");
void func_0018f028(Atk*) asm("_ZN2YS6ATTACK7destroyEv");
void YS__COLLISION__set(Col*, u8*, u8*) asm("YS__COLLISION__set");
s32 func_0018eaf8(void*, Work*) asm("func_0018eaf8");
void func_0018dc28(Atk*, Vec*, Vec*) asm("func_0018dc28");
static inline Vec Sub(const Vec& a, const Vec& b) {
    Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Norm(Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline void Scale(Vec* v, f32 s) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(v), "f"(s) : "$8", "memory");
}
static inline void Add(Vec* d, const Vec* a) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(d), "r"(a) : "memory");
}
void func_001a40d0(Atk* self, void* mgr) asm("func_001a40d0");
void func_001a40d0(Atk* self, void* mgr) {
    Vec p;
    Vec q;
    Vec d;
    Work work;
    u8* e;

    if (!YS__OBJ__is_exist(self->obj) || YS__OBJ__is_stop(self->obj) || func_0019f550(self->obj + 1148, self->id)) {
        func_0018f028(self);
        return;
    }
    if (!YS__OBJ__is_exist(self->target)) return;
    if (*(u32*)(self->target + 2040) & 4) return;
    work.owner = self;
    e = 0;
    self->count = 0;
    while ((e = func_0016bc98(self->obj, 0x2040, e)) != 0) {
        if (e[0] != self->id) continue;
        Col* c = &work.col;
        YS__COLLISION__set(c, self->obj, e);
        func_0018eaf8(mgr, &work);
        p = work.col.pos;
        if (self->count < 32) {
            if (self->flags & 4) {
                if (self->count == 0) func_0018dc28(self, &self->pts[0], &work.col.pos);
                d = Sub(self->pts[self->count], p);
                f32 len = Norm(&d);
                Scale(&d, work.col.a);
                while (c->a * 1.5f < len) {
                    Add(&work.col.pos, &d);
                    if (!func_0018eaf8(mgr, &work)) break;
                    len -= c->a;
                }
            }
            self->pts[self->count] = p;
        }
        self->count++;
    }
    if (self->count == 0) func_0018f028(self);
    else self->flags |= 4;
}
}  // namespace n001a40d0

// 001a4388 (from anon/batch_w58.cpp)
namespace n001a4388 {
struct VObj { void** vt; };
void* func_00186078(void*) asm("func_00186078");
u8* func_0016bba8(void*, s32, u8*) asm("_ZN2YS3OBJ14each_collisionEiPKNS_14COLLISION_ELEME");
void YS__ATTACK_OBJ__Exec(void) asm("YS__ATTACK_OBJ__Exec");
void YS__ATTACK_OBJ__Exec(void) {
    VObj* o = 0;
    while ((o = (VObj*)func_00186078(o)) != 0) {
        if (*(u32*)((u8*)o + 268) & 0x100000) continue;
        u8* e = 0;
        while ((e = func_0016bba8(o, 13, e)) != 0)
            ((void (*)(void*, u16, u8, void*, s32))o->vt[20])(o, *(u16*)(e + 2), e[0], o, 0);
    }
}
}  // namespace n001a4388

// 001a4498 (from anon/sweep_001a4498_nsa.cpp)
namespace n001a4498 {
void func_0018d050(void*, s32, s32, s32, s32, s32, s32) asm("func_0018d050");
void func_001a4530(void*) asm("_ZN2YS6ATTACKC2EPNS_6BTLOBJEPNS_6STDOBJEiiii");
extern u8 D_00350778[] asm("D_00350778");
typedef struct V4 { f32 x, y, z, w; } V4;
typedef struct A1 { u32 vt; u32 flags; u8 pad[0xc4 - 8]; s32 c4; f32 c8; s32 cc; u8 pad2[0x100 - 0xd0]; V4 v; u8 m110[4]; } A1;
void func_001a4420(A1* p, s32 a, s32 b, s32 c, s32 d, s32 e) asm("func_001a4420");
void func_001a4420(A1* p, s32 a, s32 b, s32 c, s32 d, s32 e) {  // obj_ctor_derived
    V4* v;
    f32 f;
    func_0018d050(p, a, a, b, d, e, c);
    p->c4 = 0;
    p->c8 = 0.0f;
    p->vt = (u32)D_00350778;
    p->cc = 0;
    v = &p->v;
    f = p->c8;
    v->x = f; v->y = f; v->z = f; v->w = f;
    func_001a4530(p->m110);
    p->flags |= 0x100;
}
void func_001a4498(A1* p, s32 a, s32 b, s32 c, s32 d, s32 e) asm("func_001a4498");
void func_001a4498(A1* p, s32 a, s32 b, s32 c, s32 d, s32 e) {  // obj_ctor_derived
    V4* v;
    f32 f;
    func_0018d050(p, a, a, b, d, e, c);
    p->c4 = 0;
    p->c8 = 0.0f;
    p->vt = (u32)D_00350778;
    p->cc = 0;
    v = &p->v;
    f = p->c8;
    v->x = f; v->y = f; v->z = f; v->w = f;
    func_001a4530(p->m110);
    p->flags |= 0x100;
}
}  // namespace n001a4498

// 001a4530 (from anon/tiny_auto80_queue.cpp)
namespace n001a4530 {
void func_001a4510(u32 a0) asm("func_001a4510");
void func_001a4510(u32 a0) {
    f32 z = 0.0f;
    u32 p = a0 + 0x20;
    volatile f32* vp = (volatile f32*)p;
    *(u32*)(a0 + 8) = 0;
    vp[0] = z;
    vp[3] = z;
    vp[1] = z;
    vp[2] = z;
}
void func_001a4530(u32 a0) asm("_ZN2YS6ATTACKC2EPNS_6BTLOBJEPNS_6STDOBJEiiii");
void func_001a4530(u32 a0) {
    f32 z = 0.0f;
    u32 p = a0 + 0x20;
    volatile f32* vp = (volatile f32*)p;
    *(u32*)(a0 + 8) = 0;
    vp[0] = z;
    vp[3] = z;
    vp[1] = z;
    vp[2] = z;
}
}  // namespace n001a4530

// 001a4550 (from anon/auto80_199_queue.cpp)
namespace n001a4550 {
u32 func_001050d8(...) asm("func_001050d8");
void func_001a4498(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5) asm("func_001a4498");
u32 func_001a4550(u32 a0, u32 a1) asm("_ZN2YS12ATTACK_MAGIC3dupEi");
u32 func_001a4550(u32 a0, u32 a1) {
    u32 s1 = func_001050d8(320);
    func_001a4498(
        s1,
        *(u32*)(a0 + 12),
        a1,
        *(u32*)(a0 + 32),
        *(u32*)(a0 + 24),
        *(u32*)(a0 + 28));
    *(u32*)(s1 + 36) = *(u32*)(a0 + 36);
    return s1;
}
}  // namespace n001a4550

// 001a45b8 (from anon/batch_w1686.cpp)
namespace n001a45b8 {
struct W1686Vec {
    f32 x, y, z, w;
    W1686Vec() {}
    W1686Vec& operator=(const W1686Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1686Col {
    s32 type;
    f32 a, b;
    s32 c;
    W1686Vec pos;
    W1686Col() { c = 0; }
};
struct W1686Magic;
struct W1686Work {
    W1686Magic* owner;
    s32 pad[3];
    W1686Col col;
};
struct W1686Magic {
    s32 pad0;
    u32 flags;               // 0x04
    u8 pad8[0xc4 - 0x8];
    void* effect;            // 0xc4
    f32 time;                // 0xc8
    f32 time_max;            // 0xcc
    W1686Vec size_start;     // 0xd0
    W1686Vec pos;            // 0xe0
    W1686Vec line_end;       // 0xf0
    W1686Vec size;           // 0x100
    u32 is_line() const { return flags & 0x20; }
    u32 is_track() const { return flags & 4; }
};
s32 func_001dc9d0(void*) asm("_ZN3ryj6EFFECT8is_aliveEv");
W1686Vec* func_001dc5f8(void*) asm("_ZN3ryj6EFFECT3posEv");
void func_001a48c0(W1686Magic*, W1686Vec*) asm("func_001a48c0");
void func_0018f028(W1686Magic*) asm("_ZN2YS6ATTACK7destroyEv");
f32 sinf(f32) asm("sinf");
void func_0018a958(W1686Col*, s32, f32, f32) asm("_ZN2YS9COLLISION4makeEiff");
s32 func_0018eaf8(void*, W1686Work*) asm("func_0018eaf8");
void func_0018dc28(W1686Magic*, W1686Vec*, W1686Vec*) asm("func_0018dc28");
extern u32 D_0034f240 asm("D_0034f240");
extern f32 D_00349e10 asm("D_00349e10");
static inline W1686Vec w1686_lerp(const W1686Vec& a, const W1686Vec& b, f32 t) {
    W1686Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}
static inline W1686Vec w1686_sub(const W1686Vec& a, const W1686Vec& b) {
    W1686Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 w1686_norm(W1686Vec* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline void w1686_scale(W1686Vec* v, f32 s) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(v), "f"(s) : "$8", "memory");
}
static inline void w1686_add(W1686Vec* d, const W1686Vec* a) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(d), "r"(a) : "memory");
}
static inline f32 w1686_min(f32 a, f32 b) { return a < b ? a : b; }
void YS__ATTACK_MAGIC__make_work(W1686Magic* self, void* mgr) asm("YS__ATTACK_MAGIC__make_work");
void YS__ATTACK_MAGIC__make_work(W1686Magic* self, void* mgr) {
    W1686Vec pos;
    W1686Vec dir;
    W1686Vec size;
    W1686Work work;

    if (self->effect) {
        if (!func_001dc9d0(self->effect)) { func_0018f028(self); return; }
        func_001a48c0(self, func_001dc5f8(self->effect));
    }
    if (self->time_max > 0.0f) {
        if (!(D_0034f240 & 0x20)) {
            self->time += D_00349e10;
            if (self->time_max < self->time) { func_0018f028(self); return; }
        }
        size = w1686_lerp(self->size_start, self->size, sinf(self->time / self->time_max * 3.1415927f * 0.5f));
    } else {
        size = self->size;
    }
    {
        f32 len;
        f32 step = w1686_min(size.x, size.y);
        if (step <= 0.0f) return;
        pos = self->pos;
        if (self->is_line() || self->is_track()) {
            dir = w1686_sub(self->line_end, self->pos);
            len = w1686_norm(&dir);
            w1686_scale(&dir, step);
        } else {
            len = 0.0f;
        }
        s32 mode = 3;
        work.owner = self;
        if (size.x != size.y) mode = 0;
        do {
            func_0018a958(&work.col, mode, size.x, size.y);
            work.col.pos = pos;
            if (!func_0018eaf8(mgr, &work)) break;
            w1686_add(&pos, &dir);
            len -= step;
        } while (step * 0.5f < len);
        if (self->is_track()) func_0018dc28(self, &self->line_end, &self->pos);
    }
}
}  // namespace n001a45b8

// 001a48c0 (from anon/batch_w84.cpp)
namespace n001a48c0 {
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq VSub(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 VLength(const Vq& v) {
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(d) : "r"(&v) : "$8", "memory");
    return d;
}
struct Trk { u32 _0; u32 flags; u8 _8[216]; Vq cur; Vq prev; };
extern f32 D_00349e10 asm("D_00349e10");
void func_001a48c0(Trk* t, Vq* v) asm("func_001a48c0");
void func_001a48c0(Trk* t, Vq* v) {
    u32 f = t->flags & 1;
    if (f) {
        t->prev = t->cur;
        Vq d;
        d = VSub(*v, t->cur);
        f32 len = VLength(d);
        if (D_00349e10 * 2.0f < len) t->flags |= 4;
        else t->flags &= ~4;
    } else {
        t->prev = *v;
    }
    t->cur = *v;
    t->flags = (t->flags | 1) & ~0x20;
}
}  // namespace n001a48c0

// 001a49a0 (from anon/batch_w17.cpp)
namespace n001a49a0 {
void func_001a49a0(u8* p, u8* a, u8* b) asm("func_001a49a0");
void func_001a49a0(u8* p, u8* a, u8* b) {
    u8* d = p + 224;
    if (d != a) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(a) : "$8", "memory");
    d = p + 240;
    if (d != b) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(b) : "$8", "memory");
    *(u32*)(p + 4) |= 0x20;
}
}  // namespace n001a49a0

// 001a49d8 (from anon/tiny_auto80_queue.cpp)
namespace n001a49d8 {
void func_001a49d8(f32 a0, f32 a1, u32 a2) asm("func_001a49d8");
void func_001a49d8(f32 a0, f32 a1, u32 a2) {
    *(f32*)(a2 + 0x100) = a0;
    if (!(0.0f < a1)) {
        a1 = a0;
    }
    *(f32*)(a2 + 0x104) = a1;
}
}  // namespace n001a49d8

// 001a49f8 (from anon/batch_w1379.cpp)
namespace n001a49f8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    f32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord Scale(const QWord& a, const f32& k)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline QWord Sub(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct Obj1a4 {
    u32 pad0;
    u32 flags;
    u8 pad8[0xe0 - 8];
    QWord pos;
    QWord prev;
};
void YS__OBJ__get_dir(QWord*, u32) asm("YS__OBJ__get_dir");
QWord* YS__OBJ__get_pos(u32) asm("YS__OBJ__get_pos");
static inline QWord Back(u32 id)
{
    QWord t;
    YS__OBJ__get_dir(&t, id);
    return Scale(t, -1.0f);
}
static inline QWord Dir(Obj1a4* o, u32 id)
{
    if (o->flags & 0x20) return Back(id);
    if (o->flags & 4) return Sub(o->pos, o->prev);
    return Sub(*YS__OBJ__get_pos(id), o->pos);
}
QWord YS__ATTACK_MAGIC__get_dir(Obj1a4* o, u32 id) asm("YS__ATTACK_MAGIC__get_dir");
QWord YS__ATTACK_MAGIC__get_dir(Obj1a4* o, u32 id)
{
    QWord r;
    r = Dir(o, id);
    if (r.v[0] == 0.0f && r.v[2] == 0.0f) r = Back(id);
    r.v[1] = 0.0f;
    Normalize(&r);
    r.v[3] = 1.0f;
    return r;
}
}  // namespace n001a49f8

// 001a4b78 (from anon/batch_w1958_nsa.cpp)
namespace n001a4b78 {
struct V58e {
    f32 x, y, z, w;
    V58e() {}
    V58e& operator=(const V58e& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
    void normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
    }
} __attribute__((aligned(16)));
static inline V58e operator-(const V58e& a, const V58e& b) {
    V58e r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder" : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
static inline V58e operator+(const V58e& a, const V58e& b) {
    V58e r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder" : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
struct S58e { u8 pad[0x9f4]; u8 x9f4[0x10]; };
struct O58e { u8 pad[0xc]; s32 xc; u8 pad2[0x84 - 0x10]; S58e* x84; u8 pad3[0xe0 - 0x88]; V58e xe0; };
s32 YS__OBJ__is_exist(s32) asm("_Z17YS__OBJ__is_existjjjj");
V58e YS__OBJ__get_target_pos(s32) asm("_Z23YS__OBJ__get_target_posjjjj");
V58e YS__OBJ__get_dir(S58e*) asm("YS__OBJ__get_dir");
s32 func_00190140(void*) asm("_ZNK2YS6TARGET8is_existEv");
V58e func_00190388(void*) asm("func_00190388");
V58e* func_001a4b78(V58e* r, O58e* o) asm("func_001a4b78");
V58e* func_001a4b78(V58e* r, O58e* o) {
    V58e d;
    if (YS__OBJ__is_exist(o->xc)) {
        *r = YS__OBJ__get_target_pos(o->xc) - o->xe0;
        r->normalize();
    } else {
        *r = YS__OBJ__get_dir(o->x84);
    }
    if (func_00190140(o->x84->x9f4)) {
        d = func_00190388(o->x84->x9f4) - o->xe0;
        d.normalize();
        *r = *r + d;
        r->normalize();
    }
    return r;
}
}  // namespace n001a4b78

// 001a4d40 (from anon/tiny_auto80_queue.cpp)
namespace n001a4d40 {
void YS__ATTACK_MAGIC__set_reaction_command(f32 a0, f32 a1, u32 a2, u32 a3, u32 a4) asm("YS__ATTACK_MAGIC__set_reaction_command");
void YS__ATTACK_MAGIC__set_reaction_command(f32 a0, f32 a1, u32 a2, u32 a3, u32 a4) {
    *(u32*)(a2 + 0x110) = a3;
    *(u32*)(a2 + 0x114) = *(u32*)(a2 + 0x0C);
    *(u32*)(a2 + 0x118) = a4;
    *(f32*)(a2 + 0x11C) = a0;
    if (!(0.0f < a1)) {
        a1 = a0;
    }
    *(f32*)(a2 + 0x120) = a1;
}
}  // namespace n001a4d40

// 001a4d70 (from anon/batch_w1664.cpp)
namespace n001a4d70 {
void func_001a4d70(u8* p, u32 v) asm("func_001a4d70");
void func_001a4d70(u8* p, u32 v) { *(u32*)(p + 196) = v; }
}  // namespace n001a4d70

// 001a4d78 (from anon/tiny_auto80_queue.cpp)
namespace n001a4d78 {
void func_001a4d78(u32 a0, f32 a1, f32 a2, f32 a3) asm("func_001a4d78");
void func_001a4d78(u32 a0, f32 a1, f32 a2, f32 a3) {
    *(volatile u32*)(a0 + 0xC8) = 0;
    *(f32*)(a0 + 0xCC) = a1;
    f32 t = *(volatile f32*)(a0 + 0xC8);
    if (!(t < a2)) {
        a2 = *(f32*)(a0 + 0x100);
    }
    *(f32*)(a0 + 0xD0) = a2;
    if (!(0.0f < a3)) {
        a3 = *(f32*)(a0 + 0x104);
    }
    *(f32*)(a0 + 0xD4) = a3;
}
}  // namespace n001a4d78

