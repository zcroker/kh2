#include "../common/types.h"

// 128-bit copy (lq/sq through t0).
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// 16-byte aligned vector; assignment copies a quadword unless self-assigned.
struct Vec4 {
    f32 x, y, z, w;
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

// Same layout, but copy-constructible (used for by-value returns).
struct Vec4c {
    f32 x, y, z, w;
    Vec4c() {}
    Vec4c(const Vec4c& o) { QCOPY(this, &o); }
} __attribute__((aligned(16)));

extern "C" {

void* create_task(void* self, int a, int b, void* fn) asm("_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE");
void setHideGroup(u32 g) asm("_ZN2dk3Map12setHideGroupEj");
void wtarget_00180d40(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_00180d40jjjj");
void wtarget_002eda40(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002eda40jjjj");

// --- 00101ce0
// Run the static constructor table backwards from its end until the -1 marker.
typedef void (*VFn)(void);
extern VFn D_0037a6e4[];
void func_00101ce0(void) {
    VFn* p;
    for (p = D_0037a6e4 - 1; *p != (VFn)-1; p--) (*p)();
}

// --- 00102788
// Allocate a 72-byte task through the manager's allocator (tagged with the
// caller's return address), construct it and link it in.
void func_001022c0(void*, void*, int, int, void*);
void func_00102528(void*, void*);
void* create_task(void* self, int a, int b, void* fn) {
    typedef void* (*AllocFn)(void*, int, void*);
    void* t = (**(AllocFn**)self)(self, 72, __builtin_return_address(0));
    func_001022c0(t, self, a, b, fn);
    func_00102528(self, t);
    return t;
}

// --- 00109140
void func_00133de8(void);
void func_00109330(void);  // set_global_3756_return
void func_00109340(void);  // to_109450_zero
void func_0010a7d8(int, int, int);  // store_triple_bytes
void func_0010a828(f32, f32);
void func_0010a8a8(f32, f32);  // store_global_float_pair
extern u64 D_003a8e10;
extern u8 D_00340eb0;
void func_00109140(void) {
    func_00133de8();
    func_00109330();  // set_global_3756_return
    func_00109340();  // to_109450_zero
    D_003a8e10 = 0x4000000001300000ULL;
    D_00340eb0 = 1;
    func_0010a7d8(128, 128, 128);  // store_triple_bytes
    func_0010a828(5000.0f, 1000000.0f);
    func_0010a8a8(0.0f, 255.0f);  // store_global_float_pair
}

// --- 0010cce0
// Advance the object iterator until an object passing the check is found.
void* func_001b9bc8p(void*) asm("func_001b9bc8");
bool func_00112d28(void*);
void* func_0010cce0(void* p) {
    while ((p = func_001b9bc8p(p)) != 0) {
        if (func_00112d28(p)) break;
    }
    return p;
}

// --- 0013e2d8
u32 func_0013a7e8(u32);
void func_001386e0(u8*, u32, u32, u32, u32, u32);
void func_00139598(u8*);
void func_00139708(u8*);
void func_0013e2d8(u8* p, u32 a, u32 b) {
    *(u32*)(p + 436) = a;
    func_001386e0(p, 4000, func_0013a7e8(0), b, a, 17);
    func_001386e0(p + 448, 4000, func_0013a7e8(0), b, 20, 17);
    func_00139598(p + 448);
    func_00139708(p + 448);
}

// --- 00141850
// Clear every entry's flag, then apply each bit set in the 64-bit mask.
void func_00141928(u8*, u8);  // mark_records_by_index
struct E141 { u8 pad[16]; u8 f; u8 p2[3]; };
void func_00141850(u8* p, u64 mask) {
    s32 j;
    s32 n = *(s32*)(p + 36);
    for (j = 0; j < n; j++) (*(E141**)(p + 8))[j].f = 0;
    s32 i;
    for (i = 0; i < 64; i++) {
        u64 one = 1;
        if (mask & (one << i)) func_00141928(p, i);  // mark_records_by_index
    }
}

// --- 0014ed28
u32 func_0014ecf8(u32);
u32 func_00136958(void);
u32 func_002bc2e8(u32, u32, u32);
extern s32 D_0034a400;
extern u32 D_0034a408[];
void func_0014ed28(u32 a, u32 b) {
    u32 r = func_0014ecf8(a);
    if (r) {
        u32 x = func_00136958();
        D_0034a408[D_0034a400] = func_002bc2e8(r, x, b);
        D_0034a400++;
    }
}

// --- 00152508
u32 func_0013d7e0(void);
void func_00138d60(u8*, u32, u32, u32, u32, u32, u32);
void func_0023aa78(u8*);
void func_00152508(u8* p, u32 a, u32 b, u32 c, u32 d) {
    u32 r = func_0013a7e8(1);
    func_00138d60(p, 9000, r, func_0013d7e0(), a, c, 14);
    *(u32*)(p + 372) = d;
    *(u32*)(p + 424) = 14;
    func_0023aa78(p + 24);
}

// --- 00157160
u8* func_0017df58(u32);
void func_001574a0(u32);
void func_001024a8(u8*);
void func_00157160(u8* p) {
    u8* o = func_0017df58(0);
    if (o && (*(u32*)(o + 1416) & 0x400000)) {
        func_001574a0(*(u32*)(p + 4));
        func_001024a8(p);
    }
}

// --- 0015ee10
// Clear the group's bit in the hidden-group mask and refresh.
void func_00143060(void);
void func_001538d8(u8);
void func_0015c4a0(u32);
void func_001de3d8(void*, u32);
extern u64 D_0034c710;
extern u8 D_0034c70c;
extern u8 D_0034c6f0[];
void setHideGroup(u32 g) {
    D_0034c710 = ~(1ULL << g) & D_0034c710;
    func_00143060();
    func_001538d8(g);
    func_0015c4a0(g);
    if (D_0034c70c == 1) func_001de3d8(D_0034c6f0, g);
}

// --- 00167cd0
u32 func_00167c90(u8*, void*);
extern u8 D_0036b628[];
extern void* D_0034d7ac;
u32 func_00167cd0(u8* p) {
    u32 r = func_00167c90(p, D_0036b628);
    if (D_0034d7ac) r |= func_00167c90(p, D_0034d7ac);
    *(Vec4*)(p + 32) = *(Vec4*)(*(u8**)(p + 68) + 32);
    *(Vec4*)(p + 48) = *(Vec4*)(*(u8**)(p + 68) + 48);
    return r;
}

// --- 0016d3c8
// p[0] = &(static vector = *p[0] - *p[1]); the static's guard/atexit is open-coded.
extern s8 D_004f62d0;
extern Vec4 D_004f62e0;
void func_002fd188(void (*)(void));  // pool_alloc_block
void func_0016e880(void);
void func_0016d3c8(Vec4** p) {
    Vec4* a = p[0];
    Vec4* b = p[1];
    if (!D_004f62d0) {
        D_004f62d0 = 1;
        func_002fd188(func_0016e880);  // pool_alloc_block
    }
    Vec4 t;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(t) : "r"(a), "r"(b));
    D_004f62e0 = t;
    p[0] = &D_004f62e0;
}

// --- 00173f68
f32 func_00184a90(u32);
f32* func_0016c028(u32);  // obj_get_attach_or_alt
void func_00173f68(u8* p) {
    u32 o = *(u32*)(*(u8**)p + 4);
    f32 d = func_00184a90(o) - func_0016c028(o)[1];
    f32 v;
    if (0.0f < d) v = func_00184a90(o) - func_0016c028(o)[1];
    else v = 0.0f;
    *(f32*)p = -v;
}

// --- 00176b58
u32 func_00176b20(s32);
s32 func_0016a070(u32);
u32 func_001d14a0(void);
u32 func_00176b58(s32 id) {
    s32 i;
    for (i = 0; i < 3; i++) {
        u32 o = func_00176b20(i);
        if (o && func_0016a070(o) == id) return o;
    }
    if (id == 1) return func_001d14a0();
    return 0;
}

// --- 00180d40
// Add b to the 16-slot table unless present (stored in the last free slot).
struct T180 { u8 pad[332]; s32 t[16]; };
void wtarget_00180d40(u32 a, u32 b, u32 c, u32 d) {
    T180* o = (T180*)a;
    s32 idx = -1;
    s32 i;
    for (i = 0; i < 16; i++) {
        if (o->t[i] == (s32)b) return;
        if (o->t[i] < 0) idx = i;
    }
    o->t[idx] = b;
}

// --- 00188ac8
s32 func_001a3570(u16);
void func_001a34e0(u16, u32);
struct S188 { u8 pad[18]; bool n; };
void func_00188ac8(S188* p) {
    s32 i;
    for (i = 0; i < p->n; i++) {
        u16* e = (u16*)((u8*)p + i * 2);
        if (e[34] && !e[26]) {
            if (func_001a3570(e[34]) <= 0) continue;
            func_001a34e0(e[34], 1);
            e[26] = e[34];
        }
    }
}

// --- 00190388
struct Buf190 { u32 a, b, c, d; Vec4c v; };
void func_001902a8(u32, Buf190*);
Vec4c func_00190388(u32 a) {  // vec4_from_arg
    Buf190 t;
    t.d = 0;
    func_001902a8(a, &t);
    return t.v;
}

// --- 001b55e8
u32 func_0016f7d0(u32, u32);
u32 func_001d1ca8(u8*);
u32 func_001d1f08(u8*);
u32 func_001c9df8(void);
u32 func_001b55e8(u8* p) {
    u32 o = *(u32*)(*(u8**)p + 36);
    if (o && (func_0016f7d0(o, 0) & 8)) return 0;
    if (func_001d1ca8(p + 104)) return 0;
    if (func_001d1f08(p + 168)) return 0;
    if (func_001c9df8()) return 0;
    return *(u32*)(p + 36) == 0 && *(u32*)(p + 60) == 0;
}

// --- 001b9ee8
extern u8* D_01d48da0;
static inline u8* Next1b9(u8* o) {
    if (!o) return D_01d48da0;
    return *(u8**)(o + 2228);
}
void func_001b9ee8(s32 lim) {
    u8* o = 0;
    while ((o = Next1b9(o))) {
        if (*(u32*)(o + 1416) & 0x20) continue;
        typedef s32 (*Fn)(u8*);
        if ((*(Fn*)(*(u8**)o + 60))(o) < lim) *(u32*)(o + 268) |= 0x80;
    }
}

// --- 001bdcd0
u32 func_001819c0(u32);
u32 func_001bd590(u32);
u32 func_001bdcd0(u32 a) {
    u32 r = 0;
    if (!func_001819c0(a) || func_001bd590(a)) r = 1;
    return r;
}

// --- 001cffe0
void func_001780d8(u8*);
void func_00198860(u8*, u32);
void func_0017f488(u8*, u32, f32, f32);
void func_0017f5e0(u8*, u32, u32, f32, f32);
void func_001987a8(u8*, void*, u8*);
extern u8 D_0036e368[];
void func_001cffe0(u8* p) {
    func_001780d8(p);
    func_00198860(p, 1);
    func_0017f488(p + 320, 191, 0.0f, 0.0f);
    func_0017f5e0(p + 320, 0, 0, 0.0f, 0.0f);
    func_001987a8(p, D_0036e368, p);
}

// --- 001d5068
// bsearch the 2-byte-entry table for key, then use the entry's id.
extern u8* D_01d5ba68;
extern u8 D_00321790[];
extern u32 D_00352768;
u8* func_002fd248(u32, u8*, u32, u32, void*);
u8* func_00168b38(u32, u32, u8);  // entry_array_find_nth
void func_0023cde8(u32);
void func_001d5068(u32 key) {
    u8* t = D_01d5ba68;
    u8* r = func_002fd248(key, t + 8, *(u32*)(t + 4), 2, D_00321790);
    func_0023cde8(*(u32*)(func_00168b38(D_00352768, 47, r[1]) + 8));
}

// --- 001d6d00
// 1-based index of the entry with the given id, 0 if none.
struct Ent1d6 { u8 d[64]; };
struct Tbl1d6 { u8 hdr[8]; Ent1d6 e[1]; };
extern Tbl1d6* D_01d5ba98;
u16* func_001d6cc8(u16*);
s32 func_001d6d00(u32 id) {
    u16* e = 0;
    while ((e = func_001d6cc8(e))) {
        if (*e == id) return (Ent1d6*)e - D_01d5ba98->e + 1;
    }
    return 0;
}

// --- 001d8ad8
u8* func_001bbcb0(void);
u32 func_001bb4a0(void);
void func_001d8ad8(s32 idx, u8 flag) {
    u8* b = func_001bbcb0() + idx * 56;
    if (func_001bb4a0()) {
        u8* o = b + 232;
        u32 f = *(u32*)(b + 244);
        u8 on = f & 1;
        if (on) {
            typedef void (*Fn)(u8*);
            if (flag) {
                if (!(f & 8)) (*(Fn*)(*(u8**)o + 12))(o);
            } else {
                if (f & 8) (*(Fn*)(*(u8**)o + 16))(o);
            }
        }
    }
}

// --- 001da458
struct P1da { u32 a; u32 b; u32 cur; };
void func_001da3d8(P1da*, u32*);  // stream_append_unaligned
void func_001da458(P1da* p, u32 a, u32* arr, s32 n) {  // stream_init_fields
    u32 i;
    p->b = a;
    for (i = 0; i < 4; i++) {
        u32* c = (u32*)p->cur;
        *c = 0;
        p->cur = (u32)(c + 1);
    }
    for (i = 0; (s32)i < n; i++) func_001da3d8(p, &arr[i]);  // stream_append_unaligned
}

// --- 001e0de8
Vec4* func_001e0cc8(Vec4*);  // entry64_by_field32
Vec4* func_001e0ce8(Vec4*);  // entry64_by_field32_b
void func_001e0de8(Vec4* p) {
    p[0] = *func_001e0cc8(p);  // entry64_by_field32
    *(u32*)&p[0].w = 0;
    p[1] = *func_001e0ce8(p);  // entry64_by_field32_b
}

// --- 001ea458
extern u8* D_01d9e6e0;
u8* func_001e7a98(u8*, u8*);
void func_001ea458(u32 a, u8* b, u16 c) {
    if (*(s32*)(b + 12) == -1) return;
    u8* m = D_01d9e6e0;
    u8* r = 0;
    u8* e = *(u8**)(m + 128) + *(s32*)(b + 12) * 16;
    if (e) {
        r = func_001e7a98(m, e);
        *(u32*)(r + 4) = a;
    }
    *(u16*)(r + *(u32*)(b + 16) + 160) = c;
}

// --- 0022b898
u32 func_0022b7f0(void);
void func_0023fa90(u8*, u32);
u32 func_0023f908(u8*, u32);
u32 func_0023f948(u8*, u32);
u32 func_001050c8(void);
void func_00236a58(u8*, u32, u32);
void func_0023c100(u8*, u32, u8*, u32);
extern u8* D_0035e2e8;
void func_0022b898(void) {
    func_0023fa90(D_0035e2e8, func_0022b7f0());
    u32 a = func_0023f908(D_0035e2e8, 0);
    u32 b = func_0023f948(D_0035e2e8, 0);
    u32 c = func_001050c8();
    func_00236a58(D_0035e2e8 + 120, a, c);
    func_0023c100(D_0035e2e8 + 28, b, D_0035e2e8 + 120, c);
}

// --- 00263960
// Store the parameters, then allocate and construct the 460-byte object.
extern u32 D_0035f0b8;
extern u32 D_0035f0bc;
extern u32 D_0035f0c0;
extern u8* D_00347f80;
extern u8 D_00347e60[];
extern u8 D_0035f360[];
extern u32* volatile D_0035f0dc;
void func_00263bb0(u32, u32);
void func_00239700(u32*);
void func_00263960(u32 a, u32 b, u32 c, u32 d, u32 e) {  // store_globals_and_init
    D_0035f0b8 = a;
    D_0035f0bc = b;
    D_0035f0c0 = c;
    func_00263bb0(d, e);
    u8* h = *(u8**)(D_00347f80 + 20);
    typedef u32* (*Fn)(u8*, u32, u32);
    u32* o = (**(Fn**)h)(h, 460, 0);
    o[3] = 0;
    o[0] = (u32)D_00347e60;
    func_00239700(o + 6);
    o[102] = 0;
    *(volatile u32*)o = (u32)D_0035f360;
    D_0035f0dc = o;
}

// --- 0027db58
u8* func_00167f18(u32);
u32 func_00287db0(void);
u32 func_00290740(u32);
void func_001039f8(void);
void func_00242618(u32, u32);
void func_00287da0(void);
extern u32 D_0035f238;
u32 func_0027db58(void) {
    u8* o = func_00167f18(0);
    if (func_00287db0()) {
        if (func_00290740(D_0035f238)) return 0;
        func_001039f8();
        return 1;
    }
    if (*(u64*)(o + 8) & 0xc) {
        func_00242618(9, 1);
        func_00287da0();
    }
    return 0;
}

// --- 002a6718
u32 func_00276368(void);
u32 func_0028acc8(u32);
u32 func_00276888(void);
u32 func_00139d78(u8*);
extern u32 D_0035f200;
extern u8* D_0035f5f0;
void func_002a6718(void) {
    if (func_00276368()) return;
    if (func_0028acc8(D_0035f200)) return;
    if (func_00276888()) return;
    s32 i;
    for (i = 0; i < 10; i++) {
        if (func_00139d78(D_0035f5f0 + i * 436)) return;
    }
}

// --- 002bc608
extern u8* D_01e2aa80;
void func_002bbf68(u8*, u32);
static inline u8* Next2bc(u8* o) {
    if (!o) return D_01e2aa80;
    return *(u8**)(o + 28);
}
void func_002bc608(u32 key) {
    u8* o = 0;
    while ((o = Next2bc(o))) {
        if (*(u32*)(o + 24) != key) continue;
        if (o[49] != 5) continue;
        func_002bbf68(o, 1);
    }
}

// --- 002c1aa0
// Constructor: base init, then vtable and flags.
void func_002be770(u8*);
extern u8 D_00361b20[];
void func_002c1aa0(u8* p) {
    func_002be770(p);
    *(u32*)p = (u32)D_00361b20;
    *(u32*)(p + 1420) |= 1;
    *(u8*)(p + 2792) = 0;
    *(u32*)(p + 2788) = 0;
}

// --- 002eda40
// Count the timer down by one; fire event 151 when it runs out.
extern f32 D_00349e10;
void func_001991a8(u32, u32);
void wtarget_002eda40(u32 a, u32 b, u32 c, u32 d) {
    f32* p = (f32*)a;
    if (0.0f < *p) {
        *p = *p - D_00349e10;
        if (*p <= 0.0f) func_001991a8(151, 0);
    }
}

// --- 002edca0
u32 func_001b9bc8(u32);
u32 func_001c0cd8(u32);
void func_001c1020(u32, u32);
void func_002edca0(u32 key, u32 arg) {
    u32 o = 0;
    while ((o = func_001b9bc8(o))) {
        if (func_001c0cd8(o) && *(u32*)(o + 1392) == key) func_001c1020(o, arg);
    }
}

// --- 002f4888
// Hand-written VU0 routine: compares the point's x/y against (0,0) and
// (4096,4096) and returns the x/y sign bits of the MAC flags.
u32 func_002f4888(void* p) {
    register u32 r asm("$2");
    asm volatile(
        "vsub.xyzw $vf4, $vf0, $vf0\n\t"
        "lui $2, 0x4580\n\t"
        "dsll $2, $2, 16\n\t"
        "ori $2, $2, 0x4580\n\t"
        "dsll $2, $2, 16\n\t"
        "lqc2 $vf7, 0(%1)\n\t"
        "qmtc2 $2, $vf6\n\t"
        "ctc2 $0, $vi16\n\t"
        "vsub.xyw $vf5, $vf7, $vf4\n\t"
        "vsub.xy $vf5, $vf6, $vf7\n\t"
        "vnop\n\tvnop\n\tvnop\n\tvnop\n\tvnop\n\t"
        "cfc2 $2, $vi16"
        : "=r"(r) : "r"(p));
    return r & 0xc0;
}

// --- 00313bc0
// libgcc fp-bit: float -> unsigned int.
struct FpNum { u32 cls; s32 sign; s32 exp; u32 frac; };
void func_00314640(f32*, FpNum*);
static inline int fp_iszero(FpNum* x) { return x->cls == 2; }
static inline int fp_isnan(FpNum* x) { return x->cls < 2; }
static inline int fp_isinf(FpNum* x) { return x->cls == 4; }
u32 func_00313bc0(f32 f) {
    FpNum a;
    f32 u = f;
    func_00314640(&u, &a);
    if (fp_iszero(&a)) return 0;
    if (fp_isnan(&a)) return 0;
    if (a.sign) return 0;
    if (fp_isinf(&a)) return 0xffffffff;
    if (a.exp < 0) return 0;
    if (a.exp > 31) return 0xffffffff;
    if (a.exp > 30) return a.frac << (a.exp - 30);
    return a.frac >> (30 - a.exp);
}

// --- 0031c7a8
// Destructor: destroy the 7-element member array (344-byte elements, virtual
// dtor) back to front, then the base subobjects.
extern u8 D_0034a660[];
extern u8 D_00347f98[];
void func_00239870(u8*);
void func_0031c7a8(u8* p) {
    *(u32*)p = (u32)D_0034a660;
    if (p + 456) {
        u8* e = p + 2864;
        for (;;) {
            if (p + 456 == e) break;
            e -= 344;
            typedef void (*Fn)(u8*);
            (**(Fn**)e)(e);
        }
    }
    *(u32*)(p + 48) = (u32)D_00347e60;
    func_00239870(p + 72);
    *(u32*)(p + 48) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00347f98;
}

}
