#include "types.h"

// Field mode (0x102a70-0x102d10): set-up and clean-up of the field (the hooks of the field mode
// object at 0x32b968, which TASK_MANAGER builds tasks for), its task helpers and its static
// initialiser. The object (0x32b968), the "keep" word (0x32b994) and the field flag (0x32b998) are
// reached as data; the static initialiser fills the object with plain stores.

struct TASK;

extern "C" {
void func_00167f38(s32);
void* func_00102508_r(void*, u32) asm("_ZN12TASK_MANAGER6CreateEPvj");
extern u8 D_0038aa50[];
struct FieldMode { u32 vt; void* manager; u8 pad8[24]; void* setup; void* ensure; u32 f28; };
extern FieldMode D_0032b968_m asm("D_0032b968");
void func_001050b8(void);
void func_00102b68_v(void) asm("func_00102b68");
void func_0014a188(void);
void func_00107a90(void);
extern u8 D_0032b998_b asm("D_0032b998");
void func_00170a50(void);
void func_00168fa8(void);
extern u32 D_0032b994_w asm("D_0032b994");
void func_00104da0(u32);
void func_00104de0(u8, u8, u8);
extern u8 D_0032bb30[];
extern s8 D_0032bb10;
void func_00226a70(void);
void func_0013ef70(void);
void func_0013f050(s32);

// 0x102a70 (not in the layout): field set-up.
void func_00102a70(TASK* t) {
    func_00167f38(1);
    D_0032b968_m.manager = func_00102508_r(D_0038aa50, 0x14000);
    func_001050b8();
    func_00102b68_v();
    func_0014a188();
    func_00107a90();
    if (D_0032b998_b) func_00170a50();
    func_00168fa8();
    if (D_0032b994_w) {
        func_00104da0(D_0032b994_w);
        D_0032b994_w = 0;
    } else {
        func_00104de0(D_0032bb30[12], D_0032bb30[13], D_0032bb30[14]);
    }
    func_00226a70();
    func_0013ef70();
    func_0013f050(1);
    D_0032bb10 = -1;
}

// 0x102b48 (not in the layout): clears the field flag.
void func_00102b48(void) {
    D_0032b998_b = 0;
}
}

extern u32 D_0032b998;
extern "C" {
void func_00102b58(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_0032b998 = (u8)v;
}
}

u32 func_00136968();
u32 func_002b9e80();
u32 func_00136ab8();
extern "C" u32 func_00102b68(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    u32 (*fp_call0_002b9e80)() = func_002b9e80;
    r2 = fp_call0_002b9e80();
    u32 (*fp_call0_00136968)() = func_00136968;
    r2 = fp_call0_00136968();
    return func_00136ab8();
}

extern "C" {
// 0x102b90 (not in the layout): field clean-up.
void func_001369b8(void);
void func_00136b00(void);
void func_00104e18(void);
void func_002b9e80_v(void) asm("func_002b9e80");
void func_00102448(TASK*, s32);  // Tz::TaskYield
void func_00102b90(TASK* t) {
    func_001369b8();
    func_00136b00();
    func_00104e18();
    func_002b9e80_v();
    func_00102448(t, 1);
}
}

// 0x102bd8: installs the field hooks.
extern "C" {
void func_00102b58_v(void) asm("func_00102b58");
void func_00102b90_v(void) asm("func_00102b90");
void func_00102a70_v(void) asm("func_00102a70");
}
struct W2039Hooks {
    u8 pad[0x20];
    void (*f20)(void);
    void (*f24)(void);
    inline void Set() { f20 = func_00102a70_v; f24 = func_00102b90_v; }
};
struct W2039Flag { s32 a; inline void Clear() { a = 0; } };

extern "C" {
extern W2039Hooks D_0032b968_h asm("D_0032b968");
extern W2039Flag D_0032b994_f asm("D_0032b994");

void func_00102bd8(void) {
    D_0032b968_h.Set();
    D_0032b994_f.Clear();
    func_00102b58_v();
}
}

// 0x102c18: FIELD::CreateTask(int, int, void (*)(TASK*)).
u32 func_00102788(u32, u32, u32, u32);
extern u8 D_00330000;
u32 func_00102c18(u32 a0, u32 a1, u32 a2, u32 a3) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
u32 func_00102c18(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00102788(((u32)(*(u32*)((u32)((u32)&D_00330000) - 18068u))), a0, a1, a2);
}

// 0x102c48: creates a coroutine task on the field's manager.
extern "C" {
void func_00102818(u32, u32, u32, u32, u32);
extern u32 D_0032b96c;
void func_00102c48(u32 a, u32 b, u32 c, u32 d) {
    func_00102818(D_0032b96c, a, b, c, d);
}
}

// 0x102c80: getFieldMode().
extern u32 D_0032b968;
u32 func_00102c80(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z12getFieldModev");
u32 func_00102c80(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)&D_0032b968;
}

// 0x102c90: the static initialiser (fills the field mode object).
struct S102c90 {
    void* vt;
    u32 f4;
    u8 f8;
    u8 pad9[11];
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f32;
    u32 f36;
    u32 f40;
};
extern S102c90 D_0032b968_s asm("D_0032b968");
extern u32 D_0032b930;
void wtarget_00102c90(u32 a, u32 b, u32, u32) asm("_Z16wtarget_00102c90jjjj");
void wtarget_00102c90(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_0032b968_s.vt = &D_0032b930;
        D_0032b968_s.f4 = 0;
        D_0032b968_s.f8 = 70;
        D_0032b968_s.f20 = a;
        D_0032b968_s.f24 = 0x1fbd0;
        D_0032b968_s.f28 = 0;
        D_0032b968_s.f32 = 0;
        D_0032b968_s.f36 = 0;
        D_0032b968_s.f40 = 14336;
    }
}

// 0x102cf0: its _GLOBAL__I_ stub.
u32 func_00102c90_u(u32, u32, u32, u32) asm("_Z16wtarget_00102c90jjjj");
extern "C" u32 func_00102cf0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00102c90_u(0x00000001u, 0x0000ffffu, a2, a3);
}
