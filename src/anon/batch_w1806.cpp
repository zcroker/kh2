#include "../common/types.h"
extern "C" {
s32 func_00224e90(void);
void func_0014ce20(s32);
void func_0022b898(void);
void func_0022b730(void);
void func_00225208(void);
s32 func_00224c20(void);
void func_00229370(void);
void func_00228f18(void);
void func_00228e58(void);
void func_002289f0(void);
void func_00228618(void);
s32 func_002249a8(s32);

// The default call stores into r and returns through the shared return,
// so it stays a jal; the case calls are direct returns (sibcalls).
s32 func_00224d48(void) {
    s32 v;
    s32 r = func_00224e90();
    if (r) {
        func_0014ce20(0);
        func_0022b898();
        func_0022b730();
        func_00225208();
        v = func_00224c20();
        switch (v) {
        case 1: func_00229370(); return func_002249a8(v);
        case 2: func_00228f18(); return func_002249a8(v);
        case 3: func_00228e58(); return func_002249a8(v);
        case 4: func_002289f0(); return func_002249a8(v);
        case 5: func_00228618(); return func_002249a8(v);
        default: r = func_002249a8(0); break;
        }
    }
    return r;
}
}
