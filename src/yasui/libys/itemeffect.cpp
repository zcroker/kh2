#include "itemeffect.hpp"

// YS::ITEM_EFFECT (0x1ba168-0x1ba7e0). The 128-bit lq/sq copy is hand-written inline asm.

using YS::ITEM_EFFECT;


#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VEC {
    f32 x, y, z, w;
    VEC() {}
    VEC& operator=(const VEC& o) { if (this != &o) QCOPY(this, &o); return *this; }
} __attribute__((aligned(16)));
struct HIT { u8 pad[12]; s32 n; VEC pos; };
union UD16 { u32 u; f32 f; };
struct B16 { f32 a, y, c; UD16 d; f32 pos[4]; };

extern "C" {
extern f32 D_00349e10;
u32 func_0016a070(OBJ*);
s32 func_001a3888(u32);
u32 func_001a3a78(void);
u32 func_001de168(u32, u32, u32, u32, u32, u32);
void* func_0016bc20(OBJ*, u32, s32);
void func_0018a818(HIT*, OBJ*, void*);
VEC* func_001dc5f8(u32);
VEC* func_0016c028(OBJ*);
u8* func_001a80c8(u32);
u8* func_00176b20(s32);
s32 func_0019ba60(void*);
u32 func_00176b58(u32);
void func_001d02c8(OBJ*);
u8* func_00177860(void*);
s32 func_001a2a50(u32, u32, s32, s32);
void func_001d97c8(void);
s32 func_00176e78(OBJ*, u32, u32);
void* func_001050d8(u32);
void func_00105110(void*);
void func_00102c18(s32, s32, void (*)(TASK*));
}

static LIST<ITEM_EFFECT> s_list;


namespace YS {

inline void* ITEM_EFFECT::operator new(u32 n) { return func_001050d8(n); }
inline void ITEM_EFFECT::operator delete(void* p) { func_00105110(p); }

ITEM_EFFECT::ITEM_EFFECT(OBJ* o, u32 item, u32 tgt) {
    id = item;
    obj = o;
    time = 30.0f;
    kind = func_0016a070(o);
    target = func_001a3888(id) ? 0 : tgt;
    s_list.Append(this);
}

ITEM_EFFECT::~ITEM_EFFECT() {
    end();
    s_list.Remove(this);
}

void ITEM_EFFECT::use(void) {
    HIT h;
    h.n = 0;
    u32 m = func_001de168(func_001a3a78(), 0, 1, 1, 10002, 0);
    void* nd = func_0016bc20(obj, 8, -1);
    if (nd) {
        func_0018a818(&h, obj, nd);
        *func_001dc5f8(m) = h.pos;
    } else {
        *func_001dc5f8(m) = *func_0016c028(obj);
    }
}

s32 ITEM_EFFECT::exec(void) {
    B16 b;
    f32 t = time;
    b.d.u = 0;
    if (30.0f <= t) use();
    time -= D_00349e10;
    if (time <= 0.0f) {
        u8* d = func_001a80c8(id);
        if (target) {
            hit(*(u16*)(d + 6), target);
        } else {
            for (s32 i = 0; i < 3; i++) {
                u8* o = func_00176b20(i);
                if (func_0019ba60(o) && !(*(u32*)(o + 1416) & 0x400000))
                    hit(*(u16*)(d + 6), func_0016a070((OBJ*)o));
            }
        }
        end();
        return 0;
    }
    return 1;
}

void ITEM_EFFECT::hit(u32 item, u32 tgt) {
    u32 o = func_00176b58(tgt);
    if (o == 0) return;
    func_001de168(func_001a3a78(), item, 1, 1, 10002, o);
}

void ITEM_EFFECT::end(void) {
    if (!id) return;
    if (kind == 4) { func_001d02c8(obj); id = 0; return; }
    s32 pri = 100;
    void* o = (void*)func_00176b58(kind);
    if (func_0019ba60(o)) pri = *(u16*)(func_00177860(o) + 80) + 100;
    if (func_001a2a50(id, target, kind, pri) && kind == 1) func_001d97c8();
    id = 0;
}


void ITEM_EFFECT::Cast(OBJ* o) {
    u8* p = (u8*)o;
    if (!func_00176e78(o, *(u16*)(p + 2860), *(u16*)(p + 2862))) return;
    new ITEM_EFFECT(o, *(u16*)(p + 2860), *(u32*)(p + 2864));
}

void ITEM_EFFECT::Exec(TASK*) {
    ITEM_EFFECT* p = s_list.head;
    if (!p) return;
    for (;;) {
        ITEM_EFFECT* next = p->next;
        if (!p->exec()) delete p;
        if (!next) return;
        p = next;
    }
}

void ITEM_EFFECT::Init(void) {
    func_00102c18(1, 19000, Exec);
}

void ITEM_EFFECT::ClearAll(void) {
    ITEM_EFFECT* p = s_list.head;
    if (!p) return;
    for (;;) {
        ITEM_EFFECT* next = p->next;
        delete p;
        if (!next) return;
        p = next;
    }
}

}  // namespace YS
