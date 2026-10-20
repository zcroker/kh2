#include "../common/types.h"

struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

extern "C" {
void func_00134508(s32, s32) asm("_Z13func_00134508ii");
void u_call0_0018d790(void) asm("_Z16u_call0_0018d790v");
void wtarget_00198690(u32, u32, u32, u32) asm("_Z16wtarget_00198690jjjj");
u32 func_001b84b8(u32, u32, u32, u32) asm("_Z13func_001b84b8jjjj");
void wtarget_001e7230(u32, u32, u32, u32) asm("_Z16wtarget_001e7230jjjj");
void wtarget_0028d068(u32, u32, u32, u32) asm("_Z16wtarget_0028d068jjjj");

s32 func_00139d78(void*);
Vec4* func_0016c028(void*);  // obj_get_attach_or_alt

void func_00170dd0(void);
void func_003058a0(s32);
void func_01f18014(s32, void*);
void func_00170c00(u32);
void func_00170320(s32);
extern u8 D_0032ba90[];
extern u32 D_0032bac0;
extern u32 D_0032babc;
extern u32 D_0032bac4;
void D_001044f0(void) {
    func_00170dd0();
    func_003058a0(2);
    func_01f18014(1, D_0032ba90);
    func_00170c00(D_0032bac0);
    func_00170c00(D_0032babc);
    func_00170320(0);
    D_0032bac4 = 0;
    D_0032bac0 = 0;
    D_0032babc = 0;
}

extern u8 D_00347c88[];
void func_00133570(void*);
void func_00133590(void*);
void func_00134508(s32 a, s32 b) {
    if (b == 0xffff && a == 1) func_00133570(D_00347c88);
    if (b == 0xffff && a == 0) func_00133590(D_00347c88);
}

// Transforms v by the 4x4 matrix m, divides by w and converts to integer
// screen coordinates (offset by 1792/1840) in a static buffer.
extern s32 D_003b8b40[4];
s32* func_0013a178(Vec4* v, Vec4* m) {  // mat4_mul
    s32* d = D_003b8b40;
    asm volatile("lqc2 $vf4,0(%1)\n\tlqc2 $vf5,16(%1)\n\tlqc2 $vf6,32(%1)\n\tlqc2 $vf7,48(%1)\n\tlqc2 $vf8,0(%2)\n\t"
        "vmulax.wxyz ACC,$vf4,$vf8x\n\tvmadday.wxyz ACC,$vf5,$vf8y\n\tvmaddaz.wxyz ACC,$vf6,$vf8z\n\tvmaddw.wxyz $vf12,$vf7,$vf8w\n\t"
        "vdiv Q,$vf0w,$vf12w\n\tvwaitq\n\tvmulq.wxyz $vf12,$vf12,Q\n\tvftoi0.wxyz $vf13,$vf12\n\tsqc2 $vf13,0(%0)"
        : : "r"(d), "r"(m), "r"(v) : "memory");
    D_003b8b40[0] -= 1792;
    d[1] -= 1840;
    return d;
}

// Takes a slot (784 bytes each) from a free-index pool and initialises it.
struct Pool13a { u8 pad[28224]; s32 free[36]; s32 n; };
extern u8* D_00348058;
u8* func_0013aa78(u8*, u32, u32, u32, u32, u32, u32);
u8* func_0013aca0(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    Pool13a* p = (Pool13a*)D_00348058;
    s32 n = p->n - 1;
    p->n = n;
    u8* r = (u8*)p + p->free[n] * 784;
    func_0013aa78(r, a, b, c + 32, d, e, f);
    return r;
}

struct S13e { u8 pad[388]; s32 f388; u8 pad2[56]; u8 sub[16]; };
void func_00138c10(void*, s32);
void func_00139510(void*);
void func_0013e4b8(S13e* p) {
    if (!func_00139d78(p)) return;
    func_00138c10(p, p->f388 - 1);
    if (func_00139d78(p->sub)) func_00139510(p->sub);
}

struct N160 { u8 pad[128]; N160* next; u8 pad2[292]; s32 key; };
extern N160* D_004f3b38;
void func_00160d38(N160*);
static inline N160* Next160(N160* n) { if (!n) return D_004f3b38; return n->next; }
void func_00160e50(s32 k) {
    N160* n = 0;
    while ((n = Next160(n))) {
        if (n->key == k) func_00160d38(n);
    }
}

union U173 { f32 f[4]; u32 u[4]; } __attribute__((aligned(16)));
extern U173 D_01c5f480;
f32 func_00184a90(void*);
void func_00173f08(u32* p) {
    U173* v = (U173*)func_0016c028(*(void**)(p[0] + 4));  // obj_get_attach_or_alt
    U173* d = &D_01c5f480;
    if (v != d) QCOPY(d, v);
    d->f[1] = func_00184a90(*(void**)(p[0] + 4));
    *p = (u32)d;
}

s32 func_0017df70(void);
u8* func_0016e920(s32);
u32 func_0016f7d0(s32, u8*);
s32 func_0017dfc8(void) {
    s32 r = func_0017df70();
    if (r) {
        u8* o = func_0016e920(r);
        if (*(u16*)(o + 76) == 8) {
            if (func_0016f7d0(r, o) < 2) r = 2077;
        }
    }
    return r;
}

void func_002cbca0(Vec4*, u32, Vec4*, u8*);
Vec4* func_001850a0(Vec4* out, u8* p) {
    if (!*(u32*)(p + 1288)) {
        asm volatile("vsub.wxyz $vf1,$vf0,$vf0\n\tsqc2 $vf1,0(%0)" : : "r"(out) : "memory");
        return out;
    }
    Vec4 t;
    func_002cbca0(&t, *(u32*)(p + 1288), func_0016c028(p), p + 1360);
    if (out != &t) QCOPY(out, &t);
    return out;
}

// Formats name [i][j] (32-byte strings, two per row) into buf (or a static buffer).
extern u8* D_01c6088c;
extern char D_01c60890[];
extern char D_0036c8f0[];
void func_002fee78(char*, const char*, ...);
char* func_00185920(s32 i, s32 j, char* buf) {
    u8* row = D_01c6088c + i * 64;
    char* s = (char*)(j * 32 + (u32)row);
    if (!*s) return 0;
    if (!buf) buf = D_01c60890;
    func_002fee78(buf, D_0036c8f0, s);
    return buf;
}

// Deletes every object in the list (virtual destructor, slot 1).
struct O18d { void** vt; u8 pad[188]; O18d* next; };
extern O18d* D_01c60cd8;
extern u8 D_01c60ce0;
static inline O18d* Next18d(O18d* n) { if (!n) return D_01c60cd8; return n->next; }
void u_call0_0018d790(void) {
    O18d* o = Next18d(0);
    O18d* it = o;
    while (o) {
        it = Next18d(it);
        if (o) ((void (*)(O18d*))o->vt[1])(o);
        o = it;
    }
    D_01c60ce0 = 0;
}

void func_00198660(u32);  // to_1b0250_field
void func_001d5770(u8*, Vec4*);
void func_0016a9b8(u32);
void wtarget_00198690(u32 a, u32, u32, u32) {
    func_00198660(a);  // to_1b0250_field
    Vec4 v;
    QCOPY(&v, func_0016c028((void*)a));  // obj_get_attach_or_alt
    u8* p = (u8*)a + 2524;
    for (s32 i = 0; i < 2; i++, p += 12) func_001d5770(p, &v);
    func_0016a9b8(a);
}

// Calls func_0015ee10 for every bit set in the 64-bit mask.
extern u64 D_0034ecc8;
void func_0015ee10(s32);
void func_0019ebc0(void) {
    for (s32 i = 0; i < 64; i++) if ((u8)((D_0034ecc8 >> i) & 1)) func_0015ee10(i);
}

void func_001a98e8(void*, u32, u32, u32, u32);
void func_001a9ae8(void*, u32, u32, u32);
void func_001aa728(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g) {
    u8 t[96];
    func_001a98e8(t, a, b, f, g);
    func_001a9ae8(t, c, d, e);
}

s32 func_001b58a8(void);
u32 func_001a8bd0(s32);
s32 func_001a8bf8(u32, s32);  // get_bits5_at
s32 func_001c8db8(void*, s32);
extern u8 D_00351ec0[];
s32 func_001b6070(void) {
    if (func_001b58a8()) return 0;
    s32 r = 0;
    if (func_001a8bf8(func_001a8bd0(-1), 3) != 18) r = func_001c8db8(D_00351ec0, 0) == 0;
    return r;
}

s32 func_0019bb98(u8*);
u8* func_001b7998(u8*, u32);
void func_0018a7d0(u8*, u32, Vec4*);
void func_001b7df0(u8* p, u32 b) {
    if (func_0019bb98(*(u8**)(p + 4))) return;
    u8* v = func_001b7998(p, b);
    if (!v) return;
    Vec4 t;
    func_0018a7d0(v, b, &t);
    u8* d = *(u8**)(p + 4) + 2160;
    asm volatile("lqc2 $vf1,0(%0)\n\tlqc2 $vf2,0(%1)\n\tvsub.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)" : : "r"(d), "r"(&t) : "memory");
}

struct S1b8 { u32 f0; u32 f4; u32 f8; u32 pad; u32 f16; };
u32 func_001b8420(u32);
u32 func_001db610(u32, void*, S1b8*);
extern u8 D_001b8520[];
u32 func_001b84b8(u32 a, u32 b, u32, u32) {
    S1b8* p = (S1b8*)a;
    if (!p->f4) return 0;
    p->f16 = b;
    if (!p->f8) p->f8 = func_001b8420(p->f0);
    p->f8 = func_001db610(p->f8, D_001b8520, p);
    return p->f8 != 0;
}

s32 func_001b9d40(u8* p) {  // vtable_call_slot64_flags
    s32 r = 0;
    if ((*(s32 (**)(u8*))(*(u8**)p + 64))(p)) {
        u32 f = *(u32*)(p + 352);
        s32 t = 0;
        if (f & 4) goto one;
        if (f & 8) goto one;
        if (!(f & 16)) goto done;
    one:
        t = 1;
    done:
        r = t;
    }
    return r;
}

struct N1e0 { u8 pad[20]; N1e0* next; };
extern N1e0* D_01d9e348;
void func_001e01e8(N1e0*, u32, u32);
static inline N1e0* Next1e0(N1e0* n) { if (!n) return D_01d9e348; return n->next; }
void func_001e0230(u32 a, u32 b) {
    N1e0* n = 0;
    while ((n = Next1e0(n))) func_001e01e8(n, a, b);
}

// Prints three diagnostic lines, then traps.
extern char D_0036e978[];
extern char D_0036e998[];
extern char D_0036e9b0[];
void func_002fdfc8(const char*, ...);  // device_vprintf_va
void func_001e2ad8(u32 a, u32 b, u32 c, u32 d) {
    func_002fdfc8(D_0036e978, a);  // device_vprintf_va
    func_002fdfc8(D_0036e998, b, c);  // device_vprintf_va
    func_002fdfc8(D_0036e9b0, d);  // device_vprintf_va
    asm volatile("break");
}

// Zero-fill: words then bytes. The nops reproduce the R5900 short-loop padding.
void wtarget_001e7230(u32 a, u32 b, u32, u32) {
    u32* p = (u32*)a;
    s32 n = (s32)b >> 2;
    if (n-- != 0) do { *p = 0; n--; asm volatile("nop\n\tnop\n\tnop"); p++; } while (n != -1);
    u8* q = (u8*)p;
    n = b & 3;
    if (n-- != 0) do { *q = 0; n--; asm volatile("nop\n\tnop\n\tnop"); q++; } while (n != -1);
}

extern u8 D_0035de26;
extern u8 D_00232150[];
void func_00102c18(s32, s32, void*);
s32 func_002282f0u(u16) asm("func_002282f0");
void func_002322b8(u8* p) {
    if (func_002282f0u(*(u16*)(p + 4))) return;
    if (!*(u16*)(p + 6)) {
        if (D_0035de26) return;
        func_00102c18(1, 29990, D_00232150);
        D_0035de26 = 1;
    } else D_0035de26 = 0;
}

extern u8* D_0035ee48;
void func_00250928(void) {
    for (s32 i = 0; i < 5; i++) {
        if (func_00139d78(D_0035ee48 + i * 408)) {
            u8* o = (u8*)(i * 408 + (u32)D_0035ee48);
            (*(void (**)(u8*))(*(u8**)o + 20))(o);
        }
    }
}

s32 func_002538f8(u32);  // entry16_get_flag_bit
s32 func_00253928(u32);  // entry16_get_bit1
s32 func_00253918(void);
s32 func_002539e8(u32, s32);
s32 func_00259350(u32 a) {
    if (func_002538f8(a)) return 1;
    if (func_00253928(a)) return 1;
    if (func_00253918()) return 0;
    return func_002539e8(a, 0) == 0;
}

extern u8* D_0035f20c;
u32 func_00192048(s32);
void func_00275e68(s32 a) {
    func_00139d78(D_0035f20c + 872);
    if (a < 0) *(u32*)(D_0035f20c + 1280) = 0;
    else { u8* o = D_0035f20c + 872; *(u32*)(o + 408) = func_00192048(a); }
}

// Sets entry b of the table to a, or every entry when b < 0.
extern s32 D_0035f404;
extern u32 D_0035f40c;
void wtarget_0028d068(u32 a, u32 b, u32, u32) {
    if ((s32)b < 0) {
        for (s32 i = 0; i < D_0035f404; i++) ((u32*)D_0035f40c)[i] = a;
    } else ((u32*)D_0035f40c)[b] = a;
}

s32 func_00293200(void);
extern s16 D_0035f4e0;
extern s32 D_0035f4c4;
u8 func_00292f18(void);
u8 func_00292fe8(void);
s32 func_00292eb0(void) {
    if (func_00293200()) return -1;
    if (!D_0035f4e0) return 0;
    if (!D_0035f4c4) return func_00292f18();
    return func_00292fe8();
}

extern s8* D_0035f5d0;
s32 func_002a01c8(s32);  // obj4_entry_by_index
s32 func_002943e8(s32);
s32 func_002a00f0(void) {
    s32 n = 0;
    for (s32 i = 0; i < D_0035f5d0[0]; i++) {
        if (func_002943e8(func_002a01c8(D_0035f5d0[i + 6]))) n++;
    }
    return n;
}

// 1 if bit a (or every bit 0..3 when a < 0) is set in the mask at +320.
extern u8* D_0035f620;
s32 func_002adf60(s32 a) {
    s32 r = 1;
    u32* bits = (u32*)(D_0035f620 + 320);
    for (s32 i = 0; i < 4; i++) {
        if (a < 0 || a == i) {
            if (!(bits[(u32)i >> 5] & (1 << (i & 31)))) { r = 0; break; }
        }
    }
    return r;
}

void func_002bb100(u8*, s32, s32);  // next_global_id
void func_002bb5a8(u8*, u32);
void func_002bb3f0(u8* p, u32 a, u32 b, u32 c, u32 d) {
    func_002bb100(p, 1, 6);  // next_global_id
    func_002bb5a8(p, c);
    *(u32*)(p + 24) = a;
    *(u32*)(p + 16) = b;
    *(u16*)(p + 42) = d;
}

void func_002d0bd8(u8*, u8*);
static inline void mcopy(void* d, void* s) {
    if (d != s) asm volatile("lq $8,0(%1)\n\tlq $9,16(%1)\n\tlq $10,32(%1)\n\tlq $11,48(%1)\n\tsq $8,0(%0)\n\tsq $9,16(%0)\n\tsq $10,32(%0)\n\tsq $11,48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
// Saves the current matrix (+2848) to +2912, loads m into it, then updates.
void func_002dc140(u8* p, u8* m) {
    mcopy(p + 2912, p + 2848);
    mcopy(p + 2848, m);
    func_002d0bd8(p, m);
}

s32 func_002ceb28(u32, u8*);
extern void* D_0034e948;
void func_0016ace0(u8*, Vec4*);
void func_0016aeb8(u8*, f32);
void func_002e31f0(u32 a, u8* b) {
    if (!func_002ceb28(a, b)) return;
    func_0016ace0(b, func_0016c028(D_0034e948));
    func_0016aeb8(b, 3.1415927f);
}

extern Vec4 D_01e2be20;
Vec4* func_002cb8e0(u8*);
void func_002e3d48(u8** p) {
    u8* o = *(u8**)(p[0] + 4);
    if (!o) return;
    o = *(u8**)(o + 1288);
    if (!o) return;
    Vec4* v = func_002cb8e0(o);
    Vec4* d = &D_01e2be20;
    if (v != d) QCOPY(d, v);
    *p = (u8*)d;
}

// Destructor body: restores the two vtables around member teardown.
extern u8 D_00363860[];
extern u8 D_003637e0[];
u8* func_001a93e8(u8*);
void func_00106ac8(u8*);
void func_001a9350(u8*);
void func_00106420(u8*);
void func_002eed48(u8* p) {
    *(u32*)p = (u32)D_00363860;
    u8* o = func_001a93e8(p + 44);
    (*(void (**)(u8*, u32, u32))(*(u8**)o + 40))(o, *(u32*)(p + 40), *(u32*)(p + 68));
    func_00106ac8(p + 80);
    func_001a9350(p + 44);
    *(u32*)p = (u32)D_003637e0;
    func_00106420(p);
}

// strrchr-style: last match of c in s (func_002ff014 is strchr).
char* func_002ff014(char*, s32);  // memset
char* func_002ff8b0(char* s, s32 c) {
    char* r = 0;
    if (c != 0) {
        while ((s = func_002ff014(s, c)) != 0) { r = s; s++; }
    } else r = func_002ff014(s, c);  // memset
    return r;
}
void wtarget_001124f8(u32, u32, u32, u32) asm("_Z16wtarget_001124f8jjjj");
void wtarget_001ce668(u32, u32, u32, u32) asm("_Z16wtarget_001ce668jjjj");

extern u8 D_00341700;
extern u8 D_003a9040[];
extern u16 D_0032bae0;
extern s32 D_00341780;
extern s32 D_003417d0;
extern s32 D_003417c4;
extern s32 D_003417c8;
void func_0010b550(void*);
void func_001127b0(void);
void wtarget_001124f8(u32, u32, u32, u32) {
    D_00341700 = 0;
    func_0010b550(D_003a9040);
    if (D_0032bae0 == 2056 || D_0032bae0 == 781) D_00341780 = 1;
    else D_00341780 = 2;
    D_003417d0 = -1;
    D_003417c4 = 0;
    D_003417c8 = 0;
    func_001127b0();
}

// Same pool scheme as func_0013aca0 (896-byte slots).
struct Pool13e { u8 pad[8064]; s32 free[9]; s32 n; };
struct G13e { u32 v; };
extern u8* D_003486a4;
extern G13e D_003486a0;
void func_0013e2d8(u8*, u32, u32);
u8* func_0013e610(u32 a) {
    Pool13e* p = (Pool13e*)D_003486a4;
    s32 n = p->n - 1;
    p->n = n;
    u8* r = (u8*)p + p->free[n] * 896;
    func_0013e2d8(r, a, D_003486a0.v + 32);
    return r;
}

s32 func_00228378(u8*, u8*);
s32 func_00147240(u8* p, u8* q, f32 f) {
    s32 r;
    if (func_00228378(p, q)) r = 0;
    else if (!p[1912]) r = 0;
    else if ((*(u32*)(q + 248) & 1) == 1) r = f < *(f32*)(p + 1908);
    else r = 0;
    return r;
}

struct T1ce { u32 a; u32 b; u32 c; };
struct F1ce { u32 a; u32 b; f32 c; };
extern T1ce D_01d5b9e0;
extern F1ce D_01d5b9f0;
void wtarget_001ce668(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_01d5b9e0.a = 0;
        D_01d5b9e0.b = 0;
        D_01d5b9e0.c = 0;
    }
    if (b == 0xffff && a == 1) {
        D_01d5b9f0.b = 0;
        D_01d5b9f0.c = 335.99997f;
        D_01d5b9f0.a = 0;
    }
}

// The original reloads p->f4 after the first store (no strict aliasing); the
// union destination reproduces that.
struct S22e { u8 pad[4]; s16 f4; u8 pad6[2]; u8 f8; u8 f9; s16 f10; s16 f12; };
union U22 { s32 i; s16 h; };
struct R22e { u8 pad[12]; U22 f12; U22 f16; u8 f20; u8 f21; };
s32 func_002282f0(s32);
R22e* func_00227d10(s32);
void func_0022efb8(S22e* p) {
    if (func_002282f0(p->f4)) return;
    R22e* r = func_00227d10(p->f12);
    r->f12.i = p->f4;
    r->f16.i = p->f4 + p->f10;
    r->f20 = p->f8;
    r->f21 = p->f9;
}

// Stores s into the first free (id == -1) of 128 table entries. Unions with a
// char member reproduce the original's reloads (built without strict aliasing).
union GU230 { u32 v; u8 c; };
union SH230 { s16 s; u16 h; u8 c; };
struct S230 { u8 pad[4]; SH230 id; SH230 a; SH230 b; };
struct E230 { s32 id; u16 a; u16 b; };
extern GU230 D_0035dce4;
void func_00230d78(S230* s) {
    for (s32 i = 0; i < 128; i++) {
        E230* e = (E230*)(i * 8 + D_0035dce4.v);
        if (e->id == -1) {
            e->id = s->id.s;
            ((E230*)(i * 8 + D_0035dce4.v))->a = s->a.h;
            ((E230*)(i * 8 + D_0035dce4.v))->b = s->b.h;
            return;
        }
    }
}

// Scales the alpha byte of an RGBA colour, clamped to 255.
struct C23 { u8 r, g, b, a; };
u32 func_002338a8(C23 c, f32 s) {
    if (s != 1.0f) {
        u32 v = (s32)((f32)((*(u32*)&c) >> 24) * s);
        if (v >= 256) c.a = 255;
        else c.a = v;
    }
    return *(u32*)&c;
}

extern u32 D_0035f57c;
extern u8 D_0035f580;
void func_0023f900(u32);
s32 func_00292630(void);
u32 func_00293db8(s32, s32);
void func_0023fa08(u32, u32);
void func_00294e48(void) {
    func_0023f900(D_0035f57c);
    if (func_00292630()) return;
    func_0023fa08(D_0035f57c, func_00293db8(1, 0));
    D_0035f580 = 1;
}
}
