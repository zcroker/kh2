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
s32 func_00141ff0(ObjN* o, SegN* ray, V4n* out, u16* id, s32 mask) {
    SegN s = *ray;
    if (!o->b209) {
        s.a = o->m144 * s.a;
        s.b = o->m144 * s.b;
    }
    SegN r2;
    r2.a = s.a;
    r2.b = s.b - s.a;
    r2.b.w = 1.0f;
    r2.a.w = 1.0f;
    BoxN box;
    func_00144618(&box, &s);
    V4n b;
    func_00144e30(&b);
    func_00144e50(&b, &box, func_00141970(o));
    u16 r = 0;
    u8 buf[2048];
    func_00141980(o, buf);
    func_00141c38(o, 0, &b, &r, mask);
    u16 v = func_00141e78(o, &r2, r, out);
    *id = v;
    if (v == 0xffff) return 0;
    if (o->b209) return 1;
    *out = o->m80 * *out;
    return 1;
}
}
