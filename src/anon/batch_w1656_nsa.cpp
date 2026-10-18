#include "../common/types.h"
// 128-bit vector / 4x4 matrix copies are hand-written lq/sq through t0-t3 (as in the original).
#define W1656_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
#define W1656_MCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t" \
    "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct W1656Vec {
    f32 x, y, z, w;
    W1656Vec() {}
    W1656Vec(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
    W1656Vec& operator=(const W1656Vec& o) {
        if (this != &o) W1656_QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct W1656Mtx {
    f32 m[16];
    W1656Mtx& operator=(const W1656Mtx& o) {
        if (this != &o) W1656_MCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));
struct W1656Cfg { u8 pad[36]; f32 scale; };
struct W1656Res { u8 pad[8]; s32 data; };
struct W1656Oarashi {
    u32 vt;
    u8 pad4[88];
    s32 f92;
    s32 res;
    s32 f100;
    s32 f104;
    s32 afp;
    f32 f112;
    u8 pad116[12];
    W1656Vec v128;
    f32 f144;
    f32 f148;
    f32 f152;
    u8 pad156[4];
    W1656Mtx m160;
    W1656Mtx m224;
    W1656Vec v288;
    W1656Vec v304;
    u8 f320;
    u8 pad321[3];
    u32 f324;
    u32 f328;
};
extern "C" {
extern u8 D_00362158[];
extern u8 D_00362110[];
void func_002ce958(W1656Oarashi* p, s32 a, s32 b, s32 c);
void MiniGame_make_data_path_W1656(W1656Oarashi* p, char* out, const char* name) asm("_ZN2Ti8MiniGame14make_data_pathEPcS1_");
s32 CACHE_BUFF_Alloc_W1656(const char* path, s32 n) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");
W1656Res* func_00168b38(s32 h, s32 kind, s32 idx);
W1656Cfg* MGOarashi_config_W1656(W1656Oarashi* p) asm("_ZN2Ti9MGOarashi6configEv");
void func_001ca8f8(f32 a, f32 b);
void Afp_getCount_W1656(s32 a) asm("_ZN2Ti3Afp8getCountEPv");
s32 func_002e64b8(s32 a, s32 b);
void getFieldMode_W1656(void) asm("_Z12getFieldModev");
void func_002e6ab0(s32 afp, W1656Mtx* m, f32 t);
void func_001069b8(s32 a);
void func_002cedd0(s32 a, u8* b);
void func_002cf938(s32 a);
void func_002d12b0(W1656Oarashi* p, s32 id, s32 b)
{
    s32 data, r;
    f32 z = 0.0f;
    W1656Vec& v128 = p->v128;
    W1656Mtx& m160 = p->m160;
    W1656Mtx& m224 = p->m224;
    W1656Vec& v288 = p->v288;
    W1656Vec& v304 = p->v304;
    func_002ce958(p, 0, b, 2048);
    p->f104 = id;
    p->f100 = 0;
    p->afp = 0;
    p->vt = (u32)D_00362158;
    p->f112 = 40.0f;
    v128.x = z;
    v128.y = z;
    v128.z = z;
    v128.w = z;
    p->f144 = z;
    p->f152 = z;
    p->f320 = 0;
    {
        char path[64] __attribute__((aligned(16)));
        MiniGame_make_data_path_W1656(p, path, "po_06");
        p->res = r = CACHE_BUFF_Alloc_W1656(path, -1);
    }
    func_00168b38(r, 42, 0);
    p->f100 = func_00168b38(r, 42, 0)->data + 16;
    func_00168b38(r, 42, 1);
    data = func_00168b38(r, 42, 1)->data;
    func_00168b38(r, 42, p->f104 + 2);
    p->f92 = func_00168b38(r, 42, p->f104 + 2)->data;
    func_001ca8f8(MGOarashi_config_W1656(p)->scale, z);
    Afp_getCount_W1656(data);
    p->afp = func_002e64b8(0, data);
    getFieldMode_W1656();
    p->f112 = 40.0f;
    v128 = W1656Vec(z, z, 150.0f, z);
    p->f144 = z;
    {
        W1656Mtx m;
        func_002e6ab0(p->afp, &m, z);
        m160 = m;
        m224 = m;
        v288 = W1656Vec(z, z, z, z);
        v304 = W1656Vec(z, z, z, z);
    }
    p->f324 = 0;
    p->f328 = 0;
    func_001069b8(2);
    func_002cedd0(4, D_00362110);
    func_002cf938(1);
}
}
