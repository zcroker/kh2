#include "./types.h"

// REGION (0x105af8-0x105c68): finds the disc's region from the product code in SYSTEM.CNF.

extern "C" {
const char* D_0033caf0;                        // language
const char* D_0033caf4;                        // voice language
const char* D_0033caf8 = "\\SYSTEM.CNF;1";
s32 D_0033cafc;                                // region (1-8)
const char* D_0033cb00[8] = { "jp", "us", "uk", "it", "sp", "gr", "fr", "fm" };
const char* D_0033cb20[8][3] = {
    { "SLPM", "662", "33" },
    { "SLUS", "210", "05" },
    { "SLES", "541", "14" },
    { "SLES", "542", "34" },
    { "SLES", "542", "35" },
    { "SLES", "542", "33" },
    { "SLES", "542", "32" },
    { "SLPM", "666", "75" },
};

void func_001ae590(void*, const char*);
void func_001ae4c0(u32, u32, void*);
s32 strncmp(const void*, const void*, u32);
}

namespace REGION {

const char** GetProductCode(s32 i);

void Init(s32 mode) {
    D_0033cafc = mode;
    D_0033caf0 = D_0033cb00[mode - 1];
    switch (mode) {
    case 3: D_0033caf4 = D_0033cb00[1]; break;
    case 8: D_0033caf4 = D_0033cb00[0]; break;
    default: D_0033caf4 = D_0033caf0; break;
    }
}

// Reads SYSTEM.CNF and picks the region whose product code it names.
void Detect(void) {
    u32 info[12];
    u8 buf[2048];
    s32 i;
    func_001ae590(info, D_0033caf8);
    func_001ae4c0(info[0], (info[1] + 2047) >> 11, buf);
    for (i = 1; i < 9; i++) {
        if (strncmp(buf + 16, GetProductCode(i)[0], 4) == 0 &&
            strncmp(buf + 21, GetProductCode(i)[1], 3) == 0 &&
            strncmp(buf + 25, GetProductCode(i)[2], 2) == 0) {
            Init(i);
            return;
        }
    }
}

s32 Get(void) {
    return D_0033cafc;
}

s32 IsDebug(void) {
    return 0;
}

const char** GetProductCode(s32 i) {
    return D_0033cb20[i - 1];
}

}  // namespace REGION
