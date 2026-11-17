#include "../common/types.h"

typedef struct Px { u8 r, g, b, a; u32 x4; } Px;
typedef struct Sub { s16 x0; s16 n; s32 off; } Sub;
typedef struct Ent { s16 off; s16 x2; s32 x4; } Ent;
typedef struct Hd { s16 x0, x2; s32 x4:16; s32 n:16; u32 x8, xc; Ent e[1]; } Hd;
s32* func_001e4e18(s32* p);  // 0x001e4e18: definition moved into src/anon/unit_001e0cb8.cpp
typedef union { s32 w; u8* p; s16 h[2]; u8 c; } U331;
void func_001e8180(u8* p, u8* base);  // 0x001e8180: definition moved into src/anon/unit_001e0cb8.cpp
void func_002fdfc8(const char*, ...);  // device_vprintf_va
void func_001e2ad8(const char*, const char*, s32, const char*);
extern char D_0036e978[], D_0036e998[], D_0036e9d0[], D_0036ec40[], D_0036ec58[], D_0036ec70[], D_0036ece0[], D_0036ecf0[];
typedef union { u16 h; void* p; u8 c; } U2_331;
typedef struct T331 { u16 a, b; void* p; } T331;
extern T331 D_00354248[];
static inline void rb331(const char* f, s32 l) { func_002fdfc8(D_0036e998, f, l); asm volatile("break"); }
#define ASSERTD331(c, e, l) if (!(c)) { func_002fdfc8(D_0036e978, e); rb331(D_0036e9d0, l); }
#define ASSERT331(c, e, l) if (!(c)) { func_002fdfc8(D_0036e978, e); func_002fdfc8(D_0036e998, D_0036e9d0, l); asm volatile("break"); }
u32* func_001e4028(u32* p, u8* bits);  // 0x001e4028: definition moved into src/anon/unit_001e0cb8.cpp
