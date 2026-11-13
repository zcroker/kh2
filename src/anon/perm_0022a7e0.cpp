/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct W1636Group W1636Group;
typedef struct W1636Rect W1636Rect;
typedef struct W1636Score W1636Score;
typedef struct W1636Spr W1636Spr;
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
typedef struct W1636Score W1636Score;
typedef struct W1636Spr W1636Spr;
struct W1636Spr
{
  u8 pad0[384];
  f32 alpha;
  u8 pad184[8];
  W1636Score *parent;
  u32 settled;
  u8 pad194[8];
};
typedef struct W1636Rect W1636Rect;
struct W1636Rect
{
  u8 pad[256];
};
typedef struct W1636Group W1636Group;
struct W1636Group
{
  u8 pad0[32];
  W1636Rect r0;
  u8 pad120[32];
  W1636Rect r1;
  W1636Rect r2;
  W1636Score *owner;
  u8 pad344[12];
};
struct W1636Score
{
  W1636Spr base;
  u8 pad19c[28];
  W1636Spr bar[3];
  u8 pad68c[4];
  W1636Group grp[4];
  W1636Spr face;
  u8 pad156c[4];
  s32 count;
  u32 pad1574;
  s32 type;
};
void func_001396b0(W1636Spr *);
void func_0031a260(W1636Spr *, s32);
u32 func_0022b720(void);
u32 func_0022b9e0(void);
void func_0022a0f8(W1636Group *, s32, s32, s32);
void func_00158050(W1636Spr *, s32, u32, u32, s32, s32, s32);
void func_001386e0(W1636Spr *, s32, u32, u32, s32, s32);
void func_00139d78(W1636Group *);
void func_0014b200(W1636Rect *, u32);
inline static void W1636_setParent(W1636Spr *s, W1636Score *p)
{
  s->parent = p;
  func_001396b0(s);
  if (s->parent)
  {
    s->settled = 0;
    func_001396b0(s);
    if (s->settled)
      func_0031a260(s, 0);
  }
}

inline static void W1636_setZ(W1636Group *g, u32 z)
{
  func_00139d78(g);
  func_0014b200(&g->r0, z);
  func_0014b200(&g->r1, z);
  func_0014b200(&g->r2, z);
}

inline static void W1636_attach(W1636Group *g, W1636Score *s)
{
  func_00139d78(g);
  g->owner = s;
}

void func_0022a7e0(W1636Score *s, s32 type);  // 0022a7e0: moved to src/sasa/musical_input.cpp (linked unit)

}
