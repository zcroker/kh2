#include "../common/types.h"

extern "C" {

struct HasF4 { s32 limit; s32 base; };
struct P10f6b8 { u8 pad[1164]; HasF4* lim; };
// Is base*scale over the limit?
s32 func_0010f6b8(P10f6b8* p, f32 scale) {  // count_reached_threshold
    HasF4* l = p->lim;
    if (l != 0) {
        s32 n = (s32)((f32)l->base * scale);
        if (l->limit < n) return 1;
    }
    return 0;
}

extern u32 D_003464b0;
void func_00113668(void*);
void func_00105110(void*);
void func_00114968(void** p) {
    *p = &D_003464b0;
    func_00113668(p);
    func_00105110(p);
}

extern u32 D_00347848;
void func_0011a510(void** p) {
    *p = &D_00347848;
    func_00113668(p);
    func_00105110(p);
}

typedef u8* (*GetFn)(void*);
s16 func_0011f238(void* o, s32 i) {
    u8* b = (*(GetFn*)((*(u8**)o) + 32))(o);
    return *(s16*)(b + i * 64 + 4);
}

struct Node135 { void* vt; u32 pad; Node135* next; };
extern u32 D_00347d00;
extern Node135* D_00347cf0;
void func_00135aa0(void*);
void func_00135900(Node135* p) {
    p->vt = &D_00347d00;
    func_00135aa0(p);
    p->next = D_00347cf0;
    D_00347cf0 = p;
}

extern u32 D_004574b8;
extern u32 D_0032b91c;
void func_0014f030(void*, f32, f32, f32);  // obj_set_lerp_params
void func_00102788(u32, u32, u32, void (*)(void));
void func_0014cd98(void);
void Vsync_setGameSpeed(f32, f32, f32) asm("_ZN2dk5Vsync12setGameSpeedEfff");
void Vsync_setGameSpeed(f32 a, f32 b, f32 c) {
    func_0014f030(&D_004574b8, a, b, c);  // obj_set_lerp_params
    func_00102788(D_0032b91c, 0, 800000, func_0014cd98);
}

void func_00138c10(void*, s32);
void func_00150578(u8* p) {
    func_00138c10(p + 840, 0);
    func_00138c10(p + 1248, 6);
}

void func_001581f8(void*);
s32 func_00154ee8(void*);  // field24_state_code
void GAUGE_FRIEND_reload(u8*) asm("_ZN2dk12GAUGE_FRIEND6reloadEv");
void GAUGE_FRIEND_reload(u8* self) {
    func_001581f8(self);
    func_00138c10(self + 916, func_00154ee8(self));
}

extern f32 D_0034aa44;
f32 func_0015a098(void*);
f32 func_0017ce10(f32);
struct P15a { u8 pad[80]; f32 v; };
void func_0015a118(P15a* p) {
    p->v = func_0017ce10(func_0015a098(p) + D_0034aa44);
}

struct RadarS { u8 pad[2928]; void* data; s32 n; };
void func_0015b7f8(void*);
void func_0015bab8(void*);
void Radar_create(RadarS*, void*) asm("_ZN2dk5Radar6createEPv");
void Radar_create(RadarS* self, void* data) {
    self->data = data;
    self->n = 16;
    func_0015b7f8(self);
    func_0015bab8(self);
}

extern u32 D_0032e020;
void* func_00189200(void*, u32);
void func_001891b8(void*, u32);
void trap_saveram_set_form_ability(u32*) asm("_ZN2YS29trap_saveram_set_form_abilityEP8BD_VALUE");
void trap_saveram_set_form_ability(u32* v) {
    func_001891b8(func_00189200(&D_0032e020, v[0]), v[1]);
}

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));
struct P173 { u8** a; Q16* q; f32 f; };
void func_0019fdc0(u8*, Q16*, f32);
void func_00173808(P173* p) {
    Q16 t;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&t), "r"(p->q) : "$8", "memory");
    func_0019fdc0(p->a[1], &t, p->f);
}

void func_0017c4c8(void*, Q16*);
void func_0016bd60(void*, s32);
void f17a8f8(void*, void*, Q16*) asm("_Z13func_0017a8f8Pv");
void f17a8f8(void*, void* o, Q16* q) {
    Q16 t;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&t), "r"(q) : "$8", "memory");
    func_0017c4c8(o, &t);
    func_0016bd60(o, 1);
}

s32 func_001860b0(void*);
void func_001c1b08(void*, u32, s32);
void func_00186948(void* a, u8* b) {
    s32 v = func_001860b0(a);
    func_001c1b08(a, *(u32*)(b + 28), v);
}

struct Obj198 { u8 pad[1416]; u32 active : 1; };
Obj198* func_001b9bc8(Obj198*);
// Advance to the next object whose active bit is set.
Obj198* func_00198700(Obj198* p) {
    do {
        p = func_001b9bc8(p);
    } while (p != 0 && (u8)p->active == 0);
    return p;
}


struct G19d { u32 pad0; s32 a; u8 pad8[24]; s32 v; s32 b; };
extern G19d* D_00350444;
s32 func_0019d380(s32 a, s32 b) {
    G19d* g = D_00350444;
    s32 v = g->v;
    if (v != 0 && g->a == a && g->b == b) return v;
    return 0;
}

void func_001991a8(s32, u32);
struct P1ac { u8 pad[112]; s32 st; u8 pad2[12]; u32 id; };
void func_001ac700(P1ac* p) {
    p->st = 4;
    func_001991a8(34, p->id);
}

struct E1af { u32 a; s32 key; u32 c; };
extern E1af D_01c94090[3];
s32 func_001afe30(s32 key) {
    s32 i;
    for (i = 0; i < 3; i++) {
        if (D_01c94090[i].key == key) return i;
    }
    return -1;
}

extern u32 D_00350e78;
void func_001b0330(void*);
void func_00106420(void*);
void func_001b01d8(void** p) {
    *p = &D_00350e78;
    func_001b0330(p);
    func_00106420(p);
}

void* func_001b77a8(s32);
void func_00153468(void*, u32, void*);
void func_001b7768(u32* a, void* b) {
    func_00153468(func_001b77a8(1), *a, b);
}

struct P1be { u8 pad[2728]; u32 a; u32 b; };
void func_001bd668(void*);
void func_001bd5b0(void*, s32, s32);
void func_001befd8(P1be* p, u32 a, u32 b) {
    p->a = a;
    p->b = b;
    func_001bd668(p);
    func_001bd5b0(p, 10, 0);
}

extern u8* D_01d49508;
extern u32 D_00320898;
u8 func_002fd248(void*, void*, u32, s32, void*);
s32 func_001c10f8(void* a) {  // request_pool_block64
    u8* g = D_01d49508;
    return func_002fd248(a, g + 8, *(u32*)(g + 4), 64, &D_00320898);
}

struct E1c5 { u8 pad[20]; s32 n; u8 pad2[8]; };
extern E1c5 D_00351680[];
void func_001c5e88(void*);
s32 func_001c5f38(u8* p) {
    if (D_00351680[p[82]].n > 0) {
        func_001c5e88(p);
        return 1;
    }
    return 0;
}

extern u16 D_0032fafe[];
// Bump a saturating counter (max 999).
void func_001d97f0(s32 i) {
    if (D_0032fafe[i + 3] < 999) D_0032fafe[i + 3]++;
}

extern u32 D_00352970;
extern void* D_00352960;
void func_001a4e30(void*);
void func_001da278(void** p) {
    *p = &D_00352970;
    D_00352960 = 0;
    func_001a4e30(p);
    func_00105110(p);
}

typedef void (*VFn)(void*);
void func_001dba98(u8* p) {
    s32 n = *(s32*)(p + 2552) - 1;
    *(s32*)(p + 2552) = n;
    if (n == 0) (*(VFn*)((*(u8**)p) + 32))(p);
}

extern u32 D_0035dd08[64];
void func_00226050(u32 v) {
    s32 i;
    for (i = 0; i < 64; i++) {
        if (D_0035dd08[i] == 0) break;
    }
    D_0035dd08[i] = v;
}

struct E22e { u32 a; s32 key; u8 pad[44]; };
extern E22e* D_0035dcf4;
E22e* func_0022e330(s32 key) {
    E22e* e = D_0035dcf4;
    s32 i;
    for (i = 0; i < 96; i++, e++) {
        if (e->key == key) return e;
    }
    return 0;
}

struct V2 { f32 a[4]; f32 b[4]; };
extern V2 D_0035db20;
void func_002314c0(f32* s) {
    D_0035db20.a[0] = s[0];
    D_0035db20.a[1] = s[1];
    D_0035db20.a[2] = s[2];
    D_0035db20.b[0] = s[3];
    D_0035db20.b[1] = s[4];
    D_0035db20.b[2] = s[5];
}

struct E237 { u32 a; s32 lo; u32 b; s32 hi; u32 c; };
struct P237 { u32 pad[2]; E237* e; u16* idx; };
s32 func_00237578(P237* p, s32 i, s32 j) {  // entry20_field12_minus4
    E237* e = &p->e[p->idx[i * 2] + j];
    return e->hi - e->lo;
}

typedef void (*VFn2)(void*, void*);
extern void* D_0035ec84;
void func_0023fe28(void* a) {
    if (a) {
        void* o = D_0035ec84;
        (*(VFn2*)((*(u8**)o) + 4))(o, a);
    }
}

extern u8* D_0035f20c;
void func_00139d78(void*);
void func_00275ec8(u32 v) {
    func_00139d78(D_0035f20c + 872);
    *(u32*)(D_0035f20c + 1280) = v;
}

void func_00281008(void*, void*);
void func_00280ef8(void*, void*);
void func_002810c8(void* a, void* b) {
    func_00281008(a, b);
    func_00280ef8(a, b);
}

void func_00281f40(void*, s32);
void func_00281f48(void*);  // memset_1920
void func_00281f70(void*);
void func_00281f90(void*);
void func_00281ec8(void* p) {
    func_00281f40(p, 0);
    func_00281f48(p);  // memset_1920
    func_00281f70(p);
    func_00281f90(p);
}

typedef s32 (*VFn3)(void*, void*, void*);
extern void* D_0035f3f8;
s32 func_0028cc08(void* a) {
    void* o = D_0035f3f8;
    return (*(VFn3*)(*(u8**)o))(o, a, __builtin_return_address(0));
}

u8* func_00103eb0(void);
u8 func_00102a38(u32, void (*)(void));  // list_contains_id
void func_00293b08(void);
u32 ChgMember_isExec(void) asm("_ZN2Tz9ChgMember18isExecChangeMemberEv");
u32 ChgMember_isExec(void) {
    return func_00102a38(*(u32*)(func_00103eb0() + 4), func_00293b08);  // list_contains_id
}

struct E2bc { s32 v; s32 key; u32 c; };
s32 func_002bc9d8(u8* p, s32 key) {
    E2bc* e = (E2bc*)(p + 132);
    do {
        if (e->key == key) return e->v;
        e++;
    } while ((s32)e < (s32)(p + 300));
    return -1;
}

void func_001780d8(void*, void*, void*);
void func_002c6c60(void*, u32);
void ObjCamera_start(u8*, void*, void*) asm("_ZN8worldmap9ObjCamera5startEPNS_6PlayerEPN2YS3PADE");
void ObjCamera_start(u8* self, void* pl, void* pad) {
    func_001780d8(self, pl, pad);
    func_0016bd60(self, 47);
    func_002c6c60(self, *(u32*)(self + 2872));
}

extern u32 D_003626a8;
void func_002db530(void*);
void func_002db730(void** p) {
    *p = &D_003626a8;
    func_002db530(p);
    func_00105110(p);
}

void func_002d10a0(void*);
void func_002dd790(u8* p) {
    func_002d10a0(p);
    u8* d = p + 3056;
    u8* s = p + 1344;
    if (d != s) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    }
}

extern u32 D_00363c2c;
extern u32 D_00363c28;
extern u32 D_01e2c100;
void func_002f1a68(void);
void func_00168388(u32, void*, void (*)(void), s32);
void func_002f1a80(void) {
    D_00363c2c = 0;
    func_00168388(D_00363c28, &D_01e2c100, func_002f1a68, 0);
}

extern u32 D_00347e60;
void func_00239870(void*);
u8 func_0031a840(void*);
s32 func_0031a508(u8* p) {
    *(void**)p = &D_00347e60;
    func_00239870(p + 24);
    return func_0031a840(p);
}

void func_0031f940(u8* p) {
    void* o = *(void**)(p + 24);
    (*(VFn*)((*(u8**)o) + 16))(o);
}

extern u32 D_00351100;
void func_0031fec0(void*);
void func_0031fe88(void** p) {
    *p = &D_00351100;
    func_0031fec0(p);
    func_00105110(p);
}

extern u32 D_00362cc8;
void func_002dea80(void*);  // set_vtbl_362d20
void func_003255b8(void** p) {
    *p = &D_00362cc8;
    func_002dea80(p);  // set_vtbl_362d20
    func_00106420(p);
}

}
