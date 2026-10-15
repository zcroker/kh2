#include "../common/types.h"
// VU0 vector/matrix helpers (inline asm: the original uses the VU0 macro library).
#define QCOPY1337(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define QCOPY4_1337(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct QV1337 {
    f32 x, y, z, w;
    QV1337() {}
    QV1337(const QV1337& o) { QCOPY1337(this, &o); }
    QV1337& operator=(const QV1337& o) { if (this != &o) QCOPY1337(this, &o); return *this; }
} __attribute__((aligned(16)));
struct QM1337 {
    QV1337 r[4];
    QM1337() {}
    QM1337(const QM1337& o) { QCOPY4_1337(this, &o); }
    QV1337 operator*(const QV1337& v) const {
        QV1337 o;
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
struct Seg1337 {
    QV1337 p0, p1;
    void set(const QV1337& a, const QV1337& b) { p0 = a; p1 = b; p1.w = 1.0f; p0.w = 1.0f; }
};
struct Hit1337 { u8 pad[16]; };
struct CollInfo1337 { u8 pad[0x12]; u8 enable : 1; u8 : 7; u8 pad13[0x15]; u8 height28; };
struct Obj1337 {
    u32 pad0;
    union { struct { u32 b0 : 1, b1 : 1, b2 : 1, b3 : 1, b4 : 1, b5 : 3, b8 : 1, : 23; }; u32 flags; };
    u8 pad8[0x20];
    CollInfo1337* coll;
    bool isB3() { if (flags & 8) return true; return false; }
    bool isB4() { if (flags & 0x10) return true; return false; }
    bool isB1() { if (flags & 2) return true; return false; }
    bool isBusy() { return isB3() || isB4(); }
};
extern "C" {


struct BoxVec1337 {
    f32 x, y, z, w;
    };
struct Box1337 { f32 v[6]; };
struct ObjData1337 { s32 w[6]; };
struct Model1337 { void** vtbl; };
static inline void BoxVecSet1337(BoxVec1337* v, f32 x, f32 y, f32 z, f32 w) { v->x = x; v->y = y; v->z = z; v->w = w; }
typedef void (*GetBoundsFn1337)(Model1337*, BoxVec1337*, BoxVec1337*);

s32 JmInfo_GetCharaData(u32) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
s32 func_0016f6f8(s32);
void func_001a91f8(ObjData1337*);
void func_001a92d8(ObjData1337*, s32, s32);
Model1337* ObjData_get_knm(ObjData1337*) asm("_ZN2YS7OBJDATA7get_knmEv");
void ObjData_free(ObjData1337*) asm("_ZN2YS7OBJDATA4freeEv");
void Aabbox_ctor(Box1337*, const BoxVec1337*, const BoxVec1337*) asm("_ZN2dk6AabboxC1ERKN2kn7FVectorES4_");

Box1337* func_002d0718(Box1337* out, s32* chara) {
    union {
        struct { ObjData1337 obj; s32 pad[2]; BoxVec1337 mn; BoxVec1337 mx; Box1337 box; } m;
        struct { BoxVec1337 mn; BoxVec1337 mx; Box1337 box; } d;
    } u;
    s32 data = JmInfo_GetCharaData(*chara);
    if (func_0016f6f8(*chara) != 0) {
        s32 id = *chara;
        Model1337* m;
        func_001a91f8(&u.m.obj);
        func_001a92d8(&u.m.obj, id, data);
        m = ObjData_get_knm(&u.m.obj);
        ((GetBoundsFn1337)m->vtbl[4])(m, &u.m.mn, &u.m.mx);
        u.m.mn.y = -u.m.mn.y;
        u.m.mn.z = -u.m.mn.z;
        u.m.mx.y = -u.m.mx.y;
        u.m.mx.z = -u.m.mx.z;
        Aabbox_ctor(&u.m.box, &u.m.mn, &u.m.mx);
        *out = u.m.box;
        ObjData_free(&u.m.obj);
    } else {
        BoxVecSet1337(&u.d.mn, -100.0f, -100.0f, -100.0f, 0.0f);
        BoxVecSet1337(&u.d.mx, 100.0f, 100.0f, 100.0f, 0.0f);
        Aabbox_ctor(&u.d.box, &u.d.mn, &u.d.mx);
        *out = u.d.box;
    }
    return out;
}


extern u8* D_00361f60;
void BtlObj_pre_exec(void*) asm("_ZN2YS6BTLOBJ13_OVR_pre_execEv");
s32 Obj_is_attach(void*) asm("_ZN2YS3OBJ9is_attachEv");
void Obj_set_pos(void*, const QV1337*) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
QV1337* func_0016c028(void*);
QM1337* func_002d1f10(u8*);
QM1337* func_002d1f00(u8*);
void func_0016b010(void*, QV1337*);

void func_002d5f48(u8* self) {
    u8* other;
    BtlObj_pre_exec(self);
    other = D_00361f60;
    if (other == 0) return;
    if (Obj_is_attach(self) == 0) {
        QV1337 pos(*func_0016c028(self));
        QM1337 m(*func_002d1f10(other));
        m.invOrtho();
        pos.w = 1.0f;
        QV1337 local = m * pos;
        local.z = 0.0f;
        QV1337 world = *func_002d1f00(other) * local;
        world.z = 0.0f;
        Obj_set_pos(self, &world);
        QV1337 v(*(QV1337*)(self + 0xb20));
        func_0016b010(self, &v);
    } else {
        *(u32*)(self + 0x108) |= 2;
    }
}


s32 func_00143b88(Seg1337*, Hit1337*, u16*, s32*, s32);
void func_0018ddc0(Obj1337*, u16, Hit1337*, s32*);

s32 func_0018dc28(Obj1337* self, const QV1337* from, const QV1337* to) {
    Seg1337 seg;
    u16 id;
    Hit1337 hit;
    s32 res;
    seg.set(*from, *to);
    res = 0;
    asm volatile("" ::: "memory");
    if (self->coll->enable && !self->isBusy() && (self->b8 || !self->isB1())) {
        if (func_00143b88(&seg, &hit, &id, &res, 4) != 0) {
            goto found;
        }
        if (self->coll->height28 != 0) {
            seg.p0 = *to;
            seg.p1 = *to;
            seg.p1.y += (f32)self->coll->height28;
            seg.p1.w = 1.0f;
            seg.p0.w = 1.0f;
            if (func_00143b88(&seg, &hit, &id, &res, 4) != 0) {
            found:
                func_0018ddc0(self, id, &hit, &res);
                return 1;
            }
        }
    }
    return 0;
}

}
