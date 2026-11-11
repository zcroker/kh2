#include "./types.h"

// Gumi menu mode (0x104318-0x1048f0): loads the ovl_gumimenu.x overlay, gives it three work
// buffers, and holds the mode object that the task manager runs. The overlay's own code
// (gm::GUMI_MENU, gumimenu.hpp) is not part of this file.

struct TASK;

// The gumi menu mode object (0x32ba90). Its vtable is TASK's (0x32b930).
extern u32 D_0032b930;
struct GumiMenuMode {
    u32 vt;          // 0
    u32 manager;     // 4 (TASK_MANAGER*)
    u8 f8;           // 8
    u8 pad9[11];
    u32 f14, f18, f1c;
    void* setup;     // 32
    void* ensure;    // 36
    u32 f28;         // 40
    GumiMenuMode() {
        manager = 0;
        f1c = 0;
        setup = 0;
        ensure = 0;
        f28 = 0x3000;
        f8 = 71;
        f18 = 160000;
        f14 = 1;
        vt = (u32)&D_0032b930;
    }
};

// Axis vectors and +-pi/2, from a shared header.
struct Vec4f {
    f32 x, y, z, w;
    Vec4f(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
};

static inline f32 half_pi() { return 1.5707963f; }

static Vec4f s_up(0.0f, 1.0f, 0.0f, 0.0f);
static Vec4f s_down(0.0f, -1.0f, 0.0f, 0.0f);
static Vec4f s_left(-1.0f, 0.0f, 0.0f, 0.0f);
static Vec4f s_right(1.0f, 0.0f, 0.0f, 0.0f);
static Vec4f s_front(0.0f, 0.0f, 1.0f, 0.0f);
static Vec4f s_back(0.0f, 0.0f, -1.0f, 0.0f);
static f32 s_rotUp __attribute__((aligned(4))) = half_pi();
static f32 s_rotDown __attribute__((aligned(4))) = -half_pi();
static f32 s_rotLeft __attribute__((aligned(4))) = -half_pi();
static f32 s_rotRight __attribute__((aligned(4))) = half_pi();

static u8 s_buf0[0x800] __attribute__((aligned(64)));
static u8 s_buf[2][0x400] __attribute__((aligned(64)));

GumiMenuMode D_0032ba90;
void* D_0032babc = 0;
void* D_0032bac0 = 0;
void* D_0032bac4 = 0;
void* D_0032bac8 = 0;
u8 D_0032bad0[3] = {0, 0, 0};

extern "C" {
void func_00167f38(s32);
void func_00168548(const char*, s32, s32);
void func_00170888(TASK*);
void func_003058a0(s32);  // FlushCache
void func_001688a0(void);
u8* func_00170b30(u32);   // alloc_align128
void* func_00106178(void*, u32);
void func_01f18014(s32, void*);
void func_00170dd0(void);
void func_00170c00(void*);
void func_00170320(s32);
u32 func_00102788(u32, u32, u32, u32);
void func_00102818(u32, u32, u32, u32, u32);

// Work buffer i (0: 2 KB, 1-2: 1 KB).
u8* func_00104318(s32 i) {
    if (i == 0) return s_buf0;
    return s_buf[i - 1];
}

u8 func_00104340(s32 i) {
    return D_0032bad0[i];
}

void func_00104358(s32 i, u8 v) {
    D_0032bad0[i] = v;
}

u8* func_00104370(void) {
    u8 ok = func_00104340(0);
    u8* r = 0;
    if (ok) r = s_buf0;
    return r;
}

u8* func_001043a0(s32 i) {
    if (!func_00104340(i + 1)) return 0;
    return s_buf[i];
}

void D_001043e8(TASK* task) {
    func_00167f38(4);
    func_00168548("ovl_gumimenu.x", 0, 0);
    func_00170888(task);
    func_003058a0(2);
    func_001688a0();
    func_00170888(task);
    D_0032babc = func_00106178(func_00170b30(0xb00000), 0xb00000);
    u8* p = func_00170b30(0x1e0000);
    D_0032bac0 = func_00106178(p, 0x40000);
    p += 0x40000;
    D_0032bac4 = func_00106178(p, 0x180000);
    p += 0x180000;
    D_0032bac8 = func_00106178(p, 0x20000);
    for (s32 i = 0; i < 3; i++) D_0032bad0[i] = 0;
    func_01f18014(0, &D_0032ba90);
}

void D_001044f0(void) {
    func_00170dd0();
    func_003058a0(2);
    func_01f18014(1, &D_0032ba90);
    func_00170c00(D_0032bac0);
    func_00170c00(D_0032babc);
    func_00170320(0);
    D_0032bac4 = 0;
    D_0032bac0 = 0;
    D_0032babc = 0;
}

void func_00104560(void) {
    D_0032ba90.setup = (void*)D_001043e8;
    D_0032ba90.ensure = (void*)D_001044f0;
}

u32 func_00104588(u32 a0, u32 a1, u32 a2) {
    return func_00102788(D_0032ba90.manager, a0, a1, a2);
}

void func_001045b8(u32 a, u32 b, u32 c, u32 d) {
    func_00102818(D_0032ba90.manager, a, b, c, d);
}
}

GumiMenuMode* getGumiMenuMode(void) {
    return &D_0032ba90;
}

extern "C" {
void* func_00104600(void) { return D_0032babc; }
void* func_00104610(void) { return D_0032bac0; }
void* func_00104620(void) { return D_0032bac4; }
void* func_00104630(void) { return D_0032bac8; }
}
