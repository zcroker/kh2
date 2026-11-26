#include "../common/types.h"
#include "../ryj/effect.hpp"
#include "../ryj/effect_data.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "tiny_auto80_solver_structs.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/help_gra.hpp"

// ---- 001dd920 from src/anon/batch_w93.cpp
namespace n001dd920 {
struct W93Dr;
struct W93DrVt { void* a; void* b; void (*draw)(W93Dr*); };
struct W93Dr { W93DrVt* vt; };
struct W93Sp { u8 pad[4]; s32 type; s32 flags; u8 p2[20 - 12]; W93Dr* dr; u8 p3[28 - 24]; u32 tex; u8 p4[40 - 32]; W93Sp* next; };
extern u8 D_00352af0 asm("D_00352af0");
extern u8 D_00352af1 asm("D_00352af1");
extern W93Sp* D_00352ae0 asm("D_00352ae0");
void ryj__EFFECT__SortEffect(void) asm("ryj__EFFECT__SortEffect");
void func_001b81e8(void) asm("func_001b81e8");
void func_001e6688(void) asm("func_001e6688");
s32 func_001dc9d0(W93Sp*) asm("func_001dc9d0");
void func_001dc878(W93Sp*) asm("func_001dc878");
s32 func_001dcc60(W93Sp*) asm("func_001dcc60");
void func_001e6648(void) asm("func_001e6648");
void func_001dca70(W93Sp*) asm("func_001dca70");
void func_001e3330(u32) asm("func_001e3330");
s32 pppPartDraw(u32) asm("pppPartDraw");
void pppDeleteMng(u32) asm("pppDeleteMng");
void func_001e6af8(void) asm("func_001e6af8");
void func_001b8218(void) asm("func_001b8218");
struct W93NoTail { ~W93NoTail() {} };
void func_001dd920(void) asm("func_001dd920");
void func_001dd920(void)
{
    W93NoTail keep;
    if (D_00352af1) return;
    if (!D_00352af0) return;
    s32 any = 0;
    ryj__EFFECT__SortEffect();
    func_001b81e8();
    func_001e6688();
    W93Sp* next;
    for (W93Sp* o = D_00352ae0; o; o = next) {
        next = o->next;
        if (!func_001dc9d0(o)) continue;
        if ((u8)((o->flags >> 26) & 1)) continue;
        if (o->type == 4) {
            o->dr->vt->draw(o->dr);
            any = 1;
            func_001dc878(o);
        } else {
            if (!o->tex) continue;
            if (!func_001dcc60(o)) continue;
            if (any) {
                func_001e6648();
                any = 0;
            }
            func_001dca70(o);
            func_001e3330(o->tex);
            if (pppPartDraw(o->tex)) continue;
            pppDeleteMng(o->tex);                        
            o->tex = 0;
            o->flags |= 0x10000;
        }
    }
    func_001e6af8();
    func_001b8218();                       
}
}  // namespace n001dd920

// ---- 001dda78 from src/anon/batch_wcx.cpp
namespace n001dda78 {
typedef void (*VFn)(u8*);
extern u8* D_00352ae0 asm("D_00352ae0");
s32 func_001dc9d0(u8*) asm("func_001dc9d0");
s32 func_001dc738(u8*) asm("func_001dc738");
void func_001dda78(void) asm("func_001dda78");
void func_001dda78(void)
{
    u8* n = D_00352ae0;
    if (!n) return;
    do {
        u8* nx = *(u8**)(n + 40);
        if (func_001dc9d0(n)) goto next;
        if ((u8)((*(s32*)(n + 8) >> 26) & 1)) goto next;
        if (!func_001dc738(n)) {                     
            u32 f = *(u32*)(n + 8);
            if (f & 0x100000) {
                if (n) (*(VFn*)(*(u8**)n + 4))(n);
            } else if ((u8)(f & 1)) {
                *(u32*)(n + 8) = f | 0x100000;
            }
        }
    next:
        n = nx;
    } while (n);
}
}  // namespace n001dda78

// ---- 001ddb30 manual (gap: run 0x1dda78 twice)
namespace n001ddb30 {
void func_001dda78(u8*) asm("func_001dda78");
void func_001ddb30(u8* o) asm("func_001ddb30");
void func_001ddb30(u8* o) { func_001dda78(o); func_001dda78(o); }
}  // namespace n001ddb30

// ---- 001ddb58 from src/anon/tiny.cpp
namespace n001ddb58 {
extern u32 D_00352af1 asm("D_00352af1");
void func_001ddb58(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001ddb58jjjj");
void func_001ddb58(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a1;
    (void)a2;
    (void)a3;
    u32 v = (u32)((s32)1);
    *(u8*)&D_00352af1 = (u8)v;
}
}  // namespace n001ddb58

// ---- 001ddb68 from src/anon/tiny.cpp
namespace n001ddb68 {
void func_001ddb68(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001ddb68jjjj");
void func_001ddb68(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 b = (0x0035u << 16);
    *(u8*)((u32)b + (10993)) = (u8)0;
}
}  // namespace n001ddb68

// ---- 001ddb78 from src/anon/batch_w64.cpp
namespace n001ddb78 {
u8* func_00102788_p(void*, u32, u32, void*) asm("func_00102788");
extern char D_001dd2b8[] asm("D_001dd2b8");
extern char D_001dd920[] asm("D_001dd920");
extern char D_001dda78[] asm("D_001dda78");
extern char D_001ddb30[] asm("D_001ddb30");
u8* func_001ddb78(void* a0, u32 a1, u32 a2, u32 a3, u32 a4) asm("func_001ddb78");
u8* func_001ddb78(void* a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    func_00102788_p(a0, a1, a2, D_001dd2b8);
    func_00102788_p(a0, a1, a3, D_001dd920);
    u8* r = func_00102788_p(a0, a1, a4, D_001dda78);
    *(void**)(r + 48) = D_001ddb30;
    return r;
}
}  // namespace n001ddb78

// ---- 001ddc08 from src/anon/batch_w14.cpp
namespace n001ddc08 {
extern u8* D_00352ae0 asm("D_00352ae0");
void func_001ddc08(void) asm("func_001ddc08");
void func_001ddc08(void) {
    u8* p;
    for (p = D_00352ae0; p; p = *(u8**)(p + 40)) {
        *(u32*)(p + 8) |= 0x4000000;
    }
}
}  // namespace n001ddc08

// ---- 001ddc48 from src/anon/batch_w20.cpp
namespace n001ddc48 {
extern u8* D_00352ae0 asm("D_00352ae0");
void func_001ddc48(void) asm("func_001ddc48");
void func_001ddc48(void) {
    for (u8* n = D_00352ae0; n; n = *(u8**)(n + 40))
        *(u32*)(n + 8) &= ~0x4000000;
}
}  // namespace n001ddc48

// ---- 001ddc88 manual (the effect list; gcc makes the static init and both stubs)
namespace n001ddc88 {
struct EFFLIST {
    void* head;
    void* tail;
    EFFLIST() { tail = 0; head = 0; }
    ~EFFLIST() {}
};
EFFLIST D_00352ae0 asm("D_00352ae0");
}  // namespace n001ddc88

// ---- 001ddcb0 dropped: gcc makes the _GLOBAL__I_ stub

