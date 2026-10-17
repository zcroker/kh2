#include "../common/types.h"
extern "C" {
s32 func_00289310(s32);
void func_0029cdf8();
void func_0029d008();
void func_0029eaa8();
void func_0029daa0();
void func_0029cd70(s32 a0, s32 a1) {
    if (func_00289310(a0) == 0) return;
    switch (a1) {
    case 14: func_0029cdf8(); return;
    case 15: case 18: case 21: func_0029d008(); func_0029eaa8(); return;
    case 16: case 19: case 22: func_0029daa0(); return;
    }
}
s32 func_00287bc0();
void func_002af0a0(); void func_002af748(); void func_002afe18(); void func_002b05f8(); void func_002b14f0(); void func_002a2818();
void func_002af010(void) {
    switch (func_00287bc0()) {
    case 27: func_002af0a0(); return;
    case 28: func_002af748(); return;
    case 29: func_002afe18(); return;
    case 30: case 31: func_002b05f8(); return;
    case 32: func_002b14f0(); return;
    case 33: func_002a2818(); return;
    }
}
}
