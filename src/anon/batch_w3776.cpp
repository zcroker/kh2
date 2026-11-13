#include "../common/types.h"
extern "C" {
struct Ent149448 { u8 pad[8]; s32 data; };
struct Part149448 { s32 a; s32 b; s32 c; };
struct Map149448 {
    char name[32];
    s32 bar;
    s32 f24, f28, f2c, f30, f34, f38, f3c, f40, f44, f48, f4c, f50;
    s32 tex[4];
    s32 f64, f68;
    s32 nSk0, nSk1, nBob;
    Part149448 parts[96];
    s32 nTex;
};
s32 m149448_Alloc(const char*, s32) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");
void func_001491d8(Map149448*);
s32 func_00168aa0(s32, s32);
void func_00168ad8(s32, s32*, s32, u32);
Ent149448* func_00168b38(s32, s32, s32);
Ent149448* func_00168b88(s32, s32, u32, s32);
}
static inline u32 Tag149448(const char* s) { return s[0] | s[1] << 8 | s[2] << 16 | s[3] << 24; }
static inline Ent149448* GetEnt149448(s32 bar, s32 t, const char* s, s32 i) { return func_00168b88(bar, t, Tag149448(s), i); }
// Map resource setup: allocates the map BAR, then reads the MAP/SK0/SK1/BOB entries and the
// remaining typed entries and texture list into the map record.
extern "C" {
// 00149448: moved to src/harata/libdk/mapfile.cpp
}
