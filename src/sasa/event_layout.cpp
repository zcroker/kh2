// sa::EVENT layout, tag, treasure, light and screen commands. Linked unit 0x22c4b8-0x22cf18.
#include "../common/types.h"

struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Seg { V4 a, b; };

struct W291S22 { u8 pad[4]; s16 a; s16 b; s16 c; };
struct W291W22 { s32 x; };

struct Ent { s16 id; s16 start; s16 end; s16 f6; u8 data[84]; };
struct Tbl { u32 f0; s16 n; s16 f6; Ent e[1]; };
struct Act { u8 p0[1704]; s32 f1704; u8 p1708[196]; void* f1904; };
union AP { Act* p; s32 i; };
struct Obj { u8 p0[8]; AP act; };

struct C22cc38 { u8 pad[4]; s16 id; s16 v; u16 type; };

struct S4 {
    s32 a;
    s16 h;
    u8 b6;
    u8 b7;
    u8 p8[4];
};

namespace dk { struct TREASURE_INFO { static void openEventInfo(int); }; }

extern "C" {
void func_002fee78(char*, const char*, ...);  // sprintf
void func_002ff3fc(char*);
void func_00170518(char*, s32, s32);
s32 func_002282f0(s32);
s32 func_00225b00(s32);
void func_00153f08(char*, u16);
s32 func_001de168(W291W22*, s32, s32, s32, s32, s32);
s32 func_001dc9d0(s32);
s32 func_001dc9e0(s32);
s32 func_001dc7e8(s32);
void func_001dc840(s32);
void func_001dc920(s32);
void func_001dc978(s32, f32);
s32 func_001de4b0(W291W22*, s32, s32);
s32 func_00227ca8(void*);
void func_00144490(Seg*, f32, f32, f32, f32, f32, f32);
void func_001d6790(Seg*);
void func_001024a8(void*);
void func_001991a8(s32, s32);
void func_002249f8(s32);
u32 func_002282d8(void);
u8* func_00102c18(s32, u32, void*);
void func_001a84f0(void);
Obj* func_00227d10(s32);
s32 func_001ba028(Act*);
s32 func_00227d58(s32);
u32 func_001050c8(void);
u8* func_001063c0(s32, u32);
void func_0023cd68(u8*);
void func_0023cde8(u8*);
s32 func_0023d240(u8*);
s32 func_0014ac08(void);
s32 func_0014abd8(void);
s32 func_0014aba8(void);
void func_0014aa58(s32, s32, s32);
void func_0014aa80(s32, s32, s32);
void func_0014a768(u8);
void func_0014a788(u16, u16);
f32 func_00227c78(u8*);
void func_0014a7b8(s16, f32);
void func_0014a7e8(s32);
void func_0014a7f8(s32);
void func_00191a20(void);
void func_00191a38(void);
void func_0015e018(void);
void func_0015e038(void);
void func_001671e8(s32, s32);
void func_00167218(void);
}

extern u32 D_0033caf4;
extern W291W22* D_0035de84;
extern s32 D_0035de88;
extern u32 D_0035de8c;
extern Tbl* D_0035de50;
extern s32 D_0035de20;
extern f32 D_00349e10;

static char D_01dad960[48] asm("D_01dad960");

char* func_0022c4b8(char* name) {
    func_002fee78(D_01dad960, "event/layout/%s/%s.2ld", D_0033caf4, name);
    func_002ff3fc(D_01dad960);
    return D_01dad960;
}

void func_0022c508(char* name) {
    func_00170518(func_0022c4b8(name), -200, 0);
}

void func_0022c530(u8* a0) {
    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (func_00225b00(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    func_00153f08(func_0022c4b8((char*)(a0 + 8)), *(u16*)(a0 + 6));
}

s32 func_0022c758(void);

void func_0022c590(W291S22* s) {
    if (func_002282f0(s->a)) return;
    if (func_00225b00(s->a)) return;
    W291W22* w = D_0035de84;
    if (!w) return;
    if (!w->x) return;
    switch (s->c) {
    case 0:
        D_0035de88 = func_001de168(w, s->b, 1, 3, 0x9c41, 0);
        break;
    case 1:
        if (D_0035de88 && func_0022c758() && func_001dc9d0(D_0035de88) && func_001dc9e0(D_0035de88) && func_001dc7e8(D_0035de88))
            func_001dc840(D_0035de88);
        break;
    case 2:
        if (D_0035de88 && func_0022c758() && func_001dc9d0(D_0035de88) && func_001dc9e0(D_0035de88))
            func_001dc978(D_0035de88, 8.0f);
        break;
    case 3:
        if (D_0035de88 && func_0022c758() && func_001dc9d0(D_0035de88) && func_001dc9e0(D_0035de88))
            func_001dc920(D_0035de88);
        break;
    }
}

s32 func_0022c758(void) {
    s32 v = 0;
    while ((v = func_001de4b0(D_0035de84, 0, v)) != 0) {
        if (D_0035de88 == v) return 1;
    }
    return 0;
}

void func_0022c8f8(s32 a);

void func_0022c7c0(u8* a0) {
    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (func_00225b00(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    s32 v0 = func_00227ca8(a0 + 8);
    if (v0 >= 100) {
        func_0022c8f8(v0);
        return;
    }
    u32 fp = D_0035de8c;
    if (fp == 0) {
        return;
    }
    ((void (*)(s32))fp)(v0);
}

void func_0022c840(u8* p) {
    Seg s;
    f32 z = 0.0f;
    f32 y = *(f32*)(p + 8);
    func_00144490(&s, -18000.0f, z, y - 187.5f, 18000.0f, z, y + 187.5f);
    func_001d6790(&s);
    *(f32*)(p + 8) -= 375.0f;
    *(f32*)(p + 4) -= D_00349e10;
    if (*(f32*)(p + 4) < z) func_001024a8(p);
}

void func_0022c8f8(s32 a) {
    switch (a) {
    case 101: func_001991a8(135, 0); break;
    case 100: func_002249f8(135); break;
    case 200: {
        u8* o = func_00102c18(1, func_002282d8(), (void*)func_0022c840);
        *(f32*)(o + 4) = 64.0f;
        *(f32*)(o + 8) = -6850.0f;
        break;
    }
    }
}

void func_0022c998(u8* a0) {
    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (func_00225b00(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    func_001a84f0();
    dk::TREASURE_INFO::openEventInfo(*(u16*)(a0 + 6));
}

void func_0022c9f0(u32 a0) { D_0035de50 = (Tbl*)a0; }

void func_0022ca00(void) {
    Tbl* t = D_0035de50;
    if (!t) return;
    s32 cur = D_0035de20;
    Ent* e = t->e;
    s32 n = t->n;
    for (s32 i = 0; i < n; i++, e++) {
        s32 a = e->start;
        void* d = e->data;
        s32 b = e->end;
        if (func_00225b00(a)) continue;
        if (cur < a) continue;
        if (!(cur < b)) continue;
        Obj* o = func_00227d10(e->id);
        if (!o || !o->act.p) continue;
        if (!func_001ba028(o->act.p)) continue;
        s32 v = func_00227d58(e->id);
        o->act.p->f1704 = v;
        o->act.p->f1904 = d;
    }
}

void func_0022cba0(u8* a0);
void func_0022cc08(u8* a0);

void func_0022cae8(u8* p) {
    if (func_002282f0(*(s16*)(p + 4))) return;
    if (func_00225b00(*(s16*)(p + 4))) return;
    u8* o = func_00102c18(1, func_002282d8(), (void*)func_0022cba0);
    *(void**)(o + 48) = (void*)func_0022cc08;
    u8* z = func_001063c0(4, func_001050c8());
    func_0023cd68(z);
    *(u8**)(o + 8) = z;
    func_0023cde8(p + 8);
}

void func_0022cba0(u8* a0) {
    u8* p = *(u8**)(a0 + 8);
    if (func_0023d240(a0) != 0) {
        return;
    }
    if (p != 0) {
        (*(void (**)(u8*))(*(u8**)p + 4))(p);
    }
    *(u32*)(a0 + 8) = 0;
    func_001024a8(a0);
}

void func_0022cc08(u8* a0) {
    u8* p = *(u8**)(a0 + 8);
    if (p != 0) {
        (*(void (**)(u8*))(*(u8**)p + 4))(p);
    }
}

void func_0022cc38(C22cc38* c) {
    if (func_002282f0(c->id)) return;
    switch (c->type) {
    case 0: func_0014aa80(func_0014ac08(), c->v, 0); break;
    case 1: func_0014aa58(func_0014ac08(), c->v, 0); break;
    case 2: func_0014aa58(func_0014ac08(), c->v, 1); break;
    case 3: func_0014aa80(func_0014abd8(), c->v, 0); break;
    case 4: func_0014aa58(func_0014abd8(), c->v, 0); break;
    case 5: func_0014aa80(func_0014ac08(), c->v, 1); break;
    case 6: func_0014aa58(func_0014aba8(), c->v, 1); break;
    case 7: func_0014aa80(func_0014aba8(), c->v, 1); break;
    }
}

void func_0022cd48(u8* o) {
    if (func_002282f0(*(s16*)(o + 4))) return;
    s32 a;
    if (!o[6]) {
        func_0014a768(o[7]);
        func_0014a788(*(s16*)(o + 12) >> 1, *(s16*)(o + 14) >> 1);
        if (func_00227c78(o + 8) != 0.0f) func_0014a7b8(*(s16*)(o + 16), func_00227c78(o + 8));
        func_0014a7e8(1);
        a = 1;
    } else a = 0;
    func_0014a7f8(a);
}

void func_0022ce00(u8* a0) {
    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (*(u8*)(a0 + 6) == 0) {
        func_00191a20();
    } else {
        func_00191a38();
    }
}

void func_0022ce50(u8* a0) {
    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (*(u8*)(a0 + 6) == 0) {
        func_0015e018();
    } else {
        func_0015e038();
    }
}

void func_0022cea0(S4* p) {
    int new_var;
    if (func_002282f0(p->h) == 0) {
        if (p->b6 == 0) {
            u8 b = p->b7;
            new_var = b == 0;
            func_001671e8(func_00227ca8(&p->p8), new_var);
        } else {
            func_00167218();
        }
    }
}

// ---- effect (pax) commands
struct EFFECT {
    s32 a, b, c, d, e, f;
    EFFECT() { a = 0; b = 0; c = 0; d = 0; e = 0; f = 0; }
    ~EFFECT() {}
};
static EFFECT D_01dad990 asm("D_01dad990");

union UUd098 { f32* p; s16 h; u32 u; u8 c; };
struct P22d098 { u8 pad[4]; s16 h4; s16 h6; u8 x8[4]; u8 x12[4]; };

extern "C" {
s32 func_002f1670(void*);
void func_002f1460(void*, s32, f32, f32, f32, f32);
s32 func_0014f0e0(void*);
void func_0015c880(f32);
void func_00106420(void*);
void func_0014f030(f32*, f32, f32, f32);
void func_0015c958(u32, u8, u8, u8, u8, u8);
void func_0015f700(void);
void func_0015f6e8(void);
void func_001b9ee8(s32);
void func_001b9f80(s32);
}

void func_0022cf18(u8* a) {
    if (!func_002f1670(&D_01dad990)) func_001024a8(a);
}

void func_0022cf60(s16* p) {
    if (func_002282f0(p[2])) return;
    if (func_00225b00(p[2])) return;
    f32 h = (f32)p[6];
    func_002f1460(&D_01dad990, p[7], (f32)p[3], (f32)p[4], (f32)p[5], h + h);
    func_00102c18(1, 29999, (void*)func_0022cf18);
}

void func_0022d000(u8* a0) {
    u8* s = *(u8**)(a0 + 8);
    if (func_0014f0e0(s) != 0) {
        goto done;
    }
    func_0015c880(*(f32*)s);
    func_00106420(s);
    *(u32*)(a0 + 8) = 0;
    func_001024a8(a0);
    return;
done:
    func_0015c880(*(f32*)s);
}

void func_0022d068(u8* a0) {
    void* p = *(void**)(a0 + 8);
    if (p == 0) {
        return;
    }
    func_00106420(p);
}

void func_0022d098(P22d098* p) {
    if (func_002282f0(p->h4)) return;
    s32 id = func_002282d8();
    if (!func_00225b00(p->h4)) {
        u8* s1 = func_00102c18(1, id, (void*)func_0022d000);
        *(void**)(s1 + 48) = (void*)func_0022d068;
        f32* o = (f32*)func_001063c0(12, func_001050c8());
        ((UUd098*)o)[0].u = 0; ((UUd098*)o)[1].u = 0; o[2] = 1.0f;
        ((UUd098*)(s1 + 8))->p = o;
        f32 a = ((UUd098*)&p->h6)->h;
        f32 x = func_00227c78(p->x8);
        a = a + a;
        func_0014f030(o, x, func_00227c78(p->x12), a);
    } else {
        func_0015c880(func_00227c78(p->x12));
    }
}

void func_0022d1d8(u8* p) {
    if (func_002282f0(*(s16*)(p + 4))) return;
    u32 v = func_00227ca8(p + 8);
    func_0015c958(v, p[12], p[13], p[14], p[6], p[7]);
}

void func_0022d238(u8* a0) {
    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (*(s16*)(a0 + 6) == 0) {
        func_0015f700();
    } else {
        func_0015f6e8();
    }
}

void func_0022d288(u8* a0) {
    if (func_002282f0(*(s16*)(a0 + 4)) != 0) {
        return;
    }
    if (*(s16*)(a0 + 6) == 0) {
        func_001b9ee8(2000);
        return;
    }
    func_001b9f80(2000);
}
