#include "../common/types.h"
extern "C" {

struct S10_w1756 { s16 h[5]; };
extern S10_w1756 D_0032bae0;
void func_00195750();
void func_00104f58(S10_w1756*, s32, s32, s32, s32);

void func_002d2070()
{
    S10_w1756 x = D_0032bae0;
    func_00195750();
    func_00104f58(&x, 1, 0, 0, 0);
}

void func_002d88a8()
{
    S10_w1756 x = D_0032bae0;
    func_00195750();
    func_00104f58(&x, 1, 0, 0, 0);
}

}
