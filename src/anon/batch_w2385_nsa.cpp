#include "../common/types.h"

extern "C" {
struct W1833Info { u8 pad[0x13]; u8 kind; };
struct W1833Obj;
struct W1833Vt;
struct W1833Sub { W1833Vt* vt; };
struct W1833Vt { void* pad[27]; void (*fn)(W1833Sub*, W1833Obj**, struct W1833B**); };
struct W1833Obj {
    u8 pad0[4]; u32 flags; u8 pad8[4]; W1833Sub* sub; u8 pad10[0x18]; W1833Info* info;
    u8 pad2c[4]; u8 a30[0x54]; s32 v84; u8 pad88[0x10]; s32 v98; u8 pad9c[4]; s32 va0; u8 cnt;
};
struct W1833B { u8 pad[0xc]; s32 vc; u8 pad10[0x18]; W1833Info* info; };
struct W1833Arg { s32 a; W1833Obj* o; W1833B* b; };
s32 func_0018f010(W1833B*);
void func_001c0320(void*, W1833B*, void*);
void func_0018ef68(void*, W1833Arg*, s32);

// Bumps the object's counter, forwards the hit to its parts and notifies the listener at +0x98.
void func_0018e7c0(W1833Obj** pp, W1833B** pb) {
    u8 buf[16];
    (*pp)->cnt++;
    if (func_0018f010(*pb) == 0 || (*pb)->info->kind != 2) {
        func_001c0320((*pp)->a30, *pb, buf);
        if (!((*pp)->flags & 0x100)) {
            func_001c0320((u8*)(*pp)->sub + 0xa50, *pb, buf);
        }
    }
    if ((*pp)->info->kind != 2) {
        (*pp)->flags |= 0x200;
        (*pp)->v84 = (*pb)->vc;
    }
    if (!((*pp)->flags & 0x100)) {
        W1833Sub* s = (*pp)->sub;
        s->vt->fn(s, pp, pb);
    }
    s32* q = &(*pp)->v98;
    if (*q != 0) {
        W1833B* vb = *pb;
        W1833Arg a;
        a.a = (*pp)->va0;
        a.o = *pp;
        a.b = vb;
        func_0018ef68(q, &a, 3);
    }
}
}
