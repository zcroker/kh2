// 0x1c5580 (gap function, was whole asm in asm_001c5580.s): per-frame target/camera update.
// Unit flags: -G0 -fno-strict-aliasing -fmove-all-movables.
// The player global is read through a reference accessor (player()): the load then has no decl of its own,
// so sched2 keeps it ahead of the spilled `best = 0` store, as in retail.
#include "../common/types.h"
struct V {
    f32 x, y, z, w;
    V() {}
    V(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    void set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    V& operator=(const V& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V operator-(const V& b) const
    {
        V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 lengthSq() const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
    f32 dot(const V& b) const
    {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder" : "=f"(r) : "r"(this), "r"(&b) : "$8", "memory");
        return r;
    }
    f32 normalize()
    {
        f32 len;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct M {
    V r[4];
    M() {}
    V operator*(const V& v) const {
        V o;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    M& operator=(const M& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    void invert() {
        asm volatile(".set noreorder\n\tlq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\tpextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\tpcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\tqmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\tvmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)\n\t.set reorder"
                     : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
asm("fptodp = func_00313b80");
asm("dpcmp = func_003142e0");
struct Pad16 { u8 pad[16]; };
struct Cam : Pad16, M {};
struct Ent { V pos; s32 a; s32 cnt; f32 dist; u32 flags; };
struct Node { u8 pad[20]; s32 kind; };
struct Obj { u8 pad[8]; };
extern u32 D_0034e948 asm("D_0034e948");
static inline u32& player() { return D_0034e948; }
extern Ent D_00351680[] asm("D_00351680");
#define FLG (&D_00351680[0].flags)
extern s32 D_00351cc0 asm("D_00351cc0");
extern V D_00352a60 asm("D_00352a60");
extern M D_01d497f0 asm("D_01d497f0");
extern V D_01d497c0 asm("D_01d497c0");
extern M D_01d49830 asm("D_01d49830");
extern V D_01d49870 asm("D_01d49870");
extern V D_01d49880 asm("D_01d49880");
extern V D_01d49890 asm("D_01d49890");
extern f32 D_01d498a0 asm("D_01d498a0");
extern s32 D_01d498a4 asm("D_01d498a4");
extern s32 D_01d498a8 asm("D_01d498a8");
extern f32 D_01d498ac asm("D_01d498ac");
extern s32 D_01d498b0 asm("D_01d498b0");
s32 YS__OBJ__is_exist(u32) asm("YS__OBJ__is_exist");
V* YS__OBJ__get_pos(u32) asm("YS__OBJ__get_pos");
Node* func_0018ee10(Node*) asm("func_0018ee10");
Cam* func_00106a60(s32) asm("func_00106a60");
V YS__OBJ__get_dir(u32) asm("YS__OBJ__get_dir");
Node* YS__ENEMY__Each(Node*) asm("YS__ENEMY__Each");
void YS__CROWDOBJ___OVR_exec(Obj*) asm("YS__CROWDOBJ___OVR_exec");
void func_001c5580(Obj* o) asm("func_001c5580");
void func_001c5580(Obj* o) {
    V v;
    s32 i;
    s32 best = 0;
    f32 maxd = 0.0f;
    s32 flag = 0;
    Node* q = 0;
    if (YS__OBJ__is_exist(player())) D_00352a60 = *YS__OBJ__get_pos(player());
    {
        Node* p = 0;
        while ((p = func_0018ee10(p)) != 0) {
            if (p->kind == 0x44) flag = 1;
        }
    }
    M* cm = func_00106a60(1);
    D_01d497f0 = *cm;
    D_01d49830 = D_01d497f0;
    D_01d49830.invert();
    v.set(-1.0f, 0.0f, 0.0f, 0.0f); D_01d49880 = D_01d49830 * v;
    v.set(1.0f, 0.0f, 0.0f, 0.0f); D_01d49890 = D_01d49830 * v;
    D_01d49870 = D_01d497f0 * D_00352a60;
    D_01d498a0 = D_01d49870.lengthSq();
    D_01d49870.y = 0.0f;
    D_01d49870.w = D_01d49870.normalize();
    D_01d498ac = -1.0f;
    for (i = 0; i < D_00351cc0; i++) {
        if (!(FLG[i * 8] & 4)) {
            v = D_00351680[i].pos - D_00352a60;
            v.y = 0.0f;
            f32 dist = v.lengthSq();
            D_00351680[i].dist = dist;
            if (dist > 3240000.0f) FLG[i * 8] &= ~1;
            else FLG[i * 8] |= 1;
            do {
                if (flag) {
                    V dir = YS__OBJ__get_dir(player());
                    if (0.0f < v.dot(dir) + D_01d497c0.z) { FLG[i * 8] |= 2; break; }
                }
                FLG[i * 8] &= ~2;
            } while (0);
            if (D_01d498ac < 0.0 || dist < D_01d498ac) {
                D_01d498ac = dist;
                best = i;
            }
        }
    }
    D_01d498a8 = 0;
    FLG[best * 8] |= 1;
    while ((q = YS__ENEMY__Each(q)) != 0) D_01d498a8++;
    s32 avail = 1000 - D_01d498b0 - D_01d498a8;
    while (avail < D_01d498a4) {
        s32* ap = &D_00351680[0].a;
        s32 b = -1;
        for (i = 0; i < D_00351cc0; i++) {
            if (!(FLG[i * 8] & 4)) {
                if (b < 0 || maxd < D_00351680[i].dist) {
                    b = i;
                    maxd = D_00351680[i].dist;
                }
            }
        }
        if (b < 0) break;
        s32 n = ap[b * 8];
        s32 ex = D_01d498a4 - avail;
        s32 take = ex;
        if (n < ex) take = n;
        Ent* e = &D_00351680[b];
        D_01d498a4 -= take;
        e->cnt = take;
        e->a -= take;
        if (e->a == 0) FLG[b * 8] |= 4;
    }
    YS__CROWDOBJ___OVR_exec(o);
}
