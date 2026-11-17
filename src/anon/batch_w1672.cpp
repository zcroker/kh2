#include "../common/types.h"

struct Q16w1672 {
    u32 w[4];
    Q16w1672& operator=(const Q16w1672& o) {
        if (this != &o) asm volatile("lq $8,0(%1)\n sq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));

extern "C" {

struct W3w1672 { u32 a; u32 b; f32 c; };
extern W3w1672 D_01d5ba78;
extern W3w1672 D_01d5ba88;
void wt_001d6850(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001d6850jjjj");
void wt_001d6850(u32 a, u32 b, u32, u32);  // 0x001d6850: definition moved into src/anon/unit_001d63a8.cpp

struct W2w1672 { u32 a; u32 b; };
extern W2w1672 D_004f3b38;
extern W2w1672 D_004f3b40;
extern W2w1672 D_004f3b48;
// 00161410: moved to src/anon/unit_001611a8.cpp (gcc makes the static init)

/* hand-written VU0 spline interpolation */
extern f32 D_003590a0[4];
void func_001f1408(f32* out, u8* a, u8* b, f32 t);  // 0x001f1408: definition moved into src/anon/unit_001f0cd8.cpp

struct E12w1672 { s32 key; s32 pad; s32 val; };
extern E12w1672 D_00361e70[9];
extern u8 D_00361ee8;
void wp_ctor_w1672(u8*, u32, u32, u32, u32) asm("_ZN2YS10WORLDPOINT16GetDisableReasonEi");
s32 get_part_num_w1672(u8*) asm("_ZN2YS3OBJ12get_part_numEv");
void func_002cb3f8(u8* p, u32 a1, u32 a2);  // 0x002cb3f8: definition moved into src/anon/unit_002cb200.cpp

void f17f488_w1672(u8*, int, float, float) asm("_Z13func_0017f488iiff");
u32 GetSystemPax_w1672(void) asm("_ZN2YS6EFFECT12GetSystemPaxEv");
u32 func_001de168(u32, u32, u32, u32, u32, u8*);
void func_001a1b30(u32, u32);
void func_001c8300(u8*, u32);
void func_001d1380(u8* p, u8* q);  // 0x001d1380: definition moved into src/anon/unit_001d12e8.cpp

extern u32 D_00352960;
extern u8 D_0036e680;
u8* func_001a5420(u32, u8*, u32);
void func_001da2b8(u32 a, s32 n);  // 0x001da2b8: definition moved into src/anon/unit_001d9d00.cpp

struct V4w1672 { f32 v[4]; } __attribute__((aligned(16)));
void func_00162a20(V4w1672*);
void func_00144908(u32, u8*);
void func_00162a88(u8* p, u32 b);  // 0x00162a88: definition moved into src/anon/unit_001614e8.cpp

extern u32 D_00363544;
extern u32 D_00363560;
void func_002edb38(void);
void set_special_command_w1672(u32, s32) asm("_ZN2YS6STDOBJ19set_special_commandEi");
void change_action_w1672(u8*, u32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
void func_002eb868(u8*, f32);
// 002eb890: moved to src/anon/unit_002eaf38.cpp

void motion_push_w1672(u8*, u32, f32, f32, u32) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
u32 member_Get_w1672(s32) asm("_ZN2YS6MEMBER3GetEi");
u32 member_get_part_w1672(u32, s32) asm("_ZNK2YS6MEMBER8get_partEi");
void party_voice_part_w1672(u8*, u32) asm("_ZN2YS5PARTY10voice_partEi");
void func_001b5ef0(u32);
void func_001d12e8(u8* p, u32 b);  // 0x001d12e8: definition moved into src/anon/unit_001d12e8.cpp

s32 func_002feac0(u8*);
typedef void (*FnWw1672)(u32);
s32 func_002fec78(u8* p, u32 i) {
    if (i >= 32) return -1;
    if (*(u32*)(p + 0x1d4) == 0 && func_002feac0(p) != 0) return -1;
    FnWw1672* slot = (FnWw1672*)((i << 2) + *(u32*)(p + 0x1d4));
    FnWw1672 fn = *slot;
    if (fn == 0) return 1;
    if (fn == (FnWw1672)-1) return 2;
    if (fn == (FnWw1672)1) return 3;
    *slot = 0;
    fn(i);
    return 0;
}

}
