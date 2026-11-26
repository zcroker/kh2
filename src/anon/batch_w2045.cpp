#include "../common/types.h"

// ---- shared declarations ----
extern "C" {
s32 func_001818e8();
u8* YS__COMMAND_ELEM__Get(u16);
void func_001bc720(void*);
void func_001bc730(u8*, s32);
void func_001bcc28(u8*);
s32 YS__COMMAND_MENU__check_close(u8*);
void func_001bce00(u8*);
s32 func_001bcf18(void*);
s32 YS__COMMAND_MENU__is_shortcut_menu(void*);
void func_001bd5b0(void*, s32, s32);
void func_001bd618(void*, s32);
void YS__PLAYER_COMMAND__decide(void*);
void func_002ba2e8(s32, s32);
}
struct W2045_S2240 { u8 pad[2240]; void** sp; };
struct W2045_Elem { u8 a[2]; u16 id; u8 b; u8 kind; u8 c[6]; };
struct W2045_Menu { u8 pad[4]; u8* o; s32 n; W2045_Elem e[8]; };
static inline bool w2045_entry_busy(void* e) {
    bool b = false;
    if (func_001bcf18(e) || YS__COMMAND_MENU__is_shortcut_menu(e)) b = true;
    return b;
}
static inline bool w2045_kind_ok(W2045_Elem* e) { return e->kind < 4; }

struct W2045_M44 {
    f32 m[16];
    W2045_M44() {}
    // lq/sq 64-byte copy (VU0 matrix copy)
    W2045_M44& operator=(const W2045_M44& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W2045_V4 { f32 v[4]; } __attribute__((aligned(16)));
struct W2045_Obj { u8 pad[8]; s32 flags; u8 pad2[16]; s32 h; u8 pad3[8]; W2045_Obj* next; };
struct W2045_Arg1 { u8 pad[16]; W2045_M44 m; };
extern "C" {
W2045_M44* func_00106ad0(s32);
void kn__Camera__getPosition(W2045_Arg1*, W2045_V4*);
void func_00107478(W2045_Arg1*, W2045_V4*);
void func_00143f78(void*, W2045_V4*);
void func_00146680(void*, W2045_M44*);
void func_001b81e8(void);
void func_001b8218(void);
s32 func_001dc738(W2045_Obj*);
s32 func_001dc790(W2045_Obj*);
s32 func_001dc9d0(W2045_Obj*);
s32 func_001dc9e0(W2045_Obj*);
void func_001dca70(W2045_Obj*);
void func_001dcae0(W2045_Obj*);
s32 func_001dcc60(W2045_Obj*);
s32 func_001dccc8(W2045_Obj*, u8);
void func_001e2c70(s32, s32);
void func_001e3330(s32);
void func_001e6250(void);
s32 func_001e6280(s32, s32);
void func_001e65c8(void);
void pppDeleteMng(s32);
void func_001e6ed8(W2045_M44*, s32, W2045_V4*, W2045_V4*);
void func_001e7008(f32);
extern f32 D_00349e10;
extern W2045_Obj* D_00352ae0;
extern u8 D_00352b00[];
}
static inline bool w2045_flag26(W2045_Obj* o) { u8 b = (o->flags >> 26) & 1; return b; }

struct W2045_V4b { f32 x, y, z, w; } __attribute__((aligned(16)));
struct W2045_Self { u8 pad[2848]; W2045_V4b dir; };
extern "C" {
W2045_V4b* YS__OBJ__get_pos(void);
f32 func_001065a8(f32, f32);
void func_002d1d30(W2045_V4b*, void*, W2045_V4b*);
f32 fabsf(f32);
extern void* D_00361f60;
}
// VU0 normalize xyz in place
static inline f32 w2045_norm(W2045_V4b* v) {
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}

extern "C" {

// ---- 0x1bc9e8 ----
s32 func_001bc9e8(u8* p);  // 0x001bc9e8: definition moved into src/anon/unit_001bc568.cpp

// ---- 0x1dd320 (VU0 matrix multiply asm) ----
void func_001dd320(s32 a0, W2045_Arg1* a1, u8 a2);  // 0x001dd320: definition moved into src/anon/unit_001dd2b8.cpp

// ---- 0x2d62d0 (VU0 normalize asm, lq/sq copy) ----
void Ti__Path__search_near_point_from_pre_point_nocycle(W2045_Self* self);  // 0x002d62d0: definition moved into src/anon/unit_002d62d0.cpp

}
