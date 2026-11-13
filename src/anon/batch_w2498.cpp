// func_0022c1f8: init three sub-objects from a2 and lay them out (x/y from a2+0x18 helpers).
#include "../common/types.h"
struct Sub {
    u8 pad0[0x18];
    u8 obj[0x16c];
    s32 state; /* 0x184 */
    s32 pad188;
    s32 f18c;
    s32 f190;
    u8 pad194[4];
};
struct Obj {
    u8 pad0[0x18];
    s32 f18;
    Sub sub[3];
};
struct Inp { u8 pad[0x18]; u8 cur[0x1a8]; u8 tail[1]; };
struct Th { u8 pad[4]; s32 f4; };
extern char D_0035e2f0[];
extern "C" {
Th* func_00197df8();
void func_00150260(void*, void*, s32, s32*);
void func_0023a9c0(void*, s32*, s32*);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
void func_001386e0(Sub*, s32, s32, void*, s32, s32);
void func_001396b0(Sub*);
void func_0031a260(Sub*, s32);
void func_00139660(Sub*);
void func_00139688(Sub*);
void func_00138c10(Sub*, s32);
void func_00139598(Sub*);
s32 func_0023aa98(void*);
void func_00138c68(Sub*, s32, s32);

void func_0022c1f8(Obj* self, void* a1, u8* a2);  // 0022c1f8: moved to src/sasa/event_countdown.cpp (linked unit)

}
