#include "../common/types.h"

/* particle effect slot table: copy each slot's value out and run its callback */
typedef struct PartVt { u8 pad[0x1c]; void (*f1c)(void*, void*); void (*f20)(void*, void*); } PartVt;
typedef union { PartVt* v; s32 w[4]; } PartEnt;
typedef struct { u8 pad[0x20]; s32 off; s32 x24:16; s32 n:16; PartEnt ent[1]; } PartHdr;
typedef struct { s32 x0, x4; PartHdr** x8; } PartObj;

void func_001e7948(PartObj* a) {
  PartHdr* h = *a->x8;
  s32* out = (s32*)((u8*)a + h->off);
  s32 i;
  for (i = 0; i < h->n; i++) {
    PartEnt* e = &h->ent[i];
    PartVt* v = e->v;
    *out++ = e->w[2];
    if (v && v->f20) v->f20(a, e);
  }
}

void func_001e79f0(PartObj* a) {
  PartHdr* h = *a->x8;
  s32* out = (s32*)((u8*)a + h->off);
  s32 i;
  for (i = 0; i < h->n; i++) {
    PartEnt* e = &h->ent[i];
    PartVt* v = e->v;
    *out++ = e->w[2];
    if (v && v->f1c) v->f1c(a, e);
  }
}
