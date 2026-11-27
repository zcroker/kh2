/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Ent Ent;
typedef struct Tbl Tbl;
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
s32 func_00257770(void) asm("_ZN2Tz5CmTop13GetListBufferEv");
s32 func_00287bc0(void) asm("_ZN2Tz8MenuBase7GetModeEv");
void func_002fde18(s32, s32, s32) asm("_Z16wtarget_002fde18jjjj");
s32 func_0028b040(s32) asm("_ZN2Tz8JmReport7GetDataEj");
s32 func_002570a0(s32) asm("_ZN2Tz5CmTop12GetSelectPosEi");
void func_0027aed8(s32, s32 *, s32 *);
void func_00263a58(s32, s32) asm("_ZN2Tz9CMenuHelp6CreateEib");
volatile short Tz__CMenuHelp__Create_2(s32, s32);
u8 *func_0027bba0(s32) asm("_Z16ctarget_0027bba0jjjj");
s32 func_00192048(s32) asm("_Z16u_tail4_00192048jjjj");
s32 func_00192b30(s32) asm("_ZNK2YS7MESSAGE8get_sizeEv");
void func_00192c90(s32, s32) asm("_ZNK2YS7MESSAGE3dupEPc");
s32 Tz__CmAbility__Cur2AbiltyType(void);
s32 func_0027c3b8(s32) asm("_ZN2Tz9CmAbility10GetItemTblEi");
u8 *func_00273180(s32, s32);
void func_002595e8(s32, s32) asm("_ZN2Tz6CmComm11CopyMessageEPcPKN2YS7MESSAGEE");
extern s32 D_0035f01c;
extern s32 D_00373e04[2];
extern u16 D_00373e68[2];
struct Ent
{
  u16 id;
  s8 on;
  u8 p0;
  s8 col;
  u8 p1;
  s8 kind;
  u8 p2;
};
struct Tbl
{
  u8 pad[7];
  s8 n;
  u8 pad2[4];
  Ent e[1];
};
extern Tbl *D_0035f230;
void func_0027b6b8(void);  // 0x0027b6b8: definition moved into src/anon/unit_0027a6d8.cpp

}
