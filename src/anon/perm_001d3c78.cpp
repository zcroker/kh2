/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct O3c O3c;
typedef struct O3c_sub O3c_sub;
typedef struct V3c V3c;
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
struct O3c_sub
{
  u8 pad[8];
  s32 f8;
};
struct O3c
{
  u8 pad0[0xc];
  O3c_sub *f0c;
  u8 pad1[0x588 - 0x10];
  s32 f588;
  u8 pad2[0xb50 - 0x58c];
  s32 fb50;
};
struct V3c
{
  u8 b0;
  u8 b1;
  u8 b2;
  u8 b3;
  u16 h4;
};
extern O3c *D_0034e948;
extern u8 D_0032bae0;
s32 func_00176b58(u8);
u32 *func_00177860(s32) asm("_ZN2YS5PARTY11get_abilityEv");
s32 func_0019ba60(s32) asm("_Z16ctarget_0019ba60jjjj");
V3c *func_001a80c8(u16);
s32 func_001c8ab0() asm("_ZN2YS6SUMMON7GetModeEv");
s32 func_001d3f80(u8 *) asm("_ZN2YS7MISSION12GetLimitCostEi");
inline static u32 bit3c(u32 *b, u32 n)
{
  return b[n >> 5] & (1 << (n & 31));
}

s32 func_001d3c78(u8 *p);  // 0x001d3c78: definition moved into src/anon/unit_001d3c08.cpp

}
