#include "../common/types.h"
struct W1636Vec {
    f32 x, y, z, w;
    W1636Vec() {}
    W1636Vec(const W1636Vec& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
struct W1636Sprite;
struct W1636SpriteVt {
    void* pad0[7];
    void (*hide)(W1636Sprite*);          // 0x1c
    void* pad20[2];
    void (*setLength)(W1636Sprite*, s32); // 0x28
    void* pad2c[2];
    void (*setPos)(W1636Sprite*, s32);    // 0x34
    void (*setOn)(W1636Sprite*);          // 0x38
    void (*setOff)(W1636Sprite*);         // 0x3c
};
struct W1636Sprite { W1636SpriteVt* vt; };
struct W1636Note {
    u32 unk0;
    s32 mode;      // 0x04
    s32 start;     // 0x08
    u32 unkc, unk10;
    s32 end;       // 0x14
    s32 limit;     // 0x18
    f32 time;      // 0x1c
    u32 unk20;
    s32 id;        // 0x24
    u32 bone;      // 0x28
    W1636Sprite* spr; // 0x2c
    s32 se;        // 0x30
    s32 sound;     // 0x34
    u8 hit;        // 0x38
    s32 count;     // 0x3c
};
struct W1636Task { u32 unk0; W1636Note* note; };
struct W1636Pad { u32 unk0, unk4; u64 bits; };
struct W1636Ent { u32 unk0, unk4; u32 obj; };
extern "C" {
extern f32 D_00349e10;
s32 func_00225e48(void);
W1636Ent* func_00227d10(s32);
s32 func_001ba028(u32);  // list_contains_ptr
W1636Vec func_0016b478(f32, u32, u32);
void* func_0022af48(W1636Vec*);
void func_0022b028(s32);
void func_00105110(void*);
void func_001024a8(void*);
W1636Pad* func_00167f18(s32);
void func_0022afe8(s32);
u32 func_0022aef0(W1636Vec*);
void func_0022afa0(s32);
u32 func_0022ae98(W1636Vec*);
void func_00224950(s32);
void func_001391a8(W1636Sprite*, W1636Vec);  // vec_copy_at416_if_diff

void func_00229e58(W1636Task* t)
{
    if (func_00225e48()) goto done;
    {
        W1636Note* n = t->note;
        s32* pcount = &n->count;
        f32* ptime = &n->time;
        s32 now = (s32)(n->time * 0.5f);
        s32 max = n->mode < 4 ? 3 : 5;
        s32 start = n->start;
        s32 end = n->end;
        s32 limit = n->limit;
        s32 se = n->se;
        u32 bone = n->bone;
        s32 sound = n->sound;
        W1636Sprite* spr = n->spr;
        W1636Ent* e = func_00227d10(n->id);
        if (e == 0) return;
        if (e->obj == 0) return;
        if (!func_001ba028(e->obj)) return;
        W1636Vec pos = func_0016b478(1.0f, e->obj, bone);
        if (now >= limit) {
            if (!n->hit) {
                func_0022af48(&pos);
                func_0022b028(se);
            }
            spr->vt->hide(spr);
            func_00105110(n);
            t->note = 0;
            goto done;
        }
        s32 before = now < start;
        if (!before && now <= end && (func_00167f18(0)->bits & 4)) {
            if (*pcount < max) {
                func_0022afe8(se);
                func_0022aef0(&pos);
            } else {
                func_0022afa0(se);
                func_0022ae98(&pos);
            }
            func_00224950(sound);
            (*pcount)++;
            n->hit = 1;
        }
        spr->vt->setLength(spr, end - start);
        spr->vt->setPos(spr, 0);
        if (!before) {
            spr->vt->setPos(spr, now - start);
            if (now <= end) spr->vt->setOn(spr);
            else spr->vt->setOff(spr);
        }
        func_001391a8(spr, pos);
        *ptime += D_00349e10;
        return;
    }
done:
    func_001024a8(t);
}
}
