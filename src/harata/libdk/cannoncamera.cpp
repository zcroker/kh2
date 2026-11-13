#include "../../common/types.h"

// dk::CannonCamera (0x1585e8-0x158708): the camera used while riding a cannon. It follows the
// target with the normal object-camera radius code and has no data of its own.

namespace YS { class OBJ; }

struct CcTarget;
struct CcTargetVt { void* f[16]; s32 (*IsValid)(CcTarget*); };
struct CcTarget { CcTargetVt* vt; };

extern "C" {
extern f32 D_00349e10;  // frame time
u8* func_00167f18(u32) asm("_ZN2Tz10MenuCursor13GetInputStateEz");
void func_0013fd78(f32, u8*, u8*) asm("_ZN2dk9ObjCamera10initRadiusEv");
void func_0013fdf0(f32, u8*, u8*);
f32 func_0013fd10(u8*);
void func_0013f828(u8*);
void func_0013f888(u8*, u8*, u32);
void func_0013fca8(u8*) asm("_ZN2dk9ObjCamera9collisionEv");
u8* func_00140df0(void) asm("_ZN2dk9ObjCamera11getInstanceEv");
void func_00140dd0(u8*) asm("_ZN2dk9ObjCamera10returnModeEv");
void func_00140e30(u8*, u32) asm("_Z16wtarget_00140e30jjjj");

// Turns the camera with the pad (or resets the radius while the hold flag is set).
void func_001585e8(u8* p) {
    u8* pad = func_00167f18(0);
    f32 t = D_00349e10;
    f32 r;
    if (*(u64*)(pad + 8) & 0x20000) {
        r = t;
        func_0013fd78(r, p, pad);
    } else {
        func_0013fdf0(t, p, pad);
    }
    r = func_0013fd10(p);
    f32 v = r;
    *(f32*)(p + 0x50) = v;
    *(f32*)(p + 0x4c) = v;
}

void func_00158658(u8* p) {
    CcTarget* t = *(CcTarget**)(p + 68);
    if (t->vt->IsValid(t)) func_001585e8(p);
    func_0013f828(p);
    func_0013f888(p, p + 128, 0);
    func_0013fca8(p);
}

}  // extern "C"

namespace dk {

class CannonCamera {
public:
    static void create(YS::OBJ* obj);
    static void destroy();
};

void CannonCamera::create(YS::OBJ*) {
    u8* cam = func_00140df0();
    *(u32*)(cam + 64) = 8;
    func_00140e30(cam, 3);
}

void CannonCamera::destroy() {
    func_00140dd0(func_00140df0());
}

}  // namespace dk
