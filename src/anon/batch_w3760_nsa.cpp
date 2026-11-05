#include "../common/types.h"
struct QV { f32 x, y, z, w; } __attribute__((aligned(16)));
struct QM { QV r[4]; } __attribute__((aligned(16)));
static inline void MulMat(QM* r, const QM* a, const QM* b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tvmulax.wxyz ACC, $vf1, $vf6x\n\tvmadday.wxyz ACC, $vf2, $vf6y\n\tvmaddaz.wxyz ACC, $vf3, $vf6z\n\tvmaddw.wxyz $vf6, $vf4, $vf6w\n\tvmulax.wxyz ACC, $vf1, $vf7x\n\tvmadday.wxyz ACC, $vf2, $vf7y\n\tvmaddaz.wxyz ACC, $vf3, $vf7z\n\tvmaddw.wxyz $vf7, $vf4, $vf7w\n\tvmulax.wxyz ACC, $vf1, $vf8x\n\tvmadday.wxyz ACC, $vf2, $vf8y\n\tvmaddaz.wxyz ACC, $vf3, $vf8z\n\tvmaddw.wxyz $vf8, $vf4, $vf8w\n\tsqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
                 : : "r"(r), "r"(a), "r"(b) : "memory");
}
struct Cam { u8 pad[16]; QM m; };
struct ONode { u8 pad[0x24]; ONode* next; };
struct LNode { u8 pad[4]; s32 v; LNode* next; };
struct LList { LNode* head; s32 n; };
struct Mgr { u8 pad[0xc]; ONode* head; u8 pad2[0x1c]; s32 cnt; s32 a30; s32 n34; };
static inline LNode* LNext(LList* l, LNode* q) { return !q ? l->head : q->next; }
static inline ONode* ONext(Mgr* g, ONode* q) { return !q ? g->head : q->next; }
extern "C" {
u8* func_001050d8(s32);
void func_00105110(u8*);
QM* func_00106a18(s32);
Cam* func_00106a60(s32);
s32 func_001c18d0(ONode*);
void func_001c1938(ONode*, LList*, u8*, QM*);
void func_001c1890(ONode*);
void func_001c1a30(s32, s32*);
void func_001c16a0(Mgr*, s32);

void func_001c14e0(Mgr* g) {
    LList l;
    QM m;
    QM* pm = &m;
    s32 t;
    u8* buf = func_001050d8(g->cnt * 12);
    l.n = 0;
    l.head = 0;
    QM* a = func_00106a18(1);
    Cam* c = func_00106a60(1);
    MulMat(pm, a, c ? &c->m : 0);
    ONode* cur = g->head;
    u8* w = buf;
    ONode* p = cur;
    t = g->a30;
    g->n34 = 0;
    while (p) {
        cur = ONext(g, cur);
        if (func_001c18d0(p)) {
            func_001c1938(p, &l, w, pm);
            w += 12;
            g->n34++;
        } else if (p) {
            func_001c1890(p);
        }
        p = cur;
    }
    w = 0;
    while ((w = (u8*)LNext(&l, (LNode*)w)) != 0) func_001c1a30(((LNode*)w)->v, &t);
    func_001c16a0(g, g->n34);
    func_00105110(buf);
}
}

struct Ent { u16 id; s16 idx; s16 mul; s16 val; };
struct Hdr { s16 n; u16 m; s16 z; s16 pad; Ent e[64]; };
struct Src { s8 k; u8 pad[7]; u16 id; u16 pad2; };
struct SrcList { u8 pad[8]; s32 n; u8 pad2[4]; Src s[1]; };
struct Lim { u8 pad[0x14]; s32 v; };
extern "C" {
extern Hdr* D_0035f594;
s32 func_002766d0(void);
SrcList* func_00294000(s32);
void func_002fde18(void*, s32, s32);
s8* func_00276568(void);
s32 func_00294268(Src*);
u16 func_0023aa78(s32);
s32 func_0023aa58(s32);
Lim* func_001aae68(s32);
s32 func_00192048(u16);
s16 func_00192b80(s32);


void func_00297478(void) {
    s32 base = func_002766d0();
    SrcList* l = func_00294000(1);
    Src* s = l->s;
    s32 cnt = 0;
    s32 i = 0;
    func_002fde18(D_0035f594, 0, 0x208);
    for (; i < l->n; i++) {
        s8 c = *func_00276568();
        if (s[i].k == c && func_00294268(&s[i])) {
            D_0035f594->e[cnt].id = s[i].id;
            D_0035f594->e[cnt].idx = i;
            cnt++;
        }
    }
    D_0035f594->n = cnt;
    u16 m = func_0023aa78(base + 0x18);
    s32 d = 15;
    s32 t = func_0023aa58(base + 0x18);
    if (t != 0) d = t;
    Lim* lim = func_001aae68(3);
    D_0035f594->m = m;
    t = m - d - lim->v;
    if (t < 0) D_0035f594->m -= t;
    for (i = 0; i < D_0035f594->n; i++) {
        D_0035f594->e[i].val = func_00192b80(func_00192048(D_0035f594->e[i].id));
        D_0035f594->e[i].mul = (u16)D_0035f594->e[i].val * D_0035f594->m;
    }
    D_0035f594->z = 0;
}



}
