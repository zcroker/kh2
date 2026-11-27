// Linked unit 0x00324380: linkonce (template) copies of game code that the linker gathered after the
// toolchain libraries. One namespace per old matched source.
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include <stdarg.h>
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../global/misc.hpp"


// 00324380 (was src/anon/auto80_199_queue.cpp)
namespace n00324380 {
/*TARGET 00324380*/
void func_00324380(u32 self) asm("_Z13func_00324380j");
void func_00324380(u32 self) {
    u32 s18 = self;
    s32 s23 = 3;
    s32 s19 = -1;
    s32 s30 = -1;

    do {
        u32 s16 = s18;
        s32 s17 = 1;
        do {
            *(u32*)s16 = addr_D_00347f98();
            func_0031a838(s16 + 12);
            *(u32*)s16 = addr_D_00347e60();
            func_00239700(s16 + 24);
            *(u32*)s16 = addr_D_00347e40();
            *(u32*)(s16 + 408) = 0;
            s16 += 436;
            --s17;
        } while (s17 != s19);

        --s23;
        s18 += 872;
    } while (s23 != s30);
}
}  // namespace n00324380

// 00324448 (was src/anon/auto80_199_queue.cpp)
namespace n00324448 {
/*TARGET 00324448*/
void func_00324448(u32 self) asm("_Z13func_00324448j");
void func_00324448(u32 self) {
    u32 s18 = self;
    s32 s23 = 9;
    s32 s19 = -1;
    s32 s30 = -1;

    do {
        u32 s16 = s18;
        s32 s17 = 1;
        do {
            *(u32*)s16 = addr_D_00347f98();
            func_0031a838(s16 + 12);
            *(u32*)s16 = addr_D_00347e60();
            func_00239700(s16 + 24);
            *(u32*)s16 = addr_D_00347e40();
            *(u32*)(s16 + 408) = 0;
            s16 += 436;
            --s17;
        } while (s17 != s19);

        --s23;
        s18 += 872;
    } while (s23 != s30);
}
}  // namespace n00324448

// 00324510 (was src/anon/batch_w2493_nsa.cpp)
namespace n00324510 {
void func_00239700(void*) asm("func_00239700");
void func_0031a838(void*) asm("func_0031a838");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e40[] asm("D_00347e40");
static inline __attribute__((always_inline)) void W1986_ctor408(u8* e)
{
    *(u32*)(e + 12) = 0; *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
}
static inline __attribute__((always_inline)) void H436(u8* e, u32 a, u32 b)
{
    *(u32*)e = a; func_0031a838(e + 12);
    *(u32*)e = b; func_00239700(e + 24);
    *(u32*)(e + 408) = 0; *(volatile u32*)e = (u32)D_00347e40;
}
static inline __attribute__((always_inline)) void H408(u8* e, u32 b)
{
    *(u32*)(e + 12) = 0; *(u32*)e = b; func_00239700(e + 24);
}
static inline __attribute__((always_inline)) void H436b(u8* e, u32 a, u32 b)
{
    *(volatile u32*)e = a; func_0031a838(e + 12);
    *(u32*)e = b; func_00239700(e + 24);
    *(u32*)e = (u32)D_00347e40; *(u32*)(e + 408) = 0;
}
/*TARGET 00324510*/
void sa__MUSICAL_SCORE5__init(u8* t) asm("sa__MUSICAL_SCORE5__init");
void sa__MUSICAL_SCORE5__init(u8* t)
{
    {
        u8* e = t;
        s32 i = 47;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
    W1986_ctor408(t + 19584);
    {
        u8* e = t + 19992;
        s32 i = 1;
        for (; i != -1; i--, e += 408) {
            *(u32*)(e + 12) = 0; *(u32*)e = (u32)D_00347e60; func_00239700(e + 24);
        }
    }
    u32 va = (u32)D_00347f98; u32 vb = (u32)D_00347e60;
    H408(t + 20808, vb);
    H408(t + 21216, vb);
    H408(t + 21624, vb);
    u8* m0 = t + 22032;
    u8* m1 = t + 22468;
    u8* m2 = t + 22904;
    u8* m3 = t + 23340;
    u8* m4 = t + 23776;
    u8* m5 = t + 24212;
    H436(m0, va, vb);
    H436(m1, va, vb);
    H436(m2, va, vb);
    H436(m3, va, vb);
    H436(m4, va, vb);
    H436b(m5, va, vb);
}
}  // namespace n00324510

// 00324710 (was src/anon/misc_3.cpp)
namespace n00324710 {
/*TARGET 00324710*/
void func_00324710(void* self) asm("_Z13func_00324710Pv");
void func_00324710(void* self) { *(s32*)((char*)self + 0) = 0; }
}  // namespace n00324710

// 00324718 (was src/anon/batch_w20.cpp)
namespace n00324718 {
/*TARGET 00324718*/
// 1 if v is in the list headed at *p (next at +0x1c).
u32 func_00324718(u8** p, u8* v) asm("func_00324718");
// 1 if v is in the list headed at *p (next at +0x1c).
u32 func_00324718(u8** p, u8* v) {
    u8* n = 0;
    while ((n = !n ? *p : *(u8**)(n + 0x1c)) != 0) {
        if (n == v) return 1;
    }
    return 0;
}
}  // namespace n00324718
