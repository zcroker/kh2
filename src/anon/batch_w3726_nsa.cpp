#include "../common/types.h"
#define QCP(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct QV {
    f32 x, y, z, w;
    QV() {}
    QV(const QV& o) { QCP(this, &o); }
    QV& operator=(const QV& o) { if (this != &o) QCP(this, &o); return *this; }
    QV operator-(const QV& b) const {
        QV o;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&o), "r"(this), "r"(&b) : "memory");
        return o;
    }
} __attribute__((aligned(16)));
struct YNode { u8 pad[0xec]; YNode* next; };
struct YList { YNode* head; YNode* tail; };
struct YFlags { u16 b0 : 1; u16 b1 : 1; };
extern "C" {
s32 func_001c0cd8(u8*);
void func_0016bd60(u8*, s32);
QV* func_0016c028(u8*);
f32 func_002f8ad0(f32, f32);
void func_0016aeb8(u8*, f32);
s32 func_0019bad8(u8*);
void func_00143928(QV*, QV*);
void func_0016ace0(u8*, QV*);
void func_0016cc18(s32, s32, s32*, s32, s32);
void func_00193608(u8*);

}
namespace YS {
struct OBJ { void detach(); };
}
// Unlinks the object from its parent's child list and restores its world placement.
void YS::OBJ::detach() {
    u8* o = (u8*)this;
    QV p;
    QV unused;
    if (!func_001c0cd8(o)) return;
    u8* par;
    YList* l = (YList*)(*(u8**)(o + 0x570) + 0x760);
    YNode* node = (YNode*)(o + 0x670);
    YNode* prev;
    if (node == l->head) {
        prev = 0;
        l->head = *(YNode**)(o + 0x75c);
    } else {
        for (prev = l->head; prev->next != node; prev = prev->next) {}
        prev->next = node->next;
    }
    if (node == l->tail) l->tail = prev;
    node->next = 0;
    if (*(s32*)(*(u8**)(o + 0xc) + 4) != *(s32*)(o + 0x578))
        func_0016bd60(o, *(s32*)(o + 0x578));
    p = *func_0016c028(*(u8**)(o + 0x570));
    *(s32*)(o + 0x60c) = *(s32*)(o + 0x80c);
    par = (u8*)*(s32*)(o + 0x570);
    *(s32*)(par + 0x60c) = *(s32*)(par + 0x80c);
    *(u8**)(o + 0x570) = 0;
    asm volatile("" ::: "memory");
    u8 b = (*(u16*)(o + 0x576) >> 1) & 1;
    if (!b) {
        *(u32*)(o + 0x7f8) &= ~8;
        func_0016aeb8(o, func_002f8ad0(-*(f32*)(o + 0x60), -*(f32*)(o + 0x68)));
    }
    if (func_0019bad8(o)) {
        QV* pos = (QV*)(o + 0x70);
        asm volatile("");
        *(QV*)(o + 0x590) = p;
        QV* dst = (QV*)(o + 0x5a0);
        QV t;
        QV* src; asm("addiu %0,%1,112" : "=r"(src) : "r"(o), "r"(dst));
        QV* tp; asm("la %0,%1" : "=r"(tp) : "m"(t), "r"(src));
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(tp), "r"(src), "r"(&p) : "memory");
        *dst = *tp;
        *(u64*)(o + 0x600) |= 1;
        func_00143928((QV*)(o + 0x590), pos);
        func_0016ace0(o, (QV*)(o + 0x5c0));
    } else {
        func_0016ace0(o, (QV*)(o + 0x70));
    }
    if (*(s32*)(o + 0x57c)) {
        s32 t = *(s32*)(o + 0x584);
        func_0016cc18(*(s32*)(o + 0x57c), *(s32*)(o + 0x580), &t, 1, 0);
    }
    func_00193608(o);
}
