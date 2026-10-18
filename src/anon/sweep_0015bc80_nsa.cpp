#include "../common/types.h"
#define W1646_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1646Vec {
    f32 x, y, z, w;
    W1646Vec() {}
    W1646Vec(const W1646Vec& o) { W1646_QCOPY(this, &o); }
    W1646Vec& operator=(const W1646Vec& o) { if (this != &o) W1646_QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1646SprVt { void* fn[3]; };
struct W1646Spr {
    W1646SprVt* vt;
    u8 pad[0xfc];
};
struct W1646Map {
    W1646Spr gauge;
    u8 pad100[0x50];
    W1646Spr arrow;
    u8 pad250[0x20];
    W1646Spr frame;
    W1646Spr ringA[4];
    W1646Spr ringB[4];
    void* texsrc;
    s32 yoff;
};
struct W1646Hud {
    u8 pad00[0x30];
    W1646Map map;
    u8 padba8[8];
    f32 scale;
    f32 div;
    s32 w;
    s32 h;
    s32 x;
    s32 y;
    u32 scrW;
    u32 scrH;
    u8 enabled;
    u8 alpha;
};
extern "C" {
extern u8 D_0034ac00;
void func_0013edd0(W1646Spr*, f32);
void func_0013ee28(W1646Spr*, u64);
void func_0013eeb8(W1646Spr*);
void func_0014b1e0(W1646Spr*, s16, s16);
void func_0014b208(W1646Spr*, u16, u16);
void func_0014b220(W1646Spr*, u8, u8, u8, u8);
void func_0014b628(W1646Spr*, u64);
void func_0014b698(W1646Spr*);
void func_0014bb30(W1646Spr*);
void func_0015bab8(W1646Map*);
u64 func_00166148(void*, s32, s32);
W1646Vec func_0016af58(void*);
void* func_0016b0d0(void);
W1646Vec* func_0016c028(void*);
s32 func_00191c88(void);
s32 func_001949d0(void);
s32 func_00242ae8(void);
f32 func_002f8ad0(f32, f32);

void func_0015bc80(W1646Hud* o) {
    if (!o->enabled) return;
    if (func_00191c88()) return;
    void* pl = func_0016b0d0();
    if (!pl) return;
    if (!func_00242ae8()) return;
    if (!func_001949d0()) return;
    W1646Map* m = &o->map;
    func_0015bab8(m);
    func_0014b220(&o->map.frame, 0x80, 0x80, 0x80, o->alpha);
    u64 tex = func_00166148(&D_0034ac00, 0x3500, 0x3520);
    func_0014b698(&o->map.frame);
    func_0014b628(&o->map.ringB[0], tex);
    for (s32 i = 0; i < 4; i++) {
        W1646Spr* a = &m->ringA[i];
        func_0014b220(a, 0x80, 0x80, 0x80, o->alpha);
        func_0014b628(a, tex);
        ((void (*)(W1646Spr*))a->vt->fn[2])(a);
        W1646Spr* b = &m->ringB[i];
        func_0014b220(b, 0x80, 0x80, 0x80, o->alpha);
        func_0014b628(b, tex);
        ((void (*)(W1646Spr*))b->vt->fn[2])(b);
    }
    W1646Spr* ar = &m->arrow;
    func_0014b628(&m->gauge, func_00166148(m->texsrc, 0x2800, 0x34e0));
    func_0014b220(&m->gauge, 0x80, 0x80, 0x80, o->alpha);
    func_0014b220(ar, 0x80, 0x80, 0x80, o->alpha);
    u32 hw = o->scrW >> 1;
    u32 hh = o->scrH >> 1;
    s32 minX = 48 - hw;
    s32 maxX = hw - 48;
    s32 minY = 48 - hh;
    s32 maxY = hh - 48;
    W1646Vec pos = *func_0016c028(pl);
    s32 dx = 0;
    s32 dy = 0;
    s32 x = o->x - (s32)(pos.x / o->div * o->scale);
    s32 y = (s32)(pos.z / o->div * o->scale) + o->y;
    W1646Vec d;
    d = func_0016af58(pl);
    func_0013edd0(ar, func_002f8ad0(d.x, d.z));
    if (x < minX) {
        dx = minX - x;
        x = minX;
    } else if (maxX < x) {
        dx = maxX - x;
        x = maxX;
    }
    if (y < minY) {
        dy = minY - y;
        y = minY;
    } else if (maxY < y) {
        dy = maxY - y;
        y = maxY;
    }
    s32 py = m->yoff;
    func_0014b1e0(ar, dx + 0x1c0, py + dy + 0x30);
    f32 sc = o->scale;
    u16 w = (s32)((f32)o->w * sc);
    u16 h = (s32)((f32)o->h * sc);
    u16 cx = (u16)o->x + (w >> 1);
    u16 cy = (u16)o->y + (h >> 1);
    func_0014b208(&m->gauge, w, h);
    s16 px = x - cx + 0x1c0;
    py = m->yoff;
    func_0014b1e0(&m->gauge, px, py + y - cy + 0x30);
    func_0014bb30(&m->gauge);
    func_0013ee28(ar, tex);
    func_0013eeb8(ar);
}
}
