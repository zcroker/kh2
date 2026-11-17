#include "../common/types.h"

/* 0020f1e0: draw one model part into the packet buffer. Path 4 draws directly; otherwise checks the
   packet space, dispatches on flags 0x80/0x300 and adds the bytes written to the used count.
   The used count is updated through the packet pointer's address (eaa4 + 4 = eaa8): the original
   did not share the eaa8 address with the overflow test, which only a different symbol form gives. */
typedef struct {
    s32 flags;
    u8 pad4[0x48];
    union { struct { s8 a; s8 b; } c; u16 h; } u;
} Part20f1e0;
extern char D_003707d0[];
extern s32 D_01d9eaa4; /* packet write pointer */
extern s32 D_01d9eaa8; /* bytes used */
extern s32 D_01d9eab0; /* packet limit */
void func_0020f118(void);
void func_0020f150(void);
void func_0020f188(void);
void func_002fdfc8(const char*, ...);
s32 func_0021aee8(s32, Part20f1e0*);
s32 func_00217d80(s32, Part20f1e0*);
s32 func_00212338(s32, Part20f1e0*);
s32 func_0020f338(s32, Part20f1e0*);
s32 func_00215f28(s32, Part20f1e0*);
s32 func_00213ea8(s32, Part20f1e0*);

s32 func_0020f1e0(s32 h, Part20f1e0* p, s32 n);  // 0x0020f1e0: definition moved into src/anon/unit_0020f118.cpp
