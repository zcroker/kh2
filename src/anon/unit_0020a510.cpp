// Linked unit 0x0020a510-0x0020a658 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>

// 0020a510 (was src/anon/batch_w1673.cpp)
namespace n0020a510 {
extern u8 D_01d9e7b0[] asm("D_01d9e7b0");
void sceVu0ApplyMatrix(void*, void*, void*) asm("sceVu0ApplyMatrix");
void sceVu0Normalize(void*, void*) asm("sceVu0Normalize");
void func_002fde18(void*, s32, u32) asm("func_002fde18");
struct V20a510 { f32 x, y, z, w; };
struct I20a510 { V20a510 pos; V20a510 q; };
struct M20a510 { u8 pad[0x7c]; f32 x, y, z; u8 pad2[0x9c - 0x88]; f32 r0, r1; };
f32 func_00209fb8() asm("func_00209fb8");
void func_0020a090(M20a510*, I20a510*, u8*) asm("func_0020a090");
/*TARGET 0020a510*/
void func_0020a510(void* self, void* mv, void* itv, u8* buf) asm("func_0020a510");
void func_0020a510(void* self, void* mv, void* itv, u8* buf) {
    M20a510* m = (M20a510*)mv;
    I20a510* it = (I20a510*)itv;
    func_002fde18(it, 0, 0x60);
    if (buf) func_002fde18(buf, 0, 0x20);
    V20a510 v;
    v.x = m->x;
    v.y = m->y;
    v.z = m->z;
    v.w = 1.0f;
    sceVu0Normalize(&it->q, &v);
    f32 r = m->r0 + m->r1;
    f32 d = r + r;
    f32 len;
    do {
        it->pos.x = d * func_00209fb8() - r;
        it->pos.y = d * func_00209fb8() - r;
        it->pos.z = d * func_00209fb8() - r;
        asm volatile(
            "lqc2 $vf10,0(%1)\n"
            "vmul.xyz $vf10,$vf10,$vf10\n"
            "vaddx.y $vf10,$vf10,$vf10x\n"
            "vaddy.z $vf10,$vf10,$vf10y\n"
            "vsqrt Q,$vf10z\n"
            "vwaitq\n"
            "vaddq.x $vf10,$vf0,Q\n"
            "qmfc2 %0,$vf10\n" : "=r"(len) : "r"(it));
    } while (r < len);
    it->pos.w = 1.0f;
    sceVu0ApplyMatrix(it, D_01d9e7b0, it);
    func_0020a090(m, it, buf);
}
}  // namespace n0020a510

