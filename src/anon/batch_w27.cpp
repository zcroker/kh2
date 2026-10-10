#include "../common/types.h"

extern "C" {

// An empty-destructor local keeps a cleanup pending, which stops gcc from
// turning the final call into a sibling call (as in the game's destructors).
struct NoTail { ~NoTail() {} };

void wtarget_00102c90(u32, u32, u32, u32) asm("_Z16wtarget_00102c90jjjj");
void wtarget_0016c640(u32, u32, u32, u32) asm("_Z16wtarget_0016c640jjjj");
void wtarget_001954a0(u32, u32, u32, u32) asm("_Z16wtarget_001954a0jjjj");
void u_call0_001d3b68(void) asm("_Z16u_call0_001d3b68v");
void u_call4_002908f0(u32, u32, u32, u32) asm("_Z16u_call4_002908f0jjjj");

struct S102c90 {
    void* vt;
    u32 f4;
    u8 f8;
    u8 pad9[11];
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f32;
    u32 f36;
    u32 f40;
};
extern S102c90 D_0032b968;
extern u32 D_0032b930;
void wtarget_00102c90(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_0032b968.vt = &D_0032b930;
        D_0032b968.f4 = 0;
        D_0032b968.f8 = 70;
        D_0032b968.f20 = a;
        D_0032b968.f24 = 0x1fbd0;
        D_0032b968.f28 = 0;
        D_0032b968.f32 = 0;
        D_0032b968.f36 = 0;
        D_0032b968.f40 = 14336;
    }
}

struct Entry108930 { u32 mask; u32 data; };
void* func_00108930(u8* p, s32 bit) {  // test_bit_of_field44
    Entry108930* e = *(Entry108930**)(p + 44);
    if (e != 0 && bit >= 0 && bit < 32) {
        u32 m = 1 << bit;
        for (Entry108930* q = e; q->mask != 0; q++) {
            if (q->mask & m) return &q->data;
        }
    }
    return p + 4;
}



f32 func_0013fd10(void*);
void func_0013fd78(void*);
void func_0013fec0(u8* p) {
    *(f32*)(p + 80) = func_0013fd10(p);
    func_0013fd78(p);
    u8* d = p + 16;
    u8* s = p + 96;
    if (d != s) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    }
}



void func_0013a6d0(void);
u8* func_00102c18(u32, u32, void*);
void func_0014a830(void);
void func_0014ae10(void);
void func_0013a9e8(u32);
void func_002bea00(void);
void func_0014a188(void) {
    func_0013a6d0();
    u8* r = func_00102c18(0, 0x124f8, (void*)func_0014a830);
    r[4] = 0;
    func_0014ae10();
    func_0013a9e8(1);
    func_002bea00();
}

s32 func_00163268(f32* a, f32* b, f32* out) {
    u32 t[4] __attribute__((aligned(16)));
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(t), "r"(a), "r"(b) : "memory");
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0" : "=f"(d) : "r"(t) : "$8", "memory");
    *out = d;
    if (d <= a[4]) return 1;
    return 0;
}

void* func_001b9bc8(void*);
s32 func_0016a070(void*);
void* func_0016b800(s32 id) {
    void* p = 0;
    while ((p = func_001b9bc8(p)) != 0) {
        if (func_0016a070(p) == id) return p;
    }
    return p;
}

void func_0016c5a0(void*, u32);
void wtarget_0016c640(u32 a, u32, u32, u32) {
    void* p = 0;
    while ((p = func_001b9bc8(p)) != 0) {
        func_0016c5a0(p, a);
    }
}

void func_0016af58(void*, u32);
extern u32 D_01c5f480[4];
void func_00171518(u32** p) {
    u32 t[4] __attribute__((aligned(16)));
    func_0016af58(t, (*p)[1]);
    u32* d = D_01c5f480;
    if (d != t) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(t) : "$8", "memory");
    }
    *p = d;
}

void func_0016b010(void*, void*);  // obj_set_float1644_from_pair
void func_00198690(void*);
void func_00175b68(void** o) {
    u32 t[4] __attribute__((aligned(16)));
    if ((*(s32 (**)(void*))(*(u8**)o + 132))(o)) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(t), "r"((u8*)o + 16) : "$8", "memory");
        func_0016b010(o, t);  // obj_set_float1644_from_pair
    }
    func_00198690(o);
}

s32 func_00195530(void*);
s32 func_00195468(void*, u32);
void wtarget_001954a0(u32 a, u32 b, u32, u32) {
    u8* p = (u8*)a;
    if (func_00195530(p) == 0) {
        s32 i = func_00195468(p, 0);
        if (i >= 0) *(u16*)(p + i * 2 + 8) = b;
    }
}

struct Pair196618 { u8 a, b; };
struct Tbl196618 { u16 count; Pair196618 e[1]; };
extern Tbl196618* D_01c61b08;
s32 func_00196618(s32 a, s32 b) {
    for (s32 i = 0; i < D_01c61b08->count; i++) {
        if (D_01c61b08->e[i].a == a && D_01c61b08->e[i].b == b) return i;
    }
    return -1;
}

s32 func_0019c090(void*);  // obj_is_enabled
s32 func_0019c0f8(u8* p) {
    s32 r = 0;
    if (func_0019c090(p)) {  // obj_is_enabled
        if (!(*(u32*)(p + 352) & 0x20)) {
            u32 m = *(u32*)(*(u8**)(p + 12) + 8) & 0x200;
            r = m == 0;
        }
    }
    return r;
}

void func_00190128(void*);
void func_0019ca20(void*);
extern void* D_00350444;
void func_0019c8d0(u32* p) {
    p[0] = 0;
    func_00190128(p + 1);
    p[6] = 0;
    p[8] = 0;
    p[11] = 0;
    func_0019ca20(p);
    D_00350444 = D_00350444 ? D_00350444 : p;
}

s32 func_0019d4a8(void*);
void func_002c0688(u32, void*);
void func_0015a638(void*, void*);
void func_0019d438(u8* p) {
    if (func_0019d4a8(p)) {
        func_002c0688(*(u32*)(p + 40), p + 4);
    } else {
        func_0015a638(p + 4, p + 4);
    }
}

u8* func_001a80c8(void);  // table24_find_by_id
s32 func_001a67b0(u32);
s32 func_001a3820(void) {
    u8* r = func_001a80c8();  // table24_find_by_id
    switch (r[2]) {
    case 0: return *(u16*)(r + 16);
    case 18: return func_001a67b0(*(u16*)(r + 4));
    }
    return 0;
}

void func_00239700(void*);
u32 func_001ab810(void);  // get_global_1c7cec0
u32 func_001ab800(void);
void func_00239988(void*, u32, u32);
void func_001ac208(u32* p) {
    p[0] = 0;
    func_00239700(p + 3);
    u32 a = func_001ab810();  // get_global_1c7cec0
    u32 b = func_001ab800();
    func_00239988(p + 3, a, b);
}

s32 func_001bb4a0(void);
u8* func_001bbcb0(void);
s32 func_001bc130(void) {
    s32 r = 0;
    if (func_001bb4a0() == 0) goto yes;
    {
        u8 f = (*(u16*)(*(u8**)(func_001bbcb0() + 8) + 4) >> 2) & 1;
        if (!f) goto out;
    }
yes:
    r = 1;
out:
    return r;
}

void func_001dca30(u32, u32, u32);  // obj_set48_52_flag40000
void func_001c16a0(u32* p, u32 x) {
    switch (p[1]) {
    case 0: func_001dca30(p[0], p[12], x); break;
    case 1: func_001dca30(p[0], p[12], x); break;
    }
}

extern f32 D_00349e10;
void func_001d2180(void*);
s32 func_001d21c0(u8* p) {
    if (*(f32*)(p + 60) > 0.0f) {
        f32 n = *(f32*)(p + 60) - D_00349e10;
        *(f32*)(p + 60) = n;
        if (n <= 0.0f) { func_001d2180(p); return 0; }
    }
    return 1;
}

struct Lerp1d3000 { u8 pad[240]; f32 hiVal; f32 loVal; f32 hi; f32 lo; };
extern Lerp1d3000* D_00352130;
f32 func_001d3000(f32 x) {
    Lerp1d3000* t = D_00352130;
    if (x >= t->hi) return t->hiVal;
    if (x <= t->lo) return t->loVal;
    x -= t->lo;
    f32 r = x / (t->hi - t->lo);
    return t->loVal + (t->hiVal - t->loVal) * r;
}

void func_001d3878(void*);
void func_00105110(void*);
extern u8* D_01d5ba20;
void u_call0_001d3b68(void) {
    u8* n = D_01d5ba20;
    while (n != 0) {
        u8* next = *(u8**)(n + 48);
        if (n != 0) {
            func_001d3878(n);
            func_00105110(n);
        }
        n = next;
    }
}

s32 func_001d3f38(u8* p) {  // type_is_282_344_484
    switch (*(u16*)(p + 40)) {
    case 282:
    case 344:
    case 484:
        return 0;
    }
    return 1;
}

void func_00106420(void*);


void func_002f3f88(void*, void*);  // memcpy16
extern u32 D_00354bc0;
extern u32 D_00354be0;
void func_00209e80(u8* a, u8* b) {
    NoTail g;
    u8* s = a + *(s32*)(*(u8**)(b + 12) + 4);
    func_002f3f88(s + 224, &D_00354bc0);  // memcpy16
    func_002f3f88(s + 240, &D_00354be0);  // memcpy16
}

extern u8 D_0035daec;
extern u8 D_0035daed;
s32 func_00225a68(void);
s32 func_00225aa8(void) {
    s32 r = 0;
    if (D_0035daec || D_0035daed || func_00225a68()) r = 1;
    return r;
}



struct S6 { u8 b[6]; };
extern S6 D_00372160[];
extern S6 D_00372178[];
extern u32 D_0035edf4;
void func_0024dfe0(void);
S6* func_0024e008(s32 i) {
    func_0024dfe0();
    if (D_0035edf4 == 0) return &D_00372160[i];
    return &D_00372178[i];
}

extern s16 D_003726b8[];
s32 func_00253380(s32 x) {
    s32 r = 0;
    for (s32 i = 0; D_003726b8[i] >= 0; i++) {
        if (D_003726b8[i] == x) { r = 1; break; }
    }
    return r;
}

u32 func_0023aa18(void*);
u32 func_0023aa38(void*);
void func_0028eab8(u8* d, u8* s) {
    u8* q = s + 24;
    *(u32*)(d + 36) = func_0023aa18(q);
    *(u32*)(d + 40) = func_0023aa38(q);
}

void func_00290a60(void*);
void func_00106450(void*);
void u_call4_002908f0(u32 a, u32, u32, u32) {
    u8* p = (u8*)a;
    if (p[16]) func_00290a60(p);
    *(u32*)(p + 4) = 0;
    if (*(void**)(p + 20)) {
        func_00106450(*(void**)(p + 20));
        *(void**)(p + 20) = 0;
    }
}

extern u8 D_0035f590;
extern u8 D_0035f591;
extern void** D_0035f58c;
void func_00295810(void) {
    D_0035f590 = 0;
    D_0035f591 = 0;
    if (D_0035f58c) {
        (*(void (**)(void*))(*(u8**)D_0035f58c + 4))(D_0035f58c);
        D_0035f58c = 0;
    }
}

u8* func_002a9d68(void);
void func_002aab90(u32 n) {
    u32* arr = (u32*)(func_002a9d68() + 132);
    u32 i = n >> 5;
    n &= 31;
    u32 v = arr[i];
    if (!(v & (1 << n))) arr[i] = v | (1 << n);
}

void func_00185ed8(void*, u32, u32, u32);
extern u32 D_00361810;
void func_002be770(u8* p, u32 a, u32 b) {
    func_00185ed8(p, a, 4, b);
    *(void**)p = &D_00361810;
    *(u32*)(p + 1416) |= 0x40000000;
}

extern u32 D_00361a50;
extern u8* D_0034e948;
void func_001c11a8(u32);
void func_00197780(void);
void func_00197cc0(void);
void func_00139858(u32);
void func_002bfaf0(void) {
    D_00361a50 = 0;
    func_001c11a8(12);
    u8* t = *(u8**)(D_0034e948 + 2880);
    *(u32*)(t + 44) &= ~1;
    func_00197780();
    func_00197cc0();
    func_00139858(201);
}

extern u32 D_00361f70;
extern u32 D_00361f60;
void func_002cf3f8(void*);
void func_002ceaa8(u8* p) {
    *(void**)p = &D_00361f70;
    func_002cf3f8(p);
    D_00361f60 = 0;
    p[88] = 0;
    func_00105110(p);
}

extern u32 D_0034ee08;
void func_0019f9a8(void*);  // array8_free_slots
void func_001c0248(void*);
void func_00319fb0(void*);  // big_obj_dtor
void func_002cffe0(u8* p) {
    NoTail g;
    *(void**)p = &D_0034ee08;
    func_0019f9a8(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    func_00319fb0(p);  // big_obj_dtor
}

extern u32 D_003625a8;
void func_002e70b0(void*);
void func_002cea28(void*);
void func_002d7338(u8* p) {
    NoTail g;
    *(void**)p = &D_003625a8;
    void* c = *(void**)(p + 160);
    if (c) {
        func_002e70b0(c);
        func_00106420(c);
    }
    func_002cea28(p);
}

extern u32 D_003625e0;
void func_002d0ea8(void*);
void func_002d9730(u8* p) {
    func_002d0ea8(p);
    *(void**)p = &D_003625e0;
    *(u32*)(p + 3056) = 0;
    *(u32*)(p + 3060) = 0;
    p[3068] = 1;
    *(u32*)(p + 3072) = 0;
    p[3076] = 1;
    *(u32*)(p + 3216) = 0;
    *(u32*)(p + 3220) = 0;
    *(u32*)(p + 3224) = 0;
}

void func_0018c258(void*, u32);
extern u32 D_01e2be20[4];
void func_002e37c0(u32** p) {
    u32 t[4] __attribute__((aligned(16)));
    func_0018c258(t, (*p)[1]);
    u32* d = D_01e2be20;
    if (d != t) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(t) : "$8", "memory");
    }
    *p = d;
}

// 4x4 matrix transpose (MMI): d = transpose(s).
void func_002f3dd8(void* d, void* s) {
    asm volatile(
        "lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
        "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
        "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\tpcpyud $11, $13, $15\n\t"
        "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
        : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
}

// strstr
char* func_002ff918(char* s, char* sub) {
    if (*s == 0) return *sub ? 0 : s;
    for (;;) {
        s32 i = 0;
        for (;;) {
            if (sub[i] == 0) return s;
            if (sub[i] != s[i]) break;
            i++;
        }
        s++;
        if (*s == 0) return 0;
    }
}



extern u32 D_0035eb98;
extern u32 D_00347f98;
void func_0023c098(void*);  // set_vtbl_36eae8_then_call
void func_002369f0(void*);  // set_vtbl_36eac8_then_call
void func_0023ee68(void*);
void func_0031cdd8(u8* p) {
    *(void**)p = &D_0035eb98;
    func_0023c098(p + 48);  // set_vtbl_36eae8_then_call
    func_002369f0(p + 24);  // set_vtbl_36eac8_then_call
    *(void**)p = &D_00347f98;
    func_0023ee68(p);
}

void func_0031f340(u8* p) {
    *(void**)p = &D_0034ee08;
    func_0019f9a8(p + 2568);  // array8_free_slots
    func_001c0248(p + 2640);
    func_00319fb0(p);  // big_obj_dtor
    func_00105110(p);
}

}
