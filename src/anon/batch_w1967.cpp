#include "../common/types.h"

struct W1967V {
    f32 x, y, z, w;
    W1967V operator-(const W1967V& b) const {
        W1967V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 length() const {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct W1967Info { f32 a; f32 r; f32 pad[2]; W1967V pos; };
struct W1967Obj;
struct W1967ObjVt { u8 pad[0x9c]; W1967V (*getPos)(W1967Obj*); };
struct W1967Obj { W1967ObjVt* vt; };
struct W1967Act { u8 pad[0x588]; u32 flags; };
struct W1967Part { u8 id; u8 pad; u16 flags; };
struct W1967Cfg { u8 pad[0x4c]; f32 range; };
extern W1967Cfg* D_00352130;

struct W1967Anim;
struct W1967AnimVt { u8 pad[0x20]; s32 (*canLink)(W1967Anim*, W1967Anim*); };
struct W1967Anim { W1967AnimVt* vt; };
struct W1967Owner { u8 pad[0x38]; W1967Anim* head; };

extern "C" {
f32 w1967_GetLockOnRatio(s32*) asm("_ZN2YS6STATUS14GetLockOnRatioEv");
void w1967_ctarget_0016bda8(W1967V*, W1967Obj*) asm("_Z16ctarget_0016bda8jjjj");
void func_00190128(s32*);
W1967Act* w1967_ctarget_001b9bc8(W1967Act*) asm("_Z16ctarget_001b9bc8jjjj");
s32 func_0019bc38(W1967Act*);
W1967Part* w1967_each_collision(W1967Act*, s32, W1967Part*) asm("_ZN2YS3OBJ14each_collisionEiPKNS_14COLLISION_ELEME");
void func_0018a818(W1967Info*, W1967Act*, W1967Part*);
void w1967_set_obj(s32*, W1967Act*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");

s32 w1967_getType(void*) asm("_Z13func_00132330Pv");
W1967Anim* w1967_getSub(void*) asm("_Z13func_00132360Pv");
void w1967_link(void*, s32) asm("_Z13func_00132368Pvi");
W1967Anim* w1967_getNext(void*) asm("_ZNK2kn13AnimationWork7getNextEv");

void func_00190b30(s32* self, W1967Obj* obj) {
    W1967Act* a = 0;
    f32 best = 0.0f;
    f32 r = w1967_GetLockOnRatio(self);
    f32 range = D_00352130->range * r;
    W1967V p0 = obj->vt->getPos(obj);
    W1967V p1;
    w1967_ctarget_0016bda8(&p1, obj);
    func_00190128(self);
    while ((a = w1967_ctarget_001b9bc8(a)) != 0) {
        if (!func_0019bc38(a)) continue;
        W1967Part* p = 0;
        f32 lim = 1.0f;
        while ((p = w1967_each_collision(a, 3, p)) != 0) {
            if (p->flags & 1) continue;
            W1967Info info;
            f32 d;
            func_0018a818(&info, a, p);
            if (!(a->flags & 0x400) || r < lim) {
                f32 d0 = (info.pos - p0).length() - info.r;
                if (range < d0) continue;
            }
            d = (info.pos - p1).length() - info.r;
            if (*self == 0 || d < best) {
                best = d;
                w1967_set_obj(self, a, p->id);
            }
        }
    }
}

void func_0011e600(W1967Owner* self, s32 a, s32 b) {
    W1967Anim* p1;
    W1967Anim* p;
    W1967Anim* q;
    if (a == 0 || b == 0 || a == b) return;
    p1 = self->head;
    if (!p1) return;
    do {
        if (w1967_getType(p1) == a || w1967_getType(p1) == b) {
            q = w1967_getSub(p1);
            if (q && (w1967_getType(q) == a || w1967_getType(q) == b)) {
                w1967_link(p1, 0);
            }
        }
    } while ((p1 = w1967_getNext(p1)) != 0);
    p = self->head;
    if (!p) return;
    do {
        if (w1967_getType(p) == a) {
            for (q = w1967_getNext(p); q; q = w1967_getNext(q)) {
                if (w1967_getType(q) == b && q->vt->canLink(q, p)) {
                    w1967_link(q, (s32)p);
                }
            }
        }
    } while ((p = w1967_getNext(p)) != 0);
    p = self->head;
    if (!p) return;
    do {
        if (w1967_getType(p) == b) {
            for (q = w1967_getNext(p); q; q = w1967_getNext(q)) {
                if (w1967_getType(q) == a && q->vt->canLink(q, p)) {
                    w1967_link(q, (s32)p);
                }
            }
        }
    } while ((p = w1967_getNext(p)) != 0);
}
}
