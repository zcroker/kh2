// YS::STDOBJ part (0x197fe0-0x198b88): the standard object's constructor, think/command hooks,
// picture and special-command helpers. The event slots that follow are unit_00198b88.cpp.
#include "../common/types.h"

struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

extern "C" s8 D_0036d0c8[];   // "comd" (0x36d0c8, right after this file's jump table)
#define ID4(s) ((s)[0] | ((s)[1] << 8) | ((s)[2] << 16) | ((s)[3] << 24))
static inline u32 Key4(s8* k) { return k[0] | k[1] << 8 | k[2] << 16 | k[3] << 24; }

extern "C" {
extern u8 D_00350388;
extern u8 D_003503e0[];
extern u8 D_00350e48[];
extern u8 D_0032f054;
extern u8* D_0034e948;
void func_00169398(void*, u32, u32*, s32, s32);
void* func_00168b38(s32, s32, s32);
u8* func_00168b88(void*, s32, s32, s32);  // find_entry16_by_half_word
s32 func_00170d18(s32);
void func_0017ebe8(void*, s32);
void func_00195858(void*, u32);
void func_001b2f38(void*, s32, u32);
void func_001d56f0(void*);
void func_001dddd0(void*, s32);
s32 func_00180cd0(u8*);
s32 func_001805a8(u8*, u32);
void func_0017f488(u8*, u32, f32, f32);
void func_00169f98(u8*);
void func_00180ce0(u8*);
void func_001de450(u8*);
void func_001dde40(u8*);
s32 func_0016a328(u8*);
s32 func_0016b638(u8*);
s32 func_001b0320(u32);
void* func_0016c028(void*);  // obj_get_attach_or_alt
void func_002bc188(s32, void*);
void func_001b0210(u32, u32, u32, u8*);
void func_001b0250(u32, u32, u32, u32);
void func_001d5770(u8*, Vec4*);
void func_0016a9b8(u8*);
u8* func_001050d8(s32);
void func_00196ca8(u8*, s32, s32);
void func_00196e98(u8*, u32);
s32 func_00196f00(u8*);
void func_00153d70(s32, s32);
void func_001bdb70(u8*, s32, u32, u32, u8*);
void func_0019d720(u8*);
void func_0013d6b0(u32, u32);
void func_0013d798(void);
s32 func_0019f528(u8*, u32);  // test_bit_by_index
s32 func_0019f550(u8*, u32);  // test_bit_addressable
void func_0019f490(u8*, u32);

void func_00197fe0(u8* o, u32* a, u32 b, u32 c) {
    func_00169398(o, *a | 0x40000000, a, b, c);
    *(void**)o = &D_00350388;
    *(u32*)(o + 1416) |= 0x20;
}

struct JS_198040 { u8 pad[0x26]; u16 h[7]; };
JS_198040* func_001a8b28(void);
u16 func_00198040(s32 a0) {
    JS_198040* p = func_001a8b28();
    u16 r;
    if (a0 == 1) {
        switch (D_0032f054) {
        case 1: r = p->h[1]; break;
        default: r = p->h[0]; break;
        case 2: r = p->h[2]; break;
        case 3: r = p->h[3]; break;
        case 4: r = p->h[4]; break;
        case 5: r = p->h[5]; break;
        case 6: r = p->h[6]; break;
        }
    } else r = 0;
    return r;
}
}

class STDOBJ {
public:
    u8 raw[0xa00];
    STDOBJ(u32* a1, s32 a2, s32 a3);
};

STDOBJ::STDOBJ(u32* a1, s32 a2, s32 a3) {
    u8* p = (u8*)this;
    u8* s0 = p + 0x9BC;
    u8* s2 = p + 0x7A0;
    func_00169398(p, *a1, a1, a2, a3);
    *(s32*)(p + 0x9B4) = 0;
    *(u32*)(p + 0x9B8) = 0;
    *(u32*)(p + 0) = (u32)D_003503e0;
    *(s32*)(s0 + 8) = -1;
    *(s32*)(s0 + 0x14) = 0x1800;
    *(s32*)(s0 + 4) = 0;
    *(s32*)(s0 + 0xC) = 0;
    *(s32*)(s0 + 0x10) = 0;
    *(u32*)(p + 0x9BC) = (u32)D_00350e48;
    func_001d56f0(p + 0x9DC);
    func_001d56f0(p + 0x9E8);
    *(s32*)(p + 0x588) |= 1;
    if (*(s32*)(s2 + 0x10) != 0) {
        u8* v = (u8*)func_00168b38(*(s32*)(s2 + 0x10), 0x12, 0);
        if (v != 0 && *(s32*)(v + 8) != 0) {
            func_001dddd0(p + 0x80, *(s32*)(v + 8));
        }
        v = (u8*)func_00168b38(*(s32*)(s2 + 0x10), 0x22, 0);
        if (v != 0) {
            s32 t = *(s32*)(v + 8);
            if (t != 0) {
                *(s32*)(s0 + 0xC) = 0;
                *(s32*)(s0 + 8) = -1;
                *(s32*)(s0 + 0x14) = 0x1800;
                *(s32*)(s0 + 0x10) = 0;
                // Partial asm (moved as it is from batch_w3704.cpp): fixes the sched2 order of this re-init.
                u32 vt; asm("" : "=r"(vt) : "0"(D_00350e48));
                asm("sw %2,28(%1)" : "=m"(*(s32*)(s0 + 0x1C)) : "r"(s0), "r"(t), "r"(vt));
                *(u32*)(p + 0x9BC) = vt;
                s32 two; asm("li %0,2" : "=r"(two) : "m"(*(u32*)(p + 0x9BC)));
                *(s32*)(s0 + 4) = two;
                *(u32*)(p + 0x9B8) = (u32)s0;
            }
        }
        *(s32*)(p + 0x9B4) = func_00170d18(*(s32*)(s2 + 0x10));
        v = (u8*)func_00168b38(*(s32*)(s2 + 0x10), 0x26, 0);
        if (v != 0 && *(s32*)(v + 8) != 0) {
            u8* q = p + 0x800;
            func_001b2f38(q, *(s32*)(v + 8), (u8)((*(u16*)((u8*)a1 + 0x48) >> 6) & 1));
            *(s32*)(p + 0x60C) = *(s32*)(q + 0xC);
        }
    }
    if (*(s32*)(s2 + 0x14) != 0) {
        func_0017ebe8(p + 0x140, *(s32*)(s2 + 0x14));
    }
    u16 h = *(u16*)(*(u8**)(p + 8) + 0x4E);
    if (h != 0) {
        func_00195858(p + 0x110, h);
    }
}

extern "C" {
void func_00198660(u8* a0, u32 a1, u32 a2, u32 a3);

void func_00198450(u8* p) {
    u8* q = p + 320;
    if (func_00180cd0(q) && func_001805a8(q, 0))
        func_0017f488(q, 0, 0.0f, 0.0f);
    func_00169f98(p);
}

s32 func_001984b8(u8* s0) {
    u8* s1 = s0 + 128;
    func_00180ce0(s0 + 320);
    if (*(u32*)(s0 + 128) != 0) {
        func_001de450(s1);
        func_001dde40(s1);
    }
    return func_0016a328(s0);
}

s32 func_00198510(u8* s0) {
    if (func_0016b638(s0) == 0) {
        return 0;
    }
    s32 r = 0;
    if (*(u32*)(s0 + 128) != 0) {
        if (*(u32*)(s0 + 140) != 0) {
            return r;
        }
    }
    ((void (*)(u8*))func_00198660)(s0);
    u32 p = *(u32*)(s0 + 2488);
    if (p != 0) {
        if (func_001b0320(p) != 0) {
            return r;
        }
    }
    r = 1;
    return r;
}

void func_00198580(u8* o, s32 id)
{
    u8* q = 0;
    if (id / 1000 == 500) {
        u32 fl = *(u32*)(o + 1416);
        if (fl & 0x40) q = o;
        else if (fl & 4) q = *(u8**)(o + 2808);
        if (q) {
            s16* e = *(s16**)(q + 2484);
            s32 k = e ? e[1] : -1;
            if (k >= 0) id = id % 1000 + k * 1000;
        }
    }
    func_002bc188(id, func_0016c028(o));
}

void func_00198630(u8* self, u32 a1, u32 a2) {
    u32 p = *(u32*)(self + 2488);
    if (p != 0) {
        func_001b0210(p, a1, a2, self);
    }
}

void func_00198660(u8* a0, u32 a1, u32 a2, u32 a3) {
    u32 t7 = *(u32*)(a0 + 2488);
    if (t7 != 0) {
        func_001b0250(t7, a1, a2, a3);
    }
}
}

void wtarget_00198690(u8* a, u32, u32, u32) asm("_Z16wtarget_00198690jjjj");
void wtarget_00198690(u8* a, u32, u32, u32) {
    ((void (*)(u8*))func_00198660)(a);
    Vec4 v;
    QCOPY(&v, func_0016c028(a));
    u8* p = a + 2524;
    for (s32 i = 0; i < 2; i++, p += 12) func_001d5770(p, &v);
    func_0016a9b8(a);
}

extern "C" {
struct Obj198 { u8 pad[1416]; u32 active : 1; };
Obj198* func_001b9bc8(Obj198*);
Obj198* func_00198700(Obj198* p) {
    do {
        p = func_001b9bc8(p);
    } while (p != 0 && (u8)p->active == 0);
    return p;
}

s32 func_00198738(u8* o, s8* b) {
    void* p = *(void**)(o + 1968);
    u8* r;
    if (p && (r = func_00168b88(p, 22, b[0] | (b[1] << 8) | (b[2] << 16) | (b[3] << 24), 0)) != 0) return *(s32*)(r + 8);
    return 0;
}
}

s32 wtarget_001987a8(u8* a0, s8* a1, u32 a2, u32) asm("_Z16wtarget_001987a8jjjj");
s32 wtarget_001987a8(u8* a0, s8* a1, u32 a2, u32) {
    s32 s2 = func_00198738(a0, a1);
    u8* s1 = a0 + 128;
    u8* s3 = func_001050d8(176);
    func_00196ca8(s3, 11, s2);
    *(u8**)(s3 + 8) = s1;
    if (a2 != 0) {
        func_00196e98(s3, a2);
    }
    return func_00196f00(s3);
}

namespace YS {
class STDOBJ {
public:
    void show_picture(int);
    void set_special_command(int);
    void hook_command_image();
};
}

void YS::STDOBJ::show_picture(int a) {
    u8* p = (u8*)this;
    u8* v = (u8*)func_00168b38(*(s32*)(p + 1968), 46, 0);
    func_00153d70(*(s32*)(v + 8), a);
}

void wtarget_00198970(u8* p, u32, u32, u32) asm("_Z16wtarget_00198970jjjj");

void YS::STDOBJ::set_special_command(int cmd)
{
    u8* self = (u8*)this;
    ((void (*)(u8*))wtarget_00198970)(self);
    u8* sub = self + 1952;
    u8* r1 = func_00168b88(*(void**)(sub + 16), 24, ID4(D_0036d0c8), 0);
    void* h = *(void**)(sub + 16);
    u32 a = *(u32*)(r1 + 8);
    u8* r2 = func_00168b88(h, 25, ID4(D_0036d0c8), 0);
    u8* o = *(u8**)(D_0034e948 + 2884);
    func_001bdb70(o, cmd, a, *(u32*)(r2 + 8), self);
    func_0019d720(o + 2552);
    *(u32*)(self + 268) |= 0x800;
    *(u32*)(self + 1160) += 1;
}

void wtarget_00198970(u8* p, u32, u32, u32)
{
    if (*(u32*)(p + 268) & 0x800) {
        u8* o = *(u8**)(D_0034e948 + 2884);
        ((void (*)(void*))(*(void***)o)[6])(o);
        *(s32*)(p + 1160) -= 1;
        *(u32*)(p + 268) &= ~0x800;
    }
}

void YS::STDOBJ::hook_command_image()
{
    u8* p = (u8*)this;
    u8* q = p + 1952;
    u8* r1 = func_00168b88(*(void**)(q + 16), 24, Key4(D_0036d0c8), 0);
    u32 k2 = Key4(D_0036d0c8);
    void* o = *(void**)(q + 16);
    u32 a = *(u32*)(r1 + 8);
    u32 b = *(u32*)(func_00168b88(o, 25, k2, 0) + 8);
    func_0013d6b0(a, b);
}

extern "C" {
void func_00198a90(void) { func_0013d798(); }

void func_00198aa8(u8* o, s32 i, s32 v, s32 id) {
    s32 val;
    u8* e;
    if (id == 0) {
        s16* t = *(s16**)(o + 2484);
        id = -1;
        if (t) id = t[1];
    }
    val = id * 1000 + v;
    e = o + i * 12;
    *(s32*)(e + 2532) = val;
}

typedef void (*Fn80)(u8*, u32, u32, u8*, u32);
void func_00198ae0(u8* p, u32 a, u32 b, u32 c)
{
    u8* q = p + 1148;
    if (func_0019f528(q, b) || !func_0019f550(q, b)) {
        func_0019f490(p + 1140, b);
        (*(Fn80*)(*(u8**)p + 80))(p, a, b, p, c);
    }
}
}
