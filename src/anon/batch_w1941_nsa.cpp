#include "../common/types.h"

// ---- 00153678 types
struct Al1941;
struct AlVt1941 { void* (*alloc)(Al1941*, u32, s32); };
struct Al1941 { AlVt1941* vt; };
struct InHdr1941 { s32 off; u32 size; };
struct InEnt1941 { s32 a; f32 x, y, z, w; s32 b; };
struct OutEnt1941 { f32 x, y, z, pad; f32 w; u8 rest[44]; };

// ---- 00162560 types
struct V1941 { f32 x, y, z, w;
    V1941() {}
    ~V1941() {}
    V1941& operator=(const V1941& o) {
        if (this != &o) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V1941 operator-(const V1941& b) const {
        V1941 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V1941 cross(const V1941& b) const {
        V1941 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvsub.wxyz $vf3,$vf0,$vf0\n\tvopmula.xyz ACC,$vf1,$vf2\n\tvopmsub.xyz $vf3,$vf2,$vf1\n\tsqc2 $vf3,0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    f32 dot(const V1941& b) const {
        f32 r;
        asm volatile("lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvmul.xyz $vf1,$vf1,$vf2\n\tvaddy.x $vf1,$vf1,$vf1y\n\tvaddz.x $vf1,$vf1,$vf1z\n\tqmfc2 $8,$vf1\n\tmtc1 $8,%0" : "=f"(r) : "r"(this), "r"(&b) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct Poly1941 { V1941* v[4]; s32 n; };

// ---- 0017fba0 types
extern "C" void func_0011c138(void*);
struct E1941 { u8 d[32]; E1941() { func_0011c138(this); } ~E1941() {} };
struct Sub1941 { u8 pad[1184]; u8 m[464]; void* p1648; };
struct Obj1941 {
    u8 pad0[8]; Sub1941* sub; s32 v12; u8 pad1[16]; u32 flags32; u8 pad2[12];
    f32 f48; f32 f52; u8 pad3[152]; s32 v208; s32 v212; u8 pad4[44]; u32 flags260;
};
static inline bool gt0_1941(f32 x) { return 0.0f < x; }

// ---- 001cad60 types
struct Q1941 { f32 x, y, z, w;
    Q1941() {}
    Q1941(const Q1941& o) { asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
static inline void qmuls1941(Q1941* d, f32 s) {
    asm volatile("lqc2 $vf1,0(%0)\n\tmfc1 $8,%1\n\tqmtc2 $8,$vf2\n\tvmulx.wxyz $vf1,$vf1,$vf2x\n\tsqc2 $vf1,0(%0)" : : "r"(d), "f"(s) : "$8", "memory");
}
static inline void qadd1941(Q1941* d, const Q1941* a, const Q1941* b) {
    asm volatile("lqc2 $vf1,0(%1)\n\tlqc2 $vf2,0(%2)\n\tvadd.wxyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
struct Mot1941 { u8 pad[48]; Q1941 p; };
struct Tgt1941;
struct TgtVt1941 { void* f[40]; Mot1941* (*get)(Tgt1941*); };
struct Tgt1941 { TgtVt1941* vt; };
struct Ob1941 { Q1941 pos; u8 pad0[6]; u8 b22; u8 pad1[41]; f32 f64; u8 pad2[44]; Q1941 v112; u8 pad3[32]; f32 f160; u8 pad4[4]; f32 f168; f32 f172; };

extern "C" {

// --- 00153678: load a 24-byte entry table, allocate the 64-byte work entries and init each one
extern Al1941* D_0034a78c;
extern InEnt1941* D_0034a778;
extern s32 D_0034a77c;
extern OutEnt1941* D_0034a790;
void func_001535f0(f32, f32, f32);
void func_001535b0(OutEnt1941*, s32);
void func_00153840(void*);
void func_00153678(InHdr1941* h, void* p, Al1941* al) {
    D_0034a78c = al;
    if (h == 0) {
        D_0034a77c = 0;
        D_0034a778 = 0;
        D_0034a790 = 0;
        return;
    }
    D_0034a778 = (InEnt1941*)((u8*)h + h->off);
    D_0034a77c = h->size / 24;
    D_0034a790 = (OutEnt1941*)al->vt->alloc(al, D_0034a77c << 6, 0);
    func_001535f0(0.125f, 0.5f, 16.0f);
    s32 n = D_0034a77c;
    for (s32 i = 0; i < n; i++) {
        OutEnt1941* o = &D_0034a790[i];
        f32 x = D_0034a778[i].x, y = D_0034a778[i].y, z = D_0034a778[i].z, w = D_0034a778[i].w;
        o->x = x;
        o->y = y;
        o->z = z;
        o->w = w;
        func_001535b0(&D_0034a790[i], i);
    }
    func_00153840(p);
}

// --- 00162560: is the point inside the polygon (every edge cross product faces away from the normal)
extern s32 D_0034c780[];
extern s32 D_0034c790[];
s32 func_00162560(Poly1941* o, V1941* p, V1941* nrm) {
    s32 n = o->n;
    s32* tbl = (n == 3) ? D_0034c780 : D_0034c790;
    V1941 e[2];
    V1941 c;
    for (s32 i = 0; i < n; i++) {
        e[0] = *o->v[tbl[i]] - *o->v[i];
        e[1] = *p - *o->v[i];
        c = e[1].cross(e[0]);
        if (0.01f < c.dot(*nrm)) return 0;
    }
    return 1;
}

// --- 0017fba0: build 16 work entries and run the timed or the plain update on them
s32 func_00180cd0(Obj1941*);
void func_0011c4b0(void*);
void func_001808c0(Obj1941*, E1941*);
void func_00180a10(Obj1941*, E1941*);
s32 func_001b0580(void*);
void func_0011c6a8(f32, void*, s32, s32, s32, s32, E1941*, s32);
void func_0011c4e8(f32, void*, s32, s32, s32, E1941*, s32);
void func_0017fba0(Obj1941* self, s32 a) {
    void* h = self->sub->p1648;
    self->flags32 &= ~0x80;
    self->flags260 = (self->flags260 | 1) & ~2;
    if (h != 0) {
        if (func_00180cd0(self) == 0) {
            E1941 arr[16];
            func_001808c0(self, arr);
            s32 r = func_001b0580(self->sub->m);
            f32 d = self->f52;
            bool pos = gt0_1941(d);
            if (pos) {
                func_0011c6a8(self->f48 / d, h, a, self->v208, self->v212, r, arr, 0);
            } else {
                s32 v = self->v12;
                func_0011c4e8(self->f48, h, a, v, r, arr, 0);
            }
            func_00180a10(self, arr);
            self->flags260 |= 2;
        } else {
            func_0011c4b0(h);
        }
    }
}

// --- 001cad60: count down the timer, then orbit around the target and set the fade byte
extern f32 D_00349e10;
extern f32 D_00351fd8;
Tgt1941* func_002d1260(void);
s32 func_0019ba60(Tgt1941*);
f32 func_001cbf50(f32);
f32 func_002f87c0(f32);
f32 func_002f8960(f32);
s32 func_001cad60(Ob1941* self) {
    Tgt1941* t = func_002d1260();
    self->f64 -= D_00349e10;
    if (self->f64 <= 0.0f || !func_0019ba60(t)) return 0;
    self->f160 += self->f168 * D_00349e10;
    f32 k = self->f64 / D_00351fd8;
    f32 a = func_001cbf50(self->f160);
    self->pos.x = func_002f87c0(a);
    self->pos.y = func_002f8960(a);
    self->pos.z = 0.0f;
    qmuls1941(&self->pos, self->f172 * k);
    Q1941 v = self->v112;
    qmuls1941(&v, v.w * k);
    Mot1941* m = t->vt->get(t);
    Q1941 u;
    qadd1941(&u, &v, &m->p);
    qadd1941(&self->pos, &self->pos, &u);
    self->b22 = (s32)(k * 255.0f);
    return 1;
}

}
