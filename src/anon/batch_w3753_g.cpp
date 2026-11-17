#include "../common/types.h"
extern "C" {
struct VO;
typedef void (*VFn6)(VO*, s32, s32, s32, s32, s32, s32);
struct VO { void** vt; };
struct Hd { u8 pad[8]; u32 f8; };
s32 func_00246840(void);
VO* func_00287dc0(void);
void func_0023d808(VO*, s32);
void func_0023e858(VO*, s32, f32);
void func_0023e8b8(VO*, s32, f32);
void func_0023e8d8(VO*, s32, f32);
s32 func_00139d78(u32);
void func_0023e9b0(VO*, s32, u32);
void func_0023e690(VO*, s32, s32, s32);
extern Hd* D_0035ed38;

void func_00245968(void);  // 0x00245968: definition moved into src/anon/unit_00242478.cpp
}
