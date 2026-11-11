#include "../common/types.h"

// Item and treasure tables, second part (0x1a82f0-0x1a85b8): opening a treasure, and a ring of
// the last 8 treasures opened. The first part is unit_001a8098.cpp.

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

static RING s_ring;

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

YS::ITEM_TABLE* func_001a80c8(u32 id);
}

// Opens a treasure: records it in the ring and sets its opened flag. Returns the item.
u32 wtarget_001a82f0(TBOX* s) asm("_Z16wtarget_001a82f0jjjj");
u32 wtarget_001a82f0(TBOX* s) {
    s32 i = s_ring.head;
    s_ring.head = (i + 1) % 8;
    u8* b = (u8*)&s_ring + i * 12;
    RING_ENT* e = (RING_ENT*)(b + 8);
    void* o = D_0034e948;
    s32 r = 100;
    YS::ITEM_TABLE* inf = func_001a80c8(s->item);
    ((RING_ENT*)(b + 8))->a = func_00192048(inf->a);
    e->b = func_00192048(inf->b);
    e->c = inf->c;
    if (o) r = func_001a3018(s->item, func_0016a070(o), 1);
    func_001a3188(s->item, r, 0);
    u32 f = s->flag;
    if (f) D_0032dedc[f >> 5] |= 1 << (f & 31);
    return e->c;
}

namespace YS {
namespace TREASURE {
class TABLE {
public:
    void get_treasurebox() const;
    u32 get_event() const;
};

void TABLE::get_treasurebox() const {
    func_001b1e80(wtarget_001a82f0((TBOX*)this));
}

u32 TABLE::get_event() const {
    return wtarget_001a82f0((TBOX*)this);
}
}  // namespace TREASURE
}  // namespace YS

u32 call4_001a8450(TBOX* a) asm("_Z16u_call4_001a8450jjjj");
u32 call4_001a8450(TBOX* a) {
    u32 r = 0;
    if (a) {
        u32 t = a->flag;
        u32 bit = t & 0x1f;
        u32 idx = t >> 5;
        if (t)
            r = (D_0032dedc[idx] & (1 << bit)) != 0;
    }
    return r;
}

extern "C" {
void func_001a8498(void) {
    s_ring.head = 0;
    s_ring.tail = 0;
}

RING_ENT* func_001a84b0(void) {
    u32* p = (u32*)&s_ring;
    s32 idx = (s32)p[1];
    u32 off = (u32)(idx * 12);
    p[1] = (idx + 1) % 8;
    return (RING_ENT*)((u8*)p + off + 8);
}

u32 func_001a84f0(void) {
    return s_ring.tail == s_ring.head;
}

s32 func_001a8510(void) {
    return (s_ring.head - s_ring.tail + 8) % 8;
}

void func_001a8548(void) {
    RING_ENT* v = func_001a84b0();
    func_00138190(v->a, v->c);
}
}
