/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Ent Ent;
typedef struct Hdr Hdr;
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
typedef struct Ent Ent;
struct Ent
{
  s16 a;
  u16 id;
  s16 b;
  s16 n;
};
typedef struct Hdr Hdr;
struct Hdr
{
  s16 count;
  s16 pad[3];
  Ent e[1];
};
s32 func_002766d0(void);
void func_00138c10(s32, s32);
s32 func_0028b040(s32);
s8 *func_00276568(void);
void func_002ac268(s32, s32);
s32 func_002abff0(s32, s32);
s32 func_002ac110(s32, s32);
extern s32 D_0035f200;
extern Hdr *D_0035f594;
extern s32 D_00374788;
extern s32 D_0037478c;
void func_00297b30(void);  // 0x00297b30: definition moved into src/anon/unit_00295d28.cpp

}
