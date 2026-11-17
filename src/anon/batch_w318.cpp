#include "../common/types.h"
struct T318 { u32 a, b, c, d, e; };
struct A318 { u8 pad[2548]; T318 t; u8 pad2[2924-2568]; int idx; u8 pad3[12]; u32 fl; };
typedef void (A318::*P318)(T318*, void*);
struct E318 { P318 f; } __attribute__((aligned(8)));
struct R318 { u32 pfn; int d; } __attribute__((aligned(8)));
extern E318 D_00345b28[];
typedef void (*F318)(void*, T318*, void*);
#define QCOPY318(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "memory")
struct Q318 {
    union { u32 v[4]; f32 f[4]; };
    Q318() {}
    Q318(f32 x, f32 y, f32 z, f32 w) { f[0] = x; f[1] = y; f[2] = z; f[3] = w; }
    Q318(const Q318& o) { QCOPY318(this, &o); }
    Q318& operator=(const Q318& o) {
        if (this != &o) QCOPY318(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct E318c { u8 b0, b1, b2, b3; union { f32 x; s32 ix; }; f32 y, z; };
struct H318 { u16 h0, h2; };
struct O318 { u8 pad[108]; H318* h; };
struct R318c { s32 a; s32 b; s32 c; s32 d; Q318 q; O318* obj; u8 b36; u8 pad[3]; f32 f40; f32 f44; u8 pad2[32]; f32 f80; };
struct K318 { u8 pad[388]; s32 f388; };
struct L318 { u8 pad[396]; void* f396; s32 f400; u8 pad2[4]; };
extern "C" {
void func_00190128(void*);
int func_00190140(void*);
int func_00190680(void*, T318*);
int func_001b58a8(void);
int func_00112720(void*);  // check_2924_lt14
void func_0010df18(A318* p);  // 0x0010df18: definition moved into src/anon/unit_0010dee8.cpp

u32 func_001064a8(int);  // int_to_float_scaled
void func_0018c438(R318c*);
int func_0018c528(int);
int func_0016b740(s32);
f32 func_00106558(f32);
f32 func_001db510(O318*, Q318);
f32 func_001065a8(f32, f32);
int func_0018c650(R318c* o, Q318* v, int n, E318c* tab, O318* obj, f32 fa, f32 fb);  // 0x0018c650: definition moved into src/yasui/libys/npc.cpp

s32 func_0013dda0(int);
s32 func_00158290(void*);
s32 func_0013a7e8(int);
s32 func_0013d7e0(void);
int func_00156030(void*);
s32 func_00155f40(void*);
s32 func_00155ee8(void*);  // state_dispatch_0_4
s32 func_00155fc0(void*);
int func_00139c18(void*);
void func_001386e0(void*, int, s32, s32, int, s32);
void func_001396b0(void*);
void func_0031a260(void*, int);
int func_001396c0(void*);
void func_00139570(void*);
int func_00156058(void*);  // state_code_is_2
int func_00156080(void*);  // state_code_is_3
void func_00138c10(void*, s32);
void func_00156d20(void*);
void func_00156408(void*);
void func_001581f8(void*);
void func_001542c8(void*, s32, s32);
void func_001575c0(void*);
// 00156e48: moved to src/anon/unit_00153ea0.cpp
void func_00156e48(u8* p);
}
