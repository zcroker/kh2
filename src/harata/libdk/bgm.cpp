// dk::BGM (0x136a98-0x137458): the two background music slots (field music and battle music) and
// the battle-mode watcher task that crossfades between them. The file's static init (0x137458, the
// slot ctor loop that sets flags = 0) and its _GLOBAL__I_ stub (0x1374a8) stay separate functions:
// gcc unrolls that 2-element ctor loop here, retail keeps it a loop.
#include "../../common/types.h"

struct TASK;

// A music slot: the requested number, the playing number, the volume and the restart flags.
struct BGM_SLOT {
    s32 id;
    s32 cur;
    s32 vol;
    u32 flags;
};

extern "C" {
BGM_SLOT D_00347d30[2];
s32 D_00347d50;
u8 D_00347d54;
u8 D_00347d55;
u8 D_00347d56;
}

// Other views of the slot table (as the matched functions saw it).
struct Slot347d30 {
    s32 id;
    void* p4;
    void* p8;
    s32 flags;
    void Clear() { *(s32*)this = 0; p4 = 0; p8 = 0; }
};
struct W1618Bgm { s32 f0; s32 id; s32 vol; u32 flags; };
struct Flag36fd0 { u32 pad[3]; u32 f0 : 1; u32 f1 : 1; u32 rest : 30; };
struct PadState { s32 a; s32 b; s32 c; u32 f; };
struct P137180 { u32 cur; u32 prev; u32 f8; u32 flags; };
extern Slot347d30 D_00347d30_clr[2] asm("D_00347d30");
extern W1618Bgm D_00347d30_bgm[2] asm("D_00347d30");
extern Flag36fd0 D_00347d30_flg[2] asm("D_00347d30");
extern PadState D_00347d30_pad[2] asm("D_00347d30");
extern P137180 D_00347d30_req[2] asm("D_00347d30");
extern s32 D_00347d30_w asm("D_00347d30");
extern s32 D_00347d40 asm("D_00347d40");
extern s32 D_00347d44 asm("D_00347d44");

struct W1618Req { u32 f0; s32 handle; s32 id; s32 slot; void* alloc; };
struct Heap;
struct HeapVt { void* (*alloc)(Heap*, u32, u32); void (*free)(Heap*, void*); };
struct Heap { HeapVt* vt; };
struct Pair36fd0 { u32 a; u32 b; };
union Half36fd0 { u16 h[2]; u32 w; };

extern "C" {
extern char D_0036ac80[];
u32 func_002ba848(u32);
void func_002ba220(s32, s32, s32, s32, s32, s32);
void func_002ba2b0(s32, s32);
s32 func_002b7148(s32);
s32 func_002bd250();
s32 func_002bd260(s32);
void func_002bd310(W1618Req*);
s32 func_00225540(void);
void func_002bb070(u32, u32, u32, u32, u32);
s32 func_002ba200(void);
void func_00168388(void*, u32, u32, u32);
s32 func_00170cd0(void);
u16* func_001a9130(void);
void func_00136a18(void);
void func_00136878(void);
}
u32 Tz_Config_isEventViewer() asm("_ZN2Tz6Config13isEventViewerEv");
void* W1618_GetAllocator(void) asm("_ZN4AREA12GetAllocatorEv");
Heap* AREA_GetAllocator(void) asm("_ZN4AREA12GetAllocatorEv");
void W1618_bgmFade(s32, s32, s32) asm("_ZN5SOUND7bgmFadeEiii");
u32 YS_FILE_GetSize(const char*) asm("_ZN2YS4FILE7GetSizeEPKc");
void TaskYield(u32, u32) asm("func_00102448");
void FIELD_CreateTask(s32, s32, void (*)(TASK*)) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
s32 YS_STATUS_IsBattleMode() asm("_ZN2YS6STATUS12IsBattleModeEv");
void BGSE_clearOff() asm("_ZN2dk4BGSE8clearOffEv");

namespace dk {
class BGM {
public:
    static void fieldExit();
};
}

extern "C" {
void func_00136a98() {
    D_00347d50 = 0;
    D_00347d54 = 0;
    D_00347d55 = 0;
}

// Clears both slots, then resets the rest of the block.
void func_00136ab8(void) {
    D_00347d30_clr[0].flags = 0;
    D_00347d30_clr[0].Clear();
    D_00347d30_clr[1].Clear();
    D_00347d30_clr[1].flags = 0;
    func_00136a98();
}
}

void dk::BGM::fieldExit() {
    if (Tz_Config_isEventViewer() != 0u) {
        func_002ba848(240u);
        return;
    }
    func_002ba848(960u);
}

extern "C" {
s32 func_00136b28(s32 i, s32 v) { return D_00347d30[i].id == v; }
void func_00136b48(s32 i, s32 v) { D_00347d30[i].id = v; }
void func_00136b60(s32 i, s32 v) { D_00347d30[i].cur = v; }
void func_00136b78(s32 i, s32 v) { D_00347d30[i].vol = v; }
s32 func_00136b90(s32 i) { return D_00347d30[i].vol; }

// Load the music118 sound data into a temporary 64-byte aligned buffer, send it, free it.
void func_00136ba8(u32 a) {
    Heap* h = AREA_GetAllocator();
    u32 size = YS_FILE_GetSize(D_0036ac80);
    void* mem = h->vt->alloc(h, (size + 0x83f) & ~0x7ff, 0);
    u32 buf = ((u32)mem + 63) & ~63;
    func_00168388(D_0036ac80, buf, 0, 0);
    while (func_00170cd0()) TaskYield(a, 0);
    func_002bb070(1, buf, size, 0, 0);
    while (func_002ba200()) TaskYield(a, 0);
    h->vt->free(h, mem);
}

void func_00136cc8(W1618Req* r, s32 id) {
    if (id == 118) func_00136ba8((u32)r);
}

void func_00136cf0(void) {
    if (func_002b7148(1) != 0) {
        if (D_00347d40 != 0) {
            func_002ba2b0(240, 1);
            func_00136b78(1, 0);
        }
    }
}

void func_00136d40(W1618Req* r) {
    s32 id;
    if (D_00347d30_bgm[0].flags & 1) {
        id = D_00347d30_bgm[0].id;
        func_00136cc8(r, id);
        r->handle = func_002bd260(id);
        r->id = id;
        r->slot = 0;
        r->alloc = W1618_GetAllocator();
        func_002bd310(r);
    }
    W1618Bgm* b = &D_00347d30_bgm[1];
    if (D_00347d30_bgm[1].flags & 1) {
        id = b->id;
        r->handle = func_002bd260(id);
        r->id = id;
        r->slot = 1;
        r->alloc = W1618_GetAllocator();
        func_002bd310(r);
    }
    if (D_00347d30_bgm[0].flags & 2) {
        D_00347d50 = 0;
        func_002ba220(0, 0x3000, 0x3000, 0, 0, 0);
        func_00136b78(0, 0x3000);
        return;
    }
    if (func_00136b90(0) != 0x3000) {
        if (D_00347d30_bgm[0].f0 == 0) return;
        if (func_00225540()) {
            s32 v = func_00136b90(0);
            if (func_002b7148(0)) {
                W1618_bgmFade(0, v, 20);
            } else {
                func_002ba220(0, 0, 0x3000, 20, 1, 0);
                v = 0x3000;
                D_00347d50 = 0;
            }
            func_00136b78(0, v);
        } else if (func_00136b90(0) == 0) {
            D_00347d50 = 0;
            func_002ba220(0, 0x3000, 0x3000, 0, 0, 0);
            func_00136b78(0, 0x3000);
        } else {
            W1618_bgmFade(0, 0x3000, 20);
            func_00136b78(0, 0x3000);
        }
        func_00136cf0();
    } else {
        if (D_00347d40 == 0) return;
        if (func_002b7148(1)) return;
        if (D_00347d30_bgm[0].f0 == 0) return;
        if (func_002b7148(0)) return;
        D_00347d50 = 0;
        func_002ba220(0, 0, 0x3000, 20, 1, 0);
        func_00136b78(0, 0x3000);
        func_00136cf0();
    }
}

void func_00137250(TASK*);
void func_00136fa8() { FIELD_CreateTask(1, 300000, func_00137250); }

void func_00137058(Pair36fd0*);
void func_00137180(Pair36fd0*);

void func_00136fd0(void) {
    Half36fd0* v = (Half36fd0*)func_001a9130();
    union { u32 w[2]; u16 h; } s;
    s.w[0] = v->h[0];
    s.w[1] = v->h[1];
    for (s32 i = 0; i < 2; i++) {
        D_00347d30_flg[i].f0 = 0;
        D_00347d30_flg[i].f1 = 0;
    }
    if (s.w[0] == s.w[1]) func_00137058((Pair36fd0*)&s);
    else func_00137180((Pair36fd0*)&s);
}

// Push the two requested numbers to the slots when they changed.
void func_00137058(Pair36fd0* arg) {
    s32* arg0 = (s32*)arg;
    if (func_002b7148(1) != 0) {
        func_002ba2b0(0xF0, 1);
    }
    D_00347d54 = 0;
    PadState* d = D_00347d30_pad;
    s32 i = 0;
    s32* p = arg0;
    PadState* e = d;
    do {
        s32 v = *p;
        if (__builtin_expect(e->a != v, 0) || __builtin_expect(e->b != v, 0)) {
            e->a = v;
            func_002ba2b0(0xF0, i);
            if (i == 0) {
                if (*arg0 != 0) {
                    d->f |= 2;
                    if (d->b != *arg0 || d->b != func_002bd250()) {
                        d->b = *arg0;
                        d->f |= 1;
                    }
                } else {
                    func_00136b78(0, 0);
                }
            }
        }
        i++;
        p++;
        e++;
    } while (i < 2);
    D_00347d44 = 0;
}

void func_00137180(Pair36fd0* arg) {
    u32* in = (u32*)arg;
    P137180* p;
    s32 i;
    u32 v;
    u32 f;
    v = 1;
    D_00347d54 = v;
    p = D_00347d30_req;
    for (i = 0; i < 2; i++, in++, p++) {
        v = *in;
        if ((p->cur == v) && (p->prev == v)) {
            continue;
        }
        p->cur = v;
        func_002ba2b0(240, i);
        if ((*in) != 0) {
            f = p->flags;
            p->flags = f | 2;
            if (p->prev != (*in)) {
                p->prev = *in;
                p->flags = f | 3;
            }
        } else {
            func_00136b78(i, 0);
        }
    }
}

void func_001372d8(void);
void func_00137340(void);

// Field task: switch between the field and battle music when the battle mode changes.
void func_00137250(TASK*) {
    if (D_00347d54 == 0) return;
    s32 b = YS_STATUS_IsBattleMode();
    if (D_00347d55 == b) return;
    if (b == 1) {
        if (D_00347d50 == 0) func_001372d8();
    } else {
        if (D_00347d50 == 1) func_00137340();
    }
    D_00347d55 = b;
}

void func_001372d8(void) {
    D_00347d50 = 1;
    if (D_00347d30_w != 0) {
        func_002ba2b0(960, 0);
    }
    if (D_00347d40 != 0) {
        func_002ba220(1, 0, 12288, 240, 0, 240);
        return;
    }
}

void func_00137340(void) {
    D_00347d50 = 0;
    if (D_00347d40 != 0) {
        func_002ba2b0(720, 1);
    }
    if (D_00347d30_w != 0) {
        func_002ba220(0, 0, 12288, 480, 1, 240);
        return;
    }
}

void func_001373a0(void) {
    D_00347d55 = 0;
    D_00347d56 = D_00347d54;
    D_00347d54 = 0;
    func_002ba848(960);
    func_00136a18();
}

void func_001373d8(void) {
    D_00347d54 = D_00347d56;
    D_00347d50 = 0;
    D_00347d55 = 0;
    if (D_00347d30_w != 0) {
        func_002ba220(0, 12288, 12288, 0, 0, 0);
        func_00136b78(0, 12288);
        func_00136b78(1, 0);
    }
    BGSE_clearOff();
    func_00136878();
}
}
