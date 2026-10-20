#include "../common/types.h"

extern "C" {

// 16-byte vector: lq/sq copy and VU0 vsub (no C equivalent for the 128-bit ops).
struct W1814Vec {
    f32 x, y, z, w;
    W1814Vec() {}
    W1814Vec(const W1814Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1814Vec& operator-=(const W1814Vec& o) {
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W1814Cam { u8 pad[0x70]; f32 fov; u8 pad2[0x110 - 0x74]; W1814Vec pos; };
f32 func_002f8a18(f32);
f32 func_002f8870(f32);

// visible-box test: point p relative to the camera inside the view half extents
s32 func_002d1e08(W1814Cam* c, W1814Vec* p, f32* sz) {
    W1814Vec d = *p;
    d -= c->pos;
    f32 t = func_002f8a18(c->fov * 0.5f * 0.017453292f);
    t *= func_002f8870(d.z);
    f32 hw = t * 4.0f / 3.0f; hw += sz[0];
    t += sz[1];
    if (d.x < -hw || hw < d.x || d.y < -t || t < d.y) return 0;
    return 1;
}

}
