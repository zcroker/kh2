#include "../common/types.h"
struct W1938Obj { u8 pad[0xd0]; f32 mn[3]; f32 mx[3]; };
struct W1938V4 { f32 x, y, z, w; };
extern "C" {
void func_0011dd08(W1938V4* out, W1938Obj** list) {
    W1938V4 mn, mx;
    W1938Obj* p = *list;
    list++;
    W1938Obj* q = *list;
    mn.x = p->mn[0]; mn.y = p->mn[1]; mn.z = p->mn[2]; mn.w = 1.0f;
    mx.x = p->mx[0]; mx.y = p->mx[1]; mx.z = p->mx[2]; mx.w = 1.0f;
    if (q) {
        W1938Obj* n;
        do {
        if (q->mn[0] < mn.x) mn.x = q->mn[0];
        if (q->mn[1] < mn.y) mn.y = q->mn[1];
        if (q->mn[2] < mn.z) mn.z = q->mn[2];
        if (mx.x < q->mx[0]) mx.x = q->mx[0];
        if (mx.y < q->mx[1]) mx.y = q->mx[1];
        if (mx.z < q->mx[2]) mx.z = q->mx[2];
            list++;
            n = *list;
            q = n;
        } while (n);
    }
    for (s32 i = 0; i < 8; i++) {
        out[i].w = 1.0f;
        if (i & 2) {
            out[i].x = mx.x;
            out[i].y = (u8)(i & 1) ? mn.y : mx.y;
        } else {
            out[i].x = mn.x;
            out[i].y = (u8)(i & 1) ? mx.y : mn.y;
        }
        out[i].z = (i & 4) ? mx.z : mn.z;
    }
}
}
