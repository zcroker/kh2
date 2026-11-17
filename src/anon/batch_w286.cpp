#include "../common/types.h"
#define QCOPY_bfa0(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV_bfa0 {
    f32 x, y, z, w;
    QV_bfa0() {}
    QV_bfa0(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV_bfa0(const QV_bfa0& o) { QCOPY_bfa0(this, &o); }
    QV_bfa0& operator=(const QV_bfa0& o) { if (this != &o) QCOPY_bfa0(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline f32 normalize_bfa0(QV_bfa0* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline QV_bfa0 operator-(const QV_bfa0& a, const QV_bfa0& b) {
    QV_bfa0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QV_bfa0 operator+(const QV_bfa0& a, const QV_bfa0& b) {
    QV_bfa0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QV_bfa0 cross_bfa0(const QV_bfa0& a, const QV_bfa0& b) {
    QV_bfa0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void scale_bfa0(QV_bfa0* v, f32 k) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(v), "f"(k) : "$8", "memory");
}
struct Act_bfa0 { u8 pad[0xa80]; QV_bfa0 xa80; };
static inline QV_bfa0 operator*(const QV_bfa0& a, f32 k) {
    QV_bfa0 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline f32 dot_c620(const QV_bfa0& a, const QV_bfa0& b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
struct Ob_c620 { u8 pad[0x84]; u8 x84; u8 x85; u8 x86; };
#define QCOPY_b0a8(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV_b0a8 {
    f32 x, y, z, w;
    QV_b0a8() {}
    QV_b0a8(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV_b0a8(const QV_b0a8& o) { QCOPY_b0a8(this, &o); }
} __attribute__((aligned(16)));
struct Fx_b0a8;
struct FxVt_b0a8 { void* s[7]; void (*f7)(Fx_b0a8*, QV_b0a8); };
struct Fx_b0a8 { FxVt_b0a8* vt; };
struct Ch_b0a8 { u8 p0[0x108]; u32 x108; u32 x10c; u8 p110[0x834 - 0x110]; u8 x834[0x9f4 - 0x834]; u8 x9f4[0xb40 - 0x9f4]; void* xb40; };
struct Ob_b0a8 { u8 p0[4]; union { Ch_b0a8* x4; u8 x4c; }; u8 p8[0x18]; u32 x20; f32 x24; f32 x28; s32 x2c; Fx_b0a8* x30; u8 p34[0xc]; QV_b0a8 x40; };
extern "C" {

struct In13 { u64 x0; u64 x8; u8 p10[0x1c]; f32 x2c; u8 p30[0xc]; f32 x3c; };
struct Ob13 { u8 p0[0x3a]; u8 x3a; u8 p3b[5]; s32 x40; u8* x44; u8 p48[4]; f32 x4c; f32 x50; u8 p54[0x6c]; f32 xc0; };
extern f32 D_004573e8;
s32 func_0019c498(u8*);
s32 func_0019c4d0(u8*);
void func_0013fd88(Ob13*);
void func_001ad990(u8*, f32, f32, f32);
void func_0013fdf0(Ob13*, In13*, f32);
void func_0013fec0(Ob13*);
s32 func_001585a0(In13*);
s32 func_001584f8(In13*);
s32 func_00158548(In13*);
f32 func_0017ce10(f32);
s32 func_0013ff08(Ob13* o, In13* in, f32 dt);  // 0x0013ff08: definition moved into src/anon/unit_0013fca8.cpp

QV_bfa0* func_0016c028(void*);  // obj_get_attach_or_alt
void func_0018bfa0(Act_bfa0* a, void* b, f32 dist);  // 0x0018bfa0: definition moved into src/yasui/libys/npc.cpp

void func_002ce2a0(Ob_c620*, s32*, f32*, QV_bfa0*);
QV_bfa0 func_002cda68(Ob_c620*, s32, f32);
void func_002cc620(Ob_c620* o, void* a, void* b);  // 0x002cc620: definition moved into src/taito/path.cpp

void func_001143d8(Ob_b0a8*);
Ch_b0a8* func_00111e38(s32);
void* func_0010c778(Ch_b0a8*);
void func_00135aa0(void*);
void func_001c0d38(Ch_b0a8*, Ch_b0a8*, s32, s32);
void func_0016ace0(Ch_b0a8*, const QV_b0a8&);
void func_00198860(Ch_b0a8*, s32);
void func_001ad990(u8*, f32, f32, f32);
void func_00190128(u8*);
void func_0019ca90(void*, s32, s32);
Fx_b0a8* func_0013e610(s32);
void func_0013e890(void);
void func_0016bd60(Ch_b0a8*, s32);
void func_0014eb48(Ch_b0a8*, QV_b0a8*, f32);
void func_0011b0a8(Ob_b0a8* o);  // 0x0011b0a8: definition moved into src/anon/unit_0011a660.cpp

struct Hd_5680 { u8 p0[0x14]; s32 x14; u32 x18; s32 x1c; u32 x20; s32 x24; u32 x28; };
struct El_5680 { s32 x0; s32 x4; };
struct Ob_5680 {
  u32 x0; u32 x4; u32 x8; u32 xc; u32 x10; u32 x14; u32 x18; u32 x1c;
  u8 x20[0x120 - 0x20]; u8 x120[0x778 - 0x120]; u8 x778; u8 x779; u8 p77a[0x790 - 0x77a];
  u8 x790[0xc60 - 0x790]; u8 xc60[16][880]; El_5680 x4360[512]; u8 p5360[4]; s32 x5364; u8 p5368[4];
  s32 x536c, x5370, x5374, x5378, x537c;
};
void func_00106ab8(void*);  // noop_ret
void func_001070c8(void*);  // set_vtbl_34cc50
void func_0015e4e0(void*);
void func_0015e9e0(void*);
void func_0031a830(void*);
void func_001447c0(u8*, f32, f32, f32, f32, f32, f32);
void func_00145b90(Ob_5680*, s32);
void func_00146d28(Ob_5680*);
void func_00145680(Ob_5680* o, Hd_5680* h, u8 flag, s32 a3);  // 0x00145680: definition moved into src/anon/unit_00145600.cpp

struct Nd94 { u8 p0[0x18c]; struct Nd94* parent; s32 x190; u8 p194[4]; };
struct Desc94 { u8 p0[0x2c]; s32 x2c; };
struct Ow94 { u8 p0[0x18]; Nd94 root; Nd94 elems[6]; u8 pad[0xb40 - 0x18 - 408*7]; s32 xb40; s32 xb44; s32 xb48; u32 xb4c; };
s32 func_0022b9e0(void);
s32 func_0022b720(void);
void func_001386e0(void*, s32, s32, s32, s32, s32);
void func_001396b0(Nd94*);
void func_0031a260(Nd94*, s32);
void func_00139660(Nd94*);
void func_00139688(Nd94*);
s32 func_0023aa98(void*);
void func_00138c68(Nd94*, s32, s32);
void func_00229430(Ow94*, s32);  // to_1391c8_arg11
void func_00229830(Ow94*);
static inline void setParent_2294c8(Nd94* n, Nd94* p) {
  n->parent = p;
  func_001396b0(n);
  if (n->parent) {
    n->x190 = 0;
    func_001396b0(n);
    if (n->x190) func_0031a260(n, 0);
  }
}
void func_002294c8(Ow94* o, s32 n, s32 b, Desc94* d);  // 002294c8: moved to src/sasa/musical_score.cpp (linked unit)
}
