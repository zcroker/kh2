#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "../yasui/libys/obj.hpp"
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../yasui/libys/lockon.hpp"
#include "tiny_auto80_solver_structs.hpp"

// ---- 0019ea10 from src/anon/batch_w83.cpp
namespace n0019ea10 {
s32 func_001a3570(s32) asm("func_001a3570");
u32* func_00177860(void) asm("func_00177860");
s32 YS__COMMAND_SLOT__GetStatus(void*, void*, s32) asm("YS__COMMAND_SLOT__GetStatus");
static inline bool lt4(void* c, void* a) { return YS__COMMAND_SLOT__GetStatus(c, a, 0) < 4; }
bool YS__RC_SEARCHER__CheckAutoCommand(void* a, u8* b, void* c) asm("YS__RC_SEARCHER__CheckAutoCommand");
bool YS__RC_SEARCHER__CheckAutoCommand(void* a, u8* b, void* c) {
    u32* bits = func_00177860();
    switch (b[2]) {
    case 19: {
        u32 id = *(u16*)(b + 4);
        if (!(bits[id >> 5] & (1 << (id & 31)))) return 0;
        break;
    }
    case 20:
        if (!func_001a3570(*(u16*)b)) return 0;
        break;
    }
    return lt4(c, a);
}
}  // namespace n0019ea10

// ---- 0019ead0 from src/anon/batch_w52.cpp
namespace n0019ead0 {
void func_00190128(void*) asm("func_00190128");
void* func_001d45a0(u32, u16) asm("func_001d45a0");
void func_00190878(void*, u32, u32) asm("func_00190878");
void YS__RC_SEARCHER__set(u8*, void*, void*, u32, u32) asm("YS__RC_SEARCHER__set");
u32 func_0019ead0(u8* p, u32 b) asm("func_0019ead0");
u32 func_0019ead0(u8* p, u32 b) {
    u8 buf[32];
    void* o = func_001d45a0(b, *(u16*)(*(u8**)p + 38));
    if (o) {
        func_00190128(buf);
        func_00190878(buf, b, 0);
        YS__RC_SEARCHER__set(p, o, buf, 0, 0);
        return 1;
    }
    return 0;
}
}  // namespace n0019ead0

// ---- 0019eb60 from src/anon/batch_w46.cpp
namespace n0019eb60 {
void Activate46(char*) asm("_ZN2YS4UNIT8ActivateEPc");
extern u64 D_0034ecc8 asm("D_0034ecc8");
void func_0015ee90(s32) asm("func_0015ee90");
void Activate46(char*) {
    for (s32 i = 0; i < 64; i++) {
        if ((u8)((D_0034ecc8 >> i) & 1)) func_0015ee90(i);
    }
}
}  // namespace n0019eb60

// ---- 0019ebc0 from src/anon/batch_w47.cpp
namespace n0019ebc0 {
extern u64 D_0034ecc8 asm("D_0034ecc8");
void func_0015ee10(s32) asm("func_0015ee10");
void func_0019ebc0(void) asm("func_0019ebc0");
void func_0019ebc0(void) {
    for (s32 i = 0; i < 64; i++) if ((u8)((D_0034ecc8 >> i) & 1)) func_0015ee10(i);
}
}  // namespace n0019ebc0

// ---- 0019ec20 from src/anon/batch_w28.cpp
namespace n0019ec20 {
void func_0019ec88(void*) asm("func_0019ec88");
void func_0019ed48(void*) asm("func_0019ed48");
void func_0019ec68(void) asm("func_0019ec68");
void func_00102c18(u32, u32, void (*)(void)) asm("func_00102c18");
extern u8 D_00350448[] asm("D_00350448");
void YS__BLUR__Init(void) asm("YS__BLUR__Init");
void YS__BLUR__Init(void) {
    func_0019ec88(D_00350448);
    func_0019ed48(D_00350448);
    func_00102c18(1, 0xa410, func_0019ec68);
}
}  // namespace n0019ec20

// ---- 0019ec68 gap function (unwritten; runs 0x19eda0 on the object at 0x350448)
namespace n0019ec68 {
extern u8 D_00350448[] asm("D_00350448");
void func_0019eda0(u8*) asm("_Z13func_0019eda0j");
void func_0019ec68() asm("func_0019ec68");
void func_0019ec68() { func_0019eda0(D_00350448); }
}  // namespace n0019ec68

// ---- 0019ec88 from src/anon/tiny_auto80_solver.cpp
namespace n0019ec88 {
void func_0019ec88(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0019ec88jjjjjjjj");
void func_0019ec88(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0019ec88jjjjjjjj");
void func_0019ec88(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    Init_0019ec88* p = (Init_0019ec88*)a0;
    u32 one = 1;
    u32 sev = 112;
    p->a = 0;
    p->b = 0;
    p->c = sev;
    p->d = one;
    p->e = one;
    p->f = 0;
    p->g = one;
}
}  // namespace n0019ec88

// ---- 0019ecb0 from src/anon/batch_w56.cpp
namespace n0019ecb0 {
void func_0014a7e8(s32) asm("func_0014a7e8");
void func_0014a768(u8) asm("func_0014a768");
void func_0014a788(u16, u16) asm("func_0014a788");
void func_0014a7b8(f32, u32) asm("func_0014a7b8");
void func_0014a7f8(s32) asm("func_0014a7f8");
void func_001ad990(u8*, f32, f32, f32) asm("func_001ad990");
struct BlurState { u32 started : 1; u32 rest : 31; void* on; u8 b8; u8 p9[3]; u16 x; u16 p0e; u16 y; u16 p12; f32 f20; u32 i24; u8 tail[4]; };
void blur_start(BlurState* self, f32 t) asm("_ZN2YS4BLUR5startEf");
void blur_start(BlurState* self, f32 t)
{
    self->started = 1;
    func_0014a7e8(self->on != 0);
    func_0014a768(self->b8);
    func_0014a788(self->x + 256, self->y + 208);
    func_0014a7b8(self->f20, self->i24);
    func_0014a7f8(1);
    func_001ad990((u8*)self + 28, 0.0f, 1.0f, t);
}
}  // namespace n0019ecb0

// ---- 0019ed48 from src/anon/tiny_auto80_fptr4.cpp
namespace n0019ed48 {
u32 func_0014a7f8(u32, u32, u32, u32) asm("_Z13func_0014a7f8jjjj");
u32 func_0019ed48(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0019ed48jjjj");
u32 func_0019ed48(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r13, r14, r15;
    r13 = (u32)((s32)0u + (-2));
    r15 = r4;
    r14 = *(u32*)((u32)r4 + (s32)(0));
    r14 = (u32)(r14 & r13);
    r4 = 0u;
    *(u32*)((u32)r15 + (s32)(0)) = r14;
    return func_0014a7f8(r4, r5, r6, r7);
}
}  // namespace n0019ed48

// ---- 0019ed78 from src/anon/tiny_auto80_queue.cpp
namespace n0019ed78 {
void func_001ad990(u32, f32, f32, f32) asm("_Z13func_001ad990jfff");
void func_0019ed78(u32 a0, f32 a1) asm("_Z13func_0019ed78jf");
void func_0019ed78(u32 a0, f32 a1) {
    f32 f14 = a1;
    func_001ad990((u32)((s32)a0 + (28)), *(f32*)((u32)a0 + (s32)(28)), 0.0f, f14);
}
}  // namespace n0019ed78

// ---- 0019eda0 from src/anon/auto80_199_queue.cpp
namespace n0019eda0 {
void func_0019eda0(u32 a0) asm("_Z13func_0019eda0j");
void func_0019eda0(u32 a0) {
    u32 *s0 = (u32 *)a0;
    u32 t7;
    f32 f1;
    f32 f0;
    s32 i0;

    t7 = s0[0];
    t7 = t7 & 1;
    if (t7 == 0) {
        return;
    }
    func_001ad9c8((void *)((u8 *)s0 + 28));                             
    f1 = *(f32 *)((u8 *)s0 + 28);
    if (f1 == 0.0f) {
        func_0019ed48((u32)s0);
        return;
    }
    i0 = *(s32 *)((u8 *)s0 + 8);
    f0 = (f32)i0;
    f0 = f0 * f1;
    i0 = (s32)f0;
    func_0014a768((u32)i0 & 0xff);
}
}  // namespace n0019eda0

// ---- 0019ee28 from src/anon/batch_w3702.cpp
namespace n0019ee28 {
union Cell00350448 { s32 i; f32 f; };
extern Cell00350448 D_00350448[9] asm("D_00350448");
extern f32 D_00350464 asm("D_00350464");
void wtarget_0019ee28(u32, u32, u32, u32) asm("_Z16wtarget_0019ee28jjjj");
void wtarget_0019ee28(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        // union cells: the +0x20 float store and the +0 int store can alias, which keeps their order in sched2
        Cell00350448* p = D_00350448;
        f32 z = 0.0f;
        p[0].i = 0;
        D_00350464 = z;
        p[8].f = z;
    }
}
}  // namespace n0019ee28

// ---- 0019ee60 from src/anon/tiny_wrappers_more.cpp
namespace n0019ee60 {
u32 func_0019ee28(u32, u32, u32, u32) asm("_Z13func_0019ee28jjjj");
u32 func_0019ee60(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0019ee60jjjj");
u32 func_0019ee60(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0019ee28(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n0019ee60

