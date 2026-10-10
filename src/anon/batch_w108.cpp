#include "../common/types.h"
extern "C" {
extern s32 D_003a6a50;
extern u8 D_0032ba30;
extern u8 D_0032ba28;
extern s32 D_0032b984;
extern s32 D_0032ba20;
extern u8 D_0032ba1c;
extern s32 D_0032ba64;
void func_00103a40(void);
s32 func_001033d8(s32);
void func_002530f0(s32);
void func_00242fc8(s32);
void func_00103748(void);
s32 func_00103c90(void);  // get_hook_ptr
void func_00103ca0(void);
void func_00253180(s32, s32);
void func_00243020(s32);
void func_0014c9f0(s32);
void func_00167ee0(void);
void func_001384a0(s32);
void func_00104108(void);

// Per-frame update: dispatches the pending map/scene id and runs post-frame hooks.
void func_001031d0(void)
{
    s32 cur;
    s32 next;
    s32 flag;
    s32 mode;

    func_00103a40();
    cur = D_003a6a50;
    if ((u32)(cur - 100) >= 800) {
        func_002530f0(func_001033d8(cur));
    } else {
        func_00242fc8(func_001033d8(cur));
    }
    if (D_0032ba30 == 0) {
        func_00103748();
    }
    flag = 0;
    D_0032ba28 = 0;
    if (func_00103c90()) {  // get_hook_ptr
        func_00103ca0();
        flag = 1;
    }
    mode = D_0032b984;
    if (mode != 0 && (mode ^ 2) != 0) {
        next = D_0032ba20;
        if (next != -1) {
            s32 v;
            D_0032ba20 = -1;
            D_003a6a50 = -1;
            v = func_001033d8(next);
            if ((u32)(next - 100) >= 800) {
                func_00253180(v, -999);
            } else {
                func_00243020(v);
            }
            return;
        }
        D_003a6a50 = next;
        func_0014c9f0(1);
        if (flag) return;
        func_00167ee0();
        if (D_0032ba1c == 0) {
            func_001384a0(0);
        }
    } else {
        if (D_0032ba64 != 0) {
            D_003a6a50 = -1;
            func_0014c9f0(1);
            func_00167ee0();
            if (D_0032ba1c == 0) {
                func_001384a0(0);
            }
            func_00104108();
            return;
        }
        D_003a6a50 = -1;
        func_0014c9f0(1);
        func_00167ee0();
        if (D_0032ba1c == 0) {
            func_001384a0(0);
        }
    }
}
}
struct Vec4f {
    f32 x, y, z, w;
};
extern Vec4f D_01e2bf10;
extern Vec4f D_01e2bf20;
extern Vec4f D_01e2bf30;
extern Vec4f D_01e2bf40;
extern Vec4f D_01e2bf50;
extern Vec4f D_01e2bf60;
extern f32 D_01e2bf70;
extern f32 D_01e2bf74;
extern f32 D_01e2bf78;
extern f32 D_01e2bf7c;

static inline void SetVec(Vec4f* v, f32 x, f32 y, f32 z, f32 w)
{
    v->x = x;
    v->y = y;
    v->z = z;
    v->w = w;
}

void wtarget_002e7870(u32, u32, u32, u32) asm("_Z16wtarget_002e7870jjjj");
// Static initializer for the axis-vector and +-pi/2 constants.
void wtarget_002e7870(u32 init, u32 prio, u32, u32)
{
    if (prio == 0xffff && init == 1) SetVec(&D_01e2bf10, 0.0f, 1.0f, 0.0f, 0.0f);
    if (prio == 0xffff && init == 1) SetVec(&D_01e2bf20, 0.0f, -1.0f, 0.0f, 0.0f);
    if (prio == 0xffff && init == 1) SetVec(&D_01e2bf30, -1.0f, 0.0f, 0.0f, 0.0f);
    if (prio == 0xffff && init == 1) SetVec(&D_01e2bf40, 1.0f, 0.0f, 0.0f, 0.0f);
    if (prio == 0xffff && init == 1) SetVec(&D_01e2bf50, 0.0f, 0.0f, 1.0f, 0.0f);
    if (prio == 0xffff && init == 1) SetVec(&D_01e2bf60, 0.0f, 0.0f, -1.0f, 0.0f);
    if (prio == 0xffff && init == 1) D_01e2bf70 = 1.5707963f;
    if (prio == 0xffff && init == 1) D_01e2bf74 = -1.5707963f;
    if (prio == 0xffff && init == 1) D_01e2bf78 = -1.5707963f;
    if (prio == 0xffff && init == 1) D_01e2bf7c = 1.5707963f;
}

extern "C" {
struct Msg24a { u8 data[36]; };
struct Ent24a { u16 f0; u16 f2; s16 id; };
extern u32 D_0035ed80;
extern u32 D_0035ed90;
extern Msg24a D_00371ee8[];
extern Msg24a D_00371f30;
extern Msg24a D_00371f58[];
s32 func_00289310(void*);
s32 func_002891e8(void*);
void func_002890e0(void*, s32, s32, s32, s32);
void func_00289038(void*, s32, s32, s32, s32, s32, s32);
Ent24a* func_0024b1a0(s32);
void func_0023f070(u32, s32, s32);
void func_0024b0e8(void);
s32 func_0028d008(void*);
s32 func_002891d0(void*);
void func_0028cf28(void*, s32);  // record408_set_and_refresh
s32 func_0024ac88(void);
void func_002b4388(u32, void*, s32);
s32 func_001a6d08(s32);
void func_00139858(s32);
void func_001398d0(s32);

void func_0024a948(void* obj, s32 quiet, void* target)
{
    s32 kind;

    if (!func_00289310(obj)) return;
    kind = func_002891e8(obj);
    func_002890e0(obj, 1, 2, 0, -1);
    func_00289038(obj, kind, 1, 1, 2, 0, -1);
    if (!quiet) {
        func_0023f070(D_0035ed80, func_0024b1a0(kind)->id, -1);
        func_0024b0e8();
    }
    if (func_0028d008(target)) {
        func_0028cf28(target, func_002891d0(obj));  // record408_set_and_refresh
    }
    if (!quiet) {
        if (kind == 1 && func_0024ac88()) {
            func_002b4388(D_0035ed90, &D_00371f30, 0);
        } else {
            func_002b4388(D_0035ed90, &D_00371ee8[kind], 0);
        }
    } else {
        func_002b4388(D_0035ed90, &D_00371f58[kind], 0);
    }
    if (!func_001a6d08(9)) return;
    if (func_0024ac88()) return;
    if (kind == 1) {
        func_00139858(100);
    } else {
        func_001398d0(100);
    }
}
}

extern "C" {
struct Info2cf {
    s32 id;
    f32 x, y, z;
};
struct Ref2cf {
    u8 pad[16];
    u16* data;
};
struct Params2cf {
    s32 f0;
    u32 f4;
    u32 f8;
    Info2cf* info;
    u32 f16;
    s32 f20;
    union { Ref2cf* ref0; u32 ref0u; };
    union { Ref2cf* ref1; u32 ref1u; };
};
struct Ctx2cf {
    u8 pad[92];
    u32 f92;
};
extern Ctx2cf* D_00361f60;
extern s32 D_00361fa8;
u8* func_001b9bc8(u8*);
s32 func_0016a020(u8*);
s32 func_0019c768(u8*);
s32 func_002cf270(u8*, s32);
u8* func_00199938(Info2cf*, s32);
void func_002cff50(u8*);
u32 func_002e3260(u32, s32, u16);
void func_0016ace0(u8*, f32*);
void func_002d0d88(u8*);

static inline void SetPos2cf(f32* v, f32 x, f32 y, f32 z)
{
    v[0] = x;
    v[1] = y;
    v[2] = z;
    v[3] = 0.0f;
}

// Finds a reusable spawned object matching p->info (or creates one) and places it.
u8* func_002cf4a8(Params2cf* p)
{
    u8* it = 0;
    u8* obj = 0;
    f32 pos[4];

    while ((it = func_001b9bc8(it)) != 0) {
        if (!(*(u32*)(it + 1416) & 0x08000000)) continue;
        if (func_0016a020(it) != p->info->id) continue;
        if (!func_0019c768(it)) continue;
        if (!func_002cf270(it + 2800, 4096)) continue;
        if (*(s32*)(it + 2832) > 0) continue;
        obj = it;
        break;
    }
    if (obj == 0) {
        obj = func_00199938(p->info, p->f20);
    }
    if (func_0019c768(obj)) {
        func_002cff50(obj);
    }
    if (p->ref0) {
        *(u32*)(obj + 2808) = func_002e3260(D_00361f60->f92, p->f0, *p->ref0->data);
        *(u32*)(obj + 2812) = (u32)p->ref0->data;
        *(u32*)(obj + 2816) = p->ref1 ? (u32)p->ref1->data : 0;
    }
    if (func_0019c768(obj)) {
        SetPos2cf(pos, p->info->x, p->info->y, p->info->z);
        func_0016ace0(obj, pos);
        func_002d0d88(obj);
    } else {
        D_00361fa8++;
    }
    return obj;
}
}

extern "C" {
extern u32 D_0035ef64;
extern u32 D_0035ef68;
extern u32 D_0035f03c;
extern s32 D_0035f3d4;
extern u32 D_0035f01c;
extern s16 D_003737e8[];
u8* func_00257770(void);
s32 func_00139d78(void*);
s32 func_00287bc0(void);
s32 func_0028d008(void*);
void func_00139510(void*);
void func_00256c40(void);
s32 func_002570a0(s32);
s32 func_00269508(s32);
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32);
void func_0028dcc0(u8*, u8*);
u8* func_0028d0e0(void*);
void func_00138c78(u32, s32*, s32*);
void func_00138c68(u8*, s32, s32);
s32 func_0028b040(u32);
void func_00256bb0(u8*);

void func_0026a3b8(void* target, u8 follow)
{
    u8* work = func_00257770();
    u8* obj = work + 816;
    s32 active = func_00139d78(obj);
    s32 mode = func_00287bc0();
    s32 kind;
    s32 x;
    s32 y;

    if (func_0028d008(target)) {
        if (!active) {
            s32 id = 249;
            s32 n = D_0035f3d4 + 2;
            if (mode != 2) {
                kind = func_00269508(func_002570a0(2));
                id = D_003737e8[kind + 5];
            }
            func_0028d8c0(obj, n, D_0035ef68, D_0035ef64, D_0035f03c, id, -1, 0);
            func_0028dcc0(obj, work);
            func_00138c78(*(u32*)(func_0028d0e0(target) + 396), &x, &y);
            func_00138c68(obj, x, y);
        }
        if (follow) {
            func_00138c78(*(u32*)(func_0028d0e0(target) + 396), &x, &y);
            func_00138c68(obj, x, y);
        }
        if (func_00139d78(work + 2504) && !follow) return;
        if (mode == 2) {
            kind = func_00269508(func_0028b040(D_0035f01c));
        } else {
            kind = func_00269508(func_002570a0(2));
        }
        if (mode == 2 && kind == 4) {
            func_00256bb0(func_0028d0e0(target));
            return;
        }
    } else {
        if (active) {
            func_00139510(obj);
            return;
        }
    }
    if ((u32)(mode - 5) < 2) return;
    func_00256c40();
}
}

extern "C" {
struct Task276;
struct Task276Vt {
    void* pad[5];
    void (*update)(Task276*);
};
struct Task276 {
    Task276Vt* vt;
    u8 body[404];
};
struct Big276 {
    u8 a[408];
    u8 b[408];
    u8 c[408];
    u8 d[408];
    u8 e[436];
    u8 f[436];
    u8 g[436];
    u8 h[436];
    u8 i[436];
    u8 pad[436];
    Task276 tasks0[32];
    Task276 tasks1[32];
};
extern Big276* D_0035f21c;
s32 func_00139d78(void*);
void func_00139510(void*);
void func_00276a18(void);
void func_00276b10(void);

void func_002766e0(void)
{
    s32 i;

    if (func_00139d78(D_0035f21c->a)) func_00139510(D_0035f21c->a);
    if (func_00139d78(D_0035f21c->b)) func_00139510(D_0035f21c->b);
    if (func_00139d78(D_0035f21c->c)) func_00139510(D_0035f21c->c);
    if (func_00139d78(D_0035f21c->d)) func_00139510(D_0035f21c->d);
    if (func_00139d78(D_0035f21c->e)) func_00139510(D_0035f21c->e);
    if (func_00139d78(D_0035f21c->f)) func_00139510(D_0035f21c->f);
    if (func_00139d78(D_0035f21c->g)) func_00139510(D_0035f21c->g);
    if (func_00139d78(D_0035f21c->h)) func_00139510(D_0035f21c->h);
    if (func_00139d78(D_0035f21c->i)) func_00139510(D_0035f21c->i);
    for (i = 0; i < 32; i++) {
        if (func_00139d78(&D_0035f21c->tasks0[i])) {
            Task276* t = ((Big276*)(i * sizeof(Task276) + (u32)D_0035f21c))->tasks0;
            t->vt->update(t);
        }
        if (func_00139d78(&D_0035f21c->tasks1[i])) {
            Task276* t = ((Big276*)(i * sizeof(Task276) + (u32)D_0035f21c))->tasks1;
            t->vt->update(t);
        }
    }
    func_00276a18();
    func_00276b10();
}
}

extern "C" {
struct List2a6 {
    s8 count;
    u8 pad[5];
    s8 items[1];
};
extern List2a6* D_0035f5ec;
s32 func_00276620(s32);
s32 func_00276638(s32);
s32 func_002a6368(s32);
s32 func_002944d0(s32);
void func_002765e8(s32, s32, s32);
void func_002a65d0(void);

// Moves the list cursor to the next/previous selectable entry (wrapping) and scrolls the 10-row window.
void func_002a6088(s32 dir)
{
    s32 top = func_00276620(37);
    s32 cur = func_00276638(37);
    s32 i;

    if (dir == -10) {
        for (i = cur + 1; i < D_0035f5ec->count; i++) {
            if (func_002944d0(func_002a6368(D_0035f5ec->items[i]))) break;
        }
        if (i >= D_0035f5ec->count) {
            for (i = 0; i < cur; i++) {
                if (func_002944d0(func_002a6368(D_0035f5ec->items[i]))) break;
            }
        }
        if (i < D_0035f5ec->count) {
            cur = i;
        } else {
            cur = 0;
            top = 0;
        }
    } else {
        for (i = cur - 1; i >= 0; i--) {
            if (func_002944d0(func_002a6368(D_0035f5ec->items[i]))) break;
        }
        if (i < 0) {
            for (i = D_0035f5ec->count - 1; i > cur; i--) {
                if (func_002944d0(func_002a6368(D_0035f5ec->items[i]))) break;
            }
        }
        cur = i;
        if (i < 0) {
            cur = D_0035f5ec->count - 1;
            top = D_0035f5ec->count - 11;
        }
    }
    if (cur - top >= 10) {
        top += cur - top - 9;
    } else if (cur - top < 0) {
        top += cur - top;
    }
    func_002765e8(37, cur - top, top);
    func_002a65d0();
}
}

extern "C" {
struct Heap251;
struct Heap251Vt {
    u8* (*alloc)(Heap251*, s32, s32);
};
struct Heap251 {
    Heap251Vt* vt;
};
struct Sys251 {
    u8 pad[20];
    Heap251* heap;
};
extern u8 D_00347f98[];
extern u8 D_0035eb98[];
extern u8 D_0035ebb8[];
extern u8* D_0035ee60;
extern u8* D_0035ee64;
extern u32 D_0035ee58;
extern Sys251* D_00347f80;
extern u8 D_00372608;
extern u8 D_00372630;
u8* func_0023ee30(s32);
void func_0031a838(u8*);
void func_002369a0(u8*);  // obj_ctor_36eac8
void func_0023c008(u8*);  // obj_ctor_36eae8
void func_0028d7f0(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0023ef50(u8*);
s32 func_00252098(s32);
void func_00288ce0(u32, s32, s32, s32, s32);
void func_0023f1e0(u8*, s32, u8*, void*, void*, s32, s32, s32);
void func_0023f6c0(u8*, s32);
void func_00252180(void);
s32 func_00252428(void);
void func_00252320(void);
void func_00252208(void);
s32 func_00252148(s32);
void func_002891f0(u32, s32, s32, s32, s32);
s32 func_00252110(s32);
void func_00252660(s32);
void func_00287bd0(s32, s32);
void func_00287cc0(s32);

void func_00251148(void)
{
    u8* o;
    u8* p;
    s32 i;
    s32 n;
    s32 sel;

    o = func_0023ee30(160);
    *(u8**)o = D_00347f98;
    func_0031a838(o + 12);
    *(u8**)o = D_0035eb98;
    func_002369a0(o + 24);  // obj_ctor_36eac8
    func_0023c008(o + 48);  // obj_ctor_36eae8
    D_0035ee60 = o;
    func_0028d7f0(o, 30002, 0, 0, 0, 1, 0, 0, 0);
    func_0023ef50(D_0035ee60);
    n = 0;
    for (i = 0; i < 4; i++) {
        if (func_00252098(i)) {
            func_00288ce0(D_0035ee58, 0, n, 0, 0);
            n++;
        }
    }
    p = D_00347f80->heap->vt->alloc(D_00347f80->heap, 76, 0);
    *(u32*)(p + 12) = 0;
    *(u8**)p = D_0035ebb8;
    D_0035ee64 = p;
    func_0023f1e0(p, 30003, D_0035ee60, &D_00372608, &D_00372630, -1, 0, 0);
    func_0023f6c0(D_0035ee64, 2);
    func_00252180();
    sel = func_00252428();
    func_00252320();
    func_00252208();
    func_002891f0(D_0035ee58, func_00252148(sel), 0, -1, -1);
    func_00252660(func_00252110(func_002891e8((void*)D_0035ee58)));
    func_00287bd0(0, 0);
    func_00287cc0(0);
}
}

extern "C" {
extern u8 D_00350e48[];
extern u8 D_003525c8[];
extern u8 D_00352560[];
extern u8 D_00351eb8;
void func_001ddd10(u8*);
void func_001d1fa8(u8*);  // obj_ctor_3525c8
void func_00320400(u8*);
void func_001d1678(u8*, s32);  // obj_init_28bytes
s32 func_001b5cb8(u8*);
s32 func_001d3f38(u32);  // type_is_282_344_484
void func_0016bd60(u8*, s32);
u8* func_0017e668(u32);
void func_001b4d70(u8*, f32);
void func_001b4a00(u8*);
s32 func_001b5858(u8*);
void func_001b4d10(u8*);
void func_001c8d80(void*, s32);
u8* func_001b1928(s32);

struct Sub72 {
    u8* vt;
    u32 f4;
    s32 f8;
    u32 f12;
    u32 f16;
    u32 f20;
};
struct Sub168 {
    u8* vt;
    u32 f4;
    u32 f8;
    u8 f12[36];
    u32 f48;
};
// Constructor-style init: sets up the sub-objects and spawns up to three child entities from data[1..3].
void func_001b47d8(u8* self, u8* data, u8* owner, f32 scale)
{
    s32 i;
    u8* p;

    *(u8**)(self + 12) = owner;
    *(u8**)(self + 0) = data;
    *(u32*)(self + 4) = 0;
    *(u32*)(self + 8) = 0;
    func_001ddd10(self + 24);
    *(u32*)(self + 52) = 0;
    *(u32*)(self + 56) = 0;
    *(u32*)(self + 60) = 0;
    *(u32*)(self + 64) = 0;
    *(u32*)(self + 68) = 0;
    {
        Sub72* q = (Sub72*)(self + 72);
        q->f20 = 6144;
        q->f8 = -1;
        q->f12 = 0;
        q->f16 = 0;
        q->f4 = 0;
        *(u32*)&q->vt = (u32)D_00350e48;
    }
    func_001d1fa8(self + 104);  // obj_ctor_3525c8
    *(u32*)(self + 172) = 0;
    *(u32*)(self + 176) = 0;
    *(u8**)(self + 168) = D_003525c8;
    func_00320400(self + 180);
    {
        Sub168* sub = (Sub168*)(self + 168);
        func_001d1678((u8*)sub, -1);  // obj_init_28bytes
        sub->f48 = 0;
    }
    *(u8**)(self + 168) = D_00352560;
    if (!func_001b5cb8(self)) {
        *(u32*)(*(u8**)(self + 12) + 268) |= 0x10000;
    }
    if (func_001d3f38(*(u32*)self)) {  // type_is_282_344_484
        func_0016bd60(*(u8**)(self + 12), 0);
    }
    *(u32*)(self + 16) = 0;
    *(u32*)(self + 20) = 0;
    {
        s32 n = 0;
        for (i = 0; i < 3; i++) {
            u8 c = data[i + 1];
            if (c < 2) continue;
            ((u8**)(self + 16))[n] = func_0017e668(c);
            ((u8**)(self + 16))[n][2892] = 1;
            *(u32*)(((u8**)(self + 16))[n] + 268) |= 0x10000;
            if (func_001d3f38(*(u32*)self)) {  // type_is_282_344_484
                func_0016bd60(((u8**)(self + 16))[n], 0);
            }
            n++;
        }
    }
    if (func_001b5cb8(self)) {
        func_001b4d70(self, scale);
    } else {
        func_001b4a00(self);
        if (func_001b5858(self)) {
            func_001b4d10(self);
        } else {
            func_001c8d80(&D_00351eb8, 0);
        }
    }
    p = func_001b1928(0);
    *(u32*)(self + 56) = (u32)p;
    *(u32*)(p + 16) |= 2;
    *(u32*)(self + 64) |= 1;
}
}
