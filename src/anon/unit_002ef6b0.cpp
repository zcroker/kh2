#include "../common/types.h"

// 0x2ef6b0-0x2ef8d0: movie playback (the movie overlay "ovl_movie.x", its heap, the pause flag and
// the sound pause count). Linked unit; the globals are .data at 0x3638c0.

void MENU_SetGameMode(s32) asm("_ZN4MENU11SetGameModeEi");
void MENU_DestoryAllocator(void) asm("_ZN4MENU16DestoryAllocatorEv");
void* createMemoryAllocator(void*, u32) asm("_ZN2kn15MemoryAllocator21createMemoryAllocatorEPvj");
void CACHE_BUFF_FixFree(void*) asm("_ZN2YS10CACHE_BUFF7FixFreeEPv");
void ovl_functionCall(s32, void*) asm("_Z16wtarget_01f18014jjjj");
extern "C" {
void* func_00170b30(u32);
void func_00103590(s32, void*);
void func_00168548(const char*, void (*)(void), s32);
s32 FlushCache(s32);
void func_001b8228(void);
void func_001b8258(void);
}

struct Movie3638d0 {
    s32 v;
    Movie3638d0() { v = 1; }
};

extern "C" {
u8 D_003638c0;
void* D_003638c4;
s8 D_003638c8;
Movie3638d0 D_003638d0;
}

extern "C" void func_002ef6b0(void) {
    MENU_SetGameMode(5);
    void* h = createMemoryAllocator(func_00170b30(0xa0000), 0xa0000);
    D_003638c4 = h;
    func_00103590(1, h);
    D_003638c0 = 0;
    D_003638c8 = 0;
}

extern "C" void func_002ef708(void) {
    MENU_DestoryAllocator();
    CACHE_BUFF_FixFree(D_003638c4);
    D_003638c4 = 0;
    MENU_SetGameMode(-1);
    D_003638c0 = 0;
    D_003638c8 = 0;
}

extern "C" void func_002ef778(void);

extern "C" void func_002ef750(void) {
    func_00168548("ovl_movie.x", func_002ef778, 0);
}

extern "C" void func_002ef778(void) {
    FlushCache(2);
    D_003638c0 = 1;
}

namespace MOVIE {
void functionCall(s32 id, void* arg) {
    ovl_functionCall(id, arg);
}
}

namespace Tz {
struct MenuSound {
    static u8 isPauseActive();
};
u8 MenuSound::isPauseActive() {
    return D_003638c0;
}
}

extern "C" void func_002ef7c8(void) {
    if (Tz::MenuSound::isPauseActive())
        func_001b8228();
    else
        func_001b8258();
}

extern "C" void func_002ef7f0(s32 on) {
    if (!Tz::MenuSound::isPauseActive()) return;
    if (on) {
        if (D_003638c8 == 0) MOVIE::functionCall(3, 0);
        D_003638c8++;
    } else if (D_003638c8 != 0) {
        if (--D_003638c8 == 0) MOVIE::functionCall(4, 0);
    }
}
