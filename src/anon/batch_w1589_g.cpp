#include "../common/types.h"

extern "C" {

s32 func_00197920(void);
void func_002ba978(s32);
s32 func_002ef7b8(void);
void func_002bd680(void);
s32 func_00103570(void);
void* func_001063c0(s32, s32);
void func_0023f800(void*);
void func_00323408(void*);
void func_001a8bb8(void*);
extern u8 D_0035f590;
extern u8 D_0035f591;
extern void* D_0035f58c;
extern u8 D_0035f5a8;
extern u8 D_0035f5a9;
extern void* D_0035f5a4;
extern u8 D_0035f0f0;
extern void* D_0035f0f4;
extern void* D_0035f0fc;

void func_00242740(s32 a)
{
    if (a < 0) {
        a = func_00197920() ? 1 : 2;
    }
    func_002ba978(a);
    if (func_002ef7b8()) func_002bd680();
}

void func_002957b8(void)
{
    void* o;
    D_0035f590 = 0;
    D_0035f591 = 0;
    o = func_001063c0(28, func_00103570());
    func_0023f800(o);
    D_0035f58c = o;
}

void func_002994f8(void)
{
    void* o;
    D_0035f5a8 = 0;
    D_0035f5a9 = 0;
    o = func_001063c0(28, func_00103570());
    func_0023f800(o);
    D_0035f5a4 = o;
}

void func_0026ba48(void)
{
    void* o;
    D_0035f0f0 = 0;
    o = func_001063c0(6252, func_00103570());
    func_00323408(o);
    D_0035f0f4 = o;
    o = func_001063c0(4, func_00103570());
    func_001a8bb8(o);
    D_0035f0fc = o;
}

}
