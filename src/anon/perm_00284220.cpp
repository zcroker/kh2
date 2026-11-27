/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct W1572_VObj W1572_VObj;
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
typedef void (*W1572_VFn)(void *);
typedef struct W1572_VObj
{
  W1572_VFn *vt;
} W1572_VObj;
extern W1572_VObj *D_0035f2c4;
extern W1572_VObj *D_0035f2c8;
extern u8 *D_0035f2cc;
extern s32 D_0035f2d4;
extern W1572_VObj *D_0035f2d8;
extern s32 D_0035f2dc;
extern W1572_VObj *D_0035f2e0;
extern u8 D_00347e60[];
void func_00285460(void);
void Tz__Ending__SoundBufferFree(void);
void func_0031acc0(void *);
void func_00239870(void *);
void func_0031a840(void *);
void func_00106420(void *);
void func_00288b00(s32);
void func_00288c20(s32);
void func_00284220(void);  // 0x00284220: definition moved into src/anon/unit_00284220.cpp

}
