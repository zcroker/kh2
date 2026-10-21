#include "../common/types.h"
struct QW1d2 { f32 x, y, z, w;
    QW1d2() {}
    QW1d2(const QW1d2& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QW1d2& operator=(const QW1d2& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline QW1d2 operator*(const QW1d2& a, f32 k) {
    QW1d2 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline f32 Normalize1d2(QW1d2* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct Res1d2 { s32 a, b, c; f32 f; };
struct Cfg1d2 { u8 p[280]; f32 k; };
struct Obj1d2 { u8 p0[32]; QW1d2 v32; u8 p1[320 - 48]; u8 mot[2548 - 320]; u8 tgt[2920 - 2548]; f32 timer; };
static inline __attribute__((always_inline)) void SubL(const QW1d2& a, const QW1d2& b, QW1d2* r) {asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(r), "r"(&a), "r"(&b) : "memory");}
extern "C" {
Res1d2 func_001d2e68(void*, Obj1d2*);
f32 func_001d3000(void*, f32);
void func_00183768(Obj1d2*, Res1d2*, f32);
void func_0016b010(Obj1d2*, QW1d2*);
s32 Tgt1d2_is_exist(void*) asm("_ZNK2YS6TARGET8is_existEv");
QW1d2 func_00190388(void*);
QW1d2 ctarget_0016bda8_1d2(Obj1d2*) asm("_Z16ctarget_0016bda8jjjj");
void f17f488_1d2(void*, s32, f32, f32) asm("_Z13func_0017f488iiff");
void push_1d2(void*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
void chg_1d2(Obj1d2*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
extern Cfg1d2* D_00352130;
extern f32 D_00349e10;
void func_001d2c78(void* a0, Obj1d2* o) {
    Cfg1d2* cfg = D_00352130;
    Res1d2 r = func_001d2e68(a0, o);
    func_00183768(o, &r, func_001d3000(a0, r.f));
    QW1d2 v(o->v32);
    func_0016b010(o, &v);
    o->timer -= D_00349e10;
    if (o->timer <= 0.0f) {
        if (Tgt1d2_is_exist(o->tgt)) {
            SubL(func_00190388(o->tgt), ctarget_0016bda8_1d2(o), &v);
            Normalize1d2(&v);
            o->v32 = v * cfg->k;
        }
        f17f488_1d2(o->mot, 153, 0.0f, 0.0f);
        push_1d2(o->mot, 0, 0.0f, 0.0f, 0);
        chg_1d2(o, 29);
    }
}

}
