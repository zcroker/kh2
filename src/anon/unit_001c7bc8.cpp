#include "../common/types.h"

// Effect-spawner object file (0x1c7b88-0x1c7f10). One instance lives at a time; its pointer is
// D_00351d98 and its vtable D_00351da8 (both retail .data, left as data). The base class
// ctor/dtor are 0x1a4db0 / 0x1a4e30. The C2 ctor copy at 0x1c7b88 (same body as 0x1c7bc8) sits
// before this unit and stays as it is.

extern "C" {
extern void* D_00351d98;
extern u8 D_00351da8;
extern const u8 D_0036dfe0[];       // 9 table indexes
extern const f32 D_0036dff0[];      // 3 scales
extern const u8 D_0036e000[][16];   // 3 effect descriptors
extern const f32 D_0036e030[];      // 3 unit sizes

void func_001a4db0(void*, u32, s32, s32);
void func_001a4e30(void*);
void func_00105110(void*);
f32 func_00191b70(void);
s32 func_001a5bd0(u32, s32, f32);
void func_001a5420(void*, const void*, u32);
void func_001a5990(u8*, u32, f32);
void func_001c1708(u32);
}

extern "C" {

// 0x1c7bc8: C1 constructor.
void func_001c7bc8(void* p, u32 a1)
{
    func_001a4db0(p, a1, 256, 96);
    *(void**)p = &D_00351da8;
    D_00351d98 = p;
}

// 0x1c7c08 / 0x1c7c38: D2 / D1 destructors.
void func_001c7c08(void* p)
{
    struct NoTail { ~NoTail() {} } nt;
    *(void**)p = &D_00351da8;
    D_00351d98 = 0;
    func_001a4e30(p);
}

void func_001c7c38(void* p)
{
    struct NoTail { ~NoTail() {} } nt;
    *(void**)p = &D_00351da8;
    D_00351d98 = 0;
    func_001a4e30(p);
}

// 0x1c7c68: D0 (deleting) destructor.
void func_001c7c68(void* p)
{
    *(void**)p = &D_00351da8;
    D_00351d98 = 0;
    func_001a4e30(p);
    func_00105110(p);
}

void func_001c7ca8(u32 a, u32 b)
{
    f32 k = func_00191b70();
    if (D_00351d98) {
        for (s32 i = 0; i < 9; i++) {
            for (s32 j = 0; j < func_001a5bd0(b, i, k); j++)
                func_001a5420(D_00351d98, D_0036e000[D_0036dfe0[i]], a);
        }
    }
}

void func_001c7d90(u32 a0, f32 x)
{
    if (!D_00351d98) return;
    for (s32 i = 0; i < 3; i++) {
        s32 n = (s32)(x * D_0036dff0[i] / D_0036e030[i]);
        for (s32 j = 0; j < n; j++) func_001a5420(D_00351d98, D_0036e000[i], a0);
        x -= D_0036e030[i] * (f32)n;
    }
}

// 0x1c7ea8: virtual method (last vtable slot); `this` is unused.
void func_001c7ea8(void* self, u8* o)
{
    func_001a5990(o, 0, D_0036e030[o[20]]);
}

void func_001c7ee0(void)
{
    u8* p = (u8*)D_00351d98;
    if (p) func_001c1708(*(u32*)(p + 2548));
}

}  // extern "C"
