#include "../common/types.h"
extern "C" {
void func_00185ed8(u8* p, u32 a1, u32 a2, u32 a3);
s32 func_001d7ec8(u32);
void* func_0016a070(u8*);
s32 func_001afe30(void*);
extern u8 D_0034e8b8;
extern u8 D_00350e60;

struct TP14d358 { s32 status; void (*func)(void*); void* stack; s32 size; void* gp; s32 prio; u32 cur, attr, option; };
struct SP14d358 { s32 count, max, init, wait; u32 attr, option; };
struct E14d358 {
    s32 tid;
    TP14d358 tp;
    u8 pad[52 - 40];
    SP14d358 sp;
    s32 sema;
    void (*func)(void*);
    void* arg;
};
extern E14d358 D_00349e48[2];
void func_0014d298(void*);
s32 func_00305620(SP14d358*) asm("CreateSema");
s32 func_00305420(TP14d358*) asm("CreateThread");
void func_00306760(s32, s32);

// 0014d358: moved to src/anon/unit_0014d298.cpp

// 00175670: moved to src/yasui/libys/party.cpp


// 00175790: moved to src/yasui/libys/party.cpp

}
