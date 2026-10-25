#include "../common/types.h"

// YS::UNIT (0x182780-0x183088): one battle unit (an object with its own update and draw
// routines). Units live in a static pool of 64 and are created per object from its data.

#define UNIT_QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

struct UnitQ { u32 w[4]; } __attribute__((aligned(16)));
struct UnitDef { u8 p0[12]; u16 f12; };
struct UnitItem { u8 p0[8]; UnitDef* def; u8 p12[40]; u8* f52; };
struct UnitHdr { u32 f0; s32 n; u8 data[1]; };

extern "C" {
UnitHdr* func_00181ba8(void*);
UnitItem* func_00199970(s32);
void func_00199aa0(UnitItem*, void*, u8*);
void func_00199cd0(void*);
void func_00199998(void*);
void func_00199d38(void*);
void func_00196908(void*);
void func_00199dc0(void*);
void func_0019a048(void*);
void func_00102c18(s32, s32, void (*)(void));  // FIELD::CreateTask
u8* func_00186078(u8*);
s32 func_0019ba60(u8*);
UnitQ* func_0016c028(u8*);  // obj_get_attach_or_alt
u32 func_0019b328(void*, u32);
u32 func_0019b380(void*, u32);
void func_0019a308(void*);
}

s32 D_0034ed00 = 0;   // units in use
u8* D_0034ed04 = 0;   // player

namespace YS {

class UNIT {
public:
    u32 key;     // 0
    u32 flags;   // 4 (1: plain value, 2: inactive)
    void* obj;   // 8
    UNIT() { flags = 0; }
    UNIT(u32 k, void* o, u8 inactive);
    UNIT(u32 k, u32 v, u8 inactive);
    ~UNIT();
    static void* operator new(unsigned int);
    static void operator delete(void*);
    void update();
    void activate();
    void draw(UnitQ* eye);
};

}  // namespace YS

static YS::UNIT D_01c60588[64];

void* YS::UNIT::operator new(unsigned int) {
    return &D_01c60588[D_0034ed00++];
}

void YS::UNIT::operator delete(void*) {
    D_0034ed00--;
}

YS::UNIT::UNIT(u32 k, void* o, u8 inactive) {
    key = k;
    obj = o;
    flags = 0;
    if (inactive) flags = 2;
}

YS::UNIT::UNIT(u32 k, u32 v, u8 inactive) {
    key = k;
    flags = 1;
    obj = (void*)v;
    if (inactive) flags = 3;
}

YS::UNIT::~UNIT() {
    u32 f = flags & 1;
    if (f != 0) return;
    void* p = obj;
    if (!p) return;
    func_00199cd0(p);
    func_00199998(p);
}

void YS::UNIT::update() {
    u32 f = flags & 1;
    if (f != 0) return;
    func_00199d38(obj);
}

void YS::UNIT::activate() {
    u32 f = flags;
    flags = f & ~2;
    f &= 1;
    if (f != 0) func_00196908(obj);
    else func_00199dc0(obj);
}

void YS::UNIT::draw(UnitQ*) {
    u32 f = flags & 1;
    if (f != 0) return;
    func_0019a048(obj);
}

extern "C" {

// Creates the units of an object from its unit data.
void func_001829b0(void* o, u8 f) {
    UnitHdr* h = func_00181ba8(o);
    if (!h) return;
    u8* p = h->data;
    for (s32 i = 0; i < h->n; i++) {
        UnitItem* it = func_00199970(56);
        func_00199aa0(it, o, p);
        new YS::UNIT((u32)o, it, f);
        p = it->f52 + it->def->f12 * 8;
    }
}

void func_00182a78(u32 v) {
    new YS::UNIT(0, v, 0);
}

void func_00182ab0(void) {
    for (s32 i = 0; i < D_0034ed00; i++) D_01c60588[i].update();
}

void func_00182c60(void);

void func_00182b18(void) {
    func_00102c18(1, 12000, func_00182c60);
    for (s32 i = 0; i < D_0034ed00; i++) {
        u32 off = i * 12;
        if (!(*(u32*)(off + (u8*)&D_01c60588[0].flags) & 2)) ((YS::UNIT*)(off + (u8*)D_01c60588))->activate();
    }
}

void func_00182bc0(s8* k) {
    u32 key = k[0] | k[1] << 8 | k[2] << 16 | k[3] << 24;
    for (s32 i = 0; i < D_0034ed00; i++)
        if (D_01c60588[i].key == key) D_01c60588[i].activate();
}

void func_00182c60(void) {
    u8* n = 0;
    while ((n = func_00186078(n)) != 0) {
        *(u32*)(n + 2728) |= 0x10000;
    }
    if (func_0019ba60(D_0034ed04) && !(*(u32*)(D_0034ed04 + 2040) & 4)) {
        UnitQ q;
        UnitQ* v = func_0016c028(D_0034ed04);
        s32 i;
        if (&q != v) UNIT_QCOPY(&q, v);
        if (*(u32*)(D_0034ed04 + 1416) & 0x80) {
            *(s32*)(D_0034ed04 + 2892) = -1;
        }
        for (i = 0; i < D_0034ed00; i++) {
            D_01c60588[i].draw(&q);
        }
    }
    n = 0;
    while ((n = func_00186078(n)) != 0) {
        if (*(u32*)(n + 2728) & 0x10000) {
            *(s32*)(n + 2728) = -1;
        }
    }
}

// Deletes every unit, newest first.
void u_call0_00182d80(void) asm("_Z16u_call0_00182d80v");
void u_call0_00182d80(void) {
    for (s32 i = D_0034ed00 - 1; i >= 0; i--) delete &D_01c60588[i];
}

void func_00182df0(void) { D_0034ed04 = 0; }
void func_00182e00(void) {}

u32 func_00182e08(u32 a0) {
    for (s32 i = 0; i < D_0034ed00; i++) {
        u32 r = func_0019b328(D_01c60588[i].obj, a0);
        if (r) return r;
    }
    return 0;
}

u32 func_00182e98(u32 x) {
    s32 i;
    for (i = 0; i < D_0034ed00; i++) {
        u32 r = func_0019b380(D_01c60588[i].obj, x);
        if (r) return r;
    }
    return 0;
}

void func_00182f28(u8* p) { D_0034ed04 = p; }

void func_00182f38(void) {
    for (s32 i = 0; i < D_0034ed00; i++) func_0019a308(D_01c60588[i].obj);
}

}
