#include "../common/types.h"

// 0x2ee8a8-0x2ef1f8: a model view object (model, light/camera block at +80, a motion sequencer at
// +456 with a 4-entry request queue). Linked unit. The vtable (0x363860) stays retail data; the
// constructors and destructors are written as plain functions.

struct VObj;
struct VObjVt { void* a; void* b; s32 (*get)(VObj*); };
struct VObj { VObjVt* vt; };
struct Ent2eef08 { u8 pad[8]; u32 v; };
struct V4 {
    f32 x, y, z, w;
    void set(f32 a, f32 b, f32 c, f32 d) { x = a; y = b; z = c; w = d; }
};
struct DrawArgX { u32 a; u16 b; };
struct DrawArgY { u16 a; u8 b; };

extern "C" {
extern u8 D_00363860[];
extern u8 D_003637e0[];
extern f32 D_00349e10;
void func_002edf28(u8*);
void func_001a91f8(u8*);
void func_001a92d8(u8*, u32, s32);
void func_00106ab8(u8*);
void func_00108698(u8*);
void** func_001a93e8(u8*);
u32 func_001a9420(u8*);
void func_0011e260(u32, u32);
void func_00106d40(u8*, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32, f32);
void func_00106c08(u8*);
void func_0011b6a8(u8*);
void func_00106ac8(u8*);
void func_001a9350(u8*);
void func_00106420(u8*);
void func_0011ea40(s32, f32);
void func_0011c4e8(s32, void*, s32, s32, s32, s32, f32);
void func_0011cdf0(s32, void*, void*, void*, s32);
void sceGsSyncPath(s32, s32);
void func_0011ea98(s32, s32);
Ent2eef08* func_00168b38(u32, s32, s32);
void func_00189f20(u32, void (*)(u8*, u8*), u32, f32);
void func_0018a008(u32, s32 (*)(u8*), void*, f32, f32);
s32 func_002bc1e8(s32);
}

struct QEnt2ee8a8 { u32 id; f32 len; };
struct SeqQ2ee8a8 {
    s32 w[2];            // write index, read index
    QEnt2ee8a8 q[4];
};
struct Seq2ee8a8 {
    u32 busy : 1;
    u32 rest : 31;
    u8* user;            // +4
    VObj* src;           // +8
    u32 target;          // +12
    f32 t;               // +16
    f32 len;             // +20
    SeqQ2ee8a8 queue;    // +24
};

extern "C" {

void func_002eeee8(Seq2ee8a8* s, u8* user);
void func_002eef08(Seq2ee8a8* s, u32 id, f32 len);
void func_002ef180(Seq2ee8a8* s, f32 from, f32 to);
void func_002ef028(Seq2ee8a8* s, f32 dt);

static inline void ViewInit(u8* p, u32 a, u32 b) {
    func_002edf28(p);
    *(u32*)(p + 40) = a;
    *(u32*)(p + 36) = 0;
    *(u32*)p = (u32)D_00363860;
    func_001a91f8(p + 44);
    func_001a92d8(p + 44, b, 0);
    func_00106ab8(p + 80);
    func_00108698(p + 400);
    func_002eeee8((Seq2ee8a8*)(p + 456), p);
    void** v = func_001a93e8(p + 44);
    *(u32*)(p + 68) = ((u32 (*)(void*, u32))(*(void***)v)[9])(v, *(u32*)(p + 40));
    u32 s = func_001a9420(p + 44);
    func_0011e260(*(u32*)(p + 68), s);
    *(u32*)(p + 436) = s;
    *(u8*)(p + 408) = 0x80;
    *(u8*)(p + 409) = 0x80;
    *(u8*)(p + 410) = 0x80;
    *(f32*)(p + 432) = 80000.0f;
    *(u32*)(p + 400) |= 2;
    *(u8*)(p + 411) = 0xff;
    func_00106d40(p + 80, 512.0f, 0.799999952f, 0.866666615f, 2048.0f, 2048.0f, 1.0f, 16770000.0f, 1.0f, 4000000.0f, 256.0f, 208.0f);
    func_00106c08(p + 80);
    func_0011b6a8(p + 336);
    ((V4*)(p + 384))->set(0.0f, 0.0f, 500.0f, 1.0f);
}

void func_002ee8a8(u8* p, u32 a, u32 b) {
    ViewInit(p, a, b);
}

void func_002eea80(u8* p, u32 a, u32 b) {
    ViewInit(p, a, b);
}

static inline void ViewFini(u8* p) {
    *(u32*)p = (u32)D_00363860;
    void** v = func_001a93e8(p + 44);
    ((void (*)(void*, u32, u32))(*(void***)v)[10])(v, *(u32*)(p + 40), *(u32*)(p + 68));
    func_00106ac8(p + 80);
    func_001a9350(p + 44);
    *(u32*)p = (u32)D_003637e0;
}

void func_002eec58(u8* p) {
    ViewFini(p);
}

void func_002eecd0(u8* p) {
    ViewFini(p);
}

void func_002eed48(u8* p) {
    ViewFini(p);
    func_00106420(p);
}

void func_002eefa8(Seq2ee8a8* s, u32 id, f32 len);
void func_002eefc8(Seq2ee8a8* s, u32 id, f32 len);

void func_002eedc0(u8* p, u32 id, f32 len) {
    func_002eefa8((Seq2ee8a8*)(p + 456), id, len);
}

void func_002eedd8(u8* p, u32 id, f32 len) {
    func_002eefc8((Seq2ee8a8*)(p + 456), id, len);
}

s32 func_002eedf0(u8* p) {
    f32 t = D_00349e10;
    Seq2ee8a8* s = (Seq2ee8a8*)(p + 456);
    func_002ef028(s, t);
    func_0011ea40(*(s32*)(p + 68), t);
    f32 y = s->t;
    s32 x = (s32)s->src;
    func_0011c4e8(*(s32*)(p + 68), p + 336, x, 0, 0, 0, y);
    return 1;
}

void func_002eee68(u8* p, DrawArgX x, DrawArgY y) {
    func_0011cdf0(*(s32*)(p + 0x44), p + 0x50, p + 0x150, p + 0x190, 0);
    sceGsSyncPath(0, 0);
}

void func_002eeeb0(u8* p, s32 id) {
    func_0011ea98(*(s32*)(p + 68), id);
}

static inline void SeqInit(Seq2ee8a8* s, u8* user) {
    s->user = user;
    *(u32*)s = 0;
    s->src = 0;
    s->t = 0;
    s->len = 0;
    s->queue.w[0] = 0;
    s->queue.w[1] = 0;
}

void seq_2eeec8(Seq2ee8a8* s, u8* user) {
    SeqInit(s, user);
}

void func_002eeee8(Seq2ee8a8* s, u8* user) {
    SeqInit(s, user);
}

void func_002eef08(Seq2ee8a8* s, u32 id, f32 len) {
    s->src = (VObj*)func_00168b38(id, 9, 0)->v;
    s->target = func_00168b38(id, 16, 0)->v;
    VObj* o = s->src;
    s->t = len;
    s->len = (f32)o->vt->get(o);
    func_002ef180(s, len, -1.0f);
}

void func_002eefa8(Seq2ee8a8* s, u32 id, f32 len) {
    s->queue.w[0] = 0;
    s->queue.w[1] = 0;
    func_002eef08(s, id, len);
}

void func_002eefc8(Seq2ee8a8* s, u32 id, f32 len) {
    SeqQ2ee8a8* q = &s->queue;
    if (!s->src) {
        func_002eef08(s, id, len);
        return;
    }
    s32 i = q->w[0];
    q->w[0] = (i + 1) % 4;
    QEnt2ee8a8* e = (QEnt2ee8a8*)((u8*)q + 8) + i;
    e->id = id;
    e->len = len;
}

void seq_2ef148(u8* ev, u8* user);

void func_002ef028(Seq2ee8a8* s, f32 dt) {
    if (!s->src) return;
    if (!s->busy) {
        f32 old = s->t;
        s->t = old + dt;
        func_002ef180(s, old, s->t);
        if (s->t >= s->len) {
            SeqQ2ee8a8* q = &s->queue;
            s32 h = q->w[1];
            if (h != q->w[0]) {
                q->w[1] = (h + 1) % 4;
                QEnt2ee8a8* e = (QEnt2ee8a8*)((u8*)q + 8) + h;
                func_002eef08(s, e->id, e->len);
            } else {
                f32 l = ((f32 (*)(VObj*))((void**)s->src->vt)[7])(s->src);
                s->t = s->t - s->len + l;
                func_002ef180(s, l, s->t);
            }
        }
    }
    if (s->target) func_00189f20(s->target, seq_2ef148, (u32)s->user, dt);
    s->busy = 0;
}

void seq_2ef148(u8* ev, u8* user) {
    if (ev[4] == 23)
        func_002eeeb0(user, *(u16*)(ev + 6));
}

s32 seq_2ef1b8(u8* ev);

void func_002ef180(Seq2ee8a8* s, f32 from, f32 to) {
    if (s->target) func_0018a008(s->target, seq_2ef1b8, s, from, to);
}

s32 seq_2ef1b8(u8* ev) {
    s32 r;
    if (ev[2] == 8)
        r = func_002bc1e8(*(u16*)(ev + 4) * 1000 + *(u16*)(ev + 6));
    return r;
}

}
