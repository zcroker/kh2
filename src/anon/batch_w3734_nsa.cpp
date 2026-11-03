#include "../common/types.h"
struct Sub {
    s32 a; s32 b; u8 c; s32 d; s32 e; s32 f; s32 g;
};
// The c..f fields are cleared through these one-field types: a type unrelated to Sub
// keeps the stores ordered after the p->/q-> field stores the way the original schedules them.
struct Word { s32 v; };
struct Byte { u8 v; };
#define CLEAR_WORD(base, off) (((Word*)((u8*)(base) + (off)))->v = 0)
#define CLEAR_BYTE(base, off) (((Byte*)((u8*)(base) + (off)))->v = 0)
struct Tmr { u8 pad[0x30]; void* f30; };
struct Mgr {
    s32 mode; s32 f4; s32 f8; u8 fc; u8 pad[7];
    Sub s1; Sub s2;
    Tmr* f4c;
};
extern "C" {
extern Mgr* D_00350df0;
extern u32 D_0034f240;
extern u8 D_00351ec8[];
s32 func_001bb9f0(void);
void func_001aefa0(Mgr*);
void func_001c8d80(void*, s32);
void func_001af0c0(Mgr*);
void func_001373a0(void);
void func_002ba2e8(s32, s32);
s32 func_00195328(s32);
void* func_001050d8(s32);
void func_00196ca8(void*, s32, s32);
void func_00196e98(void*, s32);
void func_00196f00(void*);
void func_00138480(s32);
Tmr* func_00102c18(s32, s32, void*);
void func_001af398(void);
void func_001af3e0(void);

// Initialises the manager, registers it globally and starts its timer (built with -fno-strict-aliasing).
void func_001aedf8(Mgr* m, s32 arg1, s32 mode) {
    m->mode = mode;
    m->f4 = 0;
    m->f8 = 0;
    m->fc = 0;
    {
        Sub* p = &m->s1;
        Sub* q = &m->s2;
        m->s1.a = 0;
        p->b = 0;
        q->a = 0;
        CLEAR_BYTE(m, 28); CLEAR_WORD(m, 32); CLEAR_WORD(m, 36); CLEAR_WORD(m, 40);   // s1.c..f
        p->g = 0;
        q->b = 0;
        CLEAR_BYTE(m, 56); CLEAR_WORD(m, 60); CLEAR_WORD(m, 64); CLEAR_WORD(m, 68);   // s2.c..f
        q->g = 0;
    }
    D_00350df0 = m;
    if (m->mode == 0) {
        if (func_001bb9f0()) func_001aefa0(m);
    }
    D_0034f240 |= 2;
    if (m->mode != 2) {
        func_001c8d80(D_00351ec8, 1);
        func_001af0c0(m);
    }
    func_001373a0();
    switch (m->mode) {
    case 0: case 2: case 3:
        func_002ba2e8(19, 0);
        break;
    case 1:
        func_002ba2e8(51, 0);
        break;
    }
    if (arg1 != 0) {
        s32 r = func_00195328(0);
        void* o = func_001050d8(0xb0);
        func_00196ca8(o, 15, r);
        func_00196e98(o, arg1);
        func_00196f00(o);
    }
    func_00138480(2);
    m->f4c = func_00102c18(1, 15000, (void*)func_001af398);
    m->f4c->f30 = (void*)func_001af3e0;
}
}
