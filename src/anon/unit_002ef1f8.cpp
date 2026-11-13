#include "../common/types.h"

// 0x2ef1f8-0x2ef6b0: menu::LayoutWidget (graphics/message resources at +40/+64) and a layout
// sequence player (YI::SEQUENCE at +468 with a 4-entry request queue at +812). Linked unit.

struct LayoutRes2ef258 {
    virtual void f();
    u32 a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14;
    f32 b, c, d, e;
    u32 g;
    u8 h;
    u32 i, j;
};
struct Pos2ef340 { u32 x, y; };
struct Rgba2ef340 { u8 r, g, b, a; };

extern "C" {
void func_00236a58(void*, void*, u32);
void func_0023c100(void*, void*, void*, u32);
void func_0023ca80(void*, void*);
void func_0023cc18(void*);
void func_002362b0(void*, u32);
void func_00239988(void*, u32, void*);
void* func_00236ca8(u32, u32);
u32 func_0023c4b8(void*, u32);
void func_0023acd8(void*);
s32 func_00239d10(void*);
void func_002367c8(void*);
void func_00236788(void*);
void func_00239fd0(void*, f32, f32, f32, f32);
void func_0023ade0(void*);
void func_00239bf8(void*, s32);
void func_0023a9c0(void*, s32*, s32*);
u32 func_0023a918(void*);
extern u32 D_00363898;
}

namespace menu {
struct LayoutWidget {
    u8 pad0[36];
    u32 id;          // +36
    u8 gra[24];      // +40
    u8 mes[4];       // +64
    void initialize(void* mes_res, void* gra_res);
};

void LayoutWidget::initialize(void* mes_res, void* gra_res) {
    func_00236a58(gra, gra_res, id);
    func_0023c100(mes, mes_res, gra, id);
}
}

extern "C" {

void func_002ef258(u8* d, LayoutRes2ef258* s) {
    *(LayoutRes2ef258*)(d + 64) = *s;
}

void func_002ef328(u8* p, void* a) {
    func_0023ca80(p + 64, a);
}

void func_002ef618(void);

void func_002ef340(u8* t, Pos2ef340 a, Rgba2ef340 b) {
    func_0023cc18(t + 64);
    func_002ef618();
}

struct ReqQueue2ef370 {
    s32 w[6];            // write index, read index, 4 requests
    void clear() { w[0] = 0; w[1] = 0; }
    void push(s32 id) {
        s32 i = w[0];
        w[0] = (i + 1) % 4;
        w[2 + i] = id;
    }
    bool empty() { return w[1] == w[0]; }
    s32 pop() {
        s32 i = w[1];
        s32* e = (w + 2) + i;
        w[1] = (i + 1) % 4;
        return *e;
    }
};

struct SeqPlayer2ef370 {
    u32 pad0;
    u32 flags;           // +4
    u8 pad8[28];
    u32 f36;
    u32 f40;
    u8 pad44[4];
    u8 image[416];       // +48
    void* cur;           // +464
    u8 seq[328];         // +468
    Pos2ef340 pos;       // +796
    u8 pad804[8];
    ReqQueue2ef370 queue; // +812
};

void func_002ef370(SeqPlayer2ef370* s, u32* a) {
    u32 v = a[0];
    s->f36 = v;
    s->f40 = a[1];
    func_002362b0(s->image, v);
    s->cur = s->image;
    func_00239988(s->seq, s->f40, s->image);
}

void func_002ef3c8(SeqPlayer2ef370* s, u8* layout, u32 img, u32 unit) {
    s->cur = func_00236ca8(*(u32*)(layout + 40), img);
    func_00239988(s->seq, func_0023c4b8(layout, unit), s->cur);
}

void func_002ef5c8(SeqPlayer2ef370* s, s32 id);

s32 seq_2ef438(SeqPlayer2ef370* s) {
    if (s->flags & 4) return 0;
    func_0023acd8(s->seq);
    if (func_00239d10(s->seq) == 0) {
        ReqQueue2ef370* q = &s->queue;
        if (!q->empty()) {
            s32 id = q->pop();
            if (id == -1) {
                s->flags |= 4;
                return 0;
            }
            func_002ef5c8(s, id);
        }
    }
    return 1;
}

void seq_2ef4f8(SeqPlayer2ef370* s, Pos2ef340 pos, Rgba2ef340 c) {
    func_002367c8(s->cur);
    func_00236788(s->cur);
    u8* q = s->seq;
    func_00239fd0(q, c.r * 0.0078125f, c.g * 0.0078125f, c.b * 0.0078125f, c.a * 0.0078125f);
    *(Pos2ef340*)(q + 328) = pos;
    func_0023ade0(q);
}

void func_002ef5a8(SeqPlayer2ef370* s, s32 id) {
    s->queue.clear();
    func_002ef5c8(s, id);
}

void func_002ef5c8(SeqPlayer2ef370* s, s32 id) {
    func_00239bf8(s->seq, id);
}

void seq_2ef5e0(SeqPlayer2ef370* s, s32 id) {
    s->queue.push(id);
}

void func_002ef618(void) {
    D_00363898 = 0;
}

struct XY2ef628 { s32 x, y; };

XY2ef628 func_002ef628(SeqPlayer2ef370* s) {
    XY2ef628 r;
    func_0023a9c0(s->seq, &r.x, &r.y);
    return r;
}

Rgba2ef340 func_002ef660(SeqPlayer2ef370* s) {
    Rgba2ef340 c;
    u32 v = func_0023a918(s->seq);
    c.r = v;
    c.g = v >> 8;
    c.b = v >> 16;
    c.a = v >> 24;
    return c;
}

}
