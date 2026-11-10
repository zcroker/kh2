#include "../common/types.h"
// Frame-border GS sprite packets: fill RGBAQ / XYZ2 data words (z from the source), then kick the packets.
struct Src166da8 { u8 on; u8 mode; u8 pad[2]; s32 z; };
extern u64 D_0034c990[];
extern u64 D_0034caf0[];
extern u8 D_0034cce0[];
extern u8 D_0034d150[];
extern u8 D_0034d180[];
extern "C" {
void func_0014d8d0(void*);
void func_00166da8(Src166da8* p)
{
    if (!p->on) return;
    if (!p->mode) {
        D_0034c990[4] = ((u64)p->z << 32) | 0x73007000;
        D_0034c990[5] = ((u64)p->z << 32) | 0x8d009000;
        D_0034caf0[3] = 0x180808080ULL;
        D_0034caf0[5] = ((u64)p->z << 32) | 0x72e06fe0;
        D_0034caf0[7] = ((u64)p->z << 32) | 0x8ce08fe0;
        D_0034caf0[9] = 0x140808080ULL;
        D_0034caf0[11] = ((u64)p->z << 32) | 0x72c06fc0;
        D_0034caf0[13] = ((u64)p->z << 32) | 0x8cc08fc0;
        D_0034caf0[15] = 0x140808080ULL;
        D_0034caf0[17] = ((u64)p->z << 32) | 0x73007000;
        D_0034caf0[19] = ((u64)p->z << 32) | 0x8d009000;
        D_0034caf0[21] = 0x140808080ULL;
        D_0034caf0[23] = ((u64)p->z << 32) | 0x73006fc0;
        D_0034caf0[25] = ((u64)p->z << 32) | 0x8d008fc0;
        D_0034caf0[27] = 0x140808080ULL;
        D_0034caf0[29] = ((u64)p->z << 32) | 0x72c07000;
        D_0034caf0[31] = ((u64)p->z << 32) | 0x8cc09000;
        D_0034caf0[33] = 0x120808080ULL;
        D_0034caf0[35] = ((u64)p->z << 32) | 0x72c06fe0;
        D_0034caf0[37] = ((u64)p->z << 32) | 0x8cc08fe0;
        D_0034caf0[39] = 0x120808080ULL;
        D_0034caf0[41] = ((u64)p->z << 32) | 0x72e06fc0;
        D_0034caf0[43] = ((u64)p->z << 32) | 0x8ce08fc0;
        D_0034caf0[45] = 0x120808080ULL;
        D_0034caf0[47] = ((u64)p->z << 32) | 0x73006fe0;
        D_0034caf0[49] = ((u64)p->z << 32) | 0x8d008fe0;
        D_0034caf0[51] = 0x120808080ULL;
        D_0034caf0[53] = ((u64)p->z << 32) | 0x72e07000;
        D_0034caf0[55] = ((u64)p->z << 32) | 0x8ce09000;
        func_0014d8d0(D_0034cce0);
    } else {
        D_0034caf0[3] = 0x120808080ULL;
        D_0034caf0[5] = ((u64)p->z << 32) | 0x72d06fe0;
        D_0034caf0[7] = ((u64)p->z << 32) | 0x8cd08fe0;
        D_0034caf0[9] = 0x120808080ULL;
        D_0034caf0[11] = ((u64)p->z << 32) | 0x72e06fd0;
        D_0034caf0[13] = ((u64)p->z << 32) | 0x8ce08fd0;
        D_0034caf0[15] = 0x120808080ULL;
        D_0034caf0[17] = ((u64)p->z << 32) | 0x72f06fe0;
        D_0034caf0[19] = ((u64)p->z << 32) | 0x8cf08fe0;
        D_0034caf0[21] = 0x120808080ULL;
        D_0034caf0[23] = ((u64)p->z << 32) | 0x72e06ff0;
        D_0034caf0[25] = ((u64)p->z << 32) | 0x8ce08ff0;
        D_0034caf0[27] = 0x180808080ULL;
        D_0034caf0[29] = 0x3a9872e06fe0ULL;
        D_0034caf0[31] = 0x3a988ce08fe0ULL;
        D_0034caf0[33] = 0x140808080ULL;
        D_0034caf0[35] = 0x3a9872c06fe0ULL;
        D_0034caf0[37] = 0x3a988cc08fe0ULL;
        D_0034caf0[39] = 0x140808080ULL;
        D_0034caf0[41] = 0x3a9872e06fc0ULL;
        D_0034caf0[43] = 0x3a988ce08fc0ULL;
        D_0034caf0[45] = 0x140808080ULL;
        D_0034caf0[47] = 0x3a9873006fe0ULL;
        D_0034caf0[49] = 0x3a988d008fe0ULL;
        D_0034caf0[51] = 0x140808080ULL;
        D_0034caf0[53] = 0x3a9872e07000ULL;
        D_0034caf0[55] = 0x3a988ce09000ULL;
        func_0014d8d0(D_0034d150);
    }
    func_0014d8d0(D_0034d180);
}
}
