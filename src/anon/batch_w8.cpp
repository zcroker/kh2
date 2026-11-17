#include "../common/types.h"

// Batch w8: small leaf / wrapper functions.

typedef void (*VFn)(void*);
typedef void (*VF3)(void*, u32, u32);
typedef u32 (*VR3)(void*, u32, u32);

extern "C" {

// Copy quadword a -> p+0x50 and b -> p+0x60 (each unless aliasing).
// 001072d0: moved to src/naka/libkn/camera.cpp

// Forward to the owned object's virtual slot 16 with this->field_104.
void func_0011c7f8(u8* self, u32 x);  // 0x0011c7f8: definition moved into src/anon/unit_0011c128.cpp

void** func_00124748(void*, u32);  // list_nth_node_rel
void func_00123d10(void* p);  // 0x00123d10: definition moved into src/anon/unit_00123990.cpp

// 64-byte (matrix) copy src -> dst unless they are the same.
void func_00146680(u8* dst, u8* src) {  // copy_quad4_if_diff
    if (dst != src) {
        asm volatile(
            "lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
            : : "r"(dst), "r"(src) : "$8", "$9", "$10", "$11", "memory");
    }
}

void func_0017d0e8(f32);
void* func_0016b040(void* r, u8* p) {
    func_0017d0e8(*(f32*)(p + 1644));
    return r;
}

u32 func_0016f770(s32 x);  // 0x0016f770: definition moved into src/anon/unit_0016e8f8.cpp

void trap_obj_show(void** p) asm("_ZN2YS13trap_obj_showEP8BD_VALUE");
void trap_obj_show(void** p);  // 0x00171378: definition moved into src/anon/unit_00170f58.cpp

u32 func_0016b7a0(u32);
void trap_obj_search_by_serial(u32* p) asm("_ZN2YS25trap_obj_search_by_serialEP8BD_VALUE");
void trap_obj_search_by_serial(u32* p);  // 0x00172bd8: definition moved into src/anon/unit_00171e58.cpp

void func_00199468(u32, u32, f32, u32);
struct S174060 { u32* obj; f32 f; u32 a; u32 b; };
void func_00174060(S174060* p);  // 0x00174060: definition moved into src/anon/unit_00171e58.cpp

void func_0017c430(void*);
void func_0016bd60(void*, u32);
// 0017a938: moved to src/anon/unit_0017a8f8.cpp

void func_00180ce0(void*);
u8 func_0017ee68(void*);
// 0017eb98: moved to src/yasui/libys/motion.cpp

// Increment a 16-bit counter (table at +0x1458), saturating at 999.
void func_00189228(u8* p, u32 i);  // 0x00189228: definition moved into src/anon/unit_00188848.cpp

u32 func_001921d8(u32);
void func_00170518(u32, u32, u32);
void msg_read(u32 a, u32 b) asm("_ZN2YS7MESSAGE4ReadEii");
// read: moved to src/yasui/libys/message.cpp

void func_001dc878(u32);
void func_0016b668(void*);
void savepoint_leave(u8* o) asm("_ZN2YS3OBJ6VTABLEINS_9SAVEPOINTEE5leaveEPS0_");
void savepoint_leave(u8* o);  // 0x00195f88: definition moved into src/anon/unit_00195d00.cpp

void func_0019d548(void*);
void func_0019d4f8(void*);
void func_0019d720(void* p);  // 0x0019d720: definition moved into src/anon/unit_0019ba60.cpp

// Set the RGBA bytes at +20 and refresh.
void func_001b1be0(u8*);
// 001b1bb8: moved to src/anon/unit_001b14d8.cpp

void func_001802d8(u32, u32, void*, u32, u32, void*);
void func_001b50b0(u8* p, u32 a, u32 b);  // 0x001b50b0: definition moved into src/anon/unit_001b2780.cpp

void func_001a3c88(void);
u8 func_001029e8(u32);
extern u32 D_00351214;
u32 func_001b92d0(void);  // 0x001b92d0: definition moved into src/anon/unit_001b87a0.cpp

void func_001ba598(void*);
void func_003204c8(void*, void*);
extern u8 D_01d48de0;
void item_effect_dtor(void* self) asm("_ZN2YS11ITEM_EFFECTD1Ev");
// 001ba310: moved to src/yasui/libys/itemeffect.cpp

// Is bit o->field_1c clear in the bit set (words from +4)?
u32 func_001c0268(u32* bits, u8* o);  // 0x001c0268: definition moved into src/anon/unit_001bff88.cpp

void func_00198970(void*);
void func_00178280(void*);
void mickey_leave_req(void* o) asm("_ZN2YS3OBJ6VTABLEINS_6MICKEYEE9leave_reqEPS0_");
void mickey_leave_req(void* o);  // 0x001d0200: definition moved into src/anon/unit_001cf0b0.cpp

extern void** D_01d5bb00;
u32 func_001dc488(u32 x);  // 0x001dc488: definition moved into src/anon/unit_001dbfd8.cpp

void func_001dc9e0(void*);
void func_001e6cd8(u32);
void ryj_effect_scale(u8* self) asm("_ZN3ryj6EFFECT5scaleEv");
void ryj_effect_scale(u8* self);  // 0x001dc620: definition moved into src/anon/unit_001dbfd8.cpp

extern void** D_01d9e340;
u32 func_001de948(u32 x) {
    void** o = D_01d9e340;
    return ((VR3)(*(void***)o)[0])(o, x, 0);
}

void func_001e60b0(void);
struct S354690 { u32 a; s32 b; };
extern S354690 D_00354690;
void func_001e6250(void) {
    func_001e60b0();
    D_00354690.a = 0;
    D_00354690.b = -1;
}

void func_00229d40(void*);
void func_001390f0(void*);
void func_00229d68(void* p);  // 00229d68: moved to src/sasa/musical_combo.cpp (linked unit)

void func_00234188(u32, u32, u32, u32, u32, u32);
void func_002345c0(u32 a, u32 b, u32 c, u32 d, u32 e) {
    func_00234188(a, 0, b, c, d, e);
}

struct P23 { s16 a; s16 pad[3]; s16 b; };
void func_0023e738(u8* p, u32 i, s16 a, s16 b) {  // store_2halfwords_2928
    u8* q = (u8*)(i * 2) + (u32)p;
    P23* r = (P23*)(q + 2928);
    r->a = a;
    r->b = b;
}

void func_00240c08(s32, u32, u32);
extern s8* D_0035ec94;
void func_00241740(s32 x) {
    if (x < 0) x = D_0035ec94[1];
    func_00240c08(x, 0, 19);
}

void func_0026d808(const void*);
void func_00253180(u32, s32);
void camp_start_party(s32 a, const void* b) asm("_ZN2Tz8CampMenu10StartPartyEiPKv");
void camp_start_party(s32 a, const void* b) {
    func_0026d808(b);
    func_00253180(6, a);
}

extern s16 D_0035f090;
extern s16 D_0035f092;
extern s16 D_0035f094;
extern s16 D_0035f096;
void func_00258dc8(void);  // 0x00258dc8: definition moved into src/anon/unit_002588e8.cpp

void func_00257388(u32, u32);
void func_002571e0(u32);
void func_00287cc0(u32);
void func_00269378(void);  // 0x00269378: definition moved into src/anon/unit_00268b30.cpp

u8* func_00257770(void);
void func_0028dac8(u8*, u32);
void func_0027b4e8(void) {
    func_0028dac8(func_00257770() + 0xb350, 274);
}

extern s32 D_0035f2f8;
void func_00287c20(void);  // clear_global_flag_return_m1
void func_00287c78(s32);
void next_mode_to_mode(s32 mode, s32 next) asm("_ZN2Tz8MenuBase14NextModeToModeEz");
void next_mode_to_mode(s32 mode, s32 next);  // 0x00287bd0: definition moved into src/anon/unit_00286d28.cpp

void func_00139d78(void*);
void func_00139510(void*);
void func_0028c170(void* p);  // 0x0028c170: definition moved into src/anon/unit_0028bfc0.cpp

void func_002b726c(u32, s32, s32, u32, u32);
void sound_system_se_play(s32 a, s32 b) asm("_ZN5SOUND12systemSePlayEii");
void sound_system_se_play(s32 a, s32 b) {
    func_002b726c(2, a, b, 16383, 64);
}

void func_002baf48(u32, u32, u32, u32, u32, u32);
void func_002ba5d0(u32 a, u32 b) {
    func_002baf48(10, 1, a, b, 0, 0);
}

void func_002bb070(u32 a, u32 b, u32 c, u32 d, u32 e);  // 0x002bb070: definition moved into src/anon/unit_002bb070.cpp

void func_002eda90(u32, u32, f32);
extern u32 D_003637d0;
struct S2e8290 { u32 a; f32 f; };
void func_002e8290(S2e8290* p) {
    u32 g = D_003637d0;
    func_002eda90(g, p->a, p->f);
}

// Is o->field_c->field_4 one of 0x33 / 0x3d?
// 002eb068: moved to src/anon/unit_002eaf38.cpp

void** func_0010c7e8(u32);
// 002f07c8: moved to src/naka/libkn/trapfunctions.cpp

// Never returns: func_00315440 does not come back.
void func_00316d18(void*, u32);
void func_00315440(void) __attribute__((noreturn));
extern u8 D_003785f8;
extern u8* D_00365c48;
void func_003155c0(void) {
    func_00316d18(&D_003785f8, *(u32*)(D_00365c48 + 12));
    func_00315440();
}

u32 func_003160e0(u32* a, u32* b, u32 c, u32* d) {
    if (a[1] == b[1]) {
        d[0] = c;
        d[3] = 8;
        d[1] = 6;
        return 1;
    }
    return 0;
}

}

// Store two byte arguments as floats into D_00359110 (+8, +12).
struct S359110 { u32 pad[2]; f32 x; f32 y; };
extern "C" S359110 D_00359110;
void wtarget_0020ea70(u32 a0, u32 a1, u32, u32) {
    u8 y = a0;
    u8 x = a1;
    D_00359110.x = x;
    D_00359110.y = y;
}
