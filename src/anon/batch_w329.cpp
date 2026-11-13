#include "../common/types.h"
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct E { u8 b0; u8 b1; u8 pad[38]; u16 h28; u8 pad2[22]; };
struct Tbl { u32 a; s32 n; E e[1]; };
struct X { u8 pad[16]; u32 w10; };
struct Z { u16 h0; };
extern "C" {
extern u32 D_003638d0;
extern Tbl* D_01d5ba28;
extern f32 D_0036e454;
s32 func_001d4420(void);
s32 func_001d3c78(E*);
s32 func_001d3e40(E*);
void* func_0017e668(u8);
X* func_00177860(void*);
V4* func_0016c028(void*);  // obj_get_attach_or_alt
Z* func_001b8e88(u16);
s32 func_001bc2a8(Z*, void*, s32);
}
static inline bool Near(Z* z, void* a) { return func_001bc2a8(z, a, 0) < 4; }
extern "C" {
Z* func_001d45a0(void* self, u32 id);  // 0x001d45a0: definition moved into src/anon/unit_001d3c08.cpp
}
struct _reent { s32 _errno; };
extern "C" {
extern u8 D_00377b68[];
s64 strtoll_r_w(struct _reent* rptr, const char* nptr, char** endptr, s32 base) asm("_Z9_strtol_rjjjj");
s64 strtoll_r_w(struct _reent* rptr, const char* nptr, char** endptr, s32 base)
{
    register const char* s = nptr;
    register u64 acc;
    register s32 c;
    register u64 cutoff;
    register s32 neg = 0, any, cutlim;

    do {
        c = *s++;
    } while (D_00377b68[c] & 8);
    if (c == '-') {
        neg = 1;
        c = *s++;
    } else if (c == '+')
        c = *s++;
    if ((base == 0 || base == 16) &&
        c == '0' && (*s == 'x' || *s == 'X')) {
        c = s[1];
        s += 2;
        base = 16;
    }
    if (base == 0)
        base = c == '0' ? 8 : 10;
    cutoff = neg ? -(u64)(-0x7fffffffffffffffLL - 1) : 0x7fffffffffffffffLL;
    cutlim = cutoff % (u64)base;
    cutoff /= (u64)base;
    for (acc = 0, any = 0;; c = *s++) {
        if (D_00377b68[c] & 4)
            c -= '0';
        else if (D_00377b68[c] & 3)
            c -= (D_00377b68[c] & 1) ? 'A' - 10 : 'a' - 10;
        else
            break;
        if (c >= base)
            break;
        if (any < 0 || acc > cutoff || (acc == cutoff && c > cutlim))
            any = -1;
        else {
            any = 1;
            acc = acc * base;
            acc += c;
        }
    }
    if (any < 0) {
        acc = neg ? (-0x7fffffffffffffffLL - 1) : 0x7fffffffffffffffLL;
        rptr->_errno = 34;
    } else if (neg)
        acc = -acc;
    if (endptr != 0)
        *endptr = (char*)(any ? s - 1 : nptr);
    return acc;
}
}
