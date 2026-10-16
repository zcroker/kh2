#include "../common/types.h"
#define QCOPY_w1568(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV_w1568_ca {
    f32 x, y, z, w;
    QV_w1568_ca() {}
    QV_w1568_ca(const QV_w1568_ca& o) { QCOPY_w1568(this, &o); }
    f32 dot(const QV_w1568_ca& o) const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(this), "r"(&o) : "$8", "memory");
        return r;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct E_w1568_ca { u8 pad[0x1c]; s32 x1c; u8 pad2[8]; f32 x28; u8 pad3[0x2d4]; u8 x300[0x288]; u32 flags; u8 pad4[0x314]; QV_w1568_ca vel; };

extern "C" {

static inline f32 VRand_w1568(void)
{
    f32 u;
    asm volatile("addi $8, $0, -1\n\tqmtc2 $8, $vf2\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvrxor R, $vf2x\n\tvrnext.x $vf1, R\n\tvitof0.x $vf2, $vf2\n\tvadd.x $vf1, $vf1, $vf2\n\tqmfc2 %0, $vf1" : "=r"(u) : : "$8");
    return u;
}

/* 001ed990 */
s32 func_001ed978(f32, s32);
extern s32 D_01d9ea9c;
extern u8* D_01d9e6e0;
extern s32 D_01d9e360[];
enum E_w1568_ed990 { E_w1568_0 = 0, E_w1568_BIG = 0x7fffffff };
struct P1_w1568_ed990 { s32 id; s32 off; E_w1568_ed990 a; E_w1568_ed990 b; E_w1568_ed990 c; u8 two; };
struct P2_w1568_ed990 { u8 pad[0xc]; s32* off; };
union U_w1568_ed990 { f32 f; s32 v[3]; };
struct Ent_w1568_ed990 { u8 pad[0xa0]; U_w1568_ed990 u; };
void func_001ed990(u8* obj, P1_w1568_ed990* p, P2_w1568_ed990* q)
{
    if (D_01d9ea9c != 0) return;
    if (*(u64*)(D_01d9e6e0 + 0xa8) & 0xff0000ff00ULL) return;
    if (p->id != *(s32*)(obj + 0xc)) return;
    f32 r = VRand_w1568();
    r = -r;
    if (p->two) r = (r - VRand_w1568()) * 0.5f;
    Ent_w1568_ed990* t = (Ent_w1568_ed990*)(obj + *q->off);
    t->u.f = r;
    U_w1568_ed990* fp = &t->u;
    s32* d;
    d = (p->off == -1) ? D_01d9e360 : ((Ent_w1568_ed990*)(obj + p->off))->u.v;
    d[0] += func_001ed978(fp->f, p->a);
    d[1] += func_001ed978(fp->f, p->b);
    d[2] += func_001ed978(fp->f, p->c);
}


/* 0019a480 */
struct Key_w1568 { u8 a, b, c; u8 pad; u16 d, e, f; };
struct Info_w1568 { u8 pad[0x1c]; u8 kind; u8 sub; u8 id; };
struct Obj_w1568_9a { u32 pad; union { u32 flags; struct { u32 b0:1; u32 :31; }; }; Info_w1568* info; };
struct Sub_w1568 { u16 a; u16 type; };
struct Ctx_w1568 { u8 pad[0x6c]; Sub_w1568* sub; };
extern u8 D_0032bae0;
s32 func_001917b0(void);
s32 func_00196768(u8, u8);
void func_0019a610(Obj_w1568_9a*, Key_w1568*, s32);
s32 func_0019a6c0(Obj_w1568_9a*, Key_w1568*, Sub_w1568*, s32, s32);
s32 func_001db198(Ctx_w1568*, u8);
s32 func_0019a480(Obj_w1568_9a* p, Ctx_w1568* c)
{
    s32 two = 0;
    Key_w1568 k;
    u16 m = 0xffff;
    k.a = m; k.b = m; k.c = m; k.d = m; k.e = m; k.f = m;
    s32 v = func_001917b0() ^ 2;
    if (v == 0 && p->info->id != 0) return 0;
    Info_w1568* info = p->info;
    switch (info->kind) {
    case 100: k.a = 18; k.b = 1; break;
    case 101: k.a = 2; k.b = 40; break;
    default: k.a = D_0032bae0; k.b = info->kind; break;
    }
    k.c = info->sub;
    s32 r = func_00196768(k.a, k.b);
    switch (c->sub->type) {
    case 0: {
        u8 bb = p->b0;
        if (!bb && r == 0 && func_001db198(c, p->info->id)) {
            func_0019a610(p, &k, 0);
            p->flags |= 1;
        }
        break;
    }
    case 2:
        two = 1;
    case 1:
        if (!(p->flags & 0x10) && func_0019a6c0(p, &k, c->sub, r == 0, two)) p->flags |= 0x10;
        break;
    }
    return 0;
}


/* 001bb090 */
struct VObj_w1568;
struct VObj_vt_w1568 { u8 pad[0x40]; s32 (*fn)(VObj_w1568*); };
struct VObj_w1568 { VObj_vt_w1568* vt; };
struct Q_w1568 { s32 a; s32 id; s32 kind; };
struct O_w1568_bb { u32 pad; u32 flags; u32 pad8; u8 x0c[0x78]; Q_w1568 q; u8 pad2[0x1d0]; u8 x260[0x78]; s32 state; s32 p0; s32 p1; };
extern VObj_w1568* D_0034e948;
extern u32 D_0034f240;
s32 func_00195328(s32);
s32 func_00197920(void);
f32 func_00197b98(void);
s32 func_0019ba60(VObj_w1568*);
void func_001bb630(s32, s32);
void func_001bbe18(s32);
void func_001bc0d0(O_w1568_bb*);
void func_001d21c0(void*);
void func_001d5518(Q_w1568*, void*, s32);
void func_001d7f80(O_w1568_bb*);
void func_002bc788(void);
void func_002bc798(void);
s32 func_001bb090(O_w1568_bb* o)
{
    func_001d21c0(o->x260);
    switch (o->state) {
    case 0: {
        VObj_w1568* v = D_0034e948;
        if (func_00197920() && func_0019ba60(v) && !v->vt->fn(v)) return 1;
        if (!(o->flags & 2)) func_001d7f80(o);
        o->state = 1;
        break;
    }
    case 2:
        o->state = 3;
        break;
    case 3:
        if (func_00197b98() <= 4.0f) {
            s32 a;
            if (o->p0 == 16) a = 2;
            else {
                if (o->p0 == 156) {
                    func_002bc798();
                    func_001bbe18(7016);
                    func_002bc788();
                }
                a = 1;
            }
            s32 r = func_00195328(a);
            Q_w1568* q = &o->q;
            if (q->id == 0) { q->id = r; q->kind = 566; }
            func_001d5518(q, o->x0c, 0);
            D_0034f240 |= 8;
            func_001bc0d0(o);
        }
        break;
    case 4:
        if (func_00197920() == 0) {
            func_001bb630(o->p0, o->p1);
            return 0;
        }
        break;
    }
    return 1;
}

/* 001ca4a8 */

void func_0016af58(QV_w1568_ca*, E_w1568_ca*);
s32 func_0018ee60(s32, s32, E_w1568_ca*, QV_w1568_ca*, s32);
void func_001880b0(void*, const char*);
s32 func_001ca498(E_w1568_ca*);
s32 func_00186d18(E_w1568_ca*);
void func_00187818(E_w1568_ca*);
void func_001ca4a8(E_w1568_ca* e)
{
    QV_w1568_ca v(e->vel);
    f32 len = v.normalize();
    v.w = len;
    if (len < 1.0f) return;
    QV_w1568_ca d;
    func_0016af58(&d, e);
    if (v.dot(d) < -0.866f) {
        if (e->flags & 0x80) {
            QV_w1568_ca t;
            func_0016af58(&t, e);
            func_0018ee60(0, 992, e, &t, 1);
        } else {
            func_001880b0(e->x300, "dead_crash");
        }
    } else if (func_001ca498(e) || func_00186d18(e)) {
        if (e->flags & 0x80) {
            if (func_0018ee60(0, 993, e, &v, 1)) e->x28 *= 0.5f;
        } else {
            func_00187818(e);
        }
    }
    e->x1c = 0;
}

}
