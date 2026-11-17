#include "../common/types.h"
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Q1882V4 {
    f32 x, y, z, w;
    Q1882V4() {}
    Q1882V4& operator=(const Q1882V4& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct Q1882Obj { Q1882V4 pos; u8 pad[48]; Q1882V4 vel; u8 b80; u8 pad2[3]; void* fn; };
struct Q1882Ent { Q1882Obj* p; u32 flags; u32 pad; };
extern "C" {
extern s32 D_00351600;
extern Q1882V4 D_00352a60;
extern Q1882Ent D_01d49658[];
s32 func_001c4170(void);
void func_001c4ff0(void);
void func_001c42c0(void);  // 0x001c42c0: definition moved into src/anon/unit_001c4120.cpp

}
