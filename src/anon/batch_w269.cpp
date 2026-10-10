#include "../common/types.h"
#define QCOPY269(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV269 {
    f32 x, y, z, w;
    QV269() {}
    QV269(const QV269& o) { QCOPY269(this, &o); }
    QV269& operator=(const QV269& o) { if (this != &o) QCOPY269(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline void normalize269(QV269* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(v) : "$8", "memory");
}
#define QCOPY4_269(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct RV269 {
    f32 v[4];
    RV269& operator*=(f32 k) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "f"(k) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct M269 {
    RV269 r[4];
    M269() {}
    M269& operator=(const M269& o) { if (this != &o) QCOPY4_269(this, &o); return *this; }
} __attribute__((aligned(16)));
union PU269 { u8* p; u16 h; u8 c; };
typedef void (*VF269)(u8*);
#define VCALL269(p) ((*(VF269*)(*(u8**)(p) + 20))(p))
typedef void (*KVF269)(u8*);
#define KVCALL269(p, off) ((*(KVF269*)(*(u8**)(p) + (off)))(p))
#define QCOPYL269(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct LV269 {
    f32 x, y, z, w;
    LV269() {}
    LV269(const LV269& o) { QCOPYL269(this, &o); }
    LV269& operator=(const LV269& o) { if (this != &o) QCOPYL269(this, &o); return *this; }
} __attribute__((aligned(16)));
static inline LV269 operator*(const LV269& a, f32 k) {
    LV269 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
static inline LV269 operator+(const LV269& a, const LV269& b) {
    LV269 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
struct LM269 {
    LV269 r[4];
    LM269& operator=(const LM269& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct LO269 {
    u8 pad[3088];
    LM269 prev;   // 3088
    LM269 cur;    // 3152
    LV269 pts[9]; // 3216.. (pts[1] at 3232)
};
struct NM269 {
    f32 m[16];
    NM269() {}
    NM269& operator=(const NM269& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline __attribute__((always_inline)) void ncopy269(NM269* d, const NM269* s) { *d = *s; }
struct NI269 { s32 h0; s32 frames; u8 b8; };
struct NO269 {
    u8 pad[100];
    NI269* info;   // 100
    u8 sub[8];     // 104
    s32 f112;      // 112
    s32 idx;       // 116
    f32 time;      // 120
    s32 speed;     // 124
    u32 pad128;
    u8 stop;       // 132
    u8 flag;       // 133
    u8 pad134[10];
    NM269 mtx;     // 144
};
struct SF269 {
    u8* p;
    s32 r, w;
    s16 flags;
    s16 file;
    u8* base;
    s32 size;
    s32 lbfsize;
    void* cookie;
    void* rd;
    void* wr;
    void* seek;
    void* cl;
    u8 pad48[16];
    u8 ubuf[3];
    u8 nbuf[1];
    u8 pad68[8];
    s32 blksize;
    s32 offset;
    u8* data;
};
struct SS269 { s16 dev; s16 ino; u32 mode; u8 pad[104]; };
extern "C" {

void func_0011b6a8(f32*);
f32 func_002f8960(f32);
f32 func_002f87c0(f32);
void func_0011b408(f32* m, const QV269* a) {
    func_0011b6a8(m);
    QV269 v;
    v = *a;
    normalize269(&v);
    f32 x = v.x, y = v.y, z = v.z;
    f32 s = func_002f8960(a->w);
    f32 c = func_002f87c0(a->w);
    f32 t = 1.0f - c;
    f32 xy = x * y, yz = y * z, zx = z * x;
    f32 xs = x * s, ys = y * s, zs = z * s;
    m[0] = x * x * t + c;
    m[1] = xy * t + zs;
    m[2] = zx * t - ys;
    m[4] = xy * t - zs;
    m[5] = y * y * t + c;
    m[6] = yz * t + xs;
    m[8] = zx * t + ys;
    m[9] = yz * t - xs;
    m[10] = z * z * t + c;
}
void func_0011b558(f32* m, const QV269* a) {
    func_0011b6a8(m);
    QV269 v;
    v = *a;
    normalize269(&v);
    f32 x = v.x, y = v.y, z = v.z;
    f32 s = func_002f8960(a->w);
    f32 c = func_002f87c0(a->w);
    f32 t = 1.0f - c;
    f32 xy = x * y, yz = y * z, zx = z * x;
    f32 xs = x * s, ys = y * s, zs = z * s;
    m[0] = x * x * t + c;
    m[1] = xy * t + zs;
    m[2] = zx * t - ys;
    m[4] = xy * t - zs;
    m[5] = y * y * t + c;
    m[6] = yz * t + xs;
    m[8] = zx * t + ys;
    m[9] = yz * t - xs;
    m[10] = z * z * t + c;
}

f32 func_0011bdc0(M269*, s32, s32);
f32 func_0011be50(M269* m) {
    M269 t;
    s32 i, j;
    for (i = 0; i < 4; i++) {
        f32* p = t.r[i].v; for (j = 0; j < 4; j++) { *p++ = func_0011bdc0(m, j, i);
        }
    }
    f32 det = 0.0f;
    for (i = 0; i < 4; i++) det += t.r[i].v[0] * m->r[0].v[i];
    *m = t;
    f32 inv = 1.0f / det;
    m->r[0] *= inv;
    m->r[1] *= inv;
    m->r[2] *= inv;
    m->r[3] *= inv;
    return det;
}

u16* func_001b8e88(s32);
s32 func_001b90f0(u16*, s32);
s32 func_001c11e0(void);
s32 func_00190140(u32*);
s32 func_0019c4f8(u32);
void func_0019da68(u8*, u16*, u32*, s32, s32);
s32 func_0019dbc0(u8* a0, s32 a1, u32* a2, s32 a3, s32 a4) {
    if (a3 >= *(s32*)(a0 + 0x50)) {
        if (a3 != *(s32*)(a0 + 0x50)) goto body;
        if (a4 < *(s32*)(a0 + 0x24)) goto body;
    }
    return 0;
body:
    u16* v = func_001b8e88(a1);
    if (a3 != 201) {
        s32 k = *(s32*)(**(u8***)a0 + 2528);
        if (!func_001b90f0(v, k)) return 0;
        if (*v == 30 || *v == 604) {
            if (func_001c11e0()) return 0;
        }
        if (*v != 456) {
            u32 ok = 0;
            if (func_00190140(a2)) ok = *a2 != 0;
            if ((u8)ok) {
                if (func_0019c4f8(*a2)) return 0;
            }
        }
    }
    func_0019da68(a0, v, a2, a3, a4);
    return 1;
}

extern PU269 D_0035f230;
extern s32 D_0035f010;
u8* func_002570e0(void);
void func_0028fb28(s32, u16);
void func_00257050(s32, s32, s32);
s32 func_00257070(s32);
void func_002772c8(s32);
u16 func_002813b8(void);
s32 func_0027ae20(void);
s32 func_00281100(s32);
s32 func_0027aa78(void);
s32 func_00281140(s32, s32);
void func_0028fb68(s32, s32);
void func_00279040(void);
void func_00277d20(void);
void func_00277178(s32 a0, s32 a1) {
    func_0028fb28(0, *(u16*)(func_002570e0() + 54));
    func_00257050(0, 1, 0);
    if (a0 == 15) {
        func_002772c8(a1);
        return;
    }
    PU269* p = (PU269*)D_0035f230.p;
    p->h = func_002813b8();
    u8* q = D_0035f230.p;
    s32 r = func_0027ae20();
    q[6] = r + func_00281100(D_0035f010);
    if (func_0027aa78()) *(u16*)D_0035f230.p |= 0x80;
    if (a1) a1 += func_0027ae20();
    if (func_00257070(15) != a1) {
        func_00257050(16, 0, 0);
        func_00257050(15, a1, 0);
    }
    if (a1) a1 -= func_0027ae20();
    func_0028fb68(1, func_00281140(D_0035f010, a1));
    func_00279040();
    func_00277d20();
}

extern u8* D_0035f2c8;
extern u8* D_0035f2cc;
extern u8* D_0035f2d8;
extern u8* D_0035f2dc;
s32 func_00139d78(u8*);
void func_00139510(u8*);
s32 func_0028acc8(u8*);
void func_0028abe0(u8*);
void func_002843e8(void) {
    s32 i;
    if (func_00139d78(D_0035f2c8)) VCALL269(D_0035f2c8);
    if (func_00139d78(D_0035f2cc)) func_00139510(D_0035f2cc);
    if (func_00139d78(D_0035f2cc + 436)) func_00139510(D_0035f2cc + 436);
    for (i = 0; i < 8; i++) {
        if (func_00139d78(D_0035f2cc + i * 436 + 872)) VCALL269(D_0035f2cc + i * 436 + 872);
        if (func_00139d78(D_0035f2cc + i * 436 + 4360)) VCALL269(D_0035f2cc + i * 436 + 4360);
    }
    if (func_00139d78(D_0035f2d8)) VCALL269(D_0035f2d8);
    if (func_0028acc8(D_0035f2dc)) func_0028abe0(D_0035f2dc);
}

extern u8* D_0035f5ac;
extern u8* D_0035f5b0;
extern u8 D_0035f5b4;
extern s16 D_0035f5b6;
extern u32 D_0035f5b8;
extern u8* D_0035f5bc;
extern s8 D_0035f5c4;
extern u8 D_00347e60[];
void func_00106420(void*);
void func_0031abd8(u8*);
void func_0031acc0(u8*);
void func_00239870(u8*);
void func_0031a840(u8*);
void func_0029a8e0(void) {
    if (D_0035f5ac) {
        func_00106420(D_0035f5ac);
        D_0035f5ac = 0;
    }
    u8* o = D_0035f5b0;
    if (o) {
        u8* p;
        func_0031abd8(o + 6512);
        p = o + 6104;
        func_0031abd8(p);
        if (o + 3924 != 0) {
            u8* e1 = o + 3924;
        top1:
            if (e1 == p) goto out1;
            p -= 436;
            KVCALL269(p, 12);
            goto top1;
        }
    out1:
        if (o + 1744 != 0) {
            u8* q = o + 3924;
            u8* e2 = o + 1744;
        top2:
            if (e2 == q) goto out2;
            q -= 436;
            KVCALL269(q, 12);
            goto top2;
        }
    out2:
        func_0031acc0(o + 1308);
        func_0031acc0(o + 872);
        func_0031acc0(o + 436);
        *(u32*)o = (u32)D_00347e60;
        func_00239870(o + 24);
        func_0031a840(o);
        func_00106420(o);
        D_0035f5b0 = 0;
    }
    if (D_0035f5bc) {
        KVCALL269(D_0035f5bc, 16);
        D_0035f5bc = 0;
    }
    D_0035f5b4 = 0;
    D_0035f5b6 = -1;
    D_0035f5b8 = 0;
    D_0035f5c4 = -1;
}

void func_002d0bd8(LO269*, const LM269*);
void func_002da520(LO269* a0, const LM269* a1) {
    a0->prev = a0->cur;
    a0->cur = *a1;
    func_002d0bd8(a0, a1);
    LV269 a = a0->prev.r[3];
    LV269 b = a0->cur.r[3];
    s32 i;
    s32 n = 8;
    for (i = 1; i <= n; i++) {
        f32 t = (f32)i / (f32)n;
        a0->pts[i] = b * t + a * (1.0f - t);
    }
}

extern f32 D_00349e10;
s32 func_002e34c8(u8*);  // obj_get_field8_by_vtable
void func_001991a8(s32, s32);
void func_002e0fa0(NO269*, s32);
NM269 func_002e71a0(s32, u8, s32);
void wt269(NO269* a0, u32, u32, u32) asm("_Z16wtarget_002e1288jjjj");
void wt269(NO269* a0, u32, u32, u32) {
    a0->flag = 0;
    if (!a0->stop) {
        a0->time += (f32)a0->speed * D_00349e10 * 0.5f / 100.0f;
    }
    if ((f32)a0->info->frames + 1.0f <= a0->time) {
        a0->idx++;
        if (a0->idx >= func_002e34c8(a0->sub)) {  // obj_get_field8_by_vtable
            func_001991a8(21, 0);
            a0->idx = func_002e34c8(a0->sub) - 1;
            a0->time = (f32)a0->info->frames;
        } else {
            func_002e0fa0(a0, a0->idx);
        }
    }
    NM269 t = func_002e71a0(a0->f112, a0->info->b8, 1);
    ncopy269(&a0->mtx, &t);
}

s32 func_003050b8(u8*, s32, SS269*);
void* mal269(u8*, u32) asm("_Z16wtarget_002fd680jjjj");
s32 isatty269(s32) asm("_Z13func_00305dd0xxxx");
void func_00302dd0(void);
s32 func_00304ec8(void*, s32, s32);
void func_00303808(SF269* fp) {
    u32 size;
    s32 couldbetty;
    void* p;
    SS269 st;
    if (fp->flags & 2) {
        fp->base = fp->p = fp->nbuf;
        fp->size = 1;
        return;
    }
    if (fp->file < 0 || func_003050b8(fp->data, fp->file, &st) < 0) {
        couldbetty = 0;
        size = 1024;
        fp->flags |= 0x800;
    } else {
        couldbetty = (st.mode & 0xf000) == 0x2000;
        size = 1024;
        if ((st.mode & 0xf000) == 0x8000 && fp->seek == (void*)func_00304ec8) {
            fp->flags |= 0x400;
            fp->blksize = size;
        } else {
            fp->flags |= 0x800;
        }
    }
    if ((p = mal269(fp->data, size)) == 0) {
        fp->flags |= 2;
        fp->base = fp->p = fp->nbuf;
        fp->size = 1;
    } else {
        *(void**)(fp->data + 60) = (void*)func_00302dd0;
        fp->flags |= 0x80;
        fp->base = fp->p = (u8*)p;
        fp->size = size;
        if (couldbetty && isatty269(fp->file)) fp->flags |= 1;
    }
}
}
