/* found by decomp-permuter (nightly.py) */
extern "C" {


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
void func_002e3f78(f32 *q);
void func_002e42d8(f32 *q, f32 (*m)[4])
{
  f32 t[4];
  s32 i;
  s32 j;
  s32 k;
  f32 s;
  int new_var;
  f32 d;
  i = 0;
  new_var = 1;
  if (m[new_var][new_var] > m[0][0])
  {
    i = new_var;
  }
  if (m[2][2] > m[i][i])
  {
    i = 2;
  }
  j = (i + new_var) % 3;
  k = (j + new_var) % 3;
  s = __builtin_sqrtf(((m[i][i] - m[j][j]) - m[k][k]) + 1.0f) * 0.5f;
  t[i] = s;
  if (s <= 0.001f)
  {
    func_002e3f78(q);
    return;
  }
  d = s * 4.0f;
  t[j] = (m[i][j] + m[j][i]) / d;
  t[k] = (m[i][k] + m[k][i]) / d;
  t[3] = (m[j][k] - m[k][j]) / d;
  q[0] = t[0];
  q[new_var] = t[new_var];
  q[2] = t[2];
  q[3] = t[3];
}

}
