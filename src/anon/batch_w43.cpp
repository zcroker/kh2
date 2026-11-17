#include "../common/types.h"

struct V4 {
    u32 w[4];
} __attribute__((aligned(16)));

namespace Tz {
struct Munny {
    static u32 Add(u32 n);
};
}

extern "C" {
u32 DIntr(void);
void EIntr(void);  // ee_intr_get_enable
extern u32 D_0037aa2c;
extern void* D_0037aa30;
u8* func_0016a070(void);
s32 func_001a35f8(u32, u8*);
void func_00135d88(void);
extern u8* D_00341708[];
void func_001128d0(u32, s32);
extern s32 D_003417a8;
extern u32 D_00341788[];
void* func_00132350(void*);
void func_00124bb8(void*);  // obj_ctor_347b88
extern void* D_00347bb0[];
struct E64 { u8 b[64]; };
extern E64 D_003a99f0[];
void func_0011ed90(u8*, s32);
s32 func_00139d78(void*);
void func_0014c050(void*);
extern u8 D_004f3820[];
extern void* D_00348698[];
extern u32 D_0034e948;
u32 func_0016e920(u32);
u8* func_001b9bc8(u8*);
s32 func_0016c008(u8*, u32);
void func_00190128(void*);
void func_00190878(void*, u32, u32);
void func_001d6ab0(u32);
void func_0019ca90(u32, u32, void*);
u32 func_0016c028(void*);  // obj_get_attach_or_alt
s32 func_001a7610(u32, void*, s32, f32, f32);
void func_0016ace0(void*, void*);
s32 func_001883d8(u8*, void*);
void func_001880b0(u8*, void*);
extern u8 D_0036cbb0[];
void func_001902a8(void*, void*);
extern s32 D_01c6cb70;
struct P8 { u32 a; u32 b; };
extern P8 D_01c6cb30[];
void func_00105110(u32);
void func_001ac970(void*, s32, s32, u32, s32, s32, s32, s32);
extern void* D_00350b30[];
void func_001ac078(void*, s32, s32, s32);
void func_001aa388(void*, u32);
extern f32 D_00349e10;
void* func_00168b38(u32, s32, s32);  // entry_array_find_nth
s32 func_001dcd38(void*);
s32 func_001c8ab0(void);
s32 func_001dc790(u32);
s32 func_001dcc60(u8*);
u32 func_001dc5f8(u32);
void func_002bc398(u32, u32);
void func_002bc3f0(u32);
u8* func_00102c80(void);
u8* func_00102788(u32, s32, s32, void*);
void* func_001050d8(u32);
void func_001e7be0(void*);
void func_001e7798(u32, u32);
extern u32 D_01d9e6e4;
void func_00225530(void*);
void func_00225280(u32, u32);
extern u32 D_00370d88[];
extern void* D_0035eb08[];
s32 func_002424c0(u32);
u8* func_001058e8(void);
extern u8* D_0035f0e4;
s32 func_00257780(void);
extern void* D_0035f04c;
extern void* D_0035f01c;
s32 func_0028be58(void*);
s32 func_0028acc8(void*);
void func_0028e510(void*, s32, s32);
extern u8* D_0035f480;
struct Ent8 { s16 ids[3]; s16 pad; };
extern Ent8 D_0035f468[];
s32 func_00276638(s32);
extern u8* D_0035f5ac;
u8* func_0029da68(s32);
s32 func_00292a90(s32);
s32 func_00292af0(s32);
void func_002bd998(void*, u32);
u8* func_00102c48(s32, s32, void*, s32);
void func_002be3a8(void);
void task_end_002be3c8(void*) asm("_ZN8worldmap8Libretto14finalizeThreadEP4TASK");
void func_002be428(void);
void func_00102c18(s32, s32, void*);
s32 func_002c1b48(void*);
struct B3 { u8 b[3]; };
extern B3 D_00375518[];
u32 func_001c2b58(s32);
void func_002c1b60(void*, u32);
void func_00198450(void*);
extern V4 D_01e2bca0;
extern V4 D_01e2bcb0;
struct M4 { V4 r[4]; };
extern M4 D_01e2bcc0;
void func_00177dc8(void*, u32, s32, u32, u32);
extern void* D_00361d00[];
void func_001befd8(u32, s32, s32);
void func_002cbec0(u32, u32);
void func_002eaf48(V4*, u32, s32);
extern V4 D_01e2c050;
void func_0016bd60(u32, s32);
void func_002eb6f8(u32, s32, f32);
extern f32 D_01e2c060;
extern V4 D_00363550;
V4* func_0016c028_v(u32) asm("func_0016c028");

// 128-bit copy (lq/sq), as the original
static inline void cpq(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}

// Local with a destructor: keeps the final call from becoming a tail call.
struct NoTail { ~NoTail() {} };
void func_0017d8c0(M4*, V4*, V4*);
void func_0029dd60(void);
struct P199 { u32 f0; u32 flag : 1; u32 rest : 31; u32 f8; u8* o; u32 f16; };
struct O408 { void** vt; u8 pad[404]; };
extern O408* D_0035ed64;
struct H3 { u8 pad[16]; u32 lo : 16; u32 hi : 16; u32 pad2; u32 off; };
struct P3 { u32 vt; H3* h; u32 base; u32 a; u32 b; u32 c; };
struct Ent32 { u32 key; u16 id; u8 pad[26]; };
struct NdB { u8 q[16]; u32 f16; bool b20; s8 b21; u8 b22; s8 b23; bool b24; u8 pad[3]; void* owner; u32 f32; NdB* next; };
struct LLB { NdB* head; NdB* tail; };
struct LsB { u8 pad[8]; u8 b8; u8 pad2[3]; LLB list; };

s32 func_0010f748(u8* p, u32 b);  // 0x0010f748: definition moved into src/anon/unit_0010f338.cpp

void func_00112388(void);  // 0x00112388: definition moved into src/anon/unit_001117d8.cpp

void func_001129d8(u32 a);  // 0x001129d8: definition moved into src/anon/unit_001117d8.cpp

void func_00127f40(P3* p) {
    func_00124bb8(p);  // obj_ctor_347b88
    p->vt = (u32)D_00347bb0;
    H3* h = p->h;
    s32 n = h->hi - h->lo;
    p->base = (u32)D_003a99f0;
    p->a = (u32)(D_003a99f0 + h->hi);
    p->b = (u32)((E64*)p->a + n);
    p->c = (u32)((E64*)p->b + n);
    func_0011ed90((u8*)h + h->off, n);
}

u32 func_0016b740(u32 id);  // 0x0016b740: definition moved into src/anon/unit_00169f98.cpp

s32 func_0016f6f8(u32 id);  // 0x0016f6f8: definition moved into src/anon/unit_0016e8f8.cpp

void func_00172c38(u8* p);  // 0x00172c38: definition moved into src/anon/unit_00171e58.cpp

void func_00174290(u8* p);  // 0x00174290: definition moved into src/anon/unit_00171e58.cpp

// 001852b8: moved to src/anon/unit_00183088.cpp

void func_0018b200(u8* p);  // 0x0018b200: definition moved into src/yasui/libys/npc.cpp

// Mark dead and destroy every child in the list.
void func_00199cd0(P199* p);  // 0x00199cd0: definition moved into src/anon/unit_00199688.cpp

void func_0019ca28(u8* p, u32* s);  // 0x0019ca28: definition moved into src/anon/unit_0019ba60.cpp

// 001ad430: moved to src/anon/unit_001abb28.cpp

s32 func_001ad9c8(f32* p);  // 0x001ad9c8: definition moved into src/anon/unit_001ad990.cpp

// Init a node from a 16-byte header and append it to the owner's list.
// 001c1748: moved to src/anon/unit_001c0638.cpp
void func_001c1748(NdB* n, LsB* l, void* src, u32 a3);

void func_001d5370(u32* out, u32 a, s32 b);  // 0x001d5370: definition moved into src/anon/unit_001d4f40.cpp

u8* func_001dba18(u32 id) {
    u8* v = 0;
    while ((v = func_001b9bc8(v)) != 0) {
        if (!(*(u32*)(v + 1416) & 0x10000000)) continue;
        if (*(u32*)(v + 8) == id) return v;
    }
    return 0;
}

s32 func_001dcc60(u8* p);  // 0x001dcc60: definition moved into src/anon/unit_001dbfd8.cpp

void func_001e00b0(u8* p);  // 0x001e00b0: definition moved into src/anon/unit_001deb58.cpp

void func_001e7cc0(u8* p);  // 0x001e7cc0: definition moved into src/anon/unit_001e0cb8.cpp

void func_00225328(u8* p);  // 0x00225328: definition moved into src/anon/unit_00224780.cpp

void func_0023c008(u32* p);  // 0x0023c008: definition moved into src/anon/unit_0023bc58.cpp

void func_00249358(void);  // 0x00249358: definition moved into src/anon/unit_00247ff0.cpp

s32 func_002671e8(s32 n);  // 0x002671e8: definition moved into src/anon/unit_00265580.cpp

s32 func_00269f58(void);  // 0x00269f58: definition moved into src/anon/unit_00269a60.cpp

void func_0028e5e0(void* a, s16* l, s32 n);  // 0028e5e0: moved to src/anon/unit_0028c878.cpp

Ent8* func_0028f690(s32 i);  // 0028f690: moved to src/anon/unit_0028f1e0.cpp

void func_0029dda8(void);  // 0x0029dda8: definition moved into src/anon/unit_0029d008.cpp

void func_002be340(u32 a);  // 0x002be340: definition moved into src/anon/unit_002be020.cpp

void func_002c1ae8(u8* p);  // 0x002c1ae8: definition moved into src/anon/unit_002c10e0.cpp

void func_002c20f8(V4* a);  // 0x002c20f8: definition moved into src/anon/unit_002c1e80.cpp

void func_002c5850(u8* p, u32 a, u32 b, u32 c);  // 0x002c5850: definition moved into src/anon/unit_002c53c8.cpp

// 002e3260: moved to src/anon/unit_002e2f08.cpp

// 002eca38: moved to src/anon/unit_002ec5f8.cpp

}

struct WT { s32 a; u32 b, c, d; union { u32 w; u64 q; } u; void* next; };

// 0x00242500: definition moved into src/anon/unit_00242478.cpp

void ctarget_0011e350(u32 a, u32 b, u32, u32);  // 0x0011e350: definition moved into src/anon/unit_0011c128.cpp

// 001a6ae8: moved to src/anon/unit_001a6a10.cpp

// Queue a request node: interrupts off, push onto the pending list, restore.
void wtarget_00100700(u32 a, u32 b, u32 c, u32 d) {
    NoTail nt;
    WT* p = (WT*)b;
    p->u.w = 0;
    p->a = -1;
    p->b = c;
    p->u.q |= 0x7fa;
    p->c = d;
    p->d = a;
    u32 s = DIntr();
    D_0037aa2c = s;
    p->next = D_0037aa30;
    D_0037aa30 = p;
    if (s) EIntr();  // ee_intr_get_enable
}

// 0015eaf8: moved to src/anon/unit_0015e070.cpp

// 002ec960: moved to src/anon/unit_002ec5f8.cpp
