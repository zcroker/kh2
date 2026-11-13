// sa::COUNTDOWN: the countdown display of event scripts. Linked unit 0x22bda0-0x22c4b8.
#include "../common/types.h"

struct Sub {
    u8 pad0[0x18];
    u8 obj[0x16c];
    s32 state; /* 0x184 */
    s32 pad188;
    s32 f18c;
    s32 f190;
    u8 pad194[4];
};
struct Obj {
    u8 pad0[0x18];
    s32 f18;
    Sub sub[3];
};
struct Inp { u8 pad[0x18]; u8 cur[0x1a8]; u8 tail[1]; };
struct Th { u8 pad[4]; s32 f4; };
typedef struct Alloc8 { struct AllocVt8* vt; } Alloc8;
typedef struct AllocVt8 { void* (*alloc)(Alloc8*, s32, s32); } AllocVt8;
typedef struct Mgr8 { u8 pad[20]; Alloc8* a; } Mgr8;
typedef struct Arg8 { u8 pad[4]; s16 id; } Arg8;
typedef struct Elem8 { void* vt; u8 pad[8]; u8 err[12]; u8 m[0x198 - 24]; } Elem8;
typedef struct Big8 { void* vt; u8 pad[8]; u8 err[16]; Elem8 e[3]; } Big8;
typedef struct Obj8 { void* vt; u8 pad[8]; s32 f0c; u8 pad2[8]; u8 m18[0x1a0 - 0x18]; void* vt2; u8 pad3[8]; u8 err[0x1c0 - 0x1ac]; u8 img[0x370 - 0x1c0]; } Obj8;
typedef u8* (*AllocFn)(u8*, u32, u32);

extern "C" {
Th* func_00197df8();
void func_00150260(void*, void*, s32, s32*);
void func_0023a9c0(void*, s32*, s32*);
s32 func_0023aa18(void*);
s32 func_0023aa38(void*);
void func_001386e0(void*, s32, s32, void*, s32, s32);
void func_001396b0(void*);
void func_0031a260(void*, s32);
void func_00139660(void*);
void func_00139688(void*);
void func_00138c10(void*, s32);
void func_00139598(void*);
s32 func_0023aa98(void*);
void func_00138c68(void*, s32, s32);
void func_00138650(void*, s32, s32, s32);
s32 func_00239cf0(void*, s32);
void func_00226e60(s32);
void func_001024a8(u32);
void func_00102c18(s32, s32, void*);
void func_00138840(void*);
s32 func_00139538(void*);
void func_00139510(void*);
s32 func_002282f0(s16);
s32 func_00225b00(s16);
void func_00239700(void*);
void func_0031a838(void*);  // ErrorRaise
void func_002361a0(void*);  // YI::IMAGE::IMAGE
s32 func_00139d78(void*);
}

extern Mgr8* D_00347f80;
extern u8 D_00347e60[];
extern u8 D_00347e80[];
extern u8 D_00347f98[];
extern u8 D_0035e320[];
extern u8 D_0035e340[];
extern s32 D_0035de64;
extern u32 D_0035de68;
extern s32 D_0035de6c;

s32 D_0035e2f0[10] = { 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };

void func_0022bda0(u8* self, s32 mode, u32 flag) {
    flag &= 0xff;
    self[864] = flag;
    Th* t = func_00197df8();
    func_00138650(self + 416, 26000, *(s32*)t, 16);
    func_001386e0(self, 26000, t->f4, self + 448, mode, 16);
    if (func_00239cf0(self + 24, mode) != 0) {
        self[864] = 0;
    }
}

void func_0022be28(u32 a) {
    func_00226e60(0);
    func_001024a8(a);
}

void func_0022be58(u8* self) {
    if (self[864] == 1) {
        func_00102c18(1, 24989, (void*)func_0022be28);
    }
    if (self != 0) {
        (*(void (**)(u8*))(*(u8**)self + 16))(self);
    }
}

void func_0022beb0(u8* self) {
    func_00138840(self);
    if (func_00139538(self) != 0) {
        func_00139510(self + 416);
    }
}

void func_0022c1f8(Obj* self, void* a1, u8* a2);

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
    func_0031a838(p->err);
    p->vt2 = D_00347e80;
    func_002361a0(p->img);
    func_0022bda0((u8*)p, n, 1);
    if (D_0035de6c != -1) {
        Alloc8* a = D_00347f80->a;
        Big8* q = (Big8*)a->vt->alloc(a, 0x4e4, 0);
        Elem8* e;
        s32 i;
        q->vt = D_00347f98;
        e = q->e;
        func_0031a838(q->err);
        q->vt = D_0035e320;
        for (i = 2; i != -1; i--) {
            e->vt = D_00347f98;
            func_0031a838(e->err);
            e->vt = D_00347e60;
            func_00239700(e->m);
            e++;
        }
        func_0022c1f8((Obj*)q, (void*)D_0035de6c, (u8*)p);
    }
}

static inline u8* alloc_obj(s32 size) {
    u8* a = *(u8**)((u8*)D_00347f80 + 20);
    return (**(AllocFn**)a)(a, size, 0);
}

void func_0022c108(void) {
    s32 m = D_0035de64;
    s32 mode;
    u8* v;
    if (m == 0) return;
    mode = 0;
    if (m != 1) mode = m == 2 ? 5 : 0;
    D_0035de64 = 0;
    v = alloc_obj(880);
    *(u32*)v = (u32)D_00347f98;
    func_0031a838(v + 12);
    *(u32*)v = (u32)D_00347e60;
    func_00239700(v + 24);
    *(u32*)(v + 416) = (u32)D_00347f98;
    *(u32*)v = (u32)D_0035e340;
    func_0031a838(v + 428);
    *(u32*)(v + 416) = (u32)D_00347e80;
    func_002361a0(v + 448);
    func_0022bda0(v, mode, 0);
}

void func_0022c1f8(Obj* self, void* a1, u8* a2) {
    s32 buf[3];
    s32 x, y;
    s32 i;
    s32 sum;
    Th* t;
    u8* p = a2 + 0x1c0;
    self->f18 = (s32)a2;
    sum = 0;
    t = func_00197df8();
    func_00150260(D_0035e2f0, a1, 3, buf);
    func_0023a9c0(a2 + 0x18, &x, &y);
    x += func_0023aa18(a2 + 0x18);
    y += func_0023aa38(a2 + 0x18);
    {
        // Counting down with explicit stepping pointers (an index loop gets an iteration-count
        // prediction that swaps two saved registers).
        Sub* s = self->sub;
        s32* bp = buf;
        for (i = 2; i >= 0; i--) {
        func_001386e0(s, 26000, t->f4, p, *bp, 16);
        s->f18c = (s32)a2;
        func_001396b0(s);
        if (s->f18c != 0) {
            s->f190 = 0;
            func_001396b0(s);
            if (s->f190 != 0) {
                func_0031a260(s, 0);
            }
        }
        func_00139660(s);
        func_00139688(s);
        s++; bp++;
    }
    }
    for (i = 2; i > 0; i--) {
        if (buf[i] != 7) break;
        func_00138c10(&self->sub[i], 17);
        func_00139598(&self->sub[i]);
    }
    for (i = 0; i < 3; i++) {
        if (self->sub[i].state != 17) {
            sum += func_0023aa98(self->sub[i].obj);
        }
    }
    x += sum / 2;
    for (i = 0; i < 3; i++) {
        Sub* s = &self->sub[i];
        if (s->state != 17) {
            x -= func_0023aa98(s->obj);
            func_00138c68(s, x, y);
        }
    }
}


void func_0022c410(u8* p) {
    if (p != 0) {
        (*(void (**)(u8*))(*(u8**)p + 16))(p);
    }
}

void func_0022c440(u8* self) {
    if (func_00139d78(*(u8**)(self + 24)) != 0) {
        return;
    }
    u8* o = self;
    s32 i = 2;
    do {
        u8* s = o + 28;
        if (func_00139d78(s) != 0) {
            (*(void (**)(u8*))(*(u8**)(o + 28) + 20))(s);
        }
        i--;
        o += 408;
    } while (i >= 0);
}
