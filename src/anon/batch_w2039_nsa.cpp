#include "../common/types.h"
// Built with -fno-strict-aliasing (_nsa).

extern "C" {
void func_00102b58(void);
void func_00102b90(void);
void func_00102a70(void);
}

struct W2039Hooks {
    u8 pad[0x20];
    void (*f20)(void);
    void (*f24)(void);
    inline void Set() { f20 = func_00102a70; f24 = func_00102b90; }
};
struct W2039Flag { s32 a; inline void Clear() { a = 0; } };

extern "C" {

extern W2039Hooks D_0032b968;
extern W2039Flag D_0032b994;

void func_00102bd8(void) {
    D_0032b968.Set();
    D_0032b994.Clear();
    func_00102b58();
}

}
