#include "../common/types.h"

extern "C" {

extern u8 D_0033cc18[];
void func_00106108(void*);

struct S { void* vt; u32 a; u32 b; };

// Initialises an object (vtable 0x33cc18 and two words) and continues in func_00106108.
// The empty asm emits nothing; it hides where p points so the scheduler keeps the
// stores after the ra save, as in the original.
void func_001060b8(S* q, u32 a1, u32 a2) {
    register S* p asm("$4") = q;
    asm("" : "+r"(p));
    p->vt = D_0033cc18;
    p->b = a2;
    p->a = a1;
    func_00106108(p);
}

// Twin of func_001060b8 (same body).
void func_001060e0(S* q, u32 a1, u32 a2) {
    register S* p asm("$4") = q;
    asm("" : "+r"(p));
    p->vt = D_0033cc18;
    p->b = a2;
    p->a = a1;
    func_00106108(p);
}

}
