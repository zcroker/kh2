#include "../common/types.h"

// 16-byte vector; assignment copies with a 128-bit lq/sq.
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq vscale162(const Vq& v, f32 s) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&v), "f"(s) : "$8", "$15", "memory");
    return r;
}
static inline Vq vsub162(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}

extern "C" {
u32 func_00106178(void*, s32);
extern u8 D_01f18014[];
extern u32 D_0032ba14;
extern u32 D_0032ba18;
extern u8 D_0032ba30;


struct Node139 { u32 _0; Node139* next; u32 _8, _c; s32 id; };
struct List139 { u32 _0; Node139* head; };
extern List139* D_00347f80;
void func_001395a8(void*);


s32 func_00162560(void*, Vq*);
s32 func_00162bb0(const Vq* a, void* b, const Vq* c, const f32* s, Vq* out);  // 0x00162bb0: definition moved into src/anon/unit_001614e8.cpp

extern s8 D_004f6330;
extern Vq D_004f6340;
void func_0016e898(void);
void func_002fd188(void (*)(void));  // pool_alloc_block
Vq func_0017d538(u32, f32);
// 0016d5d0: moved to src/anon/unit_0016d2e0.cpp

void func_0013f5f0(void*);  // copy_float_220_to_48
u32 func_00167f18(u32);
void func_00140618(void*, u32);
typedef s32 (*VFn)(void*);

void func_00140760(u8* p);  // 0x00140760: definition moved into src/anon/unit_0013fca8.cpp

void func_001666f0(void*, u16, u32, u16, u16);  // obj_store_masked
// 0014dc48: moved to src/anon/unit_0014d680.cpp

// 001548a8: moved to src/anon/unit_00153ea0.cpp
void func_001548a8(u8* p, s32 n);

struct Obj160 { void** vt; u8 _4[128]; Obj160* next; u8 _88[248]; u32 flags; };
extern struct { Obj160* head; u32 tail; } D_004f3b40;
typedef void (*VFn0)(void*);
static inline Obj160* nx160b(Obj160* o) { return !o ? D_004f3b40.head : o->next; }
// 00160b10: moved to src/harata/libdk/bgobj.cpp

void* func_0017ec98(void*);
void* func_0017edf0(void*, void*);
u8* func_00168b38(void*, u32, u32);  // entry_array_find_nth
// 0017f4e0: moved to src/yasui/libys/motion.cpp

void func_001d7cd0(void*);
s32 func_0016a090(void*);  // get_byte74
extern u8 D_0034ed78[];
// 00185b70: moved to src/anon/unit_001855e0.cpp

void* func_00185da8(void*);
s32 func_00186ce8(void*);
void func_0018f3a8(s32* out);  // 0x0018f3a8: definition moved into src/anon/unit_0018f140.cpp

extern u32 D_0034f240;
s32 func_00197920(void);
s32 func_001c8db8(void*, u32);
extern u8 D_00351ec8[];
// 00191a50: moved to src/yasui/libys/status.cpp

s32 func_001a2478(void*);  // count_div4_compare
u8 func_0019e848(void*, void*, void*, u32);
extern u8 D_0036d3f0[];
u8 func_0019e6e8(void* a, u8* b);  // 0x0019e6e8: definition moved into src/anon/unit_0019ba60.cpp

struct Pool1a1 { u8 d[600]; s32 timer; u8 _25c[12]; };
struct PoolMgr1a1 { Pool1a1 items[64]; s32 free[64]; s32 nfree; };
extern PoolMgr1a1 D_01c62fb8;
void func_001a1840(void*);
void func_001a17c8(Pool1a1* p);  // 0x001a17c8: definition moved into src/anon/unit_0019fb70.cpp

struct Obj1ac { void* vt; u8 _4[120]; Obj1ac* next; };
extern struct { Obj1ac* head; Obj1ac* tail; } D_01c6cec0;
extern u8 D_00350c50[];

u32 func_001ae210(const s8* s);  // 0x001ae210: definition moved into src/anon/unit_001ada38.cpp

struct Ent1c3 { u16 id; u8 _2[6]; };
struct Tbl1c3 { u32 _0; s32 n; Ent1c3 e[1]; };
extern Tbl1c3* D_01d49560;
extern u32 D_0032fca8[];

extern void* D_00351fe4;
extern u8 D_0036e180[];
u8* func_001cbc50(void*, void*, void*, u32);
void func_001cba90(void);
u8* func_001cbeb8(void* a, s32 i);  // 0x001cbeb8: definition moved into src/anon/unit_001ca8e0.cpp

void func_001980d0(void*, u32, u32);
void func_001dba88(void*);
extern u8 D_00352140[];
extern u8 D_01d5b9e0[];
// 001ce3e8: moved to src/anon/unit_001cd660.cpp
void func_001ce3e8(u8* p, void* a, u32 b);

void func_001d1678(void*, s32);  // obj_init_28bytes
void func_001d19e8(void*, s32);
void func_001d16e8(void*, u32, u32);
extern u8 D_003525c8[];
extern u8 D_003525e8[];
void func_001d1f38(u32* p);  // 0x001d1f38: definition moved into src/anon/unit_001d14e0.cpp

f32 func_002f8b30(f32, f32);
void func_001d1b60(void*, s32);

void func_00321ce8(void*, void*);  // list_unlink_node
void func_001dc920(void*);
void func_001e0058(void*);
void func_001de450(u8* p);  // 0x001de450: definition moved into src/anon/unit_001ddcf0.cpp

typedef void (*VFnP)(void*);
struct Obj1e7 { u8 _0[24]; VFnP fn; };
struct Mgr1e7 { u8 _0[100]; s32 n; u8 _68[16]; Obj1e7** objs; };
void func_001e78e0(Mgr1e7* p);  // 0x001e78e0: definition moved into src/anon/unit_001e0cb8.cpp

void sceVu0UnitMatrix(void*);  // vu_store_w_splat
void sceVu0MulMatrix(void*, void*, void*);
extern u8* D_01d9e6e0;
extern u8* D_01d9e6e8;
void func_001eb0c8(void* unused, f32* s);  // 0x001eb0c8: definition moved into src/anon/unit_001e8ac8.cpp

void func_001fa950(void*, void*, void*);

void __fixunssfsi(f32);
// Local with a non-trivial destructor: keeps the call a jal instead of a sibling call.
struct NoTail { ~NoTail() {} };
void func_00233ac0(u32 a);  // 0x00233ac0: definition moved into src/anon/unit_002335e8.cpp

struct Ev234 { s32 type; s32 seq; u32 a, b, c, d, e, f; };
extern Ev234 D_01dadc00[64];
extern s32 D_0035e360;
extern s32 D_0035e368;
s32 func_00234400(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f);  // 0x00234400: definition moved into src/anon/unit_002335e8.cpp

u8* func_00236ca8(void*, s32);

s32 func_00242a00(void);
void func_0023d1d0(void);  // set_global_word1
void func_0023d1e0(void);  // zero_global_d
s32 func_00242a68(void);
void func_002b6bc4(s32);

extern void* D_0035ee5c;
s32 func_002892f8(void*);
s32 func_0028acc8(void*);
void func_00288e88(void*);
void func_00252020(void);  // 0x00252020: definition moved into src/anon/unit_00250fb8.cpp

void* func_002570a0(u32);
u16* func_002632d0(void*);
u32 func_002811b0(void*, u32);
void func_001a2a50(u32, u32, u32, u32);
void func_001a3458(u32, u32);
void func_0013dbb0(void);
extern void* D_0035f010;

struct E283 { u8 _0[6]; u8 kind; u8 _7; };
extern E283 D_003742c8[];
extern s8* D_0035f2b4;
void func_002835a8(void);
void func_00283900(u32);
void func_00283e48(void);  // 0x00283e48: definition moved into src/anon/unit_00282c68.cpp

s32 func_00293fb0(void);
u32 func_00103570(void);
void func_00293e00(u32);
void func_00293fc0(void);
void func_00253b30(void*, u32);
void func_0023fa90(u32, void*);
extern u32 D_0035f2bc;
extern u32 D_0035f2c4;
void func_002853b8(void);  // 0x002853b8: definition moved into src/anon/unit_002853b8.cpp

s32 func_0028b1c0(void*, s32);  // test_bit_field32
void func_00289b30(void*, void*, void*);
void func_0028afd0(s16* p, s32 a);  // 0x0028afd0: definition moved into src/anon/unit_00288b00.cpp

extern u8* D_0035f638;
void func_0023f900(void*);
s32 func_00292630(void);
u8* func_00294000(u32);
void* func_00293db8(u32, void*);
void func_0023fa08(void*, void*);
void func_002b27c8(void);  // 0x002b27c8: definition moved into src/anon/unit_002b1db8.cpp

extern u8* D_0035f634;
s32 func_00139d78(void*);
s32 func_002b2d48(void);  // 0x002b2d48: definition moved into src/anon/unit_002b2a18.cpp

extern u8 D_01e2a410[];
void func_002bcfe8(void*);
void func_002bd030(void*);
void func_002b6adc(u32, s32);
void func_002ba040(void);  // 0x002ba040: definition moved into src/anon/unit_002b9ab8.cpp

void* func_001c3748(void*, void*);
void func_00192048(u16);

u8* func_001b9bc8(void*);
void func_002d24e8(void*, void*);
void func_002d25f0(void* a);  // 0x002d25f0: definition moved into src/anon/unit_002d2498.cpp

typedef s32 (*VFnB)(void*);
s32 func_002ee040(u8* p);  // 0x002ee040: definition moved into src/anon/unit_002ecdb0.cpp

void sceVu0CopyVector(void*, u32);  // memcpy16

s32 func_003160e0(void*, u32, u32, u32);
typedef s32 (*VFn4)(void*, u32, u32, u32);
s32 func_00316110(u8* a, u32 b, u32 c, u32 d);  // 0x00316110: definition moved into src/libsupc++/tinfo.cpp

void func_00239870(void*);
extern u8 D_003485b0[];
extern u8 D_00347e60[];
extern u8 D_00347f98[];
extern u8* D_00347f80_p asm("D_00347f80");
typedef void (*VFn2)(void*, void*);
void func_0031b000(u8* p);  // 0x0031b000: definition moved into src/anon/unit_003197d0.cpp

void func_002361d0(void*);
extern u8 D_0034a800[];
extern u8 D_00348608[];
void func_0031b648(u8* p);  // 0x0031b648: definition moved into src/anon/unit_003197d0.cpp
}

extern "C" void func_0013ee88(void*);
extern "C" { extern void* D_00349270; extern u8 D_00348698[]; }
void func_0014a868(int a, int b);  // 0014a868: moved to src/anon/unit_00149fa8.cpp

extern "C" { extern f32 D_004f3600; extern u8 D_0034aa18[]; void func_00190128(void*); }
// 00159c58: static initialiser, now made by gcc in src/harata/libdk/talkcamera.cpp
