#include "../common/types.h"

// 0x17bf40-0x17c290: start of the file before YS::FRIEND (its classes have vtables at 0x34eb58/0x34eb88,
// retail data, with the base methods 0x17a8f8/0x17a938 from the previous file). The VU0 vtable method
// 0x17c290 was never written and stays outside; the file goes on in src/anon/unit_0017c400.cpp.
// Each function keeps the declarations of the source it was matched in (namespace xN); every symbol
// is bound by asm label.

// 0017bf40 (src/anon/auto80_199_queue.cpp)
namespace x0 {
typedef void (*Fn0)(void);
typedef void (*Fn2)(u32, u32);
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
typedef void (*VCall4)(Obj*, u32);
u32 func_00190128(...) asm("func_00190128");
typedef void (*FnA0)(u32);
typedef void (*VirtCall)(u32 a0, u32 a1, u32 a2);
typedef void (*VirtCall2)(u32 a0, u32 a1);
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef void (*Cb)(u32);
typedef void (*Fn_001d8270)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8310)(u32 a0);
typedef void (*Fn_001d8470)(u32 a0);
typedef void (*Fn_001d8578)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8bd0)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d9288)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef void (*Fn1)(u32);
typedef void (*Fn_0028e080)(u32, u32);
typedef void (*VFn)(u32);
typedef void (*VCall20)(void*);
typedef void (*VCall16)(void*);
typedef u32 (*Method1)(u32);
typedef void (*VFn73d8)(u32 a0, u8 a1, u32 a2);
typedef void (*Fn_0031d8f8)(u32, u32);
typedef void (*Fn_0031d9b8)(u32);
typedef void (*Fn_0031f968)(u32);
typedef void (*Fn_0031f9c0)(u32);
typedef void (*Fn_00321de8)(u32);
typedef void (*Fn_00321e60_dtor)(u32);
typedef void (*Fn_00321e60_mgr)(u32, u32);
typedef void (*Fn_00321ef8)(u32);
typedef void (*Fn_00321f70_dtor)(u32);
typedef void (*Fn_00321f70_mgr)(u32, u32);
typedef void (*Fn_00322008)(u32);
typedef void (*Fn_00322080_dtor)(u32);
typedef void (*Fn_00322080_mgr)(u32, u32);
typedef void (*Fn_00322118_dtor)(u32);
typedef void (*Fn_00322118_mgr)(u32, u32);
typedef void (*Fn_003221b0)(u32);
typedef void (*Fn_00322908)(u32, u32);
typedef void (*Fn_00322a98)(u32);
typedef void (*Fn_00322a10)(u32, u32);
typedef void (*Fn_00322b10_dtor)(u32);
typedef void (*Fn_00322b10_mgr)(u32, u32);
typedef void (*FnMgr)(u32, u32);

void func_0017bf40(u32 a0) {
    *(u16*)(a0 + 0) = 0;

    u32 s0 = a0;
    func_00190128(a0 + 8);

    u32 t7 = *(u32*)(s0 + 4);
    u32 t6 = (u32)-2;
    u32 t5 = (u32)-3;
    t7 &= t6;
    t7 &= t5;
    t6 = (u32)-5;
    t7 &= t6;
    t5 = (u32)-9;
    t7 &= t5;
    t6 = (u32)-17;
    t7 &= t6;
    *(u32*)(s0 + 4) = t7;
}
}  // namespace x0

// 0017bfa0 (src/anon/auto80_199_queue.cpp)
namespace x1 {
typedef void (*Fn0)(void);
typedef void (*Fn2)(u32, u32);
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
typedef void (*VCall4)(Obj*, u32);
u32 func_00190128(...) asm("func_00190128");
u32 func_001b8e88(...) asm("func_001b8e88");
typedef void (*FnA0)(u32);
typedef void (*VirtCall)(u32 a0, u32 a1, u32 a2);
typedef void (*VirtCall2)(u32 a0, u32 a1);
void func_0017bfa0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0017bfa0");
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef void (*Cb)(u32);
typedef void (*Fn_001d8270)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8310)(u32 a0);
typedef void (*Fn_001d8470)(u32 a0);
typedef void (*Fn_001d8578)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d8bd0)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef void (*Fn_001d9288)(u32 a0, u32 a1, u32 a2, u32 a3);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef void (*Fn1)(u32);
typedef void (*Fn_0028e080)(u32, u32);
typedef void (*VFn)(u32);
typedef void (*VCall20)(void*);
typedef void (*VCall16)(void*);
typedef u32 (*Method1)(u32);
typedef void (*VFn73d8)(u32 a0, u8 a1, u32 a2);
typedef void (*Fn_0031d8f8)(u32, u32);
typedef void (*Fn_0031d9b8)(u32);
typedef void (*Fn_0031f968)(u32);
typedef void (*Fn_0031f9c0)(u32);
typedef void (*Fn_00321de8)(u32);
typedef void (*Fn_00321e60_dtor)(u32);
typedef void (*Fn_00321e60_mgr)(u32, u32);
typedef void (*Fn_00321ef8)(u32);
typedef void (*Fn_00321f70_dtor)(u32);
typedef void (*Fn_00321f70_mgr)(u32, u32);
typedef void (*Fn_00322008)(u32);
typedef void (*Fn_00322080_dtor)(u32);
typedef void (*Fn_00322080_mgr)(u32, u32);
typedef void (*Fn_00322118_dtor)(u32);
typedef void (*Fn_00322118_mgr)(u32, u32);
typedef void (*Fn_003221b0)(u32);
typedef void (*Fn_00322908)(u32, u32);
typedef void (*Fn_00322a98)(u32);
typedef void (*Fn_00322a10)(u32, u32);
typedef void (*Fn_00322b10_dtor)(u32);
typedef void (*Fn_00322b10_mgr)(u32, u32);
typedef void (*FnMgr)(u32, u32);
struct Auto80_199QueueCopy {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
    u32 e;
};

void func_0017bfa0(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u16*)(a0 + 0) = (u16)a1;

    u32 s0 = a0;
    u32 v0 = a3;
    u32 s1 = a2;

    if (a3 == 0) {
        v0 = func_001b8e88(a1);
    }

    u32 t7 = *(u16*)(v0 + 4);
    *(u16*)(s0 + 2) = (u16)t7;

    if (s1 == 0) {
        func_00190128(s0 + 8);
        return;
    }

    *(Auto80_199QueueCopy*)(s0 + 8) = *(Auto80_199QueueCopy*)s1;
}
}  // namespace x1

// 0017c030 (src/anon/batch_w45.cpp)
namespace x2 {
struct Tk { u32 f0; s32 id; };
typedef void (*VFn)(u8*);
typedef void (*VFn3)(u8*, u32, u32);
f32 func_0016c460(u8*, void*) asm("func_0016c460");
void* func_00102818(u32, u32, u32, void*, u32) asm("func_00102818");
Tk* func_00102818_t(u32, u32, u32, void*, u32) asm("func_00102818");

u8* func_0017c030(u8* out, u8* obj, void* a2, u8 flag) {
    u8* src = obj + 16;
    if (out != src) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(out), "r"(src) : "$8", "memory");
    *(f32*)(out + 4) = func_0016c460(obj, a2);
    if (flag) *(u32*)(obj + 264) |= 0x10000;
    return out;
}
}  // namespace x2

// 0017c0a0 (src/anon/batch_w45.cpp)
namespace x3 {
struct Tk { u32 f0; s32 id; };
typedef void (*VFn)(u8*);
typedef void (*VFn3)(u8*, u32, u32);
f32 func_0016c460(u8*, void*) asm("func_0016c460");
void func_0017c4c8(u8*, void*) asm("func_0017c4c8");
void func_0017f488(u8*, u32, f32, f32) asm("func_0017f488");
void* func_00102818(u32, u32, u32, void*, u32) asm("func_00102818");
Tk* func_00102818_t(u32, u32, u32, void*, u32) asm("func_00102818");
u8* func_0017c030(u8* out, u8* obj, void* a2, u8 flag) asm("func_0017c030");

void func_0017c0a0(u32 a0, u8* obj, u8 flag) {
    u8 tmp[16] __attribute__((aligned(16)));
    u8 v[16] __attribute__((aligned(16)));
    u32 w;
    func_0017c030(tmp, obj, &w, flag);
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(v), "r"(tmp) : "$8", "memory");
    func_0017c4c8(obj, v);
    func_0017f488(obj + 320, w, 0.0f, 0.0f);
    *(u32*)(obj + 256) = 4;
    *(u32*)(obj + 260) = 5;
}
}  // namespace x3

// 0017c108 (src/anon/batch_wcx2.cpp)
namespace x4 {
void func_0017f540(u8*, u32, f32, f32) asm("func_0017f540");
static inline __attribute__((always_inline)) void h_0017c108(u8* q, u32 f, u32 v) {
    if ((f & 4) || ((f & 0x10) && v)) func_0017f540(q, v, 8.0f, 0.0f);
}
void func_0017c108(u32 a0, u8* p, u32 a2) asm("func_0017c108");
void func_0017c108(u32 a0, u8* p, u32 a2) { h_0017c108(p + 320, *(u32*)(p + 352), a2); }
}  // namespace x4

// 0017c160 (src/anon/batch_w1834.cpp)
namespace x5 {
struct W1834Sub { u8 pad[0x14]; s32 st; };
struct W1834Bits { u32 b0 : 1; };
struct W1834Obj {
    u8 p0[0x1c]; f32 v;
    u8 p1[0x110 - 0x20]; f32 a; f32 b;
    u8 p2[0x140 - 0x118]; W1834Sub sub;
    u8 p3[0x164 - 0x158]; W1834Bits bits;
    u8 p4[0x588 - 0x168]; u32 flags;
};
s32 func_0016a070(W1834Obj*) asm("func_0016a070");
void func_0016c168(W1834Obj*, s32) asm("func_0016c168");
void func_0017c108(void*, W1834Obj*, s32) asm("func_0017c108");
void func_001b3748(W1834Obj*, s32) asm("func_001b3748");

void func_0017c160(void* self, W1834Obj* o) {
    s32 r = 0;
    f32 v = o->v;
    if (v > 0.0f) {
        r = 1;
        if (!(v < (o->a + o->b) * 0.5f)) r = 2;
        if ((o->flags & 0x80) && o->sub.st == 0) {
            if (func_0016a070(o) != 14) {
                func_001b3748(o, 10);
                func_001b3748(o, 11);
            }
        }
    } else if (o->flags & 0x80) {
        W1834Sub* s = &o->sub;
        if (!(u8)o->bits.b0) {
            if ((u32)(s->st - 1) < 2) {
                func_0016c168(o, 8);
                if (func_0016a070(o) != 14) {
                    func_001b3748(o, 8);
                    func_001b3748(o, 9);
                }
            }
        }
    }
    func_0017c108(self, o, r);
}
}  // namespace x5
