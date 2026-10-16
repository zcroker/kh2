/* found by decomp-permuter (nightly.py) */
extern "C" {


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
void func_0013dbb0(void);
volatile short func_001a2a50(u32, s32, s32, s32);
void func_001a3458(u32, s32);
s32 func_002570a0(s32);
u16 *func_002632d0(s32);
s32 func_002811b0(s32, s32);
extern s32 D_0035f010;
void func_00263778(s32 a0)
{
  u16 id = *func_002632d0(func_002570a0(10));
  s32 v = func_002811b0(D_0035f010, a0);
  func_001a2a50(id, v, 0, 100);
  func_001a3458(id, 100);
  func_0013dbb0();
}

}
