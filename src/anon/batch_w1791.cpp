#include "../common/types.h"
extern "C" {

struct Uc4Tgt { u8 pad[0x154]; s32 state; u8 pad2[0xa4c - 0x158]; u32 id; };
struct Uc4 { s32 kind; u8 pad4[8]; Uc4Tgt* tgt; u8 pad10[0x20]; u8 on; u8 pad31[0x1f]; f32 time; };
s32 func_0018bd50(u32, s32);
s32 func_0019ba60(Uc4Tgt*);
u32 u_call4_0018c598(u32 a, u32 b, u32 c, u32 d) asm("_Z16u_call4_0018c598jjjj");
u32 u_call4_0018c598(u32 a, u32 b, u32 c, u32 d) {
    Uc4* u = (Uc4*)a;
    if (!u->on) return 1;
    if (u->time <= 0.0f) return 1;
    if (u->kind == 4 && !func_0018bd50(b, 5)) return 1;
    if (u->kind == 5 && (!func_0019ba60(u->tgt) || u->tgt->id != b || u->tgt->state == 50)) return 1;
    return 0;
}

void func_0017f540(void*, s32, f32, f32);
struct Ch {
    u8 pad0[0x10];
    f32 f10, f14, f18, f1c;
    u8 pad20[0x110 - 0x20];
    f32 f110, f114;
    u8 pad118[0x140 - 0x118];
    u8 snd[0x20];
    u32 flags;
};
void func_001d22e0(void* a, Ch* c) {
    s32 id;
    f32 v = c->f1c;
    if (v > 0.0f) {
        if (c->f10 == 0.0f && c->f18 == 0.0f) {
            if (c->f14 < 0.0f) id = 154; else id = 155;
        } else {
            if (v < (c->f110 + c->f114) * 0.5f) id = 1; else id = 2;
        }
    } else {
        id = 0;
    }
    void* p = c->snd;
    if (c->flags & 4) func_0017f540(p, id, 20.0f, 0.0f);
}

void func_002fe0a0(const char*);
void func_002fd348(s32) __attribute__((noreturn));
extern char D_00370720[];
void func_002f28b8(void*, s32, s32, s32, s32, s32, s32, s32);
void func_002f25a0(s32, s32);
void func_003058a0(s32);
void func_002f2be0(void*, u32);
struct Tex {
    u16 w : 14;
    u16 pad0 : 2;
    u8 pad2[6];
    u8 b8;
    u8 b9;
    u8 b10;
    u8 pad11;
    s16 h12;
    s16 h14;
    u8 pad16[4];
    u32 data;
    u8 b24;
};
void func_0020e490(Tex* t, u32 flag) {
    u8 buf[96];
    if (!t->data) {
        func_002fe0a0(D_00370720);
        func_002fd348(1);
    }
    func_002f28b8(buf, (s16)t->w, t->b10 >> 2, t->b24, t->b8 << 4, t->b9 << 4, t->h12, t->h14);
    func_002f25a0(0, 0);
    func_003058a0(0);
    func_002f2be0(buf, t->data);
    if (flag) func_002f25a0(0, 0);
}

}
