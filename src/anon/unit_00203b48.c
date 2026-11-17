// Linked unit 0x00203b48-0x00204dd8 (partMng family: particle spawn, physics step, emitter update; plain C).
#include "../common/types.h"

/* Plain C (partMng family), built with -fno-strict-aliasing.
   00203b48: partMng particle birth: clear the particle, pick a direction, an emit shape
   (point / sphere shell / box / model vertex) with a random radius curve, colours, angle, uv
   scroll, scale, fades and the owner-relative position. */
typedef struct Pr203b48 Pr203b48; typedef struct Pt203b48 Pt203b48; typedef struct Cf203b48 Cf203b48;
typedef struct Ob203b48 Ob203b48; typedef struct Wk203b48 Wk203b48; typedef struct Bk203b48 Bk203b48;
struct Pr203b48 {
    u8 pad0[34]; u16 h34; u8 b36, b37, b38, b39;
    f32 f40, f44, f48, f52; u8 pad56[72 - 56]; u8 b72, b73, b74, b75;
    f32 f76, f80, f84, f88, f92; u8 pad96[112 - 96]; f32 f112, f116; u8 pad120[124 - 120];
    f32 f124, f128, f132, f136, f140, f144, f148; u8 pad152[164 - 152]; f32 f164, f168, f172, f176, f180;
    f32 f184, f188, f192, f196; u8 b200, b201, b202, b203, b204, pad205[3]; s16 h208; u8 b210, b211, b212;
    u8 pad213[216 - 213]; f32 f216;
};
struct Pt203b48 {
    f32 pos[4]; f32 vel[4]; u8 pad32[38 - 32]; s16 h38; s8 b40, b41, b42, b43; u8 b44; u8 pad45; s16 h46; s16 h48; s16 h50;
    f32 f52, f56, f60, f64, f68, f72, f76, f80, f84, f88; u8 b92, b93, b94, b95;
};
struct Cf203b48 { f32 x, y, z, w, vx, vy, vz, vw; };
struct Ob203b48 { u8 pad0[98]; u16 h98; };
struct Wk203b48 { u8 pad0[16]; f32 v16[4]; u8 pad32[144 - 32]; s16* verts; };
typedef struct { u8 pad0[20]; s16* verts; u8 pad24[36 - 24]; } Md203b48;
typedef struct { s16 model; s16 count; u16* idx; } Vs203b48;
struct Bk203b48 { u8 pad0[16]; Md203b48* models; u8 pad20[4]; Vs203b48* sets; };
typedef struct { s16 x, y, z; } Vx203b48;
extern Wk203b48* D_01d9e6e8;
extern Bk203b48* D_01d9e6e4;
f32 func_00203a40(void);
s8 func_00203a88(u8);
void func_001e7188(void*, s32, s32);
void sceVu0UnitMatrix(f32*);
void sceVu0RotMatrix(f32*, f32*, f32*);
void sceVu0ApplyMatrix(f32*, f32*, f32*);
void sceVu0Normalize(f32*, f32*);
void func_002f4870(f32, f32*, f32*);
void sceVu0CopyMatrix(f32*, f32*);
void sceVu0MulMatrix(f32*, f32*, f32*);
double func_00313b80(f32);
double __subdf3(double, double);
f32 __truncdfsf2(double);

void func_00203b48(void* e, Ob203b48* ob, Pr203b48* p, u8* col, Pt203b48* pt, f32* base, Cf203b48* cf)
{
    f32 dir[4];
    f32 ang[4];
    f32 mtx[16];
    Vx203b48 vx;
    f32 sz = p->b39;
    f32 sz2 = sz + sz;
    f32 r, half, rad;
    s32 i;
    func_001e7188(pt, 0, 24);
    if (base) func_001e7188(base, 0, 16);
    if (cf) func_001e7188(cf, 0, 8);
    if (p->b38 < 8) {
        dir[0] = p->f140;
        dir[1] = p->f144;
        dir[2] = p->f148;
        dir[3] = 0.0f;
        for (i = 0; i < 3; i++) {
            ang[i] = sz2 * func_00203a40() - sz;
            ang[i] = ang[i] * 3.1415927f / 180.0f;
        }
        if ((u8)(p->b38 - 2) < 2) {
            ang[0] = 0.0f;
            ang[1] = 0.0f;
        }
        sceVu0UnitMatrix(mtx);
        sceVu0RotMatrix(mtx, mtx, ang);
        sceVu0ApplyMatrix(pt->vel, mtx, dir);
        pt->vel[0] *= p->f188;
        pt->vel[1] *= p->f192;
        pt->vel[2] *= p->f196;
        sceVu0Normalize(pt->vel, pt->vel);
        pt->vel[3] = 0.0f;
    }
    switch (p->b38) {
    default:
    case 0: case 1: case 2: case 3:
        rad = p->f184;
        if (rad == 0.0f) break;
        switch (p->b200) {
        case 1:
            func_00203a40();
            rad = p->f184 * func_00203a40();
            break;
        case 2:
            rad = p->f184 * func_00203a40() * func_00203a40();
            break;
        case 3:
            rad = p->f184 - p->f184 * func_00203a40() * func_00203a40() * 0.7f;
            break;
        case 4:
            rad = p->f184 * func_00203a40() * func_00203a40() * func_00203a40() * func_00203a40();
            break;
        case 5:
            rad = p->f184 - p->f184 * func_00203a40() * func_00203a40() * func_00203a40() * 0.5f;
            break;
        }
        func_002f4870(rad, pt->pos, pt->vel);
        break;
    case 4: case 5:
        if (p->f184 == 0.0f) break;
        half = p->f184 * 0.5f;
        switch (p->b200) {
        default:
        case 0:
            for (i = 0; i < 3; i++) pt->pos[i] = p->f184 * func_00203a40() - half;
            break;
        case 1:
            func_00203a40();
            for (i = 0; i < 3; i++) pt->pos[i] = p->f184 * func_00203a40() - half;
            break;
        case 2:
            for (i = 0; i < 3; i++) {
                r = p->f184 * func_00203a40() * func_00203a40();
                r = r - half;
                pt->pos[i] = r;
            }
            break;
        case 3:
            for (i = 0; i < 3; i++) {
                r = p->f184 * func_00203a40() * func_00203a40();
                r = r * 0.7f;
                pt->pos[i] = p->f184 - r - half;
            }
            break;
        case 4:
            for (i = 0; i < 3; i++) {
                r = p->f184 * func_00203a40() * func_00203a40() * func_00203a40() * func_00203a40();
                r = r - half;
                pt->pos[i] = r;
            }
            break;
        case 5:
            for (i = 0; i < 3; i++) {
                r = p->f184 * func_00203a40() * func_00203a40() * func_00203a40();
                r = r * 0.5f;
                pt->pos[i] = p->f184 - r - half;
            }
            break;
        }
        pt->pos[0] *= p->f188;
        pt->pos[1] *= p->f192;
        pt->pos[2] *= p->f196;
        break;
    case 6: case 7: case 8: case 9: {
        Vs203b48* vs;
        s16* verts = D_01d9e6e8->verts;
        if (p->h208 < 0) break;
        vs = &D_01d9e6e4->sets[p->h208];
        if (!verts) verts = D_01d9e6e4->models[vs->model].verts;
        switch (p->b200) {
        default:
        case 0:
            if (!(ob->h98 < vs->count)) ob->h98 = 0;
            vx = ((Vx203b48*)verts)[vs->idx[ob->h98++]];
            break;
        case 1:
            func_00203a40();
            r = func_00203a40();
            goto pick;
        case 2:
            r = func_00203a40();
            r = r * func_00203a40();
            r = r * func_00203a40();
            goto pick;
        case 3:
            r = func_00203a40();
            r = r * func_00203a40();
            r = r * func_00203a40();
            r = __truncdfsf2(__subdf3(1.0, func_00313b80(r)));
            goto pick;
        case 4:
            r = func_00203a40();
            r = r * func_00203a40();
            r = r * func_00203a40();
            r = r * func_00203a40();
            goto pick;
        case 5:
            r = func_00203a40();
            r = r * func_00203a40();
            r = r * func_00203a40();
            r = r * func_00203a40();
            r = r * func_00203a40();
            r = __truncdfsf2(__subdf3(1.0, func_00313b80(r)));
        pick:
            if (!(ob->h98 < vs->count)) ob->h98 = 0;
            vx = ((Vx203b48*)verts)[vs->idx[(s32)(r * vs->count)]];
            break;
        }
        pt->pos[0] = vx.x * p->f188;
        pt->pos[1] = vx.y * p->f192;
        pt->pos[2] = vx.z * p->f196;
        if ((u8)(p->b38 - 8) < 2) {
            sceVu0Normalize(pt->vel, pt->pos);
            pt->vel[3] = 0.0f;
        }
        break;
    }
    }
    pt->b40 = func_00203a88(p->b72);
    pt->b41 = func_00203a88(p->b73);
    pt->b42 = func_00203a88(p->b74);
    pt->b43 = func_00203a88(p->b75);
    if (p->b36) {
        pt->f84 = col[11];
        pt->b92 = p->b36;
    }
    if (p->b37) pt->b93 = p->b37;
    pt->f88 = 1.0f;
    if (p->b211) {
        pt->f88 = 0.0f;
        pt->b94 = p->b211;
    }
    if (p->b212) pt->b95 = p->b212;
    pt->h46 = p->f124 * 32768.0f / 180.0f;
    pt->h48 = p->f128 * 32768.0f / 180.0f;
    if (p->b203) {
        pt->h50 = func_00203a40() * p->f136 * 32768.0f / 180.0f;
        if ((p->b203 & 1) && (p->b203 & 2)) {
            if (0.5f < func_00203a40()) pt->h50 = -pt->h50;
        } else if (p->b203 & 2) {
            pt->h50 = -pt->h50;
        }
    }
    if (p->b203 & 4) pt->h46 += pt->h50;
    if (p->b203 & 8) pt->h48 += pt->h50;
    pt->f52 = p->f76;
    pt->f56 = p->f80;
    pt->f60 = p->f88;
    pt->f64 = p->f92;
    if (p->b202) {
        if (p->b202 & 0x20) {
            pt->f68 = pt->f72 = func_00203a40() * p->f112;
            if ((p->b202 & 1) && (p->b202 & 2)) {
                if (0.5f < func_00203a40()) {
                    pt->f68 = -pt->f68;
                    pt->f72 = -pt->f72;
                }
            } else if (p->b202 & 2) {
                pt->f68 = -pt->f68;
                pt->f72 = -pt->f72;
            }
        } else {
            pt->f68 = func_00203a40() * p->f112;
            pt->f72 = func_00203a40() * p->f116;
            if ((p->b202 & 1) && (p->b202 & 2)) {
                if (0.5f < func_00203a40()) pt->f68 = -pt->f68;
                if (0.5f < func_00203a40()) pt->f72 = -pt->f72;
            } else if (p->b202 & 2) {
                pt->f68 = -pt->f68;
                pt->f72 = -pt->f72;
            }
        }
    }
    if (p->b202 & 4) {
        pt->f52 += pt->f68;
        pt->f56 += pt->f72;
    }
    if (p->b202 & 8) {
        pt->f60 += pt->f68;
        pt->f64 += pt->f72;
    }
    switch (p->b210) {
    case 0:
        break;
    case 1:
        if (0.5f < func_00203a40()) pt->f52 = -pt->f52;
        break;
    case 2:
        if (0.5f < func_00203a40()) pt->f56 = -pt->f56;
        break;
    case 3:
        if (0.5f < func_00203a40()) pt->f52 = -pt->f52;
        if (0.5f < func_00203a40()) pt->f56 = -pt->f56;
        break;
    }
    pt->f76 = p->f164;
    pt->f80 = p->f176;
    if (p->f172 != 0.0f) pt->f76 += (p->f172 + p->f172) * func_00203a40() - p->f172;
    if (p->f216 != 0.0f) pt->f80 += (p->f216 + p->f216) * func_00203a40() - p->f216;
    if (!p->h34) pt->h38 = -1;
    else pt->h38 = p->h34;
    pt->b44 = 0;
    switch (p->b204) {
    case 1:
        sceVu0CopyMatrix(base, (f32*)ob);
        break;
    case 2:
        sceVu0CopyMatrix(base, D_01d9e6e8->v16);
        break;
    case 3:
        sceVu0MulMatrix(base, (f32*)ob, D_01d9e6e8->v16);
        break;
    }
    if (cf) {
        cf->vx = p->f40;
        cf->vy = p->f44;
        cf->vz = p->f48;
        cf->vw = p->f52;
    }
}


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


/* Plain C (partMng family), built with -fno-strict-aliasing -fmove-all-movables.
   00204bd0: per-frame update of an emitter's particle array. Live particles run the physics step
   and advance their frame animation; dead ones are respawned while the emit threshold allows it. */
typedef struct Pt204bd0 Pt204bd0; typedef struct Cl204bd0 Cl204bd0; typedef struct Cf204bd0 Cf204bd0;
typedef struct Em204bd0 Em204bd0; typedef struct Pr204bd0 Pr204bd0; typedef struct Fr204bd0 Fr204bd0;
typedef struct An204bd0 An204bd0; typedef struct Set204bd0 Set204bd0; typedef struct Bk204bd0 Bk204bd0;
typedef struct Sys204bd0 Sys204bd0;
struct Pt204bd0 { u8 pad0[32]; u16 time; u16 frame; u16 prev; u16 active; u8 pad40[96 - 40]; };
struct Cl204bd0 { u8 pad[64]; };
struct Cf204bd0 { u8 pad[32]; };
struct Em204bd0 { u8 pad0[80]; Pt204bd0* pt; Cl204bd0* col; Cf204bd0* cf; s32 n; u16 tick; };
struct Pr204bd0 { u8 pad0[4]; s32 anim; u16 speed; u8 pad10[30 - 10]; u16 max; u16 thr; };
struct Fr204bd0 { u8 pad0[2]; u16 dur; s8 flags; u8 pad5[3]; };
struct An204bd0 { u8 pad0[6]; s16 count; u8 pad8[16 - 8]; Fr204bd0 fr[1]; };
struct Set204bd0 { An204bd0* an; u32 pad4; };
struct Bk204bd0 { u8 pad0[20]; Set204bd0* sets; };
struct Sys204bd0 { u8 pad0[168]; u64 flags; };
extern s32 D_01d9ea9c;
extern Sys204bd0* D_01d9e6e0;
extern Bk204bd0* D_01d9e6e4_bd0 asm("D_01d9e6e4");
void func_00204850_bd0(Em204bd0*, Pr204bd0*, Pt204bd0*, s32, Cf204bd0*) asm("func_00204850");
void func_00203b48_bd0(s32, Em204bd0*, Pr204bd0*, s32, Pt204bd0*, Cl204bd0*, Cf204bd0*) asm("func_00203b48");

void func_00204bd0(s32 owner, Em204bd0* em, Pr204bd0* pr, s32 col)
{
    s32 born = 0;
    s32 i;
    Pt204bd0* pt = em->pt;
    Cl204bd0* cl = em->col;
    Cf204bd0* cf = em->cf;
    s32 n = em->n;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (pr->anim == 0xffff) return;
    em->tick++;
    for (i = 0; i < n; i++) {
        if (pt->active != 0) {
            func_00204850_bd0(em, pr, pt, col, cf);
            u16 frame = pt->frame;
            Set204bd0* sets = D_01d9e6e4_bd0->sets;
            u32 off = pr->anim * 8;
            An204bd0* an = *(An204bd0**)((u8*)sets + off);
            u16 prev = pt->prev;
            pt->prev = frame;
            Fr204bd0* fr = &an->fr[prev];
            s32 time = pt->time + pr->speed;
            pt->time = time;
            if ((u16)time >= (s16)fr->dur) {
                pt->time = time - fr->dur;
                pt->frame = frame + 1;
                if (pt->frame >= an->count) {
                    if (fr->flags & 0x80) { pt->frame = 0; pt->time = 0; }
                    else { pt->frame = frame; pt->time = 0; }
                }
            }
        } else if (pr->thr <= em->tick) {
            if (born < pr->max) {
                func_00203b48_bd0(owner, em, pr, col, pt, cl, cf);
                born++;
            }
        }
        pt++;
        if (cl) cl++;
        if (cf) cf++;
    }
    if (born > 0) em->tick = 0;
}
