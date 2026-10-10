#include "../common/types.h"

struct Pair {
    u32 a, b;
};
struct Vec3u {
    u32 x, y, z;
};

extern "C" {

void func_0011ee98(void*, void*);
void* func_00140df0(void);
void func_00139858(s32);
void func_00139ab0(s32);
void* func_00102c80(void);
void func_00102688(u32, u32, u32);
void func_00183768(u32, u32, f32);  // copy_quad_at16_and_len
void func_001b1be0(u32, f32);
void func_001cc9c8(u32, f32);
void func_00153e28(u32, f32, f32);
void func_001a6490(u32, f32);
u32 func_001b1448(u32);
void func_002bea60(void);
void func_0021fbc0(void*);
void func_00220070(void*);
void* func_00257770(void);
void func_0028da70(void*, s32);
void* func_002766d0(void);
u8 func_00139d78(void*);
void func_00104f58(u32, u32, u32, u32, u32);
void func_002e9cb8(u32, u32, u32);
void func_002e9b58(u32, u32, u32);
void func_003053e0(void);

extern u32 D_00347ce0;
extern u32 D_0034aa08;
extern u32 D_004f3800;
extern u32 D_004f6288;
extern Pair D_004f6290;
extern u32 D_00350330;
extern u32 D_01c61b00;
extern Pair D_01c6cba0;
extern u32* D_01d49320;
extern s32 D_00351604;
extern s32 D_00351608;
extern s32 D_01dad910[2];
extern s32 D_003617d8;
extern s32 D_003617dc;

// Empty function that still saves ra (its body was compiled out).
void func_00101d38(void) {
    asm volatile("" : : : "$31");
}

struct Obj0011eef8 {
    u32 pad[2];
    u32 f8;
    u32 fc;
    u32 f10;
    void* f14;
};
void func_0011eef8(void* a, Obj0011eef8* b) {  // obj_init_and_call
    b->fc = 0;
    b->f14 = a;
    b->f8 = 0;
    func_0011ee98(a, b);
}

// Quadword copy from p+0x50 into dst (unless they alias).
void func_00107368(u8* p, void* dst) {  // vec_copy_at80_if_diff
    void* src = p + 80;
    if (dst != src) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    }
}

// Quadword copy of a global into dst.
void func_00135670(void* dst) {
    void* src = &D_00347ce0;
    if (dst != src) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    }
}

// Quadword copy of src into p+0x1a0.
void func_001391a8(u8* p, void* src) {  // vec_copy_at416_if_diff
    void* dst = p + 416;
    if (dst != src) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    }
}

void func_00159700(void) {
    D_0034aa08 = 0;
    *(u32*)((u8*)func_00140df0() + 64) = 5;
}

void func_0015b780(void) {
    func_00139858(15);
    func_00139ab0(15);
}

void* func_0015cea0(void* dst) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(&D_004f3800) : "$8", "memory");
    return dst;
}

void func_001623b0(void) {
    func_00102688(*(u32*)((u8*)func_00102c80() + 4), 5, 5);
}

void func_0016c750(u32 a) {
    D_004f6288 = a;
    D_004f6290.b = 0;
    D_004f6290.a = 0;
}

struct Obj00174168 {
    u32 x;
    u32 m;
};
struct Args00174168 {
    Obj00174168* o;
    u32 a;
    f32 f;
};
void func_00174168(Args00174168* p) {
    Obj00174168* o = p->o;
    u32 a = p->a;
    u32 m = o->m;
    func_00183768(m, a, p->f);  // copy_quad_at16_and_len
}

struct ArgsUF {
    u32 a;
    f32 f;
};
void func_00174b88(ArgsUF* p) {
    u32 a = p->a;
    func_001b1be0(a, p->f);
}

void func_001752e0(u32* p) {
    func_001cc9c8(((u32*)p[0])[1], ((f32*)p)[1]);
}

void func_00175480(u32* p) {
    func_00153e28(p[0], ((f32*)p)[1], ((f32*)p)[2]);
}

// Virtual call: (*(p+0x9f4))->vfunc[19]().
void func_00185a98(u8* p) {
    void** o = *(void***)(p + 2548);
    ((void (*)(void*))((void**)*o)[19])(o);
}

void func_0018fcc0(ArgsUF* p) {
    u32 a = p->a;
    func_001a6490(a, p->f);
}

void func_00196170(void) {
    D_01c61b00 = func_001b1448(D_00350330);
}

// Virtual call: o->vfunc[9](a, 0).
void func_0019fd88(void** o, u32 a) {
    ((void (*)(void*, u32, u32))((void**)*o)[9])(o, a, 0);
}

void func_001a8498(void) {
    D_01c6cba0.a = 0;
    D_01c6cba0.b = 0;
}

u32 func_001bbb08(void) {
    u32* p = D_01d49320;
    if (p == 0) return 0;
    return *p;
}

s32 func_001c4170(void) {  // global_pair_diff
    return D_00351604 - D_00351608;
}

void func_001d71f0(s32 a) {
    if (a == 12) func_002bea60();
}

void func_001efc28(u8* p, u8* q) {
    Vec3u* r = (Vec3u*)(p + ((s32*)*(u32*)(q + 12))[1] + 160);
    r->x = 0;
    r->z = 0;
    r->y = 0;
}

void func_001fa928(u8* p, u8* q) {
    func_0021fbc0(p + *(s32*)*(u32*)(q + 12) + 160);
}

void func_001fbc78(u8* p, u8* q) {
    func_00220070(p + *(s32*)*(u32*)(q + 12) + 160);
}

// d.xyz = a.xyz - b.xyz (VU0 macro mode).
void func_00222730(void* d, void* a, void* b) {
    asm volatile(".set noreorder\n\t"
                 "lqc2 $vf1, 0(%1)\n\t"
                 "lqc2 $vf2, 0(%2)\n\t"
                 "lqc2 $vf3, 0(%0)\n\t"
                 "vsub.xyz $vf3, $vf1, $vf2\n\t"
                 "sqc2 $vf3, 0(%0)\n\t"
                 ".set reorder"
                 :
                 : "r"(d), "r"(a), "r"(b)
                 : "memory");
}

void func_00225298(void) {
    D_01dad910[0] = -1;
    D_01dad910[1] = -1;
}

void func_00265c50(void) {
    func_0028da70(func_00257770(), 321);
}

u32 func_0029e0d0(void) {
    return func_00139d78((u8*)func_002766d0() + 18528);
}

// Stores the new value and reports whether it was unchanged.
u32 func_002bd230(s32 a, s32 b) {
    u32 same = D_003617d8 == a;
    D_003617d8 = a;
    D_003617dc = b;
    return same;
}

void func_002c5460(u32 a) {
    func_00104f58(a, 1, 0, 0, 0);
}

f32* func_002d5c20(f32* v) {
    v[3] = v[2] = v[1] = v[0] = 0.0f;
    return v;
}

struct Args002e8070 {
    u32 a, b, c;
};
void func_002e8070(Args002e8070* p) {
    u32 b = p->b;
    u32 a = p->a;
    func_002e9cb8(a, b, p->c);
}

void func_002e9c98(u32 x, Pair* p) {
    u32 a = p->a;
    func_002e9b58(x, a, p->b);
}

// Dot product of a.xyz and b.xyz (VU0 macro mode).
f32 func_002f3d70(void* a, void* b) {  // vec3_dot
    f32 r;
    asm volatile("lqc2 $vf4, 0(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\t"
                 "vmul.xyz $vf5, $vf4, $vf5\n\t"
                 "vaddy.x $vf5, $vf5, $vf5y\n\t"
                 "vaddz.x $vf5, $vf5, $vf5z\n\t"
                 "qmfc2 $2, $vf5\n\t"
                 "mtc1 $2, %0"
                 : "=f"(r)
                 : "r"(a), "r"(b)
                 : "$2");
    return r;
}

// d = a * s (VU0 macro mode).
void func_002f3f40(void* d, void* a, f32 s) {  // vec_scale_by_f12
    asm volatile("lqc2 $vf4, 0(%1)\n\t"
                 "mfc1 $8, %2\n\t"
                 "qmtc2 $8, $vf5\n\t"
                 "vmulx.xyzw $vf6, $vf4, $vf5x\n\t"
                 "sqc2 $vf6, 0(%0)"
                 :
                 : "r"(d), "r"(a), "f"(s)
                 : "$8", "memory");
}

// Library code: the original compiler allocated v0 for the temporary.
s32 func_00305dd8(u32 a, u8* p) {
    register u32 t asm("$2") = 0x2000;
    *(u64*)(p + 72) = 0;
    *(u32*)(p + 4) = t;
    return 0;
}

void func_003062e0(void) {
    func_003053e0();
    asm volatile("sync");
}

void func_0028af90(u8* p, s32 a) {  // obj_set_field22_from_arg
    *(u16*)(p + 22) = (a >= 0) ? a : *(u16*)(p + 4);
}

// Tests bit `bit` of the mask at +0x20.
u32 func_0028b1c0(u8* p, s32 bit) {  // test_bit_field32
    u32 m = *(u32*)(p + 32);
    if (m == 0) return 0;
    return (m & (1 << bit)) != 0;
}

}  // extern "C"

namespace dk {
class SpriteMessage {
public:
    void draw();
};
class Fade {
public:
    void fadeOut(u32 a0, bool a1);
    u8 pad[244];
    bool f_f4;
    u8 pad2[7];
    s32 f_fc;
};
}  // namespace dk

extern "C" void func_00138988(dk::SpriteMessage*);
extern "C" void func_00138de0(dk::SpriteMessage*);
extern "C" void func_0014a9a0(dk::Fade*, u32);

void dk::SpriteMessage::draw() {
    func_00138988(this);
    func_00138de0(this);
}

void dk::Fade::fadeOut(u32 a0, bool a1) {
    f_f4 = a1;
    f_fc = 3;
    func_0014a9a0(this, a0);
}

extern "C" void func_001da458(void*, u32);  // stream_init_fields
extern "C" void func_0016ce90(void*, u32);
void u_tail4_0016cba0(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)(a0 + 28) = 0;
    if ((s32)a1 > 0) func_001da458((void*)a0, a1);  // stream_init_fields
    else func_0016ce90((void*)a0, a1);
}

namespace YS {
class SELECTOR {
public:
    class ARGS;
};
}  // namespace YS
namespace Tz {
class CampMenu {
public:
    void RestartSelector(const YS::SELECTOR*, const YS::SELECTOR::ARGS*);
};
}  // namespace Tz
extern "C" void func_00258b00(void);
extern "C" void func_00258af0(s32);

void Tz::CampMenu::RestartSelector(const YS::SELECTOR*, const YS::SELECTOR::ARGS*) {
    func_00258b00();
    func_00258af0(9);
}
