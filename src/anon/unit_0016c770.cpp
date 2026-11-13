#include "../common/types.h"

// YS::VM (0x16c770-0x16d2e0): the script VM objects (start/stop/call/callback/dup/end), the BD function
// table lookup and a few traps; incl. the never-written empty functions 0x16d198 and 0x16d2a0-0x16d2c8 and
// the frame-time getter 0x16d2d0. Each function keeps the declarations of the source it was matched in
// (namespace vN); every symbol is bound by asm label.

// 0016c770 (src/anon/tiny_jal_wrappers.cpp)
namespace v0 {
u32 func_0016d110(u32, u32, u32, u32) asm("func_0016d110");

u32 func_0016c770(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r13 = 0u, r14 = 0u, r15 = 0u;
    r2 = func_0016d110(r4, r5, r6, r7);
    r15 = (u32)(0x0033u << 16);
    r13 = *(u32*)((u32)r15 + (s32)(-18148));
    r14 = (u32)(0x004fu << 16);
    *(u32*)((u32)r14 + (s32)(25224)) = r13;
    return r2;
}
}  // namespace v0

// 0016c7a0 (src/anon/batch_w18.cpp)
namespace v1 {
typedef u32 (*VFn3)(void*, u32, void*);
extern void* D_004f6288 asm("D_004f6288");

u32 func_0016c7a0(u32 a) {
    void* o = D_004f6288;
    return (**(VFn3**)o)(o, a, __builtin_return_address(0));
}
}  // namespace v1

// 0016c7d8 (src/anon/tiny_auto80_solver.cpp)
namespace v2 {

u32 func_0016c7d8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 base = 0x004fu << 16;
    u32 obj = *(u32*)((u32)base + (s32)25224);
    void (**vt)() = *(void (***)())obj;
    ((void (*)(u32, u32, u32, u32, u32, u32, u32, u32))vt[1])(obj, a0, a2, a3, a4, a5, a6, a7);
}
}  // namespace v2

// 0016c808 (src/anon/batch_w1809_nsa.cpp)
namespace v3 {
struct W1809Heap;
struct W1809HeapVt { void* (*alloc)(W1809Heap*, u32, void*); };
struct W1809Heap { W1809HeapVt* vt; };
struct W1809InfoC8 { u8 pad[16]; s32 n10; u32 sz14; u32 sz18; };
struct W1809RefC8 { u8 pad[0x488]; s32 refs; };
struct W1809ObjC8 {
    W1809InfoC8* info; s32 f4; void* f8; void* fc; void* f10; void* f14; void* f18;
    s32 f1c, f20, f24; s32 f28; s32 f2c, f30; void* f34; W1809RefC8* f38;
};
extern W1809Heap* D_004f6288 asm("D_004f6288");
void* func_0016d1a0(s32) asm("func_0016d1a0");
void* func_0016d1d8(void*) asm("func_0016d1d8");

void func_0016c808(W1809ObjC8* o, W1809InfoC8* info, void* a2, W1809RefC8* a3) {
    o->f34 = a2;
    o->f38 = a3;
    o->info = info;
    o->f1c = 0;
    o->f20 = 0;
    o->f24 = 0;
    o->f30 = 0;
    o->f2c = 0;
    void* p = D_004f6288->vt->alloc(D_004f6288, info->sz14 + 256, __builtin_return_address(0));
    o->f14 = p;
    o->f8 = p;
    p = D_004f6288->vt->alloc(D_004f6288, o->info->sz18 + 256, __builtin_return_address(0));
    o->f18 = p;
    o->fc = p;
    if (o->f34 == 0) {
        if (o->info->n10 > 0) o->f34 = func_0016d1a0(o->info->n10);
    }
    void* b = o->f34;
    o->f10 = b ? func_0016d1d8(b) : 0;
    o->f4 = 0;
    if (o->f38) o->f38->refs++;
}
}  // namespace v3

// 0016c8f8 (src/anon/batch_w1809_nsa.cpp)
namespace v4 {
struct W1809Heap;
struct W1809HeapVt { void* (*alloc)(W1809Heap*, u32, void*); };
struct W1809Heap { W1809HeapVt* vt; };
struct W1809InfoC8 { u8 pad[16]; s32 n10; u32 sz14; u32 sz18; };
struct W1809RefC8 { u8 pad[0x488]; s32 refs; };
struct W1809ObjC8 {
    W1809InfoC8* info; s32 f4; void* f8; void* fc; void* f10; void* f14; void* f18;
    s32 f1c, f20, f24; s32 f28; s32 f2c, f30; void* f34; W1809RefC8* f38;
};
extern W1809Heap* D_004f6288 asm("D_004f6288");
void* func_0016d1a0(s32) asm("func_0016d1a0");
void* func_0016d1d8(void*) asm("func_0016d1d8");

void func_0016c8f8(W1809ObjC8* o, W1809InfoC8* info, void* a2, W1809RefC8* a3) {
    o->f34 = a2;
    o->f38 = a3;
    o->info = info;
    o->f1c = 0;
    o->f20 = 0;
    o->f24 = 0;
    o->f30 = 0;
    o->f2c = 0;
    void* p = D_004f6288->vt->alloc(D_004f6288, info->sz14 + 256, __builtin_return_address(0));
    o->f14 = p;
    o->f8 = p;
    p = D_004f6288->vt->alloc(D_004f6288, o->info->sz18 + 256, __builtin_return_address(0));
    o->f18 = p;
    o->fc = p;
    if (o->f34 == 0) {
        if (o->info->n10 > 0) o->f34 = func_0016d1a0(o->info->n10);
    }
    void* b = o->f34;
    o->f10 = b ? func_0016d1d8(b) : 0;
    o->f4 = 0;
    if (o->f38) o->f38->refs++;
}
}  // namespace v4

// 0016c9e8 (src/anon/batch_w76.cpp)
namespace v5 {
typedef void (*VFn)(void*);
void func_001da458(u8*, u32, u32, u32) asm("func_001da458");  // stream_init_fields
void func_001da558(u8*, void*, u32, u32) asm("func_001da558");
extern u8 D_0034dbf8 asm("D_0034dbf8");
void func_0016cab8(u8*) asm("func_0016cab8");
void func_0016c7d8(u8*) asm("func_0016c7d8");
typedef void (*VFn2)(void*, u32);
extern void* D_004f6288 asm("D_004f6288");
void func_0016d1f0(u32) asm("func_0016d1f0");
void func_0016ce90(u8*) asm("func_0016ce90");
static inline void Kill(u8* n) { if (n) { func_0016cab8(n); func_0016c7d8(n); } }

void func_0016c9e8(u8* o)
{
    if (*(u32*)(o + 36)) {
        func_001da458(o, *(u32*)(o + 36), 0, 0);  // stream_init_fields
        func_001da558(o, &D_0034dbf8, 0, 0);
    }
    u8* n = *(u8**)(o + 44);
    while (n) {
        u8* next = *(u8**)(n + 40);
        Kill(n);
        n = next;
    }
    (*(VFn2*)(*(u8**)D_004f6288 + 4))(D_004f6288, *(u32*)(o + 20));
    (*(VFn2*)(*(u8**)D_004f6288 + 4))(D_004f6288, *(u32*)(o + 24));
    if (*(u32*)(o + 52)) func_0016d1f0(*(u32*)(o + 52));
    func_0016ce90(o);
}
}  // namespace v5

// 0016cab8 (src/anon/batch_w77.cpp)
namespace v6 {
struct VObj { void** vt; };
typedef void (*RelFn)(VObj*, u32);
struct Node { u8 pad[20]; u32 h20; u32 h24; u8 pad28[8]; u32 f36; Node* next; Node* child; u8 pad48[4]; u32 f52; };
extern VObj* D_004f6288 asm("D_004f6288");
extern u8 D_0034dbf8 asm("D_0034dbf8");
void func_001da458(Node*, u32, s32, s32) asm("func_001da458");  // stream_init_fields
void func_001da558(Node*, void*, s32, s32) asm("func_001da558");
void func_0016c7d8(Node*) asm("func_0016c7d8");
void func_0016d1f0(u32) asm("func_0016d1f0");
void func_0016ce90(Node*) asm("func_0016ce90");
void func_0016cab8(Node* p) asm("func_0016cab8");
static inline void Kill(Node* c)
{
    if (c) {
        func_0016cab8(c);
        func_0016c7d8(c);
    }
}

void func_0016cab8(Node* p)
{
    if (p->f36) {
        func_001da458(p, p->f36, 0, 0);  // stream_init_fields
        func_001da558(p, &D_0034dbf8, 0, 0);
    }
    Node* c = p->child;
    while (c) {
        Node* n = c->next;
        Kill(c);
        c = n;
    }
    ((RelFn)D_004f6288->vt[1])(D_004f6288, p->h20);
    ((RelFn)D_004f6288->vt[1])(D_004f6288, p->h24);
    if (p->f52) func_0016d1f0(p->f52);
    func_0016ce90(p);
}
}  // namespace v6

// 0016cb88 (src/anon/tiny_wrappers_more.cpp)
namespace v7 {
u32 func_001da420(u32, u32, u32, u32) asm("func_001da420");

u32 func_0016cb88(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001da420(a0, a1, a2, a3);
}
}  // namespace v7

// 0016cba0 (src/anon/batch_w4.cpp)
namespace v8 {
extern "C" void func_001da458(void*, u32) asm("func_001da458");  // stream_init_fields
extern "C" void func_0016ce90(void*, u32) asm("func_0016ce90");

void u_tail4_0016cba0(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)(a0 + 28) = 0;
    if ((s32)a1 > 0) func_001da458((void*)a0, a1);  // stream_init_fields
    else func_0016ce90((void*)a0, a1);
}
}  // namespace v8

// 0016cbc8 (src/anon/tiny_auto80_fptr4.cpp)
namespace v9 {
u32 func_0016cb88(u32, u32, u32, u32) asm("func_0016cb88");
u32 func_0016cba0(u32, u32, u32, u32) asm("func_0016cba0");

u32 func_0016cbc8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r16, r17, r18;
    r16 = r4;
    r17 = r6;
    r18 = r7;
    u32 (*fp_call4_0016cb88)(u32, u32, u32, u32) = func_0016cb88;
    r2 = fp_call4_0016cb88(r4, r5, r6, r7);
    r4 = r16;
    r6 = r17;
    r7 = r18;
    r5 = r2;
    return func_0016cba0(r4, r5, r6, r7);
}
}  // namespace v9

// 0016cc18 (src/anon/batch_w3758.cpp)
namespace v10 {
struct S64 { u32 w[7]; u32 f; u32 pad[8]; };
extern s32 D_0034d8a4 asm("D_0034d8a4");
extern s32 D_0034d8a0 asm("D_0034d8a0");
void func_0016c8f8(S64*, u32, u32, u32) asm("func_0016c8f8");
void func_001da458(S64*, s32, s32, s32) asm("func_001da458");
void func_0016cd48(S64*, u32*) asm("func_0016cd48");
void func_0016cab8(S64*) asm("func_0016cab8");

void func_0016cc18(u32* p, s32 n, s32 b, s32 c, u32* q) {
    S64 s;
    func_0016c8f8(&s, p[0], p[13], p[14]);
    s32 s0 = D_0034d8a4;
    s32 s1 = D_0034d8a0;
    s.f |= 1;
    if (n > 0) {
        func_001da458(&s, n, b, c);
        // Pin: original selects directly into a1 after the call; an unpinned pseudo gets hoisted by sched1.
        register u32* r asm("$5");
        if (!q) r = p; else r = q;
        func_0016cd48(&s, r);
    }
    D_0034d8a4 = s0;
    D_0034d8a0 = s1;
    func_0016cab8(&s);
}
}  // namespace v10

// 0016cce8 (src/anon/auto80_199_queue.cpp)
namespace v11 {
typedef u32 (*Fn4)(u32, u32, u32, u32);
typedef u32 (*FnAlloc)(u32, u32, u32);
struct VObj {
    u32* vtbl;

};
typedef u32 (*VCall48)(VObj*);
struct Obj {
    u32* vtbl;

};
u32 func_0016cce8(...) asm("func_0016cce8");
u32 func_0016cb88(...) asm("func_0016cb88");
u32 func_0016cc18(u32, u32, u32, u32, u32) asm("func_0016cc18");
typedef u32 (*Fn001c9110)(u32);
struct Arg {
    u8 pad[40];

u32 flags;

};
typedef u32 (*VirtFn)(Obj*, Arg*);
typedef u32 (*Func_001db610_cb)(u32, u32);
typedef u32 (*Method1)(u32);

u32 func_0016cce8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u32 s0 = a0;
    u32 s1 = a2;
    u32 s2 = a3;
    u32 s3 = a4;

    u32 v0 = func_0016cb88(s0);
    return func_0016cc18(s0, v0, s1, s2, s3);
}
}  // namespace v11

// 0016cd48 (src/anon/batch_w268.cpp)
namespace v12 {
struct W268Vm;
struct W268VmList { W268Vm* head; W268Vm* tail; };
struct W268Vm { u8 pad[0x1c]; u32 flags; u8 p20[8]; W268Vm* next; W268VmList kids; };
extern W268Vm* D_0034d8a4 asm("D_0034d8a4");
extern W268Vm* D_0034d8a0 asm("D_0034d8a0");
extern u8 D_0034dbf8[] asm("D_0034dbf8");
s32 func_001da558(W268Vm*, void*, s32, s32) asm("func_001da558");
void func_0016ce90(W268Vm*) asm("func_0016ce90");
void func_0016cab8(W268Vm*) asm("func_0016cab8");
void func_0016c7d8(W268Vm*) asm("func_0016c7d8");

s32 func_0016cd48(W268Vm* vm, W268Vm* parent)
{
    if (!(vm->flags & 2)) {
        D_0034d8a4 = vm;
        D_0034d8a0 = parent ? parent : vm;
        s32 r = func_001da558(vm, D_0034dbf8, 0, 0);
        D_0034d8a4 = 0;
        D_0034d8a0 = 0;
        if (r != 1) func_0016ce90(vm);
    }
    W268Vm* c = vm->kids.head;
    while (c) {
        W268Vm* nx = c->next;
        if (func_0016cd48(c, vm) == 1) {
            W268VmList* l = &vm->kids;
            W268Vm* prev;
            if (c == l->head) {
                l->head = c->next;
                prev = 0;
            } else {
                prev = l->head;
                while (prev->next != c) prev = prev->next;
                prev->next = c->next;
            }
            if (c == l->tail) l->tail = prev;
            c->next = 0;
            if (c) {
                func_0016cab8(c);
                func_0016c7d8(c);
            }
        }
        c = nx;
    }
    if (vm->flags & 2) {
        if (vm->kids.head == 0) return 1;
    }
    return 0;
}
}  // namespace v12

// 0016ce90 (src/anon/tiny_auto80_queue.cpp)
namespace v13 {
typedef void (*Fn_002cec50)(u32, u32);
typedef void (*Fn_002cf170)(u32, u32, u32, u32);
typedef u32  (*Fn_002cf1b8)(u32, u32);
typedef void (*Fn_002ead20)(u32, u32, u32);
typedef void (*Fn_002ebc38)(u32, u32, f32);
typedef void (*Fn_002ecdb0)(u32);
typedef void (*Fn_002ecdf8)(u32, u32);
typedef void (*Fn_002ece48)(u32, u32);
typedef void (*Fn_002ed478)(u32);
typedef void (*Fn_002f0798)(u32);
typedef void (*Fn_002f07c8)(u32);

void func_0016ce90(u32 a0) {
    u32 t6 = *(volatile u32*)((u32)a0 + (s32)(28));
    u32 t7 = (u32)(t6 & 2u);
    if (t7 != 0u) {
        return;
    }
    u32 t5 = *(volatile u32*)((u32)a0 + (s32)(56));
    if (t5 == 0u) {
        t7 = (u32)(t6 | 2u);
    } else {
        t7 = *(volatile u32*)((u32)t5 + (s32)(1160));
        t7 = (u32)((s32)t7 + (-1));
        *(volatile u32*)((u32)t5 + (s32)(1160)) = t7;
        t6 = *(volatile u32*)((u32)a0 + (s32)(28));
        t7 = (u32)(t6 | 2u);
    }
    *(volatile u32*)((u32)a0 + (s32)(28)) = t7;
}
}  // namespace v13

// 0016ced0 (src/anon/auto200_999.cpp)
namespace v14 {
typedef void (*Fn_00322908)(u32, u32);
extern u32 D_004f6290 asm("D_004f6290");

void func_0016ced0(u32 a0) {  // list_append
    u32 list = (u32)&D_004f6290;
    u32 tail = *(u32 *)(list + 4);
    if (tail != 0) {
        goto nonempty;
    }
    *(u32 *)(list + 4) = a0;
    *(u32 *)list = a0;
    *(u32 *)(a0 + 40) = 0;
    return;

nonempty:
    *(u32 *)(tail + 40) = a0;
    *(u32 *)(a0 + 40) = 0;
    *(u32 *)(list + 4) = a0;
}
}  // namespace v14

// 0016cf00 (src/anon/auto80_199_queue.cpp)
namespace v15 {
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
u32 func_0016c7a0(u32) asm("func_0016c7a0");
void func_0016c8f8(u32, u32, u32, u32) asm("func_0016c8f8");
void func_001da458(u32, u32, u32, u32) asm("func_001da458");
u32 func_0016cf00(...) asm("func_0016cf00");
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

u32 func_0016cf00(u8* a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u32 s1 = (u32)a0;
    u32 s2 = a2;
    u32 s3 = a3;
    u32 s4 = a1;
    u32 s5 = a4;

    u32 s0 = func_0016c7a0(64);
    func_0016c8f8(s0, *(u32*)(s1 + 0), *(u32*)(s1 + 52), *(u32*)(s1 + 56));

    u32 t7 = *(u32*)(s0 + 28);
    *(u32*)(s0 + 32) = s4;
    *(u32*)(s0 + 28) = t7 | 1;

    func_001da458(s0, s2, s3, s5);  // stream_init_fields
    return s0;
}
}  // namespace v15

// 0016cfa0 (src/anon/tiny_auto80_queue.cpp)
namespace v16 {
typedef void (*Fn_002cec50)(u32, u32);
typedef void (*Fn_002cf170)(u32, u32, u32, u32);
typedef u32  (*Fn_002cf1b8)(u32, u32);
typedef void (*Fn_002ead20)(u32, u32, u32);
typedef void (*Fn_002ebc38)(u32, u32, f32);
typedef void (*Fn_002ecdb0)(u32);
typedef void (*Fn_002ecdf8)(u32, u32);
typedef void (*Fn_002ece48)(u32, u32);
typedef void (*Fn_002ed478)(u32);
typedef void (*Fn_002f0798)(u32);
typedef void (*Fn_002f07c8)(u32);
extern "C" u32 func_0016cf00(...) asm("func_0016cf00");

void func_0016cfa0(u32 a0) {  // obj_list_insert
    u32 s0 = a0;
    u32 v0 = func_0016cf00(a0);
    u32 t7 = (u32)((s32)s0 + (44));
    u32 t6 = *(u32*)((u32)t7 + (s32)(4));
    if (t6 != 0u) {
        *(u32*)((u32)t6 + (s32)(40)) = v0;
    } else {
        *(u32*)((u32)t7 + (s32)(4)) = v0;
        *(u32*)((u32)s0 + (s32)(44)) = v0;
        *(u32*)((u32)v0 + (s32)(40)) = 0u;
        return;
    }
    *(u32*)((u32)v0 + (s32)(40)) = 0u;
    *(u32*)((u32)t7 + (s32)(4)) = v0;
}
}  // namespace v16

// 0016cff0 (src/anon/auto80_199_queue.cpp)
namespace v17 {
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
void func_0031e2c8(u32, u32) asm("func_0031e2c8");
u32 func_0016cab8(...) asm("func_0016cab8");
u32 func_0016c7d8(...) asm("func_0016c7d8");
void func_0016cff0(u32, u32, u32) asm("func_0016cff0");
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

void func_0016cff0(u8* a0, u32 a1, u32 a2) {
    u32 s2 = a2;
    u32 s3 = a1;
    u8* s4 = a0;
    u32 s0 = *(u32*)(a0 + 44);

    while (s0 != 0) {
        u32 s1 = *(u32*)(s0 + 40);
        if ((*(u32*)(s0 + 32) & s3) == s2) {
            func_0031e2c8((u32)(s4 + 44), s0);
            if (s0 != 0) {
                func_0016cab8(s0);
                func_0016c7d8(s0);
            }
        }
        s0 = s1;
    }
}
}  // namespace v17

// 0016d080 (src/anon/auto80_199_queue.cpp)
namespace v18 {
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
u32 func_0016d080(u32, u32) asm("func_0016d080");
u32 func_0016c7a0(u32) asm("func_0016c7a0");
void func_0016c8f8(u32, u32, u32, u32) asm("func_0016c8f8");
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

u32 func_0016d080(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s2 = a1;
    u32 s1 = func_0016c7a0(64);
    func_0016c8f8(s1, s0, 0, s2);
    return s1;
}
}  // namespace v18

// 0016d0d8 (src/anon/batch_w1667.cpp)
namespace v19 {
extern u32 D_0034dbf8[] asm("D_0034dbf8");

void wtarget_0016d0d8(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_0016d0d8jjjj");
void wtarget_0016d0d8(u32 a, u32 b, u32 c, u32 d) { D_0034dbf8[a] = b; }
}  // namespace v19

// 0016d0f0 (src/anon/tiny_wrappers_more.cpp)
namespace v20 {
u32 func_0016d0d8(u32, u32, u32, u32) asm("func_0016d0d8");

u32 func_0016d0f0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0016d0d8(0x00000003u, a0, a2, a3);
}
}  // namespace v20

// 0016d110 (src/anon/batch_w1531.cpp)
namespace v21 {
struct W1531_TT { u8 pad[0x28]; W1531_TT* next; };
struct W1531_TL { W1531_TT* head; s32 count; };
extern W1531_TL D_004f6290 asm("D_004f6290");
void func_0016cab8(W1531_TT*) asm("func_0016cab8");
void func_0016c7d8(W1531_TT*) asm("func_0016c7d8");

void ttarget0_0016d110(void) asm("_Z17ttarget0_0016d110v");
void ttarget0_0016d110(void) {
    W1531_TT* nx;
    W1531_TT* cur = D_004f6290.head;
    W1531_TT* it = cur;
    if (cur) {
        do {
            if (!it) nx = D_004f6290.head; else nx = it->next;
            it = nx;
            if (cur) { func_0016cab8(cur); func_0016c7d8(cur); }
            cur = nx;
        } while (nx);
    }
    D_004f6290.head = 0;
    D_004f6290.count = 0;
}
}  // namespace v21

// 0016d198 (never written before; empty function)
namespace v_d198 {
void func_0016d198(void) asm("func_0016d198");
void func_0016d198(void) {}
}  // namespace v_d198

// 0016d1a0 (src/anon/tiny_auto80_queue.cpp)
namespace v22 {
typedef void (*Fn_002cec50)(u32, u32);
typedef void (*Fn_002cf170)(u32, u32, u32, u32);
typedef u32  (*Fn_002cf1b8)(u32, u32);
typedef void (*Fn_002ead20)(u32, u32, u32);
typedef void (*Fn_002ebc38)(u32, u32, f32);
typedef void (*Fn_002ecdb0)(u32);
typedef void (*Fn_002ecdf8)(u32, u32);
typedef void (*Fn_002ece48)(u32, u32);
typedef void (*Fn_002ed478)(u32);
typedef void (*Fn_002f0798)(u32);
typedef void (*Fn_002f07c8)(u32);
extern u8 D_004f6288 asm("D_004f6288");

void func_0016d1a0(u32 a0) {
    u32 a1 = a0;
    u32 a2 = (u32)__builtin_return_address(0);
    u32 a0x = *(u32*)((u32)&D_004f6288 + (s32)(0));
    u32 t7 = *(u32*)((u32)a0x + (s32)(0));
    u32 v0 = *(u32*)((u32)t7 + (s32)(0));
    u32 r = ((u32(*)(u32,u32,u32))v0)(a0x, (u32)((s32)a1 + (16)), a2);
    *(u32*)((u32)r + (s32)(0)) = 0u;
}
}  // namespace v22

// 0016d1d8 (src/anon/tiny_leaf.cpp)
namespace v23 {

u32 func_0016d1d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r15 = *(u32*)((u32)r4 + (s32)(0));
    r2 = (u32)((s32)r4 + (16));
    r15 = (u32)((s32)r15 + (1));
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    return r2;
}
}  // namespace v23

// 0016d1f0 (src/anon/tiny_auto80_queue.cpp)
namespace v24 {
typedef void (*Fn_002cec50)(u32, u32);
typedef void (*Fn_002cf170)(u32, u32, u32, u32);
typedef u32  (*Fn_002cf1b8)(u32, u32);
typedef void (*Fn_002ead20)(u32, u32, u32);
typedef void (*Fn_002ebc38)(u32, u32, f32);
typedef void (*Fn_002ecdb0)(u32);
typedef void (*Fn_002ecdf8)(u32, u32);
typedef void (*Fn_002ece48)(u32, u32);
typedef void (*Fn_002ed478)(u32);
typedef void (*Fn_002f0798)(u32);
typedef void (*Fn_002f07c8)(u32);

void func_0016d1f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // ref_release
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r14, r15;
    r5 = r4;
    r15 = ((u32*)(u32)r4)[0];
    r15 = (u32)((s32)r15 + (-1));
    ((u32*)(u32)r4)[0] = r15;
    if (r15 == 0u) {
        r15 = (u32)(0x004fu << 16);
        r4 = ((u32*)(u32)r15)[6306];
        r14 = ((u32*)(u32)r4)[0];
        u32 f = ((u32*)(u32)r14)[1];
        ((void(*)(u32,u32,u32,u32,u32,u32,u32,u32))(u32)f)(r4, r5, r6, r7, r8, r9, r10, r11);
    }
}
}  // namespace v24

// 0016d230 (src/anon/batch_w24.cpp)
namespace v25 {
struct LNode { u32 _0; LNode* next; };
struct LMgr { u32 _0; LNode* head; u8 _8[92]; volatile u32 cur; };
extern LMgr* volatile D_00347f80 asm("D_00347f80");
static inline s32 list_has(LNode** hp, u32 a) {
    LNode* n = 0;
    while ((n = !n ? *(LNode* volatile*)hp : n->next) != 0) {
        if ((u32)n == a) return 1;
    }
    return 0;
}
u8 u_call4_00139d78(u32, u32, u32, u32) asm("_Z16u_call4_00139d78jjjj");
u8 u_call4_00139d78(u32 a, u32, u32, u32) asm("func_00139d78");
void u_call4_00167b08(u32, u32, u32, u32) asm("_Z16u_call4_00167b08jjjj");
void func_00167ad0(u8*, u32) asm("func_00167ad0");
extern u8 D_0034d3c0[] asm("D_0034d3c0");
void u_call4_00167b08(u32 a, u32, u32, u32) asm("func_00167b08");
void wtarget_0016d230(u32, u32, u32, u32) asm("_Z16wtarget_0016d230jjjj");
extern u32 D_004f6288 asm("D_004f6288");
extern u32 D_0032b91c asm("D_0032b91c");
struct W2 { u32 a; u32 b; };
extern W2 D_004f6290 asm("D_004f6290");

void wtarget_0016d230(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) D_004f6288 = D_0032b91c;
    if (b == 0xffff && a == 1) {
        D_004f6290.b = 0;
        D_004f6290.a = 0;
    }
}
}  // namespace v25

// 0016d280 (src/anon/tiny_wrappers_more.cpp)
namespace v26 {
u32 func_0016d230(u32, u32, u32, u32) asm("func_0016d230");

u32 func_0016d280(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_0016d230(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace v26

// 0016d2a0 .. 0016d2d0 (never written before; empty trap functions and a frame-time getter)
namespace v_d2a0 {
void func_0016d2a0(void) asm("func_0016d2a0");
void func_0016d2a0(void) {}
void func_0016d2a8(void) asm("func_0016d2a8");
void func_0016d2a8(void) {}
void func_0016d2b0(void) asm("func_0016d2b0");
void func_0016d2b0(void) {}
void func_0016d2b8(void) asm("func_0016d2b8");
void func_0016d2b8(void) {}
void func_0016d2c0(void) asm("func_0016d2c0");
void func_0016d2c0(void) {}
void func_0016d2c8(void) asm("func_0016d2c8");
void func_0016d2c8(void) {}
extern f32 D_00349e10 asm("D_00349e10");
void func_0016d2d0(f32* bd) asm("func_0016d2d0");
void func_0016d2d0(f32* bd) { *bd = D_00349e10; }
}  // namespace v_d2a0
