#include "../common/types.h"
extern "C" {

void* getSaveRam_w1521(void) asm("_Z10getSaveRamv");
void dk__Clock__vCountToHMSMS(s32, s32, s32, s32, s32);
void func_0014cc40(s32 a0, s32 a1, s32 a2, s32 a3, s32 idx);  // 0x0014cc40: definition moved into src/anon/unit_0014c7f0.cpp

struct W1521Node { void* vt; u8 pad[0x78]; W1521Node* next; };
struct W1521NodeList { W1521Node* first; W1521Node* cur; };
extern W1521NodeList D_01c6ced0;
extern u8 D_00350c50;
// 001ac5b8: moved to src/anon/unit_001abb28.cpp

s32 func_00287bc0(void);
void func_00276c50(s32, s32);
void Tz__JmDic__UpdateHelpMess(void);  // 0x0029ea30: definition moved into src/anon/unit_0029d008.cpp

u32 func_001024a8(...);
struct W1521Pos { s32 x, y; W1521Pos(s32 a, s32 b) : x(a), y(b) {} };
struct W1521Col { u8 r, g, b, a; W1521Col(s32 a0, s32 a1, s32 a2, s32 a3) : r(a0), g(a1), b(a2), a(a3) {} };
struct W1521Holder { s32 a, b; u8 sub[4]; };
void func_002ee040(void*);
void func_002ee0b0(void*, W1521Pos, W1521Col);
extern W1521Holder* D_003617fc;
void func_002be428(void* a0);  // 0x002be428: definition moved into src/anon/unit_002be020.cpp

}
