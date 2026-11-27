#include "../common/types.h"

// Lock-on target file (0x1cd660-0x1ce6e8): the 8-entry target slot list, the lock-on state
// (C2/C1 constructor pair 0x1cd948/0x1cda88), the target scan, the 4-char resource tags
// ("plyr", "fmab", "prty", "magi", "sstm"), the lock-on marker object and its particle
// callback, and the file's static initialiser + _GLOBAL__I_ stub. The globals stay data.

// ---- 0x1cd660
namespace n001cd660 {
void func_001cd660(u8* a0) asm("_Z13func_001cd660Ph");
void func_001cd660(u8* a0) {
    s32 t7 = 7;
    u8* p = a0 + 4;
    do {
        *(u32*)p = 0;
        --t7;
        p += 8;
    } while (t7 >= 0);
}
}  // namespace n001cd660

// ---- 0x1cd690
namespace n001cd690 {
struct W1825Slot { u32 val; void* obj; };
s32 YS__OBJ__is_exist(void*) asm("YS__OBJ__is_exist");
static inline bool w1825_dead(void* p)
{
    bool r = 0;
    if (!p || !YS__OBJ__is_exist(p)) r = 1;
    return r;
}
void YS__PRIORITYTARGET__search(W1825Slot* s, u32 val, void* obj) asm("YS__PRIORITYTARGET__search");
void YS__PRIORITYTARGET__search(W1825Slot* s, u32 val, void* obj) {
    W1825Slot* e;
    s32 i;
    W1825Slot* found;
    for (i = 7, e = s; i >= 0; i--, e++) {
        if (!w1825_dead(e->obj)) {
            if (!YS__OBJ__is_exist(e->obj)) e->obj = 0;
        }
    }
    if (!YS__OBJ__is_exist(obj)) return;
    found = 0;
    for (i = 0; i < 8; i++) {
        if (s[i].obj == obj) { found = &s[i]; break; }
        if (w1825_dead(s[i].obj)) found = &s[i];
    }
    found->val = val;
    found->obj = obj;
}
}  // namespace n001cd690

// ---- 0x1cd7a8
namespace n001cd7a8 {
typedef struct { s32 lvl; s32 id; } W1572_Cand;
extern u32 D_003638d0 asm("D_003638d0");
s32 YS__OBJ__is_exist(s32) __asm__("_Z17YS__OBJ__is_existjjjj");
u64 func_00312db8(u64, u64) asm("func_00312db8");
static inline u8 W1572_Invalid(s32 id) {
    u8 r = 0;
    if (id == 0 || YS__OBJ__is_exist(id) == 0) r = 1;
    return r;
}
s32 func_001cd7a8(W1572_Cand* arg) asm("func_001cd7a8");
s32 func_001cd7a8(W1572_Cand* arg) {
    s32 n = 0;
    W1572_Cand c[8];
    s32 i;
    { W1572_Cand* q = c; s32 k = 7; do { q->id = 0; q++; } while (--k != -1); }
    for (i = 0; i < 8; i++) {
        if (W1572_Invalid(arg[i].id)) continue;
        if (YS__OBJ__is_exist(arg[i].id) == 0) continue;
        if (arg[i].lvl == 0) return arg[i].id;
        if (W1572_Invalid(c[0].id) || arg[i].lvl < c[0].lvl) {
            c[0] = arg[i];
            n = 1;
        } else if (c[0].lvl == arg[i].lvl) {
            c[n++] = arg[i];
        }
    }
    if (n > 0) {
        u32 r;
        u64 d;
        r = D_003638d0 * 0x10dcd;
        D_003638d0 = r;
        d = func_00312db8((u64)(u32)(n - 1) + 0x100000000ULL, (u64)(u32)n);
        return c[(s32)func_00312db8((u64)r, d)].id;
    }
    return 0;
}
}  // namespace n001cd7a8

// 0x1cd948 (not in the layout): the C2 copy of the lock-on constructor, same body as 0x1cda88.
namespace n001cd948 {
static inline void QCOPY(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& s) {
        if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq operator-(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Normalize(Vq& d) {
    f32 len;
    asm volatile(
        "lqc2 $vf1, 0(%1)\n\t"
        "vmul.xyz $vf2, $vf1, $vf1\n\t"
        "vaddy.x $vf2, $vf2, $vf2y\n\t"
        "vaddz.x $vf2, $vf2, $vf2z\n\t"
        "vsqrt Q, $vf2x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8, $vi22\n\t"
        "vaddq.x $vf2, $vf0, Q\n\t"
        "mtc1 $8, %0\n\t"
        "vnop\n\t"
        "vdiv Q, $vf0w, $vf2x\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf1, $vf1, Q\n\t"
        "sqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(&d) : "$8", "memory");
    return len;
}
struct Lockon { u32 target; u32 pad4[3]; Vq aim; Vq tpos; Vq dir; u32 obj; u32 objId; u32 pad72[2]; Vq opos; u32 t96; u32 t100; };
static inline Vq operator*(const Vq& a, f32 s) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
s32 func_00190140(u32) asm("func_00190140");
Vq* YS__OBJ__get_pos(u8*) asm("YS__OBJ__get_pos");
void YS__TARGET__make_collision(u32, Vq*) asm("YS__TARGET__make_collision");
Vq YS__OBJ__get_dir(u32) asm("YS__OBJ__get_dir");
void func_001cd948(Lockon* l, u32 obj, u32 tgt) asm("func_001cd948");
void func_001cd948(Lockon* l, u32 obj, u32 tgt) {
    u32* aim = (u32*)&l->aim;
    Vq* opos = &l->opos;
    l->target = func_00190140(tgt) ? tgt : 0;
    aim[3] = 0;
    l->obj = obj;
    l->objId = *(u32*)(obj + 2800);
    QCOPY(opos, YS__OBJ__get_pos((u8*)obj));                          
    l->t96 = 0;
    l->t100 = 0;
    Vq v;
    if (l->target) {
        YS__TARGET__make_collision(l->target, (Vq*)aim);
        v = l->tpos - *opos;
        v.y = 0;
        Normalize(v);
        l->dir = v;
    } else {
        l->dir = YS__OBJ__get_dir(l->obj);
    }
}
}  // namespace n001cd948

// ---- 0x1cda88
namespace n001cda88 {
static inline void QCOPY(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& s) {
        if (this != &s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&s) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq operator-(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 Normalize(Vq& d) {
    f32 len;
    asm volatile(
        "lqc2 $vf1, 0(%1)\n\t"
        "vmul.xyz $vf2, $vf1, $vf1\n\t"
        "vaddy.x $vf2, $vf2, $vf2y\n\t"
        "vaddz.x $vf2, $vf2, $vf2z\n\t"
        "vsqrt Q, $vf2x\n\t"
        "vwaitq\n\t"
        "cfc2.ni $8, $vi22\n\t"
        "vaddq.x $vf2, $vf0, Q\n\t"
        "mtc1 $8, %0\n\t"
        "vnop\n\t"
        "vdiv Q, $vf0w, $vf2x\n\t"
        "vwaitq\n\t"
        "vmulq.xyz $vf1, $vf1, Q\n\t"
        "sqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(&d) : "$8", "memory");
    return len;
}
struct Lockon { u32 target; u32 pad4[3]; Vq aim; Vq tpos; Vq dir; u32 obj; u32 objId; u32 pad72[2]; Vq opos; u32 t96; u32 t100; };
static inline Vq operator*(const Vq& a, f32 s) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
s32 func_00190140(u32) asm("func_00190140");
Vq* YS__OBJ__get_pos(u8*) asm("YS__OBJ__get_pos");
void YS__TARGET__make_collision(u32, Vq*) asm("YS__TARGET__make_collision");
Vq YS__OBJ__get_dir(u32) asm("YS__OBJ__get_dir");
void YS__CHOOSE_ATTACK__CHOOSE_ATTACK(Lockon* l, u32 obj, u32 tgt) asm("YS__CHOOSE_ATTACK__CHOOSE_ATTACK");
void YS__CHOOSE_ATTACK__CHOOSE_ATTACK(Lockon* l, u32 obj, u32 tgt) {
    u32* aim = (u32*)&l->aim;
    Vq* opos = &l->opos;
    l->target = func_00190140(tgt) ? tgt : 0;
    aim[3] = 0;
    l->obj = obj;
    l->objId = *(u32*)(obj + 2800);
    QCOPY(opos, YS__OBJ__get_pos((u8*)obj));                          
    l->t96 = 0;
    l->t100 = 0;
    Vq v;
    if (l->target) {
        YS__TARGET__make_collision(l->target, (Vq*)aim);
        v = l->tpos - *opos;
        v.y = 0;
        Normalize(v);
        l->dir = v;
    } else {
        l->dir = YS__OBJ__get_dir(l->obj);
    }
}
}  // namespace n001cda88

// ---- 0x1cdbc8
namespace n001cdbc8 {
struct W1980V81 {
    f32 x, y, z, w;
    W1980V81() {}
    W1980V81& operator=(const W1980V81& o) {
        if (this != &o) {
            asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        }
        return *this;
    }
    W1980V81 operator-(const W1980V81& b) const {
        W1980V81 r;
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
    f32 dot(const W1980V81& b) const {
        f32 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0\n\t.set reorder"
                 : "=f"(r) : "r"(this), "r"(&b) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct W1980Ent81 { u8 a; u8 kind; u8 pad[66]; };
struct W1980List81 { s32 count; W1980Ent81 e[1]; };
struct W1980Tgt81 { f32 f0; f32 h; u8 pad[8]; W1980V81 pos; };
struct W1980Bits81 {
    u32 w[1];
    void set(u32 i) { u32* q = &w[i >> 5]; *q |= 1 << (i & 31); }
    void set2(s32 i) { w[(u32)i >> 5] |= 1 << (i & 31); }
};
struct W1980Self81 { u8 pad[0x30]; W1980V81 dir; void* ctx; W1980List81* list; u8 pad2[8]; W1980V81 pos; W1980Bits81 bits; };
s32 func_001a0920(W1980Ent81*, void*) asm("func_001a0920");
s32 func_001a0800(W1980Ent81*, void*, W1980Tgt81*, f32, f32, f32) asm("func_001a0800");
void func_001cdbc8(W1980Self81* self, W1980Tgt81* t, s32 kind) asm("func_001cdbc8");
void func_001cdbc8(W1980Self81* self, W1980Tgt81* t, s32 kind) {
    W1980V81 d;
    d = t->pos - self->pos;
    f32 dy = d.y;
    d.y = 0;
    f32 h = d.normalize() - t->h;
    if (h < 0.0f) h = 0.0f;
    f32 c = d.dot(self->dir) < 1.0f ? d.dot(self->dir) : 1.0f;
    s32 i;
    for (i = 0; i < self->list->count; i++) {
        if (self->list->e[i].kind == kind && func_001a0920(&self->list->e[i], self->ctx)) {
            if (func_001a0800(&self->list->e[i], self->ctx, t, h, dy, c)) {
                self->bits.set(i);
            }
        }
    }
}
}  // namespace n001cdbc8

// ---- 0x1cddb8
namespace n001cddb8 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct B32 { f32 a, y, c; u32 d; V4 pos; };
struct It { u8* cur; u8 pad[28]; };
void func_00190128(It*) asm("func_00190128");
u8* YS__TARGET__each(It*, u8*) asm("YS__TARGET__each");
void func_001cdbc8(u32, B32*, s32) asm("func_001cdbc8");
void YS__COLLISION__set(B32*, u8*, u8*) asm("YS__COLLISION__set");
void YS__CHOOSE_ATTACK__check_enemy(u32 a) asm("YS__CHOOSE_ATTACK__check_enemy");
void YS__CHOOSE_ATTACK__check_enemy(u32 a) {
    It it;
    func_00190128(&it);
    B32 b;
    b.d = 0;
    u8* o = 0;
    while ((o = YS__TARGET__each(&it, o)) != 0) {
        if (*(u32*)(it.cur + 1416) & 0x20000) {
            YS__COLLISION__set(&b, it.cur, o);
            func_001cdbc8(a, &b, 2);
        }
    }
}
}  // namespace n001cddb8

// ---- 0x1cde58
namespace n001cde58 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { QCOPY(this, &o); }
    QV& operator=(const QV& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
static inline QV ScaleQ(const QV& a, f32 k) {
    QV r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(&a), "f"(k) : "$8", "memory");
    return r;
}
struct CDE58Ent { s32 f0; u8 f4; u8 f5; u8 pad[62]; };
typedef CDE58Ent CDE58Tab;
struct CDE58Sub8 { s32 f0; s32 f4; s32 f8; };
struct CDE58Sub130 { u8 pad[0x2c]; f32 f2c; };
struct CDE58A {
    u8 pad0[0xc];
    CDE58Sub8* f0c;
    u8 pad10[0x120];
    CDE58Sub130* f130;
    u8 pad134[0x2c];
    s32 f160;
    u8 pad164[0x44c];
    f32 f5b0;
    u8 pad5b4[0x25c];
    s32 f810;
};
struct CDE58O {
    s32 f0;
    u8 pad4[0xc];
    u8 f10[0x20];
    QV v30;
    CDE58A* f40;
    CDE58Tab* f44;
    u8 pad48[0x18];
    u32 bits[4];
};
void YS__CHOOSE_ATTACK__check_enemy(CDE58O*) asm("YS__CHOOSE_ATTACK__check_enemy");
void func_001cdbc8(CDE58O*, void*, s32) asm("func_001cdbc8");
s32 func_001a0920(CDE58Ent*, CDE58A*) asm("func_001a0920");
s32 func_0019c090(CDE58A*) asm("func_0019c090");
QV func_001840c0(CDE58A*, QV) asm("func_001840c0");
s32 YS__OBJ__is_fall(CDE58A*, QV*) asm("YS__OBJ__is_fall");
u32 func_001d7f40(CDE58Tab*, s32) asm("func_001d7f40");
s32 func_001ce0a8(CDE58O*) asm("func_001ce0a8");
static inline __attribute__((always_inline)) bool cde58_chk(CDE58A* a) {
    bool r = false;
    if ((a->f0c->f8 & 2) || (a->f160 & 0x40)) r = true;
    return r;
}
static inline __attribute__((always_inline)) void cde58_put(u32* w, u32 i, s32 v) {
    u32* q = &w[i >> 5];
    u32 m = 1 << (i & 31);
    if (v) *q |= m;
}
static inline __attribute__((always_inline)) void cde58_set(u32* w, u32 i) {
    u32* q = &w[i >> 5];
    *q |= 1 << (i & 31);
}
static inline __attribute__((always_inline)) void cde58_scan(CDE58O* o) {
    CDE58Tab* t = o->f44;
    for (s32 i = 0; i < t->f0; i++, t = o->f44) {
        CDE58Ent* e = (CDE58Ent*)(i * 68 + (u32)t);
        if (e->f5 == 3) {
            cde58_put(o->bits, i, func_001a0920((CDE58Ent*)&e->f4, o->f40));
        }
    }
}
void func_001cde58(CDE58O* o) asm("func_001cde58");
void func_001cde58(CDE58O* o) {
    YS__CHOOSE_ATTACK__check_enemy(o);
    if (o->f0) func_001cdbc8(o, o->f10, 1);
    cde58_scan(o);
    QV v;
    v = ScaleQ(o->v30, o->f40->f5b0 + o->f40->f130->f2c);
    CDE58A* a = o->f40;
    bool hit = func_0019c090(a) || cde58_chk(a);
    bool ok = !hit;
    if (ok && o->f40->f810 == 0) {
        QV r = func_001840c0(o->f40, v);
        if (YS__OBJ__is_fall(o->f40, &r)) {
            cde58_set(o->bits, func_001d7f40(o->f44, 1));
        }
    }
    if (!func_001ce0a8(o)) {
        if (func_0019c090(o->f40)) cde58_set(o->bits, func_001d7f40(o->f44, 9));
        else cde58_set(o->bits, func_001d7f40(o->f44, 5));
        func_001ce0a8(o);
    }
}
#undef QCOPY
}  // namespace n001cde58

// ---- 0x1ce0a8
namespace n001ce0a8 {
struct E1ce0a8 { u8 a; u8 b; s8 link; u8 c; u8 pad[4]; u16 id; u8 rest[58]; };
struct T1ce0a8 { s32 n; E1ce0a8 e[1]; };
s32 func_001d7f40(T1ce0a8*, s32) asm("func_001d7f40");
static inline u32 Bit1ce0a8(u32* b, u32 i) { return b[i >> 5] & (1 << (i & 31)); }
#define TAB1ce0a8 (*(T1ce0a8**)(p + 68))
E1ce0a8* func_001ce0a8(u8* p) asm("func_001ce0a8");
E1ce0a8* func_001ce0a8(u8* p) {
    E1ce0a8* r = 0;
    for (s32 i = 0; i < TAB1ce0a8->n; i++) {
        if (Bit1ce0a8((u32*)(p + 96), i)) {
            if (TAB1ce0a8->e[i].link == TAB1ce0a8->e[i].a || TAB1ce0a8->e[i].id != *(u32*)(*(u8**)(p + 64) + 340)) return &TAB1ce0a8->e[i];
            if (!r && TAB1ce0a8->e[i].link >= 0) r = &TAB1ce0a8->e[func_001d7f40(TAB1ce0a8, TAB1ce0a8->e[i].link)];
        }
    }
    return r;
}
#undef TAB1ce0a8
}  // namespace n001ce0a8

// 4-char resource tags (.rodata 0x36e2c0)
extern "C" const char D_0036e2c0[8] = "plyr";
extern "C" const char D_0036e2c8[8] = "fmab";
extern "C" const char D_0036e2d0[8] = "prty";
extern "C" const char D_0036e2d8[8] = "magi";
extern "C" const char D_0036e2e0[8] = "sstm";

// ---- 0x1ce1a0
namespace n001ce1a0 {
extern u32 D_00352134 asm("D_00352134");
extern u32 D_00352130 asm("D_00352130");
extern u32 D_01d5b9d0 asm("D_01d5b9d0");
extern u32 D_01d5b9d4 asm("D_01d5b9d4");
extern u32 D_01d5b9d8 asm("D_01d5b9d8");
extern u32 D_01d5b9dc asm("D_01d5b9dc");
extern char D_0036e2c0[] asm("D_0036e2c0");
extern char D_0036e2c8[] asm("D_0036e2c8");
extern char D_0036e2d0[] asm("D_0036e2d0");
extern char D_0036e2d8[] asm("D_0036e2d8");
extern char D_0036e2e0[] asm("D_0036e2e0");
u32 func_001ce248(u32, const char*) asm("func_001ce248");
u32 func_001ce2a0(u32, u32, u32) asm("func_001ce2a0");
void YS__PREF__Init(u32 a) asm("YS__PREF__Init");
void YS__PREF__Init(u32 a) {
    D_00352134 = a;
    D_01d5b9d0 = func_001ce248(2, D_0036e2c0);
    D_01d5b9d4 = func_001ce248(2, D_0036e2c8);
    D_01d5b9d8 = func_001ce248(2, D_0036e2d0);
    D_01d5b9dc = func_001ce248(2, D_0036e2d8);
    D_00352130 = func_001ce2a0(func_001ce248(2, D_0036e2e0), 0, 0);
}
}  // namespace n001ce1a0

// ---- 0x1ce248
namespace n001ce248 {
struct W2365_Res { u32 f0; u32 f4; u32 data; };
extern u32 D_00352134 asm("D_00352134");
W2365_Res* func_00168b88(u32, s32, s32, s32) asm("func_00168b88");
static inline __attribute__((always_inline)) W2365_Res* W2365_Find(u32 h, s32 kind, s32 tag)
{
    return func_00168b88(h, kind, tag, 0);
}
u32 func_001ce248(s32 kind, const s8* p) asm("func_001ce248");
u32 func_001ce248(s32 kind, const s8* p) {
    return W2365_Find(D_00352134, kind, p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24))->data;
}
}  // namespace n001ce248

// ---- 0x1ce2a0
namespace n001ce2a0 {
u32 wtarget_001ce2a0(u32 a0, u32 a1, u32 a2, u32) asm("_Z16wtarget_001ce2a0jjjj");
u32 wtarget_001ce2a0(u32 a0, u32 a1, u32 a2, u32) {
    s32* t = (s32*)a0;
    if (!((s32)a1 < t[0] && t[a1 + 1] != 0)) a1 = a2;
    s32 off = t[a1 + 1];
    if (off == 0) return 0;
    return a0 + off;
}
}  // namespace n001ce2a0

// ---- 0x1ce2d8
namespace n001ce2d8 {
u32 func_001ce2a0(u32, u32, u32, u32) asm("_Z13func_001ce2a0jjjj");
extern u8 D_01d60000 asm("D_01d60000");
u32 func_001ce2d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001ce2d8jjjj");
u32 func_001ce2d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001ce2a0(((u32)(*(u32*)((u32)((u32)&D_01d60000) - 17968u))), a0, 0x00000001u, a3);
}
}  // namespace n001ce2d8

// ---- 0x1ce300
namespace n001ce300 {
u32 func_001ce2a0(u32, u32, u32, u32) asm("_Z13func_001ce2a0jjjj");
extern u8 D_01d60000 asm("D_01d60000");
u32 func_001ce300(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001ce300jjjj");
u32 func_001ce300(u32 a0, u32 a1, u32 a2, u32 a3) {                           
    return func_001ce2a0(((u32)(*(u32*)((u32)((u32)&D_01d60000) - 17964u))), ((u32)(a0) - 1u), 0x00000000u, a3);
}
}  // namespace n001ce300

// ---- 0x1ce328
namespace n001ce328 {
u32 func_001ce2a0(u32, u32, u32, u32) asm("_Z13func_001ce2a0jjjj");
extern u8 D_01d60000 asm("D_01d60000");
u32 func_001ce328(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001ce328jjjj");
u32 func_001ce328(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001ce2a0(((u32)(*(u32*)((u32)((u32)&D_01d60000) - 17960u))), a0, 0x00000001u, a3);
}
}  // namespace n001ce328

// ---- 0x1ce350
namespace n001ce350 {
u32 func_001ce2a0(u32, u32, u32, u32) asm("_Z13func_001ce2a0jjjj");
extern u8 D_01d60000 asm("D_01d60000");
u32 func_001ce350(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001ce350jjjj");
u32 func_001ce350(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001ce2a0(((u32)(*(u32*)((u32)((u32)&D_01d60000) - 17956u))), a0, 0x00000000u, a3);
}
}  // namespace n001ce350

// ---- 0x1ce378
namespace n001ce378 {
void func_001980d0(u8*, u32, u32) asm("func_001980d0");
extern u8 D_00352140[] asm("D_00352140");
extern u8 D_01d5b9e0[] asm("D_01d5b9e0");
void func_001dba88(u32) asm("func_001dba88");
void func_001ce378(u8* p, u32 a, u32 b) asm("func_001ce378");
void func_001ce378(u8* p, u32 a, u32 b) {
    func_001980d0(p, b, 4);
    *(u32*)(p + 2548) = a;
    *(void**)p = D_00352140;
    func_001dba88(a);
    *(u32*)(p + 1416) |= 0x800000;
    *(void**)(p + 2552) = D_01d5b9e0;
}
}  // namespace n001ce378

// ---- 0x1ce3e8
namespace n001ce3e8 {
void func_001980d0(void*, u32, u32) asm("func_001980d0");
void func_001dba88(void*) asm("func_001dba88");
extern u8 D_00352140[] asm("D_00352140");
extern u8 D_01d5b9e0[] asm("D_01d5b9e0");
void func_001ce3e8(u8* p, void* a, u32 b) asm("func_001ce3e8");
void func_001ce3e8(u8* p, void* a, u32 b) {
    func_001980d0(p, b, 4);
    *(void**)(p + 2548) = a;
    *(void**)p = D_00352140;
    func_001dba88(a);
    *(u32*)(p + 1416) |= 0x800000;
    *(void**)(p + 2552) = D_01d5b9e0;
}
}  // namespace n001ce3e8

// ---- 0x1ce458
namespace n001ce458 {
void func_001dba98(void*) asm("func_001dba98");
void func_0016b5b8(void*) asm("func_0016b5b8");
void func_001ce458(u8* p) asm("func_001ce458");
void func_001ce458(u8* p) {
    func_001dba98(*(void**)(p + 2548));
    func_0016b5b8(p);
}
}  // namespace n001ce458

// ---- 0x1ce488
namespace n001ce488 {
s32 func_001db9a8(void*, s32, s32) asm("func_001db9a8");
void* func_001050d8(u32) asm("func_001050d8");
void func_001ce3e8(void*, s32, void*, void*, f32) asm("func_001ce3e8");
void* func_001ce488(void* a0, void* a1, f32 f) asm("func_001ce488");
void* func_001ce488(void* a0, void* a1, f32 f) {
    s32 h = func_001db9a8(a0, 0, 1000);
    void* o = func_001050d8(2560);
    func_001ce3e8(o, h, a0, a1, f);
    return o;
}
}  // namespace n001ce488

// ---- 0x1ce508
namespace n001ce508 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct VB18 {
    f32 x, y, z, w;
    VB18& operator=(const VB18& s) { if (this != &s) QCOPY(this, &s); return *this; }
    VB18 operator-(const Vec4& b) const
    {
        VB18 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                     : : "r"(this), "r"(&b), "r"(&r) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct It18 { u8 d[80]; };
struct Pt18 { u8 pad[64]; VB18 rel; u32 pad2; void* fn; u8* owner; };
Vec4* YS__OBJ__get_pos(u8*) asm("YS__OBJ__get_pos");
void func_001c2858(It18*, Vec4*, u32, u32) asm("func_001c2858");
s32 func_001c28f8(It18*, VB18*, s32) asm("func_001c28f8");
Pt18* func_001db888(u8*, s32, void*) asm("func_001db888");
void func_001dbc58(Pt18*, u8*, VB18*, u32) asm("func_001dbc58");
void func_001ce618() asm("func_001ce618");
void YS__CROWD_EVENT___OVR_appear(u8* p, u32 a1, u32 a2) asm("YS__CROWD_EVENT___OVR_appear");
void YS__CROWD_EVENT___OVR_appear(u8* p, u32 a1, u32 a2) {
    f32 life = 1.0f;
    It18 it;
    VB18 pos;
    func_001c2858(&it, YS__OBJ__get_pos(p), a1, a2);                          
    u8* pool = *(u8**)(*(u8**)(p + 2548) + 2548);
    while (func_001c28f8(&it, &pos, 1)) {
        Pt18* o = func_001db888(pool + 20, 96, __builtin_return_address(0));                      
        func_001dbc58(o, pool, &pos, *(u32*)(p + 2552));
        o->rel = pos - *YS__OBJ__get_pos(p);                          
        o->rel.w = life;
        o->owner = p;
        o->fn = (void*)func_001ce618;
    }
}
#undef QCOPY
}  // namespace n001ce508

// 0x1ce618 (not in the layout): particle callback, position = owner matrix * relative offset.
namespace n001ce618 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct M4 { V4 r[4]; } __attribute__((aligned(16)));
static inline void QCOPY(void* d, const void* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline void VAssign(V4* d, V4* s) {
    if (d != s) QCOPY(d, s);
}
static inline void ApplyM(V4* d, M4* m, V4* v) {
    asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(d), "r"(m), "r"(v) : "memory");
}
static inline void ApplyTo(V4* d, M4* m, V4* v) { V4 t; ApplyM(&t, m, v); VAssign(d, &t); }
struct Pt18 { V4 pos; u8 pad[48]; V4 rel; u32 pad2; void* fn; u8* owner; };
void func_001ce618(Pt18* o) asm("func_001ce618");
void func_001ce618(Pt18* o) {
    ApplyTo(&o->pos, (M4*)(o->owner + 64), &o->rel);
}
}  // namespace n001ce618

// ---- 0x1ce668
namespace n001ce668 {
struct T1ce { u32 a; u32 b; u32 c; };
struct F1ce { u32 a; u32 b; f32 c; };
extern T1ce D_01d5b9e0 asm("D_01d5b9e0");
extern F1ce D_01d5b9f0 asm("D_01d5b9f0");
void wtarget_001ce668(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001ce668jjjj");
void wtarget_001ce668(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_01d5b9e0.a = 0;
        D_01d5b9e0.b = 0;
        D_01d5b9e0.c = 0;
    }
    if (b == 0xffff && a == 1) {
        D_01d5b9f0.b = 0;
        D_01d5b9f0.c = 335.99997f;
        D_01d5b9f0.a = 0;
    }
}
}  // namespace n001ce668

// ---- 0x1ce6c8
namespace n001ce6c8 {
u32 func_001ce668(u32, u32, u32, u32) asm("_Z13func_001ce668jjjj");
u32 func_001ce6c8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_001ce6c8jjjj");
u32 func_001ce6c8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001ce668(0x00000001u, 0x0000ffffu, a2, a3);
}
}  // namespace n001ce6c8
