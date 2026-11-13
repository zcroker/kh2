#include "../common/types.h"

// Task manager (0x1022c0-0x102a70): TASK set-up, run and kill, coroutine tasks with their own
// stack (wait frames / wait time, resumed through the jmpbuf helpers at 0x105550-0x105728), the
// manager's priority-sorted task list, and the walks over it by flag mask. The current task
// (0x32b940) and the vtables (0x32b930, 0x32b950) are reached as data.

typedef void (*Fn0)(void);
typedef void (*Fn2)(u32, u32);

extern "C" {
// 0x1022c0: TASK set-up (manager, priority, flags, function).
void func_001022c0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7;
    *(volatile u32*)((u32)r4 + (s32)(36)) = r5;
    *(volatile u32*)((u32)r4 + (s32)(0)) = r8;
    *(volatile u32*)((u32)r4 + (s32)(40)) = r6;
    *(volatile u32*)((u32)r4 + (s32)(44)) = r7;
    *(volatile u32*)((u32)r4 + (s32)(68)) = 0u;
    *(volatile u32*)((u32)r4 + (s32)(48)) = 0u;
    *(volatile u32*)((u32)r4 + (s32)(52)) = 0u;
    *(volatile u32*)((u32)r4 + (s32)(64)) = 0u;
}

// 0x1022e8: TASK end: runs the exit hook, frees the coroutine block and the task.
void func_001022e8(u8* a0) {
    Fn0 fn = (Fn0) * (u32*)(a0 + 48);
    if (fn != 0) {
        fn();
    }

    u32 arg = *(u32*)(a0 + 52);
    if (arg != 0) {
        u32 obj = *(u32*)(a0 + 36);
        u32 vt = *(u32*)obj;
        Fn2 m = (Fn2) * (u32*)(vt + 4);
        m(obj, arg);
    }

    u32 obj = *(u32*)(a0 + 36);
    u32 vt = *(u32*)obj;
    Fn2 m = (Fn2) * (u32*)(vt + 4);
    m(obj, (u32)a0);
}

// 0x102350: runs one task: plain tasks call their function, coroutine tasks resume on their stack.
struct C102350 { u8 pad[240]; u8 started; u8 pad2[3]; s32 wait; f32 timer; s32 size; u8 stack[1]; };
struct T102350;
struct T102350 { void (*fn)(T102350*); u8 pad[32]; u8* q; u8 pad2[12]; C102350* co; };
extern f32 D_00349e10;
void func_001056e8__102350(u8*) asm("func_001056e8");
s32 func_00105550__102350(u8*) asm("func_00105550");
void func_00105710__102350(void) asm("func_00105710");
void func_001055b8__102350(C102350*) asm("_Z13func_001055b8Pv");
C102350* func_00105728__102350(void) asm("func_00105728");
void func_00102350(T102350* t)
{
    C102350* c;
    s32 r;
    if (t->co == 0) {
        t->fn(t);
        return;
    }
    func_001056e8__102350(t->q + 32);
    r = func_00105550__102350(t->q + 32);
    if (r != 0) {
        if (r == 1) t->fn = 0;
    } else {
        c = t->co;
        if (!c->started) {
            c->started = 1;
            // Switch to the coroutine's own stack (hand-written stack swap).
            asm volatile("move $sp,%0" : : "r"((u8*)t->co + t->co->size + 256));
            t->fn(t);
            func_001055b8__102350(func_00105728__102350());
        } else if (c->wait > 0) {
            c->wait--;
        } else if (c->timer > 0.0f) {
            c->timer -= D_00349e10;
        } else {
            func_001055b8__102350(c);
        }
    }
    func_00105710__102350();
}

// 0x102448: Tz::TaskYield: waits a1 frames, then yields back to the manager.
u32 func_00105620_u(u32, u32, u32, u32) asm("func_00105620");
u32 func_00102448(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u32*)((u32)(((u32)(*(u32*)((u32)(a0) + 52u)))) + 244u) = (u32)(a1);
    return func_00105620_u(((u32)(*(u32*)((u32)(a0) + 52u))), ((u32)(((u32)(*(u32*)((u32)(a0) + 36u)))) + 32u), a2, a3);
}

// 0x102470: waits x seconds (less one frame), then yields.
void func_00105620(u8*, u8*);
union U102470 { u8* p; f32 f; };
void func_00102470(u8* p, f32 x) {
    ((U102470*)(((U102470*)(p + 52))->p + 248))->f = x - D_00349e10;
    func_00105620(((U102470*)(p + 52))->p, ((U102470*)(p + 36))->p + 32);
}
}

// 0x1024a8: kills a task (clears its function).
struct IntSlot {
    s32 value;
};
void printf_1024a8(void* self) asm("_Z6printfPv");
void printf_1024a8(void* self) { reinterpret_cast<IntSlot*>(self)->value = 0; }

extern "C" {
// 0x1024b0: builds the task manager (288 bytes) from the allocator.
extern u8 D_0032b950[];
struct Allocator { void* (**vt)(Allocator*, u32, void*); };
u32* func_001024b0(Allocator* a) {
    u32* p = (u32*)a->vt[0](a, 288, __builtin_return_address(0));
    p[1] = (u32)a;
    p[68] = 0;
    p[3] = 0;
    p[2] = 0;
    p[4] = 0;
    p[0] = (u32)D_0032b950;
    return p;
}
}

// 0x102508: TASK_MANAGER::Create(void*, unsigned int).
extern "C" void* func_00106178(void* mem, u32 size);
extern "C" void func_001024b0_v(void* alloc) asm("func_001024b0");
class TASK_MANAGER {
public:
    static void Create(void* mem, u32 size);
};
void TASK_MANAGER::Create(void* mem, u32 size) {
    func_001024b0_v(func_00106178(mem, size));  // kn::MemoryAllocator::createMemoryAllocator
}

// 0x102528: inserts a task into the list sorted by priority.
namespace n00102528 {
struct LNode { u8 p0[44]; s32 key; u8 p48[8]; LNode* link[2]; };  // link[0]=next, link[1]=prev
struct LHead { LNode* head; LNode* tail; };
struct LList { u8 p0[8]; LHead ls; u8 p16[256]; LNode* cur; };
static inline LNode* LNext(LHead* l, LNode* n) { if (!n) return l->head; return n->link[0]; }
extern "C" void func_00102528(LList* l, LNode* n);
void func_00102528(LList* l, LNode* n)
{
    LNode* pv = 0;
    LNode* c = 0;
    LHead* h;
    while ((c = LNext(&l->ls, c))) {
        if (n->key < c->key) break;
        pv = c;
    }
    if (c && l->cur == c) l->cur = n;
    h = &l->ls;
    if (!pv) {
        if (!l->ls.head) {
            h->tail = n;
            l->ls.head = n;
            n->link[0] = 0;
            n->link[1] = 0;
        } else {
            l->ls.head->link[1] = n;
            n->link[1] = 0;
            n->link[0] = l->ls.head;
            l->ls.head = n;
        }
    } else if (pv == h->tail) {
        pv->link[0] = n;
        n->link[1] = h->tail;
        n->link[0] = 0;
        h->tail = n;
    } else {
        n->link[1] = pv;
        n->link[0] = pv->link[0];
        pv->link[0]->link[1] = n;
        pv->link[0] = n;
    }
}
}  // namespace n00102528

extern "C" {
// 0x1025f8: unlinks a task and ends it.
struct Nd223 { u8 p[0x38]; Nd223* next; Nd223* prev; };
struct Ls223 { Nd223* head; Nd223* tail; };
struct Ow223 { u32 f0; u32 f4; Ls223 l; u8 q[0x110 - 16]; Nd223* cur; };
extern void func_001022e8_n(Nd223*) asm("func_001022e8");

void func_001025f8(Ow223* o, Nd223* n) asm("_Z13func_001025f8Pv");
void func_001025f8(Ow223* o, Nd223* n) {
    if (n == o->cur) o->cur = n == 0 ? o->l.head : n->next;
    Ls223* l = &o->l;
    if (n->prev == 0) l->head = n->next; else n->prev->next = n->next;
    asm volatile("" ::: "memory");
    if (n->next == 0) l->tail = n->prev; else n->next->prev = n->prev;
    n->prev = 0; n->next = 0;
    func_001022e8_n(n);
}

// 0x102670
void func_001025f8_bd(BD_VALUE*) asm("func_001025f8");
void func_00102670(BD_VALUE* bd) { func_001025f8_bd(bd); }

// 0x102688: kills every task whose flags match (mask, value).
struct N102688 { u8 pad[40]; u32 fl; u8 pad2[12]; N102688* next; };
struct M102688 { u32 f0; u32 f4; N102688* head; };
void func_001025f8__102688(M102688*, N102688*) asm("func_001025f8");
static inline N102688* Next102688(M102688* m, N102688* p, u32 mask, u32 v)
{
    do {
        p = !p ? m->head : p->next;
    } while (p && (p->fl & mask) != v);
    return p;
}
void wtarget_00102688(M102688* m, u32 mask, u32 v, u32) asm("_Z16wtarget_00102688jjjj");
void wtarget_00102688(M102688* m, u32 mask, u32 v, u32)
{
    N102688* p = Next102688(m, 0, mask, v);
    while (p) {
        N102688* n = Next102688(m, p, mask, v);
        func_001025f8__102688(m, p);
        p = n;
    }
}

// 0x102730: kills every task.
u32 func_00102688_u(u32, u32, u32, u32) asm("func_00102688");
u32 func_00102730(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00102688_u(a0, 0x00000000u, 0x00000000u, a3);
}

// 0x102750: kills every task, then frees the manager (vtable slot 1 with (this, this)).
void func_00102730_v(void*) asm("func_00102730");
void func_00102750(void** p) {
    func_00102730_v(p);
    (*(void (**)(void*, void*))(*(u8**)p + 4))(p, p);
}

// 0x102788: TASK_MANAGER::create_task(int, int, void (*)(TASK*)).
void* create_task(void* self, int a, int b, void* fn) asm("_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE");
void func_001022c0_t(void*, void*, int, int, void*) asm("func_001022c0");
void func_00102528_t(void*, void*) asm("func_00102528");
void* create_task(void* self, int a, int b, void* fn) {
    typedef void* (*AllocFn)(void*, int, void*);
    void* t = (**(AllocFn**)self)(self, 72, __builtin_return_address(0));
    func_001022c0_t(t, self, a, b, fn);
    func_00102528_t(self, t);
    return t;
}

// 0x102818: creates a coroutine task with its own stack of `size` bytes.
u8* func_00102788(void*, u32, u32, u32);
typedef u8* (*AllocFn)(void*, u32, void*);
u8* func_00102818(void** heap, u32 a1, u32 a2, u32 a3, u32 size) {
    u8* blk = (*(AllocFn*)*heap)(heap, size + 256, __builtin_return_address(0));
    u8* r = func_00102788(heap, a1, a2, a3);
    *(u32*)(blk + 252) = size;
    blk[240] = 0;
    *(u32*)(blk + 244) = 0;
    *(u32*)(blk + 248) = 0;
    *(u32*)(r + 52) = (u32)blk;
    return r;
}

// 0x1028b0: runs every task whose flags match (mask, value); ended tasks are unlinked.
struct Task2 { s32 state; u8 pad[36]; u32 flags; u8 pad2[12]; Task2* next; };
struct Mgr2 { u8 pad[8]; Task2* head; u8 pad2[4]; Task2* cur; u8 pad3[252]; Task2* it; };
union UT2 { Task2* p; u8 c; };
extern UT2 D_0032b940;
void func_00102350_x1325(Task2*) asm("func_00102350");
void func_001025f8_m(Mgr2*, Task2*) asm("func_001025f8");
static inline Task2* Next2(Mgr2* m, Task2* t, u32 mask, u32 val)
{
    do {
        t = !t ? m->head : t->next;
    } while (t && (t->flags & mask) != val);
    return t;
}
void wtarget_001028b0(Mgr2* m, u32 mask, u32 val) asm("_Z16wtarget_001028b0jjjj");
void wtarget_001028b0(Mgr2* m, u32 mask, u32 val)
{
    Task2* t = Next2(m, 0, mask, val);
    while (t) {
        m->it = Next2(m, t, mask, val);
        Task2* saved = D_0032b940.p;
        D_0032b940.p = t;
        m->cur = t;
        func_00102350_x1325(t);
        D_0032b940.p = saved;
        m->cur = 0;
        if (!t->state) func_001025f8_m(m, t);
        Task2* n = m->it;
        if (n && (n->flags & mask) != val) {
            n = Next2(m, n, mask, val);
            m->it = n;
        }
        t = n;
    }
}

// 0x1029e8: runs every task.
u32 func_001028b0_u(u32, u32, u32, u32) asm("func_001028b0");
u32 func_001029e8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001028b0_u(a0, 0x00000000u, 0x00000000u, a3);
}

// 0x102a08: counts the tasks (list at p+8, linked through +56).
static inline u8* next_node(u8* p, u8* q) {
    if (!q) return *(u8**)(p + 8);
    return *(u8**)(q + 56);
}

s32 func_00102a08(u8* p) {
    s32 n = 0;
    u8* q = 0;
    while ((q = next_node(p, q))) n++;
    return n;
}

// 0x102a38: is a task with this function in the list?
struct Node38 { u32 key; u8 _4[52]; Node38* next; };
struct List8 { u32 _0; u32 _4; Node38* head; };
int func_00102a38(List8* list, u32 key) {  // list_contains_id
    Node38* n = 0;
    while ((n = !n ? list->head : n->next) != 0) {
        if (n->key == key) return 1;
    }
    return 0;
}
}
