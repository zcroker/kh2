#include "../common/types.h"
// 0019a808: -fno-strict-aliasing keeps the u16 load after the v.xyz stores; integer address math gives the idx-first addu.
#define W1965cQCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct W1965cV {
    f32 x, y, z, w;
    W1965cV() {}
    W1965cV(const W1965cV& o) { W1965cQCOPY(this, &o); }
    W1965cV& operator=(const W1965cV& o) { if (this != &o) W1965cQCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct W1965cHdr { u8 pad[24]; u8 type; u8 mode; u16 id; };
struct W1965cEnt { s32 a; f32 x, y, z; u8 pad[12]; u8 type; u8 mode; u16 id; u8 pad2[10]; u16 delay; u8 pad3[2]; u16 r; u8 lvl; u8 pad4[15]; };
struct W1965cTbl { u8 pad[4]; u16 count; u8 pad2[38]; W1965cEnt ent[1]; };
struct W1965cObj { u8 pad[8]; W1965cTbl* tbl; u8 pad2[8]; f32 timer; u8 pad3[8]; u8 level; };
extern "C" {
extern u8 D_0034f250[];
s32 func_0016b7a0(u16);
s32 func_00195700(u8*, u16);
s32 func_00199890(W1965cEnt*, W1965cObj*, W1965cV*);
s32 func_00199938(W1965cEnt*, W1965cObj*);
s32 func_0019ac80(W1965cObj*);
W1965cV func_0019afd8(s32);
W1965cV func_0019b0e8(s32, W1965cV*, f32, f32);
void func_0019a808(W1965cObj* o)
{
    s32 i;
    do {
        do {
            for (i = 0; i < o->tbl->count; i++) {
                if (0.0f < o->timer) return;
                W1965cHdr* s = (W1965cHdr*)((i << 6) + (u32)o->tbl + 48);
                u8 type = s->type;
                u16 id = s->id;
                if (type == 2) {
                    s32 r;
                    if (func_0016b7a0(id)) continue;
                    if (func_00195700(D_0034f250, id)) continue;
                    if (o->level < o->tbl->ent[i].lvl) continue;
                    W1965cV v;
                    switch (o->tbl->ent[i].mode) {
                    case 1:
                        v = func_0019afd8(o->tbl->ent[i].a);
                        r = func_00199890(&o->tbl->ent[i], o, &v);
                        break;
                    case 2:
                        v.x = o->tbl->ent[i].x;
                        v.y = o->tbl->ent[i].y;
                        v.z = o->tbl->ent[i].z;
                        v = func_0019b0e8(o->tbl->ent[i].a, &v, (f32)o->tbl->ent[i].r, 0.0f);
                        r = func_00199890(&o->tbl->ent[i], o, &v);
                        break;
                    case 0:
                    default:
                        r = func_00199938(&o->tbl->ent[i], o);
                        break;
                    }
                    if (r) o->timer = (f32)o->tbl->ent[i].delay;
                }
            }
        } while (!(o->timer <= 0.0f));
    } while (func_0019ac80(o));
}
}
