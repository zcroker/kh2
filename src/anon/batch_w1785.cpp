#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));

// 64-element static array (56-byte elements) at 0x01c62198
struct Sub19 { u32 a; u32 b; u32 c; u32 d; };
struct Elem19 { u32 x0; Sub19 s; u8 pad[36]; ~Elem19(); };
extern "C" void func_00199cd0(Elem19*);
inline Elem19::~Elem19() { func_00199cd0(this); }

extern "C" {
extern Elem19 D_01c62198[64];

// static initialization/destruction of D_01c62198
void wt19(u32 init, u32 prio, u32, u32) asm("_Z16wtarget_0019b970jjjj");
void wt19(u32 init, u32 prio, u32, u32)
{
    if (prio == 0xffff && init == 1) {
        Elem19* e = D_01c62198;
        Sub19* p = &e->s;
        for (int i = 63; i != -1; i--) {
            p->a = 0;
            p->d = 0;
            p->c = 0;
            p = (Sub19*)((u8*)p + 56);
        }
    }
    if (prio == 0xffff && init == 0) {
        Elem19* a = D_01c62198;
        if (a) {
            Elem19* p = a + 64;
            Elem19* base = a;
        top:
            if (p == base) goto out;
            p--;
            func_00199cd0(p);
            goto top;
        out:;
        }
    }
}

struct Pair32 { u8 a; u8 b; };
extern Pair32 D_0032bae0;
extern void* D_01c62fb0;
s8* func_00105ee8(s32);
struct Res168 { u32 x0; u32 x4; u32* x8; };
Res168* func_00168b88(void*, s32, s32, s32);

u32* func_0019f7d0(s32 idx, s32 id)
{
    s32 a = D_0032bae0.a;
    if (idx < 0) idx = D_0032bae0.b;
    void* h = D_01c62fb0;
    if (id < 0) id = a;
    s8* p = func_00105ee8(id);
    Res168* r = func_00168b88(h, 2, p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24), 0);
    if (r) {
        u32* t = r->x8;
        if (t) return t + idx;
    }
    return 0;
}

u64 func_00109ea8(u32 mode, s32 flag, u8 v)
{
    u8 n;
    switch (mode) {
    case 7:
        if (flag == 0) return v != 0x80 ? 0x5000d : 0x5078d;
    case 1:
    case 3:
    case 5:
        if (v != 0x80) {
            n = v > 16 ? 16 : 0;
            return 0x5000d | ((u64)n << 4);
        }
        return 0x5010d;
    case 11:
        if (flag == 0) return 0x50007 | ((u64)v << 4);
        break;
    default:
        break;
    }
    return 0x5000d;
}

void func_002f25a0(s32, s32);
void func_003058a0(s32);
void func_002f3918(void*, void*);
struct Pkt20 { u128 tag; u8 pad[112]; u64 rgb; u64 reg; };
extern Pkt20 D_01da8c40;
extern u8 D_00359150[];
extern void* D_003591c8;
}

void func_0020dff0(void*)
{
    u128 save = D_01da8c40.tag;
    D_01da8c40.tag = 0x70000008;
    D_01da8c40.rgb = D_00359150[0] | ((u64)D_00359150[1] << 8) | ((u64)D_00359150[2] << 16);
    D_01da8c40.reg = 61;
    func_002f25a0(0, 0);
    func_003058a0(0);
    func_002f3918(D_003591c8, &D_01da8c40);
    func_002f25a0(0, 0);
    D_01da8c40.tag = save;
}
