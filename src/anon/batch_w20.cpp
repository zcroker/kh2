#include "../common/types.h"

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

extern "C" {
void dk_area_readData(void) asm("_ZN2dk4Area8readDataEv");
void trap_obj_voice(u32* v) asm("_ZN2YS14trap_obj_voiceEP8BD_VALUE");
u32 target_is_exist(const u8* t) asm("_ZNK2YS6TARGET8is_existEv");
void wtarget_002f0598(void* o, Q16* q) asm("_Z16wtarget_002f0598jjjj");
void trap_stitch_effect_kill(u32* v) asm("_ZN2kn23trap_stitch_effect_killEP8BD_VALUE");

void func_00102818(u32, u32, u32, u32, u32);
void func_00113668(void*);
void func_00105110(void*);
void func_00102c48(u32, u32, void*, u32);
void func_001384d0(void);
void func_0013a600(void);
void func_0013a4c8(void);
void func_001493b8(void*);
void func_00149428(void*);
void func_00138c10(void*, u32);
void func_00150be8(void*);
void func_00151d48(void*);
u8 func_00167e00(void*);
void func_00194108(void*, u32);
u32 func_001a4550(u32, u32);
u32 func_00190208(const u8*, u32);
u32 func_00239d10(u8*);
void func_0017c4c8(void*, Q16*);
void func_0016bd60(void*, s32);
u32 func_001bd418(u8*);
void func_001bd618(u8*, u32);
void func_001bc688(u8*);
void func_00190128(u8*);
void func_001ce378(void*);
extern void* D_01d5ba78[];
u8 func_002fd248(u32, u8*, u32, u32, void*);
void func_0021fa10(u8*);
void func_00236c38(void*);
void func_00106420(void*);
void func_00139d78(void*);
u8* func_001058e8(void);
void func_0028da70(void*, s32);
u32 func_00287bc0(void);
void func_00276c50(u32, u32);
u8* func_00294000(u32);
void func_0018a008(u32, void*, void*);
void func_002ef1b8(void);
u32 func_0010c7e8(u32);
void func_00117aa8(u32, u32);
void func_0016a358(void*);
u8 func_002cff98(void*);
void func_002e7328(void*);  // to_2e7458

extern u32 D_0033cb84;
extern void* D_003473c8[];
extern u32 D_00347e08;
extern u8 D_00348d68[];
extern u8 D_0034d6c0[];
extern s32 D_004f63a8[];
extern Q16 D_0034eef0;
extern Q16 D_0034ef00;
extern u16 D_0032bae0;
extern u32 D_0034f240;
extern u32 D_00350f18;
extern u32 D_01d44400;
extern u8 D_01d44440[];
extern void* D_00352780[];
extern u8* D_01d5ba9c;
extern u8 D_003218b8[];
extern u8* D_00352ae0;
extern void* D_0035eac8[];
extern u8* D_0035f244;
extern s8 D_0035f24c;
struct E374050 { u8 pad[4]; s16 v; };
extern E374050 D_00374050[];
extern u8* D_0035f34c;
extern u32 D_00374b44;
extern u32 D_00374b48;
extern void* D_00350388[];
extern void* D_00362398[];
extern void* D_00362908[];

// 00105da8: moved to src/common/shop.cpp

// Returns the i-th 32-byte entry of the table hanging off p->f8, or 0 when out of range.
u8* func_00113808(u8* p, s32 i);  // 0x00113808: definition moved into src/anon/unit_00113628.cpp

void func_001156b8(void** p);  // 0x001156b8: definition moved into src/anon/unit_00114a90.cpp

// Index of v in the id list at p+16 (count at p+12), or -1.
// 00135c88: moved to src/naka/libkn/obj_observer.cpp

void func_001385c0(void);  // 0x001385c0: definition moved into src/anon/unit_00138480.cpp

// 00149c08: moved to src/harata/libdk/area.cpp

void func_001514e8(u8* p);  // 0x001514e8: definition moved into src/anon/unit_0014ecb8.cpp

void func_001520c0(u8* p, s32 a);  // 0x001520c0: definition moved into src/anon/unit_0014ecb8.cpp

// 00167ea8: moved to src/anon/unit_00167358.cpp

s32 func_0016f930(s32 a);  // 0x0016f930: definition moved into src/anon/unit_0016e8f8.cpp

void trap_obj_voice(u32* v);  // 0x00171810: definition moved into src/anon/unit_00170f58.cpp

// 00177638: moved to src/yasui/libys/party.cpp

void func_0018e108(Q16* a, Q16* b);  // 0x0018e108: definition moved into src/anon/unit_0018d050.cpp

void func_0018f858(u32* p);  // 0x0018f858: definition moved into src/anon/unit_0018f140.cpp

u32 target_is_exist(const u8* t);  // 0x00190140: definition moved into src/anon/unit_001900d0.cpp

// 00191c50: moved to src/yasui/libys/status.cpp

// 001ac1d0: moved to src/anon/unit_001abb28.cpp

// 001b1ff0: moved to src/anon/unit_001b1d20.cpp

void func_001b2780(void* a0, void* a1, Q16* a2);  // 0x001b2780: definition moved into src/anon/unit_001b2780.cpp

u32 func_001bd3e0(u8* p);  // 0x001bd3e0: definition moved into src/anon/unit_001bc568.cpp

void func_001bd668(u8* p);  // 0x001bd668: definition moved into src/anon/unit_001bc568.cpp

void func_001bde58(u8* p);  // 0x001bde58: definition moved into src/anon/unit_001bc568.cpp

void func_001d6538(void** p);  // 0x001d6538: definition moved into src/anon/unit_001d63a8.cpp

u8 func_001d7980(u32 a);  // 0x001d7980: definition moved into src/anon/unit_001d7458.cpp

// Clears flag 0x4000000 on every node of the list at D_00352ae0 (next at +0x28).
void func_001ddc48(void);  // 0x001ddc48: definition moved into src/anon/unit_001dd920.cpp

void func_001fb870(u8* a, u8* b) {
    u8* s = a + **(s32**)(b + 12) + 160;
    func_0021fa10(s);
    s[8] = 4;
}

void func_00236a18(void** p) {
    *p = D_0035eac8;
    func_00236c38(p);
    func_00106420(p);
}

void func_0023f740(u8* p, u32 a) {
    func_00139d78(p);
    *(u32*)(p + 0x44) = a;
}

// The pair is read as 16-bit bitfields: plain s16 loads get hoisted above the first store.
struct Pair16 { s32 x : 16; s32 y : 16; };
void func_00242980(s32* a, s32* b) {
    Pair16* v = (Pair16*)(func_001058e8() + 16800);
    *a = v->x;
    *b = v->y;
}

void func_0027ead0(void);  // 0x0027ead0: definition moved into src/anon/unit_0027e920.cpp

// Dispatches through slot 0 of the object at D_0035f34c, passing the caller's return address.
u32 func_00288be8(u32 a);  // 0x00288be8: definition moved into src/anon/unit_00288b00.cpp

void func_002a1f40(void);  // 0x002a1f40: definition moved into src/anon/unit_002a1d38.cpp

u8* func_002a7f20(s32 i) {
    u8* b = func_00294000(7) + 16;
    return b + i * 8;
}

void func_002d6af0(void** p);  // 0x002d6af0: definition moved into src/anon/unit_002d62d0.cpp

s32 func_002db8a8(void** p);  // 0x002db8a8: definition moved into src/anon/unit_002da040.cpp

// 002ef180: moved to src/anon/unit_002ee8a8.cpp

// 002f0598: moved to src/anon/unit_002efd68.cpp

// 002f0a68: moved to src/naka/libkn/trapfunctions.cpp

void func_0031f008(void** p) {
    *p = D_00350388;
    func_0016a358(p);
    func_00105110(p);
}

// 1 if v is in the list headed at *p (next at +0x1c).
u32 func_00324718(u8** p, u8* v) {
    u8* n = 0;
    while ((n = !n ? *p : *(u8**)(n + 0x1c)) != 0) {
        if (n == v) return 1;
    }
    return 0;
}
}
