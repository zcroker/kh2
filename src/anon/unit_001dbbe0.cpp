#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));

namespace kn {
// 128-bit vector copy through $8, as the VU0 library's inline copy does.
static inline void CopyVector(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}

struct FVector {
    f32 x, y, z, w;
    FVector() {}
    FVector(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    ~FVector() {}
    FVector& operator=(const FVector& o) {
        if (this != &o) CopyVector(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
}  // namespace kn

static inline kn::FVector operator+(const kn::FVector& a, const kn::FVector& b) {
    kn::FVector r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

namespace dk {
struct Aabbox {
    kn::FVector lo, hi;
    Aabbox(const kn::FVector& a, const kn::FVector& b);
};
}  // namespace dk

extern "C" {
void func_001c1748(void*, u32, const kn::FVector*, s32 (*)(void*));
u32 func_0019ba60(u32);
kn::FVector* func_0016c028(u32);  // obj_get_attach_or_alt
void func_001a7790(dk::Aabbox*);
f32 func_002f8ad0(f32, f32);
u8* func_0016f000(u32, kn::FVector*, f32);
void func_0016c018(u8*, s32, u32);
}
extern u32 D_0034e948;
extern f32 D_00349e10;  // frame time
extern u32 D_003638d0;  // random seed

static kn::FVector D_01d5bab0;
f32 D_00352ad0 = 0.0f;

struct Owner1dbc58 {
    u8 f0;
    u8 pad1[4];
};

struct Obj1dbc58 {
    u8 base[20];
    u8 f20;          // 20
    u8 f21;
    s8 f22;          // 22
    u8 pad23[25];
    kn::FVector pos; // 48
    u8 pad64[16];
    u8 f80, f81;     // 80
    u8 pad82[2];
    void (*f84)(Obj1dbc58*);  // 84
    u32 f88;         // 88
    u8* f92;         // 92
    Obj1dbc58(u32 a1, const kn::FVector& p, u8* d);
};

extern "C" s32 func_001dbd38(Obj1dbc58*);

Obj1dbc58::Obj1dbc58(u32 a1, const kn::FVector& p, u8* d) {
    func_001c1748(this, a1, &p, (s32 (*)(void*))func_001dbd38);
    kn::CopyVector(&pos, &p);
    f80 = 0;
    f92 = d;
    f22 = -1;
    f81 = 0;
    f84 = 0;
    f88 = 0;
    f20 = *d;
}

extern "C" {

void func_001dbcd0(void) {
    if (func_0019ba60(D_0034e948)) D_01d5bab0 = *func_0016c028(D_0034e948);
    D_00352ad0 -= D_00349e10;
}

s32 func_001dbd38(Obj1dbc58* o) {
    if (o->f84) o->f84(o);
    return 1;
}

void func_001dbd68(const kn::FVector& p) {
    static const kn::FVector lo(-256.0f, -512.0f, -256.0f, 0.0f);
    static const kn::FVector hi(256.0f, 0.0f, 256.0f, 0.0f);
    dk::Aabbox box(p + lo, p + hi);
    func_001a7790(&box);
}

static inline u32 Rand() { D_003638d0 *= 0x10dcd; return D_003638d0; }
static inline f32 Rand1() { return (f32)Rand() * 2.3283064365386963e-10f; }
static inline f32 RandR(f32 lo, f32 w) { return lo + Rand1() * w; }

u8* func_001dbe78(Obj1dbc58* o, kn::FVector* dir) {
    kn::FVector t;
    t = *(kn::FVector*)o;
    t.y += *(f32*)(o->f92 + 8);
    f32 h = func_002f8ad0(dir->x, dir->z);
    u8* r = func_0016f000(*(u32*)(o->f92 + 4), &t, h);
    if (r) {
        func_0016c018(r, 1, o->f88);
        D_00352ad0 = RandR(8.0f, 22.0f);
    }
    return r;
}

}
