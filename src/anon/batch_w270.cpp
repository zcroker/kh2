#include "../common/types.h"
struct W270V {
    f32 x, y, z, w;
    W270V& operator=(const W270V& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    W270V operator-(const W270V& b) const {
        W270V r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
static inline f32 w270_vlen(W270V* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf1, $vf1, $vf1\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tvsqrt Q, $vf1x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tmtc1 $8, %0"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline f32 w270_vnorm(W270V* v) {
    f32 len;
    asm volatile("lqc2 $vf1, 0(%1)\n\tvmul.xyz $vf2, $vf1, $vf1\n\tvaddy.x $vf2, $vf2, $vf2y\n\tvaddz.x $vf2, $vf2, $vf2z\n\tvsqrt Q, $vf2x\n\tvwaitq\n\tcfc2.ni $8, $vi22\n\tvaddq.x $vf2, $vf0, Q\n\tmtc1 $8, %0\n\tvnop\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyz $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%1)"
        : "=f"(len) : "r"(v) : "$8", "memory");
    return len;
}
static inline void w270_vscale(W270V* d, const W270V* a, f32 s) {
    asm volatile("lqc2 $vf1, 0(%1)\n\tmfc1 $8, %2\n\tqmtc2 $8, $vf2\n\tvmulx.wxyz $vf1, $vf1, $vf2x\n\tsqc2 $vf1, 0(%0)" : : "r"(d), "r"(a), "f"(s) : "$8", "memory");
}
struct W270Sh { s32 type; f32 a; f32 b; u32 pad; W270V pos; };
struct W270Heap { virtual void f0(); virtual void Free(void*); };
struct W270Mgr { u8 pad[20]; W270Heap* heap; };
extern W270Mgr* D_00347f80;
struct W270Vo { virtual void f0(); virtual void f1(); virtual void f2(); virtual ~W270Vo(); };
struct W270Ae {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual ~W270Ae();
    u8 pad[432];
    void operator delete[](void* p) { D_00347f80->heap->Free(p); }
};
struct W270Sel;
extern W270Vo* D_0035f100;
extern W270Ae* D_0035f104;
extern W270Vo* D_0035f108;
extern W270Sel* D_0035f10c;
extern W270Vo* D_0035f110;
extern u8* D_0035f114;
extern W270Vo* D_0035f124;
struct W270Ys { u8 pad[320]; u8 sub320[2528]; W270V v2848; f32 f2864; f32 f2868; u8 sub2872[4]; };
struct W270Cfg { u8 pad[256]; f32 f256; f32 f260; };
extern void* D_00361f60;
extern u32 D_0034e948;
extern u8 D_00362370[];
extern u8 D_00362378[];
extern u8 D_00347f98[];
extern u8 D_00347e60[];
extern u8 D_00347e40[];
extern "C" void W270_ErrorRaise(void*) asm("_Z10ErrorRaisePv");
extern "C" void func_00239700(void*);
static inline void w270_init(u8* e) {
    *(void**)e = D_00347f98;
    W270_ErrorRaise(e + 12);
    *(void**)e = D_00347e60;
    func_00239700(e + 24);
    *(void**)e = D_00347e40;
    *(u32*)(e + 408) = 0;
}
struct W270Le { u8 b0; u8 b1; u8 pad[4]; u16 h6; };
struct W270Ls { u8 flag; u8 pad[3]; W270Le* list; };
struct W270Lt { u8 pad[4096]; W270Ls ent[1]; };
struct W270It { u8 pad[8]; u16 h8; };
extern W270Lt* D_0035f5e4;
extern u8* D_0035f5e8;
extern "C" {
f32 func_0018a970(W270Sh* s, const W270V* q) {
    f32 r = 0.0f;
    W270V d;
    W270V u;
    W270V t = s->pos - *q;
    d = t;
    switch (s->type) {
    case 0:
        if (r < s->a && r < s->b) {
            d.y *= s->a / s->b;
            r = w270_vnorm(&d);
            w270_vscale(&d, &d, r - s->a);
            d.y *= s->b / s->a;
        }
        r = w270_vlen(&d);
        break;
    case 3:
        r = w270_vlen(&d) - s->a;
        break;
    }
    return r;
}
void W270_SelDtor(W270Sel*) asm("_ZN2Tz6SelectD1Ev");
void func_00288c20(W270Sel*);
void W270_dela(void*) asm("_ZdaPv");
u32 W270_SelExitImpl(...) asm("_ZN2Tz8Selector11SelExitImplEz");
u32 W270_SelExitImpl(...) {
    if (D_0035f100) { delete D_0035f100; D_0035f100 = 0; }
    if (D_0035f104) { delete[] D_0035f104; D_0035f104 = 0; }
    if (D_0035f108) { delete D_0035f108; D_0035f108 = 0; }
    if (D_0035f10c) { W270Sel* p = D_0035f10c; W270_SelDtor(p); func_00288c20(p); D_0035f10c = 0; }
    if (D_0035f110) { delete D_0035f110; D_0035f110 = 0; }
    if (D_0035f114) { W270_dela(D_0035f114); D_0035f114 = 0; }
    if (D_0035f124) { delete D_0035f124; D_0035f124 = 0; }
}
s32 W270_is_attach(W270Ys*) asm("_ZN2YS3OBJ9is_attachEv");
void W270_detach(W270Ys*) asm("_ZN2YS3OBJ6detachEv");
void W270_change_action(W270Ys*, s32) asm("_ZN2YS3OBJ13change_actionENS_6ACTION2IDE");
void W270_ctarget(W270V*, u32) asm("_Z16ctarget_0016bda8jjjj");
void W270_set_pos(W270Ys*, W270V*) asm("_ZN2YS3OBJ7set_posERKN2kn7FVectorE");
void W270_set_rot(W270Ys*, f32) asm("_ZN2YS3OBJ7set_rotEf");
void W270_17f488(void*, s32, f32, f32) asm("_Z13func_0017f488iiff");
W270Cfg* W270_config(void*) asm("_ZN2Ti9MGOarashi6configEv");
void func_002e7568(W270Ys*, s32, void*, f32);
void func_002e7340(void*, W270Ys*, s32, void*, f32, f32);
void func_002d6600(W270Ys* o, W270V* dir) {
    void* g = D_00361f60;
    if (!W270_is_attach(o)) return;
    W270_detach(o);
    W270_change_action(o, 38);
    W270V t;
    W270_ctarget(&t, D_0034e948);
    t.z = 0.0f;
    W270_set_pos(o, &t);
    W270_set_rot(o, 0.0f);
    W270_17f488(o->sub320, 153, 0.0f, 0.0f);
    o->v2848 = *dir;
    o->v2848.z = 0.0f;
    w270_vnorm(&o->v2848);
    o->f2864 = 0.0f;
    o->f2868 = 0.0f;
    func_002e7568(o, 5, D_00362370, 1.0f);
    W270Cfg* a = W270_config(g);
    W270Cfg* b = W270_config(g);
    func_002e7340(o->sub2872, o, 5, D_00362378, a->f256, b->f260);
}
void func_00323978(u8* p) {
    w270_init(p);
    w270_init(p + 436);
    u8* q = p + 872;
    for (s32 n = 7; n != -1; n--) { w270_init(q); q += 436; }
    u8* r = p + 4360;
    for (s32 n = 7; n != -1; n--) { w270_init(r); r += 436; }
}
s32 func_002a4990(s32);
s32 func_002a4ad8(s32);
s32 func_002a4430(void);
s32 func_002a43f0(void);
W270It* func_001a80c8(u32);
void func_0028de08(u32, u8*, s32);
void* W270_tail4(u32) asm("_Z16u_tail4_00192048jjjj");
void W270_dup(void*, u8*) asm("_ZNK2YS7MESSAGE3dupEPc");
void W270_ctarget2(u8*, u32, s32) asm("_Z16ctarget_001a3788jjjj");
void W270_wtarget(u8*, u32, u32) asm("_Z16wtarget_002fde18jjjj");
void func_002a3950(void) {
    s32 a = func_002a4990(-1);
    if (!D_0035f5e4->ent[a].flag) {
        W270_wtarget(D_0035f5e8 + 0x982c, 0, 32);
        return;
    }
    s32 b = func_002a4ad8(-1);
    W270Le* e = (W270Le*)((u32)(b * 8) + (u32)D_0035f5e4->ent[a].list);
    u32 id = e->h6;
    if (e->b1) {
        if (func_002a4430()) {
            W270_dup(W270_tail4(id), D_0035f5e8 + 0x982c);
        } else if (func_002a43f0()) {
            W270_ctarget2(D_0035f5e8 + 0x982c, id, -1);
        } else {
            W270_dup(W270_tail4(func_001a80c8(id)->h8), D_0035f5e8 + 0x982c);
        }
    } else {
        if (func_002a4430()) func_0028de08(id, D_0035f5e8 + 0x982c, 64);
        else func_0028de08(func_001a80c8(id)->h8, D_0035f5e8 + 0x982c, 64);
    }
}
}
