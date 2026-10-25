#include "../common/types.h"

// 0x2e7658-0x2e7ae0: a work area with two parts (a flag and a state block), plus the axis
// vectors and +-pi/2 constants that this file's static initialiser (0x2e7870) sets.

extern "C" void func_002fde18(void*, s32, u32);  // memset
extern "C" u8* func_001058e8(void);

struct Flag2e7688 {
    s8 active;
    u8 pad[3];
    Flag2e7688();
    void init();
};

Flag2e7688::Flag2e7688() {
    init();
}

void Flag2e7688::init() {
    active = 1;
}

struct State2e76c8 {
    u8 f0, f1, f2;
    u8 pad3[135];
    u8 f138, f139, f140;
    u8 pad141[13];
    u8 a154[16];
    u8 a170[16];
    u8 a186[128];
    u8 pad314[34];
    State2e76c8();
    void init();
};

State2e76c8::State2e76c8() {
    init();
}

void State2e76c8::init() {
    u8* p = (u8*)this;
    p[0] = 1;
    p[1] = 0;
    p[2] = 0;
    p[138] = 0;
    p[139] = 1;
    p[140] = 1;
    u8* q = p;
    s32 i = 15;
    do {
        q[154] = 0;
        i--;
        q[170] = 0;
        q++;
    } while (i >= 0);
    p += 186;
    s32 j = 127;
    do {
        *p = 0;
        j--;
        p++;
    } while (j >= 0);
}

struct Work2e7738 {
    Flag2e7688 flag;     // 0
    State2e76c8 state;   // 4
    u8 x[18][1808];      // 352
    u8 y[18][608];       // 0x8080
    Work2e7738();
    ~Work2e7738();
    void init();
    u8* getX(s32 i);
    u8* getY(s32 i);
};

Work2e7738::Work2e7738() {
    init();
}

Work2e7738::~Work2e7738() {
}

void Work2e7738::init() {
    flag.init();
    state.init();
    func_002fde18(x, 0, sizeof(x));
    func_002fde18(y, 0, sizeof(y));
}

u8* Work2e7738::getX(s32 i) {
    u8* r = 0;
    u8* base = x[0];
    if (flag.active == 1) r = base + i * 1808;
    return r;
}

u8* Work2e7738::getY(s32 i) {
    u8* r = 0;
    if (flag.active == 1) {
        u8* base = y[0];
        r = base + i * 608;
    }
    return r;
}

extern "C" Work2e7738* func_002e7850(void) {
    return (Work2e7738*)(func_001058e8() + 21920);
}

struct Vec4f {
    f32 x, y, z, w;
    Vec4f(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    ~Vec4f() {}
};

static inline f32 half_pi() { return 1.5707963f; }

// Axis vectors (0x1e2bf10-0x1e2bf6f) and +-pi/2 (0x1e2bf70-0x1e2bf7f). gcc gives a dynamically
// initialised float 8-byte alignment; aligned(4) keeps the original 4-byte spacing.
Vec4f D_01e2bf10(0.0f, 1.0f, 0.0f, 0.0f);
Vec4f D_01e2bf20(0.0f, -1.0f, 0.0f, 0.0f);
Vec4f D_01e2bf30(-1.0f, 0.0f, 0.0f, 0.0f);
Vec4f D_01e2bf40(1.0f, 0.0f, 0.0f, 0.0f);
Vec4f D_01e2bf50(0.0f, 0.0f, 1.0f, 0.0f);
Vec4f D_01e2bf60(0.0f, 0.0f, -1.0f, 0.0f);
f32 D_01e2bf70 __attribute__((aligned(4))) = half_pi();
f32 D_01e2bf74 __attribute__((aligned(4))) = -half_pi();
f32 D_01e2bf78 __attribute__((aligned(4))) = -half_pi();
f32 D_01e2bf7c __attribute__((aligned(4))) = half_pi();
