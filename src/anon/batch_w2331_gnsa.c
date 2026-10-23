#include "../common/types.h"

/* Plain C (partMng family), built without strict aliasing. -g makes no difference here; the name is _gnsa
   only because batch_wcx2_nsa.c / _gnsa.c would share an object name with the workspace .cpp files. */

/* 001fa2b0: particle position integrate, then build and submit a sprite render request. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V1fa2b0;
typedef struct {
    V1fa2b0 a;
    V1fa2b0 col;
    void* p32;
    u32 w36;
    void* p40;
    s32 w44;
    V1fa2b0 b;
    u64 q64;
    u64 q72;
    u64 q80;
    f32 f88;
    f32 f92;
} Req1fa2b0;
typedef struct { s32 f0; f32 f4, f8, f12, f16, f20; u8 b24; u8 b25; } Ent1fa2b0;
typedef struct { u8 pad0[12]; s32* off; } Ctx1fa2b0;
typedef struct { u8 pad0[168]; u64 flags; } Cur1fa2b0;
extern s32 D_01d9ea9c;
extern Cur1fa2b0* D_01d9e6e0;
extern u8 D_01d9e8c0[];
extern u32 D_01d9eaa4;
extern u32 D_01d9eaa8;
extern f32 D_00354be0[];
extern s32 D_00352be4, D_00352be8, D_00352bec, D_00352bf0, D_00352bf8, D_00352bfc;
extern u64 D_00352c18;
void func_002f3cd8(V1fa2b0*, V1fa2b0*, V1fa2b0*);
void func_00222f88(Req1fa2b0*);
s32 func_002231b8(Req1fa2b0*);
void func_0020e7a8(u32, u32, s32, s32);
void func_0020e858(u32, u32, s32, s32);
void func_001fa2b0(u8* base, Ent1fa2b0* e, Ctx1fa2b0* c)
{
    f32* pos = (f32*)(base + c->off[0] + 160);
    V1fa2b0* m = (V1fa2b0*)(base + c->off[2] + 160);
    u8* col;
    Req1fa2b0 r;
    if (D_01d9ea9c == 0 && (D_01d9e6e0->flags & 0xff0000ff00ULL) == 0) {
        f32 ax = pos[2];
        f32 vx = pos[1] + ax;
        f32 x = pos[0] + vx;
        pos[1] = vx;
        pos[0] = x;
        if (*(s32*)(base + 12) == e->f0) {
            pos[0] = x + e->f4;
            pos[1] = vx + e->f8;
            pos[2] = ax + e->f12;
        }
    }
    col = base + c->off[1] + 160;
    r.col.x = col[8];
    r.col.y = col[9];
    r.col.z = col[10];
    r.col.w = col[11];
    if (e->b25 & 2) {
        f32* q = (f32*)(base + c->off[3] + 160);
        r.a.x = q[0];
        r.a.y = q[1];
        r.a.z = 512.0f;
        r.a.w = 1.0f;
        r.p40 = D_01d9e8c0;
    } else {
        r.a = m[3];
        r.p40 = D_01d9e8c0;
    }
    r.f88 = e->f16 * D_00354be0[0];
    r.p32 = D_01d9e8c0;
    r.w36 = D_01d9eaa4 + 16;
    r.f92 = e->f20 * D_00354be0[1];
    if (e->b24 == 0) {
        r.q64 = (D_00352bf8 << 5) | ((u64)(D_00352bec / 64) << 14) | ((u64)85 << 27);
        r.q80 = ((2048 - D_00352bec / 2) << 4) | ((u64)(2048 - D_00352bf0 / 2) << 36);
    } else {
        r.q64 = (D_00352bfc << 5) | ((u64)(D_00352be4 / 64) << 14) | ((u64)85 << 27);
        r.q80 = ((2048 - D_00352be4 / 2) << 4) | ((u64)(2048 - D_00352be8 / 2) << 36);
    }
    r.q72 = D_00352c18;
    r.b.x = r.b.z = r.b.w = 0.0f;
    r.b.y = -pos[0];
    func_002f3cd8(&r.b, m, &r.b);
    *(s32*)&r.b.w = e->b25;
    func_00222f88(&r);
    if (func_002231b8(&r)) {
        if (e->b25 & 2) func_0020e7a8(D_01d9eaa4, (r.w36 - D_01d9eaa4) >> 4, 4, 0);
        else func_0020e858(D_01d9eaa4, (r.w36 - D_01d9eaa4) >> 4, r.w44 / 12288, 0);
        D_01d9eaa8 += r.w36 - D_01d9eaa4;
        D_01d9eaa4 = r.w36;
    }
}
