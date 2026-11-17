/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct V4 V4;
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
typedef struct V4
{
  f32 x;
  f32 y;
  f32 z;
  f32 w;
} V4;
void func_002d1bf8(u8 *, u8 *, V4 *, V4 *);
inline static void v4set(V4 *v, f32 a, f32 b, f32 c, f32 d)
{
  v->x = a;
  v->y = b;
  v->z = c;
  v->w = d;
}

void func_002d1b90(u8 *a, u8 *b);  // 0x002d1b90: definition moved into src/anon/unit_002cf260.cpp

}
