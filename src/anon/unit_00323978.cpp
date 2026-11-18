// Linked unit 0x00323978: linkonce (template) copies of game code that the linker gathered after the
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


// 00323978 (was src/anon/batch_w270.cpp)
namespace n00323978 {
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e40[] asm("D_00347e40");
void W270_ErrorRaise(void*) asm("_Z10ErrorRaisePv");
void func_00239700(void*) asm("func_00239700");
static inline void w270_init(u8* e) {
    *(void**)e = D_00347f98;
    W270_ErrorRaise(e + 12);
    *(void**)e = D_00347e60;
    func_00239700(e + 24);
    *(void**)e = D_00347e40;
    *(u32*)(e + 408) = 0;
}
/*TARGET 00323978*/
// 0x002d6600: definition moved into src/anon/unit_002d62d0.cpp
void func_00323978(u8* p) asm("func_00323978");
// 0x002d6600: definition moved into src/anon/unit_002d62d0.cpp
void func_00323978(u8* p) {
    w270_init(p);
    w270_init(p + 436);
    u8* q = p + 872;
    for (s32 n = 7; n != -1; n--) { w270_init(q); q += 436; }
    u8* r = p + 4360;
    for (s32 n = 7; n != -1; n--) { w270_init(r); r += 436; }
}
}  // namespace n00323978

// 00323ad0 (was src/anon/batch_w1669.cpp)
namespace n00323ad0 {
/*TARGET 00323ad0*/
// 00149f30: static initialiser, now made by gcc in src/harata/libdk/area.cpp
void func_00323ad0(u32* p) asm("func_00323ad0");
// 00149f30: static initialiser, now made by gcc in src/harata/libdk/area.cpp
void func_00323ad0(u32* p) {
    s32 i = 19;
    do { *p = 0; i--; __asm__ volatile("nop\n\tnop\n\tnop"); p++; } while (i >= 0);
}
}  // namespace n00323ad0

// 00323af8 (was src/anon/batch_w26.cpp)
namespace n00323af8 {
// 16-byte vector copied with lq/sq.
struct W26Quad {
    u8 v[16] __attribute__((aligned(16)));
    W26Quad(const W26Quad& o) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    }
};
struct W26Head {
    u64 a, b, c, d;
    W26Head(const W26Head& o) {
        u64 x0 = o.a, x1 = o.b, x2 = o.c, x3 = o.d;
        a = x0; b = x1; c = x2; d = x3;
    }
};
struct W26Blk {
    W26Head h;
    W26Quad q[2];
    f32 f;
    W26Blk(const W26Blk& o) : h(o.h), q(o.q), f(o.f) {}
};
inline void* operator new(unsigned int, void* p) { return p; }
/*TARGET 00323af8*/
// Copy-constructs a block in place.
void func_00323af8(W26Blk* d, const W26Blk* s) asm("func_00323af8");
// Copy-constructs a block in place.
void func_00323af8(W26Blk* d, const W26Blk* s) {  // obj_copy_48_bytes
    new (d) W26Blk(*s);
}
}  // namespace n00323af8

// 00323b50 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n00323b50 {
u32 func_00239870(u32, u32, u32, u32) asm("_Z13func_00239870jjjj");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
/*TARGET 00323b50*/
u32 func_00323b50(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00323b50jjjj");
u32 func_00323b50(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n00323b50

// 00323b90 (was src/anon/auto80_199_queue.cpp)
namespace n00323b90 {
/*TARGET 00323b90*/
void func_00323b90(u32 self) asm("_Z13func_00323b90j");
void func_00323b90(u32 self) {
    u32 s0 = self;
    *(u32*)s0 = addr_D_00347e60();
    func_00239870(s0 + 24);
    *(u32*)s0 = addr_D_00347f98();

    u32 base = *(u32*)(u32)&D_00347f80;
    u32 p = *(u32*)(base + 20);
    FnMgr fn = (FnMgr)*(u32*)(*(u32*)p + 4);
    fn(p, s0);
}
}  // namespace n00323b90

// 00323bf0 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n00323bf0 {
u32 func_00239870(u32, u32, u32, u32) asm("_Z13func_00239870jjjj");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
/*TARGET 00323bf0*/
u32 func_00323bf0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00323bf0jjjj");
u32 func_00323bf0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n00323bf0

// 00323c30 (was src/anon/auto80_199_queue.cpp)
namespace n00323c30 {
/*TARGET 00323c30*/
void func_00323c30(u32 self) asm("_Z13func_00323c30j");
void func_00323c30(u32 self) {
    u32 s0 = self;
    *(u32*)s0 = addr_D_00347e60();
    func_00239870(s0 + 24);
    *(u32*)s0 = addr_D_00347f98();

    u32 base = *(u32*)(u32)&D_00347f80;
    u32 p = *(u32*)(base + 20);
    FnMgr fn = (FnMgr)*(u32*)(*(u32*)p + 4);
    fn(p, s0);
}
}  // namespace n00323c30

// 00323c90 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n00323c90 {
u32 func_00239870(u32, u32, u32, u32) asm("_Z13func_00239870jjjj");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
/*TARGET 00323c90*/
u32 func_00323c90(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00323c90jjjj");
u32 func_00323c90(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n00323c90

// 00323cd0 (was src/anon/auto80_199_queue.cpp)
namespace n00323cd0 {
/*TARGET 00323cd0*/
void func_00323cd0(u32 self) asm("_Z13func_00323cd0j");
void func_00323cd0(u32 self) {
    u32 s0 = self;
    *(u32*)s0 = addr_D_00347e60();
    func_00239870(s0 + 24);
    *(u32*)s0 = addr_D_00347f98();

    u32 base = *(u32*)(u32)&D_00347f80;
    u32 p = *(u32*)(base + 20);
    FnMgr fn = (FnMgr)*(u32*)(*(u32*)p + 4);
    fn(p, s0);
}
}  // namespace n00323cd0

// 00323d30 (was src/anon/tiny_jal_wrappers_reloc.cpp)
namespace n00323d30 {
u32 func_00239870(u32, u32, u32, u32) asm("_Z13func_00239870jjjj");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347f98 asm("D_00347f98");
/*TARGET 00323d30*/
u32 func_00323d30(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00323d30jjjj");
u32 func_00323d30(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u, r16 = 0u;
    r15 = (u32)&D_00347e60;
    r16 = r4;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    r4 = (u32)((s32)r4 + (24));
    r2 = func_00239870(r4, r5, r6, r7);
    r15 = (u32)&D_00347f98;
    *(u32*)((u32)r16 + (s32)(0)) = r15;
    return r2;
}
}  // namespace n00323d30

// 00323d70 (was src/anon/auto80_199_queue.cpp)
namespace n00323d70 {
/*TARGET 00323d70*/
void func_00323d70(u32 self) asm("_Z13func_00323d70j");
void func_00323d70(u32 self) {
    u32 s0 = self;
    *(u32*)s0 = addr_D_00347e60();
    func_00239870(s0 + 24);
    *(u32*)s0 = addr_D_00347f98();

    u32 base = *(u32*)(u32)&D_00347f80;
    u32 p = *(u32*)(base + 20);
    FnMgr fn = (FnMgr)*(u32*)(*(u32*)p + 4);
    fn(p, s0);
}
}  // namespace n00323d70

// 00323dd0 (was src/anon/auto80_199_queue.cpp)
namespace n00323dd0 {
/*TARGET 00323dd0*/
void func_00323dd0(u32 self) asm("_Z13func_00323dd0j");
void func_00323dd0(u32 self) {
    u32 s0 = self;
    *(u32*)s0 = addr_D_0035f490();
    func_002361d0(s0 + 416);
    *(u32*)s0 = addr_D_00347e60();
    func_00239870(s0 + 24);
    *(u32*)s0 = addr_D_00347f98();
}
}  // namespace n00323dd0

// 00323e28 (was src/anon/auto80_199_queue.cpp)
namespace n00323e28 {
/*TARGET 00323e28*/
void func_00323e28(u32 self) asm("_Z13func_00323e28j");
void func_00323e28(u32 self) {
    u32 s0 = self;
    *(u32*)s0 = addr_D_0035f490();
    func_002361d0(s0 + 416);
    *(u32*)s0 = addr_D_00347e60();
    func_00239870(s0 + 24);
    *(u32*)s0 = addr_D_00347f98();

    u32 base = *(u32*)(u32)&D_00347f80;
    u32 p = *(u32*)(base + 20);
    FnMgr fn = (FnMgr)*(u32*)(*(u32*)p + 4);
    fn(p, s0);
}
}  // namespace n00323e28

// 00323e98 (was src/anon/batch_w97.cpp)
namespace n00323e98 {
// 0x00304ba8: definition moved into src/newlib/libc/reent.c

// ---- 00323e98
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e40[] asm("D_00347e40");
void func_0031a838(u8*) asm("func_0031a838");
void func_00239700(u8*) asm("func_00239700");
static inline void ctor_323(u8* e) {
    *(u32*)e = (u32)D_00347f98;
    func_0031a838(e + 12);
    *(u32*)e = (u32)D_00347e60;
    func_00239700(e + 24);
    *(u32*)e = (u32)D_00347e40;
    *(u32*)(e + 408) = 0;
}
/*TARGET 00323e98*/
void func_00323e98(u8* p) asm("func_00323e98");
void func_00323e98(u8* p) {
    {
        u8* e = p + 4;
        s32 i = 4;
        do { ctor_323(e); i--; e += 436; } while (i != -1);
    }
    {
        u8* e = p + 2184;
        s32 i = 4;
        do { ctor_323(e); i--; e += 436; } while (i != -1);
    }
    {
        u8* e = p + 4364;
        s32 i = 14;
        do { ctor_323(e); i--; e += 436; } while (i != -1);
    }
}
}  // namespace n00323e98

// 00323fd8 (was src/anon/batch_w110.cpp)
namespace n00323fd8 {
void func_0031a838(u8*) asm("func_0031a838");
void func_00239700(u8*) asm("func_00239700");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_00347e60[] asm("D_00347e60");
extern u8 D_00347e40[] asm("D_00347e40");
static inline void CtorC(u8* q) {
    *(u32*)q = (u32)D_00347f98;
    func_0031a838(q + 12);
    *(u32*)q = (u32)D_00347e60;
    func_00239700(q + 24);
    *(u32*)(q + 408) = 0;
    *(u32*)q = (u32)D_00347e40;
}
static inline void CtorB(u8* q) {
    *(u32*)(q + 12) = 0;
    *(u32*)q = (u32)D_00347e60;
    func_00239700(q + 24);
}
static inline void CtorArr(u8* q) { for (s32 i = 4; i != -1; i--, q += 436) CtorC(q); }
static inline void CtorC2(u8* q) {
    *(u32*)q = (u32)D_00347f98;
    func_0031a838(q + 12);
    *(u32*)q = (u32)D_00347e60;
    func_00239700(q + 24);
    *(u32*)q = (u32)D_00347e40;
    *(u32*)(q + 408) = 0;
}
/*TARGET 00323fd8*/
// Constructs the member objects (vtable chain A -> B -> C) of a 6.5 KB container.
void func_00323fd8(u8* p) asm("func_00323fd8");
// Constructs the member objects (vtable chain A -> B -> C) of a 6.5 KB container.
void func_00323fd8(u8* p) {
    CtorC(p);
    CtorC(p + 436);
    CtorC(p + 872);
    CtorC(p + 1308);
    CtorArr(p + 1744);
    u8* q = p + 3924;
    for (s32 i = 4; i != -1; i--, q += 436) CtorC2(q);
    CtorB(p + 6104);
    CtorB(p + 6512);
}
}  // namespace n00323fd8
