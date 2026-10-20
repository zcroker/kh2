#include "../common/types.h"

struct W1778Obj;
struct W1778ObjVt { void* f[16]; s32 (*isOk)(W1778Obj*); };
struct W1778Obj { W1778ObjVt* vt; };

extern "C" {
extern W1778Obj* D_0034e948;
extern s32 D_01d48cb0;
extern u8 D_00351eb8[];
s32 func_0019ba60(W1778Obj*);
void func_001b5250(s32, s32);
bool func_001c8db8(void*, s32);
void func_001d4180(void);

void func_001b4340(void) {
    W1778Obj* o = D_0034e948;
    if (D_01d48cb0 == 0) {
        if (func_0019ba60(o) && o->vt->isOk(o)) {
            bool b = !func_001c8db8(D_00351eb8, 0);
            if (b) func_001d4180();
        }
    } else {
        func_001b5250(D_01d48cb0, 0);
    }
}
}
