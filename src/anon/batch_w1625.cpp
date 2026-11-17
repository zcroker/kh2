#include "../common/types.h"
// dk::ObjCamera area (0x1408a0): spring the camera eye/target/up toward their goals.
extern "C" {
struct W1625V4 {
    f32 x, y, z, w;
    W1625V4() {}
    W1625V4(const W1625V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1625V4& operator=(const W1625V4& o)
    {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    void set(const W1625V4& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct W1625Target { u8 pad[0x114]; f32 dist; };
struct W1625Cam {
    W1625V4 eye;      // 0x00
    W1625V4 at;       // 0x10
    W1625V4 up;       // 0x20 (x = fov, y = roll)
    u8 pad30[0x10];
    u32 mode;         // 0x40
    W1625Target* target;  // 0x44
    u8 pad48[0x18];
    W1625V4 at2;      // 0x60
    W1625V4 at3;      // 0x70
    W1625V4 eyeGoal;  // 0x80
    W1625V4 eyeVel;   // 0x90
    W1625V4 upGoal;   // 0xa0
    W1625V4 upVel;    // 0xb0
};
// W1625V4 func_0013f6e8(W1625V4 pos, W1625V4 goal, W1625V4 vel, f32 dt, f32 k, f32 damp, f32 rest),
// spelled with its hidden return pointer so the four 16-byte temporaries keep fixed stack slots.
void Spring_13f6e8(W1625V4* out, W1625V4* pos, W1625V4* goal, W1625V4* vel, f32 dt, f32 k, f32 damp, f32 rest) asm("func_0013f6e8");
u8 func_0013f9e0(W1625V4*, W1625Cam*, W1625V4*, s32, s32);
void func_00140480(W1625Cam*);
void func_0015a4e0(W1625Cam*);
u8* func_00106a18(s32);
void func_00106de8(u8*, s32, f32);
u8* func_00106a60(s32);
void func_00107300(u8*, W1625V4*, W1625Cam*, f32);

void func_001408a0(W1625Cam* c, u8 noUpdate);  // 0x001408a0: definition moved into src/anon/unit_0013fca8.cpp
}
