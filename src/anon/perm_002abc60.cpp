/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Flg Flg;
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
typedef struct Flg
{
  u8 pad[0x140];
  u32 bits[1];
} Flg;
extern Flg *D_0035f610;
inline static s32 chk2(u32 *b, u32 n)
{
  return (b[n >> 5] & (1 << (n & 31))) != 0;
}

s32 func_002abc60(s32 n);  // 0x002abc60: definition moved into src/anon/unit_002a99c8.cpp

}
