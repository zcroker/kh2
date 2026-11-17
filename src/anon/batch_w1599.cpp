#include "../common/types.h"
namespace n002a2010 {
struct El {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~El();
    u8 pad[432];
};
struct Ab {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~Ab();
    u8 pad[0x194];
};
extern "C" {
extern void* D_0035f5e4;
extern u8* D_0035f5e8;
extern u8 D_00347e60[];
extern u8 D_00347f98[];
void func_00106420(void*);
void func_0031acc0(void*);
void func_00239870(void*);

void func_002a2010(void);  // 0x002a2010: definition moved into src/anon/unit_002a1d38.cpp
}
}

namespace n002ac2e8 {
struct Ent { u8 a; u8 b; u8 pad[6]; u16 id; };
struct Bits {
    u32 w[2];
    s32 Test(u32 b) { return w[b >> 5] & (1 << (b & 31)); }
    void Set(u32 b) { u32* p = &w[b >> 5]; *p |= 1 << (b & 31); }
};
struct Flags { u8 pad[0x144]; Bits x[10]; Bits y[10]; };
extern "C" {
extern Flags* D_0035f610;
Flags* func_002a9d68(void);
Ent* func_001d9e30(Ent*);
s32 func_001d9d48(Ent*);
s32 func_00181500(u16);

void func_002ac2e8(void);  // 0x002ac2e8: definition moved into src/anon/unit_002a99c8.cpp
}
}

namespace n0028cc78 {
struct Sub { u8 pad[184]; u32 flags; };
struct Ent { u8 pad[24]; Sub sub; u8 pad2[408 - 24 - 188]; };
struct Pair { s16 a, b; };
union GP { Pair* p; s16 h; };
union GE { Ent* p; u32 w; s16 h; };
struct Obj { u8 pad[40]; s32 x28; };
extern "C" {
extern GE D_0035f3fc;
extern GP D_0035f400;
union GW { u32* p; s16 h; };
extern GW D_0035f408;
extern s32* D_0035f40c;
extern u32 D_0035f410;
Obj* func_0023f1b0(u8*);
s32 func_0023c4b8(Obj*, s32);
u8* func_00236ca8(s32, s32);
void func_001386e0(Ent*, s32, s32, u8*, s32, s32);
static inline void setf(Sub* s) { s->flags |= 8; }
void func_0028cc78(s32 idx, s32 a1, s32 a2, u8* a3, s32 a4, s32 a5);  // 0028cc78: moved to src/anon/unit_0028c878.cpp
}
}
