/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct W1630Menu W1630Menu;
typedef struct W1630Seq W1630Seq;
typedef struct W1630Sprite W1630Sprite;
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
struct W1630Seq
{
  u8 pad[344];
};
struct W1630Sprite
{
  u8 pad0[24];
  W1630Seq seq;
  u8 pad1[28];
  void *parent;
  s32 flag;
  u8 pad2[4];
};
struct W1630Menu
{
  u8 pad0[32];
  s32 x;
  s32 y;
  u8 pad1[8];
  W1630Sprite root;
  u8 pad2[40];
  W1630Seq title;
  W1630Sprite base;
  W1630Sprite cursor;
  W1630Sprite items[5];
  W1630Sprite items2[5];
  W1630Sprite extra;
  u32 p1;
  u32 v1;
  s32 f6152;
  u32 p2;
  u32 v2;
  s32 f6164;
  s32 count;
  s32 hasExtra;
  s32 f6176;
};
void dk__SpriteImage__create(W1630Sprite *, u32, u32, u32);
void dk__Sprite__create(W1630Sprite *, u32, u32, void *, u32, u32);
void func_001396b0(W1630Sprite *) asm("_ZN2Tz6Select10BeginLeaveEz");
void func_0031a260(W1630Sprite *, u32) asm("_ZN2Tz6Select7SetFlagEz");
void func_00139660(W1630Sprite *) asm("_ZN2dk5Obj2D19getParentSeqColorOnEv");
void func_00139688(W1630Sprite *) asm("_ZN2dk5Obj2D21getParentSeqAlphaOnlyEv");
void func_00138c68(W1630Sprite *, s32, s32) asm("_ZN2dk6Sprite12setOffsetPosEii");
void func_00138c40(W1630Sprite *, s32, s32) asm("_ZN2dk6Sprite6setPosEii");
void YI__SEQUENCE__Init(W1630Seq *, u32, void *);
void func_00239c38(W1630Seq *, s32) asm("_ZN2YI8SEQUENCE14SetNumberForceEi");
void func_0023acd8(W1630Seq *);
s32 func_0023a950(W1630Seq *) asm("_ZN2YI8SEQUENCE10GetActiveXEv");
s32 func_0023a988(W1630Seq *) asm("_ZN2YI8SEQUENCE10GetActiveYEv");
s32 func_0023aa78(W1630Seq *) asm("_ZN2YI8SEQUENCE10GetParamCrEv");
s32 func_0023aa98(W1630Seq *) asm("_ZN2YI8SEQUENCE10GetParamExEv");
void func_0014fc40(W1630Menu *, u32, s32, u32, u32, s32);
void func_00150660(W1630Menu *);
inline static void W1630_setParent(W1630Sprite *obj, W1630Sprite *parent)
{
  obj->parent = parent;
  func_001396b0(obj);
  if (obj->parent != 0)
  {
    obj->flag = 0;
    func_001396b0(obj);
    if (obj->flag != 0)
    {
      func_0031a260(obj, 0);
    }
  }
}

void dk__COUNTER__create(W1630Menu *self, u32 a1, u32 a2, s32 mode, s32 hasExtra, s32 count, u32 *p1, u32 *p2, u32 a8);  // 0x0014fe00: definition moved into src/anon/unit_0014ecb8.cpp

}
