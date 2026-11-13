// sa::MUSICAL_INPUT: note input, judgement and the 4-part score display of the musical (Atlantica)
// minigame (vtables 0x35e238, 0x35e280). Linked unit 0x229e58-0x22b108; the print task at 0x22b108
// (end of the same file) is not written yet and stays outside.
#include "../common/types.h"

struct W1636Vec {
    f32 x, y, z, w;
    W1636Vec() {}
    W1636Vec(const W1636Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct W1636Sprite;
struct W1636SpriteVt {
    void* pad0[7];
    void (*hide)(W1636Sprite*);
    void* pad20[2];
    void (*setLength)(W1636Sprite*, s32);
    void* pad2c[2];
    void (*setPos)(W1636Sprite*, s32);
    void (*setOn)(W1636Sprite*);
    void (*setOff)(W1636Sprite*);
};
struct W1636Sprite { W1636SpriteVt* vt; };
struct W1636Note {
    u32 unk0;
    s32 mode;
    s32 start;
    u32 unkc, unk10;
    s32 end;
    s32 limit;
    f32 time;
    u32 unk20;
    s32 id;
    u32 bone;
    W1636Sprite* spr;
    s32 se;
    s32 sound;
    u8 hit;
    s32 count;
};
struct W1636Task { u32 unk0; W1636Note* note; };
struct W1636Pad { u32 unk0, unk4; u64 bits; };
struct W1636Ent { u32 unk0, unk4; u32 obj; };

struct W1636Spr {
    u8 pad0[384];
    f32 alpha;
    u8 pad184[8];
    struct W1636Score* parent;
    u32 settled;
    u8 pad194[8];
};
struct W1636Rect { u8 pad[256]; };
struct W1636Group {
    u8 pad0[32];
    W1636Rect r0;
    u8 pad120[32];
    W1636Rect r1;
    W1636Rect r2;
    struct W1636Score* owner;
    u8 pad344[12];
};
struct W1636Score {
    W1636Spr base;
    u8 pad19c[28];
    W1636Spr bar[3];
    u8 pad68c[4];
    W1636Group grp[4];
    W1636Spr face;
    u8 pad156c[4];
    s32 count;
    u32 pad1574;
    s32 type;
};

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

struct Heap2;
struct Heap2Vt { void* (*alloc)(Heap2*, u32, u32); };
struct Heap2 { Heap2Vt* vt; };
struct HeapOwner { u8 pad[20]; Heap2* heap; };
struct ItemSlot { void* vt; u8 pad4[8]; u8 a[12]; u8 b[384]; };
struct ItemPanel { void* vt; u8 pad4[8]; u32 f12; u8 pad16[8]; ItemSlot slot[7]; };
union HeapOwnerRef { HeapOwner* p; s32 i; };

extern "C" {
extern f32 D_00349e10;
extern u8 D_00340000[];
extern HeapOwnerRef D_00347f80;
extern u8 D_0035e190[];
extern u8 D_00347f98[];
extern u8 D_00347e60[];
s32 func_00225e48(void);
W1636Ent* func_00227d10(s32);
s32 func_001ba028(u32);
W1636Vec func_0016b478(f32, u32, u32);
void func_00105110(void*);
void func_001024a8(void*);
W1636Pad* func_00167f18(s32);
void func_00224950(s32);
void func_001391a8(void*, ...);
void c_create(void*, s32, s32) asm("_ZN2dk5Obj2D6createEii");
void c_setRot(void*, f32) asm("_ZN2dk7Ft4Base6setRotEf");
void c_setCenterXY(void*, s32, s32) asm("_ZN2dk7Ft4Base11setCenterXYEii");
void c_ftGsTest(void*, u64) asm("_ZN2dk7Ft4Base9setGsTestEy");
void c_ftGsPrim(void*, u64) asm("_ZN2dk7Ft4Base9setGsPrimEy");
void c_setWH(void*, u16, u16) asm("_ZN2dk13RectParamBase14setWidthHeightEtt");
void c_rcGsPrim(void*, u64) asm("_ZN2dk8RectBase9setGsPrimEy");
void c_rcGsTest(void*, u64) asm("_ZN2dk8RectBase9setGsTestEy");
void func_0023a9c0(void*, s32*, s32*);
void func_00138c50(void*, s32*, s32*);
void func_0014b1e0(void*, s16, s16);
void func_0014b258(void*, u16*, u16*);
void func_0013eeb8(void*);
void func_0014b698(void*);
void func_00322790(void*);
f32 func_0017ce10(f32);
void func_001396b0(void*);
void func_0031a260(void*, s32);
u32 func_0022b720(void);
u32 func_0022b9e0(void);
void func_00158050(void*, s32, u32, u32, s32, s32, s32);
void func_001386e0(void*, s32, u32, u32, s32, s32);
s32 func_00139d78(void*);
void func_0014b200(void*, u32);
void func_00138c10(void*, s32);
void func_001390f0(void*);
void func_00139510(void*);
s32 func_002249b8(void);
void func_0031a838(void*);
void func_00239700(void*);
void func_002294c8(void*, u32, s32*, u8*);
void func_00229678(void*, u32, s32);
u32 func_0022b688(s32);
void func_002251c8(s32);
void func_00224828(s32);
void func_002248f8(s32);
void func_002247e8(s32);
void func_002248c0(s32);

void* func_0022af48(void*);
void func_0022b028(s32);
void func_0022afe8(s32);
u32 func_0022aef0(void*);
void func_0022afa0(s32);
u32 func_0022ae98(void*);
void func_0022a7e0(W1636Score* s, s32 type);
}

s32 D_0035e1f8[14] = { 0x71, 0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79, 0x7a, 0x7b, 0x70, -1, 0 };

void func_00229e58(W1636Task* t)
{
    if (func_00225e48()) goto done;
    {
        W1636Note* n = t->note;
        s32* pcount = &n->count;
        f32* ptime = &n->time;
        s32 now = (s32)(n->time * 0.5f);
        s32 max = n->mode < 4 ? 3 : 5;
        s32 start = n->start;
        s32 end = n->end;
        s32 limit = n->limit;
        s32 se = n->se;
        u32 bone = n->bone;
        s32 sound = n->sound;
        W1636Sprite* spr = n->spr;
        W1636Ent* e = func_00227d10(n->id);
        if (e == 0) return;
        if (e->obj == 0) return;
        if (!func_001ba028(e->obj)) return;
        W1636Vec pos = func_0016b478(1.0f, e->obj, bone);
        if (now >= limit) {
            if (!n->hit) {
                func_0022af48(&pos);
                func_0022b028(se);
            }
            spr->vt->hide(spr);
            func_00105110(n);
            t->note = 0;
            goto done;
        }
        s32 before = now < start;
        if (!before && now <= end && (func_00167f18(0)->bits & 4)) {
            if (*pcount < max) {
                func_0022afe8(se);
                func_0022aef0(&pos);
            } else {
                func_0022afa0(se);
                func_0022ae98(&pos);
            }
            func_00224950(sound);
            (*pcount)++;
            n->hit = 1;
        }
        spr->vt->setLength(spr, end - start);
        spr->vt->setPos(spr, 0);
        if (!before) {
            spr->vt->setPos(spr, now - start);
            if (now <= end) spr->vt->setOn(spr);
            else spr->vt->setOff(spr);
        }
        ((void (*)(W1636Sprite*, W1636Vec))func_001391a8)(spr, pos);
        *ptime += D_00349e10;
        return;
    }
done:
    func_001024a8(t);
}

void func_0022a0f8(u8* p, s32 a1, s32 a2, s32 a3) {
    c_create(p, a1, a3);
    *(s32*)(p + 0x344) = a2;
    c_ftGsPrim(p + 0x20, 4);
    c_setRot(p + 0x20, 0.0f);
    c_ftGsTest(p + 0x20, 0x32001);
    if (a2 == 0) {
        c_setWH(p + 0x20, 100, 100);
        return;
    }
    c_setWH(p + 0x20, 64, 64);
    c_setCenterXY(p + 0x20, -32, -32);
    c_rcGsPrim(p + 0x140, 6);
    c_rcGsTest(p + 0x140, 0x32001);
    c_setWH(p + 0x140, 64, 64);
    c_rcGsPrim(p + 0x240, 6);
    c_rcGsTest(p + 0x240, 0x32001);
    c_setWH(p + 0x240, 64, 64);
}

void func_0022a200(u8* g) {
    u8* owner = *(u8**)(g + 832);
    if (owner != 0) {
        s32 x, y, ox, oy;
        func_0023a9c0(owner + 24, &x, &y);
        func_00138c50(*(u8**)(g + 832), &ox, &oy);
        s32 X = ox + x;
        s32 Y = oy + y;
        func_0014b1e0(g + 32, X, Y);
        if (*(s32*)(g + 836) == 1) {
            u16 rx, ry;
            func_0014b258(g + 320, &rx, &ry);
            func_0014b1e0(g + 320, rx + X, ry + Y);
            func_0014b258(g + 576, &rx, &ry);
            func_0014b1e0(g + 576, rx + X, ry + Y);
        }
    }
    func_0013eeb8(g + 32);
    if (*(s32*)(g + 836) == 1) {
        func_0014b698(g + 320);
        func_0014b698(g + 576);
    }
}

void* func_0022a368(s32 type) {
    u8* h = *(u8**)(*(u8**)(D_00340000 + 32640) + 20);
    u8* o = (**(u8* (***)(u8*, u32, u32))h)(h, 5504, 0);
    func_00322790(o);
    func_0022a7e0((W1636Score*)o, type);
    return o;
}

extern const f32 D_003710d0 = 4.0f;

s32 func_0022a3d0(s32 n, f32 x, s32* a, s32* b, s32* c, s32* d, s32* e, s32* f, s32* g, s32* h, f32* out)
{
    f32 r = (f32)n / D_003710d0;
    f32 ang = (x + r) * (90.0f / r * 0.017453292f);
    *out = ang;
    *out = func_0017ce10(ang);
    if (x < r) {
        *a = 0; *b = 0; *c = 64; *d = 50; *e = -64; *f = -50; *g = 64; *h = 100;
        return 1;
    }
    if (x < r + r) {
        *a = 0; *b = -50; *c = 0; *d = 0; *e = -64; *f = -50; *g = 64; *h = 100;
        return 2;
    }
    if (x < r * 3.0f) {
        *a = 0; *b = 50; *c = 0; *d = 0; *e = -64; *f = -50; *g = 64; *h = 50;
        return 3;
    }
    *a = 0; *b = -50; *c = 0; *d = 0; *e = 0; *f = -50; *g = 64; *h = 50;
    return 4;
}

void W2023_hide(void*) asm("_ZN2dk5Obj2D9localHideEv");
void W2023_show(void*) asm("_ZN2dk5Obj2D9localShowEv");
void W2023_call4(void*) asm("_Z16u_call4_00139d78jjjj");
void W2023_setRot(void*, f32) asm("_ZN2dk7Ft4Base6setRotEf");
void W2023_setXY(void*, s16, s16) asm("_ZN2dk13RectParamBase5setXYEss");
void W2023_setZ(void*, u32) asm("_ZN2dk13RectParamBase4setZEj");
void W2023_setWH(void*, u16, u16) asm("_ZN2dk13RectParamBase14setWidthHeightEtt");
struct W2023Ent {
    u8 obj[32];
    u8 ft4[288];
    u8 r1[256];
    u8 r2[272];
    void setZ(u32 z)
    {
        W2023_call4(obj);
        W2023_setZ(r1, z);
        W2023_setZ(r2, z);
    }
    void setRot(f32 a)
    {
        W2023_call4(obj);
        W2023_setRot(ft4, a);
    }
    static void rect(void* o, void* r, s32 x, s32 y, s32 w, s32 h)
    {
        W2023_call4(o);
        W2023_setXY(r, x, y);
        W2023_setWH(r, w, h);
    }
};
struct W2023SelfB {
    u8 pad[1680];
    W2023Ent e[4];
    u8 pad2[5480 - 1680 - 4 * 848];
    s32 b98;
};

void func_0022a5c8(W2023SelfB* s, s32 i, u32 z1, u32 z2, f32 x)
{
    s32 h;
    f32 rot;
    s32 a, b, c, d, e, f, g;
    W2023_hide(s->e[i].obj);
    switch (func_0022a3d0(s->b98, x, &a, &b, &c, &d, &e, &f, &g, &h, &rot)) {
    case 0:
        break;
    case 1:
        s->e[i].setZ(z1);
        break;
    case 2:
        s->e[i].setZ(z1);
        break;
    case 3:
        s->e[i].setZ(z1);
        break;
    case 4:
        s->e[i].setZ(z2);
        break;
    }
    W2023Ent* p = &s->e[i];
    p->setRot(rot);
    W2023Ent::rect(p->obj, p->r1, a, b, c, d);
    W2023Ent::rect(p->obj, p->r2, e, f, g, h);
    W2023_show(p->obj);
}

inline static void W1636_setParent(W1636Spr* s, W1636Score* p)
{
    s->parent = p;
    func_001396b0(s);
    if (s->parent)
    {
        s->settled = 0;
        func_001396b0(s);
        if (s->settled)
            func_0031a260(s, 0);
    }
}

inline static void W1636_setZ(W1636Group* g, u32 z)
{
    func_00139d78(g);
    func_0014b200(&g->r0, z);
    func_0014b200(&g->r1, z);
    func_0014b200(&g->r2, z);
}

inline static void W1636_attach(W1636Group* g, W1636Score* s)
{
    func_00139d78(g);
    g->owner = s;
}

void func_0022a7e0(W1636Score* s, s32 type)
{
    s32 a = 0;
    s32 b = 0;
    s32 c = 0;
    s->type = type;
    u32 img = func_0022b720();
    u32 sqd = func_0022b9e0();
    switch (s->type)
    {
    case 0:
        if (s)
        {
            b = 103;
            a = 90;
            c = 127;
            break;
        }
        else
        {
            b = 103;
            a = 90;
            c = 127;
            break;
        }

    case 1:
        b = 104;
        a = 91;
        c = 130;
        break;

    case 2:

    case 4:
        b = 105;
        a = 92;
        c = 97;
        break;

    case 3:
        b = 106;
        a = 93;
        c = 98;
        break;
    }

    func_0022a0f8((u8*)&s->grp[0], 2500, 0, 11);
    func_0022a0f8((u8*)&s->grp[3], 2500, 1, 11);
    func_00158050(&s->bar[2], 2500, sqd, img, a, 100, 11);
    func_0022a0f8((u8*)&s->grp[2], 2500, 1, 11);
    func_00158050(&s->bar[1], 2500, sqd, img, 101, 500, 11);
    func_0022a0f8((u8*)&s->grp[1], 2500, 1, 11);
    func_00158050(&s->bar[0], 2500, sqd, img, 102, 700, 11);
    func_001386e0(&s->face, 2500, sqd, img, c, 11);
    func_001386e0(&s->base, 2499, sqd, img, b, 11);
    W1636_setZ(&s->grp[0], 0);
    W1636_setZ(&s->grp[3], 200);
    W1636_setZ(&s->grp[2], 600);
    W1636_setZ(&s->grp[1], 800);
    s32 i;
    for (i = 0; i < 3; i++)
    {
        W1636_setParent(&s->bar[i], s);
    }

    s32 j;
    for (j = 0; j < 4; j++)
    {
        W1636_attach(&s->grp[j], s);
    }

    W1636_setParent(&s->face, s);
    W1636_setParent(&s->base, 0);
    s->count = 0;
    s->base.alpha = 1.0f;
}

s32 func_0022ab80(u8* a0) { return *(u32*)(a0 + 5496) == 4; }

void func_0022ab90(u8* a0) {
    s32 v = func_0022ab80(a0);
    if (v != 0) {
        func_00138c10(a0 + 5072, 98);
    }
}

void func_0022abd8(u8* a0, u32 a1) {
    if (func_0022ab80(a0) == 0) {
        return;
    }
    if (a1 != 0) {
        return;
    }
    u8* s = a0 + 5072;
    func_00138c10(s, 100);
    *(u32*)(s + 392) = 97;
}

void func_0022ac30(u8* a0, s32 v) { *(s32*)(a0 + 5480) = v; }
void func_0022ac38(u8* a0, s32 v) { *(s32*)(a0 + 5484) = v; }
void func_0022ac40(u8* a0, s32 v) { *(s32*)(a0 + 5492) = v; }
void func_0022ac48(u8* a0, s32 v) {
    s32 d = *(s32*)(a0 + 5480) - v;
    if (d < 0) d = 0;
    *(s32*)(a0 + 5488) = d;
}

void func_0022ac60(u8* a0) {
    func_0022a5c8((W2023SelfB*)a0, 3, 200, 0, (f32)*(s32*)(a0 + 5488));
    func_0022a5c8((W2023SelfB*)a0, 2, 600, 0, (f32)*(s32*)(a0 + 5484));
    func_0022a5c8((W2023SelfB*)a0, 1, 800, 0, (f32)*(s32*)(a0 + 5492));
}

void func_0022acd0(void* p) {
    func_0022ac60((u8*)p);
    func_001390f0(p);
}

static inline void call20(u8* a0) {
    (*(void (**)(u8*))(*(u8**)a0 + 20))(a0);
}

void func_0022acf8(u8* a0) {
    u8* s = a0;
    s32 i = 2;
    call20(a0);
    do {
        call20(s + 440);
        i--;
        s += 412;
    } while (i >= 0);
    s = a0;
    i = 3;
    do {
        call20(s + 1680);
        i--;
        s += 848;
    } while (i >= 0);
    func_00139510(a0 + 5072);
}

void func_0022ad88(s32 n, u32 b) {
    if (n <= 0) return;
    if (func_002249b8() != 5) return;
    s32 cnt = n;
    Heap2* h = D_00347f80.p->heap;
    ItemPanel* o = (ItemPanel*)h->vt->alloc(h, 2900, 0);
    o->f12 = 0;
    o->vt = D_0035e190;
    ItemSlot* s = o->slot;
    for (s32 i = 6; i != -1; i--) {
        s->vt = D_00347f98;
        func_0031a838(s->a);
        s->vt = D_00347e60;
        func_00239700(s->b);
        s++;
    }
    func_002294c8(o, 6, &cnt, (u8*)D_0035e1f8);
    func_00229678(o, b, cnt);
}

u32 func_0022ae98(void* v) {
    u32 r = func_0022b688(142);
    Q16 t;
    QCOPY(&t, v);
    func_001391a8((void*)r, &t);
    func_002251c8(12101);
    return r;
}

u32 func_0022aef0(void* q) {
    u32 v = func_0022b688(141);
    Q16 t;
    QCOPY(&t, q);
    func_001391a8((void*)v, &t);
    func_002251c8(12102);
    return v;
}

void* func_0022af48(void* p) {
    u8 tmp[16] __attribute__((aligned(16)));
    void* v = (void*)func_0022b688(140);
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(tmp), "r"(p) : "$8", "memory");
    func_001391a8(v, tmp);
    func_002251c8(12103);
    return v;
}

void func_0022afa0(s32 a) {
    func_00224828(a);
    func_0022afe8((s32)((f32)a * 1.5f));
}

s32 func_0022afe8_impl(s32 a0) asm("func_0022afe8");
s32 func_0022afe8_impl(s32 a0) {
    s32 s0 = a0;
    s32 v = func_002249b8();
    if (v == 5) {
        if (s0 <= 0) {
            s0 = 0;
        }
    }
    func_002248f8(s0);
    return s0;
}

s32 func_0022b028_impl(s32 n) asm("func_0022b028");
s32 func_0022b028_impl(s32 n) {
    func_002247e8(n);
    if (func_002249b8() == 3) {
        n = -n;
        func_002248f8(n);
    } else if (func_002249b8() == 5) {
        n = -n;
        if (n > 0) func_002248f8(n);
    } else {
        n = 0;
    }
    return n;
}

void func_0022b0a0(s32 a0, void* a1) {
    func_002248c0(a0);
    s32 n = func_0022b028_impl(a0);
    u32 v;
    if (n > 0) {
        v = func_0022ae98(a1);
    } else {
        v = (u32)func_0022af48(a1);
    }
    func_0022ad88(n, v);
}
