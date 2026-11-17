#include "../common/types.h"

namespace YS {
void trap_prize_appear_tr(BD_VALUE* bd);
void trap_attack_set_hitmark_pos(BD_VALUE* bd);
}  // namespace YS
void wtarget_001efd38(u32, u32, u32, u32);
namespace Tz {
class CmEquip {
public:
    static void Init();
};
}  // namespace Tz

extern "C" {

// Empty function that still saves ra (the clobber forces the frame).
void func_001003b0() { asm volatile("" ::: "$31"); }

// 001041c0: moved to src/common/gumibattle.cpp

// Push onto a downward-growing stack of words.
extern s32 D_0032bb28;
extern u32 D_003a7b60[];
// 001056e8: moved to src/anon/unit_001056e8.cpp

// Bump allocator: returns the current pointer, advances it by size rounded up to 4.
extern u32 D_00340ea8;
u32 func_0010abc8(u32 size);  // 0010abc8: moved to src/anon/unit_0010a918.cpp

extern u32 D_00347d50;
extern u8 D_00347d54;
extern u8 D_00347d55;
// 00136a98: moved to src/harata/libdk/bgm.cpp

void func_00102c18(s32, s32, void (*)(void*));
void func_00137250(void*);
// 00136fa8: moved to src/harata/libdk/bgm.cpp

// Copy the RGBA bytes at +0xe8 to +0x0c.
void func_00147c78(u32, u8* p);  // 0x00147c78: definition moved into src/anon/unit_00147140.cpp

void func_00139948(s32);
void func_00139ba0(s32);
// 00154af0: moved to src/anon/unit_00153ea0.cpp
void func_00154af0(u8* p);

// 00158920: moved to src/yasui/libys/light.cpp

void func_0014e0d8(void*);
void func_001024a8(void*);
void func_00161f10(void* p) {
    func_0014e0d8(p);
    func_001024a8(p);
}

extern s16 D_0034c874;
extern s16 D_0034c876;
void func_00166c80(s16 a, s16 b);  // 0x00166c80: definition moved into src/anon/unit_001664c0.cpp

extern f32 D_004f5268;
extern f32 D_004f526c;
extern f32 D_004f5270;
// 00167638: moved to src/anon/unit_00167358.cpp

void func_001846a0(u32, s32, f32);
void func_00173e10(BD_VALUE* bd);  // 0x00173e10: definition moved into src/anon/unit_00171e58.cpp

void func_001b1c10(s32, f32);
void func_00174b28(BD_VALUE* bd);  // 0x00174b28: definition moved into src/anon/unit_00171e58.cpp

void func_001d2930(s32, s32);
void func_0018e108(s32, s32);
void func_001a5880(s32, s32, s32);
void func_00175328(BD_VALUE* bd);  // 0x00175328: definition moved into src/anon/unit_00171e58.cpp

// 0017fdf8: moved to src/yasui/libys/motion.cpp

struct S182 {
    u32 value;
    u32 type;
    u32 arg;
};
// 00182838 YS::UNIT::UNIT: moved to src/anon/unit_00182780.cpp

u8 func_0019c898(u32);
u32 func_0016a070();
u32 func_0019c8a8();  // 0x0019c8a8: definition moved into src/anon/unit_0019ba60.cpp

void func_001a8bb8(u8* p);  // 0x001a8bb8: definition moved into src/anon/unit_001a8618.cpp

u32 func_001a8f10();  // arg_map_0_1_2
void func_001a8b38(u32);
void func_001a90f0();  // 0x001a90f0: definition moved into src/anon/unit_001a8618.cpp

extern u32 D_00350cc8;
extern u32 D_00350cd0;
extern u32 D_00350ccc;
void func_001aeae0();  // 0x001aeae0: definition moved into src/anon/unit_001ada38.cpp

s32 func_001a35f8(u16, u8);
u32 func_001d4528(u8* p);  // 0x001d4528: definition moved into src/anon/unit_001d3c08.cpp

// Append 4 (unaligned) bytes to a write cursor.
struct Bytes4 {
    u8 b[4];
};
struct Writer {
    u8 pad[12];
    Bytes4* cur;
};
void func_001da3d8(Writer* w, Bytes4* src) { *w->cur++ = *src; }

void func_0021fe28(u32);
void func_001fba88(u32 base, const u32* info) { func_0021fe28(base + **(const u32* const*)(info + 3) + 160); }

// dst.xy = a.xy + b.xy (VU0).
void func_00222710(void* dst, void* a, void* b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tlqc2 $vf3, 0(%0)\n\t"
                 "vadd.xy $vf3, $vf1, $vf2\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                 : : "r"(dst), "r"(a), "r"(b) : "memory");
}

// 2D length sqrt(x*x + y*y) (VU0).
f32 func_002229d8(void* v) {
    f32 r;
    asm volatile(".set noreorder\n\tlqc2 $vf10, 0(%1)\n\tvmul.xy $vf10, $vf10, $vf10\n\t"
                 "vaddx.y $vf10, $vf10, $vf10x\n\tvsqrt Q, $vf10y\n\tvwaitq\n\t"
                 "cfc2 $2, $vi22\n\tmtc1 $2, %0\n\t.set reorder"
                 : "=f"(r) : "r"(v) : "$2");
    return r;
}

extern u8 D_0035dadc;
extern u32 D_0035dae0;
void func_00224950(u32 a);  // 0x00224950: definition moved into src/anon/unit_00224780.cpp

// Writes the current id (0 when unset, -1) and returns whether it was set.
extern s32 D_0035eb4c;
s32 func_0023d300(s32* out) {
    bool none = D_0035eb4c == -1;
    s32 v = none ? 0 : D_0035eb4c;
    *out = v;
    return !none;
}

u32 func_00257770();
void func_0028da70(u32, u32);
void func_00265780();  // 0x00265780: definition moved into src/anon/unit_00265580.cpp

extern u32 D_0035f264;
u8 func_00139d78(u32);
u32 func_002806a0();  // 0x002806a0: definition moved into src/anon/unit_0027f2b0.cpp

extern u32 D_0035f28c;
extern u8 D_0035f299;
void func_00281e70(u32 a);  // 0x00281e70: definition moved into src/anon/unit_00281cf0.cpp

u32 func_002766d0();
void func_0028dac8(u32, u32);
void func_0029e050();  // 0x0029e050: definition moved into src/anon/unit_0029d008.cpp

u8* func_002b23e0();  // list_entry_by_index_checked
void func_002ac678(u8);
void func_002b3420() { func_002ac678(func_002b23e0()[2]); }

u32 func_002c6218();
void func_002c6280(u32, u32);
void func_002c0700();  // 0x002c0700: definition moved into src/anon/unit_002bebd0.cpp

void func_002eac70(f32, f32, f32, f32);
void func_002e7b88(f32* v) { func_002eac70(v[0], v[1], v[2], v[3]); }

void func_002e9a00(s32, s32);
void func_002e7be0(BD_VALUE* bd) {
    BD_VALUE a = bd[0];
    func_002e9a00(a.i, bd[1].i);
}

struct VObj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
};
void func_002ecdb0(VObj* o) { o->v9(); }

// dst = a * b, componentwise (VU0).
void sceVu0MulVector(void* dst, void* a, void* b) {
    asm volatile("lqc2 $vf4, 0(%1)\n\tlqc2 $vf5, 0(%2)\n\tvmul.xyzw $vf6, $vf4, $vf5\n\tsqc2 $vf6, 0(%0)"
                 : : "r"(dst), "r"(a), "r"(b) : "memory");
}

// 16-byte copy.
void sceVu0CopyVector(void* dst, void* src) {  // memcpy16
    asm volatile("lq $6, 0(%1)\n\tsq $6, 0(%0)" : : "r"(dst), "r"(src) : "$6", "memory");
}

// Returns 1 when interrupts are disabled (Status.IE clear).
s32 func_003060f0() {  // ee_intr_disabled
    s32 r;
    asm volatile("mfc0 %0, $12" : "=r"(r));
    return (r ^ 1) & 1;
}

void func_003053d0();
void iDisableIntc() {
    func_003053d0();
    asm volatile("sync");
}

// libkernel: enable interrupts, return whether EIE was already set.
// The mfc0/lui/and sequence is in asm: this area is hand-written / other-compiler
// code that uses v0/v1 as scratch.
s32 EIntr() {  // ee_intr_get_enable
    register u32 r asm("$2");
    register u32 m asm("$3");
    asm volatile("mfc0 %0, $12\n\tlui %1, 1\n\tand %0, %0, %1" : "=r"(r), "=r"(m));
    asm volatile("ei");
    return r != 0;
}

}  // extern "C"

namespace YS {
void trap_prize_appear_tr(BD_VALUE* bd);  // 0x001751f8: definition moved into src/anon/unit_00171e58.cpp
void trap_attack_set_hitmark_pos(BD_VALUE* bd);  // 0x0018fc20: definition moved into src/anon/unit_0018f140.cpp
}  // namespace YS

struct Vec3 {
    f32 x, y, z;
};
void wtarget_001efd38(u32 a0, u32 a1, u32, u32) {
    a0 += (*(u32**)(a1 + 12))[1];
    Vec3* v = (Vec3*)(a0 + 160);
    v->x = v->y = v->z = 0.0f;
}

extern "C" void func_00267620();
extern u32 D_0035f0ec;
// 0x002675e8: definition moved into src/anon/unit_00265580.cpp
