#include "light.hpp"
#include "../../harata/libdk/scopecamera.hpp"

// YS::LIGHT (0x158900-0x1589d0): the field light fade rates and colour. ScopeCamera::destroy is
// compiled in this file too (it sits before the file's static initialiser).

struct LightColor {
    f32 r, g, b, a;
    LightColor() {}
    ~LightColor() {}
    LightColor& operator=(const LightColor& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};

f32 D_0034a998 = 0.0f;   // fade-out rate
f32 D_0034a99c = 0.0f;   // fade-in rate
LightColor D_0034a9a0;   // light colour

namespace YS {

void LIGHT::fadeout(f32 value) { D_0034a998 = value; }

void LIGHT::fadein(f32 value) { D_0034a99c = value; }

}  // namespace YS

extern "C" void func_00158920(const LightColor* c) {
    D_0034a9a0 = *c;
}

extern "C" {
u8* func_00140df0(void);   // dk::ObjCamera::getInstance
s32 func_00140dc0(void);   // dk::ObjCamera::getMode
void func_00140dd0(u8*);   // dk::ObjCamera::returnMode
}

namespace dk {

void ScopeCamera::destroy() {
    u8* cam = func_00140df0();
    if (func_00140dc0() == 7) func_00140dd0(cam);
}

}  // namespace dk
