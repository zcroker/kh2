#include "../common/types.h"
static inline void vlerp(f32* d, f32* a, f32* b, f32 t) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b), "f"(t) : "$8", "memory");
}
static inline void vnorm(f32* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\t.set noreorder\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(v) : "$8", "memory");
}
static inline void vouter(f32* d, f32* a, f32* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
struct Vq285 {
    f32 x, y, z, w;
    Vq285& operator=(const Vq285& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq285 lerp285(const Vq285& a, const Vq285& b, f32 t) {
    Vq285 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tmfc1 $8, %3\n\tqmtc2 $8, $vf3\n\tvaddw.x $vf4, $vf0, $vf0w\n\tvsub.x $vf4, $vf4, $vf3\n\tvmulax.wxyz ACC, $vf2, $vf3x\n\tvmaddx.wxyz $vf1, $vf1, $vf4x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b), "f"(t) : "$8", "memory");
    return r;
}
struct Loc285 { f32 a, b, c; s32 d; Vq285 v; };
struct Obj285 { Vq285 v0, v10, v20, v30, v40; s32 f50; f32 f54; };
struct TzObj285 { void (**vt)(TzObj285*); };
extern "C" {
void func_001256c0(f32 (*d)[4], f32 (*a)[4], f32 (*b)[4], f32 t) {
    vlerp(d[3], a[3], b[3], t);
    vlerp(d[0], a[0], b[0], t);
    vnorm(d[0]);
    vlerp(d[1], a[1], b[1], t);
    vnorm(d[1]);
    vouter(d[2], d[0], d[1]);
    vnorm(d[2]);
    vouter(d[1], d[2], d[0]);
    vnorm(d[1]);
}

void func_001902a8(void*, Loc285*);
Vq285* func_0016c028(s32);  // obj_get_attach_or_alt
void func_001a7610(Vq285*, Vq285*, s32, f32, f32);
void func_0016bd60(s32, s32);
void func_002c6eb8(Obj285* o, s32 id, void* p) {
    Loc285 l;
    l.d = 0;
    func_001902a8(p, &l);
    o->v40 = l.v;
    o->v0 = *func_0016c028(id);  // obj_get_attach_or_alt
    o->v30 = l.v;
    o->v30.z -= l.b;
    func_001a7610(&o->v30, &o->v30, 0, 5000.0f, 1000.0f);
    o->v10 = lerp285(o->v0, o->v30, 0.1f);
    o->v10.y -= 1000.0f;
    o->v20 = lerp285(o->v0, o->v30, 0.9f);
    o->f50 = 0;
    o->v20.y -= 500.0f;
    o->f54 = 30.0f;
    func_0016bd60(id, 58);
}


extern TzObj285* D_0035f100;
extern void* D_0035f10c;
extern void* D_0035f110;
extern u8 D_003738d8[];
s32 func_00287cd0(void);
s32 func_00287db0(void);
s32 func_00139d78(void*);
void func_0028ce38(void);
void func_0026ebc0(void);
s32 func_0028acc8(void*);
s32 func_0028d008(s32);
void func_0028cc78(s32, s32, s32, void*, s32, s32);
s32 func_002891d0(void*);
void func_0028cf28(s32, s32);  // record408_set_and_refresh
s32 func_0028d6e8(void*);
void func_0028d1c0(void*, s32, s32, s32, void*, void*, s32);
void func_0028d660(void*, s32);  // record_set_value_refresh
s32 func_00287bc0(void);
void func_0026eae8(void*, s32);
void func_0028cdb8(s32);  // record408_alloc_init
void func_0028d5d0(void*);
void PauseTaskUpdate_impl(void) asm("_ZN2Tz15PauseTaskUpdateEv");
void PauseTaskUpdate_impl(void) {
    s32 s = func_00287cd0();
    if (func_00287db0()) {
        if (func_00139d78(D_0035f100)) D_0035f100->vt[5](D_0035f100);
        func_0028ce38();
        func_0026ebc0();
    }
    if (func_00287db0()) return;
    if (func_0028acc8(D_0035f10c) && s == 1) {
        if (func_0028d008(0) == 0) {
            func_0028cc78(0, 0, 0, D_0035f100, 6, 6);
            func_0028cf28(0, func_002891d0(D_0035f10c));  // record408_set_and_refresh
            if (func_0028d6e8(D_0035f110) == 0) {
                func_0028d1c0(D_0035f110, 30026, 0, 0, D_0035f100, D_003738d8, 0);
            }
            func_0028d660(D_0035f110, func_002891d0(D_0035f10c));  // record_set_value_refresh
        }
    } else if (s == 2) {
        if (func_0028d008(0)) {
            func_0028cdb8(0);  // record408_alloc_init
            func_0028d5d0(D_0035f110);
        } else if (func_0028d6e8(D_0035f110)) {
            func_0028d5d0(D_0035f110);
        }
    }
    func_0026eae8(D_0035f10c, func_00287bc0());
}
}
