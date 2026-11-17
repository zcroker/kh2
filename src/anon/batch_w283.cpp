#include "../common/types.h"
// VU0 random float in [0,1) (the game's inline vrnext sequence).
static inline f32 vu0Rand(void) {
    f32 f;
    asm volatile("addi $8, $0, -1\n\t"
                 "qmtc2 $8, $vf2\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vrxor R, $vf2x\n\tvrnext.x $vf1, R\n\t"
                 "vitof0.x $vf2, $vf2\n\t"
                 "vadd.x $vf1, $vf1, $vf2\n\t"
                 "qmfc2 %0, $vf1"
                 : "=r"(f) : : "$8");
    return f;
}
struct W283_C8 { u8 r, g, b, a; };
struct W283_Arg8 { s32 id; s32 idx; W283_C8 add; u8 flag; };
struct W283_C16 { u16 r, g, b, a; };
struct W283_Arg16 { s32 id; s32 idx; W283_C16 add; u8 flag; };
union W283_FU { f32 f; u8 c; };
struct W283_WT {
    u8 pad0[12];
    void (*cb)(void);
    u8* tbl24;
    u8* tbl20;
    u8 pad24[24];
    u8* arr;
    s32 count;
    s32 state;
    f32 t0;
    f32 t1;
    f32 max;
    f32 speed;
    s32 idx;
    u8 noLoop;
};
struct W283_FE { u8 pad[16]; s32 size; u16 attr; u8 pad2[10]; char name[32]; };
struct W283_V4 {
    f32 x, y, z, w;
    W283_V4& operator=(const W283_V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W283_JCfg { u8 pad[188]; f32 step; f32 f192; f32 f196; f32 f200; };
struct W283_JTbl { s16 f0; s16 n; u8 e[1]; };
struct W283_JObj { u8 pad[64]; f32 f64; u8 pad2[28]; f32 f96, f100, f104; u8 pad3[4]; W283_V4 pos; u8 pad4[32]; f32 ang; u8 pad5[4]; f32 f168; f32 f172; u8 pad6[4]; f32 f180; };
struct W283_Tgt { void* obj; u32 a, b, c, d; };
struct W283_TI { f32 f0; f32 r; f32 f8; u32 f12; f32 pos[4]; } __attribute__((aligned(16)));
struct W283_Q { f32 v[4]; } __attribute__((aligned(16)));
extern "C" {
extern s32 D_01d9ea9c;
extern u8* D_01d9e6e0;
extern u8 D_01d9e360[];
u8 func_001edb18(s32, f32);  // fix8_mul_e
u16 func_001ee070(s32, f32);  // fix16_mul_e
void func_001edb48(u8* a0, W283_Arg8* a1, u8* a2);  // 0x001edb48: definition moved into src/anon/unit_001ec098.cpp
void func_001ee0a0(u8* a0, W283_Arg16* a1, u8* a2);  // 0x001ee0a0: definition moved into src/anon/unit_001ec098.cpp

extern f32 D_00349e14;
void func_0023c598(void*) asm("_Z13func_0023c598Pv");
void func_0023acd8(void*);
s32 W283_GetPlayMode(void*) asm("_ZN2YI8SEQUENCE11GetPlayModeEv");
void wtarget_0023ca80(W283_WT* p, u32, u32, u32) asm("_Z16wtarget_0023ca80jjjj");
void wtarget_0023ca80(W283_WT* p, u32, u32, u32) {
    *(f32*)((u8*)p + 60) += D_00349e14 * p->speed;
    switch (p->state) {
    case 1:
        p->state = 2;
        func_0023c598(p);
        break;
    case 2:
        p->t1 += D_00349e14 * p->speed;
        if (p->max <= p->t1 && p->noLoop == 0) {
            p->state = 3;
            p->t1 = p->max - 1.0f;
            if (p->cb) p->cb();
        }
        break;
    case 0:
        return;
    default:
        return;
    }
    u16* ent = (u16*)(p->tbl20 + p->idx * 20);
    u8* e = p->tbl24 + *ent * 24;
    s32 busy = 0;
    for (s32 i = 0; i < p->count; i++, e += 24) {
        u8* o = p->arr + i * 344;
        if ((f32)*(s32*)(e + 12) <= p->t1) {
            func_0023acd8(o);
            if (W283_GetPlayMode(o)) busy = 1;
        } else {
            busy = 1;
        }
    }
    if (!busy) p->state = 3;
}

extern char* D_0035ec88;
extern W283_FE* D_0035ec9c;
extern s8* D_0035ec94;
extern char* D_0035ebf8;
extern char* D_0035ec00;
extern char* D_0035ec08;
extern char D_003716e0[];
extern char D_003716e8[];
s32 strcmp(const char*, const char*);  // strcmp
void func_00240118(char*, s32, s32);
s32 W283_GetFileTableMax(s32, s32) asm("_ZN2YI5MCARD15GetFileTableMaxEii");
s32 func_00241a88(u8 a) {
    W283_FE* e = D_0035ec9c;
    u32 got = 0;
    func_00240118(D_0035ec88, 0, a ? 1 : 2);
    s32 n = W283_GetFileTableMax(*D_0035ec94, 0);
    if (n < 3) return 0;
    for (s32 i = 0; i < n; i++, e++) {
        if (strcmp(e->name, D_003716e0) == 0) continue;
        if (strcmp(e->name, D_003716e8) == 0) continue;
        if (e->attr & 0x20) continue;
        if (strcmp(e->name, D_0035ec88) == 0) {  // strcmp
            if (e->size == 1024) got |= 4;
        } else if (strcmp(e->name, D_0035ebf8) == 0) {  // strcmp
            if (e->size == 964) got |= 1;
        } else if (strcmp(e->name, !a ? D_0035ec08 : D_0035ec00) == 0) {  // strcmp
            if (e->size == 0x8a58) got |= 2;
        }
    }
    return got == 7;
}

extern void* D_00361f60;
W283_JCfg* W283_MGJump_config(void*) asm("_ZN2Ti6MGJump6configEv");
W283_JTbl* func_002dd650(void*);
W283_JObj* func_001cbeb8(W283_V4*, u32);
void func_002de500(void* self, W283_V4* pos);  // 0x002de500: definition moved into src/anon/unit_002de3c8.cpp

void func_00190128(W283_Tgt*);
void W283_set_obj(W283_Tgt*, void*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
void* func_00190730(W283_Tgt*, void*);
s32 W283_can_attack(W283_Tgt*) asm("_ZNK2YS6TARGET10can_attackEv");
void func_0018a818(W283_TI*, void*, void*);
void func_00112df0(void* obj, W283_Tgt* out, W283_Q* from, f32 best);  // 0x00112df0: definition moved into src/anon/unit_001117d8.cpp
}
