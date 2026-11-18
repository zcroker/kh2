#include "../common/types.h"

struct NoTail { ~NoTail() {} };

// 0x1008d0 is __deregister_frame_info (src/libgcc/unwind-dw2-fde.c); crtbegin references it weakly.
void func_001008d0(BD_VALUE*) asm("__deregister_frame_info") __attribute__((weak));

extern "C" {

// Run the static constructors once (crt-style).
extern u8 D_0037aa00;
extern void (**D_0032b914)();
extern BD_VALUE D_00378ae8;
void func_001002b0(void);  // 0x001002b0: definition moved into src/anon/unit_001002b0.cpp

// Sum a virtual query over the objects referenced by an offset table.
u32 func_00124748(void*);  // list_nth_node_rel
typedef s32 (*VFn124)(u8*);
s32 func_00124788(u8* a);  // 0x00124788: definition moved into src/anon/unit_00123990.cpp

// Allocate and construct an object that points back at its owner slot.
void* func_001050d8(u32);
void func_00135e50(void*);
// 00135dc8: moved to src/naka/libkn/effect_observer.cpp

u32 func_0013a7e8(u32);
u32 func_0013d7e0(void);
void func_00138d60(void*, u32, u32, u32, u32, u32, u32);
void func_001374c8(u8* t, f32 f, u32 a, u32 b, u32 c);  // 0x001374c8: definition moved into src/anon/unit_001374c8.cpp

// Constructor: reset state.
struct T13a {
    void* vtbl; u8 p4[8]; u32 f0c; u8 p10[0xdc]; s32 fec; u32 ff0; s32 ff4; s32 ff8; u8 b0, b1, b2, b3; u32 f100; void* f104; u8 p108[8]; u32 f110; u8 p114[8]; u8 f11c[0x180]; u32 f29c, f2a0, f2a4; u8 b2a8, b2a9, p2aa[2]; f32 f2ac; u32 f2b0; f32 f2b4;
};
extern u8 D_00348590, D_00347e60;
u32 func_00239700(void*);
void func_0013afe8(T13a* t);  // 0x0013afe8: definition moved into src/anon/unit_0013a8b8.cpp

extern u32 D_00348804;
void func_00141c18(u32, u32, u32, u32, u32);
u32 func_00141ff0(u32, u32, u32, u32, u32);
void func_00143dd0(u32 a, u32 b, u32 c, u32 d, u32 e);  // 0x00143dd0: definition moved into src/anon/unit_00142c90.cpp

void func_00166618(u32, u32, u32, u32, u32, u32, u32);
struct P14d { u32 pad; s16 w; u16 h; };
// 0014de30: moved to src/anon/unit_0014d680.cpp


// Either of two registered lookups is missing: fall back to the default entry.
extern u32 D_0034aaac, D_0034aaa8, D_0034aaa4;
u32 func_001492f8(u32);
u32 func_00149300(u32);
u32 func_0019f880(s32, s32);
void func_0015aa98(u32, u32, u32, f32);
void func_0015aba8(u32, u32, u32);
void func_0015b2d0(void);  // 0x0015b2d0: definition moved into src/anon/unit_0015b100.cpp

s32 func_0014aba8(void);
void func_0014aa80(u32, u32, u32);
// 0016e048: moved to src/anon/unit_0016d2e0.cpp

// CACHE_BUFF::Clear(int): walk the list and release the entries selected by the sign of n.
void func_00170018(void*);
struct CacheNode { u8 p[40]; s32 v; u8 q[16]; CacheNode* next; };
extern CacheNode* D_0034dca0;
static inline CacheNode* CacheNext(CacheNode* n) { if (!n) return D_0034dca0; return n->next; }
void CacheBuffClear(s32 n) asm("_ZN2YS10CACHE_BUFF5ClearEi");
void CacheBuffClear(s32 n);  // 0x00170320: definition moved into src/anon/unit_0016e8f8.cpp

void* func_001050c8(void);
void func_00127c70(u32, void*, u32);
// 0017ee68: moved to src/yasui/libys/motion.cpp

struct B156 { u8 p[156]; u32 bit:1; };
u32 func_00187e20(void);
u32 func_00187e58(void*);
// 00188758: moved to src/anon/unit_00188550.cpp
u32 func_00188758(B156* t);

// Fetch a 16-byte result; copy it out when the lookup succeeds.
struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
void* func_001d35e0(void*, void*, u32);
// 001a7588: moved to src/yasui/libys/bg.cpp

// Out-of-range test against the 0x7000/0x9000/0x7300/0x8d00 screen limits.
u32 func_001aaf98(u32 z, s32 a, s32 b, s32 c, s32 d);  // 0x001aaf98: definition moved into src/anon/unit_001aaea8.cpp

// OBJOCC::disable_all(): flag every occupant entry as disabled.
struct OccHdr { s32 f0; s32 count; };
struct OccObj { u32 a, b, flags; };
struct OccEnt { u8 p[128]; OccObj* obj; u8 q[12]; };
struct OccSelf { union { OccHdr* h; u32 uh; }; union { OccEnt* arr; u32 uarr; }; };
void OccDisableAll(OccSelf* t) asm("_ZN2YS6OBJOCC11disable_allEv");
void OccDisableAll(OccSelf* t);  // 0x001b3270: definition moved into src/anon/unit_001b2780.cpp

void func_001b7f88(void);
void func_00170c00(void*);
extern u8 D_003511c3;
void func_001b7f30(u32* t);  // 0x001b7f30: definition moved into src/anon/unit_001b6a50.cpp


// Destructor: release the array member and trailing sub-object.
void func_00161530(void*);  // noop_ret_b
extern u8 D_0034c750, D_0034c738;
struct E16 { u8 d[16]; ~E16() {} };
struct M272 { u8 d[8]; ~M272() { func_00161530(this); } };
typedef void (*VF160)(void*, void*, u32);
struct C160 {
    void* vt; void** owner; u8 p[0x88]; E16 arr[8]; M272 m;
    ~C160() {
        vt = &D_0034c750;
        (*(VF160*)((u8*)*owner + 40))(owner, *(void**)&D_0034c738, *(u32*)((u8*)this + 448));
    }
};
// 00160268: moved to src/harata/libdk/bgobj.cpp

// Destructor with a base chain and a 2-element array member.
void func_001d5718(void*);  // list_free_nodes
void func_0031e7f8(void*);
void func_0016a358(void*);
extern u8 D_003507a0, D_003503e0;
extern union DU { void* p; u8 c; } D_00350790;
struct Base4 { void* vt; ~Base4() { func_0016a358(this); } };
struct M2492 { u8 d[32]; ~M2492() { func_0031e7f8(this); } };
struct E12 { u8 d[12]; ~E12() { func_001d5718(this); } };
struct C4 : Base4 {
    u8 p[2492 - 4]; M2492 m; E12 arr[2];
    ~C4() {
        vt = &D_003507a0;
        if (D_00350790.p == this) D_00350790.p = 0;
        vt = &D_003503e0;
    }
};
void u_call4_001a4e30(u32 a, u32, u32, u32) asm("_Z16u_call4_001a4e30jjjj");
// 001a4e30: moved to src/anon/unit_001a4db0.cpp

// Release every live entry of the 32-slot table.
struct Ent22 { void** obj; u32 x; };
extern Ent22 D_01dad9c0[32];
void func_0022d820(void);  // 0x0022d820: definition moved into src/anon/unit_0022d358.cpp

u32 func_00138470(void);
u32 func_00138440(void);
void func_001382e0(void);
u32 func_00287db0(void);
void func_001039f8(void);
void func_0017a798(void);
void func_00287da0(void);
u32 func_00263e18(void);  // 0x00263e18: definition moved into src/anon/unit_002632d0.cpp

// Does any of the 32 records satisfy the predicate?
u32 func_00139d78(u32);
extern u8* D_0035f21c;
u32 func_00276a90(void);  // 0x00276a90: definition moved into src/anon/unit_002748a0.cpp

void func_0028d6e8(void*);
void func_001396b0(void*);
void func_0031a260(void*, u32);
struct T28d { u8 p[396]; u32 f396; u32 f400; u8 p2[9]; u8 b413; };
void func_0028d660(T28d* t, u32 v);  // 0028d660: moved to src/anon/unit_0028c878.cpp

void func_002bc470(u32);
void func_002b6e24(u32, u32, u32);
void func_002ba1b8(u32 a, u32 b, u32 c);  // 0x002ba1b8: definition moved into src/anon/unit_002b9ab8.cpp

extern u32 D_003617ec, D_003617f4;
extern u8 D_003617f8;
extern u32 D_0032b91c;
void func_002b871c(void);
u32 func_00102788(u32, u32, u32, u32);
void func_002bd870(void);
void func_002bd788(u32 a);  // 0x002bd788: definition moved into src/anon/unit_002bc978.cpp

// Destructor: tear down the layered members and chain to the base.
void func_00319f88(void*);
void func_0019f9a8(void*);  // array8_free_slots
void func_001c0248(void*);
void func_00319fb0(void*);  // big_obj_dtor
extern u8 D_00345c08, D_0034e8b8, D_0034ee08;
struct G0 { u8* t; ~G0() { func_00319fb0(t); } };
struct G1 { u8* t; ~G1() { *(void**)t = &D_0034ee08; func_0019f9a8(t + 2568); func_001c0248(t + 2640); } };
struct G2 { u8* t; ~G2() { *(void**)t = &D_0034e8b8; func_00319f88(t + 2824); } };
struct B319 {
    void* vt;
    ~B319() {
        G0 g0 = { (u8*)this };
        G1 g1 = { (u8*)this };
        G2 g2 = { (u8*)this };
    }
};
struct C319 : B319 {
    u8 p[3184 - 4];
    E16 arr[6];
    ~C319() { vt = &D_00345c08; }
};
void func_00319d68(C319* t);  // 0x00319d68: definition moved into src/anon/unit_003197d0.cpp

void func_00239870(void*);
void func_002361d0(void*);
void func_0031a840(void*);
extern u8 D_00347d90, D_00347e60, D_00347f98, D_00347e80;
void func_0031a5a0(u8* t);  // 0x0031a5a0: definition moved into src/anon/unit_003197d0.cpp


// Notify every attached listener, then clear the busy flag.
void func_001d8070(u8* t);  // 0x001d8070: definition moved into src/anon/unit_001d7458.cpp

// Drop every list entry whose owner is still valid.
u32 func_001dca20(void*);  // get_bit20_of_field8
void func_00321ce8(void*, void*);  // list_unlink_node
void func_001e0058(void*);
void func_001de610(u8* t);  // 0x001de610: definition moved into src/anon/unit_001ddcf0.cpp

u32 func_001c5f38(void*);
void func_001c6760(void*);
u32 func_001dbd68(void*);
void func_001c6748(void*);
struct T1c6 { u8 p[4]; f32 f4; u8 p2[13]; u8 b21; u8 p3[30]; f32 f52; u8 p4[20]; f32 f76; u8 b80; };
void func_001c6850(T1c6* t);  // 0x001c6850: definition moved into src/anon/unit_001c5b90.cpp

// OR the pending bitset (640 bits) into the destination set, then free it.
u32* func_002859a0(void);
void func_00106420(void*);
extern union { u32* p; u8 c; } D_0035f2e4;
void func_00285910(void);  // 0x00285910: definition moved into src/anon/unit_002853b8.cpp

}
