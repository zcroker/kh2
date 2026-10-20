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
void wt_001d6850(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_01d5ba78.a = 0;
        D_01d5ba78.b = 0;
        D_01d5ba78.c = 108.8f;
    }
    if (b == 0xffff && a == 1) {
        D_01d5ba88.a = 3;
        D_01d5ba88.b = 0;
        D_01d5ba88.c = 112.0f;
    }
}

struct W2w1672 { u32 a; u32 b; };
extern W2w1672 D_004f3b38;
extern W2w1672 D_004f3b40;
extern W2w1672 D_004f3b48;
void wt_00161410(u32 a, u32 b, u32, u32) asm("_Z16wtarget_00161410jjjj");
void wt_00161410(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) { D_004f3b38.b = 0; D_004f3b38.a = 0; }
    if (b == 0xffff && a == 1) { D_004f3b40.b = 0; D_004f3b40.a = 0; }
    if (b == 0xffff && a == 1) { D_004f3b48.b = 0; D_004f3b48.a = 0; }
}

/* hand-written VU0 spline interpolation */
extern f32 D_003590a0[4];
void func_001f1408(f32* out, u8* a, u8* b, f32 t) {
    s32 i = (s32)t;
    f32 f = t - (f32)i;
    a += i * 16;
    b += i * 16;
    D_003590a0[2] = f;
    asm volatile(
        ".set noreorder\n"
        "lqc2 $vf1,0(%1)\n"
        "lqc2 $vf2,16(%1)\n"
        "lqc2 $vf3,0(%2)\n"
        "lqc2 $vf4,16(%2)\n"
        "lqc2 $vf5,0(%3)\n"
        "vsub.xyzw $vf10,$vf4,$vf3\n"
        "vmuly.xyzw $vf11,$vf3,$vf5y\n"
        "vmulx.xyzw $vf12,$vf3,$vf5x\n"
        "vsub.xyzw $vf13,$vf2,$vf1\n"
        "vmulz.xyzw $vf10,$vf10,$vf5z\n"
        "vadd.xyzw $vf11,$vf11,$vf4\n"
        "vadd.xyzw $vf10,$vf10,$vf12\n"
        "vsub.xyzw $vf13,$vf13,$vf11\n"
        "vmulz.xyzw $vf10,$vf10,$vf5z\n"
        "vadd.xyzw $vf10,$vf10,$vf13\n"
        "vmulz.xyzw $vf10,$vf10,$vf5z\n"
        "vadd.xyzw $vf10,$vf10,$vf1\n"
        "sqc2 $vf10,0(%0)\n"
        ".set reorder\n"
        : : "r"(out), "r"(a), "r"(b), "r"(D_003590a0) : "memory");
}

struct E12w1672 { s32 key; s32 pad; s32 val; };
extern E12w1672 D_00361e70[9];
extern u8 D_00361ee8;
void wp_ctor_w1672(u8*, u32, u32, u32, u32) asm("_ZN2YS10WORLDPOINT16GetDisableReasonEi");
s32 get_part_num_w1672(u8*) asm("_ZN2YS3OBJ12get_part_numEv");
void func_002cb3f8(u8* p, u32 a1, u32 a2) {
    wp_ctor_w1672(p, a1, 5, a2, 1);
    *(u32*)(p + 0x9fc) = 0;
    *(u32*)p = (u32)&D_00361ee8;
    s32 n = get_part_num_w1672(p);
    for (s32 i = 0; i < 9; i++) {
        if (n == D_00361e70[i].key) { *(s32*)(p + 0x9fc) = D_00361e70[i].val; break; }
    }
}

void f17f488_w1672(u8*, int, float, float) asm("_Z13func_0017f488iiff");
u32 GetSystemPax_w1672(void) asm("_ZN2YS6EFFECT12GetSystemPaxEv");
u32 func_001de168(u32, u32, u32, u32, u32, u8*);
void func_001a1b30(u32, u32);
void func_001c8300(u8*, u32);
void func_001d1380(u8* p, u8* q) {
    f17f488_w1672(p + 0x140, 0x8a, 8.0f, 0.0f);
    *(u32*)(p + 0xb68) = func_001de168(GetSystemPax_w1672(), 0x13, 0, 1, 0, p);
    func_001a1b30(*(u32*)(p + 0x48c), q[0x1c]);
    func_001c8300(p, *(u16*)q);
}

extern u32 D_00352960;
extern u8 D_0036e680;
u8* func_001a5420(u32, u8*, u32);
void func_001da2b8(u32 a, s32 n) {
    if (D_00352960 != 0) {
        for (s32 i = 0; i < n; i++) {
            *(f32*)(func_001a5420(D_00352960, &D_0036e680, a) + 0x40) = 120.0f;
        }
    }
}

struct V4w1672 { f32 v[4]; } __attribute__((aligned(16)));
void func_00162a20(V4w1672*);
void func_00144908(u32, u8*);
void func_00162a88(u8* p, u32 b) {
    V4w1672 buf[2];
    V4w1672 d;
    func_00162a20(buf);
    asm volatile("lqc2 $vf1,0(%1)\n lqc2 $vf2,0(%2)\n vsub.xyzw $vf1,$vf1,$vf2\n sqc2 $vf1,0(%0)" : : "r"(&d), "r"(&buf[1]), "r"(&buf[0]) : "memory");
    f32 len;
    asm volatile("lqc2 $vf1,0(%1)\n vmul.xyz $vf1,$vf1,$vf1\n vaddy.x $vf1,$vf1,$vf1y\n vaddz.x $vf1,$vf1,$vf1z\n vsqrt Q,$vf1x\n vwaitq\n cfc2 $8,$vi22\n mtc1 $8,%0" : "=f"(len) : "r"(&d) : "$8", "memory");
    *(f32*)(p + 16) = len * 0.5f;
    func_00144908(b, p);
}

extern u32 D_00363544;
extern u32 D_00363560;
void func_002edb38(void);
void set_special_command_w1672(u32, s32) asm("_ZN2YS6STDOBJ19set_special_commandEi");
void change_action_w1672(u8*, u32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
void func_002eb868(u8*, f32);
void func_002eb890(u8* p, u32 b) {
    Q16w1672 z;
    asm volatile("vsub.xyzw $vf1,$vf0,$vf0\n sqc2 $vf1,0(%0)" : : "r"(&z) : "memory");
    *(Q16w1672*)(p + 32) = z;
    *(u32*)(p + 0x100) = 4;
    *(u32*)(p + 0x104) = 5;
    D_00363544 = 0;
    D_00363560 = 0;
    func_002edb38();
    set_special_command_w1672(b, 2);
    change_action_w1672(p, 48);
    func_002eb868(p, 0.0f);
}

void motion_push_w1672(u8*, u32, f32, f32, u32) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
u32 member_Get_w1672(s32) asm("_ZN2YS6MEMBER3GetEi");
u32 member_get_part_w1672(u32, s32) asm("_ZNK2YS6MEMBER8get_partEi");
void party_voice_part_w1672(u8*, u32) asm("_ZN2YS5PARTY10voice_partEi");
void func_001b5ef0(u32);
void func_001d12e8(u8* p, u32 b) {
    f17f488_w1672(p + 0x140, 0x89, 0.0f, 0.0f);
    motion_push_w1672(p + 0x140, 0, 0.0f, 0.0f, 0);
    party_voice_part_w1672(p, member_get_part_w1672(member_Get_w1672(-1), 3));
    func_001b5ef0(b);
}

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
