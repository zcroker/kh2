#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));

typedef void (*VF)(void*);

// 128-bit vector with an asm self-checked assignment (non-POD: returned via hidden pointer)
struct Vec128 {
    u128 q;
    Vec128() {}
    Vec128(const Vec128& o) : q(o.q) {}
    Vec128& operator=(const Vec128& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};

extern "C" {

extern void* D_0032b91c;

/* ---- 00113338 ---- */
void* func_001050d8(u32);
void func_0018d238(void*, u32, u32, u32, u32, s32, u32);
s32 func_001130b0(u128*, u32, void*, u32);
void func_0018f028(void*);

s32 func_00113338(u32 a0, u128* a1, u32 a2, u32 a3, u32 a4, u32 a5) {
    u128 tmp;
    void* o = func_001050d8(208);
    func_0018d238(o, a0, 0, a3, 0, -1, a4);
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&tmp), "r"(a1) : "$8", "memory");
    s32 r = func_001130b0(&tmp, a2, o, a5);
    func_0018f028(o);
    return r;
}

/* ---- 00137890 ---- */
extern u8* D_00347d5c;
u32 func_0013a7e8(u32);
void func_00138d60(void*, u32, u32, void*, u32, u32, u32);

void func_00137890(u8* p, u32 a1, u32 a2, u32 a3) {
    u8* base = D_00347d5c + 32;
    u32 r = func_0013a7e8(1);
    func_00138d60(p, 11100, r, base, 77, a1, 0);
    *(u32*)(p + 1308) = a3;
    *(u32*)(p + 440) = a2;
    *(u32*)(p + 424) = 16;
    *(u32*)(p + 432) = 2;
    *(u32*)(p + 1304) = 0;
    *(u32*)(p + 436) = 0;
}

/* ---- 0013d2d0 ---- */
struct Pair1 { u32 a, b; };
extern Pair1 D_00348578[];
u8* func_0013cb80(void);  // get_global_358050
s32 func_0013cb90(void);
u32 func_0013cb30(void);
void func_001386e0(void*, u32, u32, void*, u32, u32);
void func_00138c40(void*, u32, u32);
f32 func_0013b2a8(void*);  // mul_float684_692
void func_00138d48(void*, f32, f32, f32, f32);
void func_0013d1d0(void*);

void func_0013d2d0(u8* p) {
    u8* s = p + 260;
    u8* a = func_0013cb80();  // get_global_358050
    s32 i = func_0013cb90();
    func_001386e0(s, 5301, func_0013cb30(), a + 32, D_00348578[i].b, 1);
    func_00138c40(s, 28, 322);
    func_00138d48(s, 1.0f, 1.0f, 1.0f, func_0013b2a8(p));
    func_0013d1d0(p);
}

/* ---- 00146c08: box vs 5 planes (VU0 dot product) ---- */
static inline bool front2(f32 d) { return 0.0f <= d; }
static inline f32 dot1(f32* v, f32* pl) {
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
            : "=f"(d) : "r"(v), "r"(pl) : "$8", "memory");
    return d;
}
s32 func_00146c08(f32* pl, f32* box) {
    s32 i;
    for (i = 0; i < 5; i++, pl += 4) {
        f32 v[4] __attribute__((aligned(16)));
        f32 d;
        v[0] = *(s32*)&pl[0] >= 0 ? box[3] : box[0];
        v[1] = *(s32*)&pl[1] >= 0 ? box[4] : box[1];
        v[2] = *(s32*)&pl[2] >= 0 ? box[5] : box[2];
        d = dot1(v, pl);
        if (front2(d + pl[3])) return 0;
    }
    return 1;
}

/* ---- 001519f8 ---- */
s32 func_0023aa98(void*);
f32 func_00151690(void*);  // scale_ratio_2888_2880
void func_00239f18(void*, f32);  // obj_set_float312_and_flags
void func_00138c68(void*, s32, u32);

void func_001519f8(u8* p) {
    u8* a = p + 1272;
    u8* b = p + 1680;
    u8* c = p + 2064;
    f32 n = (f32)func_0023aa98(p + 2088);
    func_00239f18(a, func_00151690(p));  // obj_set_float312_and_flags
    func_00239f18(b, 1.0f - func_00151690(p));  // obj_set_float312_and_flags
    func_00138c68(c, (s32)(func_00151690(p) * n), 0);
}

/* ---- 0015c0f8 ---- */
struct Alloc1;
typedef void* (*AllocFn)(Alloc1*, u32, u32);
struct Alloc1 { AllocFn* vt; };
struct Holder1 { u32 f[5]; Alloc1* alloc; };
extern Holder1* D_00347f80;
extern void* D_0034af08;
extern void* D_0034ae80;
extern s32 D_0034ece0;
void func_0031daf0(void*);
void* func_001492e8(void*, s32);
void func_0015bbc8(void*, void*);

void ctarget0_0015c0f8(void* p) asm("_Z17ctarget0_0015c0f8v");
void ctarget0_0015c0f8(void* p) {
    Alloc1* a = D_00347f80->alloc;
    u8* o = (u8*)a->vt[0](a, 3040, 0);
    *(u32*)(o + 12) = 0;
    *(void**)o = &D_0034af08;
    func_0031daf0(o + 48);
    D_0034ae80 = o;
    s32 id = D_0034ece0;
    if (id == 99) return;
    void* r = func_001492e8(p, id);
    if (r) func_0015bbc8(D_0034ae80, r);
}

/* ---- 00168218: pick the idle node with the smallest key ---- */
struct Node2 { Node2* next; u32 busy; u8 data[1]; };
extern Node2* D_0034d840;
void func_0030edb0(void);
void func_0030ee00(void);  // ee_intr_get_enable
u32 func_001ae1e0(void*);
static inline Node2* Next2(Node2* n) { if (!n) return D_0034d840; return n->next; }

Node2* func_00168218(void) {
    Node2* best = 0;
    Node2* n = 0;
    u32 bestv = -1;
    func_0030edb0();
    while ((n = Next2(n))) {
        u32 v = func_001ae1e0(n->data);
        if (n->busy) continue;
        if (best == 0 || v < bestv) { bestv = v; best = n; }
    }
    func_0030ee00();  // ee_intr_get_enable
    return best;
}

/* ---- 00168548 ---- */
extern u8 D_01f18000[];
extern u8 D_01fc0000[];
void func_002fde18(void*, u32, u32);
extern Alloc1* D_0032b91c_a asm("D_0032b91c");
void func_00168958(void*, u32, u32);  // obj_init_name_string

void func_00168548(u32 a0, u32 a1, u32 a2) {
    func_002fde18(D_01f18000, 0, D_01fc0000 - D_01f18000);
    u8* o = (u8*)D_0032b91c_a->vt[0](D_0032b91c_a, 76, (u32)__builtin_return_address(0));
    func_00168958(o, 2, a0);  // obj_init_name_string
    *(u8**)(o + 52) = D_01f18000;
    *(u32*)(o + 56) = a1;
    *(u32*)(o + 60) = a2;
}

/* ---- 001849d8 ---- */
struct Bits3 { u64 lo:3; u64 kind:4; u64 mid:26; u64 dirty:1; };
struct Ent3 { u8 pad[1528]; f32 val; u32 pad2; union { u64 raw; Bits3 b; } u; };
void* func_0016c028(Ent3*);  // obj_get_attach_or_alt
s32 func_001a7610(void*, f32*, s32, f32, f32);
static inline bool clean3(Ent3* e) { return !e->u.b.dirty; }

f32 f_001849d8(Ent3* e) asm("_Z13func_001849d8j");
f32 f_001849d8(Ent3* e) {
    if (!clean3(e)) {
        f32 out[4];
        if (func_001a7610(func_0016c028(e), out, (s32)(e->u.raw >> 3) & 0xf, 100000.0f, 200.0f)) {
            e->val = out[1];
            e->u.b.dirty = 0;
        } else {
            e->val = ((f32*)func_0016c028(e))[1];
        }
    }
    return e->val;
}

/* ---- 00191ab8 ---- */
void* func_00176b20(s32);
s32 func_0019ba60(void*);
s32 func_00185ac0(void*);

s32 func_00191ab8(void) {
    s32 i, j;
    for (i = 0; i < 3; i++) {
        u8* p = (u8*)func_00176b20(i);
        if (!func_0019ba60(p)) continue;
        void** q = (void**)(p + 2808);
        for (j = 0; j < 2; j++) {
            void* c = *q++;
            if (func_0019ba60(c) && !func_00185ac0(c)) return 1;
        }
    }
    return 0;
}

/* ---- 00191f78 ---- */
struct Slot4 { void* obj; u32 val; };
extern Slot4 D_01c61970[];
struct Prop4 { u32 f0, f4, val; };
Prop4* func_00168b38(void*, u32, u32);  // entry_array_find_nth
void func_001aadb0(u32);
static inline bool has4(Prop4* p) { return p && p->val; }

void func_00191f78(s32 idx, void* obj) {
    Slot4* s = &D_01c61970[idx];
    s->obj = obj;
    Prop4* p = func_00168b38(obj, 2, 0);  // entry_array_find_nth
    if (has4(p)) s->val = p->val; else s->val = 0;
    p = func_00168b38(obj, 24, 0);  // entry_array_find_nth
    if (has4(p)) func_001aadb0(p->val);
}

/* ---- 0019a610 ---- */
struct Rec5 { s16 h[5]; };
extern Rec5 D_0032bb00;
extern u8 D_0032bae0;
s32 func_001991a8(u32, u32);
void func_00104f58(void*, u32, u32, u32, u32);
union Obj5b { struct { u32 f0, f4; u16* info; } s; s16 h[6]; };

void func_0019a610(Obj5b* o, Rec5* src) {
    D_0032bb00 = *src;
    if (func_001991a8(1, o->s.info[1]) == 0) {
        u32 a = 0, b = 0;
        if (D_0032bae0 != *(u8*)src) { a = 1; b = 1; }
        func_00104f58(&D_0032bb00, a, 0, 0, b);
    }
    o->s.f4 |= 1;
}

/* ---- 0019bb98 ---- */
f32 func_0016a0a0(void*);
s32 func_001c0cd8(void*);
s32 func_0019c6f0(void*);

s32 func_0019bb98(u8* p) {
    s32 r = 0;
    if (func_0016a0a0(p) == 0.0f || (*(u32*)(p + 264) & 4) || (*(u32*)(p + 352) & 0x2000000)
        || func_001c0cd8(p) || (*(u32*)(*(u8**)(p + 12) + 8) & 4) || func_0019c6f0(p))
        r = 1;
    return r;
}

/* ---- 001c2858 ---- */
void func_001c2858(f32* o, void* a, void* b, s32 n) {  // copy_2quads_and_ratio
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(o), "r"(a) : "$8", "memory");
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(o + 4), "r"(b) : "$8", "memory");
    f32 r = o[6] / o[4];
    ((s32*)o)[14] = 0;
    ((s32*)o)[15] = 0;
    f32 s = __builtin_sqrtf((f32)n / r);
    s32 w = (s32)s;
    s32 h = (s32)(s * r);
    ((s32*)o)[12] = w;
    ((s32*)o)[13] = h;
    o[8] = o[4] / (f32)w;
    o[10] = o[6] / (f32)h;
}

/* ---- 001c7fb8 ---- */
extern void* D_00351e18[];
extern u8* D_01d49960[2];
void func_0010b978(void*);
void func_001e02a0(void*, void*);
void func_0010c7f0(void*);

void func_001c7fb8(u8* o) {
    s32 i;
    func_0010b978(o);
    *(void**)o = D_00351e18;
    *(u32*)(o + 1416) |= 0x400000;
    *(u32*)(o + 1896) &= ~0x10;
    for (i = 0; i < 2; i++) {
        if (D_01d49960[i] == 0) { D_01d49960[i] = o; break; }
    }
    if (i > 0) func_001e02a0(o + 128, D_01d49960[0] + 128);
    *(u32*)(o + 152) = 1;
    func_0010c7f0(o);
}

/* ---- 001ce1a0 ---- */
extern u32 D_00352134;
extern u32 D_00352130;
extern u32 D_01d5b9d0, D_01d5b9d4, D_01d5b9d8, D_01d5b9dc;
extern char D_0036e2c0[], D_0036e2c8[], D_0036e2d0[], D_0036e2d8[], D_0036e2e0[];
u32 func_001ce248(u32, const char*);
u32 func_001ce2a0(u32, u32, u32);

void func_001ce1a0(u32 a) {
    D_00352134 = a;
    D_01d5b9d0 = func_001ce248(2, D_0036e2c0);
    D_01d5b9d4 = func_001ce248(2, D_0036e2c8);
    D_01d5b9d8 = func_001ce248(2, D_0036e2d0);
    D_01d5b9dc = func_001ce248(2, D_0036e2d8);
    D_00352130 = func_001ce2a0(func_001ce248(2, D_0036e2e0), 0, 0);
}

/* ---- 001dde40: unlink n from the list ---- */
struct LNode { u32 used; u32 pad[4]; LNode* next; };
struct LList { LNode* head; LNode* tail; };
extern LList D_01d9e348;
s32 func_00321cb0(void*, void*);
void func_001de450(void*);

void func_001dde40(LNode* n) {
    LNode* prev;
    if (!func_00321cb0(&D_01d9e348, n)) return;
    func_001de450(n);
    if (n == D_01d9e348.head) {
        D_01d9e348.head = n->next;
        prev = 0;
    } else {
        for (prev = D_01d9e348.head; prev->next != n; prev = prev->next) ;
        prev->next = n->next;
    }
    if (n == D_01d9e348.tail) D_01d9e348.tail = prev;
    n->next = 0;
    n->used = 0;
}

/* ---- 00227950 ---- */
struct E11 { s32 kind; s32 sub; u8 off; u8 pad[3]; s32 key; u8 rest[68]; };
extern E11* D_0035dcf0;
void func_002278e0(E11*);
void func_001024a8(void*);

void func_00227950(u8* p) {
    s32 key = *(s32*)(p + 4);
    s32 i;
    for (i = 0; i < 128; i++) {
        E11* e = (E11*)(i * sizeof(E11) + (u32)D_0035dcf0);
        if (e->key == key && e->kind == 1 && e->sub == 4 && e->off == 0) func_002278e0(e);
    }
    func_001024a8(p);
}

/* ---- 0022e288 ---- */
struct E12 { u32 f0; s32 id; u32 f8; u32 fc; u8 node[36]; };
union U12 { E12* p; s32 i; };
extern U12 D_0035dcf4;
s32 func_001de568(void*);

void func_0022e288(void) {
    s32 i;
    if (!D_0035dcf4.p) return;
    for (i = 0; i < 96; i++) {
        if (D_0035dcf4.p[i].id == -1) continue;
        if (func_001de568(D_0035dcf4.p[i].node)) func_001dde40((LNode*)D_0035dcf4.p[i].node);
        D_0035dcf4.p[i].fc = 0;
        D_0035dcf4.p[i].id = -1;
    }
}

/* ---- 0023ec48: out = obj->mtx(+128) * m (VU0) ---- */
void func_0011d6c0(u32, u32, f32*);
f32* func_0023ec48(f32* out, u8* obj, u32 a2) {
    f32 m[16] __attribute__((aligned(16)));
    u8* w = obj + 128;
    func_0011d6c0(*(u32*)(obj + 48), a2, m);
    asm volatile(
        "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
        "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
        "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
        "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
        "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
        : : "r"(out), "r"(w), "r"(m) : "memory");
    return out;
}

/* ---- 0024c568 ---- */
extern void* D_0035eda8;
extern void* D_0035edac;
s32 func_002892f8(void*);
s32 func_0028acc8(void*);
void func_00288e88(void*);

void func_0024c568(void) {
    if (D_0035eda8) {
        s32 r = func_002892f8(D_0035eda8);
        if (!func_0028acc8(D_0035eda8) && r) func_00288e88(D_0035eda8);
    }
    if (D_0035edac) {
        s32 r = func_002892f8(D_0035edac);
        if (!func_0028acc8(D_0035edac) && r) func_00288e88(D_0035edac);
    }
}

/* ---- 00272538 ---- */
struct E13 { s16 a, b, v; };
extern E13 D_00373a30[];
u8* func_00257770(void);
s32 func_00287bc0(void);
s32 func_00139d78(void*);
u32 func_002570a0(s32);
s32 func_00272b60(u32);

s32 func_00272538(void) {
    s32 r = 0;
    u8* p = (u8*)func_00257770();
    s32 id = func_00287bc0();
    if (p && func_00139d78(p)) {
        s32 v = 228;
        if (id != 26 && id != 27) v = D_00373a30[func_00272b60(func_002570a0(26))].v;
        r = *(s32*)(p + 388) == v;
    }
    return r;
}

/* ---- 00282cb8 ---- */
extern s16 D_00374240[];
void* func_002811b0(u32, u32);
s32 func_00282c68(void*);
void func_00259570(s32, void*, u32, u32);
s32 func_002595e0(void);
u32 func_00192048(u32);
void func_002595e8(void*, u32);

void func_00282cb8(u8* p, s32 n) {
    if (n < 0) {
        func_002595e8(p + 4132, func_00192048(0x8448));
        return;
    }
    s32 idx;
    if (n == 0) idx = func_00282c68(func_002811b0(*(u32*)(p + 4100), *(u32*)(p + 4108)));
    else idx = D_00374240[n];
    func_00259570(idx, p + 4132, 0, 1);
    func_002595e8(p + func_002595e0() + 4132, func_00192048(0x8448));
}

/* ---- 00287a28 ---- */
void func_0028c4f8(void);
void func_0023ede8(void);
void func_00288b78(void);
void func_0023ed38(void);
void func_00287c20(void);  // clear_global_flag_return_m1
void func_00287f30(void);
struct VObj { void (**vt)(VObj*); };
extern s32 D_0035f2ec;
extern s32 D_0035f318;
extern s32 D_0035f2f0;
extern s32 D_0035f2f4;
extern VObj* D_0035f31c;
extern void* D_0035f2e8;

void func_00287a28(void) {
    func_0028c4f8();
    func_0023ede8();
    func_00288b78();
    func_0023ed38();
    D_0035f2ec = -1;
    D_0035f318 = 0;
    D_0035f2f0 = 0;
    D_0035f2f4 = 0;
    func_00287c20();  // clear_global_flag_return_m1
    if (D_0035f31c) {
        D_0035f31c->vt[4](D_0035f31c);
        D_0035f31c = 0;
    }
    func_00287f30();
    if (D_0035f2e8) func_001991a8((u32)D_0035f2e8, 0);
    D_0035f2e8 = 0;
}

/* ---- 002a9048 ---- */
s8* func_00276568(void);
struct E18 { s8 id; s8 flag; u8 pad[2]; };
struct T18 { s32 n; E18 e[1]; };
extern T18* D_0035f608;
extern void* D_0035f200;
s32 func_0028afa8(void*);
void func_0028afd0(void*, s32);  // obj_set_signed18

void func_002a9048(void) {
    s32 sel;
    if (func_00287bc0() == 35) {
        sel = 0;
    } else {
        s32 n = D_0035f608->n;
        s32 k = *func_00276568();
        s32 i;
        for (i = 0; i < n; i++) {
            if (k == D_0035f608->e[i].id && D_0035f608->e[i].flag < 0) break;
        }
        sel = i;
        if (sel >= func_0028afa8(D_0035f200)) sel = func_0028afa8(D_0035f200) - 1;
    }
    func_0028afd0(D_0035f200, sel);  // obj_set_signed18
}

/* ---- 002ad1b0 ---- */
u8* func_00294000(s32);
extern u32* D_0035f620;
s32 func_002ad1b0(s32 id) {
    s32 ok = 1;
    u8* t = func_00294000(3);
    s32 n = *(s32*)(t + 8);
    s32 i;
    u8* e = t + 16;
    for (i = 0; i < n; i++, e += 36) {
        if (id < 0 || *(s8*)e == id) {
            u16 f = *(u16*)(e + 4);
            if (!(D_0035f620[f >> 5] & (1 << (f & 31)))) { ok = 0; break; }
        }
    }
    return ok;
}

/* ---- 002b1a00 ---- */
struct E19 { u16 a; s16 b; };
extern E19 D_00374c68[];
u32* func_002b23e0(s32);  // list_entry_by_index_checked
void func_00276c50(s32, u32);

void func_002b1a00(void) {
    s32 r = -1;
    s32 cur = func_00287bc0();
    s32 i;
    for (i = 0; D_00374c68[i].a != 0; i++) {
        if (cur == D_00374c68[i].b) { r = D_00374c68[i].a; break; }
    }
    if (r == 20297) {
        if (*func_002b23e0(-1) & 0x4000000) r = 20696;
    }
    func_00276c50(r, 0);
}

/* ---- 002dda88 ---- */
void func_002cfeb0(void*, void*, u32, u32);  // obj_init_field1416_bit800
extern void* D_00362b68;
union U20 { u32 id; f32 f; };
void func_002dda88(u8* o, U20* a1, u32 a2) {
    func_002cfeb0(o, a1, 3, a2);  // obj_init_field1416_bit800
    *(u32*)o = (u32)&D_00362b68;
    *(f32*)(o + 2840) = 300.0f;
    switch (a1->id) {
    case 1636: *(s32*)(o + 2836) = 2; break;
    case 1637: *(s32*)(o + 2836) = 1; break;
    case 1638: *(s32*)(o + 2836) = 0; break;
    case 1639: *(s32*)(o + 2836) = 3; break;
    }
}

/* ---- 002e7458 ---- */
struct N23 { N23* next; };
struct L23 { N23* head; N23* tail; };
extern L23 D_01e2bf00;
static inline N23* Next23(N23* n) { if (!n) return D_01e2bf00.head; return n->next; }
static inline bool has23(N23* x) {
    N23* n = 0;
    while ((n = Next23(n))) if (n == x) return true;
    return false;
}
void f_002e7458(N23* n) asm("_Z13func_002e7458Pv");
void f_002e7458(N23* n) {
    N23* prev;
    if (!has23(n)) return;
    if (n == D_01e2bf00.head) {
        D_01e2bf00.head = n->next;
        prev = 0;
    } else {
        for (prev = D_01e2bf00.head; prev->next != n; prev = prev->next) ;
        prev->next = n->next;
    }
    if (n == D_01e2bf00.tail) D_01e2bf00.tail = prev;
    n->next = 0;
}

/* 002eae08: moved to src/anon/unit_002eae08.cpp */

/* ---- 002f13b0 ---- */
union F25 { f32 f; u8 c; };
extern F25 D_00349e10;
s32 func_001ba028(u32);  // list_contains_ptr
f32 func_0017ce10(f32);
void func_0016aeb8(u32, f32);
struct O21 { u32 f0; u32 h; f32 time; f32 dflt; f32 speed; f32 val; };
s32 func_002f13b0(O21* o) {
    if (!func_001ba028(o->h)) return 0;
    o->val += o->speed * D_00349e10.f;
    o->val = func_0017ce10(o->val);
    o->time -= D_00349e10.f;
    if (o->time <= 0.0f) {
        o->val = o->dflt;
        func_0016aeb8(o->h, o->dflt);
        return 0;
    }
    func_0016aeb8(o->h, o->val);
    return 1;
}

/* ---- 0031c0f8: destructor body ---- */
extern void* D_0034a548;
extern void* D_00347e80;
extern void* D_00347f98;
extern void* D_00347f80_v asm("D_00347f80");
void func_00239870(void*);
void func_002361d0(void*);

void func_0031c0f8(u8* o) {
    *(u32*)o = (u32)&D_0034a548;
    if (o + 840) {
        u8* p = o + 6144;
        u8* end = o + 840;
    loop:
        if (end == p) goto done;
        p -= 408;
        ((VF*)*(void**)p)[3](p);
        goto loop;
    }
done:
    func_00239870(o + 496);
    *(void**)(o + 48) = &D_00347e80;
    func_002361d0(o + 80);
    *(void**)o = *(void**)(o + 48) = &D_00347f98;
    void** m = *(void***)((u8*)D_00347f80_v + 20);
    ((void (**)(void*, void*))*m)[1](m, o);
}

/* ---- 00134030: wait for VIF1 / GIF / VU0 / IPU idle ---- */
s32 func_00134030(void) {  // poll_timer_status
    if (*(volatile u32*)0x10009000 & 0x100) {
        // spin on COP0 condition (hand-written padding)
        asm volatile("1:\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tnop\n\tbc0f 1b\n\tnop");
    }
    while (*(volatile u32*)0x10003c00 & 0x1f000003) ;
    {
        u32 s;
        do { asm volatile("cfc2 %0, $vi29" : "=r"(s)); } while (s & 0x100);
    }
    while (*(volatile u32*)0x10003020 & 0xc00) ;
    return 0;
}

/* ---- 001b2578: advance along a path once the current point is reached ---- */
static inline void vsub3(void* out, const void* a, const void* b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(out), "r"(a), "r"(b) : "memory");
}
static inline f32 vlen(const void* v) {
    f32 d;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(d) : "r"(v) : "$8", "memory");
    return d;
}
struct Path29 { u32 f0; s32 n; u32 f8; s32 idx; f32 radius; Vec128* pts; };
Vec128* func_001b2578(Path29* p, Vec128* pos) {
    Vec128 e;
    Vec128 d;
    vsub3(&d, &p->pts[p->idx], pos);
    e = d;
    if (vlen(&e) <= p->radius) p->idx = (p->idx + 1) % p->n;
    return &p->pts[p->idx];
}

/* ---- 0031f6d8: destructor body ---- */
extern void* D_00350bb0;
extern void* D_0034e8a8;
void func_00239848(void*);  // set_vtbl_36eb28_then_call
void func_001ac5b8(void*);
void func_00105110(void*);
void func_0031f6d8(u8* o) {
    *(u32*)o = (u32)&D_00350bb0;
    if (o + 1544) {
        u8* p = o + 2920;
        u8* end = o + 1544;
    loop:
        if (end == p) goto done;
        p -= 344;
        ((VF*)*(void**)p)[0](p);
        goto loop;
    }
done:
    func_00239870(o + 1200);
    func_00239870(o + 848);
    func_00239870(o + 484);
    *(void**)(o + 132) = &D_0034e8a8;
    func_00239848(o + 132);  // set_vtbl_36eb28_then_call
    func_001ac5b8(o);
    func_00105110(o);
}
}
