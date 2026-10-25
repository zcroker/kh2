#include "./types.h"

// Gumi battle mode (0x103f68-0x104318): loads the ovl_gumibattle.x overlay and keeps its
// pause parameters and state flags.

struct TASK;

// The gumi battle mode object (0x32ba48). Its vtable is TASK's (0x32b930).
extern u32 D_0032b930;
struct GumiBattleMode {
    u32 vt;          // 0
    u32 f4;          // 4
    u8 f8;           // 8
    u8 pad9[11];
    u32 f14, f18, f1c;
    void* setup;     // 32
    void* ensure;    // 36
    u32 f28;         // 40
    GumiBattleMode() {
        f4 = 0; f1c = 0; setup = 0; ensure = 0;
        f28 = 0x4000; f8 = 71; f18 = 0x29810; f14 = 1;
        vt = (u32)&D_0032b930;
    }
};

struct PauseParam {
    s8 a, b, c, d;
    u32 e;
};

GumiBattleMode D_0032ba48;
u32 D_0032ba74 = 0;           // overlay memory allocator
PauseParam* D_0032ba78 = 0;   // pause parameters
u32 D_0032ba7c = 0;
u32 D_0032ba80 = 1;
s32 D_0032ba84 = 1;
u8 D_0032ba88 = 0;

extern "C" {
void func_00167f38(s32);
void func_00168548(const char*, s32, s32);
void func_00170888(TASK*);
void func_003058a0(u32);  // FlushCache
void func_001688a0(void);
u32 func_00170b30(u32);
u32 func_00106178(u32, u32);
PauseParam* func_001063c0(u32, u32);
void func_00106420(void*);
void func_00170c00(u32);
void func_00170320(u32);
void func_01f18014(u32, void*);
void func_00105fc8(void);
u32 func_0014aba8(void);
void func_0014aa58(u32, s32, s32);
}

struct VObj { void** vt; };
typedef void (*VFn)(void*);
extern "C" VObj* func_001045f0(void);

namespace GUMIBATTLE {

void Setup(TASK* t) {
    func_00167f38(2);
    func_00168548("ovl_gumibattle.x", 0, 0);
    func_00170888(t);
    func_003058a0(2);
    func_001688a0();
    func_00170888(t);
    D_0032ba74 = func_00106178(func_00170b30(0xce0000), 0xce0000);
    PauseParam* p = func_001063c0(8, D_0032ba74);
    p->a = 0;
    p->d = -1;
    p->b = 0;
    p->c = 0;
    p->e = 0;
    D_0032ba78 = p;
    func_01f18014(0, &D_0032ba48);
}

void Ensure(TASK*) {
    func_003058a0(2);
    func_01f18014(1, &D_0032ba48);
    func_00106420(D_0032ba78);
    u32 v = D_0032ba74;
    D_0032ba78 = 0;
    func_00170c00(v);
    func_00170320(0);
    D_0032ba74 = 0;
}

}  // namespace GUMIBATTLE

extern "C" {

void func_00104080(void) {
    D_0032ba48.setup = (void*)GUMIBATTLE::Setup;
    D_0032ba48.ensure = (void*)GUMIBATTLE::Ensure;
}

void func_001040a8(s8 a, s8 b, s8 c, u32 e) {
    D_0032ba78->a = a;
    D_0032ba78->b = b;
    D_0032ba78->c = c;
    D_0032ba78->d = -1;
    D_0032ba78->e = e;
}

}

namespace GUMIBATTLE {

PauseParam* GetPauseParam() {
    return D_0032ba78;
}

}  // namespace GUMIBATTLE

extern "C" {

// Dispatch on the pause state (2: virtual call on an object, 3: helper), then notify.
void func_00104108(void) {
    switch (GUMIBATTLE::GetPauseParam()->d) {
    case 0:
    case 1:
        return;
    case 2: {
        VObj* o = func_001045f0();
        ((VFn)o->vt[0])(o);
        break;
    }
    case 3:
        func_00105fc8();
        break;
    default:
        return;
    }
    func_0014aa58(func_0014aba8(), 15, 0);
}

}

GumiBattleMode* getGumiBattleMode() {
    return &D_0032ba48;
}

extern "C" {

u32 func_001041a0(void) { return D_0032ba7c; }
u32 func_001041b0(void) { return D_0032ba80; }

// One-shot latch: returns the flag, setting it to 1 the first time.
s32 func_001041c0(void) {
    s32 v = D_0032ba84;
    if (v == 0) {
        D_0032ba84 = 1;
        v = 1;
    }
    return v;
}

u8 func_001041e0(void) { return D_0032ba88; }
void func_001041f0(u32 a) { D_0032ba7c = a; }
void func_00104200(u32 a) { D_0032ba80 = a; }

void func_00104210(s32 a) {
    s32 v = a;
    if (v <= 0) v = 1;
    D_0032ba84 = v;
    switch (v) {
    case 1: func_00104200(1); break;
    case 2: func_00104200(2); break;
    case 3: func_00104200(3); break;
    }
}

void func_00104278(u8 a) { D_0032ba88 = a; }
u32 func_00104288(void) { return D_0032ba74; }

}
