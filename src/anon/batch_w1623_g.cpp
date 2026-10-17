#include "../common/types.h"
struct W1623Vec {
    f32 x, y, z, w;
    W1623Vec() {}
    W1623Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1623Vec& operator=(const W1623Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    f32 normalize() {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                     : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    W1623Vec operator-(const W1623Vec& o) const {
        W1623Vec r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1623Obj { u8 pad[1360]; W1623Vec dir; };
extern "C" {
extern u8 D_0036d9f8[];
s32 map_is_pax_exist(void) asm("_ZN2dk3Map10isPaxExistEv");
void* map_get_pax(void) asm("_ZN2dk3Map6getPaxEv");
s32 obj_get_ground(W1623Obj*) asm("_ZN2YS3OBJ10get_groundEv");
s32 pax_search_id(void*, u64) asm("_ZN3ryj3PAX9search_idEy");
W1623Vec* effect_pos(void*) asm("_ZN3ryj6EFFECT3posEv");
W1623Vec* effect_angle(void*) asm("_ZN3ryj6EFFECT5angleEv");
void* func_001de168(void*, s32, s32, s32, s32, s32);
W1623Vec func_0016b478(f32, W1623Obj*, u32);
W1623Vec* func_0016c028(W1623Obj*);
s32 func_001a76c8(W1623Vec*, W1623Vec*, s32);
W1623Vec func_0017d050(const W1623Vec&);
// Spawns the effect for a map trigger of the given type: even types aim from the 0x8028 point
// towards 0x802c, odd types from 0x8029 towards 0x802d; any other type uses the object itself.
void func_001b3748(W1623Obj* obj, u32 type)
{
    W1623Vec pos;
    W1623Vec tgt;
    W1623Vec dir;
    W1623Vec hit;
    s32 ok = 1;
    W1623Vec* pdir = &dir;
    W1623Vec* phit = &hit;
    if (!map_is_pax_exist()) return;
    u8 g = D_0036d9f8[obj_get_ground(obj)];
    if (!g) return;
    u64 mask = (u64)1 << g | (u64)1 << (type + 32);
    s32 k = pax_search_id(map_get_pax(), mask);
    if (k < 0) return;
    switch (type) {
    case 0: case 2: case 4: case 6: case 8: case 10: case 12: case 14: case 16: case 18:
        pos = func_0016b478(1.0f, obj, 0x8028);
        pos.y = func_0016c028(obj)->y;
        tgt = func_0016b478(1.0f, obj, 0x802c);
        *pdir = tgt - pos;
        dir.y = 0.0f;
        pdir->normalize();
        ok = func_001a76c8(&pos, phit, 0);
        break;
    case 1: case 3: case 5: case 7: case 9: case 11: case 13: case 15: case 17: case 19:
        pos = func_0016b478(1.0f, obj, 0x8029);
        pos.y = func_0016c028(obj)->y;
        tgt = func_0016b478(1.0f, obj, 0x802d);
        *pdir = tgt - pos;
        dir.y = 0.0f;
        pdir->normalize();
        ok = func_001a76c8(&pos, phit, 0);
        break;
    default:
        *phit = *func_0016c028(obj);
        *pdir = obj->dir;
        break;
    }
    if (!ok) return;
    void* e = func_001de168(map_get_pax(), k, 1, 2, 10001, 0);
    *effect_pos(e) = *phit;
    *effect_angle(e) = func_0017d050(*pdir);
}
}
