#include "../common/types.h"

/* func_00207350: particle/effect spawn. Fills a 0xb0-byte particle state (EffOut) from an
 * emitter description (EffDesc): initial direction/basis, velocity by emitter shape
 * (cone, box, mesh vertices), rotation/scale with random spread, life, color.
 * Built as C. The original walked raw float pointers in several 3-component loops
 * (p1..p11, w); written that way here because it decides the address base/offset split. */

asm("dpcmp = func_003142e0");
asm("dpsub = func_00313ed8");
asm("fptodp = func_00313b80");
asm("dptofp = func_003144b0");

typedef struct EffVtx EffVtx; struct EffVtx { s16 x, y, z; };

typedef struct EffFlags EffFlags; struct EffFlags { u8 b0:1; u8 b1:1; u8 b2:1; u8 b3:1; u8 b4:1; u8 b5:1; u8 b6:1; u8 b7:1; };
typedef union EffFlagByte EffFlagByte; union EffFlagByte { u8 all; EffFlags f; };

typedef struct EffShape EffShape; struct EffShape {          // 8 bytes
    s16 model;
    s16 count;
    u16* index;
};
typedef struct EffModel EffModel; struct EffModel {          // 0x24 bytes
    u8 pad0[0x14];
    EffVtx* verts;
    u8 pad18[0x24 - 0x18];
};
typedef struct EffData EffData; struct EffData {
    u8 pad0[0x10];
    EffModel* models;
    u8 pad14[4];
    EffShape* shapes;
};
typedef struct EffCtx EffCtx; struct EffCtx {
    u8 pad0[0x90];
    EffVtx* verts;
};

typedef struct EffDesc EffDesc; struct EffDesc {
    u8 pad0[0x22];
    u16 id;            // 0x22
    u8 b24;            // 0x24
    EffFlagByte b25;   // 0x25
    u8 type;           // 0x26
    u8 spread;         // 0x27
    f32 col[4];        // 0x28
    u8 pad38[0x48 - 0x38];
    u8 jitter[4];      // 0x48
    s32 rot[3];        // 0x4c
    s32 rotVel[3];     // 0x58
    u8 pad64[0x70 - 0x64];
    s32 rotRnd[3];     // 0x70
    f32 scl[3];        // 0x7c
    f32 sclVel[3];     // 0x88
    u8 pad94[0xa0 - 0x94];
    f32 sclRnd[3];     // 0xa0
    f32 ac;            // 0xac
    f32 b0;            // 0xb0
    u8 padb4[4];
    f32 b8;            // 0xb8
    f32 bc;            // 0xbc
    u8 padc0[4];
    f32 dir[3];        // 0xc4
    u8 padd0[0xdc - 0xd0];
    f32 dc;            // 0xdc
    u8 pade0[4];
    f32 dcRnd;         // 0xe4
    f32 e8;            // 0xe8
    u8 padec[4];
    f32 speed;         // 0xf0
    f32 scale[3];      // 0xf4
    u8 dist;           // 0x100
    u8 pad101;
    u8 sclFlags;       // 0x102
    u8 rotFlags;       // 0x103
    u8 lifeMode;       // 0x104
    u8 pad105[3];
    s16 shape;         // 0x108
};

typedef union EffSeq EffSeq; union EffSeq { u16 v; u8 b; };
typedef struct EffObj EffObj; struct EffObj {
    u8 pad0[0x22];
    EffSeq seq;        // 0x22
};

typedef struct EffOut EffOut; struct EffOut {
    f32 m0[4];         // 0x00
    f32 m1[4];         // 0x10
    f32 m2[4];         // 0x20
    f32 pos[4];        // 0x30
    u16 id;            // 0x40
    s8 jitter[4];      // 0x42
    u8 pad46[2];
    s32 rot[3];        // 0x48
    s32 rotVel[3];     // 0x54
    s32 rotRnd[3];     // 0x60
    f32 scl[3];        // 0x6c
    f32 sclVel[3];     // 0x78
    f32 sclRnd[3];     // 0x84
    f32 f90;           // 0x90
    f32 f94;           // 0x94
    f32 life0;         // 0x98
    f32 life1;         // 0x9c
    f32 fa0;           // 0xa0
    f32 fa4;           // 0xa4
    f32 fa8;           // 0xa8
    u8 bac;            // 0xac
    u8 bad;            // 0xad
    u8 bae;            // 0xae
};

typedef struct EffColor EffColor; struct EffColor {
    u8 pad0[0x10];
    f32 col[4];
};

f32 func_00207260(void);
s8 func_002072a8(u8);
void func_002f4000(void*);
void func_002f4298(void*, void*, void*);
void func_002f3d50(void*, void*, void*);
void func_002f3d98(void*, void*);
void func_002f4870(f32, void*, void*);
void eff_memset(void*, s32, u32) asm("_Z16wtarget_002fde18jjjj");
void eff_mulvec(void*, void*, void*) asm("_Z16wtarget_002f3cd8jjjj");
void eff_f3f98(void*, void*) asm("_Z16u_call4_002f3f98jjjj");
extern EffData* D_01d9e6e4;
extern EffCtx* D_01d9e6e8;
extern u8 D_01d9e6f0[];

void func_00207350(EffObj* obj, EffDesc* desc, u8* a2, EffOut* out, void* p40, EffColor* pcol) {
    f32 t[8];
    s32 k;
    f32 mtx[16];
    EffVtx v;
    s32 i;
    f32 *p1, *p2, *p3, *p4, *p5, *p6, *p7, *p8, *p9, *p10, *p11;
    f32 spread = (f32)desc->spread;
    f32 spread2 = spread + spread;

    eff_memset(out, 0, 0xb0);
    if (p40) eff_memset(p40, 0, 0x40);
    if (pcol) eff_memset(pcol, 0, 0x20);
    func_002f4000(out);

    if (desc->type < 8) {
        t[0] = desc->dir[0];
        t[1] = desc->dir[1];
        t[2] = desc->dir[2];
        t[3] = 1.0f;
        for (k = 0, p1 = t; k < 3; k++, p1++) {
            p1[4] = (spread2 * func_00207260() - spread) * 3.1415927f / 180.0f;
        }
        if ((u32)(desc->type - 2) < 2) {
            t[4] = 0;
            t[5] = 0;
        }
        func_002f4000(mtx);
        func_002f4298(mtx, mtx, &t[4]);
        eff_mulvec(out->m1, mtx, t);
        out->m1[0] *= desc->scale[0];
        out->m1[1] *= desc->scale[1];
        out->m1[2] *= desc->scale[2];
        func_002f3d98(out->m1, out->m1);
        func_002f3d50(out->m2, out->m1, out->m0);
        func_002f3d98(out->m2, out->m2);
        func_002f3d50(out->m0, out->m2, out->m1);
        func_002f3d98(out->m0, out->m0);
    }

    switch (desc->type) {
    case 0: case 1: case 2: case 3:
    default: {
        f32 sp = desc->speed;
        if (sp != 0.0f) {
            switch (desc->dist) {
            case 1:
                func_00207260();
                sp = desc->speed * func_00207260();
                break;
            case 2:
                sp = desc->speed * func_00207260() * func_00207260();
                break;
            case 3:
                sp = desc->speed - desc->speed * func_00207260() * func_00207260() * 0.7f;
                break;
            case 4:
                sp = desc->speed * func_00207260() * func_00207260() * func_00207260() * func_00207260();
                break;
            case 5:
                sp = desc->speed - desc->speed * func_00207260() * func_00207260() * func_00207260() * 0.5f;
                break;
            }
            func_002f4870(sp, out->pos, out->m1);
            out->pos[3] = 1.0f;
        }
        break;
    }
    case 4:
    case 5: {
        f32 sp = desc->speed;
        if (sp != 0.0f) {
            f32 half = sp * 0.5f;
            switch (desc->dist) {
            default:
                for (i = 0, p2 = out->m0; i < 3; i++, p2++)
                    p2[12] = desc->speed * func_00207260() - half;
                break;
            case 1:
                func_00207260();
                for (i = 0, p3 = out->m0; i < 3; i++, p3++)
                    p3[12] = desc->speed * func_00207260() - half;
                break;
            case 2:
                for (i = 0, p4 = out->m0; i < 3; i++, p4++)
                    p4[12] = desc->speed * func_00207260() * func_00207260() - half;
                break;
            case 3:
                for (i = 0, p5 = out->m0; i < 3; i++, p5++)
                    p5[12] = desc->speed - desc->speed * func_00207260() * func_00207260() * 0.7f - half;
                break;
            case 4:
                for (i = 0, p6 = out->m0; i < 3; i++, p6++)
                    p6[12] = desc->speed * func_00207260() * func_00207260() * func_00207260() * func_00207260() - half;
                break;
            case 5:
                for (k = 0, p7 = out->m0; k < 3; k++, p7++)
                    p7[12] = desc->speed - desc->speed * func_00207260() * func_00207260() * func_00207260() * 0.5f - half;
                break;
            }
            out->pos[0] *= desc->scale[0];
            out->pos[1] *= desc->scale[1];
            out->pos[2] *= desc->scale[2];
            out->pos[3] = 1.0f;
        }
        break;
    }
    case 6:
    case 7:
    case 8:
    case 9: {
        s32 si = desc->shape;
        EffVtx* verts = D_01d9e6e8->verts;
        if (si >= 0) {
            EffShape* sh = &D_01d9e6e4->shapes[si];
            f32 r;
            if (verts == 0)
                verts = D_01d9e6e4->models[sh->model].verts;
            switch (desc->dist) {
            default: {
                if (obj->seq.v >= sh->count) obj->seq.v = 0;
                {
                    u16 n = obj->seq.v++;
                    v = verts[sh->index[n]];
                }
                goto set;
            }
            case 1:
                func_00207260();
                r = func_00207260();
                break;
            case 2:
                r = func_00207260() * func_00207260() * func_00207260();
                break;
            case 3:
                r = 1.0 - func_00207260() * func_00207260() * func_00207260();
                break;
            case 4:
                r = func_00207260() * func_00207260() * func_00207260() * func_00207260();
                break;
            case 5:
                r = 1.0 - func_00207260() * func_00207260() * func_00207260() * func_00207260() * func_00207260();
                break;
            }
            if (obj->seq.v >= sh->count) obj->seq.v = 0;
            v = verts[sh->index[(s32)(r * (f32)sh->count)]];
        set:
            out->pos[0] = (f32)v.x * desc->scale[0];
            out->pos[1] = (f32)v.y * desc->scale[1];
            out->pos[2] = (f32)v.z * desc->scale[2];
            out->pos[3] = 1.0f;
            if ((u32)(desc->type - 8) < 2) {
                func_002f3d98(out->m1, out->pos);
                out->m1[0] *= desc->scale[0];
                out->m1[1] *= desc->scale[1];
                out->m1[2] *= desc->scale[2];
                func_002f3d98(out->m1, out->m1);
                func_002f3d50(out->m2, out->m1, out->m0);
                func_002f3d98(out->m2, out->m2);
                func_002f3d50(out->m0, out->m2, out->m1);
                func_002f3d98(out->m0, out->m0);
            }
        }
        break;
    }
    }

    out->jitter[0] = func_002072a8(desc->jitter[0]);
    out->jitter[1] = func_002072a8(desc->jitter[1]);
    out->jitter[2] = func_002072a8(desc->jitter[2]);
    out->jitter[3] = func_002072a8(desc->jitter[3]);
    if (desc->b24) {
        out->fa8 = (f32)a2[0xb];
        out->bad = desc->b24;
    }
    {
        if (desc->b25.all) out->bae = desc->b25.all;
    }
    out->rot[0] = desc->rot[0];
    out->rot[1] = desc->rot[1];
    out->rot[2] = desc->rot[2];
    out->rotVel[0] = desc->rotVel[0];
    out->rotVel[1] = desc->rotVel[1];
    out->rotVel[2] = desc->rotVel[2];

    if (desc->rotFlags) {
        if ((desc->rotFlags & 0x20)) {
            s32 r = (s32)(func_00207260() * (f32)desc->rotRnd[0]);
            out->rotRnd[2] = r;
            out->rotRnd[1] = r;
            out->rotRnd[0] = r;
            if (((EffFlagByte*)&desc->rotFlags)->f.b0 && (desc->rotFlags & 2)) {
                if (func_00207260() > 0.5) {
                    for (i = 0; i < 3; i++) out->rotRnd[i] = -out->rotRnd[i];
                }
            } else if (desc->rotFlags & 2) {
                for (i = 0; i < 3; i++) out->rotRnd[i] = -out->rotRnd[i];
            }
        } else {
            out->rotRnd[0] = (s32)(func_00207260() * (f32)desc->rotRnd[0]);
            out->rotRnd[1] = (s32)(func_00207260() * (f32)desc->rotRnd[1]);
            out->rotRnd[2] = (s32)(func_00207260() * (f32)desc->rotRnd[2]);
            if (((EffFlagByte*)&desc->rotFlags)->f.b0 && (desc->rotFlags & 2)) {
                for (i = 0; i < 3; i++) {
                    if (func_00207260() > 0.5) out->rotRnd[i] = -out->rotRnd[i];
                }
            } else if (desc->rotFlags & 2) {
                for (i = 0; i < 3; i++) out->rotRnd[i] = -out->rotRnd[i];
            }
        }
    }
    if ((desc->rotFlags & 4)) {
        for (k = 0; k < 3; k++) out->rot[k] += out->rotRnd[k];
    }
    if ((desc->rotFlags & 8)) {
        for (k = 0; k < 3; k++) out->rotVel[k] += out->rotRnd[k];
    }
    for (k = 0; k < 3; k++) {
        s32* w = (s32*)((u8*)out + 0x40);
        s32 a = w[k + 2];
        if (a > 0x7fff || a < -0x8000) w[k + 2] = a % 0x8000;
    }

    out->scl[0] = desc->scl[0];
    out->scl[1] = desc->scl[1];
    out->scl[2] = desc->scl[2];
    out->sclVel[0] = desc->sclVel[0];
    out->sclVel[1] = desc->sclVel[1];
    out->sclVel[2] = desc->sclVel[2];

    if (desc->sclFlags) {
        if ((desc->sclFlags & 0x20)) {
            f32 r = func_00207260() * desc->sclRnd[0];
            out->sclRnd[2] = r;
            out->sclRnd[1] = r;
            out->sclRnd[0] = r;
            if (((EffFlagByte*)&desc->sclFlags)->f.b0 && (desc->sclFlags & 2)) {
                if (func_00207260() > 0.5) {
                    for (i = 0, p8 = &out->sclVel[2]; i < 3; i++, p8++) p8[1] = -p8[1];
                }
            } else if (desc->sclFlags & 2) {
                for (i = 0, p9 = &out->sclVel[2]; i < 3; i++, p9++) p9[1] = -p9[1];
            }
        } else {
            out->sclRnd[0] = func_00207260() * desc->sclRnd[0];
            out->sclRnd[1] = func_00207260() * desc->sclRnd[1];
            out->sclRnd[2] = func_00207260() * desc->sclRnd[2];
            if (((EffFlagByte*)&desc->sclFlags)->f.b0 && (desc->sclFlags & 2)) {
                p10 = &out->sclVel[2];
                for (i = 0; i < 3; i++) {
                    if (func_00207260() > 0.5) p10[i + 1] = -p10[i + 1];
                }
            } else if (desc->sclFlags & 2) {
                for (i = 0, p11 = &out->sclVel[2]; i < 3; i++, p11++) p11[1] = -p11[1];
            }
        }
    }
    if ((desc->sclFlags & 4)) {
        for (k = 0; k < 3; k++) out->scl[k] += out->sclRnd[k];
    }
    if ((desc->sclFlags & 8)) {
        for (k = 0; k < 3; k++) out->sclVel[k] += out->sclRnd[k];
    }

    out->f90 = desc->dc;
    out->f94 = desc->e8;
    {
        f32 d = desc->dcRnd;
        if (d != 0.0f) out->f90 += (d + d) * func_00207260() - desc->dcRnd;
    }
    out->life0 = desc->ac;
    out->life1 = desc->b8;
    out->fa0 = desc->b0;
    out->fa4 = desc->bc;
    switch (desc->lifeMode) {
    case 1:
        out->life0 *= func_00207260();
        break;
    case 2:
        out->life1 *= func_00207260();
        break;
    case 3: {
        f32 r = func_00207260();
        out->life0 *= r;
        out->life1 *= r;
        break;
    }
    case 4:
        out->life0 *= func_00207260();
        out->life1 *= func_00207260();
        break;
    }
    if (!desc->id) out->id = 0xffff;
    else out->id = desc->id;
    out->bac = 0;
    if (p40) eff_f3f98(p40, D_01d9e6f0);
    if (pcol) {
        pcol->col[0] = desc->col[0];
        pcol->col[1] = desc->col[1];
        pcol->col[2] = desc->col[2];
        pcol->col[3] = desc->col[3];
    }
}
