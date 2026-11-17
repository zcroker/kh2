#include "../common/types.h"

// 0x1b1d20-0x1b2728: two object classes (ctor pairs storing the vtables 0x350e98 and 0x350f28,
// with their update hooks), the YS::ITEMPIC loader task ("itempic/item-%03d.imd", .bss buffer
// 0x1d44440) and the path-buffer list (nodes linked at +24 into D_01d48c80) with its static
// initialiser 0x1b26e0 and _GLOBAL__I_ stub 0x1b2708. The two functions after the stub
// (0x1b2728, 0x1b2778) belong to the next file and stay outside.

typedef unsigned int u128 __attribute__((mode(TI)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCOPYN(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")

// 001b1d20 (from src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n001b1d20 {
u32 func_00185b00(u32, u32, u32, u32) asm("func_00185b00");
u32 func_001b1d20(u32, u32, u32, u32) asm("func_001b1d20");
extern u8 D_00350e98 asm("D_00350e98");
u32 func_001b1d20(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001b1d20");
u32 func_001b1d20(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_00185b00(r4, r5, r6, r7);
    r14 = *(u32*)((u32)r16 + (s32)(1416));
    r15 = (u32)&D_00350e98;
    r14 = (u32)(r14 | 0x0800u);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r16 + (s32)(1416)) = r14;
    return r2;
}
}  // namespace n001b1d20

// 001b1d60 (from src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n001b1d60 {
u32 func_00185b00(u32, u32, u32, u32) asm("func_00185b00");
extern u8 D_00350e98 asm("D_00350e98");
u32 func_001b1d60(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001b1d60");
u32 func_001b1d60(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_00185b00(r4, r5, r6, r7);
    r14 = *(u32*)((u32)r16 + (s32)(1416));
    r15 = (u32)&D_00350e98;
    r14 = (u32)(r14 | 0x0800u);
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    *(u32*)((u32)r16 + (s32)(1416)) = r14;
    return r2;
}
}  // namespace n001b1d60

// 001b1da0 (from src/anon/auto80_199_queue.cpp)
namespace n001b1da0 {
u32 func_0016bff0(...) asm("_ZN2YS3OBJ10get_serialEv");
u32 func_001991a8(...) asm("func_001991a8");
u32 func_0017f488(...) asm("func_0017f488");
void func_00185d10(u32 a0) asm("func_00185d10");
void func_001b1da0(u32 a0) asm("func_001b1da0");
void func_001b1da0(u32 a0) {
    u32 s0 = a0;

    u32 v0 = func_0016bff0(a0);
    func_001991a8(75, v0);

    f32 f12 = 0.0f;
    u32 t6 = *(u32*)(s0 + 12);
    u32 t7 = *(u32*)(t6 + 4);
    t7 ^= 0x17;
    if (t7 == 0) {
        ((void(*)(u32, u32, f32, f32))func_0017f488)(s0 + 320, 16, f12, f12);
    }

    return func_00185d10(s0);
}
}  // namespace n001b1da0

// 001b1e00 (gap, never written): update hook of the 0x350e98 class
namespace n001b1e00 {
s32 func_0019baa8(u8*) asm("func_0019baa8");
void func_001cc160(u8*, u32) asm("func_001cc160");
void func_001bfcc8(u8*, u32) asm("func_001bfcc8");
void func_00186020(u8*) asm("func_00186020");
void func_001b1e00(u8* o) asm("func_001b1e00");
void func_001b1e00(u8* o) {
    if (func_0019baa8(o) == 0 && (*(u32*)(o + 2040) & 4)) {
        func_001cc160(o, *(u32*)(o + 2760));
        func_001bfcc8(o, *(u32*)(o + 2764));
    }
    func_00186020(o);
}
}  // namespace n001b1e00

// 001b1e58 (from src/anon/tiny.cpp)
namespace n001b1e58 {
extern u32 D_01d48c40 asm("D_01d48c40");
extern u32 D_01d48c44 asm("D_01d48c44");
void func_001b1e58(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001b1e58");
void func_001b1e58(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    D_01d48c40 = a0;
    D_01d48c44 = 0;
}
}  // namespace n001b1e58

// 001b1e70 (was src/yasui/libys/itempic.cpp)
namespace n001b1e70 {
u32 ITEMPIC_GetSequenceData() asm("_ZN2YS7ITEMPIC15GetSequenceDataEv");
u32 ITEMPIC_GetSequenceData() {
    u32 b = (0x01d5u << 16);
    return (u32)(*(u32*)((u32)b + (-29632)));
}
}  // namespace n001b1e70

// 001b1e80 (from src/anon/batch_w45.cpp)
namespace n001b1e80 {
struct Tk { u32 f0; s32 id; };
Tk* func_00102818_t(u32, u32, u32, void*, u32) asm("func_00102818");
extern s32 D_00350f1c asm("D_00350f1c");
extern u32 D_0032b91c asm("D_0032b91c");
extern Tk* D_01d48c44 asm("D_01d48c44");
void func_001b1ee8(void) asm("func_001b1ee8");
void func_001b1e80(s32 id) asm("func_001b1e80");
void func_001b1e80(s32 id) {
    if (id == -1 || id == D_00350f1c) return;
    Tk* t = func_00102818_t(D_0032b91c, 0, 0x55730, (void*)func_001b1ee8, 4096);
    D_01d48c44 = t;
    asm volatile("" ::: "memory");
    t->id = id;
}
}  // namespace n001b1e80

// 001b1ee8 (from src/anon/batch_w85.cpp)
namespace n001b1ee8 {
extern s32 D_00350f18 asm("D_00350f18");
extern u32 D_00350f1c asm("D_00350f1c");
extern char D_0036d9a8[] asm("D_0036d9a8");
extern u8 D_01d44440[] asm("D_01d44440");
extern u32 D_01d44400 asm("D_01d44400");
extern u32 D_01d48c44 asm("D_01d48c44");
void func_00102448(void*, s32) asm("func_00102448");
void func_002fee78(char*, const char*, ...) asm("func_002fee78");
void func_001688c8(char*) asm("func_001688c8");
void func_00168388(char*, void*, s32, s32) asm("func_00168388");
s32 func_001688b8(void) asm("func_001688b8");
void func_001b1ee8(u8* o) asm("func_001b1ee8");
void func_001b1ee8(u8* o) {
    char buf[48];
    u32 v;
    while (D_00350f18) func_00102448(o, 0);
    D_00350f18 = 1;
    v = *(u32*)(o + 4);
    func_002fee78(buf, D_0036d9a8, v);
    func_001688c8(buf);
    func_00168388(buf, D_01d44440, 0, 0);
    while (func_001688b8()) func_00102448(o, 0);
    D_00350f1c = v;
    D_00350f18 = 0;
    D_01d44400 = 0;
    D_01d48c44 = 0;
}
s32 func_001688b8(void) asm("func_001688b8");
}  // namespace n001b1ee8

// 001b1fc8 (from src/anon/batch_w9.cpp)
namespace n001b1fc8 {
extern u32 D_00350f18 asm("D_00350f18");
extern u32 D_00350f1c asm("D_00350f1c");
u32 func_001b1fc8(u32 a) asm("func_001b1fc8");
u32 func_001b1fc8(u32 a) {
    return D_00350f18 == 0 && D_00350f1c == a;
}
}  // namespace n001b1fc8

// 001b1ff0 (from src/anon/batch_w20.cpp)
namespace n001b1ff0 {
extern u32 D_00350f18 asm("D_00350f18");
extern u32 D_01d44400 asm("D_01d44400");
extern u8 D_01d44440[] asm("D_01d44440");
u8* func_001b1ff0(s32 a) asm("func_001b1ff0");
u8* func_001b1ff0(s32 a) {
    if (a == -1) return 0;
    D_00350f18 = 2;
    D_01d44400++;
    return D_01d44440;
}
}  // namespace n001b1ff0

// 001b2028 (from src/anon/tiny_auto80_queue.cpp)
namespace n001b2028 {
void func_001b2028() asm("func_001b2028");
void func_001b2028() {
    u32* c = (u32*)0x01D40000;
    u32 v = c[4352] - 1;
    if (((c[4352] = v), v) == 0) {
        u32* g = (u32*)0x00350000;
        g[966] = 0;
    }
}
}  // namespace n001b2028

// 001b2050 (from src/anon/tiny_auto80_solver.cpp)
namespace n001b2050 {
u32 func_001d7cd0(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001d7cd0");
extern u8 D_00350f28 asm("D_00350f28");
u32 func_001b2050(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001b2050");
u32 func_001b2050(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 s0 = a0;
    u32 r = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_001d7cd0)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 vtbl = (u32)&D_00350f28;
    u32 m1 = *(u32*)(s0 + 1416);
    u32 m2 = *(u32*)(s0 + 2748);
    *(u32*)s0 = vtbl;
    m1 |= 0x8000;
    m2 |= 4;
    *(u32*)(s0 + 1416) = m1;
    u32 three = 3;
    *(u32*)(s0 + 944) = three;
    *(u32*)(s0 + 2748) = m2;
    return r;
}
}  // namespace n001b2050

// 001b20a0 (from src/anon/tiny_auto80_solver.cpp)
namespace n001b20a0 {
u32 func_001d7cd0(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_001d7cd0");
extern u8 D_00350f28 asm("D_00350f28");
u32 func_001b20a0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_001b20a0");
u32 func_001b20a0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 s0 = a0;
    u32 r = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_001d7cd0)(a0, a1, a2, a3, a4, a5, a6, a7);
    u32 vtbl = (u32)&D_00350f28;
    u32 m1 = *(u32*)(s0 + 1416);
    u32 m2 = *(u32*)(s0 + 2748);
    *(u32*)s0 = vtbl;
    m1 |= 0x8000;
    m2 |= 4;
    *(u32*)(s0 + 1416) = m1;
    u32 three = 3;
    *(u32*)(s0 + 944) = three;
    *(u32*)(s0 + 2748) = m2;
    return r;
}
}  // namespace n001b20a0

// 001b20f0 (from src/anon/tiny.cpp)
namespace n001b20f0 {
union BD_VALUE;
void func_0017c578(void*) asm("func_0017c578");
void func_001b20f0(BD_VALUE* bd) asm("func_001b20f0");
void func_001b20f0(BD_VALUE* bd) { func_0017c578(bd); }
}  // namespace n001b20f0

// 001b2108 (gap, never written)
namespace n001b2108 {
s32 func_0017cb48(void*, u8*) asm("func_0017cb48");
u8 func_0017cb78(void*, u8*) asm("func_0017cb78");
void func_001b2108(void* s, u8* o) asm("func_001b2108");
struct NoTail { ~NoTail() {} };
void func_001b2108(void* s, u8* o) {
    NoTail nt;
    if (func_0017cb48(s, o)) {
        if (0.0f <= *(f32*)(o + 36) + *(f32*)(o + 244) * 5.0f) func_0017cb78(s, o);
    }
}
}  // namespace n001b2108

// 001b2170 (from src/anon/batch_w67.cpp)
namespace n001b2170 {
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(const Vec4& o) { QCOPYN(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
extern f32 D_00349e10 asm("D_00349e10");
Vec4 func_00184540(u8*, f32, f32) asm("func_00184540");
Vec4 func_001b2170(void* self, u8* o) asm("func_001b2170");
Vec4 func_001b2170(void* self, u8* o)
{
    f32 y0 = *(f32*)(o + 36);
    Vec4 r;
    r = func_00184540(o, *(f32*)(o + 240), *(f32*)(o + 240));
    f32 v = y0 + *(f32*)(o + 244) * D_00349e10;
    f32 m = *(f32*)(o + 288);
    f32 c;
    if (v < m) c = v; else c = m;
    *(f32*)(o + 36) = c;
    r.y = c * D_00349e10;
    return r;
}
}  // namespace n001b2170

// 001b2210 (from src/anon/batch_w85.cpp)
namespace n001b2210 {
struct Vec4 {
    f32 x, y, z, w;
    Vec4& operator=(const Vec4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
void func_0017f488(u8*, s32, f32, f32) asm("func_0017f488");
void func_0017f5e0(u8*, s32, s32, f32, f32) asm("func_0017f5e0");
static inline void vu_scale_to(void* d, const void* s, f32 k) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
static inline f32 vu_normalize(void* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\t"
                 "vsqrt Q, $vf2x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\t"
                 "vdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
void func_0017c400(u8*, s32) asm("func_0017c400");
void func_001b2210(u8* o, Vec4* dir, f32 speed, f32 h) asm("func_001b2210");
void func_001b2210(u8* o, Vec4* dir, f32 speed, f32 h) {
    f32 y = dir->y;
    f32 w = dir->w;
    f32 g;
    dir->y = 0.0f;
    vu_normalize(dir);
    g = (y + y) / (speed * speed);
    *(f32*)(o + 240) = h;
    *(f32*)(o + 244) = g;
    func_0017c400(o, 2);
    {
        Vec4* dst = (Vec4*)(o + 192);
        Vec4 t;
        vu_scale_to(&t, dir, w);
        *dst = t;
    }
    *(f32*)(o + 204) = 1.0f;
    *(f32*)(o + 196) = -g * speed;
}
}  // namespace n001b2210

// 001b2308 (from src/anon/batch_w45.cpp)
namespace n001b2308 {
struct Lnk { u32 f0; u32 f4; u32 f8; u32 f12; f32 f16; void* f20; struct Lnk* next; };
struct LList { Lnk* head; Lnk* tail; };
void* func_001050d8(u32) asm("func_001050d8");
extern LList D_01d48c80 asm("D_01d48c80");
void func_001b2308(Lnk* a0, u32 n) asm("func_001b2308");
void func_001b2308(Lnk* a0, u32 n) {
    a0->f4 = 0;
    a0->f0 = n;
    a0->f16 = 50.0f;
    a0->f8 = 0;
    a0->f12 = 0;
    a0->f20 = func_001050d8(n << 4);
    asm volatile("" ::: "memory");
    LList* l = &D_01d48c80;
    if (l->tail == 0) {
        l->tail = a0;
        l->head = a0;
        a0->next = 0;
    } else {
        l->tail->next = a0;
        a0->next = 0;
        l->tail = a0;
    }
}
}  // namespace n001b2308

// 001b2380 (from src/anon/batch_w46.cpp)
namespace n001b2380 {
struct Buf1b2 { u32 n; u32 f4; u32 f8; u32 fc; f32 f10; void* data; Buf1b2* next; };
struct List1b2 { Buf1b2* head; Buf1b2* tail; };
extern List1b2 D_01d48c80 asm("D_01d48c80");
void* func_001050d8(u32) asm("func_001050d8");
void func_001b2380(Buf1b2* p, u32 n) asm("func_001b2380");
void func_001b2380(Buf1b2* p, u32 n) {
    p->f4 = 0;
    p->n = n;
    p->f10 = 50.0f;
    p->f8 = 0;
    p->fc = 0;
    p->data = func_001050d8(n << 4);
    asm volatile("" ::: "memory");
    if (!D_01d48c80.tail) { D_01d48c80.tail = p; D_01d48c80.head = p; p->next = 0; }
    else { D_01d48c80.tail->next = p; p->next = 0; D_01d48c80.tail = p; }
}
}  // namespace n001b2380

// 001b23f8 (gap, never written): D2 of the path buffer; frees the data and unlinks the node
// (D1 0x1b2488 calls the out-of-line list remove 0x3201e8 instead).
namespace n001b23f8 {
struct Nd { u32 f0, f4, f8, fc; f32 f10; void* data; Nd* next; };
struct Ls { Nd* head; Nd* tail; };
extern Ls D_01d48c80 asm("D_01d48c80");
void func_00105110(void*) asm("func_00105110");
void func_001b23f8(Nd* p) asm("func_001b23f8");
void func_001b23f8(Nd* p) {
    func_00105110(p->data);
    Nd* prev;
    if (p == D_01d48c80.head) {
        D_01d48c80.head = p->next;
        prev = 0;
    } else {
        prev = D_01d48c80.head;
        while (prev->next != p) prev = prev->next;
        prev->next = p->next;
    }
    if (p == D_01d48c80.tail) D_01d48c80.tail = prev;
    p->next = 0;
}
}  // namespace n001b23f8

// 001b2488 (from src/anon/batch_w13.cpp)
namespace n001b2488 {
void func_00105110(void*) asm("func_00105110");
void func_003201e8(void*, void*) asm("func_003201e8");
extern u8 D_01d48c80 asm("D_01d48c80");
void func_001b2488(u8* p) asm("func_001b2488");
void func_001b2488(u8* p) {
    func_00105110(*(void**)(p + 20));
    func_003201e8(&D_01d48c80, p);
}
}  // namespace n001b2488

// 001b24c0 (from src/anon/misc_1.cpp)
namespace n001b24c0 {
void func_001b24c0(void* self) asm("_Z13func_001b24c0Pv");
void func_001b24c0(void* self) {}
}  // namespace n001b24c0

// 001b24c8 (from src/anon/batch_w55.cpp)
namespace n001b24c8 {
extern u8* D_01d48c80 asm("D_01d48c80");
void func_001b2488(u8*) asm("func_001b2488");
void func_00105110(void*) asm("func_00105110");
void func_001b24c8(void) asm("func_001b24c8");
void func_001b24c8(void) {
    u8* n = D_01d48c80;
    while (n) {
        u8* next = *(u8**)(n + 24);
        if (n) {
            func_001b2488(n);
            func_00105110(n);
        }
        n = next;
    }
}
}  // namespace n001b24c8

// 001b2520 (from src/anon/batch_w56.cpp)
namespace n001b2520 {
struct Ring { s32 cap; s32 count; s32 head; u32 pad[2]; u128* buf; };
void func_001b2520(Ring* r, u128* v) asm("func_001b2520");
void func_001b2520(Ring* r, u128* v)
{
    u128* d = r->buf + r->head;
    if (d != v) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(v) : "$8", "memory");
    s32 n = r->head + 1;
    r->count = n < r->count ? r->count : n;
    r->head = n % r->cap;
}
}  // namespace n001b2520

// 001b2578 (from src/anon/batch_w68.cpp)
namespace n001b2578 {
struct Vec128 {
    u128 q;
    Vec128() {}
    Vec128(const Vec128& o) : q(o.q) {}
    Vec128& operator=(const Vec128& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
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
Vec128* func_001b2578(Path29* p, Vec128* pos) asm("func_001b2578");
Vec128* func_001b2578(Path29* p, Vec128* pos) {
    Vec128 e;
    Vec128 d;
    vsub3(&d, &p->pts[p->idx], pos);
    e = d;
    if (vlen(&e) <= p->radius) p->idx = (p->idx + 1) % p->n;
    return &p->pts[p->idx];
}
}  // namespace n001b2578

// 001b2618 (from src/anon/batch_w77.cpp)
namespace n001b2618 {
struct Pt { f32 x, y, z; };
struct Src { u16 f0; u16 n; u8 pad[4]; Pt p[1]; };
Src* func_00182e08(void) asm("func_00182e08");
u8* func_001050d8(s32) asm("func_001050d8");
void func_001b2380(u8*, u16) asm("func_001b2380");
void func_001b2520(u8*, f32*) asm("func_001b2520");
u8* func_001b2618(void) asm("func_001b2618");
u8* func_001b2618(void)
{
    s32 i = 0;
    Src* s = func_00182e08();
    u8* o = func_001050d8(28);
    func_001b2380(o, s->n);
    for (; i < s->n; i++) {
        f32 v[4];
        v[0] = s->p[i].x;
        v[1] = s->p[i].y;
        v[2] = s->p[i].z;
        v[3] = 1.0f;
        func_001b2520(o, v);
    }
    return o;
}
u8* func_001050d8(s32) asm("func_001050d8");
}  // namespace n001b2618

// 001b26e0 (from src/anon/batch_w10.cpp)
namespace n001b26e0 {
struct L26e0 { u32 a, b; };
extern L26e0 D_01d48c80 asm("D_01d48c80");
void wtarget_001b26e0(u32, u32, u32, u32) asm("_Z16wtarget_001b26e0jjjj");
void wtarget_001b26e0(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001b26e0jjjj");
void wtarget_001b26e0(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_01d48c80.b = 0;
        D_01d48c80.a = 0;
    }
}
}  // namespace n001b26e0

// 001b2708 (from src/anon/tiny_wrappers_more.cpp)
namespace n001b2708 {
u32 func_001b26e0(u32, u32, u32, u32) asm("_Z16wtarget_001b26e0jjjj");
u32 func_001b2708(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001b2708");
u32 func_001b2708(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001b26e0(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n001b2708

