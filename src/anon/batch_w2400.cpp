#include "../common/types.h"
struct V4n {
    f32 x, y, z, w;
    V4n() {}
    V4n(const V4n& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V4n& operator=(const V4n& o) {
        if (this == &o) return *this;
        asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V4n operator-(const V4n& o) const {
        V4n r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct M4n {
    V4n r[4];
    V4n operator*(const V4n& v) const {
        V4n o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
};
struct SegN { V4n a, b; };
struct BoxN { V4n a, b; };
struct HitN { u8 pad[12]; };
struct ObjN { u8 pad[80]; M4n m80; M4n m144; u8 pad2[1]; u8 b209; };
extern "C" {
void func_00144618(BoxN*, SegN*);
void func_00144e30(V4n*);
u32 func_00141970(ObjN*);
void func_00144e50(V4n*, BoxN*, u32);
void func_00141980(ObjN*, u8*);
void func_00141c38(ObjN*, s32, V4n*, u16*, s32);
u16 func_00141e78(ObjN*, SegN*, s32, V4n*);
s32 func_00141ff0(ObjN* o, SegN* ray, V4n* out, u16* id, s32 mask);  // 0x00141ff0: definition moved into src/anon/unit_00141458.cpp
}
