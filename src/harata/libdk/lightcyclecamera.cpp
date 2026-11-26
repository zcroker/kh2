#include "lightcyclecamera.hpp"
#include "objcamera.hpp"
#include "../../yasui/libys/target.hpp"

// The light-cycle camera's target (0x34a9f0). This file's static initialiser (0x1591e8)
// constructs it; _GLOBAL__I_D_0034a9f0 (0x159220) is its .ctors entry.
YS::TARGET D_0034a9f0;

struct V159070 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct C159070;
struct VTC159070 { u8 pad[64]; s32 (*f64)(C159070*); };
struct C159070 { VTC159070* vt; };
struct O159070 { u8 pad[68]; C159070* c; };

extern "C" {
s32 YS__OBJ__can_control(C159070*);
V159070 func_001904a8(YS::TARGET*);
void func_0015a260(O159070*, V159070*, f32);
u32 func_00167f18(u32);
void func_0015a158(u32, O159070*);
void func_0015a528(O159070*);
void dk__ObjCamera__cancelSubjective(f32);

void func_00159070(O159070* o) {
    if (YS__OBJ__can_control(o->c) || !D_0034a9f0.is_exist()) {
        dk::LightCycleCamera::create();
    } else {
        V159070 v = func_001904a8(&D_0034a9f0);
        func_0015a260(o, &v, 1.0f);
        u32 k = func_00167f18(0);
        if (o->c->vt->f64(o->c)) func_0015a158(k, o);
        func_0015a528(o);
    }
}

void dk__ReactionCamera__create(YS::TARGET* a) {
    dk__ObjCamera__cancelSubjective(30.0f);
    *(u32*)((u8*)dk::ObjCamera::getInstance() + 64) = 3;
    D_0034a9f0 = *a;
}
}

namespace dk {

void LightCycleCamera::create() {
    ObjCamera* cam = ObjCamera::getInstance();
    if (ObjCamera::getMode() == 3) cam->returnMode();
}

}  // namespace dk
