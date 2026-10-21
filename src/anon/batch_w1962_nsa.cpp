#include "../common/types.h"

// ---- func_00199dc0 (-fno-strict-aliasing)
struct W1962Nd { u8 p[0x60]; W1962Nd* next; };
struct W1962Ent { u16 f0; u16 kind; u8 p4[0x3c]; };
struct W1962Ev { u32 id; u8 p4[0x18]; u8 mode; u8 p1d; u16 arg; u8 p20[0x20]; };
struct W1962Hdr { u8 type; u8 p1; u16 n2; u16 nev; u16 nent; };
struct W1962Chr { u8 p[4]; u8 kind; };
struct W1962Lst { W1962Nd* head; W1962Nd* tail; };
struct W1962Obj { u32 f0; u32 fl; W1962Hdr* hdr; W1962Lst lst; u32 f14; u32 f18; u32 f1c; u32 f20; W1962Ev* ev; W1962Ent* ent; };
extern "C" {
W1962Nd* func_001db440(W1962Ent*);
s32 func_00199810(W1962Ev*);
W1962Chr* GetCharaData_0016e920(u32) asm("_ZN2Tz6JmInfo12GetCharaDataEj");
s32 func_002d0200(W1962Chr*);
void func_00199f90(W1962Obj*, W1962Ev*);
void func_0019ab30(W1962Obj*, u16);
void func_00199dc0(W1962Obj* o) {
    s32 i;
    W1962Ev* e = o->ev;
    o->fl |= 2;
    for (i = 0; i < o->hdr->nent; i++) {
        if (o->hdr->type == 6 || (u32)(o->ent[i].kind - 3) >= 2) {
            W1962Lst* l = &o->lst;
            W1962Nd* n = func_001db440(&o->ent[i]);
            if (l->tail == 0) {
                l->tail = n;
                o->lst.head = n;
                n->next = 0;
            } else {
                l->tail->next = n;
                n->next = 0;
                l->tail = n;
            }
        }
    }
    o->f1c = 0;
    o->f18 = 0;
    if (o->hdr->type != 9) {
        for (s32 j = 0; j < o->hdr->nev; j++, e++) {
            if (func_00199810(e)) {
                W1962Chr* c = GetCharaData_0016e920(e->id);
                if (c->kind != 16 || func_002d0200(c)) {
                    switch (e->mode) {
                    case 0: case 1: case 3:
                        func_00199f90(o, e);
                        break;
                    case 2:
                        switch (c->kind) {
                        case 4: case 21:
                            func_0019ab30(o, e->arg);
                            break;
                        case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12: case 13: case 14:
                        case 15: case 16: case 17: case 18: case 19: case 20: case 22: case 23:
                            break;
                        }
                        break;
                    }
                }
            }
        }
    }
}
}
