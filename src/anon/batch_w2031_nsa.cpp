#include "../common/types.h"

extern "C" {

s32 get_part_num_0016a070(s32) asm("_ZN2YS3OBJ12get_part_numEv");
s32 func_001a3888(s32);

struct W2031_PE { s32 a; s32 b; s32 c; s32 d; s32 e; W2031_PE* next; };
struct W2031_Pool { W2031_PE e[4]; s32 fr[4]; s32 n; };
struct W2031_PL { W2031_PE* head; W2031_PE* tail; };
extern W2031_Pool D_01c620c8;
extern W2031_PL D_01c62140;

struct W2031_N { f32 t; s32 b; s32 a; s32 r; s32 c; W2031_N* next; };
struct W2031_NL { W2031_N* head; W2031_N* tail; };
extern W2031_NL D_01d48de0;

struct W2031_V5 { s32 v[5]; };

void func_0010cae8(u8* a0, u8* a1) {
    *(u16*)(a0 + 0xc30) = 1;
    *(W2031_V5*)(a0 + 0xc38) = *(W2031_V5*)(a0 + 0x9f4);
    *(s32*)(a0 + 0xb78) = 0;
    *(u8**)(a0 + 0xc68) = a1;
    if (*(s32*)(a0 + 0x48c) != 0 && *(s32*)(a1 + 8) != 0) a0[0xc35] = a1[8];
    else a0[0xc35] = 0;
}

// 001994d8: moved to src/anon/unit_001991a8.cpp

// 001ba168: moved to src/yasui/libys/itemeffect.cpp

}
