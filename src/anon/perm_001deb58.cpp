/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct D1deb58 D1deb58;
typedef struct N1deb58 N1deb58;
typedef struct O1deb58 O1deb58;
typedef union FU1deb58 FU1deb58;
typedef union NU1deb58 NU1deb58;
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
typedef struct N1deb58 N1deb58;
typedef union NU1deb58 NU1deb58;
typedef struct D1deb58 D1deb58;
typedef struct O1deb58 O1deb58;
typedef union FU1deb58 FU1deb58;
union FU1deb58
{
  f32 f;
  u16 h;
  u32 u;
};
struct N1deb58
{
  u16 h0;
  u16 h2;
  FU1deb58 v[9];
};
union NU1deb58
{
  N1deb58 *p;
  f32 f;
  u32 u;
};
struct D1deb58
{
  FU1deb58 a[3];
  u32 p0;
  FU1deb58 b[3];
  u32 p1;
  FU1deb58 c[3];
  u32 p2;
  u32 f48;
  u16 h52;
  u8 pad[6];
  u8 b60;
  u8 b61;
};
struct O1deb58
{
  u8 pad[64];
  u32 f64;
  u32 f68;
  u32 f72;
  u32 f76;
  FU1deb58 f80;
  u8 pad2[4];
  NU1deb58 n;
  u32 f92;
};
N1deb58 *func_001e0188(s32);
void func_001deb58(O1deb58 *o, u32 a, u32 b, f32 f, D1deb58 *d);  // 0x001deb58: definition moved into src/anon/unit_001deb58.cpp

}
