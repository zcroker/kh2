// Linked unit 0x23e188-0x23e580: draw of the 4-slot model viewer (Mgr23da00 in unit_0023d260): sorts the active slots by kind, drops dead
// handles, then draws each slot (screen offset, camera matrix, effect list, colour). L130 2026-11-19: matched with two empty asm reads
// (less-asm, see asm_review.tsv): `asm("" :: "r"(idx))` fixes the global-alloc order of the loop counter and idx; `asm("" : "+r"(w))`
// makes the effect-array pointer a block-crossing pseudo so the pointer giv is one `addiu`. VU0 matrix multiply is inline asm (mulmat).
// Flags -G0 -fno-strict-aliasing like the neighbours; no rodata.
#include "../common/types.h"
namespace n0023e188 {
struct M { f32 m[4][4]; } __attribute__((aligned(16)));
struct Mot;
struct Obj {
    u8 p0[48];
    s32 w48;
    u8 p34[4];
    u8 f56[16];
    u64 f72;
    u64 f80;
    u8 p58[112 - 88];
    void* mdl;
    Mot* mot;
    u8 p78[8];
    M mtx;
    u8 m192[28];
    s32 w220[16];
    s32 a2;
    s32 a3;
    s32 t0;
    u8 p128[312 - 296];
    u8 col[4];
    u8 active;
    u8 p13d[3];
    void fx();
};
struct Sub { u8 p[16]; M m; };
struct Cam { M m; u8 p40[192]; Sub sub; u8 p150[400 - 256 - sizeof(Sub)]; };
struct Mgr {
    u8 p0[32];
    Cam cam[4];
    Obj obj[4];
    u8 kind[4];
    u8 slot[4];
    s32 count;
    s32 count2;
    s16 sx[4];
    s16 sy[4];
    u8 gs0[784];
    u8 gs1[784];
    u8 gs2[784];
    void* a[4];
    void* b[4];
    void* c[4];
    u8 flag[3];
};
s32 func_00139d78(void*) asm("func_00139d78");
void func_0023e9f0(Mgr*) asm("func_0023e9f0");
void func_00138c50(void*, s32*, s32*) asm("func_00138c50");
void func_00138cb8(void*, s32*, s32*) asm("func_00138cb8");
void func_0014c350(u8*) asm("func_0014c350");
void func_0011cdf0(s32, M*, M*, u8*, s32) asm("func_0011cdf0");
void func_001de590(u8*) asm("func_001de590");
void func_001dcb98(s32, u8*) asm("func_001dcb98");
void func_0014b1e0(u8*, s32, s32) asm("func_0014b1e0");
void func_0014b200(u8*, u32) asm("func_0014b200");
void func_0014b220(u8*, s32, s32, s32, s32) asm("func_0014b220");
void func_001dd320(Cam*, Sub*, s32) asm("func_001dd320");
void func_001dd920(s32) asm("func_001dd920");
void func_00236d60(void) asm("func_00236d60");
Mot* func_001a9458(void*, s32, s32) asm("func_001a9458");

static inline void mulmat(M* d, M* a, M* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                 "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
                 "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
                 "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
                 : : "r"(d), "r"(a), "r"(b) : "memory");
}

inline void Obj::fx()
{
    if (*(s32*)m192 == 0) return;
    func_001de590(m192);
    for (s32 k = 15; k >= 0; k--) {
        if (w220[15 - k]) func_001dcb98(w220[15 - k], col);
    }
}
void func_0023e188(Mgr* m) asm("func_0023e188");
void func_0023e188(Mgr* m)
{
    s32 order[4];
    M mtx;
    s32 x, y, w, h;
    s32 i, j, k, idx;
    s32* p; s32* q;
    Obj* o;
    Cam* cam;
    s32 n = 0;
    for (i = 0; i < 4; i++) {
        if (m->obj[m->slot[i]].active) order[n++] = i;
    }
    for (i = 0; i < m->count; i++) {
        for (j = i + 1; j < m->count; j++) {
            s32 a = order[j];
            s32 b = order[i];
            if (m->kind[a] < m->kind[b]) {
                order[j] = b;
                order[i] = a;
            }
        }
    }
    for (i = 0; i < m->count2; i++) {
        if (m->c[i]) {
            if (!func_00139d78(m->c[i])) m->c[i] = 0;
        }
    }
    func_0023e9f0(m);
    cam = 0;
    for (i = 0; i < m->count; i++) {
        idx = order[i];
        o = &m->obj[m->slot[idx]];
        x = 0;
        y = 0;
        asm("" :: "r"(idx));
        if (o->active) {
            if (m->flag[1] && m->b[idx]) {
                func_00138c50(m->b[idx], &x, &y);
                func_00138cb8(m->b[idx], &w, &h);
                x = x + w - 256;
                y = y + h - 208;
            }
            func_0014c350(m->gs0);
            if (m->flag[2]) func_0014c350(m->gs1);
            if (o->w48) {
                o->f80 = 0x31000070;
                o->f72 = 0x80140;
                cam = &m->cam[idx];
                {
                    Sub* sb = &cam->sub;
                    mulmat(&mtx, &cam->m, sb ? &sb->m : 0);
                }
                func_0011cdf0(o->w48, &mtx, &o->mtx, o->f56, 0);
            }
        }
        if (*(s32*)o->m192) { s32* w = o->w220; asm("" : "+r"(w)); func_001de590(o->m192);
            for (s32 k = 0; k < 16; k++) { if (w[k]) func_001dcb98(w[k], o->col); } }
        x += m->sx[idx];
        y += m->sy[idx];
        if (o->active) {
            func_0014b1e0(m->gs2, (s16)x, (s16)y);
            func_0014b200(m->gs2, 0xffffff);
            func_0014b220(m->gs2, o->col[0], o->col[1], o->col[2], o->col[3]);
            func_0014c350(m->gs2);
        }
    }
    if (cam) {
        func_001dd320(cam, &cam->sub, 0);
        func_001dd920(0);
    }
    func_0014b1e0(m->gs2, 0, 0);
    if (m->count) func_00236d60();
}

}  // namespace n0023e188
