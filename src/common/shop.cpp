#include "./types.h"

// SHOP (0x105c68-0x105ee8): the shop mode. Loads ovl_shop.x and runs it as a task mode.

struct TASK;

// The shop mode object (0x33cb80). Its vtable is TASK's (0x32b930).
extern u32 D_0032b930;
struct ShopMode {
    u32 vt;          // 0
    u32 manager;     // 4 (TASK_MANAGER*)
    u8 f8;           // 8
    u8 pad9[11];
    u32 f14, f18, f1c;
    void* setup;     // 32
    void* ensure;    // 36
    u32 f28;         // 40
    ShopMode() {
        f1c = 0;
        setup = 0;
        ensure = 0;
        f28 = 0x1000;
        f8 = 84;
        f14 = 2;
        f18 = 0x222e0;
        manager = 0;
        vt = (u32)&D_0032b930;
    }
};

struct S32b968 { u8 pad[28]; s32 f28; };

ShopMode D_0033cb80;
s32 D_0033cbac = -1;   // signal
u8 D_0033cbb0 = 0;

extern "C" {
extern S32b968 D_0032b968;
extern u32 D_0032b984;
void func_00167ea8(TASK*);
void func_0014c9d8(s32);
void func_0014df88(void);
void func_0014e0d8(void);
void func_00168548(const char*, s32, s32);
s32 func_001688b8(void);
void func_00102448(TASK*, s32);  // Tz::TaskYield
void func_003058a0(s32, s32);    // FlushCache
void func_01f18014(s32, void*);
void func_0014df98(void);
void func_0014c9f0(s32);
void func_00167ee0(void);
s32 func_00103b38(s32);
void func_00102080(void*);
u32 func_00102788(u32, u32, u32, u32);
void func_00102818(u32, u32, u32, u32, u32);
}

namespace SHOP {

void Start(TASK* task) {
    func_00167ea8(task);
    func_0014c9d8(1);
    func_0014df88();
    func_0014e0d8();
    if (D_0032b968.f28) D_0032b968.f28 = 2;
    func_00168548("ovl_shop.x", 0, 0);
    while (func_001688b8()) func_00102448(task, 0);
    func_003058a0(2, 0);
    func_01f18014(0, &D_0033cb80);
}

void Ensure(TASK* task) {
    D_0033cbac = -1;
    func_0014df98();
    func_0014c9f0(1);
    func_00167ee0();
    D_0032b984 = 1;
    D_0033cbb0 = 0;
}

void Init(void) {
    D_0033cb80.setup = (void*)Start;
    D_0033cb80.ensure = (void*)Ensure;
}

u32 CreateTask(u32 a0, u32 a1, u32 a2) {
    return func_00102788(D_0033cb80.manager, a0, a1, a2);
}

void CreateTaskThread(u32 a0, u32 a1, u32 a2, u32 a3) {
    func_00102818(D_0033cb80.manager, a0, a1, a2, a3);
}

void StartMenu(s32 a) {
    if (func_00103b38(a) == 0 && (D_0032b984 ^ 2) != 0) {
        D_0033cbb0 = 1;
        D_0033cbac = a;
        func_00102080(&D_0033cb80);
    }
}

s32 GetSignal(void) {
    return D_0033cbac;
}

ShopMode* GetMode(void) {
    return &D_0033cb80;
}

}  // namespace SHOP
