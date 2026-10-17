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
s32 func_001688c8(void *);
s32 func_00170b30(s32);
void func_001682b8(void *, s32);
void func_002ba1b8(s32, s32, s32);
void func_002ba188(s32, s32, s32);
s32 func_002b6f78(void);
void func_002b6ab8(void);
void func_00170c00(s32);
extern u8 D_00374f30[];
extern u8 D_00374f40[];
extern u8 D_00374f50[];
extern u8 D_00374f60[];
void func_002b9c80(void)
{
  s32 new_var;
  s32 size;
  s32 buf;
  s32 p;
  size = func_001688c8(D_00374f30);
  buf = func_00170b30((size + 0x83f) & (~0x7ff));
  p = (buf + 0x3f) & (~0x3f);
  func_001682b8(D_00374f30, p);
  func_002ba1b8(2, p, size);
  while (func_002b6f78())
  {
    func_002b6ab8();
  }

  func_00170c00(buf);
  size = func_001688c8(D_00374f40);
  buf = func_00170b30((size + 0x83f) & (~0x7ff));
  p = (buf + 0x3f) & (~0x3f);
  func_001682b8(D_00374f40, p);
  func_002ba1b8(3, p, size);
  while (func_002b6f78())
  {
    func_002b6ab8();
  }

  func_00170c00(buf);
  size = func_001688c8(D_00374f50);
  buf = func_00170b30((size + 0x83f) & (~0x7ff));
  p = (buf + 0x3f) & (~0x3f);
  func_001682b8(D_00374f50, p);
  func_002ba188(2, p, size);
  while (func_002b6f78())
  {
    func_002b6ab8();
  }

  func_00170c00(buf);
  size = (new_var = func_001688c8(D_00374f60));
  buf = func_00170b30((size + 0x83f) & (~0x7ff));
  p = (buf + 0x3f) & (~0x3f);
  func_001682b8(D_00374f60, p);
  func_002ba188(3, p, new_var);
  while (func_002b6f78())
  {
    func_002b6ab8();
  }

  func_00170c00(buf);
}

}
