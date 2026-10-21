#include "../common/types.h"

struct W2024a_Hdr { u8 pad[0x10]; s32 off10; s32 off14; s32 off18; };
struct W2024a_Ent { u8 pad[0x24]; s32 idx; u8 pad2[0x18]; };
struct W2024a_Obj { s32 f0; u8* ents; };
struct W2024a_Bb { u8 pad[0x20]; u64 bitblt; };
struct W2024a_Tx { u8 pad[0x70]; u64 tex0; };
extern s32 D_003a99f0[];
struct W2024b_Vec {
    f32 x, y, z, w;
    W2024b_Vec() {}
    W2024b_Vec(const W2024b_Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
    W2024b_Vec& operator=(const W2024b_Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct W2024b_Mtx { W2024b_Vec m[4]; };
struct W2024b_Obj;
struct W2024b_Cam;
static inline void W2024b_vouter(W2024b_Vec& d, const W2024b_Vec& a, const W2024b_Vec& b, W2024b_Vec* r) {
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf3, $vf0, $vf0\n\tvopmula.xyz ACC, $vf1, $vf2\n\tvopmsub.xyz $vf3, $vf2, $vf1\n\tsqc2 $vf3, 0(%0)\n\t.set reorder"
        : : "r"(r), "r"(&a), "r"(&b) : "memory");
    d = *r;
}
static inline f32 W2024b_vnorm(W2024b_Vec& v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(&v) : "$8", "memory");
    return len;
}
s32 W2024b_mg_be_ready(void*) asm("_ZN2Ti8MiniGame8be_readyEv");
s32 W2024b_cam_matrix(W2024b_Cam*) asm("_ZN2Ti11MG_ALEscape13camera_matrixEv");
void W2024b_obj_set_pos(W2024b_Obj*, const W2024b_Vec*) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
void W2024b_obj_set_pos_trans(W2024b_Obj*, const W2024b_Vec*) asm("_ZN2YS3OBJ13set_pos_transERKN2kn7FVectorE");
void W2024b_obj_set_rot(W2024b_Obj*, const W2024b_Vec*) asm("_Z16wtarget_0016b070jjjj");
extern W2024b_Cam* D_00361f60;
extern void* D_0034e948;
extern "C" {
void func_00109788(void*, void*);
void func_00109708(void*);
s32 func_00132018(W2024a_Hdr*);
s32 func_00132f98(void*, s32, s32*, s32, s32);
s32 func_00132d90(s32, s32);
s32 func_00132c98(s32);
s32 func_00132cd0(s32);
s32 func_00132d00(s32);
s32 func_00132d30(s32);
s32 func_00132d60(s32);
void func_001097e8(s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_00133c60(void*, void*, s32, s32, s32);
void func_001094e0(void*, s32);
void func_001217a0(W2024a_Obj* o, void* ctx, s32 n, void* a3, W2024a_Hdr* h) {
    W2024a_Ent* e = (W2024a_Ent*)(n * 32 + (u32)o->ents);
    s32 k = e->idx;
    u8* base = (u8*)h;
    W2024a_Bb* bb;
    W2024a_Tx* tx;
    s32 cnt;
    s32* p;
    tx = (W2024a_Tx*)((u32)h + (h->off18 + k * 0xa0));
    s32 x = (base + h->off10)[k] * 0x90;
    x += 0x90;
    bb = (W2024a_Bb*)((u32)h + (h->off14 + x));
    func_00109788(ctx, base + h->off14);
    func_00109708(ctx);
    func_00109788(ctx, bb);
    cnt = func_00132f98(a3, e->idx, D_003a99f0, 0x3c00, func_00132018(h));
    if (cnt > 0) {
        p = D_003a99f0;
        s32 c = cnt;
        do {
            s32 s = *p++;
            if (func_00132d90(s, 0) != 0) {
                s32 r0 = func_00132c98(s);
                s32 r1 = func_00132cd0(s);
                s32 r2 = func_00132d00(s);
                s32 r3 = func_00132d30(s);
                s32 r4 = func_00132d60(s);
                s32 r5 = func_00132d90(s, 0);
                func_001097e8(r0, (s32)((bb->bitblt & 0x3fffULL << 32) >> 32), (s32)((tx->tex0 & 0xfc000ULL) >> 14), r1, r2, r3, r4, (s32)((tx->tex0 & 0x3f00000ULL) >> 20), r5);
                func_00133c60(ctx, (void*)r0, 0, 0, 0);
                func_001094e0(bb, r0);
            }
        } while (--c != 0);
    }
    func_00133c60(ctx, tx, 0, 0, 0);
}

W2024b_Vec* func_0016c028(void*);
void func_002e10d0(W2024b_Mtx*, W2024b_Cam*);
void func_002e1140(W2024b_Mtx*, W2024b_Cam*);
void func_0011b6a8(void*);
void func_002d08b8(W2024b_Vec*, const W2024b_Mtx*);
void func_002e1d28(void* self, W2024b_Obj* o) {
    W2024b_Cam* c = D_00361f60;
    W2024b_Mtx a, b, m;
    W2024b_Vec q;
    W2024b_Vec q2;
    W2024b_Mtx b2;
    if (!W2024b_mg_be_ready(self)) return;
    if (W2024b_cam_matrix(c)) {
        W2024b_obj_set_pos_trans(o, func_0016c028(D_0034e948));
        func_002e10d0(&a, c);
        func_002e1140(&b, c);
        func_0011b6a8(&m);
        m.m[1] = a.m[1];
        W2024b_vouter(m.m[0], m.m[1], b.m[2], &q);
        W2024b_vouter(m.m[2], m.m[0], m.m[1], &q);
        W2024b_vnorm(m.m[0]);
        W2024b_vnorm(m.m[1]);
        W2024b_vnorm(m.m[2]);
        m.m[0].w = 0.0f;
        m.m[1].w = 0.0f;
        m.m[2].w = 0.0f;
        func_002d08b8(&q, &m);
        W2024b_obj_set_rot(o, &q);
    } else {
        func_002e1140(&b2, c);
        func_002d08b8(&q2, &b2);
        W2024b_obj_set_rot(o, &q2);
        W2024b_obj_set_pos(o, &b2.m[3]);
    }
}
}
