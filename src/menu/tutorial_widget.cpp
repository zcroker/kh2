#include "../common/types.h"

// menu::TutorialWidget and menu::Mode (0x2ee588-0x2ee8a8). The vtables are at 0x363820
// (TutorialWidget) and 0x363840 (Mode); the constructors store vtable + 8.
extern u8 D_00363828[];
extern u8 D_00363848[];

extern "C" {
void func_002edf28(void*);  // obj_ctor_3637e0 (base class constructor)
void func_001ad330(void*, s32);
void func_001acbc0(void*);
void func_001acda8(void*);
void func_001ad3e0(void*);
u32 func_00102210(void*);
void func_00102080(void*);
u32 func_001031b0(void);
void func_0014c9d8(s32, void*);
void func_0014df88(void);
void func_0014e0d8(void);
void func_0014df98(void);
}

struct TutorialPos { s32 x, y; };
struct TutorialArg { s16 a, b; };
struct TASK;

namespace menu {

struct TutorialWidget {
    u8 base[36];
    s32 state;  // 36
    s32 id;     // 40
    u8 widget[0x80];  // 44
    TutorialWidget(s32 a);
    s32 update();
    void draw(TutorialPos, TutorialArg);
};

TutorialWidget::TutorialWidget(s32 a) {
    func_002edf28(this);
    id = a;
    state = 0;
    *(u32*)this = (u32)D_00363828;
    func_001ad330(widget, a);
}

static inline bool is_phase(u8* w, s32 p) { return *(s32*)(w + 112) == p; }

s32 TutorialWidget::update() {
    u8* w = widget;
    func_001acbc0(w);
    switch (state) {
    case 0:
        if (is_phase(w, 3)) {
            func_001acda8(w);
            state = 1;
        }
        break;
    case 1:
        if (is_phase(w, 7)) state = 2;
        break;
    }
    return 1;
}

void TutorialWidget::draw(TutorialPos, TutorialArg) {
    func_001ad3e0(widget);
}

}  // namespace menu

extern "C" u32 func_002ee6d8(menu::TutorialWidget* w) {  // obj_state_is_2
    return w->state == 2;
}

namespace menu {

struct Mode {
    u32 vptr;  // 0
    u32 f4;
    u8 f8;
    u8 pad9[11];
    u32 f14, f18, f1c, f20, f24, f28;
    u32 task;  // 44
    Mode();
    void start();
    void initialize(TASK*);
    void finalize();
};

Mode::Mode() {
    f4 = 0;
    f8 = 77;
    f14 = 2;
    f1c = 0;
    f18 = 0x222e0;
    f20 = 0;
    f24 = 0;
    f28 = 4096;
    vptr = (u32)D_00363848;
}

}  // namespace menu

extern "C" menu::Mode* func_002ee840(void);

namespace menu {

void Mode::start() {
    task = func_00102210(this);
    func_00102080(this);
    func_002ee840()->f4 = func_001031b0();
}

void Mode::initialize(TASK* t) {
    func_0014c9d8(1, t);
    func_0014df88();
    func_0014e0d8();
    if (task) *(s32*)(task + 28) = 2;
}

void Mode::finalize() {
    func_0014df98();
    if (task) *(s32*)(task + 28) = 1;
}

}  // namespace menu

// The menu mode object (0x1e2c088). This file's static initialiser (0x2ee850) constructs it;
// _GLOBAL__I_D_01e2c088 (0x2ee888) is its .ctors entry.
menu::Mode D_01e2c088;

extern "C" menu::Mode* func_002ee840(void) {  // get_data_1e2c088
    return &D_01e2c088;
}
