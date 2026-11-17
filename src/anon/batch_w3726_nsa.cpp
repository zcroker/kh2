#include "../common/types.h"
#define QCP(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { QCP(this, &o); }
    QV& operator=(const QV& o) { if (this != &o) QCP(this, &o); return *this; }
    QV operator-(const QV& b) const {
        QV o;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct YNode { u8 pad[0xec]; YNode* next; };
struct YList { YNode* head; YNode* tail; };
struct YFlags { u16 b0 : 1; u16 b1 : 1; };
extern "C" {
s32 func_001c0cd8(u8*);
void func_0016bd60(u8*, s32);
QV* func_0016c028(u8*);
f32 func_002f8ad0(f32, f32);
void func_0016aeb8(u8*, f32);
s32 func_0019bad8(u8*);
void func_00143928(QV*, QV*);
void func_0016ace0(u8*, QV*);
void func_0016cc18(s32, s32, s32*, s32, s32);
void func_00193608(u8*);

}
namespace YS {
struct OBJ { void detach(); };
}
// Unlinks the object from its parent's child list and restores its world placement.
// 001c0e60: moved to src/anon/unit_001c0638.cpp
