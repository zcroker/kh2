// Ti::MiniGame: the minigame base (current game in 0x361f60, vtable 0x361f70). Linked unit
// 0x2cea28-0x2cf268; the first function of the file (0x2ce958) is whole asm and stays outside.
#include "../common/types.h"

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCOPYN(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")

struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4 { V4 r[4]; } __attribute__((aligned(16)));
static inline void MCOPY(M4* d, const M4* s) {
    asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory");
}
static inline void MMul(M4* d, M4* a, M4* b) {
    asm volatile(
        "lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
        "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
        "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
        "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
        "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void MMulTo(M4* d, M4* a, M4* b) {
    M4 t;
    MMul(&t, a, b);
    if (d != &t) MCOPY(d, &t);
}
struct MdlRef { u32 a; u8* mdl; };
struct E16 { u32 a; u32 b; u32 c; u8* obj; };

struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(const Vec4& o) { QCOPYN(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct Mtx {
    Vec4 r[4];
    Mtx() {}
    Mtx& operator=(const Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

struct W41S24 { u32 w[6]; };

struct V2c {
    f32 x, y, z, w;
    V2c() {}
    V2c(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V2c& operator=(const V2c& o) {
        if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Box2c { V2c a, b; };
struct Mat2c { V2c r[4]; };

struct V2cf {
    f32 x, y, z, w;
    V2cf() {}
    V2cf(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));
struct M2cf { V2cf r[4]; };
struct T2cf { u16 f0; u16 kind; f32 x, y, z; };
struct Box2cf { u8 d[32]; } __attribute__((aligned(16)));

struct MG;
struct MGVt { void* f0; void (*dtor)(MG*); };
struct MG { MGVt* vt; u8 drawn; u8 pad5[83]; u8 active; u8 pad89[7]; u32 f60; };

extern "C" {
void func_002fee78(char*, const char*, ...);
u32 func_002cf3f8(void*);
void func_00105110(void*);
void func_00170950(u32);
u32 func_00146730(void*, void*);
u32 func_00106a18(u32);
M4* func_00106ad0(u32);
u8* func_00106a60(u32);
void func_00146680(u8*, M4*);
u32 func_002d00e0(void*);
u8* func_00102c80(void);
u8* func_00102788(u32, u32, u32, u32);
void func_002d0718(void*);
void func_0011b6a8(void*);
void func_0011b720(void*, f32);
void func_001449a8(void*, void*);
void func_001444c8(void*, void*, void*);
u32 func_002e7518(void*);
}

extern u8 D_00361f70[];
MG* D_00361f60;

u32 vf_culling(void* f, void* box) asm("_ZN2dk11ViewFrustum7cullingERKNS_6AabboxE");

namespace Ti {
struct MiniGame {
    void make_data_path(char* out, char* name);
    static s32 type();
    static u8 be_ready();
    u32 is_visible(const void* box);
    static u32 task_last(void* t);
    u32 bbox_is_visible(const void* box);
    u32 exec();
};
}

void func_002cea28(MG* p) {
    p->vt = (MGVt*)D_00361f70;
    func_002cf3f8(p);
    D_00361f60 = 0;
    p->active = 0;
}

void func_002cea68(MG* p) {
    p->vt = (MGVt*)D_00361f70;
    func_002cf3f8(p);
    D_00361f60 = 0;
    p->active = 0;
}

void func_002ceaa8(MG* p) {
    p->vt = (MGVt*)D_00361f70;
    func_002cf3f8(p);
    D_00361f60 = 0;
    p->active = 0;
    func_00105110(p);
}

void Ti::MiniGame::make_data_path(char* out, char* name) {
    func_002fee78(out, "minigame/%s.bar", name);
}

s32 Ti::MiniGame::type() {
    MG* g = D_00361f60;
    s32 r = 6;
    if (g != 0) r = ((s32*)g)[20];
    return r;
}

u8 Ti::MiniGame::be_ready() {
    MG* g = D_00361f60;
    if (g == 0) return 0;
    return g->active;
}

void func_002ceb48(void) {
    if (!D_00361f60) return;
    if (D_00361f60->f60) {
        func_00170950(D_00361f60->f60);
        D_00361f60->f60 = 0;
        asm volatile("" ::: "memory");
    }
    if (D_00361f60) D_00361f60->vt->dtor(D_00361f60);
    D_00361f60 = 0;
}

u32 func_002cebb0(void) { return D_00361f60 != 0; }

void wt_2cebc0(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_002cebc0jjjj");
void wt_2cebc0(u32 a, u32 b, u32 c, u32 d) {}

u32 func_002cebc8(u32 a) {
    u8* o = (u8*)D_00361f60;
    if (o) return (*(u32 (**)(void*, u32))(*(u8**)o + 16))(o, a);
    return 0;
}

u32 vf_culling(void* f, void* box) { return func_00146730((u8*)f + 16, box); }

u32 Ti::MiniGame::is_visible(const void* box) {
    u32 r = 0;
    if (((u8*)this)[4] != 0) {
        r = vf_culling(this, (void*)box) != 0;
    }
    return r;
}

void func_002cec50(u32 a0) {
    u8* o = (u8*)D_00361f60;
    if (o != 0) {
        (*(void (**)(void*, u32))(*(u8**)o + 12))(o, a0);
    }
}

void func_002cec88(MdlRef* r) {
    u8* mdl = r->mdl + 16;
    M4 m;
    MCOPY(&m, func_00106ad0(func_00106a18(1)));
    MMulTo(&m, &m, (M4*)(func_00106a60(1) + 16));
    func_00146680(mdl, &m);
    if (D_00361f60 && D_00361f60->active) D_00361f60->drawn = 1;
}

u32 Ti::MiniGame::task_last(void* t) { return func_002d00e0(t); }

void func_002cedd0(s32 n, E16* e) {
    for (s32 i = 0; i < n; i++, e++) {
        u8* o = func_00102788(*(u32*)(func_00102c80() + 4), 1, e->a, e->b);
        *(E16**)(o + 8) = e;
        *(MG**)(o + 4) = D_00361f60;
        e->obj = o;
        if (e->c) *(u32*)(o + 48) = e->c;
    }
}

s32 func_002cee58(void* a, u8* o)
{
    u8 buf[32] __attribute__((aligned(16)));
    func_002d0718(buf);
    Mtx m;
    func_0011b6a8(&m);
    func_0011b720(&m, *(f32*)(o + 20));
    Vec4 t;
    t.x = *(f32*)(o + 4);
    t.y = *(f32*)(o + 8);
    t.z = *(f32*)(o + 12);
    t.w = 0.0f;
    asm volatile("lqc2 $vf1, 48(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 48(%0)" : : "r"(&m), "r"(&t) : "memory");
    func_001449a8(buf, &m);
    return vf_culling(a, buf) != 0;
}

bool func_002ceef8(u32, u8* p) {
    MG* d = D_00361f60;
    W41S24* s = (W41S24*)(p + 1856);
    W41S24 t = *s;
    return vf_culling(d, &t) != 0;
}

u32 Ti::MiniGame::bbox_is_visible(const void* box) {
    return vf_culling(D_00361f60, (void*)box) != 0;
}

u8 func_002cef80(void* a0, V2c* pos) {
    V2c lo(-100.0f, -100.0f, -100.0f, 0.0f);
    V2c hi(100.0f, 100.0f, 100.0f, 0.0f);
    Box2c box;
    Mat2c m;
    V2c* r3 = &m.r[3];
    func_001444c8(&box, &lo, &hi);
    func_0011b6a8(&m);
    *r3 = *pos;
    m.r[3].w = 1.0f;
    func_001449a8(&box, &m);
    return vf_culling(D_00361f60, &box) != 0;
}

static inline void trans2cf(M2cf* m, V2cf* v) {
    asm volatile("lqc2 $vf1,48(%0)\n\tlqc2 $vf2,0(%1)\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,48(%0)" : : "r"(m), "r"(v) : "memory");
}

void wt_002cf058(u8* self, u8* obj) asm("_Z16wtarget_002cf058jjjj");
void wt_002cf058(u8* self, u8* obj) {
    T2cf* t = *(T2cf**)(obj + 108);
    if (t->kind != 3) return;
    f32 zero = 0.0f;
    V2cf v(t->x, t->y, t->z, zero);
    M2cf m;
    func_0011b6a8(&m);
    trans2cf(&m, &v);
    V2cf lo, hi;
    Box2cf box;
    lo.x = 1.0f;
    lo.y = 1.0f;
    hi.x = -1.0f;
    hi.y = -1.0f;
    lo.z = 1.0f;
    lo.w = zero;
    hi.z = -1.0f;
    hi.w = zero;
    func_001444c8(&box, &hi, &lo);
    func_001449a8(&box, &m);
    if (vf_culling(self, &box)) *(u32*)(obj + 104) |= 1;
    else *(u32*)(obj + 104) &= ~1;
}

void func_002cf170(u32 a0, u32 a1, u32 a2) {
    u8* o = (u8*)D_00361f60;
    if (o != 0) {
        (*(void (**)(void*, u32, u32, u32))(*(u8**)o + 20))(o, a0, a1, a2);
    }
}

u32 func_002cf1b8(u32 a0) asm("_Z16u_call4_002cf1b8jjjj");
u32 func_002cf1b8(u32 a0) {
    u8* o = (u8*)D_00361f60;
    if (o != 0) {
        return (*(u32 (**)(void*, u32))(*(u8**)o + 32))(o, a0);
    }
    return 1;
}

s32 func_002cf1f8(u8* a, u8* b) {
    if (D_00361f60 && (*(u32*)(a + 1416) & 0x8000000) && (*(u32*)(b + 1416) & 0x8000000))
        return *(u32*)(a + 2804) == *(u32*)(b + 2804);
    return 1;
}

u32 Ti::MiniGame::exec() { return func_002e7518(this); }
