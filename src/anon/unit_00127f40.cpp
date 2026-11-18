// Linked unit 0x00127ec8-0x00128040.
#include "../common/types.h"

// 00127ec8 (gap: the other constructor clone, same body as 0x127f40)
namespace g00127ec8 {
void func_00124bb8(void*) asm("func_00124bb8");
extern void* D_00347bb0[] asm("D_00347bb0");
struct E64 { u8 b[64]; };
extern E64 D_003a99f0[] asm("D_003a99f0");
void func_0011ed90(u8*, s32) asm("func_0011ed90");
struct H3 { u8 pad[16]; u32 lo : 16; u32 hi : 16; u32 pad2; u32 off; };
struct P3 { u32 vt; H3* h; u32 base; u32 a; u32 b; u32 c; };
void func_00127ec8(P3* p) asm("func_00127ec8");
void func_00127ec8(P3* p) {
    func_00124bb8(p);  // obj_ctor_347b88
    p->vt = (u32)D_00347bb0;
    H3* h = p->h;
    s32 n = h->hi - h->lo;
    p->base = (u32)D_003a99f0;
    p->a = (u32)(D_003a99f0 + h->hi);
    p->b = (u32)((E64*)p->a + n);
    p->c = (u32)((E64*)p->b + n);
    func_0011ed90((u8*)h + h->off, n);
}
}  // namespace g00127ec8

// 00127f40 (was src/anon/batch_w43.cpp)
namespace n00127f40 {
void func_00124bb8(void*) asm("func_00124bb8");
// obj_ctor_347b88
extern void* D_00347bb0[] asm("D_00347bb0");
struct E64 { u8 b[64]; };
extern E64 D_003a99f0[] asm("D_003a99f0");
void func_0011ed90(u8*, s32) asm("func_0011ed90");
struct H3 { u8 pad[16]; u32 lo : 16; u32 hi : 16; u32 pad2; u32 off; };
struct P3 { u32 vt; H3* h; u32 base; u32 a; u32 b; u32 c; };
/*TARGET 00127f40*/
void func_00127f40(P3* p) asm("func_00127f40");
void func_00127f40(P3* p) {
    func_00124bb8(p);  // obj_ctor_347b88
    p->vt = (u32)D_00347bb0;
    H3* h = p->h;
    s32 n = h->hi - h->lo;
    p->base = (u32)D_003a99f0;
    p->a = (u32)(D_003a99f0 + h->hi);
    p->b = (u32)((E64*)p->a + n);
    p->c = (u32)((E64*)p->b + n);
    func_0011ed90((u8*)h + h->off, n);
}
}  // namespace n00127f40

// 00127fb8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00127fb8 {
// set_vtbl_347940
u32 func_00124c08(u32, u32, u32, u32) asm("_Z13func_00124c08jjjj");
extern u8 D_00347bb0 asm("D_00347bb0");
/*TARGET 00127fb8*/
u32 func_00127fb8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00127fb8jjjj");
u32 func_00127fb8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347bb0;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00124c08)(u32, u32, u32, u32) = func_00124c08;
    r2 = fp_call4_00124c08(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00127fb8

// 00127fe0 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00127fe0 {
// set_vtbl_347940
u32 func_00124c08(u32, u32, u32, u32) asm("_Z13func_00124c08jjjj");
extern u8 D_00347bb0 asm("D_00347bb0");
/*TARGET 00127fe0*/
u32 func_00127fe0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00127fe0jjjj");
u32 func_00127fe0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15;
    r15 = (u32)&D_00347bb0;
    *(u32*)((u32)r4 + (s32)(0)) = r15;
    u32 (*fp_call4_00124c08)(u32, u32, u32, u32) = func_00124c08;
    r2 = fp_call4_00124c08(r4, r5, r6, r7);
    return r2;
}
}  // namespace n00127fe0

// 00128008 (was src/anon/batch_w14.cpp)
namespace n00128008 {
void func_00124c08(void*) asm("func_00124c08");
// set_vtbl_347b88
void func_00106420(void*) asm("func_00106420");
extern u8 D_00347bb0[] asm("D_00347bb0");
/*TARGET 00128008*/
void func_00128008(u8* p) asm("func_00128008");
void func_00128008(u8* p) {
    *(u8**)p = D_00347bb0;
    func_00124c08(p);  // set_vtbl_347b88
    func_00106420(p);
}
}  // namespace n00128008

