#include "../common/types.h"

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

extern "C" {
void wtarget_00103080(u32, u32, u32, u32) asm("_Z16wtarget_00103080jjjj");
u8* wtarget_001337f0(u32, u32, u32, u32) asm("_Z16wtarget_001337f0jjjj");
void wtarget_00167658(u32, u64, u32, u32) asm("_Z16wtarget_00167658jjjj");
u32 ctarget_001d9148(u32, u32, u32, u32) asm("_Z16ctarget_001d9148jjjj");
u32 cache_buff_alloc(const char*, s32) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");

void func_001398d0(u32);
void func_001397d8(u32);
void func_0014b5e8(u32, u32, u64);
void func_001666d0(void*, u16, u32, u16, u16);
Q16* func_0016c028(u32);  // obj_get_attach_or_alt
u8* func_001ce328(u16);
u8* func_00170240(const char*, s32);
void func_00170e58(void);
void func_001850a0(Q16*, u32);
void func_0013ddc0(s32, void*);
void func_001758b0(void*);
void func_00196698(u32);
s32 func_00196388(u8, u8);
void func_001963f8(s32);
u32 func_0019bad8(void*);
void func_00190128(void*);
void func_0019ca20(void*);
void func_0019ec88(void*);
void func_0019ed48(void*);
void func_0019ec68(void);
void func_00102c18(u32, u32, void (*)(void));
void func_00239700(void*);
u32 func_001ab810(void);  // get_global_1c7cec0
u32 func_001ab800(void);
void func_00239988(void*, u32, u32);
void* func_001b9bc8(void*);
u32 func_001c0cd8(void*);
void func_001c0e60(void*);
void func_001d7cd0(void*);
void func_002fee78(void*, const char*, u32, void*);
void func_0016ed50(u32, s32, u32);
u32 func_001bb4a0(void);
u8* func_001bbcb0(void);
u32 func_00321cb0(void*, void*);
void func_001dde40(void*);
u32 func_0022b688(u32);
void func_001391a8(u32, Q16*);  // vec_copy_at416_if_diff
void func_002251c8(u32);
u32 func_001058e8(void);
void func_002fdd68(u32, u32, u32);
void func_0028d188(void*);
u32 func_001a80c8(u32);  // table24_find_by_id
u8* func_001a8190(u32);
u8* func_002a9d68(void);
void func_00185ed8(void*, u32, u32, u32);
void func_001c11a8(u32);
void func_00197780(void);
void func_00197cc0(void);
void func_00139858(u32);
void func_002e70b0(void*);
void func_00106420(void*);
u8 func_002cea28(void*);
void func_0016c2b0(Q16*, u32);
s32 func_002ffd00(void*, u32, u32);  // fprintf_stream_va
void func_0023c098(void*);  // set_vtbl_36eae8_then_call
void func_002369f0(void*);  // set_vtbl_36eac8_then_call
void func_0023ee68(void*);
void func_0019f9a8(void*);  // array8_free_slots
void func_001c0248(void*);
void func_00319fb0(void*);  // big_obj_dtor
void func_00105110(void*);

struct S32b9a0 { void* vt; u32 f4; u8 f8; u8 pad[11]; u32 f14; u32 f18; u32 f1c; u32 f20; u32 f24; u32 f28; };
extern S32b9a0 D_0032b9a0;
extern u8 D_0032b930[];
struct G347 { u8 pad[0x20]; u32 f20; u8 p2[0xc]; u32 f30; u32 f34; u8 p3[0x29c0 - 0x38]; u32 f29c0; u32 f29c4; u32 f29c8; };
union G347Ptr { G347* p; u32 w; };
extern G347Ptr D_00347d64;
extern void* D_00350444;
extern u8 D_00350448[];
extern u8* D_01c61b08;
extern Q16 D_01c5f480;
extern Q16 D_01e2be20;
extern u8 D_00351468[];
extern u8 D_01d5ba30[];
extern char D_0036e448[];
extern u32 D_0033caf0;
extern u8 D_01d9e348[];
extern u32 D_0035ec90;
extern u16 D_0035ef70;
extern u8 D_00347e60[];
extern u8 D_0035f420[];
extern u8 D_0035f5a8;
extern u8 D_0035f5a9;
extern u8* D_0035f5a4;
extern u8 D_00361810[];
extern u32 D_00361a50;
extern u8* D_0034e948;
extern u8* D_00361f60;
extern u8 D_00362dc8[];
extern u32 D_00365c48;
extern u8 D_0035eb98[];
extern u8 D_00347f98[];
extern u8 D_0034ee08[];

// Initialise a fixed descriptor when called with (1, 0xffff).
void wtarget_00103080(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_0032b9a0.vt = D_0032b930;
        D_0032b9a0.f28 = 0x1000;
        D_0032b9a0.f1c = 0;
        D_0032b9a0.f8 = 0x54;
        D_0032b9a0.f20 = 0;
        D_0032b9a0.f18 = 0x1fbd0;
        D_0032b9a0.f14 = a;
        D_0032b9a0.f24 = 0;
        D_0032b9a0.f4 = 0;
    }
}

// Append a packet header of n quadwords to a packet cursor; returns its payload.
struct Pk { u16 h0; u8 b2; u8 b3; u32 f4; u32 f8; u32 fc; };
union PkCursor { Pk* p; u32 w; u16 h; };
u8* wtarget_001337f0(u32 a, u32 n, u32 c, u32) {
    PkCursor* cur = (PkCursor*)a;
    cur->p->b2 = 0;
    cur->p->f8 = c;
    cur->p->fc = n | 0x50000000;
    cur->p->b3 = 0x10;
    cur->p->f4 = 0;
    cur->p->h0 = n;
    u8* v = (u8*)cur->p;
    cur->p = (Pk*)(v + n * 16 + 16);
    return v + 16;
}

void func_00138140(void) {
    func_001398d0(13);
    func_001397d8(13);
    G347* p = D_00347d64.p;
    p->f20 = 1;
    p->f30 = 0;
    p->f34 = 0;
    G347* q = D_00347d64.p;
    q->f29c0 = 1;
    q->f29c4 = 0;
    q->f29c8 = 0;
}

void func_0014b468(u32 a, u16 x, u16 y) {
    func_0014b5e8(a, 0x80008, (u64)(s32)(x * 16 + 8) | ((u64)(s32)(y * 16 + 8) << 16));
}

void func_0014db78(u8* p, u16 a, u32 b, u16 c, u16 d, u16 e, u32 f) {
    func_001666d0(p, a, b, c, d);
    *(u16*)(p + 0x1d4) = e;
    *(u32*)(p + 0x1d0) = f;
}

// Clamp p[0] towards p[2] in the direction of p[1]; returns 0 once clamped.
u32 func_0014f068(f32* p) {
    if (p[1] >= 0.0f) {
        if (p[2] <= p[0]) { p[0] = p[2]; return 0; }
    } else {
        if (p[0] <= p[2]) { p[0] = p[2]; return 0; }
    }
    return 1;
}

void wtarget_00167658(u32 a, u64 m, u32, u32) {
    u64* p = (u64*)a;
    p[0] &= m;
    p[1] &= m;
    p[2] &= m;
    p[3] &= m;
    *(u32*)(a + 64) = 0;
    asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(a + 32) : "memory");
    asm volatile(".set noreorder\n\tvsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(a + 48) : "memory");
}

Q16* func_0016c508(Q16* out, u8* o) {
    QCOPY(out, func_0016c028((u32)o));  // obj_get_attach_or_alt
    u8* f = func_001ce328(*(u16*)(*(u8**)(o + 8) + 0x4e));
    ((f32*)out)[1] -= *(f32*)(f + 0x30);
    return out;
}

static inline bool cache_header_full(u8* h) { return *(s32*)(h + 0x28) >= 10000; }
u32 cache_buff_alloc(const char* name, s32 n) {
    u8* h = func_00170240(name, n);
    if (h == 0 || cache_header_full(h)) func_00170e58();
    (*(u16*)(h + 2))++;
    return *(u32*)(h + 0x30);
}

void func_00171418(u8** p) {
    Q16* v = func_0016c028(*(u32*)(*p + 4));  // obj_get_attach_or_alt
    if (v != &D_01c5f480) QCOPY(&D_01c5f480, v);
    *p = (u8*)&D_01c5f480;
}

void func_00172890(u8** p) {
    Q16 t;
    func_001850a0(&t, *(u32*)(*p + 4));
    if (&t != &D_01c5f480) QCOPY(&D_01c5f480, &t);
    *p = (u8*)&D_01c5f480;
}

void func_0017dbb8(u8* p) {
    if (!(*(u32*)(p + 0x588) & 0x400000)) {
        s32 t = *(s32*)(p + 0xb48);
        if (t < 2) func_0013ddc0(t + 1, p);
    }
    func_001758b0(p);
}

void func_00196710(u32 i) {
    func_00196698(i);
    u8* e = (u8*)(i * 2) + (u32)D_01c61b08;
    s32 r = func_00196388(e[2], e[3]);
    if (r >= 0) func_001963f8(r);
}

// Find the entry with the given id (any entry when id < 0) in a variable-size list.
u8* func_0019b328(u8* p, s32 id) {
    u16* e = *(u16**)(p + 0x2c);
    for (s32 i = 0; i < *(u16*)(*(u8**)(p + 8) + 8); i++) {
        if (id < 0 || e[0] == id) return (u8*)e;
        e = (u16*)((u8*)e + e[1] * 12 + 8);
    }
    return 0;
}

u32 func_0019c838(u8* p) {
    u32 r = 0;
    if (func_0019bad8(p) || (*(u32*)(p + 0x588) & 0x8000000)) {
        u32 m = *(u32*)(p + 0x108) & 0x80;
        r = m == 0;
    }
    return r;
}

void func_0019c920(u8* p) {
    *(u32*)p = 0;
    func_00190128(p + 4);
    *(u32*)(p + 0x18) = 0;
    *(u32*)(p + 0x20) = 0;
    *(u32*)(p + 0x2c) = 0;
    func_0019ca20(p);
    D_00350444 = D_00350444 ? D_00350444 : p;
}

void func_0019ec20(void) {
    func_0019ec88(D_00350448);
    func_0019ed48(D_00350448);
    func_00102c18(1, 0xa410, func_0019ec68);
}

void func_001ac258(u8* p) {
    *(u32*)p = 0;
    func_00239700(p + 12);
    u32 a = func_001ab810();  // get_global_1c7cec0
    func_00239988(p + 12, a, func_001ab800());
}

void func_001c1060(void) {
    void* p = 0;
    while ((p = func_001b9bc8(p)) != 0) {
        if (func_001c0cd8(p)) func_001c0e60(p);
    }
}

void func_001c2c98(u8* p) {
    func_001d7cd0(p);
    *(void**)p = D_00351468;
    *(u32*)(p + 0x588) |= 0x200000;
    *(u32*)(p + 0xabc) |= 4;
}

u8* func_001d3f98(u8* p) {
    func_002fee78(D_01d5ba30, D_0036e448, D_0033caf0, p + 4);
    return D_01d5ba30;
}

void func_001d6e08(u8* p) {
    u32* q = (u32*)(p + 4);
    for (s32 i = 1; i >= 0; i--) {
        u32 x = *q++;
        if (x) func_0016ed50(x, -1, 30);
    }
}

struct E64 { u8 pad[0x26c]; u32 on : 1; u32 : 31; };
static inline bool entry_on(u32 o) { return ((E64*)(func_001bbcb0() + o))->on; }
u32 ctarget_001d9148(u32 i, u32, u32, u32) {
    u32 o = i << 6;
    if (func_001bb4a0()) {
        if (entry_on(o)) return *(u32*)(func_001bbcb0() + o + 0x298);
    }
    return 0;
}

void func_001ddd88(void* p) {
    if (func_00321cb0(D_01d9e348, p)) func_001dde40(p);
}

u32 func_0022ae98(Q16* v) {
    u32 r = func_0022b688(142);
    Q16 t;
    QCOPY(&t, v);
    func_001391a8(r, &t);  // vec_copy_at416_if_diff
    func_002251c8(12101);
    return r;
}

void func_00240b48(u32 a) {
    if (!a) a = D_0035ec90;
    func_002fdd68(func_001058e8(), a, 0x10fc0);
}

// Index of the n-th set bit (of 8) in the mask, or -1.
s32 func_00257fa8(s32 n) {  // nth_set_bit_index
    s32 r = -1;
    s32 m = D_0035ef70;
    s32 c = 0;
    for (s32 i = 0; i < 8; i++) {
        if ((u8)((m >> i) & 1)) {
            if (c == n) { r = i; break; }
            c++;
        }
    }
    return r;
}

void func_0028d0f8(u8* p) {
    *(u32*)(p + 12) = 0;
    *(void**)p = D_00347e60;
    func_00239700(p + 24);
    *(void**)p = D_0035f420;
    func_0028d188(p);
}

void func_002908a8(u8* p) {
    s32* q = (s32*)p;
    q[1] = 0;
    p[16] = 0;
    q[2] = 0;
    for (s32 i = 0; i < q[3]; i++) ((s32*)q[5])[i] = 0;
}

u8* func_002924d0(u8* p, u32 a) {  // find_or_default_offset
    u8* r = a ? func_001a8190(func_001a80c8(a)) : p + 0x2b3c;
    return r ? r : p + 0x2b3c;
}

void func_00299550(void) {
    D_0035f5a8 = 0;
    D_0035f5a9 = 0;
    if (D_0035f5a4) {
        u8* o = D_0035f5a4;
        (*(void (**)(void*))(*(u8**)o + 4))(o);
        D_0035f5a4 = 0;
    }
}

// Set bit n in a bitset at +0x94 (stores only when it changes).
void func_002aae30(u32 n) {
    u32* arr = (u32*)(func_002a9d68() + 148);
    u32* w = (u32*)((n >> 5) * 4 + (u32)arr);
    u32 v = *w;
    u32 bit = 1 << (n & 31);
    if (!(v & bit)) *w = v | bit;
}

void func_002be7b8(u8* p, u32 a, u32 b) {
    func_00185ed8(p, a, 4, b);
    *(void**)p = D_00361810;
    *(u32*)(p + 0x588) |= 0x40000000;
}

void func_002bfb40(void) {
    D_00361a50 = 0;
    func_001c11a8(12);
    u8* q = *(u8**)(D_0034e948 + 0xb40);
    *(u32*)(q + 0x2c) &= ~1;
    func_00197780();
    func_00197cc0();
    func_00139858(201);
}

u32 func_002cebc8(u32 a) {
    u8* o = D_00361f60;
    if (o) return (*(u32 (**)(void*, u32))(*(u8**)o + 16))(o, a);
    return 0;
}

u8 func_002e0e70(u8* p) {
    *(void**)p = D_00362dc8;
    u8* s = *(u8**)(p + 0x70);
    if (s) {
        func_002e70b0(s);
        func_00106420(s);
    }
    return func_002cea28(p);
}

void func_002e3840(u8** p) {
    Q16 t;
    func_0016c2b0(&t, *(u32*)(*p + 4));
    if (&t != &D_01e2be20) QCOPY(&D_01e2be20, &t);
    *p = (u8*)&D_01e2be20;
}

// d = ftoi4(project(m * v)); with f set, zw are converted with ftoi0 instead.
void func_002f47d8(void* d, void* m, void* v, u32 f) {  // mat4_transform_perspective
    asm volatile(
        "lqc2 $vf4, 0(%1)\n\t"
        "lqc2 $vf5, 16(%1)\n\t"
        "lqc2 $vf6, 32(%1)\n\t"
        "lqc2 $vf7, 48(%1)\n\t"
        "lqc2 $vf8, 0(%2)\n\t"
        "vmulax.xyzw ACC, $vf4, $vf8x\n\t"
        "vmadday.xyzw ACC, $vf5, $vf8y\n\t"
        "vmaddaz.xyzw ACC, $vf6, $vf8z\n\t"
        "vmaddw.xyzw $vf9, $vf7, $vf8w\n\t"
        "vdiv Q, $vf0w, $vf9w\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf9, $vf9, Q\n\t"
        "vftoi4.xyzw $vf10, $vf9" : : "r"(d), "r"(m), "r"(v) : "memory");
    if (f) asm volatile("vftoi0.zw $vf10, $vf9");
    asm volatile("sqc2 $vf10, 0(%0)" : : "r"(d) : "memory");
}

// vsprintf-style: format into buf through a string FILE.
struct StrFile { u8* p; u32 r; u32 w; u16 flags; u16 file; u8* base; u32 size; u32 pad[15]; u32 data; u32 pad2[2]; };
s32 func_00301550(u8* buf, u32 fmt, u32 ap) {
    StrFile f;
    f.p = buf;
    f.w = 0x7fffffff;
    f.flags = 0x208;
    f.base = buf;
    f.size = 0x7fffffff;
    f.data = D_00365c48;
    s32 r = func_002ffd00(&f, fmt, ap);  // fprintf_stream_va
    *f.p = 0;
    return r;
}

void func_0031ce70(u8* p) {
    *(void**)p = D_0035eb98;
    func_0023c098(p + 48);  // set_vtbl_36eae8_then_call
    func_002369f0(p + 24);  // set_vtbl_36eac8_then_call
    *(void**)p = D_00347f98;
    func_0023ee68(p);
}

void func_00320198(u8* p) {
    *(void**)p = D_0034ee08;
    func_0019f9a8(p + 0xa08);  // array8_free_slots
    func_001c0248(p + 0xa50);
    func_00319fb0(p);  // big_obj_dtor
    func_00105110(p);
}
}
