#include "../common/types.h"

namespace w100_a1 {
extern "C" {
void func_0011b6a8(f32*);
void func_00106af0(f32*, f32*, f32, f32);

// Build projection (screen) matrix from camera params: out = view * proj, then two viewport setups.
// 00106c08: moved to src/naka/libkn/camera.cpp
}

}

namespace w100_a2 {
struct S20 { u32 w[5]; };
struct Obj { u8 pad[2548]; S20 s; u8 pad2[2940-2548-20]; u32 flags; };
extern "C" {
extern S20 D_003417b0;
void func_00190128(S20*);
s32 func_00190140(S20*);
void func_0010d918(Obj*, S20*, S20*);
}
static inline bool IsValid(S20* s) {
    bool ok = false;
    if (func_00190140(s)) ok = s->w[0] != 0;
    return ok;
}
extern "C" {
void func_001125d8(Obj* o, s32 mode, S20* src);  // 0x001125d8: definition moved into src/anon/unit_001117d8.cpp
}

}

namespace w100_a3 {
extern "C" {
void* func_0010c778(u32);
void func_00135aa0(void*);
u8* func_00111e38(u32);
void func_00194668(u8*);
void func_00194468(u8*);
void func_001c0e60(u8*);
u32 func_001762c0(u8*, s32);
void func_001c0d38(u8*, u8*, u32, u32);
void func_0016bd60(u8*, u32);
void func_00198970(u32);
void func_00112778(u32, u32);

void func_001195a8(u8* w) {
    u8* pl;
    s32 i;
    func_00135aa0(func_0010c778(*(u32*)(w + 4)));
    pl = func_00111e38(0);
    *(u32*)(pl + 1688) = 0;
    *(f32*)(pl + 60) = 1.0f;
    func_00194668(pl);
    if (w[1920]) func_00194468(pl);
    for (i = 0; i < 2; i++) {
        u8* m = ((u8**)(pl + 2808))[i];
        if (!m) continue;
        func_00194668(m);
        func_001c0e60(m);
        func_001c0d38(m, pl, func_001762c0(pl, i), 0);
        *(u32*)(m + 1688) = 0;
        if (*(u8*)(i + (u32)w + 1921)) func_00194468(m);
    }
    func_0016bd60(pl, 0);
    func_00198970(*(u32*)(w + 4));
    func_00112778(*(u32*)(w + 4), 0);
}
}

}

namespace w100_a5 {
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
static inline QWord Cross(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}

extern "C" {
void func_00128d40(const QWord* fwd, const QWord* up, QWord* out);  // 0x00128d40: definition moved into src/anon/unit_00128480.cpp
}

}

namespace w100_a6 {
extern "C" {
extern f32 D_004573e0;
extern f32 D_004573e4;
s32 func_00184478(u32);
f32 func_0013fd10(u8*);
f32 fabsf(f32);  // fabsf
f32 func_0017ce80(f32, f32, f32);
void func_00140150(u8*, f32);
}

extern "C" {
void func_00140210(u8* o, u8* b, f32 k);  // 0x00140210: definition moved into src/anon/unit_0013fca8.cpp
}

}

namespace w100_a9 {
extern "C" {
u32 func_00177860(u8*);
s32 func_001c3618(u32, s32);
s32 func_0019c090(u8*);  // obj_is_enabled
s32 func_001b9d40(u8*);  // vtable_call_slot64_flags
void func_0016aef0(u8*, u8*);
void func_0017f488(u8*, s32, f32, f32);
void func_0017f5e0(u8*, s32, s32, f32, f32);
u8* func_001ce300(s32);  // to_1ce2a0_index_minus1
void func_00176a60(u8*, f32);
}
static inline bool IsLocked(u8* o) {
    bool r = false;
    if ((*(u32*)(*(u8**)(o + 12) + 8) & 2) || (*(u32*)(o + 352) & 0x40)) r = true;
    return r;
}
static inline bool IsBusy(u8* o) {
    bool r = false;
    if (func_0019c090(o) || IsLocked(o)) r = true;
    return r;
}
static inline bool IsBusy2(u8* o) {
    if (func_0019c090(o)) return true;
    return IsLocked(o);
}
static inline bool IsBusy3(u8* o) {
    bool r = false;
    if (func_0019c090(o)) r = true;
    else if (IsLocked(o)) r = true;
    return r;
}
static inline bool CanAct(u8* o) { return !IsBusy3(o); }
static inline bool CanAct2(u8* o) { return IsBusy3(o) == false; }
static inline bool CanAct3(u8* o) { return !IsBusy(o); }

extern "C" {
// 00179530: moved to src/yasui/libys/player.cpp
}

}

namespace w100_a10 {
extern "C" {
extern char D_0036c5b0[];
extern s32 D_0034ec60;
u32 func_0016a080(u8*);
s32 func_002fee78(char*, const char*, ...);
void func_00180058(u8*, u32, char*, u32, u32, u32, f32);

// 001801b0: moved to src/yasui/libys/motion.cpp
}

}

namespace w100_a11 {
struct E11 { u32 a; u32 b; f32 t; };
extern "C" {
extern E11 D_01c608c0[64];
extern u32 D_003638d0;
u8* func_001b9bc8(u8*);
void func_001884d0(u8*, E11*);
}

extern "C" {
// 00188550: moved to src/anon/unit_00188550.cpp
void func_00188550(void);
}

}

namespace w100_a13 {
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
static inline QWord Cross(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}

static inline QWord Scale(const QWord& a, f32 s)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
extern "C" {
// Build a basis matrix from forward a and side b: rows cross(a,b), cross(-a,..), -a, identity w row.
void func_00193be8(void* self, const QWord* a, const QWord* b, QWord* m);  // 0x00193be8: definition moved into src/anon/unit_00193be8.cpp
}

}

namespace w100_a14 {
struct Bits14 { u16 f0 : 1; u16 f1 : 1; u16 rest : 14; };
struct Info14 { u8 type; u8 kind; u16 bits; f32 val; };
struct Obj14 { u32 flags; u8 pad[56]; Info14* info; };
static inline bool G00(Info14* d) { return d->bits & 1; }
static inline bool G01(Info14* d) { return (d->bits >> 1) & 1; }
static inline u8 G10(Info14* d) { return d->bits & 1; }
static inline u8 G11(Info14* d) { return (d->bits >> 1) & 1; }
static inline u8 G20(Info14* d) { u32 x = d->bits; return x & 1; }
static inline u8 G21(Info14* d) { u32 x = d->bits; return (x >> 1) & 1; }
static inline bool G30(Info14* d) { return (u32)d->bits & 1; }
static inline bool G31(Info14* d) { return ((u32)d->bits >> 1) & 1; }
static inline u8 G40(Info14* d) { return (u8)(d->bits & 1); }
static inline u8 G41(Info14* d) { return (u8)((u16)(d->bits >> 1) & 1); }
static inline bool G50(Info14* d) { return (d->bits & 1) != 0; }
static inline bool G51(Info14* d) { return (d->bits & 2) != 0; }

extern "C" {
extern u8 D_01c61b30[];
extern u32 D_0032b96c;
u32 func_0014aba8(void);
void func_0014aa58(u32, s32, s32);
void func_0015d540(void);
void func_002ef8d0(u8*, u32);
void func_002bc788(void);
void func_00196e88(Obj14*, s32, s32, f32);
}

extern "C" {
void func_00197148(Obj14* o);  // 0x00197148: definition moved into src/anon/unit_00195d00.cpp
}

}

namespace w100_a15 {
struct Sub15 { void** vt; u8 pad[92]; Sub15* next; u8 pad2[8]; u8* info; };
struct Obj15 { u32 f0; u32 b0 : 1; u32 b1 : 1; u32 b2 : 1; u32 b3 : 1; u32 b4 : 1; u32 rest : 27; u8* type; Sub15* head; u32 pad; f32 timer; };
static inline bool Off15(Obj15* o) { return o->b0; }
static inline Sub15* Next15(Obj15* o, Sub15* p) {
    if (!p) return o->head;
    return p->next;
}
extern "C" {
extern f32 D_00349e10;
void func_0019b180(Obj15*, u32);
s32 func_00191a50(Obj15*, u32);
s32 func_0019a1a0(Obj15*, Sub15*);

void func_0019a048(Obj15* o, u32 arg);  // 0x0019a048: definition moved into src/anon/unit_00199688.cpp
}

}

namespace w100_a16 {
struct Box16 {
    u32 f0;
    s32 b0 : 1; s32 b1 : 1; s32 b2 : 1; s32 b3 : 1; s32 b4 : 1; s32 rest : 27;
    u8 pad[24];
    f32 x0, x1, top, bottom, z1, z0;
};
static inline bool B1(Box16* b) { return b->b1; }
static inline bool B3(Box16* b) { return b->b3; }
static inline bool B4(Box16* b) { return b->b4; }
extern "C" {
f32 func_0016c4e8(u32);

// Point-in-box test with optional vertical offsets.
bool func_001a0800(Box16* b, u32 w, f32* d, f32 x, f32 y, f32 z);  // 0x001a0800: definition moved into src/anon/unit_0019fb70.cpp
}

}

namespace w100_a17 {
struct Ent17 { u32 f0; union { u32 flags; struct { u16 lo; u16 h6; }; }; u32 id; u32 dst; };
extern "C" {
extern u8 D_00350ca0[];
extern u32 D_00350c88;
Ent17* func_001ae460(u32);
s32 func_002f79c8(s32);
s32 func_002f7be8(u32, s32, u32, u8*);
void func_001ae620(void);
void func_001ae650(void);
void func_001ae678(void);  // to_306698_arg10
u32 func_002f7dc8(void);
void func_003058a0(s32);
void func_002efcc0(u32, u32, s32);

}

extern "C" {
u32 func_001adf00(u32 key, u32 buf);  // 0x001adf00: definition moved into src/anon/unit_001ada38.cpp

}

}

namespace w100_a18 {
struct Ent18 { u8 b0[5]; u8 kind; u8 pad[6]; };
struct Seq18 { u8 pad[12]; Ent18 e[1]; };
struct Hdr18 { u8 pad[108]; s32 cur; };
struct Obj18 { void** vt; u8 pad[28]; u32 flags; u8 pad2[2240 - 36]; Hdr18** seq; };
static inline Ent18* Cur18(Hdr18* h) { return (Ent18*)((u8*)h + h->cur * 12 + 12); }
static inline bool IsWait18(Ent18* e) { return e->kind < 4; }
extern "C" {
s32 func_001bc710(Ent18*);
void func_002ba2e8(s32, s32);
s32 func_001bcf18(Hdr18*);
s32 func_001bcf38(Hdr18*);  // state_in_set_5_10_13to18
void func_001bc730(Hdr18*, s32);
void func_001bd618(Obj18*, s32);
}
static inline bool Done18(Hdr18* h) {
    bool r = false;
    if (func_001bcf18(h) || func_001bcf38(h)) r = true;
    return r;
}
extern "C" {
void func_001bd988(Obj18* o);  // 0x001bd988: definition moved into src/anon/unit_001bc568.cpp
}

}

namespace w100_a21b {
// float->double promotion libcall is the game's own copy at 0x313b80
asm("fptodp = func_00313b80");
extern "C" {
extern char D_00370c20[];
s32 func_002fdfc8(const char*, ...);  // device_vprintf_va
void func_002234c0(const char* name, f32* m);  // 0x002234c0: definition moved into src/anon/unit_00222aa8.cpp
}

}

namespace w100_a22 {
struct M22 { f32 m[12]; f32 t[4]; } __attribute__((aligned(16)));
extern "C" {
union Cam22 { u8* p; f32 f; };
extern Cam22 D_01d9e6e8;
extern u8 D_00354bd0[];
extern f32 D_00354bc0[3];
void func_0021ec80(void*, void*);
void sceVu0InversMatrix(M22*, M22*);  // convert_vectors_to_scalar
void sceVu0MulMatrix(void*, void*, void*);
}
static inline void ScaleRow(void* row, f32 s) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(row), "r"(s) : "memory");
}
extern "C" {
void func_002010b0(u8* o, u32 a1, u8* x) {
    s32* off = *(s32**)(x + 12);
    M22 m;
    u8* mtx = o + off[3] + 160;
    f32* scl = (f32*)(o + off[2] + 160);
    f32* pos = (f32*)(o + off[0] + 160);
    func_0021ec80(D_01d9e6e8.p + 16, o + off[1] + 160);
    *(f32*)(D_01d9e6e8.p + 64) = pos[0];
    *(f32*)(D_01d9e6e8.p + 68) = pos[1];
    *(f32*)(D_01d9e6e8.p + 72) = pos[2];
    func_0021ec80(&m, D_00354bd0);
    m.t[0] = D_00354bc0[0];
    m.t[1] = D_00354bc0[1];
    m.t[2] = D_00354bc0[2];
    sceVu0InversMatrix(&m, &m);  // convert_vectors_to_scalar
    sceVu0MulMatrix(D_01d9e6e8.p + 16, D_01d9e6e8.p + 16, mtx);
    sceVu0MulMatrix(D_01d9e6e8.p + 16, &m, D_01d9e6e8.p + 16);
    ScaleRow(D_01d9e6e8.p + 16, scl[0]);
    ScaleRow(D_01d9e6e8.p + 32, scl[1]);
    ScaleRow(D_01d9e6e8.p + 48, scl[2]);
}
}

}
