#include "../common/types.h"
// Built with -fno-strict-aliasing -fmove-all-movables (_nsamam).

// 00141c38: tree walk collecting leaf indices whose boxes overlap a query box.
// Partial asm: two empty asm uses (nd before the child loop, ne at the end) steer which values stay in saved registers.
struct TNode { s16 child[8]; u8 box[12]; u16 first; u16 end; };
struct TItem { u8 box[12]; u16 lo; u16 hi; u8 on; u8 pad[3]; };
struct TLeaf { u8 pad[12]; u16 c; u16 idx; };
struct TBox { u8 b[12]; };
struct Tree {
  u8 pad0[4]; TNode* nodes; TItem* items; TLeaf* leafs; u8 pad16[4]; s32* flags; u8 pad24[4]; TBox* boxes; // 0..32
  u8 pad32[60-32]; u16* out; s32 mask; s32 val; // 60,64,68
  u8 pad72[208-72]; u8 mode; u8 pad209; u8 b210; u8 b211;
};
extern "C" {
s32 func_00145580(void*, void*);
s32 func_0031b940(Tree*, s32, s32*);
static inline bool okf(Tree* t, s32* f) {
  if (t->mode == 1) return (*f & t->mask) != t->val;
  return (*f & t->mask) == t->val;
}
static inline bool skf(Tree* t, s32* f) {
  bool sk = false;
  if (t->b211 && t->b210) sk = (*f & 0xf) == 5;
  return sk;
}

void func_00141c38(Tree* t, s32 n, void* box, u16* cnt, s32 arg) {
  TNode* nd = &t->nodes[n];
  if (!func_00145580(nd->box, box)) return;
   
  s32 ne = nd->end;
  for (s32 i = nd->first; i < ne; i++) {
    TItem* it = &t->items[i];
    if (it->on && func_00145580(it, box)) {
      s32 end = it->hi;
      for (s32 j = it->lo; j < end; j++) {
        TLeaf* lf = &t->leafs[j];
        s32* f = &t->flags[lf->idx];
        if (okf(t, f)) {
          if (skf(t, f) || func_0031b940(t, arg, f)) {
            if (lf->c == 0xffff || func_00145580(&t->boxes[lf->c], box)) {
              if (*cnt >= 1023) return;
              t->out[*cnt] = j;
              (*cnt)++;
            }
          }
        }
      }
    }
  }
  asm("" : : "r"(nd));
  s16* c = nd->child;
  s32 m;
  for (m = 0; m < 8; m++) {
    s32 k = *c++;
    if (k == -1) return;
    func_00141c38(t, k, box, cnt, arg);
  }
    asm("" : : "r"(ne));
}
}

// 0020ab48: effect emitter update (advance animation frames, spawn new parts).
// Partial asm: empty ties make the call-argument copies die at the argument moves (sched1 reg weight), a pin keeps nf in t1.
extern "C" {
typedef struct EfFrame { u16 pad0; u16 duration; s8 flags; u8 pad5[3]; } EfFrame;
typedef struct EfAnim { u8 pad0[6]; s16 count; u8 pad8[8]; EfFrame frames[1]; } EfAnim;
typedef struct EfAnimRef { EfAnim* anim; u32 pad; } EfAnimRef;
typedef struct EfBank { u8 pad0[0x14]; EfAnimRef* anims; } EfBank;
typedef struct EfState { u8 pad0[0xa8]; u64 flags; } EfState;
typedef struct EfDef { u32 pad0; s32 anim; u16 speed; u8 padA[6]; u16 maxSpawn; u16 interval; } EfDef;
typedef struct EfPart { u8 pad0[0x20]; u16 time; u16 frame; u16 curFrame; u16 active; u8 pad28[0x38]; } EfPart;
typedef struct EfEmitter { EfPart* parts; u8* work; s32 count; u8 padC[4]; u16 timer; } EfEmitter;
extern s32 D_01d9ea9c;
extern EfState* D_01d9e6e0;
extern EfBank* D_01d9e6e4;
void func_0020a658(EfEmitter* e, EfDef* def, EfPart* p, u32 a3, u8* w);
void func_0020a510(EfEmitter* e, EfDef* def, EfPart* p, u8* w);

void func_0020ab48(EfEmitter* e, EfDef* def, u32 arg2) {
    s32 i;
    s32 spawned = 0;
    EfPart* p = e->parts;
    u8* w = e->work;
    s32 n = e->count;
    if (D_01d9ea9c != 0) return;
    if (D_01d9e6e0->flags & 0xff0000ff00ULL) return;
    if (def->anim == 0xffff) return;
    e->timer++;
    for (i = 0; i < n; i++) {
        if (p->active) {
            EfAnim* anim;
            EfFrame* f;
            u16 frame;
            s32 sum, rem, dur; register s32 nf asm("$9"); u16 n16;
            { EfPart* q = p; asm("" : "+r"(q)); func_0020a658(e, def, q, arg2, w); }
            { EfAnimRef* r = D_01d9e6e4->anims; r += def->anim; anim = r->anim; }
            frame = p->frame;
            nf = frame + 1;
            f = &anim->frames[p->curFrame];
            p->curFrame = frame;
            sum = p->time + def->speed;
            p->time = sum;
            dur = f->duration;
            rem = sum - dur;
            dur = (s16)dur;
            n16 = nf;
            if ((u16)sum >= dur) {
                p->time = rem;
                p->frame = nf;
                if (n16 >= anim->count) {
                    if (f->flags & 0x80) p->frame = 0;
                    else p->frame = frame;
                    p->time = 0;
                }
            }
        } else if (def->interval <= e->timer && spawned < def->maxSpawn) {
            { EfPart* q = p; u8* ww = w; asm("" : "+r"(q)); asm("" : "+r"(ww)); func_0020a510(e, def, q, ww); asm("" : "+r"(spawned)); spawned++; }
        }
        p++;
        if (w) w += 32;
    }
    if (spawned > 0) e->timer = 0;
}

}
