// Linked unit 0x00120520-0x00121cc8 (one namespace per old matched source; class methods in their own namespace).
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

// 00120520 (gap function, not written before)
namespace g00120520 {
u32 kn__ModelBG__drawCommon(u32, u32, u32, u32, u32, u8, u32) asm("kn__ModelBG__drawCommon");
u32 func_00120520(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u8 a6, u32 a7) asm("func_00120520");
struct NoTail { ~NoTail() {} };
u32 func_00120520(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u8 a6, u32 a7) {
    NoTail nt;
    return kn__ModelBG__drawCommon(a0, a1, a3, a4, a5, a6, a7);
}
}  // namespace g00120520

// 00120550 (was src/anon/tiny_auto80_solver.cpp)
namespace n00120550 {
u32 kn__ModelBG__drawCommon(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z23kn__ModelBG__drawCommonjjjjjjjj");
/*TARGET 00120550*/
u32 kn__ModelBG__drawOnShadow(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z25kn__ModelBG__drawOnShadowjjjjjjjj");
u32 kn__ModelBG__drawOnShadow(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2;
    r6 = r7;
    r7 = r8;
    r9 = (u32)(r9 & 0x00ffu);
    r8 = 0u;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))kn__ModelBG__drawCommon)(r4, r5, r6, r7, r8, r9, r10, r11);
    if (r2 != 0) {
        return r2;
    }
    return r2;
}
}  // namespace n00120550

// 00120578 (gap function, not written before)
namespace g00120578 {
struct E { u32 a; u16 b; u16 fl; u32 c; u16 d; u16 e; };
struct H { u8 pad[16]; u16 cnt; u8 pad2[6]; u32 f24; u8 pad3[4]; E e[1]; };
struct O { void* vt; H* h; };
// Sum of the part sizes of the visible parts.
u32 func_00120578(O* o, s8* vis) asm("func_00120578");
u32 func_00120578(O* o, s8* vis) {
    H* h = o->h;
    u32 r = 0;
    for (s32 i = 0; i < h->cnt; i++)
        if (vis[i]) r += h->e[i].e;
    return r;
}
}  // namespace g00120578


// 001205c0 (gap function, not written before)
namespace g001205c0 {
struct E { u32 a; u16 b; u16 fl; u32 c; u32 g; };
struct H { u8 pad[24]; u32 f24; u8 pad2[4]; struct E e[1]; };
struct O { void* vt; struct H* h; };
u32 func_001205c0(struct O* o, s16* list) asm("func_001205c0");
u32 func_001205c0(struct O* o, s16* list) {
    struct H* h = o->h;
    u32 r = 0;
    short k;
    if (*list != -1) {
        u32* tbl = (u32*)((u8*)h + h->f24);
        while ((k = *list++) != -1) {
            s16* p;
            for (p = (s16*)((u8*)h + tbl[k & 0x7fff]); *p >= 0; p++) {
                s32 j = *p; struct E* e = (struct E*)((u32)(j << 4) + (u32)h + 32);
                u32 t = e->g & 1;
                if (t) continue;
                r += ((u16*)&e->g)[1];
            }
        }
    }
    return r;
}
}  // namespace g001205c0

// 00120648 (was src/anon/batch_w64.cpp)
namespace n00120648 {
// 0x0010f6f8: definition moved into src/anon/unit_0010f338.cpp

// ---------------------------------------------------------------------------
void func_0011ee18(void*) asm("func_0011ee18");
// obj_ctor_347940
extern char D_00347a28[] asm("D_00347a28");
struct Entry20648 { u32 b0 : 1; u32 m : 28; u32 b29 : 1; u32 hi : 2; u32 pad[7]; };
struct Hdr20648 { u8 pad[0x1c]; s32 n; Entry20648 e[1]; };
/*TARGET 00120648*/
// Constructor: base ctor, vtable, then collect flag bits from the entry list.
void func_00120648(u8* self) asm("func_00120648");
// Constructor: base ctor, vtable, then collect flag bits from the entry list.
void func_00120648(u8* self) {
    func_0011ee18(self);  // obj_ctor_347940
    Hdr20648* h = *(Hdr20648**)(self + 4);
    *(u32*)self = (u32)D_00347a28;
    for (s32 i = 0; i < h->n; i++) {
        if (h->e[i].b0) *(u32*)(self + 12) |= 1;
        if (h->e[i].b29) *(u32*)(self + 12) |= 2;
    }
}
}  // namespace n00120648

// 001206e0 (was src/anon/batch_w65.cpp)
namespace n001206e0 {
// Constructor: base init, vtable, then collect flag bits 0 / 29 of each 32-byte entry.
struct FlagEnt { u32 f; u32 x[7]; };
struct FlagHdr { u8 pad[28]; s32 n; FlagEnt e[1]; };
void func_0011ee18(void*) asm("func_0011ee18");
// obj_ctor_347940
extern u8 D_00347a28[] asm("D_00347a28");
/*TARGET 001206e0*/
void func_001206e0(u32* p) asm("func_001206e0");
void func_001206e0(u32* p) {
    func_0011ee18(p);  // obj_ctor_347940
    p[0] = (u32)D_00347a28;
    FlagHdr* d = (FlagHdr*)p[1];
    s32 i;
    for (i = 0; i < d->n; i++) {
        u32 m = d->e[i].f & 1;
        if (m) p[3] |= 1;
        m = d->e[i].f >> 29 & 1;
        if (m) p[3] |= 2;
    }
}
}  // namespace n001206e0

// 00120778 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00120778 {
u32 func_0011ee58(u32, u32, u32, u32) asm("_Z13func_0011ee58jjjj");
extern u8 D_00347a28 asm("D_00347a28");
/*TARGET 00120778*/
u32 func_00120778(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00120778jjjj");
u32 func_00120778(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347a28;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_0011ee58)(u32, u32, u32, u32) = func_0011ee58;
    r2 = fp_call4_0011ee58(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00120778

// 001207a0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n001207a0 {
u32 func_0011ee58(u32, u32, u32, u32) asm("_Z13func_0011ee58jjjj");
extern u8 D_00347a28 asm("D_00347a28");
/*TARGET 001207a0*/
u32 func_001207a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001207a0jjjj");
u32 func_001207a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347a28;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_0011ee58)(u32, u32, u32, u32) = func_0011ee58;
    r2 = fp_call4_0011ee58(r4, r5, r6, r7);
    return r2;
}
}  // namespace n001207a0

// 001207c8 (was src/anon/batch_w13.cpp)
namespace n001207c8 {
void func_0011ee58(void*) asm("func_0011ee58");
// set_vtbl_347940
void func_00106420(void*) asm("func_00106420");
extern u8 D_00347a28 asm("D_00347a28");
extern void (*D_0035e380[])(void) asm("D_0035e380");
/*TARGET 001207c8*/
void func_001207c8(void** p) asm("func_001207c8");
void func_001207c8(void** p) {
    *p = &D_00347a28;
    func_0011ee58(p);  // set_vtbl_347940
    func_00106420(p);
}
}  // namespace n001207c8

// 00120800 (was src/anon/tiny_leaf_more.cpp)
namespace n00120800 {
/*TARGET 00120800*/
// 0x00112720: definition moved into src/anon/unit_001117d8.cpp

u32 func_00120800(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00120800jjjj");
// 0x00112720: definition moved into src/anon/unit_001117d8.cpp

u32 func_00120800(u32 a0, u32 a1, u32 a2, u32 a3) {  // obj_get_sub_ptr_by12
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r15 = 0u;
    r2 = *(u32*)((u32)r4 + (s32)(4));
    r15 = *(u32*)((u32)r2 + (s32)(12));
    r2 = (u32)(r2 + r15);
    if (r15 == 0u) r2 = 0u;
    return r2;
}
}  // namespace n00120800

// 00120818 (gap function, not written before)
namespace g00120818 {
struct V {
    f32 x, y, z, w;
    V& operator=(const V& s) { if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct Ext { u8 pad[16]; V a; V b; };
struct H { u8 pad[24]; u32 ext; };
struct O { void* vt; H* h; };
static inline u8* Ext(O* o) { return (u8*)o->h + o->h->ext; }
f32 func_00120818(O* o) asm("func_00120818");
f32 func_00120818(O* o) { return *(f32*)(Ext(o) + 272); }
void func_00120830(O* o, V* a, V* b) asm("func_00120830");
void func_00120830(O* o, V* a, V* b) {
    V* s = (V*)Ext(o);
    if (a != s) *a = *s;
    s++;
    if (b != s) *b = *s;
}
f32 func_00120868(O* o, s32 i) asm("func_00120868");
f32 func_00120868(O* o, s32 i) { H* h = o->h; f32* f = (f32*)((u8*)h + h->ext + 32); return f[i]; }
u32 func_00120888(O* o, s32 i) asm("func_00120888");
u32 func_00120888(O* o, s32 i) { return ((u32*)(Ext(o) + 48))[i]; }
u32 func_001208a8(O* o) asm("func_001208a8");
u32 func_001208a8(O* o) { return *(u16*)((u8*)o->h + 16); }
}  // namespace g00120818

// 001208b8 (was src/anon/tiny_auto80_queue.cpp)
namespace n001208b8 {
/*TARGET 001208b8*/
u32 func_001208b8(u8* a0) asm("_Z13func_001208b8Ph");
u32 func_001208b8(u8* a0) {
    u32 t6 = *(u32*)a0;
    u32 (*fn)(u8*) = *(u32 (**)(u8*))(t6 + 0x1c);
    u32 s0 = *(u32*)(a0 + 4);
    u32 v0 = fn(a0);
    u32 t7 = 0;
    if (v0 != 0) {
        u32 t8 = *(u32*)(s0 + 20);
        t7 = s0;
        t7 += t8;
    }
    return t7;
}
}  // namespace n001208b8

// 001208f8 (was src/anon/batch_w2384.cpp)
namespace n001208f8 {
s32 func_00120800(void*) asm("func_00120800");
// Size of one packed table: header count at +0x1c, 32-byte entries from +0x34,
// each pointing at a list whose negative entries take two slots.
static inline __attribute__((always_inline)) s32 tableSize(u8* p) {
    s32 n = *(s32*)(p + 0x1c);
    s32 c = 0;
    s32 i;
    for (i = 0; i < n; i++) {
        s32* q = (s32*)(p + *(s32*)(p + 0x34 + i * 32));
        s32 m = *q;
        c++;
        if (m > 0) {
            s32 k = c;
            s32* e = q + 1;
            s32 j = m;
            do {
                if (*e < 0) k += 2; else k += 1;
                e++;
            } while (--j);
            c = k;
        }
        c += 2;
    }
    return c * 16 + ((n * 4 + 15) & ~15);
}
/*TARGET 001208f8*/
// Total size of the object's main table plus its optional second table.
s32 kn__ModelSKL__getDMATagBufferSize(void* a0) asm("kn__ModelSKL__getDMATagBufferSize");
// Total size of the object's main table plus its optional second table.
s32 kn__ModelSKL__getDMATagBufferSize(void* a0) {
    u8* s = *(u8**)((u8*)a0 + 4);
    s32 o = func_00120800(a0);
    s32 r = tableSize(s);
    if (o) r += tableSize((u8*)o);
    return r;
}
}  // namespace n001208f8

// 00120a20 (was src/anon/batch_w3801_nsamam.cpp)
namespace n00120a20 {
struct Pk120a20 { u32 addr; };
struct Ent120a20 { u16 qwc; u8 pad[2]; s32 off; s32 a; s32 b; };
struct Lst120a20 { s32 n; s32 ids[1]; };
struct Grp120a20 { u8 pad[16]; s32 ent; s32 lst; u8 pad2[8]; };
struct Mdl120a20 { u8 pad[28]; s32 count; Grp120a20 grp[1]; };
struct Obj120a20 { u8 pad[4]; Mdl120a20* mdl; };
struct Tx120a20 { u8 pad[44]; u32 addr[1]; };
Mdl120a20* func_00120800(Obj120a20*) asm("func_00120800");
void func_001339d0(Pk120a20*, u32, s32, s32, s32) asm("func_001339d0");
void func_00133848(Pk120a20*, s32, u32, s32) asm("func_00133848");
void func_00133898(Pk120a20*, s32, u32, s32) asm("func_00133898");
/*TARGET 00120a20*/
/* Builds the DMA packet for a model and its second model group list. */
u32 func_00120a20(Obj120a20* o, Tx120a20* tx, u32* outs, u32 addr, s32 n) asm("func_00120a20");
/* Builds the DMA packet for a model and its second model group list. */
u32 func_00120a20(Obj120a20* o, Tx120a20* tx, u32* outs, u32 addr, s32 n)
{
    Mdl120a20* m = o->mdl;
    Mdl120a20* m2 = func_00120800(o);
    Pk120a20 p;
    s32 i, j;
    p.addr = addr;
    for (i = 0; i < m->count; i++) {
        outs[i] = p.addr;
        Ent120a20* e = (Ent120a20*)((u8*)m + m->grp[i].ent);
        Lst120a20* l = (Lst120a20*)((u8*)m + m->grp[i].lst);
        func_001339d0(&p, (u32)m + e->off, e->qwc, e->a, e->b);
        e++;
        for (j = 0; j < l->n; j++) {
            s32 t = l->ids[j];
            if (t < 0) {
                func_00133848(&p, 0, 0x17000000, 0);
                e++;
                func_001339d0(&p, (u32)m + e->off, e->qwc, e->a, e->b);
                e++;
            } else {
                func_001339d0(&p, tx->addr[n] + t * 64, 4, e->a, e->b);
                e++;
            }
        }
        func_00133898(&p, 0, 0x17000000, 0);
    }
    if (m2) {
        for (i = 0; i < m2->count; i++) {
            outs[m->count + i] = p.addr;
            Ent120a20* e = (Ent120a20*)((u8*)m2 + m2->grp[i].ent);
            Lst120a20* l = (Lst120a20*)((u8*)m2 + m2->grp[i].lst);
            func_001339d0(&p, (u32)m2 + e->off, e->qwc, e->a, e->b);
            e++;
            for (j = 0; j < l->n; j++) {
                s32 t = l->ids[j];
                if (t < 0) {
                    func_00133848(&p, 0, 0x17000000, 0);
                    e++;
                    func_001339d0(&p, (u32)m2 + e->off, e->qwc, e->a, e->b);
                    e++;
                } else {
                    func_001339d0(&p, tx->addr[n] + t * 64, 4, e->a, e->b);
                    e++;
                }
            }
            func_00133898(&p, 0, 0x17000000, 0);
        }
    }
    return p.addr;
}
}  // namespace n00120a20

// 00120cf0 (was src/anon/perm_00120cf0.cpp)
namespace n00120cf0 {
typedef struct B120cf0 B120cf0;
typedef struct S120cf0 S120cf0;
typedef struct VT120cf0 VT120cf0;
typedef struct S120cf0 S120cf0;
typedef struct VT120cf0 VT120cf0;
typedef struct B120cf0 B120cf0;
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;
struct VT120cf0
{
  void *f[12];
  s32 (*count)(S120cf0 *);
};
struct S120cf0
{
  VT120cf0 *vt;
};
union U120cf0
{
  u32 u;
  VT120cf0 *v;
};
struct B120cf0
{
  u8 pad[0x108];
  U120cf0 base;
  U120cf0 mid;
};
u32 func_00120a20(S120cf0 *, B120cf0 *, u32, u32, s32) asm("func_00120a20");
/*TARGET 00120cf0*/
void func_00120cf0(S120cf0 *s, B120cf0 *b, u32 base) asm("func_00120cf0");
void func_00120cf0(S120cf0 *s, B120cf0 *b, u32 base)
{
  U120cf0 new_var2;
  u32 end;
  b->base.u = base;
  b->mid.u = b->base.u + (s->vt->count(s) * 4);
  end = ((b->mid.u + (s->vt->count(s) * 4)) + 15) & (~15);
  base = func_00120a20(s, b, b->base.u, end, 0);
  func_00120a20(s, b, (new_var2 = b->mid).u, base, 1);
}
}  // namespace n00120cf0

// 00120d90 (gap function, not written before)
namespace g00120d90 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V& operator=(const V& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
struct Alloc {
    virtual u8* alloc(u32 size, void* ra);
};
struct Part { u8 pad[16]; V a; V b; V c; };
struct Hdr { u8 pad[16]; u16 cnt; u8 pad2[2]; u32 parts; };
struct Mdl {
    virtual void f0(); virtual void f1(); virtual s32 f2(); virtual void f3(); virtual void f4(); virtual void f5();
    virtual void f6(); virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11();
    virtual s32 size();
    Hdr* hdr;
};
struct Obj {
    u8 pad0[16];
    Alloc* al;
    u8 pad1[8];
    V* p28;
    V* p32;
    V* p36;
    u8* p40;
    u8* p44;
    u8* p48;
    u8 pad2[260 - 52];
    u8* vis;
};
void func_0011c2d0(Obj*) asm("func_0011c2d0");
void func_00120cf0(Mdl*, Obj*, u8*) asm("func_00120cf0");
void func_0011eef8(Mdl*, Obj*) asm("func_0011eef8");
Obj* func_00120d90(Mdl* mdl, Alloc* al) asm("func_00120d90");
Obj* func_00120d90(Mdl* mdl, Alloc* al)
{
    s32 i = 0;
    Hdr* h = mdl->hdr;
    u32 off = (mdl->size() + 15) & ~15;
    u32 sz = off + mdl->f2() * 2;
    void* ra = __builtin_return_address(0);
    Obj* o = (Obj*)al->alloc(sz + h->cnt * 48 + 304, ra);
    func_0011c2d0(o);
    o->vis = (u8*)o + 304;
    for (i = 0; i < mdl->size(); i++) o->vis[i] = 1;
    V* p = (V*)(o->vis + off);
    o->p28 = p;
    p += h->cnt;
    o->p32 = p;
    p += h->cnt;
    o->p36 = p;
    Part* e = (Part*)((u8*)h + h->parts);
    for (i = 0; i < h->cnt; i++) {
        o->p28[i] = e[i].a;
        o->p32[i] = e[i].b;
        o->p36[i] = e[i].c;
    }
    u8* q = al->alloc(h->cnt * 192, __builtin_return_address(0));
    o->p40 = q;
    q += h->cnt * 64;
    o->p44 = q;
    q += h->cnt * 64;
    o->al = al;
    o->p48 = q;
    func_00120cf0(mdl, o, (u8*)(o->p36 + h->cnt));
    func_0011eef8(mdl, o);
    return o;
}
#undef QCOPY
}  // namespace g00120d90

// 00120fd0 (gap function, not written before)
namespace g00120fd0 {
u32 func_0011ef20(u32, u32, u32) asm("func_0011ef20");
u32 func_00120fd0(u32 a0, u32 a1, u32 a2) asm("func_00120fd0");
u32 func_00120fd0(u32 a0, u32 a1, u32 a2) {
    return func_0011ef20(a0, a1, a2);
}
}  // namespace g00120fd0

// 00120fe8 (gap function, not written before)
namespace g00120fe8 {
typedef unsigned int u128 __attribute__((mode(TI)));
struct Vq { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Mtx {
    Vq r[4];
    Mtx& operator=(const Mtx& s) {
        if (this != &s)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&s) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Pose { u8 pad[4]; s16 parent; u8 pad2[10]; Vq scale; Vq rot; Vq trans; };
struct Mdl {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5();
    virtual void f6(); virtual s32 count(); virtual Pose* poses();
};
struct Obj { u8 pad[40]; Mtx* local; Mtx* world; };
void func_0011b6a8(Mtx*) asm("func_0011b6a8");
void func_0011b7b0(Mtx*, const Vq*) asm("func_0011b7b0");
static inline void Scale(Mtx* m, const Vq* s) {
    asm volatile("lqc2 $vf4, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\t"
                 "vmulx.xyzw $vf1, $vf1, $vf4x\n\tvmuly.xyzw $vf2, $vf2, $vf4y\n\tvmulz.xyzw $vf3, $vf3, $vf4z\n\t"
                 "sqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)" : : "r"(m), "r"(s) : "memory");
}
static inline void Translate(Mtx* m, const Vq* t) {
    asm volatile("lqc2 $vf1, 48(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 48(%0)"
                 : : "r"(m), "r"(t) : "memory");
}
static inline void Mul(Mtx* d, const Mtx* a, const Mtx* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
// Builds every part's local matrix (scale, rotation, translation) and its world matrix.
void func_00120fe8(Mdl* mdl, Obj* o) asm("func_00120fe8");
void func_00120fe8(Mdl* mdl, Obj* o)
{
    Pose* ps = mdl->poses();
    s32 n = mdl->count();
    for (s32 i = 0; i < n; i++) {
        Pose* p = &ps[i];
        func_0011b6a8(&o->local[i]);
        Scale(&o->local[i], &p->scale);
        func_0011b7b0(&o->local[i], &p->rot);
        Translate(&o->local[i], &p->trans);
        if (p->parent < 0) {
            o->world[i] = o->local[i];
        } else {
            Mtx* d = &o->world[i];
            Mtx t;
            Mul(&t, &o->world[p->parent], &o->local[i]);
            *d = t;
        }
    }
}
}  // namespace g00120fe8

// 001211e0 (gap function, not written before)
namespace g001211e0 {
struct H { u8 pad[28]; u32 n; };
struct O { void* vt; H* h; };
H* func_00120800(O*) asm("func_00120800");
u32 func_001211e0(O* o) asm("func_001211e0");
u32 func_001211e0(O* o) {
    H* a = o->h;
    H* b = func_00120800(o);
    u32 r = a->n;
    if (b) r += b->n;
    return r;
}
}  // namespace g001211e0

// 00121218 (was src/anon/batch_w273.cpp)
namespace n00121218 {
struct SE273 { u32 w; u8 pad[28]; };
struct Sub273 { u8 pad[28]; s32 n; SE273 e[1]; };
struct Own273 { u8 pad[4]; Sub273* sub; };
// 0x001affe0: definition moved into src/anon/unit_001ada38.cpp

Sub273* func_00120800(Own273*) asm("func_00120800");
// obj_get_sub_ptr_by12
void func_0011efe8(Own273*, u8*) asm("func_0011efe8");
/*TARGET 00121218*/
void func_00121218(Own273* o, u8* fl, u16* list) asm("func_00121218");
void func_00121218(Own273* o, u8* fl, u16* list) {
  Sub273* a = o->sub;
  Sub273* b = func_00120800(o);  // obj_get_sub_ptr_by12
  s32 i;
  func_0011efe8(o, fl);
  while ((s16)*list != -1) {
    s16 m = *list & 0x8000;
    u8 bit = m ? 2 : 1;
    for (i = 0; i < a->n; i++)
      if (((a->e[i].w >> 6) & 0x1f) == (u32)(*list & 0x7fff)) fl[i] |= bit;
    if (b)
      for (i = 0; i < b->n; i++)
        if ((b->e[i].w & 0x1f) == (u32)(*list & 0x7fff)) fl[a->n + i] |= bit;
    list++;
  }
}
}  // namespace n00121218

// 00121380 (gap function, not written before)
namespace g00121380 {
struct SE { u32 w; u8 pad[28]; };
struct Sub { u8 pad[28]; s32 n; SE e[1]; };
struct O { void* vt; Sub* sub; };
u32 func_00121380(O* o) asm("func_00121380");
u32 func_00121380(O* o) {
    Sub* s = o->sub;
    u32 r = 0;
    for (s32 i = 0; i < s->n; i++) r |= 1 << ((s->e[i].w >> 6) & 0x1f);
    return r;
}
}  // namespace g00121380

// 001213c0 (was src/anon/batch_w88.cpp)
namespace n001213c0 {
struct F1213c0 { u8 st : 2; u8 rest : 6; };
struct EA1213c0 { u32 lo : 6; u32 kind : 5; u32 hi : 21; u8 pad[28]; };
struct EB1213c0 { u32 kind : 5; u32 hi : 27; u8 pad[28]; };
struct TA1213c0 { u8 pad[28]; s32 n; EA1213c0 e[1]; };
struct TB1213c0 { u8 pad[28]; s32 n; EB1213c0 e[1]; };
TB1213c0* func_00120800(u8*) asm("func_00120800");
/*TARGET 001213c0*/
// obj_get_sub_ptr_by12
// Mark every entry of the given kind (-1 = all) in both tables as state 1.
void kn__ModelSKL__showPart(u8* p, F1213c0* fl, s32 kind) asm("kn__ModelSKL__showPart");
// obj_get_sub_ptr_by12
// Mark every entry of the given kind (-1 = all) in both tables as state 1.
void kn__ModelSKL__showPart(u8* p, F1213c0* fl, s32 kind) {
    TA1213c0* t = *(TA1213c0**)(p + 4);
    TB1213c0* b = func_00120800(p);  // obj_get_sub_ptr_by12
    for (s32 i = 0; i < t->n; i++) {
        if (kind == -1 || t->e[i].kind == kind) fl[i].st = 1;
    }
    if (b) {
        for (s32 i = 0; i < b->n; i++) {
            if (kind == -1 || b->e[i].kind == kind) fl[t->n + i].st = 1;
        }
    }
}
}  // namespace n001213c0

// 001214c0 (was src/anon/batch_w80.cpp)
namespace n001214c0 {
// ---- unit 0 (final.cpp)
struct U0_Ent { u32 w; u8 pad[28]; };
struct U0_Hdr { u8 pad[28]; s32 n; U0_Ent e[1]; };
struct U0_Obj { u32 f0; U0_Hdr* h; };
U0_Hdr* func_00120800(U0_Obj*) asm("func_00120800");
/*TARGET 001214c0*/
// clear the low two flag bits of every entry matching id (-1 = all)
void kn__ModelSKL__hidePart(U0_Obj* p, u8* flags, s32 id) asm("kn__ModelSKL__hidePart");
// clear the low two flag bits of every entry matching id (-1 = all)
void kn__ModelSKL__hidePart(U0_Obj* p, u8* flags, s32 id) {
    U0_Hdr* h = p->h;
    U0_Hdr* h2 = func_00120800(p);  // obj_get_sub_ptr_by12
    s32 i;
    for (i = 0; i < h->n; i++) {
        if (id == -1 || ((h->e[i].w >> 6) & 0x1f) == (u32)id) flags[i] &= ~3;
    }
    if (h2) {
        for (i = 0; i < h2->n; i++) {
            if (id == -1 || (h2->e[i].w & 0x1f) == (u32)id) flags[h->n + i] &= ~3;
        }
    }
}
}  // namespace n001214c0

// 001215b8 (was src/anon/batch_w91.cpp)
namespace n001215b8 {
// 0x0010c9f8: definition moved into src/anon/unit_0010b978.cpp

// --- 001215b8
// Flags (|= 4) every entry of both tables whose id field matches (or all when id == -1).
u8* func_00120800(u8*) asm("func_00120800");
/*TARGET 001215b8*/
// obj_get_sub_ptr_by12
void kn__ModelSKL__setStealth(u8* p, u8* flags, s32 id) asm("kn__ModelSKL__setStealth");
// obj_get_sub_ptr_by12
void kn__ModelSKL__setStealth(u8* p, u8* flags, s32 id) {
    u8* q = *(u8**)(p + 4);
    u8* r = func_00120800(p);  // obj_get_sub_ptr_by12
    s32 i;
    for (i = 0; i < *(s32*)(q + 28); i++) {
        if (id == -1 || ((*(u32*)(q + 32 + i * 32) >> 6) & 0x1f) == id) flags[i] |= 4;
    }
    if (r) {
        for (i = 0; i < *(s32*)(r + 28); i++) {
            if (id == -1 || (*(u32*)(r + 32 + i * 32) & 0x1f) == id) flags[*(s32*)(q + 28) + i] |= 4;
        }
    }
}
}  // namespace n001215b8

// 001216a8 (was src/anon/batch_w81.cpp)
namespace n001216a8 {
// --- 001216a8: clear bit 2 of the flag byte of every entry (both tables) whose id matches (-1 = all)
struct Ent216 { u32 lo : 5; u32 : 1; u32 hi : 5; u32 : 21; u8 pad[28]; };
struct Tbl216 { u8 pad[28]; s32 n; Ent216 e[1]; };
struct Own216 { u32 a; Tbl216* t; };
Tbl216* func_00120800(Own216*) asm("func_00120800");
/*TARGET 001216a8*/
// obj_get_sub_ptr_by12
void kn__ModelSKL__resetStealth(Own216* o, u8* flags, s32 id) asm("kn__ModelSKL__resetStealth");
// obj_get_sub_ptr_by12
void kn__ModelSKL__resetStealth(Own216* o, u8* flags, s32 id) {
    Tbl216* t = o->t;
    Tbl216* t2 = func_00120800(o);  // obj_get_sub_ptr_by12
    s32 i;
    for (i = 0; i < t->n; i++) {
        if (id == -1 || t->e[i].hi == id) flags[i] &= ~4;
    }
    if (t2) {
        for (i = 0; i < t2->n; i++) {
            if (id == -1 || t2->e[i].lo == id) flags[t->n + i] &= ~4;
        }
    }
}
}  // namespace n001216a8

// 001217a0 (was src/anon/batch_w2024.cpp)
namespace n001217a0 {
struct W2024a_Hdr { u8 pad[0x10]; s32 off10; s32 off14; s32 off18; };
struct W2024a_Ent { u8 pad[0x24]; s32 idx; u8 pad2[0x18]; };
struct W2024a_Obj { s32 f0; u8* ents; };
struct W2024a_Bb { u8 pad[0x20]; u64 bitblt; };
struct W2024a_Tx { u8 pad[0x70]; u64 tex0; };
extern s32 D_003a99f0[] asm("D_003a99f0");
void func_00109788(void*, void*) asm("func_00109788");
void func_00109708(void*) asm("func_00109708");
s32 func_00132018(W2024a_Hdr*) asm("func_00132018");
s32 func_00132f98(void*, s32, s32*, s32, s32) asm("func_00132f98");
s32 func_00132d90(s32, s32) asm("func_00132d90");
s32 func_00132c98(s32) asm("func_00132c98");
s32 func_00132cd0(s32) asm("func_00132cd0");
s32 func_00132d00(s32) asm("func_00132d00");
s32 func_00132d30(s32) asm("func_00132d30");
s32 func_00132d60(s32) asm("func_00132d60");
void func_001097e8(s32, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_001097e8");
void func_00133c60(void*, void*, s32, s32, s32) asm("func_00133c60");
void func_001094e0(void*, s32) asm("func_001094e0");
/*TARGET 001217a0*/
void kn__ModelSKL__setTexture(W2024a_Obj* o, void* ctx, s32 n, void* a3, W2024a_Hdr* h) asm("kn__ModelSKL__setTexture");
void kn__ModelSKL__setTexture(W2024a_Obj* o, void* ctx, s32 n, void* a3, W2024a_Hdr* h) {
    W2024a_Ent* e = (W2024a_Ent*)(n * 32 + (u32)o->ents);
    s32 k = e->idx;
    u8* base = (u8*)h;
    W2024a_Bb* bb;
    W2024a_Tx* tx;
    s32 cnt;
    s32* p;
    tx = (W2024a_Tx*)((u32)h + (h->off18 + k * 0xa0));
    s32 x = (base + h->off10)[k] * 0x90;
    x += 0x90;
    bb = (W2024a_Bb*)((u32)h + (h->off14 + x));
    func_00109788(ctx, base + h->off14);
    func_00109708(ctx);
    func_00109788(ctx, bb);
    cnt = func_00132f98(a3, e->idx, D_003a99f0, 0x3c00, func_00132018(h));
    if (cnt > 0) {
        p = D_003a99f0;
        s32 c = cnt;
        do {
            s32 s = *p++;
            if (func_00132d90(s, 0) != 0) {
                s32 r0 = func_00132c98(s);
                s32 r1 = func_00132cd0(s);
                s32 r2 = func_00132d00(s);
                s32 r3 = func_00132d30(s);
                s32 r4 = func_00132d60(s);
                s32 r5 = func_00132d90(s, 0);
                func_001097e8(r0, (s32)((bb->bitblt & 0x3fffULL << 32) >> 32), (s32)((tx->tex0 & 0xfc000ULL) >> 14), r1, r2, r3, r4, (s32)((tx->tex0 & 0x3f00000ULL) >> 20), r5);
                func_00133c60(ctx, (void*)r0, 0, 0, 0);
                func_001094e0(bb, r0);
            }
        } while (--c != 0);
    }
    func_00133c60(ctx, tx, 0, 0, 0);
}
}  // namespace n001217a0

// 001219b8 (was src/anon/batch_wcx2.cpp)
namespace n001219b8 {
// ---- 001219b8
void kn__ModelSKL__setTexture(u8*, u32, u32, u32, u32) asm("kn__ModelSKL__setTexture");
void func_00134408(void) asm("func_00134408");
void func_00134428(s32, u64) asm("func_00134428");
void func_00134450(s32) asm("func_00134450");
u32 func_00109f58(s32, u32, u8) asm("func_00109f58");
u32 func_00109ea8(s32, u32, u8) asm("func_00109ea8");
u32 func_0010ae90(void) asm("func_0010ae90");
// get_table_34ed8
void kn__VU1DrawContext__setPacketForce(u32, s32, u64, u64, u32, u32, s32, s32) asm("kn__VU1DrawContext__setPacketForce");
void func_00109670(void) asm("func_00109670");
/*TARGET 001219b8*/
void func_001219b8(u8* p, u32 a1, u32 a2, u8* q, u32 a4, u8 flag, u32 a6, u32 a7) asm("func_001219b8");
void func_001219b8(u8* p, u32 a1, u32 a2, u8* q, u32 a4, u8 flag, u32 a6, u32 a7)
{
    kn__ModelSKL__setTexture(p, a1, a2, a4, a6);
    func_00134408();
    func_00134428(76, 0x40140);
    func_00134428(78, *(u64*)(q + 24) | (1ull << 32));
    func_00134428(71, 0x30003);
    func_00134428(8, 5);
    func_00134428(24, (15ull << 43) | 0x7800);
    func_00134428(64, 0xff000000ff0000ull);
    func_00134428(66, (1ull << 39) | 0x44);
    func_00134428(0, 86);
    func_00134428(1, 0x3f80000080808080ull);
    func_00134428(2, 0);
    func_00134428(5, 0x78007800);
    func_00134428(2, 0x3f8000003f800000ull);
    func_00134428(5, (17ull << 27) | 0x8800);
    func_00134450(1);
    kn__ModelSKL__setTexture(p, a1, a2, a4, a7);
    func_00134408();
    func_00134428(76, 0xff00000000040140ull);
    func_00134428(8, 5);
    func_00134428(0, 86);
    func_00134428(1, ((u64)((q[40] >> 1) & 0xff) << 24) | 0x3f80000000808080ull);
    func_00134428(2, 0);
    func_00134428(5, 0x78007800);
    func_00134428(2, 0x3f8000003f800000ull);
    func_00134428(5, (17ull << 27) | 0x8800);
    func_00134428(24, (115ull << 40) | 0x7000);
    func_00134428(64, 0x19f000001ff0000ull);
    func_00134428(6, 0x2000000620012800ull);
    func_00134450(1);
    if (!flag) {
        u32 x = func_00109f58(7, *(u32*)(*(u8**)(p + 4) + 4), q[7]);
        u32 y = func_00109ea8(7, *(u32*)(*(u8**)(p + 4) + 4), q[7]);
        kn__VU1DrawContext__setPacketForce(func_0010ae90(), 15, *(u64*)(q + 16), *(u64*)(q + 24) & ~(1ull << 32), y, x, 0, 0);
    } else {
        u32 x = func_00109f58(11, *(u32*)(*(u8**)(p + 4) + 4), q[7]);
        u32 y = func_00109ea8(11, *(u32*)(*(u8**)(p + 4) + 4), q[7]);
        kn__VU1DrawContext__setPacketForce(func_0010ae90(), 15, *(u64*)(q + 16) | (0xffull << 56), *(u64*)(q + 24) | (1ull << 32), y, x, 0, 0);
    }
    func_00109670();
}
}  // namespace n001219b8

