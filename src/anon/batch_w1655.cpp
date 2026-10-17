#include "../common/types.h"
extern "C" void func_00190128(void*);
struct W1655QW {
    f32 x, y, z, w;
    W1655QW() {}
    W1655QW(const W1655QW& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1655QW& operator=(const W1655QW& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
// d = a - b (VU0)
static inline void w1655_vsub(W1655QW* d, const W1655QW* a, const W1655QW* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}
// normalize xyz in place, return the old length
static inline f32 w1655_vnorm(W1655QW* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline f32 w1655_vlen(const W1655QW* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline f32 w1655_vdot(const W1655QW* a, const W1655QW* b) {
    f32 d;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
        : "=f"(d) : "r"(a), "r"(b) : "$8", "memory");
    return d;
}
struct W1655Obj;
// YS::TARGET: object + collision element id (20 bytes)
struct W1655Tgt {
    W1655Obj* obj;
    s32 id;
    s32 c, d, e;
    W1655Tgt() { func_00190128(this); }
};
// YS::COLLISION_ELEM
struct W1655Elem { u8 id; u8 p1; u16 flags; };
// hit sphere filled by func_0018a818
struct W1655Hit { s32 p0; f32 radius; f32 height; s32 pc; W1655QW centre; };
struct W1655Prm { u8 p0[0x60]; f32 low; f32 high; u8 p68[4]; f32 yscale; f32 dirmin; };
struct W1655ObjVt { void* f[39]; W1655QW (*getPos)(W1655Obj*); };
struct W1655Obj { W1655ObjVt* vt; u8 p4[0x130 - 4]; W1655Prm* prm; u8 p134[0x588 - 0x134]; u32 flags; };
struct W1655Sys { u8 p0[0x4c]; f32 lockRange; };
extern "C" {
extern W1655Sys* D_00352130;
f32 W1655_GetLockOnRatio() asm("_ZN2YS6STATUS14GetLockOnRatioEv");
W1655Obj* W1655_ctarget(W1655Obj*) asm("_Z16ctarget_001b9bc8jjjj");
W1655Elem* W1655_each_collision(W1655Obj*, s32, W1655Elem*) asm("_ZN2YS3OBJ14each_collisionEiPKNS_14COLLISION_ELEME");
void W1655_set_obj(W1655Tgt*, W1655Obj*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
f32 W1655_FixRadian(f32) asm("_ZN2YS4MATH9FixRadianEf");
f32 f_atan2f(f32, f32);
f32 func_002f8870(f32);  // fabsf
s32 func_0019bc38(W1655Obj*);
s32 func_0019bb58(W1655Obj*);
void func_0018a818(W1655Hit*, W1655Obj*, W1655Elem*);
W1655QW func_00190388(W1655Tgt*);
W1655QW* func_0016c028(W1655Obj*);
W1655QW func_0016af58(W1655Obj*);
}
// Best candidate so far: the target plus its score (kept in memory, next to the target).
struct W1655Best { W1655Tgt t; f32 v; };
static inline W1655QW w1655_sub(const W1655QW& a, const W1655QW& b) { W1655QW r; w1655_vsub(&r, &a, &b); return r; }
extern "C" {
// Pick the collision element whose bearing from obj is most in front, within lock-on range.
W1655Tgt func_00190d10(W1655Tgt* cur, W1655Obj* self, f32 scale) {
    f32 ratio = W1655_GetLockOnRatio();
    f32 range = D_00352130->lockRange * ratio;
    W1655QW pos = self->vt->getPos(self);
    W1655QW d;
    W1655QW tp = func_00190388(cur);
    w1655_vsub(&d, &tp, &pos);
    f32 ang0 = f_atan2f(d.x, d.z);
    W1655Best b;
    W1655Obj* o = 0;
    while ((o = W1655_ctarget(o)) != 0) {
        if (!func_0019bc38(o)) continue;
        W1655Elem* e = 0;
        while ((e = W1655_each_collision(o, 3, e)) != 0) {
            if (e->flags & 1) continue;
            if (o == cur->obj && e->id == cur->id) continue;
            W1655Hit hit;
            func_0018a818(&hit, o, e);
            w1655_vsub(&tp, &hit.centre, &pos);
            f32 dist = w1655_vnorm(&tp) - hit.radius;
            if (!(o->flags & 0x400) || ratio < 1.0f) {
                if (range < dist) continue;
            }
            f32 r = W1655_FixRadian(f_atan2f(tp.x, tp.z) - ang0) * scale;
            if (!(0.0f < r)) continue;
            if (b.t.obj != 0 && !(r < b.v)) continue;
            b.t.obj = o;
            b.t.id = e->id;
            b.v = r;
        }
    }
    return b.t;
}

// Lock onto the nearest collision element, weighted by how far it is off self's facing.
void func_00190f80(W1655Tgt* t, W1655Obj* self, f32 limit) {
    f32 best = 0.0f;
    W1655Prm* prm = self->prm;
    f32 lo = prm->low;
    f32 hi = prm->high;
    f32 ratio = W1655_GetLockOnRatio();
    if (1.0f < ratio) {
        lo *= ratio;
        hi *= ratio;
    }
    func_00190128(t);
    W1655Obj* o = 0;
    while ((o = W1655_ctarget(o)) != 0) {
        if (!func_0019bc38(o)) continue;
        if (!func_0019bb58(o)) continue;
        f32 zero = 0.0f;
        f32 one = 1.0f;
        f32 half = 0.5f;
        W1655Elem* e = 0;
        while ((e = W1655_each_collision(o, 3, e)) != 0) {
            if (e->flags & 1) continue;
            W1655QW h;
            W1655Hit hit;
            func_0018a818(&hit, o, e);
            h = w1655_sub(hit.centre, *func_0016c028(self));
            f32 dy = h.y;
            h.y = 0.0f;
            f32 len = w1655_vnorm(&h);
            if (zero < limit) {
                if (dy < lo - hit.height) continue;
                if (hi + hit.height < dy) continue;
                if (limit < len - hit.radius) continue;
            }
            len += func_002f8870(dy) * prm->yscale;
            f32 dot = w1655_vdot(&func_0016af58(self), &h);
            len *= (one - dot) * half * (one - prm->dirmin) + prm->dirmin;
            if (t->obj != 0 && !(len < best)) continue;
            best = len;
            W1655_set_obj(t, o, e->id);
        }
    }
}

// Pick the nearest collision element lying in direction dir (flattened), within lock-on range.
W1655Tgt func_001913d8(W1655Tgt* cur, W1655Obj* self, const W1655QW* dir) {
    f32 ratio = W1655_GetLockOnRatio();
    f32 range = D_00352130->lockRange * ratio;
    W1655QW tp = func_00190388(cur);
    W1655QW pos = self->vt->getPos(self);
    W1655Best b;
    W1655Obj* o = 0;
    while ((o = W1655_ctarget(o)) != 0) {
        if (!func_0019bc38(o)) continue;
        W1655Elem* e = 0;
        while ((e = W1655_each_collision(o, 3, e)) != 0) {
            if (e->flags & 1) continue;
            if (o == cur->obj && e->id == cur->id) continue;
            W1655Hit hit;
            func_0018a818(&hit, o, e);
            W1655QW v;
            w1655_vsub(&v, &hit.centre, &pos);
            if (range < w1655_vlen(&v) - hit.radius) continue;
            W1655QW f;
            w1655_vsub(&f, &hit.centre, &tp);
            f.y = -f.z;
            f.z = 0.0f;
            f32 dist = w1655_vnorm(&f) - hit.radius;
            if (w1655_vdot(&f, dir) < 0.5f) continue;
            if (b.t.obj != 0 && !(dist < b.v)) continue;
            W1655_set_obj(&b.t, o, e->id);
            b.v = dist;
        }
    }
    return b.t;
}
}
