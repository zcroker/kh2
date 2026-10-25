#include "../common/types.h"

// Pad vibration wave (0x1e0398-0x1e0808): two phases that drive the motors, and the task that
// runs it while the field or gumi battle mode is active.

struct PadWave {
    f32 t;      // 0x00 time left
    f32 per1;   // 0x04
    f32 ph1;    // 0x08
    f32 per2;   // 0x0c
    f32 ph2;    // 0x10
    f32 a1;     // 0x14
    f32 a2;     // 0x18
    f32 v1;     // 0x1c
    f32 v2;     // 0x20
    PadWave();
    ~PadWave();
    void clear();
    void set(f32 t, f32 per1, f32 per2, f32 a1, f32 a2, f32 v1, f32 v2);
    void update();
};

static inline f32 clampf(f32 x, f32 lo, f32 hi) {
    if (x < lo) return lo;
    if (x > hi) return hi;
    return x;
}
static inline f32 maxf(f32 x, f32 lo) { return x > lo ? x : lo; }

extern "C" {
void func_00166c80(s16, s16);
void func_002f8870(f32);
f32 func_002f8960(f32);
extern f32 D_00349e10;  // frame time
}

PadWave::PadWave() {
    clear();
}

PadWave::~PadWave() {
}

void PadWave::clear() {
    t = 0;
    ph1 = 0;
    per1 = 0;
    ph2 = 0;
    per2 = 0;
    a1 = 0;
    a2 = 0;
    v1 = 0;
    v2 = 0;
}

void PadWave::set(f32 at, f32 aper1, f32 aper2, f32 aa1, f32 aa2, f32 av1, f32 av2) {
    ph1 = 0;
    ph2 = 0;
    t = at;
    per1 = aper1;
    per2 = aper2;
    a1 = aa1;
    a2 = aa2;
    v1 = av1;
    v2 = av2;
}

PadWave D_00352b60;

extern "C" void func_001e0428(f32 t, f32 per1, f32 per2, f32 a1, f32 a2, f32 v1, f32 v2) {
    D_00352b60.set(t, per1, per2, a1, a2, v1, v2);
}

void PadWave::update() {
    f32 p1, p2, a, b;
    if (t <= 0.0f) {
        func_00166c80(0, 0);
        return;
    }
    p1 = per1;
    if (p1 > 0.0f) {
        ph1 += D_00349e10;
        while (ph1 >= p1) ph1 -= p1;
    }
    p2 = per2;
    if (p2 > 0.0f) {
        f32 d = D_00349e10;
        f32 ph = ph2 + d;
        ph2 = ph;
        if (ph >= p2) {
            do ph -= p2; while (ph >= p2);
            ph2 = ph;
        }
    }
    a1 += v1 * D_00349e10;
    a1 = clampf(a1, 0.0f, 16.0f);
    a2 += v2 * D_00349e10;
    a2 = clampf(a2, 0.0f, 16.0f);
    a = func_002f8960(ph1 / p1 * 3.1415927f * 2.0f - 3.1415927f) * a1;
    b = func_002f8960(ph2 / per2 * 3.1415927f * 2.0f - 3.1415927f) * a2;
    func_002f8870(a);
    func_002f8870(b);
    func_00166c80((s16)(s32)a, (s16)(s32)b);
    t -= D_00349e10;
    t = maxf(t, 0.0f);
}

extern "C" {

struct T6b8 { u32 x0; s32 x4; };
struct O6b8 { u8 pad[0x30]; void* x30; };
T6b8* func_00102c80(void);  // getFieldMode
T6b8* getGumiBattleMode_6b8(void) asm("_Z17getGumiBattleModev");
s32 func_00102180(T6b8**);
O6b8* func_00102788(s32, s32, s32, void*);  // TASK_MANAGER::create_task

void func_001e0670(void) {
    D_00352b60.update();
}

void func_001e0690(void) {
    func_00166c80(0, 0);
    D_00352b60.clear();
}

void func_001e06b8(void) {
    T6b8* m0 = func_00102c80();
    T6b8* m1 = getGumiBattleMode_6b8();
    T6b8* list[4];
    func_00102180(list);
    if (list[0] == m0) {
        func_00102788(list[0]->x4, 1, 0x1fbd0, (void*)func_001e0670)->x30 = (void*)func_001e0690;
    } else if (list[0] == m1) {
        func_00102788(m1->x4, 0, 0x222e0, (void*)func_001e0670)->x30 = (void*)func_001e0690;
    }
}

}
