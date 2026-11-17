// 0017aad0: static init/destruct of the battle command objects. Partial asm: register pins plus empty asm in cmd_def and an empty asm input in cmd_set_t only steer scheduling (see asm_review.tsv).
// 0017aad0 best draft: 10 diffs (scheduling of 5 simple-object blocks), default flags -O2 -g0 C++. Also 10 with nsa/-g.
#include "../common/types.h"

// Static construction/destruction of the battle command table objects at 0x01c60030.
struct Flags { u32 v; };
struct Cmd { void* vt; u32 id; Flags f; u32 pad; };
struct Big { void* vt; };
struct NoTail { ~NoTail() {} };

extern "C" {
void func_0031e938(Flags*);
void func_002dfb10(Big*);
void func_002ea2d8(Big*);
void func_002dea00(Big*, f32, f32);
void func_002dea80(Big*);
extern void* D_0034eb00[];
extern void* D_0034eb30[];
extern void* D_0034eb60[];
extern void* D_0034eb90[];
extern void* D_003502a8[];
extern void* D_00350480[];
extern void* D_003504b0[];
extern void* D_003506c0[];
extern void* D_003506f0[];
extern void* D_00350720[];
extern void* D_00350fb0[];
extern void* D_00350fe0[];
extern void* D_00351010[];
extern void* D_00351040[];
extern void* D_00351190[];
extern void* D_00351288[];
extern void* D_003512b8[];
extern void* D_00351348[];
extern void* D_00351378[];
extern void* D_003514f0[];
extern void* D_00351520[];
extern void* D_00351550[];
extern void* D_00351ed8[];
extern void* D_00351f08[];
extern void* D_00351f40[];
extern void* D_003521a8[];
extern void* D_00352330[];
extern void* D_00352610[];
extern void* D_00352640[];
extern void* D_003526e0[];
extern void* D_00352710[];
extern void* D_00361950[];
extern void* D_00361ac0[];
extern void* D_00361af0[];
extern void* D_003624b8[];
extern void* D_003624e8[];
extern void* D_00362518[];
extern void* D_00362548[];
extern void* D_00362c18[];
extern void* D_00362c70[];
extern void* D_00362cc8[];
extern void* D_00362e00[];
extern void* D_00362e30[];
extern void* D_00362ef0[];
extern void* D_00362f20[];
extern void* D_003633d8[];
extern void* D_00363410[];
extern void* D_00363460[];
extern void* D_00363490[];
extern void* D_003634c0[];
extern void* D_00363510[];
extern void* D_00363578[];
extern void* D_003635a8[];
extern void* D_003635d8[];
extern void* D_00363608[];
extern void* D_00363660[];
extern void* D_00363690[];
extern void* D_003636c0[];
extern void* D_003636f0[];
extern void* D_00363928[];
extern void* D_00363958[];
extern void* D_00363988[];
extern void* D_003639b8[];
extern void* D_003639e8[];
extern void* D_00363a18[];
extern Cmd D_01c60030;
extern Cmd D_01c60040;
extern Cmd D_01c60050;
extern Cmd D_01c60060;
extern Cmd D_01c60070;
extern Cmd D_01c60080;
extern Cmd D_01c60090;
extern Cmd D_01c600a0;
extern Cmd D_01c600b0;
extern Cmd D_01c600c0;
extern Cmd D_01c600d0;
extern Cmd D_01c600e0;
extern Cmd D_01c600f0;
extern Cmd D_01c60100;
extern Cmd D_01c60110;
extern Cmd D_01c60120;
extern Cmd D_01c60130;
extern Cmd D_01c60140;
extern Cmd D_01c60150;
extern Cmd D_01c60160;
extern Cmd D_01c60170;
extern Cmd D_01c60180;
extern Cmd D_01c60190;
extern Cmd D_01c601a0;
extern Cmd D_01c601b0;
extern Cmd D_01c601c0;
extern Cmd D_01c601d0;
extern Cmd D_01c601e0;
extern Cmd D_01c601f0;
extern Cmd D_01c60200;
extern Cmd D_01c60210;
extern Big D_01c60220;
extern Cmd D_01c602a0;
extern Cmd D_01c602b0;
extern Big D_01c602c0;
extern Big D_01c60300;
extern Big D_01c60340;
extern Cmd D_01c60350;
extern Cmd D_01c60360;
extern Cmd D_01c60370;
extern Cmd D_01c60380;
extern Cmd D_01c60390;
extern Cmd D_01c603a0;
extern Cmd D_01c603b0;
extern Cmd D_01c603c0;
extern Cmd D_01c603d0;
extern Cmd D_01c603e0;
extern Cmd D_01c603f0;
extern Cmd D_01c60400;
extern Cmd D_01c60410;
extern Cmd D_01c60420;
extern Cmd D_01c60430;
extern Cmd D_01c60440;
extern Cmd D_01c60450;
extern Cmd D_01c60460;
extern Cmd D_01c60470;
extern Cmd D_01c60480;
extern Cmd D_01c60490;
extern Cmd D_01c604a0;
extern Cmd D_01c604b0;
extern Cmd D_01c604c0;
extern Cmd D_01c604d0;
extern Cmd D_01c604e0;
extern Cmd D_01c604f0;

static inline void cmd_set(Cmd* o, void** vt, u32 id, u32 fl) { *(u32*)&o->vt = (u32)vt; o->id = id; o->f.v = fl; }
#define cmd_def(O, VT, ID) do { register Cmd* o asm("$12") = (O); register u32 v asm("$15") = (u32)(VT); register u32 r asm("$14") = 0x100; o->f.v = r; r = (ID); asm volatile(""); *(u32*)&o->vt = v; o->id = r; } while (0)
static inline void cmd_set_t(Cmd* o, void** vt, u32 id, u32 fl) { *(u32*)&o->vt = (u32)vt; o->f.v = fl; o->id = id; asm("" : : "r"(fl)); }
static inline void cmd_base(Cmd* o, u32 id) { o->vt = D_0034eb00; o->id = id; func_0031e938(&o->f); }

void wt17aad0(u32 init, u32 prio, u32, u32) asm("_Z16wtarget_0017aad0jjjj");
void wt17aad0(u32 init, u32 prio, u32, u32);  // 0x0017aad0: definition moved into src/anon/unit_0017a8f8.cpp

}
