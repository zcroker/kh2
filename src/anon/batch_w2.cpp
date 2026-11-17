#include "../common/types.h"

// Batch w2: small leaf / wrapper functions.

struct Rgb8 { u8 r, g, b; };
extern Rgb8 D_00340ed0;
extern void* D_00348804;
extern u32 D_00349df8;
extern u32 D_00349dfc;
extern s32 D_0034c76c;
extern u8 D_0034c770;
extern u8 D_0034c771;
extern u32 D_0034c774;
extern u32 D_0034c778;
extern u8 D_0034f250[];
extern u8 D_0034fa78[];
extern s32 D_0035eb48;
extern s16 D_0035f090;
extern s16 D_0035f092;
extern s16 D_0035f096;
extern u8* D_0035f21c;
extern u8 D_0035f440[];
extern u8 D_00377b68[];
extern u32 D_01e35980[];
extern f32 D_01c6053c;
extern f32 D_01c60540;
extern u32 D_00349dec;

// BD_VALUE argument block whose first slot points at an object holder.
struct ObjRef { u32 pad0; void* obj; };
struct BdObjFloat { ObjRef* ref; f32 value; };

struct Pair32 { u32 a, b; };
struct Vec16 { u32 x[4]; };
struct Cursor16 { u32 a, b; Vec16* p; };
struct Entry8 { u32 x, y; };
struct Table8 {
    s16 id;
    u8 pad[0x2a];
    Entry8* other;  // 0x2c
    Entry8* self;   // 0x30
};
struct OffsetHolder { u32 pad[3]; u32* offsets; };
struct TRAP;

extern "C" {
void* func_00106178(void* mem, u32 size);
void func_001024b0(void* alloc);
void func_00134730(u32, u32, u32, u32, u32);
u8 func_00141778(void*, u16);
void func_0016aeb8(void* obj, f32 v);
void func_00158870(void* obj, f32 v);
void func_001a2438(u32, u32, u32);
void func_0017dcc0(void*);
void func_00175af8(void*);
s32 func_0018e0d8(TRAP*, s32);
void func_001a49a0(u32, u32, u32);
void func_00195558(void*);
u8* func_001a80c8(s32);  // table24_find_by_id
void func_001b8e88(u32);
void func_001de168(void*, u32, u32, u32, u32, u32);  // scan_list_by_half
void func_001d2690(void*);
void func_0021fbc0(u32);
u16* func_002632d0();
u8 func_001a3888(u16);  // id_in_range_5_7_131
u8 func_00139d78(u8*);
u8* func_002766d0();
void func_0028dac8(u8*, s32);
void func_002b73ac(u32, u32, u32, u32, u32);
void func_001a55a8(u32, u32);
void func_003053c0(u32);
void* func_001050c8();
void func_0023edb0(void*);

// Empty function that still saves ra (clobber forces the frame).
void func_00100338(void) {
    asm volatile("" : : : "$31");
}

// Set the current RGB colour.
void func_0010a7d8(u8 r, u8 g, u8 b);  // 0010a7d8: moved to src/anon/unit_00109c30.cpp

// 00134db0: moved to src/anon/unit_00134668.cpp

// 00134dd0: moved to src/anon/unit_00134668.cpp

u8 func_00143448(u16 id);  // 0x00143448: definition moved into src/anon/unit_00142c90.cpp

u32 func_0014ca20(void);  // 0x0014ca20: definition moved into src/anon/unit_0014c7f0.cpp

u32 func_00152598(u32 a0, s32 i, s32 second, Pair32* tbl);  // 0x00152598: definition moved into src/anon/unit_0014ecb8.cpp

// Clamp to 0..128 and store.
void func_00161a80(s32 v);  // 0x00161a80: definition moved into src/anon/unit_001614e8.cpp

void func_00161ee8(void);  // 0x00161ee8: definition moved into src/anon/unit_001614e8.cpp

void func_00171910(BdObjFloat* a);  // 0x00171910: definition moved into src/anon/unit_00170f58.cpp

void func_00174d18(BdObjFloat* a);  // 0x00174d18: definition moved into src/anon/unit_00171e58.cpp

void func_00175108(u32* v);  // 0x00175108: definition moved into src/anon/unit_00171e58.cpp

void func_0018fb70(u32* v);  // 0x0018fb70: definition moved into src/anon/unit_0018f140.cpp

void func_00195750(void);  // 0x00195750: definition moved into src/anon/unit_00194790.cpp

void func_001a91f8(s32* p);  // 0x001a91f8: definition moved into src/anon/unit_001a9130.cpp

void func_001b58f0(u8* p, u32 a1, u32 a2, u32 a3);  // 0x001b58f0: definition moved into src/anon/unit_001b2780.cpp

// Advance the cursor by n 16-byte entries; returns the old position.
Vec16* func_001b7ff8(Cursor16* c, s32 n);  // 0x001b7ff8: definition moved into src/anon/unit_001b6a50.cpp

void func_001d1678(s32* p, s32 a1);  // 0x001d1678: definition moved into src/anon/unit_001d14e0.cpp

void func_001d2648(s32* p);  // 0x001d2648: definition moved into src/anon/unit_001d14e0.cpp

void func_001fb698(u32 base, OffsetHolder* h);  // 0x001fb698: definition moved into src/anon/unit_001fb350.cpp

// VU0 macro: d.xyz = s.xyz.
void func_002226b8(void* d, void* s);  // 0x002226b8: definition moved into src/anon/unit_00222548.cpp

// VU0 square root.
f32 func_00222978(f32 x);  // 0x00222978: definition moved into src/anon/unit_00222548.cpp

// Returns 0 (and stores 0) when the value is unset (-1).
s32 func_0023d2e0(s32* out);  // 0x0023d2e0: definition moved into src/anon/unit_0023d260.cpp

void func_00258d58(s32 a, s32 b, s32 c);  // 0x00258d58: definition moved into src/anon/unit_002588e8.cpp

u8 func_00263688(void);  // 0x00263688: definition moved into src/anon/unit_002632d0.cpp

u8 func_00276f38(void);  // 0x00276f38: definition moved into src/anon/unit_002748a0.cpp

Entry8* func_0028ac98(Table8* t, s32 id);  // 0x0028ac98: definition moved into src/anon/unit_00288b00.cpp

void func_0028dfe8(u32* p);  // 0028dfe8: moved to src/anon/unit_0028c878.cpp

void func_0029df98(void);  // 0x0029df98: definition moved into src/anon/unit_0029d008.cpp

void func_002ba330(u32 a0, u32 a1, u32 a2);  // 0x002ba330: definition moved into src/anon/unit_002b9ab8.cpp

void func_002e7b10(u32* v);  // 0x002e7b10: definition moved into src/anon/unit_002e7b10.cpp

typedef void (*VFn3)(void*, u32, u32);
void func_002ead20(void** o, u32 a1);  // 002ead20: moved to src/anon/unit_002eaa68.cpp

// VU0 macro: d = a - b.
void sceVu0SubVector(void* d, void* a, void* b) {  // vec4_sub
    asm volatile("lqc2 $vf4, 0(%0)\n\tlqc2 $vf5, 0(%1)\n\tvsub.xyzw $vf6, $vf4, $vf5\n\tsqc2 $vf6, 0(%2)"
                 : : "r"(a), "r"(b), "r"(d) : "memory");
}

// VU0 macro: d = ftoi0(s).
void sceVu0FTOI0Vector(void* d, void* s) {  // vec4_ftoi0_trunc
    asm volatile("lqc2 $vf4, 0(%0)\n\tvftoi0.xyzw $vf5, $vf4\n\tsqc2 $vf5, 0(%1)" : : "r"(s), "r"(d) : "memory");
}

// Lower-case to upper-case through the ctype table.
s32 toupper(s32 c);  // 0x002ffbe0: definition moved into src/newlib/libc/toupper.c

// EnableIntc followed by sync.l.
void iEnableIntc(u32 n);  // 0x003062a0: definition moved into src/sdk/libkernl_00306058.c

u32 func_00308200(s32 i);  // 0x00308200: definition moved into src/sdk/libkernl_003081d0.c

typedef void (*VFn1)(void*);
void func_00322968(void** o) {
    ((VFn1*)*o)[5](o);
}
}

// ---- C++ symbols ----
class TASK_MANAGER {
public:
    static void Create(void* mem, u32 size);
};
// 00102508: TASK_MANAGER::Create, moved to src/global/unit_001022c0.cpp

namespace dk {
class Layout {
public:
    void init(void);
};
// 0x00153c60: definition moved into src/anon/unit_00153678.cpp
}  // namespace dk

namespace YS {
struct OBJ;
}  // namespace YS

// 0017dc98: moved to src/yasui/libys/friend.cpp

namespace YS {
// Virtual slot 8 (byte offset 32) of the message object.
typedef void (*MsgFn)(void*);
void method_message_is_end(BD_VALUE* v);  // 0x00173270: definition moved into src/anon/unit_00171e58.cpp

s32 trap_attack_get_type(BD_VALUE* v);  // 0x0018f8a0: definition moved into src/anon/unit_0018f140.cpp

// 001a3868 (ITEM::GetCommandElem): moved to src/anon/unit_001a2a50.cpp
}  // namespace YS

// 001826e0: moved to src/yasui/libys/areadata.cpp

struct Vec3f { f32 x, y, z; };
void wtarget_001efb18(u32 a0, u32 a1, u32, u32);  // 0x001efb18: definition moved into src/anon/unit_001ef780.cpp
