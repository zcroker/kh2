#include "../common/types.h"

extern "C" {

struct Obj { u8 pad[943]; u8 a; };
struct Ent { s32 id; s32 pad4; Obj* obj; s32 start; s32 end; u8 from; u8 to; u8 pad[18]; };
extern Ent* D_0035dcfc;
extern s32 D_0035de20;
void func_001ba028(Obj*);

// Fade each live entry's object value from 'from' to 'to' over [start, end).
// The FULL path is written in both arms so CSE shares one hi(D_0035dcfc) and
// cross-jumping merges the copies into the original's single out-of-line block.
void func_0022f3a8(void)
{
    if (D_0035dcfc == 0) return;
    s32 now = D_0035de20;
    for (s32 i = 0; i < 96; i++) {
        Ent* e = (Ent*)(i*40 + (u32)D_0035dcfc);
        if (e->id == -1 || e->obj == 0) continue;
        Obj* o = e->obj;
        s32 st = e->start;
        if (st < 0 || now < st) continue;
        s32 en = e->end;
        if (now < en) {
            if (st != en) {
                u8 v = (s32)((f32)(now - st) * (f32)(e->to - e->from) / (f32)(en - st) + (f32)e->from);
                func_001ba028(o);
                D_0035dcfc[i].obj->a = v;
            } else {
                func_001ba028(o);
                D_0035dcfc[i].obj->a = D_0035dcfc[i].to;
            }
        } else {
            func_001ba028(o);
            D_0035dcfc[i].obj->a = D_0035dcfc[i].to;
        }
    }
}

}
