/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct WinReq WinReq;
typedef struct WinSlot WinSlot;
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
struct WinSlot
{
  void **obj;
  s16 id;
  s16 group;
};
extern WinSlot D_01dad9c0[32];
struct WinReq
{
  u32 _0;
  s16 idx;
  s16 group;
  s16 id;
  s16 mode;
  s16 kind;
};
void *W1688_area_alloc(u32) asm("_ZN4AREA5AllocEj");
void W1688_obj2d_ctor(void *self, void *win) asm("_ZN2YS12WINDOW_OBJ2DC1EPNS_6WINDOWE");
void func_00102448(u32, s32) asm("_ZN2Tz9TaskYieldEz");
void func_001ad0f8(void *, s32, s32);
void func_001ad330(void *, s32);
void sa__EVENT__waitMessageOn(void);
void func_00225a20(void);
s32 sa__EVENT__isJumpMode(s32);
s32 sa__EVENT__checkStart(s32);
inline static bool W1688_busy(void **o)
{
  return (*((s32 *) (((u8 *) o) + 0x70))) != 3;
}

void func_0022d9b0(WinReq *req, u32 task);  // 0x0022d9b0: definition moved into src/anon/unit_0022d358.cpp

}
