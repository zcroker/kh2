#include "../common/types.h"

#define W8007_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

extern "C" {

/* 001703a8: walk the target list and kill entries with a matching id. */
struct W8007Tgt { u8 pad[0x28]; u32 id; u8 pad2[0x10]; W8007Tgt* next; };
extern W8007Tgt* D_0034dca0;
void func_001700e8(W8007Tgt*, s32);
void w8007_wtarget_001703a8(u32 id) asm("_Z16wtarget_001703a8jjjj");
void w8007_wtarget_001703a8(u32 id) {
    W8007Tgt* n;
    for (W8007Tgt* p = D_0034dca0; __builtin_expect(p != 0, 0); p = n) {
        n = p->next;
        if (p->id == id) func_001700e8(p, 1);
    }
}

/* 00172078: the float argument is declared last so it is loaded last. */
void func_001945a0(u8*, s32, u32, f32);
struct W8007O72 { u8 pad[4]; u8* p; };
struct W8007S72 { W8007O72* o; s32 a; u32 b; f32 f; };
void func_00172078(W8007S72* s) {
    u8* p = s->o->p;
    func_001945a0(p, s->a, s->b, s->f);
}

/* 0017d8c0: 16-byte copy through lq/sq (asm, no C equivalent). */
struct W8007V4 {
    f32 x, y, z, w;
    W8007V4& operator=(const W8007V4& s) {
        if (__builtin_expect(this != &s, 0)) W8007_QCOPY(this, &s);
        return *this;
    }
} __attribute__((aligned(16)));
struct W8007Obj { u8 pad[0x30]; W8007V4 v; };
void func_0011b6a8(void*);
void func_0011b7b0(void*, u32);
W8007Obj* func_0017d8c0(W8007Obj* a0, W8007V4* v, W8007V4* a2) {
    func_0011b6a8(a0);
    u32 t = (u32)v;
    v = &a0->v;
    func_0011b7b0(a0, t);
    *v = *a2;
    v->w = 1.0f;
    return a0;
}

/* 001a6fe8: open a window and wait until it closes. */
void* w8007_Alloc(u32) asm("_ZN4AREA5AllocEj");
struct W8007Win;
struct W8007WinVt { void* f[8]; void (*Close)(W8007Win*); };
struct W8007Win { W8007WinVt* vt; u8 pad[0x6c]; s32 state; u8 pad2[0xb6c - 0x74]; };
struct W8007Msg { u16 type; u16 pad; u32 arg; };
struct W8007Task { u8 pad[16]; u32 task; };
void w8007_WinObj2D(void*, W8007Win*) asm("_ZN2YS12WINDOW_OBJ2DC1EPNS_6WINDOWE");
s32 func_001a74f8(s32);
void func_00102448(u32, s32);
void func_001ad228(W8007Win*, u32);
static inline bool w8007_IsOpen(W8007Win* w) { return w->state != 3; }
s32 func_001a6fe8(W8007Msg* m, W8007Task* t) {
    u32 task = t->task;
    if (m->type == 1) {
        u32 arg = m->arg;
        W8007Win* w = (W8007Win*)w8007_Alloc(0xb6c);
        func_001ad228(w, arg);
        w8007_WinObj2D(w8007_Alloc(0x1c), w);
        while (w8007_IsOpen(w) && func_001a74f8(14)) func_00102448(task, 0);
        w->vt->Close(w);
    }
    return 1;
}

}
