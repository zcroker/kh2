#include "../common/types.h"

extern "C" {
struct W1833Info { u8 pad[0x13]; u8 kind; };
struct W1833Obj;
struct W1833Vt;
struct W1833Sub { W1833Vt* vt; };
struct W1833Vt { void* pad[27]; void (*fn)(W1833Sub*, W1833Obj**, struct W1833B**); };
struct W1833Obj {
    u8 pad0[4]; u32 flags; u8 pad8[4]; W1833Sub* sub; u8 pad10[0x18]; W1833Info* info;
    u8 pad2c[4]; u8 a30[0x54]; s32 v84; u8 pad88[0x10]; s32 v98; u8 pad9c[4]; s32 va0; u8 cnt;
};
struct W1833B { u8 pad[0xc]; s32 vc; u8 pad10[0x18]; W1833Info* info; };
struct W1833Arg { s32 a; W1833Obj* o; W1833B* b; };
s32 func_0018f010(W1833B*);
void func_001c0320(void*, W1833B*, void*);
void func_0018ef68(void*, W1833Arg*, s32);

// Bumps the object's counter, forwards the hit to its parts and notifies the listener at +0x98.
void func_0018e7c0(W1833Obj** pp, W1833B** pb);  // 0x0018e7c0: definition moved into src/anon/unit_0018d050.cpp
}
