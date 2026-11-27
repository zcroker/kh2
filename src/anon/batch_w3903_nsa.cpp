#include "../common/types.h"
extern "C" {
struct Tgt10ff08;
void func_00190128(Tgt10ff08*);
struct Tgt10ff08 {
    s32 f0, f4, f8, f12, f16;
    Tgt10ff08() { func_00190128(this); }
};
struct V10ff08 {
    f32 x, y, z, w;
    V10ff08() {}
    V10ff08(const V10ff08& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct Pt10ff08 { f32 x, y, z, w, r; };
struct Q10ff08 { u8 pad[8]; s32 n; };
struct Other10ff08 { u8 pad[384]; s32 level; };
struct Ent10ff08;
struct Who10ff08 { s32 dummy; };
typedef s32 (Who10ff08::*Pick10ff08)(Ent10ff08*, Tgt10ff08*, s32*, s32);
struct Ent10ff08 {
    u32 flags;
    Pick10ff08 pick;
    u8 pad[4];
    Q10ff08* q;
    u8 pad2[8];
    s32 slot;
    u8 pad3[4];
};
struct Cand10ff08 {
    Ent10ff08* e;
    Tgt10ff08 t;
    s32 score;
};
struct Cam10ff08 {
    u8 pad0[1164];
    Other10ff08* other;
    u8 pad1[2548 - 1168];
    Tgt10ff08 tgt;
    u8 pad1b[2912 - 2568];
    Who10ff08* who;
    u8 pad2[2940 - 2916];
    u32 flags;
    u8 pad3[3072 - 2944];
    V10ff08 dir;
    u8 pad3b[3168 - 3088];
    Ent10ff08* cur;
    s32 score;
    u8 pad4[3304 - 3176];
    s32 count;
};
extern s8 D_003a9618;
extern Cand10ff08 D_003a9620[32];
s32 func_0010fb10(Cam10ff08*);
s32 func_0010f8d0(Cam10ff08*);
s32 func_001137e0(Who10ff08*);
Ent10ff08* func_001137e8(Who10ff08*);
s32 YS__SHEET__is_mpdrive(Other10ff08*);
s32 func_0010f648(s32);
s32 func_0010f600(Cam10ff08*);
f32 func_0010f660(void);
f32 func_001142b0(Who10ff08*);
s32 func_001137f0(Who10ff08*);
Pt10ff08* func_00113808(Who10ff08*, s32);
void func_0010c9f8(Cam10ff08*, f32, f32, f32, f32, f32);
void func_0010ef28(Cam10ff08*, Ent10ff08*);
void func_0010eed8(Cam10ff08*, Ent10ff08*, s32);
void func_00110630(Cam10ff08*);
Ent10ff08* func_0010fea0(Cam10ff08*);
u8* func_00112570(Cam10ff08*);
void YS__OBJ__set_wish_dir(Cam10ff08*, V10ff08*);
// func_0010ff08: camera target choice. Collects candidate entities whose pick callback accepts them
// (pass 0 skips kind 2 and entities refused by YS__SHEET__is_mpdrive, pass 1 takes only kind 2), then picks one at random.
void func_0010ff08(Cam10ff08* c);  // 0x0010ff08: definition moved into src/anon/unit_0010fea0.cpp
}
