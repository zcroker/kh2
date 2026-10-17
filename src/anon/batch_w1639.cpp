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

void func_0013bc50(W1639Cmd* self, s32* sel, s32 a2, s32 idx, u8 t0, s32 t1, u8* info, s32 show)
{
    if (!func_0013bc40(self, a2)) return;
    s32 kind = (*sel == 0) ? 0x14 : 0x15;
    s32 id;
    switch (info[7]) {
    case 1: id = 0x25; break;
    default: id = -1; break;
    case 2: id = 0x29; break;
    case 3: id = 0x27; break;
    case 4: id = 0x2c; break;
    case 5: id = 0x2b; break;
    case 6: id = 0x26; break;
    case 7: id = 0x28; break;
    }
    W1639Sprite* p;
    if (id != -1) {
        p = func_0013b5d0(1.0f, self, a2, D_00348430[idx], 0, t0, 0, 0, 0, t1, 2);
        if (!p) return;
        W1639_SetShow(p, show);
        func_00139580(p);
        p = func_0013b5d0(1.0f, self, a2, id, 0, t0, 0, 0, 0, t1, 2);
        W1639_SetShow(p, show);
        func_00139580(p);
        p = func_0013b5d0(1.0f, self, a2, kind, 0, t0, 0, 0, 0, t1, 2);
        W1639_SetShow(p, show);
        if (self->unkD0 == -1) func_00139580(p);
        else func_00139570(p);
        if (func_001bdcd0(self->unk29C)) func_00139570(p);
    } else {
        f32 f = 1.0f;
        
        p = func_0013b5d0(f, self, a2, D_00348430[idx], 0, t0, 0, 0, 0, t1, 2);
        if (!p) return;
        func_00139570(p);
        func_0013c820(self, a2);
        p = func_0013b5d0(f, self, a2, kind, 0, t0, 0, 0, 0, t1, 2);
        W1639_SetShow(p, show);
        if (func_001bdcd0(self->unk29C)) func_00139570(p);
        else func_00139580(p);
    }
}


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
s32 func_002ff3fc(const char*);
s32 func_002ff538(const char*, const char*, s32);
void func_002fee78(char*, const char*, ...);
void func_00170518(char*, s32, s32);
s32 W1639_CheckFlag(s32) asm("_ZN2YS8PROGRESS9CheckFlagEi");
void W1639_SetFlag(s32) asm("_ZN2YS8PROGRESS7SetFlagEi");
void W1639_ParseIndex(void*, s32*, W1639Code*) asm("_ZNK2YS8AREADATA8SETINDEX5parseEPKNS0_4CODEES4_");
void func_001ada38(s32);
s32 func_001d9b40(u8*);

s32 func_00181da0(void* self, W1639Code* code)
{
    s32 i;
    switch (code->op) {
    case 0:
        for (i = 0; i < code->n; i++) func_001829b0(code->arg[i], 0);
        break;
    case 1:
        D_0034ecc0 = (u32)code->arg[0] | ((u64)(u32)code->arg[1] << 32);
        break;
    case 2: {
        u32 n = code->n;
        u32 r = D_003638d0 *= 0x10dcd;
        func_001829b0(code->arg[(s32)func_00312db8(r, func_00312db8((u64)(n - 1) + 0x100000000ULL, n))], 0);
        break;
    }
    case 3: {
        u32 r = D_003638d0 *= 0x10dcd;
        if ((u32)(s32)func_00312db8(r, 0x28f5c29) < (u32)code->arg[0]) {
            func_001829b0(code->arg[1], 0);
            return 0;
        }
        break;
    }
    case 4:
        D_01c6053c = (f32)(u32)code->arg[0];
        break;
    case 5:
        D_0034ecd0 = code->arg[0];
        break;
    case 6:
        D_0034ecd8 = code->arg[0];
        break;
    case 7:
        D_0034ecdc = code->arg[0];
        break;
    case 9:
        func_001829b0(code->arg[0], 1);
        break;
    case 10: {
        u8* p = func_00168b38(D_0034ecf4, -1, code->arg[0]);
        if (p && *(s32*)(p + 8)) func_00182a78(*(s32*)(p + 8));
        break;
    }
    case 11:
        D_0034ecc8 = (u32)code->arg[0] | ((u64)(u32)code->arg[1] << 32);
        break;
    case 12:
        func_00182280();
        break;
    case 14:
        D_0034ece0 = code->arg[0];
        break;
    case 15:
        func_001a8d40(func_001a8bd0(-1), code->arg[0]);
        break;
    case 16:
        func_001a9110(code->arg);
        break;
    case 17:
        D_0034ece4 = code->arg[0];
        break;
    case 18:
        D_0034ecd4 = code->arg[0];
        break;
    case 19:
        D_0034ece8 = code->arg[0];
        break;
    case 20:
        D_0034f240 |= 4;
        break;
    case 21:
        func_001bb288(code->arg[0], &code->arg[1]);
        break;
    case 22: {
        const char* s = (const char*)code->arg;
        if (func_002ff538(s, D_0034ecf8, func_002ff3fc(D_0034ecf8)) == 0)
            func_002fee78(D_01c60560, s, D_0033caf0);
        else
            func_002fee78(D_01c60560, s, D_0033caf4);
        func_00170518(D_01c60560, 950, 0);
        break;
    }
    case 23:
        D_0034f240 |= 0x10;
        break;
    case 24:
        D_0034ecec = ((s32*)code)[1];
        D_0034ecf0 = ((s32*)code)[2];
        break;
    case 25:
        for (i = 0; i < code->n; i++) {
            code = (W1639Code*)((s32*)code + 1);
            if (!W1639_CheckFlag(*(s32*)code)) W1639_SetFlag(*(s32*)code);
        }
        break;
    case 26:
        for (i = 0; i < code->n; i++) {
            code = (W1639Code*)((s32*)code + 1);
            D_01c60548.v |= (u64)1 << *(s32*)code;
        }
        break;
    case 27:
        for (i = 0; i < code->n; i++) {
            code = (W1639Code*)((s32*)code + 1);
            D_01c60550.v |= (u64)1 << *(s32*)code;
        }
        break;
    case 28:
        if (code->arg[0] == D_0032bae2)
            W1639_ParseIndex(self, &code->arg[1], (W1639Code*)&code->arg[code->n]);
        break;
    case 29:
        for (i = 0; i < code->n; i++) func_001ada38(code->arg[i]);
        break;
    case 30:
        D_01c60558 = code->arg[0];
        break;
    case 31:
        if (func_001d9b40(D_0032bae0)) {
            func_001829b0(code->arg[0], 0);
            return 0;
        }
        break;
    }
    return 1;
}
}
