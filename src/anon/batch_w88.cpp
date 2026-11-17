#include "../common/types.h"

// 16-byte aligned vector / matrix used with VU0 macro code.
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4 { V4 r[4]; } __attribute__((aligned(16)));
// A local of this type disables sibling calls (keeps jal + epilogue).
struct NoTail { ~NoTail() {} };

static inline void QCOPY(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline void VAssign(V4* d, V4* s) {
    if (d != s) QCOPY(d, s);
}
static inline void ApplyM(V4* d, M4* m, V4* v) {
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(d), "r"(m), "r"(v) : "memory");
}
static inline void ApplyTo(V4* d, M4* m, V4* v) {
    V4 t;
    ApplyM(&t, m, v);
    VAssign(d, &t);
}

u32 wtarget_00105620(u32, u32, u32, u32) asm("_Z16wtarget_00105620jjjj");
void wtarget_0017a7e0(u32, u32, u32, u32) asm("_Z16wtarget_0017a7e0jjjj");
void u_tail0_001917d0(void) asm("_Z16u_tail0_001917d0v");

extern "C" {
// --- callees
void func_00190128(void*);
s32 func_00168aa0(u32, u32);
u8* func_00168b38(u32, u32, s32);  // entry_array_find_nth
void func_0031ae58(void*, void*);
u32 func_001050c8(void);
u8* func_001063c0(u32, u32);
void func_00239700(u8*);
u32 func_0013e678(void);
void func_0015b368(u8*, u32, u32, u32);
void func_001391a8(u8*, V4*);  // vec_copy_at416_if_diff
void func_0014f648(u32);
void func_001bcf80(u8*);
void func_0019c920(u8*);
void func_0031e2b8(u8*);
void func_0019c9a8(u8*);
void func_001d48b0(u8*);
s32 func_00132f98(void*, u32, u32*, u32, u32);
s32 func_001d7ba8(u8*);
s32 func_00105300(void);
s32 func_001c8db8(u8*, u32);
void func_00191cd8(void);
s32 func_001918c8(void);
void func_00191938(s32);
void func_001a3710(void);
void func_0019ba60(u32);
s32 func_001a1c30(u8*);
void func_001d6f28(s32);
void func_001c11a8(u32);
void func_0014c9f0(u32);
void func_00239870(u8*);
void func_0031e668(u8*);
void func_001ac5b8(u8*);
void func_001bd988(u32);
u32 func_0016ac38(u8*, u32, u32, u32, u32);
void func_001dc840(u32);
void func_001940f0(u8*, u32);
void func_00194108(u8*, u32);
s32 func_002282f0(u16);
u8* func_00227d10(s16);
f32 func_00227c78(u8*);
u32 func_00227ca8(u8*);
u32 func_0016f000(u32, V4*, f32);
f32 sinf(f32);
f32 cosf(f32);
s32 func_00240440(u32);  // round_up_1024
u32 func_001058e8(void);
void memcpy(void*, u32, u32);
u8 func_00241e18(void);
u32 func_00241ed8(u8);
u32 func_002409b8(u8*);
s32 func_00139d78(u32);
s32 func_0023f0c0(u32);
void func_0023f070(u32, s32, s32);
s32 func_0028acc8(u32);
void func_0028ab20(u32);
u32 func_002891e8(u32);
u8* func_0024e008(u32);
void func_0028da70(u32, u32);
s32 func_001a6d08(u32);
void func_0028d980(u32, u32, u32, u32, u32, u32, u32, s32, u32);
void func_00139620(u32);
void func_001395f8(u32);
void func_002fde18(u32, u32, u32);
void func_0024e228(void);
void func_00106420(void*);
void func_0031abd8(u8*);
void func_0031acc0(u8*);
void func_0031a840(u8*);
void func_002361d0(u8*);
s32 func_001396c0(u8*);
s32 func_0028acc8p(u8*) asm("func_0028acc8");
s32 func_00239d30i(u8*, u32) asm("func_00239d30");
void func_00290d68(u32, u32);
void func_00290f78(u32);
u32 func_00291380(u32, u32);
void func_00291510(u32, u32, u32, u32);
void func_00291918(u32, u32, u32, u32, u32);
void func_00291de0(u32, u32, u32, u32, u32, u32, u32);
s32 func_00287cd0(void);
s32 func_00289310(u32);
void func_002890e0(u32, u32, u32, u32, s32);
void func_00289038(u32, u32, u32, u32, u32, u32, s32);
s32 func_00289358(u32);
void func_002b5c30(u32);
s32 func_0028d008(u32);
u32 func_002891d0(u32);
void func_0028cf28(u32, u32);  // record408_set_and_refresh
u32 func_001708f8(u32, s32);
u32 func_002ca3d0(u8*, u32);
void func_0023eea0(u8*, u32, u32, u32, u32, u32);
void func_0023ef50(u8*);
void func_0023f0c8(u8*, u32);
void func_002ca828(u8*);
void func_001391c8(u8*, u32, u32);
void func_0031c9f8(u8*);
void func_0031c980(u8*);
void func_0031c8e8(u8*);
void func_0031cec0(u8*);

// --- data
struct E13a6f8 { u32 x, y; };
struct T13a6f8 { u32 data; s32 count; E13a6f8 e[1]; };
extern T13a6f8 D_00347fb0;
extern u8 D_003b8bc0[];
extern u8 D_00347fd8[];
extern u8 D_004193c0[];
extern u8* D_004f35a0;
extern u8 D_00347e60[];
extern u8 D_0034ab80[];
extern u8 D_01c5f530[];
extern u8 D_00351260[];
extern u8 D_00351228[];
extern u8 D_00351ec8[];
extern s32 D_01c61958;
extern f32 D_01c6195c;
extern f32 D_01c61960;
extern f32 D_00349e10;
extern u8 D_00350a70[];
extern u8 D_00350ab0[];
extern u8 D_00350bb0[];
extern u8 D_00350a56;
extern u64 D_0036dc48[];
struct S84 { u32 w[21]; };
struct B240 { u64 lo : 32; u64 b : 8; u64 f : 1; u64 rest : 23; };
extern u8* D_0035ec90;
extern S84 D_0035ec30;
extern u32 D_0035edd4;
extern u32 D_0035edcc;
extern u32 D_0035eddc;
extern u32 D_0035edd8;
extern u32 D_0035ede0;
extern u32 D_0035ede4;
extern u32 D_0035edf8;
extern u8* D_0035f2b0;
extern u8* D_0035f2b4;
extern u8* D_0035f2b8;
extern u32 D_0035f64c;
extern u8 D_0034a700[];
extern u8 D_00347f98[];
extern u8 D_0034a848[];
extern u8 D_00348608[];
extern u32 D_00347f80;

typedef void (*Dtor)(u8*);

s32 func_00133078(void* a, u32* tab, u32, u32 n, u32 x);  // 0x00133078: definition moved into src/anon/unit_00131418.cpp

// 0013a6f8: moved to src/harata/libdk/field2dd.cpp

// 001589d0: moved to src/harata/libdk/bookcamera.cpp

void func_0015b680(V4* pos, u32 a, u32 b);  // 0x0015b680: definition moved into src/anon/unit_0015b100.cpp

static inline bool Bit187920(u32 x, u32 m) { return (x & m) != 0; }
// Nonzero when any blocking flag/condition is set.
// 00187920: moved to src/anon/unit_00185d10.cpp
s32 func_00187920(u8* p);

void func_001a1b68(u8* p, f32 d);  // 0x001a1b68: definition moved into src/anon/unit_0019fb70.cpp

// 001ad738: moved to src/anon/unit_001abb28.cpp

struct E1bcc28 { u16 pad; u16 id; u8 pad2[2]; u8 kind; u8 pad3[5]; };
struct T1bcc28 { u32 pad; u32 owner; s32 n; E1bcc28 e[8]; s32 sel; };
void func_001bcc28(T1bcc28* p);  // 0x001bcc28: definition moved into src/anon/unit_001bc568.cpp

union U1c1a30 { f32 f; u8* p; u8 b; };
// 001c1a30: moved to src/anon/unit_001c0638.cpp
void func_001c1a30(u8* p, U1c1a30** out);

void func_001cf9e0(u8* p, s32 mode);  // 0x001cf9e0: definition moved into src/anon/unit_001cf0b0.cpp

typedef void (*VF233490)(u8*, V4*, u32);
void func_00233490(u8* p);  // 0x00233490: definition moved into src/anon/unit_00232f08.cpp

void func_00237988(u8* p, f32 z);  // 0x00237988: definition moved into src/anon/unit_00237068.cpp

s32 func_002408d0(u32 mode);  // 0x002408d0: definition moved into src/anon/unit_0023f5b8.cpp

void func_00240a70(u8* p);  // 0x00240a70: definition moved into src/anon/unit_0023f5b8.cpp

#define SETANIM(o, id) if (func_00139d78(o)) { if (func_0023f0c0(o) != (id)) func_0023f070(o, id, -1); }
void func_0024d4a0(void);  // 0x0024d4a0: definition moved into src/anon/unit_0024cda8.cpp

static inline void Or8(u8* o) { *(u32*)(o + 184) |= 8; }
void func_0024e158(void);  // 0x0024e158: definition moved into src/anon/unit_0024cda8.cpp

typedef void (*VF2830b8)(u8*);
void func_002830b8(void);  // 0x002830b8: definition moved into src/anon/unit_00282c68.cpp

s32 func_0028ad50(u8* p);  // 0x0028ad50: definition moved into src/anon/unit_00288b00.cpp

void func_00291110(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);  // 00291110: moved to src/anon/unit_00290f78.cpp

void func_002b5b38(u32 a, s32 b, u32 c);  // 0x002b5b38: definition moved into src/anon/unit_002b3ac8.cpp

struct T2caa50 { u8 d[32]; };
void func_0023f800(T2caa50*);
void func_0023fa08(T2caa50*, u32);
u32 func_0023f948(T2caa50*, u32);
u32 func_0023f908(T2caa50*, u32);
void func_0023f848(T2caa50*);
void func_002caa50(u8* p, u32 a, u32 b);  // 0x2caa50: moved to src/anon/unit_002ca0e0.cpp


// Class with a vtable: implicit assignment copies every field but the vptr.
struct C2ef258 { virtual void f(); u32 a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14; f32 b, c, d, e; u32 g; u8 h; u32 i, j; };
// 002ef258: moved to src/anon/unit_002ef1f8.cpp

static inline void Dtor1cb58a(u8* self) {
    if (self + 8 != 0) {
        u8* e = self + 2408;
    l:
        if (self + 8 != e) { e -= 600; func_0031c9f8(e); goto l; }
    }
}
static inline void Dtor1cb58b(u8* self) {
    if (self + 8 != 0) {
        u8* e = self + 2408;
    l:
        if (self + 8 != e) { e -= 600; func_0031c980(e); goto l; }
    }
}
static inline void Dtor1cb58c(u8* self) {
    if (self + 8 != 0) {
        u8* e = self + 9608;
    l:
        if (self + 8 != e) { e -= 600; func_0031c8e8(e); goto l; }
    }
}
void func_0031cb58(u8* o) {
    *(u32*)o = (u32)D_0034a700;
    Dtor1cb58a(o + 12076);
    Dtor1cb58b(o + 9656);
    Dtor1cb58c(o + 36);
    *(u32*)o = (u32)D_00347f98;
}

typedef void (*VF31d1b8)(u8*, u8*);
void func_0031d1b8(u8* o) {
    *(u32*)o = (u32)D_0034a848;
    if (o + 2576 != 0) {
        u8* e = o + 5536;
    l1:
        if (o + 2576 != e) { e -= 592; (*(Dtor*)(*(u8**)e + 12))(e); goto l1; }
    }
    if (o + 916 != 0) {
        u8* e = o + 2564;
    l2:
        if (o + 916 != e) { e -= 412; (*(Dtor*)(*(u8**)e + 12))(e); goto l2; }
    }
    *(u32*)o = (u32)D_00348608;
    func_0031cec0(o + 64);
    *(u32*)o = (u32)D_00347f98;
    u8* m = *(u8**)(D_00347f80 + 20);
    (*(VF31d1b8*)(*(u8**)m + 4))(m, o);
}

struct E19ad58 { u8 pad[12]; u32 obj; u8 pad2[24]; u8 kind; u8 pad3; u16 id; u8 pad4[16]; u8 lv; u8 pad5[3]; };
struct T19ad58 { u8 pad[4]; u16 n; u8 pad2[26]; E19ad58 e[1]; };
s32 func_0019ac30(u8*, u16);
u8* func_0016e920(u32);
// The table pointer is re-read from p+8 on every access.
#define TAB19ad58 (*(T19ad58**)(p + 8))
s32 func_0019ad58(u8* p);  // 0x0019ad58: definition moved into src/anon/unit_00199688.cpp

struct E1ce0a8 { u8 a; u8 b; s8 link; u8 c; u8 pad[4]; u16 id; u8 rest[58]; };
struct T1ce0a8 { s32 n; E1ce0a8 e[1]; };
s32 func_001d7f40(T1ce0a8*, s32);  // find_slot_by_byte
static inline u32 Bit1ce0a8(u32* b, u32 i) { return b[i >> 5] & (1 << (i & 31)); }
#define TAB1ce0a8 (*(T1ce0a8**)(p + 68))
// 001ce0a8: moved to src/anon/unit_001cd660.cpp
E1ce0a8* func_001ce0a8(u8* p);

extern char D_00374470[];
u8* func_00192cc0(u8*, const char*);
s32 func_00192b30(u8*);
s32 func_00105c30(void);
// Fill dst with n copies of a formatted string (5 unless mode 1/8); the last copy keeps its NUL.
u8* func_0028def0(u8* dst, s32 n);  // 0028def0: moved to src/anon/unit_0028c878.cpp

// Relocate a node tree in place: type -1 = group of child offsets (recursed),
// type 0 = table whose entry pointers (+116) are rebased from base to p.
u8* func_00131f48(u8* p, u32 base);  // 0x00131f48: definition moved into src/anon/unit_00131418.cpp

struct F1213c0 { u8 st : 2; u8 rest : 6; };
struct EA1213c0 { u32 lo : 6; u32 kind : 5; u32 hi : 21; u8 pad[28]; };
struct EB1213c0 { u32 kind : 5; u32 hi : 27; u8 pad[28]; };
struct TA1213c0 { u8 pad[28]; s32 n; EA1213c0 e[1]; };
struct TB1213c0 { u8 pad[28]; s32 n; EB1213c0 e[1]; };
TB1213c0* func_00120800(u8*);  // obj_get_sub_ptr_by12
// Mark every entry of the given kind (-1 = all) in both tables as state 1.
void func_001213c0(u8* p, F1213c0* fl, s32 kind);  // 0x001213c0: definition moved into src/anon/unit_00120520.cpp

} // extern "C"

u32 wtarget_00105620(u32 a, u32 b, u32, u32) {
    register u32 save asm("$4") = a;
    register u32 load asm("$5") = b;
    asm volatile(
        "sq $28, 0(%0)\n\tsq $29, 16(%0)\n\tsq $30, 32(%0)\n\tsq $31, 48(%0)\n\t"
        "sq $16, 64(%0)\n\tsq $17, 80(%0)\n\tsq $18, 96(%0)\n\tsq $19, 112(%0)\n\t"
        "sq $20, 128(%0)\n\tsq $21, 144(%0)\n\tsq $22, 160(%0)\n\tsq $23, 176(%0)\n\t"
        "swc1 $f20, 192(%0)\n\tswc1 $f21, 196(%0)\n\tswc1 $f22, 200(%0)\n\tswc1 $f23, 204(%0)\n\t"
        "swc1 $f24, 208(%0)\n\tswc1 $f25, 212(%0)\n\tswc1 $f26, 216(%0)\n\tswc1 $f27, 220(%0)\n\t"
        "swc1 $f28, 224(%0)\n\tswc1 $f29, 228(%0)\n\tswc1 $f30, 232(%0)\n\tswc1 $f31, 236(%0)\n\t"
        "lq $28, 0(%1)\n\tlq $29, 16(%1)\n\tlq $30, 32(%1)\n\tlq $31, 48(%1)\n\t"
        "lq $16, 64(%1)\n\tlq $17, 80(%1)\n\tlq $18, 96(%1)\n\tlq $19, 112(%1)\n\t"
        "lq $20, 128(%1)\n\tlq $21, 144(%1)\n\tlq $22, 160(%1)\n\tlq $23, 176(%1)\n\t"
        "lwc1 $f20, 192(%1)\n\tlwc1 $f21, 196(%1)\n\tlwc1 $f22, 200(%1)\n\tlwc1 $f23, 204(%1)\n\t"
        "lwc1 $f24, 208(%1)\n\tlwc1 $f25, 212(%1)\n\tlwc1 $f26, 216(%1)\n\tlwc1 $f27, 220(%1)\n\t"
        "lwc1 $f28, 224(%1)\n\tlwc1 $f29, 228(%1)\n\tlwc1 $f30, 232(%1)\n\tlwc1 $f31, 236(%1)"
        : : "r"(save), "r"(load) : "memory");
    return 2;
}

void wtarget_0017a7e0(u32 init, u32 prio, u32, u32) {
    NoTail g;
    if (prio == 0xffff && init == 1) {
        func_001bcf80(D_01c5f530);
        *(u32*)D_01c5f530 = (u32)D_00351260;
        func_00190128(D_01c5f530 + 2664);
        func_00190128(D_01c5f530 + 2684);
        func_00190128(D_01c5f530 + 2704);
        func_0019c920(D_01c5f530 + 2752);
        func_0031e2b8(D_01c5f530 + 2800);
    }
    if (prio == 0xffff && init == 0) {
        u8* o = D_01c5f530;
        func_0019c9a8(o + 2752);
        *(u32*)D_01c5f530 = (u32)D_00351228;
        func_001d48b0(o + 2496);
    }
}

// 001917d0: moved to src/yasui/libys/status.cpp

