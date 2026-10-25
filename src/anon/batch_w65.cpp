#include "../common/types.h"

// 16-byte vector; assignment copies with a 128-bit lq/sq.
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

// 4x4 matrix of Vq rows; assignment copies 64 bytes with lq/sq.
struct Mq {
    Vq r[4];
    Mq& operator=(const Mq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
};

// Vector returned by value: copy construction is a 128-bit lq/sq.
struct Vr {
    f32 x, y, z, w;
    Vr() {}
    Vr(const Vr& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));

// Reset three fade entries (count, alpha 255) when called with (1, 0xffff).
struct FadeEnt { u32 pad[3]; u32 count; f32 alpha; };
extern FadeEnt D_004f3694;
extern FadeEnt D_004f36ec;
extern FadeEnt D_004f3744;
void wtarget_0015ccf0(u32 a, u32 b, u32 c, u32 d) {
    if (b == 0xffff && a == 1) { D_004f3694.count = 0; D_004f3694.alpha = 255.0f; }
    if (b == 0xffff && a == 1) { D_004f36ec.count = 0; D_004f36ec.alpha = 255.0f; }
    if (b == 0xffff && a == 1) { D_004f3744.count = 0; D_004f3744.alpha = 255.0f; }
}

extern "C" {
s32 YS_ITEM_Reduce(s32, s32) asm("_ZN2YS4ITEM6ReduceEii");
void SEQ_GetActiveXY(u8* p, s32* x, s32* y) asm("_ZN2YI8SEQUENCE11GetActiveXYEPiS1_");
void Sel_SetSequence(u8* p, s32 a) asm("_ZN2Tz6Select11SetSequenceEz");

s32 func_00139d78(void*);
void func_00105110(void*);
void func_0031a838(void*);

// Index of x in the 7-entry table, else 7 + secondary lookup.
extern s16 D_00345d30[];
s32 func_00114738(s32);
s32 func_001145b0(s32 x) {
    s32 i;
    for (i = 0; i < 7; i++)
        if (D_00345d30[i] == x) return i;
    return func_00114738(x) + 7;
}

// Unlink the node with this key from the list at +292 and hand it to the owner's release method.
struct Node { s32 key; u32 pad; Node* prev; Node* next; };
struct VObj { void** vt; };
void func_0011ecc8(u8* p, s32 key) {
    Node* n;
    for (n = *(Node**)(p + 292); n; n = n->next) {
        if (n->key == key) {
            if (n->prev) n->prev->next = n->next;
            else *(Node**)(p + 292) = n->next;
            if (n->next) n->next->prev = n->prev;
            VObj* o = *(VObj**)(p + 16);
            ((void (*)(VObj*, Node*))o->vt[1])(o, n);
            return;
        }
    }
}

// Constructor: base init, vtable, then collect flag bits 0 / 29 of each 32-byte entry.
struct FlagEnt { u32 f; u32 x[7]; };
struct FlagHdr { u8 pad[28]; s32 n; FlagEnt e[1]; };
void func_0011ee18(void*);  // obj_ctor_347940
extern u8 D_00347a28[];
void func_001206e0(u32* p) {
    func_0011ee18(p);  // obj_ctor_347940
    p[0] = (u32)D_00347a28;
    FlagHdr* d = (FlagHdr*)p[1];
    s32 i;
    for (i = 0; i < d->n; i++) {
        u32 m = d->e[i].f & 1;
        if (m) p[3] |= 1;
        m = d->e[i].f >> 29 & 1;
        if (m) p[3] |= 2;
    }
}

void func_00139510(void*);
void func_001b2028(u32);
void func_001991a8(s32, s32);
void func_00137630(u8* p) {
    if (*(u32*)(p + 1304)) {
        if (func_00139d78(p + 448)) func_00139510(p + 448);
        if (func_00139d78(p + 896)) func_00139510(p + 896);
        func_001b2028(*(u32*)(p + 1304));
    }
    func_001991a8(36, 0);
}

// Rebuild the cached text when the current value changes.
extern u8 D_0032bae0;
extern u32 D_00347fe8;
extern u8 D_003b8b80[];
extern u8 D_003b8bc0[];
extern char D_0036acf0[];
extern u32 D_0033caf4;
u32 func_00105ee8(u32);
void func_002fee78(void*, const char*, u32, u32);
void func_001688c8(void*);
void func_001684c0(void*, void*, s32, s32);
// 0013a600: moved to src/harata/libdk/field2dd.cpp

extern f32 D_0034a9e0;
extern f32 D_0034a9e4;
extern Vq D_0034a9c0;
extern Vq D_0034a9d0;
void func_00158b20(u8* p) {
    *(f32*)(p + 72) = D_0034a9e0;
    *(f32*)(p + 80) = D_0034a9e4;
    *(Vq*)(p + 144) = D_0034a9c0;
    *(Vq*)(p + 112) = D_0034a9d0;
}

// Pop a free 16-byte slot from the pool and initialise it.
struct Pool16 { u8 e[64][16]; s32 idx[64]; s32 n; };
extern u8* D_0034c7a0;
void func_001656d0(void*, u32, u32);
void* func_001659b8(u32 a, u32 b) {
    Pool16* s = (Pool16*)D_0034c7a0;
    void* r = s->e[s->idx[--s->n]];
    func_001656d0(r, a, b);
    return r;
}

extern u8 D_0034c7b0[];
void func_002f28b8(void*, s32, s32, s32, s32, s32, s32, s32);
void func_003058a0(s32);
void func_002f2be0(void*, u32);
void func_00166618(u32 a, s16 b, s16 c, s16 d, s16 e, s16 f, s32 i) {
    u8* s = D_0034c7b0 + i * 96;
    func_002f28b8(s, c, d >> 6, b, 0, f, d, e);
    func_003058a0(0);
    func_002f2be0(s, a);
}

extern u32 D_0034f240;
void func_00192260(u32, s32);
void func_001b8318(void);
void func_001a3a50(void);
void func_001a64c0(void);
void func_001a5970(void);
void func_001bfbd8(void);
void func_00182ab0(void);
void func_001c8838(s32);
void func_001bae08(void);
void func_00169178(void) {
    func_00192260(D_0032bae0, 1040);
    func_001b8318();
    func_001a3a50();
    if (!(D_0034f240 & 0x80000)) func_001a64c0();
    func_001a5970();
    u32 v = D_0034f240;
    if (v & 0x200) {
    } else if (v & 0x400) {
    } else {
        func_001bfbd8();
    }
    func_00182ab0();
    func_001c8838(1);
    func_001bae08();
}

Vq* func_001dc648(u32);
Vq func_0017d050(u32);
void func_0016e240(u32* p) {
    Vq* d = func_001dc648(p[0]);
    *d = func_0017d050(p[1]);
}

void func_0017c4c8(void*, Vq*);
void func_0017f488(void*, u32, f32, f32);
void func_00172158(u32* p) {
    u8* o = *(u8**)(p[0] + 4);
    Vq t;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&t), "r"(p[1]) : "$8", "memory");
    func_0017c4c8(o, &t);
    func_0017f488(o + 320, p[2], *(f32*)&p[3], 0.0f);
    if (p[4]) {
        s32 v = p[2];
        *(s32*)(o + 256) = v + 1;
        *(s32*)(o + 260) = v + 2;
    }
}

// First non-zero result of func_0019b380 over the 12-byte table entries.
struct Ent12 { u32 a, b, c; };
extern s32 D_0034ed00;
extern Ent12 D_01c60588[];
u32 func_0019b380(u32, u32);
u32 func_00182e98(u32 x) {
    s32 i;
    for (i = 0; i < D_0034ed00; i++) {
        u32 r = func_0019b380(D_01c60588[i].c, x);
        if (r) return r;
    }
    return 0;
}

s32 func_0018b198(void*);
void func_001ad9c8(void*);  // float_accumulate_clamped
void func_0016aeb8(void*, f32);
void func_001b0728(void*, void*, s32, f32);
void func_0018b110(u8* p) {
    if (!func_0018b198(p)) return;
    func_001ad9c8(p + 2592);  // float_accumulate_clamped
    func_0016aeb8(p, *(f32*)(p + 2564) + *(f32*)(p + 2568) * *(f32*)(p + 2592));
    if (func_0018b198(p)) return;
    if (*(u8*)(p + 2560)) {
        func_001b0728(p + 1184, p + 2576, 0, 20.0f);
        *(u8*)(p + 2560) = 0;
    }
}

// Destructor: drop references, unlink, release.
extern u8 D_0034ef18[];
extern u8 D_01c60cd8[];
void func_0031ee68(void*, void*);
void func_0018e040(void*);
void func_001c0058(u32);  // clear_bit_in_array
void func_001c0248(void*);
void func_0018d590(u32* p) {
    p[0] = (u32)D_0034ef18;
    if (p[2]) (*(s32*)(p[2] + 1160))--;
    if (p[4]) (*(s32*)(p[4] + 1160))--;
    func_0031ee68(D_01c60cd8, p);
    if (!(p[1] & 0x400)) {
        func_0018e040(p);
        func_001c0058(p[7]);  // clear_bit_in_array
    }
    func_001c0248(p + 12);
    func_00105110(p);
}

struct S16x2 { s16 a, b; };
struct Tbl7928 { u8 pad[7928]; S16x2 arr[1]; };
extern Tbl7928 D_0032bb30;
extern u8* D_01c61b08;
s32 func_00196388(u32, u32);
void func_001963f8(s32);
void func_001966b0(s32 i) {
    D_0032bb30.arr[i].a = -1;
    u8* e = (u8*)(i * 2 + (u32)D_01c61b08);
    s32 r = func_00196388(e[2], e[3]);
    if (r >= 0) func_001963f8(r);
}

// Remove one unit of item `a` (100 = special case).
void func_001a34e0(s32, s32);
u8* func_00188fe0(void*);
extern u8 D_0032e020[];
s32 YS_ITEM_Reduce(s32 a, s32 b) {
    if (b == 100) { func_001a34e0(a, 1); return 1; }
    u8* t = func_00188fe0(D_0032e020);
    s32 i;
    for (i = t[18] - 1; i >= 0; i--) {
        if (*(u16*)(t + 52 + i * 2) == a) { *(u16*)(t + 52 + i * 2) = 0; return 1; }
    }
    return 0;
}

extern u32 D_00350748;
extern u32 D_01c6cafc;
extern u8 D_01c6cae0[];
extern u32 D_01c6cb00[4];
extern u32 D_01c6cb10;
u32 func_001708f8(u32, s32);
u8* func_00168b38(u32, s32, s32);  // entry_array_find_nth
void func_001dddd0(void*, u32);
void func_001a3a88(void) {
    u32 v = func_001708f8(D_00350748, -1);
    D_01c6cafc = v;
    func_001dddd0(D_01c6cae0, *(u32*)(func_00168b38(v, 18, 0) + 8));
    s32 i;
    u32* q = D_01c6cb00;
    for (i = 3; i >= 0; i--) *q++ = 0;
    D_01c6cb10 = 0;
}

void func_00165768(u32);
void func_001b3018(u32* p) {
    if (p[0]) {
        s32 i;
        for (i = 0; i < *(s32*)(p[0] + 4); i++) func_00165768(*(u32*)(p[1] + i * 144 + 128));
        func_00105110((void*)p[1]);
        p[0] = 0;
    }
}

extern struct { u8 v; } D_01d48d94;
extern u8* D_01d48d90;
void func_001b89d0(void);
void func_001db610(void*, void (*)(void), s32);
void func_001b8988(u8* p, u8 v) {
    D_01d48d94.v = v;
    s32 o = *(s32*)(p + 12);
    if (o) func_001db610(D_01d48d90 + o, func_001b89d0, 0);
}

struct Ent4 { u16 id; u8 b; u8 pad; };
void func_001bc778(u32);
u8* func_001bc780(u32, u32, u32, s32);
void func_001bce90(u32 a, Ent4* e, u32 n, u32 c) {
    u32 i;
    func_001bc778(a);
    for (i = 0; i < n; i++, e++) func_001bc780(a, e->id, c, 1)[6] = e->b;
}

// Find the 16-byte entry whose first byte is `key`.
extern u8* D_01d49358;
u8* func_001c0648(u32 key) {
    u8* t = D_01d49358;
    s32 n = *(s32*)(t + 4);
    u8* e = t + 8;
    s32 i;
    for (i = 0; i < n; i++, e += 16)
        if (*e == key) return e;
    return 0;
}

extern u8 D_003525c8[];
extern u8 D_00352750[];
void func_00320400(void*);
void func_001d1678(void*, s32);  // obj_init_28bytes
void func_001d19e8(void*, s32);
void func_001d16e8(void*, s32, s32);
void func_001d4d28(u32* p) {
    p[1] = 0;
    p[0] = (u32)D_003525c8;
    p[2] = 0;
    func_00320400(p + 3);
    func_001d1678(p, -1);  // obj_init_28bytes
    p[12] = 0;
    p[0] = (u32)D_00352750;
    u8* q = (u8*)p + 57;
    s32 i;
    for (i = 127; i >= 0; i--) { *q = 0; q += 4; }
    func_001d19e8(p, -1);
    func_001d16e8(p, 0, 12);
}

extern u8 D_00352878[];
void func_001b3b70(void*, void*, s32, u32);
s32 func_0019c8a8(void*);
struct Bits1536 { u32 lo:3; u32 v:4; u32 hi:25; };
void func_001d7cd0(u8* p, u8* q, u32 c) {
    func_001b3b70(p, q, 3, c);
    *(u32*)p = (u32)D_00352878;
    *(u32*)(p + 1416) |= 0x20000;
    if (!func_0019c8a8(p)) *(s32*)(p + 944) = 2;
    ((Bits1536*)(p + 1536))->v = (*(u16*)(q + 72) >> 3 & 1) ? 2 : 1;
}

// Y-axis rotation matrix from the sine table (angle in 1/65536 turns).
extern f32 D_00359a20[];
void func_0021ea50(f32* m, u32 a) {  // table_float_pair_lookup_b
    f32 s = D_00359a20[(a >> 4) & 0xfff];
    f32 c = D_00359a20[((a + 0x4000) >> 4) & 0xfff];
    m[0] = c; m[4] = 0; m[8] = s; m[12] = 0;
    m[1] = 0; m[5] = 1.0f; m[9] = 0; m[13] = 0;
    m[2] = -s; m[6] = 0; m[10] = c; m[14] = 0;
    m[3] = 0; m[7] = 0; m[11] = 0; m[15] = 1.0f;
}

// Store a copy of the 40-byte record in the first free (-1) slot.
struct Rec40 { s32 id; u8 b[36]; };
extern Rec40* D_0035dcfc;
void func_00227da8(Rec40* src) {
    s32 i;
    for (i = 0; i < 96; i++) {
        if (D_0035dcfc[i].id == -1) { D_0035dcfc[i] = *src; return; }
    }
}

void func_0023a0d8(void*);
void SEQ_GetActiveXY(u8* p, s32* x, s32* y) {
    if (!p[212]) func_0023a0d8(p);
    *x = *(s32*)(p + 228);
    *y = *(s32*)(p + 232);
}

u32 func_002efa40(u32);
extern volatile u32 D_0035ecb8;
s32 func_002421e8(u8* p) {
    s32 r = 0;
    if (func_002efa40(*(u32*)(p + 4)) || (u8)(D_0035ecb8 & 1)) r = 1;
    return r;
}

void func_00258d40(u32, u32);
void func_00258d58(u32, u32, u32);
void func_00258d78(u32 a, u32 b, u32 c, u32 d) {
    func_00258d40(a, c);
    func_00258d58(a, b, d);
}

void func_00138c10(void*, s32);
void Sel_SetSequence(u8* p, s32 a) {
    if (!func_00139d78(p)) return;
    if (*(s32*)(p + 388) != a) {
        func_00138c10(p, a);
        *(s32*)(p + 392) = -1;
    }
}

void func_00290488(VObj** p) {
    if (p[0] && func_00139d78(p[0])) ((void (*)(VObj*))p[0]->vt[5])(p[0]);
    if (p[1] && func_00139d78(p[1])) ((void (*)(VObj*))p[1]->vt[5])(p[1]);
}

s32 func_00253b00(void);  // get_global_ptr_1dae6c0
s32 func_00253b18(void);
void func_00292a58(void);
extern s32 D_0035f4c8;
extern s32 D_0035f4cc;
extern s32 D_0035f4c0;
extern s32 D_0035f4bc;
extern s16 D_0035f4e0;
extern s16 D_0035f4d8;
extern u8 D_0035f4e2;
extern s32 D_0035f4d0;
void func_00292870(void) {
    D_0035f4c8 = func_00253b00();  // get_global_ptr_1dae6c0
    D_0035f4cc = func_00253b18();
    D_0035f4d0 = D_0035f4cc / D_0035f4c0;
    if (D_0035f4d0 > D_0035f4bc) D_0035f4d0 = D_0035f4bc;
    D_0035f4cc = 0;
    D_0035f4d8 = 0;
    D_0035f4e0 = 0;
    D_0035f4e2 = 0;
    func_00292a58();
}

// Step the selection up/down (wrapping) among the entries flagged 0x2000000.
struct Ent36 { u32 f; u32 r[8]; };
extern u32* D_0035f630;
s32 func_00276608(s32);
void func_002765e8(s32, s32, s32);
void func_002b1208(u32 a) {
    s32 n = 0;
    Ent36* e = (Ent36*)D_0035f630;
    s32 i;
    for (i = 0; i < 10; i++, e++) {
        if (e->f & 0x2000000) n++;
    }
    s32 v = func_00276608(28);
    v = (a & 0x10000) ? v + 1 : v - 1;
    if (v < 0) v = n - 1;
    else if (v >= n) v = 0;
    func_002765e8(28, v, 0);
}

extern u32 D_003616f8[];
void func_002bc470(u32);
struct Ent12b { u32 a; s32 b; u32 c; };
void func_002bce50(u8* p) {
    p[336] = 0;
    *(s32*)(p + 328) = 30;
    *(s32*)(p + 332) = 20;
    Ent12b* e = (Ent12b*)p;
    u32* s = D_003616f8;
    s32 i;
    for (i = 26; i >= 0; i--) {
        e->a = *s;
        e->b = -1;
        e->c = 0;
        func_002bc470(*s);
        e++;
        s++;
    }
}

void func_002e7108(u32, f32);
Mq func_002e71a0(u32, u32, s32);
void func_002e24e0(u8* p) {
    Mq* d = (Mq*)(p + 176);
    func_002e7108(*(u32*)(p + 108), *(f32*)(p + 260));
    *d = func_002e71a0(*(u32*)(p + 108), *(u8*)(*(u32*)(p + 100) + 8), 1);
    asm volatile("lqc2 $vf1, 48(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 48(%0)" : : "r"(d), "r"(p + 240) : "memory");
}

u32 func_001dc9e0(u32);
Vq* func_001dc5f8(u32);
void func_002e9610(Vq* a, Vq* b) {
    a[0] = *b;
    a[2] = *b;
    u32 o = *(u32*)((u8*)a + 60);
    if (o && func_001dc9e0(o)) *func_001dc5f8(*(u32*)((u8*)a + 60)) = *b;
}

// 002ee730: moved to src/menu/tutorial_widget.cpp

extern u8 D_00347f98[];
extern u8 D_00347e60[];
extern u8 D_00347dd0[];
extern u8 D_00347e80[];
void func_00239700(void*);
void func_002361a0(void*);
void func_0031a350(u32* p) {
    p[0] = (u32)D_00347f98;
    func_0031a838(p + 3);
    p[0] = (u32)D_00347e60;
    func_00239700(p + 6);
    p[102] = 0;
    p[115] = 0;
    p[0] = (u32)D_00347dd0;
    p[112] = (u32)D_00347e80;
    func_002361a0(p + 120);
    p[224] = (u32)D_00347e60;
    p[227] = 0;
    func_00239700(p + 230);
}

u32 func_0016bc20(u32, s32, s32);
Vr func_0016bda8(u32);
struct Lookup32 { u32 a, b, c, d; Vr v; Lookup32() { d = 0; } };
void func_0018a818(Lookup32*, u32, u32);
Vr func_0016c2b0(u32 a) {
    Lookup32 t;
    u32 r = func_0016bc20(a, 17, -1);
    if (r) {
        func_0018a818(&t, a, r);
        return t.v;
    }
    return func_0016bda8(a);
}

// Assertion "pMng"-style failure prints the message and file/line, then breaks.
extern char D_0036e978[];
extern char D_0036ef28[];
extern char D_0036e998[];
extern char D_0036e9d0[];
u32 func_002fdfc8(const char*, ...);  // device_vprintf_va
u32 func_001e3690(void*);
void func_001e8048(void*, u32, s32);
s32 func_001e6c40(u8* p, u32 a, u32 b, u32 c, f32 f) {
    *(u32*)(p + 136) = a;
    p[147] = b;
    *(u32*)(p + 148) = c;
    *(f32*)(p + 164) = f;
    *(u32*)(p + 160) = 0;
    u32 r = func_001e3690(p);
    if (!r) {
        func_002fdfc8(D_0036e978, D_0036ef28);  // device_vprintf_va
        func_002fdfc8(D_0036e998, D_0036e9d0, 2563);  // device_vprintf_va
        asm volatile("break");
        return 0;
    }
    func_001e8048(p, r, 1);
    return 1;
}

// Cubic interpolation between key pairs a[i..i+1] / b[i..i+1] at fractional t (VU0).
extern Vq D_003590d0;
void func_00201b30(Vq* o, Vq* a, Vq* b, f32 t) {
    s32 i = (s32)t;
    a += i;
    b += i;
    D_003590d0.z = t - (f32)i;
    asm volatile(".set noreorder\n\t"
        "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 0(%2)\n\tlqc2 $vf4, 16(%2)\n\tlqc2 $vf5, 0(%3)\n\t"
        "vsub.xyzw $vf10, $vf4, $vf3\n\tvmuly.xyzw $vf11, $vf3, $vf5y\n\tvmulx.xyzw $vf12, $vf3, $vf5x\n\tvsub.xyzw $vf13, $vf2, $vf1\n\t"
        "vmulz.xyzw $vf10, $vf10, $vf5z\n\tvadd.xyzw $vf11, $vf11, $vf4\n\tvadd.xyzw $vf10, $vf10, $vf12\n\tvsub.xyzw $vf13, $vf13, $vf11\n\t"
        "vmulz.xyzw $vf10, $vf10, $vf5z\n\tvadd.xyzw $vf10, $vf10, $vf13\n\tvmulz.xyzw $vf10, $vf10, $vf5z\n\tvadd.xyzw $vf10, $vf10, $vf1\n\t"
        "sqc2 $vf10, 0(%0)\n\t.set reorder"
        : : "r"(o), "r"(a), "r"(b), "r"(&D_003590d0) : "memory");
}

extern u8 D_00361e38[];
extern u8 D_0035eb98[];
extern union { u32* v; u8 c; } D_00361e28;
void func_002369a0(void*);  // obj_ctor_36eac8
void func_0023c008(void*);  // obj_ctor_36eae8
void func_0028d140(void*);
void func_00167f38(s32);
void func_002c5f48(void);
void func_002ca170(u32* p) {
    p[7] = (u32)D_00347f98;
    p[0] = (u32)D_00361e38;
    p[3] = 0;
    p[6] = 0;
    func_0031a838(p + 10);
    p[7] = (u32)D_0035eb98;
    func_002369a0(p + 13);  // obj_ctor_36eac8
    func_0023c008(p + 19);  // obj_ctor_36eae8
    p[47] = 0;
    func_0028d140(p + 48);
    p[159] = 0;
    p[160] = 0;
    p[161] = 0;
    p[162] = 0;
    D_00361e28.v = p;
    func_00167f38(3);
    func_002c5f48();
}
}
