#include "../common/types.h"
// batch w2424 (zl90 retry), built with -fno-strict-aliasing: 002e0230 MGJump swing collision sweep.
extern "C" {
struct V2e0230 {
    f32 x, y, z, w;
    V2e0230() {}
    ~V2e0230() {}
    V2e0230(f32 ax, f32 ay, f32 az, f32 aw) { x = ax; y = ay; z = az; w = aw; }
    V2e0230(const V2e0230& o) { asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory"); }
    V2e0230& operator=(const V2e0230& o)
    {
        if (this != &o) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tsq $8, 0(%0)\n\t.set reorder" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V2e0230 operator-(const V2e0230& b) const
    {
        V2e0230 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2e0230 operator+(const V2e0230& b) const
    {
        V2e0230 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
    V2e0230 operator*(f32 k) const
    {
        V2e0230 r;
        asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(this), "f"(k) : "$8", "memory");
        return r;
    }
} __attribute__((aligned(16)));
struct Box2e0230 { f32 x, y, z; s32 pc; V2e0230 pos; };
struct Info2e0230 { f32 x, y, z; s32 pc; V2e0230 pos; Info2e0230() { pc = 0; } };
struct Col2e0230 { u8 pad[8]; s16 x, top, z, bottom; };
struct Kind2e0230 { u8 pad[5]; u8 kind; };
struct Obj2e0230 { u8 pad0[8]; Kind2e0230* info; u8 pad1[2800 - 12]; u8 flag[36]; s32 f2836; };
struct Self2e0230 { u8 pad0[40]; f32 f40; u8 pad1[112 - 44]; V2e0230 pos; };
V2e0230* func_0016c028(void*);
Col2e0230* func_0016bba8(void*, s32, s32);
void func_0018a818(void*, void*, void*);
Obj2e0230* func_001b9bc8(Obj2e0230*);
s32 func_0019c768(Obj2e0230*);
s32 func_0019c5d0(Obj2e0230*);
s32 func_002cf270(void*, s32);
void* func_0016bc20(Obj2e0230*, s32, s32);
s32 func_0018a550(void*, void*);
s32 func_002df198(Self2e0230*);
void func_002dfe38(Self2e0230*, void*, Obj2e0230*, s32, f32);
s32 func_002e0230(Self2e0230* self, void* ent)
{
    V2e0230 prev = self->pos;
    V2e0230 cur = *func_0016c028(ent);
    Col2e0230* col = func_0016bba8(ent, 6, 0);
    if (!col) return 0;
    V2e0230 a[5];
    Box2e0230 me;
    func_0018a818(&me, ent, col);
    for (s32 i = 1; i < 5; i++) {
        f32 k = (f32)i / 5.0f;
        a[i] = (cur - prev) * k + prev;
    }
    V2e0230 b[5];
    {
        V2e0230 ofs((f32)col->x, (f32)(col->top - col->bottom), (f32)col->z, 1.0f);
        for (s32 i = 1; i < 5; i++) b[i] = a[i] + ofs;
    }
    f32 h = 0.0f;
    s32 hit = 0;
    Obj2e0230* o = 0;
    while (!hit && (o = func_001b9bc8(o)) != 0) {
        if (func_0019c768(o)) continue;
        if (func_0019c5d0(o)) continue;
        if (o->info->kind != 22) continue;
        if (func_002cf270(o->flag, 4)) continue;
        void* t = func_0016bc20(o, 2, -1);
        if (!t) continue;
        Info2e0230 box;
        func_0018a818(&box, o, t);
        for (s32 j = 1; j < 5; j++) {
            me.pos = b[j];
            if (func_0018a550(&me, &box)) {
                hit++;
                h = box.pos.y - box.z;
                break;
            }
        }
    }
    if (hit > 0 && o && !func_002df198(self) && self->f40 < 0.0f) {
        s32 k = o->f2836;
        func_002dfe38(self, ent, o, k, h);
    }
    self->pos = cur;
    return hit;
}
}
