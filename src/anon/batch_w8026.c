#include "../common/types.h"

/* 00111d98: look up a non-zero table entry after the matched one. */
extern void* D_00341708[];
void* wtarget_00111d98(void* a, u32 b, u32 c, u32 d) asm("_Z16wtarget_00111d98jjjj");
void* wtarget_00111d98(void* a, u32 b, u32 c, u32 d) {
    s32 i, j;
    for (i = 0; i < 3; i++) {
        if (i != 0 && D_00341708[i] == a) {
            for (j = 1; j < 3; j++) {
                s32 k = (i + j) % 3;
                if (k != 0 && D_00341708[k] != 0) return D_00341708[k];
            }
        }
    }
    return 0;
}

/* 0014fa48: allocate a 0xb60-byte object from the heap and construct it. */
struct A1Obj;
struct A1Vt { void* (*alloc)(struct A1Obj*, s32, s32); };
struct A1Obj { struct A1Vt* vt; };
struct A1Mgr { u8 pad[0x14]; struct A1Obj* heap; };
extern struct A1Mgr* D_00347f80;
void func_0031bcf8(void*);
void func_001516b0(void*, s32, s32, s32, f32, s32, s32);
void* func_0014fa48(s32 a, s32 b, s32 c, f32 f, s32 d, s32 e) {
    struct A1Obj* h = D_00347f80->heap;
    void* p = h->vt->alloc(h, 0xb60, 0);
    func_0031bcf8(p);
    func_001516b0(p, a, b, c, f, d, e);
    return p;
}

/* 00180448 */
struct VObj;
struct VObjVt { void* a; void* b; s32 (*get)(struct VObj*); };
struct VObj { struct VObjVt* vt; };
struct Obj180 { u8 pad[0x14]; s32 mode; u8 pad2[0x14]; f32 div; f32 base; };
extern f32 D_00349e10;
s32 func_0017ec98(struct Obj180*, s32);
s32 func_0017edf0(struct Obj180*, s32);
struct VObj* func_00180408(struct Obj180*, s32);
f32 func_002f8b00(f32, f32);
f32 func_00180448(struct Obj180* o, s32 n, f32 x, f32 y) {
    s32 ok = (u32)(n - 1) < 2;
    if ((u32)(o->mode - 1) < 2 && ok) {
        f32 t = (o->base + D_00349e10 + x) / o->div;
        struct VObj* v = func_00180408(o, func_0017edf0(o, func_0017ec98(o, n)));
        f32 c = v->vt->get(v);
        return func_002f8b00(c * t, c);
    }
    return y;
}
