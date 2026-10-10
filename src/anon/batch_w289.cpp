#include "../common/types.h"
extern "C" {
extern void* D_00347f98[];
extern void* D_00347e60[];
extern void* D_00361de8[];
extern void* D_0035eb98[];
extern u8* D_00361dd8;
void func_00170950(void*);
void func_00239870(u8*);
void func_0023c098(u8*);
void func_002369f0(u8*);
typedef void (*Dtor2c7e68)(u8*);
#define DestroyArr2c7e68(B, E, SZ) \
    if ((B) != 0) { \
        u8* e = (E); \
        u8* b = (B); \
        for (;;) { \
            if (b == e) break; \
            e -= (SZ); \
            (*(Dtor2c7e68*)(*(u8**)e + 12))(e); \
        } \
    }
static inline __attribute__((always_inline)) void Seq2c7e68(u8* q) {
    *(void***)q = D_00347e60;
    func_00239870(q + 24);
    *(void***)q = D_00347f98;
}
static inline __attribute__((always_inline)) void Body2c7e68(u8* p) {
    *(void***)p = D_00361de8;
    func_00170950(*(void**)(p + 188));
    D_00361dd8 = (D_00361dd8 == p) ? 0 : D_00361dd8;
    DestroyArr2c7e68(p + 5120, p + 5936, 408);
    Seq2c7e68(p + 4712);
    DestroyArr2c7e68(p + 3488, p + 4712, 408);
    DestroyArr2c7e68(p + 2672, p + 3488, 408);
    Seq2c7e68(p + 2264);
    Seq2c7e68(p + 1856);
    DestroyArr2c7e68(p + 632, p + 1856, 408);
    Seq2c7e68(p + 196);
    *(void***)(p + 28) = D_0035eb98;
    func_0023c098(p + 76);
    func_002369f0(p + 52);
    *(void***)(p + 28) = D_00347f98;
    *(void***)p = D_00347f98;
}
void func_002c7e68(u8* p) {
    Body2c7e68(p);
}
void func_002c8028(u8* p) {
    Body2c7e68(p);
}
}
extern "C" {
struct GEnt { u16 id; u8 b2; u8 b3; u16 pad; };
struct GRow { char name[8]; u8 flag; u8 pad[7]; char buf[64]; };
struct GObj { s32 count; GEnt e[256]; GRow rows[8]; };
struct GInfo { u16 h0; u8 b2; u8 b3; u16 h4; };
struct GItem { u32 f0, f4, f8; };
extern char D_003741e8[];
GInfo* func_001a80c8(u32);
u32 func_001a3820(u32);
GItem* func_001b8e88(u32);
s32 func_001a6598(u32);
void func_00259570(u32, char*, s32, s32);
s32 func_002595e0(void);
void func_002595e8(char*, u32);
u32 func_00192048(u32);
void func_00192cc0(char*, char*);
u32 func_00259618(u32, char*, s32);
void func_00192b30(u32);
void func_00282940(GObj* obj, s32 start, s32 n) {
    for (s32 i = 0; i < n; i++) {
        s32 idx = i + start;
        s32 arg;
        if (idx >= obj->count) return;
        GInfo* info = func_001a80c8(obj->e[idx].id);
        u8 kind = info->b2;
        if (kind == 0 || kind == 18) {
            GItem* item = func_001b8e88(func_001a3820(info->h0));
            u32 msg = item->f8;
            char* p = obj->rows[i].buf;
            if (info->b2 == 0) arg = obj->e[idx].b3 != 0;
            else arg = func_001a6598(info->h4) == 0;
            func_00259570(info->b2, p, arg, 1);
            p += func_002595e0();
            func_002595e8(p, func_00192048(msg));
        } else {
            func_00192b30(func_00259618(obj->e[idx].id, obj->rows[i].buf, obj->e[idx].b3 != 0));
        }
        arg = obj->e[idx].b2;
        if (arg != 1) func_00192cc0(obj->rows[i].name, D_003741e8);
        else obj->rows[i].name[0] = 0;
        obj->rows[i].flag = 0;
    }
}
}
namespace w289_n {
#define QCOPY289(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY289(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY289(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct QMat {
    QWord r[4];
    QMat() {}
    QMat& operator=(const QMat& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord Add(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QWord Scale(const QWord& a, f32 s)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
static inline QWord MulV(const QMat& m, const QWord& v)
{
    QWord r;
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
                 : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}
extern "C" {
extern f32 D_01d498c4;
extern f32 D_00349e10;
s32 func_0019ba60(u32);
void func_0011b6a8(QMat*);
QMat* func_0011b720(QMat*, f32);
QWord func_0016be98(u32);
s32 func_001c7540(u8* o) {
    f32 t = *(f32*)(o + 64) - D_00349e10;
    *(f32*)(o + 64) = t;
    if (t <= 0.0f || !func_0019ba60(*(u32*)(o + 72))) return 0;
    f32 w = *(f32*)(o + 60);
    f32 r = *(f32*)(o + 64) / 40.0f;
    QMat m;
    func_0011b6a8(&m);
    f32 s = 30.0f / (w * r);
    m = *func_0011b720(&m, s < D_01d498c4 ? s : D_01d498c4);
    *(QWord*)(o + 48) = MulV(m, *(QWord*)(o + 48));
    *(f32*)(o + 60) = w;
    *(QWord*)o = Add(Scale(*(QWord*)(o + 48), w * r), func_0016be98(*(u32*)(o + 72)));
    *(u8*)(o + 22) = (s32)(r * 255.0f);
    return 1;
}
}
}
namespace w289_p {
#define QCOPY289P(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY289P(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY289P(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct QMat {
    QWord r[4];
    QMat() {}
    QMat& operator=(const QMat& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline QWord Add(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QWord Scale(const QWord& a, f32 s)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
static inline QWord MulV(const QMat& m, const QWord& v)
{
    QWord r;
    asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
                 : : "r"(&r), "r"(&m), "r"(&v) : "memory");
    return r;
}
static inline QWord Sub(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline QWord Cross(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Dot(const QWord& a, const QWord& b)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
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
extern u32 D_0035169c[];
extern QWord D_00352a60;
extern u32 D_0034e948;
QWord func_0016af58(u32);
void func_001c6900(u8*, QWord*);
s32 func_001c5c60(u8* o) {
    if (D_0035169c[o[82] * 8] & 2) {
    QWord d = Sub(*(QWord*)o, D_00352a60);
    d.f[1] = 0.0f;
    QWord dir = func_0016af58(D_0034e948);
    f32 t = Dot(dir, d);
    if (t < 0.0f || 1000.0f < t) return 0;
    QWord up;
    up.f[0] = 0.0f;
    up.f[1] = -1.0f;
    up.f[2] = 0.0f;
    up.f[3] = 0.0f;
    QWord c = Cross(up, dir);
    d.f[0] = Dot(c, d);
    if (40000.0f < d.f[0] * d.f[0] + d.f[1] * d.f[1]) return 0;
    d = Sub(*(QWord*)o, D_00352a60);
    Normalize(&d);
    func_001c6900(o, &d);
    return 1;
    }
    return 0;
}
}
}
