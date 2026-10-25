#include "../common/types.h"

extern "C" {
f32 func_00106558(f32);
u32 func_001c8cd8(void);
void func_00119e60(u32, u32);
void func_001391c8(u32, u32, u32);
void func_0013b128(u32);
u32 func_00140df0(u32);
void func_00140e30(u32, u32);
void func_001a9350(u32);
void func_0016c358(u32);
f32 func_002f8ad0(f32, f32);
u32 func_0016b740(u32);
void func_00188470(u32, u32, f32);
void func_001d6a80(u32);
void func_00176ec8(u32);
void func_00180ce0(u32);
u8 func_0017ee68(u32);
void func_001b50e0(u32, u32, f32, u32);
void func_00191c30(f32);
u8 func_0019f2a8(u32, u32);
void func_002f7e60(void);
void func_002f71b0(u32);
void func_002f79c8(u32);
void func_0017c430(u32);
void func_0016bd60(u32, u32);
u32 func_001a36e0(u32);
u32 func_001a80c8(u32);  // table24_find_by_id
void func_001b8e88(u32);
void func_001dc9e0(u32);
u32 func_001e6cd0(u32);
void func_001dcdb8(void);
void func_001de808(void);
void func_00229b28(u32, u32, u32, u32, f32);
void func_002340f0(u32, u32, u32, u32, u32, u32);
u32 func_002f35e8(u32);
void func_002f3918(u32, void*);
u32 func_002537c8(u32);
void func_0023fa08(u32, u32);
void func_00257388(u32, u32);
void func_002571e0(u32);
void func_00287cc0(u32);
u8 func_00139d78(u32);
void func_002ba3e8(u32, u32, u32, u32, u32, s32*, u32, u32);
void func_002b70b8(u32, u32, u32);
u32 func_0010c7e8(u32);
void func_002eb990(u32, u32, f32);

extern u8* D_00352130;
extern f32 D_01c61968;
extern u32 D_0035037c;
extern u32 D_01d48db8[];
extern s32 D_01d4934c;
struct Blob10 { u16 h[5]; };
extern Blob10 D_01d5a970;
extern u32 D_01d9e340;
struct ZeroPair { u32 a, b; };
extern ZeroPair D_01d9e348;
extern char D_0035e3f0[];
extern u8* D_0035ec94;
extern u32 D_003718d0[11];
extern u32 D_0035f074;
extern u32 D_0035f334;
extern char D_0035f3a8[];
extern u32 D_0035f21c;

struct VObj { void** vtbl; };
// Script-style argument block: {ptr, int, float, int}
struct Args { u32 a; u32 b; f32 c; u32 d; };

// Symbol table names this with eight u32 params; the body takes floats in f12/f13.
f32 func_001065a8(f32 a, f32 b) asm("_Z13func_001065a8jjjjjjjj");
f32 func_001065a8(f32 a, f32 b) {
    return a + func_00106558(b - a);
}

void func_00119c88(u32 a0) {
    func_00119e60(a0, func_001c8cd8());
}

// Virtual call (slot 15) on the object at +20, forwarding the field at +260.
void func_0011c7c8(u8* a0, u32 a1) {
    VObj* o = *(VObj**)(a0 + 20);
    ((void (*)(VObj*, u32, u32))o->vtbl[15])(o, *(u32*)(a0 + 260), a1);
}

void func_0013b1a0(u32 a0) {
    func_001391c8(a0, 5302, 1);
    func_0013b128(a0);
}

// dk CannonCamera::create
void cannon_camera_create(u32 obj) asm("_ZN2dk12CannonCamera6createEPN2YS3OBJE");
void cannon_camera_create(u32 obj) {
    u32 c = func_00140df0(obj);
    *(u32*)(c + 64) = 8;
    func_00140e30(c, 3);
}

void func_0016a328(u32 a0) {
    func_001a9350(a0 + 1952);
    func_0016c358(a0);
}

// Stores f(x, z) of the vector at a1 into +1644 (e.g. a heading angle).
void func_0016b010(u8* a0, f32* a1) {  // obj_set_float1644_from_pair
    *(f32*)(a0 + 1644) = func_002f8ad0(a1[0], a1[2]);
}

// trap_obj_hide: virtual slot 17 on the trap object.
void trap_obj_hide_impl(u32* bd) asm("_ZN2YS13trap_obj_hideEP8BD_VALUE");
void trap_obj_hide_impl(u32* bd) {
    VObj* o = *(VObj**)(*bd + 4);
    ((void (*)(VObj*))o->vtbl[17])(o);
}

void trap_obj_search_by_entry_impl(u32* bd) asm("_ZN2gm24trap_obj_search_by_entryEP8BD_VALUE");
void trap_obj_search_by_entry_impl(u32* bd) {
    u32* out = (u32*)bd[0];
    out[1] = func_0016b740(bd[1]);
}

void func_00173e38(u32* a0) {
    func_00188470(*(u32*)(a0[0] + 4) + 768, a0[1], *(f32*)&a0[2]);
}

void func_00179e18(u8* a0) {
    func_001d6a80(*(u32*)(a0 + 2876));
    *(u32*)(a0 + 2888) = 0;
    func_00176ec8((u32)a0);
}

u32 func_0017eb68(u32 a0) {
    func_00180ce0(a0);
    return func_0017ee68(a0);
}

// True when the entry at +320 is set and its id (+20) is in [140, 151).
bool func_00186d18(u8* a0) {  // check_size140to150
    u32* p = (u32*)(a0 + 320);
    if (*p == 0) return false;
    s32 v = p[5];
    if (v < 140) return false;
    if (v < 151) return true;
    return false;
}

void func_0018fde0(Args* a) {
    u32 p = a->a;
    func_001b50e0(p, a->b, a->c, a->d != 0);
}

// 00191bf0: moved to src/yasui/libys/status.cpp

u32 func_001979d8(u32 a0) {
    return func_0019f2a8(D_0035037c + 12, a0);
}

void func_001ae650(void) {
    func_002f7e60();
    func_002f71b0(0);
    func_002f79c8(0);
}

void func_001b2c18(u32 a0, u32 a1) {
    func_0017c430(a1);
    func_0016bd60(a1, 20);
}

// COMMAND_ELEM GetForm
void command_elem_get_form(u32 a0) asm("_ZN2YS12COMMAND_ELEM7GetFormEi");
void command_elem_get_form(u32 a0) {
    u32 p = func_001a80c8(func_001a36e0(a0));  // table24_find_by_id
    func_001b8e88(*(u16*)(p + 16));
}

// Sets control-off bit i in the global bitset.
void control_off(s32 i) asm("_ZN2YS3OBJ10ControlOffEi");
void control_off(s32 i) {
    D_01d48db8[(u32)i >> 5] |= 1 << (i & 31);
}

// Hands out a new combo group id, wrapping back to 256.
s32 new_combo_group(void) asm("_ZN2YS12ATTACK_CHECK13NewComboGroupEv");
s32 new_combo_group(void) {
    if (++D_01d4934c > 0x10000000) D_01d4934c = 256;
    return D_01d4934c;
}

void func_001c90c0(u32 a0, u32 a1) {
    func_0017c430(a1);
    func_0016bd60(a1, 20);
}

Blob10* func_001cd520(Blob10* p) {
    *p = D_01d5a970;
    return p;
}

// Pops one entry: --count; return base + scale * table[count].
s32 func_001db888(s32* a0) {  // record_index_calc
    a0[2]--;
    return a0[3] + a0[5] * ((s32*)a0[4])[a0[2]];
}

u32 effect_pos(u32 self) asm("_ZN3ryj6EFFECT3posEv");
u32 effect_pos(u32 self) {
    func_001dc9e0(self);
    return func_001e6cd0(*(u32*)(self + 28));
}

void func_001de7d8(u32 a0) {
    D_01d9e340 = a0;
    func_001dcdb8();
    D_01d9e348.a = 0;
    D_01d9e348.b = 0;
    func_001de808();
}

void func_001e01b8(u32 a0) {
    VObj* o = (VObj*)D_01d9e340;
    ((void (*)(VObj*, u32))o->vtbl[1])(o, a0);
}

void func_00229d40(u8* a0) {
    func_00229b28((u32)a0, 1, 200, 0, (f32)*(s32*)(a0 + 2972));
}

void func_00234590(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0) {
    func_002340f0(a0, 0, a1, a2, a3, t0);
}

void func_002367a0(void) {
    func_002f3918(func_002f35e8(2), D_0035e3f0);
}

// ORs bits into the flags of entry i (32-byte records); i < 0 means current.
void func_00240fd8(s32 i, u32 bits) {
    if (i < 0) i = (s8)D_0035ec94[1];
    *(u32*)(D_0035ec94 + i * 32 + 8) |= bits;
}

// Index of v in an 11-entry table, or 11.
u32 func_00243190(u32 v) {
    u32 i;
    for (i = 0; i < 11; i++)
        if (D_003718d0[i] == v) break;
    return i;
}

void func_00258a88(void) {
    func_0023fa08(D_0035f074, func_002537c8(0));
}

void func_002691c8(void) {
    func_00257388(0x846a, 0);
    func_002571e0(1);
    func_00287cc0(0);
}

void func_00276410(void) {
    func_0023fa08((u32)D_0035f3a8, func_002537c8(3));
}

u32 func_00276df8(void) {
    u32 p = D_0035f21c;
    if (p == 0) return 0;
    return func_00139d78(p + 3812);
}

void func_00288610(void) {
    func_0023fa08(D_0035f334, func_002537c8(0));
}

void func_002ba3b8(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 t2) {
    s32 x = -1;
    func_002ba3e8(a0, a1, a2, a3, t0, &x, t1, t2);
}

void func_002ba948(void) {
    func_002b70b8(0, 0x3000, 240);
    func_002b70b8(1, 0x3000, 240);
}

void func_002e8220(Args* a) {
    u32 p = *(u32*)(a->a + 4);
    func_002eb990(p, a->b, a->c);
}

void func_002f0798(u32* a0) {
    VObj* o = (VObj*)func_0010c7e8(*(u32*)(a0[0] + 4));
    ((void (*)(VObj*))o->vtbl[10])(o);
}

// d = m translated by v: copies rows 0-2, row 3 = m.row3 + v (xyz).
// 128-bit moves and the VU0 macro op are written as asm.
void func_002f3f58(void* d, void* m, void* v) {
    asm volatile(
        "lqc2 $vf4, 0(%2)\n\t"
        "lqc2 $vf5, 48(%1)\n\t"
        "lq $7, 0(%1)\n\t"
        "lq $8, 16(%1)\n\t"
        "lq $9, 32(%1)\n\t"
        "vadd.xyz $vf5, $vf5, $vf4\n\t"
        "sq $7, 0(%0)\n\t"
        "sq $8, 16(%0)\n\t"
        "sq $9, 32(%0)\n\t"
        "sqc2 $vf5, 48(%0)"
        : : "r"(d), "r"(m), "r"(v) : "$7", "$8", "$9", "memory");
}
}
