#include "../common/types.h"
// VU0 vector / matrix helpers (inline asm like the game's vector library).
struct W3701Vec {
    f32 x, y, z, w;
    W3701Vec() {}
    W3701Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W3701Vec& operator=(const W3701Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W3701Vec& operator+=(const W3701Vec& o) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
    // Perspective divide: this *= 1/w.
    void divW() {
        f32 d = w;
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.wxyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(d) : "$8", "memory");
    }
} __attribute__((aligned(16)));
struct W3701Mtx {
    W3701Vec r[4];
    W3701Mtx() {}
    inline W3701Mtx(const W3701Mtx& o) __attribute__((always_inline));
    W3701Mtx& operator=(const W3701Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    // Full 4x4 transform.
    void apply(W3701Vec& o, const W3701Vec& v) const {
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "vmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)"
                     : : "r"(&o), "r"(this), "r"(&v) : "memory");
    }
    // Point transform (w = 1).
    void applyPoint(W3701Vec& o, const W3701Vec& v) const {
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "vmulax.xyz ACC, $vf1, $vf5x\n\tvmadday.xyz ACC, $vf2, $vf5y\n\tvmaddaz.xyz ACC, $vf3, $vf5z\n\tvmaddw.xyz $vf5, $vf4, $vf0w\n\tvmove.w $vf5, $vf0\n\tsqc2 $vf5, 0(%0)"
                     : : "r"(&o), "r"(this), "r"(&v) : "memory");
    }
    // Inverse of a rotation + translation matrix (transpose, translation = -R^T t).
    void orthoInverse() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
                     "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
                     "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
                     "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
                     "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)"
                     : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
inline W3701Mtx::W3701Mtx(const W3701Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
extern "C" void func_0031bae0(void*, const void*);   // sceVu0CopyMatrix
struct W3701F2 { f32 v[2]; };
struct W3701I3 { s32 v[3]; };
struct W3701DI { u64 d; s32 i; };
struct W3701I5 { s32 v[5]; };
struct W3701U64 { u64 v; };
struct W3701S32 { s32 v; };
struct W3701Mtx2 {
    f32 m[4][4];
} __attribute__((aligned(16)));
void W3701_projDtor(void*) asm("_ZN2kn10ProjectionD1Ev");
struct W3701Proj {
    W3701Mtx view;
    f32 f64;
    f32 fov[2];
    s32 i76[3];
    u64 d88;
    s32 i96;
    f32 f100, f104, f108, f112, f116, f120;
    W3701Mtx2 m128;
    W3701Mtx2 m192;
    inline W3701Proj(const W3701Proj& o, void* mgr) __attribute__((always_inline));
    ~W3701Proj() { W3701_projDtor(this); }
};

inline W3701Proj::W3701Proj(const W3701Proj& o, void* mgr) : view(o.view) {
        // Scalar part of the copy, loads in the original's order.
        register s32 b76 asm("$14"), b80 asm("$13"), b84 asm("$12");
        register u32 a68 asm("$8"), a72 asm("$9");
        register u64 d asm("$11");
        register s32 i asm("$10");
        register f32 c120 asm("$f6"), a64 asm("$f5");
        register f32 c100 asm("$f0"), c104 asm("$f1"), c108 asm("$f2"), c112 asm("$f3"), c116 asm("$f4");
        register void* q1 asm("$5");
        register void* q0 asm("$4");
        const W3701Proj* op = &o;
        asm volatile("lw %0, 76(%1)" : "=r"(b76) : "r"(op));
        asm volatile("addiu %0, %1, 160" : "=r"(q1) : "r"(mgr));
        asm volatile("lw %0, 80(%1)" : "=r"(b80) : "r"(op));
        asm volatile("addiu %0, $sp, 256" : "=r"(q0));
        asm volatile("lw %0, 84(%1)" : "=r"(b84) : "r"(op));
        asm volatile("lw %0, 68(%1)" : "=r"(a68) : "r"(op));
        asm volatile("lw %0, 72(%1)" : "=r"(a72) : "r"(op));
        asm volatile("ld %0, 88(%1)" : "=r"(d) : "r"(op));
        asm volatile("lw %0, 96(%1)" : "=r"(i) : "r"(op));
        asm volatile("lwc1 %0, 120(%1)" : "=f"(c120) : "r"(op));
        asm volatile("lwc1 %0, 64(%1)" : "=f"(a64) : "r"(op));
        asm volatile("lwc1 %0, 100(%1)" : "=f"(c100) : "r"(op));
        asm volatile("lwc1 %0, 104(%1)" : "=f"(c104) : "r"(op));
        asm volatile("lwc1 %0, 108(%1)" : "=f"(c108) : "r"(op));
        asm volatile("lwc1 %0, 112(%1)" : "=f"(c112) : "r"(op));
        asm volatile("lwc1 %0, 116(%1)" : "=f"(c116) : "r"(op));
        f64 = a64; ((u32*)fov)[0] = a68; ((u32*)fov)[1] = a72; i76[0] = b76; i76[1] = b80; i76[2] = b84;
        d88 = d; i96 = i; f100 = c100; f104 = c104; f108 = c108; f112 = c112; f116 = c116; f120 = c120;
        func_0031bae0(q0, q1);
        func_0031bae0(m192.m, o.m192.m);
    }
struct W3701Box { f32 x0, y0, z0, x1, y1, z1; };
struct W3701Ob {
    s32 id;             // 0
    u32 pad4;
    u8 sub8[16];        // 8
    u64 gs24;           // 24
    u64 gs32;           // 32
    u8 pad40[24];
    W3701Mtx mtx;       // 64
    u8 pad128[64];
    W3701Vec pos;       // 192
    W3701Box box;       // 208, bounds
    u8 color[4];        // 232
    u8 pad236[12];
    u32 flags;          // 248
    u8 pad252[8];
    f32 boxGrow;        // 260
    f32 fadeDist;       // 264
    u8 alpha;           // 268
    u8 b269;            // 269
    u8 vis[2];          // 270, per slot
    u8 pad272[14];
    u8 b286;            // 286
    u8 pad287;
    W3701Mtx* attach;   // 288
};
struct W3701ObFl { u8 pad[248]; u32 flags; };
struct W3701Mgr {
    u8 pad0[32];
    W3701Proj proj;     // 32
    u8 pad288[16];
    W3701Mtx view;      // 304
    W3701Mtx screen;    // 368?
    W3701Mtx clip;      // 432
    u8 frustum[21352 - 496];    // 496
    s32 x21352;         // 21352
    s32 slot;           // 21356
};
struct W3701Pkt { u8 pad0[20]; u32 xy; u8 pad24[56]; void* cb0; void* cb1; };
extern "C" {
void func_00147c78(W3701Mgr*, W3701Ob*);
void func_00106fe8(W3701Proj*, f32);
void func_00106c08(W3701Proj*);
W3701Pkt* func_0011ca20(s32, void*, W3701Mtx*, void*, u8);
void func_00147e80(void);
void func_00147ed0(void);

void func_00147f08(W3701Mgr* m, W3701Ob* o)
{
    func_00147c78(m, o);
    s32 slot = m->slot;
    o->gs32 = 0x31000070;
    o->vis[slot] = 0;
    o->gs24 = 0x800d8;
    if (((W3701ObFl*)o)->flags & 0x1000) {
        W3701Mtx M;
        W3701Vec* pt = &M.r[3];
        W3701Vec t;
        W3701Vec scr;
        W3701Vec pos;
        W3701Vec* pv = &t;
        W3701Vec* ps = &scr;
        W3701Vec* pp = &pos;
        if (o->attach) {
            W3701Vec v;
            W3701Vec* pw = &v;
            M = *o->attach;
            pw->x = M.r[0].w;
            pw->y = M.r[1].w;
            pw->z = M.r[2].w;
            f32 s = M.r[3].w;
            M.r[3].w = 1.0f;
            M.r[0].w = 0.0f;
            M.r[1].w = 0.0f;
            M.r[2].w = 0.0f;
            W3701Proj cam(m->proj, m);
            func_00106fe8(&cam, s);
            func_00106c08(&cam);
            *pp = *pt;
            *pp += *pw;
            cam.view.apply(*ps, *pp);
            ps->divW();
            ps->x -= 2048.0f;
            ps->y -= 2048.0f;
            pt->x -= pp->x;
            pt->y -= pp->y;
            W3701Pkt* p = func_0011ca20(o->id, &cam, &M, o->sub8, o->b269);
            p->cb0 = (void*)func_00147e80;
            p->xy = ((s32)(ps->x * 16.0f + 0.5f) & 0xffff) | ((s32)(ps->y * 16.0f + 0.5f) << 16);
            p->cb1 = (void*)func_00147ed0;
        } else {
            M = o->mtx;
            *pv = o->pos;
            m->view.applyPoint(*pp, *pv);
            *ps = o->pos;
            ps->w = 1.0f;
            m->clip.apply(*ps, *ps);
            ps->divW();
            ps->x -= 2048.0f;
            ps->y -= 2048.0f;
            W3701Mtx W(m->view);
            W.orthoInverse();
            W3701Vec z(0.0f, 0.0f, pp->z, 0.0f);
            W.applyPoint(*pt, z);
            W3701Pkt* p = func_0011ca20(o->id, &m->clip, &M, o->sub8, o->b269);
            p->cb0 = (void*)func_00147e80;
            p->xy = ((s32)(ps->x * 16.0f + 0.5f) & 0xffff) | ((s32)(ps->y * 16.0f + 0.5f) << 16);
            p->cb1 = (void*)func_00147ed0;
        }
    } else {
        func_0011ca20(o->id, &m->clip, &o->mtx, o->sub8, o->b269);
    }
}
}
