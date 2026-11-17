#include "../common/types.h"
extern "C" {
// VU0 macro-mode vector helpers (hand-written asm in the original math library)
struct V110c90 {
    f32 x, y, z, w;
    V110c90() {}
    V110c90(const V110c90& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V110c90& operator=(const V110c90& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V110c90 operator-(const V110c90& b) const
    {
        V110c90 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 lengthSq() const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
struct Box110c90;
void func_00144450(Box110c90*);
struct Box110c90 {
    f32 lx, ly, lz, hx, hy, hz;
    Box110c90() { func_00144450(this); }
};
struct Pts110c90 { u8 on; u8 pad[3]; s32 count; u8 pad2[8]; V110c90 pts[32]; };
struct O110c90 {
    u8 pad0[1856];
    Box110c90 box;
    const Box110c90& getBox() const { return box; }
    u8 pad1[2940 - 1880];
    u32 flags;
    u8 pad2[3288 - 2944];
    s32 f3288;
    f32 f3292;
    s32 f3296;
};
extern Pts110c90 D_003a9040;
extern u8 D_003a9250[];
extern O110c90* D_00341708;
s32 func_00146730(u8*, Box110c90*);
V110c90* f110c90_attach(O110c90*) asm("func_0016c028");
s32 func_00110b00(O110c90*, V110c90*, Box110c90*);
s32 f110c90_rand(s32) asm("func_0010f648");
// Picks a free warp point near o (pb pins &b to s7; gcc swaps it with best otherwise).
s32 func_00110c90(O110c90* o);  // 0x00110c90: definition moved into src/anon/unit_00110b00.cpp
}
extern "C" {
void func_00138c68(u8*, s32, s32);
void func_001395f8(u8*);
void func_00139620(u8*);
u8* func_00276348(void);
u8* func_002766d0(void);
void func_00276e78(void);
s32 func_00287bc0(void);
void func_0028d8c0(u8*, s32, s32, s32, s32, s32, s32, s32);
void func_0028d980(u8*, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0028dcc0(u8*, u8*);
void func_0028f4d8(s32, s32, s32);
s32 func_0028f930(s32);
void func_002a17e8(void);
void func_002a18d0(s32, s32);
u8* func_002a1bc0(u16);
void func_002a1cd8(void);
void func_002a1f40(void);
s32 func_002a9e98(u16);
s32 func_002a9f50(u16);
extern s32 D_0035f148;
extern s32 D_0035f14c;
extern s32 D_0035f210;
extern s32 D_0035f3d4;
union U5d4 { u8* p; s16 h; u8 c; };
union U5d8 { u8* p; s32 i; };
extern U5d4 D_0035f5d4;
extern U5d8 D_0035f5d8;
extern s32 D_00374b4c;
extern s32 D_00374b50;
extern s32 D_00374b54;
extern s32 D_00374b58;
extern s16 D_00374b70[];

struct It8 { u16 id; s16 x; s16 y; s16 pad; };
struct Sel5d4 { s8 n; u8 sel; s8 kind; u8 pad[77]; It8 it[1]; };
// Builds the selection menu items. Register pins: loop index i in s7, the loop-end
// count pointer/value in t5/t7 and the 408 stride constant in a1 (gcc swaps s6/s7 otherwise).
void func_002a0908(s32 sel);  // 0x002a0908: definition moved into src/anon/unit_002a0908.cpp
}
