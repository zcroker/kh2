#include "../common/types.h"

/* Plain C (partMng / pppPart range), built with -fno-strict-aliasing. */

/* ---- 001f01b8: add an offset vector to a part's position, then refresh it */
typedef struct { s32 x, y, z, w; } W2381Vec;
typedef struct { u8 pad[0xa0]; W2381Vec pos; } W2381Part;
typedef struct { s32 id; W2381Vec d; } W2381Move;
typedef struct { u32 p0, p4, p8; s32 id; } W2381Owner;
typedef struct { u32 p0, p4, p8; s32* off; } W2381Desc;
typedef struct { u64 f0:8; u64 f1:8; u64 f2:16; u64 f4:8; u64 f5:24; } W2381Bits;
typedef struct { u8 pad[0xa8]; W2381Bits b; } W2381Mng;
extern s32 D_01d9ea9c;
extern W2381Mng* D_01d9e6e0;
void func_001f0080(W2381Move*, W2381Vec*);
void func_001f00f8(W2381Vec*);

void func_001f01b8(W2381Owner* o, W2381Move* m, W2381Desc* d)
{
    W2381Vec* v = &((W2381Part*)((u8*)o + *d->off))->pos;
    if (D_01d9ea9c == 0 && D_01d9e6e0->b.f1 == 0 && D_01d9e6e0->b.f4 == 0) {
        if (v->w == 0) func_001f0080(m, v);
        if (m->id == o->id) {
            v->x += m->d.x;
            v->y += m->d.y;
            v->z += m->d.z;
            func_001f00f8(v);
        }
    }
}

/* ---- 001e7698: pppAlloc - first-fit allocation of 16-byte-headed blocks, walking back from the
   last allocation; splits the block from its tail when the remainder is at least one header. */
typedef struct W2381Blk { struct W2381Blk* next; struct W2381Blk* prev; s32 used; s32 pad; } W2381Blk;
typedef struct { W2381Blk* cur; W2381Blk* first; W2381Blk* last; s32 total; } W2381Heap;
extern char D_0036ef40[]; /* "pppAlloc error size=%d\n" */
extern void (*D_00352c3c)(void);
void func_002fdfc8(const char*, ...);
void* w2381_pppAlloc(W2381Heap* h, s32 size) asm("_Z13func_001e7698Pv");
void* w2381_pppAlloc(W2381Heap* h, s32 size)
{
    s32 one;
    W2381Blk* b;
    W2381Blk* nx;
    W2381Blk* nb;
    size = ((size + 15) & ~15) + 16;
    one = 1;
    if (h->cur) b = h->cur->next;
    else { W2381Blk* f = h->first; b = f->next; h->cur = f; }
    for (;;) {
        W2381Blk* p = b->prev;
        if (p == 0) {
            if (h->cur == 0) {
                func_002fdfc8(D_0036ef40, size);
                if (D_00352c3c) D_00352c3c();
                return 0;
            }
            h->cur = 0;
            b = h->last;
            continue;
        }
        b = p;
        if (b->used) continue;
        nx = b->next;
        if ((s32)nx - (s32)b >= size) break;
    }
    h->total += size;
    nb = (W2381Blk*)((u8*)b->next - size);
    if (nb != b && (u32)((u8*)nb - (u8*)b) >= 16) {
        h->cur = b;
        nb->next = nx; nb->prev = b;
        b->next = nb; nx->prev = nb;
        b = nb;
    } else h->cur = 0;
    b->used = one;
    b++;
    return b;
}
