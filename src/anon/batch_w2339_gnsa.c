#include "../common/types.h"

/* Plain C (partMng family), built with -g and without strict aliasing (-g makes no difference here).
   00208298: particle physics step (colour integrate, angle step and wrap, VU0 position update, fade). */
typedef struct Pr208298 Pr208298; typedef struct Pt208298 Pt208298; typedef struct Cf208298 Cf208298;
struct Pr208298 {
    u8 pad0[34]; u16 h34; u8 pad36; u8 b37; u8 pad38[56 - 38];
    f32 f56, f60, f64, f68; u8 pad72[100 - 72]; s32 w100[3]; u8 pad112[148 - 112];
    f32 f148[3]; u8 pad160[180 - 160]; f32 f180; u8 pad184[192 - 184]; f32 f192;
    u8 pad196[220 - 196]; f32 f220, f224; u8 pad228[236 - 228]; f32 f236;
    u8 pad240[258 - 240]; u8 b258, b259; u8 pad260[7]; u8 b267;
};
struct Pt208298 {
    u8 pad0[16]; f32 vel[4]; u8 pad32[16]; f32 pos[4]; u16 h64; u8 pad66[6];
    s32 ang[3]; s32 angv[3]; s32 anga[3]; f32 f108[3]; f32 f120[3]; f32 f132[3];
    f32 f144, f148, f152, f156, f160, f164, f168; u8 b172, b173, b174;
};
struct Cf208298 { f32 x, y, z, w, vx, vy, vz, vw; };
void func_00208298(f32* wind, Pr208298* p, Pt208298* pt, u8* col, Cf208298* cf)
{
    s32 alpha = col[11];
    s32 i;
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
    for (i = 0; i < 3; i++) pt->ang[i] += pt->angv[i];
    if (p->b259 & 0x10) {
        pt->angv[0] += p->w100[0] + pt->anga[0];
        pt->angv[1] += p->w100[1] + pt->anga[1];
        pt->angv[2] += p->w100[2] + pt->anga[2];
    } else {
        pt->angv[0] += p->w100[0];
        pt->angv[1] += p->w100[1];
        pt->angv[2] += p->w100[2];
    }
    for (i = 0; i < 3; i++) {
        s32* w = (s32*)&pt->h64; /* the original indexes this block as words from +64 */
        if (w[i + 2] > 0x7fff) {
            while (w[i + 2] > 0x7fff) w[i + 2] -= 0x10000;
        } else if (w[i + 2] < -0x8000) {
            while (w[i + 2] > 0x7fff) w[i + 2] += 0x10000;
        }
    }
    for (i = 0; i < 3; i++) pt->f108[i] += pt->f120[i];
    if (p->b258 & 0x10) {
        pt->f120[0] += p->f148[0] + pt->f132[0];
        pt->f120[1] += p->f148[1] + pt->f132[1];
        pt->f120[2] += p->f148[2] + pt->f132[2];
    } else {
        pt->f120[0] += p->f148[0];
        pt->f120[1] += p->f148[1];
        pt->f120[2] += p->f148[2];
    }
    pt->f144 += p->f224;
    if (!p->b267) {
        if (p->f220 > 0.0f && p->f224 < 0.0f) {
            if (pt->f144 < 0.0f) pt->f144 = 0.0f;
        } else if (p->f220 < 0.0f && p->f224 > 0.0f) {
            if (pt->f144 > 0.0f) pt->f144 = 0.0f;
        }
    }
    pt->f148 += p->f236;
    /* hand-written VU0 block: pos.xyz += vel.xyz * f144 + wind.xyz * f148 */
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tlw $8, 0(%2)\n\tqmtc2 $8, $vf3\n\tlqc2 $vf4, 0(%3)\n\tlw $9, 0(%4)\n\tqmtc2 $9, $vf5\n\t"
                 "vmulx.xyz $vf2, $vf2, $vf3x\n\tvmulx.xyz $vf4, $vf4, $vf5x\n\tvadd.xyz $vf1, $vf1, $vf2\n\tvadd.xyz $vf1, $vf1, $vf4\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(pt->pos), "r"(pt->vel), "r"(&pt->f144), "r"(wind), "r"(&pt->f148) : "$8", "$9", "memory");
    pt->f152 += pt->f160;
    pt->f156 += pt->f164;
    pt->f160 += p->f180;
    pt->f164 += p->f192;
    if (p->h34) pt->h64--;
    pt->b172++;
    if (pt->b173 && pt->b172 <= pt->b173) pt->f168 -= (f32)alpha / (f32)pt->b173;
    if (pt->b174 && pt->h64 <= pt->b174) pt->f168 += (f32)alpha / (f32)p->b37;
}
