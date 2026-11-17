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

void func_0015bc80(W1646Hud* o);  // 0x0015bc80: definition moved into src/anon/unit_0015bab8.cpp
}
