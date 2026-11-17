#include "../common/types.h"

struct W246Sub { u8 pad[184]; u32 flags; inline void set(u32 f) { flags |= f; } };
struct W246Obj { u8 pad[24]; W246Sub sub; };
union W246UP { u8* c; W246Obj* o; s32* i; };

struct W246Bits { u32 w[8];
  inline bool test(u32 i) { return (w[i >> 5] & (1 << (i & 31))) != 0; }
  inline void set(u32 i) { u32* p = w; p += i >> 5; *p |= 1 << (i & 31); } };
struct W246Sram { u8 pad[136]; W246Bits bits; };
struct W246Score { u8 v; inline bool ok() { return v >= 2; } };

extern "C" {
s32 isPause(void) asm("_ZN2Tz5Pause7isPauseEv");
void StartFade(void (*)()) asm("_ZN2Tz5Pause9StartFadeEPFvvE");
void u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void* GetSequenceUnit(void*, s32) asm("_ZN2YI6LAYOUT15GetSequenceUnitEi");
u8* GetImage(void*, s32) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
void func_001386e0(void*, s32, void*, void*, s32, s32);
extern W246UP D_0035f338;
extern void* D_0035f33c;
extern void* D_0035f340;
extern void (*D_0035f344)();

void func_00288670(void (*cb)());  // 0x00288670: definition moved into src/anon/unit_002880b8.cpp

W246Sram* GetSram(void) asm("_ZN2Tz9JmNewInfo7GetSramEv");
u8* JmInfo_GetData(s32) asm("_ZN2Tz6JmInfo7GetDataEi");
W246Score* GetScore(s32) asm("_ZN2YS8MINIGAME8GetScoreEi");
extern W246Sram* D_0035f610;

void func_002ab020(void);  // 0x002ab020: definition moved into src/anon/unit_002a99c8.cpp
}

typedef void (*W246Fn)(u8*);
struct W246NoTail { ~W246NoTail() {} };
extern "C" {
void func_00320528(void*);
void func_001ddd88(void*);
extern u8 D_01d48de8[];
}
static inline __attribute__((always_inline)) void w246_h1(u8* self) {
    if (self + 608 != 0) {
        u8* p = self + 672;
        u8* e = self + 608;
    l1: if (p == e) return;
        p -= 64; (*(W246Fn*)(*(u8**)p + 24))(p);
        goto l1;
    }
}
static inline __attribute__((always_inline)) void w246_h2(u8* self) {
    if (self + 400 != 0) {
        u8* p = self + 556;
        u8* e = self + 400;
    l1: if (p == e) return;
        p -= 52; (*(W246Fn*)(*(u8**)p + 24))(p);
        goto l1;
    }
}
static inline __attribute__((always_inline)) void w246_h3(u8* self) {
    func_001ddd88(self + 12);
}
extern "C" {
void wt(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001bc188jjjj");
void wt(u32 a, u32 b, u32, u32);  // 0x001bc188: definition moved into src/yasui/libys/mission.cpp
}
