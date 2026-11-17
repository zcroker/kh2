/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct E29d E29d;
typedef struct G29d G29d;
typedef struct I29d I29d;
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
struct E29d
{
  u8 pad[4];
  u16 h4;
  u16 msg;
  u8 pad8[8];
  u16 flags;
  u8 pad12[0x12];
};
struct G29d
{
  u8 pad[4];
  s8 b4;
  s8 cnt;
  u16 pad6;
  s16 ids[(0x108 - 8) / 2];
  char names[10][64];
};
struct I29d
{
  u8 pad[0x198];
  void *name;
};
extern G29d *D_0035f5ac;
extern s32 D_0035f200;
extern s32 D_0035f214;
extern s32 D_00374ad0;
extern s32 D_00374ad4;
u8 *func_002766d0(void) asm("_ZN2Tz6Jiminy9GetSeqTblEv");
u8 *func_00294000(s32) asm("_ZN2Tz6JmInfo7GetDataEi");
void func_00138c10(void *, s32) asm("_ZN2dk6Sprite6setNumEi");
s32 func_0028b038(s32) asm("_ZN2Tz6Select12GetSelectTopEv");
void func_0028be78(s32, s32);
I29d *func_002891b8(s32, s32) asm("_ZN2Tz6Select10GetItemPtrEi");
void *func_00192048(u32) asm("_Z16u_tail4_00192048jjjj");
s32 func_0028afa8(s32) asm("_ZN2Tz6Select12GetSelectMaxEv");
s32 func_002943b0(E29d *);
u32 func_00295430(s32, s32);
void *func_00192e50(void *, char *, s32, void *);
void func_002595e8(char *, void *) asm("_ZN2Tz6CmComm11CopyMessageEPcPKN2YS7MESSAGEE");
void *func_00192a80(void *);
void func_0028def0(char *, void *);
s32 func_002a9e98(u32);
s32 func_002a9f50(u32);
void func_0029d008(void);  // 0x0029d008: definition moved into src/anon/unit_0029d008.cpp

}
