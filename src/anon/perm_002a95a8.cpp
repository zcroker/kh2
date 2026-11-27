/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct W1610Base W1610Base;
typedef struct W1610LE W1610LE;
typedef struct W1610Lst W1610Lst;
typedef struct W1610Rec W1610Rec;
typedef struct W1610Slot W1610Slot;
typedef union BD_VALUE BD_VALUE;
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
struct W1610Slot
{
  u8 pad[408];
  s32 h;
  u8 pad2[436 - 412];
};
struct W1610LE
{
  s8 a;
  s8 b;
  u16 c;
};
struct W1610Lst
{
  s32 cnt;
  W1610LE e[1];
};
struct W1610Rec
{
  u8 pad[4];
  u16 id;
};
struct W1610Base
{
  u8 pad[0xa998];
  u8 lay[10][408];
  u8 pad2[(0x110a0 - 0xa998) - 4080];
  u8 name[10][64];
};
extern s32 D_0035f200;
extern s32 D_0035f214;
extern W1610Slot *D_0035f60c;
extern W1610Lst *D_0035f608;
extern s32 D_00374c38;
extern s32 D_00374c3c;
W1610Base *func_002766d0(void) asm("_ZN2Tz6Jiminy9GetSeqTblEv");
s32 func_0028b038(s32) asm("_ZN2Tz6Select12GetSelectTopEv");
void Tz__ScrollBar__SetPos(s32, s32);
void func_002fde18(void *, s32, s32) asm("_Z16wtarget_002fde18jjjj");
void func_00138c10(void *, s32) asm("_ZN2dk6Sprite6setNumEi");
s32 Tz__JmWorldSel__GetId2WorldName(s32, s32);
s32 func_002954e0(s32) asm("_ZN2Tz10JmWorldSel11isWorldOpenEi");
s32 func_00192048(s32) asm("_Z16u_tail4_00192048jjjj");
s32 Tz__MenuUtil__MakeQuestionStr(s32, void *, s32);
s32 func_002a9c40(s32);
W1610Rec *func_002a92a0(s32);
s32 Tz__JmQuest__GetQuestStat(W1610Rec *);
s32 func_002aacd8(s32);
s32 func_002aad58(s32);
void func_002a95a8(void);  // 0x002a95a8: definition moved into src/anon/unit_002a92a0.cpp

}
