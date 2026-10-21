#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
extern "C" {

// 00108730: GIF packet setup. The 128-bit zero store is an sq $0 asm (C gives por+sq).
struct W1986GifTag {
    u64 NLOOP:15; u64 EOP:1; u64 pad16:30; u64 PRE:1; u64 PRIM:11; u64 FLG:2; u64 NREG:4;
    u64 REGS;
} __attribute__((aligned(16)));
struct W1986Pkt {
    W1986GifTag tag;
    u32 rgba[4];
    f32 st[4];
    f32 a[4];
    f32 b[4];
};
struct W1986Src {
    u32 flags;
    u8 c[4];
    u8 pad8[3];
    u8 b11;
    u8 pad0c[0x14];
    f32 f20;
    s32 x24;
};
extern u128 D_00340f10;
extern u128 D_00340f20;
extern u8 D_00340eb0;
u32* func_00133bb8(void*, s32, u32, u32);
s32 func_0010aba8(void);
void func_0010a8e0(void*);
s32 func_00106a18(s32);
f32 func_001070a8(s32);

W1986Pkt* func_00108730(W1986Src* p, void* q)
{
    u32* d = func_00133bb8(q, 12, 0x11000000, 0x13000000);
    d[0] = 0;
    d[1] = 0;
    d[2] = 0x01000404;
    d[3] = 0x6c0a4000;
    W1986Pkt* k = (W1986Pkt*)(d + 4);
    __asm__ volatile("sq $0, 0(%0)" : : "r"(d + 40));
    d += 44;
    d[0] = 0x14000000;
    d[1] = 0x11000000;
    d[2] = 0x13000000;
    d[3] = 0;
    if (p->x24 == 0) {
        *(u128*)&k->tag = D_00340f10;
    } else {
        *(u128*)&k->tag = D_00340f20;
    }
    k->tag.PRIM &= ~0x20;
    if ((D_00340eb0 ^ 1) == 0) {
        k->tag.PRIM |= 0x20;
    } else if (func_0010aba8() == 7 && (p->flags & 2)) {
        k->tag.PRIM |= 0x20;
    }
    k->rgba[0] = p->c[0];
    k->rgba[1] = p->c[1];
    k->rgba[2] = p->c[2];
    k->rgba[3] = p->c[3];
    if (p->flags & 2) {
        k->st[0] = 0;
        k->st[1] = p->b11;
        k->st[2] = 0;
        k->st[3] = 255.0f;
    } else {
        func_0010a8e0(k->st);
    }
    f32 c = 2048.0f;
    s32 r = func_00106a18(1);
    k->a[0] = c;
    k->a[1] = c;
    k->a[2] = 4000000.0f;
    k->a[3] = p->f20;
    k->b[0] = 1.0f;
    k->b[1] = 1.0f;
    k->b[2] = func_001070a8(r);
    k->b[3] = c;
    return k;
}

// 002d36f0
struct W1986V4 {
    f32 x, y, z, w;
    W1986V4() {}
    W1986V4(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    W1986V4& operator=(const W1986V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1986Obj {
    u8 pad0[0x40];
    s32 x40;
    u8 pad44[0x1c];
    f32 f60;
    f32 f64;
    f32 f68;
    u8 pad6c[0x14];
    W1986V4 v80;
    W1986V4 v90;
};
struct W1986Cfg {
    u8 pad0[0x44];
    s32 n;
    f32 f48;
    f32 f4c;
    f32 f50;
    f32 f54;
    f32 f58;
};
struct W1986Tmp { u8 d[16]; };
extern void* D_00361f60;
void func_002d38e8(W1986Tmp*, void*);
W1986Cfg* func_002d1878(void*);
W1986Obj* func_001cbe30(W1986Tmp*, s32, s32);
f32 func_002f8960(f32);
f32 func_002f87c0(f32);

void func_002d36f0(void* a)
{
    W1986Tmp t;
    void* g = D_00361f60;
    func_002d38e8(&t, a);
    W1986Cfg* c = func_002d1878(g);
    f32 h = c->f58 / 60.0f;
    f32 w = c->f4c;
    s32& n = c->n;
    f32& wd = c->f48;
    f32& st = c->f50;
    for (s32 j = 0; j < 1; j++) {
        f32 z = (f32)j * st;
        for (s32 i = 0; i < n; i++) {
            W1986Obj* o = func_001cbe30(&t, 1, 1);
            if (o) {
                f32 ang = (wd * (f32)i) / (f32)(n - 1) - wd * 0.5f;
                f32 cs = func_002f8960(ang);
                o->v90 = W1986V4(cs, -func_002f87c0(ang), 0, w);
                o->v80 = W1986V4(0, h, 0, 0);
                o->f60 = z;
                o->f64 = 120.0f;
                o->f68 = c->f54;
                o->x40 = 0;
            }
        }
    }
}

// 00175f68
struct W1986Ob;
struct W1986Vt {
    void* f[15];
    s32 (*get)(W1986Ob*);
    void* g[2];
    void (*act)(W1986Ob*);
};
struct W1986Ob {
    W1986Vt* vt;
    u8 pad4[0x9b0];
    s16* p9b4;
};
struct W1986Ch { u8 pad[0x4e]; u16 id; };
struct W1986Tg {
    u8 pad0[8];
    W1986Ch* ch;
    u8 padc[0x57c];
    u32 flags;
    u8 pad58c[0x56c];
    W1986Ob* obj[4];
};
W1986Tg* func_00176b58(u32);
s32 func_0019c5d0(W1986Ob*);
void func_00185a28(W1986Ob*);
void* func_001d1438(s32);
W1986Ch* func_0016e920(void*);
void func_001703a8(s32);
s32 func_00185890(u32, u32);
void func_0016ef58(u32, u32, s32, s32, s32);
void func_00170888(u32);
void func_00176168(W1986Tg*, s32, u32);
s32 func_00103b38(void);
void func_001617d8(void);
void* func_001a90f0(u32);
s32 func_0016f930(void*);

static inline s32 W1986_hid(W1986Ob* o) { return o->p9b4 ? *o->p9b4 : -1; }
void wtarget_00175f68(u32 a, u32 b, u32 c, u32 d) asm("_Z16wtarget_00175f68jjjj");
void wtarget_00175f68(u32 a, u32 b, u32 c, u32 d)
{
    s32 nb = 0;
    W1986Tg* t = func_00176b58(b);
    s32 r;
    s32 h;
    u32 id;
    s32 q;
    if (t != 0) {
        W1986Ob* o = t->obj[c];
        r = o->vt->get(o);
        h = W1986_hid(o);
        nb = func_0019c5d0(o);
        func_00185a28(o);
        *(u32*)&t->obj[c] = 0;
        id = t->ch->id;
        if (id != 53 && (t->flags & 0x1000000) && c == 0) {
            id = func_0016e920(func_001d1438(0))->id;
        }
    } else {
        q = (s32)func_001a90f0(b);
        r = func_0016f930((void*)q);
        switch (r) {
        case 2410:
            h = 5;
            break;
        case 2420:
            h = 6;
            break;
        default:
            return;
        }
        r++;
        id = func_0016e920((void*)q)->id;
    }
    func_001703a8(r);
    q = func_00185890(id, d);
    func_0016ef58(id, c, q, r, h);
    func_00170888(a);
    if (t == 0) return;
    func_00176168(t, q, c);
    if (nb == 0) t->obj[c]->vt->act(t->obj[c]);
    if (func_00103b38()) func_001617d8();
}
}
