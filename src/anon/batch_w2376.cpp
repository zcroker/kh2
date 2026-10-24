#include "../common/types.h"
extern "C" {
s32 func_001860b0(u8*, u8*);
s32 func_00186110(u8*, u8*);
s32 func_0017f4e0(u8*, u16);
void func_0017f488(u8*, u16, f32, f32);
void func_0017f5e0(u8*, u32, s32, f32, f32);
extern u16 D_0034edf8[];

// Pick one of four motions (by facing and a second check, flip if unavailable) and play it.
void func_00186478(u8* a, u8* b) {
    s32 i;
    if (func_001860b0(a, b)) i = 0; else i = 2;
    if (!func_00186110(a, b)) i++;
    if (!func_0017f4e0(a + 320, D_0034edf8[i])) i ^= 1;
    func_0017f488(a + 320, D_0034edf8[i], 0.0f, 0.0f);
    func_0017f5e0(a + 320, 0, 0, 0.0f, 0.0f);
    *(u32*)(b + 24) |= 1;
}
struct Rec_195360 { u8 pad[8]; s32 v; };
struct Pair_195360 { s32 a, b; };
Rec_195360* func_00168b88(s32, s32, s32, s32);
extern s32 D_01c61afc;
extern s8 D_0036d018[];
static inline s32 tag_195360(const s8* s) { return s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24); }
static inline Rec_195360* find_195360(s32 g, s32 id) { return func_00168b88(g, id, tag_195360(D_0036d018), 0); }

// Read the values of entries 0x18 and 0x19 (tagged by the 4-char name at D_0036d018).
void func_00195360(Pair_195360* out) {
    Rec_195360* a = find_195360(D_01c61afc, 0x18);
    Rec_195360* b = find_195360(D_01c61afc, 0x19);
    s32 x = a->v; s32 y = b->v;
    out->a = x; out->b = y;
}
struct Vec_2da238 { f32 x, y, z, w; } __attribute__((aligned(16)));
struct Info_2da238 { u8 pad[16]; s16 radius; };
struct Obj_2da238 { u8 pad[1344]; Vec_2da238 pos; u8 pad2[3056 - 1344 - 16]; void* target; };
s32 is_attach_2da238(void* o) asm("_ZN2YS3OBJ9is_attachEv");
s32 is_separate_blow_2da238(void* o) asm("_ZN2Ti14MGHachimitsuPo16is_separate_blowEv");
Info_2da238* func_0016bc20(void*, s32, s32);
Vec_2da238* func_0016c028(void*);
extern s32 D_00361f60;

// VU0 distance between two points.
static inline f32 dist_2da238(const Vec_2da238* a, const Vec_2da238* b) {
    Vec_2da238 d;
    f32 len;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
        : : "r"(&d), "r"(a), "r"(b) : "memory");
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0\n\t.set reorder"
        : "=f"(len) : "r"(&d) : "$8", "memory");
    return len;
}
static inline bool in_reach_2da238(Obj_2da238* self) {
    if (is_attach_2da238(self->target) || is_separate_blow_2da238(self->target)) return false;
    f32 r = func_0016bc20(self->target, 5, -1)->radius;
    if (dist_2da238(&self->pos, func_0016c028(self->target)) < r) return true;
    return false;
}

// True when enabled, the target is free (not attached, not blown apart) and within the target's radius.
s32 func_002da238(Obj_2da238* self) {
    return D_00361f60 && self->target && in_reach_2da238(self);
}
struct Rec_1dfdb8 { u8 pad[0xc]; f32 f; };
struct Hdr_1dfdb8 { u8 pad[6]; u16 id; };
struct Part_1dfdb8 { u8 pad[0xaf8]; Part_1dfdb8* l; Part_1dfdb8* r; };
struct Obj_1dfdb8 { u8 pad[0x40]; s32 x40; Hdr_1dfdb8* h; Part_1dfdb8* p; };
f32 func_00194690(Part_1dfdb8*);
extern s32 D_00352b50;
s32 func_0019ba60(Part_1dfdb8*);
s32 func_0019c5d0(Part_1dfdb8*);
Rec_1dfdb8* func_001dc670(s32);

// Store a factor (1, or the left/right part's value when mode 1 is on and the part is usable) into the record.
void func_001dfdb8(Obj_1dfdb8* o) {
    f32 f = 1.0f;
    if (D_00352b50 == 1) {
        Part_1dfdb8* p = o->p;
        switch (o->h->id) {
        case 0x4003: case 0x4005: case 0x4007: p = p->l; break;
        case 0x4004: case 0x4006: case 0x4008: p = p->r; break;
        }
        if (!func_0019ba60(p) || func_0019c5d0(p)) f = 0.0f;
        else f = func_00194690(p);
    }
    func_001dc670(o->x40)->f = f;
}
// Modulate an RGBA colour by another (128 = 1.0), clamping each channel to 255.
#define MOD_CH_233708(i) \
    if (((u8*)&m)[i] != 128) { \
        u32 v = (((u8*)&c)[i] * ((u8*)&m)[i]) >> 7; \
        if (v >= 256) ((u8*)&c)[i] = 0xff; else ((u8*)&c)[i] = v; \
    }
u32 func_00233708(u32 c, u32 m) {
    MOD_CH_233708(0)
    MOD_CH_233708(1)
    MOD_CH_233708(2)
    MOD_CH_233708(3)
    return c;
}
#undef MOD_CH_233708
}
