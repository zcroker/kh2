/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct D1dec78 D1dec78;
typedef struct N1dec78 N1dec78;
typedef struct O1dec78 O1dec78;
typedef union FU1dec78 FU1dec78;
typedef union NU1dec78 NU1dec78;
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
typedef struct N1dec78 N1dec78;
typedef union NU1dec78 NU1dec78;
typedef struct D1dec78 D1dec78;
typedef struct O1dec78 O1dec78;
typedef union FU1dec78 FU1dec78;
union FU1dec78
{
  f32 f;
  u16 h;
  u32 u;
};
struct N1dec78
{
  u16 h0;
  u16 h2;
  FU1dec78 v[9];
};
union NU1dec78
{
  N1dec78 *p;
  f32 f;
  u32 u;
};
struct D1dec78
{
  FU1dec78 a[3];
  u32 p0;
  FU1dec78 b[3];
  u32 p1;
  FU1dec78 c[3];
  u32 p2;
  u32 f48;
  u16 h52;
  u8 pad[6];
  u8 b60;
  u8 b61;
};
struct O1dec78
{
  u8 pad[64];
  u32 f64;
  u32 f68;
  u32 f72;
  u32 f76;
  FU1dec78 f80;
  u8 pad2[4];
  NU1dec78 n;
  u32 f92;
};
N1dec78 *func_001e0188(s32);
void ryj__PAX__MANAGER__MANAGER_2(O1dec78 *o, u32 a, u32 b, f32 f, D1dec78 *d);  // 0x001dec78: definition moved into src/anon/unit_001deb58.cpp

}
