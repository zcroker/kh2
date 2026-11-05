#include "../common/types.h"
struct Nd2Sub { u8 pad[0x7f8]; u32 flags; };
struct Nd2 {
    u8 pad0[0x570];
    Nd2Sub* sub;
    u8 pad1[0x800 - 0x574];
    s32 dead;
    u8 pad2[0x8b8 - 0x804];
    Nd2* next;
};
struct Nd2List { Nd2* head; Nd2* tail; };
extern "C" {
struct Slot { s32 id; s32 st; s32 c; s32 d; };
extern u8 D_0035ef58;
extern u32 D_0035eec0[];
extern Slot D_0035eee0[];
extern s32 D_0035ef54;
u8* func_00253b30(u8*, u32);
void func_002ff2e8(u8*);
s32 func_00253b00();
void func_00253978(void*);
void func_002539d0(void*);
void func_001684c0(u8*, s32, void (*)(void*), Slot*);
void func_00168388(u8*, s32, void (*)(void*), Slot*);

// Starts slot idx's request (idx 6 fills buf itself): records a ticket, sets state 2 and
// queues it with a completion callback.
// key is pinned to s2 (both buffer results share it); the empty asm keeps a label at the
// start of the non-6 arm, so the first beq's delay slot is filled from its target as in the original.
s32 func_002539e8(s32 idx0, u32 key0)
{
    u8 buf[128];
    s32 idx = idx0;
    if (D_0035ef58) return -1;
    register u32 key asm("$18") = key0;
    if (!key) key = D_0035eec0[idx];
    if (idx != 6) {
        lab: asm("" :: "X"(&&lab));
        key = (u32)func_00253b30(buf, key);
    } else {
        func_002ff2e8(buf);
        key = (u32)buf;
    }
    Slot* s = &D_0035eee0[idx];
    s->id = D_0035ef54++;
    s->st = 2;
    s->d = func_00253b00();
    s->c = 0;
    if (idx != 6) {
        func_001684c0((u8*)key, s->d, func_00253978, s);
    } else {
        Slot* q = &D_0035eee0[6]; func_00168388((u8*)key, q->d, func_002539d0, q);
    }
    D_0035ef58 = 1;
    return 0;
}

extern Nd2List D_01d48db0;
void func_001b9b28(Nd2*);
s32 func_001c0cd8(Nd2*);
void func_00320468(Nd2List*, Nd2*);

// Unlinks every node flagged dead, then repeatedly sweeps the list, releasing nodes that
// func_001c0cd8 rejects or whose 0x100 flag is set, until the list is empty.
// Pins: p in s1 and h in t7 give the original's register rotation; hb is the list's high
// half held in s5 before the sweep loop's entry test, as the original hoists it.
void func_001b99d0(void)
{
    register Nd2* p asm("$17");
    Nd2* n;
    Nd2* q;
    Nd2* qn;
    Nd2* it;
    register Nd2* h asm("$15");
    for (p = D_01d48db0.head; p; p = n) {
        n = p->next;
        if (p->dead) {
            func_001b9b28(p);
            Nd2* prev;
            if (p == D_01d48db0.head) {
                D_01d48db0.head = p->next;
                prev = 0;
            } else {
                prev = D_01d48db0.head;
                while (prev->next != p) prev = prev->next;
                prev->next = p->next;
            }
            if (p == D_01d48db0.tail) D_01d48db0.tail = prev;
            p->next = 0;
        }
    }
    register u32 hb asm("$21") = 0x1d50000; // %hi(D_01d48db0)
    asm("" : "+r"(hb));
    while ((h = ((Nd2List*)(hb - 29264))->head) != 0) {
        for (it = q = h; q; q = qn) {
            qn = !it ? D_01d48db0.head : it->next;
            it = qn;
            if (!func_001c0cd8(q) || (q->sub->flags & 0x100)) {
                func_001b9b28(q);
                func_00320468(&D_01d48db0, q);
            }
        }
    }
}
}
