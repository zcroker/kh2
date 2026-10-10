#include "../common/types.h"

struct W261A { int pad; };
typedef int (W261A::*W261Pmf)();
struct W261E { W261Pmf f; } __attribute__((aligned(8)));
struct W261R { u32 pfn; int d; } __attribute__((aligned(8)));
extern W261E D_00345ad0[];
typedef int (*W261Fn)(void*);

struct W261En { u8 id; u8 lv; u8 kind; u8 pad[33]; u16 req; u8 pad2[18]; };
struct W261Tb { u32 x; s32 n; W261En e[1]; };
extern W261Tb* D_01c6cb28;
extern u8 D_0032bae0;
union W261U { u32 v; u8 c; };
struct W261Ent { W261U a; W261U b; W261U c; };
struct W261Ring { W261U idx; u32 pad; W261Ent e[8]; };
struct W261Src { u16 h0; u16 id; u8 pad[6]; u16 flag; };
struct W261Inf { u8 pad[8]; u16 a; u16 b; u8 pad2[8]; u16 c; };
extern W261Ring D_01c6cba0;
extern void* D_0034e948;
extern u32 D_0032dedc[];
union W261Vf { u32 (*f)(void*); u8 c; };
struct W261Act {
    W261Vf* vt; u8 pad4[24]; f32 f28; u8 pad32[8]; f32 f40; f32 f44; u8 b48; u8 b49; u8 pad50[22];
    u32 f72; f32 f76; u32 f80;
};
extern f32 D_00375d40;
extern u8 D_00362bf8[];
extern "C" {
int func_0010cc80(void*);
int func_001b58a8(void);
int func_00112720(void*);  // check_2924_lt14

int func_0010d188(W261A* p) {
    if (!func_0010cc80(p)) return 1;
    if (func_001b58a8()) return 1;
    if (func_00112720(p)) {  // check_2924_lt14
        return (p->*D_00345ad0[*(int*)((char*)p + 0xb6c) - 8].f)();
    }
    int i = (*(int (**)(void*))(*(u32*)p + 152))(p);
    W261E ee = D_00345ad0[i];
    W261R& e = *(W261R*)&ee;
    int d = e.d;
    char* q = (char*)p + (d >> 1);
    W261Fn fn;
    if ((u8)(d & 1)) fn = *(W261Fn*)(((e.pfn >> 2) << 2) + *(u32*)q);
    else fn = (W261Fn)e.pfn;
    return fn(q);
}

s32 func_001a3570(u32);
static inline W261En* W261Find(s32 id) {
    W261Tb* t = D_01c6cb28;
    W261En* e = t->e;
    for (s32 i = 0; i < t->n; i++, e++) {
        if (e->id == id) return e;
    }
    return 0;
}
W261En* func_001a6658(s32 id) {
    W261En* e = W261Find(id);
    W261En* best = e;
    if (!e) return 0;
    s32 lv = 0;
    if (e->req) {
        lv = func_001a3570(e->req);
        if (!lv) return 0;
    }
    W261Tb* t = D_01c6cb28;
    W261En* end = &t->e[t->n];
    u8 k = D_0032bae0;
    W261En* p = e + 1;
    while (p < end && p->id == best->id && p->lv <= lv) {
        if (p->kind == 0 || p->kind == k) best = p;
        p++;
    }
    return best;
}

W261Inf* func_001a80c8(u32);  // table24_find_by_id
u32 func_00192048(u32);
u32 func_0016a070(void*);
s32 func_001a3018(u32, u32, u32);
void func_001a3188(u32, s32, u32);
u32 wtarget_001a82f0(W261Src* s) asm("_Z16wtarget_001a82f0jjjj");
u32 wtarget_001a82f0(W261Src* s) {
    s32 i = D_01c6cba0.idx.v;
    D_01c6cba0.idx.v = (i + 1) % 8;
    u8* b = (u8*)&D_01c6cba0 + i * 12;
    W261Ent* e = (W261Ent*)(b + 8);
    void* o = D_0034e948;
    s32 r = 100;
    W261Inf* inf = func_001a80c8(s->id);  // table24_find_by_id
    ((W261U*)(b + 8))->v = func_00192048(inf->a);
    e->b.v = func_00192048(inf->b);
    e->c.v = inf->c;
    if (o) r = func_001a3018(s->id, func_0016a070(o), 1);
    func_001a3188(s->id, r, 0);
    u32 f = s->flag;
    if (f) D_0032dedc[f >> 5] |= 1 << (f & 31);
    return e->c.v;
}

void func_002de698(u32);
void func_0017f488(u8*, u32, f32, f32);
s32 func_002ddbb8(u32);  // get_bit0_of_field2808
void* func_0016b740(s32);
void func_002e7568(void*, s32, void*, f32);
void func_002dfe38(W261Act* o, u8* a1, u32 a2, u32 a3, f32 f) {
    func_002de698(a2);
    o->f72 = a2;
    o->f80 = a3;
    o->f76 = f;
    o->b49 = 0;
    u32 v = o->vt[12].f(o);
    func_0017f488(a1 + 320, v, 0.0f, 0.0f);
    o->f40 = 0.0f;
    o->f44 = 0.0f;
    o->f28 = -(o->f76 + D_00375d40) * 0.01f;
    if (func_002ddbb8(o->f72)) {  // get_bit0_of_field2808
        void* p = func_0016b740(1635);
        if (p) func_002e7568(p, 2, D_00362bf8, 1.0f);
    }
}

}
