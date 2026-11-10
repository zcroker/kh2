#include "../common/types.h"

typedef struct { u32 w[4]; } __attribute__((aligned(16))) Q16_fc7;
typedef struct { u8 pad[16]; u8* ent; u8 pad2[148]; u64 st; } Gs_fc7;
typedef struct { s32 f0; s32 f4; s32 f8; } Idx_fc7;
typedef struct { u8 pad[12]; Idx_fc7* idx; } Ctx_fc7;
typedef struct { f32 x, vx, ax; } Mot_fc7;
typedef struct { s32 id; s32 tex; f32 dx, dvx, dax; u32 c0; u32 c1; } Req_fc7;
typedef struct { u8 pad[12]; s32 lo; s32 hi; u8 pad2[16]; } Tex_fc7;
typedef struct { u32 clut[256]; union { s8 step[32]; Q16_fc7 q[2]; } u; } Clut_fc7;
typedef struct { f32 x, y, z, w; } V4_fc7;
union IdU_fc7 { s32 v; u8 c; };

extern s32 D_01d9ea9c;
extern Gs_fc7* D_01d9e6e0;
extern Gs_fc7* D_01d9e6e4;
extern Q16_fc7 D_0035da40;
extern Q16_fc7 D_0035da50;
extern s8 D_0035da60[];
void* func_0020eaf8(s32);
void func_0020ebd8(s32);
void sceVu0SubVector(void*, void*, void*);
void sceVu0DivVector(void*, void*, f32);
void sceVu0AddVector(void*, void*, void*);
u32 __fixunssfsi(f32);
void sceGsSetDefLoadImage(void*, s16, s32, s16, s32, s32, s32, s32);
void func_003058a0(s32);
void sceGsExecLoadImage(void*, void*);
void sceGsSyncPath(s32, s32);

void func_001fc720(u8* o, Req_fc7* r, Ctx_fc7* c)
{
    Mot_fc7* m = (Mot_fc7*)(o + c->idx->f0 + 160);
    if (D_01d9ea9c == 0 && !(D_01d9e6e0->st & 0xff0000ff00ULL)) {
        m->vx += m->ax;
        m->x += m->vx;
        if (((union IdU_fc7*)(o + 12))->v == ((union IdU_fc7*)&r->id)->v) {
            m->x += r->dx;
            m->vx += r->dvx;
            m->ax += r->dax;
        }
    }
    if (r->tex == 0xffff) return;
    {
        Clut_fc7* b = (Clut_fc7*)func_0020eaf8(0x420);
        u32 c0, c1;
        u64 bits;
        s32 n, i;
        u32* p;
        f32 f;
        V4_fc7 a, d;
        u8 pk[96];
        Tex_fc7* t;
        b->u.q[0] = D_0035da40;
        b->u.q[1] = D_0035da50;
        n = (s32)m->x;
        c0 = r->c0;
        c1 = r->c1;
        t = (Tex_fc7*)(D_01d9e6e4->ent + r->tex * 36);
        bits = ((u64)t->hi << 32) | t->lo;
        if (n < 0) {
            if (n < -256) n = -256;
            n += 256;
            p = &b->clut[(n & 0xe0) + D_0035da60[n & 0x1f]];
            for (i = n; i < 256; i++) {
                *p = c0;
                p += b->u.step[i & 0x1f];
            }
            f = (f32)n;
            i = 0;
            p = b->clut;
        } else {
            if (n >= 256) n = 255;
            p = b->clut;
            i = 0;
            if (n > 0) {
                do {
                    *p = c1;
                    p += b->u.step[i & 0x1f];
                    i++;
                } while (i < n);
            }
            f = 256.0f - (f32)n;
            n = 256;
        }
        d.x = (f32)(s32)(c1 & 0xff);
        d.y = (f32)(s32)((c1 >> 8) & 0xff);
        d.z = (f32)(s32)((c1 >> 16) & 0xff);
        d.w = (f32)(s32)(c1 >> 24);
        a.x = (f32)(s32)(c0 & 0xff);
        a.y = (f32)(s32)((c0 >> 8) & 0xff);
        a.z = (f32)(s32)((c0 >> 16) & 0xff);
        a.w = (f32)(s32)(c0 >> 24);
        sceVu0SubVector(&a, &a, &d);
        sceVu0DivVector(&a, &a, f);
        if (i < n) {
            do {
                u32 v = __fixunssfsi(d.w) << 24 | __fixunssfsi(d.x);
                *p = v | (__fixunssfsi(d.y) << 8 | __fixunssfsi(d.z) << 16);
                sceVu0AddVector(&d, &d, &a);
                p += b->u.step[i & 0x1f];
                i++;
            } while (i < n);
        }
        sceGsSetDefLoadImage(pk, (u16)((bits >> 37) & 0x3fff), 4, (u16)((bits >> 51) & 0xf), 0, 0, 16, 16);
        func_003058a0(0);
        sceGsExecLoadImage(pk, b);
        sceGsSyncPath(0, 0);
        func_0020ebd8(0x420);
    }
}
