#include "../common/types.h"
// Built with -fno-strict-aliasing (_nsa).

struct W2030Pair { s32 a; s32 b; inline void Clear() { b = 0; a = 0; } };
struct W2030Q { s32 v; };
struct W2030P {
    u8 pad0[0x64];
    s32* r;            // 0x64
    W2030Q q;          // 0x68
    u8 pad6c[0x74 - 0x6c];
    s32 a;             // 0x74
    f32 f;             // 0x78
    u8 pad7c[0x85 - 0x7c];
    u8 b;              // 0x85
};

extern "C" {

extern W2030Pair D_01e2a5e8;
extern W2030Pair D_01e2a5f0;
extern s32 D_0032b91c;
void func_002bad20(void);
void func_00102818(s32, s32, s32, void (*)(void), s32);
s32* func_002e34d8(W2030Q*, s32);

void func_002bacc0(void) {
    D_01e2a5e8.Clear();
    D_01e2a5f0.Clear();
    func_00102818(D_0032b91c, 0, 0x7a508, func_002bad20, 0x1800);
}

void func_002e0fa0(W2030P* p, s32 a) {
    p->a = a;
    p->r = func_002e34d8(&p->q, a);
    p->f = (f32)*p->r;
    p->b = 1;
}

}
