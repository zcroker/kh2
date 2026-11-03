#include "../common/types.h"
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V1f7b40;
typedef struct {
    u64 q0;
    u64 q8;
    void* p16;
    f32* p20;
    s32 w24;
    s32 w28;
    s32 w32;
    s32 w36;
    u64 q40;
    V1f7b40* p48;
    V1f7b40* p52;
    s32 w56;
    s32 w60;
    s32 w64;
    s32 w68;
} Req1f7b40;
typedef struct { s32 f0; s32 set; f32 f8, f12, f16; u8 b20; u8 b21; } Ent1f7b40;
typedef struct { u8 pad0[12]; s32* off; } Ctx1f7b40;
typedef struct { u8 pad0[16]; u8* sets; } Res1f7b40;
typedef struct { u8 pad0[168]; u64 flags; } Cur1f7b40;
typedef struct { u8 pad0[144]; s32 p144; } Ovr1f7b40;
extern s32 D_01d9ea9c;
extern Cur1f7b40* D_01d9e6e0;
extern Res1f7b40* D_01d9e6e4;
extern Ovr1f7b40* D_01d9e6e8;
extern u8 D_01d9e8c0[];
extern s32 D_01d9eaa4;
extern s32 D_01d9eaa8;
extern f32 D_00354be0[];
extern s32 D_00352be4, D_00352be8, D_00352bec, D_00352bf0, D_00352bf8, D_00352bfc;
extern u64 D_00352c18;
void func_002f3f40(V1f7b40*, V1f7b40*, f32);
void func_001f7e90(Req1f7b40*);
void func_001f7b40(u8 *base, Ent1f7b40 *e, Ctx1f7b40 *c)
{
  f32 *pos = (f32 *) ((base + c->off[0]) + 160);
  f32 *p2 = (f32 *) ((base + c->off[2]) + 160);
  u8 *col;
  Req1f7b40 r;
  V1f7b40 v;
  if ((D_01d9ea9c == 0) && ((D_01d9e6e0->flags & 0xff0000ff00ULL) == 0))
  {
    f32 ax = pos[2];
    f32 vx = pos[1] + ax;
    f32 x = pos[0] + vx;
    pos[1] = vx;
    pos[0] = x;
    if ((*((s32 *) (base + 12))) == e->f0)
    {
      pos[0] = x + e->f8;
      pos[1] = vx + e->f12;
      if (e->b20 < 4)
      {
        pos[2] = ax + e->f16;
      }
    }
  }
  if (e->set == 0xffff)
  {
    return;
  }
  col = (base + c->off[1]) + 160;
  if (col[8] == 0)
  {
    return;
  }
  v.x = col[8];
  v.y = col[9];
  v.z = col[10];
  v.w = col[11];
  func_002f3f40(&v, &v, 0.00392156839f);
  r.p16 = D_01d9e8c0;
  r.p20 = p2;
  r.w24 = D_01d9eaa4;
  r.p48 = &v;
  r.p52 = &v;
  r.w28 = *((s32 *) ((D_01d9e6e4->sets + (e->set * 36)) + 28));
  *((f32 *) (&r.w32)) = pos[0] * D_00354be0[0];
  r.w36 = e->b21;
  r.w68 = D_01d9e6e8->p144;
  if ((e->b20 >= 4) && ((*((s32 **) (pos + 2))) != 0))
  {
    r.w64 = 1;
    r.w56 = *(*((s32 **) (pos + 2)));
    r.w60 = e->b20 & 8;
  }
  else
  {
    r.w64 = 0;
  }
  if (e->b20 == 0)
  {
    r.q8 = ((D_00352bf8 << 5) | (((u64) (D_00352bec / 64)) << 14)) | (((u64) 85) << 27);
    r.q0 = ((2048 - (D_00352bec / 2)) << 4) | (((u64) (2048 - (D_00352bf0 / 2))) << 36);
  }
  else
  {
    r.q8 = ((D_00352bfc << 5) | (((u64) (D_00352be4 / 64)) << 14)) | (((u64) 85) << 27);
    r.q0 = ((2048 - (D_00352be4 / 2)) << 4) | (((u64) (2048 - (D_00352be8 / 2))) << 36);
  }
  r.q40 = D_00352c18;
  func_001f7e90(&r);
  D_01d9eaa8 += r.w24 - D_01d9eaa4;
  D_01d9eaa4 = r.w24;
  if ((e->b20 >= 4) && ((*((s32 **) (pos + 2))) != 0))
  {
    *(*((s32 **) (pos + 2))) = r.w56;
  }
}
