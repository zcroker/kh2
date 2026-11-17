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
typedef void (*DtorFn)(void *);
void func_00106420(void *) asm("_ZN2Tz12LoadDataFreeEz");
void func_00239870(void *) asm("_ZN2YI8SEQUENCED1Ev");
extern u8 D_0035f0f0;
extern u32 D_0035f0f8;
extern void *D_0035f0fc;
extern u8 *D_0035f0f4;
extern u8 D_00347e60[];
extern u8 D_00347f98[];
inline static void vdtor(void *e)
{
  (*((DtorFn *) ((*((u8 **) e)) + 12)))(e);
}

void func_0026bab8(void);  // 0x0026bab8: definition moved into src/anon/unit_0026a900.cpp

}
