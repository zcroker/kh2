/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Item Item;
typedef struct Q Q;
typedef struct Ring Ring;
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
typedef struct Item
{
  u8 pad[0x520];
  s32 a;
  s32 b;
  u8 p2[8];
} Item;
typedef struct Ring
{
  s32 head;
  s32 tail;
  u8 pad[8];
  Item e[8];
} Ring;
typedef struct Q
{
  u8 pad[0x30];
  Ring r;
} Q;
extern Q *D_00347d64;
inline int inline_fn(s32 arg0, Ring *arg1)
{
  return ((arg0 - arg1->tail) + 8) % 8;
}

void func_00138190(s32 a, s32 b)
{
  Q *q = D_00347d64;
  Ring *r = &q->r;
  s32 h = q->r.head;
  s32 n;
  if (inline_fn(h, r) < 7)
  {
    Item *it;
    q->r.head = (h + 1) % 8;
    it = &r->e[h];
    it->a = a;
    it->b = b;
  }
}

}
