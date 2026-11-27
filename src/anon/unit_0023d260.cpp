// Linked unit 0x0023d260-0x0023e188: Tz::MenuCommon, Tz::MenuObj.
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
#include "../ishi/sequence.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_obj.hpp"
#include "../tozawa/layout.hpp"
#include "../tozawa/laymsg.hpp"
#include "../tozawa/layfile.hpp"
#include "../tozawa/file_address_layout.hpp"
#include "../tozawa/mcard.hpp"

// 0023d260 (was src/anon/batch_w64.cpp)
namespace n0023d260 {
// ---------------------------------------------------------------------------
void func_0023d2b0(void) asm("func_0023d2b0");
void func_00253638(void) asm("func_00253638");
void func_00257000(void) asm("func_00257000");
extern u8 D_00349e20 asm("D_00349e20");
extern u32 D_00349e1c asm("D_00349e1c");
extern u8 D_0035eb50 asm("D_0035eb50");
extern u32 D_0035eb54 asm("D_0035eb54");
/*TARGET 0023d260*/
void func_0023d260(void) asm("func_0023d260");
void func_0023d260(void) {
    func_0023d2b0();
    func_00253638();
    func_00257000();
    D_0035eb50 = D_00349e20 == 0;
    D_0035eb54 = D_00349e1c;
}
}  // namespace n0023d260

// 0023d2b0 (was src/anon/tiny_more2.cpp)
namespace n0023d2b0 {
extern u32 D_0035eb48 asm("D_0035eb48");
extern u32 D_0035eb4c asm("D_0035eb4c");
/*TARGET 0023d2b0*/
// 0x0022d3b8: definition moved into src/anon/unit_0022d358.cpp

void func_0023d2b0(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_0023d2b0jjjj");
// 0x0022d3b8: definition moved into src/anon/unit_0022d358.cpp

void func_0023d2b0(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 v=(u32)((s32)-1); D_0035eb48=v; D_0035eb4c=v; }
}  // namespace n0023d2b0

// 0023d2c8 (was src/anon/tiny_more2.cpp)
namespace n0023d2c8 {
extern u32 D_0035eb48 asm("D_0035eb48");
extern u32 D_0035eb4c asm("D_0035eb4c");
/*TARGET 0023d2c8*/
void func_0023d2c8(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_0023d2c8jjjj");
void func_0023d2c8(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; D_0035eb48 = a0; D_0035eb4c = a1; }
}  // namespace n0023d2c8

// 0023d2e0 (was src/anon/batch_w2.cpp)
namespace n0023d2e0 {
extern s32 D_0035eb48 asm("D_0035eb48");
/*TARGET 0023d2e0*/
// 0x00222978: definition moved into src/anon/unit_00222548.cpp

// Returns 0 (and stores 0) when the value is unset (-1).
s32 func_0023d2e0(s32* out) asm("func_0023d2e0");
// 0x00222978: definition moved into src/anon/unit_00222548.cpp

// Returns 0 (and stores 0) when the value is unset (-1).
s32 func_0023d2e0(s32* out) {  // store_global_test_result
    s32 v = D_0035eb48;
    s32 none = (v == -1);
    *out = none ? 0 : v;
    return none ^ 1;
}
}  // namespace n0023d2e0

// 0023d300 (was src/anon/batch_w3.cpp)
namespace n0023d300 {
// 0x00224950: definition moved into src/anon/unit_00224780.cpp

// Writes the current id (0 when unset, -1) and returns whether it was set.
extern s32 D_0035eb4c asm("D_0035eb4c");
/*TARGET 0023d300*/
s32 func_0023d300(s32* out) asm("func_0023d300");
s32 func_0023d300(s32* out) {
    bool none = D_0035eb4c == -1;
    s32 v = none ? 0 : D_0035eb4c;
    *out = v;
    return !none;
}
}  // namespace n0023d300

// 0023d320 (was src/anon/batch_w52.cpp)
namespace n0023d320 {
// 0x00236bb8: definition moved into src/anon/unit_00236180.cpp

extern u32 D_00349e1c asm("D_00349e1c");
extern u8 D_00349e20 asm("D_00349e20");
extern u32 D_0035eb54 asm("D_0035eb54");
extern u8 D_0035eb50 asm("D_0035eb50");
void func_0014ce20(u32) asm("func_0014ce20");
void func_0014ce30(u32) asm("func_0014ce30");
/*TARGET 0023d320*/
void func_0023d320(void) asm("func_0023d320");
void func_0023d320(void) {
    D_0035eb54 = D_00349e1c;
    D_0035eb50 = D_00349e20 == 0;
    if (D_0035eb50) func_0014ce20(1);
    func_0014ce30(0);
}
}  // namespace n0023d320

// 0023d368 (was src/anon/auto80_199_queue.cpp)
namespace n0023d368 {
/*TARGET 0023d368*/
void func_0023d368() asm("_Z13func_0023d368v");
void func_0023d368() {
    if (D_0035eb50 != 0) {
        func_0014ce20(0);
    }
    func_0014ce30(D_0035eb54);
    D_0035eb50 = (u8)(D_00349e20 < 1);
    D_0035eb54 = D_00349e1c;
}
}  // namespace n0023d368

// 0023d3d0 (was src/anon/batch_w14.cpp)
namespace n0023d3d0 {
u8* func_001058e8(void) asm("func_001058e8");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
void func_00242880(void) asm("func_00242880");
void func_0023d410(void) asm("func_0023d410");
void func_00257000(void) asm("func_00257000");
/*TARGET 0023d3d0*/
void func_0023d3d0(void) asm("func_0023d3d0");
void func_0023d3d0(void) {
    func_002fde18(func_001058e8() + 16796, 0, 5124);
    func_00242880();
    func_0023d410();
    func_00257000();
}
}  // namespace n0023d3d0

// 0023d410 (was src/anon/tiny_auto80_solver.cpp)
namespace n0023d410 {
u32 func_001058e8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001058e8jjjjjjjj");
u32 func_0023d410(void) asm("_Z13func_0023d410v");
u32 func_002fde18(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_002fde18jjjjjjjj");
/*TARGET 0023d410*/
u32 func_0023d410(void) asm("_Z13func_0023d410v");
u32 func_0023d410(void) {
    u32 v0 = ((u32(*)())func_001058e8)();
    return ((u32(*)(u32, u32, u32))func_002fde18)(v0 + 20000, 255, 1920);
}
}  // namespace n0023d410

// 0023d438 (was src/anon/auto80_199_queue.cpp)
namespace n0023d438 {
/*TARGET 0023d438*/
u32 func_0023d438(void* a0, u32 a1) asm("_Z13func_0023d438Pvj");
u32 func_0023d438(void* a0, u32 a1) {
    u8* s2;
    u8* s0;
    s32 i;

    s2 = (u8*)a0;
    *(u32*)(s2 + 0x0c) = 0;
    *(u32*)(s2 + 0x00) = (u32)&D_0035eb60;

    s0 = s2 + 0x20;
    for (i = 3; i != -1; --i) {
        func_00106ab8(s0);  // noop_ret
        func_001070c8(s0 + 0x100);  // set_vtbl_34cc50
        s0 += 0x190;
    }

    s0 = s2 + 0x660;
    for (i = 3; i != -1; --i) {
        func_00322ba8(s0);
        s0 += 0x140;
    }

    func_0014c050(s2 + 0xb80);
    func_0014c050(s2 + 0xe90);
    func_0014c050(s2 + 0x11a0);

    *(u32*)(s2 + 0xb6c) = a1;
    return func_0023d5b8(s2);
}
}  // namespace n0023d438

// 0023d4f8 (was src/anon/auto80_199_queue.cpp)
namespace n0023d4f8 {
/*TARGET 0023d4f8*/
u32 func_0023d4f8(void* a0, u32 a1) asm("_Z13func_0023d4f8Pvj");
u32 func_0023d4f8(void* a0, u32 a1) {
    u8* s2;
    u8* s0;
    s32 i;

    s2 = (u8*)a0;
    *(u32*)(s2 + 0x0c) = 0;
    *(u32*)(s2 + 0x00) = (u32)&D_0035eb60;

    s0 = s2 + 0x20;
    for (i = 3; i != -1; --i) {
        func_00106ab8(s0);  // noop_ret
        func_001070c8(s0 + 0x100);  // set_vtbl_34cc50
        s0 += 0x190;
    }

    s0 = s2 + 0x660;
    for (i = 3; i != -1; --i) {
        func_00322ba8(s0);
        s0 += 0x140;
    }

    func_0014c050(s2 + 0xb80);
    func_0014c050(s2 + 0xe90);
    func_0014c050(s2 + 0x11a0);

    *(u32*)(s2 + 0xb6c) = a1;
    return func_0023d5b8(s2);
}
}  // namespace n0023d4f8

// 0023d5b8 (was src/anon/batch_w110.cpp)
namespace n0023d5b8 {
void func_0023e738(void*, s32, s32, s32) asm("func_0023e738");
// store_2halfwords_2928
void func_0014b610(u8*, u64) asm("func_0014b610");
void func_0014b608(u8*, u64) asm("func_0014b608");
void func_0014b5e0(u8*, u32) asm("func_0014b5e0");
void func_0014b220(u8*, s32, s32, s32, s32) asm("func_0014b220");
void func_0014b208(u8*, s32, s32) asm("func_0014b208");
void func_0014b630(u8*, u32) asm("func_0014b630");
void func_0014b618(u8*, u32) asm("func_0014b618");
void func_0014b468(u8*, s32, s32) asm("func_0014b468");
void func_0014b628(u8*, u64) asm("func_0014b628");
extern u64 D_00371510 asm("D_00371510");
extern u64 D_00371518 asm("D_00371518");
struct Slot { u8 pad0[48]; u32 f30; u8 pad1[60]; u32 f70; u32 f74; u8 pad2[196]; u8 f13c; u8 pad3[3]; };
struct Work {
    u8 pad0[1632];
    Slot slot[4];
    u8 pad1[2912 - 1632 - 1280];
    u8 kind[4];
    u8 index[4];
    u32 f2920;
    s32 count;
    u8 pad2[16];
    u8 gs0[784];
    u8 gs1[784];
    u8 gs2[784];
    u8 pad3[5296 - 5296];
    u32 a[4];
    u32 b[4];
    u32 c[4];
    u8 flag[3];
};
/*TARGET 0023d5b8*/
// Resets the four slots and sets up the three GS draw contexts.
void func_0023d5b8(Work* w) asm("func_0023d5b8");
// Resets the four slots and sets up the three GS draw contexts.
void func_0023d5b8(Work* w) {
    s32 i;
    for (i = 0; i < w->count; i++) {
        Slot* s = &w->slot[i];
        w->index[i] = i;
        w->kind[i] = 16;
        s->f70 = 0;
        s->f74 = 0;
        s->f30 = 0;
        s->f13c = 0;
        w->a[i] = 0;
        w->b[i] = 0;
        w->c[i] = 0;
        func_0023e738(w, i, 0, 0);  // store_2halfwords_2928
    }
    w->f2920 = 0;
    w->flag[0] = 0;
    w->flag[1] = 0;
    w->flag[2] = 0;
    func_0014b610(w->gs0, 0x31000070);
    func_0014b608(w->gs0, 0x80140);
    func_0014b5e0(w->gs0, 6);
    func_0014b220(w->gs0, 0, 0, 0, 0);
    func_0014b208(w->gs0, 512, 416);
    func_0014b608(w->gs1, 0x80140);
    func_0014b610(w->gs1, 0x131000070ULL);
    func_0014b5e0(w->gs1, 342);
    func_0014b630(w->gs1, 96);
    func_0014b618(w->gs1, 0x30003);
    func_0014b208(w->gs1, 512, 416);
    func_0014b468(w->gs1, 512, 416);
    func_0014b628(w->gs1, D_00371510);
    func_0014b610(w->gs2, 0x131000070ULL);
    func_0014b5e0(w->gs2, 342);
    func_0014b630(w->gs2, 96);
    func_0014b618(w->gs2, 13);
    func_0014b208(w->gs2, 512, 416);
    func_0014b468(w->gs2, 512, 416);
    func_0014b628(w->gs2, D_00371518);
}
}  // namespace n0023d5b8

// 0023d7c8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0023d7c8 {
u32 func_0023d820(...) asm("func_0023d820");
/*TARGET 0023d7c8*/
void func_0023d7c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0023d7c8jjjjjjjj");
void func_0023d7c8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15, r16;
    r15 = (u32)(*(u8*)((u32)r4 + (s32)(5344)));
    r16 = r4;
    if (r15 == 0u) {
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_0023d820)(r4, r5, r6, r7, r8, r9, r10, r11);
        r15 = (u32)((s32)0u + (1));
        *(u32*)((u32)r16 + (s32)(2924)) = 0u;
        *(u8*)((u32)r16 + (s32)(5344)) = (u8)r15;
    }
}
}  // namespace n0023d7c8

// 0023d808 (was src/anon/tiny_wrappers_more.cpp)
namespace n0023d808 {
u32 dk_Obj2D_create(u32, u32, u32, u32) asm("_ZN2dk5Obj2D6createEii");
/*TARGET 0023d808*/
u32 func_0023d808(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0023d808jjjj");
u32 func_0023d808(u32 a0, u32 a1, u32 a2, u32 a3) {
    return dk_Obj2D_create(a0, a1, 0x00000000u, a3);
}
}  // namespace n0023d808

// 0023d820 (was src/anon/batch_w114.cpp)
namespace n0023d820 {
// 0x0027e770: definition moved into src/anon/unit_0027e6e0.cpp

// ---- 0023d820
struct SubT { u8 pad[12]; u32 items[16]; };
struct Slot11 {
    u8 pad0[48]; u8* handle; u8 pad52[60]; u8* obj; u8 pad116[76]; u32 f192; u8 pad196[12];
    SubT sub; u8 pad284[32]; u8 active; u8 pad317[3];
};
struct Mgr11 {
    void* vt; u8 pad4[1628]; Slot11 slots[4]; u8 pad2912[4]; u8 order[4]; u32 f2920; s32 count;
    u8 pad2928[2368]; u32 a[4]; u32 b[4]; u32 c[4]; u8 pad5344[0]; u8 busy; u8 f5345; u8 f5346;
};
typedef void (*VFn11)(Mgr11*);
typedef void (*VRel11)(u8*, u32, u8*);
s32 func_00139d78(u8*) asm("func_00139d78");
u32 func_00103580(void) asm("func_00103580");
void func_001dc920(u32) asm("func_001dc920");
void func_001dde40(u32*) asm("func_001dde40");
void func_001a9350(u8*) asm("func_001a9350");
void func_00106420(u8*) asm("func_00106420");
void func_0023e738(Mgr11*, s32, s32, s32) asm("func_0023e738");
// store_2halfwords_2928
void func_001dda78(s32) asm("func_001dda78");
void func_0023d820(Mgr11* p) asm("func_0023d820");
/*TARGET 0023d820*/
void func_0023d820(Mgr11* p) asm("func_0023d820");
void func_0023d820(Mgr11* p) {
    s32 any, i, k;
    if (p->busy) return;
    if (func_00139d78((u8*)p)) (*(VFn11*)((*(u8**)p) + 20))(p);
    any = 0;
    for (i = 0; i < p->count; i++) {
        if (!p->slots) break;
        Slot11* s = &p->slots[p->order[i]];
        if (s->active) {
            if (s->handle) {
                u8* h = *(u8**)(s->handle + 20);
                (*(VRel11*)((*(u8**)h) + 40))(h, func_00103580(), s->handle);
                s->handle = 0;
            }
            SubT* sb = &s->sub;
            for (k = 0; k < 16; k++) {
                if (sb->items[k]) {
                    func_001dc920(sb->items[k]);
                    sb->items[k] = 0;
                }
            }
            u32* q = &s->f192;
            if (*q) func_001dde40(q);
            u8* o = s->obj;
            if (o) {
                func_001a9350(o);
                func_00106420(o);
                s->obj = 0;
            }
            s->active = 0;
            any = 1;
        }
        func_0023e738(p, i, 0, 0);  // store_2halfwords_2928
    }
    if (any) {
        func_001dda78(0);
        func_001dda78(0);
    }
    for (i = 0; i < p->count; i++) {
        p->order[i] = i;
        p->a[i] = 0;
        p->b[i] = 0;
        p->c[i] = 0;
    }
    p->f5345 = 0;
    p->f5346 = 0;
    p->f2920 = 0;
}
}  // namespace n0023d820

// 0023da00 (was src/anon/batch_w3747_nsa.cpp)
namespace n0023da00 {
struct V23da00 {
    f32 x, y, z, w;
    V23da00() {}
    V23da00(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V23da00& operator=(const V23da00& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    void unit() { asm volatile("sqc2 $vf0, 0(%0)" : : "r"(this) : "memory"); }
} __attribute__((aligned(16)));
struct Mot23da00 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6();
    virtual f32 len();
};
struct Res23da00 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7(); virtual void f8();
    virtual s32 get(s32);
};
struct Obj23da00 {
    V23da00 pos;
    V23da00 rot;
    V23da00 scl;
    s32 w48;
    u8 pad52[4];
    u32 flags;
    u8 pad60[4];
    s8 rgba[4];
    u8 pad68[92 - 68];
    void* p92;
    u8 pad96[112 - 96];
    void* mdl;
    Mot23da00* mot;
    s32 w120;
    s32 w124;
    u8 pad128[192 - 128];
    u8 m192[28];
    s32 w220[16];
    u8 pad284[0];
    s32 a2;
    s32 a3;
    s32 t0;
    s32 w296;
    f32 f300;
    f32 f304;
    f32 f308;
    struct Col { u8 r, g, b, a; void set(s32 R, s32 G, s32 B, s32 A) { r = R; g = G; b = B; a = A; } } col;
    u8 b316;
};
struct Mgr23da00 {
    u8 pad0[2916];
    u8 slot[4];
    s32 count;
};
void func_0023eac0(Mgr23da00*, s32, s32) asm("func_0023eac0");
void func_0023dd28(Mgr23da00*, s32, s32, s32) asm("func_0023dd28");
void func_00107330(void*, f32, f32, f32) asm("func_00107330");
void func_00107340(void*, f32, f32, f32) asm("func_00107340");
void func_00107350(void*, f32, f32, f32) asm("func_00107350");
void func_00107360(void*, f32) asm("func_00107360");
void func_00107118(void*) asm("func_00107118");
s32 func_0013a1d8() asm("func_0013a1d8");
void* func_001063c0(s32, s32) asm("func_001063c0");
void func_001a91f8(void*) asm("func_001a91f8");
void func_001a92d8(void*, s32, s32) asm("func_001a92d8");
s32 func_00103580() asm("func_00103580");
Res23da00* func_001a93e8(void*) asm("func_001a93e8");
Mot23da00* func_001a9458(void*, s32, s32) asm("func_001a9458");
void* func_001a9420(void*) asm("func_001a9420");
void func_0011e260(s32, void*) asm("func_0011e260");
f32 func_0023e700(Mgr23da00*) asm("func_0023e700");
void* func_001a9528(void*) asm("func_001a9528");
void func_001dddd0(void*, void*) asm("func_001dddd0");
void func_001a9560(void*, Obj23da00*, void*, s32*) asm("func_001a9560");
/*TARGET 0023da00*/
void func_0023da00(Mgr23da00* m, s32 idx, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2) asm("func_0023da00");
void func_0023da00(Mgr23da00* m, s32 idx, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2)
{
    u8* cam = (u8*)m + idx * 400 + 288;
    s32 sl = m->slot[idx] * 320; asm("" : "+r"(sl) : "r"(a3));
    Obj23da00* o = (Obj23da00*)((u8*)m + sl + 1632);
    func_0023eac0(m, idx, 16);
    func_0023dd28(m, idx, t1, t2);
    func_00107330(cam, 0.0f, -50.0f, -800.0f);
    func_00107340(cam, 0.0f, 0.0f, 55.0f);
    func_00107350(cam, 0.0f, -1.0f, 0.0f);
    func_00107360(cam, 0.0f);
    func_00107118(cam);
    o->rot.unit();
    o->pos = V23da00(0.0f, 0.0f, 0.0f, 0.0f);
    o->scl = V23da00(1.0f, 1.0f, 1.0f, 1.0f);
    void* p = func_001063c0(24, func_0013a1d8());
    func_001a91f8(p);
    func_001a92d8(p, a2, 0);
    o->mdl = p;
    o->a2 = a2;
    o->a3 = a3;
    o->t0 = t0;
    o->w48 = 0;
    s32 v = func_00103580();
    o->w48 = func_001a93e8(o->mdl)->get(v);
    if (a3 >= 0) o->mot = func_001a9458(o->mdl, a3, t0);
    else o->mot = 0;
    o->w120 = 0;
    o->w124 = 0;
    o->flags |= 2;
    o->rgba[3] = -1;
    o->rgba[2] = -128;
    o->rgba[1] = -128;
    o->rgba[0] = -128;
    o->p92 = func_001a9420(o->mdl);
    if (o->p92) func_0011e260(o->w48, o->p92);
    o->col.set(128, 128, 128, 128);
    if (o->mot) {
        o->f300 = o->mot->len();
        o->f304 = o->mot->len();
        o->f308 = func_0023e700(m);
        o->b316 = 1;
        o->w296 = 0;
    }
    for (s32 i = 0; i < 16; i++) o->w220[i] = 0;
    void* x = func_001a9528(o->mdl);
    if (x) {
        func_001dddd0(o->m192, x);
        func_001a9560(o->mdl, o, o->m192, o->w220);
    }
    m->count++;
}
}  // namespace n0023da00

// 0023dd28 (was src/anon/batch_w87.cpp)
namespace n0023dd28 {
// 0x002378c8: definition moved into src/anon/unit_00237068.cpp

// ---- 0x23dd28 ----
void func_00106d40(void*, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32) asm("func_00106d40");
void func_00106de8(void*, s32, f32) asm("func_00106de8");
void func_00106c08(void*) asm("func_00106c08");
/*TARGET 0023dd28*/
void func_0023dd28(u8* p, s32 i, s32 x, s32 y) asm("func_0023dd28");
void func_0023dd28(u8* p, s32 i, s32 x, s32 y) {
    u8* o = p + i * 400 + 32;
    func_00106d40(o, 512.0f, 0.7999999523162842f, 0.8666666150093079f, (f32)(x + 2048), (f32)(y + 2048), 1.0f, 16770000.0f, 1.0f, 4000000.0f, 256.0f, 208.0f);
    func_00106de8(o, 0, 0.6981316804885864f);
    func_00106c08(o);
}
}  // namespace n0023dd28

// 0023de00 (was src/anon/batch_w1705_nsa.cpp)
namespace n0023de00 {
// 0023de00: per-frame update of the owner's animated props (idle/action motion cycling + matrix build).
// Needs -fno-strict-aliasing (state/time stores stay before the vtable-pointer reloads).

struct W1705Vec { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W1705Mtx { W1705Vec r[4]; };
struct W1705Motion {
    virtual void v0();
    virtual void v1();
    virtual s32 GetEnd();      // +0x08
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual f32 GetStart();    // +0x1c
};
struct W1705Prop {
    W1705Vec rot;          // 0x00 degrees
    W1705Vec pos;          // 0x10
    W1705Vec scale;        // 0x20
    s32 model;             // 0x30
    u8 pad34[0x74 - 0x34];
    W1705Motion* idle;     // 0x74
    W1705Motion* act1;     // 0x78
    W1705Motion* act2;     // 0x7c
    W1705Mtx mtx;          // 0x80
    u8 padC0[0x128 - 0xc0];
    s32 state;             // 0x128
    f32 time;              // 0x12c
    f32 wait;              // 0x130
    f32 waitMax;           // 0x134
    u8 pad138[4];
    u8 active;             // 0x13c
    u8 pad13d[3];

};
struct W1705Owner {
    u8 pad0[0x660];
    W1705Prop props[4];         // 0x660
    u8 padB5C[0xb64 - (0x660 + 4 * 0x140)];
    u8 propIdx[8];              // 0xb64
    s32 count;                  // 0xb6c
    u8 padB70[0x14b0 - 0xb70];
    s32 handleA[4];             // 0x14b0
    s32 handleB[4];             // 0x14c0
};
s32 func_001064a8(s32) asm("func_001064a8");
void func_0011b6a8(W1705Mtx*) asm("func_0011b6a8");
void func_0011b7b0(W1705Mtx*, W1705Vec*) asm("func_0011b7b0");
void func_0011c4e8(f32, s32, W1705Mtx*, W1705Motion*, s32, s32, s32) asm("func_0011c4e8");
void func_0011ea40(f32, s32) asm("func_0011ea40");
u8 u_call4_00139d78(s32) asm("_Z16u_call4_00139d78jjjj");
f32 func_0014ce78(void) asm("func_0014ce78");
void func_0023d820(W1705Owner*) asm("func_0023d820");
f32 func_0023e700(W1705Owner*) asm("func_0023e700");
/*TARGET 0023de00*/
void func_0023de00(W1705Owner* o) asm("func_0023de00");
void func_0023de00(W1705Owner* o)
{
    s32 i;
    for (i = 0; i < o->count; i++) {
        W1705Prop* p = &o->props[o->propIdx[i]];
        if ((o->handleA[i] && !u_call4_00139d78(o->handleA[i])) ||
            (o->handleB[i] && !u_call4_00139d78(o->handleB[i]))) {
            func_0023d820(o);
            return;
        }
        if (p->active) {
            f32 dt = func_0014ce78();
            W1705Motion* m;
            switch (p->state) {
            case 0: m = p->idle; break;
            case 1: m = p->act1; break;
            case 2: m = p->act2; break;
            default: m = p->idle; break;
            }
            p->time += dt;
            if (p->state == 0) {
                p->wait += dt;
                if (p->wait >= p->waitMax && p->act1) {
                    p->state = func_001064a8(2) + 1;
                    if (p->state == 2 && !p->act2) p->state = 1;
                    p->time = p->idle->GetStart();
                } else if ((f32)p->idle->GetEnd() < p->time) {
                    p->time = p->time - (f32)p->idle->GetEnd();
                }
                if (p->time < p->idle->GetStart()) p->time = p->time + p->idle->GetStart();
            } else if ((s32)p->time > m->GetEnd()) {
                p->state = 0;
                p->time = p->idle->GetStart();
                p->wait = p->idle->GetStart();
                p->waitMax = func_0023e700(o);
            }
            switch (p->state) {
            case 0: m = p->idle; break;
            case 1: m = p->act1; break;
            case 2: m = p->act2; break;
            default: m = p->idle; break;
            }
            W1705Mtx* mtx = &p->mtx;
            func_0011b6a8(mtx);
            W1705Vec r;
            asm volatile("sqc2 $vf0, 0(%0)" : : "r"(&r) : "memory");
            r.x = p->rot.x * 0.017453292f;
            r.y = p->rot.y * 0.017453292f;
            r.z = p->rot.z * 0.017453292f;
            func_0011b7b0(mtx, &r);
            asm volatile("lqc2 $vf1, 48(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 48(%0)"
                         : : "r"(mtx), "r"(&p->pos) : "memory");
            asm volatile("lqc2 $vf4, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\t"
                         "vmulx.wxyz $vf1, $vf1, $vf4x\n\tvmuly.wxyz $vf2, $vf2, $vf4y\n\tvmulz.wxyz $vf3, $vf3, $vf4z\n\t"
                         "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)"
                         : : "r"(mtx), "r"(&p->scale) : "memory");
            func_0011c4e8(p->time, p->model, mtx, m, 0, 0, 0);
            func_0011ea40(dt, p->model);
        }
    }
}
}  // namespace n0023de00

