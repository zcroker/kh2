// Linked unit 0x001f7010-0x001f7b40 (ppp programs; one namespace per old matched source, gap functions written for the unit).
#include "../common/types.h"
#include <stdarg.h>
// gcc 3.2 soft-float double helpers in this toolchain: bind them to the retail libgcc copies.

asm("dpdiv = func_00314190");
asm("fptodp = func_00313b80");
asm("dptoli = func_003143e0");
// 001f7010 (gap, written for the unit)
namespace n001f7010 {
struct V4 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Mgr { u8 pad[0xa8]; u64 flags; };
struct Ctx { u8 pad[12]; s32* off; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern Mgr* D_01d9e6e0 asm("D_01d9e6e0");
s32 func_001f6eb8(V4*, f32*) asm("func_001f6eb8");
f32 func_00222978(f32) asm("func_00222978");
void func_001f7010(u8* o, u8* in, Ctx* c) asm("func_001f7010");
void func_001f7010(u8* o, u8* in, Ctx* c) {
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    s32* off = c->off;
    f32* v = (f32*)(o + off[1] + 160);
    f32 x = v[0];
    f32 y = v[1];
    if (y == 0.0f && x == 0.0f && v[2] == 0.0f) return;
    s32* r = (s32*)(o + off[0] + 160);
    V4 p;
    f32 ang;
    p.x = -y;
    p.y = x;
    if (func_001f6eb8(&p, &ang)) r[2] = (s32)((double)(ang * 32768.0f) / 3.141592654);
    y = y * y + x * x;
    p.x = func_00222978(y);
    p.y = -v[2];
    if (func_001f6eb8(&p, &ang)) r[0] = (s32)((double)(ang * 32768.0f) / 3.141592654);
}
}  // namespace n001f7010

// 001f7180 (was src/anon/batch_w1984_nsa.cpp)
namespace n001f7180 {
// 0x0019dd10: definition moved into src/anon/unit_0019ba60.cpp

// 001f7180, 001f7660
struct F7Gs { u8 pad[16]; u8* ent; u8 pad2[148]; u64 st; };
struct F7Idx { s32 f0; s32 f4; s32 f8; };
struct F7Ctx { u8 pad[12]; F7Idx* idx; };
struct F7Mot { f32 x, vx, ax; };
struct F7Req { s32 id; s32 tex; f32 dx, dvx, dax; s32 sx; s32 sy; u8 frame; u8 f29; };
struct F7Tex { u8 pad[16]; u32 bits; u8 pad2[16]; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern F7Gs* D_01d9e6e0 asm("D_01d9e6e0");
extern F7Gs* D_01d9e6e4 asm("D_01d9e6e4");
extern u8* D_01d9eaa4 asm("D_01d9eaa4");
union F7IdU { s32 v; u8 c; };
union F7TagU { u64 v; u8 c; };
union F7PkU { u8* p; u8 c; };
void sceGsSetDefLoadImage(u8* p, u32 a, s32 b, u32 c, s32 d, s32 e, s32 f, s32 g) asm("sceGsSetDefLoadImage");
void func_00222aa8(s32 a, s32 b, u8* p, f32 x) asm("func_00222aa8");
void func_0020e7a8(u8* p, s32 a, s32 b, s32 c) asm("func_0020e7a8");
void func_00222d40(s32 tex, u8* pos, u32 frame, s32 y, s32 z, s32 a, s32 b) asm("func_00222d40");
/*TARGET 001f7180*/
void func_001f7180(u8* o, F7Req* r, F7Ctx* c) asm("func_001f7180");
void func_001f7180(u8* o, F7Req* r, F7Ctx* c)
{
    F7Mot* m = (F7Mot*)(o + c->idx->f8 + 160);
    if (D_01d9ea9c == 0 && !(D_01d9e6e0->st & 0xff0000ff00ULL)) {
        m->vx += m->ax;
        m->x += m->vx;
        if (((F7IdU*)(o + 12))->v == ((F7IdU*)&r->id)->v) {
            m->x += r->dx;
            m->vx += r->dvx;
            m->ax += r->dax;
        }
    }
    if (r->tex == 0xffff) return;
    {
        s32 off = r->tex * 36;
        u32 frame = r->frame * 4;
        u8* p = D_01d9eaa4 + 16;
        u32 bits = ((F7Tex*)(D_01d9e6e4->ent + off))->bits;
        u8* q;
        sceGsSetDefLoadImage(p, ((bits >> 5) & 0x3fff) + frame, 4, (bits >> 19) & 0xf, 0, 0, 16, 16);
        ((F7TagU*)(p + 80))->v = 0x0800000000008100ULL;
        q = ((F7PkU*)&D_01d9eaa4)->p;
        func_00222aa8(r->sx, r->sy, q + 112, m->x);
        func_0020e7a8(D_01d9eaa4, 263, 0, 0);
        ((F7PkU*)&D_01d9eaa4)->p = q + 4208;
        func_00222d40(r->tex, o + c->idx->f0 + 160, frame, 0, 0, 1, 0);
    }
}
}  // namespace n001f7180

// 001f7378 (gap, written for the unit)
namespace n001f7378 {
struct S { s32 a, b, c; };
void func_001f7378(u8* self, u8* t) asm("func_001f7378");
void func_001f7378(u8* self, u8* t) {
    S* s = (S*)(self + (*(s32**)(t + 12))[2] + 0xa0);
    s->a = 0;
    s->b = 0;
    s->c = 0;
}
}  // namespace n001f7378

// 001f7398 (was src/anon/batch_wcx2.cpp)
namespace n001f7398 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
// 0x00144e50: definition moved into src/anon/unit_00144450.cpp

// --------------------
// Effect particle: integrate motion, apply the per-frame delta, then emit its sprite.
struct Gs1f7398 { u8 pad[16]; u8* ent; u8 pad2[148]; u64 st; };
struct Idx1f7398 { s32 f0; s32 f4; s32 f8; };
struct Ctx1f7398 { u8 pad[12]; Idx1f7398* idx; };
struct Mot1f7398 { f32 x, vx, ax, pad; f32 y, vy, ay, z, vz, az; };
struct Req1f7398 {
    s32 id; s32 tex; f32 dx, dvx, dax; s32 sx; s32 sy; u8 frame; u8 pad29[3];
    f32 dy, dvy, day, dz, dvz, daz; u8 f56;
};
struct Tex1f7398 { u8 pad[16]; u32 bits; u8 pad2[16]; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern Gs1f7398* D_01d9e6e0_x13984 asm("D_01d9e6e0");
extern Gs1f7398* D_01d9e6e4 asm("D_01d9e6e4");
extern u8* D_01d9eaa4 asm("D_01d9eaa4");
union IdU1f7398 { s32 v; u8 c; };
union TagU1f7398 { u64 v; u8 c; };
union PkU1f7398 { u8* p; u8 c; };
void sceGsSetDefLoadImage(u8* p, u32 a, s32 b, u32 c, s32 d, s32 e, s32 f, s32 g) asm("sceGsSetDefLoadImage");
void func_00222aa8(s32 a, s32 b, u8* p, f32 x) asm("func_00222aa8");
void func_0020e7a8(u8* p, s32 a, s32 b, s32 c) asm("func_0020e7a8");
void func_00222d40(s32 tex, u8* pos, u32 frame, s32 y, s32 z, s32 a, s32 b) asm("func_00222d40");
/*TARGET 001f7398*/
void func_001f7398(u8* o, Req1f7398* r, Ctx1f7398* c) asm("func_001f7398");
void func_001f7398(u8* o, Req1f7398* r, Ctx1f7398* c)
{
    Mot1f7398* m = (Mot1f7398*)(o + c->idx->f8 + 160);
    if (D_01d9ea9c == 0 && !(D_01d9e6e0_x13984->st & 0xff0000ff00ULL)) {
        m->vx += m->ax;
        m->vy += m->ay;
        m->vz += m->az;
        m->x += m->vx;
        m->y += m->vy;
        m->z += m->vz;
        if (((IdU1f7398*)(o + 12))->v == ((IdU1f7398*)&r->id)->v) {
            m->x += r->dx;
            m->vx += r->dvx;
            m->ax += r->dax;
            m->y += r->dy;
            m->vy += r->dvy;
            m->ay += r->day;
            m->z += r->dz;
            m->vz += r->dvz;
            m->az += r->daz;
        }
    }
    if (r->tex == 0xffff) return;
    {
        s32 off = r->tex * 36;
        u32 frame = r->frame * 4;
        u8* p = D_01d9eaa4 + 16;
        u32 bits = ((Tex1f7398*)(D_01d9e6e4->ent + off))->bits;
        u8* q;
        sceGsSetDefLoadImage(p, ((bits >> 5) & 0x3fff) + frame, 4, (bits >> 19) & 0xf, 0, 0, 16, 16);
        ((TagU1f7398*)(p + 80))->v = 0x0800000000008100ULL;
        q = ((PkU1f7398*)&D_01d9eaa4)->p;
        func_00222aa8(r->sx, r->sy, q + 112, m->x);
        func_0020e7a8(D_01d9eaa4, 263, 0, 0);
        ((PkU1f7398*)&D_01d9eaa4)->p = q + 4208;
        func_00222d40(r->tex, o + c->idx->f0 + 160, frame, (s32)m->y, (s32)m->z, 1, 0);
    }
}
}  // namespace n001f7398

// 001f7620 (gap, written for the unit)
namespace n001f7620 {
struct S { f32 a, b, c, d, e, f, g, h, i, j; };
void func_001f7620(u8* self, u8* t) asm("func_001f7620");
void func_001f7620(u8* self, u8* t) {
    S* s = (S*)(self + (*(s32**)(t + 12))[2] + 0xa0);
    s->a = s->b = s->c = s->e = s->f = s->g = s->h = s->i = s->j = 0.0f;
}
}  // namespace n001f7620

// 001f7660 (was src/anon/batch_w1984_nsa.cpp)
namespace n001f7660 {
// 0x0019dd10: definition moved into src/anon/unit_0019ba60.cpp

// 001f7180, 001f7660
struct F7Gs { u8 pad[16]; u8* ent; u8 pad2[148]; u64 st; };
struct F7Idx { s32 f0; s32 f4; s32 f8; };
struct F7Ctx { u8 pad[12]; F7Idx* idx; };
struct F7Mot { f32 x, vx, ax; };
struct F7Req { s32 id; s32 tex; f32 dx, dvx, dax; s32 sx; s32 sy; u8 frame; u8 f29; };
struct F7Tex { u8 pad[16]; u32 bits; u8 pad2[16]; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern F7Gs* D_01d9e6e0 asm("D_01d9e6e0");
extern F7Gs* D_01d9e6e4 asm("D_01d9e6e4");
extern u8* D_01d9eaa4 asm("D_01d9eaa4");
union F7IdU { s32 v; u8 c; };
union F7TagU { u64 v; u8 c; };
union F7PkU { u8* p; u8 c; };
void sceGsSetDefLoadImage(u8* p, u32 a, s32 b, u32 c, s32 d, s32 e, s32 f, s32 g) asm("sceGsSetDefLoadImage");
void func_00222aa8(s32 a, s32 b, u8* p, f32 x) asm("func_00222aa8");
void func_0020e7a8(u8* p, s32 a, s32 b, s32 c) asm("func_0020e7a8");
void func_00222d40(s32 tex, u8* pos, u32 frame, s32 y, s32 z, s32 a, s32 b) asm("func_00222d40");
/*TARGET 001f7660*/
void func_001f7660(u8* o, F7Req* r, F7Ctx* c) asm("func_001f7660");
void func_001f7660(u8* o, F7Req* r, F7Ctx* c)
{
    F7Mot* m = (F7Mot*)(o + c->idx->f8 + 160);
    if (D_01d9ea9c == 0 && !(D_01d9e6e0->st & 0xff0000ff00ULL)) {
        m->vx += m->ax;
        m->x += m->vx;
        if (((F7IdU*)(o + 12))->v == ((F7IdU*)&r->id)->v) {
            m->x += r->dx;
            m->vx += r->dvx;
            m->ax += r->dax;
        }
    }
    if (r->tex == 0xffff) return;
    {
        s32 off = r->tex * 36;
        u32 frame = r->frame * 4;
        u8* p = D_01d9eaa4 + 16;
        u32 bits = ((F7Tex*)(D_01d9e6e4->ent + off))->bits;
        u8* q;
        sceGsSetDefLoadImage(p, ((bits >> 5) & 0x3fff) + frame, 4, (bits >> 19) & 0xf, 0, 0, 16, 16);
        ((F7TagU*)(p + 80))->v = 0x0800000000008100ULL;
        q = ((F7PkU*)&D_01d9eaa4)->p;
        func_00222aa8(r->sx, r->sy, q + 112, m->x);
        func_0020e7a8(D_01d9eaa4, 263, 0, 0);
        ((F7PkU*)&D_01d9eaa4)->p = q + 4208;
        func_00222d40(r->tex, o + c->idx->f0 + 160, frame, 0, 0, r->f29, 0);
    }
}
}  // namespace n001f7660

// 001f7858 (gap, written for the unit)
namespace n001f7858 {
struct S { s32 a, b, c; };
void func_001f7858(u8* self, u8* t) asm("func_001f7858");
void func_001f7858(u8* self, u8* t) {
    S* s = (S*)(self + (*(s32**)(t + 12))[2] + 0xa0);
    s->a = 0;
    s->b = 0;
    s->c = 0;
}
}  // namespace n001f7858

// 001f7878 (was src/anon/batch_wcx2.cpp)
namespace n001f7878 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
// --------------------
// Effect particle: integrate motion, apply the per-frame delta, then emit its sprite.
struct Gs1f7878 { u8 pad[16]; u8* ent; u8 pad2[148]; u64 st; };
struct Idx1f7878 { s32 f0; s32 f4; s32 f8; };
struct Ctx1f7878 { u8 pad[12]; Idx1f7878* idx; };
struct Mot1f7878 { f32 x, vx, ax, pad; f32 y, vy, ay, z, vz, az; };
struct Req1f7878 {
    s32 id; s32 tex; f32 dx, dvx, dax; s32 sx; s32 sy; u8 frame; u8 pad29[3];
    f32 dy, dvy, day, dz, dvz, daz; u8 f56;
};
struct Tex1f7878 { u8 pad[16]; u32 bits; u8 pad2[16]; };
extern s32 D_01d9ea9c asm("D_01d9ea9c");
extern Gs1f7878* D_01d9e6e0_x14045 asm("D_01d9e6e0");
extern Gs1f7878* D_01d9e6e4_x14046 asm("D_01d9e6e4");
extern u8* D_01d9eaa4 asm("D_01d9eaa4");
union IdU1f7878 { s32 v; u8 c; };
union TagU1f7878 { u64 v; u8 c; };
union PkU1f7878 { u8* p; u8 c; };
void sceGsSetDefLoadImage(u8* p, u32 a, s32 b, u32 c, s32 d, s32 e, s32 f, s32 g) asm("sceGsSetDefLoadImage");
void func_00222aa8(s32 a, s32 b, u8* p, f32 x) asm("func_00222aa8");
void func_0020e7a8(u8* p, s32 a, s32 b, s32 c) asm("func_0020e7a8");
void func_00222d40(s32 tex, u8* pos, u32 frame, s32 y, s32 z, s32 a, s32 b) asm("func_00222d40");
/*TARGET 001f7878*/
void func_001f7878(u8* o, Req1f7878* r, Ctx1f7878* c) asm("func_001f7878");
void func_001f7878(u8* o, Req1f7878* r, Ctx1f7878* c)
{
    Mot1f7878* m = (Mot1f7878*)(o + c->idx->f8 + 160);
    if (D_01d9ea9c == 0 && !(D_01d9e6e0_x14045->st & 0xff0000ff00ULL)) {
        m->vx += m->ax;
        m->vy += m->ay;
        m->vz += m->az;
        m->x += m->vx;
        m->y += m->vy;
        m->z += m->vz;
        if (((IdU1f7878*)(o + 12))->v == ((IdU1f7878*)&r->id)->v) {
            m->x += r->dx;
            m->vx += r->dvx;
            m->ax += r->dax;
            m->y += r->dy;
            m->vy += r->dvy;
            m->ay += r->day;
            m->z += r->dz;
            m->vz += r->dvz;
            m->az += r->daz;
        }
    }
    if (r->tex == 0xffff) return;
    {
        s32 off = r->tex * 36;
        u32 frame = r->frame * 4;
        u8* p = D_01d9eaa4 + 16;
        u32 bits = ((Tex1f7878*)(D_01d9e6e4_x14046->ent + off))->bits;
        u8* q;
        sceGsSetDefLoadImage(p, ((bits >> 5) & 0x3fff) + frame, 4, (bits >> 19) & 0xf, 0, 0, 16, 16);
        ((TagU1f7878*)(p + 80))->v = 0x0800000000008100ULL;
        q = ((PkU1f7878*)&D_01d9eaa4)->p;
        func_00222aa8(r->sx, r->sy, q + 112, m->x);
        func_0020e7a8(D_01d9eaa4, 263, 0, 0);
        ((PkU1f7878*)&D_01d9eaa4)->p = q + 4208;
        func_00222d40(r->tex, o + c->idx->f0 + 160, frame, (s32)m->y, (s32)m->z, r->f56, 0);
    }
}
}  // namespace n001f7878

// 001f7b00 (gap, written for the unit)
namespace n001f7b00 {
struct S { f32 a, b, c, d, e, f, g, h, i, j; };
void func_001f7b00(u8* self, u8* t) asm("func_001f7b00");
void func_001f7b00(u8* self, u8* t) {
    S* s = (S*)(self + (*(s32**)(t + 12))[2] + 0xa0);
    s->a = s->b = s->c = s->e = s->f = s->g = s->h = s->i = s->j = 0.0f;
}
}  // namespace n001f7b00

