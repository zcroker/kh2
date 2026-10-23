/* batch w2352, built with -g and -fno-strict-aliasing (_gnsa). */
#include "../common/types.h"

/* 128-bit copy (lq/sq): gcc cannot emit these from C. */
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct V {
    f32 x, y, z, w;
    V() {}
    V(const V& o) { QCOPY(this, &o); }
    V& operator=(const V& o) {
        if (this != &o) QCOPY(this, &o);
        return *this;
    }
} __attribute__((aligned(16)));

struct Obj { u8 pad[0x7f8]; u32 flags; };
struct Tgt { Obj* obj; u8 pad[0x10]; s32 f14; u8 pad2[0x8]; };
struct Slot { u8 pad[0xc]; };
struct Buf {
    void* owner;    /* 00 */
    Slot slot;      /* 04 */
    Tgt tgt;        /* 10 */
    u8 pad[0x60 - 0x30];
};
struct Sub0c { u8 pad[8]; u32 f8; };
struct Q {
    u8 pad[0xc];
    Sub0c* f0c;      /* 0c */
    u8 pad1[0x168 - 0x10];
    u32 f168;        /* 168 */
    u8 pad2[0x508 - 0x16c];
    void* path;      /* 508 */
    u8 pad3[0xb50 - 0x50c];
    s32 fb50;        /* b50 */
};
struct P { u8 pad[0x9e0]; Q* q; };
typedef void (*VFn)(void*, V);
struct VObj { VFn* vt; };

bool tgt_exist(Tgt*) asm("_ZNK2YS6TARGET8is_existEv");
void tgt_setobj(Tgt*, void*, s32) asm("_ZN2YS6TARGET7set_objEPNS_3OBJEi");
bool slot_exist(Slot*) asm("_ZN2YS12COMMAND_SLOT8is_existEv");
V path_pos(void*) asm("_ZN2Ti4Path15get_current_posEv");

extern "C" {
s32 func_0019d748(u8*);
void func_0019da20(Buf*, u8*);
void func_0019dd10(Buf*);
void func_0019d5f8(u8*, Slot*);
void func_0019d720(u8*);
void func_00196028(Obj*);
void* func_0016b740(s32);
void func_00190128(Tgt*);
V func_00190388(Tgt*);

static inline bool hasobj(u8* s) { bool r = false; if (tgt_exist((Tgt*)(s + 0xc))) r = ((Tgt*)(s + 0xc))->obj != 0; return r; }
static inline bool is6(Q* q) { return q->fb50 == 6; }
static inline bool low(u8* s) { return *(u8*)(s + 0x29) < 4; }
#define SELF_P(s)   (*(P**)((s) + 0x00))
#define SELF_VO(s)  (*(VObj**)((s) + 0x08))
#define SELF_TGT(s) ((Tgt*)((s) + 0x0c))
#define SELF_ID(s)  (*(u16*)((s) + 0x26))
#define SELF_ST(s)  (*(u8*)((s) + 0x29))
/* 0019d790: per-frame update of a command user: refreshes its command slot, marks the target busy, then reports the
   current target position (a special target for ids 440/464, the path position for 523) through virtual slot 7. */
void func_0019d790(u8* self)
{
    Buf b;
    if (!func_0019d748(self)) return;
    func_0019da20(&b, self);
    func_0019dd10(&b);
    if (slot_exist(&b.slot)) {
        bool has;
        Q* q;
        func_0019d5f8(self, &b.slot);
        has = hasobj(self);
        if (has) SELF_TGT(self)->obj->flags |= 0x2000;
        q = SELF_P(self)->q;
        if (is6(q) || (q->f0c->f8 & 0x8000) || (q->f168 & 0x80)) SELF_ST(self) = 5;
    } else {
        func_0019d720(self);
    }
    if (low(self) && SELF_ID(self) == 55) func_00196028(SELF_TGT(self)->obj);
    if (b.tgt.f14 > 0 && (b.tgt.f14 & 0x40000000)) SELF_ST(self) = 5;
    if (SELF_VO(self)) {
        V pos;
        switch (SELF_ID(self)) {
        case 440:
        case 464: {
            void* o = func_0016b740(1762);
            if (o) {
                Tgt t;
                func_00190128(&t);
                tgt_setobj(&t, o, 0);
                pos = func_00190388(&t);
            } else {
                pos = func_00190388(SELF_TGT(self));
            }
            break;
        }
        case 523:
            pos = path_pos(SELF_P(self)->q->path);
            break;
        default:
            pos = func_00190388(SELF_TGT(self));
            break;
        }
        SELF_VO(self)->vt[7](SELF_VO(self), pos);
    }
}


}
