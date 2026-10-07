#include "../common/types.h"

// An empty-destructor local keeps a cleanup pending, which stops gcc from
// turning the final call into a sibling call.
struct NoTail { ~NoTail() {} };

// 16-byte element with an empty destructor; arrays of it get a destructor loop.
struct E16 { u8 d[16]; ~E16() {} };
struct Q128 { u32 w[4]; } __attribute__((aligned(16)));

extern "C" void func_00106420(void*);
extern "C" void func_00105110(void*);
extern "C" void func_0018d420(void*);
extern "C" void func_002d0f38(void*);
extern "C" void* D_00350758[];
extern "C" void* D_003625e0[];

// Base-part destructors run last, after the member arrays.
struct Head18d420 { u32 vt; ~Head18d420() { func_0018d420(this); } };
struct Obj1a4060 {
    Head18d420 head;
    u8 pad4[204];
    E16 arr[32];
    u32* f720;
    ~Obj1a4060() { *(void**)this = D_00350758; *f720 = 0; }
    static void operator delete(void* p) { func_00105110(p); }
};

struct Head2d0f38 { u32 vt; ~Head2d0f38() { func_002d0f38(this); } };
struct Obj325498 {
    Head2d0f38 head;
    u8 pad4[3228];
    E16 arr[8];
    ~Obj325498() { *(void**)this = D_003625e0; }
    static void operator delete(void* p) { func_00105110(p); }
};

struct Obj287f30 {
    u8 pad[32];
    E16 arr[2];
    static void operator delete(void* p) { func_00106420(p); }
};

void func_001064a8(void*) asm("_Z13func_001064a8Pv");

extern "C" {

void LeadDataSetText(u8*, u32) asm("_ZN2Tz15LeadDataSetTextEPvj");
void CmItem_FadeOutTop(void*) asm("_ZN2Tz6CmItem10FadeOutTopEv");
void CmItem_FadeOutWarn(void*) asm("_ZN2Tz6CmItem11FadeOutWarnEv");
void Select_End(void*) asm("_ZN2Tz6Select3EndEv");
void MenuCursor_AttachSprite(u8*, u32) asm("_ZN2Tz10MenuCursor12AttachSpriteEz");

s32 func_002fea18(void);
void func_00313bc0(f32);

// Deleting destructor.
void func_001a4060(Obj1a4060* p) {
    p->~Obj1a4060();
    Obj1a4060::operator delete(p);
}

// Deleting destructor.
void func_00325498(Obj325498* p) {
    p->~Obj325498();
    Obj325498::operator delete(p);
}

extern Obj287f30* D_0035f324;
void func_00287f30(void) {
    if (D_0035f324) {
        delete D_0035f324;
        D_0035f324 = 0;
    }
}

}

// Scales n by a random fraction.
void func_001064a8(void* n) {
    NoTail g;
    f32 x = (f32)(u32)n;
    s32 r = func_002fea18();
    func_00313bc0(x * (f32)r / 2147483520.0f);
}

extern "C" {

// Hides every 2D object owned by `owner`.
struct Node1399c0 { u32 f0; Node1399c0* next; u8 pad8[8]; void* owner; };
struct List1399c0 { u32 f0; Node1399c0* head; };
extern List1399c0* D_00347f80;
void func_00139598(Node1399c0*);
static inline Node1399c0* nextNode(Node1399c0* o) {
    List1399c0* l = D_00347f80;
    if (!o) return l->head;
    return o->next;
}
void func_001399c0(void* owner) {
    Node1399c0* o = 0;
    while ((o = nextNode(o)) != 0)
        if (o->owner == owner) func_00139598(o);
}

void func_0015a850(void);
void func_00153c80(void);
void func_0014f148(void);
void func_0014f220(void);
void func_0014f1e0(void);
void func_0014f288(void);
void func_0015edb8(void);
void func_00165968(void);
void func_00149bd0(void*);
void func_00149de0(void*);
extern u8 D_00348d68[];
void func_00149ec0(void* p) {
    func_0015a850();
    func_00153c80();
    func_0014f148();
    func_0014f220();
    func_0014f1e0();
    func_0014f288();
    func_0015edb8();
    func_00165968();
    func_00149bd0(D_00348d68);
    func_00149de0(p);
}

void func_001666f0(u8*, u16, u32, u16, u16);
void func_0014dca8(u8* p, u16 a, u32 b, u16 c, u16 d, u16 e, u32 f) {
    func_001666f0(p, a, b, c, d);
    *(u32*)(p + 464) = f;
    *(u16*)(p + 468) = e;
    p[470] = 0;
    p[471] = 0;
    p[472] = 0;
    p[473] = 0;
}

void func_00166808(u8* p, u8 k, u16 a, u32 b, u16 c, u16 d, s16 x, s16 y) {
    func_001666f0(p, a, b, c, d);
    *(s16*)(p + 10) = x;
    *(s16*)(p + 12) = y;
    p[14] = k;
}

// RGBA bytes to a float colour normalised by 255 (VU0).
void func_00153540(f32* v, u8 r, u8 g, u8 b, u8 a) {
    v[0] = r;
    v[1] = g;
    v[2] = b;
    v[3] = a;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tmfc1 $8, %1\n\tqmtc2 $8, $vf2\n\tvdiv Q, $vf0w, $vf2x\n\tvwaitq\n\tvmulq.xyzw $vf1, $vf1, Q\n\tsqc2 $vf1, 0(%0)\n\t.set reorder"
                 : : "r"(v), "f"(255.0f) : "$8", "memory");
}

f32 func_00166d38(void*);
f32 func_00166d10(void*, u32);
void func_00154cd0(void*, s32, f32);
struct In155658 { u8 pad[4]; u32 f4; };
struct Ob155658 { u8 pad[1164]; In155658* f1164; };
struct P155658 { u8 pad[36]; void* f36; u8 pad2[12]; Ob155658* f52; };
void func_00155658(P155658* p) {
    f32 a = func_00166d38(p->f52);
    Ob155658* o = p->f52;
    void* q = p->f36;
    f32 b = func_00166d10(q, o->f1164->f4);
    func_00154cd0(p, 1, b);
    func_00154cd0(p, 2, a);
}

extern Q128 D_004f37b0, D_004f37a0, D_004f3790, D_004f3780, D_004f37e0, D_004f37d0;
static inline void qcopy(void* d, const void* s) {
    if (d != s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
}
void func_0015cff0(void) {
    qcopy(&D_004f37b0, &D_004f37a0);
    qcopy(&D_004f3790, &D_004f3780);
    qcopy(&D_004f37e0, &D_004f37d0);
}

// Finds the next entry, optionally with a matching id (-1 = any).
u8* func_0016bba8(void*, void*, u8*);
u8* func_0016bc20(void* a, void* b, s32 id) {
    u8* p = 0;
    do {
        p = func_0016bba8(a, b, p);
    } while (p && id != -1 && *p != id);
    return p;
}

void func_003058a0(s32);
void func_001707d8(void);
void func_0014d430(void);
extern volatile u8 D_0034dcac;
void func_0016f9e8(void) {
    for (;;) {
        func_003058a0(0);
        if (D_0034dcac == 1) {
            do {
                func_001707d8();
                D_0034dcac = 0;
            } while (D_0034dcac == 1);
        }
        func_0014d430();
    }
}

void func_00180c38(void*);
void func_00180ef0(void*);
typedef void (*Fn1)(void*);
void func_00180ce0(u8* p) {
    s32* r = *(s32**)(p + 328);
    if (r) {
        (*r)--;
        *(s32*)(p + 328) = 0;
    }
    func_00180c38(p);
    func_00180ef0(p);
    Fn1 f = *(Fn1*)(p + 404);
    if (f) {
        f(*(void**)(p + 8));
        *(Fn1*)(p + 404) = 0;
    }
}

void* func_0018c8b8(void);
void func_0018c960(void*, u32, u32, u32, u32);
void* func_0018c8f0(u32 a, u32 b, u32 c, u32 d) {
    void* v = func_0018c8b8();
    func_0018c960(v, a, b, c, d);
    return v;
}

struct Pair192320 { u32 a; u32 b; };
extern Pair192320 D_01c61970[3];
extern u32 D_0033caf4;
extern const char D_0036cda0[];
void func_002fee78(char*, const char*, u32);
u32 func_001b1490(const char*);
void func_00191f78(s32, u32);
void func_00192320(void) {
    char buf[48];
    for (s32 i = 0; i < 3; i++) D_01c61970[i].a = 0;
    func_002fee78(buf, D_0036cda0, D_0033caf4);
    func_00191f78(1, func_001b1490(buf));
}

struct S1964d8 { u8 a, b, c; u16 d, e, f; };
S1964d8 func_00196328(u32);
void func_001967f0(u8, u8, s32);
void func_001964d8(u32 x) {
    S1964d8 s;
    u16 m = 0xffff;
    s.a = m;
    s.b = m;
    s.c = m;
    s.d = m;
    s.e = m;
    s.f = m;
    s = func_00196328(x);
    func_001967f0(s.a, s.b, 1);
}

extern s32 D_00351f30;
extern u32 D_01d49980[];
s32 func_001c9d88(u32);
s32 func_001c9c00(void) {
    for (s32 i = 0; i < D_00351f30; i++) {
        if (!func_001c9d88(D_01d49980[i])) return 0;
    }
    return 1;
}

extern void* D_00352668;
extern u8 D_0036e3d0[];
void func_001a5420(void*, void*, void*);
void func_001d2930(void* a, s32 n) {
    if (D_00352668) {
        for (s32 i = 0; i < n; i++) func_001a5420(D_00352668, D_0036e3d0, a);
    }
}

extern const char D_0036e598[];
extern u32 D_0035276c;
u8* func_00168b88(u32, s32, u32, s32);
void func_001c10b8(u32);
void func_001d53e8(void) {
    u32 v = func_001b1490((const char*)D_0035276c);
    const char* s = D_0036e598;
    func_001c10b8(*(u32*)(func_00168b88(v, -1, s[0] | (s[1] << 8) | (s[2] << 16) | (s[3] << 24), 0) + 8));
}

struct Item1d59b0 { u8 d[60]; };
struct Tbl1d59b0 { u32 f0; s32 count; Item1d59b0 items[1]; };
extern Tbl1d59b0* D_01d5ba6c;
void func_001d5960(void*);
void func_001d59b0(void) {
    for (s32 i = 0; i < D_01d5ba6c->count; i++) func_001d5960(&D_01d5ba6c->items[i]);
}

s32 func_001db200(void*, s32);
s32 func_001db250(void*);
s32 func_001db198(void* p, s32 n) {
    switch (n) {
    case 0:
        return 1;
    case 1:
    case 2: {
        s32 r = 0;
        if (func_001db200(p, n) && func_001db250(p)) r = 1;
        return r;
    }
    }
    return 0;
}

void func_001e1728(void*);
void func_001e2238(u8* p) {
    for (s32 i = 0; i < *(s32*)(p + 3532); i++) func_001e1728(*(u8**)(p + 3528) + i * 48);
}

// Ring-buffered command queue (64 entries).
struct Q234460 { s32 type; s32 id; u32 a[6]; };
extern s32 D_0035e360;
extern s32 D_0035e368;
extern Q234460 D_01dadc00[64];
s32 func_00234460(u32 a, u32 b, u32 c, u32 d, u32 e, u32 f) {
    s32 i = D_0035e360;
    s32 id = D_0035e368;
    Q234460* q = &D_01dadc00[i];
    q->type = 11;
    q->a[0] = a;
    q->a[1] = b;
    q->a[2] = c;
    q->a[3] = d;
    q->a[4] = e;
    q->id = id;
    q->a[5] = f;
    D_0035e360 = (i + 1) & 63;
    D_0035e368 = id + 1;
    return id;
}

s32 func_002344c0(u32 a, u32 b, u32 c, u32 d, u32 e) {
    s32 i = D_0035e360;
    s32 id = D_0035e368;
    Q234460* q = &D_01dadc00[i];
    q->type = 9;
    q->a[0] = a;
    q->a[1] = b;
    q->a[2] = c;
    q->a[3] = d;
    q->id = id;
    q->a[4] = e;
    D_0035e360 = (i + 1) & 63;
    D_0035e368 = id + 1;
    return id;
}

u32 func_00168aa0(u32, s32);
void LeadDataSetText(u8* p, u32 id) {
    *(u32*)(p + 4) = id;
    *(u32*)(p + 8) = func_00168aa0(id, 28);
    *(u32*)(p + 16) = func_00168aa0(*(u32*)(p + 4), 29);
    *(u32*)(p + 12) = func_00168aa0(*(u32*)(p + 4), 25);
    *(u32*)(p + 20) = func_00168aa0(*(u32*)(p + 4), 24);
}

u8* func_00257770(void);
s32 func_00287bc0(void);
void func_0028dac8(void*, s32);
s32 func_0028acc8(void*);
s32 func_0028acb8(void*);
void func_0028aa40(void*);
extern void* D_0035f01c;
void CmItem_FadeOutTop(void*) {
    u8* b = func_00257770();
    if (func_00287bc0() == 1) {
        func_0028dac8(b, 142);
        if (func_0028acc8(D_0035f01c) && !func_0028acb8(D_0035f01c)) func_0028aa40(D_0035f01c);
    }
}

void CmItem_FadeOutWarn(void*) {
    s32 m = func_00287bc0();
    u8* b = func_00257770();
    if ((u32)(m - 11) < 4) {
        func_0028dac8(b, 298);
        func_0028dac8(b + 0xb350, 307);
    }
}

s32 func_00103b38(void);
extern s8 D_0035f348;
extern u32 D_0035f34c;
extern u32 D_0035f350;
void Select_End(void*) {
    if (func_00103b38()) func_00287f30();
    s8* c = &D_0035f348;
    if (*c) {
        (*c)--;
        return;
    }
    u32 n = D_0035f350;
    if (n) D_0035f34c = n;
    else D_0035f34c = 0;
    D_0035f350 = 0;
}

void func_001396b0(void*);
void func_00139660(void*);
void func_00139688(void*);
void func_0031a260(void*, s32);
void MenuCursor_AttachSprite(u8* p, u32 s) {
    *(u32*)(p + 396) = s;
    func_001396b0(p);
    if (*(u32*)(p + 396)) {
        *(u32*)(p + 400) = 0;
        func_001396b0(p);
        if (*(u32*)(p + 400)) func_0031a260(p, 0);
    }
    func_00139660(p);
    func_00139688(p);
    func_001396b0(p);
}

u8* func_002bc158_0(void) asm("func_002bc158");
u8* func_002bc158_1(u32) asm("func_002bc158");
void func_002bb1c8(void*, u32, u32);
void func_002bb310(void*, u32, u32, u32);
u32 func_002bc188(u32 a, u32 b) {
    u8* v = func_002bc158_0();
    if (!v) return 0;
    func_002bb1c8(v, a, b);
    return *(u32*)(v + 20);
}

u32 func_002bc2e8(u32 a, u32 b, u32 c) {
    u8* v = func_002bc158_1(a);
    if (!v) return 0;
    func_002bb310(v, a, b, c);
    return *(u32*)(v + 20);
}

void func_001dc978(void*, f32);
void* func_001de168(u32, u32, s32, s32, s32, void*);
void func_002c5658(u8* p, u32 a, u32 b) {
    if (*(void**)(p + 2552)) func_001dc978(*(void**)(p + 2552), 10.0f);
    *(void**)(p + 2552) = func_001de168(a, b, 0, 1, 0x9c41, p);
}

// Pushes a 16-byte value into a ring buffer, overwriting the oldest when full.
struct Ent2cb828 { Q128 v; u8 pad[16]; };
struct Ring2cb828 { u32 f0; s32 head; s32 cnt; s32 cap; u8 pad[112]; Ent2cb828* buf; };
Ent2cb828* func_002cb828(Ring2cb828* r, Q128* src) {
    s32 cnt = r->cnt;
    s32 head = r->head;
    s32 idx = (head + cnt) % r->cap;
    if (cnt < r->cap) r->cnt = cnt + 1;
    else r->head = head + 1;
    qcopy(&r->buf[idx].v, src);
    return &r->buf[idx];
}

void func_00110500(u8*);
Q128* func_0010fa28(u8*);
Q128* func_0010fa58(u8*);
void func_002f0af0(u8** p) {
    u8* o = *(u8**)(*p + 4);
    func_00110500(o);
    qcopy(o + 16, func_0010fa28(o));
    qcopy(o + 32, func_0010fa58(o));
}

extern void* D_0034a800[];
extern void* D_00347f98[];
extern u8 D_00347e60;
void func_002361d0(void*);
void func_00239870(void*);
typedef void (*VFn2)(void*, void*);
extern void* D_00347f80v asm("D_00347f80");
// Destructor body: unwinds the vtables and unregisters from the manager.
void func_0031cf18(u8* p) {
    *(void**)p = D_0034a800;
    func_002361d0(p + 416);
    *(void**)p = &D_00347e60;
    func_00239870(p + 24);
    *(void**)p = D_00347f98;
    void** o = *(void***)((u8*)D_00347f80v + 20);
    (*(VFn2*)((u8*)*o + 4))(o, p);
}


// Bitfield members carry the struct's alias set, so these loads stay after
// the float stores as in the original.
struct Out1fbb20 { u8 pad[32]; f32 f32_; u32 f36; f32 f40; u16 f44; };
struct In1fbb20 { u32 id; u8 pad[8]; f32 f12; u16 f16 : 16; u16 f18 : 16; };
void func_001facf8(u8*, In1fbb20*, u8*);
void func_001fbb20(u8* p, In1fbb20* q, u8* r) {
    Out1fbb20* d = (Out1fbb20*)(p + **(s32**)(r + 12) + 160);
    func_001facf8(p, q, r);
    if (q->id == *(u32*)(p + 12)) {
        d->f32_ = q->f12;
        d->f40 = q->f16;
        d->f44 = q->f18;
    }
}

void* func_001d9e30(void*);
s32 func_001d9d48(void*);
s32 func_00276c18(void);
s32 func_002b3ae8(void) {
    void* p = 0;
    s32 found = 0;
    while ((p = func_001d9e30(p)) != 0) {
        if (func_001d9d48(p)) {
            found = 1;
            break;
        }
    }
    return found || func_00276c18();
}

}
