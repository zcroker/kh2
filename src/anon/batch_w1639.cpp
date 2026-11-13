#include "../common/types.h"

// 0013bc50: command-menu sprite setup; 00181da0: area event code dispatcher (YS::AREADATA)

struct W1639Sprite {
    u8 pad0[0x18c];
    s32 on18c;
    s32 on190;
};

struct W1639Cmd {
    u8 pad0[0xd0];
    s32 unkD0;
    u8 padD4[0x29c - 0xd4];
    s32 unk29C;
};


struct W1639Code {
    u16 op;
    s16 n;
    s32 arg[1];
};

extern "C" {


extern s32 D_00348430[];
s32 func_0013bc40(W1639Cmd*, s32);
W1639Sprite* func_0013b5d0(f32, W1639Cmd*, s32, s32, s32, u8, s32, s32, s32, s32, s32);
void func_001396b0(W1639Sprite*);
void func_0031a260(W1639Sprite*, s32);
void func_00139570(W1639Sprite*);
void func_00139580(W1639Sprite*);
void func_0013c820(W1639Cmd*, s32);
s32 func_001bdcd0(s32);

static inline __attribute__((always_inline)) void W1639_SetShow(W1639Sprite* p, s32 v)
{
    p->on18c = v;
    func_001396b0(p);
    if (p->on18c) {
        p->on190 = 0;
        func_001396b0(p);
        if (p->on190) func_0031a260(p, 0);
    }
}

void func_0013bc50(W1639Cmd* self, s32* sel, s32 a2, s32 idx, u8 t0, s32 t1, u8* info, s32 show);  // 0x0013bc50: definition moved into src/anon/unit_0013a8b8.cpp


extern u64 D_0034ecc0;
extern u64 D_0034ecc8;
extern s32 D_0034ecd0;
extern s32 D_0034ecd4;
extern s32 D_0034ecd8;
extern s32 D_0034ecdc;
extern s32 D_0034ece0;
extern s32 D_0034ece4;
extern s32 D_0034ece8;
extern s32 D_0034ecec;
extern s32 D_0034ecf0;
extern s32 D_0034ecf4;
extern char* D_0034ecf8;
extern u32 D_0034f240;
extern u32 D_003638d0;
extern f32 D_01c6053c;
union W1639Bits { u64 v; s16 h; u8 c; };
extern W1639Bits D_01c60548;
extern W1639Bits D_01c60550;
extern s32 D_01c60558;
extern char D_01c60560[];
extern char* D_0033caf0;
extern char* D_0033caf4;
extern u8 D_0032bae0[];
extern u8 D_0032bae2;

void func_001829b0(s32, s32);
u64 func_00312db8(u64, u64);
u8* func_00168b38(s32, s32, s32);
void func_00182a78(s32);
void func_00182280(void);
s32 func_001a8bd0(s32);
void func_001a8d40(s32, s32);
void func_001a9110(s32*);
void func_001bb288(s32, s32*);
s32 strlen(const char*);
s32 strncmp(const char*, const char*, s32);
void func_002fee78(char*, const char*, ...);
void func_00170518(char*, s32, s32);
s32 W1639_CheckFlag(s32) asm("_ZN2YS8PROGRESS9CheckFlagEi");
void W1639_SetFlag(s32) asm("_ZN2YS8PROGRESS7SetFlagEi");
void W1639_ParseIndex(void*, s32*, W1639Code*) asm("_ZNK2YS8AREADATA8SETINDEX5parseEPKNS0_4CODEES4_");
void func_001ada38(s32);
s32 func_001d9b40(u8*);

// 00181da0: moved to src/yasui/libys/areadata.cpp
}
