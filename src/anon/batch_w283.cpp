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
void func_001edb48(u8* a0, W283_Arg8* a1, u8* a2) {
    if (D_01d9ea9c != 0) return;
    if ((*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) != 0) return;
    if (a1->id != *(s32*)(a0 + 12)) return;
    f32 f = vu0Rand();
    if (a1->flag != 0) f = f + vu0Rand(); else f = f + f;
    u8* p = a0 + **(s32**)(a2 + 12);
    ((W283_FU*)(p + 160))->f = f;
    f32* s2 = (f32*)(p + 160);
    s32 idx = a1->idx;
    W283_C8* s1;
    if (idx != -1) s1 = (W283_C8*)(a0 + idx + 160); else s1 = (W283_C8*)D_01d9e360;
    asm volatile("" ::: "memory");
    { f32 ff = *s2; s1->r += func_001edb18((s8)a1->add.r, ff); }
    s1->g += func_001edb18((s8)a1->add.g, *s2);  // fix8_mul_e
    s1->b += func_001edb18((s8)a1->add.b, *s2);  // fix8_mul_e
    s1->a += func_001edb18((s8)a1->add.a, *s2);  // fix8_mul_e
}
void func_001ee0a0(u8* a0, W283_Arg16* a1, u8* a2) {
    if (D_01d9ea9c != 0) return;
    if ((*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) != 0) return;
    if (a1->id != *(s32*)(a0 + 12)) return;
    f32 f = vu0Rand();
    if (a1->flag != 0) f = f + vu0Rand(); else f = f + f;
    u8* p = a0 + **(s32**)(a2 + 12);
    ((W283_FU*)(p + 160))->f = f;
    W283_FU* s2 = (W283_FU*)(p + 160);
    s32 idx = a1->idx;
    W283_C16* s1;
    if (idx != -1) s1 = (W283_C16*)(a0 + idx + 160); else s1 = (W283_C16*)D_01d9e360;
    asm volatile("" ::: "memory");
    { f32 ff = s2->f; s1->r += func_001ee070((s16)a1->add.r, ff); }
    s1->g += func_001ee070((s16)a1->add.g, s2->f);  // fix16_mul_e
    s1->b += func_001ee070((s16)a1->add.b, s2->f);  // fix16_mul_e
    s1->a += func_001ee070((s16)a1->add.a, s2->f);  // fix16_mul_e
}

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
s32 func_002ff1a4(const char*, const char*);  // strcmp
void func_00240118(char*, s32, s32);
s32 W283_GetFileTableMax(s32, s32) asm("_ZN2YI5MCARD15GetFileTableMaxEii");
s32 func_00241a88(u8 a) {
    W283_FE* e = D_0035ec9c;
    u32 got = 0;
    func_00240118(D_0035ec88, 0, a ? 1 : 2);
    s32 n = W283_GetFileTableMax(*D_0035ec94, 0);
    if (n < 3) return 0;
    for (s32 i = 0; i < n; i++, e++) {
        if (func_002ff1a4(e->name, D_003716e0) == 0) continue;
        if (func_002ff1a4(e->name, D_003716e8) == 0) continue;
        if (e->attr & 0x20) continue;
        if (func_002ff1a4(e->name, D_0035ec88) == 0) {  // strcmp
            if (e->size == 1024) got |= 4;
        } else if (func_002ff1a4(e->name, D_0035ebf8) == 0) {  // strcmp
            if (e->size == 964) got |= 1;
        } else if (func_002ff1a4(e->name, !a ? D_0035ec08 : D_0035ec00) == 0) {  // strcmp
            if (e->size == 0x8a58) got |= 2;
        }
    }
    return got == 7;
}

extern void* D_00361f60;
W283_JCfg* W283_MGJump_config(void*) asm("_ZN2Ti6MGJump6configEv");
W283_JTbl* func_002dd650(void*);
W283_JObj* func_001cbeb8(W283_V4*, u32);
void func_002de500(void* self, W283_V4* pos) {
    void* mg = D_00361f60;
    if (mg == 0) return;
    W283_JCfg* cfg = W283_MGJump_config(mg);
    f32* p188 = &cfg->step;
    f32* p192 = &cfg->f192;
    f32* p196 = &cfg->f196;
    W283_JTbl* t = func_002dd650(mg);
    s32 n = t->n;
    for (s32 j = 0; j < n; j++) {
        f32 y = (f32)j * *p188;
        u32 kind = ((u8*)t)[4 + j * 2];
        s32 cnt = ((u8*)t)[5 + j * 2];
        for (s32 i = 0; i < cnt; i++) {
            W283_JObj* o = func_001cbeb8(pos, kind);
            if (o == 0) continue;
            f32 a = (f32)i * 6.2831855f / (f32)cnt - 3.1415927f;
            o->pos = *pos;
            o->ang = a;
            o->f168 = *p196;
            o->f172 = 0.0f;
            o->f180 = *p192;
            o->f96 = y;
            o->f100 = 120.0f;
            o->f104 = p188[3];
            o->f64 = 0.0f;
        }
    }
}

void func_00190128(W283_Tgt*);
void W283_set_obj(W283_Tgt*, void*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
void* func_00190730(W283_Tgt*, void*);
s32 W283_can_attack(W283_Tgt*) asm("_ZNK2YS6TARGET10can_attackEv");
void func_0018a818(W283_TI*, void*, void*);
void func_00112df0(void* obj, W283_Tgt* out, W283_Q* from, f32 best) {
    W283_TI ti;
    W283_Tgt t;
    W283_Q d;
    void* cur = 0;
    ti.f12 = 0;
    func_00190128(&t);
    func_00190128(&t);
    W283_set_obj(&t, obj, 0);
    while ((cur = func_00190730(&t, cur)) != 0) {
        if (t.obj != obj) break;
        if (!W283_can_attack(&t)) continue;
        if (from == 0) { *out = t; break; }
        func_0018a818(&ti, obj, cur);
        f32 len;
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(ti.pos), "r"(from), "r"(&d) : "memory");
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(&d) : "$8");
        len = len - ti.r;
        if (best <= 0.0f || len < best) {
            best = len;
            *out = t;
        }
    }
}
}
