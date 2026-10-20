#include "../common/types.h"

// C++ linkage: the build binds these to their absolute addresses.
void func_0014ccb8(void);
void func_003058d0(s32);

extern "C" {
void func_0014ca48(void);
void func_0014d4e8(void);
extern volatile s32 D_00349e04;
extern volatile s32 D_00349e08;

s32 func_0014cf18(void) {
    func_0014ccb8();
    func_0014ca48();
    D_00349e04++;
    D_00349e08++;
    func_0014d4e8();
    func_003058d0(0);
    func_003058d0(2);
    asm volatile("sync.l\n\tei");  // gcc cannot emit sync.l / ei
    return 0;
}
}
