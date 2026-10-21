#include "../common/types.h"

extern "C" {

/* 002eef08 */
struct VObj;
struct VObjVt { void* a; void* b; s32 (*get)(VObj*); };
struct VObj { VObjVt* vt; };
struct Ent { u8 pad[8]; u32 v; };
Ent* func_00168b38(u32, s32, s32);
void func_002ef180(void*, f32, f32);
struct E2 { u8 pad[8]; VObj* o; u32 c; f32 f; f32 g; };

void func_002eef08(E2* e, u32 a, f32 f) {
    e->o = (VObj*)func_00168b38(a, 9, 0)->v;
    e->c = func_00168b38(a, 16, 0)->v;
    VObj* o = e->o;
    e->f = f;
    e->g = (f32)o->vt->get(o);
    func_002ef180(e, f, -1.0f);
}

/* 00160388 */
struct Alloc;
struct AllocVt { void* a; void (*free)(Alloc*, void*); };
struct Alloc { AllocVt* vt; };
extern Alloc* D_0034c738;
extern u8 D_0034c750[];
struct Mgr;
struct MgrVt { void* s[10]; void (*rel)(Mgr*, Alloc*, u32); };
struct Mgr { MgrVt* vt; };
void func_00161530(void*);
struct __attribute__((aligned(16))) V16 { u32 x[4]; ~V16() {} };
struct Obj {
    u32 vt; Mgr* mgr; u8 pad[0x88]; V16 arr[8]; u8 m110[0xb0]; u32 h1c0;
};

void func_00160388(Obj* o) {
    o->vt = (u32)D_0034c750;
    Mgr* m = o->mgr; m->vt->rel(m, D_0034c738, o->h1c0);
    func_00161530(o->m110);
    if (o->arr) {
        V16* p = o->arr + 8;
        for (;;) { p->~V16(); if (o->arr == p) break; --p; }  // gcc pads this empty dtor loop with nops
    }
    D_0034c738->vt->free(D_0034c738, o);
}

}
