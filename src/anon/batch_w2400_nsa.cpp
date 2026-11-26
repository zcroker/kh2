#include "../common/types.h"
struct V4q {
    f32 x, y, z, w;
    V4q() {}
    V4q(const V4q& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4q& operator=(const V4q& o) {
        if (this == &o) return *this;
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct EntQ { u8 b0; u8 b1; u8 pad[14]; };
struct MgrQ { u8 pad[12]; EntQ* tbl; };
struct InfQ { s16 h0; s16 h2; };
struct ObjQ { u8 pad[48]; V4q pos; u8 pad2[32]; u16 h96; u8 pad3[10]; f32 f108; u8 pad4[8]; MgrQ** p120; };
struct OutQ { V4q v0; V4q v16; u8 sub[4]; u32 f36; u32 f40; u32 f44; u32 f48; u8 b52; };
extern "C" {
extern MgrQ* D_0034880c;
extern MgrQ* D_00348804;
void func_0015cb78(u8*, s32);
void func_00141980(MgrQ*, u8*);
s32 dk__OctCollFile__selectDownAllPolygon(MgrQ*, ObjQ*);
u16 func_00142688(MgrQ*, u32*, s32, ObjQ*);
void func_001539c0(u8*, V4q*);
u32 dk__Octree__getSkeltonType(ObjQ*);
V4q func_00143e50(u16, s32);
V4q func_001422a0(MgrQ*, u16);
InfQ* func_00142398(MgrQ*, u16);
InfQ* dk__Octree__getAttr(u16, s32);
void func_00141988(MgrQ*, EntQ*, V4q*);
static inline void negq(V4q* d, const V4q* s) {
    asm volatile("lqc2 $vf4, 0(%1)\n\tvsub.xyz $vf5, $vf0, $vf4\n\tsqc2 $vf5, 0(%0)" : : "r"(d), "r"(s) : "memory");
}
void func_00143648(ObjQ* o, OutQ* out);  // 0x00143648: definition moved into src/anon/unit_00142c90.cpp
}
