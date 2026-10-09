#include "../common/types.h"

extern "C" {

extern u32 D_0035f250;
extern u32 D_0035f254;
extern u32 D_0035f258;
extern u8 D_00374178[];
struct F { u8 pad[3]; u8 b3; void (*fn)(void); };
s32 func_00287db0(void);
s32 func_00139d78(u32);
s32 func_0028acc8(u32);
F* func_001040f8(void);
void func_001039f8(void);
s32 func_00289380(u32);
s32 func_00289310(u32);
s32 func_00287df0(s32, s32, s32, s32, s32);
s32 func_00242848(s32);
void func_00287da0(void);
s32 func_00280c38(void)
{
    s32 r;
    if (func_00287db0()) {
        if (func_00139d78(D_0035f250)) { r = 0; goto out; }
        if (func_00139d78(D_0035f258)) { r = 0; goto out; }
        if (func_0028acc8(D_0035f254)) { r = 0; goto out; }
        func_001040f8()->fn();
        func_001039f8();
        r = 1;
    } else {
        s32 s = func_00289380(D_0035f254);
        if (func_00242848(func_00287df0(s, func_00289310(D_0035f254), 0, 0, 1))) { r = 0; goto out; }
        if (s != -1) {
        func_001040f8()->b3 = D_00374178[s];
        func_00287da0();
        }
        r = 0;
    }
out:
    return r;
}


struct JV { f32 x, y, z, w; } __attribute__((aligned(16)));
struct JO;
typedef void (*JVF)(JV*, JO*);
struct JO { JVF* vt; };
struct JP { u8 pad[0x588]; u32 flags; };
struct JA { s32 state; JP* p; u8 pad[32]; JO* o; };
s32 func_00190140(void*);
f32 func_00191c20(void);
f32 func_00191c40(void);
f32 func_001906f0(void*, JV*);
void func_0019cc20(JA*);
void func_0019cd40(JA* a)
{
    JV t[3];
    t[0].w = 0;
    switch (a->state) {
    case 0:
        return;
    case 1:
        if (!func_00190140(&a->p)) break;
        return;
    case 2:
        if (func_00190140(&a->p)) {
            if (a->p->flags & 0x400) {
                if (!(func_00191c20() < 1.0f)) return;
            }
            JV v;
            a->o->vt[39](&v, a->o);
            f32 d = func_001906f0(&a->p, &v);
            if (!(func_00191c40() < d)) return;
        }
        break;
    default:
        return;
    }
    func_0019cc20(a);
}

}
