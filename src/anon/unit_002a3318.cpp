// Linked unit 0x002a3318-0x002a3648 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/jm_diagram.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/layfile.hpp"
#include "../tozawa/file_address_layout.hpp"
#include "../tozawa/jm_treasure.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"

// 002a3318 (was src/anon/batch_w2420_nsa.cpp)
namespace n002a3318 {
struct Ent2a3 { u8 b0; u8 n; u8 b2; u8 b3; u8 pad[4]; };
struct G2a3 { u8 pad[0x1000]; Ent2a3 ent[15]; u8 pad2[0x1084 - 0x1078]; s32 lim; };
extern G2a3* D_0035f5e4 asm("D_0035f5e4");
extern u8* D_0035f5e8 asm("D_0035f5e8");
extern s32 D_0035f214 asm("D_0035f214");
extern u32 D_00374ba0 asm("D_00374ba0");
extern u32 D_00374ba4 asm("D_00374ba4");
extern s32 D_00374b9c asm("D_00374b9c");
extern s32 D_00374b98 asm("D_00374b98");
u8* func_002766d0(void) asm("func_002766d0");
void Tz__ScrollBar__SetPos(s32, s32) asm("Tz__ScrollBar__SetPos");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
void func_00138c10(void*, s32) asm("func_00138c10");
u32 Tz__JmWorldSel__GetId2WorldName(s32, s32) asm("Tz__JmWorldSel__GetId2WorldName");
s32 func_002954e0(s32) asm("func_002954e0");
void* func_00192048(u32) asm("func_00192048");
void* Tz__MenuUtil__MakeQuestionStr(u32, void*, s32) asm("Tz__MenuUtil__MakeQuestionStr");
s32 func_002a43f0(void) asm("func_002a43f0");
void func_002a3648(void) asm("func_002a3648");
void func_002a3950(void) asm("func_002a3950");
/*TARGET 002a3318*/
void func_002a3318(void) asm("func_002a3318");
void func_002a3318(void) {
    s32 i, k, sum;
    u32 t;
    u8* o;
    u8* base = func_002766d0();
    Tz__ScrollBar__SetPos(D_0035f214, D_0035f5e4->lim);
    func_002fde18(D_0035f5e8 + 0x982c, 0, 32);
    for (i = 0; i < 9; i++) {
        o = D_0035f5e8 + i * 0x1b4 + 0x7974;
        func_00138c10(o, 2);
        *(s32*)(o + 0x198) = 0;
        o = D_0035f5e8 + i * 0x1b4 + 0x88c8;
        func_00138c10(o, 2);
        *(s32*)(o + 0x198) = 0;
        func_00138c10(base + 0xa998 + i * 0x198, 2);
    }
    func_002fde18(base + 0x110a0, 0, 640);
    sum = 0;
    {
        for (i = 0; i < 15; i++) {
            if (D_0035f5e4->ent[i].n) {
                if (sum >= D_0035f5e4->lim) break;
                sum += D_0035f5e4->ent[i].n;
            }
        }
        k = i;
    }
    for (i = 0; i < 9 && k < 15; i++) {
        if (i + D_0035f5e4->lim != sum) continue;
        o = D_0035f5e8 + i * 0x1b4 + 0x7974;
        func_00138c10(o, 72);
        t = Tz__JmWorldSel__GetId2WorldName(k, 1);
        if (func_002954e0(k)) *(void**)(o + 0x198) = func_00192048(t);
        else *(void**)(o + 0x198) = Tz__MenuUtil__MakeQuestionStr(t, base + i * 64 + 0x110a0, 64);
        if (!D_0035f5e4->ent[k].b0) {
            t = (u32)(D_0035f5e8 + i * 0x1b4 + 0x88c8);
            *(void**)((u8*)t + 0x198) = func_00192048(func_002a43f0() ? D_00374ba0 : D_00374ba4);
        }
        if (func_002954e0(k)) {
            if (D_0035f5e4->ent[k].b2) {
                if (D_0035f5e4->ent[k].b3) t = D_00374b9c;
                else t = D_00374b98;
                func_00138c10(base + i * 0x198 + 0xa998, t);
            }
        }
        sum += D_0035f5e4->ent[k].n;
        {
            s32 j;
            for (j = k + 1; j < 15; j++) {
                if (D_0035f5e4->ent[j].n) break;
            }
            k = j;
        }
    }
    func_002a3648();
    func_002a3950();
}
}  // namespace n002a3318

