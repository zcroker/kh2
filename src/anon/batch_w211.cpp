#include "../common/types.h"

struct W211Node { W211Node* n0; W211Node* next; };
struct W211List { u32 a; u32 b; W211Node* head; };
struct W211Q { f32 a; f32 b; };
struct W211S28 { u8 p[4]; s16 n; u8 q[0x22]; u32* tbl; };
struct W211H { u8 c0, c1, c2, c3; f32 f; u32 z; u32 nx; };

extern "C" {
extern W211Q D_00359110;

void func_0011eea8(W211List* l, W211Node* x);  // 0x0011eea8: definition moved into src/anon/unit_0011c128.cpp

void func_001e1df8(u8* p);  // 0x001e1df8: definition moved into src/anon/unit_001e0cb8.cpp

void wtarget_0020e9f8(f32 a, f32 b) asm("_Z16wtarget_0020e9f8jjjj");
void wtarget_0020e9f8(f32 a, f32 b);  // 0x0020e9f8: definition moved into src/anon/unit_0020e9f8.cpp

s32 func_0028b160(W211S28* s, u32 key);  // 0x0028b160: definition moved into src/anon/unit_00288b00.cpp

void func_0031e268(W211H* h) {
    h = (W211H*)((u8*)h + 4);
    s32 i = 7;
    do {
        *(u32*)((u8*)h - 4) = 0;
        u32 k = 128; h->c0 = k; h->c1 = k; h->c2 = k; h->c3 = k;
        h->f = 1.0f; h->z = 0; h++; i--;
    } while (i != -1);
}
}
