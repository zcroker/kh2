#include "../common/types.h"

extern "C" {

typedef struct V4 { f32 x, y, z, w; } V4;

void func_001788b8(void*);
void func_00183768(f32, void*, void*);
u8* func_002dc7c8(s32);
f32 func_002dc808(s32);
f32 func_002f8870(f32);
extern s32 D_00361f60;

// Applies a push along the owner's direction vector, then eases the value at +0xc00 within the param range.
void func_002dd7d0(u8* p) {
    func_001788b8(p);
    s32 id = D_00361f60;
    V4 v;
    f32 s = func_002dc808(id) * 10.0f;
    V4* dir = (V4*)(*(u8**)(p + 0xb44) + 0xa30);
    v.w = v.z = v.y = 0.0f;
    v.x = dir->x;
    func_00183768(s, p, &v);
    if (*(u32*)(*(u8**)(p + 0xb44) + 8) & 2) {
        *(u32*)(p + 0x108) |= 0x10000;
    }
    u8* prm = func_002dc7c8(id);
    f32* lo = (f32*)(func_002dc7c8(id) + 0x98);
    f32* hi = (f32*)(func_002dc7c8(id) + 0x9c);
    if (func_002f8870(*(f32*)(*(u8**)(p + 0xb44) + 0xa34)) < 0.1f) {
        f32 d = 1.0f - *(f32*)(p + 0xc00);
        f32 m = (func_002f8870(d) < *(f32*)(prm + 0x94)) ? func_002f8870(d) : *(f32*)(prm + 0x94);
        if (d < 0.0f) *(f32*)(p + 0xc00) = *(f32*)(p + 0xc00) - m;
        else *(f32*)(p + 0xc00) = *(f32*)(p + 0xc00) + m;
    } else {
        *(f32*)(p + 0xc00) = *(f32*)(p + 0xc00) + *(f32*)(*(u8**)(p + 0xb44) + 0xa34) * *(f32*)(prm + 0x94);
    }
    f32 c = *(f32*)(p + 0xc00);
    if (c < *lo) *(f32*)(p + 0xc00) = *lo;
    else if (*hi < c) *(f32*)(p + 0xc00) = *hi;
}

}
