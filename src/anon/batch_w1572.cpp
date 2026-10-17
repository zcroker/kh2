#include "../common/types.h"
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
struct W1572_C8 { u8 r, g, b, a; };
struct W1572_Arg8 { s32 id; s32 idx; W1572_C8 add; u8 flag; };
union W1572_FU { f32 f; u8 c; };
struct W1572_C16 { u16 r, g, b, a; };
struct W1572_Arg16 { s32 id; s32 idx; W1572_C16 add; u8 flag; };
struct W1572_Obj { u8 pad[388]; s32 id; s32 val; u8 pad2[12]; };
struct W1572_Vt { u8 pad[28]; void (*fn)(void*); };
struct W1572_Mgr { W1572_Vt* vt; u8 pad[428]; W1572_Obj objs[5]; u8 pad3[2472 - 432 - 5 * 408]; s32 cur; };
extern "C" {
extern char D_0036e490[]; extern char D_0036e4e0[]; extern char D_0036e4e8[]; extern char D_0036e4f8[];
extern char D_0036e500[]; extern char D_0036e508[]; extern char D_0036e510[]; extern char D_0036e520[];
extern char D_01d5ba58[];
void func_00190878(void*, s32, s32);
s32 func_0019ba60(s32);
void func_001bc778(void*);
void func_001bce90(void*, const char*, s32, void*);
s32 func_001d4ae0(void*, void*, void*);
s32 func_001d4bd8(void*, void*, void*);
struct S { u32 type; s32 id; s32 pad; char buf[1]; };
struct NoTail { ~NoTail(){} };
s32 func_001d4940(S* p, void* a1, void* a2) {
    NoTail nt;
    s32 r;
    if (p->id != 0) {
        r = 0;
        if (func_0019ba60(p->id) == 0) return r;
    }
    r = 1;
    if (p->type == 10) return r;
    func_001bc778(a2);
    switch (p->type) {
    case 1: func_001bce90(a2, D_0036e490, 3, 0); break;
    case 2: return func_001d4ae0(p, a1, a2);
    case 3: func_001bce90(a2, D_01d5ba58, 3, 0); break;
    case 4: func_001bce90(a2, D_0036e4e0, 2, 0); break;
    case 5: func_001bce90(a2, D_0036e4e8, 3, 0); break;
    case 6: func_001bce90(a2, D_0036e4f8, 1, 0); break;
    case 7: func_001bce90(a2, D_0036e500, 1, 0); break;
    case 8: func_001bce90(a2, D_0036e508, 1, 0); break;
    case 9: func_001bce90(a2, D_0036e510, 3, 0); break;
    case 11: return func_001d4bd8(p, a1, a2);
    case 12: func_00190878(p->buf, p->id, 0); func_001bce90(a2, D_0036e520, 3, p->buf); break;
    }
    return 1;
}
extern s32 D_01d9ea9c;
extern u8* D_01d9e6e0;
extern u8 D_01d9e360[];
u8 func_001edce0(s32, f32);
u8 func_001edea8(s32, f32);
u16 func_001ee238(s32, f32);
u16 func_001ee400(s32, f32);
void func_001edd08(u8* a0, W1572_Arg8* a1, u8* a2) {
    if (D_01d9ea9c != 0) return;
    if ((*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) != 0) return;
    if (a1->id != *(s32*)(a0 + 12)) return;
    f32 f = vu0Rand();
    if (a1->flag != 0) f = (f + vu0Rand()) * 0.5f;
    u8* p = a0 + **(s32**)(a2 + 12);
    ((W1572_FU*)(p + 160))->f = f;
    f32* s2 = (f32*)(p + 160);
    s32 idx = a1->idx;
    W1572_C8* s1;
    if (idx != -1) s1 = (W1572_C8*)(a0 + idx + 160); else s1 = (W1572_C8*)D_01d9e360;
    asm volatile("" ::: "memory");
    { f32 ff = *s2; s1->r += func_001edce0((s8)a1->add.r, ff); }
    s1->g += func_001edce0((s8)a1->add.g, *s2);
    s1->b += func_001edce0((s8)a1->add.b, *s2);
    s1->a += func_001edce0((s8)a1->add.a, *s2);
}
void func_001eded0(u8* a0, W1572_Arg8* a1, u8* a2) {
    if (D_01d9ea9c != 0) return;
    if ((*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) != 0) return;
    if (a1->id != *(s32*)(a0 + 12)) return;
    f32 f = vu0Rand();
    f = -f;
    if (a1->flag != 0) { f32 g = vu0Rand(); f = (f - g) * 0.5f; }
    u8* p = a0 + **(s32**)(a2 + 12);
    ((W1572_FU*)(p + 160))->f = f;
    f32* s2 = (f32*)(p + 160);
    s32 idx = a1->idx;
    W1572_C8* s1;
    if (idx != -1) s1 = (W1572_C8*)(a0 + idx + 160); else s1 = (W1572_C8*)D_01d9e360;
    asm volatile("" ::: "memory");
    { f32 ff = *s2; s1->r += func_001edea8((s8)a1->add.r, ff); }
    s1->g += func_001edea8((s8)a1->add.g, *s2);
    s1->b += func_001edea8((s8)a1->add.b, *s2);
    s1->a += func_001edea8((s8)a1->add.a, *s2);
}
void func_001ee260(u8* a0, W1572_Arg16* a1, u8* a2) {
    if (D_01d9ea9c != 0) return;
    if ((*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) != 0) return;
    if (a1->id != *(s32*)(a0 + 12)) return;
    f32 f = vu0Rand();
    if (a1->flag != 0) f = (f + vu0Rand()) * 0.5f;
    u8* p = a0 + **(s32**)(a2 + 12);
    ((W1572_FU*)(p + 160))->f = f;
    W1572_FU* s2 = (W1572_FU*)(p + 160);
    s32 idx = a1->idx;
    W1572_C16* s1;
    if (idx != -1) s1 = (W1572_C16*)(a0 + idx + 160); else s1 = (W1572_C16*)D_01d9e360;
    asm volatile("" ::: "memory");
    { f32 ff = s2->f; s1->r += func_001ee238((s16)a1->add.r, ff); }
    s1->g += func_001ee238((s16)a1->add.g, s2->f);
    s1->b += func_001ee238((s16)a1->add.b, s2->f);
    s1->a += func_001ee238((s16)a1->add.a, s2->f);
}
void func_001ee428(u8* a0, W1572_Arg16* a1, u8* a2) {
    if (D_01d9ea9c != 0) return;
    if ((*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) != 0) return;
    if (a1->id != *(s32*)(a0 + 12)) return;
    f32 f = vu0Rand();
    f = -f;
    if (a1->flag != 0) { f32 g = vu0Rand(); f = (f - g) * 0.5f; }
    u8* p = a0 + **(s32**)(a2 + 12);
    ((W1572_FU*)(p + 160))->f = f;
    W1572_FU* s2 = (W1572_FU*)(p + 160);
    s32 idx = a1->idx;
    W1572_C16* s1;
    if (idx != -1) s1 = (W1572_C16*)(a0 + idx + 160); else s1 = (W1572_C16*)D_01d9e360;
    asm volatile("" ::: "memory");
    { f32 ff = s2->f; s1->r += func_001ee400((s16)a1->add.r, ff); }
    s1->g += func_001ee400((s16)a1->add.g, s2->f);
    s1->b += func_001ee400((s16)a1->add.b, s2->f);
    s1->a += func_001ee400((s16)a1->add.a, s2->f);
}
extern s32 D_0035e118[];
extern s32 D_0035e130[];
extern s32 D_0035e148[];
s32 func_00224860(void);
s32 func_0022b9e0(void);
s32 func_0022b720(void);
s32 func_00139d78(W1572_Obj*);
void func_001386e0(W1572_Obj*, s32, s32, s32, s32, s32);
void func_00138c10(W1572_Obj*, s32);
void func_002291d0(W1572_Mgr* m) {
    m->vt->fn(m);
    s32 v = func_00224860();
    if (m->cur != v) {
        s32 a = func_0022b9e0();
        s32 b = func_0022b720();
        s32 i;
        s32 n = 6 - v;
        i = 1;
        if (i < n) {
            W1572_Obj* o = m->objs;
            s32 j = 0;
            i = n - 1;
            do {
                if (func_00139d78(o) == 0) {
                    func_001386e0(o, 0xaf0, a, b, D_0035e118[j], 11);
                    o->val = D_0035e130[j];
                } else if (o->id == D_0035e148[j]) {
                    func_00138c10(o, D_0035e118[j]);
                    o->val = D_0035e130[j];
                }
                j++; o++;
            } while (--i != 0);
        }
        s32 k;
        for (k = m->cur; k < v; k++) {
            if (k >= 5) break;
            func_00138c10(&m->objs[4 - k], D_0035e148[4 - k]);
        }
    }
    m->cur = v;
}
}
