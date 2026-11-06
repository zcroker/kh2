#include "../common/types.h"
// w3839: 0010f448 and 00270c70 (both need -fno-strict-aliasing for 00270c70; 0010f448 matches either way).
struct QWf44 { f32 x, y, z, w;
    QWf44() {}
    QWf44(const QWf44& o) { asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory"); }
} __attribute__((aligned(16)));
static inline f32 Dotf44(const QWf44& a, const QWf44& b) {
    f32 r;
    asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvmul.xyz $vf1, $vf1, $vf2\n\tvaddy.x $vf1, $vf1, $vf1y\n\tvaddz.x $vf1, $vf1, $vf1z\n\tqmfc2 $8, $vf1\n\tmtc1 $8, %0" : "=f"(r) : "r"(&a), "r"(&b) : "$8", "memory");
    return r;
}
struct Kf44 { s32 i0; s32 i4; };
struct Tf44 { s32 i0; s32 i4; s32 i8; u32 flags; };
struct Hf44 { s32 i0; s32 i4; s32 i8; };
struct Of44 {
    u8 p0[12]; Kf44* k; u8 p1[352 - 16]; u32 f160; u8 p2[1164 - 356]; Hf44* h;
    u8 p3[1360 - 1168]; QWf44 v550; u8 p4[2940 - 1376]; u32 fb7c; u8 p5[2992 - 2944]; QWf44 vbb0;
    u8 p6[3024 - 3008]; QWf44 vbd0; u8 p7[3056 - 3040]; f32 fbf0;
};
struct Af44 { u32 flags; s32 i4; s32 i8; s32 ic; Tf44* t; s32 i14; s32 i18; s32 i1c; };
extern "C" {
u8* getFSR_f44(Of44*) asm("_ZN2kn6Friend16getFriendSaveRamEv");
s32 ct_10f7b0_f44(Of44*, s32, s32) asm("_Z16ctarget_0010f7b0jjjj");
s32 uc_1a1de0_f44(Hf44*) asm("_Z16u_call4_001a1de0jjjj");
s32 func_0010cc80(Of44*);
s32 func_0010f340(Of44*, QWf44*, Tf44*, f32);
// Checks whether an action entry may be used now (party member, flags, save state, target, facing).
// The ==3 return shares its block with the failed ctarget call (goto zero) so if-conversion keeps it,
// and the function ends on return 1, which makes cross-jumping keep that early return-0 block.
s32 func_0010f448(Of44* o, Af44* a, u8 c1, u8 c2) {
    if (c1) {
        Kf44* k = o->k;
        if (!k) return 0;
        if (k->i4 != 0 && k->i4 != 31) return 0;
    }
    if (c2 && !(o->f160 & 4)) return 0;
    if (a->i14) {
        if (a->i1c == -1) return 0;
        if ((getFSR_f44(o) + a->i1c)[1] == 3) { zero: return 0; }
        if (!ct_10f7b0_f44(o, a->i14, a->i18)) goto zero;
    }
    if (a->t) {
        if (o->h && a->t->i8 > 0) {
            if (!(o->fb7c & 0x20)) return 0;
            if (uc_1a1de0_f44(o->h)) return 0;
        }
        if (a->flags & 2) {
            if (!func_0010cc80(o)) return 0;
            f32 f = o->fbf0;
            if (!func_0010f340(o, &o->vbb0, a->t, f)) return 0;
            if (!(a->t->flags & 0x10)) {
                QWf44 v(o->v550);
                v.y = 0.0f;
                if (Dotf44(v, o->vbd0) < v.y) return 0;
            }
        }
    } else if (a->flags & 2) return 0;
    return 1;
}
}


struct W1712Entry {
    s16 id;
    s8 flag;
    u8 level;
    u8 pad[4];
};

struct W1712List {
    s8 numDrive;
    s8 numParty;
    s8 numSummon;
    u8 b3;
    s8 total;
    u8 pad[3];
    W1712Entry e[18];
};

struct W1712Sheet {
    u8 pad0[0x12];
    u8 count;
    u8 pad13[0x34 - 0x13];
    u16 a34[8];
    u16 a44[8];
    struct { u16 id : 15; u16 on : 1; } a54[80];
    u8 xf4;
    u8 xf5[1];
};

struct W1712Item {
    u16 id;
    u8 type;
};

struct W1712Rec {
    u8 pad[6];
    u8 kind;
};

extern "C" {
void func_002713a0(s32, s8**, s32*);
s16 func_00271870(u16);
s32 func_001a36f8(s32);
W1712Rec* func_001a80c8(s32);
s32 func_001145b0(s16, s32);
u8* W1712_getSaveRam(void) asm("_Z10getSaveRamv");
void W1712_memset(void*, s32, u32) asm("_Z16wtarget_002fde18jjjj");
u8* W1712_GetSheet(void*, s32) asm("_ZN2Tz9PartyInfo8GetSheetEi");
s32 W1712_HasAnsemEntry(u32) asm("_ZN2Tz6JmInfo13HasAnsemEntryEj");
W1712Item* W1712_ItemEach(W1712Item*) asm("_ZN2YS10ITEM_TABLE4EachEPKS0_");
u8 W1712_GetMpDriveStatus(s32) asm("_ZN2YS5MAGIC16GetMpDriveStatusEi");
extern void* D_0035f010;
extern W1712List* D_0035f12c;

void W1712_func(s32 arg0) asm("_Z17ctarget0_00270c70v");
void W1712_func(s32 arg0)
{
    s32 buf[80];
    s8* list;
    s32 num;
    W1712Sheet* sheet;
    W1712Item* item = 0;
    s32 n = 0;
    s32 k;
    s32 i;
    s32 j;
    s32 cnt;
    u32 id;
    s32 x;

    func_002713a0(arg0, &list, &num);
    W1712_memset(D_0035f12c, 0, sizeof(W1712List));
    sheet = *(W1712Sheet**)(W1712_GetSheet(D_0035f010, arg0) + 0x244);
    for (k = 0; k < num; k++) {
        switch (list[k]) {
        case 0:
            for (i = 0; i < 4; i++) {
                u16 v = ((u16*)(W1712_getSaveRam() + 0x36f8))[i];
                D_0035f12c->e[n++].id = func_00271870(v);
            }
            break;
        case 1: {
            s32 mask = 0;
            for (i = 0; i < 6; i++) {
                buf[i] = func_001a36f8(i);
            }
            while ((item = W1712_ItemEach(item)) != 0) {
                if (item->type == 0x12 && W1712_HasAnsemEntry(item->id) > 0) {
                    for (i = 0; i < 6; i++) {
                        if (buf[i] == item->id) {
                            mask |= 1 << i;
                            break;
                        }
                    }
                }
            }
            cnt = 0;
            for (i = 0; i < 6; i++) {
                if ((u8)((mask >> i) & 1)) {
                    cnt++;
                    D_0035f12c->e[n].id = buf[i];
                    D_0035f12c->e[n++].flag = W1712_GetMpDriveStatus(i);
                }
            }
            D_0035f12c->numDrive = cnt;
            break;
        }
        case 2:
            cnt = 0;
            W1712_memset(buf, 0, sizeof(buf));
            for (i = 0; i < sheet->count; i++) {
                id = sheet->a34[i];
                if (id == 0) {
                    id = sheet->a44[i];
                    if (id == 0) {
                        continue;
                    }
                }
                for (j = 0; j < cnt; j++) {
                    if ((u16)buf[j] == id) {
                        break;
                    }
                }
                if (j < cnt) {
                    continue;
                }
                if (sheet->a44[i] == id) {
                    id |= 0x80000000;
                }
                buf[cnt++] = id;
            }
            for (i = 0; i < cnt; i++) {
                D_0035f12c->e[n].id = buf[i];
                if (arg0 != 0) {
                    u8 lv = sheet->xf5[func_001145b0(D_0035f12c->e[n].id, arg0)];
                    D_0035f12c->e[n].level = lv;
                }
                if (buf[i] & 0x80000000) {
                    D_0035f12c->e[n].flag = 1;
                }
                n++;
            }
            D_0035f12c->numParty = cnt;
            break;
        case 3:
            D_0035f12c->b3 = sheet->xf4;
            break;
        case 4: {
            s32 idx;
            cnt = 0;
            W1712_memset(buf, 0, sizeof(buf));
            for (i = 0; i < 80; i++) {
                id = sheet->a54[i].id;
                if (id != 0 && sheet->a54[i].on && func_001a80c8(id)->kind == 2) {
                    buf[cnt++] = id;
                }
            }
            for (i = 0; i < cnt; i++) {
                D_0035f12c->e[n].id = buf[i];
                D_0035f12c->e[n].flag = 1;
                if (arg0 != 0) {
                    u8 lv = sheet->xf5[func_001145b0(D_0035f12c->e[n].id, arg0)];
                    D_0035f12c->e[n].level = lv;
                }
                n++;
            }
            item = 0;
            W1712_memset(buf, 0, sizeof(buf));
            idx = 0;
            for (;;) {
                item = W1712_ItemEach(item);
                if (item == 0) break;
                if (item->type == 0x13) {
                    for (i = 0; i < cnt; i++) {
                        if (D_0035f12c->e[i].id == item->id) {
                            buf[i] = idx;
                        }
                    }
                }
                idx++;
            }
            for (i = 0; i < cnt; i++) {
                for (j = i + 1; j < cnt; j++) {
                    if (buf[i] > buf[j]) {
                        W1712Entry t = D_0035f12c->e[i];
                        D_0035f12c->e[i] = D_0035f12c->e[j];
                        D_0035f12c->e[j] = t;
                        register s32 x asm("$4") = buf[i]; // pin: orig keeps the swap temp in a0
                        buf[i] = buf[j];
                        buf[j] = x;
                    }
                }
            }
            D_0035f12c->numSummon = cnt;
            break;
        }
        }
    }
    D_0035f12c->total = n;
    if (list[0] == 0) {
        for (k = 0; k < 4; k++) {
            if (D_0035f12c->e[k].id != 0) {
                for (i = 4; i < D_0035f12c->total; i++) {
                    if (D_0035f12c->e[k].id == D_0035f12c->e[i].id) {
                        D_0035f12c->e[k].flag = D_0035f12c->e[i].flag;
                    }
                }
            }
        }
    }
}
}
