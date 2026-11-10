#include "talkcamera.hpp"

// dk::TalkCamera (0x159790-0x159ce0): the camera used while talking. It follows a YS::TARGET,
// either orbiting the target (mode 1) or sitting behind it.

struct V159790 {
    f32 x, y, z, w;
    V159790() {}
    V159790(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V159790& operator=(const V159790& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V159790 operator-(const V159790& b) const {
        V159790 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V159790 operator+(const V159790& b) const {
        V159790 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct M159790 {
    f32 r[4][4];
    M159790() {}
    M159790& operator=(const M159790& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    V159790 operator*(const V159790& v) const {
        V159790 o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder"
                     : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    void invOrtho() {
        asm volatile(".set noreorder\n\tlq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
struct S159790 { f32 f0, dist, height; s32 flag; V159790 pos; };
struct Obj159790 { u8 pad[1712]; M159790 mtx; };
struct C159790 { u8 p0[48]; f32 f48; s32 x52; u8 p38[12]; void* target; u8 p48[24]; V159790 v96; u8 p70[16]; V159790 v128; };

namespace YS {
class TARGET {
public:
    TARGET();
    Obj159790* obj;
    u32 w[4];
};
}  // namespace YS

static inline f32 deg2rad(f32 d) { return d * 3.1415927f / 180.0f; }

static f32 D_004f3600 = deg2rad(60.0f);   // view angle

extern "C" {
u8 D_0034aa10;            // active
u8 D_0034aa11;            // mode
YS::TARGET D_0034aa18;
}

extern "C" {
void func_001904f0(YS::TARGET*, S159790*);
V159790* func_0016c028(void*);
f32 func_002f8ad0(f32, f32);
f32 func_0017ce10(f32);
void func_0011b6a8(M159790*);
void func_0011b720(M159790*, f32);
void func_0013f648(C159790*);
void func_00141010(f32);
void func_00162058(f32);
void func_001024a8(TASK*);
}

namespace dk {
class ObjCamera {
public:
    static ObjCamera* getInstance();
    void collision();
    void setWarp();
    void returnMode();
};
}  // namespace dk

void FIELD_CreateTask(int, int, void (*)(TASK*)) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");

extern "C" void func_00159790(C159790* c)
{
    S159790 s;
    s.flag = 0;
    func_001904f0(&D_0034aa18, &s);
    c->v128 = s.pos;
    if (D_0034aa11 == 1) {
        V159790 a, b;
        V159790& t = *func_0016c028(c->target);
        V159790 d;
        b = c->v128;
        d = t;
        V159790 e, f;
        e = b;
        f = d - b;
        f.w = 1.0f;
        e.w = 1.0f;
        a = f;
        f32 ang = func_0017ce10(func_002f8ad0(a.x, a.z));
        V159790 r(0.0f, 0.0f, s.dist, 0.0f);
        M159790 m;
        func_0011b6a8(&m);
        func_0011b720(&m, ang);
        a = m * r;
        c->v96 = c->v128 + a;
        c->v96.y -= s.height;
    } else {
        M159790 m1; M159790 m2; V159790 p; V159790 q;
        m1 = D_0034aa18.obj->mtx;
        m2 = m1;
        V159790 u(0.0f, 0.0f, -s.dist, 0.0f);
        m2.invOrtho();
        q = m2 * s.pos;
        p = q + u;
        p.y -= s.height;
        c->v96 = m1 * p;
    }
    c->f48 = D_004f3600;
    c->x52 = 0;
    func_0013f648(c);
}

namespace dk {

void TalkCamera::update(ObjCamera* cam) {
    if (D_0034aa10 == 1) {
        D_0034aa10 = 0;
        func_00159790((C159790*)cam);
    }
    cam->collision();
}

}  // namespace dk

extern "C" void func_00159b40(YS::TARGET* t, u8 mode) {
    func_00141010(30.0f);
    *(u32*)((u8*)dk::ObjCamera::getInstance() + 64) = 4;
    D_0034aa18 = *t;
    func_00162058(8.0f);
    D_0034aa10 = 1;
    D_0034aa11 = mode;
}

namespace dk {

void TalkCamera::ensureTask(TASK* task) {
    ObjCamera::getInstance()->setWarp();
    ObjCamera::getInstance()->returnMode();
    func_001024a8(task);
}

}  // namespace dk

extern "C" void func_00159c20(void) {
    FIELD_CreateTask(1, 25990, dk::TalkCamera::ensureTask);
    func_00162058(8.0f);
}
