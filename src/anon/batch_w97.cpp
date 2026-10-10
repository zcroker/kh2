#include "../common/types.h"

extern "C" {
// ---- shared VU0 helpers
struct Vq {
    f32 x, y, z, w;
    Vq& operator=(const Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
static inline Vq vsub(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline f32 vdot(const Vq& a, const Vq& b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
static inline Vq vsubn(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline Vq vadd(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline Vq vscale(const Vq& a, f32 s) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
static inline Vq vscalen(const Vq& a, f32 s) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "f"(s) : "$8", "memory");
    return r;
}
// Normalises xyz in place; returns the original length.
static inline f32 vnormalize(Vq* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline Vq vcross(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline Vq vcrossn(const Vq& a, const Vq& b) {
    Vq r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void vscalei(Vq* v, f32 s) {
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(v), "f"(s) : "$8", "memory");
}
static inline void vcopy(Vq* d, const Vq* s) {
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
static inline f32 vlen(const Vq& a) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&a) : "$8", "memory");
    return r;
}

// ---- 001043e8
void func_00167f38(s32);
extern char D_00369e30[];
void func_00168548(char*, s32, s32);
void func_00170888(u32);
void func_003058a0(s32);
void func_001688a0(void);
u8* func_00170b30(u32);  // alloc_align128
void* func_00106178(void*, u32);
extern void* D_0032babc;
extern void* D_0032bac0;
extern void* D_0032bac4;
extern void* D_0032bac8;
extern u8 D_0032bad0[];
extern u8 D_0032ba90[];
void func_01f18014(s32, void*);
void D_001043e8(u32 a) {
    func_00167f38(4);
    func_00168548(D_00369e30, 0, 0);
    func_00170888(a);
    func_003058a0(2);
    func_001688a0();
    func_00170888(a);
    D_0032babc = func_00106178(func_00170b30(0xb00000), 0xb00000);
    u8* p = func_00170b30(0x1e0000);  // alloc_align128
    D_0032bac0 = func_00106178(p, 0x40000);
    p += 0x40000;
    D_0032bac4 = func_00106178(p, 0x180000);
    p += 0x180000;
    D_0032bac8 = func_00106178(p, 0x20000);
    s32 i = 0;
    do {
        *(u8*)(i + (u32)D_0032bad0) = 0;
        i++;
        s32 c = i < 3;
        asm volatile("nop\n\tnop" : "+r"(c));
        if (!c) break;
    } while (1);
    func_01f18014(0, D_0032ba90);
}

// ---- 00104f58
struct Pos10 { s16 v[5]; };
struct Task104 { u32 f0; u32 f4; u8 f8; u32 f12; u32 f16; };
extern u8 D_003a7b00;
extern Pos10 D_003a7b08;
extern Pos10 D_0032baf0;
extern u32 D_0032b96c;
extern Task104* volatile D_0032bb20;
extern char D_00351ec8[];
void func_0013f050(u32);
void func_001ada38(u32);
void func_00167ea8(void);
void func_00104e98(void);
Task104* func_00102788(u32, u32, u32, void (*)(void));
void func_001c8d80(char*, s32);
void func_00104f58(const Pos10* pos, u32 id, u32 mode, u8 flag, u32 snd) {
    if (D_003a7b00) {
        func_0013f050(id | 0x80000000);
        D_003a7b08 = *pos;
        if (snd) func_001ada38(snd);
        return;
    }
    func_00167ea8();
    Task104* t = func_00102788(D_0032b96c, 0, 0x493e0, func_00104e98);
    D_0032bb20 = t;
    t->f4 = mode;
    D_0032bb20->f8 = flag;
    D_0032bb20->f12 = id;
    if (mode == 0) {
        D_0032bb20->f16 = snd;
        func_0013f050(id);
    } else {
        func_001ada38(snd);
        D_0032bb20->f16 = 0;
    }
    func_001c8d80(D_00351ec8, 2);
    D_0032baf0 = *pos;
}

// ---- 0010d038
Vq func_00190388(const void*);  // vec4_from_arg
const Vq* func_0016c028(u32);  // obj_get_attach_or_alt
f32 func_001142d0(u32);  // get_float_at_ptr108
f32 func_00114390(u32);
extern u32 D_00341708;
s32 func_0010d038(u8* o) {
    struct Lk { u32 on : 1; u32 rest : 31; };
    Lk* lock = *(Lk**)(o + 3168);
    if (lock && !lock->on) return 1;
    Vq d = vsubn(func_00190388(o + 2548), *func_0016c028((u32)o));  // vec4_from_arg
    f32 r = func_001142d0(*(u32*)(o + 2912));  // get_float_at_ptr108
    r = r * r;
    if (r < vdot(d, d)) return 1;
    r = func_00114390(*(u32*)(o + 2912));
    r = r * r;
    d = vsubn(func_00190388(o + 2548), *func_0016c028(D_00341708));  // vec4_from_arg
    if (vdot(d, d) < r) return 1;
    return 0;
}

// ---- 00154cd0
f32 func_0017ce10(f32);
void func_0013edd0(u8*, f32);
void func_0014b1e0(u8*, s16, s16);
void func_0014b208(u8*, u16, u16);
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
extern f32 D_0034a838;
void func_00154cd0(u8* p, s32 i, f32 t) {
    s32 w, h, x, y;
    if (t < D_0034a838) { w = 64; h = 64; x = -64; y = -64; }
    else { w = 0; h = 0; x = 0; y = 0; }
    
    f32 s = t * 3.1415925f + -1.5707963f;
    s = func_0017ce10(s);
    u_call4_00139d78(p + i*592 + 2576);
    func_0013edd0(p + i*592 + 2608, s);
    u_call4_00139d78(p + i*592 + 2576);
    func_0014b1e0(p + i*592 + 2896, x, y);
    func_0014b208(p + i*592 + 2896, w, h);
}

// ---- 00158300
struct Menu158;
typedef void (*Menu158Fn)(Menu158*);
struct Menu158 { Menu158Fn* vt; u8 pad[40]; u32 f44; u32 f48; u32 f52; };
void func_001581f8(Menu158*);
void func_001582a8(Menu158*);
s32 func_0013dd48(u32, s32);
void func_0013dd78(u32, s32);
void func_00158300(Menu158* m) {
    u32 in = m->f44 + m->f48;
    func_001581f8(m);
    if (func_0013dd48(in, 0)) {
        func_0013dd78(in, 0);
        m->vt[6](m);
        func_001582a8(m);
    }
    if (func_0013dd48(in, 1)) {
        func_0013dd78(in, 1);
        if (!m->f52) return;
        m->vt[7](m);
    }
    if (func_0013dd48(in, 2)) {
        func_0013dd78(in, 2);
        if (!m->f52) return;
        m->vt[8](m);
    }
    if (func_0013dd48(in, 3)) {
        func_0013dd78(in, 3);
        if (!m->f52) return;
        m->vt[9](m);
    }
    if (func_0013dd48(in, 4)) {
        func_0013dd78(in, 4);
        if (!m->f52) return;
        m->vt[10](m);
    }
}

// ---- 00169030
struct Area169 { u8 id; u8 pad[3]; u8 f4[1]; };
extern Area169 D_0032bae0;
extern u32 D_004f6280;
void func_00168808(u32);
s32 func_001688b8(void);
void func_00102448(u32, s32);
void func_00168fd8(u32);
void func_0016f7b0(void);
void func_00181ad0(Area169*);
void func_00170320(s32);
void func_001c10c8(void);
void func_00191758(void);
void func_001bb270(void);
void func_00198b88(void);
void func_001aebf0(Area169*);
void func_001947a0(void);
void func_001823d0(void*);
void func_001a89f0(void);
void func_00196b88(void);
void func_001a8498(void);
void func_001c8de0(void);
void func_001ada38(u32);
void func_00169030(u32 a) {
    Area169* ar = &D_0032bae0;
    if (ar->id != D_004f6280) {
        func_00168808(ar->id);
        while (func_001688b8()) func_00102448(a, 0);
        func_00168fd8(ar->id);
        D_004f6280 = ar->id;
    }
    func_0016f7b0();
    func_00181ad0(ar);
    while (func_001688b8()) func_00102448(a, 0);
    func_00170320(-200);
    func_001c10c8();
    func_00191758();
    func_001bb270();
    func_00198b88();
    func_001aebf0(ar);
    func_001947a0();
    func_001823d0(ar->f4);
    func_001a89f0();
    func_00196b88();
    func_001a8498();
    func_001c8de0();
    func_001ada38(11);
}

// ---- 001840c0
Vq func_001840c0(u8* o, Vq* v) {
    f32 len = vnormalize(v);
    const Vq& up = *(Vq*)(o + 1584);
    Vq c;
    c = vcrossn(up, *v);
    vnormalize(&c);
    *v = vcrossn(c, up);
    vnormalize(v);
    vscalei(v, len);
    Vq r;
    vcopy(&r, v);
    return r;
}

// ---- 00185330
extern u8 D_0034ed18[];
void func_001980d0(u8*, u32, s32, Vq*, f32);
void func_001a93b0(u8*, u32);
u32 func_00185920(u32, u32, s32);
u32 func_001708f8(u32, s32);
void func_0017ebe8(u8*, u32);
void func_0017fd30(u8*, u8*);
u32 func_001762c0(u8*, u32);
void func_001c0d38(u8*, u8*, u32, s32);
void func_00185330(u8* p, u32 a1, u8* owner, u32 a3, u32 a4, u32 a5) {
    Vq z;
    z.w = z.z = z.y = z.x = 0.0f;
    func_001980d0(p, a1, 12, &z, 3.1415927f);
    *(u32*)p = (u32)D_0034ed18;
    *(u32*)(p + 1416) |= 0x40;
    *(u32*)(p + 264) |= 2;
    *(u32*)(p + 944) = 1;
    *(u8**)(p + 2548) = owner;
    *(u32*)(p + 2552) = 0;
    *(u32*)(p + 2556) = a4;
    *(u32*)(p + 2560) = a5;
    func_001a93b0(p + 1952, a5);
    u32 v = func_00185920(a3, a4, 0);
    if (v) {
        func_0017ebe8(p + 320, func_001708f8(v, -1));
        func_0017fd30(owner + 320, p + 320);
        func_001c0d38(p, owner, func_001762c0(owner, a4), 0);
    }
    *(u32*)(p + 268) |= 0x700;
}

// ---- 0018a550
struct Shape18a { s32 type; };
u8 func_0018a250(Shape18a*, Shape18a*);
u8 func_0018a318(Shape18a*, Shape18a*);
u8 func_0018a420(Shape18a*, Shape18a*);
u8 func_0018a4d8(Shape18a*, Shape18a*);
s32 func_0018a550(Shape18a* a, Shape18a* b) {  // state_dispatch_0_1_3
    switch (a->type) {
    case 0:
        switch (b->type) {
        case 0: case 3: return func_0018a250(a, b);
        case 1: return func_0018a318(a, b);
        }
        break;
    case 1:
        switch (b->type) {
        case 0: case 3: return func_0018a318(b, a);
        case 1: return func_0018a420(a, b);
        }
        break;
    case 3:
        switch (b->type) {
        case 0: return func_0018a250(a, b);
        case 1: return func_0018a318(a, b);
        case 3: return func_0018a4d8(a, b);
        }
        break;
    }
    return 0;
}

// ---- 0019afd8
struct Unit19b { u8 pad[72]; u16 f0 : 3; u16 big : 1; u16 rest : 12; bool isBig() { return big; } };
extern u32 D_0034e948;
const Vq* func_0016c028(u32);  // obj_get_attach_or_alt
Unit19b* func_0016e920(u32);
Vq func_001a78c0(const Vq*, u32, f32, f32, f32, f32);
Vq func_001a7888(const Vq*, u32, f32, f32);
Vq func_0019afd8(u32 u) {
    Vq r;
    r = *func_0016c028(D_0034e948);  // obj_get_attach_or_alt
    r.y += -200.0f;
    if (func_0016e920(u)->isBig()) {
        r = func_001a78c0(&r, 0x10002, 150.0f, 450.0f, -100.0f, 100.0f);
    } else {
        r = func_001a7888(&r, 0x10001, 150.0f, 450.0f);
    }
    return r;
}

// ---- 001aca98
extern u8 D_00350bb0[];
extern u8 D_0034e8a8[];
extern u8 D_00350a38[][3];
void func_001ac378(u8*, u32, u32, u32, s32, u32, u32);
void func_002395b8(u8*);
void func_001abd90(u8*);
void func_001ac028(u8*);
void func_00239700(u8*);
u32 func_001ab810(void);  // get_global_1c7cec0
u32 func_001ab800(void);
void func_00239988(u8*, u32, u32);
void func_00239bf8(u8*, u8);
void func_001aa668(u8*, u8*);
void func_001aca98(u8* p, u32 a1, u32 a2, u32 a3, s32 a4, u32 a5, u32 a6, u32 kind) {
    func_001ac378(p, a1, a2, a3, a4, a5, a6);
    *(u32*)p = (u32)D_00350bb0;
    func_002395b8(p + 132);
    *(u32*)(p + 476) = kind;
    *(u32*)(p + 132) = (u32)D_0034e8a8;
    func_001abd90(p + 480);
    *(u32*)(p + 1192) = 0;
    func_001ac028(p + 1196);
    {
        u8* e = p + 1544;
        s32 i = 3;
        do { func_00239700(e); i--; e += 344; } while (i != -1);
    }
    *(u32*)(p + 2920) = 0;
    {
        u32 x = func_001ab810();  // get_global_1c7cec0
        func_00239988(p + 132, x, func_001ab800());
    }
    func_00239bf8(p + 132, D_00350a38[*(u32*)(p + 476)][0]);
    for (s32 i = 0; i < 4; i++) {
        u32 x = func_001ab810();  // get_global_1c7cec0
        func_00239988(p + 1544 + i * 344, x, func_001ab800());
    }
    func_001aa668(p + 12, p);
}

// ---- 001bb4f0
struct Info1bb { u8 pad0[4]; u16 flags; u8 pad6[7]; u8 snd; u8 pad14[6]; u32 f20; };
struct Obj1bb { u8 pad0[8]; Info1bb* info; u8 pad12[92]; u32 f104; u32 f108; u8 pad112[616]; u32 f728; u32 f732; u32 f736; u8 pad740[12]; u32 f752; };
void func_001c0890(u8);
s32 func_001d83c0(s32);
void func_001d4fd0(u32*);
void func_001d4ff0(u32*);
void func_001bbe18(u32);
void func_001bb890(void);
void func_001bb630(u32, u32);
u32 func_00198d00(u32, s32);
void func_001d5518(u32*, u8*, u32);
void func_001bc0d0(Obj1bb*);
void wtarget_001bb4f0(Obj1bb* o, u32 id, u32 arg, u32) asm("_Z16wtarget_001bb4f0jjjj");
void wtarget_001bb4f0(Obj1bb* o, u32 id, u32 arg, u32) {
    u8 snd = o->info->snd;
    if (snd) func_001c0890(snd);
    u32* q = (u32*)((u8*)o + 740);
    if (o->f752 & 4) {
        if (func_001d83c0(0) > 0) func_001d4fd0(q);
        func_001d4ff0(q);
    }
    func_001bbe18(o->info->f20);
    func_001bb890();
    u32* m = &o->f104;
    if (m[1]) {
        u32 v = func_00198d00(id, -1);
        if (id == 16 || id == 156 || (v && !(o->info->flags & 0x40))) {
            func_001d5518(m, (u8*)o + 12, 0);
            o->f728 = 2;
        } else {
            func_001d5518(m, (u8*)o + 12, v);
            func_001bc0d0(o);
        }
        o->f732 = id;
        o->f736 = arg;
    } else {
        func_001bb630(id, arg);
    }
}

// ---- 001bee78
s32 func_001b6070(u8*);
void func_001bc778(u8*);
u32 func_001a8bd0(s32);
u32 func_001a8c10(u32, s32);
u32 func_0017e668(u32);
s32 func_0019ba60(u32);
void func_00190878(u8*, u32, s32);
u32 func_001b7800(u32);
void func_001bc780(u8*, u32, u8*, s32);
s32 func_0017e358(u32);
void func_001bee78(u8* p) {
    u8* list = p + 964;
    s32 flag = func_001b6070(p);
    func_001bc778(list);
    u32 grp = func_001a8bd0(-1);
    for (s32 i = 1; i < 3; i++) {
        u32 m = func_001a8c10(grp, i);
        if (!m) continue;
        u32 c = func_0017e668(m);
        if (!func_0019ba60(c)) continue;
        s32 n = *(s32*)(list + 8);
        u8* e = p + n * 20 + 2664;
        func_00190878(e, c, 0);
        func_001bc780(list, func_001b7800(m), e, 1);
        if (flag && func_0017e358(c)) continue;
        list[n * 12 + 17] = 5;
    }
}

// ---- 001c99b0
f32 func_001bbfd0(s32);
u32 func_0017df58(s32);
s32 func_0019ba60(u32);
u32 func_0016a070(u32);
s32 func_001c9958(s32, u32);  // state_pair_check
s32 func_0017e358(u32);
static inline bool tooFar(s32 mode) { return 1.0f < func_001bbfd0(mode); }
s32 func_001c99b0(s32 mode) {
    s32 cnt = 0;
    s32 res = 0;
    if (tooFar(mode)) return 0;
    if (mode == 3) return 0;
    for (s32 i = 0; i < 2; i++) {
        u32 m = func_0017df58(i);
        u32 c;
        if (func_0019ba60(m)) c = func_0016a070(m);
        else c = 0;
        if (!func_001c9958(mode, c)) continue;
        if (!c) { res = 2; break; }
        cnt++;
        if (!func_0017e358(m)) res = 1;
    }
    return cnt ? res : 2;
}

// ---- 001d4180
struct Ent1d4 { u8 id; u8 pad[63]; };
struct Mgr1d4 { u32 f0; s32 count; Ent1d4 ent[1]; };
extern Mgr1d4* D_01d5ba28;
s32 func_00170cd0(void);
s32 func_001d4808(Ent1d4*);  // is_halfword42_zero
s32 func_001d3c78(Ent1d4*);
s32 func_001d3de0(Ent1d4*);
void func_00170320(s32);
void func_001d3c18(Ent1d4*);
void func_00170888(u32);
void func_001d4180(void) {
    u32 mask = 0;
    s32 n = 0;
    s32 any = 0;
    u8 idx[16];
    if (func_00170cd0()) return;
    s32 i;
    for (i = 0; i < D_01d5ba28->count; i++) {
        Ent1d4* e = &D_01d5ba28->ent[i];
        if (mask & (1 << e->id)) continue;
        if (func_001d4808(e)) continue;
        if (!func_001d3c78(e)) continue;
        mask |= 1 << e->id;
        idx[n++] = i;
        if (!func_001d3de0(e)) any = 1;
    }
    if (!any) return;
    func_00170320(5000);
    for (i = 0; i < n; i++) func_001d3c18(&D_01d5ba28->ent[idx[i]]);
    func_00170888(0);
}

// ---- 00226bd0
extern u8 D_0035de55;
extern u8 D_0035de0c;
void func_0015cde0(u8);
s32 func_0022d7d8(void);
u32 func_0014abb8(void);  // get_data_359840
u32 func_0014abc8(void);  // get_data_359950
void func_0014aa80(u32, s32, s32);
s32 func_001069a8(void);
void func_001618f0(void);
void func_001623b0(void);
void func_002bbe80(void);
s32 func_0022bd90(void);
void func_002bbf18(void);
void func_00224b08(u32);
s32 func_0022f5e8(void);
void func_00102448(u32, s32);
s32 func_001a84f0(void);  // compare_two_globals
u32 func_001a8510(void);  // mod8_of_difference
void func_001382b8(u32);
void func_001978f0(f32);
void wtarget_00226bd0(u32 a0, u32, u32, u32) asm("_Z16wtarget_00226bd0jjjj");
void wtarget_00226bd0(u32 a0, u32, u32, u32) {
    if (D_0035de55 == 1) func_0015cde0(D_0035de0c);
    if (func_0022d7d8()) {
        func_0014aa80(func_0014abb8(), 15, 0);
        func_0014aa80(func_0014abc8(), 15, 0);
    }
    if (func_001069a8() == 1) {
        func_001618f0();
        func_001623b0();
    }
    func_002bbe80();
    if (!func_0022bd90()) func_002bbf18();
    func_00224b08(a0);
    if (func_0022f5e8()) func_00102448(a0, 1);
    if (!func_001a84f0()) {  // compare_two_globals
        func_001382b8(func_001a8510());
        func_00102448(a0, 0);
    }
    func_001978f0(0.0f);
}

// ---- 002309c8
union FP230 { f32* p; f32 f; };
struct Obj230 { u32 f0; u32 owner; FP230 x; FP230 y; FP230 z; };
s32 func_001ba028(u32);  // list_contains_ptr
s32 func_0014f0e0(f32*);
void func_0016ace0(u32, f32*);
void func_00106420(f32*);
void func_001024a8(Obj230*);
void func_002309c8(Obj230* o) {
    u32 owner = o->owner;
    if (!func_001ba028(owner)) return;
    f32 v[4];
    f32* px = o->x.p;
    v[3] = 1.0f;
    f32* pz = o->z.p;
    f32* py = o->y.p;
    s32 bx = func_0014f0e0(px);
    s32 by = func_0014f0e0(py);
    s32 bz = func_0014f0e0(pz);
    if (!bx && !by && !bz) {
        v[0] = *px;
        v[1] = *py;
        v[2] = *pz;
        func_0016ace0(owner, v);
        func_00106420(px);
        func_00106420(py);
        func_00106420(pz);
        o->x.p = 0;
        o->y.p = 0;
        o->z.p = 0;
        func_001024a8(o);
    } else {
        v[0] = *px;
        v[1] = *py;
        v[2] = *pz;
        func_0016ace0(owner, v);
    }
}

// ---- 00245a90
struct Ent245 { u8 f0[8]; u8 f8[8]; s8 active; u8 pad17; u16 f18; u8 pad20[16]; };
extern Ent245 D_00371c50[];
extern u32 D_0035ed24;
extern u32 D_0035ed28;
extern u32 D_0035ed38;
void func_00288d80(u32, s32, s32, s32, u32, u16, Ent245*, u8*);
u8* func_002891b8(u32, s32);
u32 func_0023aa78(u8*);
void func_00288e08(u32, s32, u32, s32);
u32 func_0023aa98(u8*);
u32 func_0028dd90(u32);  // mod10_classify_012
u32 func_0028ddd8(u32);
void func_001395f8(u8*);
void func_002891f0(u32, s32, s32, s32, s32);
void func_002b4388(u32, Ent245*, s32);
void func_00245a90(void) {
    s32 sel = 0;
    u32 off = 0;
    for (s32 i = 0; i < 2; i++) {
        Ent245* e = (Ent245*)(off + (u32)D_00371c50);
        if (e->active) sel = i;
        func_00288d80(D_0035ed24, i, 0, 0, D_0035ed28, e->f18, e, (u8*)(off + (u32)D_00371c50[0].f8));
        off += 36;
        u8* m = func_002891b8(D_0035ed24, i);
        func_00288e08(D_0035ed24, i, func_0023aa78(m + 24), 0);
        u32 h = func_0023aa98(m + 24);
        *(u32*)(m + 432) = func_0028dd90(h);
        *(u32*)(m + 428) = func_0028ddd8(h);
        func_001395f8(m);
    }
    func_002891f0(D_0035ed24, sel, 1, 0, 2);
    func_002b4388(D_0035ed38, &D_00371c50[sel], 0);
}

// ---- 0024ada0
struct Sub24a { u8 pad[184]; u32 flags; };
struct Win24a { u8 pad[24]; Sub24a sub; u8 pad2[405 - 24 - 188]; u8 f405; u8 pad406[2]; u8* f408; u8 pad412[20]; u32 f432; };
union WinPtr24a { Win24a* p; u32 u; u8 b; };
extern WinPtr24a D_0035ed88;
extern u32 D_0035ed78;
union BufPtr24a { u8* p; u32 u; };
extern BufPtr24a D_0035ed98;
extern u32 D_0035ed70;
extern char D_00371e98[];
s32 func_001a6d08(s32);
void func_0028d980(Win24a*, s32, s32, s32, u32, s32, s32, s32, s32);
void func_00139620(Win24a*);
void func_001395f8(u8*);
void func_002fde18(u8*, s32, s32);
u8* func_001d56c8(s32);
u32 func_00192cc0(u8*, char*, u32);
s32 func_00192b30(u32);
u32 func_00192048(u32);
void func_00192c90(u32, u8*);
s32 func_002891e8(u32);
void func_001398d0(s32);
void func_0024ada0(void) {
    if (!func_001a6d08(9)) return;
    func_0028d980(D_0035ed88.p, 30011, 0, 0, D_0035ed78, 39, 41, -1, 100);
    func_00139620(D_0035ed88.p);
    func_001395f8((u8*)D_0035ed88.p);
    D_0035ed88.p->f432 = 2;
    D_0035ed88.p->f405 = 1;
    Sub24a* sb = &D_0035ed88.p->sub;
    sb->flags |= 8;
    func_002fde18(D_0035ed98.p, 0, 32);
    D_0035ed88.p->f408 = D_0035ed98.p;
    u8* buf = D_0035ed98.p;
    u8* v = func_001d56c8(10);
    if (v[0] != 3) {
        func_00192c90(func_00192048(0xcb9b), buf);
    } else {
        s32 n = func_00192b30(func_00192cc0(buf, D_00371e98, *(u32*)(v + 4)));
        func_00192c90(func_00192048(0xcb98), buf + n);
    }
    if (func_002891e8(D_0035ed70)) return;
    func_001398d0(100);
}

// ---- 002875e8
struct Alloc287;
typedef u8* (*AllocFn287)(Alloc287*, s32, s32);
struct Alloc287 { AllocFn287* vt; };
struct Heap287 { u8 pad[20]; Alloc287* alloc; };
extern Heap287* D_00347f80;
extern u8 D_00347e80[];
extern u8 D_00347e60[];
extern char D_01e21ef8[];
extern char D_003743f8[];
extern u32 D_0033caf4;
void func_002361a0(u8*);
void func_0023f800(u8*);
void func_00239700(u8*);
void func_002fee78(char*, char*, u32);
void func_0023fa90(u8*, char*);
u32 func_0023f988(u8*, s32);
void func_00138650(u8*, s32, u32, s32);
void func_002875e8(u8** o) {
    Alloc287* a = D_00347f80->alloc;
    u8* v = a->vt[0](a, 448, 0);
    *(u32*)(v + 12) = 0;
    *(u32*)v = (u32)D_00347e80;
    func_002361a0(v + 32);
    o[0] = v;
    func_0023f800((u8*)(o + 3));
    u8** slot = o + 1;
    for (s32 k = 1; k >= 0; k--) {
        a = D_00347f80->alloc;
        v = a->vt[0](a, 408, 0);
        *(u32*)(v + 12) = 0;
        *(u32*)v = (u32)D_00347e60;
        func_00239700(v + 24);
        *slot++ = v;
    }
    func_002fee78(D_01e21ef8, D_003743f8, D_0033caf4);
    func_0023fa90((u8*)(o + 3), D_01e21ef8);
    func_00138650(o[0], 26000, func_0023f988((u8*)(o + 3), 0), 0);
}

// ---- 002ae660
struct Ent2ae { u8 f0; u8 f1; u8 pad[14]; };
struct List2ae { u8 pad[8]; s32 count; u8 pad12[4]; Ent2ae ent[1]; };
struct Prog2ae { u8 pad[324]; u32 bits[1][2]; };
extern Prog2ae* D_0035f620;
List2ae* func_00294000(s32);
s32 func_002b3ac8(s8);
static inline bool testb(u32* p, u32 n) { return p[n >> 5] & (1 << (n & 31)); }
s32 func_002ae660(s32 sel) {
    s32 i = 0;
    s32 ok = 1;
    List2ae* l = func_00294000(9);
    for (Ent2ae* e = l->ent; i < l->count; i++, e++) {
        if (sel >= 0 && sel != i) continue;
        s32 n = func_002b3ac8((s8)(e->f1 & 0xf));
        for (s32 j = 0; j < n; j++) {
            if (!testb(D_0035f620->bits[i], j)) {
                ok = 0;
                break;
            }
        }
        if (!ok) break;
    }
    return ok;
}

// ---- 002c5b20
struct Quad2c5 { u32 v[4]; };
struct Rec2c5 { u32 a; Quad2c5 b; };
struct Src2c5 { u32 f0; Rec2c5 r; };
struct Obj2c5 { u8 pad[2548]; Rec2c5 r; };
struct Msg2c5 { u16 f0; u16 id; };
void func_002c5dc0(u8*, u8*);
void func_002c5c50(u8*, u8*);
void func_0016bd60(u8*, s32);
s32 func_00190140(Rec2c5*);
void func_002f1990(u8*);
Vq func_00190388(const void*);  // vec4_from_arg
const Vq* func_0016c028(u32);  // obj_get_attach_or_alt
void func_002c6eb8(u8*, u8*, Rec2c5*);
void func_002c5b20(u8* o, Msg2c5* m) {
    switch (m->id) {
    case 518:
        func_002c5dc0(o, *(u8**)(o + 2884) + 12);
        break;
    case 159:
        func_002c5c50(o, *(u8**)(o + 2884) + 12);
        break;
    case 582: {
        Rec2c5* sr = &(*(Src2c5**)(o + 2880))->r;
        ((Obj2c5*)o)->r.a = sr->a;
        ((Obj2c5*)o)->r.b = sr->b;
        Rec2c5* r = &((Obj2c5*)o)->r;
        if (func_00190140(r)) {
            func_002f1990(o + 3024);
            Vq d = vsub(func_00190388(r), *func_0016c028((u32)o));  // vec4_from_arg
            func_002c6eb8(o + 2928, o, r);
        }
        break;
    }
    case 583:
        func_0016bd60(o, 59);
        break;
    }
}

// ---- 002d4f60
union W2d4 { u32 u; f32 f; };
struct Quad2d4 { W2d4 v[4]; };
struct Rec2d4 { u32 a; Quad2d4 b; };
struct Src2d4 { u32 f0; Rec2d4 r; };
struct Obj2d4 { u8 pad[1344]; Vq pos; u8 pad1360[2548 - 1360]; Rec2d4 r; u8 pad2568[3104 - 2568]; Vq dir; };
Vq func_00190388(const void*);  // vec4_from_arg
Vq func_002d4f60(Obj2d4* o) {
    Rec2d4* rr = &o->r;
    Rec2d4* sr = &(*(Src2d4**)((u8*)o + 2880))->r;
    o->r.a = sr->a;
    o->r.b = sr->b;
    Vq d;
    d.w = d.z = d.y = d.x = 0.0f;
    if (rr->b.v[2].u == 6) {
        d = vsubn(func_00190388(rr), o->pos);  // vec4_from_arg
        vnormalize(&d);
        o->dir = d;
    }
    Vq r;
    vcopy(&r, &o->dir);
    return r;
}

// ---- 002da3d8
struct Range2da { u8 pad[12]; f32 near; f32 far; };
struct Obj2da { u8 pad[1344]; Vq pos; u8 pad1360[3056 - 1360]; u32 tgt; u8 pad3060[17]; u8 multi; u8 pad3078[154]; Vq pts[8]; };
extern u32 D_00361f60;
s32 func_002da110(Obj2da*);  // is_field340_eq14
s32 func_001c0cd8(u32);
Range2da* func_002d73f0(u32);
s32 func_002da3d8(Obj2da* o, const Vq* p) {
    s32 r = 0;
    if (func_002da110(o)) return r;
    u32 m = D_00361f60;
    if (!m) return 0;
    f32 rad;
    if (!o->tgt || !func_001c0cd8(o->tgt)) rad = func_002d73f0(m)->near;
    else rad = func_002d73f0(m)->far;
    if (o->multi) {
        for (s32 i = 0; i < 8; i++) {
            Vq d = vsub(o->pts[i], *p);
            r = 0;
            if (vlen(d) <= rad) return 1;
        }
        return r;
    }
    Vq d = vsub(o->pos, *p);
    return vlen(d) <= rad;
}

// ---- 00304ba8
struct Node304 { Node304* next; };
struct Ctx304;
struct Ctx304 {
    u8 pad[56]; u32 f56; void (*f60)(Ctx304*); u8 pad64[12]; Node304** f76; u8 pad80[4]; Node304* f84;
    u8 pad88[240]; Node304* f328; Node304 f332; u8 pad336[136]; u32 f472;
};
extern Ctx304* D_00365c48;
void func_00302e90(Ctx304*, void*);
void func_00304b60(Ctx304*, u32);
void func_00304ba8(Ctx304* c) {
    if (c == D_00365c48) return;
    if (c->f76) {
        for (s32 i = 0; i < 15; i++) {
            Node304* n = c->f76[i];
            while (n) {
                Node304* cur = n;
                n = n->next;
                func_00302e90(c, cur);
            }
        }
        func_00302e90(c, c->f76);
    }
    if (c->f328 && c->f328 != &c->f332) {
        Node304* n = c->f328;
        do {
            Node304* cur = n;
            n = n->next;
            func_00302e90(c, cur);
        } while (n != &c->f332);
    }
    if (c->f84) func_00302e90(c, c->f84);
    if (!c->f56) return;
    c->f60(c);
    if (c->f472) func_00304b60(c, c->f472);
}

// ---- 00323e98
extern u8 D_00347f98[];
extern u8 D_00347e60[];
extern u8 D_00347e40[];
void func_0031a838(u8*);
void func_00239700(u8*);
static inline void ctor_323(u8* e) {
    *(u32*)e = (u32)D_00347f98;
    func_0031a838(e + 12);
    *(u32*)e = (u32)D_00347e60;
    func_00239700(e + 24);
    *(u32*)e = (u32)D_00347e40;
    *(u32*)(e + 408) = 0;
}
void func_00323e98(u8* p) {
    {
        u8* e = p + 4;
        s32 i = 4;
        do { ctor_323(e); i--; e += 436; } while (i != -1);
    }
    {
        u8* e = p + 2184;
        s32 i = 4;
        do { ctor_323(e); i--; e += 436; } while (i != -1);
    }
    {
        u8* e = p + 4364;
        s32 i = 14;
        do { ctor_323(e); i--; e += 436; } while (i != -1);
    }
}

}
