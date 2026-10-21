#include "../common/types.h"
extern "C" {
struct M1885 { f32 m[16]; } __attribute__((aligned(16)));
struct G1885 { u8 pad[16]; M1885 mtx; };
union U1885 { G1885* p; f32 f; };
extern U1885 D_01d9e6e8;
extern M1885 D_00354bd0;
extern f32 D_00354bc0[3];
void func_0021ed18(M1885*, void*);
void func_002f3e20(M1885*, M1885*);
void func_002f3d08(M1885*, M1885*, void*);

static inline void ScaleRow1885(f32* row, f32 s)
{
    asm("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)"
        : : "r"(row), "r"(s) : "memory");
}

// 00201510: model node matrix build (rotate, translate, multiply, VU0 row scale). Same shape as func_00200e80.
void func_00201510(u8* p, u32, u8* a2)
{
    u32* offs = *(u32**)(a2 + 12);
    f32* pos = (f32*)(p + offs[0] + 160);
    u8* rot = p + offs[1] + 160;
    u8* m = p + offs[3] + 160;
    f32* scl = (f32*)(p + offs[2] + 160);
    M1885 t;
    func_0021ed18(&D_01d9e6e8.p->mtx, rot);
    D_01d9e6e8.p->mtx.m[12] = pos[0];
    D_01d9e6e8.p->mtx.m[13] = pos[1];
    D_01d9e6e8.p->mtx.m[14] = pos[2];
    func_0021ed18(&t, &D_00354bd0);
    t.m[12] = D_00354bc0[0];
    t.m[13] = D_00354bc0[1];
    t.m[14] = D_00354bc0[2];
    func_002f3e20(&t, &t);
    func_002f3d08(&D_01d9e6e8.p->mtx, &D_01d9e6e8.p->mtx, m);
    func_002f3d08(&D_01d9e6e8.p->mtx, &t, &D_01d9e6e8.p->mtx);
    ScaleRow1885(&D_01d9e6e8.p->mtx.m[0], scl[0]);
    ScaleRow1885(&D_01d9e6e8.p->mtx.m[4], scl[1]);
    ScaleRow1885(&D_01d9e6e8.p->mtx.m[8], scl[2]);
}
}
