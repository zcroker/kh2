// Linked unit 0x00169f98-0x0016c770.
#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../yasui/libys/obj.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "tiny_auto80_solver_structs.hpp"

// 00169f98 (was src/anon/auto80_199_queue.cpp)
namespace n00169f98 {
/*TARGET 00169f98*/
void func_00169f98(u8* a0) asm("_Z13func_00169f98Ph");
void func_00169f98(u8* a0) {
    if ((*(u32*)(a0 + 1416) & 0x20u) == 0) {
        u32 t2 = func_00168b38(*(u32*)(a0 + 1964), 3, 0);  // entry_array_find_nth
        D_004f6284 = t2;
        if (t2 != 0) {
            u32 t5 = *(u32*)(t2 + 8);
            if (t5 != 0) {
                func_0016a158((u32)a0, t5);
            }
        }
    }

    kn::FVector* t6 = (kn::FVector*)(a0 + 2192);
    kn::FVector* t7 = (kn::FVector*)(a0 + 1344);
    if (t6 != t7) {
        *t6 = *t7;
    }

    u32 t7v = *(u32*)(a0 + 2040);
    f32 f0 = *(f32*)(a0 + 1372);
    *(f32*)(a0 + 2204) = f0;
    *(u32*)(a0 + 2040) = t7v | 0x80u;
}
}  // namespace n00169f98

// 0016a020 (was src/yasui/libys/obj.cpp)
namespace n0016a020 { // method (was YS::OBJ::get_entry_id)
/*TARGET 0016a020*/
u32 OBJ_get_entry_id(void* self) asm("_ZN2YS3OBJ12get_entry_idEv");
u32 OBJ_get_entry_id(void* self) {
    u32 p = *(u32*)((u32)self + 8);
    return *(u32*)((u32)p + 0);
}
}

// 0016a030 (was unwritten gap)
namespace n0016a030 {
u32 func_0016a030(u8* o) asm("func_0016a030");
u32 func_0016a030(u8* o) { return *(u32*)(o + 8) + 8; }
}  // namespace

// 0016a040 (was src/yasui/libys/obj.cpp)
namespace n0016a040 { // method (was YS::OBJ::get_type)
/*TARGET 0016a040*/
// 0x0019c410: definition moved into src/anon/unit_0019ba60.cpp

u32 OBJ_get_type(void* self) asm("_ZN2YS3OBJ8get_typeEv");
u32 OBJ_get_type(void* self) {
    u32 flags = *(u32*)((u32)self + 1416);
    flags &= 0x80u;
    u32 r = 0;
    if (flags == 0u) {
        u32 p = *(u32*)((u32)self + 8);
        r = *(u8*)((u32)p + 4);
    }
    return r;
}
}

// 0016a060 (was src/yasui/libys/obj.cpp)
namespace n0016a060 { // method (was YS::OBJ::get_sub_type)
/*TARGET 0016a060*/
u32 OBJ_get_sub_type(void* self) asm("_ZN2YS3OBJ12get_sub_typeEv");
u32 OBJ_get_sub_type(void* self) {
    u32 p = *(u32*)((u32)self + 8);
    return *(u8*)((u32)p + 5);
}
}

// 0016a070 (was src/yasui/libys/obj.cpp)
namespace n0016a070 { // method (was YS::OBJ::get_part_num)
/*TARGET 0016a070*/
u32 OBJ_get_part_num(void* self) asm("_ZN2YS3OBJ12get_part_numEv");
u32 OBJ_get_part_num(void* self) {
    u32 p = *(u32*)((u32)self + 8);
    return (u32)(*(u16*)((u32)p + 76));
}
}

// 0016a080 (was src/yasui/libys/obj.cpp)
namespace n0016a080 { // method (was YS::OBJ::get_skeleton_num)
/*TARGET 0016a080*/
u32 OBJ_get_skeleton_num(void* self) asm("_ZN2YS3OBJ16get_skeleton_numEv");
u32 OBJ_get_skeleton_num(void* self) {
    u32 p = *(u32*)((u32)self + 8);
    return *(u8*)((u32)p + 7);
}
}

// 0016a090 (was src/anon/tiny_more.cpp)
namespace n0016a090 {
/*TARGET 0016a090*/
// 0x00143318: definition moved into src/anon/unit_00142c90.cpp

u32 func_0016a090(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_0016a090jjjj");
// 0x00143318: definition moved into src/anon/unit_00142c90.cpp

u32 func_0016a090(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a1; (void)a2; (void)a3; u32 p = *(u32*)((u32)a0 + (8)); return *(u8*)((u32)p + (74)); }
}  // namespace n0016a090

// 0016a0a0 (was src/anon/auto200_999.cpp)
namespace n0016a0a0 {
extern f32 D_0036c1a0 asm("D_0036c1a0");
/*TARGET 0016a0a0*/
// 0x001bf140: definition moved into src/anon/unit_001bc568.cpp

f32 func_0016a0a0(u32 a0) asm("_Z13func_0016a0a0j");
// 0x001bf140: definition moved into src/anon/unit_001bc568.cpp

f32 func_0016a0a0(u32 a0) {
    u32 p = (u32)&D_0036c1a0;
    asm volatile("" : "+r"(p));
    f32 ret = *(f32 *)p;
    asm volatile("" : "+f"(ret));
    if ((*(u32 *)(a0 + 356) & 2) == 0) {
        u32 obj = *(u32 *)(a0 + 8);
        ret = *(f32 *)(obj + 80);
    }
    return ret;
}
}  // namespace n0016a0a0

// 0016a0d0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0016a0d0 {
// count_div4_compare


extern "C" u32 func_00168b38(...) asm("func_00168b38");
/*TARGET 0016a0d0*/
// entry_array_find_nth

u32 func_0016a0d0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0016a0d0jjjjjjjj");
// entry_array_find_nth

u32 func_0016a0d0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r5 = (u32)((s32)0u + (4));
    r6 = 0u;
    r4 = *(u32*)((u32)r4 + (s32)(1964));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00168b38)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = 0u;
    if (r2 != 0u) {
        r15 = *(u32*)((u32)r2 + (s32)(8));
    }
    r2 = r15;
    return r2;
}
}  // namespace n0016a0d0

// 0016a108 (was src/anon/tiny_auto80_queue.cpp)
namespace n0016a108 {
u32 func_00168b38(...) asm("func_00168b38");
/*TARGET 0016a108*/
// entry_array_find_nth

u32 func_0016a108(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0016a108jjjjjjjj");
// entry_array_find_nth

u32 func_0016a108(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r5 = (u32)((s32)0u + (7));
    r6 = 0u;
    r4 = *(u32*)((u32)r4 + (s32)(1964));
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_00168b38)(r4, r5, r6, r7, r8, r9, r10, r11);
    r15 = 0u;
    if (r2 != 0u) {
        r15 = *(u32*)((u32)r2 + (s32)(8));
    }
    r2 = r15;
    return r2;
}
}  // namespace n0016a108

// 0016a140 (was src/anon/tiny_wrappers_more.cpp)
namespace n0016a140 {
u32 func_00180828(u32, u32, u32, u32) asm("_Z13func_00180828jjjj");
/*TARGET 0016a140*/
// 0x00167288: definition moved into src/anon/unit_001664c0.cpp

// 001681d8: moved to src/anon/unit_00167358.cpp

// 001688c8: moved to src/yasui/libys/file.cpp

// 00168a80: _GLOBAL__I_ stub, now made by gcc in src/yasui/libys/file.cpp

u32 func_0016a140(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0016a140jjjj");
// 0x00167288: definition moved into src/anon/unit_001664c0.cpp

// 001681d8: moved to src/anon/unit_00167358.cpp

// 001688c8: moved to src/yasui/libys/file.cpp

// 00168a80: _GLOBAL__I_ stub, now made by gcc in src/yasui/libys/file.cpp

u32 func_0016a140(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00180828(((u32)(a0) + 320u), a1, a2, a3);
}
}  // namespace n0016a140

// 0016a158 (was src/anon/batch_w42.cpp)
namespace n0016a158 {
void vm_call(u32, s32, void*, s32) asm("_ZN2YS2VM4callEiP8BD_VALUEi");
void vm_callback(u32, s32, void*, s32, void*) asm("_ZN2YS2VM8callbackEiP8BD_VALUEiPS0_");
u32 vm_start(void*, void*) asm("_ZN2YS2VM5StartEPvPNS_3OBJE");
/*TARGET 0016a158*/
// strlen
// 00168958: moved to src/yasui/libys/file.cpp

// 0016a158: start a script VM for this object and run its entry
void func_0016a158(u8* self, void* code) asm("func_0016a158");
// strlen
// 00168958: moved to src/yasui/libys/file.cpp

// 0016a158: start a script VM for this object and run its entry
void func_0016a158(u8* self, void* code)
{
    u32 vm = vm_start(code, self);
    *(u32*)(self + 1156) = vm;
    u32 arg = (u32)self;
    vm_callback(vm, 0, &arg, 1, 0);
    vm_call(*(u32*)(self + 1156), 1, 0, 0);
}
}  // namespace n0016a158

// 0016a1b8 (was src/anon/batch_w80.cpp)
namespace n0016a1b8 {
struct U0_Info { u8 pad[4]; u8 f4; u8 pad2[9]; s16 f14; s16 f16; s16 f18; };
union U0_FU { f32 f; s16 s; };
struct U0_Chr {
    u8 pad0[1296]; u32 f1296;
    u8 pad1[1456 - 1300]; U0_FU f1456, f1460, f1464;
    u8 pad2[1532 - 1468]; U0_FU f1532;
    u64 b0:1; u64 b1:2; u64 rest:61;
    u8 pad3[1636 - 1544]; U0_Info* f1636; U0_Info* f1640;
    u8 pad4[2040 - 1644]; u32 f2040;
    u8 pad5[2088 - 2044]; u32 f2088;
    u8 pad6[2264 - 2092]; u32 id;
};
U0_Info* func_0018a1b8(u32, u32, U0_Info*) asm("func_0018a1b8");
// find_byte1_entry
u32 func_001b7850(U0_Chr*, u32, u32) asm("func_001b7850");
/*TARGET 0016a1b8*/
// 0x00165768: definition moved into src/anon/unit_001656b8.cpp
void func_0016a1b8(U0_Chr* c, u32 id) asm("func_0016a1b8");
// 0x00165768: definition moved into src/anon/unit_001656b8.cpp
void func_0016a1b8(U0_Chr* c, u32 id) {
    U0_Info* v;
    c->id = id;
    v = func_0018a1b8(id, 17, 0);  // find_byte1_entry
    if (v) {
        c->f1456.f = c->f1464.f = (f32)v->f16;
        c->f1460.f = (f32)v->f18;
        c->f1532.f = (f32)v->f14;
        c->b1 = v->f4 != 0;
        c->f2040 |= 1;
        v = func_0018a1b8(c->id, 17, v);  // find_byte1_entry
        if (v) {
            c->f1636 = v;
            c->f1640 = func_0018a1b8(c->id, 17, v);  // find_byte1_entry
        }
    }
    c->f2088 = func_001b7850(c, c->id, 1);
    c->f1296 = func_001b7850(c, c->id, 2);
}
}  // namespace n0016a1b8

// 0016a2b0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0016a2b0 {
/*TARGET 0016a2b0*/
// 00168a30: moved to src/yasui/libys/file.cpp

void func_0016a2b0(u32 a0) asm("_Z13func_0016a2b0j");
// 00168a30: moved to src/yasui/libys/file.cpp

void func_0016a2b0(u32 a0) {  // clear_15_words_at1976
    u32 t7 = (u32)((s32)0u + (15));
    a0 = (u32)((s32)a0 + (1976));
    do {
        *(u32*)((u32)a0 + (s32)(0)) = 0u;
        t7 = (u32)((s32)t7 + (-1));
        a0 = (u32)((s32)a0 + (4));
    } while ((s32)t7 >= 0);
}
}  // namespace n0016a2b0

// 0016a2e0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0016a2e0 {
/*TARGET 0016a2e0*/
void func_0016a2e0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0016a2e0jjjjjjjj");
void func_0016a2e0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 t7 = *(u32*)((u32)a0 + (s32)(2040));
    t7 = (u32)(t7 & 0x0040u);
    u32 s0 = a0;
    if (t7 == 0u) {
        u32 obj = *(u32*)((u32)a0 + (s32)(0));
        u32 fn = *(u32*)((u32)obj + (s32)(28));
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))fn)(a0,a1,a2,a3,a4,a5,a6,a7);
        t7 = *(u32*)((u32)s0 + (s32)(2040));
        t7 = (u32)(t7 | 0x0040u);
        *(u32*)((u32)s0 + (s32)(2040)) = t7;
    }
}
}  // namespace n0016a2e0

// 0016a328 (was src/anon/batch_w7.cpp)
namespace n0016a328 {
void func_001a9350(u32) asm("func_001a9350");
void func_0016c358(u32) asm("func_0016c358");
/*TARGET 0016a328*/
// 0x0013b1a0: definition moved into src/anon/unit_0013a8b8.cpp

// 001586b8: moved to src/harata/libdk/cannoncamera.cpp

void YS__OBJ___OVR__destroy(u32 a0) asm("YS__OBJ___OVR__destroy");
// 0x0013b1a0: definition moved into src/anon/unit_0013a8b8.cpp

// 001586b8: moved to src/harata/libdk/cannoncamera.cpp

void YS__OBJ___OVR__destroy(u32 a0) {
    func_001a9350(a0 + 1952);
    func_0016c358(a0);
}
}  // namespace n0016a328

// 0016a358 (was src/anon/batch_w82.cpp)
namespace n0016a358 {
// Disables sibling-call optimisation where the original keeps jal + epilogue.
struct NoTail82 { ~NoTail82() {} };
extern u8 D_0034d850[] asm("D_0034d850");
void YS__SHEET__Free(u32) asm("YS__SHEET__Free");
void func_001b78b8(u32) asm("func_001b78b8");
// to_105110
void func_002cb708(u32) asm("func_002cb708");
void func_00105110(u32) asm("func_00105110");
void func_001b3098(void*) asm("func_001b3098");
void func_001a9350(void*) asm("func_001a9350");
void func_001a6d68(void*) asm("func_001a6d68");
void func_00187b90(void*) asm("func_00187b90");
void func_0017eb98(void*) asm("func_0017eb98");
void func_001ddd88(void*) asm("func_001ddd88");
// 0017a9e8: moved to src/anon/unit_0017a8f8.cpp

// 0017cd20: moved to src/anon/unit_0017c400.cpp

// 0017e418: moved to src/yasui/libys/friend.cpp

// 00178bf0: moved to src/yasui/libys/player.cpp

void u_call4_0016a358(u32, u32, u32, u32) asm("_Z16u_call4_0016a358jjjj");
/*TARGET 0016a358*/
void u_call4_0016a358(u32 a0, u32, u32, u32) asm("_Z16u_call4_0016a358jjjj");
void u_call4_0016a358(u32 a0, u32, u32, u32)
{
    NoTail82 nt;
    u8* o = (u8*)a0;
    u32 p;
    *(u32*)o = (u32)D_0034d850;
    if (*(u32*)(o + 1164)) YS__SHEET__Free(*(u32*)(o + 1164));
    if (*(u32*)(o + 2088)) func_001b78b8(*(u32*)(o + 2088));  // to_105110
    if (*(u32*)(o + 1296)) func_001b78b8(*(u32*)(o + 1296));  // to_105110
    p = *(u32*)(o + 1288);
    if (p) {
        func_002cb708(p);
        func_00105110(p);
    }
    func_001b3098(o + 2048);
    func_001a9350(o + 1952);
    func_001a6d68(o + 1280);
    func_00187b90(o + 768);
    func_0017eb98(o + 320);
    func_001ddd88(o + 156);
    func_001ddd88(o + 128);
}
}  // namespace n0016a358

// 0016a420 (was src/anon/batch_w83.cpp)
namespace n0016a420 {
// Local with a non-trivial destructor: keeps the final call a jal.
struct NoTail { ~NoTail() {} };
extern u32 D_0034d850[] asm("D_0034d850");
void YS__SHEET__Free(void*) asm("YS__SHEET__Free");
void func_001b78b8(void*) asm("func_001b78b8");
// to_105110
void func_002cb708(void*) asm("func_002cb708");
void func_00105110(void*) asm("func_00105110");
void func_001b3098(void*) asm("func_001b3098");
void func_001a9350(void*) asm("func_001a9350");
void func_001a6d68(void*) asm("func_001a6d68");
void func_00187b90(void*) asm("func_00187b90");
void func_0017eb98(void*) asm("func_0017eb98");
void func_001ddd88(void*) asm("func_001ddd88");
/*TARGET 0016a420*/
// Destructor body: reset vtable, release owned objects and members.
void func_0016a420(u8* p) asm("func_0016a420");
// Destructor body: reset vtable, release owned objects and members.
void func_0016a420(u8* p) {
    NoTail nt;
    *(u32*)p = (u32)D_0034d850;
    if (*(void**)(p + 1164)) YS__SHEET__Free(*(void**)(p + 1164));
    if (*(void**)(p + 2088)) func_001b78b8(*(void**)(p + 2088));  // to_105110
    if (*(void**)(p + 1296)) func_001b78b8(*(void**)(p + 1296));  // to_105110
    void* s = *(void**)(p + 1288);
    if (s) {
        func_002cb708(s);
        func_00105110(s);
    }
    func_001b3098(p + 2048);
    func_001a9350(p + 1952);
    func_001a6d68(p + 1280);
    func_00187b90(p + 768);
    func_0017eb98(p + 320);
    func_001ddd88(p + 156);
    func_001ddd88(p + 128);
}
}  // namespace n0016a420

// 0016a4e8 (was src/anon/batch_w81.cpp)
namespace n0016a4e8 {
// 0x00165a10: definition moved into src/anon/unit_001656b8.cpp

// --- 0016a4e8: deleting destructor
extern u8 D_0034d850[] asm("D_0034d850");
void YS__SHEET__Free(u32) asm("YS__SHEET__Free");
void func_001b78b8(u32) asm("func_001b78b8");
// to_105110
void func_002cb708(u32) asm("func_002cb708");
void func_00105110(u32) asm("func_00105110");
void func_001b3098(u8*) asm("func_001b3098");
void func_001a9350(u8*) asm("func_001a9350");
void func_001a6d68(u8*) asm("func_001a6d68");
void func_00187b90(u8*) asm("func_00187b90");
void func_0017eb98(u8*) asm("func_0017eb98");
void func_001ddd88(u8*) asm("func_001ddd88");
/*TARGET 0016a4e8*/
void func_0016a4e8(u8* o) asm("func_0016a4e8");
void func_0016a4e8(u8* o) {
    *(u8**)o = D_0034d850;
    if (*(u32*)(o + 1164)) YS__SHEET__Free(*(u32*)(o + 1164));
    if (*(u32*)(o + 2088)) func_001b78b8(*(u32*)(o + 2088));  // to_105110
    if (*(u32*)(o + 1296)) func_001b78b8(*(u32*)(o + 1296));  // to_105110
    u32 p = *(u32*)(o + 1288);
    if (p) { func_002cb708(p); func_00105110(p); }
    func_001b3098(o + 2048);
    func_001a9350(o + 1952);
    func_001a6d68(o + 1280);
    func_00187b90(o + 768);
    func_0017eb98(o + 320);
    func_001ddd88(o + 156);
    func_001ddd88(o + 128);
    func_00105110((u32)o);
}
}  // namespace n0016a4e8

// 0016a5b0 (was src/anon/batch_w1637.cpp)
namespace n0016a5b0 {
#define W1637_QCOPY4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct W1637Vec {
    f32 x, y, z, w;
    W1637Vec() {}
    W1637Vec(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    void Set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    void Zero() { asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(this) : "memory"); }
    W1637Vec operator-(const W1637Vec& b) const {
        W1637Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1637Vec(const W1637Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1637Vec& operator=(const W1637Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1637Mtx {
    W1637Vec r[4];
    W1637Mtx() {}
    W1637Mtx(const W1637Mtx& o) { W1637_QCOPY4(this, &o); }
    W1637Mtx& operator=(const W1637Mtx& o) { if (this != &o) W1637_QCOPY4(this, &o); return *this; }
    W1637Vec operator*(const W1637Vec& v) const {
        W1637Vec o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    void Inverse() {
        asm volatile(
            "lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t"
            "vopmula.xyz ACC, $vf2, $vf3\n\tvopmsub.xyz $vf5, $vf3, $vf2\n\t"
            "vopmula.xyz ACC, $vf3, $vf1\n\tvopmsub.xyz $vf6, $vf1, $vf3\n\t"
            "vopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf7, $vf2, $vf1\n\t"
            "vmul.xyz $vf8, $vf1, $vf5\n\tvmul.xyz $vf1, $vf4, $vf5\n\tvmul.xyz $vf2, $vf4, $vf6\n\tvmul.xyz $vf3, $vf4, $vf7\n\t"
            "vaddy.x $vf8, $vf8, $vf8y\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddx.y $vf2, $vf2, $vf2x\n\tvaddx.z $vf3, $vf3, $vf3x\n\t"
            "vaddz.x $vf8, $vf8, $vf8z\n\tvaddz.x $vf4, $vf1, $vf1z\n\tvaddz.y $vf4, $vf2, $vf2z\n\tvaddy.z $vf4, $vf3, $vf3y\n\t"
            "vdiv Q, $vf0w, $vf8x\n\t"
            "qmfc2 $8, $vf5\n\tqmfc2 $9, $vf6\n\tqmfc2 $10, $vf7\n\tqmfc2 $11, $vf0\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vsub.xyz $vf4, $vf0, $vf4\n\tvwaitq\n\t"
            "vmulq.xyzw $vf1, $vf1, Q\n\tvmulq.xyzw $vf2, $vf2, Q\n\tvmulq.xyzw $vf3, $vf3, Q\n\tvmulq.xyz $vf4, $vf4, Q\n\t"
            "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)\n\tsqc2 $vf4, 48(%0)"
            : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    W1637Mtx operator*(const W1637Mtx& b) const {
        W1637Mtx o;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct W1637Pad16 { u8 p[16]; };
struct W1637Cam : W1637Pad16, W1637Mtx {};
struct W1637Ent { u8 p0[8]; u32 f8; };
struct W1637Obj2 {
    u8 p0[0xc];
    W1637Ent* ent;          // 0x00c
    W1637Vec v010;          // 0x010
    W1637Vec v020;          // 0x020
    u8 p030[0xd8];
    u32 f108;               // 0x108
    u8 p10c[0x54];
    u32 f160;               // 0x160
    u8 p164[0x3fc];
    W1637Vec v560;          // 0x560
    W1637Obj2* f570; u8 p574[2]; u16 h576;   // 0x570
    u8 p578[0x438];
    f32 f9b0;               // 0x9b0
};
static inline bool W1637_Flag12(u32 f) { return (f & 1) || (f & 2); }
static inline bool W1637_Bit(u32 f, u32 m) { return (f & m) != 0; }
static inline bool W1637_Flag4(u32 f) { return W1637_Bit(f, 4) || W1637_Bit(f, 8) || W1637_Bit(f, 0x10); }
static inline bool W1637_Flag20(u32 f) { return W1637_Bit(f, 0x20) || W1637_Bit(f, 0x1000000); }
extern f32 D_00349e10 asm("D_00349e10");
extern W1637Mtx D_003511d0 asm("D_003511d0");
s32 W1637_is_attach(W1637Obj2*) asm("_ZN2YS3OBJ9is_attachEv");
void W1637_detach(W1637Obj2*) asm("_ZN2YS3OBJ6detachEv");
s32 W1637_ctarget_0019ba60(W1637Obj2*) asm("_Z17YS__OBJ__is_existjjjj");
W1637Vec* W1637_get_pos(W1637Obj2*) asm("YS__OBJ__get_pos");
W1637Cam* func_00106a60(s32) asm("func_00106a60");
/*TARGET 0016a5b0*/
void YS__OBJ___OVR_pre_exec(W1637Obj2* o) asm("YS__OBJ___OVR_pre_exec");
void YS__OBJ___OVR_pre_exec(W1637Obj2* o)
{
    if (o->f160 & 0x40) {
        if (!(o->f108 & 0x1000000)) {
            if (!W1637_Flag12(o->ent->f8)) o->v020.Zero();
            o->f108 |= 0x1000000;
        }
        o->f108 &= ~0x800000;
    } else if (W1637_Flag20(o->f160)) {
        o->f108 |= 0x800000;
        o->f108 &= ~0x1000000;
    } else {
        o->f108 &= ~0x800000;
        o->f108 &= ~0x1000000;
    }
    if (W1637_is_attach(o) && (o->h576 & 1)) {
        if (!W1637_ctarget_0019ba60(o->f570) || !(o->f570->f160 & 0x8000)) W1637_detach(o);
    }
    if (o->f9b0 > 0.0f) {
        if (!W1637_Flag4(o->f160)) o->f9b0 = 0.0f;
        else o->f9b0 -= D_00349e10;
    }
    o->v010.Zero();
    if (o->f108 & 0x10) {
        W1637Vec pos = *W1637_get_pos(o);
        pos.w = 1.0f;
        pos = D_003511d0 * pos;
        pos.w = 1.0f;
        W1637Mtx inv = *func_00106a60(1);
        inv.Inverse();
        pos = inv * pos;
        o->v560 = pos - *W1637_get_pos(o);
    } else {
        o->v560.Zero();
    }
}
}  // namespace n0016a5b0

// 0016a950 (was src/anon/tiny_auto80_queue.cpp)
namespace n0016a950 {
u32 YS__VM__exec(...) asm("YS__VM__exec");
u32 YS__ACT__exec(...) asm("YS__ACT__exec");
/*TARGET 0016a950*/
void func_0016a950(u32 a0) asm("_Z13func_0016a950j");
void func_0016a950(u32 a0) {
    u32 s0 = a0;
    u32 p = *(u32*)((u32)a0 + (s32)(1156));
    if (p != 0u) {
        if (YS__VM__exec(p, 0u) == 0u) {
            YS__ACT__exec((u32)((s32)s0 + (768)));
            return;
        }
    }
}
}  // namespace n0016a950

// 0016a9a0 (was src/anon/tiny_wrappers_more.cpp)
namespace n0016a9a0 {
u32 func_0016a950(u32, u32, u32, u32) asm("_Z13func_0016a950jjjj");
/*TARGET 0016a9a0*/
u32 func_0016a9a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0016a9a0jjjj");
u32 func_0016a9a0(u32 a0, u32 a1, u32 a2, u32 a3) {  // to_16a950
    return func_0016a950(a0, a1, a2, a3);
}
}  // namespace n0016a9a0

// 0016a9b8 (was src/anon/batch_w2044_nsa.cpp)
namespace n0016a9b8 {
struct W2044Obj;
struct W2044PVt { u8 pad[16]; void (*f16)(struct W2044P*, W2044Obj*); u8 pad2[4]; void (*f24)(struct W2044P*, W2044Obj*); };
struct W2044P { W2044PVt* vt; u8 pad[4]; u32 flags; };
struct W2044OVt { u8 pad[44]; void (*f44)(W2044Obj*); };
struct W2044Q { u8 pad[72]; u16 b0:5; u16 bit:1; };
struct W2044V4 { f32 x, y, z, w;
  W2044V4& operator=(const W2044V4& o) { if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" :: "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct W2044Obj {
  W2044OVt* vt; u8 pad4[4]; W2044Q* q; W2044P* p;   // 0..16
  u8 pad16[16];
  W2044V4 v32;                 // 32
  u8 pad48[208-48];
  f32 f208; s32 f212; f32 f216; union { f32 f; s32 i; } f220; // 208..224
  u8 pad224[264-224];
  u32 f264; // 264
  u8 pad268[284-268];
  f32 f284;
  u8 pad288[352-288];
  u32 f352;
  u8 pad356[496-356];
  W2044V4 v496;
  u8 pad512[1184-512];
  u8 sub1184[1288-1184];
  void* p1288;
  u8 pad1292[1348-1292];
  f32 f1348;
  u8 pad1352[1372-1352];
  f32 f1372;
  u8 pad1376[1644-1376];
  f32 f1644;
  u8 pad1648[2144-1648];
  W2044V4 v2144;
};
s32 func_001c0cd8(W2044Obj*) asm("func_001c0cd8");
s32 func_0019c400(W2044Obj*) asm("func_0019c400");
f32 func_0017ce80(f32, f32, f32) asm("func_0017ce80");
void func_0016ae58(W2044Obj*, f32) asm("func_0016ae58");
void func_002ccf98(void*, W2044Obj*) asm("func_002ccf98");
void func_001b04d8(void*) asm("func_001b04d8");
void func_00194318(W2044Obj*) asm("func_00194318");
extern f32 D_00349e10 asm("D_00349e10");
static inline u32 t264a(W2044Obj* o) { return o->f264 & 0x800000; }
static inline u32 t264b(W2044Obj* o) { return o->f264 & 0x1000000; }
static inline u32 t352a(W2044Obj* o) { return o->f352 & 0x20; }
static inline u32 t352b(W2044Obj* o) { return o->f352 & 0x1000000; }
static inline u32 t352c(W2044Obj* o) { return o->f352 & 0x40; }
static inline u32 tp2(W2044P* p) { return p->flags & 2; }
static inline u32 tp20(W2044P* p) { return p->flags & 0x20; }
static inline bool isA(W2044Obj* o) { return t264a(o) || t264b(o); }
static inline bool isC(W2044Obj* o) { return t352a(o) || t352b(o); }
static inline bool isB(W2044Obj* o) { return isC(o) || t352c(o); }
static inline bool qbit(W2044Obj* o) { return o->q->bit; }
static inline bool notB(W2044Obj* o) { return !isB(o); }
/*TARGET 0016a9b8*/
void func_0016a9b8(W2044Obj* o) asm("func_0016a9b8");
void func_0016a9b8(W2044Obj* o) {
  if (!tp2(o->p) || tp20(o->p)) {
    if (func_001c0cd8(o) == 0 && isA(o) && notB(o)) {
      asm volatile("vsub.xyzw $vf1,$vf0,$vf0\n\tsqc2 $vf1,0(%0)" :: "r"(&o->v496) : "memory");
      o->f264 &= ~0x4000000;
      W2044P* p = o->p;
      p->vt->f16(p, o);
      if (!(o->f264 & 0x4000000)) o->vt->f44(o);
      o->f220.i = 0;
      o->f212 = 0;
      f32 y = o->v2144.y;
      f32 t = (o->f220.f < y) ? y / 0.40816324949264526f : o->f220.f;
      o->f208 = t;
      o->f216 = o->f1348 - t * 0.40816324949264526f * t * 0.5f;
      o->v32 = o->v2144;
    }
  }
  W2044P* p = o->p;
  p->vt->f24(p, o);
  if (func_0019c400(o) == 0) func_0016ae58(o, func_0017ce80(o->f1372, o->f1644, o->f284 * D_00349e10));
  if (o->p1288) func_002ccf98(o->p1288, o);
  func_001b04d8(o->sub1184);
  if (qbit(o)) func_00194318(o);
}
}  // namespace n0016a9b8

// 0016abf8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0016abf8 {
u32 ryj__PAX__start(...) asm("ryj__PAX__start");
/*TARGET 0016abf8*/
// scan_list_by_half

u32 func_0016abf8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0016abf8jjjj");
// scan_list_by_half

u32 func_0016abf8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 t0 = a3;
    a3 = 1u;
    u32 p = *(u32*)((u32)a0 + (s32)(128));
    if (p == 0u) {
        return 0u;
    }
    a0 = (u32)((s32)a0 + (128));
    return ryj__PAX__start(a0, a1, a2, a3, t0, 0u);  // scan_list_by_half
}
}  // namespace n0016abf8

// 0016ac38 (was src/anon/batch_w2362.cpp)
namespace n0016ac38 {
// Effect set embedded in a game object at +0x80; list is non-zero once loaded.
struct EffSet { s32 list; };
struct Obj { u8 pad[0x80]; EffSet eff; };
void* ryj__PAX__start(void*, s32, s32, s32, s32, void*) asm("ryj__PAX__start");
/*TARGET 0016ac38*/
// Starts effect id on the object's effect set; owner defaults to the object itself.
void* func_0016ac38(Obj* o, s32 id, s32 a, s32 b, Obj* owner) asm("func_0016ac38");
// Starts effect id on the object's effect set; owner defaults to the object itself.
void* func_0016ac38(Obj* o, s32 id, s32 a, s32 b, Obj* owner) {
    EffSet* e = &o->eff;
    if (!e->list) return 0;
    if (!owner) owner = o;
    return ryj__PAX__start(e, id, a, 1, b, owner);
}
}  // namespace n0016ac38

// 0016ac80 (was src/anon/batch_w25.cpp)
namespace n0016ac80 {
// 00167b98: moved to src/anon/unit_00167358.cpp

void* func_0016abf8(u32, u32, u32, u32) asm("func_0016abf8");
void* func_001dc5f8(void*) asm("func_001dc5f8");
/*TARGET 0016ac80*/
void* func_0016ac80(u32 a, u32 b, void* src, u32 c, u32 d) asm("func_0016ac80");
void* func_0016ac80(u32 a, u32 b, void* src, u32 c, u32 d) {
    void* r = func_0016abf8(a, b, c, d);
    if (r) {
        void* dst = func_001dc5f8(r);
        if (dst != src)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(dst), "r"(src) : "$8", "memory");
    }
    return r;
}
}  // namespace n0016ac80

// 0016ace0 (was src/anon/batch_w1757.cpp)
namespace n0016ace0 {
#define QCOPY1757(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1757Vec {
    f32 x, y, z, w;
    W1757Vec& operator=(const W1757Vec& o) {
        if (this != &o) QCOPY1757(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct W1757Obj {
    u8 pad[0x540];
    W1757Vec pos;
};
void YS__OBJ__is_valid(void*) asm("YS__OBJ__is_valid");
void YS__OBJ__make_matrix(void*) asm("YS__OBJ__make_matrix");
void W1757_set_pos(W1757Obj* self, const W1757Vec& v) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
/*TARGET 0016ace0*/
void W1757_set_pos(W1757Obj* self, const W1757Vec& v) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
void W1757_set_pos(W1757Obj* self, const W1757Vec& v) {
    YS__OBJ__is_valid(self);
    self->pos = v;
    self->pos.w = 1.0f;
    YS__OBJ__make_matrix(self);
}
}  // namespace n0016ace0

// 0016ad38 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n0016ad38 {
u32 YS_OBJ_set_pos(u32, u32, u32, u32) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
/*TARGET 0016ad38*/
// 0x0015bc50: definition moved into src/anon/unit_0015bab8.cpp

u32 func_0016ad38(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0016ad38jjjj");
// 0x0015bc50: definition moved into src/anon/unit_0015bab8.cpp

u32 func_0016ad38(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r16 = r4;
    r2 = YS_OBJ_set_pos(r4, r5, r6, r7);
    r15 = *(u32*)((u32)r16 + (s32)(2040));
    r15 = (u32)(r15 | 0x1000u);
    *(u32*)((u32)r16 + (s32)(2040)) = r15;
    return r2;
}
}  // namespace n0016ad38

// 0016ad68 (was src/anon/auto80_199_queue.cpp)
namespace n0016ad68 {
/*TARGET 0016ad68*/
u32 func_0016ad68(u32 a0, u32 a1, f32 f12) asm("_Z13func_0016ad68jjf");
u32 func_0016ad68(u32 a0, u32 a1, f32 f12) {
    f32 f20 = f12;
    f32 f0 = func_0016afe0(a1);
    f0 = f0 + f20;
    ((void(*)(u32, f32))func_0016aeb8)(a0, f0);
    return func_0016ad38(a0, YS__OBJ__get_pos(a1));
}
}  // namespace n0016ad68

// 0016adc8 (was src/anon/batch_w52.cpp)
namespace n0016adc8 {
// Worker loop: runs queued jobs forever.
// 001685f0: moved to src/yasui/libys/file.cpp

void func_0016ace0(u8*) asm("func_0016ace0");
/*TARGET 0016adc8*/
void func_0016adc8(u8* p) asm("func_0016adc8");
void func_0016adc8(u8* p) {
    *(u32*)(p + 264) |= 0x200000;
    func_0016ace0(p);
    if (*(u32*)(p + 1416) & 2) {
        // zero the 128-bit vector at +2768
        asm volatile("vsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(p + 2768) : "memory");
    }
}
}  // namespace n0016adc8

// 0016ae18 (was src/anon/batch_w18.cpp)
namespace n0016ae18 {
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
// 00167b60: moved to src/anon/unit_00167358.cpp

void func_0016adc8(void*, Vec4*) asm("func_0016adc8");
void func_0016aeb8(void*, f32) asm("func_0016aeb8");
/*TARGET 0016ae18*/
void YS__OBJ__reset_first_pos(u8* p) asm("YS__OBJ__reset_first_pos");
void YS__OBJ__reset_first_pos(u8* p) {
    Vec4 v;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&v), "r"(p + 2192) : "$8", "memory");
    func_0016adc8(p, &v);
    func_0016aeb8(p, *(f32*)(p + 2204));
}
}  // namespace n0016ae18

// 0016ae58 (was src/anon/auto80_199_queue.cpp)
namespace n0016ae58 {
/*TARGET 0016ae58*/
f32 func_0016ae58(u8* a0, f32 f12) asm("_Z13func_0016ae58Phf");
f32 func_0016ae58(u8* a0, f32 f12) {
    kn::FVector sp0;
    kn::FVector* s0 = (kn::FVector*)(a0 + 1360);
    u8* s1 = a0;
    f32 f20 = f12;

    func_0019c400((u32)s1);
    func_0017d0e8(&sp0, f20);
    if (s0 != &sp0) {
        *s0 = sp0;
    }

    return *(f32*)(s1 + 1372);
}
}  // namespace n0016ae58

// 0016aeb8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0016aeb8 {
f32 func_0016ae58(u32) asm("_Z13func_0016ae58j");
/*TARGET 0016aeb8*/
void func_0016aeb8(u32 a0) asm("_Z13func_0016aeb8j");
void func_0016aeb8(u32 a0) {
    u32 s0 = a0;
    f32 f0 = func_0016ae58(a0);
    u32 t7 = *(u32*)((u32)s0 + (s32)(2040));
    u32 t6 = (u32)((s32)0u + (-9));
    *(f32*)((u32)s0 + (s32)(1644)) = f0;
    t7 = (u32)(t7 & t6);
    *(u32*)((u32)s0 + (s32)(2040)) = t7;
}
}  // namespace n0016aeb8

// 0016aef0 (was src/anon/auto80_199_queue.cpp)
namespace n0016aef0 {
/*TARGET 0016aef0*/
u32 func_0016aef0(u32 a0, u32 a1) asm("_Z13func_0016aef0jj");
u32 func_0016aef0(u32 a0, u32 a1) {
    if (func_0019c400(a0) != 0) {
        return func_0016b070(a0, a1);
    }

    f32 f0 = func_002f8ad0(*(f32*)(a1 + 0), *(f32*)(a1 + 8));
    return ((u32(*)(u32, f32))func_0016aeb8)(a0, f0);
}
}  // namespace n0016aef0

// 0016af58 (was src/anon/batch_w1545.cpp)
namespace n0016af58 {
struct W1545V4 {
    f32 x, y, z, w;
    W1545V4() {}
    W1545V4(const W1545V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1545V4& operator=(const W1545V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
struct W1545OK { u8 pad[0x60]; f32 x; f32 y; f32 z; u8 p2[1360 - 0x6c]; W1545V4 v; };
s32 func_001c0cd8(u8*) asm("func_001c0cd8");
f32 func_002f8ad0(f32, f32) asm("func_002f8ad0");
void func_0017d0e8(W1545V4*, f32) asm("func_0017d0e8");
/*TARGET 0016af58*/
// 0x00196768: definition moved into src/anon/unit_00195d00.cpp

// Facing vector (struct return): from the angle of -(x, z) when active, else the stored one.
W1545V4 YS__OBJ__get_dir(W1545OK* o) asm("YS__OBJ__get_dir");
// 0x00196768: definition moved into src/anon/unit_00195d00.cpp

// Facing vector (struct return): from the angle of -(x, z) when active, else the stored one.
W1545V4 YS__OBJ__get_dir(W1545OK* o) {  // obj_get_rotation
    if (func_001c0cd8((u8*)o) != 0) {
        f32 z = -o->z;
        f32 x = -o->x;
        f32 f = func_002f8ad0(x, z);
        W1545V4 t;
        func_0017d0e8(&t, f);
        t.w = f;
        return t;
    }
    return o->v;
}
}  // namespace n0016af58

// 0016afe0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0016afe0 {
u32 YS__OBJ__get_dir(...) asm("YS__OBJ__get_dir");
f32 func_002f8ad0(f32, f32) asm("_Z13func_002f8ad0ff");
/*TARGET 0016afe0*/
void func_0016afe0(u32 a0) asm("_Z13func_0016afe0j");
void func_0016afe0(u32 a0) {
    struct {
        f32 f0;
        u32 pad;
        f32 f1;
    } sp;
    YS__OBJ__get_dir((u32)&sp, a0);
    func_002f8ad0(sp.f0, sp.f1);
}
}  // namespace n0016afe0

// 0016b010 (was src/anon/batch_w7.cpp)
namespace n0016b010 {
f32 func_002f8ad0(f32, f32) asm("func_002f8ad0");
/*TARGET 0016b010*/
// Stores f(x, z) of the vector at a1 into +1644 (e.g. a heading angle).
void YS__OBJ__set_wish_dir(u8* a0, f32* a1) asm("YS__OBJ__set_wish_dir");
// Stores f(x, z) of the vector at a1 into +1644 (e.g. a heading angle).
void YS__OBJ__set_wish_dir(u8* a0, f32* a1) {  // obj_set_float1644_from_pair
    *(f32*)(a0 + 1644) = func_002f8ad0(a1[0], a1[2]);
}
}  // namespace n0016b010

// 0016b040 (was src/anon/batch_w8.cpp)
namespace n0016b040 {
// 0x00146680: definition moved into src/anon/unit_00145600.cpp

void func_0017d0e8(f32) asm("func_0017d0e8");
/*TARGET 0016b040*/
void* func_0016b040(void* r, u8* p) asm("func_0016b040");
void* func_0016b040(void* r, u8* p) {
    func_0017d0e8(*(f32*)(p + 1644));
    return r;
}
}  // namespace n0016b040

// 0016b070 (was src/anon/batch_w9.cpp)
namespace n0016b070 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
/*TARGET 0016b070*/
void wtarget_0016b070(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_0016b070jjjj");
void wtarget_0016b070(u32 a0, u32 a1, u32, u32) {
    u8* p = (u8*)a0;
    u8* d = p + 1360;
    if (d != (u8*)a1) QCOPY(d, a1);
    *(f32*)(p + 1372) = *(f32*)(a1 + 4);
    *(u32*)(p + 2040) |= 8;
}
}  // namespace n0016b070

// 0016b0a0 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n0016b0a0 {
u32 YS_OBJ_is_xyzrot(u32, u32, u32, u32) asm("_ZN2YS3OBJ9is_xyzrotEv");
/*TARGET 0016b0a0*/
u32 func_0016b0a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0016b0a0jjjj");
u32 func_0016b0a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r2 = YS_OBJ_is_xyzrot(r4, r5, r6, r7);
    r16 = (u32)((s32)r16 + (1360));
    r2 = r16;
    return r2;
}
}  // namespace n0016b0a0

// 0016b0d0 (was src/yasui/libys/obj.cpp)
namespace n0016b0d0 { // method (was YS::OBJ::GetPlayer)
/*TARGET 0016b0d0*/
u32 OBJ_GetPlayer(void* self) asm("_ZN2YS3OBJ9GetPlayerEv");
u32 OBJ_GetPlayer(void* self) {
    u32 b = (0x0035u << 16);
    return (u32)(*(u32*)((u32)b + (-5816)));
}
}

// 0016b0e0 (was src/anon/batch_w1637b.cpp)
namespace n0016b0e0 {
#define W1637B_QCOPY4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct W1637BVec {
    f32 x, y, z, w;
    W1637BVec() {}
    W1637BVec(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    void Set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1637BVec(const W1637BVec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1637BVec& operator=(const W1637BVec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1637BMtx {
    W1637BVec r[4];
    W1637BMtx() {}
    W1637BMtx(const W1637BMtx& o) { W1637B_QCOPY4(this, &o); }
    W1637BMtx& operator=(const W1637BMtx& o) { if (this != &o) W1637B_QCOPY4(this, &o); return *this; }
    W1637BVec operator*(const W1637BVec& v) const {
        W1637BVec o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    W1637BMtx operator*(const W1637BMtx& b) const {
        W1637BMtx o;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct W1637BMdl3;
typedef s32 (*W1637BMdl3Fn)(W1637BMdl3*, u32);
struct W1637BMdl3 { W1637BMdl3Fn* vt; };
struct W1637BModel { u8 p0[0x8b0]; W1637BMdl3* mdl; };
struct W1637BObj3 {
    u8 p0[0x40];
    W1637BMtx m040;          // 0x040
    u8 p080[0x5f0];
    W1637BModel* model;      // 0x670
    u8 p674[0x3c];
    W1637BMtx m6b0;          // 0x6b0
    u8 p6f0[0x1c0];
    W1637BMdl3* mdl;         // 0x8b0
};
struct W1637BInfo { u8 p0[0xc]; s32 f0c; W1637BVec pos; W1637BInfo() : f0c(0) {} };
W1637BVec* YS__OBJ__get_pos(W1637BObj3*) asm("YS__OBJ__get_pos");
W1637BVec func_0016be98(W1637BObj3*) asm("func_0016be98");
f32 func_0016b518(W1637BObj3*, s32) asm("func_0016b518");
void* func_0016bc20(W1637BObj3*, s32, s32) asm("func_0016bc20");
void YS__COLLISION__set(W1637BInfo*, W1637BObj3*, void*) asm("YS__COLLISION__set");
f32 func_0011d6c0(W1637BModel*, u32, W1637BMtx*) asm("func_0011d6c0");
/*TARGET 0016b0e0*/
f32 YS__OBJ__get_bone_matrix(W1637BObj3* o, u32 id, W1637BMtx* out) asm("YS__OBJ__get_bone_matrix");
f32 YS__OBJ__get_bone_matrix(W1637BObj3* o, u32 id, W1637BMtx* out)
{
    W1637BVec v;
    W1637BInfo info;
    f32 r = 0.0f;
    if (id & 0x4000) {
        switch (id) {
        case 0x4000: {
            *out = o->m040;
            W1637BVec& t = out->r[3];
            t = *YS__OBJ__get_pos(o);
            t.w = 1.0f;
            break;
        }
        case 0x4001: {
            *out = o->m040;
            W1637BVec& t = out->r[3];
            t = func_0016be98(o);
            t.w = 1.0f;
            break;
        }
        case 0x4002:
            *out = o->m6b0;
            break;
        case 0x4003:
        case 0x4004:
            r = func_0016b518(o, (id - 0x4003) & 1);
            v.Set(r, 0.0f, 0.0f, 1.0f);
            out->r[3] = *out * v;
            break;
        case 0x4005:
        case 0x4006:
            func_0016b518(o, (id - 0x4005) & 1);
            r = 0.0f;
            break;
        case 0x4007:
        case 0x4008:
            r = func_0016b518(o, (id - 0x4007) & 1) * 0.5f;
            v.Set(r, 0.0f, 0.0f, 1.0f);
            out->r[3] = *out * v;
            break;
        case 0x4009: {
            void* t;
            *out = o->m040;
            t = func_0016bc20(o, 9, -1);
            if (t) {
                YS__COLLISION__set(&info, o, t);
                out->r[3] = info.pos;
            }
            r = 0.0f;
            break;
        }
        }
    } else {
        if (id & 0x8000) {
            id = o->mdl->vt[6](o->mdl, id & 0xfff);
            if ((s32)id < 0) id = 0;
        }
        r = func_0011d6c0(o->model, id, out);
        *out = o->m6b0 * *out;
    }
    return r;
}
}  // namespace n0016b0e0

// 0016b478 (was src/anon/batch_w52.cpp)
namespace n0016b478 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 {
    f32 x, y, z, w;
} __attribute__((aligned(16)));
f32 YS__OBJ__get_bone_matrix(u32, u32, f32*) asm("YS__OBJ__get_bone_matrix");
#define MULV(m, v, out) asm volatile( \
    "lqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tlqc2 $vf4, 48(%0)\n\t" \
    "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\t" \
    "vmaddw.xyzw $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%2)" : : "r"(m), "r"(v), "r"(out) : "memory")
/*TARGET 0016b478*/
Vec4* func_0016b478(Vec4* out, f32 s, u32 a, u32 b) asm("func_0016b478");
Vec4* func_0016b478(Vec4* out, f32 s, u32 a, u32 b) {
    f32 m[16] __attribute__((aligned(16)));
    Vec4 t;
    f32 f = YS__OBJ__get_bone_matrix(a, b, m);
    out->y = 0.0f;
    out->z = 0.0f;
    out->w = 1.0f;
    out->x = f * s;
    MULV(m, out, &t);
    if (out != &t) QCOPY(out, &t);
    return out;
}
}  // namespace n0016b478

// 0016b518 (was src/anon/batch_w13.cpp)
namespace n0016b518 {
u8 func_00176db0(void*, u32) asm("func_00176db0");
u8 func_0016b558(void*, u32) asm("func_0016b558");
extern void (*D_0035e380[])(void) asm("D_0035e380");
/*TARGET 0016b518*/
// 0x00165ef0: definition moved into src/anon/unit_00165db8.cpp

u8 func_0016b518(u8* p, u32 a1, u32 a2) asm("func_0016b518");
// 0x00165ef0: definition moved into src/anon/unit_00165db8.cpp

u8 func_0016b518(u8* p, u32 a1, u32 a2) {
    if (*(u32*)(p + 1416) & 4) {
        return func_00176db0(p, a1);
    }
    return func_0016b558(p, a2);
}
}  // namespace n0016b518

// 0016b558 (was src/anon/auto80_199_queue.cpp)
namespace n0016b558 {
/*TARGET 0016b558*/
f32 func_0016b558(u32 a0, u32 a1) asm("_Z13func_0016b558jj");
f32 func_0016b558(u32 a0, u32 a1) {
    u32 s2 = a1;
    u32 s1 = a0;
    u8* s0 = func_0016bc20(a0, 15, 0xFFFFFFFFu);
    YS__OBJ__get_bone_matrix(s1, *(u16*)(s0 + 6), s2);
    return (f32)*(s16*)(s0 + 8);
}
}  // namespace n0016b558

// 0016b5b8 (was src/anon/auto80_199_queue.cpp)
namespace n0016b5b8 {
/*TARGET 0016b5b8*/
void func_0016b5b8(u8* a0) asm("_Z13func_0016b5b8Ph");
void func_0016b5b8(u8* a0) {
    u32 t6 = *(u32*)(a0 + 264);
    if ((t6 & 0x10000000u) == 0) {
        u32 t7 = *(u32*)(a0 + 1156);
        if (t7 != 0) {
            YS__ACT__end(a0 + 768);
            func_0016ce90(*(u32*)(a0 + 1156));
        }

        func_00180ce0(a0 + 320);

        u32 t6p = *(u32*)(a0 + 8);
        u32 t7v = *(u8*)(t6p + 84);
        func_001826c8((f32)(-(s32)t7v));
        t6 = *(u32*)(a0 + 264);
    }

    *(u32*)(a0 + 264) = t6 | 0x10000000u;
}
}  // namespace n0016b5b8

// 0016b638 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n0016b638 {
u32 func_0016a950(u32, u32, u32, u32) asm("_Z13func_0016a950jjjj");
/*TARGET 0016b638*/
u32 YS__OBJ___OVR_check_leave(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z25YS__OBJ___OVR_check_leavejjjj");
u32 YS__OBJ___OVR_check_leave(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r2 = func_0016a950(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r16 + (s32)(1160));
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}
}  // namespace n0016b638

// 0016b668 (was src/anon/batch_w86.cpp)
namespace n0016b668 {
struct Obj;
typedef void (*VFn)(Obj*);
struct Obj { VFn* vt; u8 p4[152]; s32 f156; u8 p160[104]; u32 f264; u8 p268[500]; u8 sub768[388]; void* f1156; };
void func_00187b90(void*) asm("func_00187b90");
void func_0016cab8(void*) asm("func_0016cab8");
void func_0016c7d8(void*) asm("func_0016c7d8");
void func_001de450(void*) asm("func_001de450");
void ryj__PAX__ensure(void*) asm("ryj__PAX__ensure");
void func_0016a2b0(Obj*) asm("func_0016a2b0");
// clear_15_words_at1976
s32 func_001c0cd8(Obj*) asm("func_001c0cd8");
void func_001c0e60(Obj*) asm("func_001c0e60");
/*TARGET 0016b668*/
void YS__OBJ___OVR_leave(Obj* o) asm("YS__OBJ___OVR_leave");
void YS__OBJ___OVR_leave(Obj* o)
{
    void* s;
    if (!(o->f264 & 0x10000000)) o->vt[8](o);
    if (o->f1156) {
        func_00187b90(o->sub768);
        s = o->f1156;
        if (s) {
            func_0016cab8(s);
            func_0016c7d8(s);
        }
        o->f1156 = 0;
    }
    if (o->f156) {
        s = &o->f156;
        func_001de450(s);
        ryj__PAX__ensure(s);
        func_0016a2b0(o);  // clear_15_words_at1976
    }
    if (func_001c0cd8(o)) func_001c0e60(o);
    o->f264 |= 0x80000;
    o->f264 &= ~0x10000000;
}
}  // namespace n0016b668

// 0016b740 (was src/anon/batch_w43.cpp)
namespace n0016b740 {
extern u32 D_0034e948 asm("D_0034e948");
u32 func_0016e920(u32) asm("func_0016e920");
u8* YS__OBJ__Each(u8*) asm("YS__OBJ__Each");
/*TARGET 0016b740*/
u32 func_0016b740(u32 id) asm("func_0016b740");
u32 func_0016b740(u32 id) {
    if (id == 566) return D_0034e948;
    u32 key = func_0016e920(id);
    u8* v = 0;
    while ((v = YS__OBJ__Each(v)) != 0) {
        if (*(u32*)(v + 8) == key) break;
    }
    return (u32)v;
}
}  // namespace n0016b740

// 0016b7a0 (was src/anon/batch_w26.cpp)
namespace n0016b7a0 {
void* YS__OBJ__Each(void*) asm("_Z13YS__OBJ__Eachjjjj");
void* obj_get_serial(void*) asm("_ZN2YS3OBJ10get_serialEv");
/*TARGET 0016b7a0*/
// 0x00145c68: definition moved into src/anon/unit_00145600.cpp

// Finds the object with the given serial.
void* func_0016b7a0(void* serial) asm("func_0016b7a0");
// 0x00145c68: definition moved into src/anon/unit_00145600.cpp

// Finds the object with the given serial.
void* func_0016b7a0(void* serial) {
    void* p = 0;
    while ((p = YS__OBJ__Each(p)) != 0) {
        if (obj_get_serial(p) == serial) return p;
    }
    return p;
}
}  // namespace n0016b7a0

// 0016b800 (was src/anon/batch_w27.cpp)
namespace n0016b800 {
void* YS__OBJ__Each(void*) asm("YS__OBJ__Each");
s32 func_0016a070(void*) asm("func_0016a070");
/*TARGET 0016b800*/
void* func_0016b800(s32 id) asm("func_0016b800");
void* func_0016b800(s32 id) {
    void* p = 0;
    while ((p = YS__OBJ__Each(p)) != 0) {
        if (func_0016a070(p) == id) return p;
    }
    return p;
}
}  // namespace n0016b800

// 0016b860 (was unwritten gap)
namespace n0016b860 {
u8* YS__OBJ__Each(u8*) asm("YS__OBJ__Each");
u8* func_0016b860(u32 id) asm("func_0016b860");
u8* func_0016b860(u32 id) {
    u8* o = 0;
    while ((o = YS__OBJ__Each(o)) != 0) {
        u8* q = *(u8**)(o + 2072);
        if (q && *(u16*)(*(u8**)(q + 8) + 2) == id) break;
    }
    return o;
}
}  // namespace

// 0016b8b8 (was src/anon/batch_w3762.cpp)
namespace n0016b8b8 {
#define QCOPY16b(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCOPY4_16b(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QV16b {
    f32 x, y, z, w;
    QV16b() {}
    QV16b(const QV16b& o) { QCOPY16b(this, &o); }
    QV16b& operator=(const QV16b& o) { if (this != &o) QCOPY16b(this, &o); return *this; }
} __attribute__((aligned(16)));
struct QM16b {
    QV16b r[4];
    QM16b() {}
    QM16b(const QM16b& o) { QCOPY4_16b(this, &o); }
    QM16b& operator=(const QM16b& o) { QCOPY4_16b(this, &o); return *this; }
    void apply(QV16b* o, const QV16b* v) const {
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(o), "r"(this), "r"(v) : "memory");
    }
    QV16b operator*(const QV16b& v) const {
        QV16b o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    void invOrtho() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
struct Obj16b { u8 pad0[0x10c]; u32 flags; };
static inline void vsub16b(QV16b* o, const QV16b* a, const QV16b* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(o), "r"(a), "r"(b) : "memory");
}
static inline f32 normalize16b(QV16b* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
u8* func_00106a60(s32) asm("func_00106a60");
Obj16b* YS__OBJ__Each(Obj16b*) asm("YS__OBJ__Each");
s32 func_0016a020(Obj16b*) asm("func_0016a020");
QV16b* YS__OBJ__get_pos(Obj16b*) asm("YS__OBJ__get_pos");
/*TARGET 0016b8b8*/
Obj16b* YS__OBJ__SearchByCamera(s32 kind0, const QV16b* pos0) asm("YS__OBJ__SearchByCamera");
Obj16b* YS__OBJ__SearchByCamera(s32 kind0, const QV16b* pos0) {
    s32 kind = kind0;
    register const QV16b* pos asm("$17") = pos0;
    QM16b m;
    QV16b local;
    QV16b d;
    Obj16b* o = 0;
    Obj16b* best = 0;
    u8* cam = func_00106a60(1);
    f32 bestDist = 0.0f;
    m = *(QM16b*)(cam ? cam + 16 : 0);
    m.invOrtho(); asm("" : "+r"(pos));
    register QV16b* q asm("$7") = &local; asm("" : "+r"(q)); m.apply(q, pos); pos = q; asm("" : "+r"(pos));register QV16b* dp asm("$16") = &d; asm("" : "+r"(dp));
    while ((o = YS__OBJ__Each(o)) != 0) {
        if (func_0016a020(o) != kind) continue;
        if (o->flags & 0x2000) continue;
        vsub16b(dp, YS__OBJ__get_pos(o), pos);
 f32 len = normalize16b(dp);
        Obj16b* other = best;
        if (!best || len < bestDist) {
            bestDist = len;
            best = o;
        } else {
            other = o;
        }
        if (other && (other->flags & 0x1000)) other->flags |= 0x2000;
    }
    if (best) best->flags |= 0x1000;
    return best;
}
}  // namespace n0016b8b8

// 0016baa8 (was unwritten gap)
namespace n0016baa8 {
void func_0016cce8(u32, s32, u32*, s32, s32) asm("func_0016cce8");
void func_0016baa8(u8* o, u32 a, u32 b) asm("func_0016baa8");
void func_0016baa8(u8* o, u32 a, u32 b) {
    u32 buf[2];
    buf[0] = a;
    buf[1] = b;
    u32 t = *(u32*)(o + 1156);
    if (t) func_0016cce8(t, 10, buf, 2, 0);
}
}  // namespace

// 0016bae8 (was src/anon/tiny_auto80_queue.cpp)
namespace n0016bae8 {
u32 func_0016cce8(...) asm("func_0016cce8");
/*TARGET 0016bae8*/
void func_0016bae8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0016bae8jjjj");
void func_0016bae8(u32 a0, u32 a1, u32 a2, u32 a3) {
    struct {
        u32 x;
        u32 y;
        u32 z;
    } sp;
    u32 t7 = *(u32*)((u32)a0 + (s32)(1156));
    if (t7 != 0u) {
        sp.x = a1;
        sp.y = a2;
        sp.z = a3;
        func_0016cce8(t7, 11u, (u32)&sp, 3u, 0u);
    }
}
}  // namespace n0016bae8

// 0016bb38 (was src/anon/batch_w44.cpp)
namespace n0016bb38 {
typedef void (*VFn3)(void*, u32, u32);
// poll_timer_status
void* YS__OBJ__Each(void*) asm("YS__OBJ__Each");
/*TARGET 0016bb38*/
// 0x0015cc80: definition moved into src/anon/unit_0015cb18.cpp

// Calls virtual slot 13 on every object of the iterator.
void func_0016bb38(u32 a, u32 b) asm("func_0016bb38");
// 0x0015cc80: definition moved into src/anon/unit_0015cb18.cpp

// Calls virtual slot 13 on every object of the iterator.
void func_0016bb38(u32 a, u32 b) {
    void* o = 0;
    while ((o = YS__OBJ__Each(o)) != 0) (*(VFn3*)(*(u8**)o + 52))(o, a, b);
}
}  // namespace n0016bb38

// 0016bba8 (was src/anon/auto80_199_queue.cpp)
namespace n0016bba8 {
/*TARGET 0016bba8*/
u32 func_0016bba8(u8* a0, u32 a1, u32 a2) asm("_Z13func_0016bba8Phjj");
u32 func_0016bba8(u8* a0, u32 a1, u32 a2) {
    u32 s0 = a2;
    u8* s1 = a0;
    u32 s2 = a1;
    u32 v0;

    if (*(u32*)(s1 + 2264) == 0) {
        return 0;
    }

loop:
    s0 = func_0018a100(*(u32*)(s1 + 2264), s2, s0);
    if (s0 == 0) {
        goto done;
    }

    v0 = YS__OBJ__is_enable_collision((u32)s1, *(u8*)s0);
    if (v0 == 0) {
        goto loop;
    }
done:
    return s0;
}
}  // namespace n0016bba8

// 0016bc20 (was src/anon/batch_w38.cpp)
namespace n0016bc20 {
// 0015cff0: moved to src/anon/unit_0015cdb0.cpp

// Finds the next entry, optionally with a matching id (-1 = any).
u8* func_0016bba8(void*, void*, u8*) asm("func_0016bba8");
/*TARGET 0016bc20*/
u8* func_0016bc20(void* a, void* b, s32 id) asm("func_0016bc20");
u8* func_0016bc20(void* a, void* b, s32 id) {
    u8* p = 0;
    do {
        p = func_0016bba8(a, b, p);
    } while (p && id != -1 && *p != id);
    return p;
}
}  // namespace n0016bc20

// 0016bc98 (was src/anon/auto80_199_queue.cpp)
namespace n0016bc98 {
/*TARGET 0016bc98*/
u32 func_0016bc98(u8* a0, u32 a1, u32 a2) asm("_Z13func_0016bc98Phjj");
u32 func_0016bc98(u8* a0, u32 a1, u32 a2) {
    u32 s0 = a2;
    u8* s1 = a0;
    u32 s2 = a1;
    u32 v0;

    if (*(u32*)(s1 + 2264) == 0) {
        return 0;
    }

loop:
    s0 = func_0018a1b8(*(u32*)(s1 + 2264), s2, s0);  // find_byte1_entry
    if (s0 != 0) {
        v0 = YS__OBJ__is_enable_collision((u32)s1, *(u8*)s0);
        if (v0 == 0) {
            goto loop;
        }
    }
    return s0;
}
}  // namespace n0016bc98

// 0016bd10 (was src/yasui/libys/action.cpp)
namespace n0016bd10 { // method (was YS::ACTION::Get)
void* func_0017aab8(int id) asm("func_0017aab8");
// One singleton per action ID (table at 0x34e9f8, filled by the static
// constructor at 0x17aad0). Vtable slot 0 is start(obj), slot 1 end(obj),
// slot 2 jump(obj, vec), slot 3 jump_height(obj, h).
class ActionState {
public:
    virtual void start(void* obj);
};
struct ACTION { u8 pad[0xc]; ActionState* current; };
/*TARGET 0016bd10*/
// Enters action `id`: runs its start() on this object and makes it current.
void ACTION_Get(ACTION* self, s32 id) asm("_ZN2YS6ACTION3GetENS0_2IDE");
void ACTION_Get(ACTION* self, s32 id) {
    ActionState* a = (ActionState*)func_0017aab8(id);
    a->start(self);
    self->current = a;
}
}

// 0016bd60 (was src/anon/tiny_auto80_solver.cpp)
namespace n0016bd60 {
u32 func_0016bd10(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0016bd10jjjjjjjj");
u32 func_0016bd60(u32, u32) asm("_Z13func_0016bd60jj");
/*TARGET 0016bd60*/
u32 func_0016bd60(u32 a0, u32 a1) asm("_Z13func_0016bd60jj");
u32 func_0016bd60(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    u32 obj = *(u32*)(a0 + 12);
    void (**vt)() = *(void (***)())obj;
    ((void (*)(u32, u32))vt[1])(obj, s0);
    return ((u32(*)(u32, u32))func_0016bd10)(s0, s1);
}
}  // namespace n0016bd60

// 0016bda8 (was src/anon/auto80_199_queue.cpp)
namespace n0016bda8 {
/*TARGET 0016bda8*/
u32 YS__OBJ__get_target_pos(u32 a0, u32 a1) asm("_Z23YS__OBJ__get_target_posjj");
u32 YS__OBJ__get_target_pos(u32 a0, u32 a1) {
    u8 sp0[32];
    func_00190128(sp0);
    func_00190878(sp0, a1, 0);
    func_00190388(a0, sp0);  // vec4_from_arg
    return a0;
}
}  // namespace n0016bda8

// 0016be00 (was src/anon/batch_w50.cpp)
namespace n0016be00 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
// 16-byte aligned vector: copies are one quadword; assignment skips self-copies.
struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(const Vec4& o) { QCOPY(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
// obj_init_name_string
Vec4 YS__OBJ__get_target_pos(void*) asm("YS__OBJ__get_target_pos");
s32 YS__BGHIT__check_line(Vec4*, Vec4*, Vec4*, s32) asm("YS__BGHIT__check_line");
void YS__PRIZE__Appear(Vec4*, s32) asm("YS__PRIZE__Appear");
void YS_OBJ_scatter_prize(u8*, s32) asm("_ZN2YS3OBJ13scatter_prizeEi");
/*TARGET 0016be00*/
// 0x0013f0d0: definition moved into src/anon/unit_0013ef70.cpp

// 0015cde0: moved to src/anon/unit_0015cdb0.cpp

// 00160ac0: moved to src/harata/libdk/bgobj.cpp

// Allocates a 76-byte object from the heap (tagged with the caller) and initialises it.
// 00168388: moved to src/yasui/libys/file.cpp

// YS::OBJ::scatter_prize(int)
void YS_OBJ_scatter_prize(u8* self, s32 n) asm("_ZN2YS3OBJ13scatter_prizeEi");
// 0x0013f0d0: definition moved into src/anon/unit_0013ef70.cpp

// 0015cde0: moved to src/anon/unit_0015cdb0.cpp

// 00160ac0: moved to src/harata/libdk/bgobj.cpp

// Allocates a 76-byte object from the heap (tagged with the caller) and initialises it.
// 00168388: moved to src/yasui/libys/file.cpp

// YS::OBJ::scatter_prize(int)
void YS_OBJ_scatter_prize(u8* self, s32 n) {
    Vec4 c;
    Vec4 t;
    Vec4 a(*(Vec4*)(self + 1344));
    a.y -= *(f32*)(self + 1532);
    Vec4 b = YS__OBJ__get_target_pos(self);
    if (YS__BGHIT__check_line(&c, &a, &b, 6)) b = c;
    YS__PRIZE__Appear(&b, n);
}
}  // namespace n0016be00

// 0016be98 (was src/anon/batch_w56.cpp)
namespace n0016be98 {
// 0x0015c068: definition moved into src/anon/unit_0015bab8.cpp

// 0016be98: returns a 128-bit value by hidden pointer
struct L16be98 { u32 a, b, c, d; u128 v; };
void* func_0016bc20(u8*, s32, s32) asm("func_0016bc20");
void YS__COLLISION__set(void*, u8*, void*) asm("YS__COLLISION__set");
/*TARGET 0016be98*/
u128* func_0016be98(u128* out, u8* a) asm("func_0016be98");
u128* func_0016be98(u128* out, u8* a)
{
    L16be98 l;
    u128* src = &l.v;
    l.d = 0;
    void* r = func_0016bc20(a, 1, -1);
    if (r) {
        YS__COLLISION__set(&l, a, r);
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(out), "r"(src) : "$8", "memory");
    } else {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(out), "r"(a + 1344) : "$8", "memory");
    }
    return out;
}
}  // namespace n0016be98

// 0016bf20 (was src/yasui/libys/obj.cpp)
namespace n0016bf20 { // method (was YS::OBJ::get_appear_way)
/*TARGET 0016bf20*/
u32 OBJ_get_appear_way(void* self) asm("_ZN2YS3OBJ14get_appear_wayEv");
u32 OBJ_get_appear_way(void* self) {
    u32 r15 = *(u32*)((u32)self + 2076);
    u32 r2 = (u32)((s32)0u + (-1));
    if (r15 != 0u) {
        r2 = (u32)(*(u8*)((u32)r15 + 28));
    }
    return r2;
}
}

// 0016bf38 (was src/anon/batch_w242.cpp)
namespace n0016bf38 {
void func_0016c028x() asm("YS__OBJ__get_pos");
void func_001cc3b8(void*, u32) asm("func_001cc3b8");
extern u8 D_0032bae0 asm("D_0032bae0");
/*TARGET 0016bf38*/
// 0x0014a9a0: definition moved into src/harata/libdk/fade.cpp

void func_0016bf38(char* a, u32 a1, char* c) asm("func_0016bf38");
// 0x0014a9a0: definition moved into src/harata/libdk/fade.cpp

void func_0016bf38(char* a, u32 a1, char* c) {
    *(u32*)(a + 0x81c) = (u32)c;
    *(u32*)(a + 0x818) = a1;
    u32 h = *(u16*)(c + 40);
    if (h) *(u32*)(a + 0x500) = h;
    for (int i = 0; i < 2; i++) *(u32*)(a + 0x820 + i * 4) = *(u32*)(c + 32 + i * 4);
    u32 b = *(u8*)(c + 49);
    if (b) {
        u32 g = D_0032bae0;
        if (g != 14) {
            if (g == 16) {
                if (*(u32*)(a + 0x588) & 2) {
                    *(u32*)(a + 0xac8) = b;
                } else {
                    void* r = ((void*(*)())func_0016c028x)();
                    func_001cc3b8(r, *(u8*)(c + 49));
                }
            }
        } else {
            *(u32*)(a + 0xacc) = b;
        }
    }
}
}  // namespace n0016bf38

// 0016bff0 (was src/yasui/libys/obj.cpp)
namespace n0016bff0 { // method (was YS::OBJ::get_serial)
/*TARGET 0016bff0*/
u32 OBJ_get_serial(void* self) asm("_ZN2YS3OBJ10get_serialEv");
u32 OBJ_get_serial(void* self) {
    u32 r15 = *(u32*)((u32)self + 2076);
    u32 r2 = 0u;
    if (r15 != 0u) {
        r2 = (u32)(*(u16*)((u32)r15 + 30));
    }
    return r2;
}
}

// 0016c008 (was src/anon/tiny_leaf.cpp)
namespace n0016c008 {
/*TARGET 0016c008*/
// 0x00146100: definition moved into src/anon/unit_00145600.cpp

// 001492e8: moved to src/harata/libdk/mapfile.cpp

// 0014b258: moved to src/anon/unit_0014b150.cpp

u32 func_0016c008(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0016c008jjjj");
// 0x00146100: definition moved into src/anon/unit_00145600.cpp

// 001492e8: moved to src/harata/libdk/mapfile.cpp

// 0014b258: moved to src/anon/unit_0014b150.cpp

u32 func_0016c008(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r5 = (u32)(r5 << 2);
    r5 = (u32)(r5 + r4);
    r2 = *(u32*)((u32)r5 + (s32)(2076));
    return r2;
}
}  // namespace n0016c008

// 0016c018 (was src/yasui/libys/obj.cpp)
namespace n0016c018 { // method (was YS::OBJ::set_unit_arg)
/*TARGET 0016c018*/
void OBJ_set_unit_arg(void* self, int idx, int value) asm("_ZN2YS3OBJ12set_unit_argEii");
void OBJ_set_unit_arg(void* self, int idx, int value) {
    u32 r5 = (u32)(idx << 2);
    r5 = (u32)(r5 + (u32)self);
    *(u32*)((u32)r5 + 2076) = (u32)value;
}
}

// 0016c028 (was src/anon/batch_w17.cpp)
namespace n0016c028 {
// 00167fc8: moved to src/anon/unit_00167358.cpp

u32 func_001c0cd8(void*) asm("func_001c0cd8");
/*TARGET 0016c028*/
u8* YS__OBJ__get_pos(u8* p) asm("YS__OBJ__get_pos");
u8* YS__OBJ__get_pos(u8* p) {  // obj_get_attach_or_alt
    return func_001c0cd8(p) ? p + 112 : p + 1344;
}
}  // namespace n0016c028

// 0016c060 (was src/anon/batch_w2382_nsa.cpp)
namespace n0016c060 {
// ---- 0016c060
struct W2382Res { u32 f0; u32 f4; u32 data; };
struct W2382Dict { u8 pad[0x10]; void* h; };
extern s8 D_0036c1f0[8] asm("D_0036c1f0");
// Four-character tag read from a byte string (little endian).
static inline u32 W2382Tag(const s8* s) { return s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24); }
W2382Res* func_00168b88(void*, s32, s32, s32) asm("func_00168b88");
/*TARGET 0016c060*/
// Reads entries 24 and 25 (tagged by the name at D_0036c1f0) from the dictionary at o+0x7a0.
// Returns 1 when both are present and non-zero. The handle goes through a pointer local so its
// null test gets the pointer branch heuristic (that sets the original's s-register order).
s32 func_0016c060(u8* o, u32* first, u32* second) asm("func_0016c060");
// Reads entries 24 and 25 (tagged by the name at D_0036c1f0) from the dictionary at o+0x7a0.
// Returns 1 when both are present and non-zero. The handle goes through a pointer local so its
// null test gets the pointer branch heuristic (that sets the original's s-register order).
s32 func_0016c060(u8* o, u32* first, u32* second)
{
    W2382Dict* dict = (W2382Dict*)(o + 0x7a0);
    W2382Res* r;
    u32 d;
    *first = 0;
    *second = 0;
    void* h = dict->h;
    if (h && (r = func_00168b88(dict->h, 24, W2382Tag(D_0036c1f0), 0)) && (d = r->data)) {
        *first = d;
        if ((r = func_00168b88(dict->h, 25, W2382Tag(D_0036c1f0), 0)) && (d = r->data)) {
            *second = d;
            return 1;
        }
    }
    return 0;
}
}  // namespace n0016c060

// .rodata in place (between 0x16c060's and 0x16c168's constants): pad word + the "face" tag that 0x16c060 reads
extern const u32 R_0036c1ec[1] asm("D_0036c1ec") __attribute__((aligned(4))) = { 0x0 };
extern const u32 R_0036c1f0[2] asm("D_0036c1f0") __attribute__((aligned(4))) = { 0x65636166, 0x0 };

// 0016c168 (was src/anon/batch_wcx2.cpp)
namespace n0016c168 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
// --------------------
struct T16c168 { u8 pad[14]; s16 a; s16 b; s16 c; s16 d; s16 e; };
s32 func_001849b8(u8*) asm("func_001849b8");
T16c168* func_001aec40() asm("func_001aec40");
s32 func_0016a070_x8187(u8*) asm("func_0016a070");
void* func_0016c028_x8188(u8*) asm("YS__OBJ__get_pos");
void func_002bc188(s32, void*) asm("func_002bc188");
/*TARGET 0016c168*/
void func_0016c168(u8* obj, s32 n) asm("func_0016c168");
void func_0016c168(u8* obj, s32 n) {
    s32 id = func_001849b8(obj);
    if (id == 0) return;
    T16c168* t = func_001aec40();
    if (t == 0) return;
    s32 v;
    switch (func_0016a070_x8187(obj)) {
    case 1: case 14:
        v = t->a;
        break;
    case 2:
        v = t->b;
        break;
    case 3:
        v = t->c;
        break;
    case 4:
        v = t->e;
        break;
    default:
        if (func_0016a070_x8187(obj) < 16) v = t->d;
        else v = t->e;
        break;
    }
    if (n == 4 || n == 0) {
        n += obj[2044]++ & 3;
    } else if (n == 13) {
        n = (obj[2044]++ & 1) + 13;
    }
    func_002bc188(v * 1000 + id * 16 + n, func_0016c028_x8188(obj));
}
}  // namespace n0016c168

// 0016c2b0 (was src/anon/batch_w65.cpp)
namespace n0016c2b0 {
// Vector returned by value: copy construction is a 128-bit lq/sq.
struct Vr {
    f32 x, y, z, w;
    Vr() {}
    Vr(const Vr& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
u32 func_0016bc20(u32, s32, s32) asm("func_0016bc20");
Vr YS__OBJ__get_target_pos(u32) asm("YS__OBJ__get_target_pos");
struct Lookup32 { u32 a, b, c, d; Vr v; Lookup32() { d = 0; } };
void YS__COLLISION__set(Lookup32*, u32, u32) asm("YS__COLLISION__set");
/*TARGET 0016c2b0*/
Vr func_0016c2b0(u32 a) asm("func_0016c2b0");
Vr func_0016c2b0(u32 a) {
    Lookup32 t;
    u32 r = func_0016bc20(a, 17, -1);
    if (r) {
        YS__COLLISION__set(&t, a, r);
        return t.v;
    }
    return YS__OBJ__get_target_pos(a);
}
}  // namespace n0016c2b0

// 0016c330 (was unwritten gap)
namespace n0016c330 {
u32 func_0016f470(u32, s32) asm("func_0016f470");
void func_00170db0(u32) asm("func_00170db0");
void func_0016c330(u8* o) asm("func_0016c330");
void func_0016c330(u8* o) { func_00170db0(func_0016f470(*(u32*)(o + 8), 0)); }
}  // namespace

// 0016c358 (was src/anon/batch_w53.cpp)
namespace n0016c358 {
typedef void (*Fn3)(u32, u32, u32);
u32 func_001050c8(void) asm("func_001050c8");
/*TARGET 0016c358*/
void func_0016c358(u8* p) asm("func_0016c358");
void func_0016c358(u8* p) {
    if (*(u32*)(p + 2224)) {
        u32 v = func_001050c8();
        u32 o = *(u32*)(p + 2224);
        (*(Fn3*)(**(u8***)(p + 2224) + 40))(o, v, *(u32*)(p + 1648));
        *(u32*)(p + 2224) = 0;
    }
}
}  // namespace n0016c358

// 0016c3a8 (was src/anon/batch_w241.cpp)
namespace n0016c3a8 {
u32 YS__OBJ__Each(u32) asm("YS__OBJ__Each");
u32 func_0016bba8(u32, u32, u32) asm("func_0016bba8");
void YS__COLLISION__set(u8*, u32, u32) asm("YS__COLLISION__set");
/*TARGET 0016c3a8*/
s32 func_0016c3a8(u8* arr, s32 n) asm("func_0016c3a8");
s32 func_0016c3a8(u8* arr, s32 n) {
    s32 cnt = 0;
    u32 it = 0;
    while ((it = YS__OBJ__Each(it))) {
        u8* dst = (u8*)((cnt << 5) + (u32)arr);
        u32 x = 0;
        while ((x = func_0016bba8(it, 18, x)) != 0) {
            YS__COLLISION__set(dst, it, x);
            dst += 32;
            cnt++;
            if (cnt >= n) return cnt;
        }
    }
    return cnt;
}
}  // namespace n0016c3a8

// 0016c460 (was src/anon/batch_w54.cpp)
namespace n0016c460 {
union S32c {
    s32 v;
    u8 c;
};
// 0x0015bbc8: definition moved into src/anon/unit_0015bab8.cpp

s32 func_00177860(void) asm("func_00177860");
s32 func_001c3618(s32, s32) asm("func_001c3618");
f32* func_001ce300(s32) asm("func_001ce300");
/*TARGET 0016c460*/
// to_1ce2a0_index_minus1
f32 func_0016c460(u8* p, S32c* out) asm("func_0016c460");
// to_1ce2a0_index_minus1
f32 func_0016c460(u8* p, S32c* out) {
    f32 r = *(f32*)(p + 280);
    out->v = 3;
    if (*(u32*)(p + 1416) & 4) {
        if (*(u32*)(*(u8**)(p + 12) + 8) & 0x800) return r;
        s32 k = func_001c3618(func_00177860(), 0);
        if (k > 0) {
            r = *func_001ce300(k);  // to_1ce2a0_index_minus1
            out->v = 201;
        }
    }
    return r;
}
}  // namespace n0016c460

// 0016c4e8 (was src/yasui/libys/obj.cpp)
namespace n0016c4e8 { // method (was YS::OBJ::get_jump_height)
void func_0016c460(u32, u32) asm("func_0016c460");
/*TARGET 0016c4e8*/
void OBJ_get_jump_height(void* self) asm("_ZN2YS3OBJ15get_jump_heightEv");
void OBJ_get_jump_height(void* self) {
    struct {
        u32 w0;
        u32 w1;
        u32 w2;
        u32 w3;
    } sp;
    func_0016c460((u32)self, (u32)&sp);
}
}

// 0016c508 (was src/anon/batch_w28.cpp)
namespace n0016c508 {
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
Q16* YS__OBJ__get_pos(u32) asm("YS__OBJ__get_pos");
// obj_get_attach_or_alt
u8* func_001ce328(u16) asm("func_001ce328");
/*TARGET 0016c508*/
// 0x0014f068: definition moved into src/anon/unit_0014ecb8.cpp

// 00167658: moved to src/anon/unit_00167358.cpp

Q16* func_0016c508(Q16* out, u8* o) asm("func_0016c508");
// 0x0014f068: definition moved into src/anon/unit_0014ecb8.cpp

// 00167658: moved to src/anon/unit_00167358.cpp

Q16* func_0016c508(Q16* out, u8* o) {
    QCOPY(out, YS__OBJ__get_pos((u32)o));  // obj_get_attach_or_alt
    u8* f = func_001ce328(*(u16*)(*(u8**)(o + 8) + 0x4e));
    ((f32*)out)[1] -= *(f32*)(f + 0x30);
    return out;
}
}  // namespace n0016c508

// 0016c568 (was src/anon/auto200_999.cpp)
namespace n0016c568 {
void func_001d79b8(u32) asm("_Z13func_001d79b8j");
/*TARGET 0016c568*/
// 0016ced0: moved to src/anon/unit_0016c770.cpp

void func_0016c568(u32 a0) asm("_Z13func_0016c568j");
// 0016ced0: moved to src/anon/unit_0016c770.cpp

void func_0016c568(u32 a0) {
    register u32 p asm("$14") = a0 + 1304;
    asm volatile("" : "+r"(p));
    u32 flags = *(u32 *)(a0 + 2040);
    if ((flags & 4) == 0) {
        func_001d79b8(p);
    }
}
}  // namespace n0016c568

// 0016c5a0 (was src/anon/tiny_wrappers_more.cpp)
namespace n0016c5a0 {
u32 func_0016c5a0(u32, u32, u32, u32) asm("_Z13func_0016c5a0jjjj");
u32 func_001d7a08(u32, u32, u32, u32) asm("_Z13func_001d7a08jjjj");
/*TARGET 0016c5a0*/
u32 func_0016c5a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0016c5a0jjjj");
u32 func_0016c5a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001d7a08(((u32)(a0) + 1304u), a1, a2, a3);
}
}  // namespace n0016c5a0

// 0016c5b8 (was src/anon/batch_w55.cpp)
namespace n0016c5b8 {
u32 YS__OBJ__Each(u32) asm("YS__OBJ__Each");
s32 func_0016a040(u32) asm("func_0016a040");
void func_0016c568(u32, u32, f32) asm("func_0016c568");
void wtarget_0016c5b8(u32, u32, u32, u32) asm("_Z16wtarget_0016c5b8jjjj");
/*TARGET 0016c5b8*/
void wtarget_0016c5b8(u32 a, u32 b, u32, u32) asm("_Z16wtarget_0016c5b8jjjj");
void wtarget_0016c5b8(u32 a, u32 b, u32, u32) {
    u32 i = 0;
    while ((i = YS__OBJ__Each(i)) != 0) {
        if ((1 << func_0016a040(i)) & b) func_0016c568(i, a, 0.0f);
    }
}
}  // namespace n0016c5b8

// 0016c640 (was src/anon/batch_w27.cpp)
namespace n0016c640 {
void wtarget_0016c640(u32, u32, u32, u32) asm("_Z16wtarget_0016c640jjjj");
void* YS__OBJ__Each(void*) asm("YS__OBJ__Each");
void func_0016c5a0(void*, u32) asm("func_0016c5a0");
/*TARGET 0016c640*/
void wtarget_0016c640(u32 a, u32, u32, u32) asm("_Z16wtarget_0016c640jjjj");
void wtarget_0016c640(u32 a, u32, u32, u32) {
    void* p = 0;
    while ((p = YS__OBJ__Each(p)) != 0) {
        func_0016c5a0(p, a);
    }
}
}  // namespace n0016c640

// 0016c698 (was src/anon/tiny_auto80_queue.cpp)
namespace n0016c698 {
u32 func_0016cce8(...) asm("func_0016cce8");
/*TARGET 0016c698*/
void func_0016c698(u32 a0, u32 a1, u32 a2) asm("_Z13func_0016c698jjj");
void func_0016c698(u32 a0, u32 a1, u32 a2) {
    struct {
        u32 x;
        u32 y;
        u32 z;
    } sp;
    u32 t7 = *(u32*)((u32)a0 + (s32)(1156));
    if (t7 != 0u) {
        sp.x = a0;
        sp.y = a1;
        sp.z = a2;
        func_0016cce8(t7, (u32)((s32)0u + (27)), (u32)&sp, 3u, 0u);
    }
}
}  // namespace n0016c698

// 0016c6e8 (was src/anon/batch_w40.cpp)
namespace n0016c6e8 {
u8* YS__OBJ__Each(u8*) asm("YS__OBJ__Each");
u32 func_0016a020(u8*) asm("func_0016a020");
s32 obj_count_entry(u32 id) asm("_ZN2YS3OBJ10CountEntryEj");
/*TARGET 0016c6e8*/
// Counts objects whose entry id equals id.
s32 obj_count_entry(u32 id) asm("_ZN2YS3OBJ10CountEntryEj");
// Counts objects whose entry id equals id.
s32 obj_count_entry(u32 id) {
    u8* o = 0;
    s32 n = 0;
    while ((o = YS__OBJ__Each(o)) != 0)
        if (func_0016a020(o) == id) n++;
    return n;
}
}  // namespace n0016c6e8

// 0016c750 (was src/anon/batch_w4.cpp)
namespace n0016c750 {
struct Pair {
    u32 a, b;
};
extern u32 D_004f6288 asm("D_004f6288");
extern Pair D_004f6290 asm("D_004f6290");
/*TARGET 0016c750*/
void func_0016c750(u32 a) asm("func_0016c750");
void func_0016c750(u32 a) {  // list_init_global
    D_004f6288 = a;
    D_004f6290.b = 0;
    D_004f6290.a = 0;
}
}  // namespace n0016c750

