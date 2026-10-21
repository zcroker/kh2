#include "../common/types.h"
extern "C" {
extern s32 D_0035f250;
extern s32 D_0035f254;
extern s32 D_0035f258;
extern u16 D_00374120[2][3];
extern u16 D_00374148[];
extern u16 D_00374150[];
void func_0028d7f0(s32, s32, s32, s32, s32, s32, s32, s32, s32);
void func_0023ef50(s32);
void func_0028d8c0(s32, s32, s32, s32, s32, s32, s32, s32);
s32 func_00103550(void);
void func_00288d80(s32, s32, s32, s32, s32, s32, s16*, s16*);
u8* func_002891b8(s32, s32);
void func_00139620(u8*);
void func_0028af28(s32, s32);
void func_002891f0(s32, s32, s32, s32, s32);

static inline void setf8(u8* p) { *(u32*)(p + 184) |= 8; }
static inline void set432(u8* p, s32 v) { *(s32*)(p + 432) = v; }
void func_00280a50(void) {
    s16 arr[2][4];
    s32 i, j, k;
    func_0028d7f0(D_0035f250, 30002, 0, 0, 0, -1, 0, 0, 0);
    func_0023ef50(D_0035f250);
    func_0028d8c0(D_0035f258, 30003, 1, 0, D_0035f250, 0, -1, 0);
    setf8((u8*)D_0035f258 + 24);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++)
            for (k = 0; k < 4; k++) arr[j][k] = D_00374120[j][i];
        u16* t = D_00374148;
        if (func_00103550() == 53) t = D_00374150;
        func_00288d80(D_0035f254, i, 1, 0, D_0035f250, t[i], arr[0], arr[1]);
        func_00139620(func_002891b8(D_0035f254, i));
        set432(func_002891b8(D_0035f254, i), 2);
    }
    func_0028af28(D_0035f254, 32);
    func_0028af28(D_0035f254, 64);
    func_002891f0(D_0035f254, 0, 1, 0, -1);
}

}

namespace n002a2de8 {
struct Ent { u8 a; u8 b; u16 v; u8 c4; };
struct Bits {
    u32 w[2];
    s32 Test(u32 b) { return w[b >> 5] & (1 << (b & 31)); }
    void Set(u32 b) { u32* p = &w[b >> 5]; *p |= 1 << (b & 31); }
};
struct Rec { u8 id; s8 f; u8 c2; u8 c3; s16 n; u16 v; };
struct Tbl { Rec r[512]; Rec s[15]; s32 count; s32 cnt2; u8 pad[12]; Bits bits[10]; };
extern "C" {
union TU { Tbl* p; s16 h; u8 c; };
extern TU D_0035f5e4;
s32 func_00276c18(void);
void func_002fde18(void*, s32, s32);
Ent* func_001d9e30(Ent*);
s32 func_001d9d88(Ent*);
s32 func_002a43d0(Ent*);
u8 func_002764b0(u8);
void func_002a2ff8(void);
s32 func_002ac748(s32);
s32 func_002ac800(s32);
void func_002a2de8(void) {
    Ent* e; s32 n; s32 cnt; s32 cnt2; s32 flag; s32 i;
    flag = func_00276c18();
    func_002fde18(D_0035f5e4.p, 0, 4316);
    e = 0;
    n = 0;
    cnt = 0;
    cnt2 = 0;
top:
    e = func_001d9e30(e);
    if (!e) goto out;
    if (func_001d9d88(e) || flag) {
        if (!D_0035f5e4.p->bits[e->a].Test(e->b)) {
            s32 r = func_002a43d0(e);
            u8 id = func_002764b0(e->c4);
            if (r) cnt2++;
            D_0035f5e4.p->r[cnt].id = id;
            D_0035f5e4.p->r[cnt].n = n;
            D_0035f5e4.p->r[cnt].v = e->v;
            D_0035f5e4.p->r[cnt].f = r != 0;
            cnt++;
            D_0035f5e4.p->bits[e->a].Set(e->b);
        }
    }
    n++;
    goto top;
out:
    D_0035f5e4.p->count = cnt;
    D_0035f5e4.p->cnt2 = cnt2;
    func_002a2ff8();
    for (i = 0; i < 15; i++) {
        if (!D_0035f5e4.p->r[i + 512].id) {
            D_0035f5e4.p->r[i + 512].c2 = 0;
            D_0035f5e4.p->r[i + 512].c3 = 0;
        } else {
            D_0035f5e4.p->r[i + 512].c2 = func_002ac748(i) != 0;
            D_0035f5e4.p->r[i + 512].c3 = func_002ac800(i) != 0;
        }
    }
}
}
}

#define QCOPY_w(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCOPY4_w(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QV_w {
    f32 x, y, z, w;
    QV_w() {}
    QV_w(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    QV_w(const QV_w& o) { QCOPY_w(this, &o); }
    QV_w& operator=(const QV_w& o) { if (this != &o) QCOPY_w(this, &o); return *this; }
    QV_w& operator+=(const QV_w& o) {
        asm volatile("lqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvadd.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(this), "r"(&o) : "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct QV2_w : QV_w { QV2_w(f32 a, f32 b, f32 c, f32 d) : QV_w() { w = d; z = c; y = b; x = a; } };
struct QM_w {
    QV_w r[4];
    QM_w() {}
    QM_w& operator=(const QM_w& o) { if (this != &o) QCOPY4_w(this, &o); return *this; }
    QV_w operator*(const QV_w& v) const {
        QV_w o;
        asm volatile("lqc2 $vf5, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\tvmulax.wxyz ACC, $vf1, $vf5x\n\tvmadday.wxyz ACC, $vf2, $vf5y\n\tvmaddaz.wxyz ACC, $vf3, $vf5z\n\tvmaddw.wxyz $vf5, $vf4, $vf5w\n\tsqc2 $vf5, 0(%0)" : : "r"(&o), "r"(this), "r"(&v) : "memory");
        return o;
    }
    void invOrtho() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
struct Cam_w { u8 pad[0xb70]; QM_w m; QM_w inv; };
extern "C" {
void func_00178758(Cam_w*);
void func_0011b6a8(QM_w*);
void FMatrix_rotateY_w(QM_w*, f32) asm("_ZN2kn7FMatrix7rotateYEf");
void FMatrix_rotateXYZ_w(QM_w*, const QV_w*) asm("_ZN2kn7FMatrix9rotateXYZERKNS_7FVectorE");
f32 ObjCamera_getObjBackDirection_w(Cam_w*) asm("_ZN2dk9ObjCamera19getObjBackDirectionEv");
const QV_w* OBJ_get_xyzrot_w(Cam_w*) asm("_ZN2YS3OBJ10get_xyzrotEv");
s32 OBJ_is_xyzrot_w(Cam_w*) asm("_ZN2YS3OBJ9is_xyzrotEv");
const QV_w* func_0016c028(Cam_w*);
void func_002d10a0(Cam_w* o)
{
    func_00178758(o);
    QM_w* m = &o->m;
    func_0011b6a8(m);
    if (OBJ_is_xyzrot_w(o)) FMatrix_rotateXYZ_w(m, OBJ_get_xyzrot_w(o));
    else FMatrix_rotateY_w(m, ObjCamera_getObjBackDirection_w(o));
    o->m.r[3] = *func_0016c028(o);
    { QV_w t = *m * QV_w(0.0f, -80.0f, 0.0f, 0.0f); o->m.r[3] += t; }
    o->m.r[3].w = 1.0f;
    o->inv = *m;
    o->inv.invOrtho();
}
}
