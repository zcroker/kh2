#include "../common/types.h"
struct C2040Vec {
    f32 x, y, z, w;
    C2040Vec() {}
    C2040Vec(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {}
    C2040Vec& operator=(const C2040Vec& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
struct C2040Mtx {
    f32 m[16];
    C2040Mtx() {}
    C2040Mtx(const C2040Mtx& o) {
        asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                     "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                     : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
    }
    C2040Mtx& operator=(const C2040Mtx& o) {
        if (this != &o)
            asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                         "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)"
                         : : "r"(this), "r"(&o) : "$8", "$9", "$10", "$11", "memory");
        return *this;
    }
    // inverse of a rotation + translation matrix, in place
    void invOrtho() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
    C2040Mtx inverse() const {
        C2040Mtx r(*this);
        r.invOrtho();
        return r;
    }
    C2040Vec operator*(const C2040Vec& v) const {
        C2040Vec r;
        asm volatile(".set noreorder\n\tlqc2 $vf5, 0(%1)\n\tlqc2 $vf1, 0(%2)\n\tlqc2 $vf2, 16(%2)\n\tlqc2 $vf3, 32(%2)\n\tlqc2 $vf4, 48(%2)\n\t"
                     "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                     "sqc2 $vf5, 0(%0)\n\t.set reorder" : : "r"(&r), "r"(&v), "r"(this) : "memory");
        return r;
    }
    C2040Mtx operator*(const C2040Mtx& b) const {
        C2040Mtx r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 16(%1)\n\tlqc2 $vf3, 32(%1)\n\tlqc2 $vf4, 48(%1)\n\t"
                     "lqc2 $vf5, 0(%2)\n\tlqc2 $vf6, 16(%2)\n\tlqc2 $vf7, 32(%2)\n\tlqc2 $vf8, 48(%2)\n\t"
                     "vmulax.xyzw ACC, $vf1, $vf5x\n\tvmadday.xyzw ACC, $vf2, $vf5y\n\tvmaddaz.xyzw ACC, $vf3, $vf5z\n\tvmaddw.xyzw $vf5, $vf4, $vf5w\n\t"
                     "vmulax.xyzw ACC, $vf1, $vf6x\n\tvmadday.xyzw ACC, $vf2, $vf6y\n\tvmaddaz.xyzw ACC, $vf3, $vf6z\n\tvmaddw.xyzw $vf6, $vf4, $vf6w\n\t"
                     "vmulax.xyzw ACC, $vf1, $vf7x\n\tvmadday.xyzw ACC, $vf2, $vf7y\n\tvmaddaz.xyzw ACC, $vf3, $vf7z\n\tvmaddw.xyzw $vf7, $vf4, $vf7w\n\t"
                     "vmulax.xyzw ACC, $vf1, $vf8x\n\tvmadday.xyzw ACC, $vf2, $vf8y\n\tvmaddaz.xyzw ACC, $vf3, $vf8z\n\tvmaddw.xyzw $vf8, $vf4, $vf8w\n\t"
                     "sqc2 $vf5, 0(%0)\n\tsqc2 $vf6, 16(%0)\n\tsqc2 $vf7, 32(%0)\n\tsqc2 $vf8, 48(%0)"
                     : : "r"(&r), "r"(this), "r"(&b) : "memory");
        return r;
    }
} __attribute__((aligned(16)));
s32 func_002ceb28(void);
struct W2040Ent { u32 a; u32 b; s32 v; };
struct W2040Obj {
    u8* vt;
    u8 pad04[0x58];
    s32 f5c;
    s32 f60;
    f32 f64, f68, f6c;
    s32 f70;
    s32 f74[3];
    s32 f80;
    u8 pad84[0x100 - 0x84];
    u8 m100[0x7e20 - 0x100];
    u8 m7e20[0x8060 - 0x7e20];
    u8 f8060;
    u8 pad8061[3];
    s32 f8064;
    u8 pad8068[0x10];
    u8 m8078[0x10];
};
struct W2040Req { u16 type; u16 pad; u16 val; };
struct W2040Unit { s32 f0; s32 f4; u8 pad[0x184 - 8]; s32 f184; };

extern "C" {
void func_00102c80(void);
void func_00144450(void*);
W2040Ent* func_00168b38(s32, s32, s32);
s32 func_0016b740(s32);
void func_0016bd60(s32, s32);
s32 func_001708f8(char*, s32);
void func_002ce958(void*, s32, s32, s32);
void func_002ceae8(void*, char*, const char*);
void func_002cedd0(s32, void*);
s32 func_002dc7f8(void*);
void func_002dc850(void*);
void func_002e4a08(void*);
void func_002e5f70(void*);
void func_002e5fb8(void*, s32);
extern u8 D_00362990[];
extern u8 D_003629e8[];
extern char D_00375d48[];
W2040Unit* func_001a1658(s32, s32);
void func_001a17c8(W2040Unit*);
void func_001a1950(W2040Unit*, s32, s32, s32);
void func_001a1a20(W2040Unit*, s32, s32);
void func_001a1aa0(W2040Unit*, s32, s32);
void func_001a2578(W2040Unit*, s32, s32);
void func_001a25c8(W2040Unit*, s32, s32);
void func_001a2618(W2040Unit*, s32, s32);
void func_001a2668(W2040Unit*, s32, s32);
extern f32 D_00362d70;
C2040Mtx func_002e10d0(void*);
f32 func_002f8a18(f32);
f32 func_002f8870(f32);

void func_002dc2b8(W2040Obj* self, s32 x, s32 y) {
    char buf[64];
    s32 i;
    s32 h;
    s32 t;
    s32 r;
    W2040Ent* e;
    u8* m;
    func_002ce958(self, 2, y, 160);
    m = self->m7e20;
    self->vt = D_003629e8;
    self->f64 = 0.34906584f;
    self->f68 = 2000.0f;
    self->f6c = 0.5f;
    self->f80 = x;
    func_002e4a08(self->m100);
    func_002e5f70(m);
    func_00144450(self->m8078);
    func_00102c80();
    func_002ceae8(self, buf, D_00375d48);
    h = func_001708f8(buf, -1);
    self->f60 = h;
    func_00168b38(h, 42, 0);
    self->f70 = func_00168b38(h, 42, 0)->v + 16;
    func_00168b38(h, 10, 0);
    t = func_00168b38(h, 10, 0)->v;
    self->f5c = func_00168b38(h, 42, self->f80 * 2 + 1)->v;
    e = func_00168b38(h, 42, self->f80 * 2 + 2);
    self->f8064 = e->v;
    {
        s32* p = self->f74;
        i = 0;
        do {
            *p = func_00168b38(h, 42, i + 9)->v;
            i++;
            p++;
        } while (i < 3);
    }
    func_002e5fb8(m, t);
    func_002dc850(self);
    func_002cedd0(5, D_00362990);
    self->f8060 = 0;
    func_0016bd60(func_002dc7f8(self), 30);
    r = func_0016b740(0x6a2);
    if (r != 0) func_0016bd60(r, 34);
    r = func_0016b740(0x6a3);
    if (r != 0) func_0016bd60(r, 35);
}
void func_002dc4e0(W2040Obj* self, s32 x, s32 y) {
    char buf[64];
    s32 i;
    s32 h;
    s32 t;
    s32 r;
    W2040Ent* e;
    u8* m;
    func_002ce958(self, 2, y, 160);
    m = self->m7e20;
    self->vt = D_003629e8;
    self->f64 = 0.34906584f;
    self->f68 = 2000.0f;
    self->f6c = 0.5f;
    self->f80 = x;
    func_002e4a08(self->m100);
    func_002e5f70(m);
    func_00144450(self->m8078);
    func_00102c80();
    func_002ceae8(self, buf, D_00375d48);
    h = func_001708f8(buf, -1);
    self->f60 = h;
    func_00168b38(h, 42, 0);
    self->f70 = func_00168b38(h, 42, 0)->v + 16;
    func_00168b38(h, 10, 0);
    t = func_00168b38(h, 10, 0)->v;
    self->f5c = func_00168b38(h, 42, self->f80 * 2 + 1)->v;
    e = func_00168b38(h, 42, self->f80 * 2 + 2);
    self->f8064 = e->v;
    {
        s32* p = self->f74;
        i = 0;
        do {
            *p = func_00168b38(h, 42, i + 9)->v;
            i++;
            p++;
        } while (i < 3);
    }
    func_002e5fb8(m, t);
    func_002dc850(self);
    func_002cedd0(5, D_00362990);
    self->f8060 = 0;
    func_0016bd60(func_002dc7f8(self), 30);
    r = func_0016b740(0x6a2);
    if (r != 0) func_0016bd60(r, 34);
    r = func_0016b740(0x6a3);
    if (r != 0) func_0016bd60(r, 35);
}
void func_002e1440(void* self, C2040Vec* v, C2040Vec* mn, C2040Vec* mx) {
    C2040Mtx m = func_002e10d0(self);
    C2040Mtx inv = m.inverse();
    v->w = 1.0f;
    *v = inv * *v;
    f32 t = func_002f8a18(D_00362d70 * 0.5f * 0.017453292f) * func_002f8870(v->z);
    f32 hx = t * 4.0f / 3.0f;
    if (hx - mx->x < v->x) v->x = hx - mx->x;
    if (v->x < mn->x - hx) v->x = mn->x - hx;
    if (t - mx->y < v->y) v->y = t - mx->y;
    if (v->y < mn->y - t) v->y = mn->y - t;
    *v = m * *v;
}
void func_001a2b50(W2040Req* r, s32 id, s32 other, s32 pct) {
    W2040Unit* o = func_001a1658(id, -1);
    s32 flag;
    s32 val;
    s32 a, b;
    if (o == 0) return;
    flag = 0;
    if (other != 0) flag = other != id;
    val = r->val;
    a = (o->f4 * val * pct + 9999) / 10000;
    b = (o->f184 * val * pct + 9999) / 10000;
    switch (r->type) {
    case 1: case 2: case 5:
        func_001a1950(o, a, 0, flag);
        break;
    case 3: case 6:
        func_001a1a20(o, b, flag);
        break;
    case 4: case 7:
        func_001a1950(o, a, 0, flag);
        func_001a1a20(o, b, 0);
        break;
    case 131:
        func_001a1950(o, o->f4, 0, flag);
        func_001a1a20(o, b, 0);
        break;
    case 274: case 275:
        func_001a1aa0(o, r->val * 100, flag);
        break;
    case 276:
        func_001a2578(o, val, flag);
        break;
    case 277:
        func_001a25c8(o, val, flag);
        break;
    case 278:
        func_001a2618(o, val, flag);
        break;
    case 279:
        func_001a2668(o, val, flag);
        break;
    }
    func_001a17c8(o);
}
}
