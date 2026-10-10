#include "../common/types.h"

extern "C" {
f32 func_002f8a18(f32);
f32 func_002f8420(f32);

struct Proj106 { u8 pad[64]; f32 dist; f32 fovx; f32 fovy; f32 w; f32 h; };

// Sets the projection distance from a field of view (horizontal or vertical) and derives the other angle.
void func_00106de8(Proj106* p, s32 vert, f32 fov) {
    if (!vert) {
        f32 d = 512.0f / p->w * 0.5f / func_002f8a18(fov * 0.5f);
        p->fovx = fov;
        p->dist = d;
        p->fovy = func_002f8420(416.0f / p->h * 0.5f / d) * 2;
    } else {
        f32 d = 416.0f / p->h * 0.5f / func_002f8a18(fov * 0.5f);
        p->dist = d;
        f32 r = func_002f8420(512.0f / p->w * 0.5f / d) * 2;
        p->fovy = fov;
        p->fovx = r;
    }
}

struct ImgHdr166 { u8 pad[12]; u16 dataOff; u8 pad2[5]; u8 kind; u16 w; u16 h; };
extern u8 D_004f41d0[];
void func_00166148(u8*, s32, s32);
void func_002f2aa0(void*, s32, s16, s32, s32, s32, s16, s16);
void func_003058a0(s32);
void func_002f25a0(s32, s32);
void func_002f2d60(void*, u8*);

// Uploads an image once, converting kinds 4/5 to their uploaded kinds 6/7.
void func_001664c0(u8* p) {
    ImgHdr166* h = (ImgHdr166*)(p + 16);
    u8* data = (u8*)h + h->dataOff;
    if ((u8)(h->kind - 6) < 2) return;
    func_00166148(p, 10240, 13568);
    s32 x = 0, y = 0, z = 0;
    switch (h->kind) {
    case 4:
        x = h->w >> 7;
        y = h->w >> 1;
        z = h->h >> 2;
        h->kind = 6;
        break;
    case 5:
        x = h->w >> 7;
        y = h->w >> 1;
        z = h->h >> 1;
        h->kind = 7;
        break;
    }
    func_002f2aa0(D_004f41d0, 10240, x, 0, 0, 0, y, z);
    func_003058a0(0);
    func_002f25a0(0, 0);
    func_002f2d60(D_004f41d0, data);
}

struct M174 { f32 m[4][4]; } __attribute__((aligned(16)));
struct IV174 { f32 x, y, z; s32 w; };
union PU174 { IV174* p; f32 f; };
extern IV174 D_01c5f480;
u8* func_00106a18(s32);  // buffer_get_256
u8* func_00106a60(s32);  // buffer_get_by_index
void func_002f47d8(void*, void*, void*, u32);  // mat4_transform_perspective
static inline void mulmat174(M174* d, const void* a, const void* b) {
    asm volatile(
        "lqc2 $vf1,0(%1)\n\tlqc2 $vf2,16(%1)\n\tlqc2 $vf3,32(%1)\n\tlqc2 $vf4,48(%1)\n\t"
        "lqc2 $vf5,0(%2)\n\tlqc2 $vf6,16(%2)\n\tlqc2 $vf7,32(%2)\n\tlqc2 $vf8,48(%2)\n\t"
        "vmulax.wxyz ACC,$vf1,$vf5x\n\tvmadday.wxyz ACC,$vf2,$vf5y\n\tvmaddaz.wxyz ACC,$vf3,$vf5z\n\tvmaddw.wxyz $vf5,$vf4,$vf5w\n\t"
        "vmulax.wxyz ACC,$vf1,$vf6x\n\tvmadday.wxyz ACC,$vf2,$vf6y\n\tvmaddaz.wxyz ACC,$vf3,$vf6z\n\tvmaddw.wxyz $vf6,$vf4,$vf6w\n\t"
        "vmulax.wxyz ACC,$vf1,$vf7x\n\tvmadday.wxyz ACC,$vf2,$vf7y\n\tvmaddaz.wxyz ACC,$vf3,$vf7z\n\tvmaddw.wxyz $vf7,$vf4,$vf7w\n\t"
        "vmulax.wxyz ACC,$vf1,$vf8x\n\tvmadday.wxyz ACC,$vf2,$vf8y\n\tvmaddaz.wxyz ACC,$vf3,$vf8z\n\tvmaddw.wxyz $vf8,$vf4,$vf8w\n\t"
        "sqc2 $vf5,0(%0)\n\tsqc2 $vf6,16(%0)\n\tsqc2 $vf7,32(%0)\n\tsqc2 $vf8,48(%0)"
        : : "r"(d), "r"(a), "r"(b) : "memory");
}
// Projects *pv to screen space and replaces it with a pointer to the static result vector.
void func_00174e38(PU174* pv) {
    M174 m;
    s32 o[4];
    u8* a = func_00106a18(1);  // buffer_get_256
    u8* b = func_00106a60(1);  // buffer_get_by_index
    mulmat174(&m, a, b ? b + 16 : 0);
    func_002f47d8(o, &m, pv->p, 0);  // mat4_transform_perspective
    D_01c5f480.x = (f32)((o[0] >> 4) - 2048);
    D_01c5f480.y = (f32)((o[1] >> 4) - 2048);
    D_01c5f480.z = (f32)(o[2] >> 4);
    D_01c5f480.w = 0;
    pv->p = &D_01c5f480;
}
struct Tmp178 { u8 pad[112]; };
u8* func_00176fb0(u8*, s32);
s32 func_001a0920(u8*, u8*);
void func_001cda88(Tmp178*, u8*, u32);
u8* func_001cde58(Tmp178*);
void func_00177008(u8*, u8*, u32);
void func_0017f488(u8*, u16, f32, f32);
void func_0017f5e0(u8*, s32, s32, f32, f32);
void func_001bbd58(u8*);
void func_00178e80(void);
extern u8* D_00351068;

// Picks or builds the effect entry for this object, then applies it.
void func_00178d28(u8* p) {
    u8* m = p + 320;
    u8* e = 0;
    if (*(s32*)(m + 20) == 42) {
        e = func_00176fb0(p, 39);
        if (e && !func_001a0920(e, p)) e = 0;
    }
    u32 k = *(u32*)(*(u8**)(p + 12) + 4);
    if ((k ^ 0x16) == 0 || (k ^ 0x1a) == 0) {
        e = func_00176fb0(p, 41);
        if (e && !func_001a0920(e, p)) e = 0;
    }
    if (!e) {
        Tmp178 t;
        func_001cda88(&t, p, *(u32*)(p + 2880) + 4);
        e = func_001cde58(&t);
    }
    func_00177008(p, e, *(u32*)(p + 2880) + 4);
    if (*(u32*)(*(u8**)(p + 12) + 8) & 0x20) {
        u16 id = *(u16*)(e + 8);
        if (id > 210) {
        func_0017f488(D_00351068 + 320, id, 0.0f, 0.0f);
        func_0017f5e0(D_00351068 + 320, 0, 0, 0.0f, 0.0f);
        *(void**)(m + 404) = (void*)func_00178e80;
        }
    }
    func_001bbd58(e);
}

extern u32 D_01c60528[2];
extern f32 D_01c60520;
extern u32 D_0034ebc8[];
void func_00175670(u8*, u32, s32, u32);
u8* func_0016a070(u8*);
u8* func_001a1540(u8*);
u8* func_0016f6a0(u32, s32);
void func_00176168(u8*, u8*, s32);

// Constructor: registers in the 2-slot table and attaches child parts.
void func_0017d968(u8* p, u32 a, u32 b) {
    s32 i = 0;
    func_00175670(p, a, 1, b);
    *(u32*)(p + 2872) = 0;
    *(u32*)(p + 2880) = 0;
    *(u32*)(p + 2884) = 0;
    *(u32*)p = (u32)D_0034ebc8;
    *(u8*)(p + 2892) = 0;
    for (; i < 2; i++) {
        if (!D_01c60528[i]) break;
    }
    *(s32*)(p + 2888) = i;
    D_01c60528[i] = (u32)p;
    *(u32*)(p + 1416) |= 0x4000;
    u8* r = func_001a1540(func_0016a070(p));
    *(u8**)(p + 1164) = r;
    if (r) *(u8**)(r + 604) = p;
    f32 w = D_01c60520;
    *(f32*)(p + 2876) = (w + w) * i - w;
    for (i = 0; i < 2; i++) {
        u8* e = func_0016f6a0(a, i);
        if (e) func_00176168(p, e, i);
    }
    *(u32*)(p + 1896) |= 0x10;
}

struct Ent180 { u8 pad[6]; u16 id; u8 pad2[10]; s16 val; };
struct Slot180 { u8 pad[32]; };
struct Obj180 { u8 pad[8]; u8* body; u8 pad2[248]; u32 active : 1; };
s32 func_0019bad8(u8*);
Ent180* func_0016bba8(u8*, s32, Ent180*);
void func_0011c148(Slot180*, u32, u16, s32, s32, f32);
void func_0011c210(Slot180*);

// Fills buf with one slot per type-10 then type-11 child of the body, then terminates the list.
void func_001808c0(Obj180* o, Slot180* buf) {
    if (!o->active || (*(u32*)(o->body + 264) & 0x40000000)
        || (!func_0019bad8(o->body) && !(*(u32*)(o->body + 1416) & 0x20))) {
        func_0011c210(buf);
        return;
    }
    s32 n = 0;
    Ent180* e = 0;
    while ((e = func_0016bba8(o->body, 10, e)) != 0) {
        func_0011c148(&buf[n], *(u32*)(o->body + 2224), e->id, 0, 1, e->val);
        n++;
    }
    while ((e = func_0016bba8(o->body, 11, e)) != 0) {
        func_0011c148(&buf[n], *(u32*)(o->body + 2224), e->id, 1, 1, e->val);
        n++;
    }
    func_0011c210(&buf[n]);
}

struct V185 { f32 x, y, z, w; };
void func_001980d0(u8*, u32, s32, V185*, f32);
void func_001a93b0(u8*, u32);
u8* func_00185920(u32, u32, s32);
u32 func_001708f8(u8*, s32);
void func_0017ebe8(u8*, u32);
void func_0017fd30(u8*, u8*);
u32 func_001762c0(u8*, u32);
void func_001c0d38(u8*, u8*, u32, s32);
extern u32 D_0034ed18[];

// Constructor: base init, owner link and initial effect attachment.
void func_00185468(u8* p, u32 a1, u8* owner, u32 a3, u32 t0, u32 t1) {
    V185 v;
    v.w = v.z = v.y = v.x = 0.0f;
    func_001980d0(p, a1, 12, &v, 3.1415927f);
    *(u32*)p = (u32)D_0034ed18;
    *(u32*)(p + 1416) |= 0x40;
    *(u32*)(p + 264) |= 2;
    *(u32*)(p + 944) = 1;
    *(u8**)(p + 2548) = owner;
    *(u32*)(p + 2552) = 0;
    *(u32*)(p + 2556) = t0;
    *(u32*)(p + 2560) = t1;
    func_001a93b0(p + 1952, t1);
    u8* r = func_00185920(a3, t0, 0);
    if (r) {
        func_0017ebe8(p + 320, func_001708f8(r, -1));
        func_0017fd30(owner + 320, p + 320);
        func_001c0d38(p, owner, func_001762c0(owner, t0), 0);
    }
    *(u32*)(p + 268) |= 0x700;
}

static inline u32 ActFlags18d(u8* a) {
    u32* f = (u32*)(a + 2748);
    return (f[0] | f[1]) & ~f[2];
}
s32 func_0018cae0(u8*);

u8* func_0018c8f0(u8*, u8*, u8*);
void func_00198580(u8*, s32);  // check_div1000_500
s32 func_001de2e0(u32*, u64);
void func_001877a0(u8*, u32*, s32);

// Applies a hit result and sets the matching reaction bit.
u8* func_0018da18(u8* o, u8* act, u8* info) {
    u8* r = func_0018c8f0(o, info, act);
    if (*(u8**)(o + 12)) *(u32*)(*(u8**)(o + 12) + 264) |= 0x2000000;
    *(u32*)(o + 4) |= 2;
    if (*(u32*)(r + 24) & 4) return r;
    if (ActFlags18d(act) & 0x2000) return r;
    if (*(s32*)(info + 28) >= 0) func_00198580(*(u8**)(o + 16), *(s32*)(info + 28));  // check_div1000_500
    u32* e = *(u32**)(o + 36);
    if (!e) return r;
    if (!*e) return r;
    u8 n = info[11];
    if (!n) return r;
    u64 bit = (u64)1 << 32 << (n - 1);
    s32 k = func_001de2e0(e, (*(u32*)(act + 1416) & 0x80) ? bit | 0x400 : bit | 0x800);
    if (k >= 0) func_001877a0(act, *(u32**)(o + 36), k);
    return r;
}

s32 func_00192440(u8*, s32);  // is_byte_lt25
u32 func_00192498(u8*, s32);  // read_u16_be
u8* func_00192388(u8*);  // skip_control_codes

// Walks the node list, forwarding type-5 nodes to the listener; stops at type 0 or 16.
void func_001aa558(u8* o) {
    u8* n = *(u8**)(o + 12);
    while (n) {
        if (func_00192440(n, 0)) {  // is_byte_lt25
            switch (*n) {
            case 0:
            case 16:
                n = 0;
                break;
            case 5:
                if (*(u8**)(o + 24)) {
                    u32 a = func_00192498(n, 1);  // read_u16_be
                    u32 b = func_00192498(n, 3);  // read_u16_be
                    u32 c = func_00192498(n, 5);  // read_u16_be
                    u8* t = *(u8**)(o + 24);
                    (*(void (**)(u8*, u32, u32, u32))(*(u8**)t + 28))(t, a, b, c);
                }
                break;
            }
        }
        if (!n) break;
        n = func_00192388(n);  // skip_control_codes
    }
}

s32 func_001b5858(u8*);
s32 func_001b5cb8(u8*);
u8* func_001b9bc8(u8*);
void func_0016cab8(u8*);
void func_0016c7d8(u8*);
void func_001de450(u8*);
void func_001c9770(void);
void func_001c9b90(void);
void func_001d1c70(u8*);
void func_001d1ed0(u8*);
void func_001b57f8(u8*);
void func_001b5588(u32);
extern u32 D_01d48cb0;

// Shutdown: releases owned resources and hands off to the next stage.
void func_001b5460(u8* o) {
    if (!func_001b5858(o) && !func_001b5cb8(o)) {
        u8* e = 0;
        while ((e = func_001b9bc8(e)) != 0) {
            if ((*(s32 (**)(u8*))(*(u8**)e + 60))(e) == 5000) (*(void (**)(u8*))(*(u8**)e + 40))(e);
        }
    }
    u8* t = *(u8**)(o + 52);
    if (t) {
        func_0016cab8(t);
        func_0016c7d8(t);
        *(u8**)(o + 52) = 0;
    }
    u8* h = o + 24;
    if (*(u32*)h) func_001de450(h);
    if (!func_001b5858(o)) {
        if (*(u32*)(o + 64) & 0x10) func_001c9770();
        else func_001c9b90();
    }
    func_001d1c70(o + 104);
    func_001d1ed0(o + 168);
    func_001b57f8(o);
    func_001b5588(D_01d48cb0);
}

void func_002f25a0(s32, s32);
extern u32 D_01d9e6b4;

static inline s32 PathBusy1e7(void) {
    u32 m = *(volatile u32*)0x10009000 & 0x100;
    s32 r = m != 0;
    if (*(volatile u32*)0x1000a000 & 0x100) r = 2;
    if (*(volatile u32*)0x10003c00 & 0x1f000003) r = 4;
    u32 v;
    asm volatile("cfc2.ni %0, $vi29" : "=r"(v));
    if (v & 0x100) r = 8;
    return r;
}

// Kicks a GIF PATH3 transfer of the given packet once all paths are idle (skips if already sent).
void func_001e72a8(u32 addr) {
    func_002f25a0(0, 0);
    if (D_01d9e6b4 != addr) {
        while (PathBusy1e7()) {}
        *(volatile u32*)0x10009020 = 0;
        *(volatile u32*)0x10009030 = addr;
        *(volatile u32*)0x1000e010 = 2;
        D_01d9e6b4 = addr;
        *(volatile u32*)0x10009000 = 325;
    } else {
        while (PathBusy1e7()) {}
    }
}

struct E1d4 { u8 kind; u8 pad[39]; u16 id; u8 pad2[22]; };
struct T1d4 { u32 f0; s32 n; E1d4 e[1]; };
extern T1d4* D_01d5ba28;
extern u32 D_00352738[4];
void func_001d3c18(E1d4*);

// Activates the first table entry matching the id (id 609 activates the four preset ids).
void func_001d4078(u32 id) {
    s32 i, j;
    if (id == 609) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < D_01d5ba28->n; j++) {
                E1d4* e = &D_01d5ba28->e[j];
                if (e->id == D_00352738[i]) {
                    func_001d3c18(e);
                    break;
                }
            }
        }
        return;
    }
    for (i = 0; i < D_01d5ba28->n; i++) {
        E1d4* e = &D_01d5ba28->e[i];
        if (e->id == id) {
            func_001d3c18(e);
            return;
        }
    }
}

struct Ent1d4 { u8 pad[2]; u16 id; u8 cnt; u8 kind; u8 pad2[6]; };
struct List1d4 { u8 pad[8]; s32 n; Ent1d4 e[1]; };
void func_001bc778(void*);
void func_001bc780(void*, u16, s32, s32);
s32 func_001d4420(void);
s32 func_001b58a8(void);
s32 func_001d3f80(E1d4*);
s32 func_001d4808(E1d4*);  // is_halfword42_zero
s32 func_001d3c78(E1d4*);
s32 func_001d3e40(E1d4*);

void wtarget_001d42d0(List1d4*, u32, u32, u32) asm("_Z16wtarget_001d42d0jjjj");
// Adds one list entry per active table group (first entry of each kind), marking non-special ones kind 5.
void wtarget_001d42d0(List1d4* L, u32, u32, u32) {
    u32 mask = 0;
    s32 x = func_001d4420();
    func_001bc778(L);
    if (func_001b58a8()) return;
    for (s32 i = 0; i < D_01d5ba28->n; i++) {
        E1d4* e = &D_01d5ba28->e[i];
        if (func_001d3f80(e)) continue;
        if (func_001d4808(e)) continue;
        if (!func_001d3c78(e)) continue;
        u32 b = 1 << e->kind;
        if (mask & b) continue;
        mask |= b;
        func_001bc780(L, e->id, 0, 1);
        if (x && func_001d3e40(e)) continue;
        *(s8*)&L->e[L->n - 1].kind = 5;
    }
}

struct M200 { f32 m[4][4]; } __attribute__((aligned(16)));
struct Cam200 { u8 pad[16]; M200 mat; };
union CamP200 { Cam200* p; f32 f; u32 u; };
extern CamP200 D_01d9e6e8;
extern u8 D_00354bd0[];
extern f32 D_00354bc0[4];
void func_001e8fe0(void*, void*);
void func_002f3e20(M200*, M200*);  // convert_vectors_to_scalar
void func_002f3d08(void*, void*, void*);
static inline void ScaleRow(f32* row, u32 k) {
    asm volatile("qmtc2 %1, $vf9\n\tlqc2 $vf10, 0(%0)\n\tvmulx.xyz $vf10, $vf10, $vf9x\n\tsqc2 $vf10, 0(%0)" : : "r"(row), "r"(k) : "memory");
}

// Builds the camera matrix from rotation/translation/scale channels.
void func_00200c50(u8* base, u8*, u8* c) {
    u32* offs = *(u32**)(c + 12);
    u8* rot = base + offs[1] + 160;
    u8* sc = base + offs[3] + 160;
    f32* pos = (f32*)(base + offs[0] + 160);
    u32* scale = (u32*)(base + offs[2] + 160);
    M200 m;
    func_001e8fe0(&D_01d9e6e8.p->mat, rot);
    D_01d9e6e8.p->mat.m[3][0] = pos[0];
    D_01d9e6e8.p->mat.m[3][1] = pos[1];
    D_01d9e6e8.p->mat.m[3][2] = pos[2];
    func_001e8fe0(&m, D_00354bd0);
    m.m[3][0] = D_00354bc0[0];
    m.m[3][1] = D_00354bc0[1];
    m.m[3][2] = D_00354bc0[2];
    func_002f3e20(&m, &m);  // convert_vectors_to_scalar
    func_002f3d08(&D_01d9e6e8.p->mat, &D_01d9e6e8.p->mat, sc);
    func_002f3d08(&D_01d9e6e8.p->mat, &m, &D_01d9e6e8.p->mat);
    ScaleRow(D_01d9e6e8.p->mat.m[0], scale[0]);
    ScaleRow(D_01d9e6e8.p->mat.m[1], scale[1]);
    ScaleRow(D_01d9e6e8.p->mat.m[2], scale[2]);
}

void func_00229430(u8*, s32);  // to_1391c8_arg11
u32 func_0022b9e0(void);
u32 func_0022b720(void);
void func_001386e0(u8*, s32, u32, u32, s32, s32);
void func_001396b0(u8*);
void func_0031a260(u8*, s32);
u32 func_00224910(void);  // get_global_36dac4

static inline void Settle228(u8* m) {
    func_001396b0(m);
    if (*(u32*)(m + 396)) {
        *(u32*)(m + 400) = 0;
        func_001396b0(m);
        if (*(u32*)(m + 400)) func_0031a260(m, 0);
    }
}

// Init: sets up the two model slots, links the second to the first and settles them.
void func_00228ab0(u8* o) {
    u8* m1 = o + 432;
    u8* m2 = o + 24;
    func_00229430(o, 2800);  // to_1391c8_arg11
    u32 a = func_0022b9e0();
    u32 b = func_0022b720();
    func_001386e0(m2, 2800, a, b, 28, 11);
    *(u32*)(m2 + 392) = 29;
    func_001386e0(m1, 2800, a, b, 23, 11);
    *(u8**)(m1 + 396) = m2;
    Settle228(m1);
    *(u32*)(m2 + 396) = 0;
    Settle228(m2);
    *(f32*)(o + 1248) = *(f32*)(o + 1252) = 0.0f;
    *(u32*)(o + 1256) = func_00224910();
}

struct O208 { u8 pad[16]; u8* items; u8* b; u8* c; s32 n; u16 f32; };
struct A208 { u8 pad[30]; u16 max; u16 delay; };
extern u32 D_01d9ea9c;
extern u8* D_01d9e6e0;
void func_00208298(O208*, A208*, u8*, u32, u8*);
void func_00207350(O208*, A208*, u32, u8*, u8*, u8*);

// Updates spawn slots: live ones tick, free ones spawn after the delay (up to max per call).
void func_002086e0(O208* o, A208* a, u32 arg) {
    s32 cnt = 0;
    u8* it = o->items;
    u8* b = o->b;
    u8* c = o->c;
    s32 n = o->n;
    if (D_01d9ea9c) return;
    if (*(u64*)(D_01d9e6e0 + 168) & 0xff0000ff00ULL) return;
    o->f32++;
    for (s32 i = 0; i < n; i++) {
        if (*(u16*)(it + 64)) {
            func_00208298(o, a, it, arg, c);
        } else if (a->delay <= o->f32 && cnt < a->max) {
            func_00207350(o, a, arg, it, b, c);
            cnt++;
        }
        if (b) b += 64;
        if (c) c += 32;
        it += 176;
    }
    if (cnt > 0) o->f32 = 0;
}

extern u8* D_0035f200;
extern u8* D_0035f204;
extern u8* D_0035f208;
extern u8* D_0035f218;
s32 func_0028acc8(u8*);
s32 func_0028acb8(u8*);
u8* func_002891b8(u8*, s32);
void func_0028aa40(u8*);
s32 func_00139d78(u8*);
void func_00276300(void);
void func_0028f7a0(void);
void func_0028d5d0(u8*);
void func_00276dc0(void);
void func_002945a0(void);
void func_00295860(void);
void func_00297008(void);
void func_00297df8(void);
void func_002995a0(void);
void func_0029aa30(void);
void func_0029ee30(void);
void func_002a0780(void);
void func_002a2148(void);
void func_002a4df0(void);
void func_002a6a10(void);
void func_002a7758(void);
void func_002a8a80(void);
void func_002aece8(void);
void func_00275c78(void);

static inline bool Busy274(u8* m) { return *(u32*)(m + 400) || *(u32*)(m + 396); }

// Per-frame update of the menu subsystems.
void func_002748a0(void) {
    if (func_0028acc8(D_0035f200) && !func_0028acb8(D_0035f200)) {
        if (!Busy274(func_002891b8(D_0035f200, 0))) func_0028aa40(D_0035f200);
    }
    if (func_00139d78(D_0035f204)) func_00276300();
    if (func_00139d78(D_0035f208)) (*(void (**)(u8*))(*(u8**)D_0035f208 + 20))(D_0035f208);
    func_0028f7a0();
    func_0028d5d0(D_0035f218);
    func_00276dc0();
    func_002945a0();
    func_00295860();
    func_00297008();
    func_00297df8();
    func_002995a0();
    func_0029aa30();
    func_0029ee30();
    func_002a0780();
    func_002a2148();
    func_002a4df0();
    func_002a6a10();
    func_002a7758();
    func_002a8a80();
    func_002aece8();
    func_00276dc0();
    func_00275c78();
}

extern u32 D_0035f3d4;
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern u32 D_0035f03c;
u8* func_00257770(u32);
s32 func_00287bc0(void);
s32 func_0028d008(u32);
u8* func_0028d0e0(u32);
void func_0028d8c0(u8*, u32, u32, u32, u32, s32, s32, s32);
void func_0028dcc0(u8*, u32);

// Shows or hides the help window for an entry.
void func_002633a8(u32 id, u8 show) {
    u8* base = func_00257770(id);
    s32 k = func_00287bc0();
    u8* m = k == 11 ? base + 816 : base + 1224;
    if (k == 13) id = 1;
    s32 busy = func_00139d78(m);
    if (func_0028d008(id)) {
        if (!busy) {
            func_0028d8c0(m, D_0035f3d4 + 2, D_0035ef68, D_0035ef64, D_0035f03c, 290, -1, 0);
            func_0028dcc0(m, *(u32*)(func_0028d0e0(id) + 396));
        }
        if (show) func_0028dcc0(m, *(u32*)(func_0028d0e0(id) + 396));
    } else if (busy) {
        (*(void (**)(u8*))(*(u8**)m + 20))(m);
    }
}

struct E248 { u8 pad[8]; u8 name[8]; s8 on; u8 pad2; u16 id; u8 pad3[16]; };
extern E248 D_00371e00[];
extern u8* D_0035ed50;
extern u32 D_0035ed54;
extern u32 D_0035ed60;
void func_00288d80(u8*, s32, s32, s32, u32, u16, E248*, u8*);
u32 func_0023aa78(u8*);
u32 func_0023aa98(u8*);
void func_00288e08(u8*, s32, u32, s32);
u32 func_0028dd90(u32);  // mod10_classify_012
u32 func_0028ddd8(u32);
void func_001395f8(u8*);
void func_002891f0(u8*, s32, s32, s32, s32);
void func_002b4388(u32, E248*, s32);

// Builds the two-entry selection list and focuses the active entry.
void func_002485c8(void) {
    s32 sel = 0;
    for (s32 i = 0; i < 2; i++) {
        if (D_00371e00[i].on) sel = i;
        func_00288d80(D_0035ed50, i, 0, 0, D_0035ed54, D_00371e00[i].id, &D_00371e00[i], D_00371e00[i].name);
        u8* w = func_002891b8(D_0035ed50, i);
        func_00288e08(D_0035ed50, i, func_0023aa78(w + 24), 0);
        u32 x = func_0023aa98(w + 24);
        *(u32*)(w + 432) = func_0028dd90(x);
        *(u32*)(w + 428) = func_0028ddd8(x);
        func_001395f8(w);
    }
    func_002891f0(D_0035ed50, sel, 1, 0, 2);
    func_002b4388(D_0035ed60, &D_00371e00[sel], 0);
}

extern u32* D_0035f2e4;
u32* func_002859a0(void);
u8* func_001a80c8(s32);  // table24_find_by_id
s32 func_00285d18(u8);
static inline u32 Bit285(u32* a, s32 i) { return a[(u32)i >> 5] & (1 << (i & 31)); }
// True when the id (or, for id < 0, every enabled id that qualifies) is also set in the obtained mask.
s32 func_00285e30(s32 id) {
    s32 ok = 1;
    u32* got = func_002859a0();
    if (id >= 0) {
        ok = Bit285(D_0035f2e4, id) && Bit285(got, id);
    } else {
        for (s32 i = 0; i < 640; i++) {
            if (!Bit285(D_0035f2e4, i)) continue;
            if (!func_00285d18(func_001a80c8(i)[2])) continue;
            ok = Bit285(got, i) != 0;
            if (!ok) break;
        }
    }
    return ok;
}

struct W280 { void** vt; u8 pad[432]; };
extern u8* D_0035f250;
extern u8* D_0035f258;
extern u8* D_0035f254;
extern W280* D_0035f25c;
s32 func_00287db0(void);
void func_0028abe0(u8*);
s32 func_00289310(u8*);
s32 func_002891e8(u8*);
void func_002890e0(u8*, s32, s32, s32, s32);
void func_00289038(u8*, s32, s32, s32, s32, s32, s32);


// Closes the open sub-windows and resets the list cursor.
void func_00280d40(void) {
    if (func_00287db0()) {
        if (func_00139d78(D_0035f250)) (*(void (**)(u8*))(*(u8**)D_0035f250 + 20))(D_0035f250);
        if (func_00139d78(D_0035f258)) (*(void (**)(u8*))(*(u8**)D_0035f258 + 20))(D_0035f258);
        if (func_0028acc8(D_0035f254)) func_0028abe0(D_0035f254);
        for (s32 i = 0; i < 3; i++) {
            if (func_00139d78((u8*)&D_0035f25c[i])) (*(void (**)(W280*))((u8*)D_0035f25c[i].vt + 20))(&D_0035f25c[i]);
        }
    }
    if (func_00289310(D_0035f254)) {
        s32 s = func_002891e8(D_0035f254);
        func_002890e0(D_0035f254, 1, 2, 0, -1);
        func_00289038(D_0035f254, s, 1, 1, 2, 0, -1);
    }
}

extern u8* D_0035f21c;
extern u8* D_0035f20c;
extern u32 D_0035f148;
extern u32 D_0035f14c;
extern u32 D_0035f210;
s32 func_00276df8(void);
void func_0028d980(u8*, s32, u32, u32, u32, s32, s32, s32, s32);
void func_00138c10(u8*, s32);
u32 func_0023aa18(u8*);
u32 func_0023aa38(u8*);
void func_00138c68(u8*, u32, u32);

// Opens (or retargets) the info window for id; optionally fills it from the current entry.
void func_00276c88(u32 id, u8 flag) {
    u8* w = D_0035f21c + 3812;
    if (!func_00276df8()) {
        func_0028d980(w, 30045, D_0035f14c, D_0035f148, D_0035f210, 145, -1, -1, 0);
        if (func_00139d78(D_0035f20c + 1308)) func_0028dcc0(w, (u32)(D_0035f20c + 1308));
        *(u32*)(w + 408) = id;
        func_001395f8(w);
        if (flag) {
            func_00139d78(D_0035f20c + 1308);
            u32 x = func_0023aa18(D_0035f20c + 1332);
            func_00138c68(w, x, func_0023aa38(D_0035f20c + 1332));
        }
    } else {
        *(u32*)(w + 408) = id;
        if (*(s32*)(w + 388) != 145) {
            func_00138c10(w, 145);
            *(s32*)(w + 392) = -1;
        }
    }
}

extern u16 D_00374cb0[][2];
extern u32 D_00374c9c;
extern u32 D_00374ca0;
u8* func_002766d0(void);
s32 func_002892f8(u8*);
u32 func_00192048(u16);
s32 func_002ac420(s32);
s32 func_002ac748(s32);
s32 func_002ac538(s32);
s32 func_002ac800(s32);

// Resets the item rows, then refreshes the three category rows and their availability marks.
void func_002b1708(void) {
    u8* base = func_002766d0();
    s32 n = func_002892f8(D_0035f200);
    s32 i;
    for (i = 0; i < n; i++) func_00138c10(base + 0xa998 + i * 408, 2);
    u8* w = base + 0xa998;
    for (i = 0; i < 3; w += 408, i++) {
        u8* it = func_002891b8(D_0035f200, i);
        *(u32*)(it + 408) = func_00192048(D_00374cb0[i][0]);
        if (i == 2) continue;
        s32 a, b;
        if (i == 0) a = func_002ac420(-1);
        else a = func_002ac748(-1);
        if (i == 0) b = func_002ac538(-1);
        else b = func_002ac800(-1);
        if (a) func_00138c10(w, b == 0 ? D_00374c9c : D_00374ca0);
    }
}

u8* func_001050d8(u32);
void func_002bf468(u8*, u8*, u32, f32);
void func_002c1aa0(u8*, u8*, u32, f32);
void func_002c54c8(u8*, u8*, u32, f32);
u8* func_002c5ed8(u8*, u32, f32);

// Creates the object for the given type (type 2 is built by its own factory).
u8* func_002be800(u8* d, u32 a, f32 f) {
    switch (d[5]) {
    case 0:
        {
            u8* p = func_001050d8(2832);
            func_002bf468(p, d, a, f);
            return p;
        }
    case 1:
        {
            u8* p = func_001050d8(2800);
            func_002c1aa0(p, d, a, f);
            return p;
        }
    case 2:
        return func_002c5ed8(d, a, f);
    case 3:
        {
            u8* p = func_001050d8(2560);
            func_002c54c8(p, d, a, f);
            return p;
        }
    }
    return 0;
}

extern E248** D_0035f6cc;
extern u8* D_0035f64c;
extern u32 D_0035f644;
extern u32 D_0035f640;
extern u32 D_0035f664;
void func_00139620(u8*);
s32 func_00240ba0(void);
void func_00287cc0(s32);

// Builds the two-entry list from the current table and focuses the default entry.
void func_002b4b00(void) {
    for (s32 i = 0; i < 2; i++) {
        func_00288d80(D_0035f64c, i, D_0035f644, D_0035f640, D_0035f664, (*D_0035f6cc)[i].id, &(*D_0035f6cc)[i], (*D_0035f6cc)[i].name);
        func_00288e08(D_0035f64c, i, 0, -1);
        func_00139620(func_002891b8(D_0035f64c, i));
        func_001395f8(func_002891b8(D_0035f64c, i));
    }
    func_002891f0(D_0035f64c, func_00240ba0(), 1, 0, 2);
    func_00287cc0(0);
}

}
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) QW2cd;
static inline void VSub2cd(QW2cd* d, const QW2cd* a, const QW2cd* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
static inline f32 VLen2cd(const QW2cd* v) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0" : "=f"(r) : "r"(v) : "$8", "memory");
    return r;
}
static inline void VScale2cd(QW2cd* d, const QW2cd* s, f32 k) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(s), "f"(k) : "$8", "memory");
}
static inline void VAdd2cd(QW2cd* d, const QW2cd* a, const QW2cd* b) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "r"(b) : "memory");
}
struct O2cd { u8 pad[4]; u32 f4; u32 f8; u8 pad2[12]; u32 f24; f32 f28; u8 pad3[4]; f32 range; u8 pad4[95]; u8 on; u8* target; };
extern "C" {
QW2cd* func_0016c028(u8*);  // obj_get_attach_or_alt
void func_002cd3e0(O2cd*, u8*);
void func_002cd428(O2cd*, QW2cd*);

// Retargets the leash: places the midpoint 110 units short of the new target when it is out of range.
void func_002cd290(O2cd* o, u8* from, u8* to) {
    if (!o->on) return;
    if (o->target == to) return;
    if (!to) {
        to = o->target;
        if (!to) return;
    }
    o->target = to;
    o->f4 = 0;
    o->f8 = 0;
    o->f28 = -2.0f;
    o->f24 = 0;
    QW2cd* a = func_0016c028(from);  // obj_get_attach_or_alt
    QW2cd* b = func_0016c028(to);  // obj_get_attach_or_alt
    QW2cd d, p, e;
    VSub2cd(&d, b, a);
    f32 len = VLen2cd(&d);
    if (o->range + o->range < len) {
        VScale2cd(&e, &d, (len - 110.0f) / len);
        VAdd2cd(&p, &e, a);
        func_002cd3e0(o, from);
        func_002cd428(o, &p);
        func_002cd3e0(o, to);
    }
}

}
