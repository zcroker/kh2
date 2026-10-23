#include "../common/types.h"

/* Plain C code (partMng family). Lives in _nsi.c only because batch_wcx2.c would share the object name with batch_wcx2.cpp; it matches with or without -fno-sched-interblock.
   00204850: strip particle physics step (colour integrate, angle step, VU0 position update, fade counters). */
typedef struct Em048 Em048; typedef struct Pr048 Pr048; typedef struct Pt048 Pt048; typedef struct Cf048 Cf048;
struct Em048 { u8 pad[64]; f32 v64[4]; };
struct Pr048 {
    u8 pad0[34]; u16 h34; u8 pad36; u8 b37; u8 pad38[56 - 38];
    f32 f56, f60, f64, f68; u8 pad72[100 - 72]; f32 f100, f104; u8 pad108[132 - 108];
    f32 f132; u8 pad136[164 - 136]; f32 f164, f168; u8 pad172[180 - 172]; f32 f180;
    u8 pad184[202 - 184]; u8 b202, b203; u8 pad204[2]; u8 b206;
};
struct Pt048 {
    f32 pos[4]; f32 vel[4]; u8 pad32[38 - 32]; u16 h38; u8 pad40[44 - 40]; u8 b44; u8 pad45; u16 h46; s16 h48; s16 h50;
    f32 f52, f56, f60, f64, f68, f72, f76, f80, f84, f88; u8 b92, b93, b94, b95;
};
struct Cf048 { f32 x, y, z, w, vx, vy, vz, vw; };
void func_00204850(Em048* e, Pr048* p, Pt048* pt, u8* col, Cf048* cf)
{
    s32 alpha = col[11];
    if (cf) {
        cf->x += cf->vx;
        cf->y += cf->vy;
        cf->z += cf->vz;
        cf->w += cf->vw;
        s32 w = (s32)cf->w;
        cf->vx += p->f56;
        cf->vy += p->f60;
        cf->vz += p->f64;
        cf->vw += p->f68;
        alpha = col[11] + w;
        if (alpha > 255) alpha = 255;
    }
    pt->h46 += pt->h48;
    if (p->b203 & 0x10) pt->h48 += p->f132 + pt->h50;
    else pt->h48 += p->f132;
    pt->f52 += pt->f60;
    pt->f56 += pt->f64;
    if (p->b202 & 0x10) {
        pt->f60 += p->f100 + pt->f68;
        pt->f64 += p->f104 + pt->f72;
    } else {
        pt->f60 += p->f100;
        pt->f64 += p->f104;
    }
    pt->f76 += p->f168;
    if (!p->b206) {
        if (p->f164 > 0.0f && p->f168 < 0.0f) {
            if (pt->f76 < 0.0f) pt->f76 = 0.0f;
        } else if (p->f164 < 0.0f && p->f168 > 0.0f) {
            if (pt->f76 > 0.0f) pt->f76 = 0.0f;
        }
    }
    pt->f80 += p->f180;
    /* hand-written VU0 block: pos.xyz += vel.xyz * f76 + wind.xyz * f80 */
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tlw $8, 0(%2)\n\tqmtc2 $8, $vf3\n\tlqc2 $vf4, 0(%3)\n\tlw $9, 0(%4)\n\tqmtc2 $9, $vf5\n\t"
                 "vmulx.xyz $vf2, $vf2, $vf3x\n\tvmulx.xyz $vf4, $vf4, $vf5x\n\tvadd.xyz $vf1, $vf1, $vf2\n\tvadd.xyz $vf1, $vf1, $vf4\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(pt->pos), "r"(pt->vel), "r"(&pt->f76), "r"(e->v64), "r"(&pt->f80) : "$8", "$9", "memory");
    if (p->h34) pt->h38--;
    pt->b44++;
    if (pt->b92 && pt->b44 <= pt->b92) pt->f84 -= (f32)alpha / (f32)pt->b92;
    if (pt->b93 && pt->h38 <= pt->b93) pt->f84 += (f32)alpha / (f32)p->b37;
    if (pt->b94 && pt->b44 <= pt->b94) pt->f88 = (f32)pt->b44 / (f32)pt->b94;
    if (pt->b95 && pt->h38 <= pt->b95) pt->f88 = (f32)pt->h38 / (f32)pt->b95;
}
