#include "../common/types.h"

// ---- 002abba8 ----
struct W1790Sram { u8 pad[0x140]; u32 bits[4]; };
static inline int w1790_bitTest(u32* p, u32 i) { return p[i >> 5] & (1 << (i & 0x1f)); }
static inline void w1790_bitSet(u32* p, u32 i) { *(u32*)((u8*)p + ((i >> 5) << 2)) |= (1 << (i & 0x1f)); }

// ---- 002be630 ----
struct W1790V4 { f32 x, y, z, w; };

// ---- 0013aba8 ----
struct W1790Pos { u8 pad[328]; s32 x, y; };
struct W1790Obj { u8 p0[24]; u8 seq[344]; s32 a170, a174; u8 p178[60]; W1790Pos pos; u8 p[780 - 436 - 336]; s32 v30c; };

// ---- 00148470 ----
struct W1790Node { u8 p0[235]; u8 eb; struct W1790Node* ec; struct W1790Node* f0; u32 f4; u32 f8; u8 pfc[32]; u16 h11c; u8 b11e; u8 b11f; };
struct W1790Flag { u32 f : 1; u32 r : 31; u32 pad; };
struct W1790Mgr { u8 p[17252]; W1790Flag tbl[1]; };
static inline u32 w1790_tst(u8* base, u32 off) { return ((W1790Flag*)(base + off))->f; }
static inline W1790Node* w1790_next(W1790Node* n, W1790Node* c) { return c == 0 ? n->f0 : c->ec; }

void func_0017f488(int, int, float, float);

extern "C" {
W1790Sram* jm_GetSram(void) asm("_ZN2Tz9JmNewInfo7GetSramEv");
s32 func_002a7490(void);
s32 func_002a74c0(void);
extern W1790Sram* D_0035f610;

s32 func_0016b740(s32);
void u_tail4_001c0d38(u32, u32, u32, u32) asm("_Z16u_tail4_001c0d38jjjj");
void wtarget_0016b070(u32, W1790V4*) asm("_Z16wtarget_0016b070jjjj");
void func_002fd188(void (*)());
void D_002be6e8();
extern s8 D_01e2bc20;
extern W1790V4 D_01e2bc30;
extern s32 D_0034e948;

void func_00138988(W1790Obj*);
void func_00138de0(W1790Obj*);
void seq_GetActiveXY(void*, s32*, s32*) asm("_ZN2YI8SEQUENCE11GetActiveXYEPiS1_");
s32 seq_GetParamX(void*) asm("_ZN2YI8SEQUENCE9GetParamXEv");
s32 seq_GetParamY(void*) asm("_ZN2YI8SEQUENCE9GetParamYEv");
void func_0023ade0(W1790Pos*);
extern s32 D_0034805c;

void func_00148a68(W1790Mgr*, W1790Node*);
void func_00147f08(W1790Mgr*, W1790Node*);

void func_002abba8(void) {
    W1790Sram* p = jm_GetSram();
    s32 a = func_002a7490();
    u32* bits = p->bits;
    s32 b = func_002a74c0();
    u32 i;
    for (i = 0; (s32)i < 4; i++) {
        s32 f;
        if (i == 0 || i == 3) f = a; else f = b;
        if (f) {
            if (!w1790_bitTest(bits, i)) w1790_bitSet(D_0035f610->bits, i);
        }
    }
}

void func_002be630(void) {
    s32 v = func_0016b740(931);
    s32 o = D_0034e948;
    u_tail4_001c0d38(o, v, 0x4002, 0);
    // function-local static (guard byte, atexit of its empty destructor)
    if (!D_01e2bc20) {
        D_01e2bc20 = 1;
        D_01e2bc30.x = D_01e2bc30.z = D_01e2bc30.w = 0.0f;
        D_01e2bc30.y = 3.14159274f;
        func_002fd188(D_002be6e8);
    }
    wtarget_0016b070(o, &D_01e2bc30);
    func_0017f488(o + 320, 156, 0.0f, 0.0f);
}

void func_0013aba8(W1790Obj* o) {
    s32 x = 0, y = 0;
    void* m = o->seq;
    func_00138988(o);
    func_00138de0(o);
    if (o->v30c >= D_0034805c) {
        seq_GetActiveXY(m, &x, &y);
        x += seq_GetParamX(m);
        y += seq_GetParamY(m);
        W1790Pos* p = &o->pos;
        s32 a = o->a170 + x;
        s32 b = o->a174 + y;
        p->y = b;
        p->x = a;
        func_0023ade0(p);
    }
}

void func_00148470(W1790Mgr* g, W1790Node* n) {
    u16 i = n->h11c;
    if (n->eb && (n->f8 & 4)) {
        if (w1790_tst((u8*)g->tbl, i * 8)) {
            if (n->b11f) func_00148a68(g, n); else func_00147f08(g, n);
        }
    }
    W1790Node* c = 0;
    while ((c = w1790_next(n, c)) != 0) func_00148470(g, c);
}
}
