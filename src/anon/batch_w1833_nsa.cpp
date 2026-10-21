#include "../common/types.h"
typedef unsigned int u128 __attribute__((mode(TI)));
extern "C" {
struct W1833GifTag {
    u64 NLOOP:15; u64 EOP:1; u64 pad16:30; u64 PRE:1; u64 PRIM:11; u64 FLG:2; u64 NREG:4;
    u64 REGS0:4; u64 REGS1:4; u64 REGS2:4; u64 REGS3:4; u64 REGS4:4; u64 REGS5:4; u64 REGS6:4; u64 REGS7:4;
    u64 REGS8:4; u64 REGS9:4; u64 REGS10:4; u64 REGS11:4; u64 REGS12:4; u64 REGS13:4; u64 REGS14:4; u64 REGS15:4;
} __attribute__((aligned(16)));
struct W1833AD { u64 data; u64 addr; };
struct W1833Pkt { W1833GifTag tag; W1833AD ad[13]; };

void func_001081c8(W1833Pkt* p) {
    *(u128*)&p->tag = 0;
    p->tag.NLOOP = 13;
    p->tag.EOP = 1;
    p->tag.NREG = 1;
    p->tag.REGS0 = 0xE;
    p->ad[0].addr = 0x3f;
    p->ad[1].addr = 0x4c;
    p->ad[2].addr = 0x4e;
    p->ad[3].addr = 0x34;
    p->ad[4].addr = 0x36;
    p->ad[5].addr = 0x16;
    p->ad[6].addr = 0x14;
    p->ad[7].addr = 6;
    p->ad[8].addr = 0x47;
    p->ad[9].addr = 0x42;
    p->ad[10].addr = 8;
    p->ad[11].addr = 0x3d;
    p->ad[12].addr = 1;
    p->ad[0].data = 0;
    p->ad[1].data = 0x800d8;
    p->ad[2].data = 0x31000070;
    p->ad[3].data = 0;
    p->ad[4].data = 0;
    p->ad[5].data = 0x2000000001300000ULL;
    p->ad[6].data = 0x60;
    p->ad[7].data = 0x2000000664023500ULL;
    p->ad[8].data = 0x5000d;
    p->ad[9].data = 0x44;
    p->ad[10].data = 5;
    p->ad[11].data = 0x808080;
    p->ad[12].data = 0x3f80000080808080ULL;
}
struct W1833Vec { f32 x, y, z, w; };
struct W1833Mgr { u8 pad[0x80]; u8* tbl; };
struct W1833Cam { u8 pad[0x10]; f32 m0[12]; f32 m1[4]; };
struct W1833Ent { u8 pad[4]; void* owner; };
struct W1833Prm { u8 pad[8]; f32 scale; u8 padc[4]; s32 idx; s32 o20; u8 pad18[4]; s32 o28; };
extern W1833Mgr* D_01d9e6e0;
extern W1833Cam* D_01d9e6e8;
W1833Ent* func_001e7a98(W1833Mgr*, u8*);
void func_002f3cd8(W1833Vec*, void*, W1833Vec*);
void func_002226b8(void*, W1833Vec*);
void func_002f3f10(W1833Vec*, W1833Vec*, void*);
void func_002f3d98(W1833Vec*, W1833Vec*);
void func_002f3f40(W1833Vec*, W1833Vec*, f32);

void func_001f5cc8(void* owner, W1833Prm* prm, s16* pos) {
    W1833Ent* e = 0;
    u8* t = D_01d9e6e0->tbl + prm->idx * 16;
    if (t != 0) {
        e = func_001e7a98(D_01d9e6e0, t);
        e->owner = owner;
    }
    u8* p1 = (u8*)e + prm->o28 + 160;
    u8* p0 = (u8*)e + prm->o20 + 160;
    W1833Vec v;
    v.x = pos[0];
    v.y = pos[1];
    v.z = pos[2];
    v.w = 1.0f;
    func_002f3cd8(&v, D_01d9e6e8->m0, &v);
    func_002226b8(p0, &v);
    func_002f3f10(&v, &v, D_01d9e6e8->m1);
    func_002f3d98(&v, &v);
    func_002f3f40(&v, &v, prm->scale);
    func_002226b8(p1, &v);
}
void func_001f6648(void* owner, W1833Prm* prm, s16* pos) {
    W1833Ent* e = 0;
    u8* t = D_01d9e6e0->tbl + prm->idx * 16;
    if (t != 0) {
        e = func_001e7a98(D_01d9e6e0, t);
        e->owner = owner;
    }
    u8* p1 = (u8*)e + prm->o28 + 160;
    u8* p0 = (u8*)e + prm->o20 + 160;
    W1833Vec v;
    v.x = pos[0];
    v.y = pos[1];
    v.z = pos[2];
    v.w = 1.0f;
    func_002f3cd8(&v, D_01d9e6e8->m0, &v);
    func_002226b8(p0, &v);
    func_002f3f10(&v, &v, D_01d9e6e8->m1);
    func_002f3d98(&v, &v);
    func_002f3f40(&v, &v, prm->scale);
    func_002226b8(p1, &v);
}
}
