#include "../common/types.h"
extern "C" {

// --------------------
// 0031b130: constructor of a big object (0x3cf0 bytes) built from many embedded
// sub-objects and arrays. Each element constructor is written out inline; vtables
// are stored as plain words (the classes' vtables live in the original binary).
//   Elem408 (vt 00347e60): word at +12 cleared, sub-object at +24 (func_00239700)
//   Elem848 : 00347f98 base (func_0031a838 at +12) -> 00347e60 -> 0034a800, YI::IMAGE at +416
//   Elem412 : same chain ending in vt 0034a958
//   Elem592 : 00347f98 base -> vt 00348658, sub-objects at +32 (func_0013ee88), +320 (func_0014b668)
void func_00239700(void*);
void func_002361a0(void*);
void func_0031a838(void*);
void func_0013ee88(void*);
void func_0014b668(void*);
extern u8 D_00347f98[], D_00347e60[], D_00348608[], D_0034a800[], D_0034a920[], D_0034a958[],
    D_00348678[], D_00348658[];

void func_0031b130(u8* t);  // 0x0031b130: definition moved into src/anon/unit_003197d0.cpp

}
