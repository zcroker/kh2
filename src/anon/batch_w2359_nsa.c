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
void func_002f4000(f32*);
void func_002f4298(f32*, f32*, f32*);
void func_002f3cd8(f32*, f32*, f32*);
void func_002f3d98(f32*, f32*);
void func_002f4870(f32, f32*, f32*);
void func_002f3f98(f32*, f32*);
void func_002f3d08(f32*, f32*, f32*);
double func_00313b80(f32);
double func_00313ed8(double, double);
f32 func_003144b0(double);

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
        func_002f4000(mtx);
        func_002f4298(mtx, mtx, ang);
        func_002f3cd8(pt->vel, mtx, dir);
        pt->vel[0] *= p->f188;
        pt->vel[1] *= p->f192;
        pt->vel[2] *= p->f196;
        func_002f3d98(pt->vel, pt->vel);
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
            r = func_003144b0(func_00313ed8(1.0, func_00313b80(r)));
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
            r = func_003144b0(func_00313ed8(1.0, func_00313b80(r)));
        pick:
            if (!(ob->h98 < vs->count)) ob->h98 = 0;
            vx = ((Vx203b48*)verts)[vs->idx[(s32)(r * vs->count)]];
            break;
        }
        pt->pos[0] = vx.x * p->f188;
        pt->pos[1] = vx.y * p->f192;
        pt->pos[2] = vx.z * p->f196;
        if ((u8)(p->b38 - 8) < 2) {
            func_002f3d98(pt->vel, pt->pos);
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
        func_002f3f98(base, (f32*)ob);
        break;
    case 2:
        func_002f3f98(base, D_01d9e6e8->v16);
        break;
    case 3:
        func_002f3d08(base, (f32*)ob, D_01d9e6e8->v16);
        break;
    }
    if (cf) {
        cf->vx = p->f40;
        cf->vy = p->f44;
        cf->vz = p->f48;
        cf->vw = p->f52;
    }
}
