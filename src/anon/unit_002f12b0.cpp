#include "../common/types.h"

// Game file 0x2f12b0-0x2f17e0: a timed turn of an object towards an angle, a random effect
// position around the camera, a fade progress helper and the task that watches a pad flag.
// The VU0 vector code uses Sony-style inline asm (lq/sq, lqc2/vadd/vmul*), as before.

extern "C" {
void YS__OBJ__get_dir(void*, u32);
f32 func_0017ce10(f32);
f32 func_002f8ad0(f32, f32);
s32 YS__OBJ__is_valid(u32);
void func_0016aeb8(u32, f32);
s32 func_002fea18(void);
s32 func_00106a60(s32);
void kn__Camera__getPosition(s32, void*);
f32 func_001074b8(s32);
void func_0011b6a8(void*);
void sceVu0RotMatrixZ(void*, void*, f32);
void func_00107330(s32, f32, f32, f32);
void func_00102448(void*, u32);
u8* func_00167f18(u32);
void func_001039f8(void);
u8* func_00103eb0(void);
void* TASK_MANAGER__create_thread(u32, u32, u32, void (*)(void*), u32);
extern f32 D_00349e10;

void dk__Turn__start(void* s, f32 deg, u32 h, f32 t, s32 flag);
s32 func_002f13b0(void* o);
void func_002f1460(u32* a0, u32 a1, f32 f12, f32 f13, f32 f14, f32 f15);
s32 func_002f1480(void* o, f32 s);
void func_002f1670(u8* o);
void func_002f1758(void* t);
void func_002f17a8(void);
}

// --- 002f12b0: start a timed turn towards an angle (degrees) around an object
struct W1816Turn { bool rev; u32 h; f32 time; f32 dst; f32 speed; f32 val; };
struct W1816Q { f32 x, y, z, w; };
void dk__Turn__start(void* sv, f32 deg, u32 h, f32 t, s32 flag) {
    W1816Turn* s = (W1816Turn*)sv;
    s->rev = flag != 0;
    s->h = h; s->time = t;
    s->dst = 3.1415927f - deg * 0.017453292f;
    W1816Q v; YS__OBJ__get_dir(&v, h);
    s->val = func_002f8ad0(v.x, v.z);
    s->val = func_0017ce10(s->val);
    s->dst = func_0017ce10(s->dst);
    f32 d;
    if (s->dst < s->val) { d = s->val - s->dst; if (s->rev == false) d = 6.283185f - d; }
    else { d = s->dst - s->val; if (s->rev == true) d = 6.283185f - d; }
    s->speed = d / s->time;
    if (s->rev == true) s->speed = -s->speed;
}

// --- 002f13b0: step the turn; returns 0 when done
union F25 { f32 f; u8 c; };
struct O21 { u32 f0; u32 h; f32 time; f32 dflt; f32 speed; f32 val; };
extern F25 D_00349e10_u asm("D_00349e10");
s32 func_002f13b0(void* ov) {
    O21* o = (O21*)ov;
    if (!YS__OBJ__is_valid(o->h)) return 0;
    o->val += o->speed * D_00349e10_u.f;
    o->val = func_0017ce10(o->val);
    o->time -= D_00349e10_u.f;
    if (o->time <= 0.0f) {
        o->val = o->dflt;
        func_0016aeb8(o->h, o->dflt);
        return 0;
    }
    func_0016aeb8(o->h, o->val);
    return 1;
}

void func_002f1460(u32* a0, u32 a1, f32 f12, f32 f13, f32 f14, f32 f15) {
    a0[3] = a1;
    a0[5] = 0;
    *(f32*)((u8*)a0 + 0) = f12;
    *(f32*)((u8*)a0 + 4) = f13;
    *(f32*)((u8*)a0 + 8) = f14;
    *(f32*)((u8*)a0 + 16) = f15;
}

// --- 002f1480: put the effect at a random offset (scaled box) around the camera
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { QCOPY(this, &o); }
    QV& operator=(const QV& o) { if (this != &o) QCOPY(this, &o); return *this; }
    QV operator+(const QV& v) const {
        QV o;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct QM {
    QV r[4];
    QV operator*(const QV& v) const {
        QV o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Obj { f32 sx, sy, sz, pad; f32 f10, f14, p18, p1c; QV pos; };
s32 func_002f1480(void* ov, f32 s)
{
    Obj* o = (Obj*)ov;
    QV v;
    QM m;
    QV c;
    f32 k = 2147483520.0f;
    f32 x = (f32)func_002fea18() / k * o->sx - o->sx / 2.0f;
    x = x * s;
    f32 y = (f32)func_002fea18() / k * o->sy - o->sy / 2.0f;
    y = y * s;
    f32 z = (f32)func_002fea18() / k * o->sz - o->sz / 2.0f;
    z = z * s;
    s32 cam = func_00106a60(1);
    kn__Camera__getPosition(cam, &c);
    f32 a = func_001074b8(cam);
    asm("" : "+r"(o) : "f"(x), "f"(y));
    v.x = x;
    v.y = y;
    v.z = z;
    v.w = 1.0f;
    func_0011b6a8(&m);
    sceVu0RotMatrixZ(&m, &m, a);
    v = m * v;
    o->pos = c + v;
    func_00107330(cam, o->pos.x, o->pos.y, o->pos.z);
    o->f14 += D_00349e10;
    if (o->f10 <= o->f14) return 0;
    return 1;
}

// --- 002f1670: progress value for the current fade state
// local with an empty destructor: keeps the final call a jal (no sibcall)
struct NoTail81 { ~NoTail81() {} };
void func_002f1670(u8* o) {
    NoTail81 nt;
    f32 r = 0.0f;
    switch (*(s32*)(o + 12)) {
    case 0:
        r = 1.0f;
        break;
    case 1:
        r = *(f32*)(o + 20) / *(f32*)(o + 16);
        if (0.5f < r) r = (1.0f - r) + (1.0f - r);
        else r = r + r;
        break;
    case 2:
        r = *(f32*)(o + 20) / *(f32*)(o + 16);
        break;
    case 3:
        r = 1.0f - *(f32*)(o + 20) / *(f32*)(o + 16);
        break;
    }
    func_002f1480(o, r);
}

// --- 002f1758: task: every frame, if pad flag bit 1 is set, call func_001039f8.
void func_002f1758(void* t) {
    func_00102448(t, 1);
    for (;;) {
        if (*(u64*)(func_00167f18(0) + 8) & 2) func_001039f8();
        func_00102448(t, 0);
    }
}

// --- 002f17a8: start that task (2000, 4 KB stack).
void func_002f17a8(void) {
    TASK_MANAGER__create_thread(*(u32*)(func_00103eb0() + 4), 0, 2000, func_002f1758, 0x1000);
}
