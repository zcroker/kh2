#include "../common/types.h"
struct W291S22 { u8 pad[4]; s16 a; s16 b; s16 c; };
struct W291W22 { s32 x; };
struct W291P28 { s32 x0; s8 a[9]; s8 b13; s8 b14; };
struct W291T28 { u8 pad[6]; u8 f6; u8 pad7; };
struct W291Q28 { u8 pad[8]; u64 flags; };
struct W291C17 { u8 pad[19]; u8 b19; u8 b20; };
struct W291B17 { u8 pad[4]; u32 f4; u8 pad8[32]; W291C17* p40; };
struct W291D17 { u8 pad[8]; u32 f8; };
struct W291A17 { u8 pad[12]; W291D17* p12; u8 pad16[248]; union { u32 f264; W291B17* f264p; }; u8 pad268[84]; u32 f352; u8 pad356[1060]; u32 f1416; };
struct W291Mtx2d {
    u32 m[16];
    W291Mtx2d& operator=(const W291Mtx2d& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W291K2d { u8 pad[8]; u8 b8; };
struct W291R2d { u8 pad[3077]; u8 b3077; };
struct W291O2d {
    u8 pad0[160]; s32 f160; s32 f164; u8 pad168[4]; f32 f172; u8 pad176[8]; W291K2d* p184;
    u8 pad188[8]; s32 f196; u8 pad200; u8 b201; u8 pad202[6];
    W291Mtx2d m208; W291Mtx2d m272; W291Mtx2d m336; W291Mtx2d m400; u8 b464; u8 pad465[15]; u8 b480;
};
extern "C" {





extern W291W22* D_0035de84;
extern s32 D_0035de88;
s32 func_002282f0(s32); s32 func_00225b00(s32); s32 func_0022c758();
s32 func_001de168(W291W22*, s32, s32, s32, s32, s32);  // scan_list_by_half
s32 func_001dc9d0(s32); s32 func_001dc9e0(s32); s32 func_001dc7e8(s32);
void func_001dc840(s32); void func_001dc920(s32); void func_001dc978(s32, f32);
void func_0022c590(W291S22* s)
{
    if (func_002282f0(s->a)) return;
    if (func_00225b00(s->a)) return;
    W291W22* w = D_0035de84;
    if (!w) return;
    if (!w->x) return;
    switch (s->c) {
    case 0:
        D_0035de88 = func_001de168(w, s->b, 1, 3, 0x9c41, 0);  // scan_list_by_half
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

extern u8 D_0035f0b0;
s32 func_00240ba0(); s32 func_00287cd0(); s32 func_002b4ff8(); void func_00287cc0(s32);
s32 func_00241a48(); void func_00287bd0(s32, s32); s32 func_00287d30();
s32 func_00240430(); void func_00240118(s32, s32, s32); void func_00241450(s32); void func_00287d20(s32);
s32 func_00233e70(s32); s32 func_00234798(); s32 func_00234758(); void func_00240e10(s32);
void func_002b5108(s32, s32); void func_002b4c88(s32); s32 func_00241a88(s32); void func_00241a60();
s32 func_00288040(); void func_00288018();  // global_zero_4dwords
void func_0025b050()
{
    s32 r;
    s32 a = func_00240ba0();
    s32 st = func_00287cd0();
    if (st == 2) return;
    if (!func_002b4ff8()) return;
    if (st == 0) func_00287cc0(1);
    if (!func_00241a48()) { func_00287bd0(21, 0); return; }
    switch (func_00287d30()) {
    case 90:
        func_00240118(func_00240430(), 0, 1);
        func_00241450(0);
        func_00287d20(91);
        break;
    case 91:
        if (func_00233e70(0)) break;
        if (func_00234798()) goto give;
        func_00240e10(-4);
        func_00287d20(92);
        break;
    case 92: {
        if (func_00233e70(0)) break;
        r = func_00234758();
        if (r == 0) { func_00287d20(93); break; }
        if (r == 1) goto fail;
    give:
        func_002b5108(0x8a8c, a);
        func_00287bd0(7, 0);
        func_002b4c88(0);
        D_0035f0b0 = 0;
        break;
    }
    case 93:
        if (!func_00241a88(1)) {
    fail:
            func_00241a60();
        }
        func_00287bd0(21, 0);
        break;
    }
    if (func_00288040()) func_00288018();
}

extern W291P28* D_0035f2b4;
extern W291T28 D_003742c8[];
W291Q28* func_00167f18(s32); s32 func_00287cd0(); s32 func_002839f0(s32); s32 func_00283618();
void func_00284048(); void func_00283f50(); void func_002833f8(); void func_00287cc0(s32);
void func_00257708(s32); void func_00283c50(); void func_00287bd0(s32, s32); void func_002937c0(s32);
s32 func_00170cd0(); void func_00283fb0(); void func_00283790(); s32 func_00283668();
void func_00242618(s32, s32); void func_00283e48();
void func_00283230()
{
    W291Q28* q = func_00167f18(0);
    s32 st = func_00287cd0();
    if (st == 2) {
        W291P28* p = D_0035f2b4;
        s32 i = p->b14;
        s32 r;
        if (i + 1 >= p->b13)
            r = func_00283618();
        else
            r = func_002839f0(D_003742c8[p->a[i]].f6 != D_003742c8[p->a[i + 1]].f6);  // entry416_by_masked_index
        if (r) return;
        func_00284048();
        D_0035f2b4->b14++;
        if (D_0035f2b4->b14 >= D_0035f2b4->b13) {
            func_00257708(0);
            func_00283c50();
            func_00287bd0(D_0035f2b4->x0, 0);
            if (D_0035f2b4->x0 == 0) {
                func_002937c0(1);
                return;
            }
            func_00287cc0(1);
            return;
        }
        func_00283f50();
        func_002833f8();
        func_00287cc0(0);
        return;
    }
    if (func_00170cd0()) return;
    if (!func_002839f0(0)) {  // entry416_by_masked_index
        func_00283fb0();
        func_00283790();
    }
    if (st == 0) {
        if (!func_00283668()) return;
        func_00287cc0(1);
    }
    if (q->flags & 4) {
        func_00242618(2, 1);
        func_00283e48();
        func_00287cc0(2);
    }
}

s32 func_001a3a78(); void func_0018e8f0(W291B17**, s32, s32, W291B17**); s32 func_0019c090();  // obj_is_enabled
void func_00187018(W291A17*, W291B17*, W291B17*, s32, f32); void func_00177a58(W291A17*);
void func_00176680(W291A17*, W291B17*, W291B17*);
static inline bool w291_h1(W291A17* s) { return (s->p12->f8 & 2) || (s->f352 & 0x40); }
static inline bool w291_h2(W291A17* s) { return func_0019c090() || w291_h1(s); }
void func_00176458(W291A17* s, W291B17** b, W291B17** c)
{
    s->f264 |= 0x2000000;
    u8 x = (*b)->p40->b19;
    u8 y = (*c)->p40->b20;
    if (x == 2 || y == 2) {
        func_0018e8f0(b, func_001a3a78(), 13, c);
        return;
    }
    bool r = w291_h2(s);
    if (r || (x == 0 && y == 0)) {
        func_0018e8f0(b, func_001a3a78(), 13, c);
        func_00187018(s, *b, *c, -1, -1.0f);
        func_00177a58(s);
        return;
    }
    s32 k = (s->f1416 & 0x80) ? 11 : 12;
    func_0018e8f0(b, func_001a3a78(), k, c);
    func_00176680(s, *b, *c);
    (*b)->f4 |= 0x40;
}

extern s32 D_0034e948;
void func_002cf248(); void func_002cfb30(); W291R2d* func_002d1260(); void func_002d7698(W291O2d*);
void func_002da8f0(W291R2d*, s32); void func_002da958(s32); void func_002d9218(W291O2d*);
void func_002e7108(s32, f32); W291Mtx2d func_002e71a0(s32, u8, s32); void func_002d7af0(W291O2d*);
void func_002d84a8_w(W291O2d* o) asm("_Z13func_002d84a8i");
void func_002d84a8_w(W291O2d* o)
{
    func_002cf248();
    func_002cfb30();
    W291R2d* r = func_002d1260();
    func_002d7698(o);
    func_002da8f0(r, o->f196);
    if (!o->b480 && o->f164 == 4 && 671.0f <= o->f172) {
        func_002da958(D_0034e948);
        o->b480 = 1;
    }
    if (o->b201) {
        func_002d9218(o);
    } else {
        func_002e7108(o->f160, o->f172);
        o->m400 = func_002e71a0(o->f160, o->p184->b8, 1);
        o->m208 = func_002e71a0(o->f160, o->p184->b8, 2);
        func_002d7af0(o);
        if (o->b464) {
            o->m336 = o->m272;
            o->b464 = 0;
        }
    }
    u8 t = 0;
    if (o->p184->b8 == 7 && 250.0f <= o->f172) t = 1;
    r->b3077 = t;
}
}
