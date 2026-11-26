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
s32 YS__OBJ__is_disable_rc(W2397Obj*);
W2397Elem* W2397Obj_select(W2397Obj*, u32, W2397Elem*) asm("_ZN2YS3OBJ16select_collisionEjPKNS_14COLLISION_ELEME");
s32 func_0019bdc8(W2397Obj*, u32, u32);
u16* YS__RC_SEARCHER__get_command_elem(W2397Coll*, u32);
void YS__COLLISION__set(W2397Col*, W2397Obj*, W2397Elem*);
s32 func_0018a550(W2397Col*, W2397Col*);
void func_00190128(W2397Tgt*);
void W2397Tgt_set_obj(W2397Tgt*, W2397Obj*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
s32 W2397Coll_draw(W2397Coll*, u16*) asm("_ZN2YS9COLLISION4drawEji");
void YS__OBJ__get_dir(W2397X*, W2397Obj*);
s32 YS__RC_SEARCHER__get_dist(W2397Coll*, u16*, W2397Tgt*, W2397X*, s32);
void YS__RC_SEARCHER__check_set(W2397Coll*, u32, W2397Tgt*, s32, s32);

// Walks obj's collision elements (kind 5 uses the element id, 0x83 maps to the sub-object id) and, for each one that
// hits this collision, draws it and passes the flattened distance on to YS__RC_SEARCHER__check_set.
// The constants and &col.b are locals set before the loop (the original keeps 5/131 in s6/s7 and spills &col.b).
void YS__RC_SEARCHER__check_obj(W2397Coll* self, W2397Obj* obj);  // 0x0019e210: definition moved into src/anon/unit_0019ba60.cpp

}
