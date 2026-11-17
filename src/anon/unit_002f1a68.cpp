#include "../common/types.h"

// Game file 0x2f1a68-0x2f1b48: gumibattle/advice.bin (loaded into a static buffer; 64-byte
// entries after an 8-byte header) and a flag bitset test/set on the bit array at 0x33cae8.

extern "C" {
void func_00168388(const char*, void*, void (*)(void), u32);
extern u32 D_0033cae8[];
}

const char* D_00363c28 = "gumibattle/advice.bin";
u8* D_00363c2c;
// Load buffer for advice.bin (size not known; the next known .bss object is at 0x1e2d960).
static u8 D_01e2c100[0x1860] __attribute__((aligned(64)));

extern "C" {

void func_002f1a68(void) {
    D_00363c2c = D_01e2c100;
}

void func_002f1a80(void) {
    D_00363c2c = 0;
    func_00168388(D_00363c28, D_01e2c100, func_002f1a68, 0);
}

u32 func_002f1ab8(void) {
    return *(u32*)(D_00363c2c + 4);
}

u8* func_002f1ac8(u32 n) {
    return D_00363c2c + (n << 6) + 8;
}

bool func_002f1ae0(u32 n) {
    return (D_0033cae8[n >> 5] & (1 << (n & 31))) != 0;
}

void func_002f1b10(u32* n) {
    D_0033cae8[*n >> 5] |= 1 << (*n & 31);
}

}
