#include "../common/types.h"
// 001c1268 and 001c1308 are twins: placement new into an inline constructor.
// The const member makes the mode store RTX_UNCHANGING, which fixes the prologue schedule.
inline void* operator new(unsigned int, void* p) { return p; }
struct W8021Pool { u8 pad[0x1c]; };
struct W8021Q1 { u8 pad[0x1b4]; f32 f1b4; };
struct W8021A {
    u8 p0[0x160]; u32 m160; u8 p1[0x48c - 0x164]; W8021Q1* q48c; u8 p2[0x7f8 - 0x490]; u32 m7f8;
    u8 p3[0xaec - 0x7fc]; s32 maec; u8 p4[0xb50 - 0xaf0]; s32 mb50;
};
extern "C" {
s32 func_001050c8(void);
void func_001db710(W8021Pool*, s32, s32, s32);
void* func_001050d8(s32);
void func_001788b8();
s32 func_00179c08(W8021A*, s32);
s32 func_0017a538(W8021A*);
s32 func_0019c218(W8021A*, s32);
void func_001b6b10(W8021A*, s32);
void func_001b6c20(W8021A*);
s32 func_001b8e88(s32);
s32 func_001bc2a8(s32, W8021A*, s32);
s32 func_001c8ab0();
void func_001d1408(W8021A*);

struct W8021Buf {
    s32 a; const s32 mode; s32 sz; s32 c; s32 d; W8021Pool pool; void* buf; s32 e;
    inline __attribute__((always_inline)) W8021Buf(s32 a_, s32 mode_, s32 b, s32 n)
        : mode(mode_) {
        a = a_;
        sz = 16;
        d = 0;
        c = 0;
        func_001db710(&pool, func_001050c8(), b, n);
        e = 0;
        switch (mode_) {
        case 0: buf = func_001050d8(n << 4); break;
        case 1: buf = func_001050d8(n << 4); break;
        }
    }
};

// 001c1268: moved to src/anon/unit_001c0638.cpp
void func_001c1268(W8021Buf* o, s32 a, s32 mode, s32 b, s32 n);

// 001c1308: moved to src/anon/unit_001c0638.cpp
void func_001c1308(W8021Buf* o, s32 a, s32 mode, s32 b, s32 n);

static inline u8 lt4(s32 id, W8021A* a) { return func_001bc2a8(id, a, 0) < 4; }
static inline u32 is12(W8021A* a) { return a->mb50 == 12; }

void func_001d0f08(W8021A* a);  // 0x001d0f08: definition moved into src/anon/unit_001d0cb8.cpp
}
