/* found by decomp-permuter (nightly.py) */
extern "C" {


typedef struct Heap24e850 Heap24e850;
typedef struct Heap24e850Vt Heap24e850Vt;
typedef struct Sys24e850 Sys24e850;
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
struct Heap24e850;
struct Heap24e850Vt
{
  u8 *(*alloc)(Heap24e850 *, s32, s32);
};
struct Heap24e850
{
  Heap24e850Vt *vt;
};
struct Sys24e850
{
  u8 pad[20];
  Heap24e850 *heap;
};
extern u8 D_0035eb98[];
extern u8 D_0035ebb8[];
extern u8 *D_0035ee08;
extern u8 *D_0035ee0c;
extern u32 D_0035ee04;
extern Sys24e850 *D_00347f80;
extern u8 D_00372380;
extern u8 D_00372388;
u8 *func_0023ee30(s32);
void func_002369a0(u8 *);
void func_0023c008(u8 *);
void func_0028d7f0(u8 *, s32, s32, s32, s32, s32, s32, s32, s32);
void func_00288ce0(u32, s32, s32, s32, s32);
void func_002891f0(u32, s32, s32, s32, s32);
s32 func_002891e8(u32) asm("_ZN2Tz6Select10GetCurrentEv");
void func_0024f348(void);
void func_0023f1e0(u8 *, s32, u8 *, void *, void *, s32, s32, s32);
void func_0023f6c0(u8 *, s32);
void func_00287cc0(s32) asm("_ZN2Tz8Selector8SetStateEi");
void func_0024e850(void)
{
  u8 *o;
  u8 *p;
  s32 i;
  o = func_0023ee30(160);
  *((u32 *) (o + 12)) = 0;
  *((u8 **) o) = D_0035eb98;
  func_002369a0(o + 24);
  func_0023c008(o + 48);
  p = o;
  D_0035ee08 = o;
  func_0028d7f0(p, 30002, 0, 0, 0, 1, 0, 0, 0);
  for (i = 0; i < 5; i++)
  {
    func_00288ce0(D_0035ee04, 0, i, 0, 0);
  }

  func_002891f0(D_0035ee04, 0, 0, -1, -1);
  func_0024f348();
  func_002891f0(D_0035ee04, func_002891e8(D_0035ee04), 0, -1, -1);
  p = D_00347f80->heap->vt->alloc(D_00347f80->heap, 76, 0);
  *((u32 *) (p + 12)) = 0;
  *((u8 **) p) = D_0035ebb8;
  D_0035ee0c = p;
  func_0023f1e0(p, 30003, D_0035ee08, &D_00372380, &D_00372388, -1, 0, 0);
  func_0023f6c0(D_0035ee0c, 2);
  func_00287cc0(0);
}

}
