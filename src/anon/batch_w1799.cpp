#include "../common/types.h"
extern "C" {

// ---- func_002ab818 ----
struct W1799E { u8 a, b; u16 id; };
struct W1799T { u8 a, b, type; };
W1799T* func_001a80c8(u16);
W1799E* func_001a82b0(W1799E*);
s32 func_002a43b0(W1799E*);
s32 func_002a9d68();
extern s32 D_0035f610;

void func_002ab818(void) {
    W1799E* p = 0;
    u32 i = 0;
    s32 bits = func_002a9d68() + 300;
    for (;;) {
        do {
            p = func_001a82b0(p);
            if (p == 0) return;
        } while (func_001a80c8(p->id)->type != 22);
        {
            s32 r = func_002a43b0(p);
            u32 w = (i >> 5) * 4;
            u32 m = 1 << (i & 31);
            i++;
            if (__builtin_expect(r == 0, 0)) continue;
            if (*(u32*)(w + bits) & m) continue;
            s32 d = D_0035f610 + 300; *(u32*)(d + w) |= m;
        }
    }
}

// ---- func_002d94b8 ----
s32 w1799_IsExec(void) asm("_ZN2YS5EVENT6IsExecEv");
f32 w1799_GetRestTime(void) asm("_ZN2YS5EVENT11GetRestTimeEv");
void w1799_texanm_start(u8* obj, s32 n) asm("_ZN2YS3OBJ12texanm_startEi");
void w1799_change(u8* mot, s32 n, f32 a, f32 b) asm("_ZN2YS6MOTION6changeEiff");
void w1799_ut_1c0d38(u8*, s32, s32, s32) asm("_Z16u_tail4_001c0d38jjjj");
u8* func_0016b740(s32);
void func_002db968(u8*, u8);
extern s32 D_0034e948;
struct W1799Obj { u8 pad[200]; u8 flag; u8 active; };

s32 func_002d94b8(W1799Obj* self) {
    if (self->active) {
        if (!w1799_IsExec() || w1799_GetRestTime() < 1.0f) {
            self->active = 0;
            u8* o = func_0016b740(1630);
            w1799_texanm_start(o, 12);
            if (self->flag) {
                w1799_ut_1c0d38(o, D_0034e948, 67, 0);
                w1799_change(o + 320, 0, 0.0f, 0.0f);
            }
            func_002db968(o, self->flag);
            return 1;
        }
    }
    return 0;
}

}
