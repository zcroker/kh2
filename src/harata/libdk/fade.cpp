// dk::Fade (0x14a950-0x14aed0): screen fades (7 global Fade rectangles at 0x3493a0, 0x110 bytes each).
// Linked unit from the C2 copy of the ctor (0x14a918). The static initialiser
// 0x14aed0 with its _GLOBAL__I_/_GLOBAL__D_ stubs stays outside as plain functions (it builds the
// objects and destroys them through an inline base dtor), so the objects are plain externs here.
#include "../../common/types.h"
#include "fade.hpp"

extern "C" {
extern u8 D_003493a0[];  // all-screen fade
extern u8 D_003494b0[];  // 3D fade
extern u8 D_003495c0[];
extern u8 D_003496d0[];
extern u8 D_003497e0[];
extern u8 D_003498f0[];
extern u8 D_00349a00[];  // wide mask before fade
extern u8 D_00349b10;    // update paused flag
extern u8 D_00349b28[];  // Fade vtable
extern f32 D_00349e14;   // frame step (1.0f)
extern u32 D_0032b91c;

void func_0014b638(void*);  // RectBase C2 ctor
void func_0014a988(void*);
void Fade_setColor(void*, u32, u32, u32, u32) asm("_ZN2dk13RectParamBase8setColorEhhhh");
void Fade_setGsAlpha(void*, u64) asm("_ZN2dk8RectBase10setGsAlphaEy");
void func_0014b1e0(u8*, s32, s32);
void func_0014b208(u8*, s32, s32);
u32 func_00102788(u32, u32, u32, void (*)(void));
void func_00102c18(s32, s32, void (*)(void));
}

// 0x14a918: dk::Fade C2 ctor (same body as the C1)
extern "C" void func_0014a918(void** p) {
    func_0014b638(p);
    *p = D_00349b28;
    func_0014a988(p);
}

// 0x14a950: dk::Fade C1 ctor
extern "C" void func_0014a950(void** p) {
    func_0014b638(p);
    *p = D_00349b28;
    func_0014a988(p);
}

// 0x14a988: reset the fade state
extern "C" void func_0014a988(void* v) {
    u8* p = (u8*)v;
    *(volatile u32*)(p + 260) = 0;
    *(volatile u32*)(p + 248) = 0;
    *(volatile u8*)(p + 244) = 0;
    *(volatile u32*)(p + 252) = 0;
    *(volatile u32*)(p + 256) = 0;
}

// 0x14a9a0: dk::Fade::fadeSetup
extern "C" void func_0014a9a0(char* p, u32 n) {
    if (!n) n = 1;
    float f = (float)(n << 1);
    *(float*)(p + 256) = f;
    *(float*)(p + 260) = 128.0f / f;
    if (*(u8*)(p + 244) == 0) {
        Fade_setColor(p, 0, 0, 0, 0);
        Fade_setGsAlpha(p, 68);
    } else {
        Fade_setColor(p, 255, 255, 255, 0);
        Fade_setGsAlpha(p, 72);
    }
}

namespace n0014aa58 {
class Fade {
public:
    void fadeOut(u32 a0, bool a1) asm("_ZN2dk4Fade7fadeOutEjb");
    u8 pad[244];
    bool f_f4;
    u8 pad2[7];
    s32 f_fc;
};
extern "C" void func_0014a9a0_f(Fade*, u32) asm("func_0014a9a0");

// 0x14aa58: dk::Fade::fadeOut
void Fade::fadeOut(u32 a0, bool a1) {
    f_f4 = a1;
    f_fc = 3;
    func_0014a9a0_f(this, a0);
}
}  // namespace n0014aa58

// 0x14aa80: dk::Fade::fadeIn
extern "C" void func_0014aa80(char* p, u32 n, u8 c) {
    *(u32*)(p + 252) = 1;
    *(u8*)(p + 244) = c;
    *(u32*)(p + 248) = 1;
    func_0014a9a0(p, n);
}

namespace n0014aaa8 {
struct W14aaa8 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    u8 pad[15];
    u8 alpha;
    u8 pad2[228];
    s32 count;
    s32 state;
    f32 t;
    f32 scale;
};
void wtarget_0014aaa8(W14aaa8* p) asm("_Z16wtarget_0014aaa8jjjj");

// 0x14aaa8: dk::Fade::update
void wtarget_0014aaa8(W14aaa8* p) {
    switch (p->state) {
    case 0:
        return;
    case 1:
        if (p->count == 0) p->state = 2;
        p->count--;
        p->alpha = 0x80;
        break;
    case 2:
        p->t -= D_00349e14;
        p->alpha = (s32)(p->scale * p->t);
        if (p->t <= 0.0f) {
            p->alpha = 0;
            p->state = 0;
        }
        break;
    case 3:
        p->t -= D_00349e14;
        p->alpha = 0x80 - (s32)(p->scale * p->t);
        if (p->t <= 0.0f) {
            p->alpha = 0x80;
            p->state = 4;
        }
        break;
    case 4:
        break;
    }
    p->v2();
}
}  // namespace n0014aaa8

extern "C" void Fade_update(u8*) asm("_Z16wtarget_0014aaa8jjjj");

// 0x14aba8-0x14ac08: the fade objects
extern "C" u32 getAllFade(void) asm("_ZN2dk10getAllFadeEv");
extern "C" u32 getAllFade(void) { return (u32)D_003493a0; }
extern "C" u32 func_0014abb8(void) { return (u32)D_003497e0; }
extern "C" u32 func_0014abc8(void) { return (u32)D_003498f0; }
extern "C" u32 get3DFade(void) asm("_ZN2dk9get3DFadeEv");
extern "C" u32 get3DFade(void) { return (u32)D_003494b0; }
extern "C" u32 func_0014abe8(void) { return (u32)D_003495c0; }
extern "C" u32 func_0014abf8(void) { return (u32)D_003496d0; }
extern "C" u32 getWideMaskBeforeFade(void) asm("_ZN2dk21getWideMaskBeforeFadeEv");
extern "C" u32 getWideMaskBeforeFade(void) { return (u32)D_00349a00; }

// 0x14ac18: task: update the all-screen fade unless paused
extern "C" void func_0014ac18(void) {
    if (D_00349b10 == 0) {
        Fade_update(D_003493a0);
        return;
    }
}

// 0x14ac48 .. 0x14acb0: tasks that update the other fades
extern "C" void func_0014ac48(void) { Fade_update(D_003494b0); }
extern "C" void func_0014ac68(void) {
    Fade_update(D_003495c0);
    Fade_update(D_003496d0);
}
extern "C" void func_0014ac90(void) { Fade_update(D_00349a00); }
extern "C" void func_0014acb0(void) {
    Fade_update(D_003497e0);
    Fade_update(D_003498f0);
}

// 0x14acd8 / 0x14ace8: pause / resume the all-screen fade
extern "C" void func_0014acd8(void) { D_00349b10 = 1; }
extern "C" void func_0014ace8(void) { D_00349b10 = 0; }

// 0x14acf8
extern "C" void func_0014acf8(void) {
    func_0014ace8();
    func_0014a988(D_003493a0);
}

// 0x14ad20: reset and start the all-screen fade task
extern "C" void func_0014ad20(void) {
    func_0014acf8();
    func_00102788(D_0032b91c, 0, 0x50910, func_0014ac18);
}

// 0x14ad58: place the four letterbox bars
extern "C" void func_0014ad58(void) {
    func_0014b1e0(D_003495c0, 0, 0);
    func_0014b208(D_003495c0, 512, 35);
    func_0014b1e0(D_003496d0, 0, 381);
    func_0014b208(D_003496d0, 512, 35);
    func_0014b1e0(D_003497e0, 0, 0);
    func_0014b208(D_003497e0, 512, 35);
    func_0014b1e0(D_003498f0, 0, 381);
    func_0014b208(D_003498f0, 512, 35);
}

// 0x14ae10: reset the fades and start their tasks
extern "C" void func_0014ae10(void) {
    func_0014a988(D_003495c0);
    func_0014a988(D_003496d0);
    func_0014a988(D_003497e0);
    func_0014a988(D_003498f0);
    func_0014a988(D_00349a00);
    func_0014a988(D_003494b0);
    func_0014ad58();
    func_00102c18(0, 80000, func_0014ac48);
    func_00102c18(0, 80000, func_0014ac68);
    func_00102c18(0, 0x19640, func_0014ac90);
    func_00102c18(0, 0x19a28, func_0014acb0);
}
