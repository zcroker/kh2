// Linked unit 0x1aaa08-0x1aaea8 (YS file 0x1a8618-0x1abad8, part).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../tozawa/menu_sound.hpp"

#ifndef QCOPY
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#endif

// 001aaa08 (from src/anon/batch_w1963.cpp)
namespace n001aaa08 {
struct W1963Res { u32 f0; u32 f4; u32 data; };
struct W1963Ent { u8 pad[0x13]; u8 b13; u8 pad2[8]; u32 d1c; };
extern W1963Ent D_01c6cc60[6] asm("D_01c6cc60");
extern u32 D_01c6cec0 asm("D_01c6cec0");
extern u32 D_01c6cec4 asm("D_01c6cec4");
extern s32 D_00350a30 asm("D_00350a30");
extern char* D_00350a28 asm("D_00350a28");
extern s32 D_0033caf4 asm("D_0033caf4");
extern s8 D_0036d740[8] asm("D_0036d740");
extern s8 D_0036d748[8] asm("D_0036d748");
extern s8 D_0036d750[8] asm("D_0036d750");
void func_001aabd8(void) asm("func_001aabd8");
void func_002fee78(char*, const char*, ...) asm("func_002fee78");
void* func_001b1490(void*) asm("func_001b1490");
W1963Res* func_00168b38(void*, s32, s32) asm("func_00168b38");
W1963Res* func_00168b88(void*, s32, s32, s32) asm("func_00168b88");
s32 func_00105c30(void) asm("func_00105c30");
static inline u32 TAG(const s8* s) { return s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24); }
void func_001aaa08(void) asm("func_001aaa08");
void func_001aaa08(void)
{
    char buf[48];
    W1963Ent* e = D_01c6cc60;
    func_001aabd8();
    s32 f = 0;
    func_002fee78(buf, D_00350a28, D_0033caf4);
    void* h = func_001b1490(buf);
    u32 v = func_00168b88(h, 2, TAG(D_0036d740), 0)->data;
    e[5].d1c = v;
    e[2].d1c = v;
    e[1].d1c = v;
    e[0].d1c = v;
    v = func_00168b88(h, 2, TAG(D_0036d748), 0)->data;
    e[4].d1c = v;
    e[3].d1c = v;
    D_01c6cec4 = func_00168b88(h, 2, TAG(D_0036d750), 0)->data;
    D_01c6cec0 = func_00168b38(h, 25, 0)->data;
    if (func_00105c30() == 1 || func_00105c30() == 8) f = 1;
    if ((u8)f == 0) {
        D_01c6cc60[5].b13 = 24;
        D_01c6cc60[2].b13 = 24;
        D_01c6cc60[1].b13 = 24;
        D_01c6cc60[0].b13 = 24;
        D_01c6cc60[4].b13 = 32;
        D_01c6cc60[3].b13 = 32;
        D_00350a30 = 32;
    }
}
} // n001aaa08

// 001aabd8 (from src/anon/batch_w96.cpp)
namespace n001aabd8 {
void func_002fee78(char*, const char*, ...) asm("func_002fee78");
u32 func_00170b30(u32) asm("func_00170b30");
void func_00168328(char*, u32) asm("func_00168328");
u8* func_00168b38(u32, u32, u32) asm("func_00168b38");
void func_001aad28(u32, u32, u32, u32, u32, u32) asm("func_001aad28");
void func_00170c00(u32) asm("func_00170c00");
extern const char* D_00350a2c asm("D_00350a2c");
extern u32 D_0033caf4 asm("D_0033caf4");
void func_001aabd8(void) asm("func_001aabd8");
void func_001aabd8(void) {
    char path[48];
    u32 h;
    u32 p;
    func_002fee78(path, D_00350a2c, D_0033caf4);
    h = func_00170b30(0x80000);                   
    func_00168328(path, h);
    p = *(u32*)(func_00168b38(h, 36, 0) + 8);                         
    func_001aad28(0, 8, 36, 512, 256, p);
    func_001aad28(0, 8, 44, 512, 256, p + 0x10000);
    p = *(u32*)(func_00168b38(h, 36, 1) + 8);                         
    func_001aad28(2048, 8, 36, 512, 512, p);
    func_001aad28(2048, 8, 44, 512, 512, p + 0x20000);
    p = *(u32*)(func_00168b38(h, 36, 2) + 8);                         
    func_001aad28(6144, 4, 27, 256, 160, p);
    func_001aad28(16380, 1, 0, 16, 16, p + 0xa000);
    func_00170c00(h);
}
} // n001aabd8

// 001aad28 (from src/anon/auto80_199_queue.cpp)
namespace n001aad28 {
void func_001aad28(s16 a0, s16 a1, s16 a2, s16 a3, s16 a4, u32 a5) asm("func_001aad28");
void func_001aad28(s16 a0, s16 a1, s16 a2, s16 a3, s16 a4, u32 a5) {
    u8 stack_70[96];
    sceGsSetDefLoadImage(stack_70, (u32)a0, (u32)a1, (u32)a2, 0, 0, (u32)a3, (u32)a4);
    func_003058a0(0);
    sceGsExecLoadImage(stack_70, a5);
    sceGsSyncPath(0, 0);
}
} // n001aad28

// 001aadb0 (from src/anon/batch_w18.cpp)
namespace n001aadb0 {
extern u8 D_01c6cd20[] asm("D_01c6cd20");
void func_002362b0(void*, u32) asm("func_002362b0");
void func_002367c8(void*) asm("func_002367c8");
void func_001aadb0(u32 a) asm("func_001aadb0");
void func_001aadb0(u32 a) {
    func_002362b0(D_01c6cd20, a);
    func_002367c8(D_01c6cd20);                            
}
} // n001aadb0

// 001aade8 (gap: twin of 0x001aae28)
namespace n001aade8 {
struct S1aae28 { u32 a, b, c, d; u8 e, f, g, h; u32 j; u32 i; };
void func_001aade8(S1aae28* s, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 j, u32 i) asm("func_001aade8");
void func_001aade8(S1aae28* s, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 j, u32 i) {                        
    s->a = a;
    s->b = b;
    s->c = c;
    s->d = d;
    s->e = e;
    s->f = f;
    s->g = g;
    s->h = h;
    s->j = j;
    s->i = i;
}
} // n001aade8

// 001aae28 (from src/anon/batch_w22.cpp)
namespace n001aae28 {
struct S1aae28 { u32 a, b, c, d; u8 e, f, g, h; u32 j; u32 i; };
void func_001aae28(S1aae28* s, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 j, u32 i) asm("func_001aae28");
void func_001aae28(S1aae28* s, u32 a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h, u32 j, u32 i) {                        
    s->a = a;
    s->b = b;
    s->c = c;
    s->d = d;
    s->e = e;
    s->f = f;
    s->g = g;
    s->h = h;
    s->j = j;
    s->i = i;
}
} // n001aae28

// 001aae68 (from src/anon/tiny.cpp)
namespace n001aae68 {
extern u32 D_01c6cc60 asm("D_01c6cc60");
u32 func_001aae68(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001aae68");
u32 func_001aae68(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    return (u32)&D_01c6cc60 + ((u32)a0 << 5);
}
} // n001aae68

// 001aae80 (from src/anon/tiny_leaf.cpp)
namespace n001aae80 {
u32 func_001aae80(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001aae80");
u32 func_001aae80(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r15 = *(u32*)((u32)r4 + (s32)(28));
    r15 = (u32)(r15 + r5);
    r2 = (u32)(*(u8*)((u32)r15 + (s32)(0)));
    return r2;
}
} // n001aae80

// 001aae90 (from src/anon/tiny_leaf.cpp)
namespace n001aae90 {
u32 func_001aae90(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001aae90");
u32 func_001aae90(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r14 = 0u, r15 = 0u;
    r14 = (u32)(0x01c7u << 16);
    r15 = *(u32*)((u32)r14 + (s32)(-12604));
    r15 = (u32)(r15 + r4);
    r2 = (u32)(*(u8*)((u32)r15 + (s32)(0)));
    return r2;
}
} // n001aae90

