// Linked unit 0x0020e490-0x0020e590: texture/CLUT upload wrappers (the GS clear 0x20e590 after it is not written yet).
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
typedef unsigned int w3728_u128 __attribute__((mode(TI)));
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"

// 0020e490 (was src/anon/batch_w1791.cpp)
namespace n0020e490 {
// 0x001d22e0: definition moved into src/anon/unit_001d14e0.cpp

void puts(const char*) asm("puts");
void func_002fd348(s32)  asm("func_002fd348")__attribute__((noreturn));
extern char D_00370720[] asm("D_00370720");
void sceGsSetDefLoadImage(void*, s32, s32, s32, s32, s32, s32, s32) asm("sceGsSetDefLoadImage");
void sceGsSyncPath(s32, s32) asm("sceGsSyncPath");
void func_003058a0(s32) asm("func_003058a0");
void sceGsExecLoadImage(void*, u32) asm("sceGsExecLoadImage");
struct Tex {
    u16 w : 14;
    u16 pad0 : 2;
    u8 pad2[6];
    u8 b8;
    u8 b9;
    u8 b10;
    u8 pad11;
    s16 h12;
    s16 h14;
    u8 pad16[4];
    u32 data;
    u8 b24;
};
/*TARGET 0020e490*/
void func_0020e490(Tex* t, u32 flag) asm("func_0020e490");
void func_0020e490(Tex* t, u32 flag) {
    u8 buf[96];
    if (!t->data) {
        puts(D_00370720);
        func_002fd348(1);
    }
    sceGsSetDefLoadImage(buf, (s16)t->w, t->b10 >> 2, t->b24, t->b8 << 4, t->b9 << 4, t->h12, t->h14);
    sceGsSyncPath(0, 0);
    func_003058a0(0);
    sceGsExecLoadImage(buf, t->data);
    if (flag) sceGsSyncPath(0, 0);
}
}  // namespace n0020e490

// 0020e548 (was src/anon/batch_w52.cpp)
namespace n0020e548 {
// 0x001dc558: definition moved into src/anon/unit_001dbfd8.cpp

void puts(const char*) asm("puts");
void func_002fd348(s32)  asm("func_002fd348")__attribute__((noreturn));
extern char D_00370748[] asm("D_00370748");
void func_0020e2e8(u32, u8, u16, u32) asm("func_0020e2e8");
/*TARGET 0020e548*/
void func_0020e548(u8* p, u32 b) asm("func_0020e548");
void func_0020e548(u8* p, u32 b) {
    if (!*(u32*)(p + 4)) {
        puts(D_00370748);
        func_002fd348(1);
    }
    func_0020e2e8(*(u32*)(p + 4), p[9], *(u16*)p, b);
}
}  // namespace n0020e548

