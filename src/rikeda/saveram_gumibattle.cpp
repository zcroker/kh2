#include "saveram_gumibattle.hpp"

// ryj::SAVERAM_GUMIBATTLE (gumi battle records in the save data) and the ryj gumi traps
// (0x1e0808-0x1e0cb8). Linked unit; the trap table is .data at 0x352b88.

extern "C" {
u32 func_00190128(...);              // YS::TARGET::TARGET
u32 func_00190878(...);              // YS::TARGET::set_obj
void func_001902a8(u32 a0, u32 a1);
void wtarget_0016b070(void*, s32) asm("_Z16wtarget_0016b070jjjj");
void func_001e29e0(void*);
void func_001e2a50(BD_VALUE*);
void func_001e2a78(BD_VALUE*);
void func_001e2aa0(BD_VALUE*);
void func_001e2ac0(BD_VALUE*);
}

namespace ryj {

SAVERAM_GUMIBATTLE::SAVERAM_GUMIBATTLE() {
    s32 t6 = 19;
    u32 t7 = (u32)this + 3712;
    do {
        *(u32*)(t7 + 0) = 0;
        t6 = t6 - 1;
        t7 = t7 + 4;
    } while (t6 >= 0);

    *(u32*)((u32)this + 3792) = 0;
    *(u32*)((u32)this + 3796) = 0;
    *(u32*)((u32)this + 3800) = 0;
    *(u32*)((u32)this + 3804) = 0;
    func_001e08c8((u8*)this);
    func_001e0958((GB_REC*)this);
}

}  // namespace ryj

extern "C" {

struct Adj1e0 { s32 off; s32 add; };
void func_001e08c8(u8* p) {
    Adj1e0 t[10] = {
        { 3, 10 }, { 11, 1 }, { 20, 4 }, { 30, 4 }, { 35, 2 },
        { 50, 2 }, { 53, 2 }, { 59, 3 }, { 210, 1 }, { 0, 0 },
    };
    s32 i;
    for (i = 0; t[i].off; i++) {
        s32 a = t[i].add;
        u8* b = p + 3456;
        b[t[i].off] += a;
    }
}

// Number a 9x3 grid of 64-byte cells: row index and 1-based column.
void func_001e0958(GB_REC* p) {
    s32 i, j;
    for (i = 0; i < 9; i++) {
        for (j = 0; j < 3; j++) {
            p->a = i;
            p->b = j + 1;
            p++;
        }
    }
}

}

void func_001e0998(void* self) {}

namespace ryj {

GB_REC* SAVERAM_GUMIBATTLE::get_record(s32 a0, s32 a1, bool a2) {
    a1--;
    s32 i = a0 * 3 + a1;
    if (a2) i += 27;
    return &((GB_REC*)this)[i];
}

f32 SAVERAM_GUMIBATTLE::get_all_treasure_complete(void) {
    f32 sum = 0.0f, cnt = 0.0f;
    s32 i, j;
    for (j = 0; j < 9; j++)
        for (i = 1; i < 4; i++) {
            cnt += 100.0f;
            sum += get_record(j, i, false)->rate;
        }
    return sum / cnt * 100.0f;
}

bool SAVERAM_GUMIBATTLE::is_treasure_complete(void) {
    return (s32)get_all_treasure_complete() == 100;
}

void trap_obj_target_radius(BD_VALUE* bd) {
    u8 spv[64];
    u32 a0 = (u32)bd;
    u32 s1 = a0;
    u32 t7 = *(u32*)(a0 + 0);
    u32 s0 = *(u32*)(t7 + 4);
    func_00190128((u32)&spv[0]);
    func_00190878((u32)&spv[0], s0, 0);
    *(u32*)(&spv[44]) = 0;
    func_001902a8((u32)&spv[0], (u32)&spv[32]);
    f32 f0 = *(f32*)(&spv[36]);
    *(f32*)(s1 + 0) = f0;
}

void trap_obj_set_xyzrot(BD_VALUE* bd) {
    wtarget_0016b070(*(void**)((char*)bd[0].p + 4), bd[1].i);
}

static void trap_1e0b40(BD_VALUE* bd) {
    u8* o = *(u8**)(*(u8**)((char*)bd[0].p + 4) + 0xb44);
    bd[0].i = (*(u32*)(o + 8) >> 2) & 1;
}

void trap_player_push_ability_button(BD_VALUE* bd) {
    func_001e29e0(*(void**)((char*)bd[0].p + 4));
}

static void trap_1e0b80(BD_VALUE* bd) { func_001e2aa0(bd); }
static void trap_1e0b98(BD_VALUE* bd) { func_001e2ac0(bd); }
static void trap_1e0bb0(BD_VALUE* bd) { func_001e2a50(bd); }
static void trap_1e0bc8(BD_VALUE* bd) { func_001e2a78(bd); }

}  // namespace ryj


namespace kn {
struct FVector {
    f32 x, y, z, w;
    FVector() {}
    ~FVector() {}
} __attribute__((aligned(16)));

// 4x4 matrix; the copy is the VU0 library's hand-written 128-bit lq/sq copy.
struct FMatrix {
    f32 m[4][4];
    FMatrix() {}
    FMatrix(const FMatrix& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
} __attribute__((aligned(16)));
}  // namespace kn

extern "C" kn::FMatrix D_003511d0;

static kn::FVector s_pos;

namespace ryj {

// Applies the matrix at 0x3511d0 to a point (VU0 macro code, hand-written in the original).
static void trap_1e0be0(BD_VALUE* bd) {
    kn::FMatrix m(D_003511d0);
    asm volatile("lqc2 $vf5, 0(%1)\n\t"
                 "lqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 16(%2)\n\tlqc2 $vf3, 32(%2)\n\tlqc2 $vf4, 48(%2)\n\t"
                 "vmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\t"
                 "vmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\t"
                 "sqc2 $vf5, 0(%0)"
                 : : "r"(&s_pos), "r"(bd[0].p), "r"(&m) : "memory");
    bd[0].p = &s_pos;
}

struct TRAP { void (*fn)(BD_VALUE*); u32 flags; };

}  // namespace ryj

extern "C" {
ryj::TRAP D_00352b88[9] = {
    { ryj::trap_obj_target_radius, 0x40000001 },
    { ryj::trap_1e0b40, 0x40000001 },
    { ryj::trap_obj_set_xyzrot, 2 },
    { ryj::trap_player_push_ability_button, 1 },
    { ryj::trap_1e0b80, 0 },
    { ryj::trap_1e0b98, 0 },
    { ryj::trap_1e0bb0, 0 },
    { ryj::trap_1e0bc8, 0 },
    { ryj::trap_1e0be0, 0x40000001 },
};
}
