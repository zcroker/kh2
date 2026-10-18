#include "../common/types.h"
struct QW18c { f32 x, y, z, w;
    QW18c() {}
    QW18c(const QW18c& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    QW18c& operator=(const QW18c& o) { if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
static inline QW18c operator-(const QW18c& a, const QW18c& b) {
    QW18c r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Normalize18c(QW18c* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct Obj18c {
    u8 p0[2624]; s32 kind; s32 mode; s32 p2632; Obj18c* tgt; QW18c v2640; u8 p1[2688 - 2656]; QW18c v2688;
};
extern "C" {
void func_0016af58(QW18c*, Obj18c*);
QW18c* func_0016c028(Obj18c*);
s32 func_0018c458(s32*);
s32 ctarget_0019ba60_18c(Obj18c*) asm("_Z16ctarget_0019ba60jjjj");
extern Obj18c* D_0034e948;
QW18c func_0018c258(Obj18c* o) {
    QW18c dir;
    func_0016af58(&dir, o);
    if (func_0018c458(&o->kind) && o->mode) {
        QW18c pos(*func_0016c028(o));
        pos.y = 0.0f;
        if (o->kind == 3) {
            Obj18c* t = o->tgt;
            if (t && ctarget_0019ba60_18c(t)) return o->v2688;
        } else {
            switch (o->mode) {
            case 1: {
                Obj18c* t = o->tgt;
                if (t && ctarget_0019ba60_18c(t)) {
                    QW18c tp(*func_0016c028(t));
                    tp.y = 0.0f;
                    dir = tp - pos;
                    Normalize18c(&dir);
                }
                break;
            }
            case 3:
                dir = o->v2640 - pos;
                Normalize18c(&dir);
                break;
            case 2: {
                Obj18c* t = D_0034e948;
                if (t) {
                    QW18c tp(*func_0016c028(t));
                    tp.y = 0.0f;
                    dir = tp - pos;
                    Normalize18c(&dir);
                }
                break;
            }
            }
        }
    }
    return dir;
}
}
