#include "../common/types.h"
extern "C" {
struct W2418Seq { u8 pad[344]; };
struct W2418Sprite {
    u8 pad0[24];
    W2418Seq seq;       // 24
    u8 pad1[28];
    void* parent;       // 396
    s32 flag;           // 400
    u8 pad2[4];
};
struct W2418Menu3 {
    u8 pad0[32];
    s32 x, y;               // 32, 36
    u8 pad1[8];
    W2418Sprite root;       // 48
    u8 pad2[40];
    W2418Seq title;         // 496
    W2418Sprite spr[5];     // 840
    union { f32 f; u8 c; } f2880;
    union { u32 u; u8 c; } p2884;
    f32 f2888;
    f32 f2892;
    union { s32 i; u8 c; } f2896;
};
void func_00138650(W2418Sprite*, u32, u32, u32);
void func_001386e0(W2418Sprite*, u32, u32, void*, u32, u32);
s32 func_0013a9d0(void);
void func_002368e8(void*, f32);
void func_002367c8(void*);
void func_001396b0(W2418Sprite*);
void func_0031a260(W2418Sprite*, u32);
void func_00139660(W2418Sprite*);
void func_00139688(W2418Sprite*);
void func_00138c68(W2418Sprite*, s32, s32);
void func_00138c40(W2418Sprite*, s32, s32);
void func_00239988(W2418Seq*, u32, void*);
void func_00239c38(W2418Seq*, s32);
void func_0023acd8(W2418Seq*);
s32 func_0023a950(W2418Seq*);
s32 func_0023a988(W2418Seq*);
s32 func_0023aa18(W2418Seq*);
s32 func_0023aa38(W2418Seq*);
s32 func_0023aa78(W2418Seq*);
void func_0014fc40(W2418Menu3*, u32, s32, u32, u32, s32);
void func_001519f8(W2418Menu3*);
void func_00151bd8(W2418Menu3*);

static inline void W2418_setParent(W2418Sprite* obj, W2418Sprite* parent) {
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

void func_001516b0(W2418Menu3* self, u32 a1, u32 a2, s32 mode, f32* pv, u32 a5, f32 f);  // 0x001516b0: definition moved into src/anon/unit_0014ecb8.cpp
}

extern "C" {

typedef struct W2418Pk { u16 a0; u16 flags; u8 c[4]; u64 f8; void* f10; s32 f14; u8 f18; u32 f1c; u8 pad[16]; } W2418Pk;
typedef struct W2418It { u8 p0[0x24]; u16 f24; u16 f26; s8 c[4]; u8 p2c[0x54 - 0x2c]; f32 f54; u64 f58; } W2418It;
typedef struct W2418Vc { f32 x, y, z, w; u8 p10[16]; } W2418Vc;
typedef struct W2418Q { W2418It* it; W2418Vc* v; s32 n; f32 scale; u8 p10[2]; u8 f12; } W2418Q;
typedef struct W2418T { s32 a; s32 b; s32 c; } W2418T;
typedef struct W2418A2 { u8 p0[0xc]; W2418T* fc; } W2418A2;
typedef struct W2418A1 { u32 p0; s32 f4; u8 p8[4]; u8 fc; u8 p0d[0x94 - 0xd]; f32 f94; f32 f98; } W2418A1;
typedef struct W2418E { u8* data; s32 x; } W2418E;
typedef struct W2418O { u8 p0[0x14]; W2418E* f14; } W2418O;
typedef struct W2418Ent { s16 off; u8 p[6]; } W2418Ent;
typedef struct W2418H { u8 p[16]; W2418Ent e[1]; } W2418H;
extern W2418O* D_01d9e6e4;
extern s32 D_01d9eaa4;
s32 func_0021d048(u8*, W2418Pk*, s32);
s32 func_0020a060(W2418Q*, W2418A1*);
void func_0020aec0(void*, W2418A1*, W2418Q*);
f32 func_0020aec8(void*, f32 (*)[4], W2418A1*, W2418Q*, W2418It*);

void func_0020aff8(u8* a0, W2418A1* a1, W2418A2* a2);  // 0x0020aff8: definition moved into src/anon/unit_0020ad28.cpp
}
