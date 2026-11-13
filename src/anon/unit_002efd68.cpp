#include "../common/types.h"

// 0x2efd68-0x2f0700: friend/party motion controllers (idle/turn motion choice, move speed from the
// velocity, reaction and pose helpers). Linked unit. The motion tables (0x3638d8) and the six
// vtables (0x363920-0x363a40) stay retail data; the methods are written as plain functions.

// 16-byte VU0 vector.
struct W1634Vec {
    f32 x, y, z, w;
} __attribute__((aligned(16)));

// Motion player embedded in the object at +320.
struct W1634Motion {
    u8 pad0[20];
    s32 id;                  // current motion id (+340 in the object)
    u8 pad18[8];
};

struct W1634MotObj {
    u8 pad0[16];
    W1634Vec vel;            // +16 (y = vertical speed, w = horizontal speed)
    W1634Vec dir;            // +32
    u8 pad30[192];
    f32 f240;                // +240
    f32 stopSpeed;           // +244
    u8 pad248[24];
    f32 f272;                // +272
    f32 f276;                // +276
    u8 pad118[4];
    f32 turnLimit;           // +284
    u8 pad120[32];
    W1634Motion motion;      // +320
    u32 motFlags;            // +352
};

struct M2efe18 { u8 pad0[48]; f32 time; };
struct O2efe18 { u8 pad0[320]; M2efe18 mot; };

extern "C" {
extern f32 D_00349e10;
extern u8* D_00352130;
extern s32 D_003638d8[3][6];   // motion id tables: idle, idle2, stop, turn right, turn left
s32 func_0016a070(W1634MotObj*);   // YS::OBJ::get_part_num
f32 fabsf(f32);
s32 func_002eff58(W1634MotObj*);
void func_0016af58(W1634Vec*, W1634MotObj*);
f32 func_002f8aa0(f32);
f32 func_002efe18(O2efe18*, s32, f32);
void func_0017f488(void*, s32, f32, f32);
f32 func_001806f8(M2efe18*, s32);
f32 func_00180770(M2efe18*, s32);
f32 func_002f8b00(f32, f32);
void func_0016bd60(void*, s32);
void func_0017c430(void*);
void func_0017c4c8(void*, W1634Vec*);
void func_0017c030(W1634Vec*, void*, s32*, u8);
}
void wtarget_0017cc30(void*, void*, s32) asm("_Z16wtarget_0017cc30jjjj");
void wtarget_002f0598(void* o, W1634Vec* q) asm("_Z16wtarget_002f0598jjjj");

static inline void W1634VecCopy(W1634Vec* d, const W1634Vec* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline void W1634VecAssign(W1634Vec* d, const W1634Vec* s) {
    if (d != s) W1634VecCopy(d, s);
}
static inline void W1634VecAdd(W1634Vec* d, const W1634Vec* a, const W1634Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 W1634Normalize(W1634Vec* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline f32 W1634Length(const W1634Vec* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline void W1634Scale(W1634Vec* d, const W1634Vec* v, f32 s) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(d), "r"(v), "f"(s) : "$8", "memory");
}
static inline void W1634Zero(W1634Vec* v) {
    asm volatile("vsub.wxyz $vf1, $vf0, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(v) : "memory");
}
static inline f32 W1634Dot(const W1634Vec* a, const W1634Vec* b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(a), "r"(b) : "$8", "memory");
    return r;
}
static inline void W1634Cross(W1634Vec* r, const W1634Vec* a, const W1634Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)"
                 : : "r"(r), "r"(a), "r"(b) : "memory");
}

// t[2] is pinned to t6: the original keeps the stop-motion entry in t6 at every compare
// (register pin, no code; the closest plain C put it in t7 and changed the delay-slot fills).
static inline bool W1634InTable(s32 id, const s32* t) {
    register s32 stop asm("$14");
    if (id == t[0] || id == t[1] || id == (stop = t[2]) || id == t[3] || id == t[4]) return true;
    return false;
}

// True unless the change is idle -> stop or stop -> none (those cut without blending when flag 2 is set).
static inline bool W1634NeedBlend(s32 cur, s32 next, s32 idle, s32 stop) {
    if (cur == idle && next == stop) return false;
    if (cur == stop && next == 0) return false;
    return true;
}

// Move direction from the velocity: unit vector times the speed (w) times the frame time.
void ctl_2efd68(void* self, W1634MotObj* obj) {
    W1634Vec v;
    W1634VecCopy(&v, &obj->vel);
    f32 w = obj->vel.w;
    W1634Normalize(&v);
    W1634Vec b, a;
    W1634Vec* d = &obj->dir;
    W1634Scale(&a, &v, w);
    W1634Scale(&b, &a, D_00349e10);
    W1634VecAssign(d, &b);
    obj->f240 = 0.85f;
}

extern "C" {

f32 func_002efe18(O2efe18* o, s32 id, f32 dt) {
    M2efe18* m = &o->mot;
    f32 t = m->time + D_00349e10 + dt;
    f32 s0 = func_001806f8(m, -1);
    f32 e0 = func_00180770(m, -1);
    f32 s1 = func_001806f8(m, id);
    f32 e1 = func_00180770(m, id);
    f32 r;
    if (e0 < s0 && e1 < s1) {
        if (e0 < t) {
            f32 d = s1 - e1;
            r = (t - e0) / (s0 - e0);
            return e1 + func_002f8b00(d * r, d);
        }
        r = t / e0;
        return func_002f8b00(e1 * r, e1);
    }
    r = t / s0;
    return func_002f8b00(s1 * r, s1);
}

s32 func_002eff58(W1634MotObj* o) {
    f32 t = (o->f272 + o->f276) * 0.5f;
    return t <= o->vel.w;
}
void func_002eff90(void* self, W1634MotObj* obj) {
    const s32* tbl;
    W1634Motion* mot;
    s32 cur;
    s32 next;
    f32 blend = 0.0f;
    u32 flags;

    switch (func_0016a070(obj)) {
    case 202: tbl = D_003638d8[1]; break;
    case 201: tbl = D_003638d8[2]; break;
    case 200: default: tbl = D_003638d8[0]; break;
    }
    mot = &obj->motion;
    cur = mot->id;
    next = 0;
    if (cur != 0 && !W1634InTable(cur, tbl)) return;
    if (1.0f < obj->vel.w && fabsf(obj->vel.y) < 0.8f) {
        if (cur == 0) {
            if (func_002eff58(obj)) {
                next = tbl[1];
                if (next < 0) next = tbl[0];
            } else {
                next = tbl[0];
                if (next < 0) next = tbl[1];
            }
        } else {
            W1634Vec d;
            W1634Vec a;
            W1634Vec c;
            W1634Vec* dir = &obj->dir;
            f32 lim;
            func_0016af58(&a, obj);
            W1634VecAdd(&d, dir, &a);
            W1634VecCopy(&a, &obj->vel);
            d.y = 0.0f;
            a.y = 0.0f;
            W1634Normalize(&d);
            W1634Normalize(&a);
            lim = obj->turnLimit * 0.65f;
            if (lim < func_002f8aa0(W1634Dot(&d, &a))) {
                W1634Cross(&c, &d, &a);
                if (c.y > 0.0f && tbl[3] >= 0) next = tbl[3];
                if (c.y < 0.0f && tbl[4] >= 0) next = tbl[4];
            }
            if (next != tbl[3] && next != tbl[4]) {
                if (func_002eff58(obj)) {
                    if (tbl[1] >= 0) {
                        next = tbl[1];
                        blend = func_002efe18((O2efe18*)obj, next, 16.0f);
                    } else {
                        next = tbl[0];
                    }
                } else {
                    if (tbl[0] >= 0) {
                        next = tbl[0];
                        blend = func_002efe18((O2efe18*)obj, next, 16.0f);
                    } else {
                        next = tbl[1];
                    }
                }
            }
        }
    } else {
        register s32 stop asm("$14");
        if (!W1634InTable(cur, tbl) || (stop = tbl[2]) < 0) next = 0;
        else next = stop;
    }

    if (cur != next) {
        flags = obj->motFlags;
        if ((flags & 4) || ((flags & 0x10) && next != 0)) {
            if (W1634NeedBlend(cur, next, tbl[0], tbl[2]) || !(flags & 2)) {
                func_0017f488(mot, next, 16.0f, blend);
            } else {
                func_0017f488(mot, next, 0.0f, 0.0f);
            }
        }
    } else if (cur == tbl[2] && (obj->motFlags & 2)) {
        func_0017f488(mot, 0, 0.0f, 0.0f);
    }
}

}

void ctl_2f03b8(void* self, W1634MotObj* obj) {
    W1634Vec v;
    W1634VecCopy(&v, &obj->vel);
    f32 w = obj->vel.w;
    W1634Normalize(&v);
    W1634Vec b, a;
    W1634Vec* d = &obj->dir;
    W1634Scale(&a, &v, w);
    W1634Scale(&b, &a, D_00349e10);
    W1634VecAssign(d, &b);
}

W1634Vec ctl_2f0458(void* self, W1634MotObj* obj) {
    W1634Vec r;
    W1634VecAssign(&r, &obj->vel);
    f32 w = obj->vel.w;
    W1634Normalize(&r);
    W1634Scale(&r, &r, w * D_00349e10);
    r.w = 1.0f;
    return r;
}

extern "C" {

void func_002f04e0(void* self, W1634MotObj* obj) {
    W1634Vec* v = &obj->dir;
    W1634Scale(v, v, *(f32*)(D_00352130 + 60));
    if (W1634Length(v) < obj->stopSpeed) {
        W1634Zero(v);
        func_0017f488(&obj->motion, 0, 0.0f, 0.0f);
        func_0016bd60(obj, 31);
    }
}

}

void ctl_2f0588(void* self, W1634MotObj* obj) {}

void ctl_2f0590(void* self, W1634MotObj* obj) {}

void wtarget_002f0598(void* o, W1634Vec* q) {
    W1634Vec t;
    W1634VecCopy(&t, q);
    func_0017c4c8(o, &t);
    func_0016bd60(o, 63);
}

extern "C" void func_002f05d8(void* o) {
    func_0017c430(o);
    func_0016bd60(o, 63);
}

void ctl_2f0608(void* self, void* o, W1634Vec* q) {
    wtarget_002f0598(o, q);
}

void ctl_2f0628(void* self, void* o) {
    func_002f05d8(o);
}

extern "C" void func_002f0640(void* self, u8* obj, u8 flag) {
    W1634Vec tmp;
    W1634Vec v;
    s32 w;
    func_0017c030(&tmp, obj, &w, flag);
    W1634VecCopy(&v, &tmp);
    func_0017c4c8(obj, &v);
    obj[1300] = 9;
    func_0017f488(obj + 320, w, 0.0f, 0.0f);
    *(u32*)(obj + 256) = 4;
    *(u32*)(obj + 260) = 5;
}

extern "C" void func_002f06b0(void* self, void* o, W1634Vec* q) {
    wtarget_002f0598(o, q);
}

void ctl_2f06d0(void* self, void* o) {
    func_002f05d8(o);
}

extern "C" void func_002f06e8(void* self, void* o) {
    wtarget_0017cc30(self, o, 62);
}
