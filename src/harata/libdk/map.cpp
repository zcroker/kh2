#include "map.hpp"

// dk::Map, first part (0x15eba8-0x15efa0): map load/unload, visible groups, the PAX getters and the
// animation speed. The colour/fog tint setter after it (0x15efa0) is still a separate function;
// the rest of the file (effects, the PAX itself and the static init) is map_effect.cpp.

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
void func_001612b8(u8*, u8*);
void func_00142c90(u8*, u8*, u8, u64);
void func_0015f8d8(void*, s32, V15eba8*, V15eba8*, V15eba8*, s32, s32);
void func_0015c2a0(s32, u64);
u32 func_001492e0(u8*) asm("_Z13func_001492e0Pv");
void func_001dddd0(void*, u32) asm("_Z16wtarget_001dddd0jjjj");
void func_001de228(void*, s32, s32, s32, s32, s32);
s32 func_001de568(void*) asm("_ZN3ryj3PAX11ThisIsValidEPS0_");
void func_001dde40(void*);
void func_00142f50(void);
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

void func_0015eba8(u8* o, u8* x, u8 flag, u64 mask)
{
    func_0015f288();
    D_0034c710 = mask;
    func_001612b8(x, o);
    func_00142c90(o, x, flag, mask);
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
        func_001dddd0(&D_0034c6f0, func_001492e0(o));
        D_0034c70c = 1;
        u64 one = 1;
        for (s32 i = 0; i < 64; i++) {
            if (mask & (one << i)) func_001de228(&D_0034c6f0, i, 1, 2, 0, 0);
        }
    }
}

void func_0015edb8(void)
{
    if (D_0034c70c == 1) {
        if (func_001de568(&D_0034c6f0)) func_001dde40(&D_0034c6f0);
    }
    D_0034c70c = 0;
    func_00142f50();
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
    if (D_0034c70c == 1) func_001de228(&D_0034c6f0, g, 1, 2, 0, 0);
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
