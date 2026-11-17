/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Ent Ent;
typedef struct Tab Tab;
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
typedef struct Ent
{
  u32 id;
  s32 key;
  u8 pad[24];
} Ent;
typedef struct Tab
{
  s32 x;
  s32 n;
  Ent e[1];
} Tab;
extern Tab *D_01d49360;
extern u32 D_0032f254[];
// 001c0ba0: moved to src/anon/unit_001c0638.cpp
void func_001c0ba0(s32 key);

}
