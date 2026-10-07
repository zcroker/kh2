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

// One-shot latch: returns the flag, setting it to 1 the first time.
extern s32 D_0032ba84;
s32 func_001041c0() {
    s32 v = D_0032ba84;
    if (v == 0) {
        D_0032ba84 = 1;
        v = 1;
    }
    return v;
}

// Push onto a downward-growing stack of words.
extern s32 D_0032bb28;
extern u32 D_003a7b60[];
void func_001056e8(u32 value) { D_003a7b60[--D_0032bb28] = value; }

// Bump allocator: returns the current pointer, advances it by size rounded up to 4.
extern u32 D_00340ea8;
u32 func_0010abc8(u32 size) {
    u32 p = D_00340ea8;
    D_00340ea8 = p + ((size + 3) & ~3);
    return p;
}

extern u32 D_00347d50;
extern u8 D_00347d54;
extern u8 D_00347d55;
void func_00136a98() {
    D_00347d50 = 0;
    D_00347d54 = 0;
    D_00347d55 = 0;
}

void func_00102c18(s32, s32, void (*)(void*));
void func_00137250(void*);
void func_00136fa8() { func_00102c18(1, 300000, func_00137250); }

// Copy the RGBA bytes at +0xe8 to +0x0c.
void func_00147c78(u32, u8* p) {
    u8 r = p[232], g = p[233], b = p[234], a = p[235];
    p[12] = r;
    p[13] = g;
    p[14] = b;
    p[15] = a;
}

void func_00139948(s32);
void func_00139ba0(s32);
void func_00154af0(u8* p) {
    p[15584] = 1;
    func_00139948(6);
    func_00139ba0(6);
}

// Copy a 16-byte vector into D_0034a9a0 unless it is the source.
extern u8 D_0034a9a0[];
void func_00158920(u8* src) {
    if (src != D_0034a9a0)
        asm volatile("lq $8, 0(%0)\n\tsq $8, 0(%1)" : : "r"(src), "r"(D_0034a9a0) : "$8", "memory");
}

void func_0014e0d8(void*);
void func_001024a8(void*);
void func_00161f10(void* p) {
    func_0014e0d8(p);
    func_001024a8(p);
}

extern s16 D_0034c874;
extern s16 D_0034c876;
void func_00166c80(s16 a, s16 b) {
    D_0034c874 = a;
    D_0034c876 = b;
}

extern f32 D_004f5268;
extern f32 D_004f526c;
extern f32 D_004f5270;
void func_00167638(f32 x, f32 y, f32 z) {
    D_004f5268 = x;
    D_004f526c = y;
    D_004f5270 = z;
}

void func_001846a0(u32, s32, f32);
void func_00173e10(BD_VALUE* bd) {
    BD_VALUE a = bd[0];
    s32 b = bd[1].i;
    u32 obj = ((u32*)a.p)[1];
    func_001846a0(obj, b, bd[2].f);
}

void func_001b1c10(s32, f32);
void func_00174b28(BD_VALUE* bd) {
    BD_VALUE a = bd[0];
    func_001b1c10(a.i, bd[1].f);
}

void func_001d2930(s32, s32);
void func_0018e108(s32, s32);
void func_001a5880(s32, s32, s32);
void func_00175328(BD_VALUE* bd) {
    BD_VALUE a = bd[0];
    func_001a5880(a.i, bd[1].i, bd[2].i);
}

// Zero the 16-byte vector at +0xa0 (VU0).
void func_0017fdf8(u8* p) {
    asm volatile(".set noreorder\n\tvsub.xyzw $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(p + 160) : "memory");
}

struct S182 {
    u32 value;
    u32 type;
    u32 arg;
};
void func_00182838(S182* p, u32 value, u32 arg, u8 flag) {
    p->value = value;
    p->type = 1;
    p->arg = arg;
    if (flag) p->type = 3;
}

u8 func_0019c898(u32);
u32 func_0016a070();
u32 func_0019c8a8() { return func_0019c898(func_0016a070()); }

void func_001a8bb8(u8* p) {
    p[0] = 0;
    p[1] = 18;
    p[2] = 18;
    p[3] = 18;
}

u32 func_001a8f10();
void func_001a8b38(u32);
void func_001a90f0() { func_001a8b38(func_001a8f10()); }

extern u32 D_00350cc8;
extern u32 D_00350cd0;
extern u32 D_00350ccc;
void func_001aeae0() {
    D_00350cc8 = 0;
    D_00350cd0 = 0;
    D_00350ccc = 0;
}

s32 func_001a35f8(u16, u8);
u32 func_001d4528(u8* p) { return func_001a35f8(*(u16*)(p + 42), p[1]) > 0; }

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
void func_00224950(u32 a) {
    D_0035dadc = 1;
    D_0035dae0 = a;
}

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
void func_00265780() { func_0028da70(func_00257770(), 141); }

extern u32 D_0035f264;
u8 func_00139d78(u32);
u32 func_002806a0() { return func_00139d78(D_0035f264 + 896); }

extern u32 D_0035f28c;
extern u8 D_0035f299;
void func_00281e70(u32 a) {
    D_0035f28c = a;
    D_0035f299 = 0;
}

u32 func_002766d0();
void func_0028dac8(u32, u32);
void func_0029e050() { func_0028dac8(func_002766d0() + 18528, 6); }

u8* func_002b23e0();
void func_002ac678(u8);
void func_002b3420() { func_002ac678(func_002b23e0()[2]); }

u32 func_002c6218();
void func_002c6280(u32, u32);
void func_002c0700() { func_002c6280(func_002c6218(), 1); }

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
void func_002f3f28(void* dst, void* a, void* b) {
    asm volatile("lqc2 $vf4, 0(%1)\n\tlqc2 $vf5, 0(%2)\n\tvmul.xyzw $vf6, $vf4, $vf5\n\tsqc2 $vf6, 0(%0)"
                 : : "r"(dst), "r"(a), "r"(b) : "memory");
}

// 16-byte copy.
void func_002f3f88(void* dst, void* src) {
    asm volatile("lq $6, 0(%1)\n\tsq $6, 0(%0)" : : "r"(dst), "r"(src) : "$6", "memory");
}

// Returns 1 when interrupts are disabled (Status.IE clear).
s32 func_003060f0() {
    s32 r;
    asm volatile("mfc0 %0, $12" : "=r"(r));
    return (r ^ 1) & 1;
}

void func_003053d0();
void func_003062c0() {
    func_003053d0();
    asm volatile("sync");
}

// libkernel: enable interrupts, return whether EIE was already set.
// The mfc0/lui/and sequence is in asm: this area is hand-written / other-compiler
// code that uses v0/v1 as scratch.
s32 func_0030ee00() {
    register u32 r asm("$2");
    register u32 m asm("$3");
    asm volatile("mfc0 %0, $12\n\tlui %1, 1\n\tand %0, %0, %1" : "=r"(r), "=r"(m));
    asm volatile("ei");
    return r != 0;
}

}  // extern "C"

namespace YS {
void trap_prize_appear_tr(BD_VALUE* bd) {
    BD_VALUE a = bd[0];
    func_001d2930(a.i, bd[1].i);
}
void trap_attack_set_hitmark_pos(BD_VALUE* bd) {
    BD_VALUE a = bd[0];
    func_0018e108(a.i, bd[1].i);
}
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
void Tz::CmEquip::Init() {
    D_0035f0ec = 0;
    func_00267620();
}
