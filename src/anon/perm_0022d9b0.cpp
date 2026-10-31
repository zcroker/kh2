/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct WinReq WinReq;
typedef struct WinSlot WinSlot;
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
struct WinSlot
{
  void **obj;
  s16 id;
  s16 group;
};
extern WinSlot D_01dad9c0[32];
struct WinReq
{
  u32 _0;
  s16 idx;
  s16 group;
  s16 id;
  s16 mode;
  s16 kind;
};
void *W1688_area_alloc(u32) asm("_ZN4AREA5AllocEj");
void W1688_obj2d_ctor(void *self, void *win) asm("_ZN2YS12WINDOW_OBJ2DC1EPNS_6WINDOWE");
void func_00102448(u32, s32) asm("_ZN2Tz9TaskYieldEz");
void func_001ad0f8(void *, s32, s32);
void func_001ad330(void *, s32);
void func_00225a10(void);
void func_00225a20(void);
s32 func_00225b00(s32);
s32 func_002282f0(s32);
inline static bool W1688_busy(void **o)
{
  return (*((s32 *) (((u8 *) o) + 0x70))) != 3;
}

void func_0022d9b0(WinReq *req, u32 task)
{
  s32 i;
  if (func_002282f0(req->idx) != 0)
  {
    return;
  }
  if (func_00225b00(req->idx) != 0)
  {
    return;
  }
  i = 0;
  switch (req->mode)
  {
    case 0:
      for (; __builtin_expect(i < 32, 0); i++)
    {
      if (D_01dad9c0[i].obj == 0)
      {
        void *w;
        s16 id;
        switch (req->kind)
        {
          case 0:
            id = req->id;
            w = W1688_area_alloc(0xb6c);
            func_001ad0f8(w, id, 0);
            W1688_obj2d_ctor(W1688_area_alloc(0x1c), w);
            D_01dad9c0[i].obj = (void **) w;
            break;

          case 1:
            if (req->group)
          {
            id = req->id;
            w = W1688_area_alloc(0x1230);
            func_001ad330(w, id);
            W1688_obj2d_ctor(W1688_area_alloc(0x1c), w);
            D_01dad9c0[i].obj = (void **) w;
            break;
          }
          else
          {
            id = req->id;
            w = W1688_area_alloc(0x1230);
            func_001ad330(w, id);
            W1688_obj2d_ctor(W1688_area_alloc(0x1c), w);
            D_01dad9c0[i].obj = (void **) w;
            break;
          }

        }

        D_01dad9c0[i].group = req->group;
        D_01dad9c0[i].id = req->id;
        return;
      }
    }

      break;

    case 1:
    {
      WinSlot *e = D_01dad9c0;
      for (; i < 32; i++, e++)
      {
        if ((e->obj && (e->group == req->group)) && (e->id == req->id))
        {
          (*((void (**)(void *)) (((u8 *) (*e->obj)) + 32)))(e->obj);
          e->obj = 0;
          break;
        }
      }

    }

    case 2:
      for (i = 0; i < 32; i++)
    {
      if ((D_01dad9c0[i].obj && (D_01dad9c0[i].group == req->group)) && (D_01dad9c0[i].id == req->id))
      {
        if (func_00225b00(req->idx) != 0)
        {
          return;
        }
        while (W1688_busy(D_01dad9c0[i].obj))
        {
          func_00225a10();
          func_00102448(task, 0);
        }

        func_00225a20();
        return;
      }
    }

      break;

  }

}

}
