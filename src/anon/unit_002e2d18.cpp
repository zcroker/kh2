#include "../common/types.h"

// Ti::MG_EHSidecar (the side-car shooting minigame), second part 0x2e2d18-0x2e2ed0 (after 0x2e2c98).
// Linked unit. The vtables and task tables (0x362e80-0x362f48) stay retail data; the up vector set by
// the static initialiser is .data at 0x362e70.

typedef unsigned int u128 __attribute__((mode(TI)));
struct FV6 {
    f32 x, y, z, w;
    FV6() {}
    FV6(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    FV6(const f32* v, f32 c, f32 d) { x = v[0]; y = v[1]; z = c; w = d; }
    ~FV6() {}
} __attribute__((aligned(16)));
extern "C" {
extern u8* D_00361f60 asm("D_00361f60");
extern u8 D_00362eb8[] asm("D_00362eb8");
void func_002e70b0(void*);
void func_00106420(void*);
void func_002cea28(void*);
void func_00105110(void*);
void func_002cebc0(void*);
s32 func_002e34c8(void*);
void func_002e2728(u8*, s32, s32);
void func_002ceb08(void*);
void func_002e2660(u8*);
void func_002e26c0(u8*);
}
void wtarget_002e2440(void*) asm("_Z16wtarget_002e2440jjjj");
void wtarget_002e2570(void*) asm("_Z16wtarget_002e2570jjjj");
void wtarget_002e27c8(void*) asm("_Z16wtarget_002e27c8jjjj");

void ceb08_noarg(void) asm("func_002ceb08");
namespace Ti {
struct MG_EHSidecar {
    static void MoveToBeforePoint();
    static s32 GetCurrentPoint();
};
}

// 0x2e2c98 (a FVector maker: scale 25, normalise, w = length) is not linked: gcc hoists the
// literal load above the stores, retail does not. Two units around it.

namespace Ti {
void MG_EHSidecar::MoveToBeforePoint() {
    u8* m = D_00361f60;
    if (m) ceb08_noarg();
    func_002e26c0(m);
}
}

extern "C" void func_002e2d50(void) {
    u8* m = D_00361f60;
    if (m != 0) {
        asm volatile("");
        ceb08_noarg();
    }
    func_002e2660(m);
}

void u_tail4_002e2d88(s32 a, u32 b) asm("_Z16u_tail4_002e2d88jjjj");
void u_tail4_002e2d88(s32 a, u32 b) {
    u8 c = b;
    u8* m = D_00361f60;
    if (m) ceb08_noarg();
    *(s32*)(m + 276) = a;
    m[280] = c;
}

extern "C" s32 func_002e2dd8(void) {
    u8* m = D_00361f60;
    if (m) ceb08_noarg();
    return *(s32*)(m + 272) != 0;
}

namespace Ti {
s32 MG_EHSidecar::GetCurrentPoint() {
    u8* m = D_00361f60;
    if (m) ceb08_noarg();
    return *(s32*)(m + 264);
}
}

FV6 g_up_2e2e70 asm("D_00362e70") = FV6(0.0f, 0.0f, 1000.0f, 0.0f);
