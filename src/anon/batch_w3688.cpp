#include "../common/types.h"

// 001773b8: difference of two probe results' vectors; returns the sum of their y values.
// The empty asm on the &p[1] temporary keeps a0 set up before a1 like the original.
namespace n001773b8 {
struct __attribute__((aligned(16))) Vec {
    f32 x, y, z, w;
    Vec& operator=(const Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
static inline Vec vsub(const Vec& a, const Vec& b) {
    Vec r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct P { f32 x, y, z; u32 k; Vec b; };
extern "C" {
void func_001902a8(u32, P*);
s32 func_0016bc20(u32, s32, s32);
void func_0018a818(P*, u32, s32);

// 001773b8: moved to src/yasui/libys/party.cpp
}
}

// 00180b98: walks 8 attached slots, dropping dead ones and updating live ones with the owner's position.
// a1 (the vector) is pinned so it is set before the branch like the original.
namespace n00180b98 {
struct Vec {
    f32 x, y, z, w;
    Vec() {}
    Vec(const Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    Vec& operator=(const Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Slot { void* p; u32 a; };
struct Grp { u32 a, b; Slot slots[8]; };
struct Obj6 { u8 pad[8]; s32 id; u8 pad2[0x100 - 12]; Grp g; };
extern "C" {
Vec* func_0016c028(s32);
s32 func_0019c6f0(s32);
void func_002bc398(void*, Vec*);
void func_002bc3f0(void*, Vec*);
s32 func_002bc420(void*);
// 00180b98: moved to src/anon/unit_00180408.cpp
}
}
