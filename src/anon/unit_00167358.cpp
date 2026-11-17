#include "../common/types.h"

// Pad and IOP module start-up (0x167358-0x168218): IRX loading from cdrom0:, the two DualShock2 pad
// slots (0x34d3c0, 384 B each) with their button-mapping filters (0x34d6c0, 96 B each), the
// mapping-table stack and the static init of both slot arrays. Incl. the never-written functions
// 0x167468 (load a file through the IOP), 0x167c10 / 0x168040 (slot "active" tests) and the
// getter 0x167fb8. Each function keeps the declarations of the source it was matched in
// (namespace pN); every symbol is bound by asm label.

extern "C" s32 strlen(const char*);
extern "C" s32 toupper(s32 c);

// ---- globals (.data 0x34d3c0) ----
void PadClear_g(void*, u64) asm("_Z16wtarget_00167658jjjj");
void PadList_g(void*) asm("_Z13func_0031a830Pv");
inline void* operator new(unsigned int, void* p) { return p; }
struct PadQ { u8 b[16]; ~PadQ() {} } __attribute__((aligned(16)));
struct PadBase {
    u64 m[4];
    PadQ v[2];
    u32 x40;
    PadBase() { PadClear_g(this, 0); }
};
struct PadSlot : PadBase { u8 pad[384 - 80]; };
struct PadFilter : PadBase {
    u32 x44;
    u32 x48;
    u32 x4c;
    u8 pad50[16];
    PadFilter() { x44 = 0; PadList_g(&x48); x4c = 0; }
};
PadSlot D_0034d3c0[2];
PadFilter D_0034d6c0[2];
s32 D_0034d780 = 0;

// ---- file statics (.bss 0x4f4250) ----
static u8 s_cdCbBuf[0x1000] asm("D_004f4250") __attribute__((used));
static s32 s_tableIdx asm("D_004f5250") __attribute__((used));
static u32 s_tableStack[4] asm("D_004f5258") __attribute__((used));
static f32 s_deadZone asm("D_004f5268") __attribute__((used, aligned(4)));
static f32 s_repeatDelay asm("D_004f526c") __attribute__((used, aligned(4)));
static f32 s_repeatRate asm("D_004f5270") __attribute__((used, aligned(4)));

// 001672c8: first function of this file (buffer alloc + SIF DMA + free), never written before
namespace p_1672c8 {
void* func_0030d8a8(u32) asm("func_0030d8a8");
s32 func_00308310(void*, s32) asm("func_00308310");
void func_0030e508(void*, u32, u32) asm("func_0030e508");
void func_0030da10(void*) asm("func_0030da10");
struct DmaT { u32 src; void* dst; u32 size; u32 attr; };
void func_001672c8(u32 src, s32 n, u32 a, u32 b) asm("func_001672c8");
void func_001672c8(u32 src, s32 n, u32 a, u32 b) {
    u32 size = n << 4;
    void* buf = func_0030d8a8(size);
    DmaT d;
    d.src = src;
    d.dst = buf;
    d.size = size;
    d.attr = 0;
    func_00308310(&d, 1);
    func_0030e508(buf, a, b);
    func_0030da10(buf);
}
}

// 00167358 (src/anon/batch_w250.cpp)
namespace p0 {
extern char D_0036b600[] asm("D_0036b600");
char* func_002ff2e8(char*, const char*) asm("func_002ff2e8");
char* func_002feee8(char*, const char*) asm("func_002feee8");
s32 func_0030e770(char*, u32, u32) asm("func_0030e770");
void wtarget_00167358(u32 a0, u32 a1, u32 a2, u32) asm("_Z16wtarget_00167358jjjj");
void wtarget_00167358(u32 a0, u32 a1, u32 a2, u32) {
  char buf[256];
  func_002ff2e8(buf, D_0036b600);
  func_002feee8(buf, (const char*)a0);
  s32 n0 = strlen(D_0036b600);  // strlen
  s32 n = strlen(buf);  // strlen
  for (s32 i = n0; i < n; i++) {
    char* p = &buf[i];
    if (*p == '/') *p = '\\';
    else *p = toupper(*p);
  }
  while (func_0030e770(buf, a1, a2) < 0) {}
}
}  // namespace p0

// 00167448 (src/anon/tiny_wrappers_more.cpp)
namespace p1 {
u32 func_00167358(u32, u32, u32, u32) asm("func_00167358");
u32 func_00167448(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00167358(a0, 0x00000000u, 0x00000000u, a3);
}
}  // namespace p1

// 00167468 (never written): read a file through the IOP file server.
namespace p2 {
s32 func_0030e3d8(const char*) asm("func_0030e3d8");
void func_0030e140(s32, u32, u32, void*) asm("func_0030e140");
void func_0030e348(s32) asm("func_0030e348");
void func_00167468(const char* path, u32 a1, u32 a2) {
    u8 st[16];
    s32 fd = func_0030e3d8(path);
    if (fd >= 0) {
        func_0030e140(fd, a1, a2, st);
        func_0030e348(fd);
    }
}
}  // namespace p2

// 001674c8 (src/anon/batch_w8015.cpp)
namespace p3 {
void func_00167448(const char*) asm("func_00167448");
void sceCdInitEeCB(s32, void*, s32) asm("sceCdInitEeCB");
void sceCdInit(s32) asm("sceCdInit");
void func_002f7f18(s32) asm("func_002f7f18");
void func_00308b30(s32) asm("func_00308b30");
void func_0030a690() asm("func_0030a690");
s32 func_0030ec50() asm("func_0030ec50");
s32 func_0030eca0(const char*) asm("func_0030eca0");
extern u8 D_004f4250[] asm("D_004f4250");

// IRX module load list. The two pad2/ds2o.irx loads are a 2-iteration loop:
// gcc fully unrolls it and hoists only %hi of the string into s0.
void func_001674c8(void) {
    func_00308b30(0);
    func_0030a690();
    sceCdInit(0);
    func_002f7f18(2);
    while (func_0030eca0("cdrom0:\\IOPRP300.IMG") == 0) {}
    while (func_0030ec50() == 0) {}
    func_00308b30(0);
    sceCdInit(0);
    sceCdInitEeCB(10, D_004f4250, 0x1000);
    func_002f7f18(2);
    func_00167448("sio2man.irx");
    func_00167448("sio2d.irx");
    func_00167448("dbcman.irx");
    for (int i = 0; i < 2; i++) func_00167448("pad2/ds2o.irx");
    func_00167448("mcman.irx");
    func_00167448("mcserv.irx");
    func_00167448("libsd.irx");
    func_00167448("libssl.irx");
}
}  // namespace p3

// 16 bytes: the float literals after it sit 8-aligned in retail.
extern "C" const char D_0036b600[16] = "cdrom0:\\";

// 001675b0 (src/anon/batch_w39.cpp)
namespace p4 {
void func_00167638(f32, f32, f32) asm("func_00167638");
void func_00167b98(void) asm("func_00167b98");
void func_00167c30(void) asm("func_00167c30");
void func_00167618(void) asm("func_00167618");
extern u32 D_0032b91c asm("D_0032b91c");
void func_00102788(u32, u32, u32, void (*)(void)) asm("func_00102788");
void func_001675b0(void) {
    func_00167638(60.0f, 30.0f, 4.0f);
    func_00167b98();
    func_00167c30();
    func_00102788(D_0032b91c, 0, 0x1adb0, func_00167618);
}
}  // namespace p4

// 00167618 (src/anon/tiny_jal_tail_wrappers.cpp)
namespace p5 {
u32 func_00167b60() asm("func_00167b60");
u32 func_00167e70() asm("func_00167e70");
u32 func_00167618(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_00167b60();
    return func_00167e70();
}
}  // namespace p5

// 00167638 (src/anon/batch_w3.cpp)
namespace p6 {
extern f32 D_004f5268 asm("D_004f5268");
extern f32 D_004f526c asm("D_004f526c");
extern f32 D_004f5270 asm("D_004f5270");
void func_00167638(f32 x, f32 y, f32 z) {
    D_004f5268 = x;
    D_004f526c = y;
    D_004f5270 = z;
}
}  // namespace p6

// 00167658 (src/anon/batch_w28.cpp)
namespace p7 {
void wtarget_00167658(u32, u64, u32, u32) asm("_Z16wtarget_00167658jjjj");
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
}  // namespace p7

// 001676b0 (src/anon/sweep_001676b0_nsa.cpp)
namespace p8 {
extern f32 D_00349e10 asm("D_00349e10");
extern f32 D_004f526c asm("D_004f526c");
extern f32 D_004f5270 asm("D_004f5270");
typedef struct S2 { s64 cur, trg, rel, rep; u8 pad[0x20]; f32 t; } S2;
void func_001676b0(S2* p, s64 v) {
    s64 x;
    p->rep = 0;
    x = p->cur ^ v;
    p->cur = v;
    p->trg = x & v;
    p->rel = x & ~v;
    if (p->trg) { p->t = D_004f526c; p->rep = p->trg; return; }
    if (v) {
        p->t -= D_00349e10;
        if (p->t <= 0.0f) { p->t = D_004f5270; p->rep = v; }
    }
}
}  // namespace p8

// 00167728 (src/anon/tiny_jal_wrappers_reloc.cpp)
namespace p9 {
u32 func_002f5d18(u32, u32, u32, u32) asm("func_002f5d18");
extern u8 D_0034d7b0 asm("D_0034d7b0");
u32 func_00167728(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u, r16 = 0u;
    *(u8*)((u32)r4 + (s32)(69)) = (u8)0u;
    r15 = (u32)&D_0034d7b0;
    *(u8*)((u32)r4 + (s32)(68)) = (u8)0u;
    r14 = (u32)(r5 << 5);
    *(u32*)((u32)r4 + (s32)(72)) = 0u;
    r16 = r4;
    r14 = (u32)(r14 + r15);
    r5 = (u32)((s32)r4 + (128));
    r4 = r14;
    r2 = func_002f5d18(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(76)) = r2;
    return r2;
}
}  // namespace p9

// 00167778 (src/anon/batch_w8019.cpp)
namespace p10 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
extern f32 D_004f5268 asm("D_004f5268");
u32 func_00167778(u8* self, u8* in) {
    QWord* out = (QWord*)(self + 0x20);
    u32 mask = 0;
    for (s32 i = 0; i < 2; i++) {
        QWord v;
        for (s32 j = 0; j < 2; j++) {
            *(f32*)((u8*)&v + (j << 2)) = in[i * 2 + j + 2] - 127.5f;
            if (*(f32*)((u8*)&v + (j << 2)) > 0.0f) {
                *(f32*)((u8*)&v + (j << 2)) -= D_004f5268;
                if (*(f32*)((u8*)&v + (j << 2)) < 0.0f) *(f32*)((u8*)&v + (j << 2)) = 0.0f;
                else { u32 nm = ((j + 1) << (i * 4 + 16)) | mask; mask = nm; }
            } else {
                *(f32*)((u8*)&v + (j << 2)) += D_004f5268;
                if (*(f32*)((u8*)&v + (j << 2)) > 0.0f) *(u32*)((u8*)&v + (j << 2)) = 0;
                else { u32 nm = ((j + 1) << (i * 4 + 18)) | mask; mask = nm; }
            }
            *(f32*)((u8*)&v + (j << 2)) /= 127.5f - D_004f5268;
        }
        v.v[2] = 0;
        f32 len = Normalize(&v);
        if (len > 1.0f) len = 1.0f;
        v.f[3] = len;
        *out = v;
        out++;
    }
    return mask;
}
#undef QCOPY
}  // namespace p10

// Button-mapping tables (.rodata 0x36b628): {required buttons, result bits} pairs, zero-terminated.
extern "C" const u64 D_0036b628[] = {
    0xf09ull, 0x1ull,
    0x8ull, 0x2ull,
    0x1000000ull, 0x4ull,
    0x2000000ull, 0x8ull,
    0x10ull, 0x10ull,
    0x800000ull, 0x10ull,
    0x40ull, 0x20ull,
    0x200000ull, 0x20ull,
    0x80ull, 0x40ull,
    0x400000ull, 0x40ull,
    0x20ull, 0x80ull,
    0x100000ull, 0x80ull,
    0x0ull, 0x0ull,
};
extern "C" const u64 D_0036b6f8[] = {
    0x2000000ull, 0x100ull,
    0x8000ull, 0x200ull,
    0x1000ull, 0x400ull,
    0x1ull, 0x400000ull,
    0x10ull, 0x4000ull,
    0x40ull, 0x8000ull,
    0x80ull, 0x10000ull,
    0x20ull, 0x10000000ull,
    0x400ull, 0x800000ull,
    0x2000ull, 0x1000000ull,
    0x1000ull, 0x2000000ull,
    0x8000ull, 0x4000000ull,
    0x4000ull, 0x8000000ull,
    0x800ull, 0x800ull,
    0x400ull, 0x400000000ull,
    0x100ull, 0x400000000ull,
    0x800ull, 0x800000000ull,
    0x200ull, 0x800000000ull,
    0x200ull, 0x100000000ull,
    0x40200ull, 0x1000000000ull,
    0x10200ull, 0x2000000000ull,
    0x4080000ull, 0x40000ull,
    0x4020000ull, 0x80000ull,
    0x4040000ull, 0x100000ull,
    0x4010000ull, 0x200000ull,
    0x4080000ull, 0x20000000ull,
    0x4020000ull, 0x40000000ull,
    0x4000004ull, 0x20000ull,
    0x8080000ull, 0x4000ull,
    0x8020000ull, 0x8000ull,
    0x8040000ull, 0x10000ull,
    0x8010000ull, 0x10000000ull,
    0x8000004ull, 0x200000000ull,
    0x0ull, 0x0ull,
};
extern "C" const u64 D_0036b918[] = {
    0x1000000ull, 0x100ull,
    0x1000000ull, 0x200ull,
    0x2000000ull, 0x400ull,
    0x8000ull, 0x800ull,
    0x1000ull, 0x1000ull,
    0x200ull, 0x2000ull,
    0x100ull, 0x4000ull,
    0x400ull, 0x8000ull,
    0x800ull, 0x10000ull,
    0x20000ull, 0x20000ull,
    0x40000ull, 0x8000ull,
    0x10000ull, 0x10000ull,
    0x1ull, 0x40000ull,
    0x10ull, 0x80000ull,
    0x40ull, 0x100000ull,
    0x80ull, 0x200000ull,
    0x20ull, 0x400000ull,
    0x1000ull, 0x8000000ull,
    0x10ull, 0x10000000ull,
    0x800000ull, 0x10000000ull,
    0x40ull, 0x20000000ull,
    0x200000ull, 0x20000000ull,
    0x0ull, 0x0ull,
};
extern "C" const u64 D_0036ba88[] = {
    0x800ull, 0x100ull,
    0x400ull, 0x200ull,
    0x1000ull, 0x400ull,
    0x0ull, 0x0ull,
};
extern "C" const u64 D_0036bac8[] = {
    0x10ull, 0x100ull,
    0x40ull, 0x200ull,
    0x80ull, 0x400ull,
    0x20ull, 0x800ull,
    0x800ull, 0x2000ull,
    0x400ull, 0x1000ull,
    0x8000ull, 0x4000ull,
    0x1ull, 0x8000ull,
    0x1000ull, 0x10000ull,
    0x0ull, 0x0ull,
};
extern "C" const u64 D_0036bb68[] = {
    0x10ull, 0x100ull,
    0x40ull, 0x200ull,
    0x80ull, 0x400ull,
    0x20ull, 0x800ull,
    0x800000ull, 0x1000ull,
    0x200000ull, 0x2000ull,
    0x400000ull, 0x4000ull,
    0x100000ull, 0x8000ull,
    0x80000ull, 0x10000ull,
    0x20000ull, 0x20000ull,
    0x40000ull, 0x40000ull,
    0x10000ull, 0x80000ull,
    0x800ull, 0x100000ull,
    0x200ull, 0x200000ull,
    0x4ull, 0x400000ull,
    0x1000ull, 0x800000ull,
    0x8ull, 0x1000000ull,
    0x8000ull, 0x2000000ull,
    0x400ull, 0x4000000ull,
    0x1000ull, 0x8000000ull,
    0x400ull, 0x10000000ull,
    0x100ull, 0x20000000ull,
    0x2ull, 0x40000000ull,
    0x800ull, 0x80000000ull,
    0x8000ull, 0x100000000ull,
    0x1000ull, 0x200000000ull,
    0x1ull, 0x400000000ull,
    0x1ull, 0x800000000ull,
    0x800ull, 0x1000000000ull,
    0x400ull, 0x2000000000ull,
    0x800ull, 0x4000000000ull,
    0x400ull, 0x8000000000ull,
    0x800ull, 0x10000000000ull,
    0x400ull, 0x20000000000ull,
    0x1000ull, 0x40000000000ull,
    0x0ull, 0x0ull,
};
extern "C" const u64 D_0036bda8[] = {
    0x10ull, 0x100ull,
    0x40ull, 0x200ull,
    0x80ull, 0x400ull,
    0x20ull, 0x800ull,
    0x8ull, 0x2000ull,
    0x0ull, 0x0ull,
};
extern "C" const u64 D_0036be08[] = {
    0x8ull, 0x100ull,
    0x1000ull, 0x200ull,
    0x8ull, 0x400ull,
    0x8000ull, 0x800ull,
    0x1000ull, 0x1000ull,
    0x1ull, 0x2000ull,
    0x800ull, 0x4000ull,
    0x400ull, 0x8000ull,
    0x200ull, 0x10000ull,
    0x100ull, 0x20000ull,
    0x10000ull, 0x40000ull,
    0x40000ull, 0x80000ull,
    0x1000ull, 0x100000000ull,
    0x8000ull, 0x200000000ull,
    0x0ull, 0x0ull,
};
extern "C" const u64 D_0036bef8[] = {
    0x800ull, 0x100ull,
    0x400ull, 0x200ull,
    0x8000ull, 0x400ull,
    0x4000ull, 0x800ull,
    0x0ull, 0x0ull,
};

// Mapping-table set per index (.data 0x34d788), current extra table, dbc socket params and send tag.
const u64* D_0034d788[9] = {
    0, D_0036b6f8, D_0036b918, D_0036ba88, D_0036bac8, D_0036bb68, D_0036bda8, D_0036be08, D_0036bef8,
};
const u64* D_0034d7ac = 0;
u32 D_0034d7b0[2][8] = { { 2, 0, 0, 0, 0, 0, 0, 0 }, { 2, 1, 0, 0, 0, 0, 0, 0 } };
u32 D_0034d7f0[4] = { 3, 0, 0, 0 };

// 001678f0 (src/anon/batch_w112.cpp)
namespace p11 {
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
s32 func_002f6020(s32) asm("func_002f6020");
s32 func_002f5f50(s32, u8*) asm("func_002f5f50");
s32 func_002f5e78(s32, u8*) asm("func_002f5e78");
s32 func_00105c30(void) asm("func_00105c30");
s32 func_00242bd0(void) asm("func_00242bd0");
s32 func_00242a00(void) asm("func_00242a00");
u64 func_00167778(Pad*, u8*) asm("func_00167778");
void func_00167ad0(Pad*, u32) asm("func_00167ad0");
void func_001676b0(Pad*, u64) asm("func_001676b0");
void func_00167658(Pad*, u32) asm("func_00167658");
static inline bool IsJp(s32 st) { return func_00105c30() == st || func_00105c30() == 8; }
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
}  // namespace p11

// 00167ad0 (src/anon/tiny_auto80_queue.cpp)
namespace p12 {
u32 func_002f65a8(...) asm("func_002f65a8");
extern u8 D_0034d7f0 asm("D_0034d7f0");
u32 func_00167ad0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // sif_send_tag
    u32 p0 = a1;
    return func_002f65a8(
        *(u32*)((u32)a0 + (s32)(76)),
        (u32)((s32)0u + (1)),
        (u32)&D_0034d7f0,
        (u32)((s32)0u + (2)),
        (u32)&p0,
        a5,
        a6,
        a7
    );
}
}  // namespace p12

// 00167b08 (src/anon/batch_w24.cpp)
namespace p13 {
void func_00167ad0(u8*, u32) asm("func_00167ad0");
extern u8 D_0034d3c0[] asm("D_0034d3c0");
void u_call4_00167b08(u32, u32, u32, u32) asm("_Z16u_call4_00167b08jjjj");
void u_call4_00167b08(u32 a, u32, u32, u32) {
    for (u8* p = D_0034d3c0; (s32)p < (s32)(D_0034d3c0 + 768); p += 384)
        func_00167ad0(p, a);
}
}  // namespace p13

// 00167b60 (src/anon/batch_w18.cpp)
namespace p14 {
extern u8 D_0034d3c0[] asm("D_0034d3c0");
u8 func_001678f0(void*) asm("func_001678f0");
u8 func_00167b60(void) {
    func_001678f0(D_0034d3c0);
    return func_001678f0(D_0034d3c0 + 384);
}
}  // namespace p14

// 00167b98 (src/anon/batch_w25.cpp)
namespace p15 {
struct S384 { u8 d[384]; };
extern S384 D_0034d3c0[] asm("D_0034d3c0");
void sceDbcInit(void) asm("sceDbcInit");
void func_002f5c70(u32) asm("func_002f5c70");
void func_00167728(S384*, s32) asm("func_00167728");
void func_00167b98(void) {
    s32 i;
    sceDbcInit();
    func_002f5c70(0);
    for (i = 0; i < 2; i++) func_00167728(&D_0034d3c0[i], i);
}
}  // namespace p15

// 00167bf0 (src/anon/tiny_auto80_solver.cpp)
namespace p16 {
extern u8 D_0034d3c0 asm("D_0034d3c0");
u32 func_00167bf0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // entry384_get
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r14 = (u32)((s32)0u + (384));
    r4 = (u32)(r4 * r14);
    r15 = (u32)&D_0034d3c0;
    r4 = (u32)(r4 + r15);
    r2 = r4;
    return r2;
}
}  // namespace p16

// 00167c10 (never written): is pad slot i active.
namespace p17 {
struct Slot { u8 pad[80]; u32 x50; u8 pad2[384 - 84]; };
extern Slot D_0034d3c0[] asm("D_0034d3c0");
u32 func_00167c10(s32 i) {
    return D_0034d3c0[i].x50 != 0;
}
}  // namespace p17

// 00167c30 (src/anon/batch_w39.cpp)
namespace p18 {
struct S167a { u8 pad[68]; void* p; u8 pad2[24]; };
struct S167b { u8 pad[384]; };
extern S167a D_0034d6c0[] asm("D_0034d6c0");
extern S167b D_0034d3c0[] asm("D_0034d3c0");
extern s32 D_004f5250 asm("D_004f5250");
extern u32 D_0034d780 asm("D_0034d780");
void func_00167f38(int) asm("func_00167f38");
void func_00167c30(void) {
    for (int i = 0; i < 2; i++) D_0034d6c0[i].p = &D_0034d3c0[i];
    D_004f5250 = -1;
    D_0034d780 = 0;
    func_00167f38(0);
}
}  // namespace p18

// 00167c90 (src/anon/tiny_auto80_queue.cpp)
namespace p19 {
u64 func_00167c90(u32 a0, u32 a1) {  // flag_test_table
    u64 t5 = *(u64*)((u32)*(u32*)((u32)a0 + (s32)(68)) + (s32)(0));
    u64 v0 = 0ull;
    u64 t6 = *(u64*)((u32)a1 + (s32)(0));
    while (t6 != 0ull) {
        if ((t5 & t6) == t6) v0 |= *(u64*)((u32)a1 + (s32)(8));
        a1 += 16;
        u64 t7 = *(u64*)((u32)a1 + (s32)(0));
        if (t7 == 0ull) break;
        t6 = t7;
    }
    return v0;
}
}  // namespace p19

// 00167cd0 (src/anon/batch_w59.cpp)
namespace p20 {
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
u32 func_00167c90(u8*, void*) asm("func_00167c90");
extern u8 D_0036b628[] asm("D_0036b628");
extern void* D_0034d7ac asm("D_0034d7ac");
u32 func_00167cd0(u8* p) {
    u32 r = func_00167c90(p, D_0036b628);
    if (D_0034d7ac) r |= func_00167c90(p, D_0034d7ac);
    *(Vec4*)(p + 32) = *(Vec4*)(*(u8**)(p + 68) + 32);
    *(Vec4*)(p + 48) = *(Vec4*)(*(u8**)(p + 68) + 48);
    return r;
}
#undef QCOPY
}  // namespace p20

// 00167d68 (src/anon/batch_w60.cpp)
namespace p21 {
void func_00167658(void*, s32) asm("func_00167658");
u64 func_00167cd0(void*) asm("func_00167cd0");
void func_001676b0(void*, u64) asm("func_001676b0");
struct Flags167 { u32 a : 1; u32 b : 1; };
static inline bool flagA167(u8* p) { return ((Flags167*)(p + 72))->a; }
void func_00167d68(u8* p) {
    if (flagA167(p)) {
        func_00167658(p, 0);
    } else {
        u64 v = func_00167cd0(p);
        if (*(u32*)(p + 72) & 2) *(u64*)p = v;
        func_001676b0(p, v);
        if (*(s32*)(*(u8**)(p + 68) + 72) == 1) {
            *(u32*)(p + 72) &= ~2;
            return;
        }
    }
    *(u32*)(p + 72) |= 2;
}
}  // namespace p21

// 00167e00 (src/anon/tiny_wrappers_more.cpp)
namespace p22 {
u32 func_00167658(u32, u32, u32, u32) asm("func_00167658");
u32 func_00167e00(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(a0) + 72u) = (u32)(((u32)(((u32)(*(u32*)((u32)(a0) + 72u)))) | 0x1u));
    return func_00167658(a0, 0x00000000u, a2, a3);
}
}  // namespace p22

// 00167e28 (src/anon/batch_w31.cpp)
namespace p23 {
void func_00167658(void*, int) asm("func_00167658");
u64 func_00167cd0(void*) asm("func_00167cd0");
void func_00167e28(u8* p) {
    *(u32*)(p + 72) &= ~1;
    func_00167658(p, 0);
    *(u64*)p = func_00167cd0(p);
}
}  // namespace p23

// 00167e70 (src/anon/batch_w19.cpp)
namespace p24 {
u8 func_00167d68(void*) asm("func_00167d68");
extern u8 D_0034d6c0[] asm("D_0034d6c0");
u32 func_00167e70(void) {
    func_00167d68(D_0034d6c0);
    return func_00167d68(D_0034d6c0 + 96);
}
}  // namespace p24

// 00167ea8 (src/anon/batch_w20.cpp)
namespace p25 {
u8 func_00167e00(void*) asm("func_00167e00");
extern u8 D_0034d6c0[] asm("D_0034d6c0");
s32 func_00167ea8(void) {
    func_00167e00(D_0034d6c0);
    return func_00167e00(D_0034d6c0 + 96);
}
}  // namespace p25

// 00167ee0 (src/anon/batch_w21.cpp)
namespace p26 {
void func_00167e28(void*) asm("func_00167e28");
extern u8 D_0034d6c0[] asm("D_0034d6c0");
// Run func_00167e28 on both 96-byte entries of D_0034d6c0.
void func_00167ee0(void) {
    u8* p = D_0034d6c0;
    for (s32 i = 0; i < 2; i++) {
        func_00167e28(p);
        p += 96;
    }
}
}  // namespace p26

// 00167f18 (src/anon/tiny_auto80_solver.cpp)
namespace p27 {
extern u8 D_0034d6c0 asm("D_0034d6c0");
u32 func_00167f18(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r14 = (u32)((s32)0u + (96));
    r4 = (u32)(r4 * r14);
    r15 = (u32)&D_0034d6c0;
    r4 = (u32)(r4 + r15);
    r2 = r4;
    return r2;
}
}  // namespace p27

// 00167f38 (src/anon/batch_w63.cpp)
namespace p28 {
void func_00167658(void*, s32) asm("func_00167658");
extern u32 D_0034d788[] asm("D_0034d788");
extern u32 D_0034d7ac asm("D_0034d7ac");
extern u8 D_0034d6c0[] asm("D_0034d6c0");
extern s32 D_004f5250 asm("D_004f5250");
void func_00167f38(s32 idx) {
    D_0034d7ac = D_0034d788[idx];
    u8* p = D_0034d6c0;
    u8* end = p + 192;
    do {
        func_00167658(p, 255);
        p += 96;
    } while ((s32)p < (s32)end);
    D_004f5250 = idx;
}
}  // namespace p28

// 00167fb8 (never written): current mapping-table index.
namespace p29 {
extern s32 D_004f5250 asm("D_004f5250");
s32 func_00167fb8(void) {
    return D_004f5250;
}
}  // namespace p29

// 00167fc8 (src/anon/batch_w17.cpp)
namespace p30 {
extern u32 D_004f5250 asm("D_004f5250");
extern u32 D_004f5258[] asm("D_004f5258");
extern s32 D_0034d780 asm("D_0034d780");
void func_00167f38(void) asm("func_00167f38");
void func_00167fc8(void) {
    D_004f5258[D_0034d780++] = D_004f5250;
    func_00167f38();
}
}  // namespace p30

// 00168008 (src/anon/batch_w22.cpp)
namespace p31 {
extern s32 D_0034d780 asm("D_0034d780");
extern u32 D_004f5258[] asm("D_004f5258");
void func_00167f38(u32) asm("func_00167f38");
void func_00168008(void) {
    func_00167f38(D_004f5258[--D_0034d780]);
}
}  // namespace p31

// 00168040 (never written): is the slot behind filter i active.
namespace p32 {
struct Slot { u8 pad[80]; u32 x50; };
struct Filter { u8 pad[68]; Slot* slot; u8 pad2[96 - 72]; };
extern Filter D_0034d6c0[] asm("D_0034d6c0");
u32 func_00168040(s32 i) {
    return D_0034d6c0[i].slot->x50 != 0;
}
}  // namespace p32

// 00168068 / 001681d8 / 001681f8: static init and I/D stubs of D_0034d3c0 / D_0034d6c0, made by gcc.
