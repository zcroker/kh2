#include "../common/types.h"

extern "C" {

s32 func_00224910(void);
void func_00239f18(void* p, f32 v);

static inline f32 w1781_clamp(f32 x, f32 lo, f32 hi) {
    f32 r;
    if (x < lo) r = lo;
    else if (hi < x) r = hi;
    else r = x;
    return r;
}

void func_00228918(u8* self) {
    f32 v = (f32)func_00224910() / 10000.0f;
    v = w1781_clamp(v, 0.0f, 1.0f);
    v = 1.0f - v;
    v = w1781_clamp(v, 0.0f, 1.0f);
    func_00239f18(self + 0x1c8, v);
}

struct W1781VObj {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10();
};
struct W1781Ent40 { s32 a; s32 b; W1781VObj* obj; u8 pad[28]; };
extern W1781Ent40* D_0035dcfc;
void func_001ba028(W1781VObj*);
void func_00232db0(s32);

void func_0022d440(void) {
    if (D_0035dcfc != 0) {
        for (s32 i = 0; i < 96; i++) {
            if (D_0035dcfc[i].obj != 0) {
                func_001ba028(D_0035dcfc[i].obj);
                D_0035dcfc[i].obj->v10();
                D_0035dcfc[i].obj = 0;
                func_00232db0(D_0035dcfc[i].b);
            }
        }
    }
}

// FVector-style 16-byte vector; the subtraction is a VU0 macro sequence (asm only for lqc2/vsub/sqc2)
struct W1781Vec { f32 x, y, z, w; } __attribute__((aligned(16)));
static inline void w1781_sub(W1781Vec* r, const W1781Vec* a, const W1781Vec* b) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(r), "r"(a), "r"(b) : "memory");
}
struct W1781Obj {
    u8 pad[0x30];
    W1781Vec p30;
    W1781Vec p40;
    f32 time;
    f32 dur;
};
void w1781_set_pos(void* obj, const W1781Vec* v) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
extern f32 D_00349e10;
void func_0017d748(W1781Vec* out, W1781Obj* self, f32 t);

void func_002c7060(W1781Obj* self, void* obj) {
    W1781Vec v;
    f32 dur;
    self->time += D_00349e10;
    dur = self->dur;
    if (self->time < dur) {
        func_0017d748(&v, self, self->time / dur);
        w1781_set_pos(obj, &v);
    } else {
        w1781_set_pos(obj, &self->p30);
        w1781_sub(&v, &self->p40, &self->p30);
        self->dur = 0.0f;
    }
}

struct W1781Ent616 { u8 d[616]; };
struct W1781Mgr616 { W1781Ent616 ent[64]; s32 list[64]; s32 count; };

W1781Ent616* func_0031f168(W1781Mgr616* m, W1781Ent616* p) {
    if (p) p++; else p = m->ent;
    while (p < &m->ent[64]) {
        s32 idx = p - m->ent;
        s32 i;
        for (i = 0; i < m->count; i++) {
            if (m->list[i] == idx) { p++; break; }
        }
        if (i == m->count) return p;
    }
    return 0;
}

}
