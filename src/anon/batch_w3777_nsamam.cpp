#include "../common/types.h"
extern "C" {
struct Clip { u8 pad[8]; u16 n; u16 pad2; u8 data[1]; };
struct ClipRef { Clip* clip; s32 b; };
struct Obj { u8 pad[6]; u16 start; u16 end; };
struct Ent { Obj* o; ClipRef* r; s32 w; };
struct V4 { f32 x, y, z, w; };
struct S2 { f32 a, b; };
extern Ent* D_0035dcec;
extern s32 D_0035de20;
extern f32 D_0035de1c;
void func_001ba028(s32);
void func_0016ace0(s32, V4*);
void func_0016aeb8(s32, f32);
s32 func_002302c0(f32, s32, V4*, S2*);
f32 func_00230f10(f32, void*, u32, s32);
}

// Updates the 64 clip players: drops finished ones, samples active ones at the current time and applies the pose.
extern "C" {
void func_002306a8(void) {
    s32 i;
    if (D_0035dcec != 0) {
        for (i = 0; i < 64; i++) {
            Obj* o = D_0035dcec[i].o;
            if (o != 0) {
                if (o->end < D_0035de20) {
                    D_0035dcec[i].o = 0;
                    D_0035dcec[i].r = 0;
                } else if (D_0035de20 >= o->start) {
                    V4 v; S2 s;
                    Clip* c = D_0035dcec[i].r->clip;
                    if (func_002302c0(func_00230f10(D_0035de1c * 0.5f - (f32)o->start, c->data, c->n, 0),
                                      D_0035dcec[i].r->b, &v, &s) == 1) {
                        s32 w;
                        v.w = 1.0f;
                        v.y = -v.y;
                        v.z = -v.z;
                        w = D_0035dcec[i].w;
                        func_001ba028(w);
                        func_0016ace0(w, &v);
                        func_0016aeb8(w, s.b);
                    }
                }
            }
        }
    }
}
}
