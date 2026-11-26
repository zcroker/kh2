/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct W1950Mgr W1950Mgr;
typedef struct W1950Obj W1950Obj;
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
struct W1950Obj
{
  u8 pad[0x18c];
  s32 f18c;
  s32 f190;
};
struct W1950Mgr
{
  u8 pad[0x18];
  u8 sub[1];
};
void func_00138c68(W1950Obj *, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
void func_00138c78(W1950Obj *, s32 *, s32 *) asm("_ZN2dk6Sprite12getOffsetPosERiS1_");
void func_001396b0(W1950Obj *) asm("_ZN2Tz6Select10BeginLeaveEz");
s32 func_00139d78(W1950Mgr *) asm("_Z16u_call4_00139d78jjjj");
s32 func_0023aa18(void *) asm("_ZN2YI8SEQUENCE9GetParamXEv");
s32 func_0023aa38(void *) asm("_ZN2YI8SEQUENCE9GetParamYEv");
void Tz__CmComm__CreateConfirmSelector(void *, s32, s32, s32, s32, s32, void *);
void func_00288f48(void *, s32, s32, s32, s32) asm("_ZN2Tz6Select10SetMoveKeyEiiii");
W1950Obj *func_002891b8(void *, s32) asm("_ZN2Tz6Select10GetItemPtrEi");
s32 func_002892f8(void *) asm("_ZN2Tz6Select10GetItemMaxEv");
void func_0028af28(void *, s32) asm("_ZN2Tz6Select16SetDisableButtonEj");
void func_0031a260(W1950Obj *, s32) asm("_ZN2Tz6Select7SetFlagEz");
extern s32 D_0035ef64;
extern s32 D_0035ef68;
extern s32 D_0035f03c;
extern void *D_0035f024;
extern W1950Mgr *D_0035f034;
extern u8 D_00372a10[];
void func_002571e0(s32 arg0);  // 0x002571e0: definition moved into src/anon/unit_00254020.cpp

}
