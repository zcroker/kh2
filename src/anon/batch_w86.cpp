#include "../common/types.h"

// ---- 00102528: insert a node into a list sorted by key
namespace n00102528 {
struct LNode { u8 p0[44]; s32 key; u8 p48[8]; LNode* link[2]; };  // link[0]=next, link[1]=prev
struct LHead { LNode* head; LNode* tail; };
struct LList { u8 p0[8]; LHead ls; u8 p16[256]; LNode* cur; };
static inline LNode* LNext(LHead* l, LNode* n) { if (!n) return l->head; return n->link[0]; }
extern "C" void func_00102528(LList* l, LNode* n);
void func_00102528(LList* l, LNode* n)
{
    LNode* pv = 0;
    LNode* c = 0;
    LHead* h;
    while ((c = LNext(&l->ls, c))) {
        if (n->key < c->key) break;
        pv = c;
    }
    if (c && l->cur == c) l->cur = n;
    h = &l->ls;
    if (!pv) {
        if (!l->ls.head) {
            h->tail = n;
            l->ls.head = n;
            n->link[0] = 0;
            n->link[1] = 0;
        } else {
            l->ls.head->link[1] = n;
            n->link[1] = 0;
            n->link[0] = l->ls.head;
            l->ls.head = n;
        }
    } else if (pv == h->tail) {
        pv->link[0] = n;
        n->link[1] = h->tail;
        n->link[0] = 0;
        h->tail = n;
    } else {
        n->link[1] = pv;
        n->link[0] = pv->link[0];
        pv->link[0]->link[1] = n;
        pv->link[0] = n;
    }
}
}

// ---- 001058f8
namespace n001058f8 {
extern "C" {
extern u8 D_0032bb30[];
void func_00319bd0(void*); void func_00188e08(void*); void func_00319870(void*); void func_00319930(void*);
void func_00319d20(void*); void func_00319d30(void*); void func_00319d58(void*); void func_003199d0(void*);
void func_00319a60(void*); void func_002e7768(void*); void func_001e0868(void*); void func_002e77a0(void*);
}
struct NoTail { ~NoTail() {} };
}
void func_001058f8(int a, int b)
{
    using namespace n001058f8;
    NoTail nt;
    if (b == 0xffff && a == 1) {
        u8* s = D_0032bb30;
        func_00319bd0(s + 12);  // clear_18x64_entries
        func_00188e08(s + 9456);
        func_00319870(s + 16364);  // init_18x4_entries
        func_00319930(s + 16808);
        func_00319d20(s + 18904);  // zero_two_words
        func_00319d30(s + 18912);
        func_00319d58(s + 18928);  // store_zero_byte
        func_003199d0(s + 18932);
        func_00319a60(s + 19512);  // clear_fixed_blocks
        func_002e7768(s + 21920);
        func_001e0868(s + 0x100e0);
    }
    if (b == 0xffff && a == 0) {
        u8* s = D_0032bb30;
        func_002e77a0(s + 21920);
    }
}

// ---- 0010b620: direction vector from two points, normalised
namespace n0010b620 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    u32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
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
struct Obj { f32 f0; u32 pad[3]; QWord a; QWord b; };
#define F(q,i) (((f32*)&(q))[i])
extern "C" void func_0010b620(Obj* o, const QWord* p, const QWord* q);
void func_0010b620(Obj* o, const QWord* p, const QWord* q)
{
    o->a = Sub(*p, *q);
    o->f0 = F(o->a, 1);
    o->b = o->a;
    o->b.v[1] = 0;
    F(o->a, 3) = Normalize(&o->a);
    F(o->b, 3) = Normalize(&o->b);
}
}

// ---- 001110e8
namespace n001110e8 {
struct Obj;
typedef s32 (*VFn)(Obj*);
struct Obj { VFn* vt; u8 pad[2936]; u32 b0:1; u32 b1:1; u32 b2:13; u32 b15:1; u32 rest:16; };
struct Ent { u32 v[4]; };
static inline bool IsB0(Obj* o) { return o->b0; }
extern "C" {
extern s32 D_00341780;
extern Ent D_003a9050[];
s32 func_001917c0(void);
s32 func_00110c90(Obj*);
void func_00111060(Obj*, Ent*);
void func_001110e8(Obj* o)
{
    if (IsB0(o)) {
        if (!o->vt[24](o)) {
            o->b0 = 0;
            o->b15 = 0;
        }
        return;
    }
    if (o->b1) return;
    s32 m = D_00341780;
    if (m != 1) {
        if (m < 2) {
            if (m == 0) return;
        }
    } else if (func_001917c0()) return;
    s32 r = func_00110c90(o);
    if (r < 0) return;
    func_00111060(o, &D_003a9050[r]);
}
}
}

// ---- 00117b38: constructor
namespace n00117b38 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void Zero(V4* v) { asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(v) : "memory"); }
union FU { f32 f; s32 i; };
struct Obj {
    void* vt; u8 p4[8]; s32 f12; void* f16; FU* f20; u8 p24[8]; u8 sub32[1536]; s32 f1568; u8 p1572[4];
    f32 f1576; f32 f1580; s32 f1584; u8 p1588[12]; V4 a; V4 b; u8 p1632[16]; s32 f1648; f32 f1652; u8 p1656[72];
    u8 sub1728[200]; s32 f1928;
};
extern "C" {
extern u8 D_003476f0[];
extern u8 D_00347588[];
void func_00113628(Obj*);
void func_0031a060(void*);
FU* func_00114490(Obj*, s32);
void func_0011b6a8(void*);
void func_00117910(Obj*, s32);  // entry64_clear_fields
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
}
}

// ---- 00123ac0: constructor; walks a table of element offsets and accumulates sizes
namespace n00123ac0 {
struct Elem;
typedef s32 (*EFn)(Elem*);
struct Elem { s32 vt; };
#define VT(e) ((EFn*)(e)->vt)
struct Obj { void* vt; u32* tbl; u8 p8[8]; s32 n; s32 a[3]; s32 b[3]; };
extern "C" {
extern u8 D_00347a90[];
void func_0011ee18(Obj*);  // obj_ctor_347940
void func_0011f2f0(Elem*);
void func_00123ac0(Obj* o)
{
    s32 a = 0;
    s32 b = 0;
    func_0011ee18(o);  // obj_ctor_347940
    u32* t = o->tbl;
    o->n = 0;
    o->vt = D_00347a90;
    u32* p = t + 4;
    while (*p) {
        Elem* e = (Elem*)((u8*)t + *p++);
        func_0011f2f0(e);
        a += VT(e)[2](e);
        o->a[o->n] = a;
        b += VT(e)[12](e);
        s32 n = o->n;
        o->b[n] = b;
        o->n = n + 1;
    }
}
}
}

// ---- 00139c90: camera matrix = A * B
namespace n00139c90 {
struct Mtx {
    u32 m[16];
    Mtx() {}
    Mtx& operator=(const Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Mtx Mul(const Mtx& a, const Mtx& b)
{
    Mtx r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct Cam { u8 p0[32]; Mtx m; };
struct Mats { u8 p0[16]; Mtx m; };
extern "C" {
extern Cam* D_00347f80;
Mtx* func_00106a18(s32);  // buffer_get_256
Mats* func_00106a60(s32);  // buffer_get_by_index
void func_00139c90(void)
{
    Mtx* d = &D_00347f80->m;
    Mtx* a = func_00106a18(0);  // buffer_get_256
    Mats* b = func_00106a60(0);  // buffer_get_by_index
    *d = Mul(*a, b ? b->m : *(Mtx*)0);
}
}
}

// ---- 00147050: recursive search through linked nodes
namespace n00147050 {
struct Node { s16 link[8]; u8 box[32]; };
struct Graph { u32 f0; Node* nodes; };
extern "C" {
s32 func_00144d90(void*, void*);
s32 func_00147050(Graph* g, s32 idx, u8* c, s32 depth, s32* best)
{
    Node* n = &g->nodes[idx];
    s32 found = 0;
    if (!func_00144d90(n->box, c + 208)) return 0;
    if (*best <= depth) {
        *best = depth;
        found = idx;
    }
    s16* l = n->link;
    for (s32 i = 0; i < 8; i++) {
        s32 k = *l++;
        if (k == -1) break;
        s32 r = func_00147050(g, k, c, depth + 1, best);  // entry48_process_5args
        if (r) found = r;
    }
    return found;
}
}
}

// ---- 0014ae10
namespace n0014ae10 {
extern "C" {
extern u8 D_003495c0[], D_003496d0[], D_003497e0[], D_003498f0[], D_00349a00[], D_003494b0[];
void func_0014a988(void*);  // clear_fields_244_260
void func_0014ad58(void);
void func_00102c18(s32, s32, void (*)(void));
void func_0014ac48(void);
void func_0014ac68(void);
void func_0014ac90(void);
void func_0014acb0(void);
void func_0014ae10(void)
{
    func_0014a988(D_003495c0);  // clear_fields_244_260
    func_0014a988(D_003496d0);  // clear_fields_244_260
    func_0014a988(D_003497e0);  // clear_fields_244_260
    func_0014a988(D_003498f0);  // clear_fields_244_260
    func_0014a988(D_00349a00);  // clear_fields_244_260
    func_0014a988(D_003494b0);  // clear_fields_244_260
    func_0014ad58();
    func_00102c18(0, 80000, func_0014ac48);
    func_00102c18(0, 80000, func_0014ac68);
    func_00102c18(0, 0x19640, func_0014ac90);
    func_00102c18(0, 0x19a28, func_0014acb0);
}
}
}

// ---- 0016b668
namespace n0016b668 {
struct Obj;
typedef void (*VFn)(Obj*);
struct Obj { VFn* vt; u8 p4[152]; s32 f156; u8 p160[104]; u32 f264; u8 p268[500]; u8 sub768[388]; void* f1156; };
extern "C" {
void func_00187b90(void*);
void func_0016cab8(void*);
void func_0016c7d8(void*);
void func_001de450(void*);
void func_001dde40(void*);
void func_0016a2b0(Obj*);  // clear_15_words_at1976
s32 func_001c0cd8(Obj*);
void func_001c0e60(Obj*);
void func_0016b668(Obj* o)
{
    void* s;
    if (!(o->f264 & 0x10000000)) o->vt[8](o);
    if (o->f1156) {
        func_00187b90(o->sub768);
        s = o->f1156;
        if (s) {
            func_0016cab8(s);
            func_0016c7d8(s);
        }
        o->f1156 = 0;
    }
    if (o->f156) {
        s = &o->f156;
        func_001de450(s);
        func_001dde40(s);
        func_0016a2b0(o);  // clear_15_words_at1976
    }
    if (func_001c0cd8(o)) func_001c0e60(o);
    o->f264 |= 0x80000;
    o->f264 &= ~0x10000000;
}
}
}

// ---- 00175bb8
namespace n00175bb8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    f32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
} __attribute__((aligned(16)));
struct Info { u8 p0[8]; u32 f8; };
struct Obj { u8 p0[12]; Info* info; QWord pos; u8 p32[320]; s32 f352; u8 p356[4]; u32 f360; };
static inline bool Flag(Obj* o)
{
    u32 f = o->f360;
    bool r = false;
    if (f & 4) {
        u32 m = f & 8;
        r = m == 0;
    }
    return r;
}
extern "C" {
double func_00313b80(f32);  // float_to_double
s32 func_003142e0(double, double);  // double_compare
s32 func_00175bb8(Obj* o)
{
    QWord v = o->pos;
    bool ok = false;
    if (0.0f < v.v[3] && (func_003142e0(func_00313b80(v.v[0]), 0.0) != 0 || v.v[2] != 0.0f)) ok = true;
    bool no = !ok;
    if (no) return 0;
    if (Flag(o)) return 1;
    if (!(o->info->f8 & 0x100)) return 0;
    s32 zero = 0;
    s32 neg = o->f352 < zero;
    return neg == 0;
}
}
}

// ---- 001829b0
namespace n001829b0 {
struct Hdr { u32 f0; s32 n; u8 data[1]; };
struct Def { u8 p0[12]; u16 f12; };
struct Item { u8 p0[8]; Def* def; u8 p12[40]; u8* f52; };
extern "C" {
Hdr* func_00181ba8(void*);
Item* func_00199970(s32);
void func_00199aa0(Item*, void*, u8*);
void* func_00182780(s32);
void func_001827e8(void*, void*, Item*, u8);
// 001829b0: moved to src/anon/unit_00182780.cpp
}
}

// ---- 00184308
namespace n00184308 {
struct Obj;
struct Ctl;
typedef void (*CFn)(Ctl*, Obj*);
typedef void (*OFn)(Obj*);
struct Ctl { CFn* vt; };
struct Obj { OFn* vt; u8 p4[8]; Ctl* ctl; u8 p16[248]; u32 f264; u8 p268[500]; u8 sub768[388]; void* f1156; };
extern "C" {
void func_00188340(void*, s32, s32, s32);
void func_0016cce8(void*, s32, s32, s32, s32);
void func_00184308(Obj* o)
{
    o->f264 &= ~0x08000000;
    func_00188340(o->sub768, 2, 0, 0);
    if (!(o->f264 & 0x08000000) && o->f1156) func_0016cce8(o->f1156, 14, 0, 0, 0);
    if (!(o->f264 & 0x08000000)) o->ctl->vt[5](o->ctl, o);
    if (!(o->f264 & 0x08000000)) o->vt[12](o);
}
}
}

// ---- 0018a008: call fn for every key whose time lies in (lo, hi]
namespace n0018a008 {
struct Key { u16 t; u8 f2; u8 n; u16 data[1]; };
struct Hdr { u8 f0; u8 n; u16 off; };
typedef void (*KFn)(Key*, void*);
static inline bool InRange(f32 t, f32 lo, f32 hi) { return (lo < t && t <= hi) || (hi < 0.0f && t == lo); }
extern "C" {
void func_0018a008(Hdr* h, KFn fn, void* arg, f32 lo, f32 hi)
{
    Key* k = (Key*)((u8*)h + h->off);
    for (s32 i = 0; i < h->n; i++) {
        if (InRange(k->t, lo, hi)) fn(k, arg);
        k = (Key*)&k->data[k->n];
    }
}
}
}

// ---- 0018ee60
namespace n0018ee60 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    u32 v[4];
    QWord() {}
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct Res { QWord q; u8 p16[8]; u32 f24; };
struct Tgt;
typedef void (*TFn)(Tgt*, Res*);
struct Tgt { TFn* vt; };
struct Q { u8 p0[40]; s32 f40; };
extern "C" {
Q* func_001050d8(s32);
void func_0018d238(Q*, s32, s32, s32, s32, s32, s32);
Res* func_0018da18(Q*, Tgt*, s32, s32);
Res* func_0018db38(Q*, Tgt*, s32, s32);
void func_0018ca10(Res*);  // alloc_from_pool_magic
void func_0018f028(Q*);
s32 func_0018ee60(s32 a, s32 b, Tgt* t, QWord* v, u8 flag)
{
    s32 r = 0;
    Q* q = func_001050d8(208);
    func_0018d238(q, a, 0, b, 0, -1, -1);
    Res* res;
    if (flag) res = func_0018da18(q, t, q->f40, 0);
    else res = func_0018db38(q, t, 0, 0);
    if (res) {
        r = (res->f24 & 1) ^ 1;
        res->q = *v;
        t->vt[25](t, res);
        func_0018ca10(res);  // alloc_from_pool_magic
    }
    func_0018f028(q);
    return r;
}

}
}

// ---- 00195d00
namespace n00195d00 {
struct Ent { u8 p0[20]; f32 f20; u8 p24[296]; u8 sub320[2548]; u16 f2868; };
struct Obj;
typedef void (*OFn)(Obj*, Ent*, s32);
struct Obj { OFn* vt; };
extern "C" {
void func_0017f488(void*, s32, f32, f32);
void func_0017f5e0(void*, s32, f32, f32, void (*)(void));
void func_00195c80(void);
s32 func_00143448(u16);
void func_00195d00(Obj* o, Ent* e)
{
    if (e->f20 < 0.0f) {
        func_0017f488(e->sub320, 8, 0.0f, 0.0f);
        func_0017f5e0(e->sub320, 4, 0.0f, 0.0f, func_00195c80);
        ((void (*)(Obj*, Ent*))o->vt[1])(o, e);
    } else {
        if (func_00143448(e->f2868)) return;
        o->vt[8](o, e, 0);
    }
}
}
}

// ---- 001a2a50 / 001a2d78: apply to one target or to every party slot
namespace n001a2a50 {
extern "C" {
void* func_001a80c8(s32);  // table24_find_by_id
s32 func_001a3888(s32);  // id_in_range_5_7_131
void* func_001a8bd0(s32);
s32 func_001a8c10(void*, s32);
void func_001a2b50(void*, s32, s32, s32);
s32 func_001a2e50(void*, s32);
s32 func_001a2a50(s32 id, s32 a, s32 b, s32 c)
{
    s32 r = 0;
    void* w = func_001a80c8(id);  // table24_find_by_id
    if (!func_001a3888(id)) {  // id_in_range_5_7_131
        func_001a2b50(w, a, b, c);
        if (a != b) r = 1;
    } else {
        void* g = func_001a8bd0(-1);
        for (s32 i = 0; i < 4; i++) {
            a = func_001a8c10(g, i);
            if (a) {
                func_001a2b50(w, a, b, c);
                if (a != b) r = 1;
            }
        }
    }
    return r;
}
s32 func_001a2d78(s32 id, s32 a)
{
    s32 r = 0;
    void* w = func_001a80c8(id);  // table24_find_by_id
    if (!func_001a3888(id)) {  // id_in_range_5_7_131
        r = func_001a2e50(w, a);
    } else {
        void* g = func_001a8bd0(-1);
        for (s32 i = 0; i < 4; i++) {
            a = func_001a8c10(g, i);
            if (a) r = r || func_001a2e50(w, a);
        }
    }
    return r;
}
}
}

// ---- 001b7a18
namespace n001b7a18 {
struct QWord { f32 v[4]; } __attribute__((aligned(16)));
static inline void Scale(QWord* d, const QWord* a, f32 k)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "f"(k) : "$8", "memory");
}
static inline void SubIn(QWord* a, const QWord* b)
{
    asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(a), "r"(b) : "memory");
}
struct Item { u8 p0[16]; u8 key[16]; };
struct List { s32 n; u8 p4[12]; Item items[1]; };
extern "C" {
void* func_001b7998(void*, void*);
void func_0018a7d0(void*, void*, QWord*);
void func_001b7b10(void*, List*, QWord*, QWord*);
void func_001b7958(void*, QWord*);  // add_vec_to_records
void func_001b7a18(void* o, List* l, QWord* acc)
{
    QWord t;
    QWord s;
    for (s32 i = 0; i < l->n; i++) {
        void* x = func_001b7998(o, l->items[i].p0);
        if (x) {
            func_0018a7d0(x, l->items[i].p0, &t);
            func_001b7b10(o, l, acc, &t);
            Scale(&s, &t, -1.0f);
            func_001b7958(o, &s);  // add_vec_to_records
            SubIn(acc, &t);
        }
    }
}
}
}

// ---- 001c0ae0: process every entry whose id bit is set
namespace n001c0ae0 {
struct E { u32 id; u32 f4; u8 data[24]; };
struct Tbl { u32 f0; s32 n; E e[1]; };
extern "C" {
extern Tbl* D_01d49360;
extern u32 D_0032f254[];
void func_001c0a80(void*);
void func_001c0ab0(void*, void*);
void func_001c0ae0(void* o)
{
    func_001c0a80(o);
    E* e = D_01d49360->e;
    for (s32 i = 0; i < D_01d49360->n; i++, e++) {
        if (D_0032f254[e->id >> 5] & (1 << (e->id & 31))) func_001c0ab0(o, e->data);
    }
}
}
}

// ---- 001da070: is the object within range (height and horizontal distance) of the player
namespace n001da070 {
struct QWord { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline QWord Sub(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Length(const QWord& v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&v) : "$8", "memory");
    return r;
}
extern "C" {
extern void* D_0034e948;
s32 func_0019ba60(void*);
QWord* func_0016c028(void*);  // obj_get_attach_or_alt
f32 func_002f8870(f32);  // fabsf
s32 func_001da070(void* o)
{
    void* p = D_0034e948;
    if (!func_0019ba60(p)) return 0;
    QWord* a = func_0016c028(p);  // obj_get_attach_or_alt
    QWord d = Sub(*a, *func_0016c028(o));  // obj_get_attach_or_alt
    d.y += -50.0f;
    if (func_002f8870(d.y) > 90.0f) return 0;
    *(u32*)&d.y = 0;
    return Length(d) <= 80.0f;
}
}
}

// ---- 001eb368
namespace n001eb368 {
struct M { u8 p0[16]; u8 a[16]; u8 b[16]; u8 c[16]; u8 d[16]; u8 r0[16]; u8 r1[16]; u8 r2[16]; f32 t[4]; };
extern "C" {
union MP { M* p; f32 f; };
extern MP D_01d9e6e8;
extern f32 D_00354be0[];
extern f32 D_01d9e840[];
extern u8 D_01d9e8c0[];
void func_002f3f40(void*, void*, f32);  // vec_scale_by_f12
void func_002f3f28(void*, void*, f32*);
void func_002f3d08(void*, void*, void*);
void func_001eb368(void)
{
    func_002f3f40(D_01d9e6e8.p->r0, D_01d9e6e8.p->a, D_00354be0[0]);  // vec_scale_by_f12
    func_002f3f40(D_01d9e6e8.p->r1, D_01d9e6e8.p->b, D_00354be0[1]);  // vec_scale_by_f12
    func_002f3f40(D_01d9e6e8.p->r2, D_01d9e6e8.p->c, D_00354be0[2]);  // vec_scale_by_f12
    func_002f3f28(D_01d9e6e8.p->t, D_01d9e6e8.p->d, D_00354be0);
    D_01d9e6e8.p->t[0] += D_01d9e840[12];
    D_01d9e6e8.p->t[1] += D_01d9e840[13];
    D_01d9e6e8.p->t[2] += D_01d9e840[14];
    D_01d9e6e8.p->t[3] = 1.0f;
    func_002f3d08(D_01d9e6e8.p->r0, D_01d9e8c0, D_01d9e6e8.p->r0);
}
}
}

// ---- 0022ca00
namespace n0022ca00 {
struct Ent { s16 id; s16 start; s16 end; s16 f6; u8 data[84]; };
struct Tbl { u32 f0; s16 n; s16 f6; Ent e[1]; };
struct Act { u8 p0[1704]; s32 f1704; u8 p1708[196]; void* f1904; };
union AP { Act* p; s32 i; };
struct Obj { u8 p0[8]; AP act; };
extern "C" {
extern Tbl* D_0035de50;
extern s32 D_0035de20;
s32 func_00225b00(s32);  // flag_query_by_index
Obj* func_00227d10(s32);
s32 func_001ba028(Act*);  // list_contains_ptr
s32 func_00227d58(s32);
void func_0022ca00(void)
{
    Tbl* t = D_0035de50;
    if (!t) return;
    s32 cur = D_0035de20;
    Ent* e = t->e;
    s32 n = t->n;
    for (s32 i = 0; i < n; i++, e++) {
        s32 a = e->start;
        void* d = e->data;
        s32 b = e->end;
        if (func_00225b00(a)) continue;
        if (cur < a) continue;
        if (!(cur < b)) continue;
        Obj* o = func_00227d10(e->id);
        if (!o || !o->act.p) continue;
        if (!func_001ba028(o->act.p)) continue;
        s32 v = func_00227d58(e->id);
        o->act.p->f1704 = v;
        o->act.p->f1904 = d;
    }
}
}
}

// ---- 00232988
namespace n00232988 {
struct Obj { s32 type; u8 p4[16]; s32 f20; };
struct Ent { Obj* obj; s16 f4; s8 kind; u8 p7[25]; };
struct Tbl { u32 f0; s16 n; s16 f6; Ent e[1]; };
extern "C" {
extern Tbl* D_0035de4c;
s32 func_002baa20(s32);
void func_002baa48(s32);
void func_00232718(void);  // decrement_global_clamped
void func_002278e0(Obj*);
void func_00232988(void)
{
    Tbl* t = D_0035de4c;
    if (!t) return;
    Ent* e = t->e;
    s32 n = t->n;
    for (s32 i = 0; i < n; i++, e++) {
        if (e->kind != 2) continue;
        Obj* o = e->obj;
        if (o->type != 3) continue;
        if (func_002baa20(o->f20) == 1) {
            func_002baa48(o->f20);
            func_00232718();  // decrement_global_clamped
        }
        func_002278e0(o);
    }
}
}
}

// ---- 002330c8: build a file path from a directory prefix and a name (strcat into a static buffer)
namespace n002330c8 {
extern "C" {
extern char D_01dadbd8[];
extern char D_00371370[];
extern char D_00371378[];
extern char D_00371380[];
char* func_002feee8(char*, const char*);
void func_002ff3fc(char*);  // strlen
char* func_002330c8(const char* path, const char* name)
{
    char buf[48];
    D_01dadbd8[0] = 0;
    func_002feee8(D_01dadbd8, D_00371370);
    s32 i = 0;
    const char* p;
    char* q;
    char c;
    do {
        p = path + i;
        q = buf + i;
        c = *p;
        i++;
        *q = c;
    } while (c != '/');
    *q = 0;
    func_002feee8(D_01dadbd8, buf + 4);
    func_002feee8(D_01dadbd8, D_00371378);
    func_002feee8(D_01dadbd8, name);
    func_002feee8(D_01dadbd8, p);
    func_002feee8(D_01dadbd8, D_00371380);
    func_002ff3fc(D_01dadbd8);  // strlen
    func_002ff3fc(buf);  // strlen
    return D_01dadbd8;
}
}
}

// ---- 0023c5f0: maximum value over a group of entries
namespace n0023c5f0 {
struct Grp { u16 first; u16 n; u8 p4[16]; };
struct Ent { s32 f0; s32 idx; s32 arg; s32 add; u8 p16[8]; };
struct Item { u8 p0[344]; };
struct Obj { u8 p0[16]; Ent* ents; Grp* grps; u8 p24[20]; Item* items; };
extern "C" {
s32 func_00239b50(Item*, s32);  // find_entry_in_group
s32 func_0023c5f0(Obj* o, s32 g)
{
    Grp* gp = &o->grps[g];
    Ent* e = &o->ents[gp->first];
    s32 best = 0;
    for (s32 i = 0; i < gp->n; i++, e++) {
        s32 v = func_00239b50(&o->items[e->idx], e->arg) + e->add;
        if (best < v) best = v;
    }
    return best;
}
}
}

// ---- 0023e9f0
namespace n0023e9f0 {
struct Obj { u8 p0[2924]; s32 n; u8 p2928[2368]; u8* a[4]; u8* b[4]; u8* c[4]; };
extern "C" {
u32 func_0023f6f8(u8*);
s32 func_00139d78(u8*);
u32 func_0023a918(u8*);
void func_0023e990(Obj*, s32, u32);
void func_0023e9f0(Obj* o)
{
    for (s32 i = 0; i < o->n; i++) {
        u32 v;
        if (!o->a[i]) {
            if (!o->b[i]) continue;
            if (o->c[i] && func_00139d78(o->c[i])) v = func_0023a918(o->c[i] + 24) >> 24;
            else if (func_00139d78(o->b[i])) v = func_0023a918(o->b[i] + 24) >> 24;
            else v = 0;
        } else v = func_0023f6f8(o->a[i]);
        func_0023e990(o, i, v);
    }
}
}
}

// ---- 00245be8 / 0024a048: refresh menu animations
namespace n00245be8 {
struct Info { u8 p0[4]; s16 anim; };
extern "C" {
extern void* D_0035ed28;
extern void* D_0035ed20;
extern void* D_0035ed30;
extern void* D_0035ed2c;
extern void* D_0035ed78;
extern void* D_0035ed70;
extern void* D_0035ed80;
extern void* D_0035ed7c;
extern void* D_0035ed84;
extern void* D_0035ed88;
s32 func_00139d78(void*);
s32 func_0023f0c0(void*);
void func_0023f070(void*, s32, s32);
s32 func_0028acc8(void*);
void func_0028ab20(void*);
void* func_002891e8(void*);
void* func_002469a0(void*);
Info* func_002468a0(void*);
Info* func_0024b1a0(void*);
void func_0028da70(void*, s32);
void func_00245be8(void)
{
    if (func_00139d78(D_0035ed28) && func_0023f0c0(D_0035ed28) != 32) func_0023f070(D_0035ed28, 32, -1);
    if (func_0028acc8(D_0035ed20)) {
        func_0028ab20(D_0035ed20);
        Info* in = func_002468a0(func_002469a0(func_002891e8(D_0035ed20)));
        if (func_00139d78(D_0035ed30) && func_0023f0c0(D_0035ed30) != in->anim) func_0023f070(D_0035ed30, in->anim, -1);
    }
    if (func_00139d78(D_0035ed2c) && func_0023f0c0(D_0035ed2c) != 35) func_0023f070(D_0035ed2c, 35, -1);
}
void func_0024a048(void)
{
    if (func_00139d78(D_0035ed78) && func_0023f0c0(D_0035ed78) != 32) func_0023f070(D_0035ed78, 32, -1);
    if (func_0028acc8(D_0035ed70)) {
        func_0028ab20(D_0035ed70);
        Info* in = func_0024b1a0(func_002891e8(D_0035ed70));
        if (func_00139d78(D_0035ed80) && func_0023f0c0(D_0035ed80) != in->anim) func_0023f070(D_0035ed80, in->anim, -1);
    }
    if (func_00139d78(D_0035ed7c) && func_0023f0c0(D_0035ed7c) != 35) func_0023f070(D_0035ed7c, 35, -1);
    func_0028da70(D_0035ed84, 33);
    func_0028da70(D_0035ed88, 41);
}
}
}

// ---- 00274cf0
namespace n00274cf0 {
extern "C" {
extern s8* D_0035f1fc;
void func_00293bd0(s32, s32, s32);
s32 func_002953c8(s32);
s32 func_002941d8(s32);
s32 func_00296f90(void);  // get_global_36f598
s32 func_00296f80(void);  // get_global_36f594
void func_00274cf0(s32 m)
{
    switch (m) {
    case 0:
        func_00293bd0(1, 0, 0);
        break;
    case 1:
        func_00293bd0(2, func_00296f80(), 0);
        break;
    case 2:
        if (*D_0035f1fc == 1) {
            if (func_002941d8(func_002953c8(1))) {
                func_00293bd0(2, func_00296f90(), 0);
                break;
            }
        }
        func_00293bd0(2, func_002953c8(*D_0035f1fc) + 1, 0);
        break;
    case 13:
        func_00293bd0(2, func_002953c8(15) + 1, 0);
        break;
    }
}
}
}

// ---- 002817d8
namespace n002817d8 {
extern "C" {
extern s32 D_0035f270;
extern s32 D_0035f274;
extern s32 D_0035f278;
extern s32 D_0035f27c;
extern s32 D_0035f284;
extern s32 D_0035f288;
extern s32 D_0035f28c;
extern u8 D_0035f299;
extern u16 D_0035f2a0[3];
extern u16 D_0035f2a8[2];
extern u16 D_003741a8[];
void func_002817d8(s32 a, s32 b, s32 c, s32 d, s32 e, u16* f, u16* g)
{
    D_0035f270 = a;
    D_0035f278 = b;
    D_0035f27c = c;
    D_0035f284 = d;
    D_0035f274 = e;
    if (f) {
        D_0035f28c = D_0035f288;
        D_0035f299 = 1;
    } else {
        D_0035f28c = 0;
        D_0035f299 = 0;
    }
    for (s32 i = 0; i < 3; i++) D_0035f2a0[i] = f ? f[i] : 0xffff;
    if (!g) g = D_003741a8;
    for (s32 i = 0; i < 2; i++) D_0035f2a8[i] = g[i];
}
}
}

// ---- 00284650
namespace n00284650 {
struct Item { u8 p[436]; };
struct Tri { s8 a, b, anim; };
extern "C" {
extern void* D_0035f2c8;
extern Item* D_0035f2cc;
extern Tri D_00374360[];
s32 func_00139d78(void*);
s32 func_002854c0(void);
void func_0023f070(void*, s32, s32);
void func_00138c10(void*, s32);
void func_00284650(void)
{
    func_00139d78(D_0035f2c8);
    func_0023f070(D_0035f2c8, D_00374360[func_002854c0()].anim, -1);
    func_00139d78(&D_0035f2cc[0]);
    func_00138c10(&D_0035f2cc[0], 2);
    func_00139d78(&D_0035f2cc[1]);
    func_00138c10(&D_0035f2cc[1], 8);
    for (s32 i = 0; i < 8; i++) {
        func_00139d78(&D_0035f2cc[i + 2]);
        func_00138c10(&D_0035f2cc[i + 2], 5);
    }
}
}
}

// ---- 00285d58: flag test (id >= 0) or any set flag whose record passes the check
namespace n00285d58 {
struct Rec { u8 f0, f1, kind; };
extern "C" {
extern u32* D_0035f2e4;
Rec* func_001a80c8(s32);  // table24_find_by_id
s32 func_00285d18(u8);
s32 func_00285d58(s32 id)
{
    s32 r = 0;
    if (id >= 0) {
        r = (D_0035f2e4[(u32)id >> 5] & (1 << (id & 31))) != 0;
    } else {
        for (s32 i = 0; i < 640; i++) {
            if (!(D_0035f2e4[(u32)i >> 5] & (1 << (i & 31)))) continue;
            if (func_00285d18(func_001a80c8(i)->kind)) { r = 1; break; }
        }
    }
    return r;
}
}
}

// ---- 00287358: set a flag bit in the save data
namespace n00287358 {
struct Save { u8 p0[80]; u32 a[3]; u32 b[1]; };
static inline void SetBit(u32* bits, u32 i)
{
    u32* p = (u32*)(((i >> 5) << 2) + (u32)bits);
    u32 m = 1 << (i & 31);
    if (!(*p & m)) *p |= m;
}
extern "C" {
Save* func_002859a0(void);
void* func_00258108(void);
void* func_002811b0(void*, s32);
s32 func_001b7818(void*);
void func_00287358(s32 mode, u32 id)
{
    Save* s = func_002859a0();
    void* v = func_00258108();
    if (!mode) {
        SetBit(s->a, id);
    } else {
        s32 k = func_001b7818(func_002811b0(v, mode));
        k -= 2;
        SetBit(s->b, k * 48 + id);
    }
}
}
}

// ---- 0028a980
namespace n0028a980 {
struct Spr { u8 p0[392]; s32 f392; };
struct Def { s16 anim; s16 f2; s16 f4; };
union N16 { s16 v; s32 i; };
struct Obj { u8 p0[4]; N16 n; u8 p8[6]; s16 f14; u8 p16[24]; Spr** sprs; };
extern "C" {
Def* func_0028ac98(Obj*, s32);  // lookup_by_index_align
void func_00138c10(Spr*, s32);
void func_0028a980(Obj* o)
{
    for (s32 i = 0; i < o->n.v; i++) {
        if (!o->sprs[i]) continue;
        Def* d = func_0028ac98(o, i);  // lookup_by_index_align
        if (d) {
            func_00138c10(o->sprs[i], d->anim);
            o->sprs[i]->f392 = d->f4;
        }
    }
    o->f14 = 0;
}
}
}

// ---- 0028c4f8: swap in the pending item array, destroying the current one
namespace n0028c4f8 {
struct Elem;
typedef void (*EFn)(Elem*);
struct Elem { EFn* vt; u8 p4[436]; };
extern "C" {
extern Elem* D_0035f3c4;
extern Elem* D_0035f3c8;
extern s32 D_0035f3cc;
extern s32 D_0035f3d0;
void func_00106420(void*);
void menuitem_update(void) asm("_ZN2Tz8MenuItem6updateEv");
}
static inline void Release()
{
    Elem* a = D_0035f3c4;
    if (a) {
        Elem* e = a + 32;
    next:
        if (a != e) {
            --e;
            e->vt[3](e);
            goto next;
        }
        func_00106420(a);
        D_0035f3c4 = 0;
    }
}
void menuitem_update(void)
{
    if (D_0035f3c8) {
        Release();
        D_0035f3c4 = D_0035f3c8;
        D_0035f3cc = D_0035f3d0;
        D_0035f3c8 = 0;
        D_0035f3d0 = 0;
    } else {
        Release();
        D_0035f3c4 = 0;
    }
}
}

// ---- 002a9f50: are the required flags set
namespace n002a9f50 {
struct Lst { u8 p0[8]; s32 n; };
extern "C" {
extern u32* D_0035f610;
u32* func_002a9d68(void);
Lst* func_00294000(s32);
s32 func_002a9f50(s32 id)
{
    s32 r = 1;
    u32* bits = func_002a9d68();
    Lst* l = func_00294000(3);
    if (id < 0) {
        s32 n = l->n;
        for (s32 i = 0; i < n; i++) {
            u32 m = 1 << (i & 31);
            if (D_0035f610[(u32)i >> 5] & m) {
                r = (bits[(u32)i >> 5] & m) != 0;
                if (!r) break;
            }
        }
    } else {
        u32 m = 1 << (id & 31);
        s32 t = 0;
        if (D_0035f610[(u32)id >> 5] & m) t = (bits[(u32)id >> 5] & m) != 0;
        r = t;
    }
    return r;
}
}
}

// ---- 002b3d00: allocate the object's parts (one, an array of three, one) from the system allocator
namespace n002b3d00 {
struct Alloc;
typedef void* (*AFn)(Alloc*, s32, s32);
struct Alloc { AFn* vt; };
struct Sys { u8 p0[20]; Alloc* alloc; };
union SysP { Sys* p; u32 u; };
struct T { u32 vt; u8 p4[8]; u32 f12; u8 p16[60]; };
struct Obj { u32 a; u32 b; u32 c; };
extern SysP g_sys asm("D_00347f80");
extern "C" {
extern u8 D_0035ebb8[];
static inline T* NewT(void* p)
{
    T* t = (T*)p;
    t->f12 = 0;
    t->vt = (u32)D_0035ebb8;
    return t;
}
void func_002b3d00(Obj* o)
{
    o->a = 0;
    o->b = 0;
    o->c = 0;
    o->a = (u32)NewT(g_sys.p->alloc->vt[0](g_sys.p->alloc, 76, 0));
    u32* y = (u32*)g_sys.p->alloc->vt[0](g_sys.p->alloc, 232, 0);
    y[0] = 3;
    T* e = (T*)(y + 1);
    T* p = e;
    for (s32 k = 2; k != -1; k--, p++) NewT(p);
    o->b = (u32)e;
    o->c = (u32)NewT(g_sys.p->alloc->vt[0](g_sys.p->alloc, 76, 0));
}
}
}

// ---- 002cd428
namespace n002cd428 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    f32 v[4];
    QWord() {}
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord Sub(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Length(const QWord& v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&v) : "$8", "memory");
    return r;
}
struct Pt { QWord pos; QWord dir; };
struct Obj { u8 p0[8]; s32 f8; };
extern "C" {
QWord* func_002cb828(Obj*, QWord*);  // ring_advance_index
Pt* func_002cb8e0(Obj*);
s32 func_002cb920(Obj*);  // get_sum_fields_minus1
void func_002cd428(Obj* o, QWord* p)
{
    if (!o->f8) {
        func_002cb828(o, p);  // ring_advance_index
        return;
    }
    QWord d = Sub(func_002cb8e0(o)->pos, *p);
    if (Length(d) < 100.0f) return;
    Pt* t = func_002cb8e0(o);
    QWord* q = func_002cb828(o, p);  // ring_advance_index
    t->dir = Sub(*q, t->pos);
    t->dir.v[3] = func_002cb920(o) - 1;
}
}
}

// ---- 0031d030: deleting destructor (destroys both element arrays, frees through the system allocator)
namespace n0031d030 {
struct Elem;
typedef void (*EFn)(Elem*);
struct Elem { EFn* vt; u8 p4[404]; };
struct Obj { u32 vt; u8 p4[44]; Elem a[6]; Elem b[32]; };
struct Alloc;
typedef void (*AFn)(Alloc*, void*);
struct Alloc { AFn* vt; };
struct Sys { u8 p0[20]; Alloc* alloc; };
union SysP { Sys* p; u32 u; };
extern SysP g_sys asm("D_00347f80");
extern "C" {
extern u8 D_0034a820[];
extern u8 D_00347f98[];
static inline void DestroyArr(Elem* a, s32 n)
{
    if (a) {
        Elem* e = a + n;
    next:
        if (a != e) {
            --e;
            e->vt[3](e);
            goto next;
        }
    }
}
void func_0031d030(Obj* o)
{
    o->vt = (u32)D_0034a820;
    if (o->b) {
        Elem* e = o->b + 32;
    nb:
        if (o->b != e) {
            --e;
            e->vt[3](e);
            goto nb;
        }
    }
    if (o->a) {
        Elem* e = o->a + 6;
    na:
        if (o->a != e) {
            --e;
            e->vt[3](e);
            goto na;
        }
    }
    o->vt = (u32)D_00347f98;
    g_sys.p->alloc->vt[1](g_sys.p->alloc, o);
}
}
}

// ---- 00314830: libgcc fp-bit __fpcmp_parts (compare two unpacked floats)
namespace n00314830 {
typedef enum { CLASS_SNAN, CLASS_QNAN, CLASS_ZERO, CLASS_NUMBER, CLASS_INFINITY } fp_class_type;
typedef struct {
    fp_class_type class_;
    unsigned int sign;
    int normal_exp;
    union { u64 ll; } fraction;
} fp_number_type;
static inline int isnan(fp_number_type* x) { return x->class_ == CLASS_SNAN || x->class_ == CLASS_QNAN; }
static inline int isinf(fp_number_type* x) { return x->class_ == CLASS_INFINITY; }
static inline int iszero(fp_number_type* x) { return x->class_ == CLASS_ZERO; }
extern "C" int func_00314830(fp_number_type* a, fp_number_type* b);
int func_00314830(fp_number_type* a, fp_number_type* b)
{
    if (isnan(a) || isnan(b)) return 1;
    if (isinf(a) && isinf(b)) return b->sign - a->sign;
    if (isinf(a)) return a->sign ? -1 : 1;
    if (isinf(b)) return b->sign ? 1 : -1;
    if (iszero(a) && iszero(b)) return 0;
    if (iszero(a)) return b->sign ? 1 : -1;
    if (iszero(b)) return a->sign ? -1 : 1;
    if (a->sign != b->sign) return a->sign ? -1 : 1;
    if (a->normal_exp > b->normal_exp) return a->sign ? -1 : 1;
    if (a->normal_exp < b->normal_exp) return a->sign ? 1 : -1;
    if (a->fraction.ll > b->fraction.ll) return a->sign ? -1 : 1;
    if (a->fraction.ll < b->fraction.ll) return a->sign ? 1 : -1;
    return 0;
}
}

// ---- 00318908: libgcc unwinder _Unwind_RaiseException_Phase2
namespace n00318908 {
struct Ctx { u8 p0[712]; u32 ra; };
struct Exc { u64 exception_class; void* cleanup; u64 private_1; u64 private_2; };
typedef s32 (*Pers)(s32, s32, u64, Exc*, Ctx*);
struct FS { u8 p0[2868]; Pers personality; u8 p2872[24]; };
static inline u32 Identify(Ctx* c) { return c->ra; }
extern "C" {
s32 func_00317d80(Ctx*, FS*);
void func_002fd160(void) __attribute__((noreturn));
void func_003181a0(Ctx*, FS*);
s32 func_00318908(Exc* exc, Ctx* ctx)
{
    s32 code;
    while (1) {
        FS fs;
        s32 match;
        code = func_00317d80(ctx, &fs);
        match = (Identify(ctx) == exc->private_2 ? 4 : 0);
        if (code != 0) return 2;
        if (fs.personality) {
            code = (*fs.personality)(1, 2 | match, exc->exception_class, exc, ctx);
            if (code == 7) break;
            if (code != 8) return 2;
        }
        if (match) func_002fd160();
        func_003181a0(ctx, &fs);
    }
    return code;
}
}
}
