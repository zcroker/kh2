// Linked unit 0x0011c128-0x0011f7a8 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include <stdarg.h>
#include "../tozawa/menu_sound.hpp"
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
#include "tiny_auto80_solver_structs.hpp"

// 0011c128 (gap function, not written before)
namespace g0011c128 {
// C2 copy of the two-quadword clear at 0x11c138.
void func_0011c128(void* p) asm("func_0011c128");
void func_0011c128(void* p) {
    asm volatile(".set noreorder\n\tsq $0, 0(%0)\n\tsq $0, 16(%0)\n\t.set reorder" : : "r"(p) : "memory");
}
}  // namespace g0011c128

// 0011c138 (was src/anon/probe.cpp)
namespace n0011c138 {
/*TARGET 0011c138*/
// Clears two quadwords.
void func_0011c138(void* p) asm("func_0011c138");
// Clears two quadwords.
void func_0011c138(void* p) {  // vec4_zero
    asm volatile(".set noreorder\n\tsq $0, 0(%0)\n\tsq $0, 16(%0)\n\t.set reorder" : : "r"(p) : "memory");
}
}  // namespace n0011c138

// 0011c148 (was src/anon/batch_wcx2.cpp)
namespace n0011c148 {
struct VA14;
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
struct F11c148 { u64 lo : 51; u64 b51 : 1; u64 b52 : 1; u64 b53 : 1; u64 hi : 10; };
struct O11c148 { u8 pad[0x10]; F11c148 fl; f32 k; u16 h; u16 id; };
u16 func_0011f238(u32, u32) asm("func_0011f238");
/*TARGET 0011c148*/
void func_0011c148(O11c148* o, u32 a, u32 id, u8 x, u8 y, f32 k) asm("func_0011c148");
void func_0011c148(O11c148* o, u32 a, u32 id, u8 x, u8 y, f32 k)
{
    u16 h = func_0011f238(a, id);
    o->k = k;
    o->id = id;
    o->fl.b52 = x != 0;
    o->fl.b51 = y != 0;
    o->fl.b53 = 0;
    o->h = h;
}
}  // namespace n0011c148

// 0011c210 (was src/anon/auto200_999.cpp)
namespace n0011c210 {
/*TARGET 0011c210*/
void func_0011c210(u32 a0) asm("_Z13func_0011c210j");
void func_0011c210(u32 a0) {
    u64 v = *(u64 *)(a0 + 16);
    u64 mask = 1ull << 53;
    *(u64 *)(a0 + 16) = v | mask;
}
}  // namespace n0011c210

// 0011c228 (was src/anon/misc_1.cpp)
namespace n0011c228 {
/*TARGET 0011c228*/
u16 func_0011c228(void* self) asm("_Z13func_0011c228Pv");
u16 func_0011c228(void* self) { return (u16)(*(u16*)((char*)self + 30)); }
}  // namespace n0011c228

// 0011c230 (was src/anon/auto200_999.cpp)
namespace n0011c230 {
/*TARGET 0011c230*/
// 0x0010ef28: definition moved into src/anon/unit_0010dee8.cpp

u64 func_0011c230(u32 a0) asm("_Z13func_0011c230j");
// 0x0010ef28: definition moved into src/anon/unit_0010dee8.cpp

u64 func_0011c230(u32 a0) {
    u64 v = *(u64 *)(a0 + 16);
    return (v >> 53) & 1;
}
}  // namespace n0011c230

// 0011c240 (gap function, not written before)
namespace g0011c240 {
extern u32* D_00347930 asm("D_00347930");
// Walks the live-object list to its end.
void func_0011c240(void) asm("func_0011c240");
void func_0011c240(void) {
    u32* p = D_00347930;
    while (p) p = (u32*)*p;
}
}  // namespace g0011c240

// 0011c278 (gap function, not written before)
namespace g0011c278 {
extern u32 D_00347930 asm("D_00347930");
// C2 copy of the object init at 0x11c2d0.
void func_0011c278(u8* a0) asm("func_0011c278");
void func_0011c278(u8* a0) {
    *(u32*)(a0 + 0x10) = 0;
    *(u32*)(a0 + 0x14) = 0;
    *(u32*)(a0 + 0x18) = 0;
    *(u32*)(a0 + 0x1c) = 0;
    *(u32*)(a0 + 0x20) = 0;
    *(u32*)(a0 + 0x24) = 0;
    *(u32*)(a0 + 0x28) = 0;
    *(u32*)(a0 + 0x2c) = 0;
    *(u32*)(a0 + 0x30) = 0;
    *(u32*)(a0 + 0x34) = 0;
    *(u32*)(a0 + 0x38) = 0;
    *(u32*)(a0 + 0x100) = 0;
    *(u32*)(a0 + 0x104) = 0;
    *(u32*)(a0 + 4) = 0;
    *(u32*)(a0 + 0x124) = 0;

    u32 next = D_00347930;
    *(u32*)(a0 + 0) = next;
    D_00347930 = (u32)a0;

    *(u32*)(a0 + 0x108) = 0;
    *(u32*)(a0 + 0x10c) = 0;
}
}  // namespace g0011c278

// 0011c2d0 (was src/anon/auto80_199_queue.cpp)
namespace n0011c2d0 {
/*TARGET 0011c2d0*/
// 0x0011bdc0: definition moved into src/anon/unit_0011b3f8.cpp

void func_0011c2d0(u8* a0) asm("_Z13func_0011c2d0Ph");
// 0x0011bdc0: definition moved into src/anon/unit_0011b3f8.cpp

void func_0011c2d0(u8* a0) {  // obj_clear_16_onwards
    *(u32*)(a0 + 0x10) = 0;
    *(u32*)(a0 + 0x14) = 0;
    *(u32*)(a0 + 0x18) = 0;
    *(u32*)(a0 + 0x1c) = 0;
    *(u32*)(a0 + 0x20) = 0;
    *(u32*)(a0 + 0x24) = 0;
    *(u32*)(a0 + 0x28) = 0;
    *(u32*)(a0 + 0x2c) = 0;
    *(u32*)(a0 + 0x30) = 0;
    *(u32*)(a0 + 0x34) = 0;
    *(u32*)(a0 + 0x38) = 0;
    *(u32*)(a0 + 0x100) = 0;
    *(u32*)(a0 + 0x104) = 0;
    *(u32*)(a0 + 4) = 0;
    *(u32*)(a0 + 0x124) = 0;

    u32 next = D_00347930;
    *(u32*)(a0 + 0) = next;
    D_00347930 = (u32)a0;

    *(u32*)(a0 + 0x108) = 0;
    *(u32*)(a0 + 0x10c) = 0;
}
}  // namespace n0011c2d0

// 0011c328 (was src/anon/batch_w52.cpp)
namespace n0011c328 {
struct Obj;
typedef void (*ObjFn)(Obj*, ...);
struct Obj {
    ObjFn* vt;
};
struct NoTail {
    ~NoTail() {}
};
void func_0011e350(u8*, u32) asm("func_0011e350");
void func_0011c438(u8*) asm("func_0011c438");
struct Node11c {
    u8 pad[12];
    Node11c* next;
};
/*TARGET 0011c328*/
// Releases the pending handle and every queued node, then tears down.
void func_0011c328(u8* p) asm("func_0011c328");
// Releases the pending handle and every queued node, then tears down.
void func_0011c328(u8* p) {
    if (*(u32*)(p + 40)) {
        Obj* o = *(Obj**)(p + 16);
        o->vt[1](o, *(u32*)(p + 40));
        *(u32*)(p + 40) = 0;
    }
    Node11c* n = *(Node11c**)(p + 292);
    while (n) {
        Obj* o = *(Obj**)(p + 16);
        Node11c* next = n->next;
        o->vt[1](o, n);
        n = next;
    }
    NoTail nt;  // keeps the last call a jal
    func_0011e350(p, *(u32*)(p + 56));
    func_0011c438(p);
}
}  // namespace n0011c328

// 0011c3b0 (was src/anon/batch_w53.cpp)
namespace n0011c3b0 {
// Local with a non-trivial destructor: keeps the final call a jal instead of a sibcall.
struct NoTail { ~NoTail() {} };
struct Node12 { u32 pad[3]; Node12* next; };
typedef void (*Fn1)(void*, void*);
void func_0011e350(u8*, u32) asm("func_0011e350");
void func_0011c438(u8*) asm("func_0011c438");
/*TARGET 0011c3b0*/
// 00109c30: moved to src/anon/unit_00109c30.cpp

// Release the pending entry and every node of the list through the owner's vtable slot 1.
void func_0011c3b0(u8* p) asm("func_0011c3b0");
// 00109c30: moved to src/anon/unit_00109c30.cpp

// Release the pending entry and every node of the list through the owner's vtable slot 1.
void func_0011c3b0(u8* p) {
    NoTail g;
    if (*(void**)(p + 40)) {
        u8* o = *(u8**)(p + 16);
        (*(Fn1*)(*(u8**)o + 4))(o, *(void**)(p + 40));
        *(u32*)(p + 40) = 0;
    }
    for (Node12* n = *(Node12**)(p + 292); n;) {
        u8* o = *(u8**)(p + 16);
        Node12* next = n->next;
        (*(Fn1*)(*(u8**)o + 4))(o, n);
        n = next;
    }
    func_0011e350(p, *(u32*)(p + 56));
    func_0011c438(p);
}
}  // namespace n0011c3b0

// 0011c438 (was src/anon/auto80_199_queue.cpp)
namespace n0011c438 {
/*TARGET 0011c438*/
void func_0011c438(u8* a0) asm("_Z13func_0011c438Ph");
void func_0011c438(u8* a0) {
    u8* s0 = a0;
    func_0011eea8(*(u32*)(a0 + 0x14), (u32)s0);

    u8* t7 = (u8*)D_00347930;
    u8* t5 = 0;

    if (t7 != 0 && t7 != s0) {
        do {
            t5 = t7;
            t7 = *(u8**)t7;
            if (t7 == 0) {
                break;
            }
        } while (t7 != s0);
    }

    if (t5 != 0) {
        *(u32*)t5 = *(u32*)s0;
    } else {
        D_00347930 = *(u32*)s0;
    }
}
}  // namespace n0011c438

// 0011c4b0 (was src/anon/batch_w23.cpp)
namespace n0011c4b0 {
// 0x0011a340: definition moved into src/anon/unit_0011a260.cpp

void func_0011d440(void*) asm("func_0011d440");
/*TARGET 0011c4b0*/
void func_0011c4b0(u8* p) asm("func_0011c4b0");
void func_0011c4b0(u8* p) {
    func_0011d440(p);
    void* o = *(void**)(p + 20);
    (*(void (**)(void*, void*))((*(u8**)o) + 44))(o, p);
}
}  // namespace n0011c4b0

// 0011c4e8 (was src/anon/batch_w111.cpp)
namespace n0011c4e8 {
typedef unsigned int u128 __attribute__((mode(TI)));
struct Mtx11 { u128 q[4]; };
struct VObj11 { void** vt; };
#define MCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t" \
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" \
                         : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
static inline void VScale(void* v, f32 k) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(v), "f"(k) : "$8", "memory");
}
extern Mtx11 D_00347af0 asm("D_00347af0");
extern Mtx11 D_00347b30 asm("D_00347b30");
void func_0011d440(void) asm("func_0011d440");
void func_0011b6a8(Mtx11*) asm("func_0011b6a8");
typedef void (*Fn11a)(VObj11*, u8*, Mtx11*, u32, u32, f32);
typedef void (*Fn11b)(VObj11*, u8*);
#define WORK_MTX(o) ((Mtx11*)((o) + 128))
/*TARGET 0011c4e8*/
void func_0011c4e8(u8* o, Mtx11* m, VObj11* src, u32 a3, u32 a4, Mtx11* m2, f32 f) asm("func_0011c4e8");
void func_0011c4e8(u8* o, Mtx11* m, VObj11* src, u32 a3, u32 a4, Mtx11* m2, f32 f)
{
    func_0011d440();
    if (m) {
        if (WORK_MTX(o) != m) MCOPY(WORK_MTX(o), m);
        VScale(o + 144, -1.0f);
        VScale(o + 160, -1.0f);
    } else func_0011b6a8(WORK_MTX(o));
    if (WORK_MTX(o) != &D_00347af0) MCOPY(&D_00347af0, WORK_MTX(o));
    if (m2) { if (m2 != &D_00347b30) MCOPY(&D_00347b30, m2); }
    else func_0011b6a8(&D_00347b30);
    if (src) ((Fn11a)src->vt[3])(src, o, m, a3, a4, f);
    else { VObj11* p = *(VObj11**)(o + 20); ((Fn11b)p->vt[11])(p, o); }
    *(VObj11**)(o + 24) = src;
    *(u32*)(o + 12) &= ~1;
}
}  // namespace n0011c4e8

// 0011c6a8 (was src/anon/batch_w89.cpp)
namespace n0011c6a8 {
typedef unsigned int u128 __attribute__((mode(TI)));
struct Mtx { u128 q[4]; };
extern Mtx D_00347b30 asm("D_00347b30");
void func_0011d440(void) asm("func_0011d440");
void func_0011b6a8(Mtx*) asm("func_0011b6a8");
void kn__Motion__calc(u8*, u32, u32, u32, u32, u32, f32) asm("kn__Motion__calc");
/*TARGET 0011c6a8*/
// Loads the given matrix (or identity when null) into the shared work matrix, then sets up the object.
void func_0011c6a8(u8* o, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, Mtx* m, f32 f) asm("func_0011c6a8");
// Loads the given matrix (or identity when null) into the shared work matrix, then sets up the object.
void func_0011c6a8(u8* o, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, Mtx* m, f32 f) {
    func_0011d440();
    if (m != 0) {
        if (m != &D_00347b30)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(&D_00347b30), "r"(m) : "$8", "$9", "$10", "$11", "memory");
    } else func_0011b6a8(&D_00347b30);
    kn__Motion__calc(o, a1, a2, a3, a4, a5, f);
    *(u32*)(o + 24) = 0;
    *(u32*)(o + 12) |= 1;
}
}  // namespace n0011c6a8

// 0011c798 (was src/anon/batch_w6.cpp)
namespace n0011c798 {
// Batch w6: small leaf / wrapper functions.

// Object whose first word is a vtable pointer.
struct VObj { void** vt; };
/*TARGET 0011c798*/
// 0x00111278: definition moved into src/anon/unit_00110b00.cpp

void func_0011c798(u8* p, u32 a) asm("func_0011c798");
// 0x00111278: definition moved into src/anon/unit_00110b00.cpp

void func_0011c798(u8* p, u32 a) {
    VObj* o = *(VObj**)(p + 20);
    ((void (*)(VObj*, u32, u32))o->vt[13])(o, *(u32*)(p + 260), a);
}
}  // namespace n0011c798

// 0011c7c8 (was src/anon/batch_w7.cpp)
namespace n0011c7c8 {
struct VObj { void** vtbl; };
/*TARGET 0011c7c8*/
// 0x00119c88: definition moved into src/anon/unit_00119bf8.cpp

// Virtual call (slot 15) on the object at +20, forwarding the field at +260.
void func_0011c7c8(u8* a0, u32 a1) asm("func_0011c7c8");
// 0x00119c88: definition moved into src/anon/unit_00119bf8.cpp

// Virtual call (slot 15) on the object at +20, forwarding the field at +260.
void func_0011c7c8(u8* a0, u32 a1) {
    VObj* o = *(VObj**)(a0 + 20);
    ((void (*)(VObj*, u32, u32))o->vtbl[15])(o, *(u32*)(a0 + 260), a1);
}
}  // namespace n0011c7c8

// 0011c7f8 (was src/anon/batch_w8.cpp)
namespace n0011c7f8 {
typedef void (*VF3)(void*, u32, u32);
/*TARGET 0011c7f8*/
// Copy quadword a -> p+0x50 and b -> p+0x60 (each unless aliasing).
// 001072d0: moved to src/naka/libkn/camera.cpp

// Forward to the owned object's virtual slot 16 with this->field_104.
void func_0011c7f8(u8* self, u32 x) asm("func_0011c7f8");
// Copy quadword a -> p+0x50 and b -> p+0x60 (each unless aliasing).
// 001072d0: moved to src/naka/libkn/camera.cpp

// Forward to the owned object's virtual slot 16 with this->field_104.
void func_0011c7f8(u8* self, u32 x) {
    void** o = *(void***)(self + 20);
    ((VF3)(*(void***)o)[16])(o, *(u32*)(self + 260), x);
}
}  // namespace n0011c7f8

// 0011c828 (was src/anon/batch_w46.cpp)
namespace n0011c828 {
void wtarget_0011c828(u8* o, u32 a1, u32, u32) asm("_Z16wtarget_0011c828jjjj");
// 00106048: moved to src/common/world.cpp

// ---- 0011c828
struct VObj11c { void (**vt)(VObj11c*, u32, u32); };
s32 func_0011f078(VObj11c*, u32) asm("func_0011f078");
/*TARGET 0011c828*/
void wtarget_0011c828(u8* o, u32 a1, u32, u32) asm("_Z16wtarget_0011c828jjjj");
void wtarget_0011c828(u8* o, u32 a1, u32, u32) {
    VObj11c* x = *(VObj11c**)(o + 20);
    x->vt[17](x, *(u32*)(o + 260), a1);
    if (func_0011f078(*(VObj11c**)(o + 20), *(u32*)(o + 260)))
        *(u32*)(o + 12) |= 2;
    else
        *(u32*)(o + 12) &= ~2;
}
}  // namespace n0011c828

// 0011c890 (was src/anon/batch_w1671.cpp)
namespace n0011c890 {
// 001c8e00 static initialiser: moved to src/yasui/libys/mutex.cpp (linked unit).

struct VObj_w1671 { void** vt; };
s32 func_0011f078(void*, s32) asm("func_0011f078");
/*TARGET 0011c890*/
void func_0011c890(u8* a0, s32 a1) asm("func_0011c890");
void func_0011c890(u8* a0, s32 a1) {
    VObj_w1671* o = *(VObj_w1671**)(a0 + 0x14);
    ((void (*)(VObj_w1671*, s32, s32))o->vt[0x48 / 4])(o, *(s32*)(a0 + 0x104), a1);
    if (func_0011f078(*(void**)(a0 + 0x14), *(s32*)(a0 + 0x104))) *(u32*)(a0 + 0xc) |= 2;
    else *(u32*)(a0 + 0xc) &= ~2;
}
}  // namespace n0011c890

// 0011c8f8 (was src/anon/batch_wcx2.cpp)
namespace n0011c8f8 {
typedef s32 (*Fn5)(void*, void*, u32, void*, u32, u32, u8, u32);
struct Obj5 { void** vt; };
s32 func_00132338(u8*) asm("func_00132338");
// get_field8
void func_00132cb8(u8*) asm("func_00132cb8");
u8* func_00132350(u8*) asm("func_00132350");
/*TARGET 0011c8f8*/
s32 func_0011c8f8(u8* p, u8* a1, u8 flag, Obj5* o, u32 a4, u32 a5) asm("func_0011c8f8");
s32 func_0011c8f8(u8* p, u8* a1, u8 flag, Obj5* o, u32 a4, u32 a5)
{
    s32 r = ((Fn5)o->vt[19])(o, p + 64, a4, a1, a5, *(u32*)(p + 56), flag, *(u32*)(a1 + 52));
    if (!flag && (*(u32*)(p + 12) & 2))
        ((Fn5)o->vt[21])(o, p + 64, a4, a1, a5, *(u32*)(p + 56), 0, *(u32*)(a1 + 52));
    if (r || flag) {
        for (u8* q = *(u8**)(p + 56); q; q = func_00132350(q)) {
            if (func_00132338(q) == 1) func_00132cb8(q);  // get_field8
        }
    }
    return r;
}
}  // namespace n0011c8f8

// 0011ca20 (was src/anon/batch_wcx2.cpp)
namespace n0011ca20 {
struct VA14;
struct Mdl11ca20;
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
extern u8 D_0033cc50 asm("D_0033cc50");
struct V11ca20 {
    f32 x, y, z, w;
    V11ca20() {}
    V11ca20(const V11ca20& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V11ca20& operator*=(f32 s) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M11ca20 {
    V11ca20 r[4];
    M11ca20() {}
    M11ca20(const M11ca20& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    M11ca20& operator=(const M11ca20& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    static void mul(M11ca20* o, const M11ca20* a, const M11ca20* b) {
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)" : : "r"(o), "r"(a), "r"(b) : "memory");
    }
    M11ca20 operator*(const M11ca20& b) const {
        M11ca20 o;
        mul(&o, this, &b);
        return o;
    }
} __attribute__((aligned(16)));
struct XfB11ca20 {
    u32 vt;
    M11ca20 m;
    XfB11ca20(const XfB11ca20& o) : m(o.m) { vt = (u32)&D_0033cc50; }
};
struct Xf11ca20 : XfB11ca20 {
    V11ca20 a, b, c;
    f32 s;
};
struct Hdr11ca20 { s16 kind; u8 pad[2]; u32 count; s32 off[1]; };
struct Res11ca20 { u8 pad0[60]; Hdr11ca20* hdr; u8 b64; u8 pad1[11]; M11ca20* xf; };
struct Seq11ca20 { s32 id; };
struct Mdl11ca20 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
    virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17();
    virtual void f18(); virtual void f19(); virtual void f20(); virtual void f21(); virtual void f22();
    virtual s32 frames(s32);
    Seq11ca20* seq;
    u8 pad[4];
    u32 flags;
};
struct Self11ca20 {
    u8 pad0[20];
    Mdl11ca20* mdl;
    u8 pad1[64 - 24];
    M11ca20 world;
    M11ca20 local;
    M11ca20 xf;
    u8 pad2[256 - 256];
    s32 nframes;
    s32 base;
    s32* tbl;
};
Mdl11ca20* func_00124748(Mdl11ca20*, u32) asm("func_00124748");
s32 func_00124788(Mdl11ca20*, u32) asm("func_00124788");
Res11ca20* kn__VU1Draw__draw(Self11ca20*, s32, Mdl11ca20*, s32*, s32) asm("kn__VU1Draw__draw");
Xf11ca20* f11ca20_get(s32) asm("func_00106a60");
void f11ca20_submit(Xf11ca20*) asm("func_001070e8");
/*TARGET 0011ca20*/
Res11ca20* func_0011ca20(Self11ca20* s, const M11ca20* w, const M11ca20* l, s32 arg, u32 idx) asm("func_0011ca20");
Res11ca20* func_0011ca20(Self11ca20* s, const M11ca20* w, const M11ca20* l, s32 arg, u32 idx)
{
    s->local = *l;
    s->local.r[1] *= -1.0f;
    s->local.r[2] *= -1.0f;
    s->world = *w * s->local;
    Mdl11ca20* m = s->mdl;
    Mdl11ca20* o = m;
    s32 multi = 0;
    s32* tbl = s->tbl;
    s32 base = s->base;
    if (m->seq->id == -1) {
        m = func_00124748(m, idx);
        multi = 1;
        s32 k = func_00124788(o, idx);
        tbl = s->tbl + k;
        base = s->base + k;
    }
    Res11ca20* r = kn__VU1Draw__draw(s, arg, m, tbl, base);
    if (!r->xf && (m->flags & 2)) {
        Xf11ca20 x(*f11ca20_get(1));
        M11ca20::mul(&s->xf, &x.m, &s->local);
        r->xf = &s->xf;
        f11ca20_submit(&x);
    }
    s->nframes = m->frames(s->base);
    if (r && r->hdr) {
        Hdr11ca20* h = r->hdr;
        if (h->kind == -1) {
            if (multi) {
                if (idx >= h->count) idx = h->count - 1;
                r->hdr = (Hdr11ca20*)((u8*)h + h->off[idx]);
            } else if (r->b64 == 0) {
                r->hdr = (Hdr11ca20*)((u8*)h + h->off[0]);
            } else if (r->b64 == 255) {
                r->hdr = (Hdr11ca20*)((u8*)h + h->off[1]);
            }
        }
    }
    return r;
}
}  // namespace n0011ca20

// 0011cd80 (was src/anon/batch_w49.cpp)
namespace n0011cd80 {
void func_0011c798(u32, u32) asm("func_0011c798");
void func_0011ca20(u32, u32, u32, u32, u32) asm("func_0011ca20");
/*TARGET 0011cd80*/
void func_0011cd80(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) asm("func_0011cd80");
void func_0011cd80(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    func_0011c798(a, e);
    func_0011ca20(a, b, c, d, f);
}
}  // namespace n0011cd80

// 0011cdf0 (was src/anon/batch_w2473_nsa.cpp)
namespace n0011cdf0 {
struct V11cdf0 {
    f32 x, y, z, w;
    V11cdf0() {}
    V11cdf0(const V11cdf0& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V11cdf0& operator*=(f32 s) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M11cdf0 {
    V11cdf0 r[4];
    M11cdf0() {}
    M11cdf0(const M11cdf0& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    M11cdf0& operator=(const M11cdf0& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    static void mul(M11cdf0* o, const M11cdf0* a, const M11cdf0* b) {
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)" : : "r"(o), "r"(a), "r"(b) : "memory");
    }
    M11cdf0 operator*(const M11cdf0& b) const {
        M11cdf0 o;
        mul(&o, this, &b);
        return o;
    }
} __attribute__((aligned(16)));
extern u8 D_0033cc50[] asm("D_0033cc50");
struct XfB11cdf0 {
    u32 vt;
    M11cdf0 m;
    XfB11cdf0(const XfB11cdf0& o) : m(o.m) { vt = (u32)D_0033cc50; }
};
struct Xf11cdf0 : XfB11cdf0 {
    V11cdf0 a, b, c;
    f32 s;
};
struct Hdr11cdf0 { s16 kind; u8 pad[2]; u32 count; s32 off[1]; };
struct Desc11cdf0 {
    u32 flags;
    u8 b4, b5, b6, b7;
    u8 r, g, b, pad11;
    u8 pad12[4];
    u64 a16;
    u64 a24;
    u32 p32;
    Hdr11cdf0* hdr;
    u8 pad40[12];
    M11cdf0* xf;
} __attribute__((aligned(8)));
struct Seq11cdf0 { s32 id; s32 p4; };
struct Mdl11cdf0 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
    virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18();
    virtual s32 draw(M11cdf0*, s32*, Desc11cdf0*, s32, s32, s32, M11cdf0*);
    Seq11cdf0* seq;
    u8 pad[4];
    u32 flags;
};
struct Self11cdf0 {
    u8 pad0[20];
    Mdl11cdf0* mdl;
    u8 pad1[56 - 24];
    s32 p56;
    u8 pad2[64 - 60];
    M11cdf0 world;
    M11cdf0 local;
    M11cdf0 xf;
    u8 pad3[260 - 256];
    s32 base;
    s32* tbl;
};
Mdl11cdf0* func_00124748(Mdl11cdf0*, u32) asm("func_00124748");
s32 func_00124788(Mdl11cdf0*, u32) asm("func_00124788");
Xf11cdf0* func_00106a60(s32) asm("func_00106a60");
void func_001070e8(Xf11cdf0*) asm("func_001070e8");
void sceGsSyncPath(s32, s32) asm("sceGsSyncPath");
s32 func_00134278() asm("func_00134278");
void func_00109330() asm("func_00109330");
void func_00109340() asm("func_00109340");
void* func_0010ae90() asm("func_0010ae90");
void func_001344b8(s32) asm("func_001344b8");
void func_0010a800(u8*, u8*, u8*) asm("func_0010a800");
void func_00108998(void*) asm("func_00108998");
s32 func_0010abb8(s32) asm("func_0010abb8");
s32 func_00109f58(s32, s32, u8) asm("func_00109f58");
s32 func_00109ea8(s32, s32, u8) asm("func_00109ea8");
void kn__VU1DrawContext__setPacket(void*, s32, u64, u64, s32, s32, u64, u64) asm("kn__VU1DrawContext__setPacket");
void func_00108a10(void*) asm("func_00108a10");
void func_001342a8() asm("func_001342a8");
s32 func_00133d38() asm("func_00133d38");
void func_002f3918(s32, s32) asm("func_002f3918");
/*TARGET 0011cdf0*/
// two-pass model draw (sibling of 0011ca20)
void func_0011cdf0(Self11cdf0* s, const M11cdf0* w, const M11cdf0* l, Desc11cdf0* desc, u32 idx) asm("func_0011cdf0");
// two-pass model draw (sibling of 0011ca20)
void func_0011cdf0(Self11cdf0* s, const M11cdf0* w, const M11cdf0* l, Desc11cdf0* desc, u32 idx)
{
    s->local = *l;
    s->local.r[1] *= -1.0f;
    s->local.r[2] *= -1.0f;
    s->world = *w * s->local;
    Mdl11cdf0* m = s->mdl;
    Mdl11cdf0* o = m;
    s32* tbl = s->tbl;
    if (m->seq->id == -1) {
        m = func_00124748(m, idx);
        tbl = s->tbl + func_00124788(o, idx);
    }
    Desc11cdf0 d = *desc;
    Hdr11cdf0* h = d.hdr;
    if (h && h->kind == -1) {
        if (idx >= h->count) idx = h->count - 1;
        d.hdr = (Hdr11cdf0*)((u8*)h + h->off[idx]);
    }
    sceGsSyncPath(0, 0);
    s32 saved = func_00134278();
    func_00109330();
    func_00109340();
    void* pk = func_0010ae90();
    func_001344b8(64);
    u8 rgb[3];
    if (!(desc->flags & 2)) {
        func_0010a800(&rgb[0], &rgb[1], &rgb[2]);
    } else {
        rgb[0] = desc->r;
        rgb[1] = desc->g;
        rgb[2] = desc->b;
    }
    func_00108998(pk);
    s32 mode = 5;
    if (m->seq->id != 2) mode = 7;
    s32 old = func_0010abb8(mode);
    {
    s32 a = func_00109f58(mode, m->seq->p4, desc->b7);
    s32 b = func_00109ea8(mode, m->seq->p4, desc->b7);
    kn__VU1DrawContext__setPacket(pk, 63, desc->a16, desc->a24 & ~((u64)1 << 32), b, a,
                  (u64)rgb[0] | ((u64)rgb[1] << 8) | ((u64)rgb[2] << 16),
                  (u64)desc->b4 | ((u64)desc->b5 << 8) | ((u64)desc->b6 << 16) | ((u64)desc->b7 << 24) | ((u64)127 << 55));
    }
    M11cdf0* xf = desc->xf;
    if (!xf && (m->flags & 2)) {
        Xf11cdf0 x(*func_00106a60(1));
        M11cdf0::mul(&s->xf, &x.m, &s->local);
        xf = &s->xf;
        func_001070e8(&x);
    }
    if (!m->draw(&s->world, tbl, &d, s->base, s->p56, 0, xf)) {
        mode = 8;
        if (m->seq->id != 2) mode = 11;
        func_0010abb8(mode);
        s32 a2 = func_00109f58(mode, m->seq->p4, desc->b7);
        s32 b2 = func_00109ea8(mode, m->seq->p4, desc->b7);
        kn__VU1DrawContext__setPacket(pk, 63, desc->a16 | ((u64)-1 << 56), desc->a24 | ((u64)1 << 32), b2, a2,
                      (u64)rgb[0] | ((u64)rgb[1] << 8) | ((u64)rgb[2] << 16),
                      (u64)desc->b4 | ((u64)desc->b5 << 8) | ((u64)desc->b6 << 16) | ((u64)desc->b7 << 24) | ((u64)127 << 55));
        m->draw(&s->world, tbl, &d, s->base, s->p56, 1, xf);
    }
    func_00108a10(pk);
    func_001342a8();
    func_0010abb8(old);
    func_002f3918(func_00133d38(), saved);
    sceGsSyncPath(0, 0);
}
}  // namespace n0011cdf0

// 0011d3d0 (gap function, not written before)
namespace g0011d3d0 {
void func_0011c798(u8* p, u32 a) asm("func_0011c798");
u32 func_0011cdf0(u8*, u32, u32, u32, u32) asm("func_0011cdf0");
u32 func_0011d3d0(u8* p, u32 a, u32 b, u32 c, u32 d, u32 e) asm("func_0011d3d0");
u32 func_0011d3d0(u8* p, u32 a, u32 b, u32 c, u32 d, u32 e) {
    func_0011c798(p, d);
    return func_0011cdf0(p, a, b, c, e);
}
}  // namespace g0011d3d0

// 0011d440 (was src/anon/tiny_auto80.cpp)
namespace n0011d440 {
void func_0011d440(u32*, u32, u32, u32) asm("_Z13func_0011d440jjjj");
/*TARGET 0011d440*/
// 0x00113450: definition moved into src/anon/unit_001117d8.cpp

// 0x00113450: definition moved into src/anon/unit_001117d8.cpp

void func_0011d440(u32* p, u32, u32, u32) {
    u32 a = p[11], b = p[12], c = p[66], d = p[67];
    p[11] = b; p[12] = a; p[66] = d; p[67] = c;
}
}  // namespace n0011d440

// 0011d468 (was src/anon/batch_w51.cpp)
namespace n0011d468 {
/*TARGET 0011d468*/
// 0x00111808: definition moved into src/anon/unit_001117d8.cpp

// Copy matrix i of the table into m, then negate its Y and Z columns.
void func_0011d468(u8* p, s32 i, f32* m) asm("func_0011d468");
// 0x00111808: definition moved into src/anon/unit_001117d8.cpp

// Copy matrix i of the table into m, then negate its Y and Z columns.
void func_0011d468(u8* p, s32 i, f32* m) {
    u8* s = *(u8**)(p + 44) + (i << 6);
    if ((u8*)m != s)
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(m), "r"(s) : "$8", "$9", "$10", "$11", "memory");
    m[1] = -m[1];
    m[5] = -m[5];
    m[9] = -m[9];
    m[13] = -m[13];
    m[2] = -m[2];
    m[6] = -m[6];
    m[10] = -m[10];
    m[14] = -m[14];
}
}  // namespace n0011d468

// 0011d500 (gap function, not written before)
namespace g0011d500 {
typedef unsigned int u128 __attribute__((mode(TI)));
struct Mtx {
    f32 m[4][4];
    Mtx& operator=(const Mtx& s) {
        if (this != &s)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&s) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct O { u8 pad[44]; Mtx* mtx; };
// Stores a matrix into slot i and mirrors it (negates the Y and Z columns).
void func_0011d500(O* o, s32 i, const Mtx* m) asm("func_0011d500");
void func_0011d500(O* o, s32 i, const Mtx* m) {
    s32 off = i << 6;
    *(Mtx*)((u8*)o->mtx + off) = *m;
#define M(r,c) ((Mtx*)((u8*)o->mtx + off))->m[r][c]
    M(0,1) = -M(0,1); M(1,1) = -M(1,1); M(2,1) = -M(2,1); M(3,1) = -M(3,1);
    M(0,2) = -M(0,2); M(1,2) = -M(1,2); M(2,2) = -M(2,2); M(3,2) = -M(3,2);
#undef M
}
}  // namespace g0011d500

// 0011d5e0 (was src/anon/batch_w1806_nsa.cpp)
namespace n0011d5e0 {
#define W1806_QC(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1806Vec {
    f32 x, y, z, w;
    W1806Vec() {}
    W1806Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1806Vec(const W1806Vec& o) { W1806_QC(this, &o); }
    W1806Vec& operator=(const W1806Vec& o) { if (this != &o) W1806_QC(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1806Mtx {
    W1806Vec r[4];
    W1806Vec operator*(const W1806Vec& v) const {
        W1806Vec o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct W1806Elem { u8 pad[28]; f32 len; u8 pad2[32]; };
struct W1806Src {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual W1806Elem* get();
};
struct W1806Obj { u8 pad[20]; W1806Src* src; u8 pad2[20]; W1806Mtx* mtx; };
/*TARGET 0011d5e0*/
void func_0011d5e0(W1806Obj* o, s32 i, W1806Vec* out, f32 s) asm("func_0011d5e0");
void func_0011d5e0(W1806Obj* o, s32 i, W1806Vec* out, f32 s) {
    W1806Elem* e = &o->src->get()[i];
    W1806Vec v(e->len * s, 0.0f, 0.0f, 1.0f);
    *out = o->mtx[i] * v;
    out->y = -out->y;
    out->z = -out->z;
}
}  // namespace n0011d5e0

// 0011d6c0 (was src/anon/tiny_auto80_queue.cpp)
namespace n0011d6c0 {
u32 func_0011d468(...) asm("func_0011d468");
/*TARGET 0011d6c0*/
f32 func_0011d6c0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0011d6c0jjjjjjjj");
f32 func_0011d6c0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 s0 = a1;
    u32 s1 = a0;
    func_0011d468(a0, a1, a2, a3, a4, a5, a6, a7);
    s0 = (u32)((u32)s0 << 6);
    u32 r4 = *(u32*)((u32)s1 + (s32)(20));
    u32 t7 = *(u32*)((u32)r4 + (s32)(0));
    u32 v0 = ((u32(*)(u32))(*(u32*)((u32)t7 + (s32)(32))))(r4);
    v0 = (u32)(v0 + s0);
    return *(f32*)((u32)v0 + (s32)(28));
}
}  // namespace n0011d6c0

// 0011d710 (was src/anon/tiny.cpp)
namespace n0011d710 {
// int_to_float_scaled
void func_00127a88(void*) asm("_Z13func_00127a88Pv");
/*TARGET 0011d710*/
// 0x0010f648: definition moved into src/anon/unit_0010f338.cpp
void func_0011d710(BD_VALUE* bd) asm("_Z13func_0011d710P8BD_VALUE");
// 0x0010f648: definition moved into src/anon/unit_0010f338.cpp
void func_0011d710(BD_VALUE* bd) { func_00127a88(bd); }
}  // namespace n0011d710

// 0011d728 (gap function, not written before)
namespace g0011d728 {
u32 func_00127c70(u32, u32, u32, u32) asm("func_00127c70");
u32 func_0011d728(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_0011d728");
u32 func_0011d728(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00127c70(a0, a1, a2, a3);
}
}  // namespace g0011d728

// 0011d740 (was src/anon/batch_w3856_nsamam.cpp)
namespace n0011d740 {
struct Self11d740;
struct V11d740 {
    f32 x, y, z, w;
    V11d740() {}
    V11d740& operator*=(f32 s) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M11d740 {
    V11d740 r[4];
    M11d740() {}
    M11d740& operator=(const M11d740& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    static void mul(M11d740* o, const M11d740* a, const M11d740* b) {
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)" : : "r"(o), "r"(a), "r"(b) : "memory");
    }
    M11d740 operator*(const M11d740& b) const {
        M11d740 o;
        mul(&o, this, &b);
        return o;
    }
} __attribute__((aligned(16)));
struct Desc11d740 {
    u32 flags;
    bool lit() const { return flags & 1; }
    u8 ulit() const { u32 f = flags; return f & 1; }
    u8 b4, b5, b6, b7;
    u8 pad8[8];
    u64 a16;
    u64 a24;
};
struct Pkt11d740 {
    s32 kind;
    u8 r, g, b, a;
    u8 c8[4];
    u8 pad12[4];
    u64 frame;
    u64 zbuf;
    s32 f32, f36;
    u8 c40[4];
    s32 f44, f48, f52;
};
struct Seq11d740 { s32 id; };
struct Mdl11d740 {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
    virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual void f12();
    virtual void begin(s32, s32);
    virtual void f14(); virtual void f15(); virtual void f16(); virtual void f17(); virtual void f18();
    virtual s32 draw(M11d740*, s32, Pkt11d740*, s32, s32, s32, s32);
    virtual s32 draw2(M11d740*, s32, Pkt11d740*, s32, s32, s32, s32);
    virtual void f21();
    virtual s32 drawm(s32, s32, Desc11d740*, s32, s32, M11d740*);
    Seq11d740* seq;
};
struct Self11d740 {
    u8 pad0[20];
    Mdl11d740* mdl;
    u8 pad1[52 - 24];
    s32 p52;
    s32 p56;
    u8 pad2[260 - 60];
    s32 base;
    s32 tbl;
};
struct Item11d740 {
    Self11d740* obj;
    u8 pad4[11];
    u8 alpha;
    u8 pad16[52 - 16];
    s32 f52;
    u8 pad56[8];
    M11d740 m;
};
s32 func_0010ae90() asm("func_0010ae90");
void func_0010a918(s32) asm("func_0010a918");
void func_00108698(Pkt11d740*) asm("func_00108698");
Mdl11d740* func_00124748(Mdl11d740*, u32) asm("func_00124748");
void func_0010ab08(s32) asm("func_0010ab08");
void func_00134408() asm("func_00134408");
void func_00134428(s32, u64) asm("func_00134428");
void func_00134450(s32) asm("func_00134450");
void func_00108998(s32) asm("func_00108998");
void func_0011f120(Mdl11d740*, s32) asm("func_0011f120");
void func_0011f1a8(Mdl11d740*, s32) asm("func_0011f1a8");
/*TARGET 0011d740*/
// draw a null-terminated list of child models under a parent matrix, then the owner's own model
void func_0011d740(Self11d740* s, s32 a1, Desc11d740* desc, s32 a3, M11d740* own, M11d740* parent, Item11d740** list, s32 mode) asm("func_0011d740");
// draw a null-terminated list of child models under a parent matrix, then the owner's own model
void func_0011d740(Self11d740* s, s32 a1, Desc11d740* desc, s32 a3, M11d740* own, M11d740* parent, Item11d740** list, s32 mode)
{
    s32 pk = func_0010ae90();
    if (list) {
        func_0010a918(mode);
        M11d740 local;
        Pkt11d740 pkt;
        func_00108698(&pkt);
        u64 v;
        switch (mode) {
        case 0: v = 0x10140; break;
        case 1: v = 0x20140; break;
        case 2: v = 0x40140; break;
        default: v = 0; break;
        }
        pkt.frame = v;
        switch (mode) {
        case 0: v = 0x30000142; break;
        case 1: v = 0x30000148; break;
        case 2: v = 0x30000160; break;
        default: v = 0; break;
        }
        pkt.zbuf = v;
        u32 fl = ((Pkt11d740*)desc)->kind;
        pkt.kind = 2;
        u8 b = fl & 1;
        if (!b) {
            pkt.r = 0;
            pkt.g = 0;
            pkt.b = 0;
        }
        pkt.a = desc->b7;
        for (Item11d740** p = list; *p; p++) {
            local = (*p)->m;
            local.r[1] *= -1.0f;
            local.r[2] *= -1.0f;
            local = *parent * local;
            Self11d740* o = (*p)->obj;
            Mdl11d740* m = o->mdl;
            if (m->seq->id == -1) {
                m = func_00124748(m, 0);
                if (!m) m = o->mdl;
            }
            Item11d740* it = *p;
            s32 al = it->alpha * desc->b7;
            pkt.f44 = it->f52;
            u32 fl2 = ((Pkt11d740*)desc)->kind; // desc->flags
            u8 c = fl2 & 1;
            pkt.a = al >> 7;
            if (c) {
                pkt.f36 = o->p52;
                if (!m->draw(&local, o->tbl, &pkt, o->base, s->p56, 0, 0))
                    m->draw(&local, o->tbl, &pkt, o->base, s->p56, 1, 0);
            } else {
                if (!m->draw2(&local, o->tbl, &pkt, o->base, s->p56, 0, 0))
                    m->draw2(&local, o->tbl, &pkt, o->base, s->p56, 1, 0);
            }
        }
        if (!(desc->lit())) func_0010ab08(mode);
        func_00134408();
        func_00134428(76, 0x800d8);
        func_00134428(78, 0x31000070);
        func_00134428(71, 0x5000d);
        func_00134428(24, 0x730000007000ULL);
        func_00134428(64, 0x019f000001ff0000ULL);
        func_00134450(1);
    }
    func_00108998(pk);
    func_00134408();
    u64 t;
    if (!(desc->lit())) {
        switch (mode) {
        case 0: t = 0x598006840ULL; break;
        case 1: t = 0x5dc00a900ULL; break;
        case 2: t = 0x620012c00ULL; break;
        default: t = 0; break;
        }
    } else {
        switch (mode) {
        case 0: t = 0x598006800ULL; break;
        case 1: t = 0x5dc00a800ULL; break;
        case 2: t = 0x620012800ULL; break;
        default: t = 0; break;
        }
    }
    func_00134428(6, t);
    func_00134428(66, 0x8000000044ULL);
    func_00134428(76, desc->a16);
    func_00134428(78, desc->a24 | 0xff00000000000000ULL);
    func_00134428(71, 0x5000d);
    func_00134450(1);
    desc->b7 = 0x80;
    func_0011f120(s->mdl, s->base);
    s->mdl->begin(s->base, a3);
    M11d740 local2;
    local2 = *own;
    if (!s->mdl->drawm(a1, s->tbl, desc, s->base, 0, &local2))
        s->mdl->drawm(a1, s->tbl, desc, s->base, 1, &local2);
    func_0011f1a8(s->mdl, s->base);
}
}  // namespace n0011d740

// 0011dd08 (was src/anon/batch_w1938.cpp)
namespace n0011dd08 {
struct W1938Obj { u8 pad[0xd0]; f32 mn[3]; f32 mx[3]; };
struct W1938V4 { f32 x, y, z, w; };
/*TARGET 0011dd08*/
void func_0011dd08(W1938V4* out, W1938Obj** list) asm("func_0011dd08");
void func_0011dd08(W1938V4* out, W1938Obj** list) {
    W1938V4 mn, mx;
    W1938Obj* p = *list;
    list++;
    W1938Obj* q = *list;
    mn.x = p->mn[0]; mn.y = p->mn[1]; mn.z = p->mn[2]; mn.w = 1.0f;
    mx.x = p->mx[0]; mx.y = p->mx[1]; mx.z = p->mx[2]; mx.w = 1.0f;
    if (q) {
        W1938Obj* n;
        do {
        if (q->mn[0] < mn.x) mn.x = q->mn[0];
        if (q->mn[1] < mn.y) mn.y = q->mn[1];
        if (q->mn[2] < mn.z) mn.z = q->mn[2];
        if (mx.x < q->mx[0]) mx.x = q->mx[0];
        if (mx.y < q->mx[1]) mx.y = q->mx[1];
        if (mx.z < q->mx[2]) mx.z = q->mx[2];
            list++;
            n = *list;
            q = n;
        } while (n);
    }
    for (s32 i = 0; i < 8; i++) {
        out[i].w = 1.0f;
        if (i & 2) {
            out[i].x = mx.x;
            out[i].y = (u8)(i & 1) ? mn.y : mx.y;
        } else {
            out[i].x = mn.x;
            out[i].y = (u8)(i & 1) ? mx.y : mn.y;
        }
        out[i].z = (i & 4) ? mx.z : mn.z;
    }
}
}  // namespace n0011dd08

// 0011de88 (was src/anon/batch_w2428_gnsa.cpp)
namespace n0011de88 {
struct V11de88 {
    f32 x, y, z, w;
    V11de88() {}
    ~V11de88() {}
    V11de88& operator=(const V11de88& o) {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V11de88 operator+(const V11de88& b) const {
        V11de88 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V11de88 operator-(const V11de88& b) const {
        V11de88 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V11de88 operator*(f32 s) const {
        V11de88 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    f32 length() const {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
struct R11de88 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M11de88 {
    R11de88 r[4];
    M11de88() {}
    M11de88(const M11de88& o) {
        asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    M11de88& operator=(const M11de88& o) {
        if (this != &o)
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    M11de88 operator*(const M11de88& b) const {
        M11de88 o;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
            "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\t"
            "vmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\t"
            "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct Kind11de88 { s32 kind; };
struct Res11de88 { u8 pad[4]; Kind11de88* k; };
struct Self11de88 { u8 pad0[20]; Res11de88* res; u8 pad1[64 - 24]; M11de88 m64; M11de88 m128; };
struct Desc11de88 { u32 flags; };
struct Out11de88 { R11de88 v[4]; };
struct Mat11de88 { M11de88 m; R11de88 e[2]; };
void cam11de88_dtor(void*) asm("_Z13func_00134d58Pv");
void func_0011dd08(V11de88*, void*) asm("func_0011dd08");
void func_00134d10(void*) asm("func_00134d10");
void func_00134d60(void*, V11de88*) asm("func_00134d60");
void gm__CONVERT__CreateModel(void*, V11de88*, Out11de88*, Mat11de88*, void*) asm("gm__CONVERT__CreateModel");
void* func_00135640(void) asm("func_00135640");
void func_0011be50(M11de88*) asm("func_0011be50");
void func_0010abf0(Self11de88*, M11de88*, Desc11de88*, void*, Mat11de88*, Out11de88*, void*, void*) asm("func_0010abf0");
struct Cam11de88 {
    V11de88 pos;
    f32 f[4];
    Cam11de88() { func_00134d10(this); }
    ~Cam11de88() { cam11de88_dtor(this); }
};
/*TARGET 0011de88*/
void func_0011de88(Self11de88* s, Desc11de88* d, void* a2, void* a3, void* e) asm("func_0011de88");
void func_0011de88(Self11de88* s, Desc11de88* d, void* a2, void* a3, void* e)
{
    Out11de88 o;
    Mat11de88 mt;
    V11de88 box[8];
    func_0011dd08(box, a3);
    if (d->flags & 1) {
        Cam11de88 c;
        V11de88 ctr;
        ctr = (box[0] + box[6]) * 0.5f;
        ctr.y -= (box[6] - box[0]).length() * 8.0f;
        func_00134d60(&c, &ctr);
        gm__CONVERT__CreateModel(&c, box, &o, &mt, e);
    } else {
        gm__CONVERT__CreateModel(func_00135640(), box, &o, &mt, e);
    }
    if (s->res->k->kind != 2) {
        M11de88 t(s->m64);
        func_0011be50(&t);
        mt.m = mt.m * s->m128 * t;
    } else {
        mt.m = mt.m * s->m128;
    }
    func_0010abf0(s, &s->m64, d, a2, &mt, &o, a3, e);
}
}  // namespace n0011de88

// 0011e260 (was src/anon/batch_w90.cpp)
namespace n0011e260 {
// 0011e260: attach a chunk list, then process element 0 and every (0, i) pair.
void* func_00132068(void*, s32) asm("func_00132068");
// entry_get_by_index
void* func_00132018(void*) asm("func_00132018");
// entry_ptr_from_header
void func_0011e410(void*, void*) asm("func_0011e410");
void func_0011e450(void*, void*) asm("func_0011e450");
void kn__ModelObj__synchronizeAnimation(void*, void*, void*) asm("kn__ModelObj__synchronizeAnimation");
struct ChunkList { s16 tag; s16 pad; u32 n; };
struct ChunkUser { u8 pad[52]; ChunkList* list; };
static inline void* ChunkAt(ChunkList* c, s32 i) { return func_00132018(func_00132068(c, i)); }
/*TARGET 0011e260*/
void func_0011e260(ChunkUser* self, ChunkList* c) asm("func_0011e260");
void func_0011e260(ChunkUser* self, ChunkList* c)
{
    self->list = c;
    func_0011e410(self, ChunkAt(self->list, 0));
    if (self->list && self->list->tag == -1) {
        for (u32 i = 1; i < self->list->n; i++) {
            func_0011e450(self, ChunkAt(self->list, i));
            void* a = ChunkAt(self->list, 0);
            kn__ModelObj__synchronizeAnimation(self, a, ChunkAt(self->list, i));
        }
    }
}
}  // namespace n0011e260

// 0011e350 (was src/anon/batch_w43.cpp)
namespace n0011e350 {
void* func_00132350(void*) asm("func_00132350");
/*TARGET 0011e350*/
void ctarget_0011e350(u32 a, u32 b, u32, u32) asm("_Z16ctarget_0011e350jjjj");
void ctarget_0011e350(u32 a, u32 b, u32, u32) {
    u8* s = (u8*)a;
    u8* o = (u8*)b;
    while (o) {
        u8* n = (u8*)func_00132350(o);
        (*(void (**)(void*))(*(u8**)o + 0))(o);
        u8* q = *(u8**)(s + 16);
        (*(void (**)(void*, void*))(*(u8**)q + 4))(q, o);
        o = n;
    }
}
}  // namespace n0011e350

// 0011e3c8 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n0011e3c8 {
u32 func_0011e350(u32, u32, u32, u32) asm("_Z13func_0011e350jjjj");
/*TARGET 0011e3c8*/
// 00106520: moved to src/anon/unit_00106490.cpp

u32 func_0011e3c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0011e3c8jjjj");
// 00106520: moved to src/anon/unit_00106490.cpp

u32 func_0011e3c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u, r17 = 0u;
    r17 = r5;
    r16 = r4;
    r5 = *(u32*)((u32)r4 + (s32)(56));
    r2 = func_0011e350(r4, r5, r6, r7);
    *(u32*)((u32)r16 + (s32)(56)) = r17;
    return r2;
}
}  // namespace n0011e3c8

// 0011e400 (gap function, not written before)
namespace g0011e400 {
u32 func_0011e400(u8* p) asm("func_0011e400");
u32 func_0011e400(u8* p) {
    u32 r = *(u32*)(p + 56);
    *(u32*)(p + 56) = 0;
    return r;
}
}  // namespace g0011e400

// 0011e410 (was src/anon/batch_w21.cpp)
namespace n0011e410 {
void func_0011e350(void*, u32) asm("func_0011e350");
void func_0011e450(void*, u32) asm("func_0011e450");
/*TARGET 0011e410*/
void func_0011e410(u8* p, u32 a) asm("func_0011e410");
void func_0011e410(u8* p, u32 a) {
    func_0011e350(p, *(u32*)(p + 56));
    *(u32*)(p + 56) = 0;
    func_0011e450(p, a);
}
}  // namespace n0011e410

// 0011e450 (was src/anon/batch_w112.cpp)
namespace n0011e450 {
struct Node { void** vt; };
struct Alloc { void** vt; };
struct Owner { u8 pad[16]; Alloc* alloc; u8 pad2[36]; Node* list; };
typedef Node* (*AllocFn)(Alloc*, u32, u32);
typedef void (*LoadFn)(Node*, void*);
void* func_00132350(Node*) asm("func_00132350");
void* func_00132180(void*, u32) asm("func_00132180");
void* func_00132130(void*) asm("func_00132130");
void kn__TEXAnmWork__TEXAnmWork(Node*, void*) asm("kn__TEXAnmWork__TEXAnmWork");
void func_00133198(Node*, void*) asm("func_00133198");
void func_00132358(Node*, Node*) asm("func_00132358");
/*TARGET 0011e450*/
// Builds TEXA (texture) and UVSC (uv scroll) nodes from a chunk list and appends them to the owner's list.
void func_0011e450(Owner* o, void* c) asm("func_0011e450");
// Builds TEXA (texture) and UVSC (uv scroll) nodes from a chunk list and appends them to the owner's list.
void func_0011e450(Owner* o, void* c) {
    Node* tail;
    void* ch;
    if (!c) return;
    tail = o->list;
    while (tail && func_00132350(tail)) tail = (Node*)func_00132350(tail);
    for (ch = func_00132180(c, 0x41584554); ch; ch = func_00132180(func_00132130(ch), 0x41584554)) {
        Node* n = ((AllocFn)o->alloc->vt[0])(o->alloc, 656, 0);
        kn__TEXAnmWork__TEXAnmWork(n, c);
        ((LoadFn)n->vt[2])(n, ch);
        if (!tail) o->list = n;
        else func_00132358(tail, n);
        tail = n;
    }
    for (ch = func_00132180(c, 0x43535655); ch; ch = func_00132180(func_00132130(ch), 0x43535655)) {
        Node* n = ((AllocFn)o->alloc->vt[0])(o->alloc, 44, 0);
        func_00133198(n, c);
        ((LoadFn)n->vt[2])(n, ch);
        if (!tail) o->list = n;
        else func_00132358(tail, n);
        tail = n;
    }
}
}  // namespace n0011e450

// 0011e600 (was src/anon/batch_w1967.cpp)
namespace n0011e600 {
struct W1967Anim;
struct W1967AnimVt { u8 pad[0x20]; s32 (*canLink)(W1967Anim*, W1967Anim*); };
struct W1967Anim { W1967AnimVt* vt; };
struct W1967Owner { u8 pad[0x38]; W1967Anim* head; };
s32 w1967_getType(void*) asm("_Z13func_00132330Pv");
W1967Anim* w1967_getSub(void*) asm("_Z13func_00132360Pv");
void w1967_link(void*, s32) asm("_Z13func_00132368Pvi");
W1967Anim* w1967_getNext(void*) asm("_ZNK2kn13AnimationWork7getNextEv");
/*TARGET 0011e600*/
// 0x00190b30: definition moved into src/anon/unit_001900d0.cpp

void kn__ModelObj__synchronizeAnimation(W1967Owner* self, s32 a, s32 b) asm("kn__ModelObj__synchronizeAnimation");
// 0x00190b30: definition moved into src/anon/unit_001900d0.cpp

void kn__ModelObj__synchronizeAnimation(W1967Owner* self, s32 a, s32 b) {
    W1967Anim* p1;
    W1967Anim* p;
    W1967Anim* q;
    if (a == 0 || b == 0 || a == b) return;
    p1 = self->head;
    if (!p1) return;
    do {
        if (w1967_getType(p1) == a || w1967_getType(p1) == b) {
            q = w1967_getSub(p1);
            if (q && (w1967_getType(q) == a || w1967_getType(q) == b)) {
                w1967_link(p1, 0);
            }
        }
    } while ((p1 = w1967_getNext(p1)) != 0);
    p = self->head;
    if (!p) return;
    do {
        if (w1967_getType(p) == a) {
            for (q = w1967_getNext(p); q; q = w1967_getNext(q)) {
                if (w1967_getType(q) == b && q->vt->canLink(q, p)) {
                    w1967_link(q, (s32)p);
                }
            }
        }
    } while ((p = w1967_getNext(p)) != 0);
    p = self->head;
    if (!p) return;
    do {
        if (w1967_getType(p) == b) {
            for (q = w1967_getNext(p); q; q = w1967_getNext(q)) {
                if (w1967_getType(q) == a && q->vt->canLink(q, p)) {
                    w1967_link(q, (s32)p);
                }
            }
        }
    } while ((p = w1967_getNext(p)) != 0);
}
}  // namespace n0011e600

// 0011e7e0 (was src/anon/batch_w1777.cpp)
namespace n0011e7e0 {
struct N1777;
typedef s32 (*N1777Fn)(N1777*, s32, s32, s32);
struct N1777 { N1777Fn* vt; };
struct O1777 { u8 pad[0x38]; N1777* first; };
N1777* anim_next_1777(N1777*) asm("_ZNK2kn13AnimationWork7getNextEv");
/*TARGET 0011e7e0*/
N1777* func_0011e7e0(O1777* o, N1777* from, s32 a, s32 b, s32 c) asm("func_0011e7e0");
N1777* func_0011e7e0(O1777* o, N1777* from, s32 a, s32 b, s32 c) {
    N1777* n = from;
    if (n == 0) n = o->first;
    else n = anim_next_1777(n);
    while (n) {
        if (n->vt[3](n, a, b, c)) return n;
        n = anim_next_1777(n);
    }
    return 0;
}
}  // namespace n0011e7e0

// 0011e880 (was src/anon/batch_w52.cpp)
namespace n0011e880 {
struct Obj;
typedef void (*ObjFn)(Obj*, ...);
struct Obj {
    ObjFn* vt;
};
Obj* func_0011e7e0(u32, Obj*, u32, u32, u32) asm("func_0011e7e0");
/*TARGET 0011e880*/
// Visits every match from func_0011e7e0 and calls its slot-4 virtual.
void func_0011e880(u32 a, u32 b, u32 c, u32 d) asm("func_0011e880");
// Visits every match from func_0011e7e0 and calls its slot-4 virtual.
void func_0011e880(u32 a, u32 b, u32 c, u32 d) {
    Obj* o = 0;
    while ((o = func_0011e7e0(a, o, b, c, d)) != 0) o->vt[4](o, c, d);
}
}  // namespace n0011e880

// 0011e918 (gap function, not written before)
namespace g0011e918 {
struct N;
typedef void (*NFn)(N*);
struct N { NFn* vt; };
N* func_0011e7e0(u8* o, N* from, s32 a, s32 b, s32 c) asm("func_0011e7e0");
// Calls slot 6 of every node that the search at 0x11e7e0 returns.
void func_0011e918(u8* o, s32 a, s32 b, s32 c) asm("func_0011e918");
void func_0011e918(u8* o, s32 a, s32 b, s32 c) {
    N* n = 0;
    while ((n = func_0011e7e0(o, n, a, b, c)) != 0) n->vt[6](n);
}
}  // namespace g0011e918

// 0011e9a8 (was src/anon/batch_w53.cpp)
namespace n0011e9a8 {
void wtarget_0011e9a8(u32, u32, u32, u32, f32) asm("_Z16wtarget_0011e9a8jjjj");
void* func_0011e7e0(u32, void*, u32, u32, u32) asm("func_0011e7e0");
void func_00132370(void*, f32) asm("func_00132370");
/*TARGET 0011e9a8*/
void wtarget_0011e9a8(u32 a, u32 b, u32 c, u32 d, f32 x) asm("_Z16wtarget_0011e9a8jjjj");
void wtarget_0011e9a8(u32 a, u32 b, u32 c, u32 d, f32 x) {
    void* p = 0;
    while ((p = func_0011e7e0(a, p, b, c, d)) != 0) func_00132370(p, x);
}
}  // namespace n0011e9a8

// 0011ea40 (was src/anon/batch_w29.cpp)
namespace n0011ea40 {
typedef void (*VFnF)(void*, f32);
void* anim_getNext(void* w) asm("_ZNK2kn13AnimationWork7getNextEv");
/*TARGET 0011ea40*/
// Calls a virtual method (slot 5) with t on every animation work in o's list.
void kn__ModelObj__playAnimation(u8* o, f32 t) asm("kn__ModelObj__playAnimation");
// Calls a virtual method (slot 5) with t on every animation work in o's list.
void kn__ModelObj__playAnimation(u8* o, f32 t) {
    void* p = *(void**)(o + 56);
    while (p) {
        (*(VFnF*)((*(u8**)p) + 20))(p, t);
        p = anim_getNext(p);
    }
}
}  // namespace n0011ea40

// 0011ea98 (was src/anon/auto80_199_queue.cpp)
namespace n0011ea98 {
/*TARGET 0011ea98*/
void kn__ModelObj__setTexanm(u32 a0, u32 a1) asm("_Z23kn__ModelObj__setTexanmjj");
void kn__ModelObj__setTexanm(u32 a0, u32 a1) {
    u32 s0 = *(u32*)(a0 + 0x38);
    u32 s1 = a1;

    while (s0 != 0) {
        u32 t7 = *(u32*)s0;
        u32 v0 = ((Fn4)(*(u32*)(t7 + 0xc)))(s0, 1, 0xffff, s1);
        if (v0 != 0) {
            kn__TEXAnmWork__set(s0, s1);
        }
        v0 = func_00132350(s0);
        if (v0 != 0) {
            s0 = v0;
            continue;
        }
        break;
    }
}
}  // namespace n0011ea98

// 0011eb08 (was src/anon/auto80_199_queue.cpp)
namespace n0011eb08 {
/*TARGET 0011eb08*/
void kn__ModelObj__setDefaultTexanm(u32 a0, u32 a1) asm("_Z30kn__ModelObj__setDefaultTexanmjj");
void kn__ModelObj__setDefaultTexanm(u32 a0, u32 a1) {
    u32 s0 = *(u32*)(a0 + 0x38);
    u32 s1 = a1;

    while (s0 != 0) {
        u32 t7 = *(u32*)s0;
        u32 v0 = ((Fn4)(*(u32*)(t7 + 0xc)))(s0, 1, 0xffff, s1);
        if (v0 != 0) {
            func_00132ec0(s0, s1);
        }
        v0 = func_00132350(s0);
        if (v0 != 0) {
            s0 = v0;
            continue;
        }
        break;
    }
}
}  // namespace n0011eb08

// 0011eb78 (was src/anon/auto80_199_queue.cpp)
namespace n0011eb78 {
/*TARGET 0011eb78*/
void kn__ModelObj__resetDefaultTexanm(u32 a0, u32 a1) asm("_Z32kn__ModelObj__resetDefaultTexanmjj");
void kn__ModelObj__resetDefaultTexanm(u32 a0, u32 a1) {
    u32 s0 = *(u32*)(a0 + 0x38);
    u32 s1 = a1;

    while (s0 != 0) {
        u32 t7 = *(u32*)s0;
        u32 v0 = ((Fn4)(*(u32*)(t7 + 0xc)))(s0, 1, 0xffff, s1);
        if (v0 != 0) {
            func_00132f38(s0);
        }
        v0 = func_00132350(s0);
        if (v0 != 0) {
            s0 = v0;
            continue;
        }
        break;
    }
}
}  // namespace n0011eb78

// 0011ebe8 (gap function, not written before)
namespace g0011ebe8 {
u32 func_0011ebe8(u8* p) asm("func_0011ebe8");
u32 func_0011ebe8(u8* p) { return *(u32*)(p + 256); }
void func_0011ebf0(u8* p, u32 v) asm("func_0011ebf0");
void func_0011ebf0(u8* p, u32 v) { *(u32*)(p + 8) = v; }
u32 func_0011ebf8(u8* p) asm("func_0011ebf8");
u32 func_0011ebf8(u8* p) { return *(u32*)(p + 8); }
}  // namespace g0011ebe8

// 0011ec00 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0011ec00 {
/*TARGET 0011ec00*/
// 0x0011a4e8: definition moved into src/anon/unit_0011a260.cpp

u32 func_0011ec00(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0011ec00jjjj");
// 0x0011a4e8: definition moved into src/anon/unit_0011a260.cpp

u32 func_0011ec00(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r4 = *(u32*)((u32)r4 + (s32)(20));
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r2 = *(u32*)((u32)r15 + (s32)(24));
    r2 = ((u32 (*)(u32, u32, u32, u32))(u32)r2)(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0011ec00

// 0011ec28 (was src/anon/auto80_199_queue.cpp)
namespace n0011ec28 {
/*TARGET 0011ec28*/
void func_0011ec28(u8* a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0011ec28Phjjj");
void func_0011ec28(u8* a0, u32 a1, u32 a2, u32 a3) {
    u32 s1 = a3;
    u8* s2 = a0;
    u32 s3 = a1;

    func_0011ecc8();
    u32 s4 = a2;

    u32 obj = *(u32*)(s2 + 0x10);
    u32 t7 = *(u32*)obj;
    u32 v0 = ((FnAlloc)(*(u32*)(t7 + 0x0)))(obj, s1 + 0x10, 0);

    *(u32*)(v0 + 0x0) = s3;
    *(u32*)(v0 + 0x4) = s1;
    *(u32*)(v0 + 0x8) = 0;
    *(u32*)(v0 + 0xc) = 0;
    memcpy(v0 + 0x10, s4, s1);

    *(u32*)(v0 + 0x8) = 0;
    *(u32*)(v0 + 0xc) = *(u32*)(s2 + 0x124);
    *(u32*)(s2 + 0x124) = v0;
}
}  // namespace n0011ec28

// 0011ecc8 (was src/anon/batch_w65.cpp)
namespace n0011ecc8 {
// Unlink the node with this key from the list at +292 and hand it to the owner's release method.
struct Node { s32 key; u32 pad; Node* prev; Node* next; };
struct VObj { void** vt; };
/*TARGET 0011ecc8*/
void func_0011ecc8(u8* p, s32 key) asm("func_0011ecc8");
void func_0011ecc8(u8* p, s32 key) {
    Node* n;
    for (n = *(Node**)(p + 292); n; n = n->next) {
        if (n->key == key) {
            if (n->prev) n->prev->next = n->next;
            else *(Node**)(p + 292) = n->next;
            if (n->next) n->next->prev = n->prev;
            VObj* o = *(VObj**)(p + 16);
            ((void (*)(VObj*, Node*))o->vt[1])(o, n);
            return;
        }
    }
}
}  // namespace n0011ecc8

// 0011ed48 (gap function, not written before)
namespace g0011ed48 {
struct Node { u32 key; u32 val; u32 f8; Node* next; u8 data[1]; };
// Finds the node with the given key in the list at +292: data pointer and value.
void func_0011ed48(u8* o, u32 key, u8** data, u32* val) asm("func_0011ed48");
void func_0011ed48(u8* o, u32 key, u8** data, u32* val) {
    Node* n;
    for (n = *(Node**)(o + 292); n; n = n->next) {
        if (n->key == key) {
            *data = n->data;
            *val = n->val;
            return;
        }
    }
    *data = 0;
    *val = 0;
}
}  // namespace g0011ed48

// 0011ed90 (was src/anon/batch_w54.cpp)
namespace n0011ed90 {
// run the registered hook if any, otherwise set the state to 3
// 001039f8: moved to src/common/unit_001031b0.cpp

struct Link64 {
    s16 a;
    u16 b;
    s16 c;
    u16 d;
    u8 pad[56];
};
/*TARGET 0011ed90*/
// rebuild the link fields of a 64-byte record table
void func_0011ed90(Link64* p, s32 n) asm("func_0011ed90");
// rebuild the link fields of a 64-byte record table
void func_0011ed90(Link64* p, s32 n) {
    s32 i;
    for (i = 0; i < n; i++) {
        p[i].b = 0xffff;
        p[i].d = 0xffff;
    }
    for (i = 0; i < n; i++) {
        s16 c = p[i].c;
        s32 t = p[i].a - i;
        if (c >= 0 && c >= t) {
            Link64* q = (Link64*)((u8*)((c - t) * 64) + (u32)p);
            u16 tmp = q->d;
            q->d = i + t;
            p[i].b = tmp;
        }
    }
}
}  // namespace n0011ed90

// 0011ee18 (was src/anon/auto200_999.cpp)
namespace n0011ee18 {
extern u8 D_00347940 asm("D_00347940");
/*TARGET 0011ee18*/
void func_0011ee18(u32 a0, u32 a1) asm("_Z13func_0011ee18jj");
void func_0011ee18(u32 a0, u32 a1) {  // obj_ctor_347940
    u32 p = (u32)&D_00347940;
    *(u32 *)(a0 + 4) = a1;
    p += 0;
    *(u32 *)(a0 + 8) = 0;
    *(u32 *)a0 = p;
    *(u32 *)(a0 + 12) = 0;
}
}  // namespace n0011ee18

// 0011ee38 (gap function, not written before)
namespace g0011ee38 {
extern u8 D_00347940 asm("D_00347940");
// C1 copy of the ctor at 0x11ee18.
void func_0011ee38(u32 a0, u32 a1) asm("func_0011ee38");
void func_0011ee38(u32 a0, u32 a1) {
    u32 p = (u32)&D_00347940;
    *(u32 *)(a0 + 4) = a1;
    p += 0;
    *(u32 *)(a0 + 8) = 0;
    *(u32 *)a0 = p;
    *(u32 *)(a0 + 12) = 0;
}
}  // namespace g0011ee38

// 0011ee58 (was src/anon/tiny.cpp)
namespace n0011ee58 {
extern u32 D_00347940 asm("D_00347940");
/*TARGET 0011ee58*/
void func_0011ee58(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0011ee58jjjj");
void func_0011ee58(u32 a0, u32 a1, u32 a2, u32 a3) {  // set_vtbl_347940
    (void)a1;
    (void)a2;
    (void)a3;
    *(u32*)((u32)a0 + (0)) = (u32)&D_00347940;
}
}  // namespace n0011ee58

// 0011ee68 (gap function, not written before)
namespace g0011ee68 {
extern u32 D_00347940 asm("D_00347940");
// D1 copy of the dtor at 0x11ee58.
void func_0011ee68(u32 a0) asm("func_0011ee68");
void func_0011ee68(u32 a0) {
    *(u32*)((u32)a0 + (0)) = (u32)&D_00347940;
}
}  // namespace g0011ee68

// 0011ee78 (was src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n0011ee78 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00106420jjjjjjjj");
extern u8 D_00347940 asm("D_00347940");
/*TARGET 0011ee78*/
// 001022c0: moved to src/global/unit_001022c0.cpp

// 00106158: moved to src/naka/libkn/memoryallocator.cpp

// 001070f8: moved to src/naka/libkn/camera.cpp

u32 func_0011ee78(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_0011ee78jjjjjjjj");
// 001022c0: moved to src/global/unit_001022c0.cpp

// 00106158: moved to src/naka/libkn/memoryallocator.cpp

// 001070f8: moved to src/naka/libkn/camera.cpp

u32 func_0011ee78(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_00347940;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n0011ee78

// 0011ee98 (was src/anon/tiny_more3.cpp)
namespace n0011ee98 {
/*TARGET 0011ee98*/
// 0x001124e8: definition moved into src/anon/unit_001117d8.cpp

void func_0011ee98(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_0011ee98jjjj");
// 0x001124e8: definition moved into src/anon/unit_001117d8.cpp

void func_0011ee98(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a2; (void)a3; u32 v=*(u32*)((u32)a0+(8)); *(u32*)((u32)a1+(4))=v; *(u32*)((u32)a0+(8))=a1; }
}  // namespace n0011ee98

// 0011eea8 (was src/anon/batch_w211.cpp)
namespace n0011eea8 {
struct W211Node { W211Node* n0; W211Node* next; };
struct W211List { u32 a; u32 b; W211Node* head; };
/*TARGET 0011eea8*/
void func_0011eea8(W211List* l, W211Node* x) asm("func_0011eea8");
void func_0011eea8(W211List* l, W211Node* x) {
    W211Node* h = l->head;
    if (h == x) { l->head = x->next; return; }
    W211Node* c = h->next; W211Node* p = h;
    if (c == 0) goto out;
    if (c == x) goto out;
    do { W211Node* n = c->next; p = c; c = n; if (!n) break; } while (c != x);
out:
    p->next = x->next;
}
}  // namespace n0011eea8

// 0011eef8 (was src/anon/batch_w4.cpp)
namespace n0011eef8 {
void func_0011ee98(void*, void*) asm("func_0011ee98");
struct Obj0011eef8 {
    u32 pad[2];
    u32 f8;
    u32 fc;
    u32 f10;
    void* f14;
};
/*TARGET 0011eef8*/
void func_0011eef8(void* a, Obj0011eef8* b) asm("func_0011eef8");
void func_0011eef8(void* a, Obj0011eef8* b) {  // obj_init_and_call
    b->fc = 0;
    b->f14 = a;
    b->f8 = 0;
    func_0011ee98(a, b);
}
}  // namespace n0011eef8

// 0011ef20 (was src/anon/tiny_auto80_solver.cpp)
namespace n0011ef20 {
u32 func_0011c3b0(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_0011c3b0jjjjjjjj");
u32 func_0011ef20(u32, u32, u32) asm("_Z13func_0011ef20jjj");
/*TARGET 0011ef20*/
u32 func_0011ef20(u32 a0, u32 a1, u32 a2) asm("_Z13func_0011ef20jjj");
u32 func_0011ef20(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a1;
    u32 s1 = a2;
    ((u32(*)(u32))func_0011c3b0)(a2);
    void (**vt)() = *(void (***)())s0;
    ((void (*)(u32, u32))vt[1])(s0, s1);
}
}  // namespace n0011ef20

// 0011ef68 (gap function, not written before)
namespace g0011ef68 {
void func_0011ef68(void) asm("func_0011ef68");
void func_0011ef68(void) {}
}  // namespace g0011ef68

// 0011ef70 (was src/anon/tiny_auto80_queue.cpp)
namespace n0011ef70 {
/*TARGET 0011ef70*/
u32 func_0011ef70(u32 a0, u32 a1) asm("_Z13func_0011ef70jj");
u32 func_0011ef70(u32 a0, u32 a1) {
    if (a1 != 0u) {
        return *(u32*)((u32)a1 + (s32)(4));
    }
    return *(u32*)((u32)a0 + (s32)(8));
}
}  // namespace n0011ef70

// 0011ef88 (gap function, not written before)
namespace g0011ef88 {
// Default (empty) virtual methods of the base model class.
s32 func_0011ef88(void) asm("func_0011ef88");
s32 func_0011ef88(void) { return 0; }
f32 func_0011ef90(void) asm("func_0011ef90");
f32 func_0011ef90(void) { return 0.0f; }
void func_0011ef98(void* o, void* a, void* b) asm("func_0011ef98");
void func_0011ef98(void* o, void* a, void* b) {
    asm volatile("sqc2 $vf0, 0(%0)" : : "r"(a) : "memory");
    asm volatile(".set noreorder\n\tsqc2 $vf0, 0(%0)\n\t.set reorder" : : "r"(b) : "memory");
}
f32 func_0011efa8(void) asm("func_0011efa8");
f32 func_0011efa8(void) { return 0.0f; }
s32 func_0011efb0(void) asm("func_0011efb0");
s32 func_0011efb0(void) { return -1; }
s32 func_0011efb8(void) asm("func_0011efb8");
s32 func_0011efb8(void) { return 0; }
s32 func_0011efc0(void) asm("func_0011efc0");
s32 func_0011efc0(void) { return 0; }
s32 func_0011efc8(void) asm("func_0011efc8");
s32 func_0011efc8(void) { return 0; }
s32 func_0011efd0(void) asm("func_0011efd0");
s32 func_0011efd0(void) { return 0; }
s32 func_0011efd8(void) asm("func_0011efd8");
s32 func_0011efd8(void) { return 0; }
s32 func_0011efe0(void) asm("func_0011efe0");
s32 func_0011efe0(void) { return 0; }
}  // namespace g0011ef88

// 0011efe8 (was src/anon/batch_w2434.c)
namespace n0011efe8 {
struct O_0011efe8;
struct Ovt_0011efe8 { u8 pad[0x30]; s32 (*fn)(struct O_0011efe8*); };
struct O_0011efe8 { struct Ovt_0011efe8* vt; };
/*TARGET 0011efe8*/
void func_0011efe8(struct O_0011efe8* o, u8* p) asm("func_0011efe8");
void func_0011efe8(struct O_0011efe8* o, u8* p) {
    s32 n = o->vt->fn(o);
    s32 r = n & 7;
    s32 i;
    u64 m = 0xf0f0f0f0f0f0f0f0ULL;
    n >>= 3;
    u64* q = (u64*)p;
    for (i = 0; i < n; i++) { *q = *q & m; q++; }
    p = (u8*)q;
    for (i = 0; i < r; i++) { *p = *p & 0xf0; p++; }
}
}  // namespace n0011efe8

// 0011f078 (was src/anon/batch_w44.cpp)
namespace n0011f078 {
typedef s32 (*IFn)(void*);
/*TARGET 0011f078*/
// 0x00112d28: definition moved into src/anon/unit_001117d8.cpp

// Any of the first count() flag bytes has bit 2 set.
s32 func_0011f078(void** o, u8* flags) asm("func_0011f078");
// 0x00112d28: definition moved into src/anon/unit_001117d8.cpp

// Any of the first count() flag bytes has bit 2 set.
s32 func_0011f078(void** o, u8* flags) {
    for (s32 i = 0; i < (*(IFn*)((u8*)*o + 48))(o); i++) {
        if (flags[i] & 4) return 1;
    }
    return 0;
}
}  // namespace n0011f078

// 0011f0f8 (gap function, not written before)
namespace g0011f0f8 {
s32 func_0011f0f8(void) asm("func_0011f0f8");
s32 func_0011f0f8(void) { return 0; }
void func_0011f100(void) asm("func_0011f100");
void func_0011f100(void) {}
void func_0011f108(void) asm("func_0011f108");
void func_0011f108(void) {}
void func_0011f110(void) asm("func_0011f110");
void func_0011f110(void) {}
void func_0011f118(void) asm("func_0011f118");
void func_0011f118(void) {}
}  // namespace g0011f0f8

// 0011f11f (gap function, not written before)
namespace g0036a938 {
// u64 nibble mask in .rodata, read by 0x11f120 as an extern (no code loads it as a literal).
extern "C" const u64 D_0036a938_def asm("D_0036a938") = 0x0f0f0f0f0f0f0f0fULL;
}  // namespace g0036a938

// 0011f120 (was src/anon/batch_w55.cpp)
namespace n0011f120 {
extern u64 D_0036a938 asm("D_0036a938");
/*TARGET 0011f120*/
// Shifts packed nibbles up: whole 64-bit words, then the leftover bytes.
void func_0011f120(void* o, u8* p) asm("func_0011f120");
// Shifts packed nibbles up: whole 64-bit words, then the leftover bytes.
void func_0011f120(void* o, u8* p) {
    s32 n = (*(s32 (**)(void*))(*(u8**)o + 48))(o);
    s32 rem = n & 7;
    n >>= 3;
    u64 m = D_0036a938;
    s32 i;
    u64* q = (u64*)p;
    for (i = 0; i < n; i++) {
        *q = (*q & m) << 4;
        q++;
    }
    p = (u8*)q;
    for (i = 0; i < rem; i++) {
        *p = (*p & 0xf) << 4;
        p++;
    }
}
}  // namespace n0011f120

// 0011f1a8 (was src/anon/batch_w1538.cpp)
namespace n0011f1a8 {
struct O5_0011f1a8;
struct O5vt_0011f1a8 { u8 pad[0x30]; s32 (*fn)(O5_0011f1a8*); };
struct O5_0011f1a8 { O5vt_0011f1a8* vt; };
/*TARGET 0011f1a8*/
void func_0011f1a8(O5_0011f1a8* o, s8* p) asm("func_0011f1a8");
void func_0011f1a8(O5_0011f1a8* o, s8* p) {
    s32 n = o->vt->fn(o);
    s32 r = n & 7;
    s32 i;
    u64 m = 0xf0f0f0f0f0f0f0f0ULL;
    n >>= 3;
    u64* q = (u64*)p;
    for (i = 0; i < n; i++) { *q = (*q & m) >> 4; q++; }
    p = (s8*)q;
    for (i = 0; i < r; i++) { *p = (*p & 0xf0) >> 4; p++; }
}
}  // namespace n0011f1a8

// 0011f230 (gap function, not written before)
namespace g0011f230 {
s32 func_0011f230(void) asm("func_0011f230");
s32 func_0011f230(void) { return -1; }
}  // namespace g0011f230

// 0011f238 (was src/anon/batch_w11.cpp)
namespace n0011f238 {
// 0x0011a510: definition moved into src/anon/unit_0011a260.cpp

typedef u8* (*GetFn)(void*);
/*TARGET 0011f238*/
s16 func_0011f238(void* o, s32 i) asm("func_0011f238");
s16 func_0011f238(void* o, s32 i) {
    u8* b = (*(GetFn*)((*(u8**)o) + 32))(o);
    return *(s16*)(b + i * 64 + 4);
}
}  // namespace n0011f238

// 0011f270 (was src/anon/batch_w50.cpp)
namespace n0011f270 {
struct Bone { u32 f0; s16 parent; s16 f6; u64 flags; u8 pad[48]; };
typedef Bone* (*BoneFn)(void*);
/*TARGET 0011f270*/
// Walks up the bone hierarchy past bones with flag bit 32 set.
s32 func_0011f270(void* o, s32 n) asm("func_0011f270");
// Walks up the bone hierarchy past bones with flag bit 32 set.
s32 func_0011f270(void* o, s32 n) {
    Bone* b = (*(BoneFn*)((*(u8**)o) + 32))(o);
    s32 i = b[n].parent;
    while (i >= 0 && (b[i].flags & 0x100000000ull)) i = b[i].parent;
    return i;
}
}  // namespace n0011f270

// 0011f2f0 (was src/anon/batch_w90.cpp)
namespace n0011f2f0 {
struct VObj { void** vt; };
typedef s32 (*VFn)(void*);
// 0011f2f0: initialise by kind, then run the object's two virtual hooks.
void func_00123ac0(void*, void*) asm("func_00123ac0");
void func_0011f4b8(void*, void*) asm("func_0011f4b8");
void func_001206e0(void*, void*) asm("func_001206e0");
void func_0011ed90(s32, s32) asm("func_0011ed90");
/*TARGET 0011f2f0*/
VObj* func_0011f2f0(u8* self) asm("func_0011f2f0");
VObj* func_0011f2f0(u8* self)
{
    VObj* o = 0;
    u8* p = self + 144;
    switch (*(s32*)p) {
    case -1: func_00123ac0(self, p); o = (VObj*)self; break;
    case 2: func_0011f4b8(self, p); o = (VObj*)self; break;
    case 3: func_001206e0(self, p); o = (VObj*)self; break;
    }
    s32 a = ((VFn)o->vt[7])(o);
    func_0011ed90(((VFn)o->vt[8])(o), a);
    return o;
}
}  // namespace n0011f2f0

// 0011f3b8 (was src/anon/batch_w5.cpp)
namespace n0011f3b8 {
// 0x0011a900: definition moved into src/anon/unit_0011a660.cpp

// Call the object's first virtual function.
typedef void (*VFn)(void*);
/*TARGET 0011f3b8*/
void kn__modelDestroy(void** obj) asm("kn__modelDestroy");
void kn__modelDestroy(void** obj) {
    (*(VFn**)obj)[0](obj);
}
}  // namespace n0011f3b8

// 0011f3e0 (was src/anon/batch_w12.cpp)
namespace n0011f3e0 {
void* func_0011ef70(void*, void*) asm("func_0011ef70");
void func_0011f2f0(void*) asm("func_0011f2f0");
/*TARGET 0011f3e0*/
void func_0011f3e0(void* p) asm("func_0011f3e0");
void func_0011f3e0(void* p) {
    u8* c = 0;
    while ((c = (u8*)func_0011ef70(p, c)) != 0)
        *(void**)(c + 20) = p;
    func_0011f2f0(p);
}
}  // namespace n0011f3e0

// 0011f420 (gap function, not written before)
namespace g0011f420 {
struct E { u32 a; u16 b; u16 fl; u32 c; u16 d; u16 e; };
struct H { u8 pad[16]; u16 cnt; u8 pad2[14]; E e[1]; };
struct O { void* vt; H* h; u32 f8; u32 flags; };
struct P { u8 pad[32]; E e; };
extern u8 D_003479a8 asm("D_003479a8");
void func_0011ee18(O*, H*) asm("func_0011ee18");
// Ctor: base ctor, then flags from the part table (bit 0: big id, bit 1: part flag 1).
void func_0011f420(O* o, H* h) asm("func_0011f420");
void func_0011f420(O* o, H* h) {
    func_0011ee18(o, h);
    o->vt = &D_003479a8;
    H* t = o->h;
    for (s32 i = 0; i < t->cnt; i++) {
        P* e = (P*)((u8*)t + i * 16);
        if (e->e.c > 0xffff) o->flags |= 1;
        u16 f = e->e.fl & 1;
        if (f) o->flags |= 2;
    }
}
}  // namespace g0011f420

// 0011f4b8 (was src/anon/batch_wcx2.cpp)
namespace n0011f4b8 {
// 002eb6f8: moved to src/anon/unit_002eaf38.cpp

// ---- 0011f4b8
union UC_0011f4b8 { u16 h; u32 i; };
void func_0011ee18(u8*) asm("func_0011ee18");
// obj_ctor_347940
extern u8 D_003479a8[] asm("D_003479a8");
/*TARGET 0011f4b8*/
void func_0011f4b8(u8* p) asm("func_0011f4b8");
void func_0011f4b8(u8* p) {
    func_0011ee18(p);  // obj_ctor_347940
    u8* t = *(u8**)(p + 4);
    *(u32*)p = (u32)D_003479a8;
    for (s32 i = 0; i < ((UC_0011f4b8*)(t + 16))->h; i++) {
        u8* e = t + i * 16;
        if (*(u32*)(e + 40) > 0xffff) *(u32*)(p + 12) |= 1;
        u16 f = *(u16*)(e + 38) & 1;
        if (f) *(u32*)(p + 12) |= 2;
    }
}
}  // namespace n0011f4b8

// 0011f550 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0011f550 {
u32 func_0011ee58(u32, u32, u32, u32) asm("_Z13func_0011ee58jjjj");
extern u8 D_003479a8 asm("D_003479a8");
/*TARGET 0011f550*/
u32 func_0011f550(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0011f550jjjj");
u32 func_0011f550(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003479a8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_0011ee58)(u32, u32, u32, u32) = func_0011ee58;
    r2 = fp_call4_0011ee58(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0011f550

// 0011f578 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n0011f578 {
u32 func_0011ee58(u32, u32, u32, u32) asm("_Z13func_0011ee58jjjj");
extern u8 D_003479a8 asm("D_003479a8");
/*TARGET 0011f578*/
u32 func_0011f578(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_0011f578jjjj");
u32 func_0011f578(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_003479a8;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_0011ee58)(u32, u32, u32, u32) = func_0011ee58;
    r2 = fp_call4_0011ee58(r4, r5, r6, r7);
    return r2;
}
}  // namespace n0011f578

// 0011f5a0 (was src/anon/batch_w12.cpp)
namespace n0011f5a0 {
void func_0011ee58(void*) asm("func_0011ee58");
// set_vtbl_347940
void func_00106420(void*) asm("func_00106420");
extern u8 D_003479a8 asm("D_003479a8");
/*TARGET 0011f5a0*/
// Deleting destructor: reset vtable, run base dtor, free.
void func_0011f5a0(void** p) asm("func_0011f5a0");
// Deleting destructor: reset vtable, run base dtor, free.
void func_0011f5a0(void** p) {
    *p = &D_003479a8;
    func_0011ee58(p);  // set_vtbl_347940
    func_00106420(p);
}
}  // namespace n0011f5a0

// 0011f5d8 (gap function, not written before)
namespace g0011f5d8 {
struct Alloc {
    virtual u8* alloc(u32 size, void* ra);
};
struct Hdr { u8 pad[16]; u16 cnt; };
struct Mdl {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
    virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual s32 size();
    Hdr* hdr;
};
struct Obj {
    u8 pad0[16];
    Alloc* al;
    u8 pad1[8];
    u8* p28;
    u8* p32;
    u8* p36;
    u8* p40;
    u8* p44;
    u8* p48;
    u8 pad2[260 - 52];
    u8* vis;
    u8* p264;
    u8* p268;
};
void func_0011c2d0(Obj*) asm("func_0011c2d0");
void func_0011eef8(Mdl*, Obj*) asm("func_0011eef8");
Obj* func_0011f5d8(Mdl* mdl, Alloc* al) asm("func_0011f5d8");
Obj* func_0011f5d8(Mdl* mdl, Alloc* al)
{
    Hdr* h = mdl->hdr;
    u32 n = (mdl->size() + 15) & ~15;
    Obj* o = (Obj*)al->alloc(n + 304, __builtin_return_address(0));
    func_0011c2d0(o);
    o->p40 = 0;
    o->vis = (u8*)o + 304;
    o->p44 = 0;
    o->p48 = 0;
    o->p28 = 0;
    o->p32 = 0;
    o->p36 = 0;
    for (s32 i = 0; i < h->cnt; i++) o->vis[i] = 2;
    o->al = al;
    o->p264 = 0;
    o->p268 = 0;
    func_0011eef8(mdl, o);
    return o;
}
}  // namespace g0011f5d8

// 0011f6c0 (was src/anon/tiny_wrappers_more.cpp)
namespace n0011f6c0 {
u32 func_0011ef20(u32, u32, u32, u32) asm("_Z13func_0011ef20jjjj");
/*TARGET 0011f6c0*/
// 0x0011b3e0: definition moved into src/anon/unit_0011a660.cpp

u32 kn__ModelBG__destroyModelObj(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z28kn__ModelBG__destroyModelObjjjjj");
// 0x0011b3e0: definition moved into src/anon/unit_0011a660.cpp

u32 kn__ModelBG__destroyModelObj(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0011ef20(a0, a1, a2, a3);
}
}  // namespace n0011f6c0

// 0011f6d8 (gap function, not written before)
namespace g0011f6d8 {
u32 func_0011f6d8(u8* p) asm("func_0011f6d8");
u32 func_0011f6d8(u8* p) { return *(u16*)(*(u8**)(p + 4) + 16); }
}  // namespace g0011f6d8

// 0011f6e8 (was src/anon/batch_w1792.cpp)
namespace n0011f6e8 {
struct D18_1792 { u8 pad[0x18]; s32 off18; };
struct O4_1792 { u32 pad; D18_1792* d; };
void func_0011efe8(void*) asm("func_0011efe8");
/*TARGET 0011f6e8*/
void kn__ModelBG__setDisplayFlag(O4_1792* o, u8* bits, s16* list) asm("kn__ModelBG__setDisplayFlag");
void kn__ModelBG__setDisplayFlag(O4_1792* o, u8* bits, s16* list) {
    D18_1792* d = o->d;
    func_0011efe8(o);
    if (*list != -1) {
        s32* tbl = (s32*)((u8*)d + d->off18);
        s16 v;
        while ((v = *list++) != -1) {
            s16* q = (s16*)((u8*)d + tbl[v & 0x7fff]);
            u8 flag = (v & ~0x7fff) ? 2 : 1;
            for (; *q >= 0; q++) bits[*q] |= flag;
        }
    }
}
}  // namespace n0011f6e8

