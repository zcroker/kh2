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
extern void **D_0034b240;
extern void **D_0034b278;
void func_0031dd50(void *);
void func_0015de98(void)
{
  void **heap = D_0034b278;
  void **new_var3;
  void **o = (void **) ((void *(*)(void *, u32, void *)) (*((void ***) D_0034b278))[0])(heap, 4928, __builtin_return_address(0));
  void **new_var;
  void **new_var2;
  func_0031dd50(o);
  D_0034b240 = o;
  new_var = o;
  new_var2 = new_var;
  new_var3 = *((void ***) new_var2);
  o = new_var3;
  ((void (*)(void *)) o[0])(new_var2);
}

}
