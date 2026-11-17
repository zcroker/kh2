#include "../common/types.h"

extern "C" {

// ---- 002bb468
struct CT {
    u8 _00[0x10];
    u32 _10;
    u32 _14;
    u32 _18;
    CT* next;     // 1c
    u8 _20[0x11];
    u8 kind;      // 31
};
extern CT* D_01e2aa80;
u8 f73_u8(u32, u32, u32, s32, u32) asm("func_002b73ac");
s32 f7d_s(u32, u32, s32, u32) asm("func_002b7d5c");
s32 f97_s(u32, u32, s32, u32) asm("func_002b97d8");

static inline CT* ct_next(CT* p) { return p ? p->next : D_01e2aa80; }

s32 ctarget_002bb468(CT* self, u32 a1, u32 a2, u32 a3) asm("_Z16ctarget_002bb468jjjj");
s32 ctarget_002bb468(CT* self, u32 a1, u32 a2, u32 a3);  // 0x002bb468: definition moved into src/anon/unit_002bb070.cpp

// ---- 002dd3a0
struct S24c { u32 a, b, c, d, e, f; };
struct SubE { S24c v; const S24c& ref() const { return v; } };
struct DE { u8 _0[0x740]; SubE m740; u8 _758[0xaf0 - 0x758]; u8 maf0[4]; };
bool fpv(u32, S24c) asm("func_00144d10");
s32 func_002cf270(u32, s32);
void func_002cf280(u32, s32, s32);

bool func_002dd3a0(u32 a0, DE* a1);  // 0x002dd3a0: definition moved into src/anon/unit_002da040.cpp

// ---- 00102080
struct PN {
    u8 _0[0xc];
    PN* next;   // 0c
    u8 _10[4];
    u32 mask;   // 14
    u32 _18;
    u32 state;  // 1c
    u8 _20[8];
    u32 _28;
};
struct PR { u8 _0[4]; PN* owner; };
extern PN* D_0038aa40;
extern u32 D_0032b91c;
void func_00101ea8(void);
PR* func_00102818(u32, u32, u32, void (*)(void), u32);
void func_001021d0(void);

static inline PN* pnB(PN* p) { if (!p) return D_0038aa40; return p->next; }

void func_00102080(PN* self);  // 0x00102080: definition moved into src/global/unit_00101d50.cpp

}
