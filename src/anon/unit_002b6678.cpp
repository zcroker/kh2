// Linked unit (see linked_units.tsv); one namespace per old matched source.
#include "../common/types.h"
#include "tiny_auto80_solver_structs.hpp"
#include <stdarg.h>

// 002b6678 (was src/anon/batch_w61_O0.cpp)
namespace n002b6678 {
void func_003058a0(u32) asm("func_003058a0");
struct E64 { u32 used; u8 pad[60]; };
extern E64 D_01e22080[512] asm("D_01e22080");
/*TARGET 002b6678*/
// Returns the index of the first free 64-byte slot, or -1.
s32 func_002b6678(void) asm("func_002b6678");
// Returns the index of the first free 64-byte slot, or -1.
s32 func_002b6678(void) {
    func_003058a0(0);
    for (s32 i = 0; i < 512; i++) {
        if (D_01e22080[i].used == 0) return i;
    }
    return -1;
}
}  // namespace n002b6678

// 002b6708, 002b691c (were whole asm: src/anon/asm_002b6708.s, asm_002b691c.s)
// Sound driver (SIF RPC) code, built -O0 with the default -G8 in retail: its two globals at gp-7464/gp-7460 and
// two short .sdata strings are addressed from $gp. A -G0 unit reaches them through a $gp register variable.
namespace n002b6708 {
extern "C" {
s32 func_002b6678(void);
void FlushCache(s32);
s32 sceSifDmaStat(s32);
void func_002fdfc8(const char*, ...);
s32 sceSifBindRpc(void*, u32, s32);
s32 sceSifCallRpc(void*, u32, u32, void*, s32, void*, s32, void*, void*);
}
u32 sceSifSetDma(void*, s32) asm("func_00308310");
void w_002fde18(void*, u32, u32) asm("_Z16wtarget_002fde18jjjj");
struct DmaT { void* src; void* dst; s32 size; s32 attr; };
extern DmaT D_0035f6e0[] asm("D_0035f6e0");
extern s32 D_01e22080[] asm("D_01e22080");
extern s32 D_0032b920 asm("D_0032b920");
struct RpcCd { u8 pad[0x24]; void* serve; };
extern RpcCd D_01e22040 asm("D_01e22040");
struct SndBuf { s32 a; void* b; void* c; void* d; u8 pad[240]; };
extern SndBuf D_01e21f40 asm("D_01e21f40");
extern u8 D_01e2a080[] asm("D_01e2a080");
extern u8 D_01e2a3c0[] asm("D_01e2a3c0");

// Copies n int arguments into a free 64-byte command slot and DMAs it to the IOP; returns the slot.
s32 func_002b6708(s32 n, ...) asm("func_002b6708");
s32 func_002b6708(s32 n, ...) {
    register s32* gp asm("$28");
    va_list ap;
    s32 i;
    s32 r;
    s32 id;
    id = func_002b6678();
    if (id < 0) return -1;
    va_start(ap, n);
    for (i = 0; i < n; i++) {
        D_01e22080[id * 16 + i] = va_arg(ap, s32);
    }
    D_01e22080[id * 16 + 15] = 1;
    (&D_0035f6e0[id])[0].src = &D_01e22080[id * 16];
    (&D_0035f6e0[id])[0].dst = (void*)(gp[-1866] + id * 64);
    (&D_0035f6e0[id])[0].size = 64;
    (&D_0035f6e0[id])[0].attr = 0;
    FlushCache(0);
retry:
    r = sceSifSetDma(&D_0035f6e0[id], 1);
    if (r == 0) {
        func_002fdfc8("\x1b[44m%06d:\x1b[0m", D_0032b920);
        func_002fdfc8("PlayList dma error = %d\n", r);
        goto retry;
    }
    while (sceSifDmaStat(r) >= 0);
    return id;
}

// Binds the sound RPC server and exchanges the buffer addresses with the IOP.
s32 func_002b691c(u32 a0) asm("_Z16u_call4_002b691cjjjj");
s32 func_002b691c(u32 a0) {
    register s32* gp asm("$28");
    s32 cnt;
    s32 r;
    w_002fde18(D_01e22080, 0, 0x8000);
    w_002fde18(&D_01e21f40, 0, 256);
    while (1) {
        if (sceSifBindRpc(&D_01e22040, 17, 0) < 0) {
            func_002fdfc8("\x1b[44m%06d:\x1b[0m", D_0032b920);
            func_002fdfc8("SslInit Bind Error\n");
            return -1;
        }
        if (D_01e22040.serve != 0) break;
        cnt = 0x10000;
        while (--cnt != -1);
    }
    D_01e21f40.a = a0;
    D_01e21f40.b = D_01e2a080;
    D_01e21f40.c = D_01e22080;
    D_01e21f40.d = D_01e2a3c0;
    do {
        r = sceSifCallRpc(&D_01e22040, 0, 0, &D_01e21f40, 256, &D_01e21f40, 256, 0, 0);
    } while (r != 0);
    gp[-1866] = D_01e21f40.a;
    gp[-1865] = (s32)D_01e21f40.b;
    return 0;
}
}  // namespace n002b6708

// 002b6ab8 (was src/anon/batch_w200_O0.cpp)
namespace n002b6ab8 {
/*TARGET 002b6ab8*/
u32 func_002b6ab8() asm("func_002b6ab8");
u32 func_002b6ab8() { return 0; }
}  // namespace n002b6ab8

// 002b6adc (was src/anon/batch_w210_O0.cpp)
namespace n002b6adc {
u32 func_002b6708(u32, u32, u32, u32) asm("func_002b6708");
/*TARGET 002b6adc*/
u32 func_002b6adc(u32 a, u32 b) asm("func_002b6adc");
u32 func_002b6adc(u32 a, u32 b) { return func_002b6708(3, 6, b, a); }
}  // namespace n002b6adc

// 002b6b24 (was src/anon/batch_w37_O0.cpp)
namespace n002b6b24 {
s32 func_002b6708(s32, s32, u32, u32, u32, u32, u32) asm("func_002b6708");
/*TARGET 002b6b24*/
s32 func_002b6b24(u32 a, u32 b, u32 c, u32 d, u32 e) asm("func_002b6b24");
s32 func_002b6b24(u32 a, u32 b, u32 c, u32 d, u32 e) {
    return func_002b6708(6, 7, a, b, c, d, e);
}
}  // namespace n002b6b24

// 002b6b84 (was src/anon/batch_w208_O0.cpp)
namespace n002b6b84 {
extern void* func_002b6708(int, int, void*) asm("func_002b6708");
void* func_002b6b84(void*) asm("_Z13func_002b6b84Pv");
/*TARGET 002b6b84*/
void* func_002b6b84(void* a) asm("_Z13func_002b6b84Pv");
void* func_002b6b84(void* a) { return func_002b6708(2, 8, a); }
}  // namespace n002b6b84

// 002b6bc4 (was src/anon/batch_w206_O0.cpp)
namespace n002b6bc4 {
s32 func_002b6708(s32, s32, s32) asm("func_002b6708");
/*TARGET 002b6bc4*/
s32 func_002b6bc4(s32 a) asm("func_002b6bc4");
s32 func_002b6bc4(s32 a) { return func_002b6708(2, 9, a); }
}  // namespace n002b6bc4

// 002b6c04 (was src/anon/batch_w208_O0.cpp)
namespace n002b6c04 {
extern void* func_002b6708(int, int, void*) asm("func_002b6708");
/*TARGET 002b6c04*/
void* func_002b6c04(void* a) asm("func_002b6c04");
void* func_002b6c04(void* a) { return func_002b6708(2, 10, a); }
}  // namespace n002b6c04

// 002b6c44, 002b6d34, 002b6e24 (were whole asm: src/anon/asm_002b6c44.s, asm_002b6d34.s, asm_002b6e24.s)
// Wave/BGM/SE data loaders: check the 2-byte header, else print an error with a hex dump.
// Retail printed two short .sdata strings (gp-7480 "\x1b[41m", gp-7472 "\x1b[0m") through a gp-relative `la` that gas
// cannot move into the jal delay slot: here the address goes straight into $4 and a label on the call keeps gas from
// filling the slot.
namespace n002b6c44 {
extern "C" void func_002fdfc8(const char*, ...);
extern s32 D_0032b920 asm("D_0032b920");
s32 func_002b6708(s32, ...) asm("func_002b6708");
void func_002b6550(char*, s32) asm("func_002b6550");
void func_002b6adc(s32, u32) asm("func_002b6adc");
void w_002b7078(u32) asm("_Z16wtarget_002b7078jjjj");
void func_002b72e4(u32, s32, s32) asm("func_002b72e4");
struct Hd { char a; char b; };

#define DATA_ERROR(msg, s) \
    { \
        register char* gp asm("$28"); \
        func_002fdfc8("\x1b[44m%06d:\x1b[0m", D_0032b920); \
        func_002fdfc8(msg); \
        { register char* p asm("$4"); p = gp - 7480; red: func_002fdfc8(p); } \
        func_002b6550((char*)(s), 8); \
        { register char* p asm("$4"); p = gp - 7472; reset: func_002fdfc8(p); } \
    }

s32 func_002b6c44(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_002b6c44jjjj");
s32 func_002b6c44(u32 a0, u32 a1, u32 a2, u32 a3) {
    char* s;
    s = (char*)a1;
    if (((Hd*)s)->a != 'W' || ((Hd*)s)->b != 'D') {
        DATA_ERROR("sound wave data error !!\n", a1)
        return 0;
    } else {
        func_002b6adc(0, a0);
        return func_002b6708(5, 11, a0, a1, a2, a3);
    }
}

s32 func_002b6d34(u32 a0, u32 a1, u32 a2) asm("_Z13func_002b6d34Pv");
s32 func_002b6d34(u32 a0, u32 a1, u32 a2) {
    char* s;
    s = (char*)a1;
    if (((Hd*)s)->a != 'B' || ((Hd*)s)->b != 'G') {
        DATA_ERROR("sound bgm data error !!\n", a1)
        return 0;
    } else {
        w_002b7078(a0);
        func_002b6adc(1, a0);
        return func_002b6708(4, 12, a0, a1, a2);
    }
}

s32 func_002b6e24(s32 a0, u32 a1, u32 a2) asm("func_002b6e24");
s32 func_002b6e24(s32 a0, u32 a1, u32 a2) {
    char* s;
    s = (char*)a1;
    if (((Hd*)s)->a != 'S' || ((Hd*)s)->b != 'e') {
        DATA_ERROR("sound se data error !!\n", a1)
        return 0;
    } else {
        if (a0 >= 0) func_002b72e4(a0, -1, -1);
        func_002b6adc(2, a0);
        return func_002b6708(4, 13, a0, a1, a2);
    }
}
#undef DATA_ERROR
}  // namespace n002b6c44
