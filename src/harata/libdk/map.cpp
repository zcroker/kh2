#include "map.hpp"

// dk::Map, first part (0x15eba8-0x15efa0): map load/unload, visible groups, the PAX getters and the
// animation speed, then the colour/fog tint setter (0x15efa0). The rest of the file (effects, the
// PAX itself and the static init) is map_effect.cpp.

namespace ryj { class PAX; }
extern ryj::PAX D_0034c6f0 asm("D_0034c6f0");
extern u8 D_0034c70c asm("D_0034c70c");  // the PAX holds the map's effects
extern u64 D_0034c710 asm("D_0034c710");  // visible groups, one bit each

// lq/sq 128-bit copy and VU0 vf0 store (hand-written VU idioms)
#define QCOPY_15eba8(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V15eba8 {
    f32 x, y, z, w;
    V15eba8() {}
    V15eba8(const V15eba8& o) { QCOPY_15eba8(this, &o); }
    void Set15eba8(const V15eba8& o) { QCOPY_15eba8(this, &o); }
} __attribute__((aligned(16)));
static inline void Unit15eba8(V15eba8* v) { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(v) : "memory"); }
struct A15eba8;
struct AV15eba8 { void* (*alloc)(A15eba8*, u32, void*); };
struct A15eba8 { AV15eba8* vt; };

extern "C" {
extern A15eba8* D_0034c738;
void func_0015f288();
void dk__BgObj__init(u8*, u8*);
void dk__Octree__create(u8*, u8*, u8, u64);
void func_0015f8d8(void*, s32, V15eba8*, V15eba8*, V15eba8*, s32, s32);
void func_0015c2a0(s32, u64);
u32 func_001492e0(u8*) asm("_Z13func_001492e0Pv");
void ryj__PAX__init(void*, u32) asm("_Z14ryj__PAX__initjjjj");
void ryj__PAX__start_group(void*, s32, s32, s32, s32, s32);
s32 func_001de568(void*) asm("_ZN3ryj3PAX11ThisIsValidEPS0_");
void ryj__PAX__ensure(void*);
void dk__Octree__destroy(void);
void func_00143060(void);
void func_001538d8(u8);
void func_0015c4a0(u32);
void func_001de3d8(void*, u32);
void func_00143110(u32);
void func_00153948(u8);
void func_0015c450(u32);
u32 func_00143318(u32);
void func_0011e9a8(u32, u32, u32, u32, f32) asm("_Z16wtarget_0011e9a8jjjj");
void func_00161248(u32, f32);

void dk__Map__create(u8* o, u8* x, u8 flag, u64 mask)
{
    func_0015f288();
    D_0034c710 = mask;
    dk__BgObj__init(x, o);
    dk__Octree__create(o, x, flag, mask);
    V15eba8 a, b, c;
    Unit15eba8(&a);
    Unit15eba8(&b);
    c.x = 1.0f; c.y = 1.0f; c.z = 1.0f; c.w = 1.0f;
    s32 n0 = *(s32*)(o + 0x6c);
    s32 made = 0;
    if (n0 == 1) {
        void* p = D_0034c738->vt->alloc(D_0034c738, 752, __builtin_return_address(0));
        V15eba8 ta(a), tb(b), tc(c);
        func_0015f8d8(p, 0, &ta, &tb, &tc, 0, 0);
        made = 1;
    }
    s32 n1 = *(s32*)(o + 0x70);
    if (n1 == 1) {
        void* p = D_0034c738->vt->alloc(D_0034c738, 752, __builtin_return_address(0));
        V15eba8 tc, tb, ta;
        ta.Set15eba8(a); tb.Set15eba8(b); tc.Set15eba8(c);
        func_0015f8d8(p, made, &ta, &tb, &tc, made, 1);
    }
    func_0015c2a0(n0 + n1, mask);
    D_0034c70c = 0;
    if (func_001492e0(o)) {
        ryj__PAX__init(&D_0034c6f0, func_001492e0(o));
        D_0034c70c = 1;
        u64 one = 1;
        for (s32 i = 0; i < 64; i++) {
            if (mask & (one << i)) ryj__PAX__start_group(&D_0034c6f0, i, 1, 2, 0, 0);
        }
    }
}

void func_0015edb8(void)
{
    if (D_0034c70c == 1) {
        if (func_001de568(&D_0034c6f0)) ryj__PAX__ensure(&D_0034c6f0);
    }
    D_0034c70c = 0;
    dk__Octree__destroy();
}
}

namespace dk {

// Clear the group's bit in the visible-group mask and refresh.
void Map::setHideGroup(u32 g)
{
    D_0034c710 = ~(1ULL << g) & D_0034c710;
    func_00143060();
    func_001538d8(g);
    func_0015c4a0(g);
    if (D_0034c70c == 1) func_001de3d8(&D_0034c6f0, g);
}

void Map::setVisibleGroup(u32 g)
{
    D_0034c710 = (1ULL << g) | D_0034c710;
    func_00143110(g);
    func_00153948(g);
    func_0015c450(g);
    if (D_0034c70c == 1) ryj__PAX__start_group(&D_0034c6f0, g, 1, 2, 0, 0);
}

u32 Map::isPaxExist() { return D_0034c70c; }

void* Map::getPax() { return &D_0034c6f0; }

}  // namespace dk

extern "C" {
u32 func_0015ef38(u32 type) { return func_00143318(type); }
}

namespace dk {
void Map::setAnimationSpeedRatio(kn::AnimationWork::TYPE type, f32 r)
{
    func_0011e9a8(func_00143318(type), type, 0, 0, r);
    func_00161248(type, r);
}
}  // namespace dk

// ---- 0x0015efa0 (was whole asm, src/anon/batch_w3876.s): tint the map. The ambient colour and the
// fog colour are multiplied by (r, g, b) / 128, then the models, the background objects and the
// map's effects get the tint. The colour and the fog share the base struct Rgba (as in the fog
// functions at 0x15c500-0x15ca40): the fog's r store and the local colour's a store are then
// different fields of one type and do not depend on each other.
namespace n0015efa0 {
struct Rgba { u8 r, g, b, a; };
struct Fog : Rgba {
    f32 near, far, min, max;
    inline void update();
};
s32 func_0015f268(void) asm("func_0015f268");
void func_0015cb18(u8*, u8*, u8*, u8*) asm("func_0015cb18");
void func_0015cbb8(u8, u8, u8, u8) asm("func_0015cbb8");
void func_0015c4b8(void) asm("func_0015c4b8");
Fog* func_0015cc60(void) asm("func_0015cc60");
Fog* func_0015cc50(void) asm("func_0015cc50");
s32 func_0015cc80(Fog*) asm("func_0015cc80");
void func_0010a8a8(f32, f32) asm("func_0010a8a8");
void func_0010a828(f32, f32) asm("func_0010a828");
void func_0010a7d8(u8, u8, u8) asm("func_0010a7d8");
void func_001dd1e8(u8, u8) asm("func_001dd1e8");
void func_001dd1b0(f32, f32) asm("func_001dd1b0");
void func_001dd1c8(u8, u8, u8) asm("func_001dd1c8");
void func_001432f0(u8, u8, u8) asm("func_001432f0");
void func_001611a8(u8, u8, u8) asm("func_001611a8");
u8* func_001de4b0(void*, s32, u8*) asm("func_001de4b0");
s32 func_001dc9e0(u8*) asm("func_001dc9e0");
f32* func_001dc670(u8*) asm("func_001dc670");
static inline void SetRgba(Rgba* c, s32 r, s32 g, s32 b, s32 a) {
    c->r = r;
    c->g = g;
    c->b = b;
    c->a = a;
}
inline void Fog::update() {
    if (!func_0015cc80(this)) {
        func_0010a8a8(min, max);
        func_0010a828(near, far);
        func_0010a7d8(r, g, b);
    }
    func_001dd1e8((s32)min, (s32)max);
    func_001dd1b0(near, far);
    func_001dd1c8(r, g, b);
}
void func_0015efa0(u8 r, u8 g, u8 b) asm("func_0015efa0");
void func_0015efa0(u8 r, u8 g, u8 b)
{
    Rgba c;
    Rgba m;
    if (func_0015f268()) return;
    s32 alpha = 0x80;
    m.r = r;
    m.g = g;
    m.b = b;
    m.a = alpha;
    f32 fg, fr;
    fr = r * 0.0078125f;
    fg = g * 0.0078125f;
    f32 fb = b * 0.0078125f;
    func_0015cb18(&c.r, &c.g, &c.b, &c.a);
    c.r = (c.r * m.r) >> 7;
    c.g = (c.g * m.g) >> 7;
    c.b = (c.b * m.b) >> 7;
    c.a = (c.a * m.a) >> 7;
    func_0015cbb8(c.r, c.g, c.b, c.a);
    func_0015c4b8();
    Fog* src = func_0015cc60();
    Fog* t = func_0015cc50();
    c.r = src->r;
    c.g = src->g;
    c.b = src->b;
    c.r = (c.r * m.r) >> 7;
    c.g = (c.g * m.g) >> 7;
    c.b = (c.b * m.b) >> 7;
    c.a = (c.a * m.a) >> 7;
    SetRgba(t, c.r, c.g, c.b, alpha);
    t->update();
    u8* o = 0;
    func_001432f0(r, g, b);
    func_001611a8(r, g, b);
    if (D_0034c70c != 1) return;
    for (s32 i = 0; i < 64; i++) {
        while ((o = func_001de4b0(&D_0034c6f0, i, o))) {
            if (func_001dc9e0(o)) {
                f32* col = func_001dc670(o);
                col[0] = fr;
                col[1] = fg;
                col[2] = fb;
            }
        }
    }
}
}  // namespace n0015efa0
