#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));

typedef void (*VF)(void*);

// 128-bit vector with an asm self-checked assignment (non-POD: returned via hidden pointer)
struct Vec128 {
    u128 q;
    Vec128() {}
    Vec128(const Vec128& o) : q(o.q) {}
    Vec128& operator=(const Vec128& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};

extern "C" {

extern void* D_0032b91c;

/* ---- 00113338 ---- */
void* func_001050d8(u32);
void YS__ATTACK__ATTACK_2(void*, u32, u32, u32, u32, s32, u32);
s32 func_001130b0(u128*, u32, void*, u32);
void func_0018f028(void*);

s32 kn__Friend__strike_2(u32 a0, u128* a1, u32 a2, u32 a3, u32 a4, u32 a5);  // 0x00113338: definition moved into src/anon/unit_001117d8.cpp

/* ---- 00137890 ---- */
extern u8* D_00347d5c;
u32 func_0013a7e8(u32);
void func_00138d60(void*, u32, u32, void*, u32, u32, u32);

void func_00137890(u8* p, u32 a1, u32 a2, u32 a3);  // 0x00137890: definition moved into src/anon/unit_001374c8.cpp

/* ---- 0013d2d0 ---- */
struct Pair1 { u32 a, b; };
extern Pair1 D_00348578[];
u8* func_0013cb80(void);  // get_global_358050
s32 func_0013cb90(void);
u32 func_0013cb30(void);
void dk__Sprite__create(void*, u32, u32, void*, u32, u32);
void func_00138c40(void*, u32, u32);
f32 func_0013b2a8(void*);  // mul_float684_692
void func_00138d48(void*, f32, f32, f32, f32);
void func_0013d1d0(void*);

void func_0013d2d0(u8* p);  // 0x0013d2d0: definition moved into src/anon/unit_0013a8b8.cpp

/* ---- 00146c08: box vs 5 planes (VU0 dot product) ---- */
static inline bool front2(f32 d) { return 0.0f <= d; }
static inline f32 dot1(f32* v, f32* pl) {
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
            : "=f"(d) : "r"(v), "r"(pl) : "$8", "memory");
    return d;
}
s32 func_00146c08(f32* pl, f32* box);  // 0x00146c08: definition moved into src/anon/unit_00145600.cpp

/* ---- 001519f8 ---- */
s32 func_0023aa98(void*);
f32 func_00151690(void*);  // scale_ratio_2888_2880
void YI__SEQUENCE__SetScaleX(void*, f32);  // obj_set_float312_and_flags
void func_00138c68(void*, s32, u32);

void func_001519f8(u8* p);  // 0x001519f8: definition moved into src/anon/unit_0014ecb8.cpp

/* ---- 0015c0f8 ---- */
struct Alloc1;
typedef void* (*AllocFn)(Alloc1*, u32, u32);
struct Alloc1 { AllocFn* vt; };
struct Holder1 { u32 f[5]; Alloc1* alloc; };
extern Holder1* D_00347f80;
extern void* D_0034af08;
extern void* D_0034ae80;
extern s32 D_0034ece0;
void func_0031daf0(void*);
void* func_001492e8(void*, s32);
void func_0015bbc8(void*, void*);

void ctarget0_0015c0f8(void* p) asm("_Z17ctarget0_0015c0f8v");
void ctarget0_0015c0f8(void* p);  // 0x0015c0f8: definition moved into src/anon/unit_0015bab8.cpp

/* ---- 00168218: pick the idle node with the smallest key ---- */
struct Node2 { Node2* next; u32 busy; u8 data[1]; };
extern Node2* D_0034d840;
void DIntr(void);
void EIntr(void);  // ee_intr_get_enable
u32 func_001ae1e0(void*);
static inline Node2* Next2(Node2* n) { if (!n) return D_0034d840; return n->next; }

// 00168218: moved to src/yasui/libys/file.cpp

/* ---- 00168548 ---- */
extern u8 D_01f18000[];
extern u8 D_01fc0000[];
void func_002fde18(void*, u32, u32);
extern Alloc1* D_0032b91c_a asm("D_0032b91c");
void func_00168958(void*, u32, u32);  // obj_init_name_string

// 00168548: moved to src/yasui/libys/file.cpp

/* ---- 001849d8 ---- */
struct Bits3 { u64 lo:3; u64 kind:4; u64 mid:26; u64 dirty:1; };
struct Ent3 { u8 pad[1528]; f32 val; u32 pad2; union { u64 raw; Bits3 b; } u; };
void* YS__OBJ__get_pos(Ent3*);  // obj_get_attach_or_alt
s32 func_001a7610(void*, f32*, s32, f32, f32);
static inline bool clean3(Ent3* e) { return !e->u.b.dirty; }

// 001849d8: moved to src/anon/unit_00183088.cpp

/* ---- 00191ab8 ---- */
void* func_00176b20(s32);
s32 YS__OBJ__is_exist(void*);
s32 YS__WEAPON__is_equip(void*);

// 00191ab8: moved to src/yasui/libys/status.cpp

/* ---- 00191f78 ---- */
struct Slot4 { void* obj; u32 val; };
extern Slot4 D_01c61970[];
struct Prop4 { u32 f0, f4, val; };
Prop4* func_00168b38(void*, u32, u32);  // entry_array_find_nth
void func_001aadb0(u32);
static inline bool has4(Prop4* p) { return p && p->val; }

// 00191f78: moved to src/yasui/libys/message.cpp

/* ---- 0019a610 ---- */
struct Rec5 { s16 h[5]; };
extern Rec5 D_0032bb00;
extern u8 D_0032bae0;
s32 func_001991a8(u32, u32);
void AREA__MapJump(void*, u32, u32, u32, u32);
union Obj5b { struct { u32 f0, f4; u16* info; } s; s16 h[6]; };

void func_0019a610(Obj5b* o, Rec5* src);  // 0x0019a610: definition moved into src/anon/unit_00199688.cpp

/* ---- 0019bb98 ---- */
f32 func_0016a0a0(void*);
s32 func_001c0cd8(void*);
s32 YS__OBJ__is_stop(void*);

s32 YS__OBJ__is_heavy(u8* p);  // 0x0019bb98: definition moved into src/anon/unit_0019ba60.cpp

/* ---- 001c2858 ---- */
// 001c2858: moved to src/anon/unit_001c0638.cpp
void func_001c2858(f32* o, void* a, void* b, s32 n);

/* ---- 001c7fb8 ---- */
extern void* D_00351e18[];
extern u8* D_01d49960[2];
void func_0010b978(void*);
void func_001e02a0(void*, void*);
void func_0010c7f0(void*);

// 0x1c7fb8: moved to src/yasui/libys/summon.cpp

/* ---- 001ce1a0 ---- */
extern u32 D_00352134;
extern u32 D_00352130;
extern u32 D_01d5b9d0, D_01d5b9d4, D_01d5b9d8, D_01d5b9dc;
extern char D_0036e2c0[], D_0036e2c8[], D_0036e2d0[], D_0036e2d8[], D_0036e2e0[];
u32 func_001ce248(u32, const char*);
u32 func_001ce2a0(u32, u32, u32);

// 001ce1a0: moved to src/anon/unit_001cd660.cpp
void YS__PREF__Init(u32 a);

/* ---- 001dde40: unlink n from the list ---- */
struct LNode { u32 used; u32 pad[4]; LNode* next; };
struct LList { LNode* head; LNode* tail; };
extern LList D_01d9e348;
s32 func_00321cb0(void*, void*);
void func_001de450(void*);

void ryj__PAX__ensure(LNode* n);  // 0x001dde40: definition moved into src/anon/unit_001ddcf0.cpp

/* ---- 00227950 ---- */
struct E11 { s32 kind; s32 sub; u8 off; u8 pad[3]; s32 key; u8 rest[68]; };
extern E11* D_0035dcf0;
void func_002278e0(E11*);
void func_001024a8(void*);

void func_00227950(u8* p);  // 0x00227950: definition moved into src/anon/unit_00224780.cpp

/* ---- 0022e288 ---- */
struct E12 { u32 f0; s32 id; u32 f8; u32 fc; u8 node[36]; };
union U12 { E12* p; s32 i; };
extern U12 D_0035dcf4;
s32 func_001de568(void*);

void sa__EVENT__leaveAllEffect(void);  // 0x0022e288: definition moved into src/anon/unit_0022d358.cpp

/* ---- 0023ec48: out = obj->mtx(+128) * m (VU0) ---- */
void func_0011d6c0(u32, u32, f32*);
f32* func_0023ec48(f32* out, u8* obj, u32 a2);  // 0x0023ec48: definition moved into src/anon/unit_0023e5d0.cpp

/* ---- 0024c568 ---- */
extern void* D_0035eda8;
extern void* D_0035edac;
s32 func_002892f8(void*);
s32 func_0028acc8(void*);
void func_00288e88(void*);

void func_0024c568(void);  // 0x0024c568: definition moved into src/anon/unit_0024ba58.cpp

/* ---- 00272538 ---- */
struct E13 { s16 a, b, v; };
extern E13 D_00373a30[];
u8* func_00257770(void);
s32 func_00287bc0(void);
s32 func_00139d78(void*);
u32 func_002570a0(s32);
s32 Tz__CmCustom__CurPos2CustomType(u32);

s32 func_00272538(void);  // 0x00272538: definition moved into src/anon/unit_00271e08.cpp

/* ---- 00282cb8 ---- */
extern s16 D_00374240[];
void* func_002811b0(u32, u32);
s32 func_00282c68(void*);
void func_00259570(s32, void*, u32, u32);
s32 func_002595e0(void);
u32 func_00192048(u32);
void func_002595e8(void*, u32);

void func_00282cb8(u8* p, s32 n);  // 0x00282cb8: definition moved into src/anon/unit_00282c68.cpp

/* ---- 00287a28 ---- */
void func_0028c4f8(void);
void func_0023ede8(void);
void func_00288b78(void);
void func_0023ed38(void);
void func_00287c20(void);  // clear_global_flag_return_m1
void func_00287f30(void);
struct VObj { void (**vt)(VObj*); };
extern s32 D_0035f2ec;
extern s32 D_0035f318;
extern s32 D_0035f2f0;
extern s32 D_0035f2f4;
extern VObj* D_0035f31c;
extern void* D_0035f2e8;

void Tz__MenuBase__Exit(void);  // 0x00287a28: definition moved into src/anon/unit_00286d28.cpp

/* ---- 002a9048 ---- */
s8* func_00276568(void);
struct E18 { s8 id; s8 flag; u8 pad[2]; };
struct T18 { s32 n; E18 e[1]; };
extern T18* D_0035f608;
extern void* D_0035f200;
s32 func_0028afa8(void*);
void func_0028afd0(void*, s32);  // obj_set_signed18

void Tz__JmQuest__AdjustPos(void);  // 0x002a9048: definition moved into src/anon/unit_002a8ac8.cpp

/* ---- 002ad1b0 ---- */
u8* func_00294000(s32);
extern u32* D_0035f620;
s32 func_002ad1b0(s32 id);  // 0x002ad1b0: definition moved into src/anon/unit_002a99c8.cpp

/* ---- 002b1a00 ---- */
struct E19 { u16 a; s16 b; };
extern E19 D_00374c68[];
u32* Tz__JmPuzzle__GetImageInfo(s32);  // list_entry_by_index_checked
void func_00276c50(s32, u32);

void Tz__JmPuzzle__UpdateHelpMess(void);  // 0x002b1a00: definition moved into src/anon/unit_002b0950.cpp

/* ---- 002dda88 ---- */
void func_002cfeb0(void*, void*, u32, u32);  // obj_init_field1416_bit800
extern void* D_00362b68;
union U20 { u32 id; f32 f; };
void func_002dda88(u8* o, U20* a1, u32 a2);  // 0x002dda88: definition moved into src/anon/unit_002dd650.cpp

/* ---- 002e7458 ---- */
struct N23 { N23* next; };
struct L23 { N23* head; N23* tail; };
extern L23 D_01e2bf00;
static inline N23* Next23(N23* n) { if (!n) return D_01e2bf00.head; return n->next; }
static inline bool has23(N23* x) {
    N23* n = 0;
    while ((n = Next23(n))) if (n == x) return true;
    return false;
}
void f_002e7458(N23* n) asm("_Z13func_002e7458Pv");
void f_002e7458(N23* n);  // 0x002e7458: definition moved into src/anon/unit_002e5f70.cpp

/* 002eae08: moved to src/anon/unit_002eae08.cpp */

/* ---- 002f13b0 ---- */
union F25 { f32 f; u8 c; };
extern F25 D_00349e10;
s32 YS__OBJ__is_valid(u32);  // list_contains_ptr
f32 func_0017ce10(f32);
void func_0016aeb8(u32, f32);
struct O21 { u32 f0; u32 h; f32 time; f32 dflt; f32 speed; f32 val; };
s32 func_002f13b0(O21* o);  // 0x002f13b0: definition moved into src/anon/unit_002f12b0.cpp

/* ---- 0031c0f8: destructor body ---- */
extern void* D_0034a548;
extern void* D_00347e80;
extern void* D_00347f98;
extern void* D_00347f80_v asm("D_00347f80");
void func_00239870(void*);
void func_002361d0(void*);

void func_0031c0f8(u8* o);  // 0x0031c0f8: definition moved into src/anon/unit_0031b9e0.cpp

/* ---- 00134030: wait for VIF1 / GIF / VU0 / IPU idle ---- */
s32 func_00134030(void);  // 0x00134030: definition moved into src/anon/unit_00133cf0.cpp

/* ---- 001b2578: advance along a path once the current point is reached ---- */
static inline void vsub3(void* out, const void* a, const void* b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(out), "r"(a), "r"(b) : "memory");
}
static inline f32 vlen(const void* v) {
    f32 d;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(d) : "r"(v) : "$8", "memory");
    return d;
}
struct Path29 { u32 f0; s32 n; u32 f8; s32 idx; f32 radius; Vec128* pts; };
// 001b2578: moved to src/anon/unit_001b1d20.cpp

/* ---- 0031f6d8: destructor body ---- */
extern void* D_00350bb0;
extern void* D_0034e8a8;
void func_00239848(void*);  // set_vtbl_36eb28_then_call
void func_001ac5b8(void*);
void func_00105110(void*);
void func_0031f6d8(u8* o);  // 0x0031f6d8: definition moved into src/anon/unit_0031f2f8.cpp
}
