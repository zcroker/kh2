
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;
typedef float f32;
union BD_VALUE
{
  s32 i;
  f32 f;
  void *p;
  u32 u;
};
typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
  f32 w;
} W2426Vec;
typedef struct 
{
  s16 x;
  s16 y;
  s16 z;
} W2426Pt;
typedef struct 
{
  u8 pad[0x80];
  u8 *tbl;
  u8 pad84[0x24];
  u64 flags;
} W2426Mgr;
typedef struct 
{
  u8 pad[0x10];
  f32 m0[12];
  f32 m1[4];
  u8 pad50[0x40];
  W2426Pt *pts;
} W2426Cam;
typedef struct 
{
  u8 pad[4];
  void *owner;
} W2426Ent;
typedef struct 
{
  s16 a;
  s16 cnt;
  u16 *list;
} W2426Grp;
typedef struct 
{
  u8 pad[0x14];
  W2426Pt *pts;
  u8 pad18[0xc];
} W2426Mdl;
typedef struct 
{
  u8 pad[0x10];
  W2426Mdl *mdl;
  u8 pad14[4];
  W2426Grp *grp;
} W2426Tab;
typedef struct 
{
  u8 pad[4];
  s16 g0;
  u8 pad6[2];
  f32 scale;
  u8 n;
  u8 mask;
  u8 rnd;
  u8 padf;
  s32 idx;
  s32 o14;
  s32 i18;
  s32 o1c;
  s32 i20;
  s32 o24;
} W2426Prm;
typedef struct 
{
  u8 pad[0xc];
  s32 *ofs;
} W2426Ctx;
typedef void (*W2426CB)(void *, W2426Prm *, s16 *);
extern s32 D_01d9eab4;
extern s32 D_01d9ea9c;
extern W2426Mgr *D_01d9e6e0;
extern W2426Tab *D_01d9e6e4;
extern W2426Cam *D_01d9e6e8;
s32 func_00222568(void);
W2426Ent *func_001e7a98(W2426Mgr *, u8 *);
void pppKeBornRnd4_Born(void *, W2426Prm *, s16 *);
void func_0021ee48(void *, W2426Prm *, W2426CB, u16 *, s16, u8, u8);
void sceVu0ApplyMatrix(void *, void *, void *);
void func_002226b8(void *, void *);
void sceVu0SubVector(void *, void *, void *);
void sceVu0Normalize(void *, void *);
void sceVu0ScaleVector(void *, void *, f32);
void pppKeBornRnd4(void *owner, W2426Prm *prm, W2426Ctx *c);  // 0x001f6298: definition moved into src/anon/unit_001f6298.cpp

