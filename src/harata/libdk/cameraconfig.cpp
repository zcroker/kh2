#include "../../common/types.h"

// dk::CameraConfig (0x158450-0x1585e8): pad tests for the camera controls. The button masks
// for zoom in/out and turn left/right depend on the config's camera settings.

u64 D_0034a970[4] = { 0x40000, 0x80000, 0x100000, 0x200000 };  // zoom in, zoom out, left, right

extern "C" {
u8 func_00242d58(void);
u32 func_00242ce8(void);
u32 isCameraAuto(void) asm("_ZN2Tz6Config12isCameraAutoEv");

s32 func_00158450(u64* p) {
    s32 i = func_00242d58();
    return (*p & D_0034a970[i]) != 0;
}

s32 func_001584a0(u64* p) {
    u8 b = func_00242d58();
    return (*p & D_0034a970[(u8)(b ^ 1)]) != 0;
}

s32 func_001584f8(u64* p) {
    u32 i = func_00242ce8();
    return (*p & D_0034a970[i + 2]) != 0;
}

s32 func_00158548(u64* p) {
    u8 i = func_00242ce8() ^ 1;
    return (*p & D_0034a970[i + 2]) != 0;
}

}  // extern "C"

u32 isManual(u64* pad) asm("_ZN2dk12CameraConfig8isManualEPN2YS3PADE");
u32 isManual(u64* pad) {
    u32 r = 1;
    if (!(*pad & 0x100000000ULL)) r = 0;
    if (!isCameraAuto()) r = !r;
    return r;
}
