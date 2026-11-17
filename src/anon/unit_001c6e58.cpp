// Linked unit 0x1c6e58-0x1c70e8: first part of one original file (effect objects that fly out of
// D_01d498d0): the ctor pair, the manager z-sort hook and the two object init functions.
// 0x1c70e8 (partial asm, needs -fno-schedule-insns) stays in src/anon/batch_w3719_nosched.cpp;
// the rest of the file is src/anon/unit_001c7148.cpp. Every function and global is bound by asm label.
#include "../common/types.h"

struct NoTail { ~NoTail() {} };

// 001c6e58 (from src/anon/batch_w24.cpp)
namespace n001c6e58 {
void func_001c23a8(u32*, u32, s32, s32, s32, u32, u32) asm("func_001c23a8");
extern void* D_00351d38[] asm("D_00351d38");
void func_001c6e58(u32* p, u32 a, u32 b, u32 c) asm("func_001c6e58");
void func_001c6e58(u32* p, u32 a, u32 b, u32 c) {
    func_001c23a8(p, a, 0, 1, 0, c, b);
    *(void**)p = D_00351d38;
}
} // n001c6e58

// 001c6ea0 (from src/anon/batch_w25.cpp)
namespace n001c6ea0 {
extern u8 D_00351d38 asm("D_00351d38");
void func_001c23a8(void*, u32, u32, u32, u32, u32, u32) asm("func_001c23a8");
void func_001c6ea0(void* o, u32 a, u32 b, u32 c) asm("func_001c6ea0");
void func_001c6ea0(void* o, u32 a, u32 b, u32 c) {
    func_001c23a8(o, a, 0, 1, 0, c, b);
    *(void**)o = &D_00351d38;
}
} // n001c6ea0

// 001c6ee8 (from src/anon/batch_w13.cpp)
namespace n001c6ee8 {
void func_0016a9a0(void*) asm("func_0016a9a0");  // to_16a950
void func_001c14e0(void*) asm("func_001c14e0");
void MANAGER_exec_zsort(u8*) asm("_ZN2YS10MASSEFFECT7MANAGER10exec_zsortEv");
void MANAGER_exec_zsort(u8* self) {
    func_0016a9a0(self);  // to_16a950
    func_001c14e0(*(void**)(self + 2548));
}
} // n001c6ee8

// 001c6f10 (from src/anon/auto80_199_queue.cpp)
namespace n001c6f10 {
u32 func_001db888(void*, u32, u32) asm("func_001db888");
u32 func_001c7048(u32, u32, u32, u32, u32) asm("func_001c7048");
u32 func_001c6f10(u8* a0, void* a1, void* a2, void* a3) asm("func_001c6f10");
u32 func_001c6f10(u8* a0, void* a1, void* a2, void* a3) {
    u32 out = 0;
    u8* p = *(u8**)(a0 + 2548) + 20;
    if (*(u32*)(p + 8) != 0) {
        u32 ret = func_001db888(p, 96, (u32)__builtin_return_address(0));  // record_index_calc
        func_001c7048(ret, (u32)a0, (u32)a1, (u32)a2, (u32)a3);
        out = ret;
    }
    return out;
}
} // n001c6f10

// 001c6fa8, 001c7048 (from src/anon/batch_w1776_nsa.cpp)
namespace n001c6fa8 {
struct W1776V4 { f32 x, y, z, w; };
struct W1776Obj {
    u8 pad0[0x14]; u8 b14; u8 pad15; s8 b16; u8 pad17[0x11];
    s32 f28; u8 pad2c[4]; W1776V4 v30; f32 f40; u8 b44; u8 b45; u8 pad46[2]; s32 f48; u8* f4c; void* f50;
};
struct W1776Src { u8 pad[0x9f4]; u32 f9f4; };
void func_001c1748(W1776Obj*, u32, u32, u32) asm("func_001c1748");

void func_001c6fa8(W1776Obj* o, W1776Src* s, u8* p, u32 a, u32 b) asm("func_001c6fa8");
void func_001c6fa8(W1776Obj* o, W1776Src* s, u8* p, u32 a, u32 b) {
    func_001c1748(o, s->f9f4, a, b);
    o->f28 = 0;
    W1776V4* v = &o->v30;
    v->x = v->w = v->z = v->y = 0.0f;
    o->f40 = 900.0f;
    o->f50 = s;
    o->f4c = p;
    o->b44 = 0;
    o->b45 = 30;
    o->f48 = 0;
    o->b14 = *p;
    o->b16 = -1;
}

void func_001c7048(W1776Obj* o, W1776Src* s, u8* p, u32 a, u32 b) asm("func_001c7048");
void func_001c7048(W1776Obj* o, W1776Src* s, u8* p, u32 a, u32 b) {
    func_001c1748(o, s->f9f4, a, b);
    o->f28 = 0;
    W1776V4* v = &o->v30;
    v->x = v->w = v->z = v->y = 0.0f;
    o->f40 = 900.0f;
    o->f50 = s;
    o->f4c = p;
    o->b44 = 0;
    o->b45 = 30;
    o->f48 = 0;
    o->b14 = *p;
    o->b16 = -1;
}
} // n001c6fa8
