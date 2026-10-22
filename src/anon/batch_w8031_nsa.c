#include "../common/types.h"
s32 func_00170b30(s32);
void func_001b7f30(void);
void func_001b7f88(s32);
extern u32 D_003511bc;
extern u8 D_003511c3;
extern u32 D_01d48cb8;
typedef struct { u32 start; u32 end; u32 data; } Buf;
void func_001b7e68(Buf* b, s32 n) {
    func_001b7f30();
    if (n != 0) {
        n++;
        if ((u32)n < 1024) {
            D_003511c3 = 0;
            if (D_003511bc < D_01d48cb8 + n * 16) func_001b7f88(n * 16);
            b->start = D_01d48cb8;
            D_01d48cb8 += n * 16;
        } else {
            b->start = func_00170b30(n * 16);
            D_003511c3 = 1;
        }
        b->end = b->start + n * 16;
        b->data = b->start + 16;
    }
}
