#include "../common/types.h"

/* Plain C code (partMng family). Lives in _nsi.c only because batch_wcx2.c would share the object name with batch_wcx2.cpp; it matches with or without -fno-sched-interblock.
   00204850: strip particle physics step (colour integrate, angle step, VU0 position update, fade counters). */
typedef struct Em048 Em048; typedef struct Pr048 Pr048; typedef struct Pt048 Pt048; typedef struct Cf048 Cf048;
struct Em048 { u8 pad[64]; f32 v64[4]; };
struct Pr048 {
    u8 pad0[34]; u16 h34; u8 pad36; u8 b37; u8 pad38[56 - 38];
    f32 f56, f60, f64, f68; u8 pad72[100 - 72]; f32 f100, f104; u8 pad108[132 - 108];
    f32 f132; u8 pad136[164 - 136]; f32 f164, f168; u8 pad172[180 - 172]; f32 f180;
    u8 pad184[202 - 184]; u8 b202, b203; u8 pad204[2]; u8 b206;
};
struct Pt048 {
    f32 pos[4]; f32 vel[4]; u8 pad32[38 - 32]; u16 h38; u8 pad40[44 - 40]; u8 b44; u8 pad45; u16 h46; s16 h48; s16 h50;
    f32 f52, f56, f60, f64, f68, f72, f76, f80, f84, f88; u8 b92, b93, b94, b95;
};
struct Cf048 { f32 x, y, z, w, vx, vy, vz, vw; };
void func_00204850(Em048* e, Pr048* p, Pt048* pt, u8* col, Cf048* cf);  // 0x00204850: definition moved into src/anon/unit_00203b48.c

/* 00203408: trail/strip effect set-up: allocate the history vectors, then number the vertices of
   every strip record (types 4 and 6) in the model set; unknown record types print an error. */
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V203408;
typedef struct { u8 r, g, b, a; } C203408;
typedef struct { C203408 col[4]; s16 idx[4]; } R203408;
typedef struct { u8 pad0; s8 type; s16 count; u8 pad4[12]; } H203408;
typedef struct { s32 f0; s32 set; u8 pad8[6]; u8 n; } Ent203408;
typedef struct { u8 pad0[12]; s32* off; } Ctx203408;
typedef struct { u8 pad0[16]; u8* sets; } Res203408;
typedef struct { u8 pad0[4]; u8 n; u8 pad5[3]; V203408* hist; } St203408;
typedef struct { s32 w0; u8 pad4[4]; s32 w8; u8 pad12[16]; u8* data; } Set203408;
extern Res203408* D_01d9e6e4;
extern V203408* D_00354680;
extern s32 D_00354684;
extern char D_003703e0[];
extern char D_00370398[];
extern char D_00370378[];
void* func_001e7698(Res203408*, s32);
void func_002233f0(char*, char*, s32);
void sceVu0CopyVector(V203408*, V203408*);
s32 puts(char*);
void func_00202ce0(Set203408*, Ent203408*, St203408*);
s32 func_00203408(u8* base, Ent203408* e, Ctx203408* c);  // 0x00203408: definition moved into src/anon/unit_00203408.c

/* 001e6280: partMng particle update (assert line 2137). */
typedef struct { s32 start; s32 cur; s32 max; } PartTime1e6280;
typedef struct { u8 pad0[248]; u8 hide; } PartOwn1e6280;
typedef struct {
    u8 pad0[88];
    void* p88;
    u8 pad1[96 - 92];
    s32 steps;
    u8 pad2[134 - 100];
    u16 flags;
    s32 id;
    PartOwn1e6280* own;
    u8 on;
    u8 pad3[147 - 145];
    u8 sub;
    u8 pad4[152 - 148];
    f32 acc;
    u8 pad5[164 - 156];
    f32 wait;
    u64 b168 : 8, stopA : 8, b170 : 8, dead : 8, stopB : 8, b173 : 24;
    u8 pad6[208 - 176];
    PartTime1e6280 tUpdate;
    u8 pad7[256 - 220];
    PartTime1e6280 tTotal;
    u8 pad8[288 - 268];
    PartTime1e6280 tDraw;
} Part1e6280;
typedef struct { s32 id; s32 sub; } PartLast1e6280;
extern Part1e6280* D_01d9e6e0;
extern s32 D_01d9ea9c;
extern f32 D_00352be0;
extern PartLast1e6280 D_00354690;
extern char D_0036e978[];
extern char D_0036e998[];
extern char D_0036e9c0[];
extern char D_0036e9d0[];
void func_002fdfc8(const char*, ...);
void func_001e6038(Part1e6280*);
void func_001e41e0(Part1e6280*);
void func_001e8bb8(Part1e6280*);
s32 func_001e8c28(Part1e6280*, s32);
void func_001e7cc0(Part1e6280*);
static inline void timeEnd1e6280(PartTime1e6280* t)
{
    t->cur += *(volatile s32*)0x10000000 - t->start;
    if (t->max < t->cur) t->max = t->cur;
}
static inline void timeSub1e6280(PartTime1e6280* t)
{
    t->cur -= t->start;
    if (t->max < t->cur) t->max = t->cur;
}
static inline void ryjAssert1e6280(const char* e, const char* f, u32 l)
{
    func_002fdfc8(D_0036e978, e);
    func_002fdfc8(D_0036e998, f, l);
    asm volatile("break"); /* assert trap */
}
s32 func_001e6280(Part1e6280* p, s32 force);  // 0x001e6280: definition moved into src/anon/unit_001e0cb8.cpp

/* The soft-float double compare (rand() > 0.5) is a libcall to dpcmp, which lives in the game at 0x3142e0. */
asm("dpcmp = func_003142e0");
asm("fptodp = func_00313b80");

/* 0020a090: strip particle init from its emitter record (random colour spread, angle, speeds, signs). */
typedef struct {
    u8 pad0[4]; s32 kind; u8 pad8[12]; u16 life; u8 tex;
    u8 pad23; f32 pos[4]; u8 pad40[16]; u8 col[4]; f32 f60, f64; u8 pad68[4]; f32 f72, f76;
    u8 pad80[16]; f32 f96, f100; u8 pad104[4]; f32 f108, f112; u8 pad116[4]; f32 f120;
    u8 pad124[12]; f32 f136; u8 pad140[4]; f32 f144; u8 pad148[35];
    u8 s;
    u8 r;
} Src20a090;
typedef struct {
    u8 pad0[34]; s16 h34; u8 pad36[2]; s16 h38; s8 col[4]; f32 f44, f48, f52, f56, f60, f64, f68, f72, f76, f80;
    s32 w84; u64 tex : 8, b8 : 1, texOn : 1, rest : 54;
} Dst20a090;
typedef struct { u8 pad0[6]; s16 h6; } Shape20a090;
typedef struct { Shape20a090* sh; s32 pad; } ShapeEnt20a090;
typedef struct { u8 pad0[20]; ShapeEnt20a090* shapes; } Res20a090;
extern Res20a090* D_01d9e6e4_20a090 asm("D_01d9e6e4"); /* same global as D_01d9e6e4, typed for this function */
s8 func_0020a000(u8);
f32 func_00209fb8(void);
void func_0020a090(Src20a090* s, Dst20a090* d, f32* pos);  // 0x0020a090: definition moved into src/anon/unit_0020a090.c
