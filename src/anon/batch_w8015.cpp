#include "../common/types.h"
extern "C" {
void func_00167448(const char*);
void func_002f6870(s32, void*, s32);
void func_002f74c8(s32);
void func_002f7f18(s32);
void func_00308b30(s32);
void func_0030a690();
s32 func_0030ec50();
s32 func_0030eca0(const char*);
extern u8 D_004f4250[];

// IRX module load list. The two pad2/ds2o.irx loads are a 2-iteration loop:
// gcc fully unrolls it and hoists only %hi of the string into s0.
void func_001674c8(void) {
    func_00308b30(0);
    func_0030a690();
    func_002f74c8(0);
    func_002f7f18(2);
    while (func_0030eca0("cdrom0:\\IOPRP300.IMG") == 0) {}
    while (func_0030ec50() == 0) {}
    func_00308b30(0);
    func_002f74c8(0);
    func_002f6870(10, D_004f4250, 0x1000);
    func_002f7f18(2);
    func_00167448("sio2man.irx");
    func_00167448("sio2d.irx");
    func_00167448("dbcman.irx");
    for (int i = 0; i < 2; i++) func_00167448("pad2/ds2o.irx");
    func_00167448("mcman.irx");
    func_00167448("mcserv.irx");
    func_00167448("libsd.irx");
    func_00167448("libssl.irx");
}
}
