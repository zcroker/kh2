// 002302c0: built with -fno-cse-follow-jumps (_ncfj); with it on, cse2 follows the type-test jump and folds the loop start to p+56.
// -O2 -fno-cse-follow-jumps gives a full match (no such build rule).
// 002302c0 near-miss (80 diff lines, all register rotation + lerp schedule). Spline arc-length lookup:
// t in [0,100] -> distance along spline; walks keys (dist = cumulative length at +0x24), samples 0022fe08
// at 0.025 steps, lerps inside the step. Want ints s1=&p1 s2=tmp s3=i (got i,&p1,tmp); floats f20=pos f21=acc f22=s (got s,pos,acc).
#include "../common/types.h"
struct Vec {
    f32 x, y, z, w;
    Vec() {}
    Vec& operator=(const Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    f32 length() const {
        f32 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(this) : "$8");
        return r;
    }
} __attribute__((aligned(16)));
static inline void Vec_sub(Vec* r, const Vec* a, const Vec* b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(r), "r"(a), "r"(b) : "memory");
}
static inline Vec operator-(const Vec& a, const Vec& b) { Vec r; Vec_sub(&r, &a, &b); return r; }
struct Rot { f32 x, y, z; };
struct PathKey { u8 pad[0x24]; f32 dist; };
struct Path {
    u8 pad0[6];
    s16 count;
    s16 type;
    u8 pad1[2];
    f32 length;
    PathKey keys[1];
};
extern "C" {
void func_0022fe08(Vec* out, f32 s, Path* p, s32 i);
void func_00230260(Vec* a, Vec* b, Rot* rot);

s32 func_002302c0(f32 t, Path* p, Vec* out, Rot* rot) {
    Vec p0, p1, d;
    f32 pos;
    f32 acc;
    f32 s;
    s32 i;
    PathKey* keys = p->keys;
    s16 cnt;
    rot->x = 0.0f;
    rot->y = 0.0f;
    rot->z = 0.0f;
    if (t < rot->x) t = rot->x;
    if (100.0f < t) t = 100.0f;
    pos = p->length * t / 100.0f;
    cnt = p->count;
    if (p->type == 1) {
        s32 n;
        PathKey* k;
        n = cnt - 1;
        
        for (i = 0; i < n; i++) {
            k = &keys[i];
            if (k->dist <= pos && pos < k[1].dist) {
                f32 l;
                acc = k->dist;
                func_0022fe08(&p0, 0.0f, p, i);
                if (pos == acc) {
                    *out = p0;
                    func_0022fe08(&p1, 0.025f, p, i);
                    func_00230260(&p0, &p1, rot);
                    return 1;
                }
                for (s = 0.025f; s <= 1.0f; s += 0.025f) {
                    func_0022fe08(&p1, s, p, i);
                    d = p1 - p0;
                    l = d.length();
                    if (pos < acc + l) {
                        s = pos - acc;
                        s /= l;
                        out->x = p0.x + (p1.x - p0.x) * s;
                        out->y = p0.y + (p1.y - p0.y) * s;
                        out->z = p0.z + (p1.z - p0.z) * s;
                        goto done0;
                    }
                    acc += l;
                    p0 = p1;
                }
            }
        }
        return 0;
    done0:
        func_00230260(&p0, &p1, rot);
        return 1;
    } else {
        s32 n;
        PathKey* k;
        n = cnt - 2;
        
        for (i = 1; i < n; i++) {
            k = &keys[i];
            if (k->dist <= pos && pos <= k[1].dist) {
                f32 l;
                acc = k->dist;
                func_0022fe08(&p0, 0.0f, p, i);
                if (pos == acc) {
                    *out = p0;
                    func_0022fe08(&p1, 0.025f, p, i);
                    func_00230260(&p0, &p1, rot);
                    return 1;
                }
                for (s = 0.025f; s < 1.0f; s += 0.025f) {
                    func_0022fe08(&p1, s, p, i);
                    d = p1 - p0;
                    l = d.length();
                    if (pos < acc + l) {
                        s = pos - acc;
                        s /= l;
                        out->x = p0.x + (p1.x - p0.x) * s;
                        out->y = p0.y + (p1.y - p0.y) * s;
                        out->z = p0.z + (p1.z - p0.z) * s;
                        goto done1;
                    }
                    acc += l;
                    p0 = p1;
                }
            }
        }
        return 0;
    done1:
        func_00230260(&p0, &p1, rot);
        return 1;
    }
}
}
