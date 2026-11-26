#include "../common/types.h"

struct Ent8 { u8 f0, f1, f2, f3; u16 f4, f6; };
struct EntTbl { Ent8 list[512]; Ent8 sub[15]; s32 count; s32 active; };
struct ItemRec { u8 f0, f1; u16 id; u8 f4; u8 f5; u16 f6; u16 f8; };
struct W1957Vec {
    f32 x, y, z, w;
    W1957Vec() {}
    W1957Vec& operator=(const W1957Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

void func_0017f488(int, int, float, float);

struct W1957V {
    f32 x, y, z, w;
    W1957V() {}
    W1957V(const W1957V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
    }
    W1957V& operator=(const W1957V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

extern "C" {

union TblPtr { EntTbl* p; u32 w; u16 h; u8 b; };
extern TblPtr D_0035f5e4;
u32 func_00276c18(void);
void func_002fde18(void*, s32, s32);
ItemRec* func_001a82b0(ItemRec*);
s32 func_00181500(u16);
s32 func_002a4390(ItemRec*);
u8 Tz__Jiminy__AreaWorld2JmWorld(u8);
void Tz__JmTreasure__SortList(void);
s32 Tz__JmNewInfo__isTreasureNew(s32);
s32 func_002ab620(s32);
void func_002a2a80(void);  // 0x002a2a80: definition moved into src/anon/unit_002a1d38.cpp


struct W1957Range { u8 pad[12]; s16 lo, hi, z; };
struct W1957Tgt {
    virtual void v0();
    virtual void v1();
    virtual W1957Vec pos();
    u8 pad[36];
    W1957Range* range;
};
struct W1957Info { u32 f0, f4, flags; };
struct W1957Obj {
    u8 pad0[12];
    W1957Info* info;        // 0x0c
    u8 pad10[320 - 16];
    u8 sub[32];             // 0x140
    u32 flags;              // 0x160
    u8 pad164[2732 - 356];
    W1957Tgt* tgt;          // 0xaac
    f32 dist;               // 0xab0
    f32 f2740;              // 0xab4
    s32 act;                // 0xab8
};

W1957Vec func_0016be98(W1957Obj*);
void func_001c1fe0(W1957Obj*);
void w1957_change_action(W1957Obj*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
extern s32 D_003638d0;

static inline W1957Vec w1957_sub(const W1957Vec& a, const W1957Vec& b) {
    W1957Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

static inline f32 w1957_len(const W1957Vec& v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(len) : "r"(&v) : "$8", "memory");
    return len;
}

static inline f32 w1957_frand(void) {
    D_003638d0 = D_003638d0 * 0x10dcd;
    return (f32)(u32)D_003638d0 * 2.3283064e-10f;
}

static inline bool w1957_flag(W1957Obj* o) {
    return (o->info->flags & 2) || (o->flags & 0x40);
}

// 001c1b08: moved to src/anon/unit_001c0638.cpp
void YS__BTLOBJ__tornado(W1957Obj* self, W1957Tgt* tgt, u8 on);


struct W1957Face { u8 pad[10]; u16 plane; u8 pad2[4]; };
struct W1957Hit { u8 d[32]; };
struct W1957Map {
    u8 pad0[12];
    W1957Face* faces;      // 0x0c
    u8 pad10[8];
    W1957V* planes;        // 0x18
    u8 pad1c[32];
    u16* list;             // 0x3c
};
struct W1957Who { u8 pad[48]; W1957V pos; u8 pad40[44]; f32 height; };

void func_00141988(W1957Map*, W1957Face*, W1957Hit*);
s32 func_00162408(W1957Hit*, W1957V*);
f32 fabsf(f32);

static inline f32 w1957_dot(const W1957V& a, const W1957V& b) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}

s32 func_00142688(W1957Map* map, f32* out, s32 n, W1957Who* who);  // 0x00142688: definition moved into src/anon/unit_00141458.cpp

}
