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

s32 func_0020f1e0(s32 h, Part20f1e0* p, s32 n)
{
    s32 r;
    if (p->flags & 4) {
        if (p->u.c.b != 0) func_0020f118();
        else if (p->u.c.a != 0) func_0020f150();
        if (p->flags & 0x300) r = func_0021aee8(h, p);
        else r = func_00217d80(h, p);
        if (p->u.h != 0) func_0020f188();
        return r;
    }
    if (D_01d9eaa8 + n >= D_01d9eab0) {
        func_002fdfc8(D_003707d0, n);
        return D_01d9eaa4;
    }
    if (p->flags & 0x80) {
        if (p->flags & 0x300) { r = func_00212338(h, p); (&D_01d9eaa4)[1] += r - D_01d9eaa4; }
        else { r = func_0020f338(h, p); (&D_01d9eaa4)[1] += r - D_01d9eaa4; }
    } else {
        if (p->flags & 0x300) { r = func_00215f28(h, p); (&D_01d9eaa4)[1] += r - D_01d9eaa4; }
        else { r = func_00213ea8(h, p); (&D_01d9eaa4)[1] += r - D_01d9eaa4; }
    }
    return r;
}
