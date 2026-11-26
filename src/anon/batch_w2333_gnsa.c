#include "../common/types.h"

/* Plain C (partMng.c), built with -g and without strict aliasing (-g makes no difference here). */

/* 001e66e8: partMng particle draw (assert line 2311): timers, record setup, GS flush, update and draw. */
typedef struct { s32 start; s32 cur; s32 max; } PartTime1e66e8;
typedef struct { u8 pad0[176]; u8 m176[72]; u8 hide; } PartOwn1e66e8;
typedef struct {
    u8 pad0[134];
    u16 flags;
    s32 id;
    PartOwn1e66e8* own;
    u8 on;
    u8 b145;
    u8 pad146;
    u8 sub;
    u8 pad148[4];
    union { u64 gs; struct { u32 lo; s16 h156; s16 h158; } h; } u;
    u8 pad160[4];
    f32 wait;
    u8 pad168[192 - 168];
    PartTime1e66e8 tSetup;
    u8 pad204[224 - 204];
    PartTime1e66e8 tUpdate;
    u8 pad236[4];
    PartTime1e66e8 tDraw2;
    u8 pad252[272 - 252];
    PartTime1e66e8 tTotal;
    u8 pad284[304 - 284];
    PartTime1e66e8 tDraw;
    u8 pad316[4];
    PartTime1e66e8 tPacket;
} Part1e66e8;
typedef struct { s32 id; s32 sub; } PartLast1e66e8;
extern Part1e66e8* D_01d9e6e0;
extern s32 D_01d9eaa4;
extern s32 D_01d9eaa8;
extern s32 D_01d9eaac;
extern PartLast1e66e8 D_00354690;
extern u8 D_00354698[];
extern u8 D_00354650[];
extern s32 D_003591c8;
extern char D_0036e978[];
extern char D_0036e998[];
extern char D_0036e9c0[];
extern char D_0036e9d0[];
void func_002fdfc8(const char*, ...);
void func_001e41e0(Part1e66e8*);
s32 func_001e8c28(Part1e66e8*, s32);
void func_001e7cc0(Part1e66e8*);
void func_001e5f40(u8*, Part1e66e8*);
void func_001e5f88(u8*, Part1e66e8*);
void func_001e5458(s32, u8*, s32);
void func_001e5718(s32, u8*, s32);
void sceGsSyncPath(s32, s32);
void func_003058a0(s32);
void func_002f3918(s32, u8*);
void func_001e3c18(Part1e66e8*);
void func_001e2b90();
static inline void timeEnd1e66e8(PartTime1e66e8* t)
{
    t->cur += *(volatile s32*)0x10000000 - t->start;
    if (t->max < t->cur) t->max = t->cur;
}
static inline void timeStart1e66e8(PartTime1e66e8* t)
{
    t->start = *(volatile s32*)0x10000000;
}
static inline void timeSub1e66e8(PartTime1e66e8* t)
{
    t->cur -= t->start;
    if (t->max < t->cur) t->max = t->cur;
}
static inline void ryjAssert1e66e8(const char* e, const char* f, u32 l)
{
    func_002fdfc8(D_0036e978, e);
    func_002fdfc8(D_0036e998, f, l);
    asm volatile("break"); /* assert trap */
}
s32 pppPartDraw(Part1e66e8* p);  // 0x001e66e8: definition moved into src/anon/unit_001e0cb8.cpp
