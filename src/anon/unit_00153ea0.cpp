#include "../common/types.h"

// dk gauges (0x153ea0-0x157688), part of the 0x14ecb8 segment: assembled from the matched
// per-function sources. Each source's declarations stay in their own namespace (srcN) and every
// external symbol is bound by asm label.

// ==== from src/anon/auto80_199_queue.cpp
namespace dk { 

class Sprite {
public:
    u32 getSeqActiveXY(s32&, s32&);
    void getSeqActiveXYAddOffset(s32&, s32&);
    void setPos(s32, s32);
    void getPos(s32&, s32&);
    void setOffsetPos(s32, s32);
    void getOffsetPos(s32&, s32&);
}; }
namespace src0 {
u32 func_001386e0(...) asm("func_001386e0");
u32 func_0013c7d0(...) asm("func_0013c7d0");
u32 func_00138c10(...) asm("func_00138c10");
u32 func_001395a8(...) asm("func_001395a8");
u32 func_00139598(...) asm("func_00139598");
u32 func_0023f800(...) asm("func_0023f800");
u32 func_0023fa08(...) asm("func_0023fa08");
u32 func_0023f948(...) asm("func_0023f948");
u32 func_0023f908(...) asm("func_0023f908");
u32 func_0023eea0(u32, u32, u32, u32, u32, u32) asm("func_0023eea0");
u32 func_0023f848(...) asm("func_0023f848");
u32 func_001708f8(...) asm("func_001708f8");
void func_00153cc8(u32, u32, u32, u32, u32) asm("func_00153cc8");
u32 func_0016c060(...) asm("func_0016c060");
void func_00154100(u32, u32, u32) asm("func_00154100");
u32 func_002362b0(...) asm("func_002362b0");
void func_00236410(u32, u32) asm("func_00236410");
void func_00236428(u32, u32) asm("func_00236428");
void func_002367c8(u32) asm("func_002367c8");
u32 func_00154288(u32, u32) asm("func_00154288");
void func_00154af0(u32) asm("func_00154af0");
void func_00154b98(u32, u32) asm("func_00154b98");
void func_0014fcd8(u32) asm("func_0014fcd8");
u32 func_00154950(u32) asm("func_00154950");
u32 func_0013dda0(u32) asm("func_0013dda0");
void func_001542c8(u32, u32, u32) asm("func_001542c8");
void func_00155528(u32) asm("func_00155528");
u32 func_00154ee8(u32) asm("func_00154ee8");
void func_001543a0(u32, u32, u32) asm("func_001543a0");
void func_00158300(u32) asm("func_00158300");
void func_001554c0(u32) asm("func_001554c0");
void func_00155568(u32) asm("func_00155568");
void func_00155658(u32) asm("func_00155658");
void func_001556c0(u32) asm("func_001556c0");
u32 func_00156058(u32) asm("func_00156058");
u32 func_00156080(u32) asm("func_00156080");
u32 func_001560a8(u32, u32, u32) asm("func_001560a8");
u32 func_00156010(u32) asm("func_00156010");
u32 func_00156030(u32) asm("func_00156030");
u32 func_001396b0(...) asm("func_001396b0");
u32 func_0031a260(...) asm("func_0031a260");
u32 func_001565a8(...) asm("func_001565a8");
u32 func_00155ee8(u32) asm("func_00155ee8");


u32 fn(...);
void func_00153cc8(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) asm("func_00153cc8");
void func_00153ea0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) asm("func_00153ea0");
u32 func_001541d8(u32 a0, u32 a1, u32 a2) asm("func_001541d8");
void func_001543a0(u32 a0, u32 a1, u32 a2) asm("func_001543a0");
u32 func_00154450(u32 a0, u32 a1, u32 a2) asm("func_00154450");
void func_00154a88(u32 a0) asm("func_00154a88");
void func_00155300(u32 a0) asm("func_00155300");
void func_00155390(u32 a0, u32 a1) asm("func_00155390");
void func_001554c0(u32 a0) asm("func_001554c0");
void func_001556f0(u32 a0) asm("func_001556f0");
u32 func_00155d80(u32 a0) asm("func_00155d80");
void func_00156408(u32 a0) asm("func_00156408");
u32 func_001564b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001564b0");

}

// 153ea0
namespace src0 {
void func_00153ea0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) asm("func_00153ea0");
void func_00153ea0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    u32 s0 = a0;
    u32 s1 = a2;
    u32 s2 = a3;
    u32 s3 = a4;

    u32 v = func_001708f8(a1, 0xFFFFFFFFu);
    func_00153cc8(s0, v, s1, s2, s3);
}
}

// ==== from src/anon/batch_w63.cpp
namespace src1 {
void* func_0023ee30(u32) asm("func_0023ee30");
void func_0031a838(void*) asm("func_0031a838");
void func_002369a0(void*) asm("func_002369a0");
void func_0023c008(void*) asm("func_0023c008");
void func_00153ea0(void*, u32, s32, u32, s32) asm("func_00153ea0");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8 D_0034a7a0[] asm("D_0034a7a0");


void* cam_sxfs(u32, u32) asm("_ZN2dk6Camera20singleCrossFadeStartEf");
}

// 153f08
namespace src1 {
void* cam_sxfs(u32, u32) asm("_ZN2dk6Camera20singleCrossFadeStartEf");
void* cam_sxfs(u32 a0, u32 a1) {
    u8* p = (u8*)func_0023ee30(164);
    *(void**)p = D_00347f98;
    func_0031a838(p + 12);
    *(void**)p = D_0035eb98;
    func_002369a0(p + 24);  // obj_ctor_36eac8
    func_0023c008(p + 48);  // obj_ctor_36eae8
    *(void**)p = D_0034a7a0;
    func_00153ea0(p, a0, 4800, a1, 0);
    return p;
}
}

// ==== from src/anon/batch_wcx.cpp
namespace src2 {
void func_001396b0(u8*) asm("func_001396b0");
void func_0031a260(u8*, s32) asm("func_0031a260");
void func_0031ac78(u8*, s32) asm("func_0031ac78");
void func_00138748(u8* p) asm("func_00138748");

u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");f32 func_0017ce10(f32) asm("func_0017ce10");
void func_00239f18(u8*, f32) asm("func_00239f18");
void func_00239f18(u8*, f32) asm("func_00239f18");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void func_001386e0(u8*, s32, u32, u32, s32, s32) asm("func_001386e0");
void func_002362b0(u8*, u32) asm("func_002362b0");
void func_002367c8(u8*) asm("func_002367c8");
s32 func_001541d8(u8*, u32*, u32) asm("func_001541d8");
u32 func_00154288(u8*, u32, u32) asm("func_00154288");
void func_001386e0(u8*, u32, u32, u8*, u32, u32) asm("func_001386e0");
void func_001391c8(u8*, u32) asm("func_001391c8");
void func_00138748(u8*) asm("func_00138748");
f32 func_0017ce10(f32) asm("func_0017ce10");
void func_0013edd0(u8*, f32) asm("func_0013edd0");
void func_0014b1e0(u8*, s32, s32) asm("func_0014b1e0");
void func_001391c8(u8*, u32, u32) asm("func_001391c8");
void func_001395a8(u8*) asm("func_001395a8");
void func_00139598(u8*) asm("func_00139598");
f32 func_0017ce10(f32) asm("func_0017ce10");
void func_001391c8(u8*, u32, u32) asm("func_001391c8");
f32 func_0017ce10(f32) asm("func_0017ce10");
void func_0014b1e0(u8*, s32, s32) asm("func_0014b1e0");
s32 func_0013a9d0(void) asm("func_0013a9d0");
f32 func_0017ce10(f32) asm("func_0017ce10");
void func_002362b0(u8*, u32) asm("func_002362b0");
s32 func_0013a9d0(void) asm("func_0013a9d0");
void func_002368e8(u8*, f32) asm("func_002368e8");
void func_002367c8(u8*) asm("func_002367c8");
void func_001386e0(u8*, u32, u32, u8*, u32, u32) asm("func_001386e0");
void func_001395a8(u8*) asm("func_001395a8");
void func_00139598(u8*) asm("func_00139598");

}

// 153fa0
namespace src2 {
void func_00153fa0(u8* p, u32 a, u32 b, u32 c, u32 d, u32 e) asm("func_00153fa0");
void func_00153fa0(u8* p, u32 a, u32 b, u32 c, u32 d, u32 e)
{
    *(u32*)(p + 832) = b;
    u32 v = 0;
    if (func_001541d8(p, &v, c) == 1) {
        func_001386e0(p, a, v, p + 416, func_00154288(p, d, e), e);
    } else {
        func_001391c8(p, a);
        func_00138748(p);
    }
}
}

// 154048
namespace src2 {
void func_00154048(u8* p, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1) asm("func_00154048");
void func_00154048(u8* p, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1)
{
    *(u32*)(p + 832) = 0;
    u8* q = p + 416;
    func_002362b0(q, a3);
    if (func_0013a9d0()) func_002368e8(q, 1.0f);
    func_002367c8(q);  // obj_dispatch_bitfield64
    func_001386e0(p, a1, a2, q, t0, t1);
    p[836] = 1;
}
}

// ==== from src/anon/batch_w84.cpp
namespace src3 {
extern s32 D_0034a7d8[] asm("D_0034a7d8");
extern s32 D_0034a7e8[] asm("D_0034a7e8");
u32 func_0013d7e0(void*) asm("func_0013d7e0");
s32 func_00236490(u32) asm("func_00236490");
s32 func_002364f8(u32) asm("func_002364f8");

}

// 154100
namespace src3 {
void func_00154100(u8* p, s32* a, s32* b) asm("func_00154100");
void func_00154100(u8* p, s32* a, s32* b) {
    *a = 0;
    *b = 0;
    for (s32 i = 0; i < *(s32*)(p + 832); i++) {
        *a += D_0034a7d8[i];
        *b += D_0034a7e8[i];
    }
    u32 o = func_0013d7e0(p);
    *a += func_00236490(o) + 13568;
    *b += func_002364f8(o) + 10240;
}
}

// 1541d8
namespace src0 {
u32 func_001541d8(u32 a0, u32 a1, u32 a2) asm("func_001541d8");
u32 func_001541d8(u32 a0, u32 a1, u32 a2) {
    *(u8*)(a0 + 836) = 0;

    u32 s1 = a0;
    u32 p = a1;
    u32 kind = a2;

    u32 tmp0;
    u32 tmp1;
    u32 tmp2;

    if (kind != 0) {
        u32 s2 = func_0016c060(kind, (u32)&tmp0, p);
        u32 p1 = (u32)&tmp1;
        u32 p2 = (u32)&tmp2;
        if (s2 == 1) {
            u32 s0 = s1 + 416;
            func_00154100(s1, p1, p2);
            func_002362b0(s0, tmp0);
            func_00236410(s0, tmp1);  // obj_set4_then_call
            func_00236428(s0, tmp2);  // obj_set32_then_call
            func_002367c8(s0);  // obj_dispatch_bitfield64
            *(u8*)(s1 + 836) = (u8)s2;
            return 1;
        }
    }

    return 0;
}
}

// ==== from src/anon/batch_w21.cpp
namespace src4 {

}

// 154288
namespace src4 {
s32 func_00154288(u32, s32 a) asm("func_00154288");
s32 func_00154288(u32, s32 a) {  // state_index_0_1_2
    switch (a) {
    case 0: return 3;
    case 1: return 0;
    case 2: return 2;
    }
    return 3;
}
}

// ==== from src/anon/batch_w36.cpp
namespace src5 {
s32 func_001541d8(u8*, u32*, u32) asm("func_001541d8");
u32 func_00154288(u8*, u32) asm("func_00154288");
void func_001387f8(u8*, u32, u8*, u32) asm("func_001387f8");

}

// 1542c8
namespace src5 {
void func_001542c8(u8* p, u32 a, u32 b) asm("func_001542c8");
void func_001542c8(u8* p, u32 a, u32 b) {
    u32 v = 0;
    if (func_001541d8(p, &v, a) == 1) {
        func_001387f8(p, v, p + 416, func_00154288(p, b));
    }
}
}

// ==== from src/anon/tiny_auto80_queue.cpp
namespace src6 {
 u32 func_00138c10(...) asm("func_00138c10");
 u32 func_00138988(...) asm("func_00138988");
 u32 func_00138988(...) asm("func_00138988");
 u32 func_00138988(...) asm("func_00138988");
 u32 func_00138840(...) asm("func_00138840");
 u32 func_00138c10(...) asm("func_00138c10");
u32 func_00156030(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00156030");
u32 func_00156058(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00156058");
u32 func_00156080(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00156080");
 u32 func_00138840(...) asm("func_00138840");
void func_00154330(u32 a0) asm("func_00154330");
 u32 func_00138988(...) asm("func_00138988");
 u32 func_00236788(...) asm("func_00236788");
void func_00154358(u32 a0) asm("func_00154358");
 u32 func_00154288(...) asm("func_00154288");
void func_00154408(u32 a0, u32 a1) asm("func_00154408");
u32 func_00154910(u32 a0) asm("func_00154910");
u32 func_00154930(u32 a0) asm("func_00154930");
u32 func_00156010(u32 a0) asm("func_00156010");
 u32 func_001572e8(...) asm("func_001572e8");
void func_001574a0(u32 a0) asm("func_001574a0");
u32 func_001570d0(u8* a0) asm("func_001570d0");
u32 func_00157100(u8* a0) asm("func_00157100");

}

// 154330
namespace src6 {
void func_00154330(u32 a0) asm("func_00154330");
void func_00154330(u32 a0) {
    if (*(u8*)((u32)a0 + (s32)(836)) != 0u) {
        func_00138840(a0);
        return;
    }
}
}

// 154358
namespace src6 {
void func_00154358(u32 a0) asm("func_00154358");
void func_00154358(u32 a0) {
    u32 s0 = a0;
    if (*(u8*)((u32)s0 + (s32)(836)) != 0u) {
        func_00236788((u32)((s32)a0 + (416)));  // to_236830
        func_00138988(s0);
        return;
    }
}
}

// 1543a0
namespace src0 {
void func_001543a0(u32 a0, u32 a1, u32 a2) asm("func_001543a0");
void func_001543a0(u32 a0, u32 a1, u32 a2) {
    u32 s0 = a0;
    u32 s1 = a2;

    if (*(u8*)(a0 + 836) != 0) {
        if (a1 == 1) {
            func_00138c10(a0, a1);
            *(u32*)(s0 + 392) = func_00154288(s0, s1);
            return;
        }
        func_00138c10(a0, a1);
    }
}
}

// 154408
namespace src6 {
void func_00154408(u32 a0, u32 a1) asm("func_00154408");
void func_00154408(u32 a0, u32 a1) {
    u32 s0 = a0;
    if (*(u8*)((u32)a0 + (s32)(836)) != 0u) {
        u32 v0 = func_00154288(a0, a1);  // state_index_0_1_2
        func_00138c10(s0, v0);
        return;
    }
}
}

// 154450
namespace src0 {
u32 func_00154450(u32 a0, u32 a1, u32 a2) asm("func_00154450");
u32 func_00154450(u32 a0, u32 a1, u32 a2) {
    *(u32*)(a0 + 15556) = a2;

    u32 s0 = a0;
    *(u32*)(s0 + 15552) = a1;
    u32 s1 = a1;
    *(u32*)(s0 + 15560) = a1;
    *(u32*)(s0 + 15564) = a1;

    func_00154af0(s0);
    func_00154b98(s0, s1);

    u32 vtbl = *(u32*)s0;
    u32 fn = *(u32*)(vtbl + 4);
    ((void (*)(u32))fn)(s0);

    return s0;
}
}

// 1544b0
namespace src2 {
void func_001544b0(u8* p) asm("func_001544b0");
void func_001544b0(u8* p)
{
    u8* q = p;
    u8* end = p + 13056;
    do {
        for (s32 j = 0; j < 2; j++) func_00139598(q + 2496 + j * 408);
        q += 816;
    } while ((s32)q < (s32)end);
    for (s32 i = 0; i < *(s32*)(p + 15568); i++)
        if (i < 16) func_001395a8(p + 2496 + i * 816);
}
}

// ==== from src/anon/batch_w2407.cpp
namespace src7 {

struct W1632Seq { u8 pad[344]; };

struct W1632Sprite {
    u8 pad0[24];
    W1632Seq seq;       // 24
    u8 pad1[28];
    void* parent;       // 396
    s32 flag;           // 400
    u8 pad2[4];
};

struct W1632Menu {
    u8 pad0[32];
    s32 x;                      // 32
    u8 pad1[12];
    W1632Sprite parts[6];       // 48
    W1632Sprite grid[16][2];    // 2496
};
void func_00154b18(W1632Menu*) asm("func_00154b18");
void func_0014fc40(W1632Menu*, u32, s32, u32, u32, s32) asm("func_0014fc40");
u32 func_0013a7e8(s32) asm("func_0013a7e8");
u32 func_0013d7e0(void) asm("func_0013d7e0");
void func_001386e0(W1632Sprite*, u32, u32, u32, u32, u32) asm("func_001386e0");
void func_001396b0(W1632Sprite*) asm("func_001396b0");
void func_0031a260(W1632Sprite*, u32) asm("func_0031a260");
void func_00138c68(W1632Sprite*, s32, s32) asm("func_00138c68");
s32 func_0023aa98(W1632Seq*) asm("func_0023aa98");
void func_001399c0(s32) asm("func_001399c0");


static inline void W1632_setParent(W1632Sprite* obj, W1632Sprite* parent) {
    obj->parent = parent;
    func_001396b0(obj);
    if (obj->parent != 0) {
        obj->flag = 0;
        func_001396b0(obj);
        if (obj->flag != 0) {
            func_0031a260(obj, 0);
        }
    }
}
}

// 154558
namespace src7 {
void func_00154558(W1632Menu* self) asm("func_00154558");
void func_00154558(W1632Menu* self) {
    u32 tex, img;
    s32 i, row, pos;
    func_00154b18(self);
    func_0014fc40(self, 18, 0, 7000, 6, 1);
    self->x = 0;
    tex = func_0013a7e8(1);
    img = func_0013d7e0();
    func_001386e0(&self->parts[0], 7000, tex, img, 38, 6);
    func_001386e0(&self->parts[1], 7000, tex, img, 42, 6);
    func_001386e0(&self->parts[2], 7000, tex, img, 39, 6);
    func_001386e0(&self->parts[3], 7000, tex, img, 40, 6);
    func_001386e0(&self->parts[4], 7000, tex, img, 41, 6);
    func_001386e0(&self->parts[5], 7000, tex, img, 43, 6);
    for (i = 0; i < 6; i++) {
        W1632_setParent(&self->parts[i], &self->parts[0]);
    }
    W1632_setParent(&self->parts[0], 0);
    pos = 0;
    for (row = 0; row < 16; row++) {
        for (s32 j = 0; j < 2; j++) {
            W1632Sprite* p = &self->grid[row][j];
            func_001386e0(p, 7000, tex, img, j == 0 ? 45 : 44, 6);
            W1632_setParent(p, &self->parts[0]);
            func_00138c68(p, pos, 0);
        }
        pos -= func_0023aa98(&self->grid[row][0].seq);
    }
    func_001399c0(6);
}
}

// ==== from src/anon/batch_w76.cpp
namespace src8 {
void func_00239f18(u8*, f32) asm("func_00239f18");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");

}

// 1547e0
namespace src8 {
void func_001547e0(u8* a, s32 b, s32 c) asm("func_001547e0");
void func_001547e0(u8* a, s32 b, s32 c)
{
    f32 v = b;
    func_00239f18(a + c * 408 + 72, v / 100.0f);  // obj_set_float312_and_flags
    s32 n = (s32)-v;
    func_00138c68(a + c * 408 + 48, n, 0);
    if (c == 2) func_00138c68(a + 1272, n, 0);
}
}

// ==== from src/anon/batch_w37.cpp
namespace src9 {
void func_001395a8(void*) asm("func_001395a8");

}

// 1548a8
namespace src9 {
void func_001548a8(u8* p, s32 n) asm("func_001548a8");
void func_001548a8(u8* p, s32 n) {
    if (*(u32*)(p + 15568)) {
        for (s32 i = 0; i < n; i++) {
            if (i < 16) func_001395a8(p + 2904 + i * 816);
        }
    }
}
}

// 154910
namespace src6 {
u32 func_00154910(u32 a0) asm("func_00154910");
u32 func_00154910(u32 a0) {
    u32 v0 = *(volatile u32*)((u32)a0 + (s32)(15552));
    v0 = (u32)((s32)v0 + (-1));
    return (u32)((s32)v0 / (s32)200);
}
}

// 154930
namespace src6 {
u32 func_00154930(u32 a0) asm("func_00154930");
u32 func_00154930(u32 a0) {
    u32 v0 = *(volatile u32*)((u32)a0 + (s32)(15560));
    v0 = (u32)((s32)v0 + (-1));
    return (u32)((s32)v0 / (s32)200);
}
}

// ==== from src/anon/batch_wcx2.cpp
namespace src10 {
void func_00158050(u8*, s32, u32, u32, s32, s32, u32) asm("func_00158050");
void func_00139598(u8*) asm("func_00139598");
void func_00156880(u8* p, u32 a1, u32 a2, u32 a3) asm("func_00156880");


struct Pg7 { u8 pad[15552]; s32 total; s32 count; s32 last; u8 pad2[4]; s32 page; s32 n0; s32 n1; s32 n2; u8 pad3; u8 one; };
void func_00139948(s32) asm("func_00139948");
s32 func_00154910(Pg7*) asm("func_00154910");
s32 func_00154930(Pg7*) asm("func_00154930");
void func_00139598(u8*) asm("func_00139598");
void func_001544b0(Pg7*) asm("func_001544b0");
void func_001547e0(Pg7*, s32, s32) asm("func_001547e0");
void func_001548a8(Pg7*, s32) asm("func_001548a8");
void func_00154950(Pg7* p) asm("func_00154950");
void func_00139598(u8*) asm("func_00139598");


// fdlibm/newlib __ieee754_acosf (sqrtf is __ieee754_sqrtf).
static const f32 one = 1.0f, pi = 3.1415925f, pio2_hi = 1.57079625f, pio2_lo = 7.54978942e-08f,
    pS0 = 0.166666657f, pS1 = -0.325565785f, pS2 = 0.201212525f, pS3 = -0.0400555357f,
    pS4 = 0.000791535014f, pS5 = 3.47933092e-05f, qS1 = -2.4033947f, qS2 = 2.02094555f,
    qS3 = -0.68828392f, qS4 = 0.0770381466f;
void func_00155d80(u8*) asm("func_00155d80");
s32 func_00155e30(u8*) asm("func_00155e30");
void func_00139598(u8*) asm("func_00139598");


// --------------------
s32 func_00155d80_r(u8*) asm("func_00155d80");extern s32 D_0034a8f0[] asm("D_0034a8f0");
extern s32 D_0034a8a0[] asm("D_0034a8a0");
extern s32 D_0034a8c8[] asm("D_0034a8c8");
s32 func_00155e30(u8* p) asm("func_00155e30");
s32 func_00155fc0(u8* p) asm("func_00155fc0");

}

// 154950
namespace src10 {
void func_00154950(Pg7* p) asm("func_00154950");
void func_00154950(Pg7* p)
{
    func_00139948(6);
    s32 c = p->count;
    p->page = (c - 1) / 200;
    p->n0 = c - p->page * 200;
    s32 a = func_00154910(p);
    p->n2 = p->total - a * 200;
    s32 b = func_00154930(p);
    p->n1 = p->last - b * 200;
    if (p->n2 > p->n0) p->n0 = 200;
    if (p->page != a) p->n0 = 200;
    if (b != a) p->n1 = 200;
    p->one = 0;
    if (a == p->page && a != 0) p->one = 1;
    if (!p->one) func_00139598((u8*)p + 456);
    func_001544b0(p);
    func_001547e0(p, p->n0, 2);
    func_001547e0(p, p->n1, 4);
    func_001547e0(p, p->n2, 5);
    func_001548a8(p, b);
}
}

// 154a88
namespace src0 {
void func_00154a88(u32 a0) asm("func_00154a88");
void func_00154a88(u32 a0) {
    u32 s0 = a0;

    if (*(u8*)(a0 + 15584) != 0) {
        if ((*(u32*)(a0 + 12) & 0x100) == 0) {
            func_0014fcd8(a0);
            ((dk::Sprite*)(u32)(s0 + 48))->setPos(*(u32*)(s0 + 32), *(u32*)(s0 + 36));
            func_00154950(s0);
        }
    }
}
}

// ==== from src/anon/batch_w3.cpp
namespace src11 {
void func_00139948(s32) asm("func_00139948");
void func_00139ba0(s32) asm("func_00139ba0");

}

// 154af0
namespace src11 {
void func_00154af0(u8* p) asm("func_00154af0");
void func_00154af0(u8* p) {
    p[15584] = 1;
    func_00139948(6);
    func_00139ba0(6);
}
}

// ==== from src/anon/batch_w1.cpp
namespace src12 {
void func_001399c0(s32) asm("func_001399c0");
void func_00139b28(s32) asm("func_00139b28");

}

// 154b18
namespace src12 {
void func_00154b18(u8* p) asm("func_00154b18");
void func_00154b18(u8* p) {
    p[0x3ce0] = 0;
    func_001399c0(6);
    func_00139b28(6);
}
}

// ==== from src/anon/batch_w22.cpp
namespace src13 {
u32 func_0013d810(void) asm("func_0013d810");
void func_00154450(u32, u32, u32) asm("func_00154450");
void func_00154b40(u32 a, u32 b) asm("func_00154b40");
u32 func_00155f40(void*) asm("func_00155f40");
void func_00138c10(void*, u32) asm("func_00138c10");
void func_00156408(void*) asm("func_00156408");

void GAUGE_PLAYER_update(u8*) asm("_ZN2dk12GAUGE_PLAYER6updateEv");
}

// 154b40
namespace src13 {
void func_00154b40(u32 a, u32 b) asm("func_00154b40");
void func_00154b40(u32 a, u32 b) {
    func_00154450(func_0013d810(), a, b);
}
}

// ==== from src/anon/tiny.cpp
namespace src14 {
void func_00154b18(void*) asm("func_00154b18");
void func_00155410(void*) asm("func_00155410");
void func_00154b80(BD_VALUE* bd) asm("func_00154b80");

}

// 154b80
namespace src14 {
void func_00154b80(BD_VALUE* bd) asm("func_00154b80");
void func_00154b80(BD_VALUE* bd) { func_00154b18(bd); }
}

// ==== from src/anon/batch_w49.cpp
namespace src15 {
void func_00138c10(u8*, s32) asm("func_00138c10");

}

// 154b98
namespace src15 {
void func_00154b98(u8* p, s32 n) asm("func_00154b98");
void func_00154b98(u8* p, s32 n) {
    s32 m = *(s32*)(p + 15556);
    if (m < n) n = m;
    *(s32*)(p + 15552) = n;
    *(s32*)(p + 15564) = n;
    *(s32*)(p + 15560) = n;
    s32 k = (n - 1) / 200;
    for (s32 i = 0; i < k; i++) func_00138c10(p + 2904 + i * 816, 44);
}
}

// ==== from src/anon/batch_w87.cpp
namespace src16 {
void func_00138c10(void*, s32) asm("func_00138c10");
s32 func_00154910(void*) asm("func_00154910");
s32 func_00154930(void*) asm("func_00154930");

struct P154 { u8 pad[15552]; s32 a; s32 pad2; s32 b; s32 c; };

}

// 154c10
namespace src16 {
void func_00154c10(u8* p, s32 n) asm("func_00154c10");
void func_00154c10(u8* p, s32 n) {
    s32 i = 0;
    if (n < 0) n = 0;
    P154* s = (P154*)p;
    s->a = n;
    s->b = s->c;
    s->c = n;
    func_00138c10(p + 1680, 41);
    s32 a = func_00154910(p);
    s32 cnt = func_00154930(p);
    if (cnt > 0) {
        p += 2904;
        do {
            func_00138c10(p, i < a ? 44 : 46);
            i++;
            p += 816;
        } while (i < cnt);
    }
}
}

// ==== from src/anon/batch_w97.cpp
namespace src17 {
f32 func_0017ce10(f32) asm("func_0017ce10");
void func_0013edd0(u8*, f32) asm("func_0013edd0");
void func_0014b1e0(u8*, s16, s16) asm("func_0014b1e0");
void func_0014b208(u8*, u16, u16) asm("func_0014b208");

u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");extern f32 D_0034a838 asm("D_0034a838");

}

// 154cd0
namespace src17 {
void func_00154cd0(u8* p, s32 i, f32 t) asm("func_00154cd0");
void func_00154cd0(u8* p, s32 i, f32 t) {
    s32 w, h, x, y;
    if (t < D_0034a838) { w = 64; h = 64; x = -64; y = -64; }
    else { w = 0; h = 0; x = 0; y = 0; }
    
    f32 s = t * 3.1415925f + -1.5707963f;
    s = func_0017ce10(s);
    u_call4_00139d78(p + i*592 + 2576);
    func_0013edd0(p + i*592 + 2608, s);
    u_call4_00139d78(p + i*592 + 2576);
    func_0014b1e0(p + i*592 + 2896, x, y);
    func_0014b208(p + i*592 + 2896, w, h);
}
}

// ==== from src/anon/batch_w91.cpp
namespace src18 {


u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");f32 func_0017ce10(f32) asm("func_0017ce10");
void func_0013edd0(u8*, f32) asm("func_0013edd0");
void func_0014b1e0(u8*, s16, s16) asm("func_0014b1e0");
void func_0014b208(u8*, u16, u16) asm("func_0014b208");
extern f32 D_0034a838 asm("D_0034a838");

}

// 154de8
namespace src18 {
void func_00154de8(u8* p, f32 t) asm("func_00154de8");
void func_00154de8(u8* p, f32 t) {
    s32 w, h, x, y;
    if (t < D_0034a838) { w = 64; h = 64; x = 0; y = -64; }
    else { w = 1; h = 1; x = -64; y = 0; }
    f32 s = (1.0f - t) * 3.1415925f;
    s = func_0017ce10(s);
    u_call4_00139d78(p + 4944);
    func_0013edd0(p + 4976, s);
    u_call4_00139d78(p + 4944);
    func_0014b1e0(p + 5264, x, y);
    func_0014b208(p + 5264, w, h);
}
}

// ==== from src/anon/batch_w29.cpp
namespace src19 {

}

// 154ee8
namespace src19 {
u32 func_00154ee8(u8* p) asm("func_00154ee8");
u32 func_00154ee8(u8* p) {  // field24_state_code
    switch (*(s32*)(p + 24)) {
    case 1: return 67;
    case 0: case 2: return 72;
    default: return 72;
    }
}
}

// ==== from src/anon/batch_w1632.cpp
namespace src20 {

struct W1632Seq { u8 pad[344]; };

struct W1632Rect { u8 pad[256]; };

struct W1632Sprite2 {
    u8 pad0[24];
    W1632Seq seq;       // 24
    u8 pad1[24];
    s32 f392;           // 392
    void* parent;       // 396
    s32 flag;           // 400
    u8 pad2[8];
};

struct W1632Gauge {
    u8 pad0[32];
    W1632Rect r1;       // 32
    u8 pad1[32];
    W1632Rect r2;       // 320
    void* owner;        // 576
    u8 pad2[12];
};

struct W1632Party {
    u8 pad0[24];
    s32 f24;                    // 24
    u8 pad1[20];
    s32 f48;                    // 48
    s32 f52;                    // 52
    u8 pad2[8];
    W1632Sprite2 head;          // 64
    u8 pad3[916 - 64 - 412];
    W1632Sprite2 spr[4];        // 916
    u8 pad4[2576 - 916 - 4 * 412];
    W1632Gauge g[5];            // 2576
    u8 b[3];                    // 5536
};
void func_00158138(W1632Party*, u32, u32, s32) asm("func_00158138");
u32 func_0013a7e8(s32) asm("func_0013a7e8");
u32 func_0013d7e0(void) asm("func_0013d7e0");
u32 func_00158290(W1632Party*) asm("func_00158290");
void func_00158050(W1632Sprite2*, u32, u32, u32, u32, u32, u32) asm("func_00158050");
void func_0013e0f8(W1632Gauge*, u32, u32, u32) asm("func_0013e0f8");
void func_001581f8(W1632Party*) asm("func_001581f8");
void func_00153fa0(W1632Sprite2*, u32, s32, s32, s32, u32) asm("func_00153fa0");
u32 func_00139d78(void*) asm("func_00139d78");
void func_0014b208(W1632Rect*, u32, u32) asm("func_0014b208");
void func_0014b200(W1632Rect*, u32) asm("func_0014b200");
void func_001396b0(void*) asm("func_001396b0");
void func_0031a260(void*, u32) asm("func_0031a260");
void func_001395e8(void*) asm("func_001395e8");
void func_00139610(void*) asm("func_00139610");
s32 func_00154ee8(W1632Party*) asm("func_00154ee8");
s32 func_0023aa98(W1632Seq*) asm("func_0023aa98");
void func_00138c40(void*, s32, s32) asm("func_00138c40");
void func_001582a8(W1632Party*) asm("func_001582a8");


static inline void W1632_setParent2(W1632Sprite2* obj, W1632Sprite2* parent) {
    obj->parent = parent;
    func_001396b0(obj);
    if (obj->parent != 0) {
        obj->flag = 0;
        func_001396b0(obj);
        if (obj->flag != 0) {
            func_0031a260(obj, 0);
        }
    }
}

static inline void W1632_setParent2b(W1632Sprite2* obj, W1632Sprite2* parent) {
    obj->parent = parent;
    asm volatile("" ::: "memory");
    func_001396b0(obj);
    if (obj->parent != 0) {
        obj->flag = 0;
        func_001396b0(obj);
        if (obj->flag != 0) {
            func_0031a260(obj, 0);
        }
    }
}void func_00154f30(W1632Party* self, u32 a1, u32 a2) asm("func_00154f30");


struct W1632Sprite {
    u8 pad0[24];
    W1632Seq seq;       // 24
    u8 pad1[28];
    void* parent;       // 396
    s32 flag;           // 400
    u8 pad2[4];
};

struct W1632Bar {
    u8 pad0[32];
    W1632Rect r;        // 32
    u8 pad1[32];
    void* owner;        // 320
};

struct W1632Panel {
    u8 pad0[916];
    W1632Sprite icon;           // 916
    u8 pad1[6704 - 916 - 408];
    W1632Sprite2 frame;         // 6704
    u8 pad2[11648 - 6704 - 412];
    W1632Sprite2 spr[3];        // 11648
    u8 pad3[12896 - 11648 - 3 * 412];
    W1632Bar bar;               // 12896
};
u32 func_00155ee8(W1632Panel*) asm("func_00155ee8");
u32 func_00155fc0(W1632Panel*) asm("func_00155fc0");
u32 func_00155e30(W1632Panel*) asm("func_00155e30");
s32 func_00155f40(W1632Panel*) asm("func_00155f40");
s32 func_00156030(W1632Panel*) asm("func_00156030");
void func_00156408(W1632Panel*) asm("func_00156408");
void func_00158050(W1632Sprite2*, u32, u32, u32, u32, u32, u32) asm("func_00158050");
void func_0013dfb8(W1632Bar*, u32, u32) asm("func_0013dfb8");
void func_001386e0(W1632Sprite*, u32, u32, u32, u32, u32) asm("func_001386e0");
u32 func_00139d78(void*) asm("func_00139d78");
void func_0014b200(W1632Rect*, u32) asm("func_0014b200");
void func_001396b0(void*) asm("func_001396b0");
void func_0031a260(void*, u32) asm("func_0031a260");
void func_001395e8(void*) asm("func_001395e8");
void func_00139610(void*) asm("func_00139610");
void func_00139598(void*) asm("func_00139598");
s32 func_0023aa18(W1632Seq*) asm("func_0023aa18");
s32 func_0023aa38(W1632Seq*) asm("func_0023aa38");
void func_00138c68(void*, s32, s32) asm("func_00138c68");
void func_00138c10(void*, s32) asm("func_00138c10");


static inline void W1632_link2(W1632Sprite2* obj, void* parent) {
    obj->parent = parent;
    func_001396b0(obj);
    if (obj->parent != 0) {
        obj->flag = 0;
        func_001396b0(obj);
        if (obj->flag != 0) {
            func_0031a260(obj, 0);
        }
    }
}

static inline void W1632_link(W1632Sprite* obj, void* parent) {
    obj->parent = parent;
    func_001396b0(obj);
    if (obj->parent != 0) {
        obj->flag = 0;
        func_001396b0(obj);
        if (obj->flag != 0) {
            func_0031a260(obj, 0);
        }
    }
}
}

// 154f30
namespace src20 {
void func_00154f30(W1632Party* self, u32 a1, u32 a2) asm("func_00154f30");
void func_00154f30(W1632Party* self, u32 a1, u32 a2) {
    u32 tex, img, grp;
    s32 i, j;
    W1632Sprite2* root = &self->spr[0];
    W1632Gauge* g;
    func_00158138(self, a1, a2, 1);
    tex = func_0013a7e8(1);
    img = func_0013d7e0();
    grp = func_00158290(self);
    self->b[0] = 0;
    self->b[1] = 0;
    self->b[2] = 0;
    func_00158050(&self->spr[0], 7000, tex, img, 71, 0, grp);
    func_0013e0f8(&self->g[0], 7000, 0, grp);
    func_0013e0f8(&self->g[1], 7000, 1, grp);
    func_00158050(&self->spr[1], 7000, tex, img, 64, 100, grp);
    func_0013e0f8(&self->g[2], 7000, 1, grp);
    func_00158050(&self->spr[2], 7000, tex, img, 65, 1000, grp);
    func_0013e0f8(&self->g[3], 7000, 0, grp);
    func_0013e0f8(&self->g[4], 7000, 1, grp);
    func_00158050(&self->spr[3], 7000, tex, img, 66, 10000, grp);
    func_001581f8(self);
    {
        s32 c = self->f24;
        func_00153fa0(&self->head, 7000, self->f48 + 1, self->f52, c, grp);
    }
    func_00139d78(&self->g[0]);
    func_0014b208(&self->g[0].r1, 64, 64);
    func_00139d78(&self->g[3]);
    func_0014b208(&self->g[3].r1, 64, 64);
    func_00139d78(&self->g[0]);
    func_0014b200(&self->g[0].r1, 0);
    func_0014b200(&self->g[0].r2, 0);
    func_00139d78(&self->g[3]);
    func_0014b200(&self->g[3].r1, 0);
    func_0014b200(&self->g[3].r2, 0);
    func_00139d78(&self->g[1]);
    func_0014b200(&self->g[1].r1, 200);
    func_0014b200(&self->g[1].r2, 200);
    func_00139d78(&self->g[2]);
    func_0014b200(&self->g[2].r1, 2000);
    func_0014b200(&self->g[2].r2, 2000);
    func_00139d78(&self->g[4]);
    func_0014b200(&self->g[4].r1, 20000);
    func_0014b200(&self->g[4].r2, 20000);
    for (i = 0; i < 4; i++) {
        W1632_setParent2(&self->spr[i], root);
        func_001395e8(&self->spr[i]);
        func_00139610(&self->spr[i]);
    }
    for (j = 0; j < 5; j++) {
        g = &self->g[j];
        func_00139d78(g);
        g->owner = root;
    }
    W1632_setParent2b(&self->head, root);
    W1632_setParent2(root, 0);
    root->f392 = func_00154ee8(self);
    func_00138c40(root, 0, func_0023aa98(&self->spr[0].seq) * self->f48);
    func_001582a8(self);
}
}

// 155300
namespace src0 {
void func_00155300(u32 a0) asm("func_00155300");
void func_00155300(u32 a0) {
    u32 s0 = a0;
    u32 s1 = func_0013dda0(*(u32*)(s0 + 48) + 1);
    u32 p;
    *(u32*)(s0 + 52) = s1;

    if (*(u8*)(s0 + 5538) != 0) {
        goto L_call_55528;
    }
    *(u8*)(s0 + 5538) = 1;
L_after_flag:
    func_001542c8(s0 + 64, s1, *(u32*)(s0 + 24));
    *(u8*)(s0 + 5536) = 1;

    p = *(u32*)(s0 + 52);
    if (p != 0) {
        u32 v = *(u32*)(*(u32*)(p + 1164));
        *(u32*)(s0 + 40) = v;
        *(u32*)(s0 + 36) = v;
    }
    return;

L_call_55528:
    func_00155528(s0);
    goto L_after_flag;
}
}

// 155390
namespace src0 {
void func_00155390(u32 a0, u32 a1) asm("func_00155390");
void func_00155390(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = s0 + 916;
    u32 s2 = a1;

    *(u32*)(s0 + 36) = *(u32*)(a0 + 40);
    *(u32*)(s0 + 40) = *(u32*)(*(u32*)(*(u32*)(s0 + 52) + 1164));

    func_00138c10(a0 + 1328, 64);
    func_00138c10(s1, s2);
    *(u32*)(s1 + 392) = func_00154ee8(s0);
    func_001543a0(s0 + 64, 1, *(u32*)(s0 + 24));
}
}

// ==== from src/anon/batch_w31.cpp
namespace src21 {
u32 func_00154ee8(void*) asm("func_00154ee8");
void func_00138c10(void*, u32) asm("func_00138c10");
void func_00154408(void*, u32) asm("func_00154408");

}

// 155410
namespace src21 {
void func_00155410(u8* p) asm("func_00155410");
void func_00155410(u8* p) {
    u32 v = **(u32**)(*(u8**)(p + 52) + 1164);
    *(u32*)(p + 40) = v;
    *(u32*)(p + 36) = v;
    func_00138c10(p + 916, func_00154ee8(p));
    func_00154408(p + 64, *(u32*)(p + 24));
}
}

// ==== from src/anon/tiny_wrappers_more.cpp
namespace src22 {

extern "C" u32 dk_Obj2D_localHide(u32, u32, u32, u32) asm("_ZN2dk5Obj2D9localHideEv");u32 func_00155390(u32, u32, u32, u32) asm("func_00155390");
u32 func_001572e8(u32, u32, u32, u32) asm("func_001572e8");
u32 func_00155460(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00155460");
u32 func_00155478(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00155478");
u32 func_00155490(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00155490");
u32 func_001565a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001565a8");

}

// 155460
namespace src22 {
u32 func_00155460(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00155460");
u32 func_00155460(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00155390(a0, 0x00000046u, a2, a3);
}
}

// 155478
namespace src22 {
u32 func_00155478(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00155478");
u32 func_00155478(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00155390(a0, 0x00000045u, a2, a3);
}
}

// 155490
namespace src22 {
u32 func_00155490(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00155490");
u32 func_00155490(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_00155390(a0, 0x00000044u, a2, a3);
}
}

// 1554a8
namespace src14 {
void func_001554a8(BD_VALUE* bd) asm("func_001554a8");
void func_001554a8(BD_VALUE* bd) { func_00155410(bd); }
}

// 1554c0
namespace src0 {
void func_001554c0(u32 a0) asm("func_001554c0");
void func_001554c0(u32 a0) {
    u32 s0 = a0;
    if (*(u8*)(s0 + 32) != 0) {
        return;
    }

    if (func_0013c7d0() != 0) {
        func_00138c10(s0 + 916, func_00154ee8(s0));
        *(u8*)(s0 + 32) = 1;
        return;
    }

    if (*(u8*)(s0 + 1320) != 0) {
        *(u8*)(s0 + 32) = 1;
    }
}
}

// ==== from src/anon/batch_w11.cpp
namespace src23 {
void func_00138c10(void*, s32) asm("func_00138c10");
void func_001581f8(void*) asm("func_001581f8");
s32 func_00154ee8(void*) asm("func_00154ee8");
  // field24_state_code
void GAUGE_FRIEND_reload(u8*) asm("_ZN2dk12GAUGE_FRIEND6reloadEv");
}

// 155528
namespace src23 {
void GAUGE_FRIEND_reload(u8*) asm("_ZN2dk12GAUGE_FRIEND6reloadEv");
void GAUGE_FRIEND_reload(u8* self) {
    func_001581f8(self);
    func_00138c10(self + 916, func_00154ee8(self));
}
}

// ==== from src/anon/batch_w77.cpp
namespace src24 {
u8* func_0013d7f0(void) asm("func_0013d7f0");
s32 func_0013dda0(s32) asm("func_0013dda0");
void func_00138c10(u8*, s32) asm("func_00138c10");
u32 func_00154ee8(u8*) asm("func_00154ee8");
u32 func_0023aa98(u8*) asm("func_0023aa98");
void func_00138c40(u8*, s32, u32) asm("func_00138c40");
void func_00139598(u8*) asm("func_00139598");
void func_001395a8(u8*) asm("func_001395a8");
s32 func_00155830(u32, f32*, f32*, f32*) asm("func_00155830");
void func_00239f18(u8*, f32) asm("func_00239f18");
void func_00138d30(u8*, f32) asm("func_00138d30");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");

}

// 155568
namespace src24 {
void func_00155568(u8* p) asm("func_00155568");
void func_00155568(u8* p)
{
    if (!p[32]) return;
    s32 s = *(s32*)(p + 48);
    if (s != 1) return;
    u8* g = func_0013d7f0();
    if (!g[5536]) return;
    g[5536] = 0;
    if (!func_0013dda0(1)) {
        if (p[5537]) return;
        u8* q = p + 916;
        func_00138c10(q, 73);
        *(u32*)(q + 392) = func_00154ee8(p);
        func_0023aa98(p + 940);
        func_00138c40(q, 0, 0);
        p[5537] = s;
    } else {
        if (p[5537] != s) return;
        u8* q = p + 916;
        func_00138c10(q, 74);
        *(u32*)(q + 392) = func_00154ee8(p);
        func_00138c40(q, 0, func_0023aa98(p + 940));
        p[5537] = 0;
    }
}
}

// ==== from src/anon/batch_w38.cpp
namespace src25 {
f32 func_00166d38(void*) asm("func_00166d38");
f32 func_00166d10(void*, u32) asm("func_00166d10");
void func_00154cd0(void*, s32, f32) asm("func_00154cd0");

struct In155658 { u8 pad[4]; u32 f4; };

struct Ob155658 { u8 pad[1164]; In155658* f1164; };

struct P155658 { u8 pad[36]; void* f36; u8 pad2[12]; Ob155658* f52; };

}

// 155658
namespace src25 {
void func_00155658(P155658* p) asm("func_00155658");
void func_00155658(P155658* p) {
    f32 a = func_00166d38(p->f52);
    Ob155658* o = p->f52;
    void* q = p->f36;
    f32 b = func_00166d10(q, o->f1164->f4);
    func_00154cd0(p, 1, b);
    func_00154cd0(p, 2, a);
}
}

// ==== from src/anon/batch_w1669.cpp
namespace src26 {
f32 func_00166d70(u32) asm("func_00166d70");
void func_00154de8(u8*, f32) asm("func_00154de8");

}

// 1556c0
namespace src26 {
void func_001556c0(u8* p) asm("func_001556c0");
void func_001556c0(u8* p) {
    func_00154de8(p, func_00166d70(*(u32*)(p + 0x34)));
}
}

// 1556f0
namespace src0 {
void func_001556f0(u32 a0) asm("func_001556f0");
void func_001556f0(u32 a0) {
    u32 s0 = a0;
    func_00158300(s0);
    if (*(u32*)(s0 + 52) == 0) {
        return;
    }
    if ((*(u32*)(s0 + 12) & 0x100) != 0) {
        return;
    }
    func_001554c0(s0);
    func_00155568(s0);
    func_00155658(s0);
    return func_001556c0(s0);
}
}

// ==== from src/anon/batch_w78.cpp
namespace src27 {
f32 func_0017ce10(f32) asm("func_0017ce10");
u32 func_00155d58(u32, s32) asm("func_00155d58");
void func_00138c10(u32, u32) asm("func_00138c10");
void func_00154408(u32, u32) asm("func_00154408");
s32 func_001581d0(u32) asm("func_001581d0");
s32 func_002ba358(void) asm("func_002ba358");
void func_002ba390(void) asm("func_002ba390");
extern f32 D_004f3588 asm("D_004f3588");
s32 func_00155758(s32 n, f32* a, s32* b, s32* c, s32* d, f32* ang) asm("func_00155758");


void wtarget_001575c0(u8* p) asm("_Z16wtarget_001575c0jjjj");
}

// 155758
namespace src27 {
s32 func_00155758(s32 n, f32* a, s32* b, s32* c, s32* d, f32* ang) asm("func_00155758");
s32 func_00155758(s32 n, f32* a, s32* b, s32* c, s32* d, f32* ang) {
    if (n >= 60) return 1;
    *a = 0.0f;
    *ang = (f32)n * D_004f3588;
    *ang = func_0017ce10(*ang);
    if (n < 20) { *c = 64; *d = 100; *b = -50; }
    else if (n < 40) { *c = 64; *d = 50; *b = 0; }
    else { *c = 0; *d = 0; *b = 50; }
    return 0;
}
}

// ==== from src/anon/batch_w64.cpp
namespace src28 {
f32 func_0017ce10(f32) asm("func_0017ce10");
s32 func_00155830(s32 a0, f32* a1, f32* a2, f32* a3) asm("func_00155830");
void func_00239f18(u8*) asm("func_00239f18");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");

}

// 155830
namespace src28 {
s32 func_00155830(s32 a0, f32* a1, f32* a2, f32* a3) asm("func_00155830");
s32 func_00155830(s32 a0, f32* a1, f32* a2, f32* a3) {
    if (a0 < 60) return 1;
    f32 t = (f32)(a0 - 60) * 3.0f;
    *a2 = t;
    *a1 = t / 100.0f;
    *a3 = -4.71238852f;
    *a3 = func_0017ce10(-4.71238852f);
    return 0;
}
}

// ==== from src/anon/batch_w96.cpp
namespace src29 {
void func_00139598(u32) asm("func_00139598");
s32 func_00155758(u32, s32*, s32*, s32*, s32*, f32*) asm("func_00155758");
s32 func_00139d78(u8*) asm("func_00139d78");
void func_0013edd0(u32, f32) asm("func_0013edd0");
void func_0014b1e0(u32, s16, s16) asm("func_0014b1e0");
void func_0014b208(u32, u32, u32) asm("func_0014b208");
void func_001395a8(u32) asm("func_001395a8");
void func_00138d30(u32, f32) asm("func_00138d30");

}

// 1558b8
namespace src29 {
void func_001558b8(u32 self, u32 a1, s32 idx) asm("func_001558b8");
void func_001558b8(u32 self, u32 a1, s32 idx) {  // entry592_process
    u32 e = self + idx * 592;
    u32 obj = e + 13232;
    u32 s7 = e + 13552;
    s32 x, y, w, h;
    f32 f;
    func_00139598(obj);
    if (func_00155758(a1, &x, &y, &w, &h, &f) == 0) {
        f32 scale = f;
        s32 sx, sy, sw, sh;
        func_00139d78((u8*)obj);
        func_0013edd0(e + 13264, scale);
        sx = x;
        sy = y;
        sw = w;
        sh = h;
        func_00139d78((u8*)obj);
        func_0014b1e0(s7, sx, sy);
        func_0014b208(s7, (u16)sw, (u16)sh);
        func_001395a8(obj);
        if (idx == 1) {
            func_00138d30(self + 9588, -f);
        }
    }
}
}

// 1559e8
namespace src24 {
void func_001559e8(u8* p, u32 a, s32 idx) asm("func_001559e8");
void func_001559e8(u8* p, u32 a, s32 idx)
{
    u8* e = p + idx * 412;
    f32 x, y, z;
    func_00139598(e + 6704);
    if (func_00155830(a, &x, &y, &z)) return;
    func_00239f18(e + 6728, x);  // obj_set_float312_and_flags
    func_001395a8(e + 6704);
    if (idx == 4) {
        func_00138d30(p + 9588, z);
        func_00138c68(p + 9588, (s32)-y, 0);
    }
}
}

// 155ab0
namespace src2 {
void func_00155ab0(u8* p, s32 v, s32 i) asm("func_00155ab0");
void func_00155ab0(u8* p, s32 v, s32 i)
{
    f32 f = (f32)v;
    func_00239f18(p + i * 412 + 6728, f / 100.0f);  // obj_set_float312_and_flags
    if (i == 9) func_00138c68(p + 11236, (s32)-f, 0);
}
}

// 155b58
namespace src28 {
void func_00155b58(u8* p, s32 idx, f32 f) asm("func_00155b58");
void func_00155b58(u8* p, s32 idx, f32 f) {
    func_00239f18(p + idx * 412 + 6728);  // obj_set_float312_and_flags
    if (idx == 9) func_00138c68(p + 11236, -(s32)(f * 100.0f), 0);
}
}

// ==== from src/anon/batch_w1792.cpp
namespace src30 {
extern s8 D_004f3590 asm("D_004f3590");
extern f32 D_004f3598 asm("D_004f3598");
f32 func_0017ce10(f32) asm("func_0017ce10");

u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");void func_0013edd0(u8*, f32) asm("func_0013edd0");
void func_0014b1e0(u8*, s32, s32) asm("func_0014b1e0");

}

// An int constant that sits here in .rodata; no code in this range loads it.
extern "C" const s32 D_0036b29c = 100;

// 155bf0
namespace src30 {
void func_00155bf0(u8* p, s32 a) asm("func_00155bf0");
void func_00155bf0(u8* p, s32 a)
{
    if (D_004f3590 == 0) {
        D_004f3590 = 1;
        D_004f3598 = 0.00401425688f;
    }
    f32 x;
    if (a == 100) x = 200.0f * D_004f3598;
    else x = (f32)a * D_004f3598;
    x = func_0017ce10(x);
    u_call4_00139d78(p + 12896);
    func_0013edd0(p + 12928, x);
    u_call4_00139d78(p + 12896);
    func_0014b1e0(p + 12928, 50, 100);
}
}

// 155cb0
namespace src2 {
void func_00155cb0(u8* p, s32 a, s32 b) asm("func_00155cb0");
void func_00155cb0(u8* p, s32 a, s32 b)
{
    f32 x = (f32)a * (23.0f / (f32)b * 0.01745329238474369f);
    x = func_0017ce10(x);
    u_call4_00139d78(p + 12896);
    func_0013edd0(p + 12928, x);
    u_call4_00139d78(p + 12896);
    func_0014b1e0(p + 12928, 50, 100);
}
}

// ==== from src/anon/tiny_auto80_solver.cpp
namespace src31 {
extern u8 D_0034a878 asm("D_0034a878");

}

// 155d58
namespace src31 {
u32 func_00155d58(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00155d58");
u32 func_00155d58(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // table_word_indexed_by_3
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r14 = *(volatile u32*)((u32)r4 + (s32)(24));
    r15 = (u32)(r5 << 1);
    r15 = (u32)(r15 + r5);
    r15 = (u32)(r15 + r14);
    r14 = (u32)&D_0034a878;
    r15 = (u32)(r15 << 2);    r15 = (u32)(r15 + r14);
    r2 = *(volatile u32*)((u32)r15 + (s32)(0));
    return r2;
}
}

// 155d80
namespace src0 {
u32 func_00155d80(u32 a0) asm("func_00155d80");
u32 func_00155d80(u32 a0) {
    u32 s0 = a0;
    u32 sp0;
    u32 sp4;
    u32 v0;
    u32 p;
    u32 cur;
    u32 old;
    if (func_00156058(s0) != 0) {  // state_code_is_2
        sp0 = 0;
        goto L_common;
    }
    if (func_00156080(s0) == 0) {  // state_code_is_3
        goto L_path2;
    }
    sp0 = 0;

L_common:
    sp4 = 0;
    v0 = func_001560a8(s0, (u32)&sp0, (u32)&sp4);
    old = (u32)*(u8*)(s0 + 15605);
    if (old != v0) {
        if (old < v0) {
            *(u8*)(s0 + 15608) = 1;
        }
        *(u8*)(s0 + 15605) = (u8)v0;
        *(u8*)(s0 + 15607) = 1;
    }
    goto L_end;

L_path2:
    p = *(u32*)(s0 + 52);
    if (p == 0) {
        v0 = 0;
        goto L_end;
    }
    v0 = (u32)*(u8*)(*(u32*)(p + 1164) + 433);
    cur = (u32)*(u8*)(s0 + 15604);
    if (cur != v0) {
        if (cur < v0) {
            *(u8*)(s0 + 15608) = 1;
        }
        *(u8*)(s0 + 15604) = (u8)v0;
        *(u8*)(s0 + 15606) = 1;
    }

L_end:
    return v0;
}
}

// 155e30
namespace src10 {
s32 func_00155e30(u8* p) asm("func_00155e30");
s32 func_00155e30(u8* p) {
    u8* o = *(u8**)(p + 52);
    if (o != 0) {
        switch (*(*(u8**)(o + 1164) + 431)) {
        case 2:
            func_00155d80_r(p);
            return D_0034a8f0[func_00155d80_r(p)];
        case 0: case 1: case 4:
            break;
        case 3:
            func_00155d80_r(p);
            return D_0034a8a0[func_00155d80_r(p)];
        }
    }
    func_00155d80_r(p);
    return D_0034a8c8[func_00155d80_r(p)];
}
}

// 155ee8
namespace src10 {
s32 func_00155ee8(u8* p) asm("func_00155ee8");
s32 func_00155ee8(u8* p) {
    u8* o = *(u8**)(p + 52);
    if (!o) goto def;
    switch ((*(u8**)(o + 1164))[431]) {
    case 4: return 18;
    case 0: case 1:
    def:
        return 21;
    case 2: return 50;
    case 3: return 140;
    }
    return 21;
}
}

// ==== from src/anon/batch_w1766.cpp
namespace src32 {
s32 func_001a1de0(void*) asm("func_001a1de0");

}

// 155f40
namespace src32 {
s32 func_00155f40(u8* p) asm("func_00155f40");
s32 func_00155f40(u8* p) {
    u8* q = *(u8**)(p + 0x34);
    s32 r;
    if (q) {
        switch (*(*(u8**)(q + 0x48c) + 0x1af)) {
        case 4: r = 0x13; break;
        default:
        case 0: case 1:
            if (func_001a1de0(*(void**)(q + 0x48c))) { r = 0x1a; break; }
            goto none;
        case 2: r = 0x33; break;
        case 3: r = 0x8d; break;
        }
    } else {
    none:
        r = 0x17;
    }
    return r;
}
}

// 155fc0
namespace src10 {
s32 func_00155fc0(u8* p) asm("func_00155fc0");
s32 func_00155fc0(u8* p) {
    u8* o = *(u8**)(p + 52);
    if (o) {
        switch ((*(u8**)(o + 1164))[431]) {
        case 2: return 49;
        case 3: return 139;
        case 0: case 1: case 4: break;
        }
    }
    return 25;
}
}

// 156010
namespace src6 {
u32 func_00156010(u32 a0) asm("func_00156010");
u32 func_00156010(u32 a0) {
    u32 t7 = *(volatile u32*)((u32)a0 + (s32)(52));
    u32 v0 = 0u;
    if (t7 != 0u) {
        u32 p = *(volatile u32*)((u32)t7 + (s32)(1164));
        u32 t6 = (u32)(*(u8*)((u32)p + (s32)(431)));
        v0 = (u32)(t6 < 1u);
    }
    return v0;
}
}

// 156030
namespace src6 {
u32 func_00156030(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00156030");
u32 func_00156030(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r14 = *(volatile u32*)((u32)r4 + (s32)(52));
    r2 = 0u;
    if (r14 != 0u) {
        r14 = *(volatile u32*)((u32)r14 + (s32)(1164));
        r15 = (u32)(*(u8*)((u32)r14 + (s32)(431)));
        r15 = (u32)(r15 ^ 0x0004u);
        r2 = ((u32)r15 < 0x00000001u);
    }
    return r2;
}
}

// 156058
namespace src6 {
u32 func_00156058(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00156058");
u32 func_00156058(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // state_code_is_2
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r14 = *(volatile u32*)((u32)r4 + (s32)(52));
    r2 = 0u;
    if (r14 != 0u) {
        r14 = *(volatile u32*)((u32)r14 + (s32)(1164));
        r15 = (u32)(*(u8*)((u32)r14 + (s32)(431)));
        r15 = (u32)(r15 ^ 0x0002u);
        r2 = ((u32)r15 < 0x00000001u);
    }
    return r2;
}
}

// 156080
namespace src6 {
u32 func_00156080(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("func_00156080");
u32 func_00156080(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {  // state_code_is_3
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r14, r15;
    r14 = *(volatile u32*)((u32)r4 + (s32)(52));
    r2 = 0u;
    if (r14 != 0u) {
        r14 = *(volatile u32*)((u32)r14 + (s32)(1164));
        r15 = (u32)(*(u8*)((u32)r14 + (s32)(431)));
        r15 = (u32)(r15 ^ 0x0003u);
        r2 = ((u32)r15 < 0x00000001u);
    }
    return r2;
}
}

// ==== from src/anon/batch_w53.cpp
namespace src33 {

}

// 1560a8
namespace src33 {
u8 func_001560a8(u8* o, s32* outA, s32* outB) asm("func_001560a8");
u8 func_001560a8(u8* o, s32* outA, s32* outB) {
    u8* x = *(u8**)(*(u8**)(o + 52) + 1164);
    u8 n = x[435];
    s32 per = (s32)(*(f32*)(x + 440) / n);
    s32 cur = (s32)*(f32*)(x + 436);
    *outB = per;
    if (per == 0) {
        *outA = 0;
        return 0;
    }
    s32 q = cur / per;
    if (q == n) {
        *outA = per;
        q--;
    } else {
        *outA = cur % per;
    }
    return q;
}
}

// 156130
namespace src20 {
void func_00156130(W1632Panel* self, u32 tex, u32 img, u32 grp) asm("func_00156130");
void func_00156130(W1632Panel* self, u32 tex, u32 img, u32 grp) {
    s32 i;
    s32 x, y;
    W1632Sprite2* head;
    W1632Bar* bar;
    func_00158050(head = &self->spr[0], 7000, tex, img, func_00155ee8(self), 0, grp);
    bar = &self->bar;
    func_0013dfb8(bar, 7000, grp);
    func_00158050(&self->spr[1], 7000, tex, img, func_00155fc0(self), 5000, grp);
    func_00158050(&self->spr[2], 7000, tex, img, func_00155e30(self), 0, grp);
    func_001386e0(&self->icon, 7010, tex, img, 20, grp);
    func_00139d78(bar);
    func_0014b200(&bar->r, 6000);
    for (i = 0; i < 3; i++) {
        W1632_link2(&self->spr[i], &self->frame);
        func_001395e8(&self->spr[i]);
        func_00139610(&self->spr[i]);
    }
    W1632_link2(&self->spr[1], head);
    W1632_link2(&self->spr[2], head);
    func_00139d78(bar);
    bar->owner = head;
    W1632_link(&self->icon, head);
    func_00139598(&self->icon);
    x = func_0023aa18(&self->spr[0].seq);
    y = func_0023aa38(&self->spr[0].seq);
    func_00138c68(&self->spr[2], x, y);
    head->f392 = func_00155f40(self);
    if (func_00156030(self)) {
        func_00138c10(head, 18);
        head->f392 = func_00155f40(self);
    }
    func_00156408(self);
}
}

// 156408
namespace src0 {
void func_00156408(u32 a0) asm("func_00156408");
void func_00156408(u32 a0) {
    u32 s0 = a0;
    s32 s1;

    if (func_00156010(s0) != 0) {
        s1 = 12;
        s0 = s0 + 11648;
        do {
            func_00139598(s0);
            s1 = s1 + 1;
            if (s1 < 15) {
                s0 = s0 + 412;
            } else {
                break;
            }
        } while (1);
        return;
    }

    if (func_00156030(s0) == 0) {
        goto L_after_56030;
    }
    s0 = s0 + 12060;
    {
        s1 = 13;
        do {
            func_00139598(s0);
            s1 = s1 + 1;
            if (s1 < 15) {
                s0 = s0 + 412;
            } else {
                break;
            }
        } while (1);
        return;
    }

L_after_56030:
    s0 = s0 + 12060;
    s1 = 1;
    do {
        func_001395a8(s0);
        s1 = s1 - 1;
        if (s1 >= 0) {
            s0 = s0 + 412;
        } else {
            break;
        }
    } while (1);
}
}

// 1564b0
namespace src0 {
u32 func_001564b0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001564b0");
u32 func_001564b0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 s16 = a0 + 1324;
    u32 s17 = a0;

    func_001386e0(s16, 7005, a1, a2, 27, a3);
    *(u32*)(s16 + 396) = s17 + 6704;
    func_001396b0(s16);

    if (*(u32*)(s16 + 396) != 0) {
        *(u32*)(s16 + 400) = 0;
        func_001396b0(s16);
        if (*(u32*)(s16 + 400) != 0) {
            func_0031a260(s16, 0);
        }
    }

    return func_001565a8(s17);
}
}

// 156540
namespace src0 {
u32 func_00156540(u32 a0) asm("func_00156540");
u32 func_00156540(u32 a0) {
    u32 s0 = a0;
    u32 s1;
    func_001565a8(s0);
    s1 = s0 + 1324;
    func_00138c10(s1, 27);
    u32 v0 = func_00155ee8(s0);  // state_dispatch_0_4
    if (v0 == 21) {
        return func_001395a8(s1);
    }
    return v0;
}
}

// 1565a8
namespace src22 {
u32 func_001565a8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001565a8");
u32 func_001565a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return dk_Obj2D_localHide(((u32)(a0) + 1324u), a1, a2, a3);
}
}

// ==== from src/anon/batch_w1633.cpp
namespace src34 {

struct W1633Sprite {
    u8 pad0[0x188];
    s32 id;             // 0x188
    W1633Sprite* parent;// 0x18c
    s32 flag;           // 0x190
    u8 pad1[8];
};

struct W1633Gauge {
    u8 pad0[0x20];
    u8 barA[0x120];     // 0x20
    u8 barB[0x100];     // 0x140
    W1633Sprite* parent;// 0x240
    u8 pad1[0xc];
};

struct W1633Owner2 { u8 pad[0x250]; u32 flags; };

struct W1633Owner { u8 pad[0x48c]; W1633Owner2* sub; };

struct W1633Hud {
    u8 pad0[0x18];
    u32 f18;                    // 0x18
    u8 pad1[0x34 - 0x1c];
    W1633Owner* owner;          // 0x34
    u8 pad2[8];
    W1633Sprite header;         // 0x40
    u8 pad3[0x1a30 - 0x1dc];
    W1633Sprite spr[12];        // 0x1a30
    u8 pad4[0x33b0 - 0x2d80];
    W1633Gauge gauge[4];        // 0x33b0
    u8 pad5[0x3cf0 - 0x3cf0];
    s32 f3cf0;                  // 0x3cf0
    s8 b3cf4, b3cf5, b3cf6, b3cf7, b3cf8, b3cf9, b3cfa, b3cfb;
};
void func_0013e0f8(W1633Gauge*, u32, u32, u32) asm("func_0013e0f8");
void func_00158050(W1633Sprite*, u32, u32, u32, u32, u32, u32) asm("func_00158050");
void func_00139d78(void*) asm("func_00139d78");
void func_0014b200(void*, u32) asm("func_0014b200");
void func_00139598(void*) asm("func_00139598");

}

// 1565c0
namespace src34 {
void func_001565c0(W1633Hud* self, u32 a1, u32 a2, u32 a3) asm("func_001565c0");
void func_001565c0(W1633Hud* self, u32 a1, u32 a2, u32 a3) {
    func_0013e0f8(&self->gauge[1], 7000, 1, a3);
    func_00158050(&self->spr[1], 7000, a1, a2, 121, 100, a3);
    func_0013e0f8(&self->gauge[2], 7000, 1, a3);
    func_00158050(&self->spr[2], 7000, a1, a2, 121, 500, a3);
    func_0013e0f8(&self->gauge[3], 7000, 1, a3);
    func_00158050(&self->spr[3], 7000, a1, a2, 128, 1000, a3);
    func_00158050(&self->spr[4], 7000, a1, a2, 124, 0, a3);
    func_00158050(&self->spr[5], 7000, a1, a2, 127, 0, a3);
    func_00158050(&self->spr[6], 7000, a1, a2, 129, 0, a3);
    func_00158050(&self->spr[7], 7000, a1, a2, 123, 0, a3);
    func_00139d78(&self->gauge[1]);
    func_0014b200(self->gauge[1].barA, 200);
    func_0014b200(self->gauge[1].barB, 200);
    func_00139d78(&self->gauge[2]);
    func_0014b200(self->gauge[2].barA, 600);
    func_0014b200(self->gauge[2].barB, 600);
    func_00139d78(&self->gauge[3]);
    func_0014b200(self->gauge[3].barA, 2000);
    func_0014b200(self->gauge[3].barB, 2000);
    if (self->owner != 0 && (self->owner->sub->flags & 2)) {
        func_00139598(&self->gauge[0]);
        func_00139598(&self->gauge[1]);
        func_00139598(&self->spr[1]);
        func_00139598(&self->gauge[2]);
        func_00139598(&self->spr[2]);
        func_00139598(&self->gauge[3]);
        func_00139598(&self->spr[3]);
        func_00139598(&self->spr[4]);
        func_00139598(&self->spr[5]);
        func_00139598(&self->spr[6]);
        func_00139598(&self->spr[7]);
    }
}
}

// 156880
namespace src10 {
void func_00156880(u8* p, u32 a1, u32 a2, u32 a3) asm("func_00156880");
void func_00156880(u8* p, u32 a1, u32 a2, u32 a3)
{
    func_00158050(p + 10000, 7000, a1, a2, 116, 0, a3);
    func_00158050(p + 10412, 7000, a1, a2, 119, 0, a3);
    func_00158050(p + 10824, 7000, a1, a2, 115, 0, a3);
    func_00158050(p + 11236, 7000, a1, a2, 120, 0, a3);
    u8* o = *(u8**)(p + 52);
    if (o && (*(u32*)(*(u8**)(o + 1164) + 592) & 4)) {
        func_00139598(p + 10000);
        func_00139598(p + 10412);
        func_00139598(p + 10824);
        func_00139598(p + 11236);
    }
}
}

// ==== from src/anon/perm_001569d8.cpp
namespace src35 {



typedef struct W1633Gauge W1633Gauge;

typedef struct W1633Hud W1633Hud;

typedef struct W1633Owner W1633Owner;

typedef struct W1633Owner2 W1633Owner2;

typedef struct W1633Sprite W1633Sprite;

typedef struct W1633Sprite W1633Sprite;

struct W1633Sprite
{
  u8 pad0[0x188];
  s32 id;
  W1633Sprite *parent;
  s32 flag;
  u8 pad1[8];
};

typedef struct W1633Gauge W1633Gauge;

struct W1633Gauge
{
  u8 pad0[0x20];
  u8 barA[0x120];
  u8 barB[0x100];
  W1633Sprite *parent;
  u8 pad1[0xc];
};

typedef struct W1633Owner2 W1633Owner2;

struct W1633Owner2
{
  u8 pad[0x250];
  u32 flags;
};

typedef struct W1633Owner W1633Owner;

struct W1633Owner
{
  u8 pad[0x48c];
  W1633Owner2 *sub;
};

typedef struct W1633Hud W1633Hud;

struct W1633Hud
{
  u8 pad0[0x18];
  u32 f18;
  u8 pad1[0x34 - 0x1c];
  W1633Owner *owner;
  u8 pad2[8];
  W1633Sprite header;
  u8 pad3[0x1a30 - 0x1dc];
  W1633Sprite spr[12];
  u8 pad4[0x33b0 - 0x2d80];
  W1633Gauge gauge[4];
  u8 pad5[0x3cf0 - 0x3cf0];
  s32 f3cf0;
  s8 b3cf4;
  s8 b3cf5;
  s8 b3cf6;
  s8 b3cf7;
  s8 b3cf8;
  s8 b3cf9;
  s8 b3cfa;
  s8 b3cfb;
};
void func_00158138(W1633Hud *, W1633Owner *, u32, u32) asm("func_00158138");
u32 func_0013a7e8(u32) asm("func_0013a7e8");
u32 func_0013d7e0(void) asm("func_0013d7e0");
u32 func_00158290(W1633Hud *) asm("func_00158290");
volatile unsigned char func_00158050(W1633Sprite *, u32, u32, u32, u32, u32, u32) asm("func_00158050");
void func_0013e0f8(W1633Gauge *, u32, u32, u32) asm("func_0013e0f8");
void func_00139d78(void *) asm("func_00139d78");
void func_0014b200(void *, u32) asm("func_0014b200");
void func_001581f8(W1633Hud *) asm("func_001581f8");
void func_001565c0(W1633Hud *, u32, u32, u32) asm("func_001565c0");
void func_00153fa0(W1633Sprite *, u32, u32, W1633Owner *, u32, u32) asm("func_00153fa0");
void func_00156880(W1633Hud *, u32, u32, u32) asm("func_00156880");
void func_00156130(W1633Hud *, u32, u32, u32) asm("func_00156130");
void func_001564b0(W1633Hud *, u32, u32, u32) asm("func_001564b0");
void func_001582a8(W1633Hud *) asm("func_001582a8");
s32 func_00155d58(W1633Hud *, u32) asm("func_00155d58");
void func_001396b0(W1633Sprite *) asm("func_001396b0");
void func_0031a260(W1633Sprite *, u32) asm("func_0031a260");
void func_001395e8(W1633Sprite *) asm("func_001395e8");
void func_00139610(W1633Sprite *) asm("func_00139610");

inline static void W1633_setParent(W1633Sprite *obj, W1633Sprite *parent)
{
  obj->parent = parent;
  func_001396b0(obj);
  if (obj->parent != 0)
  {
    obj->flag = 0;
    func_001396b0(obj);
    if (obj->flag != 0)
    {
      func_0031a260(obj, 0);
    }
  }
}
}

// 1569d8
namespace src35 {
void func_001569d8(W1633Hud *self, W1633Owner *owner) asm("func_001569d8");
void func_001569d8(W1633Hud *self, W1633Owner *owner)
{
  u32 a;
  u32 b;
  u32 c;
  s32 j;
  W1633Sprite *top = &self->spr[0];
  W1633Sprite *sub;
  W1633Gauge *g;
  func_00158138(self, owner, 0, 0);
  a = func_0013a7e8(1);
  b = func_0013d7e0();
  c = func_00158290(self);
  self->b3cf6 = 0;
  self->b3cf4 = -1;
  self->b3cf5 = -1;
  self->b3cf7 = 0;
  self->b3cf8 = 0;
  self->b3cf9 = 0;
  self->f3cf0 = 0;
  self->b3cfa = 0;
  self->b3cfb = 0;
  func_00158050(top, 7000, a, b, 136, 0, c);
  func_0013e0f8(&self->gauge[0], 7000, 0, c);
  func_00139d78(&self->gauge[0]);
  func_0014b200(self->gauge[0].barA, 0);
  func_0014b200(self->gauge[0].barB, 0);
  func_001581f8(self);
  func_001565c0(self, a, b, c);
  func_00153fa0(&self->header, 7000, 0, self->owner, self->f18, c);
  func_00156880(self, a, b, c);
  for (s32 i = 0; i < 12; i++)
  {
    W1633_setParent(&self->spr[i], top);
    func_001395e8(&self->spr[i]);
    func_00139610(&self->spr[i]);
  }

  for (j = 0; j < 4; j++)
  {
    g = &self->gauge[j];
    func_00139d78(g);
    g->parent = top;
  }

  W1633_setParent(&self->header, top);
  sub = &self->spr[8];
  W1633_setParent(&self->spr[9], sub);
  W1633_setParent(&self->spr[10], sub);
  W1633_setParent(&self->spr[11], sub);
  W1633_setParent(top, 0);
  top->id = func_00155d58(self, 0);
  sub->id = 117;
  func_00156130(self, a, b, c);
  func_001564b0(self, a, b, c);
  func_001582a8(self);
}
}

// ==== from src/anon/batch_w94.cpp
namespace src36 {
u32 func_00158290(u8*) asm("func_00158290");
u32 func_0013a7e8(s32) asm("func_0013a7e8");
u32 func_0013d7e0(void) asm("func_0013d7e0");
u32 func_00155f40(u8*) asm("func_00155f40");
u32 func_00155fc0(u8*) asm("func_00155fc0");
void func_00138c10(u8*, u32) asm("func_00138c10");
s32 func_00139c18(u8*) asm("func_00139c18");
void func_001386e0(u8*, s32, u32, u32, s32, u32) asm("func_001386e0");
void func_001396b0(u8*) asm("func_001396b0");
void func_0031a260(u8*, s32) asm("func_0031a260");

}

// 156d20
namespace src36 {
void func_00156d20(u8* p) asm("func_00156d20");
void func_00156d20(u8* p) {
    u8* q = p + 11648;
    u32 a = func_00158290(p);
    u32 b = func_0013a7e8(1);
    u32 c = func_0013d7e0();
    func_00138c10(q, func_00155f40(p));
    func_00138c10(p + 12060, func_00155fc0(p));
    p[15606] = 1;
    if (p[15611] == 1) {
        u8* e = p + func_00139c18(p + 4180) * 408 + 4180;
        func_001386e0(e, 7000, b, c, 53, a);
        *(u8**)(e + 396) = q;
        func_001396b0(e);
        if (*(u32*)(e + 396)) {
            *(u32*)(e + 400) = 0;
            func_001396b0(e);
            if (*(u32*)(e + 400)) func_0031a260(e, 0);
        }
    }
}
}

// ==== from src/anon/batch_w318.cpp
namespace src37 {

struct K318 { u8 pad[388]; s32 f388; };

struct L318 { u8 pad[396]; void* f396; s32 f400; u8 pad2[4]; };
s32 func_0013dda0(int) asm("func_0013dda0");
s32 func_00158290(void*) asm("func_00158290");
s32 func_0013a7e8(int) asm("func_0013a7e8");
s32 func_0013d7e0(void) asm("func_0013d7e0");
int func_00156030(void*) asm("func_00156030");
s32 func_00155f40(void*) asm("func_00155f40");
s32 func_00155ee8(void*) asm("func_00155ee8");
s32 func_00155fc0(void*) asm("func_00155fc0");
int func_00139c18(void*) asm("func_00139c18");
void func_001386e0(void*, int, s32, s32, int, s32) asm("func_001386e0");
void func_001396b0(void*) asm("func_001396b0");
void func_0031a260(void*, int) asm("func_0031a260");
int func_001396c0(void*) asm("func_001396c0");
void func_00139570(void*) asm("func_00139570");
int func_00156058(void*) asm("func_00156058");
int func_00156080(void*) asm("func_00156080");
void func_00138c10(void*, s32) asm("func_00138c10");
void func_00156d20(void*) asm("func_00156d20");
void func_00156408(void*) asm("func_00156408");
void func_001581f8(void*) asm("func_001581f8");
void func_001542c8(void*, s32, s32) asm("func_001542c8");
void func_001575c0(void*) asm("func_001575c0");

}

// 156e48
namespace src37 {
void func_00156e48(u8* p) asm("func_00156e48");
void func_00156e48(u8* p) {
    L318* t;
    s32 a = func_0013dda0(0);
    s32 b = func_00158290(p);
    s32 c = func_0013a7e8(1);
    s32 d = func_0013d7e0();
    K318* k;
    if (func_00156030(p)) goto out;
    k = (K318*)(p + 11648);
    {
    s32 v1 = k->f388;
    if (v1 == func_00155f40(p)) goto out;
    }
    {
    s32 v2 = k->f388;
    if (v2 == func_00155ee8(p)) goto out;
    }
    {
        if (p[15611] == 1) {
            int i = func_00139c18(p + 3364);
            void* q = p + 6704;
            t = &((L318*)(p + 3364))[i];
            func_001386e0(t, 7000, c, d, 130, b);
            t->f396 = q;
            func_001396b0(t);
            if (t->f396) {
                t->f400 = 0;
                func_001396b0(t);
                if (t->f400) func_0031a260(t, 0);
            }
            if (func_001396c0(q)) func_00139570(&((L318*)(p + 3364))[i]);
        }
        if (func_00156058(p) || func_00156080(p)) {  // state_code_is_2
            func_00138c10(k, func_00155f40(p));
            func_00138c10(p + 12060, func_00155fc0(p));
            p[15607] = 1;
        } else {
            func_00156d20(p);
        }
    }
out:
    func_00156408(p);
    *(s32*)(p + 52) = a;
    func_001581f8(p);
    func_001542c8(p + 64, a, *(s32*)(p + 24));
    if (*(s32*)(p + 52)) func_001575c0(p);
}
}

// 157068
namespace src13 {
void GAUGE_PLAYER_update(u8*) asm("_ZN2dk12GAUGE_PLAYER6updateEv");
void GAUGE_PLAYER_update(u8* self) {
    func_00138c10(self + 11648, func_00155f40(self));
    func_00156408(self);
}
}

// ==== from src/anon/auto200_999.cpp
namespace src38 {

}

// 1570a0
namespace src38 {
u32 func_001570a0(u8 *a0) asm("func_001570a0");
u32 func_001570a0(u8 *a0) {
    u32 t4 = *(u32 *)(a0 + 15600);
    u32 v0 = 0;
    if (t4 != 4) {
        u32 p15 = *(u32 *)(a0 + 52);
        u32 p14 = *(u32 *)(p15 + 1164);
        if (*(u8 *)(p14 + 431) == 4) {
            return 1;
        }
        v0 = 0;
    }
    return v0;
}
}

// 1570d0
namespace src6 {
u32 func_001570d0(u8* a0) asm("func_001570d0");
u32 func_001570d0(u8* a0) {
    u32 t4 = *(u32*)(a0 + 15600);
    u32 v0 = 0;
    if (t4 == 4) {
        u32 p15 = *(u32*)(a0 + 52);
        u32 p14 = *(u32*)(p15 + 1164);
        if (*(u8*)(p14 + 431) != t4) {
            return 1;
        }
        v0 = 0;
    }
    return v0;
}
}

// 157100
namespace src6 {
u32 func_00157100(u8* a0) asm("func_00157100");
u32 func_00157100(u8* a0) {
    u32 t4 = *(u32*)(a0 + 15600);
    u32 v0 = 0;
    if (t4 != 3) {
        u32 p15 = *(u32*)(a0 + 52);
        u32 p14 = *(u32*)(p15 + 1164);
        if (*(u8*)(p14 + 431) == 3) {
            return 1;
        }
        v0 = 0;
    }
    return v0;
}
}

// 157130
namespace src6 {
u32 func_00157130(u8* a0) asm("func_00157130");
u32 func_00157130(u8* a0) {
    u32 t4 = *(u32*)(a0 + 15600);
    u32 v0 = 0;
    if (t4 == 3) {
        u32 p15 = *(u32*)(a0 + 52);
        u32 p14 = *(u32*)(p15 + 1164);
        if (*(u8*)(p14 + 431) != t4) {
            return 1;
        }
        v0 = 0;
    }
    return v0;
}
}

// ==== from src/anon/batch_w59.cpp
namespace src39 {
u8* func_0017df58(u32) asm("func_0017df58");
void func_001574a0(u32) asm("func_001574a0");
void func_001024a8(u8*) asm("func_001024a8");

}

// 157160
namespace src39 {
void func_00157160(u8* p) asm("func_00157160");
void func_00157160(u8* p) {
    u8* o = func_0017df58(0);
    if (o && (*(u32*)(o + 1416) & 0x400000)) {
        func_001574a0(*(u32*)(p + 4));
        func_001024a8(p);
    }
}
}

// ==== from src/anon/batch_w92.cpp
namespace src40 {

struct Q157 { u8 pad[396]; void* f396; s32 f400; u32 pad2; };

struct R157 { u32 f0; void* f4; };
R157* func_00102c18(s32, u32, void (*)(void*)) asm("func_00102c18");
void func_00157160(void*) asm("func_00157160");
s32 func_00156030(u8*) asm("func_00156030");
u32 func_00158290(u8*) asm("func_00158290");
u32 func_0013a7e8(s32) asm("func_0013a7e8");
u32 func_0013d7e0(void) asm("func_0013d7e0");
s32 func_00139c18(u8*) asm("func_00139c18");
void func_001386e0(Q157*, s32, u32, u32, s32, u32) asm("func_001386e0");
void func_001396b0(Q157*) asm("func_001396b0");
void func_0031a260(Q157*, s32) asm("func_0031a260");
u32 func_00155f40(u8*) asm("func_00155f40");
u32 func_00155fc0(u8*) asm("func_00155fc0");
void func_00138c10(void*, s32) asm("func_00138c10");

}

// 1571c0
namespace src40 {
void func_001571c0(u8* p) asm("func_001571c0");
void func_001571c0(u8* p) {
    func_00102c18(1, 0x19258, func_00157160)->f4 = p;
    if (func_00156030(p)) return;
    u32 c = func_00158290(p);
    u32 a = func_0013a7e8(1);
    u32 b = func_0013d7e0();
    Q157* q = (Q157*)(p + 3364) + func_00139c18(p + 3364);
    func_001386e0(q, 7000, a, b, 130, c);
    q->f396 = p + 6704;
    func_001396b0(q);
    if (q->f396) {
        q->f400 = 0;
        func_001396b0(q);
        if (q->f400) func_0031a260(q, 0);
    }
    func_00138c10(p + 11648, func_00155f40(p));
    func_00138c10(p + 12060, func_00155fc0(p));
    p[15607] = 1;
}
}

// ==== from src/anon/batch_w117.cpp
namespace src41 {
void func_001396b0(u8*) asm("func_001396b0");
void func_0031a260(u8*, s32) asm("func_0031a260");
void func_00139660(u8*) asm("func_00139660");
void func_00139688(u8*) asm("func_00139688");
u32 func_00158290(u8*) asm("func_00158290");
u32 func_0013a7e8(s32) asm("func_0013a7e8");
u32 func_0013d7e0(void) asm("func_0013d7e0");
s32 func_00139c18(u8*) asm("func_00139c18");
void func_001386e0(u8*, s32, u32, u32, u32, u32) asm("func_001386e0");
void func_00154048(u8*, s32, s32, s32, s32, u32) asm("func_00154048");
u32 func_0017df58(s32) asm("func_0017df58");
s32 func_0016c060(u32, s32*, s32*) asm("func_0016c060");

static inline void settle(u8* m) {
    func_001396b0(m);
    if (*(u32*)(m + 396)) {
        *(u32*)(m + 400) = 0;
        func_001396b0(m);
        if (*(u32*)(m + 400)) func_0031a260(m, 0);
    }
}
void wt_001572e8(u8* p, u32 a, u32 b, u32) asm("_Z16wtarget_001572e8jjjj");
}

// 1572e8
namespace src41 {
void wt_001572e8(u8* p, u32 a, u32 b, u32) asm("_Z16wtarget_001572e8jjjj");
void wt_001572e8(u8* p, u32 a, u32 b, u32) {
    u32 h = func_00158290(p);
    u32 x = func_0013a7e8(1);
    u32 y = func_0013d7e0();
    s32 i = func_00139c18(p + 1732);
    u8* m = p + i * 408 + 1732;
    func_001386e0(m, 7000, x, y, a, h);
    *(u32*)(m + 392) = b;
    *(u8**)(m + 396) = p + 6704;
    settle(m);
    s32 s0, s4;
    s4 = 0;
    s0 = 0;
    if (func_0016c060(func_0017df58(0), &s0, &s4)) {
        s32 j = func_00139c18(p + 5008);
        u8* n = p + j * 848 + 5008;
        func_00154048(n, 13000, s4, s0, 3, h);
        *(u8**)(n + 396) = p + i * 408 + 1732;
        settle(n);
        u8* q = p + j * 848 + 5008;
        func_00139660(q);
        func_00139688(q);
    }
}
}

// 1574a0
namespace src6 {
void func_001574a0(u32 a0) asm("func_001574a0");
void func_001574a0(u32 a0) {
    if (*(u8*)((u32)a0 + (s32)(15610)) != 1u) {
        *(u8*)((u32)a0 + (s32)(15610)) = (u8)1u;
        func_001572e8(a0, 154u, 155u);
        return;
    }
}
}

// 1574d8
namespace src22 {
u32 func_001574d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001574d8");
u32 func_001574d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    *(u8*)((u32)(a0) + 15610u) = (u8)(0x00000000u);
    return func_001572e8(a0, 0x0000009cu, 0xffffffffu, a3);
}
}

// ==== from src/anon/batch_w79.cpp
namespace src42 {
void func_00157990(u32) asm("func_00157990");
void func_00138c10(u32, u32) asm("func_00138c10");
u32 func_00155d58(u32, s32) asm("func_00155d58");
void func_001543a0(u32, s32, u32) asm("func_001543a0");
s32 func_001581a8(u32) asm("func_001581a8");
s32 func_002ba358(void) asm("func_002ba358");
void func_002ba368(void) asm("func_002ba368");

}

// 1574f8
namespace src42 {
void wtarget_001574f8(u32 a, u32 b, u32, u32) asm("_Z16wtarget_001574f8jjjj");
void wtarget_001574f8(u32 a, u32 b, u32, u32) {
    u32 o;
    func_00157990(a);
    o = a + 6704;
    func_00138c10(o, b);
    *(u32*)(o + 392) = func_00155d58(a, 0);
    func_00138c10(a + 7116, func_00155d58(a, 1));
    func_00138c10(a + 8352, func_00155d58(a, 2));
    func_001543a0(a + 64, 1, *(u32*)(a + 24));
    if (func_001581a8(a) != 0 && func_002ba358() == 0) func_002ba368();
}
}

// 1575c0
namespace src27 {
void wtarget_001575c0(u8* p) asm("_Z16wtarget_001575c0jjjj");
void wtarget_001575c0(u8* p) {
    u32 v = **(u32**)(*(u8**)(p + 52) + 1164);
    u8 c = p[15611];
    *(u32*)(p + 40) = v;
    *(u32*)(p + 36) = v;
    if (c == 0) p[15611] = 1;
    else func_00138c10((u32)(p + 6704), func_00155d58((u32)p, 0));
    func_00138c10((u32)(p + 7116), func_00155d58((u32)p, 1));
    func_00138c10((u32)(p + 8352), func_00155d58((u32)p, 2));
    func_00154408((u32)(p + 64), *(u32*)(p + 24));
    if (func_001581d0((u32)p) && func_002ba358()) func_002ba390();
}
}

