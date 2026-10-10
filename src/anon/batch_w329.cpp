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
V4* func_0016c028(void*);
Z* func_001b8e88(u16);
s32 func_001bc2a8(Z*, void*, s32);
}
static inline bool Near(Z* z, void* a) { return func_001bc2a8(z, a, 0) < 4; }
extern "C" {
Z* func_001d45a0(void* self, u32 id) {
    if (!func_001d4420()) return 0;
    s32 cnt = 0;
    Z* arr[D_01d5ba28->n];

    for (s32 i = 0; i < D_01d5ba28->n; i++) {
        E* e = &D_01d5ba28->e[i];
        if (e->b1 == 1) continue;
        if (!func_001d3c78(e)) continue;
        if (!func_001d3e40(e)) continue;
        void* o = func_0017e668(e->b1);
        if (!(func_00177860(o)->w10 & 2)) continue;
        V4* p1 = func_0016c028(o);
        V4* p2 = func_0016c028(self);
        V4 d;
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)" : : "r"(p1), "r"(p2), "r"(&d) : "memory");
        d.y = 0.0f;
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(len) : "r"(&d) : "$8", "memory");
        if (len > 500.0f) continue;
        Z* z = func_001b8e88(e->h28);
        if (!Near(z, self)) continue;
        if (z->h0 == id) return z;
        arr[cnt] = z;
        cnt++;
    }
    if (cnt > 0) {
        D_003638d0 *= 0x10dcd;
        u32 m = cnt;
        s32 idx = (u64)D_003638d0 / ((0x100000000ull + (m - 1)) / m);
        return arr[idx];
    }
    return 0;
}
}
struct _reent { s32 _errno; };
extern "C" {
extern u8 D_00377b68[];
s64 strtoll_r_w(struct _reent* rptr, const char* nptr, char** endptr, s32 base) asm("_Z16wtarget_002ff970jjjj");
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
