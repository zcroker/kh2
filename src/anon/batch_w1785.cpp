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
void wt19(u32 init, u32 prio, u32, u32);  // 0x0019b970: definition moved into src/anon/unit_00199688.cpp

struct Pair32 { u8 a; u8 b; };
extern Pair32 D_0032bae0;
extern void* D_01c62fb0;
s8* func_00105ee8(s32);
struct Res168 { u32 x0; u32 x4; u32* x8; };
Res168* func_00168b88(void*, s32, s32, s32);

u32* func_0019f7d0(s32 idx, s32 id);  // 0x0019f7d0: definition moved into src/anon/unit_0019ee80.cpp

u64 func_00109ea8(u32 mode, s32 flag, u8 v);  // 00109ea8: moved to src/anon/unit_00109c30.cpp

void sceGsSyncPath(s32, s32);
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
    sceGsSyncPath(0, 0);
    func_003058a0(0);
    func_002f3918(D_003591c8, &D_01da8c40);
    sceGsSyncPath(0, 0);
    D_01da8c40.tag = save;
}
