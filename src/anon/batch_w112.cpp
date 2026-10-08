#include "../common/types.h"

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
extern "C" {
Vec4* func_0016c028(void*);
f32 func_002f8870(f32);
}

// ---- 001011e0
namespace n001011e0 {
struct EhObj { u32 pc_begin, tbase, dbase, u; u64 sorted : 1, from_array : 1, mixed : 1, encoding : 8, count : 21; };
struct EhFde { u32 length; s32 cie; u8 pc_begin[8]; };
extern "C" {
u32 func_00100920(u8, EhObj*);
s32 func_001009a0(void*);
u8* func_001004c0(u8, u32, u8*, u32*);
u32 func_001003c8(u8);
// linear_search_fdes: walks an FDE list for the entry covering pc.
EhFde* func_001011e0(EhObj* ob, EhFde* fde, u32 pc) {
    void* last_cie = 0;
    s32 encoding = ob->encoding;
    u32 base = func_00100920(ob->encoding, ob);
    for (; fde->length != 0; fde = (EhFde*)((u8*)fde + fde->length + 4)) {
        u32 pc_begin, pc_range;
        if (fde->cie == 0) continue;
        if ((s32)ob->mixed) {
            void* cie = (u8*)&fde->cie - fde->cie;
            if (cie != last_cie) {
                last_cie = cie;
                encoding = func_001009a0(cie);
                base = func_00100920(encoding, ob);
            }
        }
        if (encoding == 0) {
            pc_begin = ((u32*)fde->pc_begin)[0];
            pc_range = ((u32*)fde->pc_begin)[1];
            if (pc_begin == 0) continue;
        } else {
            u32 mask;
            u8* p = func_001004c0(encoding, base, fde->pc_begin, &pc_begin);
            func_001004c0(encoding & 0x0F, 0, p, &pc_range);
            mask = func_001003c8(encoding);
            if (mask < 4) mask = (1L << (mask << 3)) - 1;
            else mask = -1;
            if ((pc_begin & mask) == 0) continue;
        }
        if (pc - pc_begin < pc_range) return fde;
    }
    return 0;
}
}
}

// ---- 00110b00
namespace n00110b00 {
struct RayQ { Vec4 a, b, c, hit; u8 pad[48]; u64 on : 1, rest : 33, hitflag : 1, rest2 : 29; u8 pad2[24]; };
extern "C" {
extern u8 D_003a9250[];
extern u8* D_00341708;
s32 w146730(void*, u32) asm("_Z16wtarget_00146730jjjj");
void func_00319e90(RayQ*, void*);
void func_00143928(RayQ*);
}
static inline void vsub(Vec4* d, const Vec4* a, const Vec4* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 vdot(const Vec4* a, const Vec4* b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(a), "r"(b) : "$8");
    return r;
}
static inline void QvCopy(Vec4* d, Vec4* s) { if (d != s) QCOPY(d, s); }
extern "C" {
// Checks whether pos is in front of / reachable from the object with a ground ray test.
s32 func_00110b00(u8* o, Vec4* pos, u32 a2) {
    s32 r = w146730(D_003a9250, a2);
    Vec4 d;
    f32 k;
    if (r == 1) return 0;
    if (r != 0) return 0;
    if (*(u32*)(D_00341708 + 352) & 0x4000) return 0;
    vsub(&d, pos, func_0016c028(D_00341708));
    k = *(f32*)(o + 2944);
    if (0.0f < d.y * k) return 0;
    d.y = 0.0f;
    if (func_002f8870(k) < 1000.0f) {
        if (0.0f < vdot((Vec4*)(o + 2976), &d)) return 0;
    } else {
        if (-0.5f < vdot((Vec4*)(o + 2976), &d)) return 0;
    }
    {
        RayQ ray;
        func_00319e90(&ray, o + 1424);
        QvCopy(&ray.a, pos);
        asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(&ray.b) : "memory");
        ray.on = 0;
        func_00143928(&ray);
        if (ray.hitflag) return 0;
        return 1;
    }
}
}
}

// ---- 0011e450
namespace n0011e450 {
struct Node { void** vt; };
struct Alloc { void** vt; };
struct Owner { u8 pad[16]; Alloc* alloc; u8 pad2[36]; Node* list; };
typedef Node* (*AllocFn)(Alloc*, u32, u32);
typedef void (*LoadFn)(Node*, void*);
extern "C" {
void* func_00132350(Node*);
void* func_00132180(void*, u32);
void* func_00132130(void*);
void func_001324b8(Node*, void*);
void func_00133198(Node*, void*);
void func_00132358(Node*, Node*);
// Builds TEXA (texture) and UVSC (uv scroll) nodes from a chunk list and appends them to the owner's list.
void func_0011e450(Owner* o, void* c) {
    Node* tail;
    void* ch;
    if (!c) return;
    tail = o->list;
    while (tail && func_00132350(tail)) tail = (Node*)func_00132350(tail);
    for (ch = func_00132180(c, 0x41584554); ch; ch = func_00132180(func_00132130(ch), 0x41584554)) {
        Node* n = ((AllocFn)o->alloc->vt[0])(o->alloc, 656, 0);
        func_001324b8(n, c);
        ((LoadFn)n->vt[2])(n, ch);
        if (!tail) o->list = n;
        else func_00132358(tail, n);
        tail = n;
    }
    for (ch = func_00132180(c, 0x43535655); ch; ch = func_00132180(func_00132130(ch), 0x43535655)) {
        Node* n = ((AllocFn)o->alloc->vt[0])(o->alloc, 44, 0);
        func_00133198(n, c);
        ((LoadFn)n->vt[2])(n, ch);
        if (!tail) o->list = n;
        else func_00132358(tail, n);
        tail = n;
    }
}
}
}

// ---- 00142940
namespace n00142940 {
struct Mtx { f32 m[16]; } __attribute__((aligned(16)));
static inline void MtxCopy(Mtx* d, const Mtx* s) {
    if (d != s)
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
// In-place inverse of an affine matrix (VU0).
static inline void MtxInverse(Mtx* m) {
    asm volatile(
        "lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
        "vopmula.xyz ACC, $vf2, $vf3\n\tvopmsub.xyz $vf5, $vf3, $vf2\n\t"
        "vopmula.xyz ACC, $vf3, $vf1\n\tvopmsub.xyz $vf6, $vf1, $vf3\n\t"
        "vopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf7, $vf2, $vf1\n\t"
        "vmul.xyz $vf8, $vf1, $vf5\n\tvmul.xyz $vf1, $vf4, $vf5\n\tvmul.xyz $vf2, $vf4, $vf6\n\tvmul.xyz $vf3, $vf4, $vf7\n\t"
        "vaddy.x $vf8, $vf8, $vf8y\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddx.y $vf2, $vf2, $vf2x\n\tvaddx.z $vf3, $vf3, $vf3x\n\t"
        "vaddz.x $vf8, $vf8, $vf8z\n\tvaddz.x $vf4, $vf1, $vf1z\n\tvaddz.y $vf4, $vf2, $vf2z\n\tvaddy.z $vf4, $vf3, $vf3y\n\t"
        "vdiv Q, $vf0w, $vf8x\n\t"
        "qmfc2 $8, $vf5\n\tqmfc2 $9, $vf6\n\tqmfc2 $10, $vf7\n\tqmfc2 $11, $vf0\n\t"
        "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
        "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
        "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
        "vsub.xyz $vf4, $vf0, $vf4\n\tvwaitq\n\t"
        "vmulq.xyzw $vf1, $vf1, Q\n\tvmulq.xyzw $vf2, $vf2, Q\n\tvmulq.xyzw $vf3, $vf3, Q\n\tvmulq.xyz $vf4, $vf4, Q\n\t"
        "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\tsqc2 $vf4, 48(%0)"
        : : "r"(m) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}
struct Xf { u8 pad[80]; Mtx world; Mtx inv; u8 pad3[1]; u8 identity; };
extern "C" {
// Sets the world matrix (flagging identity) and its inverse; m is inverted in place.
void func_00142940(Xf* o, Mtx* m) {
    o->identity = 0;
    if (m->m[0] == 1.0f && m->m[1] == 0.0f && m->m[2] == 0.0f && m->m[3] == 0.0f &&
        m->m[4] == 0.0f && m->m[5] == 1.0f && m->m[6] == 0.0f && m->m[7] == 0.0f &&
        m->m[8] == 0.0f && m->m[9] == 0.0f && m->m[10] == 1.0f && m->m[11] == 0.0f &&
        m->m[12] == 0.0f && m->m[13] == 0.0f && m->m[14] == 0.0f && m->m[15] == 1.0f)
        o->identity = 1;
    MtxCopy(&o->world, m);
    MtxInverse(m);
    MtxCopy(&o->inv, m);
}
}
}

// ---- 00147aa8
namespace n00147aa8 {
struct Ob { u8 pad[56]; u32 f56; u8 pad1[4]; u8 f64[184]; u32 flags; u8 pad2[4]; u32 f256; u8 pad3[10]; u8 state[4]; };
struct Mgr { u8 pad[3152]; s32 cnt[(21356 - 3152) / 4]; s32 idx; };
extern "C" {
void func_001349a8(u32, u8*, u32);
s32 func_00147240(Mgr*, Ob*, f32);
void func_00147ca0(Mgr*, Ob*, f32);
void func_00147d80(Mgr*, Ob*, f32);
void func_00148470(Mgr*, Ob*);
}
extern "C" {
// Per-frame update of an entry: refreshes it, then queues it (bounded at 16 per slot) by state.
void func_00147aa8(Mgr* m, Ob* o, f32 t) {
    s32 had = 0;
    if (o->flags & 0x4000) {
        o->flags &= ~0x4000;
        had = 1;
    }
    if (o->f56 && o->f256) func_001349a8(o->f56, o->f64, o->f256);
    if (func_00147240(m, o, t)) {
        func_00147ca0(m, o, t);
        o->state[m->idx] = 1;
        return;
    }
    if (o->state[m->idx] == 1) func_00147ca0(m, o, t);
    if (*(u8*)((u8*)o + 235) != 0 && *(s8*)((u8*)o + 235) >= 0 && m->cnt[m->idx] < 16 && (o->flags & 0x10)) {
        if (had == 1) return;
        func_00147d80(m, o, t);
        m->cnt[m->idx]++;
        return;
    }
    if (o->state[m->idx] == 2 && m->cnt[m->idx] < 16) {
        func_00147d80(m, o, t);
        m->cnt[m->idx]++;
    }
    func_00148470(m, o);
}
}
}

// ---- 00157ae0
namespace n00157ae0 {
struct Cfg { u8 pad[384]; u32 f384, f388; };
struct Wk { u8 pad[1164]; Cfg* cfg; };
extern "C" {
s32 func_001a1de0(Cfg*);
f32 func_001a1e00(Cfg*);
s32 func_00158250(u8*);
s32 func_00155f40(u8*);
void func_00138c10(u8*, s32);
void func_001565a8(u8*);
void func_00156540(u8*);
void func_00155ab0(u8*, u32, u32);
void func_00155b58(u8*, u32, f32);
void func_001395a8(u8*);
}
extern "C" {
// Picks one of two motion sets (by mode) and applies both blend slots.
void func_00157ae0(u8* o) {
    if (func_001a1de0((*(Wk**)(o + 52))->cfg) == 0) {
        Cfg* c;
        u32 b;
        if (func_00158250(o)) {
            func_00138c10(o + 11648, func_00155f40(o));
            u8* s = o + 10000;
            func_00138c10(s, 116);
            func_00138c10(o + 10412, 119);
            func_00138c10(o + 10824, 115);
            func_00138c10(o + 11236, 120);
            *(u32*)(s + 392) = 117;
            func_001565a8(o);
        }
        c = (*(Wk**)(o + 52))->cfg;
        u32 a = c->f388;
        b = c->f384;
        func_00155ab0(o, a, 9);
        func_00155ab0(o, b, 10);
    } else {
        f32 v;
        if (func_00158250(o)) {
            func_00138c10(o + 11648, func_00155f40(o));
            u8* s = o + 10000;
            func_00138c10(s, 110);
            func_00138c10(o + 10412, 113);
            func_00138c10(o + 10824, 109);
            func_00138c10(o + 11236, 114);
            *(u32*)(s + 392) = 111;
            func_00156540(o);
        } else if (func_00155f40(o) == 26) func_001395a8(o + 1324);
        v = func_001a1e00((*(Wk**)(o + 52))->cfg);
        func_00155b58(o, 9, 1.0f);
        func_00155b58(o, 10, v);
    }
}
}
}

// ---- 00179fd0
namespace n00179fd0 {
extern "C" {
u32 func_00167f18(u32);
void* func_001050d8(u32);
void func_002d49c0(void*, u32*, u32, u32, f32);
void func_002d9730(void*, u32*, u32, u32, f32);
void func_002dd700(void*, u32*, u32, u32, f32);
void func_001d1540(void*, u32*, u32, u32, f32);
void func_001cf698(void*, u32*, u32, u32, f32);
void func_001ced68(void*, u32*, u32, u32, f32);
void func_001d0980(void*, u32*, u32, u32, u32, f32);
}
extern "C" {
// Creates the object class matching the spawn entry's type id.
void* func_00179fd0(u32* info, u32 a1, u32 a2, f32 t) {
    u32 m = func_00167f18(0);
    void* o;
    switch (*info) {
    case 859:
        o = func_001050d8(3136);
        func_002d49c0(o, info, m, a2, t);
        break;
    case 860:
        o = func_001050d8(3360);
        func_002d9730(o, info, m, a2, t);
        break;
    case 861:
        o = func_001050d8(3088);
        func_002dd700(o, info, m, a2, t);
        break;
    case 958:
        o = func_001050d8(2928);
        func_001d1540(o, info, m, a2, t);
        break;
    case 968:
        o = func_001050d8(2992);
        func_001cf698(o, info, m, a2, t);
        break;
    case 1525:
        o = func_001050d8(2944);
        func_001ced68(o, info, m, a2, t);
        break;
    default:
        o = func_001050d8(2944);
        func_001d0980(o, info, a1, m, a2, t);
        break;
    }
    return o;
}
}
}

// ---- 001975a0
namespace n001975a0 {
struct Cfg { u16 h0; u16 b0 : 1, b1 : 1, b2 : 1, b3 : 1, b4 : 1, rest : 11; };
struct Obj { u32 flags; u8 pad[8]; u8 sub[48]; Cfg* cfg; };
struct St { u8 pad[244]; u8 b244; u8 pad2[7]; s32 f252; };
extern "C" {
extern u8 D_00350379;
extern u8 D_0032b9dd;
extern u32 D_0032b9e0;
void func_0014ce60(void);
void func_00194980(void);
s32 func_0019f060(u8*);
void func_0019f070(u8*, u32);
u32 func_0014abe8(void);
u32 func_0014abf8(void);
void func_0014aa80(u32, u32, u32);
void func_00170320(s32);
void func_00197780(void);
void func_00197cc0(void);
s32 func_00242ea8(void);
s32 func_00242ee8(void);
St* func_0014aba8(void);
u8* func_001058e8(void);
void func_0014a138(u8);
}
static inline bool B4(Cfg* c) { return c->b4; }
static inline bool B2(Cfg* c) { return c->b2; }
static inline u8 U0(Cfg* c) { return c->b0; }
extern "C" {
// Per-frame field update: runs effects/sounds per config bits, then hands off control.
void func_001975a0(Obj* o) {
    func_0014ce60();
    func_00194980();
    if (!func_0019f060(o->sub)) {
        if (B4(o->cfg)) {
            func_0014aa80(func_0014abe8(), 6, 0);
            func_0014aa80(func_0014abf8(), 6, 0);
        }
        if (U0(o->cfg)) func_00170320(-200);
        if (!(o->flags & 0x20)) func_00197780();
        if (!B2(o->cfg)) func_00197cc0();
    }
    if (func_00242ea8() && ((o->flags & 0x10) || (!func_00242ee8() && D_00350379 == 0))) {
        u8 v = 0;
        if ((func_0014aba8()->f252 ^ 4) == 0) {
            v = func_0014aba8()->b244;
            if (v == 1) D_0032b9dd = v;
        }
        D_0032b9e0 = func_001058e8()[12];
        func_0014a138(v);
        return;
    }
    func_0019f070(o->sub, 0x80000000);
}
}
}

// ---- 002267a0
namespace n002267a0 {
extern "C" {
void func_002255f0(void);
void func_00106450(void*);
void func_00105110(void*);
void func_001ddd88(void*);
void func_00170c00(void*);
}
struct E52 {
    u8 a[16];
    u8 b[36];
    ~E52() { func_001ddd88(b); }
    static void operator delete[](void*) asm("func_00105110");
};
struct E64 {
    u8 d[64];
    ~E64() {}
    static void operator delete[](void*) asm("func_00105110");
} __attribute__((aligned(16)));
struct E112 {
    u8 d[112];
    ~E112() {}
    static void operator delete[](void*) asm("func_00106450");
} __attribute__((aligned(16)));
extern "C" {
extern void* D_0035dce0;
extern void* D_0035dce4;
extern void* D_0035dce8;
extern void* D_0035dcec;
extern void* D_0035dcf0;
extern E52* D_0035dcf4;
extern E64* D_0035dcf8;
extern void* D_0035dcfc;
extern E112* D_0035dd00;
extern void* D_0035db14;
}
extern "C" {
// Frees all of this module's buffers.
void func_002267a0(void) {
    func_002255f0();
    if (D_0035dce0) { func_00106450(D_0035dce0); D_0035dce0 = 0; }
    if (D_0035dce4) { func_00106450(D_0035dce4); D_0035dce4 = 0; }
    if (D_0035dce8) { func_00106450(D_0035dce8); D_0035dce8 = 0; }
    if (D_0035dcec) { func_00106450(D_0035dcec); D_0035dcec = 0; }
    if (D_0035dcf4) { delete[] D_0035dcf4; D_0035dcf4 = 0; }
    if (D_0035dcf0) { func_00105110(D_0035dcf0); D_0035dcf0 = 0; }
    if (D_0035dcf8) { delete[] D_0035dcf8; D_0035dcf8 = 0; }
    if (D_0035dcfc) { func_00105110(D_0035dcfc); D_0035dcfc = 0; }
    if (D_0035dd00) { delete[] D_0035dd00; D_0035dd00 = 0; }
    if (D_0035db14) { func_00170c00(D_0035db14); D_0035db14 = 0; }
}
}
}

// ---- 002a99c8
namespace n002a99c8 {
struct LRec { u16 id; u16 val; u16 pad; u16 flags; u16 h8; u16 h10; u16 h12; u16 h14; };
struct Info { u8 type; u8 pad[3]; u32 value; };
extern "C" {
s32 func_00181500(u32);
s32 func_001a6d08(u32);
Info* func_001d56c8(u32);
s32 func_00276c18(void);
void func_0014ca80(u32, s32*, s32*, s32*, s32*);
}
extern "C" {
// Evaluates an entry's unlock condition: 0 = locked, 1 = available, 2 = cleared, 3 = forced.
s32 func_002a99c8(LRec* r) {
    s32 st = 0;
    if (r->flags & 1) {
        if (func_00181500(r->h8)) st = 1;
    } else st = func_001a6d08(r->h8) != 0;
    if (st) {
        if (r->flags & 4) st = func_001d56c8(r->h10)->type != 0;
    }
    if (!st) return func_00276c18() ? 3 : st;
    {
        {
            u16 f = r->flags;
            if (f & 0x10) {
                if (func_00181500(r->h14)) st = 2;
            } else if (f & 0x20) {
                if (func_001a6d08(r->h14)) st = 2;
            } else {
                Info* x = func_001d56c8(r->h10);
                if (r->flags & 0x1000) {
                    if (x->type) st = 2;
                } else if (r->flags & 0x2000) {
                    if (x->type >= 2) st = 2;
                } else if (x->type >= 2) {
                    u32 v;
                    if (x->type != 4) v = x->value;
                    else {
                        s32 h, m, s, fr;
                        func_0014ca80(x->value, &h, &m, &s, &fr);
                        v = h * 3600 + m * 60 + s;
                        if (fr != 0) v++;
                    }
                    if (r->flags & 0x100) {
                        if (!(r->h12 < v)) st = 2;
                    } else if (r->flags & 0x200) {
                        if (!(v < r->h12)) st = 2;
                    }
                }
            }
        }
    }
    return st;
}
}
}

// ---- 002ba3e8
namespace n002ba3e8 {
extern "C" {
extern u8 D_01e2a410[];
s32 func_002ba620(void);
s32 func_002bcbf0(u8*, u32, u32, s32*, s32*);
s32 func_002bca78(u8*, u32, u32, s32*, s32*);
s32 func_002bcb60(u8*, s32, u32, u32, s32*, s32*);
void func_002baf48(s32, u32, u32, u32, void (*)(u32), u32);
void func_002bce10(u8*, s32);
}
extern "C" {
// Issues a request of the given kind, then registers the transfer(s) and callback on success.
s32 func_002ba3e8(s32 cmd, u32 a, u32 b, u32 c, u32 d, s32* out, void (*cb)(u32), u32 arg) {
    s32 ok = 1;
    s32 res;
    *out = -1;
    res = -1;
    switch (cmd) {
    case 2:
    case 3:
        break;
    case 20:
        func_002bcbf0(D_01e2a410, a, c, out, &res);
        break;
    case 30:
        if (func_002ba620()) ok = 0;
        else if (!func_002bca78(D_01e2a410, a, c, out, &res)) ok = 0;
        break;
    default:
        ok = 0;
        if (!func_002ba620()) ok = func_002bcb60(D_01e2a410, cmd, a, c, out, &res) != 0;
        break;
    }
    if (res < 0 || !ok) {
        if (cb) cb(arg);
        return res;
    }
    if (c) {
        func_002baf48(*out, 0, a, b, 0, 0);
        func_002baf48(*out, 1, c, d, cb, arg);
    } else func_002baf48(*out, 0, a, b, cb, arg);
    func_002bce10(D_01e2a410, *out);
    return res;
}
}
}

// ---- 001d03a0
namespace n001d03a0 {
struct Iter { u8 d[32]; };
struct Lv { u8 pad[433]; u8 cur; u8 max; };
struct Cfg2 { u8 pad[212]; f32 interval; };
struct Ch {
    u8 pad[320]; u8 mot[844]; Lv* lv; u8 pad2[1716]; u32 f2884; u8 pad3[32]; f32 timer; f32 tick; u8 flag; u8 pad4[3]; u8 eff[4];
};
extern "C" {
extern f32 D_00349e10;
extern f32 D_0036e3bc;
extern Cfg2* D_00352130;
void func_00178758(Ch*);
s32 func_00180618(u8*);
void func_001a1aa0(Lv*, u32);
void func_0017f488(u8*, u32, f32, f32);
void func_0017f5e0(u8*, u32, u32, f32, f32);
void func_00190128(Iter*);
void func_001d0558(Ch*);
void func_001d2648(u8*, u32, f32);
void func_001d2690(u8*, u32, f32);
u32 func_001d14a0(void);
void func_00190878(Iter*, u32, u32);
void func_001bd418(u32, u32, u32, Iter*, u32, u32);
s32 func_00197920(void);
void func_001d2750(u8*);
}
static inline bool IsFull(Lv* l) { return l->cur >= l->max; }
extern "C" {
// Character tick: counts down timers, then reports level-up or normal status for this frame.
void func_001d03a0(Ch* o) {
    Iter it;
    func_00178758(o);
    if (0.0f < o->timer) {
        if (func_00180618(o->mot)) {
            if ((o->tick -= D_00349e10) <= 0.0f) {
                func_001a1aa0(o->lv, 1);
                o->tick += D_00352130->interval;
            }
        }
        if ((o->timer -= D_00349e10) <= 0.0f) {
            o->timer = 0.0f;
            func_0017f488(o->mot, 5, 0.0f, 0.0f);
            func_0017f5e0(o->mot, 0, 0, 0.0f, 0.0f);
        }
    }
    func_00190128(&it);
    if (IsFull(o->lv)) {
        if (!o->flag) {
            func_001d0558(o);
            func_001d2648(o->eff, 0xbbc3, D_0036e3bc);
            func_001d2690(o->eff, 0xbbc4, D_0036e3bc);
        }
        func_00190878(&it, func_001d14a0(), 0);
        func_001bd418(o->f2884, 1, 456, &it, 1, 100);
    } else {
        if (func_00197920()) goto done;
        func_00190878(&it, (u32)o, 0);
        func_001bd418(o->f2884, 1, 455, &it, 1, 100);
    }
done:
    func_001d2750(o->eff);
}
}
}

// ---- 001678f0
namespace n001678f0 {
struct Pad {
    u64 btn;
    u8 pad[60];
    union { struct { u8 b68, b69; } c; struct __attribute__((packed)) { u16 lo : 7, act : 2, hi : 7; } f; } __attribute__((packed)) u;
    u8 pad2[2];
    s32 connected;
    s32 port;
    s32 valid;
    u8 info[2];
    u8 mode;
};
extern "C" {
s32 func_002f6020(s32);
s32 func_002f5f50(s32, u8*);
s32 func_002f5e78(s32, u8*);
s32 func_00105c30(void);
s32 func_00242bd0(void);
s32 func_00242a00(void);
u64 func_00167778(Pad*, u8*);
void func_00167ad0(Pad*, u32);
void func_001676b0(Pad*, u64);
void func_00167658(Pad*, u32);
}
static inline bool IsJp(s32 st) { return func_00105c30() == st || func_00105c30() == 8; }
extern "C" {
// Pad read: maps raw buttons (with region-dependent swaps) into the 64-bit button word.
void func_001678f0(Pad* p) {
    u8 buf[256];
    u8 ok = 0;
    u64 btn = 0;
    s32 st = func_002f6020(p->port);
    p->valid = st != 0;
    if (st == 1) {
        if (p->connected == 0 && func_002f5f50(p->port, p->info) < 0) goto done;
        if (func_002f5e78(p->port, buf) >= 0) {
            u32 a;
            btn = (buf[0] | (buf[1] << 8)) ^ 0xffff;
            if (IsJp(st)) {
                if (btn & 0x2000) btn |= 0x1000000;
                if (btn & 0x4000) btn |= 0x2000000;
            } else {
                if (btn & 0x4000) btn |= 0x1000000;
                if (btn & 0x2000) btn |= 0x2000000;
            }
            st = func_00242bd0();
            if (btn & 0x100) { if ((st ^ 1) != 0) btn |= 0x4000000; else btn |= 0x8000000; }
            else { if (st != 0) btn |= 0x4000000; else btn |= 0x8000000; }
            if ((p->mode & 0xf) == 15 && p->connected == 1) btn |= func_00167778(p, buf);
            a = 0;
            if (func_00242a00()) { /* 2-bit field straddling bytes 68/69 */ u32 hi = p->u.c.b69; u32 lo = (u32)(s32)(s8)p->u.c.b68 >> 31; a = lo | (hi << 1); }
            func_00167ad0(p, a);
            ok = 1;
        }
    }
done:
    if (ok == 1) {
        if (p->connected != 1) p->btn = btn;
        func_001676b0(p, btn);
    } else func_00167658(p, 0);
    p->connected = ok;
    p->u.c.b69 = 0;
    p->u.c.b68 = 0;
}
}
}

// ---- 002d5958
namespace n002d5958 {
struct QV { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Info64 { u8 pad[48]; QV pos; };
extern "C" {
extern u32 D_00361f60;
void func_0016b0e0(u32, u32, Info64*);
u8* func_001b9bc8(u8*);
s32 func_0016a060(u8*);
s32 func_002cf270(u8*, u32);
s32 func_002ceef8(u32, u8*);
QV* func_0016c028(u8*);
}
static inline void qcopy(QV* d, const QV* s) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory"); }
static inline void vsub(QV* d, const QV* a, const QV* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 vlen(const QV* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(v) : "$8");
    return r;
}
extern "C" {
// Returns the nearest active actor of kind 20 that passes the area checks.
u8* func_002d5958(u32 id) {
    u8* best = 0;
    f32 bestd = 0.0f;
    u32 area = D_00361f60;
    Info64 info;
    QV pos;
    u8* a = 0;
    func_0016b0e0(id, 67, &info);
    qcopy(&pos, &info.pos);
    while ((a = func_001b9bc8(a))) {
        if (!(*(u32*)(a + 1416) & 0x8000000)) continue;
        if (func_0016a060(a) != 20) continue;
        if (func_002cf270(a + 2800, 128)) continue;
        if (!func_002ceef8(area, a)) continue;
        if (best) {
            QV d;
            vsub(&d, func_0016c028(a), &pos);
            if (vlen(&d) < bestd) best = a;
        } else {
            QV d;
            best = a;
            vsub(&d, func_0016c028(a), &pos);
            bestd = vlen(&d);
        }
    }
    return best;
}
}
}
