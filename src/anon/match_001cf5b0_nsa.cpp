// 001cf5b0: camera setup; the eight float constants are the original ones (literal pool at 0x36e320).
#include "../common/types.h"
extern "C" {
void func_00177dc8(void*, u32, s32, u32, u32);
void func_00158a90(void*);
extern u8 D_00352288[];
struct W1807V4s { f32 x, y, z, w; void set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; } };
struct W1807Cam { u32 vt; u8 pad[2924]; W1807V4s a; W1807V4s b; f32 r0, r1, r2, r3; u32 z0, z1; };
void func_001cf5b0(W1807Cam* p, u32 a1, u32 a2, u32 a3) {
    func_00177dc8(p, a1, 11, a2, a3);
    p->vt = (u32)D_00352288;
    p->a.set(0.0f, -200.0f, 200.0f, 1.0f);
    p->b.set(0.0f, 0.0f, -100.0f, 1.0f);
    p->r0 = 0.05235987529158592f; p->r1 = 0.7853981256484985f; p->r2 = 0.01745329238474369f; p->r3 = 0.2617993652820587f;
    p->z0 = 0; p->z1 = 0;
    func_00158a90(p);
}
}
