#include "../common/types.h"
struct Rect14b { u8 pad0[4]; u16 w; u16 h; s16 x; s16 y; u8 pad1[4]; u8 r, g, b, a; u8 pad2[12]; u64 pk[26]; };
#define RGBAQ(r, g, b, a, q) ((u64)(r) | ((u64)(g) << 8) | ((u64)(b) << 16) | ((u64)(a) << 24) | ((u64)(q) << 32))
#define XYZ(x, y, z) ((u64)(x) | ((u64)(y) << 16) | ((u64)(z) << 32))
extern "C" {
void func_0014b300(Rect14b* p) {
    p->pk[0] = 0x8000000000000001ULL;
    p->pk[1] = 0xEEEEEEEEULL;
    p->pk[2] = 0;
    p->pk[3] = 0x3f;
    p->pk[4] = 0x800d8;
    p->pk[5] = 0x4c;
    p->pk[6] = 0x31000070;
    p->pk[7] = 0x4e;
    p->pk[8] = 0;
    p->pk[9] = 6;
    p->pk[10] = 0x60;
    p->pk[11] = 0x14;
    p->pk[12] = 0x30000;
    p->pk[13] = 0x47;
    p->pk[14] = 0x44;
    p->pk[15] = 0x42;
    p->pk[16] = 5;
    p->pk[17] = 8;
    p->pk[18] = 0x6400000000008001ULL;
    p->pk[19] = 0x535310;
    p->pk[20] = 0x146;
    p->pk[21] = RGBAQ(p->r, p->g, p->b, p->a, 1);
    p->pk[22] = 0x80008;
    p->pk[23] = XYZ(p->x * 16 + 0x7000, p->y * 16 + 0x7300, 1);
    p->pk[24] = 0x80008;
    p->pk[25] = XYZ((p->x + p->w) * 16 + 0x7000, (p->y + p->h) * 16 + 0x7300, 1);
}
}

#define QCOPY186(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV186 {
    f32 x, y, z, w;
    QV186() {}
    QV186(const QV186& o) { QCOPY186(this, &o); }
    QV186& operator=(const QV186& o) { if (this != &o) QCOPY186(this, &o); return *this; }
    QV186 operator-(const QV186& b) const {
        QV186 o;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
    f32 normalize() {
        f32 len;
        asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)" : "=f"(len) : "r"(this) : "$8", "memory");
        return len;
    }
} __attribute__((aligned(16)));
struct Info186 { u32 pad0; s32 kind; };
struct Obj186 { u8 pad0[0xc]; Info186* info; u8 pad10[0x508]; u8 sub518[4]; };
struct Msg186 { QV186 dir; u8 pad10[8]; u32 flags; u8 pad1c[0xa]; u8 action; u8 type; };
extern "C" {
extern void* D_0034e948;
QV186* func_0016c028(void*);
s32 func_001d7b90(void*);
void func_001cf0d8(Obj186*, Msg186*);
u32 func_0018ca48(u8);
s32 func_001c0cd8(Obj186*);
void func_001c0e60(Obj186*);
f32 func_0018cb30(Msg186*);
void func_00186378(Obj186*, Msg186*, f32);
void func_00186478(Obj186*, Msg186*);
void func_001863a8(Obj186*, Msg186*, f32);
void func_0018cd28(Msg186*, f32*, f32*);
void func_00186740(Obj186*, Msg186*, s32, s32, f32, f32);
void func_00186948(Obj186*, Msg186*);
void func_00186988(Obj186*, Msg186*, f32);
void func_001cd078(Msg186*);

static inline bool isType17(Obj186* o) { return o->info->kind == 0x17; }
void func_00186160(Obj186* obj, Msg186* msg) {
    u32 fl = msg->flags & 1;
    if ((u8)fl) return;
    if (!func_001d7b90(obj->sub518)) return;
    if (isType17(obj)) {
        func_001cf0d8(obj, msg);
        return;
    }
    if ((u32)(msg->type - 15) < 4) {
        msg->dir = *func_0016c028(D_0034e948) - *func_0016c028(obj);
        msg->dir.y = 0;
        msg->dir.normalize();
    }
    u32 mode = func_0018ca48(msg->action);
    if (func_001c0cd8(obj) && mode != 0 && mode != 2) func_001c0e60(obj);
    switch (mode) {
    case 1:
        func_00186378(obj, msg, func_0018cb30(msg));
        break;
    case 2:
        func_00186478(obj, msg);
        break;
    case 3:
        func_001863a8(obj, msg, func_0018cb30(msg));
        break;
    case 4: {
        f32 a, b;
        func_0018cd28(msg, &a, &b);
        func_00186740(obj, msg, 16, 18, a, b);
        break;
    }
    case 5:
        func_00186948(obj, msg);
        break;
    case 14:
        func_00186988(obj, msg, func_0018cb30(msg));
        break;
    }
    func_001cd078(msg);
    msg->flags |= 1;
}
}
