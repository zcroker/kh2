#include "../common/types.h"

struct W1618V {
    f32 x, y, z, w;
    W1618V() {}
    W1618V(const W1618V& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W1618V& operator=(const W1618V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W1618V operator-(const W1618V& b) const {
        W1618V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1618V operator+(const W1618V& b) const {
        W1618V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    W1618V operator*(f32 s) const {
        W1618V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "f"(s) : "$8", "memory");
        return r;
    }
    f32 length() const {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));

struct W1618Box {
    f32 mn[3];
    f32 mx[3];
    W1618Box();
};

// Climb/ledge parameters (pointer at obj+0x12c).
struct W1618Ledge { u8 pad[0x10]; f32 drop; f32 minHeight; };
// Collision body at obj+0x590.
struct W1618Body { u8 pad[0x20]; f32 radius; };
// Global collision settings (D_00352130).
struct W1618Cfg { u8 pad[8]; f32 below; f32 above; f32 margin; };
struct W1618Flags { u64 lo:33; u64 noStep:1; u64 hi:30; };

struct W1618Obj;
struct W1618Obj {
    bool canStep() const { return !f600.noStep; }
    u8 pad0[0x10c];
    u32 flags;
    u8 pad110[0x12c - 0x110];
    W1618Ledge* ledge;
    u8 pad130[0x590 - 0x130];
    W1618Body body;
    u8 pad5b4[0x600 - 0x5b4];
    W1618Flags f600;
    u8 pad608[0xb34 - 0x608];
    u8 colB34[4];
};

// BGM slot table at 0x347d30 (16 bytes per slot).
struct W1618Bgm { s32 f0; s32 id; s32 vol; u32 flags; };
// Sequence/stream request filled from a slot.
struct W1618Req { u32 f0; s32 handle; s32 id; s32 slot; void* alloc; };

extern "C" {
extern W1618Cfg* D_00352130;
void W1618Box_init(W1618Box*) asm("_ZN2dk6Aabbox4initEv");
void W1618Box_set(W1618Box*, f32, f32, f32, f32, f32, f32) asm("_ZN2dk6Aabbox3setEffffff");
W1618V* func_0016c028(W1618Obj*);
W1618V func_0016af58(W1618Obj*);
s32 func_00143470(W1618V*, W1618Box*, W1618V*, W1618V*, W1618V*, W1618V*, u8*);
f32 W1618_get_step_height(W1618Obj*) asm("_ZN2YS3OBJ15get_step_heightEv");
bool func_0019bfd0(W1618Obj*, const W1618V&);
void W1618_set_dir(W1618Obj*, const W1618V&) asm("_ZN2YS3OBJ7set_dirERKN2kn7FVectorE");
void W1618_set_pos(W1618Obj*, const W1618V&) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
void W1618_change_action(W1618Obj*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
inline W1618Box::W1618Box() { W1618Box_init(this); }

// Ledge grab test: sweeps a box around the object down to the ledge; on a hit,
// faces the wall, snaps onto the edge and switches to action 2. Returns 1 on grab.
bool func_001958d0(W1618Obj* o) {
    W1618V pos;
    W1618V hit;
    W1618V d;
    W1618V dir;
    W1618V ea;
    W1618V eb;
    W1618Box box;
    W1618Ledge* l = o->ledge;
    if (!l || l->minHeight == 0.0f || (o->flags & 0x4000)) return 0;
    f32 drop = l->drop;
    W1618Body* b = &o->body;
    f32 r = b->radius + D_00352130->margin;
    pos = *func_0016c028(o);
    pos.y -= drop;
    W1618Box_set(&box, pos.x - r, pos.y - D_00352130->below, pos.z - r,
                 pos.x + r, pos.y + D_00352130->above, pos.z + r);
    dir = func_0016af58(o);
    if (!func_00143470(&pos, &box, &hit, &ea, &eb, &dir, o->colB34)) return 0;
    if (hit.y < box.mn[1] || box.mx[1] < hit.y) return 0;
    if (o->canStep()) {
        if (W1618_get_step_height(o) - hit.y < l->minHeight) return 0;
    }
    d = hit - pos;
    d.y = 0.0f;
    if (r < d.length()) return 0;
    d = eb - ea;
    d.y = 0.0f;
    d.normalize();
    dir.x = -d.z;
    dir.y = 0.0f;
    dir.z = d.x;
    d = dir * -b->radius;
    d.y = drop;
    if (!func_0019bfd0(o, hit + d)) return 0;
    W1618_set_dir(o, dir);
    W1618_set_pos(o, hit + d);
    W1618_change_action(o, 2);
    return 1;
}

// ---- BGM slot restart ----
extern W1618Bgm D_00347d30[2];
extern s32 D_00347d50;
extern s32 D_00347d40;
void func_00136cc8(W1618Req*, s32);
s32 func_002bd260(s32);
void* W1618_GetAllocator(void) asm("_ZN4AREA12GetAllocatorEv");
void func_002bd310(W1618Req*);
void func_002ba220(s32, s32, s32, s32, s32, s32);
void func_00136b78(s32, s32);
s32 func_00136b90(s32);
s32 func_00225540(void);
s32 func_002b7148(s32);
void W1618_bgmFade(s32, s32, s32) asm("_ZN5SOUND7bgmFadeEiii");
void func_00136cf0(void);

void func_00136d40(W1618Req* r) {
    s32 id;
    if (D_00347d30[0].flags & 1) {
        id = D_00347d30[0].id;
        func_00136cc8(r, id);
        r->handle = func_002bd260(id);
        r->id = id;
        r->slot = 0;
        r->alloc = W1618_GetAllocator();
        func_002bd310(r);
    }
    W1618Bgm* b = &D_00347d30[1];
    if (D_00347d30[1].flags & 1) {
        id = b->id;
        r->handle = func_002bd260(id);
        r->id = id;
        r->slot = 1;
        r->alloc = W1618_GetAllocator();
        func_002bd310(r);
    }
    if (D_00347d30[0].flags & 2) {
        D_00347d50 = 0;
        func_002ba220(0, 0x3000, 0x3000, 0, 0, 0);
        func_00136b78(0, 0x3000);
        return;
    }
    if (func_00136b90(0) != 0x3000) {
        if (D_00347d30[0].f0 == 0) return;
        if (func_00225540()) {
            s32 v = func_00136b90(0);
            if (func_002b7148(0)) {
                W1618_bgmFade(0, v, 20);
            } else {
                func_002ba220(0, 0, 0x3000, 20, 1, 0);
                v = 0x3000;
                D_00347d50 = 0;
            }
            func_00136b78(0, v);
        } else if (func_00136b90(0) == 0) {
            D_00347d50 = 0;
            func_002ba220(0, 0x3000, 0x3000, 0, 0, 0);
            func_00136b78(0, 0x3000);
        } else {
            W1618_bgmFade(0, 0x3000, 20);
            func_00136b78(0, 0x3000);
        }
        func_00136cf0();
    } else {
        if (D_00347d40 == 0) return;
        if (func_002b7148(1)) return;
        if (D_00347d30[0].f0 == 0) return;
        if (func_002b7148(0)) return;
        D_00347d50 = 0;
        func_002ba220(0, 0, 0x3000, 20, 1, 0);
        func_00136b78(0, 0x3000);
        func_00136cf0();
    }
}
}
