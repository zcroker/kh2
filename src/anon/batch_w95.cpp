#include "../common/types.h"
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4 { V4 r[4]; } __attribute__((aligned(16)));
struct NoTail { ~NoTail() {} };
static inline void QCOPY(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline void VAssign(V4* d, V4* s) {
    if (d != s) QCOPY(d, s);
}
static inline void ApplyM(V4* d, M4* m, V4* v) {
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(d), "r"(m), "r"(v) : "memory");
}
static inline void ApplyTo(V4* d, M4* m, V4* v) { V4 t; ApplyM(&t, m, v); VAssign(d, &t); }
static inline void VAddTo(V4* d, V4* a, V4* b) {
    V4 t;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&t), "r"(a), "r"(b) : "memory");
    VAssign(d, &t);
}
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& s) {
        if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq operator-(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Normalize(Vq& d) {
    f32 len;
    asm volatile(
        "lqc2 $vf1, 0(%1)\n\t"
        "vmul.xyz $vf2, $vf1, $vf1\n\t"
        "vaddy.x $vf2, $vf2, $vf2y\n\t"
        "vaddz.x $vf2, $vf2, $vf2z\n\t"
        "vsqrt Q, $vf2x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8, $vi22\n\t"
        "vaddq.x $vf2, $vf0, Q\n\t"
        "mtc1 $8, %0\n\t"
        "vnop\n\t"
        "vdiv Q, $vf0w, $vf2x\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf1, $vf1, Q\n\t"
        "sqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(&d) : "$8", "memory");
    return len;
}
union FI { f32 f; s32 i; };

struct Heap;
struct HeapVt { void* (*alloc)(Heap*, u32, u32); void (*free)(Heap*, void*); };
struct Heap { HeapVt* vt; };

void wtarget_00151df0(u32, u32, u32, u32) asm("_Z16wtarget_00151df0jjjj");
struct TaskB { u8 pad0[4]; f32 t; u8 pad8[8]; u32 mode; u8 pad20[28]; void* fn; };
void func_00161f48_impl(u8 mode, f32 t) asm("_Z13func_00161f48i");
struct EvInfo { u8 pad[4]; u8 kind; };
struct HitEv { u8 pad0[32]; EvInfo* info; u8 pad36[2]; u8 type; u8 pad39; s32 power; };
struct ActObj;
struct ActVt { u8 pad[96]; s32 (*canHit)(ActObj*); void* slot100; void (*onHit)(ActObj*, HitEv*); };
struct ActMask { u32 a, b, c; };
struct ActObj { ActVt* vt; u8 pad4[2036]; u32 flags; u8 pad2044[704]; ActMask mask; };
static inline u8 IsGuardKind(HitEv* e) { return (u32)(e->info->kind - 5) < 2; }
struct Homing { Vq pos; void (*step)(void); u8 pad20[28]; Vq dir; f32 speed; u32 pad68; u32 target; u32* owner; };
struct SaveBig { u64 d[0x10fc0 / 8]; } __attribute__((aligned(16)));
struct SaveMid { u32 d[2088 / 4]; };
typedef unsigned int u128 __attribute__((mode(TI)));
struct Lockon { u32 target; u32 pad4[3]; Vq aim; Vq tpos; Vq dir; u32 obj; u32 objId; u32 pad72[2]; Vq opos; u32 t96; u32 t100; };
static inline Vq operator*(const Vq& a, f32 s) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) < (b) ? (b) : (a))
struct XfRec { f32 x, y, z, pad; f32 rx, ry, rz, pad2; f32 s[3]; };
struct XfCtx { u8 pad[12]; u32* offs; };
struct XfMat { u8 pad[16]; f32 r0[4]; f32 r1[4]; f32 r2[4]; f32 r3[4]; f32 m0[4]; f32 m1[4]; f32 m2[4]; f32 m3[4]; };
struct XfCtx2 { u8 pad[12]; u32* offs; };
struct Osc { u32 on; f32 pos; f32 vel; f32 acc; f32 pos2; f32 vel2; f32 acc2; };
struct OscIn { u32 id; u32 pad[2]; f32 a, b; u32 pad2; f32 c, d; };
struct Heap2;
struct Heap2Vt { void* (*alloc)(Heap2*, u32, u32); };
struct Heap2 { Heap2Vt* vt; };
struct HeapOwner { u8 pad[20]; Heap2* heap; };
struct ItemSlot { void* vt; u8 pad4[8]; u8 a[12]; u8 b[384]; };
struct ItemPanel { void* vt; u8 pad4[8]; u32 f12; u8 pad16[8]; ItemSlot slot[7]; };
struct Cfg84 { u32 d[21]; };
struct DirEnt { u8 pad0[16]; u32 size; u16 attr; u8 pad22[10]; char name[32]; };
struct SaveRec { u32 type; u32 size; char name[32]; };
struct SaveList { s32 n; u32 pad; SaveRec rec[1]; };
struct SaveSel { s8 a, b; };
struct MPartA { u8 d[408]; };
struct MPartB { u8 d[436]; };
struct MenuParts { MPartA a[5]; MPartB b[4]; };
struct ColEnt { u8 pad[5]; u8 col; u8 pad6[2]; };
struct ColSlot { s16 id; u8 pad2; s8 col; u8 pad4[4]; };
struct ColSlot2 { u16 id; u16 pad2; s8 lock; u8 pad5[3]; };
struct ColTab2 { u8 pad[12]; ColSlot2 s[1]; };
struct SortEnt { u16 id; u16 x; u16 key; };
struct SortList { union { s32 n; u16 h; }; SortEnt e[1]; };
struct SeReq { s16 id; s16 pass; s16 arg; };
struct TaskInfo { u32 a; u32 name; };
struct PickCur { s8 n; s8 sel; u8 pad2[66]; s16 x; s16 y; };
struct AnmId3 { s16 a, b, c; };
static inline void MCOPY(M4* d, const M4* s) {
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
static inline void MMul(M4* d, M4* a, M4* b) {
    asm volatile(
        "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
        "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
        "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
        "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void MMulTo(M4* d, M4* a, M4* b) {
    M4 t;
    MMul(&t, a, b);
    if (d != &t) MCOPY(d, &t);
}
struct CamObj { u8 pad[4]; u8 drawn; u8 pad5[83]; u8 active; };
struct MdlRef { u32 a; u8* mdl; };
u32 ctarget_002ed8e0(u32, u32, u32, u32) asm("_Z16ctarget_002ed8e0jjjj");
struct Bigint { Bigint* next; };
struct Reent { u8 pad[72]; Bigint* p5s; };
extern "C" {
extern u8 D_0036ac80[];
Heap* func_001050c8(void);
u32 func_001688c8(void*);
void func_00168388(void*, u32, u32, u32);
s32 func_00170cd0(void);
void func_002bb070(u32, u32, u32, u32, u32);
s32 func_002ba200(void);
void func_00102448(u32, u32);
// Load a file into a temporary 64-byte aligned buffer, process it, free.
void func_00136ba8(u32 a) {
    Heap* h = func_001050c8();
    u32 size = func_001688c8(D_0036ac80);
    void* mem = h->vt->alloc(h, (size + 0x83f) & ~0x7ff, 0);
    u32 buf = ((u32)mem + 63) & ~63;
    func_00168388(D_0036ac80, buf, 0, 0);
    while (func_00170cd0()) func_00102448(a, 0);
    func_002bb070(1, buf, size, 0, 0);
    while (func_002ba200()) func_00102448(a, 0);
    h->vt->free(h, mem);
}

extern f32 D_00349e10;
extern f32 D_004573dc;
void func_0011b6a8(M4*);
void func_0011b720(M4*, f32);
f32 func_0017ce80(f32, f32, f32);
void func_0013f648(u8*);
void func_0013f888(u8* p, V4* pos, u8 mode) {
    f32 d = *(f32*)(p + 0x48) - *(f32*)(p + 0xd0);
    f32 h = *(f32*)(p + 0xd8) * (d * d);
    if (mode == 1) *(f32*)(p + 0x4c) = *(f32*)(p + 0x50);
    else {
        f32 dt = D_00349e10;
        *(f32*)(p + 0x4c) = func_0017ce80(*(f32*)(p + 0x4c), *(f32*)(p + 0x50), D_004573dc * dt);
    }
    V4 v;
    v.w = v.y = v.x = 0.0f;
    v.z = *(f32*)(p + 0x48);
    M4 m;
    func_0011b6a8(&m);
    func_0011b720(&m, *(f32*)(p + 0x4c));
    ApplyTo(&v, &m, &v);
    VAddTo((V4*)(p + 0x60), pos, &v);
    *(f32*)(p + 0x64) = pos->y - -150.0f - h;
    if (mode == 1) func_0013f648(p);
}

// Quicksort of key[] (floats, ascending) carrying idx[] along.
void func_001472b8(FI* idx, FI* key, s32 lo, s32 hi) {
    s32 i = lo, j = hi;
    f32 p = key[(hi + lo) >> 1].f;
    do {
        while (key[i].f < p) i++;
        while (p < key[j].f) j--;
        if (i <= j) {
            f32 t = key[i].f; key[i].f = key[j].f; key[j].f = t;
            s32 u = idx[i].i; idx[i].i = idx[j].i; idx[j].i = u;
            i++; j--;
        }
    } while (i <= j);
    if (lo < j) func_001472b8(idx, key, lo, j);
    if (i < hi) func_001472b8(idx, key, i, hi);
}

s32 func_00152100(u32, u32);
void func_001520c0(u32, u32);
u32 func_0013e678(void);
u32 func_0013a7e8(u32);
void func_001386e0(u8*, u32, u32, u32, u32, u32);
void func_001396b0(u8*);
void func_0031a260(u8*, u32);
void func_00138c40(u8*, u32, u32);
void func_00239988(u8*, u32, u32);
void func_00239bf8(u8*, u32);
void func_00151d48(u8*);
u32 func_0023aa78(u8*);
void func_0014fc40(u8*, u32, u32, u32, u32, u32);
}
void wtarget_00151df0(u32 a, u32 b, u32, u32) {
    u8* p = (u8*)a;
    if (func_00152100(a, b)) {
        func_001520c0(a, b);
        return;
    }
    *(u32*)(p + 2892) = b;
    u32 w = func_0013e678();
    u32 m = func_0013a7e8(0);
    u8* q = p + 48;
    func_001386e0(q, 4600, m, w, 17, 7);
    *(u32*)(q + 396) = 0;
    func_001396b0(q);
    if (*(u32*)(q + 396)) {
        *(u32*)(q + 400) = 0;
        func_001396b0(q);
        if (*(u32*)(q + 400)) func_0031a260(q, 0);
    }
    func_00138c40(q, 0, *(u32*)(p + 36));
    u8* r = p + 456;
    for (s32 i = 0; i < 7; i++) {
        func_00239988(r, m, w);
        func_00239bf8(r, 28);
        r += 344;
    }
    func_00151d48(p);
    func_0014fc40(p, 17, func_0023aa78(p + 72), 4600, 7, 0);
}
extern "C" {

extern f32 D_00349e10;
extern f32 D_004f35a8;
extern V4 D_0034a9b0;
void func_0011b6a8(M4*);
void func_0011b720(M4*, f32);
f32 func_0017ce80(f32, f32, f32);
void func_00158c88(u8* p) {
    VAssign((V4*)(p + 0x80), &D_0034a9b0);
    f32 d = *(f32*)(p + 0x48) - *(f32*)(p + 0xd0);
    f32 dt = D_00349e10;
    f32 h = *(f32*)(p + 0xd8) * (d * d);
    *(f32*)(p + 0x4c) = func_0017ce80(*(f32*)(p + 0x4c), *(f32*)(p + 0x50), D_004f35a8 * dt);
    V4 v;
    v.w = v.y = v.x = 0.0f;
    v.z = *(f32*)(p + 0x48);
    M4 m;
    func_0011b6a8(&m);
    func_0011b720(&m, *(f32*)(p + 0x4c));
    ApplyTo(&v, &m, &v);
    VAddTo((V4*)(p + 0x60), (V4*)(p + 0x80), &v);
    *(f32*)(p + 0x64) = *(f32*)(p + 0x84) - -220.0f - h;
}

// GS register setup for two draw contexts (constructor).
extern u8 D_0034c6e0[];
void func_0014b7f0(u8*);
void func_0014c050(u8*);
void func_0014b610(u8*, u64);
void func_0014b608(u8*, u64);
void func_0014b5e0(u8*, u64);
void func_0014b630(u8*, u64);
void func_0014b618(u8*, u64);
void func_0014b5e8(u8*, u64, u64);
void func_0014b208(u8*, u64, u64);
void func_0014b468(u8*, u64, u64);
void func_0014b628(u8*, u64);
void func_0015e3b8(u8* p) {
    *(u32*)(p + 4) = 0;
    *(u32*)p = (u32)D_0034c6e0;
    u8* a = p + 144;
    func_0014b7f0(a);
    func_0014c050(p + 416);
    *(u32*)(p + 1200) = 0;
    func_0014b610(a, 0x131000070ULL);
    func_0014b608(a, 0x00ffffff00080140ULL);
    func_0014b5e0(a, 278);
    func_0014b630(a, 96);
    func_0014b618(a, 0x3cfe5);
    func_0014b5e8(a, 0x80008, 0x4080408);
    func_0014b610(p + 416, 0x131000070ULL);
    func_0014b5e0(p + 416, 342);
    func_0014b630(p + 416, 96);
    func_0014b618(p + 416, 0x3001d);
    func_0014b208(p + 416, 512, 416);
    func_0014b468(p + 416, 512, 416);
    func_0014b628(p + 416, 0x2006a00664022800ULL);
}

extern u8 D_0034c6c8[];
extern u8 D_004f3820[];
void func_0014c050(u8*);
void func_0014b610(u8*, u64);
void func_0014b608(u8*, u64);
void func_0014b5e0(u8*, u64);
void func_0014b630(u8*, u64);
void func_0014b618(u8*, u64);
void func_0014b220(u8*, u64, u64, u64, u64);
void func_0014b208(u8*, u64, u64);
void func_0014b468(u8*, u64, u64);
void func_0014b628(u8*, u64);
void func_0015e8c8(u8* p) {
    *(u32*)(p + 4) = 0;
    *(u32*)p = (u32)D_0034c6c8;
    func_0014c050(p + 80);
    *(u32*)(p + 864) = 0;
    func_0014b610(D_004f3820, 0x131000070ULL);
    func_0014b608(D_004f3820, 0x80140);
    func_0014b5e0(D_004f3820, 6);
    func_0014b220(D_004f3820, 0, 0, 0, 0);
    func_0014b208(D_004f3820, 512, 416);
    func_0014b610(p + 80, 0x131000070ULL);
    func_0014b5e0(p + 80, 342);
    func_0014b630(p + 80, 96);
    func_0014b618(p + 80, 0x3001d);
    func_0014b208(p + 80, 512, 416);
    func_0014b468(p + 80, 512, 416);
    func_0014b628(p + 80, 0x2006a00664022800ULL);
}

TaskB* func_00102c18(s32, s32, void (*)(void));
struct TaskMgr { u32 pad; void* q; };
TaskMgr* func_00102c80(void);
void func_00102670(void*, TaskB*);
void func_00161df0(void);
void func_00161f10(void);
void func_00161c20(void);
void func_00161f38(void);
struct U8Flag { u8 v; };
extern U8Flag D_0034c770;
extern U8Flag D_0034c771;
extern void* D_0034c778;
}
void func_00161f48_impl(u8 mode, f32 t) {
    if (mode == 1) {
        TaskB* k = func_00102c18(1, 0x186a0, func_00161df0);
        k->mode = mode;
        k->t = t + t;
        D_0034c770.v = 1;
        func_00102c18(1, 0x15f90, func_00161f10);
        if (D_0034c778) func_00102670(func_00102c80()->q, (TaskB*)D_0034c778);
        D_0034c778 = func_00102c18(1, 0x16008, func_00161c20);
        ((TaskB*)D_0034c778)->fn = (void*)func_00161f38;
    } else {
        TaskB* k = func_00102c18(1, 0x186a0, func_00161df0);
        k->mode = mode;
        t -= 1.0f;
        k->t = t + t;
        D_0034c771.v = 1;
    }
}
extern "C" {

void func_001c20e8(u32, HitEv*, ActObj*);
void func_00186d48(ActObj*, HitEv*);
s32 func_0018ca48(u8);
void func_0013de08(ActObj*);
void func_0013de58(ActObj*);
void func_0013dea8(ActObj*);
void func_00186148(ActObj*, HitEv*);
void func_001762f8(ActObj* o, HitEv* e) {
    if ((o->flags & 4) || o->vt->canHit(o)) {
        if (!IsGuardKind(e)) return;
    }
    ActMask* m = &o->mask;
    func_001c20e8((o->mask.a | m->b) & ~m->c, e, o);
    func_00186d48(o, e);
    if (!IsGuardKind(e)) {
        if (o->flags & 4) func_0013dea8(o);
        else switch (func_0018ca48(e->type)) {
        case 3: func_0013de58(o); break;
        case 4: func_0013dea8(o); break;
        case 0: if (e->power > 0) func_0013de08(o); break;
        default: func_0013de08(o); break;
        }
    }
    o->vt->onHit(o, e);
    func_00186148(o, e);
}

Vq func_0016be98(u32);
void func_002bc188(u32, Vq*);
void func_001c7700(void);
void func_001c78e0(void);
void func_001c79a0(Homing* h, u32 target, s32 mode) {
    h->target = target;
    Vq v;
    v = func_0016be98(target);
    h->dir = h->pos - v;
    h->dir.w = Normalize(h->dir);
    switch (mode) {
    case 0:
        h->speed = 40.0f;
        h->step = func_001c7700;
        break;
    case 1:
        h->speed = 80.0f;
        h->step = func_001c78e0;
        break;
    }
    func_002bc188(h->owner[3], &v);
}

extern SaveBig D_01d499b0;
extern SaveBig D_0032bb30;
extern SaveMid D_01d5a97c;
extern SaveMid D_0034f250;
extern SaveMid D_01d5b1a4;
extern SaveMid D_0034fa78;
void func_001ada38(u32);
void func_001ba138(void);
void func_00242908(void);
void func_00168fa8(void);
// Restore the saved copies of the game-state blocks.
void func_001cd388(void) {
    D_0032bb30 = D_01d499b0;
    D_0034f250 = D_01d5a97c;
    D_0034fa78 = D_01d5b1a4;
    func_001ada38(8);
    func_001ba138();
    func_00242908();
    func_00168fa8();
}

s32 func_00190140(u32);
Vq* func_0016c028(u8*);
void func_001902a8(u32, Vq*);
Vq func_0016af58(u32);
void func_001cda88(Lockon* l, u32 obj, u32 tgt) {
    u32* aim = (u32*)&l->aim;
    Vq* opos = &l->opos;
    l->target = func_00190140(tgt) ? tgt : 0;
    aim[3] = 0;
    l->obj = obj;
    l->objId = *(u32*)(obj + 2800);
    QCOPY(opos, func_0016c028((u8*)obj));
    l->t96 = 0;
    l->t100 = 0;
    if (l->target) {
        func_001902a8(l->target, (Vq*)aim);
        Vq v;
        v = l->tpos - *opos;
        v.y = 0;
        Normalize(v);
        l->dir = v;
    } else {
        l->dir = func_0016af58(l->obj);
    }
}

extern u8 D_0032e020[];
s32 func_001a8bf8(u32*, s32);
void func_001a8c60(u32*, s32, s32);
u32 func_001a8c10(u32*, s32);
u8* func_00188fe0(u8*, u32);
void func_001d9630(u8*, u32);
void func_001d94f8(u32 a, u32* other) {
    u32 p = a;
    for (s32 i = 0; i < 4; i++) {
        func_001a8bf8(&p, i);
        for (s32 j = 0; j < 4; j++) {
            if (func_001a8bf8(&p, i) == func_001a8bf8(other, j)) {
                func_001a8c60(&p, i, 18);
                break;
            }
        }
    }
    for (s32 i = 0; i < 4; i++) {
        if (func_001a8bf8(&p, i) == 18) continue;
        u8* e = func_00188fe0(D_0032e020, func_001a8c10(&p, i));
        func_001d9630(e + 20, 8);
        func_001d9630(e + 36, 8);
        func_001d9630(e + 52, 8);
        u16* q = (u16*)(e + 80);
        for (s32 n = 0; n < 80; n++) q[n + 2] &= 0x7fff;
    }
}

extern f32 D_00349e10;
f32 func_00184a90(u8*);
Vq* func_0016c028(u8*);
struct VqI { FI x, y, z, w; } __attribute__((aligned(16)));
// Velocity for a floating object, easing its height towards the ground.
Vq func_001d2a68(u32, u8* o) {
    VqI v;
    QCOPY(&v, o + 2144);
    v.x.i = 0;
    v.z.i = 0;
    f32 z = v.x.f;
    if (v.y.f < z) v.y.f = z;
    f32 h = MAX(z, func_00184a90(o) - func_0016c028(o)->y);
    if (h < 300.0f) {
        v.y.f = (v.y.f - 0.5f) * 0.95f + 0.5f;
    } else {
        v.y.f = MIN(v.y.f + D_00349e10 * 0.2f, 6.0f);
    }
    return *(Vq*)&v * D_00349e10;
}

union XfMatPtr { XfMat* p; f32 f; };
extern XfMatPtr D_01d9e6e8;
extern M4 D_01d9e730;
extern M4 D_01d9e8c0;
void func_002f4000(M4*);
void func_002f3d08(void*, void*, void*);
void func_002f3f40(f32*, f32*, f32);
void func_002f3f28(f32*, f32*, f32*);
void func_00200830(u8* base, u32, XfCtx* c) {
    XfRec* r = (XfRec*)(base + c->offs[1] + 160);
    M4 m;
    func_002f4000(&m);
    m.r[3].x = r->x;
    m.r[3].y = r->y;
    m.r[3].z = r->z;
    func_002f3d08(&m, &D_01d9e730, &m);
    func_002f3f40(D_01d9e6e8.p->m0, D_01d9e6e8.p->r0, r->rx);
    func_002f3f40(D_01d9e6e8.p->m1, D_01d9e6e8.p->r1, r->ry);
    func_002f3f40(D_01d9e6e8.p->m2, D_01d9e6e8.p->r2, r->rz);
    func_002f3f28(D_01d9e6e8.p->m3, D_01d9e6e8.p->r3, &r->rx);
    D_01d9e6e8.p->m3[0] += m.r[3].x;
    D_01d9e6e8.p->m3[1] += m.r[3].y;
    D_01d9e6e8.p->m3[2] += m.r[3].z;
    func_002f3d08(D_01d9e6e8.p->m0, &D_01d9e8c0, D_01d9e6e8.p->m0);
}

extern u32 D_01d9ea9c;
extern u32 D_01d9eab4;
extern u8* D_01d9e6e0;
void func_001f0868(OscIn*, Osc*);
f32 func_002f8b00(f32, f32);
void func_001f08e0(u8* base, OscIn* in, XfCtx2* c) {
    Osc* o = (Osc*)(base + c->offs[2] + 160);
    if (o->on == 0) func_001f0868(in, o);
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0x000000ff0000ff00ULL) return;
    if (in->id == *(u32*)(base + 12)) {
        o->vel += in->a;
        o->acc += in->b;
        o->vel2 += in->c;
        o->acc2 += in->d;
    }
    if (D_01d9eab4) return;
    o->vel += o->acc;
    o->pos += o->vel;
    o->vel2 += o->acc2;
    o->pos2 += o->vel2;
    o->pos = func_002f8b00(o->pos, 32768.0f);
    o->pos2 = func_002f8b00(o->pos2, 32768.0f);
}

union HeapOwnerRef { HeapOwner* p; s32 i; };
extern HeapOwnerRef D_00347f80;
extern u8 D_0035e190[];
extern u8 D_00347f98[];
extern u8 D_00347e60[];
extern u8 D_0035e1f8[];
s32 func_002249b8(void);
void func_0031a838(u8*);
void func_00239700(u8*);
void func_002294c8(ItemPanel*, u32, s32*, u8*);
void func_00229678(ItemPanel*, u32, s32);
void func_0022ad88(s32 n, u32 b) {
    if (n <= 0) return;
    if (func_002249b8() != 5) return;
    s32 cnt = n;
    Heap2* h = D_00347f80.p->heap;
    ItemPanel* o = (ItemPanel*)h->vt->alloc(h, 2900, 0);
    o->f12 = 0;
    o->vt = D_0035e190;
    ItemSlot* s = o->slot;
    for (s32 i = 6; i != -1; i--) {
        s->vt = D_00347f98;
        func_0031a838(s->a);
        s->vt = D_00347e60;
        func_00239700(s->b);
        s++;
    }
    func_002294c8(o, 6, &cnt, D_0035e1f8);
    func_00229678(o, b, cnt);
}

extern u8* D_0035ec90;
extern char* D_0035ec00;
extern char* D_0035ebfc;
extern Cfg84 D_0035ec30;
extern Cfg84 D_0032df74;
extern u8 D_003716c0[];
extern u8 D_003716f8[];
extern u8 D_00371738[];
extern u8 D_00371768[];
extern u8 D_00371798[];
void func_002fde18(void*, s32, u32);
void func_002fdd68(void*, const void*, u32);
void func_002405a8(u8*, s32);
s32 func_00240108(void);
void func_002ff2e8(char*, const char*);
void func_00240450(u8* p, s32 n) {
    if (!p) p = D_0035ec90;
    func_002fde18(p, 0, 964);
    func_002fdd68(p, D_003716c0, 4);
    *(u16*)(p + 6) = 32;
    *(u32*)(p + 12) = 96;
    func_002fdd68(p + 16, D_003716f8, 64);
    func_002fdd68(p + 80, D_00371738, 48);
    func_002fdd68(p + 128, D_00371768, 48);
    func_002fdd68(p + 176, D_00371798, 16);
    func_002405a8(p + 192, n + 1);
    char* s = func_00240108() ? D_0035ec00 : D_0035ebfc;
    func_002ff2e8((char*)p + 260, s);
    func_002ff2e8((char*)p + 324, s);
    func_002ff2e8((char*)p + 388, s);
    D_0035ec30 = D_0032df74;
}

extern SaveSel* D_0035ec94;
extern SaveList* D_0035ec98;
extern DirEnt* D_0035ec9c;
extern char D_003716e0[];
extern char D_003716e8[];
void func_00240360(s32);
s32 func_002349c8(s32, u32);
void func_002fde18(void*, s32, u32);
s32 func_002ff1a4(const char*, const char*);
void func_002ff2e8(char*, const char*);
// Build the list of save files from the directory listing (skipping "." and "..").
s32 func_00241008(void) {
    DirEnt* e = D_0035ec9c;
    func_00240360(D_0035ec94->b);
    s32 n = func_002349c8(D_0035ec94->a, 0);
    func_002fde18(D_0035ec98, 0, 4);
    D_0035ec98->n = n;
    for (s32 i = 0; i < n; i++, e++) {
        if (func_002ff1a4(e->name, D_003716e0) && func_002ff1a4(e->name, D_003716e8)) {
            func_002ff2e8(D_0035ec98->rec[i].name, e->name);
            if (e->attr & 0x20) D_0035ec98->rec[i].type = 1;
            else D_0035ec98->rec[i].type = 2;
            D_0035ec98->rec[i].size = e->size;
        }
    }
    return n;
}

extern MenuParts* D_0035f0f4;
extern u32 D_0035f01c;
u8* func_00256b68(u32);
s32 func_00139d78(void*);
s32 func_0028acc8(u32);
// Non-zero while any of the menu's animated parts is still busy.
s32 func_0026cda0(void) {
    s32 i;
    s32 busy = func_00139d78(func_00256b68(1));
    if (busy) return busy;
    busy = func_00139d78(D_0035f0f4) != 0;
    if (busy) return busy;
    for (i = 0; i < 4; i++) {
        if (func_00139d78(&D_0035f0f4->a[i + 1])) busy = 1;
    }
    if (busy) return busy;
    for (i = 0; i < 4; i++) {
        if (func_00139d78(&D_0035f0f4->b[i])) {
            busy = 1;
            break;
        }
    }
    if (busy) return busy;
    if (D_0035f01c) busy = func_0028acc8(D_0035f01c) != 0;
    return busy;
}

extern u32 D_0035f010;
extern u32 D_0035f01c;
extern ColSlot* D_0035f12c;
s32 func_00287bc0(void);
ColEnt* func_00273180(u32, s32);
u32 func_002570a0(u32);
u8* func_00281180(u32, u32);
s32 func_0028b040(u32);
u8* func_001145b0(u32);
void func_00273cb8(s32 sel) {
    s32 k = func_00287bc0();
    ColEnt* tbl = func_00273180(4, -1);
    u32 alt = (u32)(k - 26) < 2;
    u32 off = *(u32*)(func_00281180(D_0035f010, func_002570a0(25)) + 580);
    s32 idx;
    if (alt) idx = func_0028b040(D_0035f01c);
    else idx = func_002570a0(26);
    u8* r = func_001145b0(D_0035f12c[idx].id);
    if (sel < 0) {
        for (s32 j = 0; j < 3; j++) {
            if (D_0035f12c[idx].col == tbl[j].col) {
                sel = j;
                break;
            }
        }
        sel++;
        if (sel >= 3) sel = 0;
    }
    r[off + 245] = tbl[sel].col;
    D_0035f12c[idx].col = tbl[sel].col;
}

extern u32 D_0035f010;
extern u32 D_0035f01c;
extern ColTab2* D_0035f230;
u32 func_002570a0(u32);
s32 func_0028b040(u32);
void func_0027c118(u32, u32);
s32 func_0027af58(void);
void func_0027aed8(u32, s32*, s32*);
s32 func_0027c3b8(u32);
ColEnt* func_00273180(u32, s32);
u8* func_001145b0(u32);
u8* func_00281180(u32, u32);
void func_0027c1c0(void) {
    u32 x = func_002570a0(16);
    s32 b = func_0028b040(D_0035f01c);
    func_0027c118(x, b != 0);
    u32 y = func_002570a0(15);
    u32 z = func_0027af58();
    s32 o1, o0;
    func_0027aed8(y, &o0, &o1);
    s8 lock = D_0035f230->s[x].lock;
    if (o0 != 0) return;
    if (o1 == 0) return;
    if (z != 0) return;
    if (lock != 0) return;
    if (func_0027c3b8(x)) return;
    z = (u32)func_00273180(4, -1);
    y = (u32)func_001145b0(D_0035f230->s[x].id);
    x = func_0028b040(D_0035f01c);
    if (!x) return;
    u32 off = *(u32*)(func_00281180(D_0035f010, o1) + 580);
    ((u8*)y)[off + 245] = ((ColEnt*)z)[x - 1].col;
    func_002570a0(16);
}

u8* func_001a8110(u8*);
// Assign each entry its table order (+1000 unless type 18), then sort by it.
void func_00282d70(SortList* l) {
    u8* v = 0;
    s32 i = 0;
    for (;;) {
        v = func_001a8110(v);
        if (!v) break;
        for (s32 j = 0; j < l->n; j++) {
            if (*(u16*)v == l->e[j].id) {
                l->e[j].key = i;
                if (v[2] != 18) l->e[j].key = i + 1000;
            }
        }
        i++;
    }
    for (i = 0; i < l->n; i++) {
        for (s32 j = i + 1; j < l->n; j++) {
            if (l->e[j].key < l->e[i].key) {
                SortEnt t = l->e[i];
                l->e[i] = l->e[j];
                l->e[j] = t;
            }
        }
    }
}

extern u32 D_0035f318;
extern u32 D_0035f2ec;
extern void* D_0035f31c;
extern u8 D_0035f314;
extern u32 D_0035f2e8;
extern u8 D_0035f320;
u32 func_00103570(void);
void func_00139e00(u32, u8);
void func_0023edb0(u32);
void func_00288b18(u32);
void func_00236d60(void);
void func_00287b30(void);
void func_00287d08(void);
void func_0023ed00(u32);
void func_0023d4f8(void*, u32);
void func_00287c20(void);
void func_0028c3f0(u32);
void func_00287ed8(u32);
void func_00287910(u32 a, u32 b, u8 c) {
    func_00139e00(func_00103570(), c);
    func_0023edb0(func_00103570());
    func_00288b18(func_00103570());
    func_00236d60();
    func_00287b30();
    func_00287d08();
    func_0023ed00(7);
    D_0035f318 = b;
    D_0035f2ec = a;
    if (b) {
        Heap2* h = D_00347f80.p->heap;
        void* m = h->vt->alloc(h, 5360, 0);
        func_0023d4f8(m, D_0035f318);
        D_0035f31c = m;
    }
    D_0035f314 = 0;
    func_00287c20();
    func_0028c3f0(func_00103570());
    D_0035f2e8 = 0;
    D_0035f320 = 0;
    func_00287ed8(func_00103570());
}

extern u8 D_0035f4f0;
union SeReqRef { SeReq* p; s16 h; };
extern SeReqRef D_0035f4e8;
TaskInfo* func_00103eb0(void);
s32 func_00102a38(u32, void (*)(void));
void func_002933b8(void);
u32* func_001a8bd0(s32);
u32 func_001a8c10(u32*, s32);
void func_00293350(s16, s16, s16);
void func_00293520(void) {
    if (D_0035f4f0) return;
    if (func_00102a38(func_00103eb0()->name, func_002933b8)) return;
    s32 id = func_001a8c10(func_001a8bd0(-1), 3);
    s32 found = -1;
    for (s32 pass = 0; pass < 2; pass++) {
        for (s32 i = 0; i < 8; i++) {
            if (D_0035f4e8.p[i].id == id) {
                D_0035f4e8.p[i].id = -1;
                D_0035f4e8.p[i].pass = -1;
                D_0035f4e8.p[i].arg = -1;
            } else if (D_0035f4e8.p[i].id >= 0 && D_0035f4e8.p[i].pass == pass) {
                found = i;
                break;
            }
        }
        if (found >= 0) break;
    }
    if (found >= 0) {
        func_00293350(D_0035f4e8.p[found].id, D_0035f4e8.p[found].pass, D_0035f4e8.p[found].arg);
        D_0035f4e8.p[found].id = -1;
        D_0035f4e8.p[found].pass = -1;
        D_0035f4e8.p[found].arg = -1;
    }
}

extern u32 D_0035f200;
s32 func_00289380(u32);
s32 func_00287cd0(void);
void func_00296b08(void);
s32 func_00289310(u32);
s32 func_00276398(void);
void func_00276220(u32, u32);
void func_00287c90(u32);
u32 func_00287df0(s32, s32, u32, u32, u32);
s32 func_00242848(u32);
void func_00287da0(void);
void func_002968d8(void) {
    s32 sel = func_00289380(D_0035f200);
    s32 busy = func_00287cd0();
    func_00296b08();
    if (sel != -1 || func_00289310(D_0035f200)) {
        if (!func_00276398()) func_00276220(0, 2);
    }
    if (!busy && func_00276398()) func_00287c90(1);
    if (func_00242848(func_00287df0(sel, func_00289310(D_0035f200), 1, 0, 1))) return;
    switch (sel) {
    case -4:
    case -2:
        func_00287da0();
        break;
    case -1:
        break;
    }
}

extern PickCur* D_0035f5d4;
u8* func_002766d0(void);
s32 func_0023aa98(u8*);
void func_00138c90(u8*, s32*, s32*);
// Pick the icon under the cursor.
void func_002a16b8(void) {
    u8* w = func_002766d0();
    s16 x = D_0035f5d4->x;
    s16 y = D_0035f5d4->y;
    s32 r = func_0023aa98(w + 4272) / 2;
    s32 i;
    for (i = 0; i < D_0035f5d4->n; i++) {
        s32 py, px;
        func_00138c90(w + 4248 + i * 408, &px, &py);
        if (x < px - r || px + r < x) continue;
        if (y < py - r || py + r < y) continue;
        D_0035f5d4->sel = i;
        break;
    }
    if (i >= D_0035f5d4->n) D_0035f5d4->sel = -1;
}

extern u8* D_0035f634;
extern AnmId3 D_00374cd8[];
u32* func_002b23e0(s32);
s32 func_00139d78(void*);
s32 func_001396c0(u8*);
void func_00139570(u8*);
void func_00138c10(u8*, s16);
void func_0028dcc0(u8*, u8*);
void func_002b2f28(s32 idx) {
    u32* st = func_002b23e0(-1);
    u8* p = D_0035f634 + idx * 408 + 19992;
    func_00139d78(p);
    if (!func_001396c0(p)) func_00139570(p);
    p = D_0035f634 + 20808;
    if (!func_001396c0(p)) func_00139570(p);
    if (idx == 0) {
        p = D_0035f634 + 20400;
        if (!func_001396c0(p)) func_00139570(p);
        func_00139570(D_0035f634 + 19584);
        return;
    }
    p = D_0035f634 + 19992;
    func_00138c10(p, D_00374cd8[(st[0] >> 27) & 1].a);
    func_0028dcc0(D_0035f634 + 19584, p);
}

extern CamObj* D_00361f60;
u32 func_00106a18(u32);
M4* func_00106ad0(u32);
u8* func_00106a60(u32);
void func_00146680(u8*, M4*);
void func_002cec88(MdlRef* r) {
    u8* mdl = r->mdl + 16;
    M4 m;
    MCOPY(&m, func_00106ad0(func_00106a18(1)));
    MMulTo(&m, &m, (M4*)(func_00106a60(1) + 16));
    func_00146680(mdl, &m);
    if (D_00361f60 && D_00361f60->active) D_00361f60->drawn = 1;
}

extern u32 D_003637b0[8];
extern u32 D_003638d0;
u8 func_0016f7d0(u32, u32);
u8* func_0016e920(u32);
s32 func_00182690(f32);
u32 func_0016a020(u32);
u64 func_00312db8(u64, u64);
}
// Pick a random member among the eligible party slots.
u32 ctarget_002ed8e0(u32 a, u32, u32, u32) {
    u32 cand[12];
    u32* out = cand;
    s32 n = 0;
    u32* src = D_003637b0;
    for (s32 i = 7; i >= 0; i--, src++) {
        if (func_0016f7d0(*src, 0) & 1) continue;
        if (func_00182690(func_0016e920(*src)[84])) {
            *out++ = *src;
            n++;
        }
    }
    if (n > 0) {
        D_003638d0 *= 0x10dcd;
        u32 r = D_003638d0;
        return cand[(s32)func_00312db8(r, func_00312db8((u64)(u32)(n - 1) + 0x100000000ULL, (u32)n))];
    }
    return func_0016a020(a);
}
extern "C" {

extern const s32 D_00377d00[3];
Bigint* func_00303c48(Reent*, Bigint*, s32, s32);
Bigint* func_00303fc0(Reent*, s32);
Bigint* func_00303ff8(Reent*, Bigint*, Bigint*);
void func_00303c18(Reent*, Bigint*);
// newlib mprec: __pow5mult (b * 5^k).
Bigint* func_00304200(Reent* ptr, Bigint* b, s32 k) {
    Bigint *b1, *p5, *p51;
    s32 i;
    if ((i = k & 3) != 0)
        b = func_00303c48(ptr, b, D_00377d00[i - 1], 0);
    if (!(k >>= 2))
        return b;
    if (!(p5 = ptr->p5s)) {
        p5 = ptr->p5s = func_00303fc0(ptr, 625);
        p5->next = 0;
    }
    for (;;) {
        if (k % 2) {
            b1 = func_00303ff8(ptr, b, p5);
            func_00303c18(ptr, b);
            b = b1;
        }
        if (!(k >>= 1))
            break;
        if (!(p51 = p5->next)) {
            p51 = p5->next = func_00303ff8(ptr, p5, p5);
            p51->next = 0;
        }
        p5 = p51;
    }
    return b;
}

}
