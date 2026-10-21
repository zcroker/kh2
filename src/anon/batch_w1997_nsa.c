#include "../common/types.h"
typedef struct Alloc8 { struct AllocVt8* vt; } Alloc8;
typedef struct AllocVt8 { void* (*alloc)(Alloc8*, s32, s32); } AllocVt8;
typedef struct Mgr8 { u8 pad[20]; Alloc8* a; } Mgr8;
typedef struct Arg8 { u8 pad[4]; s16 id; } Arg8;
typedef struct Elem8 { void* vt; u8 pad[8]; u8 err[12]; u8 m[0x198 - 24]; } Elem8;
typedef struct Big8 { void* vt; u8 pad[8]; u8 err[16]; Elem8 e[3]; } Big8;
typedef struct Obj8 { void* vt; u8 pad[8]; s32 f0c; u8 pad2[8]; u8 m18[0x1a0 - 0x18]; void* vt2; u8 pad3[8]; u8 err[0x1c0 - 0x1ac]; u8 img[0x370 - 0x1c0]; } Obj8;
s32 func_002282f0(s16);
s32 func_00225b00(s16);
void func_00239700(void*);
void ErrorRaise8(void*) asm("_Z10ErrorRaisePv");
void Image8(void*) asm("_ZN2YI5IMAGEC1Ev");
void Create8(void*, s32, s32) asm("_ZN2sa9COUNTDOWN6createEib");
void func_0022c1f8(void*, s32, void*);
extern Mgr8* D_00347f80;
extern u8 D_00347e60[];
extern u8 D_00347e80[];
extern u8 D_00347f98[];
extern u8 D_0035e320[];
extern u8 D_0035e340[];
extern s32 D_0035de64;
extern u32 D_0035de68;
extern s32 D_0035de6c;
void func_0022bef8(Arg8* arg) {
    s32 n;
    Obj8* p;
    if (func_002282f0(arg->id)) return;
    if (func_00225b00(arg->id)) return;
    n = 1;
    D_0035de64 = 1;
    switch (D_0035de68) {
    case 0: break;
    case 1: n = 1; break;
    case 2: n = 2; D_0035de64 = 2; break;
    case 3: n = 3; break;
    case 4: n = 4; break;
    case 5: n = 5; break;
    }
    {
        Alloc8* a = D_00347f80->a;
        p = (Obj8*)a->vt->alloc(a, 0x370, 0);
    }
    p->f0c = 0;
    p->vt = D_00347e60;
    {
    void* vb = D_00347f98;
    func_00239700(p->m18);
    p->vt2 = vb;
    }
    p->vt = D_0035e340;
    ErrorRaise8(p->err);
    p->vt2 = D_00347e80;
    Image8(p->img);
    Create8(p, n, 1);
    if (D_0035de6c != -1) {
        Alloc8* a = D_00347f80->a;
        Big8* q = (Big8*)a->vt->alloc(a, 0x4e4, 0);
        Elem8* e;
        s32 i;
        q->vt = D_00347f98;
        e = q->e;
        ErrorRaise8(q->err);
        q->vt = D_0035e320;
        for (i = 2; i != -1; i--) {
            e->vt = D_00347f98;
            ErrorRaise8(e->err);
            e->vt = D_00347e60;
            func_00239700(e->m);
            e++;
        }
        func_0022c1f8(q, D_0035de6c, p);
    }
}
