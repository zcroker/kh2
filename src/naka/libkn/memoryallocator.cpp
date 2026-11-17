#include "../../common/types.h"

// kn::MemoryAllocator (0x1060b8-0x106490): a first-fit heap in a caller-given buffer, the
// current allocator pointer (0x33cc08) and the operator new/delete helpers that use it.
// The vtable (0x33cc18) stays retail data; its methods are plain functions here.

u32 D_0033cc08_def asm("D_0033cc08") = 0;

// ---- 001060b8 (from src/anon/batch_w3684.cpp)
namespace n001060b8 {
extern u8 D_0033cc18[] asm("D_0033cc18");
void func_00106108(void*) asm("func_00106108");
struct S { void* vt; u32 a; u32 b; };
void func_001060b8(S* q, u32 a1, u32 a2) asm("func_001060b8");
void func_001060b8(S* q, u32 a1, u32 a2) {
    register S* p asm("$4") = q;
    asm("" : "+r"(p));
    p->vt = D_0033cc18;
    p->b = a2;
    p->a = a1;
    func_00106108(p);
}
}  // namespace n001060b8


// ---- 001060e0 (from src/anon/batch_w3684.cpp)
namespace n001060e0 {
extern u8 D_0033cc18[] asm("D_0033cc18");
void func_00106108(void*) asm("func_00106108");
struct S { void* vt; u32 a; u32 b; };
void func_001060e0(S* q, u32 a1, u32 a2) asm("func_001060e0");
void func_001060e0(S* q, u32 a1, u32 a2) {
    register S* p asm("$4") = q;
    asm("" : "+r"(p));
    p->vt = D_0033cc18;
    p->b = a2;
    p->a = a1;
    func_00106108(p);
}
}  // namespace n001060e0


// ---- 00106108 (from src/anon/tiny_auto80.cpp)
namespace n00106108 {
void func_00106108(u32, u32, u32, u32) asm("func_00106108");
void func_00106108(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00106108");
void func_00106108(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r13, r14, r15;
    r15 = *(volatile u32*)((u32)r4 + (s32)(4));
    r14 = (u32)((s32)r4 + (20));
    r13 = *(volatile u32*)((u32)r4 + (s32)(8));
    r15 = (u32)(r15 - r14);
    *(volatile u32*)((u32)r4 + (s32)(12)) = 0u;
    *(volatile u32*)((u32)r4 + (s32)(20)) = r13;
    *(volatile u32*)((u32)r4 + (s32)(28)) = r15;
    *(volatile u32*)((u32)r4 + (s32)(24)) = 0u;
    *(volatile u32*)((u32)r4 + (s32)(32)) = r4;
    *(volatile u32*)((u32)r4 + (s32)(16)) = 0u;
}
}  // namespace n00106108


// ---- 00106138 (gap: D2 destructor, only resets the vptr)
namespace n00106138 {
extern u8 D_0033cc18[] asm("D_0033cc18");
void func_00106138(u8** p) asm("func_00106138");
void func_00106138(u8** p) { *p = D_0033cc18; }
}  // namespace n00106138

// ---- 00106148 (gap: D1 destructor)
namespace n00106148 {
extern u8 D_0033cc18[] asm("D_0033cc18");
void func_00106148(u8** p) asm("func_00106148");
void func_00106148(u8** p) { *p = D_0033cc18; }
}  // namespace n00106148

// ---- 00106158 (from src/anon/tiny_auto80_harvest8_force0.cpp)
namespace n00106158 {
u32 func_00106420(u32, u32, u32, u32, u32, u32, u32, u32) asm("func_00106420");
extern u8 D_0033cc18 asm("D_0033cc18");
u32 func_00106158(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00106158");
u32 func_00106158(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r15;
    r15 = (u32)&D_0033cc18;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r15;
    return ((u32(*)())func_00106420)();
}
}  // namespace n00106158


// ---- 00106178 (from src/anon/auto80_199_queue.cpp)
namespace n00106178 {
void func_001060e0(u32, u32, u32) asm("func_001060e0");
u32 func_00106178(u32 a0, u32 a1) asm("func_00106178");
u32 func_00106178(u32 a0, u32 a1) {
    u32 s0 = (a0 + 15u) & ~15u;
    u32 a2 = a0 + a1;
    u32 arg0 = s0;
    u32 t = (s0 + 80u);
    u32 ok = (t < a2);
    u32 v0 = 0;
    u32 arg1 = s0 + 48u;

    if (ok) {
        func_001060e0(arg0, arg1, a2);
        v0 = s0;
    }

    return v0;
}
}  // namespace n00106178


// ---- 001061d0 (gap: alloc, vtable slot 0)
namespace n001061d0 {
struct Block { Block* next; Block* prev; u32 size; void* owner; };
struct Alloc { void* vt; u8* start; Block* end; u32 used; Block* last; Block head; };
void* func_001061d0(Alloc* m, u32 size) asm("func_001061d0");
void* func_001061d0(Alloc* m, u32 size) {
    Block* found = 0;
    u32 gap;
    size = ((size + 15) & ~15) + 16;
    Block* p = m->last;
    if (p) {
        u8* e = (u8*)p + p->size;
        gap = (u8*)p->next - e;
        if (gap >= size && e < (u8*)m->end) found = p;
    }
    if (!found) {
        Block* endp = m->end;
        for (p = &m->head; p != endp; p = p->next) {
            gap = (u8*)p->next - ((u8*)p + p->size);
            if (gap == size) { found = p; break; }
            if (size < gap) { found = p; break; }
        }
        if (!found) return 0;
    }
    Block* nb = (Block*)((u8*)found + found->size);
    nb->next = found->next;
    nb->prev = found;
    found->next = nb;
    nb->size = size;
    nb->owner = m;
    if (nb->next != m->end) nb->next->prev = nb;
    m->last = nb;
    m->used += size;
    return nb + 1;
}
}  // namespace n001061d0

// ---- 001062b8 (gap: free, vtable slot 1)
namespace n001062b8 {
struct Block { Block* next; Block* prev; u32 size; void* owner; };
struct Alloc { void* vt; u8* start; Block* end; u32 used; Block* last; Block head; };
void func_00168a30(void*, void*) asm("func_00168a30");
void func_001062b8(Alloc* m, void* ptr) asm("func_001062b8");
void func_001062b8(Alloc* m, void* ptr) {
    Block* b = (Block*)ptr - 1;
    func_00168a30(b, (u8*)b + b->size);
    if (m->last == b) m->last = b->prev;
    m->used -= b->size;
    Block* n = ((Block*)ptr)[-1].next;
    if (n != m->end) n->prev = b->prev;
    b->prev->next = n;
}
}  // namespace n001062b8

// ---- 00106340 (gap: heap size, vtable slot 2)
namespace n00106340 {
struct Alloc { void* vt; u8* start; u8* end; u32 used; };
u32 func_00106340(Alloc* m) asm("func_00106340");
u32 func_00106340(Alloc* m) { return m->end - m->start; }
}  // namespace n00106340

// ---- 00106350 (gap: used size, vtable slot 3)
namespace n00106350 {
struct Alloc { void* vt; u8* start; u8* end; u32 used; };
u32 func_00106350(Alloc* m) asm("func_00106350");
u32 func_00106350(Alloc* m) { return m->used; }
}  // namespace n00106350

// ---- 00106358 (from src/anon/auto80_199_queue.cpp)
namespace n00106358 {
extern u32 D_0033cc08 asm("D_0033cc08");
u32 func_00106178(u32 a0, u32 a1) asm("func_00106178");
u32 func_00106358(u32 a0, u32 a1) asm("func_00106358");
u32 func_00106358(u32 a0, u32 a1) {
    u32 s2 = D_0033cc08;
    u32 s1 = a0;
    u32 s0 = a1;

    if (s2 != 0) {
        u32 vtbl = *(u32*)s2;
        (*(void (**)(u32))(vtbl + 24))(s2);
    }

    u32 v0 = func_00106178(s1, s0);
    D_0033cc08 = v0;
    return v0;
}
}  // namespace n00106358


// ---- 001063c0 (from src/anon/tiny_auto80_fptr4.cpp)
namespace n001063c0 {
u32 func_001063c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001063c0");
u32 func_001063c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r14, r15;
    r15 = r4;
    r4 = r5;
    r6 = 0u;
    r14 = *(u32*)((u32)r5 + (s32)(0));
    r2 = *(u32*)((u32)r14 + (s32)(0));
    r5 = r15;
    r2 = ((u32 (*)(u32, u32, u32, u32))(u32)r2)(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001063c0


// ---- 001063f0 (from src/anon/tiny_auto80_fptr4.cpp)
namespace n001063f0 {
u32 func_001063f0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001063f0");
u32 func_001063f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r14, r15;
    r15 = r4;
    r4 = r5;
    r6 = 0u;
    r14 = *(u32*)((u32)r5 + (s32)(0));
    r2 = *(u32*)((u32)r14 + (s32)(0));
    r5 = r15;
    r2 = ((u32 (*)(u32, u32, u32, u32))(u32)r2)(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001063f0


// ---- 00106420 (from src/anon/tiny_auto80.cpp)
namespace n00106420 {
void func_00106420(u32, u32, u32, u32) asm("func_00106420");
void func_00106420(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00106420");
void func_00106420(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14, r15;
    r5 = r4;
    if (r4 != 0u) {
        r4 = *(volatile u32*)((u32)r4 + (s32)(-4));
        r14 = *(volatile u32*)((u32)r4 + (s32)(0));
        r15 = *(volatile u32*)((u32)r14 + (s32)(4));
        ((void(*)(u32,u32,u32,u32))(u32)r15)(r4, r5, r6, r7);
    }
}
}  // namespace n00106420


// ---- 00106450 (from src/anon/tiny_auto80_harvest_activity.cpp)
namespace n00106450 {
void func_00106450(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00106450");
void func_00106450(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14, r15;
    r5 = r4;
    if (r4 != 0u) {
        r4 = *(volatile u32*)((u32)r4 + (s32)(-4));
        r14 = *(volatile u32*)((u32)r4 + (s32)(0));
        r15 = *(volatile u32*)((u32)r14 + (s32)(4));
        ((void(*)(u32,u32,u32,u32))(u32)r15)(r4, r5, r6, r7);
    }
}
}  // namespace n00106450


// ---- 00106480 (gap: returns -1)
namespace n00106480 {
s32 func_00106480(void) asm("func_00106480");
s32 func_00106480(void) { return -1; }
}  // namespace n00106480

// ---- 00106488 (gap: returns -1)
namespace n00106488 {
s32 func_00106488(void) asm("func_00106488");
s32 func_00106488(void) { return -1; }
}  // namespace n00106488
