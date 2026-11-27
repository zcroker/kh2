#include "../common/types.h"

extern "C" {

struct W2043a_Vq {
    f32 x, y, z, w;
    W2043a_Vq() {}
    W2043a_Vq(const W2043a_Vq& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W2043a_Vq& operator=(const W2043a_Vq& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); return *this; }
} __attribute__((aligned(16)));
struct W2043a_Tgt { u8 pad[0x588]; u32 f588; };
struct W2043a_Hdl { W2043a_Tgt* p; u8 pad[0x1c]; };
struct W2043a_Obj;
struct W2043a_Vt { u8 pad[0x98]; s32 (*f98)(W2043a_Obj*); };
struct W2043a_Obj {
    W2043a_Vt* vt; u8 p0[0x9f4 - 4];
    W2043a_Hdl h;               // 9f4
    u8 p1[0xb60 - 0xa14];
    void* b60;
    u8 p2[0xb7c - 0xb64];
    s32 flags;           // b7c
    u8 b80[0x30];        // b80
    f32 fbb0pad[0];
    u8 bb0[0x1c];        // bb0
    f32 bcc;             // bcc
    u8 p4[0x20];
    f32 bf0;             // bf0
};
W2043a_Vq* YS__OBJ__get_pos(W2043a_Obj*);
void func_00190128(void*);
s32 func_00190140(W2043a_Hdl*);
W2043a_Vq func_00190388(W2043a_Hdl*);
f32 YS__TARGET__get_dist(W2043a_Hdl*, W2043a_Vq*);
void func_00190878(W2043a_Hdl*, u32, s32);
void func_0010b620(void*, W2043a_Vq*, W2043a_Vq*);
s32 func_001917c0(void);
f32 func_00114370(void*);
s32 func_0010f8d0(W2043a_Obj*);
void func_0010df18(W2043a_Obj*);
s32 func_0010d188(W2043a_Obj*);
extern u32 D_00341708;

s32 W2043_ctarget_0010e130(W2043a_Obj* o, u8 a1) asm("_Z24kn__Friend__updateTargetjjjj");
s32 W2043_ctarget_0010e130(W2043a_Obj* o, u8 a1);  // 0x0010e130: definition moved into src/anon/unit_0010dee8.cpp


struct W2043b_Vq {
    f32 x, y, z, w;
    W2043b_Vq& operator=(const W2043b_Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline W2043b_Vq W2043b_vsub(const W2043b_Vq& a, const W2043b_Vq& b) {
    W2043b_Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 W2043b_vnormalize(W2043b_Vq* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
struct W2043b_Tg;
struct W2043b_TgVt { u8 pad[0x60]; s32 (*f60)(W2043b_Tg*); void (*f64)(W2043b_Tg*, void*); };
struct W2043b_Tg { W2043b_TgVt* vt; };
struct W2043b_Hdl { W2043b_Tg* p; u8 pad[0x1c]; };
struct W2043b_Res { W2043b_Vq a; W2043b_Vq b; };
struct W2043b_Ent { W2043b_Vq v; u8 pad[8]; u32 f18; };
struct W2043b_Obj { u8 p0[4]; u32 f4; u8 p1[0x620 - 8]; void* f620; s32 f624; };
void* func_00106a60(s32);
void kn__Camera__getPosition(void*, W2043b_Vq*);
void* func_001050d8(u32);
void YS__ATTACK__ATTACK_2(void*, u32, u32, u32, u32, s32, s32);
void func_00190128(void*);
void* YS__TARGET__each(W2043b_Hdl*, void*);
s32 func_00112d90(W2043b_Hdl*);
s32 func_001901c0(W2043b_Hdl*);
s32 func_0018d940(void*, W2043b_Tg*);
s32 func_0019c410(W2043b_Tg*);
void* func_00112f88(W2043b_Hdl*);
void YS__COLLISION__set(W2043b_Res*, W2043b_Tg*, void*);
W2043b_Ent* YS__ATTACK__strike(void*, W2043b_Tg*, u32, u32);
void func_0018ca10(W2043b_Ent*);
void YS__PRIZE__Appear(W2043b_Vq*, s32);

void func_00118378(W2043b_Obj* o, s32 a1);  // 0x00118378: definition moved into src/anon/unit_001182d0.cpp


struct W2043c_Vq { f32 x, y, z, w; W2043c_Vq() {} W2043c_Vq(f32 a, f32 b, f32 c, f32 e) { x = a; y = b; z = c; w = e; } } __attribute__((aligned(16)));
struct W2043c_Mat { W2043c_Vq r[4]; };
struct W2043c_Sub { W2043c_Vq r[3]; s32 fc_pad[0]; s32 idx[9]; };
struct W2043c_Dat { u8 p0[0x2c]; s32 f2c; s32 f30; s32 f34; s32 f38; u8 p1[0x90 - 0x3c]; f32 f90; f32 f94; f32 f98; };
struct W2043c_Obj { u8 p0[4]; W2043c_Dat* d; };
void func_0011b6a8(W2043c_Mat*);
void func_001285f8(W2043c_Obj*, s32*, s32*, f32);
f32 func_00128750(W2043c_Obj*, void*, s32, s32, f32);
void func_0011b6d8(W2043c_Mat*, f32);
void func_0011b720(W2043c_Mat*, f32);
void func_0011b768(W2043c_Mat*, f32);
static inline void W2043c_m_trans(W2043c_Mat* m, W2043c_Vq* v) {
    asm volatile("lqc2 $vf1, 48(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 48(%0)" : : "r"(m), "r"(v) : "memory");
}
static inline void W2043c_m_scale(W2043c_Mat* m, W2043c_Vq* v) {
    asm volatile("lqc2 $vf4, 0(%1)\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 16(%0)\n\tlqc2 $vf3, 32(%0)\n\tvmulx.wxyz $vf1, $vf1, $vf4x\n\tvmuly.wxyz $vf2, $vf2, $vf4y\n\tvmulz.wxyz $vf3, $vf3, $vf4z\n\tsqc2 $vf1, 0(%0)\n\tsqc2 $vf2, 16(%0)\n\tsqc2 $vf3, 32(%0)" : : "r"(m), "r"(v) : "memory");
}

s32 kn__MotionPrototype0__getPosition(W2043c_Obj* o, W2043c_Mat* m, f32 t);  // 0x00131450: definition moved into src/anon/unit_00131418.cpp

}
