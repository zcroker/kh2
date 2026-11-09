// 0013f9e0: segment collision probe; on a hit, push the end point out along the surface normal.
// Partial asm: the 30.0f pool address and the flag constant (the original interleaves li between lui and addiu).
#include "../common/types.h"
typedef unsigned int W3906U128 __attribute__((mode(TI)));
/* 16-byte vector; assignment copies one quadword unless self-assigned */
struct W3906Q {
    union { W3906U128 q; f32 f[4]; };
    W3906Q& operator=(const W3906Q& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
};
struct W3906Seg {
    W3906Q v[2];
};
/* collision hit info filled by func_00143d10 */
struct W3906HitInfo {
    u16 id;
    u8 _pad2[14];
};
struct W3906HitObj {
    u8* obj;        /* hit object (0 = map) */
    s32 again;      /* second probe done */
    W3906HitObj() : obj(0), again(0) {}
} __attribute__((aligned(8)));
static inline void W3906VSub(W3906Q& r, const W3906Q& a, const W3906Q& b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
}
static inline void W3906VAdd(W3906Q& r, const W3906Q& a, const W3906Q& b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
}
static inline void W3906VScale(W3906Q& r, const W3906Q& v, f32 s)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&v), "f"(s) : "$8", "memory");
}
extern "C" {
void func_0015a8a0(void);
s32 func_0015a8d0(W3906Seg*, W3906Q*);
s32 func_00143d10(W3906Seg*, W3906Q*, W3906HitInfo*, W3906HitObj*);
void func_00143e50(W3906Q*, u16, s32);
s32 func_00143f28(u16, s32);
void func_001422a0(W3906Q*, u8*, u16);
s32 func_0013f9e0(W3906Q* pos, W3906Q* from, W3906Q* to, u8 mode, u8 flag)
{
    W3906HitInfo info;
    W3906Q hit;
    W3906Seg seg;
    W3906Q normal;
    W3906Q work;
    W3906Q v0;
    W3906Q v1;
    W3906Q base;
    W3906Q dir;
    W3906Seg seg2;
    W3906HitObj res;
    s32 ret = 0;
    s32 kind;
    f32 len;

    W3906Seg* ps = &seg;
    W3906Q* pend = &seg.v[1];
    W3906Q* ph = &hit;
    ps->v[0] = *from;
    *pend = *to;
    if (mode == 1) {
        func_0015a8a0();
        if (func_0015a8d0(ps, ph)) {
            *to = *ph;
            *pend = *ph;
            ret = 1;
        }
    }
    if (func_00143d10(ps, ph, &info, &res)) {
        W3906Q* pn = &normal;
        kind = 0;
        if (res.obj == 0) {
            func_00143e50(&work, info.id, 1);
            *pn = work;
            kind = func_00143f28(info.id, 1);
        } else {
            func_001422a0(&work, *(u8**)(res.obj + 4), info.id);
            *pn = work;
        }
        if (kind == 5) {
            W3906Q* p1 = &v1;
            W3906Q* p0 = &v0;
            v0 = *pos;
            *p1 = *to;
            W3906Q* pd = &dir;
            base = *p0;
            W3906VSub(work, *p1, v0);
            *pd = work;
            dir.f[3] = 1.0f;
            base.f[3] = 1.0f;
            hit.f[0] = pos->f[0] + dir.f[0];
            hit.f[2] = pos->f[2] + dir.f[2];
            W3906Seg* s2 = &seg2;
            W3906Q* s2e = &seg2.v[1];
            s2->v[0] = *from;
            *s2e = *ph;
            func_00143d10(s2, ph, &info, &res);
            res.again = 1;
        }
        f32 s;
        {
            /* 30.0f from the literal pool at 0x0036adc4, with the 1 for the flag test in between */
            register s32 one asm("$15");
            register const f32* k30 asm("$14");
            asm("lui $14,0x37\n\tli $15,1\n\taddiu $14,$14,-21052" : "=r"(k30), "=r"(one));
            s = *k30;
            if (flag != one) s = 5.0f;
        }
        {
            s32 one = 1;
            asm("" : "+r"(one));
            len = 5.0f;
            asm volatile("");
            if (res.again != one) len = s;
        }
        W3906VScale(work, *pn, len);
        W3906VAdd(v0, *ph, work);
        *to = v0;
        return 1;
    }
    return ret;
}
}
