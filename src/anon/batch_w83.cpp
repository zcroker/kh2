#include "../common/types.h"

// 128-bit copy through $t0.
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// 16-byte value whose assignment is a single lq/sq.
struct QWord {
    u32 v[4];
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

struct Vec4 {
    f32 x, y, z, w;
    Vec4() {}
    Vec4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    Vec4(const Vec4& o) { QCOPY(this, &o); }
    Vec4& operator=(const Vec4& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

// Local with a non-trivial destructor: keeps the final call a jal.
struct NoTail { ~NoTail() {} };

extern "C" {
extern u32 D_0034d850[];
void func_001a17c8(void*);
void func_001b78b8(void*);
void func_002cb708(void*);
void func_00105110(void*);
void func_001b3098(void*);
void func_001a9350(void*);
void func_001a6d68(void*);
void func_00187b90(void*);
void func_0017eb98(void*);
void func_001ddd88(void*);

// Destructor body: reset vtable, release owned objects and members.
void func_0016a420(u8* p) {
    NoTail nt;
    *(u32*)p = (u32)D_0034d850;
    if (*(void**)(p + 1164)) func_001a17c8(*(void**)(p + 1164));
    if (*(void**)(p + 2088)) func_001b78b8(*(void**)(p + 2088));
    if (*(void**)(p + 1296)) func_001b78b8(*(void**)(p + 1296));
    void* s = *(void**)(p + 1288);
    if (s) {
        func_002cb708(s);
        func_00105110(s);
    }
    func_001b3098(p + 2048);
    func_001a9350(p + 1952);
    func_001a6d68(p + 1280);
    func_00187b90(p + 768);
    func_0017eb98(p + 320);
    func_001ddd88(p + 156);
    func_001ddd88(p + 128);
}

struct Entry600 {
    u8 pad[452];
    s32 f452;
    s32 f456;
    s32 f460;
    s32 f464;
    s32 f468;
    char name[128];
};
struct Ring600 {
    s32 head;
    s32 tail;
    Entry600 e[4];
};
extern u8* D_0034a6f0;
void func_00192c90(char*, char*);
void func_00192b30(char*);

// Push an entry into a 4-slot ring buffer if there is room.
void func_00153468(s32 a, char* name, s32 b) {
    Ring600* r = (Ring600*)(D_0034a6f0 + 12076);
    s32 idx = r->head;
    s32 n = (idx - r->tail + 4) % 4;
    if (n < 3) {
        r->head = (idx + 1) % 4;
        Entry600* e = &r->e[idx];
        func_00192c90(name, e->name);
        func_00192b30(name);
        e->f456 = a;
        e->f464 = b;
        e->f452 = 0;
        e->f460 = 0;
        e->f468 = 0;
    }
}

s32 func_00181500(s32);
s32 func_001a3570(s32);
void func_00181178(s32);
extern u8 D_0032f05a;

void func_00181670(void) {
    if (!func_00181500(11302)) {
        if (func_00181500(11313) && func_001a3570(87) > 0) func_00181178(11302);
        return;
    }
    if (!func_00181500(11303)) {
        if (func_00181500(11316) && D_0032f05a >= 5) func_00181178(11303);
        return;
    }
    if (!func_00181500(11304)) {
        if (func_00181500(11319) && func_001a3570(87) >= 2) func_00181178(11304);
        return;
    }
    if (!func_00181500(11309)) {
        if (func_00181500(11322) && func_001a3570(23) >= 3) func_00181178(11309);
    }
}

struct Name10 { u16 c[5]; };
extern Name10 D_01c60530;
extern void* D_0034ecf4;
extern char D_0036c7b8[];
s32 func_001051a0(void*, const char*);
void func_00170c00(void*);
s32 func_00105140(const char*, s32);
void func_002fee78(char*, const char*, ...);
s32 func_001688c8(const char*);
void* func_00170b30(s32);
void func_001684c0(const char*, void*, s32, s32);

// Load a named file into a 2 KB-aligned buffer unless it is already loaded.
void func_00181ad0(const char* name) {
    char buf[48];
    if (func_001051a0(&D_01c60530, name)) return;
    if (D_0034ecf4) func_00170c00(D_0034ecf4);
    func_002fee78(buf, D_0036c7b8, func_00105140(name, 0));
    D_0034ecf4 = func_00170b30((func_001688c8(buf) + 2047) & ~2047);
    func_001684c0(buf, D_0034ecf4, 0, 0);
    D_01c60530 = *(const Name10*)name;
}

struct Info32 {
    u32 f0, f4, f8, f12;
    u32 pad[4];
    Info32() { f12 = 0; }
};
void* func_0016bc20(void*, void*, s32);
void func_0018a818(Info32*, void*, void*);
void* func_001b9bc8(void*);
s32 func_0016bff0(void*);
s32 func_0018a550(Info32*, Info32*);

void* func_0018bc60(void* a, void* b) {
    void* v = func_0016bc20(a, b, -1);
    if (!v) return 0;
    Info32 i0;
    func_0018a818(&i0, a, v);
    void* it = 0;
    Info32 i1;
    while ((it = func_001b9bc8(it))) {
        if (func_0016bff0(it) == func_0016bff0(a)) continue;
        void* w = func_0016bc20(it, b, -1);
        if (!w) continue;
        func_0018a818(&i1, it, w);
        if (func_0018a550(&i0, &i1)) return it;
    }
    return 0;
}

void func_0018a958(void*, s32, f32, f32);
s32 func_0019ba60(void*);
void* func_0016bc20b(void*, s32, void*) asm("func_0016bc20");
void func_0018a818b(void*, void*, void*) asm("func_0018a818");
void func_001902a8(void*, void*);

void func_001903d0(void** p, u8* out) {
    u8* o = (u8*)p[2];
    if (o) {
        func_0018a958(out, 0, *(f32*)(o + 256), *(f32*)(o + 260));
        *(QWord*)(out + 16) = *(QWord*)((u8*)p[2] + 224);
    } else if (func_0019ba60(p[0])) {
        void* v = func_0016bc20b(p[0], 7, p[1]);
        if (v) func_0018a818b(out, p[0], v);
        else func_001902a8(p, out);
    } else {
        // vf0 = (0, 0, 0, 1)
        asm volatile("sqc2 $vf0, 0(%0)" : : "r"(out + 16) : "memory");
    }
    *(f32*)(out + 28) = 1.0f;
}

struct VTest { virtual void f0(); virtual void f4(); virtual s32 test(QWord*); u8 pad[92]; VTest* next; };
u8* func_00186078(u8*);
QWord* func_0016c028(u8*);
void func_001991a8(s32, u32);

void func_0019b180(u8* p) {
    QWord v;
    u8* it = 0;
    while ((it = func_00186078(it))) {
        v = *func_0016c028(it);
        VTest* o = 0;
        while ((o = !o ? *(VTest**)(p + 12) : o->next)) {
            if (o->test(&v)) {
                if ((*(u32*)(it + 2728) & ~0x10000) != *(u16*)(*(u8**)(p + 8) + 2)) {
                    func_001991a8(*(s32*)(*(u8**)(p + 8) + 28), func_0016bff0(it));
                }
                *(u32*)(it + 2728) = *(u16*)(*(u8**)(p + 8) + 2);
                break;
            }
        }
    }
}

u32* func_00177860(void);
s32 func_001bc2a8(void*, void*, s32);
static inline bool lt4(void* c, void* a) { return func_001bc2a8(c, a, 0) < 4; }

bool func_0019ea10(void* a, u8* b, void* c) {
    u32* bits = func_00177860();
    switch (b[2]) {
    case 19: {
        u32 id = *(u16*)(b + 4);
        if (!(bits[id >> 5] & (1 << (id & 31)))) return 0;
        break;
    }
    case 20:
        if (!func_001a3570(*(u16*)b)) return 0;
        break;
    }
    return lt4(c, a);
}

extern f32 D_00349e10;
f32 func_0017c930(void*, void*);
Vec4 func_00184540(f32, f32);
s32 func_00180618(void*);

Vec4 func_001a0a48(void* a, u8* o) {
    Vec4 r;
    f32 t = *(f32*)(o + 208) + D_00349e10;
    if (t < *(f32*)(o + 212)) {
        *(f32*)(o + 208) = t;
        r.y = func_0017c930(a, o);
        r.x = r.z = 0.0f;
        return r;
    }
    r = func_00184540(0.95f, 0.9f);
    u8* s = o + 320;
    if (*(s32*)(s + 20) == 156 && !func_00180618(s)) {
        r.y = 0;
        return r;
    }
    *(f32*)(o + 208) = t;
    r.y = func_0017c930(a, o);
    return r;
}

struct Rgba8 { s8 r, g, b, a; };
extern Rgba8 D_0036da98;
void* func_00168b88(void*, s32, u32, s32);
void func_001bdb70(void*, void*, void*, void*, s32);
static inline u32 packRgba(const Rgba8& c) { return c.r | (c.g << 8) | (c.b << 16) | (c.a << 24); }
struct R8 { u8 pad[8]; void* p; };
struct Obj1b5708 { u32 pad; void* d; };

void func_001b5708(Obj1b5708* p, void* a) {
    R8* r0 = (R8*)func_00168b88(p->d, 24, packRgba(D_0036da98), 0);
    void* d = p->d;
    u32 c = packRgba(D_0036da98);
    void* v0 = r0->p;
    R8* r1 = (R8*)func_00168b88(d, 25, c, 0);
    func_001bdb70(*(void**)(*(u8**)((u8*)p + 12) + 2884), a, v0, r1->p, 0);
    *(u32*)((u8*)p + 64) |= 8;
    *(s32*)((u8*)p + 60) += 1;
}

extern u8 D_01d49520[];
extern u32 D_00351408[];
void func_001980d0(void*, void*, s32, void*, f32);
void* func_001de168b(void*, void*, s32, s32, s32, s32) asm("func_001de168");
void func_001dcc00(void*, void*);
void* func_001050d8(u32);
void func_001c1308(void*, void*, void*, void*, void*);

// Constructor: base init, vtable, then create the owned 56-byte helper.
void func_001c23a8(u8* p, void* a1, void* a2, void* a3, void* t0, void* t1, void* t2) {
    func_001980d0(p, a1, 4, D_01d49520, 0.0f);
    *(u32*)p = (u32)D_00351408;
    *(u32*)(p + 1416) |= 0x100000;
    void* h = func_001de168b(p + 156, a2, 0, 1, 0, 0);
    func_001dcc00(h, a3);
    void* o = func_001050d8(56);
    func_001c1308(o, h, t0, t1, t2);
    *(void**)(p + 2548) = o;
}

s32 func_00186ce8(u8*);
s32 func_00186d18(u8*);
s32 func_001c7950(void*, void*, f32, f32);
void func_001c79a0(void*, void*, s32);
void func_001d86a0(s32, s32);
struct Fl40 { u32 on:1; u32 rest:31; };

void func_001ccfa0(void* self, u8* a) {
    if (((Fl40*)(a + 40))->on) {
        u8* it = 0;
        while ((it = func_00186078(it)) != 0) {
            if (func_00186ce8(it)) continue;
            if (func_00186d18(it)) continue;
            if (*(u32*)(it + 360) & 0x40) continue;
            if (!func_001c7950(a, it, 0.0f, 0.0f)) continue;
            func_001c79a0(a, it, 0);
            u32 m = *(u32*)(it + 1416) & 0x80;
            func_001d86a0(1, m == 0);
            return;
        }
    }
}

struct Trig { f32 x, y, z; u8 pad[8]; u8 cnt; u8 pad2[2]; u8 flag; u8 pad3[68]; s32* ref; };
void* func_0016e920(s32);
u8* func_001dba18(void*);
Trig* func_001c16f0(void*, Trig*);

// Bump the counter of every trigger whose XZ position lies inside box.
void func_001d6790(f32* box) {
    void* list = *(void**)(func_001dba18(func_0016e920(2120)) + 2548);
    Trig* it = 0;
    while ((it = func_001c16f0(list, it))) {
        if (it->cnt != *it->ref) continue;
        if (box[0] <= it->x && it->x <= box[3] && box[2] <= it->z && it->z <= box[5]) {
            it->flag = 0;
            it->cnt++;
        }
    }
}

// r = m * v (4x4 matrix at m, column vectors), via VU0.
static inline Vec4 xform(const void* m, const Vec4& v) {
    Vec4 r;
    asm volatile(
        "lqc2 $vf5, 0(%1)\n\t"
        "lqc2 $vf1, 0(%2)\n\t"
        "lqc2 $vf2, 16(%2)\n\t"
        "lqc2 $vf3, 32(%2)\n\t"
        "lqc2 $vf4, 48(%2)\n\t"
        "vmulax.xyzw ACC, $vf1, $vf5x\n\t"
        "vmadday.xyzw ACC, $vf2, $vf5y\n\t"
        "vmaddaz.xyzw ACC, $vf3, $vf5z\n\t"
        "vmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
        "sqc2 $vf5, 0(%0)"
        : : "r"(&r), "r"(&v), "r"(m) : "memory");
    return r;
}
struct XBox { u8 pad[16]; f32 m[16]; f32 ex, ey, ez; };

// Is point inside the box's local half-extents after transforming by its matrix?
bool func_001db298(XBox* p, const Vec4* in) {
    Vec4 v;
    v = *in;
    v.w = 1.0f;
    v = xform(p->m, v);
    bool r = false;
    if (-p->ex <= v.x && v.x <= p->ex && -p->ey <= v.y && v.y <= p->ey && -p->ez <= v.z && v.z <= p->ez) r = true;
    return r;
}

extern s32 D_01d9eab4;
extern s32 D_01d9ea9c;
extern u8* D_01d9e6e0;
void func_001f5f10();
s32 func_00222568(void);
void func_0021ee48(void*, void*, void (*)(), void*, s32, u32, u32);

void func_001f6030(u8* p, u8* e, u8* c) {
    if (D_01d9eab4) return;
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ull) return;
    if (e[7] == 255) return;
    if ((func_00222568() >> 8) & e[7]) return;
    if (*(s32*)(e + 12) == -1) return;
    if (*(s32*)(e + 20) == -1) return;
    func_0021ee48(p, e, func_001f5f10, p + **(s32**)(c + 12) + 160, *(s16*)(e + 4), e[8], e[6]);
}

extern f32 D_00354bd0[3];
extern f32 D_00354bc0[3];
void func_0021ebe8(void*, s32*);

// Radians -> 16-bit angle units (32768 per pi).
void func_00201208(u8* p, u8* c) {
    u8* s = p + *(s32*)(*(u8**)(c + 12) + 12) + 160;
    s32 a[3];
    a[0] = (s32)(D_00354bd0[0] * 32768.0f / 3.1415927f);
    a[1] = (s32)(D_00354bd0[1] * 32768.0f / 3.1415927f);
    a[2] = (s32)(D_00354bd0[2] * 32768.0f / 3.1415927f);
    func_0021ebe8(s, a);
    *(f32*)(s + 48) = D_00354bc0[0];
    *(f32*)(s + 52) = D_00354bc0[1];
    *(f32*)(s + 56) = D_00354bc0[2];
}

s32 func_002282f0(s32);
u8* func_00227d10(s32);
void func_001ba028(void*);
double func_00313b80(f32);
double func_002f83f0(double);
f32 func_003144b0(double);
struct Rot { s16 pad0, pad1; s16 a, b, nx, ny, nz; };
struct Hold { u8 pad[8]; f32* o; };

// Wrap each rotation component through double helpers, optionally negating it.
void func_0022e4f0(Rot* r) {
    if (func_002282f0(r->a)) return;
    Hold* v = (Hold*)func_00227d10(r->b);
    func_001ba028(v->o);
    f32* o = v->o;
    o[12] = func_003144b0(func_002f83f0(func_00313b80(o[12])));
    if (r->nx) { v->o[12] = -v->o[12]; asm volatile("" ::: "memory"); }
    o = v->o;
    o[13] = func_003144b0(func_002f83f0(func_00313b80(o[13])));
    if (r->ny) { v->o[13] = -v->o[13]; asm volatile("" ::: "memory"); }
    o = v->o;
    o[14] = func_003144b0(func_002f83f0(func_00313b80(o[14])));
    if (r->nz) v->o[14] = -v->o[14];
}

struct VObj20 { virtual void f0(); virtual void f4(); virtual void f8(); virtual void f12(); virtual void f16(); virtual void f20(); };
extern VObj20* D_0035ee3c;
extern VObj20* D_0035ee44;
extern VObj20* D_0035ee40;
extern void* D_0035ee34;
extern void* D_0035ee38;
s32 func_00139d78(void*);
s32 func_0028acc8(void*);
void func_0028abe0(void*);
void func_00250928(void);
void func_0028ce38(void);

void func_0024fe30(void) {
    if (func_00139d78(D_0035ee3c)) D_0035ee3c->f20();
    if (func_00139d78(D_0035ee44)) D_0035ee44->f20();
    if (func_00139d78(D_0035ee40)) D_0035ee40->f20();
    if (func_0028acc8(D_0035ee34)) func_0028abe0(D_0035ee34);
    if (func_0028acc8(D_0035ee38)) func_0028abe0(D_0035ee38);
    func_00250928();
    func_0028ce38();
}

u8* func_00257770(void);
extern void* D_0035f01c;
extern void* D_0035f020;
extern void* D_0035f024;
u8 func_00139d78c(void*) asm("func_00139d78");
u8 func_0028acc8c(void*) asm("func_0028acc8");

// Is anything in this menu still busy?
u8 func_00262e30(void) {
    u8 r;
    u8* s = func_00257770();
    if ((r = func_00139d78c(s))) return r;
    if ((r = func_00139d78c(s + 1632))) return r;
    if ((r = func_00139d78c(s + 0xb350))) return r;
    if ((r = func_0028acc8c(D_0035f01c))) return r;
    if ((r = func_0028acc8c(D_0035f020))) return r;
    if ((r = func_0028acc8c(D_0035f024))) return r;
    s32 i;
    u8* e;
    for (i = 0, e = s; i < 24; i++, e += 436) {
        if ((r = func_00139d78c(e + 3376))) return r;
        if ((r = func_00139d78c(e + 24304))) return r;
    }
    r = func_00139d78c(s + 816);
    return r;
}

void func_00139510(void*);
s32 func_0027e920(void);
void func_0027e770(void);
// Tz CmItem LeaveHelp
void LeaveHelp(void*) asm("_ZN2Tz6CmItem9LeaveHelpEv");
void LeaveHelp(void*) {
    u8* s = func_00257770();
    u8* w = s + 408;
    if (func_00139d78(w)) func_00139510(w);
    w = s + 2068;
    if (func_00139d78(w)) func_00139510(w);
    if (func_0028acc8(D_0035f020)) func_0028abe0(D_0035f020);
    if (func_0028acc8(D_0035f024)) func_0028abe0(D_0035f024);
    if (func_0027e920()) func_0027e770();
    w = s + 1224;
    if (func_00139d78(w)) func_00139510(w);
}

extern void* D_0035f010;
extern void* D_0035f0ec;
void* func_00257070(s32);
u8* func_00281180(void*, void*);
void func_001a3188(u32, s32, s32);
u8* func_00281f20(void*);
u32 func_0028b040(void*);
void func_001a3458(u32, s32);
struct Six { u8 b0, b1, b2, b3, b4, b5; };

s32 func_0026af30(s32 idx, u32 id) {
    u8* b = func_00281180(D_0035f010, func_00257070(1));
    u16* e = (u16*)(idx * 2 + *(u32*)(b + 580));
    if (e[26]) func_001a3188(e[26], 100, 0);
    Six* t = (Six*)func_00281f20(D_0035f0ec);
    u32 n = func_0028b040(D_0035f01c) - 1;
    if (id == 0 || t[n].b2 != 0) {
        e[26] = id;
        e[34] = 0;
        if (id) func_001a3458(id, 100);
    } else {
        e[34] = id;
        e[26] = 0;
    }
    return 1;
}

extern VObj20* D_0035f208;
extern void* D_0035f218;
void func_00274ac8(void);
void func_0028f878(void);
void func_0028d620(void*);
void func_00276e28(void);
void func_002945a8(void);
void func_00295868(void);
void func_00297010(void);
void func_00297e00(s32);
void func_002995a8(void);
void func_0029aac0(s32);
void func_0029ee38(void);
void func_002a07f0(s32);
void func_002a2150(void);
void func_002a4df8(void);
void func_002a6a18(void);
void func_002a7760(void);
void func_002a8a88(void);
void func_002aecf0(s32);
void func_00275cb8(void);
void func_002763c8(void);

void func_002749f0(void) {
    func_00274ac8();
    if (func_00139d78(D_0035f208)) D_0035f208->f20();
    func_0028f878();
    func_0028d620(D_0035f218);
    func_00276e28();
    func_002945a8();
    func_00295868();
    func_00297010();
    func_00297e00(-1);
    func_002995a8();
    func_0029aac0(-1);
    func_0029ee38();
    func_002a07f0(-1);
    func_002a2150();
    func_002a4df8();
    func_002a6a18();
    func_002a7760();
    func_002a8a88();
    func_002aecf0(1);
    func_00275cb8();
    func_002763c8();
}

void func_00288c58(void*, s16);
void func_00288f48(void*, s32, s32, s32, s32);
void func_0028af18(void*, s32);
void func_0028b1b0(void*, s32);
union S16Ptr { s16* p; s16 h; };
struct Grid { s16 h0, h2, h4, pad6, pad8, pad10, pad12, h14, h16, h18, h20, h22, h24, h26, h28, pad30, pad32, pad34; u8 b36, b37, b38, b39; u32 pad40; S16Ptr f44; S16Ptr f48; };

void func_002888f8(Grid* g, s32 n, u8 kind) {
    g->h0 = 0;
    g->h16 = n;
    g->h2 = -1;
    g->h28 = 1;
    g->b36 = kind;
    g->h20 = -1;
    g->h4 = 0;
    g->h18 = 0;
    g->h22 = 0;
    g->h24 = 0;
    g->h26 = 0;
    g->b37 = 0;
    g->b38 = 0;
    g->b39 = 0;
    func_00288c58(g, n);
    func_00288f48(g, 16, 32, 0, 0);
    for (s32 i = 0; i < g->h16; i++) {
        for (s32 j = 0; j < 4; j++) {
            g->f44.p[i * 4 + j] = -1;
            g->f48.p[i * 4 + j] = -1;
        }
    }
    g->h14 = 0;
    func_0028af18(g, 115);
    func_0028b1b0(g, 0);
}

void* func_0023f1b0(s32);
void* func_0023c4b8(void*, s32);
u8* func_00236ca8(void*, s32);
void func_001386e0(void*, s32, void*, void*, s32, s32);
// Tz Pause CreateFadeObject
void CreateFadeObject(u8*, s32, s32, s32, s32, s32, s32, s32) asm("_ZN2Tz5Pause16CreateFadeObjectEz");
void CreateFadeObject(u8* p, s32 id, s32 a2, s32 a3, s32 t0, s32 t1, s32 t2, s32 t3) {
    void* h = func_0023c4b8(func_0023f1b0(t0), a2);
    u8* v = func_00236ca8(*(void**)((u8*)func_0023f1b0(t0) + 40), a3);
    func_001386e0(p, id, h, v, t1, t3);
    *(s32*)(p + 392) = t2;
}

struct Flags236 { u8 pad[236]; u32 bits[42]; };
extern Flags236* D_0035f610;
Flags236* func_002a9d68(void);
u8* func_001a82b0(u8*);
void* func_002764b0(u8);
s32 func_002954e0(void*);

void func_002ab448(void) {
    u32* bits = func_002a9d68()->bits;
    u8* it = 0;
    for (u32 i = 0;; i++) {
        it = func_001a82b0(it);
        if (!it) return;
        if (it[4]) continue;
        u16 id = *(u16*)(it + 8);
        if (!id) continue;
        if (id == 2048) continue;
        if (!func_00181500(id)) continue;
        s32 v = func_002954e0(func_002764b0(it[5]));
        u32 w = i >> 5;
        u32 bit = 1 << (i & 31);
        if (v) {
            if (!(bits[w] & bit)) {
                u8* a = (u8*)D_0035f610->bits;
                a += w * 4;
                *(u32*)a |= bit;
            }
        }
    }
}

u8* func_002d73f0(void);
s32 func_002cee58(void*, void*);

// d = a - b (xyzw) via VU0.
static inline void vsub(Vec4* d, const void* a, const void* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}
// |v.xyz| via VU0.
static inline f32 vlen(const Vec4* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\t"
                 "vaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2 $8, $vi22\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
struct Pt4 {
    f32 x, y, z, w;
    Pt4(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
} __attribute__((aligned(16)));

s32 func_002d89b0(u8* p, u8* a) {
    s32* t = *(s32**)(a + 12);
    if ((u32)(t[0] - 2034) < 2) return 1;
    Pt4 q(((f32*)t)[1], ((f32*)t)[2], ((f32*)t)[3], 0.0f);
    Vec4 d;
    vsub(&d, p + 448, &q);
    f32 dist = vlen(&d);
    if (*(f32*)(func_002d73f0() + 20) < dist) return 0;
    return func_002cee58(p, t);
}

extern void* D_00361f60;
void* func_002d9210(void*);
s32 func_001c0cd8(void*);
u8* func_0016bc20c(void*, s32, s32) asm("func_0016bc20");
Vec4* func_0016c028b(void*) asm("func_0016c028");

// Is p within the target's radius?
bool func_002da308(u8* p) {
    void* v = func_002d9210(D_00361f60);
    if (!v) return false;
    if (func_001c0cd8(v)) return false;
    u8* pos = p + 1344;
    f32 r = *(s16*)(func_0016bc20c(v, 5, -1) + 16);
    Vec4* q = func_0016c028b(v);
    Vec4 d;
    vsub(&d, pos, q);
    return vlen(&d) < r;
}

s32 func_002e0fe8(void*);

// Direction (scaled xy, normalized) with its length in w; zero if a is not ready.
Vec4 func_002e17a0(void* a, f32* b) {
    if (!func_002e0fe8(a)) {
        return Vec4(0.0f, 0.0f, 0.0f, 0.0f);
    }
    Vec4 t;
    t.x = b[0];
    t.y = b[1];
    t.w = t.z = 0.0f;
    f32 k = 25.0f;
    asm volatile("lqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvmulx.xyzw $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)"
                 : : "r"(&t), "f"(k) : "$8", "memory");
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\t"
                 "vaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2 $8, $vi22\n\t"
                 "vaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\t"
                 "vmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(len) : "r"(&t) : "$8", "memory");
    t.w = len;
    return t;
}

f32 func_002f8ad0(f32, f32);
f32 func_0017ce10(f32);
Vec4 func_0017d0e8(f32);

// Turn cur's heading toward tgt by at most lim.
Vec4 func_002ea360(f32 lim, f32* cur, f32* tgt) {
    Vec4 r;
    f32 m = lim * D_00349e10;
    f32 d = func_002f8ad0(tgt[0], tgt[2]);
    f32 c = func_002f8ad0(cur[0], cur[2]);
    d = d - c;
    cur[3] = c;
    f32 e = func_0017ce10(d);
    if (m < e) r = func_0017d0e8(func_0017ce10(cur[3] + m));
    else if (e < -m) r = func_0017d0e8(func_0017ce10(cur[3] - m));
    else r = *(Vec4*)tgt;
    return r;
}

typedef s32 (*SigFn)(s32);
s32 func_002feac0(void*);
s32 func_002fedf0(void*);
s32 func_002fed98(void*, s32, s32);
s32 raise_r(u8*, u32, u32, u32) asm("_Z16wtarget_002febb0jjjj");
// newlib _raise_r(reent, sig): errno at +0, signal table at +468.
s32 raise_r(u8* r, u32 sig, u32, u32) {
    if (sig >= 32) {
        *(s32*)r = 22;
        return -1;
    }
    if (*(SigFn**)(r + 468) == 0 && func_002feac0(r) != 0) return -1;
    SigFn* tab = *(SigFn**)(r + 468);
    SigFn f = tab[sig];
    if (f == (SigFn)0) return func_002fed98(r, func_002fedf0(r), sig);
    if (f == (SigFn)1) return 0;
    if (f == (SigFn)-1) {
        *(s32*)r = 22;
        return 1;
    }
    tab[sig] = 0;
    f(sig);
    return 0;
}

// Elements of member arrays, destroyed through their vtables.
struct E408 { virtual void f0(); virtual void f4(); virtual void f8(); virtual void f12(); u8 pad[404]; };
struct E592 { virtual void f0(); virtual void f4(); virtual void f8(); virtual void f12(); u8 pad[588]; };
struct E412 { virtual void f0(); virtual void f4(); virtual void f8(); virtual void f12(); u8 pad[408]; };
struct E344 { virtual void f0(); u8 pad[340]; };
struct VReg { virtual void f0(); virtual void f4(void*); };
union RegPtr { u8* p; u32 v; };
extern u32 D_0034a5b0[];
extern u32 D_00347e80[];
extern u32 D_00347f98[];
extern RegPtr D_00347f80;
void func_00239870(void*);
void func_002361d0(void*);

void func_0031c368(u8* p) {
    *(u32*)p = (u32)D_0034a5b0;
    func_00239870(p + 6208);
    if (p + 4576) {
        E408* e = (E408*)(p + 6208);
        for (;;) {
            if ((E408*)(p + 4576) == e) break;
            --e;
            e->f12();
        }
    }
    if (p + 496) {
        E408* e = (E408*)(p + 4576);
        for (;;) {
            if ((E408*)(p + 496) == e) break;
            --e;
            e->f12();
        }
    }
    *(u32*)(p + 48) = (u32)D_00347e80;
    func_002361d0(p + 80);
    *(u32*)(p + 48) = (u32)D_00347f98;
    *(u32*)p = (u32)D_00347f98;
    (*(VReg**)(D_00347f80.p + 20))->f4(p);
}

extern u32 D_0034a848[];
extern u32 D_00348608[];
void func_0031cec0(void*);

void func_0031d0f8(u8* p) {
    *(u32*)p = (u32)D_0034a848;
    if (p + 2576) {
        E592* e = (E592*)(p + 5536);
        for (;;) {
            if ((E592*)(p + 2576) == e) break;
            --e;
            e->f12();
        }
    }
    if (p + 916) {
        E412* e = (E412*)(p + 2564);
        for (;;) {
            if ((E412*)(p + 916) == e) break;
            --e;
            e->f12();
        }
    }
    *(u32*)p = (u32)D_00348608;
    func_0031cec0(p + 64);
    *(u32*)p = (u32)D_00347f98;
}

extern u32 D_00350ab0[];
extern u32 D_00350bb0[];
extern u32 D_0034e8a8[];
void func_00239848(void*);
void func_001ac5b8(void*);

// Deleting destructor.
void func_0031fb90(u8* p) {
    *(u32*)p = (u32)D_00350ab0;
    if (p + 3280) {
        E344* e = (E344*)(p + 4656);
        for (;;) {
            if ((E344*)(p + 3280) == e) break;
            --e;
            e->f0();
        }
    }
    func_00239870(p + 2936);
    *(u32*)p = (u32)D_00350bb0;
    if (p + 1544) {
        E344* e = (E344*)(p + 2920);
        for (;;) {
            if ((E344*)(p + 1544) == e) break;
            --e;
            e->f0();
        }
    }
    func_00239870(p + 1200);
    func_00239870(p + 848);
    func_00239870(p + 484);
    *(u32*)(p + 132) = (u32)D_0034e8a8;
    func_00239848(p + 132);
    func_001ac5b8(p);
    func_00105110(p);
}

}
