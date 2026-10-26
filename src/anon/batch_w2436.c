#include "../common/types.h"

/* 0031b940: flag test by kind. Case 0 and case 6 are written as two bodies so
   that the shared sltu return label gets the jump alignment of the original. */
_Bool func_0031b940(void* self, s32 k, u32* fl) {
    switch (k) {
    case 1: if (*fl & 0x20) return 1; return 0;
    case 2: if (*fl & 0x40) return 1; return 0;
    case 3: if (*fl & 0x10) return 1; if (*fl & 0x80000) return 1; return 0;
    case 4: if (*fl & 0x80) return 1; return 0;
    case 5: if (*fl & 0x100) return 1; return 0;
    case 0: if (*fl & 0x10) return 1; return 0;
    case 6: if (*fl & 0x10) return 1; return 0;
    case 15: return 1;
    }
    return 1;
}

/* 00233e70: is id queued (ring of 64 entries) or current. R0 is the last block
   before the return, so it falls into the bare jr ra that the branches target. */
typedef struct Ent233e70 { s32 a; s32 b; u8 pad[24]; } Ent233e70;
extern Ent233e70 D_01dadc00[64];
extern s32 D_0035e360;
extern s32 D_0035e364;
extern s32 D_0035e36c;
extern s32 D_0035e370;

s32 func_00233e70(s32 id) {
    s32 r;
    if (id == 0) goto Z;
    {
        s32 i;
        for (i = D_0035e364; i != D_0035e360; ) {
            s32 c = i;
            i++;
            i &= 0x3f;
            if (D_01dadc00[c].b == id) goto F;
        }
    }
    if (D_0035e370 != 0) {
        if (D_0035e36c == id) { r = 1; goto RET; }
    }
    goto R0;
Z:
    if (D_0035e360 != D_0035e364) goto F;
    if (D_0035e370 == 0) goto R0;
F:
    r = 1;
    goto RET;
R0:
    r = 0;
RET:
    return r;
}

/* 0019b3d0: first child node of type-6 owner whose info flag is clear and
   whose vtable slot 2 accepts arg. */
struct N19b3d0;
struct Vt19b3d0 { void* f0; void* f4; s32 (*f8)(struct N19b3d0*, void*); };
struct I19b3d0 { u8 pad[0x2c]; u16 h2c; };
struct N19b3d0 { struct Vt19b3d0* vt; u8 pad[0x5c]; struct N19b3d0* next; u8 pad2[8]; struct I19b3d0* info; };
struct T19b3d0 { u8 type; };
struct O19b3d0 { u8 pad[8]; struct T19b3d0* t; struct N19b3d0* first; };

static inline struct N19b3d0* Next19b3d0(struct O19b3d0* o, struct N19b3d0* p) {
    return !p ? o->first : p->next;
}

struct N19b3d0* func_0019b3d0(struct O19b3d0* o, void* arg) {
    struct N19b3d0* r;
    struct N19b3d0* p;
    if (o->t->type == 6) goto L;
    r = 0;
RET:
    return r;
L:
    p = 0;
    while ((p = Next19b3d0(o, p)) != 0) {
        if (p->info->h2c == 0 && p->vt->f8(p, arg)) { r = p; goto RET; }
    }
    r = 0;
    goto RET;
}
