#include "../common/types.h"
// Built with -fno-strict-aliasing (_nsa).
extern "C" {
struct AllocVt7cf0 { void* (*alloc)(void* self, u32 size, void* ra); };
struct AllocObj7cf0 { union { AllocVt7cf0* vt; u8 c; }; };
struct Holder7cf0 { u8 pad[20]; union { AllocObj7cf0* al; u8 c; }; };
struct Ret7cf0 { u8 pad[4]; s32 f4; };
extern AllocObj7cf0* D_0032ba14;
extern Holder7cf0* D_00347f80;
extern s32 D_0035ed4c;
extern s32 D_0035ed50;
extern s32 D_0035ed54;
extern s32 D_0035ed58;
extern s32 D_0035ed5c;
extern void* D_0035ed60;
extern u8 D_00347e60[];
void func_00239700(void*);
struct Elem7cf0 {
    void* vt; u8 pad4[8]; s32 f12; u8 pad16[8]; u8 sub[408 - 24];
    static void* operator new[](unsigned int sz, AllocObj7cf0* a) { return a->vt->alloc(a, sz, 0); }
    Elem7cf0() { f12 = 0; vt = D_00347e60; func_00239700(sub); }
    ~Elem7cf0();
};
extern Elem7cf0* D_0035ed64;
extern u8 D_0035ed68;
extern u8 D_0035ed69;
void func_00287b18(s32, s32);
s32 func_00288be8(s32);
void func_002889f0(s32, s32, s32);
void func_00288f48(s32, s32, s32, s32, s32);
void func_002b3df8(void*);
void func_00239700(void*);
void func_0028d068(s32, s32);
Ret7cf0* func_00103eb0(void);
void func_00247ff0(void);
void func_00102818(s32, s32, s32, void (*)(void), s32);
void func_00247cf0(void);  // 0x00247cf0: definition moved into src/anon/unit_00242478.cpp

struct O16fc10 { u8 f0; u8 f1; u8 p2[2]; u8 sub[0x20]; u32 flags; s32 f28; s32 size; u32 start; u32 cur; u32 f38; O16fc10* next; };
void func_001684c0(void*, u32, void*, void*);
void func_00168d08(u32);
void func_00168e30(u32);
void func_0016fda8(O16fc10*);
void func_001755a4(void*, const void*, s32) asm("_Z13func_001755a4PvPKvi"); /* absolute alias: the asm copy in batch_w81 links 4 bytes late */
extern u8 D_00170160;
extern O16fc10* D_0034dca0;
static inline O16fc10* nx16fc10(O16fc10* o) { if (o == 0) return D_0034dca0; return o->next; }
static inline bool big16fc10(O16fc10* a) { return a->f28 >= 10000; }
static inline u8 ovl16fc10(O16fc10* o, O16fc10* a) {
    u8 ov = 0;
    if (o->cur < a->start + a->size) ov = a->start < o->cur + o->size;
    return ov;
}
void func_0016fc10(O16fc10* a);  // 0x0016fc10: definition moved into src/anon/unit_0016e8f8.cpp

void func_0031cc28(void*) asm("_Z13func_0031cc28Pv");
void func_00144490(f32, f32, f32, f32, f32, f32, void*);
void func_0017fdf8(void*);
struct E7e9d0 { u8 pad[0x10]; u8 sub[4]; };
struct P7e9d0 { s32 f00, f04, f08, f0c, f10, f14, f18, f1c, f20, f24, f28; u8 p2c[0x10];
  s32 f3c[2]; E7e9d0 e44[4]; s32 f94, f98; u8 p9c[0x14]; f32 vb0[4]; u8 pc0[0x10]; s32 fd0, fd4;
  u8 bd8[0x18]; s32 ff0; f32 ff4; s32 ff8; s32 ffc, f100, f104; s32 a108[8][2]; s32 f148; s32 a14c[16];
  s32 f18c, f190, f194; u8 p198[0x20]; s32 f1b8; };
void func_0017e9d0(P7e9d0* p, s32 a1);  // 0x0017e9d0: definition moved into src/anon/unit_0017e9d0.cpp
}
