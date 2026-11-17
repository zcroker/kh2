#include "../common/types.h"

struct D18_1792 { u8 pad[0x18]; s32 off18; };
struct O4_1792 { u32 pad; D18_1792* d; };

struct QW1792 {
    f32 x, y, z, w;
    QW1792& operator=(const QW1792& o) {
        /* lq/sq quadword copy */
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct Obj1792 {
    u8 pad[0x590];
    QW1792 pos;      /* 0x590 */
    QW1792 rot;      /* 0x5a0 */
    u8 pad2[0x10];
    QW1792 tgt;      /* 0x5c0 */
    u8 pad3[0x30];
    u64 flags;       /* 0x600 */
};

extern "C" {
void func_0011efe8(void*);
void func_0011f6e8(O4_1792* o, u8* bits, s16* list);  // 0x0011f6e8: definition moved into src/anon/unit_0011c128.cpp

extern s8 D_004f3590;
extern f32 D_004f3598;
f32 func_0017ce10(f32);
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_0013edd0(u8*, f32);
void func_0014b1e0(u8*, s32, s32);
// 00155bf0: moved to src/anon/unit_00153ea0.cpp
void func_00155bf0(u8* p, s32 a);

void func_00185118(Obj1792*, QW1792*);
void func_00143928(QW1792*);
s32 func_0019bfd0(Obj1792* self, QW1792* v);  // 0x0019bfd0: definition moved into src/anon/unit_0019ba60.cpp
}
