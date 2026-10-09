#include "../common/types.h"
#define QCOPY257(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV257 {
    f32 x, y, z, w;
    QV257() {}
    QV257(const QV257& o) { QCOPY257(this, &o); }
} __attribute__((aligned(16)));
static inline QV257 operator*(const QV257& a, f32 k) {
    QV257 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline QV257 operator+(const QV257& a, const QV257& b) {
    QV257 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

static inline QV257 operator-(const QV257& a, const QV257& b) {
    QV257 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 normalize257(QV257* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline __attribute__((always_inline)) void set4_257(QV257* v, f32 x, f32 y, f32 z, f32 w) { v->x = x; v->y = y; v->z = z; v->w = w; }
extern "C" {
extern u8* D_0035f634;
s32 func_00139d78(u8*);
void func_002b1660(void);
void func_002b2220(void) {
    struct NoTail { ~NoTail(){} } nt;
    s32 i;
    for (i = 0; i < 48; i++) {
        if (func_00139d78(D_0035f634 + i * 408)) return;
    }
    if (func_00139d78(D_0035f634 + 19584)) return;
    for (i = 0; i < 2; i++) {
        if (func_00139d78(D_0035f634 + 19992 + i * 408)) return;
    }
    if (func_00139d78(D_0035f634 + 20808)) return;
    if (func_00139d78(D_0035f634 + 21216)) return;
    if (func_00139d78(D_0035f634 + 22032)) return;
    if (func_00139d78(D_0035f634 + 22468)) return;
    if (func_00139d78(D_0035f634 + 24212)) return;
    func_002b1660();
}
extern u8* D_00361f60;
void func_00198690(u8*);
s32 func_001c0cd8(u8*);
void func_0016b070(u8*, f32*);
void func_0016ace0(u8*, f32*);
s32 func_002d8d68(u8*, u8*, u8*, u8*);
u8* func_002d73f0(u8*);
void func_001d86a0(s32, s32);
union UF { f32 f; s32 i; u8 c; };
void func_002dbb88(u8* a0) {
    func_00198690(a0);
    if (func_001c0cd8(a0)) {
        register f32 z asm("$f20") = 0.0f;
        f32 v[4];
        f32 w[4];
        v[0] = -1.570796251296997f; v[1] = -1.570796251296997f; v[2] = z; v[3] = z;
        func_0016b070(a0, v);
        w[0] = z; w[1] = z; w[2] = z; w[3] = z;
        func_0016ace0(a0, w);
        return;
    }
    if (a0[0xbc0]) return;
    if (!(*(f32*)(a0 + 0xbf0) <= 0.0f)) return;
    u8* s = D_00361f60;
    if (!s) return;
    if (func_002d8d68(s, a0, a0 + 0xb20, a0 + 0xb60) <= 0) return;
    a0[0xb1c] = *(f32*)(a0 + 0xb18) < 0.0f;
    ((UF*)(a0 + 0xbf0))->f = *(f32*)(func_002d73f0(s) + 0x34);
    if (*(s32*)(s + 0x98) == 1) func_001d86a0(-1, 0);
}
extern u8* D_0035f610;
u8* func_00294000(s32);
s32 func_002abf40(s32, s32);
static inline s32 tst_002abff0(s32 a0, s32 b) {
    u32* p = (u32*)(D_0035f610 + a0 * 4) + 43; return (p[(u32)b >> 5] & (1 << (b & 31))) != 0;
}
s32 func_002abff0(s32 a0, s32 a1) {
    s32 res = 0;
    u8* v = func_00294000(1);
    if (a1 < 0) {
        for (s32 i = 0; i < *(s32*)(v + 8); i++) {
            s32 b = func_002abf40(a0, i);
            if (b >= 0) {
                res = tst_002abff0(a0, b);
                if (res) break;
            }
        }
    } else {
        res = tst_002abff0(a0, a1 = func_002abf40(a0, a1));
    }
    return res;
}
QV257 func_002cd950(void* self, f32 t, const QV257* p, const QV257* q) {
    f32 t2 = t * t;
    f32 h00 = t2 * 6.0f - t * 6.0f;
    f32 h01 = t2 * -6.0f + t * 6.0f;
    f32 h10 = t2 * 3.0f - t * 4.0f + 1.0f;
    f32 h11 = t2 * 3.0f - (t + t);
    return p[0] * h00 + q[0] * h01 + p[1] * h10 + q[1] * h11;
}
extern s8 D_01e2bd80;
extern QV257 D_01e2bd90;
void func_00178cf8(u8*);
QV257 func_00190388(u32*);
QV257* func_0016c028(u8*);
void func_0016aef0(u8*, QV257*);
void func_002c6118(void);
void func_002fd188(void (*)(void));
void func_002cb0e8(u32*, QV257*, f32);
u32 func_002c1b48(u32);
void func_002cab98(u32);
void func_002c17a0(void);
void func_002c5dc0(u8* a0, u32* a1) {
    func_00178cf8(a0);
    QV257 d = func_00190388(a1) - *func_0016c028(a0);
    d.y = 0.0f;
    normalize257(&d);
    func_0016aef0(a0, &d);
    if (!D_01e2bd80) {
        D_01e2bd80 = 1;
        set4_257(&D_01e2bd90, 0.0f, 0.0f, 1.0f, 0.0f);
        func_002fd188(func_002c6118);
    }
    func_002cb0e8(a1, &D_01e2bd90, 0.0f);
    func_002cab98(func_002c1b48(*a1));
    func_002c17a0();
}
extern u8* D_00352130;
struct S32bb { u8 pad[0x3db0]; u16 h; };
extern S32bb D_0032bb30;
extern u32 D_003638d0;
u8* func_0017df58(s32);
s32 func_0019ba60(u8*);
s32 func_0017e280(u8*);
f32 func_002f8b30(f32, f32);
#define MAX257(a, b) ((a) > (b) ? (a) : (b))
void func_001aefa0(u8* a0) {
    for (s32 i = 0; i < 2; i++) {
        u8* p = func_0017df58(i);
        if (func_0019ba60(p)) {
            if (!func_0017e280(p)) return;
        }
    }
    f32 m = MAX257(func_002f8b30(*(f32*)(D_00352130 + 0xd8), (f32)D_0032bb30.h), *(f32*)(D_00352130 + 0xdc));
    D_003638d0 *= 0x10dcd;
    if ((f32)D_003638d0 * 2.3283064365386963e-10f < m) a0[0xc] = 1;
}
}
