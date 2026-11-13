#include "../common/types.h"

// dk::GAUGE_PLAYER, last part (0x157688-0x158050): the drive/alert updates of the player gauge and
// the file's static initialiser (the gauge turn step, 4.5 degrees). The first part of the file is
// src/anon/unit_00153ea0.cpp. Each function keeps the declarations of the source it was matched in
// (namespace gN); every external symbol is bound by asm label.

static inline f32 Radians(f32 deg) { return deg * 0.0174532925f; }

static f32 D_004f3588 __attribute__((aligned(4))) = Radians(4.5f);  // gauge turn step

// 157688 .. 1576d0: vtable entries that forward to the shared handlers with a message number
namespace g0 {
u32 func_001574f8(u32, u32, u32, u32) asm("func_001574f8");
u32 func_001575c0(u32, u32, u32, u32) asm("func_001575c0");

u32 func_00157688(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_00157688");
u32 func_00157688(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001574f8(a0, 0x00000087u, a2, a3);
}

u32 func_001576a0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001576a0");
u32 func_001576a0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001574f8(a0, 0x00000086u, a2, a3);
}

u32 func_001576b8(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001576b8");
u32 func_001576b8(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001574f8(a0, 0x00000085u, a2, a3);
}

u32 func_001576d0(u32 a0, u32 a1, u32 a2, u32 a3) asm("func_001576d0");
u32 func_001576d0(u32 a0, u32 a1, u32 a2, u32 a3) {
    return func_001575c0(a0, a1, a2, a3);
}
}  // namespace g0

// 1576e8
namespace g1 {
u32 func_00155d58(u8*, int) asm("func_00155d58");  // table_word_indexed_by_3
void func_00138c10(u8*, u32) asm("func_00138c10");
void func_00154408(u8*, u32) asm("func_00154408");

void func_001576e8(u8* p) asm("func_001576e8");
void func_001576e8(u8* p) {
    func_00138c10(p + 6704, func_00155d58(p, 0));
    func_00138c10(p + 7116, func_00155d58(p, 1));
    func_00138c10(p + 8352, func_00155d58(p, 2));
    func_00154408(p + 64, *(u32*)(p + 24));
}
}  // namespace g1

// 157758 .. 157880
namespace g2 {
u32 func_002ba358(void) asm("func_002ba358");
void func_002ba368(void) asm("func_002ba368");
void func_002ba390(void) asm("func_002ba390");
u32 func_00166cc8(u32) asm("func_00166cc8");
u32 func_00166cf0(u32) asm("func_00166cf0");
u32 func_001396c0(u32) asm("func_001396c0");
void func_001576e8(u32) asm("func_001576e8");

void func_00157758(u32 a0) asm("func_00157758");
void func_00157758(u32 a0) {
    u32 s0 = a0;
    u32 p = *(u32*)(a0 + 52);
    if (p == 0) {
        return;
    }

    if (func_002ba358() == 0) {
        if (func_00166cc8(*(u32*)(s0 + 52)) == 0) {
            return;
        }
        return func_001576e8(s0);
    }

    if (func_00166cc8(*(u32*)(s0 + 52)) != 0) {
        return;
    }
    return func_001576e8(s0);
}

void func_001577c8(u32 a0) asm("func_001577c8");
void func_001577c8(u32 a0) {
    u32 s0 = a0;
    u32 p;
    if (func_001396c0(s0) != 0) {
        goto L_800;
    }

    p = *(u32*)(s0 + 52);
    if (p == 0) {
        return;
    }
    if (func_00166cf0(p) == 0) {
        goto L_828;
    }

L_800:
    if (func_002ba358() == 0) {
        return;
    }
    return func_002ba390();

L_828:
    if (func_002ba358() != 0) {
        goto L_854;
    }
    if (func_00166cc8(*(u32*)(s0 + 52)) == 0) {
        return;
    }
    return func_002ba368();

L_854:
    if (func_00166cc8(*(u32*)(s0 + 52)) != 0) {
        return;
    }
    func_002ba390();
    return func_001576e8(s0);
}

void func_00157880(u32 a0) asm("_ZN2dk12GAUGE_PLAYER13checkAlertOffEv");
void func_00157880(u32 a0) {
    u32 s0 = a0;
    if (*(u32*)(a0 + 52) == 0) {
        return;
    }
    if (func_002ba358() == 0) {
        return;
    }
    if (func_00166cc8(*(u32*)(s0 + 52)) != 0) {
        return;
    }
    return func_002ba390();
}
}  // namespace g2

// 1578d8
namespace g3 {
s32 func_0013c7d0(void) asm("func_0013c7d0");
s32 func_00155d58(u8*, s32) asm("func_00155d58");  // table_word_indexed_by_3
s32 func_00155f40(u8*) asm("func_00155f40");
s32 func_00155fc0(u8*) asm("func_00155fc0");
void func_00157aa0(u8*) asm("func_00157aa0");
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void func_00138c10(u8*, s32) asm("func_00138c10");

void func_001578d8(u8* p) asm("func_001578d8");
void func_001578d8(u8* p)
{
    if (p[32]) return;
    if (func_0013c7d0()) {
        u8* s = p + 12060;
        func_00138c10(p + 6704, func_00155d58(p, 0));
        func_00138c10(p + 11648, func_00155f40(p));
        if (u_call4_00139d78(s)) func_00138c10(s, func_00155fc0(p));
        func_00157aa0(p);
        p[32] = 1;
    } else if (p[12052]) {
        p[32] = 1;
    }
}
}  // namespace g3

// 157990
namespace g4 {
struct P {
    u8 pad[0x24];
    s32 x24;
    s32 x28;
    s32 pad2[2];
    s32** x34;
};
void func_00138c10(u8*, s32) asm("func_00138c10");

void func_00157990(P* p) asm("func_00157990");
void func_00157990(P* p)
{
  s32 b = *p->x34[0x48c / 4];
  int new_var;
  s32 a = p->x28;
  if (a == b)
  {
    return;
  }
  if (a < b)
  {
    p->x24 = b;
  }
  else
  {
    p->x24 = a;
    new_var = 8764;
  }
  p->x28 = b;
  func_00138c10(((u8 *) p) + 7528, 126);
  func_00138c10(((u8 *) p) + new_var, 127);
}
}  // namespace g4

// 157a00
namespace g5 {
void func_00157990(u32) asm("func_00157990");
void func_001558b8(u32, u32, u32) asm("func_001558b8");  // entry592_process
void func_001559e8(u32, u32, u32) asm("func_001559e8");

void func_00157a00(u32 a0) asm("func_00157a00");
void func_00157a00(u32 a0) {
    u32 s0 = a0;
    u32 s1;
    u32 s2;
    u32 p;

    func_00157990(s0);
    p = *(u32*)(*(u32*)(s0 + 52) + 1164);
    s1 = *(u32*)(p + 4);
    s2 = *(u32*)(p + 0);

    func_001558b8(s0, s1, 1);  // entry592_process
    func_001559e8(s0, s1, 4);
    func_001558b8(s0, *(u32*)(s0 + 36), 2);  // entry592_process
    func_001559e8(s0, *(u32*)(s0 + 36), 5);
    func_001558b8(s0, s2, 3);  // entry592_process
    return func_001559e8(s0, s2, 6);
}
}  // namespace g5

// 157aa0
namespace g6 {
s32 func_001a1de0(void*) asm("_Z16u_call4_001a1de0jjjj");
void func_00138c10(void*, s32) asm("func_00138c10");

void func_00157aa0(u8* p) asm("func_00157aa0");
void func_00157aa0(u8* p) {
    if (!func_001a1de0(*(void**)(*(u8**)(p + 52) + 1164))) func_00138c10(p + 10000, 117);
    else func_00138c10(p + 10000, 111);
}
}  // namespace g6

// 157ae0
namespace g7 {
struct Cfg { u8 pad[384]; u32 f384, f388; };
struct Wk { u8 pad[1164]; Cfg* cfg; };
s32 func_001a1de0(Cfg*) asm("_Z16u_call4_001a1de0jjjj");
f32 func_001a1e00(Cfg*) asm("func_001a1e00");
s32 func_00158250(u8*) asm("func_00158250");
s32 func_00155f40(u8*) asm("func_00155f40");
void func_00138c10(u8*, s32) asm("func_00138c10");
void func_001565a8(u8*) asm("func_001565a8");
void func_00156540(u8*) asm("func_00156540");
void func_00155ab0(u8*, u32, u32) asm("func_00155ab0");
void func_00155b58(u8*, u32, f32) asm("func_00155b58");
void func_001395a8(u8*) asm("func_001395a8");

void func_00157ae0(u8* o) asm("func_00157ae0");
void func_00157ae0(u8* o) {
    if (func_001a1de0((*(Wk**)(o + 52))->cfg) == 0) {
        Cfg* c;
        u32 b;
        if (func_00158250(o)) {
            func_00138c10(o + 11648, func_00155f40(o));
            u8* s = o + 10000;
            func_00138c10(s, 116);
            func_00138c10(o + 10412, 119);
            func_00138c10(o + 10824, 115);
            func_00138c10(o + 11236, 120);
            *(u32*)(s + 392) = 117;
            func_001565a8(o);
        }
        c = (*(Wk**)(o + 52))->cfg;
        u32 a = c->f388;
        b = c->f384;
        func_00155ab0(o, a, 9);
        func_00155ab0(o, b, 10);
    } else {
        f32 v;
        if (func_00158250(o)) {
            func_00138c10(o + 11648, func_00155f40(o));
            u8* s = o + 10000;
            func_00138c10(s, 110);
            func_00138c10(o + 10412, 113);
            func_00138c10(o + 10824, 109);
            func_00138c10(o + 11236, 114);
            *(u32*)(s + 392) = 111;
            func_00156540(o);
        } else if (func_00155f40(o) == 26) func_001395a8(o + 1324);
        v = func_001a1e00((*(Wk**)(o + 52))->cfg);
        func_00155b58(o, 9, 1.0f);
        func_00155b58(o, 10, v);
    }
}
}  // namespace g7

// 157c88
namespace g8 {
struct Sub4 { u8 pad[396]; void* owner; s32 f400; };
void func_00156408(u8*) asm("func_00156408");
s32 func_00156010(u8*) asm("func_00156010");
s32 func_00156030(u8*) asm("func_00156030");
s32 func_00156058(u8*) asm("func_00156058");  // state_code_is_2
s32 func_00156080(u8*) asm("func_00156080");  // state_code_is_3
void func_00155d80(u8*) asm("func_00155d80");
void func_001560a8(u8*, s32*, s32*) asm("func_001560a8");
void func_00155cb0(u8*, s32, s32) asm("func_00155cb0");
s32 func_00155e30(u8*) asm("func_00155e30");
void func_00138c10(u8*, s32) asm("func_00138c10");
void func_00139598(u8*) asm("func_00139598");
void func_00155bf0(u8*, u8) asm("func_00155bf0");
s32 func_00105300(void) asm("func_00105300");
void func_002ba2e8(s32, s32) asm("func_002ba2e8");
void func_001395a8(u8*) asm("func_001395a8");
u32 func_00158290(u8*) asm("func_00158290");
u32 func_0013a7e8(s32) asm("func_0013a7e8");
u32 func_0013d7e0(void) asm("func_0013d7e0");
s32 func_00139c18(u8*) asm("func_00139c18");
s32 func_00139d78(Sub4*) asm("func_00139d78");
void func_001386e0(Sub4*, s32, u32, u32, s32, u32) asm("func_001386e0");
void func_001396b0(Sub4*) asm("func_001396b0");
void func_0031a260(Sub4*, s32) asm("func_0031a260");

void func_00157c88(u8* p) asm("func_00157c88");
void func_00157c88(u8* p)
{
    func_00156408(p);
    if (func_00156010(p)) return;
    if (!func_00156030(p)) {
        if (func_00156058(p) || func_00156080(p)) {  // state_code_is_2
            s32 a = 0;
            s32 b = 0;
            func_00155d80(p);
            func_001560a8(p, &a, &b);
            func_00155cb0(p, a, b);
            if (p[15607] == 1) {
                p[15607] = 0;
                func_00138c10(p + 12472, func_00155e30(p));
            }
        } else {
            func_00155bf0(p, (*(u8**)(*(u8**)(p + 52) + 1164))[432]);
            func_00155d80(p);
            u8* q = *(u8**)(*(u8**)(p + 52) + 1164);
            bool full = q[433] >= q[434];
            if (full) {
                if (!p[15609]) {
                    if (p[15608] == 1 && !func_00105300()) func_002ba2e8(33, 0);
                    func_00138c10(p + 916, 20);
                    p[15609] = 1;
                }
                func_001395a8(p + 916);
            } else {
                p[15609] = 0;
                func_00139598(p + 916);
            }
            u8 f = p[15606];
            if (f != 1) return;
            p[15606] = 0;
            func_00138c10(p + 12472, func_00155e30(p));
            if (p[15608] != f) return;
            if (!p[15609]) func_002ba2e8(32, 0);
            u32 c = func_00158290(p);
            u32 h = func_0013a7e8(1);
            u32 w = func_0013d7e0();
            Sub4* s = (Sub4*)(p + func_00139c18(p + 2548) * 408 + 2548);
            if (!func_00139d78(s)) {
                func_001386e0(s, 7000, h, w, 22, c);
                s->owner = p + 11648;
                func_001396b0(s);
                if (s->owner) {
                    s->f400 = 0;
                    func_001396b0(s);
                    if (s->f400) func_0031a260(s, 0);
                }
            }
            p[15608] = 0;
            return;
        }
    }
    func_00139598(p + 916);
}
}  // namespace g8

// 157f08: GAUGE_PLAYER update
namespace g9 {
void func_00158300(void*) asm("func_00158300");
void func_00157758(void*) asm("func_00157758");
void func_001577c8(void*) asm("func_001577c8");
void func_001578d8(void*) asm("func_001578d8");
void func_00157a00(void*) asm("func_00157a00");
void func_00157ae0(void*) asm("func_00157ae0");
s32 func_00157100(void*) asm("func_00157100");
void func_001571c0(void*) asm("func_001571c0");
s32 func_00157130(void*) asm("func_00157130");
void func_001574d8(void*) asm("func_001574d8");
void func_00156d20(void*) asm("func_00156d20");
s32 func_001570a0(void*) asm("func_001570a0");
void func_00157068(void*) asm("func_00157068");
s32 func_001570d0(void*) asm("func_001570d0");
void func_00157c88(void*) asm("func_00157c88");

void func_00157f08(u8* p) asm("func_00157f08");
void func_00157f08(u8* p) {
    func_00158300(p);
    func_00157758(p);
    func_001577c8(p);
    if (*(u32*)(p + 52) == 0) return;
    if (*(u32*)(p + 12) & 0x100) return;
    func_001578d8(p);
    func_00157a00(p);
    func_00157ae0(p);
    if (func_00157100(p)) {
        func_001571c0(p);
    } else if (func_00157130(p)) {
        func_001574d8(p);
        func_00156d20(p);
    } else if (func_001570a0(p)) {
        func_00157068(p);
    } else if (func_001570d0(p)) {
        func_00156d20(p);
    } else {
        func_00157c88(p);
    }
    *(u32*)(p + 15600) = *(*(u8**)(*(u8**)(p + 52) + 1164) + 431);
}
}  // namespace g9
