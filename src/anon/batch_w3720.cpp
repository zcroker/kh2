#include "../common/types.h"
// 00232738: the D_0035de2c increment is hand-written (4 insns) so its address is not hoisted out of the loop.
extern "C" {
s32 func_00225b00(s16);
s32 func_00225b50(s16);
s32 func_00225e48(void);
void func_002278e0(void*);
void func_002326d0(void*);
void func_00232718(void);
s32 func_002baa20(s32);
void func_002baa48(s32);
typedef struct Obj_w { s32 a; s32 type; u8 pad[0xc]; s32 h; } Obj_w;
typedef struct Ent_w { Obj_w* obj; s16 time; s8 state; u8 pad[0x19]; } Ent_w;
typedef struct Hdr_w { s32 a; s16 n; s16 b; Ent_w e[1]; } Hdr_w;
extern Hdr_w* D_0035de4c;
extern s32 D_0035de20;
extern s32 D_0035de2c;
void func_00232738(void)
{
    Hdr_w* h = D_0035de4c;
    if (h == 0) return;
    s32 now = D_0035de20;
    Ent_w* e = h->e;
    s16 n = h->n;
    for (s32 i = 0; i < n; i++, e++) {
        switch (e->state) {
        case 0:
            if (now >= e->time) {
                Obj_w* o = e->obj;
                if (o->type == 3) {
                    e->state = 1;
                    if (func_00225e48() == 0 && func_00225b50(e->time) == 0 && func_00225b00(e->time) == 0) {
                        func_002326d0(o);
                        { register s32 a asm("$15"); register s32 b asm("$14"); asm volatile("lui %1,%%hi(D_0035de2c)\n\tlw %0,%%lo(D_0035de2c)(%1)\n\taddiu %0,%0,1\n\tsw %0,%%lo(D_0035de2c)(%1)" : "=&r"(a), "=&r"(b)); }
                    }
                }
            }
            break;
        case 1: {
            Obj_w* o = e->obj;
            if (func_00225e48() != 0) {
                if (func_002baa20(o->h) == 1) {
                    func_002baa48(o->h);
                    func_00232718();
                    func_002278e0(o);
                    e->state = 2;
                }
            } else {
                if (func_002baa20(o->h) == 0) {
                    func_00232718();
                    func_002278e0(o);
                    e->state = 2;
                }
            }
            break;
        }
        case 2: break;
        }
    }
}
/* 0015c880: partial asm (register pins plus scheduling dependencies). The li and the y store are hand-written so sched2
   issues the stores in the original order; the empty asm holds the a store back until the float stores are done. */
struct S4f3694 { u8 r, g, b, a; f32 x, y, z, w; };
extern u8 D_00340eb0;
extern struct S4f3694 D_004f3694;
void func_0010a8a8(f32, f32);
void func_0010a828(f32, f32);
void func_0010a7d8(u8, u8, u8);
void func_001dd1e8(u8, u8);
void func_001dd1b0(f32, f32);
void func_001dd1c8(u8, u8, u8);
static inline __attribute__((always_inline)) void init_4f3694(f32 z, f32 w, f32 y) {
    s32 t;
    register f32 yy asm("$f2") = y;
    asm("swc1 %1,%0" : "=m"(D_004f3694.y) : "f"(yy), "m"(D_00340eb0));
    asm("li %0,128" : "=r"(t) : "m"(D_004f3694.y), "m"(D_004f3694.x), "m"(D_004f3694.z), "m"(D_004f3694.w));
    D_004f3694.r = 0;
    D_004f3694.g = 0;
    D_004f3694.x = z;
    D_004f3694.z = z;
    D_004f3694.w = w;
    asm("" : "+r"(t) : "m"(D_004f3694.x), "m"(D_004f3694.y), "m"(D_004f3694.z), "m"(D_004f3694.w));
    D_004f3694.a = t;
    D_004f3694.b = 0;
    func_0010a8a8(z, w);
}
void func_0015c880(f32 arg0) {
    register s32 one asm("$14") = 1;
    D_00340eb0 = one;
    init_4f3694(0.0f, 255.0f, arg0);
    func_0010a828(D_004f3694.x, D_004f3694.y);
    func_0010a7d8(D_004f3694.r, D_004f3694.g, D_004f3694.b);
    func_001dd1e8((s32)D_004f3694.z, (s32)D_004f3694.w);
    func_001dd1b0(D_004f3694.x, D_004f3694.y);
    func_001dd1c8(D_004f3694.r, D_004f3694.g, D_004f3694.b);
}
}
