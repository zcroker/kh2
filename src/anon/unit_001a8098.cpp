#include "../common/types.h"

// Item and treasure tables, first part (0x1a8098-0x1a82b0): look-ups in the loaded item table (24-byte
// entries) and treasure table (12-byte entries), and a ring of the last 8 treasures opened.

namespace YS {
// One item table entry (24 bytes).
struct ITEM_TABLE {
    u16 id;       // 0
    u8 pad2[6];
    u16 a;        // 8
    u16 b;        // 10
    u8 pad12[8];
    u16 c;        // 20
    u16 pad22;
    static const ITEM_TABLE* Each(const ITEM_TABLE* p);
};
}  // namespace YS

struct ITEM_FILE {
    u32 magic;
    s32 n;
    YS::ITEM_TABLE e[1];
};

// One treasure entry (12 bytes).
struct TBOX {
    u16 id;       // 0
    u16 item;     // 2
    u8 type;      // 4: 0 box, 1 event
    u8 world;     // 5
    u8 room;      // 6
    u8 no;        // 7
    u8 pad8[2];
    u16 flag;     // 10: bit in the opened-flags array (0: none)
};

struct TBOX_FILE {
    u16 pad;
    u16 n;
    TBOX e[1];
};

struct RING_ENT { u32 a; u32 b; u32 c; };

struct RING {
    s32 head;
    s32 tail;
    RING_ENT e[8];
    RING() { head = 0; tail = 0; }
};

// 0x1a82b0 (the treasure table iterator) stays a separate function: it only matches without
// interblock scheduling. The second part is unit_001a82f0.cpp.
extern "C" {
ITEM_FILE* D_01c6cb90 __attribute__((aligned(8)));
TBOX_FILE* D_01c6cb98 __attribute__((aligned(8)));
}
#define s_item D_01c6cb90
#define s_tbox D_01c6cb98

extern "C" {
extern void* D_0034e948;
extern u32 D_0032dedc[];
void func_001d2298(void*);
s32 func_001d22a8(u32);
u32 func_00192048(u32);
u32 func_0016a070(void*);
s32 func_001a3018(u32, u32, u32);
void func_001a3188(u32, s32, u32);
void func_001b1e80(u32);
void func_00138190(u32, u32);

void func_001a8098(ITEM_FILE* f) {
    s_item = f;
    func_001d2298(&f->e[f->n]);
}

YS::ITEM_TABLE* func_001a80c8(u32 id) {
    ITEM_FILE* t = s_item;
    s32 n = t->n;
    YS::ITEM_TABLE* e = t->e;
    for (s32 i = 0; i < n; i++, e++) {
        if (e->id == id) return e;
    }
    return 0;
}
}

const YS::ITEM_TABLE* YS::ITEM_TABLE::Each(const ITEM_TABLE* p) {
    if (!p) return s_item->e;
    p++;
    return p < &s_item->e[s_item->n] ? p : 0;
}

extern "C" {
s32 func_001a8158(void) {
    return s_item->n;
}

s32 func_001a8168(YS::ITEM_TABLE* p) {
    return p - s_item->e;
}

s32 func_001a8190(u8* p) {
    switch (p[2]) {
    case 2 ... 13: return func_001d22a8(*(u16*)(p + 6));
    case 14 ... 15: return func_001d22a8(*(u16*)(p + 4));
    }
    return 0;
}

void func_001a81e0(TBOX_FILE* f) {
    s_tbox = f;
}

TBOX* func_001a81f0(u32 world, u32 room, u32 no) {
    s32 i;
    TBOX* e = s_tbox->e;
    for (i = 0; i < s_tbox->n; i++, e++) {
        if (!e->type && e->world == world && e->room == room && e->no == no) return e;
    }
    return 0;
}

TBOX* func_001a8258(u32 id) {
    TBOX_FILE* t = s_tbox;
    TBOX* e = t->e;
    for (s32 i = 0; i < t->n; i++, e++)
        if (e->type == 1 && e->id == id) return e;
    return 0;
}

}
