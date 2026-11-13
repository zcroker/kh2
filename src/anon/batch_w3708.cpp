// Partial asm in func_00198290: three small asm statements only fix sched2 order of the member re-init (same as twin func_001980d0).
// Partial asm in func_002c8680: one hand-written li of the loop constant fixes preheader order; rest is plain C.
#include "../common/types.h"
extern "C" {
void func_00169398(void*, u32, void*, s32, s32, f32);
void* func_00168b38(s32, s32, s32);
s32 func_00170d18(s32);
void func_0017ebe8(void*, s32);
void func_00195858(void*, u32);
void func_001b2f38(void*, s32, u32);
void func_001d56f0(void*);
void func_001dddd0(void*, s32);
extern u8 D_003503e0[];
extern u8 D_00350e48[];

// 00198290: moved to src/anon/unit_00197fe0.cpp
}
struct Sub { u8 pad[0x18c]; void* p18c; s32 x190; u8 pad2[4]; };
struct Cnt { u8 pad[0x19c]; s32 x19c; s32 x1a0; };
struct Self {
    u8 pad0[0xc4];
    Cnt cnt;          // 0xc4 .. 0x264
    u8 pad1[0x278 - 0x268];
    Sub subs[1];      // 0x278 (overlaps 0x290)
};
extern "C" {
s32 func_002c22f0(s32);
s32 func_002c2358(s32);
void func_001386e0(Sub*, s32, s32, s32, s32, s32);
void func_001396b0(Sub*);
void func_0031a260(Sub*, s32);
void func_00139660(Sub*);
void func_00139688(Sub*);
s32 func_0023aa18(void*);
s32 func_0023aa58(void*);
void func_00138c68(Sub*, s32, s32);
void func_002c8680(Self* self, s32 arg) {
    s32 n = func_002c22f0(arg);
    if (n != 0) {
        s32 i = 0;
        s32 m = func_002c2358(arg);
        Cnt* c; u8* z;
        if (i < n) {
c = &self->cnt; z = (u8*)self + 0x290; s32 e; asm("li %0,150" : "=r"(e)); Sub* s = self->subs;
            do {
                func_001386e0(s, 0x7585, *(s32*)((u8*)self + 0x1734), *(s32*)((u8*)self + 0x1730), i < m ? e : 149, 201);
                s->p18c = c;
                func_001396b0(s);
                if (s->p18c) {
                    s->x190 = 0;
                    func_001396b0(s);
                    if (s->x190) func_0031a260(s, 0);
                }
                func_00139660(s);
                func_00139688(s);
                s32 a = func_0023aa18(z);
                func_00138c68(s, a - func_0023aa58(z) * i, 0);
                func_001396b0(s);
                s++;
                i++;
            } while (i < n);
        } else {
c = &self->cnt; z = (u8*)self + 0x290;
        }
        s32 v = -func_0023aa58(z);
        c->x1a0 = 0;
        c->x19c = v * n / 2;
    }
}
}
