#include "../common/types.h"
extern "C" {
struct W1632Seq { u8 pad[344]; };
struct W1632Rect { u8 pad[256]; };
struct W1632Sprite2 {
    u8 pad0[24];
    W1632Seq seq;       // 24
    u8 pad1[24];
    s32 f392;           // 392
    void* parent;       // 396
    s32 flag;           // 400
    u8 pad2[8];
};
struct W1632Gauge {
    u8 pad0[32];
    W1632Rect r1;       // 32
    u8 pad1[32];
    W1632Rect r2;       // 320
    void* owner;        // 576
    u8 pad2[12];
};
struct W1632Party {
    u8 pad0[24];
    s32 f24;                    // 24
    u8 pad1[20];
    s32 f48;                    // 48
    s32 f52;                    // 52
    u8 pad2[8];
    W1632Sprite2 head;          // 64
    u8 pad3[916 - 64 - 412];
    W1632Sprite2 spr[4];        // 916
    u8 pad4[2576 - 916 - 4 * 412];
    W1632Gauge g[5];            // 2576
    u8 b[3];                    // 5536
};
void func_00158138(W1632Party*, u32, u32, s32);
u32 func_0013a7e8(s32);
u32 func_0013d7e0(void);
u32 func_00158290(W1632Party*);
void func_00158050(W1632Sprite2*, u32, u32, u32, u32, u32, u32);
void func_0013e0f8(W1632Gauge*, u32, u32, u32);
void func_001581f8(W1632Party*);
void func_00153fa0(W1632Sprite2*, u32, s32, s32, s32, u32);
u32 func_00139d78(void*);
void func_0014b208(W1632Rect*, u32, u32);
void func_0014b200(W1632Rect*, u32);
void func_001396b0(void*);
void func_0031a260(void*, u32);
void func_001395e8(void*);
void func_00139610(void*);
s32 func_00154ee8(W1632Party*);
s32 func_0023aa98(W1632Seq*);
void func_00138c40(void*, s32, s32);
void func_001582a8(W1632Party*);

static inline void W1632_setParent2(W1632Sprite2* obj, W1632Sprite2* parent) {
    obj->parent = parent;
    func_001396b0(obj);
    if (obj->parent != 0) {
        obj->flag = 0;
        func_001396b0(obj);
        if (obj->flag != 0) {
            func_0031a260(obj, 0);
        }
    }
}

static inline void W1632_setParent2b(W1632Sprite2* obj, W1632Sprite2* parent) {
    obj->parent = parent;
    asm volatile("" ::: "memory");
    func_001396b0(obj);
    if (obj->parent != 0) {
        obj->flag = 0;
        func_001396b0(obj);
        if (obj->flag != 0) {
            func_0031a260(obj, 0);
        }
    }
}

void func_00154f30(W1632Party* self, u32 a1, u32 a2) {
    u32 tex, img, grp;
    s32 i, j;
    W1632Sprite2* root = &self->spr[0];
    W1632Gauge* g;
    func_00158138(self, a1, a2, 1);
    tex = func_0013a7e8(1);
    img = func_0013d7e0();
    grp = func_00158290(self);
    self->b[0] = 0;
    self->b[1] = 0;
    self->b[2] = 0;
    func_00158050(&self->spr[0], 7000, tex, img, 71, 0, grp);
    func_0013e0f8(&self->g[0], 7000, 0, grp);
    func_0013e0f8(&self->g[1], 7000, 1, grp);
    func_00158050(&self->spr[1], 7000, tex, img, 64, 100, grp);
    func_0013e0f8(&self->g[2], 7000, 1, grp);
    func_00158050(&self->spr[2], 7000, tex, img, 65, 1000, grp);
    func_0013e0f8(&self->g[3], 7000, 0, grp);
    func_0013e0f8(&self->g[4], 7000, 1, grp);
    func_00158050(&self->spr[3], 7000, tex, img, 66, 10000, grp);
    func_001581f8(self);
    {
        s32 c = self->f24;
        func_00153fa0(&self->head, 7000, self->f48 + 1, self->f52, c, grp);
    }
    func_00139d78(&self->g[0]);
    func_0014b208(&self->g[0].r1, 64, 64);
    func_00139d78(&self->g[3]);
    func_0014b208(&self->g[3].r1, 64, 64);
    func_00139d78(&self->g[0]);
    func_0014b200(&self->g[0].r1, 0);
    func_0014b200(&self->g[0].r2, 0);
    func_00139d78(&self->g[3]);
    func_0014b200(&self->g[3].r1, 0);
    func_0014b200(&self->g[3].r2, 0);
    func_00139d78(&self->g[1]);
    func_0014b200(&self->g[1].r1, 200);
    func_0014b200(&self->g[1].r2, 200);
    func_00139d78(&self->g[2]);
    func_0014b200(&self->g[2].r1, 2000);
    func_0014b200(&self->g[2].r2, 2000);
    func_00139d78(&self->g[4]);
    func_0014b200(&self->g[4].r1, 20000);
    func_0014b200(&self->g[4].r2, 20000);
    for (i = 0; i < 4; i++) {
        W1632_setParent2(&self->spr[i], root);
        func_001395e8(&self->spr[i]);
        func_00139610(&self->spr[i]);
    }
    for (j = 0; j < 5; j++) {
        g = &self->g[j];
        func_00139d78(g);
        g->owner = root;
    }
    W1632_setParent2b(&self->head, root);
    W1632_setParent2(root, 0);
    root->f392 = func_00154ee8(self);
    func_00138c40(root, 0, func_0023aa98(&self->spr[0].seq) * self->f48);
    func_001582a8(self);
}

struct W1632Sprite {
    u8 pad0[24];
    W1632Seq seq;       // 24
    u8 pad1[28];
    void* parent;       // 396
    s32 flag;           // 400
    u8 pad2[4];
};
struct W1632Bar {
    u8 pad0[32];
    W1632Rect r;        // 32
    u8 pad1[32];
    void* owner;        // 320
};
struct W1632Panel {
    u8 pad0[916];
    W1632Sprite icon;           // 916
    u8 pad1[6704 - 916 - 408];
    W1632Sprite2 frame;         // 6704
    u8 pad2[11648 - 6704 - 412];
    W1632Sprite2 spr[3];        // 11648
    u8 pad3[12896 - 11648 - 3 * 412];
    W1632Bar bar;               // 12896
};
u32 func_00155ee8(W1632Panel*);
u32 func_00155fc0(W1632Panel*);
u32 func_00155e30(W1632Panel*);
s32 func_00155f40(W1632Panel*);
s32 func_00156030(W1632Panel*);
void func_00156408(W1632Panel*);
void func_00158050(W1632Sprite2*, u32, u32, u32, u32, u32, u32);
void func_0013dfb8(W1632Bar*, u32, u32);
void func_001386e0(W1632Sprite*, u32, u32, u32, u32, u32);
u32 func_00139d78(void*);
void func_0014b200(W1632Rect*, u32);
void func_001396b0(void*);
void func_0031a260(void*, u32);
void func_001395e8(void*);
void func_00139610(void*);
void func_00139598(void*);
s32 func_0023aa18(W1632Seq*);
s32 func_0023aa38(W1632Seq*);
void func_00138c68(void*, s32, s32);
void func_00138c10(void*, s32);

static inline void W1632_link2(W1632Sprite2* obj, void* parent) {
    obj->parent = parent;
    func_001396b0(obj);
    if (obj->parent != 0) {
        obj->flag = 0;
        func_001396b0(obj);
        if (obj->flag != 0) {
            func_0031a260(obj, 0);
        }
    }
}

static inline void W1632_link(W1632Sprite* obj, void* parent) {
    obj->parent = parent;
    func_001396b0(obj);
    if (obj->parent != 0) {
        obj->flag = 0;
        func_001396b0(obj);
        if (obj->flag != 0) {
            func_0031a260(obj, 0);
        }
    }
}

void func_00156130(W1632Panel* self, u32 tex, u32 img, u32 grp) {
    s32 i;
    s32 x, y;
    W1632Sprite2* head;
    W1632Bar* bar;
    func_00158050(head = &self->spr[0], 7000, tex, img, func_00155ee8(self), 0, grp);
    bar = &self->bar;
    func_0013dfb8(bar, 7000, grp);
    func_00158050(&self->spr[1], 7000, tex, img, func_00155fc0(self), 5000, grp);
    func_00158050(&self->spr[2], 7000, tex, img, func_00155e30(self), 0, grp);
    func_001386e0(&self->icon, 7010, tex, img, 20, grp);
    func_00139d78(bar);
    func_0014b200(&bar->r, 6000);
    for (i = 0; i < 3; i++) {
        W1632_link2(&self->spr[i], &self->frame);
        func_001395e8(&self->spr[i]);
        func_00139610(&self->spr[i]);
    }
    W1632_link2(&self->spr[1], head);
    W1632_link2(&self->spr[2], head);
    func_00139d78(bar);
    bar->owner = head;
    W1632_link(&self->icon, head);
    func_00139598(&self->icon);
    x = func_0023aa18(&self->spr[0].seq);
    y = func_0023aa38(&self->spr[0].seq);
    func_00138c68(&self->spr[2], x, y);
    head->f392 = func_00155f40(self);
    if (func_00156030(self)) {
        func_00138c10(head, 18);
        head->f392 = func_00155f40(self);
    }
    func_00156408(self);
}
}
