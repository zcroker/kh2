#include "../common/types.h"
struct W2397V {
    f32 x, y, z, w;
    W2397V() {}
    W2397V& operator=(const W2397V& o) {
        if (this != &o) {
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        }
        return *this;
    }
    W2397V operator-(const W2397V& b) const {
        W2397V r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
            : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 normalize() {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)\n\t.set reorder"
                 : "=f"(r) : "r"(this) : "$8", "memory");
        return r;
    }
    f32 dot(const W2397V& b) const {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder"
                 : "=f"(r) : "r"(this), "r"(&b) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W2397Col { W2397V a; W2397V b; };
struct W2397Elem { u8 b0; u8 b1; u16 id; u8 kind; };
struct W2397Sub { u8 pad[0x2c]; u16 id; };
struct W2397Obj { u8 pad[0x81c]; W2397Sub* sub; u8 pad2[0xaa4 - 0x820]; u32 id; };
struct W2397Coll { u8 pad[0x30]; W2397Col col; };
struct W2397Tgt { u8 d[32]; };
struct W2397X { u8 d[16]; };
extern "C" {
s32 func_0019c4f8(W2397Obj*);
W2397Elem* W2397Obj_select(W2397Obj*, u32, W2397Elem*) asm("_ZN2YS3OBJ16select_collisionEjPKNS_14COLLISION_ELEME");
s32 func_0019bdc8(W2397Obj*, u32, u32);
u16* func_0019e5f8(W2397Coll*, u32);
void func_0018a818(W2397Col*, W2397Obj*, W2397Elem*);
s32 func_0018a550(W2397Col*, W2397Col*);
void func_00190128(W2397Tgt*);
void W2397Tgt_set_obj(W2397Tgt*, W2397Obj*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
s32 W2397Coll_draw(W2397Coll*, u16*) asm("_ZN2YS9COLLISION4drawEji");
void func_0016af58(W2397X*, W2397Obj*);
s32 func_0019df08(W2397Coll*, u16*, W2397Tgt*, W2397X*, s32);
void func_0019dbc0(W2397Coll*, u32, W2397Tgt*, s32, s32);

// Walks obj's collision elements (kind 5 uses the element id, 0x83 maps to the sub-object id) and, for each one that
// hits this collision, draws it and passes the flattened distance on to func_0019dbc0.
// The constants and &col.b are locals set before the loop (the original keeps 5/131 in s6/s7 and spills &col.b).
void func_0019e210(W2397Coll* self, W2397Obj* obj) {
    if (func_0019c4f8(obj)) return;
    W2397Elem* el = 0; W2397V* cb = &self->col.b; u32 k5 = 5; u32 k131 = 131;
    for (;;) {
        el = W2397Obj_select(obj, 0x4020, el);
        if (!el) break;
        u32 id;
        if (el->kind == k5) {
            id = el->id;
            if (id == k131 && obj->sub) id = obj->sub->id;
        } else {
            id = obj->id;
        }
        if (!func_0019bdc8(obj, id, el->b0)) continue;
        u16* e = func_0019e5f8(self, id);
        if (!e) continue;
        W2397Col c;
        func_0018a818(&c, obj, el);
        if (!func_0018a550(&c, &self->col)) continue;
        W2397V d = c.b - *cb;
        d.y = 0;
        s32 dist = (s32)d.normalize();
        u8 k = el->b0;
        W2397Tgt tgt;
        func_00190128(&tgt);
        W2397Tgt_set_obj(&tgt, obj, k);
        s32 r = W2397Coll_draw(self, e);
        W2397X x;
        func_0016af58(&x, obj);
        func_0019dbc0(self, *e, &tgt, r, func_0019df08(self, e, &tgt, &x, dist));
    }
}

}
