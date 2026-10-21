#include "../common/types.h"
// 0019f2a8: -g keeps the nop after the case-3 b; goto labels for the return blocks stop ifcvt from hoisting the return value into a pseudo.
struct W1965dV3 { u16 x, y, z; };
struct W1965dItem { u8 a, b, c; W1965dV3 v; };
struct W1965dSrc { s32 type; W1965dItem it; };
static inline void W1965dv3set(W1965dV3* p, s32 v) { p->x = v; p->y = v; p->z = v; }
extern "C" {
extern W1965dItem D_0032bb00;
s32 func_00181500(s32);
W1965dItem func_00199718(s32, s32);
s32 func_0019f2a8(W1965dSrc* s, W1965dItem* out)
{
    switch (s->type) {
    case 1:
    case 2:
        *out = s->it;
        break;
    case 3:
        *out = D_0032bb00;
        break;
    case 4:
        if (func_00181500(0x1071) && !func_00181500(0x1072)
            && (func_00181500(0x140f) || func_00181500(0x1822) || func_00181500(0x200b))) {
            out->a = 4;
            out->b = 0;
            out->c = 0;
            W1965dv3set(&out->v, 0xffff);
            break;
        }
        if (func_00181500(0x8cd)) goto fail;
        if (func_00181500(0x3834) || func_00181500(0x1c1c)) {
            *out = func_00199718(64, 18);
            break;
        }
        goto fail;
    default:
        goto fail;
    }
    if (func_00181500(0x872)) goto done;
    if (!func_00181500(0x86e)) goto done;
    if (!func_00181500(0x86f)) goto done;
    if (!func_00181500(0x870)) goto done;
    if (func_00181500(0x871)) *out = func_00199718(122, 2);
done:
    return 1;
fail:
    return 0;
}
}
