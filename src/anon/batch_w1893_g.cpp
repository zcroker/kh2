#include "../common/types.h"
struct V1893 {
    f32 x, y, z, w;
    V1893() {}
    V1893(const V1893& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V1893& operator=(const V1893& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V1893 operator-(const V1893& b) const {
        V1893 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
extern "C" {
extern u32 D_0034e948;
s32 func_0016e920(void);
V1893* func_0016c028(u32);
s32 func_001a75d8(V1893*, V1893*, s32);
V1893 func_001a7888(V1893*, s32, f32, f32);
s32 func_001050d8(s32);
f32 func_002f8ad0(f32, f32);
void func_0010c078(f32, s32, s32, V1893*);
s32 func_0017e4f8(void* a, V1893* t, f32 h, f32 x, f32 y) {
    V1893 p;
    V1893 q;
    V1893 r;
    V1893* pq = &q;
    if (a == 0) return 0;
    s32 k = func_0016e920();
    p = *func_0016c028(D_0034e948);
    p.y -= h;
    if (t != 0) {
        *pq = *t;
        pq->y -= h;
        if (func_001a75d8(&p, pq, 0x10000)) {
            *pq = *t;
            goto done;
        }
    }
    *pq = func_001a7888(&p, 0x10000, x, y);
done:
    r = p - *pq;
    s32 o = func_001050d8(0xd00);
    func_0010c078(func_002f8ad0(r.x, r.z), o, k, pq);
    return o;
}

}
