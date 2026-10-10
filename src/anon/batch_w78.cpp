#include "../common/types.h"
struct W78Vec {
    f32 x, y, z, w;
    W78Vec& operator=(const W78Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W78Mtx {
    W78Vec r[4];
    W78Mtx& operator=(const W78Mtx& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
};
static inline void vsub(W78Vec* d, const W78Vec* a, const W78Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline void vadd(W78Vec* d, const W78Vec* a, const W78Vec* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 vnormalize(W78Vec* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline f32 vlength(const W78Vec* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}

// ---- c1
extern "C" {
u32 func_002ff3fc(const u8*);  // strlen
u8* func_00100430(u8*, u64*);  // varint64_decode_c
u8* func_00100468(u8*, s64*);
u8* func_001004c0(u8, u32, u8*, u32*);
W78Vec* func_00133bb8(u32, s32, u32, u32);  // forward_sub24_to_133848
void func_0015cb78(void*, u32);
void func_00141c18(void*, u32, u32, u32, u32);
s32 func_00141ff0(void*, void*, void*, void*, s32);
struct W78VecC { f32 x,y,z,w; W78VecC(const W78VecC& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); } } __attribute__((aligned(16)));
void func_001539c0(void*, W78VecC);
void func_00147c78(u8*, u8*, f32);  // copy_bytes_232_to_12
u8* func_001058e8(void);
f32 func_0017ce10(f32);
u32 func_00155d58(u32, s32);  // table_word_indexed_by_3
void func_00138c10(u32, u32);
void func_00154408(u32, u32);
s32 func_001581d0(u32);
s32 func_002ba358(void);
void func_002ba390(void);
extern u8* D_0034880c;
extern f32 D_004f3588;
extern u32 D_0032b984;
extern u8 D_0032bae0[];

// Reads a CIE's augmentation data and returns its FDE pointer encoding.
s32 func_001009a0(u8* cie) {
    u64 utmp;
    s64 stmp;
    u32 dummy;
    u8* aug = cie + 9;
    u8* p;
    if (aug[0] != 'z') return 0;
    p = aug + func_002ff3fc(aug) + 1;
    p = func_00100430(p, &utmp);  // varint64_decode_c
    p = func_00100468(p, &stmp);
    p++;
    aug++;
    p = func_00100430(p, &utmp);  // varint64_decode_c
    while (1) {
        if (*aug == 'R') return *p;
        else if (*aug == 'P') p = func_001004c0(*p & 0x7f, 0, p + 1, &dummy);
        else if (*aug == 'L') p++;
        else return 0;
        aug++;
    }
}

void func_00134c00(W78Vec* v, u32 a) {
    W78Vec* d = func_00133bb8(a, 3, 0x01000101, 0x6c034005);  // forward_sub24_to_133848
    d[0] = v[0];
    d[1] = v[1];
    d[2] = v[2];
    W78Mtx* m = (W78Mtx*)func_00133bb8(a, 4, 0x01000101, 0x6c04400a);  // forward_sub24_to_133848
    *m = *(W78Mtx*)(v + 3);
}

struct W78Ent { u8 b; u8 pad[15]; };
struct W78Hit { u8 pad[12]; u8* tbl; };
void* func_00143860(void* self, W78VecC* v) {
    W78Vec a;
    s16 idx = -1;
    func_0015cb78(self, 0);
    if (D_0034880c) {
        func_00141c18(D_0034880c, 0, 0, 0, 0);
        if (func_00141ff0(D_0034880c, v, &a, &idx, 15) && (u16)idx != 0xffff)
            func_0015cb78(self, *(u8*)(((W78Hit*)D_0034880c)->tbl + ((u16)idx << 4)));
    }
    func_001539c0(self, *v);
    return self;
}

static inline u8* next(u8* o, u8* c) { if (!c) return *(u8**)(o + 240); return *(u8**)(c + 236); }
struct W78Flag { u32 f, g; };
struct W78Grp { u32 a; f32 f; u8* ptr[214]; s32 n; u8 pad[12]; };
struct W78World { u8 pad[3168]; W78Grp grp[4]; };

struct W78Pair { u32 a, b; u32 c[19]; };
struct W78Loc { u32 a, b; s32 i; u32 n; };

s32 func_00155758(s32 n, f32* a, s32* b, s32* c, s32* d, f32* ang) {
    if (n >= 60) return 1;
    *a = 0.0f;
    *ang = (f32)n * D_004f3588;
    *ang = func_0017ce10(*ang);
    if (n < 20) { *c = 64; *d = 100; *b = -50; }
    else if (n < 40) { *c = 64; *d = 50; *b = 0; }
    else { *c = 0; *d = 0; *b = 50; }
    return 0;
}
}

void wtarget_001575c0(u8* p) asm("_Z16wtarget_001575c0jjjj");
void wtarget_001575c0(u8* p) {
    u32 v = **(u32**)(*(u8**)(p + 52) + 1164);
    u8 c = p[15611];
    *(u32*)(p + 40) = v;
    *(u32*)(p + 36) = v;
    if (c == 0) p[15611] = 1;
    else func_00138c10((u32)(p + 6704), func_00155d58((u32)p, 0));
    func_00138c10((u32)(p + 7116), func_00155d58((u32)p, 1));
    func_00138c10((u32)(p + 8352), func_00155d58((u32)p, 2));
    func_00154408((u32)(p + 64), *(u32*)(p + 24));
    if (func_001581d0((u32)p) && func_002ba358()) func_002ba390();
}

// ---- c2
extern "C" {
u8* func_00102c80(void);
void func_00102670(u32, void*);  // to_1025f8
void func_001623b0(void);
void func_001619e8(void);
void func_001620a8(void);
u8* func_00102c18(s32, u32, void*);
void func_001024a8(void*);
void func_00161d48(void);
void func_00161c88(void);
void func_00161de0(void);
union W78Any { u8* p; f32 f; u32 u; };
extern W78Any D_0034c774;

struct W78Snd { u32 x0; f32 f4; u32 x8, x12; s32 mode; };
struct W78Task { u32 x0; f32 f4; f32 f8; f32 inv; s32 mode; u8 pad[28]; W78Any fn; };

static inline W78Vec operator-(const W78Vec& a, const W78Vec& b) { W78Vec r; vsub(&r, &a, &b); return r; }

void func_0016c8f8(void*, u32, u32, u32);
void func_001da458(void*, s32, u32, u32);  // stream_init_fields
void func_0016cd48(void*, u32*);
void func_0016cab8(void*);
extern u32 D_0034d8a4;
extern u32 D_0034d8a0;

s32 func_001a1de0(u32);
u8* func_00177860(void*);
void func_00187650(void*, s32, s32);
void func_00187520(void*, s32, u32, u8);
void func_00177c50(u8* o, s32 dmg, u32 c, u8 flag) {
    u32 st = *(u32*)(o + 1164);
    if (st && !func_001a1de0(st) && dmg < 0) {
        f32 r = (f32)(-dmg) / (f32)*(s32*)(*(u8**)(o + 1164) + 4);
        r *= *(f32*)(func_00177860(o) + 88);
        s32 n = (s32)r;
        if (n > 0) func_00187650(o, n, 0);
    }
    if (*(u32*)(o + 352) & 0x4000) flag = 0;
    func_00187520(o, dmg, c, flag);
}
}

s32 func_00190180(u32*);
void func_00190388(W78Vec*, u32*);  // vec4_from_arg
W78Vec* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_00184ad0(u8*, W78Vec*, f32);
extern "C" {
u32 u_call4_00187300(u8* o, u32* tgt, f32 f) asm("_Z16u_call4_00187300jjjj");
}

extern "C" {
static inline bool inRange(u8* p, f32 t) {
    bool r = false;
    if ((f32)*(u16*)p <= t) {
        if (*(u16*)(p + 2) != 0xffff) { if (t < (f32)*(u16*)(p + 2)) r = true; }
        else r = true;
    }
    return r;
}
typedef void (*W78Cb)(u8*, void*);
void func_00189f20(u8* tbl, W78Cb cb, void* arg, f32 t) {
    u8* p = tbl + 4;
    for (s32 i = 0; i < tbl[0]; i++) {
        bool hit = inRange(p, t);
        if (hit) cb(p, arg);
        p = p + p[5] * 2 + 6;
    }
}

struct W78Hdr { u32 a, b, c, d; };
struct W78St {
    W78Hdr h;
    W78Vec v1;
    u32 x20; u8 x24; f32 x28, x2c; u8 x30, x31;
    W78Vec v2;
    f32 x50;
};
void func_0018c480(W78St*, s32);
void func_0018c438(W78St*);
void func_0018c150(u8* p) {
    W78St* s = (W78St*)(p + 2624);
    *(W78St*)(p + 2720) = *s;
    func_0018c480(s, 0);
    func_0018c438(s);
    s32 m = *(s32*)(p + 2624);
    f32 f;
    switch (m) {
    case 4: f = *(f32*)(p + 2840); break;
    case 5: f = *(f32*)(p + 2852); break;
    default: f = *(f32*)(p + 2864); break;
    }
    *(f32*)(p + 2816) = f;
}
}

// ---- c3
extern "C" {
s32 func_00192440(u8*, s32);  // is_byte_lt25
u8* func_00192388(u8*);  // skip_control_codes
s32 func_00192b80(u8* n) {
    s32 depth = 1;
    if (n) {
        do {
            s32 prev = depth;
            if (func_00192440(n, 0)) {  // is_byte_lt25
                if (*n == 2) depth++;
                else if (*n == 0) return depth;
            }
            n = func_00192388(n);  // skip_control_codes
            if (prev != depth) {
                if (!n || (func_00192440(n, 0) && *n == 0)) depth--;
            }
        } while (n);
    }
    return depth;
}

struct W78Sub { u8 pad[24]; u8 kind; u8 p25; u16 id; u8 pad2[12]; };
struct W78Ent64 { u32 x0; W78Sub s; u8 pad[20]; };
struct W78List { u8 pad[4]; u16 n; u8 pad2[38]; W78Ent64 e[1]; };
s32 func_0016b7a0(u16);
u8* func_00199938(W78Ent64*, void*);
void func_001ad990(u8*, f32, f32, f32);
void func_0019b500(u8* o) {
    for (s32 i = 0; i < (*(W78List**)(o + 8))->n; i++) {
        W78Sub* s = (W78Sub*)((u8*)(i * 64) + (u32)*(W78List**)(o + 8) + 48);
        if (s->kind == 2 && !func_0016b7a0(s->id)) {
            u8* r = func_00199938(&(*(W78List**)(o + 8))->e[i], o);
            if (!(*(u32*)(r + 2040) & 0x10)) func_001ad990(r + 2092, 0.0f, 1.0f, 10.0f);
        }
    }
}

extern u8 D_0032bae0[];
void func_00198450(u8*);
u32 func_0016c008(u8*, s32);
u8* func_001a81f0(u8, u8, u32);
s32 func_001a8450(u8*);
void func_0017f488(u8*, s32, f32, f32);
void func_001a8678(u8*);
void func_001a86b8(u8* o) {
    func_00198450(o);
    u8* d = D_0032bae0;
    u32 v = func_0016c008(o, 1);
    u8* r = func_001a81f0(d[0], d[1], v);
    *(u8**)(o + 2552) = r;
    if (!r) {
        func_0017f488(o + 320, 151, 0.0f, 0.0f);
        return;
    }
    if (func_001a8450(r)) {
        func_0017f488(o + 320, 152, 0.0f, 0.0f);
        func_001a8678(o);
    } else {
        func_0017f488(o + 320, 151, 0.0f, 0.0f);
    }
}

s32 func_001a9780(u32);
u8* func_001a97b8(u32, s32);
u8* func_00168b38(u8*, s32, s32);  // entry_array_find_nth
u32 func_001a9458(u8* o, s32 a, s32 b) {
    u8* r = 0;
    if (func_001a9780(*(u32*)(o + 20))) {
        a *= 4;
        if (b >= 0) r = func_001a97b8(*(u32*)(o + 20), a + b);
        if (!r) {
            for (b = 3; b >= 0; b--) {
                r = func_001a97b8(*(u32*)(o + 20), a + b);
                if (r) break;
            }
        }
    } else {
        r = func_001a97b8(*(u32*)(o + 20), a);
    }
    u8* v;
    if (r && (v = func_00168b38(r, 9, 0)) != 0) return *(u32*)(v + 8);  // entry_array_find_nth
    return 0;
}

u8* func_00168b88(u32, s32, s32, s32);  // find_entry16_by_half_word
#define W78_FOURCC(c) ((c)[0] | ((c)[1] << 8) | ((c)[2] << 16) | ((c)[3] << 24))

struct W78Five { u32 w[5]; };
struct W78Slot { u16 x0; u16 cnt; u8 pad[8]; W78Five v; u8 lvl; u8 pad2[3]; };
u32 func_001b8e88(u32);
void func_001bc6a8(W78Slot*, u32, u32, W78Five*, u32);
W78Slot* func_001bd418(u8* o, s32 idx, u32 key, W78Five* src, u32 arg, s32 lvl) {
    u8* base = o + idx * 36;
    W78Slot* e = (W78Slot*)(base + 2244);
    if (e->cnt != 0 && lvl < e->lvl) return 0;
    u32 v = func_001b8e88(key);
    e->v = *src;
    func_001bc6a8(e, v, *(u32*)(o + 2528), (W78Five*)(base + 2256), arg);
    e->lvl = lvl;
    return e;
}
}

// ---- c4
extern "C" {
u8 func_001d6d00(s32);
void func_001c8d80(void*, s32);
u8 func_001c8c38(void);
u8* func_00102818(u32, s32, s32, void*, s32);
void func_001c83f8(void);
void func_001c86e8(void);
void func_001c98f0(f32);
void func_001c8710(void);
void func_001d9820(u8);
extern u8 D_00351eb8;
extern u8 D_0032bb30[];
extern s32 D_01d49968;
extern u32 D_00351214;
extern u8* D_00351e08;
void func_001c8300(u8* o, s32 id) {
    u8 v = func_001d6d00(id);
    func_001c8d80(&D_00351eb8, 0);
    D_0032bb30[13605] = v;
    D_01d49968 = 2;
    if (id != 89) {
        if (id == 306) D_0032bb30[13607] = 1;
    } else {
        D_0032bb30[13607] = func_001c8c38();
    }
    *(u32*)(o + 264) |= 0x104;
    u8* t = func_00102818(D_00351214, 0, 3, (void*)func_001c83f8, 0x2000);
    D_00351e08 = t;
    *(u8**)(t + 48) = (u8*)func_001c86e8;
    func_001c98f0(15.0f);
    func_001c8710();
    func_001d9820(v);
}

void func_00177dc8(u8*, u32, s32, u32, u32);
void func_00158a90(u8*);
extern u8 D_00352288[];
struct W78V4 {
    f32 x, y, z, w;
    void set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
};
struct W78Cam { W78V4 a; W78V4 b; f32 r0, r1, r2, r3; u32 z0, z1; };

void func_001d86a0(s32, s32);
void func_001d8820(s32, s32);
void func_0017f488(u8*, s32, f32, f32);
void func_0017f5e0(u8*, s32, s32, f32, f32);

s32 func_001bbb28(void);
u8* func_001d5cd0(void);
void func_001d7000(u8, u8*);
void func_001b7468(u32);
extern u8 D_0032e020[];
extern u32 D_0034e948;
void func_001d6f28(s32 n) {
    if (n <= 0) return;
    if (func_001bbb28()) return;
    u8* g = D_0032e020;
    s32 up = 0;
    *(s32*)(g + 4596) += n;
    while (1) {
        u8* e = func_001d5cd0();
        if (!e) { *(s32*)(g + 4596) = 0; break; }
        if (*(s32*)(g + 4596) < *(s32*)(e + 4)) break;
        up = 1;
        u8 lv = ++g[4150];
        *(s32*)(g + 4596) -= *(s32*)(e + 4);
        func_001d7000(lv, e);
    }
    if (up) func_001b7468(D_0034e948);
}

void func_002fdfc8(const char*, ...);  // device_vprintf_va
u8* func_001e3650(void*);  // ptr_add4
s32* func_001e3660(u8*, s32);
void func_001e5220(u32, s32);
extern char D_0036e978[];
extern char D_0036ed60[];
extern char D_0036e998[];
extern char D_0036e9d0[];
extern char D_0036ec40[];
// "RyjAssertion failed: %s\n" / "   File %s, Line %u\n" (partMng.c), then break.
static inline void w78_assert(const char* e, const char* f, s32 l) {
    func_002fdfc8(D_0036e978, e);  // device_vprintf_va
    func_002fdfc8(D_0036e998, f, l);  // device_vprintf_va
    asm volatile("break");
}
}

// ---- c5
extern "C" {
struct W78Prm {
    u16 x0;
    u16 flags;
    u8 rgba[4];
    u64 z8;
    u8* mtx;
    u32 tex;
    u8 b24;
    u32 x28;
    u8 pad[16];
};
extern u8* D_01d9e6e4;
extern u8* D_01d9e6e8;
extern u32 D_01d9eaa4;
u32 func_0021d048(u8*, W78Prm*, u32);

extern u8* volatile D_01d9e6e8v asm("D_01d9e6e8");
void func_0021eb50(u8*, u8*);
static inline void w78_scale(u8* v, u32 s) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(v), "r"(s) : "memory");
}

void func_002f4000(W78Vec*);  // vu_store_w_splat
void func_002f3d08(W78Vec*, void*, W78Vec*);
void func_002f3f40(u8*, u8*, f32);  // vec_scale_by_f12
void func_002f3cd8(u8*, W78Vec*, u8*);
extern u8 D_01d9e730[];
extern u8 D_01d9e8c0[];
void func_00200700(u8* o, u32 a1, u8* a2) {
    W78Vec m[4];
    u8* p = o + (*(u32**)(a2 + 12))[1];
    func_002f4000(m);  // vu_store_w_splat
    f32* s = (f32*)(p + 160);
    m[3].x = s[0];
    m[3].y = s[1];
    m[3].z = s[2];
    func_002f3d08(m, D_01d9e730, m);
    func_002f3f40(D_01d9e6e8 + 80, D_01d9e6e8 + 16, s[4]);  // vec_scale_by_f12
    func_002f3f40(D_01d9e6e8 + 96, D_01d9e6e8 + 32, s[5]);  // vec_scale_by_f12
    func_002f3f40(D_01d9e6e8 + 112, D_01d9e6e8 + 48, s[6]);  // vec_scale_by_f12
    func_002f3cd8(D_01d9e6e8 + 128, m, D_01d9e6e8 + 64);
    func_002f3d08((W78Vec*)(D_01d9e6e8 + 80), D_01d9e8c0, (W78Vec*)(D_01d9e6e8 + 80));
}

void func_00228240(void);
u32 func_002282d8(void);  // limit_15000_or_25000
u8* func_00102c80(void);
u8* func_00102788(u32, u32, u32, void*);
void func_00227e30(void);
void func_002272b8(void);
void func_00228058(void);
void func_002280f8(void);
extern u8* D_0035de30;
extern u8* D_0035de34;
extern u8* D_0035de38;
extern u32 D_0035de3c;
extern u8 D_0035de27;
void func_00228150(u32 a) {
    func_00228240();
    u32 w = func_002282d8();  // limit_15000_or_25000
    D_0035de3c = *(u32*)(func_00102c80() + 4);
    if (!D_0035de30) D_0035de30 = func_00102818(D_0035de3c, a, w, (void*)func_00227e30, 0x2000);
    if (!D_0035de34) D_0035de34 = func_00102818(D_0035de3c, a, w, (void*)func_002272b8, 0x2000);
    if (!D_0035de38) {
        u8* v = func_00102788(D_0035de3c, a, w, (void*)func_00228058);
        D_0035de38 = v;
        *(u8**)(v + 48) = (u8*)func_002280f8;
        D_0035de27 = 0;
    }
}

struct W78Alloc;
typedef u8* (*W78AllocFn)(W78Alloc*, s32, s32);
struct W78Alloc { W78AllocFn* vt; };
struct W78Item { void* vt; u8 p4[8]; u8 m1[12]; u8 m2[384]; };
extern u8* D_00347f80;
extern u8 D_0035e028[];
extern u8 D_00347f98[];
extern u8 D_00347e60[];
void func_0031a838(u8*);
void func_00239700(u8*);
void func_00228788(u8*);
void func_002289f0(void) {
    W78Alloc* a = *(W78Alloc**)(D_00347f80 + 20);
    u8* v = a->vt[0](a, 1248, 0);
    *(u32*)(v + 12) = 0;
    *(u8**)v = D_0035e028;
    W78Item* it = (W78Item*)(v + 24);
    s32 i = 2;
    do {
        it->vt = D_00347f98;
        func_0031a838(it->m1);
        it->vt = D_00347e60;
        func_00239700(it->m2);
        it++;
    } while (--i != -1);
    func_00228788(v);
}
}

// ---- c6
extern "C" {
extern u8 D_0035e359;
extern char D_00371300[];
extern char D_00371320[];
u32 func_00232348(void);
void func_002fee78(char*, const char*, ...);
s32 func_002ff538(const char*, const char*, s32);
void func_002baa08(u32, u32, s32, s32);
// Plays the title voice lines when the event name matches.
s32 func_002325f0(u8* o) {
    char buf[64];
    s32 r = 0;
    if (D_0035e359 == 1) {
    func_002fee78(buf, D_00371300, func_00232348());
    if (!func_002ff538((char*)(o + 48), buf, 24)) {
        r = 1;
        func_002baa08(*(u32*)(o + 20), *(u32*)(o + 28), 16383, 0);
    }
    func_002fee78(buf, D_00371320, func_00232348());
    if (!func_002ff538((char*)(o + 48), buf, 24)) {
        r = 1;
        func_002baa08(*(u32*)(o + 20), *(u32*)(o + 28), 16383, 127);
    }
    }
    return r;
}

s32 func_002282f0(s16);
s32 func_00227ca8(void*);
s32 func_00225b00(s16);  // flag_query_by_index
u32 func_002bc238(s32);
void func_002bc358(u32, s32);
extern s32 D_0035e35c;
extern u32 D_0035db60[];
struct W78Snd2 { s16 x0, x2, slot, kind; u8 name[4]; s16 id; };
void func_00232c88(W78Snd2* o) {
    if (func_002282f0(o->id)) return;
    if (o->kind == 0) {
        s32 v = func_00227ca8(o->name);
        s32 r = v - 1000;
        if (v <= 1000) r = D_0035e35c * 1000 + v;
        if (func_00225b00(o->id)) return;
        D_0035db60[o->slot] = func_002bc238(r);
    } else {
        if (func_00225b00(o->id)) return;
        u32 h = D_0035db60[o->slot];
        func_002bc358(h, 240);
    }
}
}

void func_00106450(void*);
void func_00106420(void*);
void func_00242048(void*);
extern void* D_0035ec88;
extern void* D_0035ec8c;
extern void* D_0035ec90;
extern void* D_0035ec94;
extern void* D_0035ec98;
extern u32 D_0035ec9c;
extern void* D_0035eca0;
extern void* D_0035eca4;
void u_call0_00240000(void) asm("_Z16u_call0_00240000v");
void u_call0_00240000(void) {
    if (D_0035ec88) { func_00106450(D_0035ec88); D_0035ec88 = 0; }
    if (D_0035ec8c) { func_00106450(D_0035ec8c); D_0035ec8c = 0; }
    if (D_0035ec90) { func_00106450(D_0035ec90); D_0035ec90 = 0; }
    if (D_0035ec94) { func_00106420(D_0035ec94); D_0035ec94 = 0; }
    if (D_0035ec98) { func_00106420(D_0035ec98); D_0035ec98 = 0; }
    if (D_0035eca0) { func_00106450(D_0035eca0); D_0035eca0 = 0; }
    D_0035ec9c = 0;
    void* p = D_0035eca4;
    if (p) {
        func_00242048(p);
        func_00106420(p);
        D_0035eca4 = 0;
    }
}

extern "C" {
s32 func_00276c18(void);
u8* func_001d56c8(u8);
extern u32 D_0035edf4;
extern s32 D_003722ec;
extern s32 D_003722f0;
extern u8 D_003722e0[];
extern u8 D_003722e8[];
s32 func_0024e080(void) {
    if (func_00276c18()) return 1;
    s32 any = 0;
    s32 n;
    if (!D_0035edf4) n = D_003722ec;
    else n = D_003722f0;
    for (s32 i = 0; i < n; i++) {
        u8* e;
        if (!D_0035edf4) e = func_001d56c8(D_003722e0[i]);
        else e = func_001d56c8(D_003722e8[i]);
        if (*e >= 2) { any = 1; break; }
    }
    return any;
}

u32 func_00257770(void);
s32 func_00287bc0(void);
s32 func_0027af58(void);  // check_state16_then_loop
void func_0028dac8(u32, s16);
s32 func_0028be58(u32);
void func_0028bdb8(u32);
s32 func_0028acc8(u32);
s32 func_0028acb8(u32);
void func_0028aa40(u32);
extern u32 D_0035f04c;
extern u32 D_0035f01c;
struct W78E6 { s16 a, b, c; };
extern W78E6 D_00373e30[];
}

// ---- c7
extern "C" {
extern u8 D_0035f3a8;
u32 func_0023f948(void*, u32);
u32 func_0023f908(void*, u32);
void func_0023eea0(u32, u32, u32, u32, u32, u32);
void func_0023f0c8(u32, u32);
void func_0028d7f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1, u32 x, u32 y, u32 z) {
    if (!x) x = func_0023f948(&D_0035f3a8, a2);
    if (!y) y = func_0023f908(&D_0035f3a8, a3);
    func_0023eea0(a0, a1, x, y, t0, z);
    func_0023f0c8(a0, t1);
}

void func_00290060(u8*);
void func_001386e0(u32, u32, u32, u32, s32, s32);
void func_00259020(u32, u32, u32, u32, u32, u16*, s32, s32);
void func_0028ff00(u8*);
struct W78Mot { u32 obj; u32 x4; s16 a8; s16 pad; s16 a12; s16 pad2; u16 a16; };

s32 func_002a4990(s32);
s32 func_002a4430(void);
s32 func_002a43f0(void);
void func_002ac8e0(s32);
void func_002ab728(s32);
void func_002abac8(s32);
void func_002a3318(void);
extern u8* D_0035f5e4;
struct W78Slot8 { u8 a, b, on, done; u8 pad[4]; };
struct W78Tbl { u8 pad[4096]; W78Slot8 e[1]; };
void func_002a3aa8(void) {
    s32 id = func_002a4990(-1);
    if (func_002a4430()) {
        W78Slot8* e = (W78Slot8*)(id * 8 + (u32)D_0035f5e4 + 4096);
        if (e->on && !e->done) {
            func_002ac8e0(id);
            ((W78Slot8*)(id * 8 + (u32)D_0035f5e4 + 4096))->done = 1;
        }
    } else if (func_002a43f0()) {
        W78Slot8* e = (W78Slot8*)(id * 8 + (u32)D_0035f5e4 + 4096);
        if (e->on && !e->done) {
            func_002ab728(id);
            ((W78Slot8*)(id * 8 + (u32)D_0035f5e4 + 4096))->done = 1;
        }
    } else {
        W78Slot8* e = (W78Slot8*)(id * 8 + (u32)D_0035f5e4 + 4096);
        if (e->on && !e->done) {
            func_002abac8(id);
            ((W78Slot8*)(id * 8 + (u32)D_0035f5e4 + 4096))->done = 1;
        }
    }
    func_002a3318();
}

u8* func_002a9d68(s32);
extern u8* D_0035f610;
static inline u32 w78_bit(u32* bits, u32 i) { return bits[i >> 5] & (1 << (i & 31)); }

u8* func_001a82b0(u8*);
s32 func_002764b0(u8);
void func_002ab728(s32 id) {
    u32* bits = (u32*)(func_002a9d68(id) + 236);
    u8* e = 0;
    u32 i = 0;
    for (;; i++) {
        e = func_001a82b0(e);
        if (!e) break;
        if (e[4]) continue;
        if (*(u16*)(e + 8) == 0) continue;
        if (*(u16*)(e + 8) == 0x800) continue;
        if (func_002764b0(e[5]) != id) continue;
        u32 m = 1 << (i & 31);
        u32 w4 = (i >> 5) * 4;
        if (*(u32*)(D_0035f610 + w4 + 236) & m) {
            u32 w = bits[i >> 5];
            if (!(w & m)) bits[i >> 5] = w | m;
        }
    }
}

extern s32 D_0035f62c;
extern s32 D_0035f628;
void func_002ad110(void);
void func_002ad258(void);
void func_002ad390(void);
void func_002ad580(void);
void func_002ad6e8(void);
void func_002ad878(void);
void func_002ad9f8(void);
void func_002adbd0(void);
void func_002add90(void);
void func_002ae320(void);
void func_002adfd0(void);
s32 func_002ae0c0(s32);
void func_002acf48(void) {
    D_0035f62c = 0;
    D_0035f628 = 0;
    func_002ad110();
    func_002ad258();
    func_002ad390();
    func_002ad580();
    func_002ad6e8();
    func_002ad878();
    func_002ad9f8();
    func_002adbd0();
    func_002add90();
    func_002ae320();
    func_002adfd0();
    D_0035f628 += 15;
    for (s32 i = 0; i < 15; i++) {
        if (func_002ae0c0(i)) D_0035f62c++;
    }
}
}

// ---- c8
extern "C" {
u8* func_00294000(s32);
s32 func_002943e8(u8*);
extern s32 D_0035f628;
extern s32 D_0035f62c;
extern u8* D_0035f620;

u8* func_002b23e0(s32);  // list_entry_by_index_checked
u8* w78_9d68(void) asm("func_002a9d68");
s32 func_002b2380(s16, s16);
extern u8* D_0035f638;
s32 func_002b3c38(u32 mask) {
    s32 r = 1;
    u8* a = func_002b23e0(-1);  // list_entry_by_index_checked
    u8* b = w78_9d68();
    u8* t = D_0035f638;
    s32 k = (*(u32*)(t + 52) >> 10) & 2;
    u8* tk = (u8*)k + (u32)t;
    s32 v = func_002b2380(*(s16*)(tk + 28), *(s16*)(tk + 32));
    s8 x = *(s8*)(b + (a[2] * 48 + v) * 4 + 488);
    if ((mask & 0xc0004) && !(*(u32*)(D_0035f638 + 52) & 0x800)) r = x >= 0;
    return r;
}

u32 func_002bc988(u32);
s32 func_002bc9d8(u8*, u32);
void func_002bc9a8(u8*, s32, u32);  // find_entry12_set_field
s32 func_002bc978(u32);
void func_002bcda8(u8*, s32);
void func_002bd188(u8*, s32);
}

extern W78Vec D_01e2bd20;
extern W78Vec D_01e2bd30;
extern W78Vec D_01e2bd40;
void wtarget_002c5298(u32 a, u32 b) asm("_Z16wtarget_002c5298jjjj");

// ---- c9
extern "C" {
f32 func_002f8a18(f32);
f32 func_002f8870(f32);  // fabsf
struct W78VecC2 {
    f32 x, y, z, w;
    W78VecC2& operator=(const W78VecC2& o) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
W78VecC2* func_002d1d30(W78VecC2* out, u8* cam, W78VecC2* pos) {
    *out = *pos;
    vsub((W78Vec*)out, (W78Vec*)out, (W78Vec*)(cam + 208));
    f32 t = func_002f8a18(*(f32*)(cam + 112) * 0.5f * 0.01745329238474369f);
    t *= func_002f8870(out->z);  // fabsf
    out->z = 0.0f;
    out->x = out->x / (t * 4.0f / 3.0f);
    out->y = out->y / t;
    return out;
}

extern u32 D_00361f60;
extern u8 D_00362380;
extern u8 D_00362388;
void func_0017f540(u8*, s32, f32, f32);
u32 func_002d1260(void);
void func_001c0d38(u8*, u32, s32, s32);
void func_002e7568(u8*, s32, void*, f32);
u8* func_002d1878(u32);
void func_002e7340(u8*, u8*, s32, void*, f32, f32);

u8* func_001b9bc8(u8*);
s32 func_0019c768(u8*);
s32 func_0016a060(u8*);
void func_002cf280(u8*, s32, s32);
}
