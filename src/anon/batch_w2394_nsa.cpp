#include "../common/types.h"
extern "C" {
struct VT { u8 pad[76]; u16 id; };
struct VO { u8 pad[48]; u16 sub; };
struct Slot { u32 flags; u32 id; u32 sub; };
extern Slot D_01c94090[3];
extern char* D_0033caf4;
extern char D_0036d938[];
extern char D_0036d940[];
extern u8 D_0032bae0;
extern u32 D_00350e00[];
extern u8* D_00350df8;
VT* func_0016e920(u32);
VO* func_001947c0(s32, s32);
s32 func_00105c30(void);
u32 func_00105ee8(u8);
void func_002fee78(char*, const char*, ...);
void YS__FILE__ReadBack(char*, void*, void (*)(void), s32);
void func_001afdd0(void);
void func_00102448(u8*, s32);

static inline bool same(Slot* e, u32 id, u32 sub) { return e->id == id && e->sub == sub; }

/* 001afc00: register an (id, sub) pair in the 3-slot table (re-flag it if already present), format its
   label string and open it, then wait until the handler clears its busy flag.
   The __builtin_expect hints reproduce the original's register allocation (block frequencies). */
void YS__VOICE__ReadEntryId(u32 a, void* b);  // 0x001afc00: definition moved into src/anon/unit_001ada38.cpp
}
