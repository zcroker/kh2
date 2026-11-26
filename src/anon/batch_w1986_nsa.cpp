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
s32 kn__getProjection(s32);
f32 func_001070a8(s32);

W1986Pkt* func_00108730(W1986Src* p, void* q);  // 00108730: moved to src/anon/unit_001085a8.cpp

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
f32 sinf(f32);
f32 cosf(f32);

void Ti__MGOarashiGimObj__appear_fall_prize(void* a);  // 0x002d36f0: definition moved into src/anon/unit_002d2498.cpp

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
W1986Tg* YS__PARTY__GetByPart(u32);
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
// 00175f68: moved to src/yasui/libys/party.cpp
}
