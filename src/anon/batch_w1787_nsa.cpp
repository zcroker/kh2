#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
extern "C" {

/* 0013eeb8 */
struct Pkt13eeb8 { u32 a; u32 b; u128* p; };
struct Obj13eeb8 { u8 pad[0x10]; u8 c[4]; u8 pad2[0xc]; union { u128 q[15]; struct { u8 pad[0xa8]; u64 tag; } t; }; };
void func_0013eb00(Obj13eeb8*);
void func_001b7e68(Pkt13eeb8*, s32);
void func_001b80d8(Pkt13eeb8*);
void func_001b7f30(Pkt13eeb8*);
void func_0013eeb8(Obj13eeb8* o);  // 0x0013eeb8: definition moved into src/anon/unit_0013dfb8.cpp

/* 00236200 */
extern u64 D_0035e3c0[6];
extern u64 D_0035e3f0[10];
void func_003058a0(s32);
void u_call0_00236200() asm("_Z16u_call0_00236200v");
void u_call0_00236200() {
    D_0035e3c0[0] = 0x70000002;
    D_0035e3c0[2] = (1ULL << 60) | 0x8001;
    D_0035e3c0[3] = 0xe;
    D_0035e3c0[4] = 0x30000;
    D_0035e3c0[5] = 0x47;
    D_0035e3f0[0] = 0x70000004;
    D_0035e3f0[2] = (3ULL << 60) | 0x8001;
    D_0035e3f0[3] = 0xeee;
    D_0035e3f0[4] = 5;
    D_0035e3f0[5] = 8;
    D_0035e3f0[6] = 0x60;
    D_0035e3f0[7] = 0x14;
    D_0035e3f0[8] = 0x44;
    D_0035e3f0[9] = 0x42;
    func_003058a0(0);
}

/* 00283c50 */
struct E8b283c50 { u32 a; u16 id; u16 b; };
extern E8b283c50 D_003742c8[];
s32 func_00181500(u16);
struct Sv283c50 { u8 pad[200]; u32 bits[1]; };
Sv283c50* func_00258048();
void func_00283c50(void);  // 0x00283c50: definition moved into src/anon/unit_00282c68.cpp

/* 002dbad8 */
extern f32 D_00349e10;
void func_00187750(void*);
f32 fabsf(f32);
struct Obj2dbad8 {
    u8 pad0[0xbc0];
    u8 flag;          /* bc0 */
    u8 pad1[0x13];
    f32 a;            /* bd4 */
    u8 pad2[8];
    f32 v[4];         /* be0 */
    u8 pad3[4];
    f32 c;            /* bf4 */
};
void func_002dbad8(Obj2dbad8* p);  // 0x002dbad8: definition moved into src/anon/unit_002da040.cpp

}
