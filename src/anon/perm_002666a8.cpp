/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct W1610Ent W1610Ent;
typedef struct W1610Mn W1610Mn;
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
typedef struct W1610Ent W1610Ent;
typedef struct W1610Mn W1610Mn;
struct W1610Ent
{
  u16 a;
  u16 b;
  u16 c;
};
struct W1610Mn
{
  u8 pad[0x20];
  s8 mode;
  u8 pad2[0x7a4 - 0x21];
  u8 buf[160];
};
extern W1610Mn *D_0035f0e4;
extern s32 D_0035f01c;
extern s32 D_0035f010;
extern u16 D_00373518[];
extern W1610Ent D_00373530[][10];
extern W1610Ent D_003735a8[][10];
extern W1610Ent D_00373620[][10];
extern u16 D_00373698[];
extern u16 D_003736a0[];
extern u16 D_003736a8[];
extern u16 D_003736b0[];
extern u16 D_003736b8[];
s32 func_00287bc0(void);
void func_002fde18(void *, s32, s32);
s32 func_0028b040(s32);
u32 func_002670a0(s32);
s32 func_00192048(u16);
s32 func_00281140(s32, s32);
s32 func_00192e50(s32, void *, s32, s32);
void func_00192b30(s32);
void func_00192c90(s32, void *);
void Tz__CMenuHelp__Create_2(void *, s32);
s32 func_00267248(void);
u32 func_00257070(s32);
s32 func_002671e8(s32);
void func_00263a58(u16, s32);
void func_002666a8(void);  // 0x002666a8: definition moved into src/anon/unit_00265580.cpp

}
