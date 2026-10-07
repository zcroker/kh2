#include "../common/types.h"

#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

// 16-byte vector with a qword copy constructor and a self-checking assignment.
struct QWord {
    union { u32 v[4]; f32 f[4]; };
    QWord() {}
    QWord(const QWord& o) { QCOPY(this, &o); }
    QWord& operator=(const QWord& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

// ---- 00100aa0
namespace n00100aa0 {
struct EhObj { u32 pc_begin, tbase, dbase, u; u64 sorted : 1, from_array : 1, mixed : 1, encoding : 8, count : 21; };
struct EhFde { u32 length; s32 cie; u8 pc_begin[4]; };
extern "C" {
u32 func_00100920(u8, EhObj*);
u8* func_001004c0(u8, u32, u8*, u32*);
// fde_single_encoding_compare: orders two FDEs by their decoded pc_begin.
s32 func_00100aa0(EhObj* ob, EhFde* x, EhFde* y) {
    u32 xp, yp;
    u32 base = func_00100920(ob->encoding, ob);
    func_001004c0(ob->encoding, base, x->pc_begin, &xp);
    func_001004c0(ob->encoding, base, y->pc_begin, &yp);
    if (xp > yp) return 1;
    if (xp < yp) return -1;
    return 0;
}
}
}

// ---- 0011c6a8
namespace n0011c6a8 {
typedef unsigned int u128 __attribute__((mode(TI)));
struct Mtx { u128 q[4]; };
extern "C" {
extern Mtx D_00347b30;
void func_0011d440(void);
void func_0011b6a8(Mtx*);
void func_00125f78(u8*, u32, u32, u32, u32, u32, f32);
// Loads the given matrix (or identity when null) into the shared work matrix, then sets up the object.
void func_0011c6a8(u8* o, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, Mtx* m, f32 f) {
    func_0011d440();
    if (m != 0) {
        if (m != &D_00347b30)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(&D_00347b30), "r"(m) : "$8", "$9", "$10", "$11", "memory");
    } else func_0011b6a8(&D_00347b30);
    func_00125f78(o, a1, a2, a3, a4, a5, f);
    *(u32*)(o + 24) = 0;
    *(u32*)(o + 12) |= 1;
}
}
}

// ---- 00130c18
namespace n00130c18 {
struct AnKey { f32 t; s32 v; };
struct AnTrack { u8 pad0; u8 flag; u8 pad[6]; u16 count; u16 start; };
struct AnData { u8 pad[80]; s32 trackOff; s32 nTracks; s32 keyOff; };
extern "C" {
// Samples every on/off track at time t (binary search over its keys).
void func_00130c18(u8* o, f32 t) {
    AnData* a = *(AnData**)(o + 4);
    AnTrack* tr = (AnTrack*)((u8*)a + a->trackOff);
    AnKey* keys = (AnKey*)((u8*)a + a->keyOff);
    for (s32 i = 0; i < a->nTracks; i++, tr++) {
        if (tr->count == 0) continue;
        s32 lo = tr->start;
        s32 hi = lo + tr->count - 1;
        if (t < keys[lo].t) { tr->flag = keys[lo].v == 0; continue; }
        if (keys[hi].t <= t) { tr->flag = keys[hi].v != 0; continue; }
        while (hi - lo >= 2) {
            s32 mid = (lo + hi) / 2;
            if (t < keys[mid].t) hi = mid;
            else if (keys[mid].t < t) lo = mid;
            else { lo = mid; break; }
        }
        tr->flag = keys[lo].v != 0;
    }
}
}
}

// ---- 00136878
namespace n00136878 {
struct Pos24 { s16 f0, f2, f4, f6, f8, f10; s16 r[6]; };
extern "C" {
extern Pos24 D_003b8b20;
extern u32 D_003b8b38;
extern u32 D_00347d24;
Pos24* func_001aec40(void);
void func_00136840(void);
u32 func_00136778(s32, s32);
u32 func_002bc288(u32, u32);
// Tracks the current position record; reloads when the area/map changes.
void func_00136878(void) {
    u64 unused[2]; // keeps the original's 48-byte frame
    Pos24* p = func_001aec40();
    if (!p) return;
    if (p->f8 == -1) func_00136840();
    else if (p->f8 == D_003b8b20.f8 && p->f4 == D_003b8b20.f4 && p->f6 == D_003b8b20.f6) {}
    else {
        func_00136840();
        D_00347d24 = func_002bc288(func_00136778(p->f6, p->f8), D_003b8b38);
    }
    D_003b8b20 = *p;
}
}
}

// ---- 0013d208
namespace n0013d208 {
struct Pair8 { u32 x, y; };
extern "C" {
extern Pair8 D_00348578[];
s32 func_0013cb80(void);
s32 func_0013cb90(void);
u32 func_0013cb30(void);
void func_001386e0(u8*, u32, u32, s32, u32, u32);
void func_00138c40(u8*, u32, u32);
f32 func_0013b2a8(u8*);
void func_00138d48(u8*, f32, f32, f32, f32);
void func_0013d1d0(u8*);
void func_0013d208(u8* o) {
    s32 a = func_0013cb80();
    u8* s = o + 260;
    s32 b = func_0013cb90();
    a += 32;
    u32 c = func_0013cb30();
    Pair8* e = &D_00348578[b];
    func_001386e0(s, 5301, c, a, e->x, 1);
    func_00138c40(s, 28, 322);
    *(u32*)(s + 392) = e->y;
    f32 r = func_0013b2a8(o);
    func_00138d48(s, 1.0f, 1.0f, 1.0f, r);
    func_0013d1d0(o);
}
}
}

// ---- 0013e0f8
namespace n0013e0f8 {
extern "C" {
void func_001391c8(u8*, u32, u32);
void func_0013ee38(u8*, u32);
void func_0013edd0(u8*, f32);
void func_0013ee18(u8*, u32);
void func_0014b208(u8*, s32, s32);
void func_0013ede0(u8*, s32, s32);
void func_0014b5e0(u8*, u32);
void func_0014b618(u8*, u32);
void func_0013e0f8(u8* o, u32 a1, u32 a2, u32 a3) {
    func_001391c8(o, a1, a3);
    *(u32*)(o + 580) = a2;
    u8* s = o + 32;
    func_0013ee38(s, 4);
    func_0013edd0(s, 0.0f);
    func_0013ee18(s, 0x32001);
    if (!a2) { func_0014b208(s, 100, 100); return; }
    func_0014b208(s, 64, 64);
    func_0013ede0(s, -32, -32);
    func_0014b5e0(o + 320, 6);
    func_0014b618(o + 320, 0x32001);
    func_0014b208(o + 320, 64, 64);
}
}
}

// ---- 0015f8d8
namespace n0015f8d8 {
extern "C" {
extern u8 D_0034c720[];
void func_0015f9c8(u8*, u32, u32, QWord, QWord, QWord, u32, s32, u32, u32, u32);
void func_001433c0(u8*, u32);
// Constructor: base init with three vectors by value, then own vtable and defaults.
void func_0015f8d8(u8* o, u32 a1, const QWord& a, const QWord& b, const QWord& c, u32 t1, u32 t2) {
    func_0015f9c8(o, 0, a1, a, b, c, t1, -1, 0, 0, 0);
    *(u32*)o = (u32)D_0034c720;
    if (!t2) {
        *(u32*)(o + 456) |= 2;
        o[466] = 0x80;
        o[465] = 0x80;
        o[464] = 0x80;
        o[467] = 0xff;
    }
    func_001433c0(o + 448, t2);
    *(u32*)(o + 500) = 0;
    *(u32*)(o + 432) = 1;
    *(u32*)(o + 696) &= ~0x80;
    *(u32*)(o + 696) &= ~0x100;
}
}
}

// ---- 00188958
namespace n00188958 {
struct O9 { u8 pad[18]; u8 count; u8 pad2[33]; u16 a[8]; u16 b[8]; };
extern "C" {
void func_001a3188(u32, u32, u32);
// Resizes a slot list: clears new slots, releases removed ones.
void func_00188958(O9* o, s32 n) {
    s32 i;
    if (o->count < n) {
        for (i = o->count; i < n; i++) {
            o->a[i] = 0;
            o->b[i] = 0;
        }
    } else {
        for (i = n; i < o->count; i++) {
            if (o->a[i]) {
                func_001a3188(o->a[i], 100, 0);
                o->a[i] = 0;
            }
        }
    }
    o->count = n;
}
}
}

// ---- 00194120
namespace n00194120 {
extern "C" {
void func_00194218(u8*, s32, f32);
// Sets a 0..1 level (stored as 0..255) and applies it to the model's parts.
void func_00194120(u8* o, f32 v) {
    f32 c = v < 0.0f ? 0.0f : (1.0f < v ? 1.0f : v);
    o[1696] = (s32)(c * 255.0f);
    u16 type = *(u16*)(*(u8**)(o + 8) + 76);
    if (type != 5000) {
        if (type == 5002) {
            func_00194218(o, 0, 1.0f - c);
            func_00194218(o, 1, c);
        }
    } else {
        for (s32 i = 0; i < 10; i++) func_00194218(o, i, c);
    }
}
}
}

// ---- 0019aa60
namespace n0019aa60 {
extern "C" {
extern u8 D_0034f250;
s32 func_0019a9e0(u8*, u8*);
u32 func_0016bff0(u8*);
void func_001956e8(u8*, u32);
s32 func_0016bf20(u8*);
void func_0019ab80(u8*);
void func_0019aa60(u8* o, u8* e) {
    if (*(u32*)(e + 2040) & 4) {
        if (func_0019a9e0(o, e)) func_001956e8(&D_0034f250, func_0016bff0(e));
    } else {
        func_001956e8(&D_0034f250, func_0016bff0(e));
        s32 r = func_0016bf20(e);
        if (r >= 0 && (r < 2 || r == 3) && (*(u32*)(e + 1416) & 0x800)) func_0019ab80(o);
    }
    *(f32*)(o + 20) = *(u16*)(*(u8**)(o + 8) + 32);
}
}
}

// ---- 001ac108
namespace n001ac108 {
struct W108 { u8 on; u8 b1; u8 mode : 8; };
extern "C" {
extern f32 D_00350a58[4];
void func_0023acd8(u8*);
void func_0023ade0(u8*);
// Positions a child widget relative to (x, y) using the alignment mode.
void func_001ac108(W108* o, s32 x, s32 y, s32 w, s32 h) {
    if (!o->on) return;
    if (o->mode < 4) y -= h / 2;
    else y += h / 2;
    x += (s32)(w * D_00350a58[o->mode & 3]);
    u8* p = (u8*)o + 4;
    func_0023acd8(p);
    *(s32*)(p + 328) = x;
    *(s32*)(p + 332) = y;
    func_0023ade0(p);
}
}
}

// ---- 001b3e88
namespace n001b3e88 {
extern "C" {
s32 func_0018ca48(u8);
void func_00198580(u8*, s32);
void func_001b3e88(u8* o, u8* e) {
    u8* p = *(u8**)(o + 2484);
    s32 id = p ? *(s16*)(p + 2) : -1;
    if (id >= 0) {
        s32 k = -1;
        bool isK = *(u32*)(*(u8**)(o + 12) + 4) == 0x17;
        if (isK) {
            switch ((*(u8**)(e + 32))[43]) {
            case 0: k = 0; break;
            case 1: k = 2; break;
            }
        } else {
            switch (func_0018ca48(e[39])) {
            case 1: case 3: case 5: k = 0; break;
            case 4: k = 2; break;
            }
        }
        if (k >= 0) {
            func_00198580(o, id * 1000 + k + (o[2044] & 1));
            o[2044]++;
        }
    }
}
}
}

// ---- 001c2eb8
namespace n001c2eb8 {
struct CEnt { u16 id; u8 pad[126]; };
struct CTbl { u32 f0; s32 count; CEnt e[1]; };
extern "C" {
extern CTbl* D_01d4955c;
void func_001c2d88(CEnt*);
static inline CEnt* FindC(u32 id) {
    CTbl* t = D_01d4955c;
    s32 n = t->count;
    CEnt* p = t->e;
    for (s32 i = 0; i < n; i++, p++)
        if (p->id == id) return p;
    return 0;
}
void u_call4_001c2eb8(u32, u32, u32, u32) asm("_Z16u_call4_001c2eb8jjjj");
// Runs func_001c2d88 on every consecutive table entry with the given id.
void u_call4_001c2eb8(u32 id, u32, u32, u32) {
    CEnt* p = FindC(id);
    while (p < &D_01d4955c->e[D_01d4955c->count] && p->id == id) {
        func_001c2d88(p);
        p++;
    }
}
}
}

// ---- 001d7880
namespace n001d7880 {
extern "C" {
s32 func_001a6d08(u32);
void func_001a6c90(u32);
s32 func_00181500(u16);
u8* func_00189200(u8*, s32);
extern u16 D_0036e628[];
extern u8 D_0032e020;
extern u8 D_0032f056;
void u_tail0_001d7880(void) asm("_Z16u_tail0_001d7880v");
// Sets flag 104 once all listed conditions are met.
void u_tail0_001d7880(void) {
    if (func_001a6d08(104)) return;
    u16* p = D_0036e628;
    for (u32 i = 0; i < 11; i++)
        if (!func_00181500(*p++)) return;
    for (s32 j = 1; j < 6; j++)
        if (func_00189200(&D_0032e020, j)[2] < 7) return;
    if (D_0032f056 < 7) return;
    func_001a6c90(104);
}
}
}

// ---- 001e7be0
namespace n001e7be0 {
struct E7Ent { u8 pad[36]; void (*fn)(void*, void*); };
struct E7Slot { E7Ent* e; u8 pad[12]; };
struct E7Def { u8 pad[38]; s16 count; E7Slot slots[1]; };
struct E7Obj { E7Def* def; void* cur; u32 f8; u16 refs; };
struct E7Ctx { void* next; u32 f4; E7Obj* obj; };
extern "C" {
extern u32 D_01d9e6e4;
void func_001e7798(u32, E7Ctx*);
void func_001e7be0(E7Ctx* c) {
    E7Obj* ob = c->obj;
    E7Def* d = ob->def;
    for (s32 i = 0; i < d->count; i++) {
        E7Slot* s = &d->slots[i];
        if (s->e && s->e->fn) s->e->fn(c, s);
    }
    if (--ob->refs == 0) ob->cur = 0;
    else if (ob->cur == c) ob->cur = c->next;
    func_001e7798(D_01d9e6e4, c);
}
}
}

// ---- 00245ce8
namespace n00245ce8 {
struct VObj { void (**vt)(VObj*); };
extern "C" {
extern VObj* D_0035ed28;
extern VObj* D_0035ed2c;
extern VObj* D_0035ed30;
extern void* D_0035ed20;
extern void* D_0035ed24;
s32 func_00139d78(void*);
s32 func_0028acc8(void*);
void func_0028abe0(void*);
void func_00246f80(void);
u32 func_00287dc0(void);
void func_0023d820(u32);
void func_00247bb0(void);
void func_00245ce8(void) {
    if (func_00139d78(D_0035ed28)) D_0035ed28->vt[5](D_0035ed28);
    if (func_00139d78(D_0035ed30)) D_0035ed30->vt[5](D_0035ed30);
    if (func_00139d78(D_0035ed2c)) D_0035ed2c->vt[5](D_0035ed2c);
    if (func_0028acc8(D_0035ed20)) func_0028abe0(D_0035ed20);
    if (func_0028acc8(D_0035ed24)) func_0028abe0(D_0035ed24);
    func_00246f80();
    func_0023d820(func_00287dc0());
    func_00247bb0();
}
}
}

// ---- 0024fd28
namespace n0024fd28 {
struct Tbl6 { s16 a, b, c; };
extern "C" {
extern void* D_0035ee3c;
extern void* D_0035ee34;
extern void* D_0035ee44;
extern void* D_0035ee40;
extern Tbl6 D_00372448[];
s32 func_00139d78(void*);
s32 func_0028acc8(void*);
s32 func_002891e8(u32);
s32 func_0023f0c0(void*);
void func_0023f070(void*, s32, s32);
void func_0028ab20(void*);
void func_0024fd28(void) {
    if (func_00139d78(D_0035ee3c)) {
        if (func_0023f0c0(D_0035ee3c) != 32) func_0023f070(D_0035ee3c, 32, -1);
    }
    if (func_0028acc8(D_0035ee34)) {
        func_0028ab20(D_0035ee34);
        s32 i = func_002891e8((u32)D_0035ee34);
        if (func_00139d78(D_0035ee44)) {
            if (func_0023f0c0(D_0035ee44) != D_00372448[i].c) func_0023f070(D_0035ee44, D_00372448[i].c, -1);
        }
    }
    if (func_00139d78(D_0035ee40)) {
        if (func_0023f0c0(D_0035ee40) != 35) func_0023f070(D_0035ee40, 35, -1);
    }
}
}
}

// ---- 00252d88
namespace n00252d88 {
extern "C" {
extern void* D_0035eea4;
extern s16* D_0035ee90[3];
s32 func_00139d78(void*);
s32 func_0023f0c0(void*);
s32 func_00287bc0(void);
void func_00287bd0(s32, s32);
void func_00252d88(void) {
    s32 idx = 0;
    func_00139d78(D_0035eea4);
    s32 v = func_0023f0c0(D_0035eea4);
    if (v != 0) {
        if (v == 1) idx = 4;
        else {
            idx = -1;
            for (s32 i = 0; i < 3; i++) {
                s16* p = D_0035ee90[i];
                for (s32 j = 0; j < 3; j++) {
                    if (v == p[j]) { idx = i + 1; break; }
                }
                if (idx >= 0) break;
            }
        }
    }
    if (func_00287bc0() != idx) func_00287bd0(idx, 0);
}
}
}

// ---- 00257388
namespace n00257388 {
struct VObj2 { void (**vt)(VObj2*); };
struct Pt8 { s16 x, p, y, q; };
extern "C" {
extern u32 D_0035f034;
extern Pt8 D_00372a00;
extern Pt8 D_00372a08;
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern u32 D_0035f03c;
s32 func_00139d78(void*);
void func_0028d980(u32, u32, u32, u32, u32, s32, s32, u32, u32);
void func_00139620(u32);
void func_00257388(u32 a0, s32 a1) {
    if (func_00139d78((void*)D_0035f034)) ((VObj2*)D_0035f034)->vt[5]((VObj2*)D_0035f034);
    Pt8* t = !a1 ? &D_00372a00 : &D_00372a08;
    func_0028d980(D_0035f034, 30022, D_0035ef68, D_0035ef64, D_0035f03c, t->x, t->y, a0, 0);
    func_00139620(D_0035f034);
    *(u32*)(D_0035f034 + 432) = 2;
    u32 s = D_0035f034 + 24;
    *(u32*)(s + 184) |= 8;
}
}
}

// ---- 0026a9f8
namespace n0026a9f8 {
extern "C" {
extern u32 D_0035f01c;
extern u32 D_0035f0ec;
s32 func_00287bc0(void);
s32 func_0028b160(u32, u8*);
s32 func_0028b038(u32);
u8* func_00281f30(u32);
void func_001a98e8(u8*, u32, u8*, u32, u32);
s32 func_0023aa18(u8*);
s32 func_0023aa38(u8*);
u32 func_0023a918(u8*);
void func_001a9ae8(u8*, s32, s32, u32);
void func_0026a9f8(s32 x, s32 y, u32 a2, u32 a3, u8* o) {
    u8 buf[96];
    s32 m = func_00287bc0();
    s32 n = func_0028b160(D_0035f01c, o);
    bool b = (u32)(m - 5) < 2;
    s32 k = func_0028b038(D_0035f01c);
    u8* base = func_00281f30(D_0035f0ec);
    if (!b && !k) {
        if (n == 0) return;
        n--;
    }
    func_001a98e8(buf, 1, base + n * 80, *(u32*)(o + 424), 1);
    s32 px = func_0023aa18(o + 24) + x;
    s32 py = func_0023aa38(o + 24) + y;
    func_001a9ae8(buf, px, py, func_0023a918(o + 24));
}
}
}

// ---- 0027f3d8
namespace n0027f3d8 {
struct FnHolder { u32 f0; void (*fn)(void); };
extern "C" {
s32 func_00287bc0(void);
s32 func_00287db0(void);
s32 func_0027f2b0(void);
s32 func_00253918(void);
FnHolder* func_001040f8(void);
s32 func_00242a00(void);
void func_0023d1d0(void);
void func_0023d1e0(void);
void func_001039f8(void);
void func_0027f7f0(void);
void func_0027f9d8(void);
s32 func_0027f3d8(void) {
    if (func_00287db0()) {
        if (func_0027f2b0()) return 0;
        if (func_00253918()) return 0;
        func_001040f8()->fn();
        if (func_00242a00()) func_0023d1d0();
        else func_0023d1e0();
        func_001039f8();
        return 1;
    }
    s32 m = func_00287bc0();
    if (m != 0) {
        if (m == 1) func_0027f9d8();
    } else func_0027f7f0();
    return 0;
}
}
}

// ---- 00283668
namespace n00283668 {
extern "C" {
extern u8* D_0035f2b8;
s32 func_00139d78(void*);
// True when every active sub-object is in its expected state.
s32 func_00283668(void) {
    s32 ok = 1;
    if (func_00139d78(D_0035f2b8 + 852) && *(s32*)(D_0035f2b8 + 1240) != 0x13) ok = 0;
    if (ok) {
        if (func_00139d78(D_0035f2b8 + 416) && *(s32*)(D_0035f2b8 + 804) != 0x10) ok = 0;
        if (ok) {
            if (func_00139d78(D_0035f2b8 + 1288) && *(s32*)(D_0035f2b8 + 1676) != 2) ok = 0;
            if (ok) {
                if (func_00139d78(D_0035f2b8 + 1696) && *(s32*)(D_0035f2b8 + 2084) != 5) ok = 0;
            }
        }
    }
    return ok;
}
}
}

// ---- 002aaf40
namespace n002aaf40 {
struct Tbl { u8 pad[8]; s32 count; u32 pad2; };
struct Bits148 { u8 pad[148]; u32 bits[1]; };
struct Ent16 { u16 id; u8 pad[14]; };
static inline bool BitTest(u32* b, u32 i) { return b[i >> 5] & (1 << (i & 31)); }
extern "C" {
extern Bits148* D_0035f610;
Bits148* func_002a9d68(void);
Tbl* func_00294000(s32);
s32 func_002aad58(s32);
s32 func_002aaf40(s32 id) {
    s32 r = 1;
    Bits148* g = func_002a9d68();
    Tbl* t = func_00294000(8);
    Ent16* e = (Ent16*)(t + 1);
    if (id < 0) r = func_002aad58(-1);
    else {
        s32 n = t->count;
        for (u32 i = 0; (s32)i < n; i++, e++) {
            if (e->id != id) continue;
            if (BitTest(D_0035f610->bits, i)) {
                r = BitTest(g->bits, i);
                if (!r) break;
            }
        }
    }
    return r;
}
}
}

// ---- 002b3ef0
namespace n002b3ef0 {
struct Heap { void (**vt)(Heap*, void*); };
struct HeapHolder { u8 pad[20]; Heap* heap; };
extern "C" HeapHolder* D_00347f80;
struct Elem76 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~Elem76();
    u8 pad[72];
    static void operator delete[](void* p) { D_00347f80->heap->vt[1](D_00347f80->heap, p); }
};
struct VB { void (**vt)(VB*); };
struct Res3 { VB* a; Elem76* arr; VB* c; };
extern "C" {
// Releases the three owned resources.
void func_002b3ef0(Res3* r) {
    if (r->a) { r->a->vt[4](r->a); r->a = 0; }
    if (r->arr) {
        delete[] r->arr;
        r->arr = 0;
    }
    if (r->c) { r->c->vt[4](r->c); r->c = 0; }
}
}
}

// ---- 002d2a90
namespace n002d2a90 {
struct VO { void (**vt)(VO*, s32, s32, VO*, s32); };
extern "C" {
void* func_0016abf8(VO*, s32, s32, s32);
QWord* func_001dc5f8(void*);
QWord func_0016bda8(VO*);
void func_002d2a90(VO* o) {
    s32 st = *(s32*)((u8*)o + 2924);
    if (st < 0) return;
    if (st == 0) {
        o->vt[20](o, 1548, 0, o, 0);
    } else {
        o->vt[20](o, 1549, 0, o, 0);
        void* x = func_0016abf8(o, 1, 1, 0);
        if (x) *func_001dc5f8(x) = func_0016bda8(o);
    }
    *(u32*)((u8*)o + 2876) = 0;
}
}
}

// ---- 002e66f0
namespace n002e66f0 {
struct KEnt { u8 pad[12]; u32 loop : 1; u32 rest : 31; u8 pad2[12]; f32 t; };
struct KHdr { u32 f0; s32 count; u8 pad[8]; KEnt e[1]; };
extern "C" {
// Finds the key segment containing t: index of the left key and the blend fraction.
void func_002e66f0(KHdr* h, s32* idx, f32* frac, f32 t) {
    s32 n = h->count;
    if (h->e[0].t >= t) { *idx = 0; goto zero; }
    if (h->e[n - 1].t <= t) { *idx = n - 1; goto zero; }
    {
        s32 hi = n - 1, lo = 0;
        while (hi - lo >= 2) {
            s32 mid = (hi - lo) / 2 + lo;
            f32 m = *(f32*)((u8*)h + (mid << 5) + 44);
            if (t == m) { *idx = mid; goto zero; }
            if (*(f32*)((u8*)h + (lo << 5) + 44) < t && t <= m) hi = mid;
            else lo = mid;
        }
        *idx = lo;
        if (h->e[lo].loop) goto zero;
        *frac = (t - h->e[lo].t) / (h->e[hi].t - h->e[lo].t);
        return;
    }
zero:
    *frac = 0.0f;
}
}
}

// ---- 00145ab8
namespace n00145ab8 {
struct E880 { void (**vt)(E880*); u8 pad[876]; };
struct Q16 { u8 d[16]; };
struct E80 { Q16 q[5]; };
// Local whose (empty) destructor keeps the final call from becoming a tail call.
struct NoTail { ~NoTail() {} };
extern "C" {
extern u8 D_0034c6e0[];
extern u8 D_00349dc0[];
extern u8 D_00348d58[];
void func_0031bab8(u8*);
void func_0031baa8(u8*);
void func_001070e8(u8*);
void func_00106ac8(u8*);
// Destructor body: member arrays destroyed back to front, then members and bases.
void func_00145ab8(u8* o) {
    NoTail nt;
    if (o + 3168 != 0) {
        E880* p = (E880*)(o + 3168) + 16;
        E880* b = (E880*)(o + 3168);
    top1:
        if (b != p) { p--; p->vt[0](p); goto top1; }
    }
    *(u32*)(o + 1936) = (u32)D_0034c6e0;
    func_0031bab8(o + 2352);
    *(u32*)(o + 2080) = (u32)D_00349dc0;
    func_0031baa8(o + 2080);
    *(u32*)(o + 1936) = (u32)D_00348d58;
    if (o + 624 != 0) {
        E80* p = (E80*)(o + 624) + 16;
        E80* b = (E80*)(o + 624);
    top2:
        if (b != p) {
            p--;
            Q16* a = (Q16*)p;
            if (a != 0) {
                Q16* q = a + 5;
            top3:
                if (a != q) { q--; goto top3; }
            }
            goto top2;
        }
    }
    func_001070e8(o + 288);
    func_00106ac8(o + 32);
}
}
}

// ---- 00163568
namespace n00163568 {
static inline QWord operator-(const QWord& a, const QWord& b)
{
    QWord r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(&r), "r"(&a), "r"(&b) : "memory");
    return r;
}
static inline void Cross(QWord* r, const QWord& a, const QWord& b)
{
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)"
                 : : "r"(r), "r"(&a), "r"(&b) : "memory");
}
static inline f32 Normalize(QWord* v)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
                 : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline f32 Dot(const QWord& a, const QWord& b)
{
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0"
                 : "=f"(r) : "r"(&a), "r"(&b) : "$8");
    return r;
}
struct Plane { f32 x, y, z, d; };
extern "C" {
// Plane through three points: unit normal and signed distance.
void func_00163568(Plane* out, const QWord& p0, const QWord& p1, const QWord& p2) {
    QWord e1, e2, n;
    e1 = p1 - p0;
    e2 = p2 - p0;
    Cross(&n, e1, e2);
    Normalize(&n);
    out->x = n.f[0];
    out->y = n.f[1];
    out->z = n.f[2];
    out->d = -Dot(n, p0);
}
}
}

// ---- 0031dc78
namespace n0031dc78 {
struct E256 { void (**vt)(E256*); u8 pad[252]; };
extern "C" {
extern u8 D_0034af08[];
extern u8 D_00349b40[];
extern u8 D_00347f98[];
void func_0031bbc8(u8*);
void func_0031b910(u8*);
void func_0031bb08(u8*);
// Destructor body: own vtable, inlined member destructor (two arrays, members, base), base vtable.
void func_0031dc78(u8* o) {
    *(u32*)o = (u32)D_0034af08;
    u8* m = o + 48;
    if (m + 1904 != 0) {
        E256* p = (E256*)(m + 1904) + 4;
        E256* b = (E256*)(m + 1904);
    top1:
        if (b != p) { p--; p->vt[0](p); goto top1; }
    }
    if (m + 880 != 0) {
        E256* p = (E256*)(m + 880) + 4;
        E256* b = (E256*)(m + 880);
    top2:
        if (b != p) { p--; p->vt[0](p); goto top2; }
    }
    func_0031bbc8(m + 624);
    func_0031b910(m + 336);
    *(u32*)m = (u32)D_00349b40;
    func_0031bb08(m);
    *(u32*)o = (u32)D_00347f98;
}
}
}

// ---- 0015aba8
namespace n0015aba8 {
extern "C" {
extern u8 D_0032bae0;
void func_002362b0(u8*);
void func_002367c8(u8*);
s32 func_00105c30(void);
s32 func_00241ed8(u8);
void func_001386e0(u8*, u32, u32, s32, u32, u32);
void func_0015aba8(u8* o, u32 a1, u32 a2) {
    u8* s = o + 416;
    s32 skip = 0;
    s32 x = 0;
    func_002362b0(s);
    func_002367c8(s);
    if (func_00105c30() == 1 || func_00105c30() == 8) skip = 1;
    if (!(u8)skip) x = func_00241ed8(D_0032bae0) != 0;
    func_001386e0(o, 20000, a2, (s32)s, x, 0);
}
}
}

// ---- 001cea48
namespace n001cea48 {
struct Cea { s32 state; u32 b0 : 1; u32 b1 : 1; u32 rest : 30; };
extern "C" {
void func_002877a0(u8*, u32, u32);
void func_001cea48(Cea* o, u8* e, u64* pad) {
    u64 b = *pad;
    if ((b & (1ULL << 34)) && (u8)o->b0) {
        func_002877a0((u8*)o + 12, 0, 3);
        if (o->b1) func_002877a0((u8*)o + 12, 1, 4);
        *(s32*)(e + 2928) = 1;
        o->state = 3;
    } else if ((b & (1ULL << 35)) && o->b1) {
        func_002877a0((u8*)o + 12, 1, 3);
        if ((u8)o->b0) func_002877a0((u8*)o + 12, 0, 4);
        *(s32*)(e + 2928) = 2;
        o->state = 3;
    }
}
}
}

// ---- 00244e28
namespace n00244e28 {
extern "C" {
extern u32 D_0035ece8;
extern s8 D_0035ed14;
extern u8* D_0035ed04;
s32 func_002891e8(u32);
s32 func_00244ee8(s32);
s32 func_00139d78(void*);
void func_00138c10(u8*, s32);
void func_00243230(s32, s32);
void func_00244e28(void) {
    s32 i = func_002891e8(D_0035ece8);
    s32 b = func_00244ee8(i);
    u8 off = !((D_0035ed14 >> b) & 1);
    if (off) return;
    if (func_00139d78(D_0035ed04 + i * 408)) {
        u8* e = D_0035ed04 + i * 408;
        if (*(s32*)(e + 388) != 37) func_00138c10(e, 37);
    }
    func_00243230(3, b);
}
}
}

// ---- 002a4a00
namespace n002a4a00 {
struct Slot8 { u8 b0, b1; u8 pad[6]; };
struct A4 { u8 pad[4096]; Slot8 s[1]; };
struct A4h { u8 pad[4228]; s32 base; s32 bits; };
extern "C" {
extern u8* D_0035f5e4;
s32 func_002a4990(s32);
s32 func_002a4a00(s32 i) {
    if (i < 0) i = ((A4h*)D_0035f5e4)->base + ((A4h*)D_0035f5e4)->bits / 8;
    s32 n = func_002a4990(i);
    s32 sum = 0;
    for (s32 j = 0; j < n; j++) sum += ((A4*)D_0035f5e4)->s[j].b1;
    Slot8* e = (Slot8*)((u32)n * 8 + (u32)D_0035f5e4 + 4096);
    s32 r = 8;
    if (!(i - sum < e->b1 - 1)) {
        u8 b = e->b0;
        r = b & 7;
        if (!r) r = b ? 8 : 1;
    }
    return r;
}
}
}
