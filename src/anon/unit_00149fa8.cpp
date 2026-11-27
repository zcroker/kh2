#include "../common/types.h"

// dk Field / LoopDemo / SoftReset / Blur (0x149fa8-0x14a918): the field start helpers (area id lookup,
// world-map and title start), the loop-demo and soft-reset flags, the soft-reset task and the full-screen
// blur sprite. Every symbol is bound by asm label. Globals stay where they are (extern).

typedef void (*Fn0)(u8*);

// ---- Field ----
struct AreaPair { u32 value; u32 key; };
extern AreaPair D_0036b028[] asm("D_0036b028");

// 00149fa8: area number -> world id.
u32 func_00149fa8(u32 key) asm("func_00149fa8");
u32 func_00149fa8(u32 key) {
    AreaPair* p = D_0036b028;
    for (s32 i = 0; i < 15; i++, p++) {
        if (key == p->key) return p->value;
    }
    return 0;
}

struct S10 { u8 a, b, c; u16 d, e, f; };
void func_001991a8(s32, s32) asm("func_001991a8");
u8* func_001058e8(void) asm("func_001058e8");
u8 func_00149fa8_b(s32) asm("func_00149fa8");
void AREA__MapJump(S10*, u32, s32, s32, s32) asm("AREA__MapJump");

// 00149fe0: dk::Field::WorldMapStart
void func_00149fe0(s32 a, u32 b) asm("func_00149fe0");
void func_00149fe0(s32 a, u32 b) {
    func_001991a8(33, 0);
    S10 s;
    u16 m = 0xffff;
    s.a = m;
    s.b = m;
    s.c = m;
    s.d = m;
    s.e = m;
    s.f = m;
    if (a < 0) a = func_001058e8()[12];
    func_001058e8()[12] = 15; s.a = 15;
    func_001058e8()[13] = 0; s.b = 0;
    u8* g = func_001058e8();
    u8 r = func_00149fa8_b(a);
    g[14] = r;
    s.c = r;
    AREA__MapJump(&s, b | 1, 0, 0, 0);
}

void func_0014df88(void) asm("func_0014df88");
void func_0014e0d8(void) asm("func_0014e0d8");
u8* func_0014aba8(void) asm("func_0014aba8");
void func_0014aa58(u8*, u32, u32) asm("func_0014aa58");
void func_00102448(u8*, u32) asm("func_00102448");
u8* func_00103070(void) asm("func_00103070");

// 0014a0a0: dk::Field::execTitle_task
static inline bool ready_14a0a0() { return *(u32*)(func_0014aba8() + 252) == 4; }
void dk__Field__execTitle_task(u8* p) asm("dk__Field__execTitle_task");
void dk__Field__execTitle_task(u8* p) {
    if (*(u8*)(p + 4) == 0) {
        func_0014df88();
        func_0014e0d8();
        func_0014aa58(func_0014aba8(), 15, 0);
        while (!ready_14a0a0()) func_00102448(p, 0);
    }
    u8* o = func_00103070();
    (**(Fn0**)o)(o);
}

u8* TASK_MANAGER__create_thread(u32, s32, u32, void*, s32) asm("TASK_MANAGER__create_thread");
extern u32 D_0032b96c asm("D_0032b96c");

// 0014a138: dk::Field::TitleStart
void TitleStart(bool flag) asm("_ZN2dk5Field10TitleStartEb");
void TitleStart(bool flag) {
    u8* t = TASK_MANAGER__create_thread(D_0032b96c, 0, 0x493e0, (void*)dk__Field__execTitle_task, 4096);
    t[4] = flag;
}

void func_0013a6d0(void) asm("func_0013a6d0");
u8* func_00102c18(u32, u32, void*) asm("func_00102c18");
void func_0014a830(u8* p) asm("_ZN2dk4Blur9blur_taskEP4TASK");
void func_0014ae10(void) asm("func_0014ae10");
void func_0013a9e8(u32) asm("func_0013a9e8");
void worldmap__Manager__readPackEnable(void) asm("worldmap__Manager__readPackEnable");

// 0014a188: dk::Field::init
void func_0014a188(void) asm("func_0014a188");
void func_0014a188(void) {
    func_0013a6d0();
    u8* r = func_00102c18(0, 0x124f8, (void*)func_0014a830);
    r[4] = 0;
    func_0014ae10();
    func_0013a9e8(1);
    worldmap__Manager__readPackEnable();
}

// ---- LoopDemo / soft reset flags ----
extern u8 D_00349268 asm("D_00349268");
extern u8 D_00349269 asm("D_00349269");
extern u8 D_0034926a asm("D_0034926a");
extern u8 D_0034926b asm("D_0034926b");
extern u8 D_0034926b_a[] asm("D_0034926b");  // [1] is the byte at 0x34926c

// 0014a1d0: dk::LoopDemo::set (never written before)
void LoopDemo_set(void) asm("_ZN2dk8LoopDemo3setEv");
void LoopDemo_set(void) { D_00349268 = 1; }

// 0014a1e0: dk::LoopDemo::reset
void func_0014a1e0(void) asm("func_0014a1e0");
void func_0014a1e0(void) { D_00349268 = 0; }

void func_00138480(u32) asm("func_00138480");

// 0014a1f0: dk::LoopDemo::isLoopDemo
u8 LoopDemo_isLoopDemo(void) asm("_ZN2dk8LoopDemo10isLoopDemoEv");
u8 LoopDemo_isLoopDemo(void) {
    if (D_00349268 == 1) func_00138480(0);
    return D_00349268;
}

void func_0014a238(void) asm("func_0014a238");
void func_0014a238(void) { D_00349269 = 1; }
void func_0014a248(void) asm("func_0014a248");
void func_0014a248(void) { D_00349269 = 0; }
u8 func_0014a258(void) asm("func_0014a258");
u8 func_0014a258(void) { return D_00349269; }

s32 func_002b99a0(void) asm("func_002b99a0");
s32 func_001ae990(void) asm("func_001ae990");
s32 func_002f79c8(s32) asm("func_002f79c8");
void func_00167b08(s32) asm("func_00167b08");
void func_0014d060(void) asm("func_0014d060");

// 0014a268: reset buttons held
bool func_0014a268(void) asm("func_0014a268");
bool func_0014a268(void) { return func_002b99a0() == 1; }

// 0014a290
bool func_0014a290(void) asm("func_0014a290");
bool func_0014a290(void) {
    bool r = 0;
    if (func_002b99a0() != 1) r = func_001ae990() == 0;
    return r;
}

// 0014a2c8
bool func_0014a2c8(void) asm("func_0014a2c8");
bool func_0014a2c8(void) { return func_002f79c8(1) == 2; }

// 0014a2f0: wait one frame
void func_0014a2f0(void) asm("func_0014a2f0");
void func_0014a2f0(void) {
    func_00167b08(0);
    func_0014d060();
}

s32 func_0014ca10(void) asm("func_0014ca10");
void Tz__MenuSound__SetPause(s32) asm("Tz__MenuSound__SetPause");
void func_0014c9d8(s32) asm("func_0014c9d8");
void func_0014c9f0(s32) asm("func_0014c9f0");
void func_002ef7f0(s32) asm("func_002ef7f0");
void func_00242790(void) asm("func_00242790");

// 0014a310: soft-reset task (never written before)
void func_0014a310(void) asm("func_0014a310");
void func_0014a310(void) {
    s32 reset = 0;
    s32 paused = 0;
    s32 loop = 1;
    s32 r = 0;
    do {
        if (func_0014a258()) return;
        if (func_0014a268()) reset = 1;
        if (func_0014a290()) reset = 0;
        if (!paused && reset == 1) {
            r = func_0014ca10();
            Tz__MenuSound__SetPause(1);
            if (!r) {
                func_0014c9d8(1);
                func_0014c9d8(1);
            }
            func_002ef7f0(1);
            paused = 1;
        }
        if (paused == 1) {
            if (!reset) {
                paused = 0;
                D_0034926a = 1;
            }
        }
        if (reset) {
            func_0014a2f0();
        } else {
            if (D_0034926a) {
                do {
                    if (func_0014a2c8()) {
                        D_0034926a = 0;
                        if (!r) func_0014c9f0(1);
                        func_002ef7f0(0);
                        func_00242790();
                        break;
                    }
                    func_0014a2f0();
                } while (D_0034926a);
            }
            loop = 0;
        }
    } while (loop);
}

extern u32 D_0032b91c asm("D_0032b91c");
void func_00102788(u32, u32, u32, void (*)(void)) asm("func_00102788");

// 0014a470: start the soft-reset task
void func_0014a470(void) asm("func_0014a470");
void func_0014a470(void) {
    D_0034926a = 0;
    func_0014a248();
    func_00102788(D_0032b91c, 0, 0x1c908, func_0014a310);
}

// 0014a4b0: dk::SoftReset::disable
void SoftReset_disable(void) asm("_ZN2dk9SoftReset7disableEv");
void SoftReset_disable(void) { D_0034926b = 1; }
void func_0014a4c0(void) asm("func_0014a4c0");
void func_0014a4c0(void) { D_0034926b = 0; }
// 0014a4d0, 0014a4e0: never written before
u8 func_0014a4d0(void) asm("func_0014a4d0");
u8 func_0014a4d0(void) { return D_0034926b; }
u8 func_0014a4e0(void) asm("func_0014a4e0");
u8 func_0014a4e0(void) { return D_0034926b_a[1]; }
void func_0014a4f0(void) asm("func_0014a4f0");
void func_0014a4f0(void) { D_0034926b_a[1] = 0; }

// ---- Blur ----
extern u8 D_00349270[] asm("D_00349270");
extern f32 D_00349390 asm("D_00349390");
extern s32 D_00349394 asm("D_00349394");
extern f32 D_00349398 asm("D_00349398");
extern u8 D_0034939c asm("D_0034939c");
extern u8 D_0034939d asm("D_0034939d");
extern u8 D_0034939e asm("D_0034939e");
extern f32 D_00349e10 asm("D_00349e10");
void f14a500_setRot(void*, f32) asm("_ZN2dk7Ft4Base6setRotEf");
f32 func_0013edd8(void*) asm("func_0013edd8");
void f14a500_setGsTex0(void*, u64) asm("_ZN2dk7Ft4Base9setGsTex0Ey");
void func_0013ee30(void*, s64) asm("func_0013ee30");
void f14a500_setGsUV(void*, u64, u64, u64, u64) asm("_ZN2dk7Ft4Base7setGsUVEyyyy");
void func_0013eeb8(void*) asm("func_0013eeb8");
void f14a500_setXY(void*, s16, s16) asm("_ZN2dk13RectParamBase5setXYEss");
void f14a500_loadImage(u32) asm("_ZN2dk9loadImageEj");
void f14a500_storeImage(void) asm("_ZN2dk10storeImageEv");
f32 f14a500_FixRadian(f32) asm("_ZN2YS4MATH9FixRadianEf");

// 0014a500: dk::Blur::update
void dk__Blur__update(void) asm("dk__Blur__update");
void dk__Blur__update(void)
{
    if (!D_0034939c) {
        D_0034939e = 1;
        return;
    }
    if (D_0034939d == 1) {
        if (D_0034939e == 1) {
            f14a500_storeImage();
            D_0034939e = 0;
        }
        f14a500_loadImage(320);
        f14a500_setGsUV(D_00349270, 0x80008, 0x82008, 0x1a080008, 0x1a082008);
        f14a500_setGsTex0(D_00349270, 0x2000000264122800ULL);
        func_0013ee30(D_00349270, 0);
    } else {
        f14a500_setGsUV(D_00349270, 0x80008, 0x82008, 0x1c080008, 0x1c082008);
        f14a500_setGsTex0(D_00349270, 0x2000000264120000ULL);
        func_0013ee30(D_00349270, 96);
    }
    f14a500_setXY(D_00349270, 256, 208);
    f32 rot;
    if (D_00349390 == 0.0f) rot = 0.0f;
    else {
        rot = func_0013edd8(D_00349270);
        if ((s32)D_00349398 < D_00349394) {
            rot += D_00349390 * D_00349e10;
            rot = f14a500_FixRadian(rot);
            D_00349398 += D_00349e10;
        }
    }
    f14a500_setRot(D_00349270, rot);
    func_0013eeb8(D_00349270);
    if (D_0034939d == 1) f14a500_storeImage();
}

void func_0014b208(u8*, s32, s32) asm("func_0014b208");
void func_0013edd0(u8*, f32) asm("func_0013edd0");
void func_0014b248(u8*, s32) asm("func_0014b248");
void func_0013ee38(u8*, s32) asm("func_0013ee38");

// 0014a6e0: dk::Blur::init
void dk__Blur__init(void) asm("dk__Blur__init");
void dk__Blur__init(void) {
    D_00349394 = 1;
    D_0034939d = 0;
    D_00349390 = 0;
    D_00349398 = 0;
    func_0014b208(D_00349270, 256, 208);
    func_0013edd0(D_00349270, 0.0f);
    func_0014b248(D_00349270, 112);
    func_0013ee38(D_00349270, 340);
    D_0034939c = 0;
}

// 0014a768: dk::Blur::setBlurAlpha
void Blur_setBlurAlpha(u8 a) asm("_ZN2dk4Blur12setBlurAlphaEh");
void Blur_setBlurAlpha(u8 a) { func_0014b248(D_00349270, a); }

// 0014a788: dk::Blur::setBlurXYSize
void Blur_setBlurXYSize(u16 x, u16 y) asm("_ZN2dk4Blur13setBlurXYSizeEtt");
void Blur_setBlurXYSize(u16 x, u16 y) { func_0014b208(D_00349270, (u16)(x * 2), (u16)(y * 2)); }

// 0014a7b8: dk::Blur::setBlurRot
void func_0014a7b8(s32 n, f32 rot) asm("func_0014a7b8");
void func_0014a7b8(s32 n, f32 rot) {
    if (n == 0) D_00349394 = 1;
    else D_00349394 = n;
    D_00349390 = rot;
    D_00349398 = 0;
}

// 0014a7e8: dk::Blur::setBlurType
void func_0014a7e8(u8 t) asm("func_0014a7e8");
void func_0014a7e8(u8 t) { D_0034939d = t; }

// 0014a7f8: dk::Blur::setBlurFlag
void func_0014a7f8(u8 f) asm("_Z16u_tail4_0014a7f8jjjj");
void func_0014a7f8(u8 f) {
    D_0034939c = f;
    if (f == 0) func_0014a7b8(1, 0.0f);
}

// 0014a830: dk::Blur::blur_task
void func_0014a830(u8* p) {
    if (p[4] == 0) {
        dk__Blur__init();
        p[4] = 1;
    }
    dk__Blur__update();
}

void func_0013ee88(void*) asm("func_0013ee88");
extern u32 D_00349270_w asm("D_00349270");
extern u8 D_00348698[] asm("D_00348698");

// 0014a868: static init/destroy of the blur sprite (built by the sprite C1 0x13ee88, destroyed by the
// inline base dtor that only sets vptr 0x348698).
void func_0014a868(int a, int b) asm("_Z13func_0014a868ii");
void func_0014a868(int a, int b) {
    if (b == 0xffff && a == 1) func_0013ee88(D_00349270);
    if (b == 0xffff && a == 0) D_00349270_w = (u32)D_00348698;
}

// 0014a8d8: _GLOBAL__I_ stub; 0014a8f8: _GLOBAL__D_ stub (never written before)
void func_0014a8d8(void) asm("func_0014a8d8");
void func_0014a8d8(void) { func_0014a868(1, 0xffff); }
void func_0014a8f8(void) asm("func_0014a8f8");
void func_0014a8f8(void) { func_0014a868(0, 0xffff); }
