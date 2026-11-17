#include "../common/types.h"


extern "C" {
void func_00135cc8(void*, u32, u32);
void func_00135ad0(void*);
u32 func_0016c3a8(u32, u32);
void func_00185278(u32, f32, u32);
u32 func_0016b800(u32);
u32 func_001d14a0(void);
void func_001b6bd8(u32, u32);
u8* func_0019b260(void*, s32);
u32 func_001d96c0(u32, u32);
void func_001a1a20(void*, u32, u32);
void func_001d48b0(void*);
void func_001bd668(void*);
void func_001bd2d0(void*);
void func_001bd5b0(void*, u32, u32);
void func_00176cd0(void*);
void func_001dc9e0(void*);
void func_001e6ce8(u32);
void func_001e72a8(void*);
void func_0022ac60(void*);
void func_001390f0(void*);
void func_00234348(u32, u32, u32, u32, u32, u32);
void func_002b4b00(void);
void func_0028f4d8(u32, u32, u32);
void func_00240be0(void);
u8* func_00257770(void);
void func_0028da70(void*, u32);
void func_00280148(void);
void func_002800d0(void);
void func_00287cc0(u32);
u8* func_00167f18(u32);
void func_00138d48(void*);
void func_001395f8(void*);
void func_00170950(u32);
u32 func_002bc0f0(s32);
void* func_001050d8(u32);
void func_002e0d28(void*, u32);
void func_0017f5f8(u32, u32, u32, f32, f32);
void func_003146c8(void*);
void func_00106420(void*);

extern u32 D_0034aa90;
extern u32 D_0034aa94;
extern void* D_0034dc98;
extern void* D_01d5bb00;
extern void* D_01d9e340;
extern u32 D_00350f18;
extern u32 D_00350f1c;
extern u8* D_01d48cb0;
extern u8* D_01d49320;
extern u32 D_00359810;
extern u32 D_00359788;
extern u32 D_00359808;
extern u32 D_00359780;
extern u8 D_0032b100[];
extern u8 D_0032a980[];
extern u8* D_0035ec94;
extern u16 D_00372eea;
extern u8 D_00348d58[];
extern u8 D_00348698[];

void bc_make(void) asm("_ZN2dk14BlindCollision4makeEv");
void trap_obj_search_by_part(u32* v) asm("_ZN2YS23trap_obj_search_by_partEP8BD_VALUE");
void trap_player_capture_form(u32* v) asm("_ZN2YS24trap_player_capture_formEP8BD_VALUE");
void reset_anmatr_flag(u8* m) asm("_ZN2YS6MOTION17reset_anmatr_flagEv");
void group_enable(void* g, s32 i) asm("_ZN2YS10UNIT_GROUP6EnableEi");
void reset_special_command(u8* c) asm("_ZN2YS14PLAYER_COMMAND21reset_special_commandEv");
void effect_angle(u8* e) asm("_ZN3ryj6EFFECT5angleEv");
void jm_unload(u8* j) asm("_ZN2Tz6JmInfo6UnloadEz");

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// 00107300: moved to src/naka/libkn/camera.cpp

u32 func_001231f8(void* o, u32 a1, u32 a2, u32 a3, u32 t0, u8 t1, u32 t2);  // 0x001231f8: definition moved into src/anon/unit_00123138.cpp

// 00135c50: moved to src/naka/libkn/obj_observer.cpp

void bc_make(void);  // 0x0015a8a0: definition moved into src/anon/unit_0015a810.cpp

void func_0016fb00(u32 a);  // 0x0016fb00: definition moved into src/anon/unit_0016e8f8.cpp

struct Args171690 { u32* obj; f32 f; u32 flag; };
void func_00171690(Args171690* p);  // 0x00171690: definition moved into src/anon/unit_00170f58.cpp

void trap_obj_search_by_part(u32* v);  // 0x00172c08: definition moved into src/anon/unit_00171e58.cpp

void trap_player_capture_form(u32* v);  // 0x001741e0: definition moved into src/anon/unit_00171e58.cpp

// 001805e8: moved to src/anon/unit_00180408.cpp

void group_enable(void* g, s32 i);  // 0x0019b2d8: definition moved into src/anon/unit_00199688.cpp

void func_001a06e0(u32* p);  // 0x001a06e0: definition moved into src/anon/unit_0019fb70.cpp

struct Obj1a1db8 { u8 pad[444]; f32 x, y; };
void func_001a1db8(Obj1a1db8* p);  // 0x001a1db8: definition moved into src/anon/unit_0019fb70.cpp

// 001b1fc8: moved to src/anon/unit_001b1d20.cpp

u16 func_001b5af0(void);  // 0x001b5af0: definition moved into src/anon/unit_001b2780.cpp

// 001bbb28: moved to src/yasui/libys/mission.cpp

void reset_special_command(u8* c);  // 0x001bdc18: definition moved into src/anon/unit_001bc568.cpp

void func_001bdf38(u8* p);  // 0x001bdf38: definition moved into src/anon/unit_001bc568.cpp

// 001c0a80: moved to src/anon/unit_001c0638.cpp
void func_001c0a80(u8* p);

void func_001d14b8(u8* p);  // 0x001d14b8: definition moved into src/anon/unit_001d12e8.cpp

void func_001dc4b8(u32 a);  // 0x001dc4b8: definition moved into src/anon/unit_001dbfd8.cpp

void effect_angle(u8* e);  // 0x001dc648: definition moved into src/anon/unit_001dbfd8.cpp

void func_001de978(u32 a);  // 0x001de978: definition moved into src/anon/unit_001ddcf0.cpp

void func_0020eac0(void);  // 0x0020eac0: definition moved into src/anon/unit_0020e9f8.cpp

void func_0021cda0(s32 a);  // 0x0021cda0: definition moved into src/anon/unit_0021aee8.cpp

void func_0022acd0(void* p);  // 0022acd0: moved to src/sasa/musical_input.cpp (linked unit)

void func_00234670(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0);  // 0x00234670: definition moved into src/anon/unit_002335e8.cpp

u8* func_0023e788(u8* d, u8* p, s32 i);  // 0x0023e788: definition moved into src/anon/unit_0023e5d0.cpp

u32 func_00241770(s32 i);  // 0x00241770: definition moved into src/anon/unit_0023f5b8.cpp

void func_0025a1d0(void);  // 0x0025a1d0: definition moved into src/anon/unit_002588e8.cpp

void func_002631b0(void);  // 0x002631b0: definition moved into src/anon/unit_0025f6b8.cpp

void func_0027f9b0(void);  // 0x0027f9b0: definition moved into src/anon/unit_0027f2b0.cpp

s32 func_00288088(void);  // 0x00288088: definition moved into src/anon/unit_00286d28.cpp

void func_0028d708(void* p);  // 0028d708: moved to src/anon/unit_0028c878.cpp

// 00290a60: moved to src/anon/unit_0028f1e0.cpp

u32 func_002bc158(s32 a);  // 0x002bc158: definition moved into src/anon/unit_002bb8b0.cpp

void func_002e0bb0(u32 a);  // 0x002e0bb0: definition moved into src/anon/unit_002de3c8.cpp

struct Flags2e9fb8 { u32 lo : 16; u32 flag : 1; u32 hi : 15; };
void func_002e9fb8(u8* p, u8 b);  // 002e9fb8: moved to src/anon/unit_002e9a00.cpp

// 002f0a38: moved to src/naka/libkn/trapfunctions.cpp

// VU0 vector blend: d = a*t + b*(1-t).
void sceVu0InterVector(f32* d, f32* a, f32* b, f32 t) {  // vec4_lerp
    asm volatile(
        "lqc2 $vf4, 0(%1)\n\t"
        "lqc2 $vf5, 0(%2)\n\t"
        "mfc1 $8, %3\n\t"
        "qmtc2 $8, $vf6\n\t"
        "vaddw.x $vf7, $vf0, $vf0w\n\t"
        "vsub.x $vf8, $vf7, $vf6\n\t"
        "vmulax.xyzw ACC, $vf4, $vf6x\n\t"
        "vmaddx.xyzw $vf9, $vf5, $vf8x\n\t"
        "sqc2 $vf9, 0(%0)"
        : : "r"(d), "r"(a), "r"(b), "f"(t) : "$8", "memory");
}

struct Args314480 { u32 a, b, c; u64 d; };
void func_00314480(u32 a, u32 b, u32 c, u64 d) {
    Args314480 s;
    s.a = a; s.b = b; s.c = c; s.d = d;
    func_003146c8(&s);
}

void func_003197f8(u8* p) {
    void* o = *(void**)(p + 4);
    (*(void (**)(void*))(*(u8**)o + 4))(o);
}

void func_0031e068(u8* p) {
    *(u8**)(p + 416) = D_00348698;
    *(u8**)(p + 144) = D_00348698;
    *(u8**)(p + 0) = D_00348d58;
    func_00106420(p);
}
}

void wtarget_0016b070(u32 a0, u32 a1, u32, u32);  // 0x0016b070: definition moved into src/anon/unit_00169f98.cpp

// 001d3350: moved to src/anon/unit_001d30b0.cpp
