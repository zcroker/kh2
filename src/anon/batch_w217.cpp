#include "../common/types.h"

extern "C" {

extern u32 D_0032b930;
struct S104298 { u32 vt; u32 a; u8 b; u8 pb[11]; u32 c, d, e, f, g, h; };
extern S104298 D_0032ba48;
void wtarget_00104298(u32 a0, u32 a1, u32, u32) asm("_Z16wtarget_00104298jjjj");
// 00104298: static initialiser, now made by gcc in src/common/gumibattle.cpp

extern f32 D_00340eb4, D_00340eb8, D_00340ebc, D_00340ec0;
void func_0010a828(f32 a, f32 b) {
    D_00340eb8 = b;
    D_00340eb4 = a;
    f32 d = b - a;
    D_00340ebc = -255.0f / d;
    D_00340ec0 = 255.0f * b / d;
}

u32* func_0016c028(u32);  // obj_get_attach_or_alt
void func_0013f828(u32* t) {
    u32* s0 = t + 32;
    u32* v = func_0016c028(t[17]);  // obj_get_attach_or_alt
    if (s0 != v) asm volatile("lq $8,0(%1)\n\tsq $8,0(%0)" :: "r"(s0), "r"(v) : "$8", "memory");
    ((f32*)t)[33] = ((f32*)t)[33] - 170.0f;
}

void func_00177a58(u32*);
void func_00187018(u32*, u32, f32, u32, u32);
void func_00176620(u32* a, u32 b) {
    a[66] |= 0x2000000;
    func_00177a58(a);
    return func_00187018(a, b, -1.0f, 0, -1);
}

extern u32 D_00350b70;
void func_001ac970(u32*, u32, u32, u32, u32, u32, u32, u32);
void func_001ad098(u32* t, u32 a1, u32 a2) {
    func_001ac970(t, 3, 5, a1, a2, 128, 104, 0);
    *(u32*)t = (u32)&D_00350b70;
    ((f32*)t)[26] = 1.0f;
}
void func_001ad0f8(u32* t, u32 a1, u32 a2) {
    func_001ac970(t, 3, 5, a1, a2, 128, 104, 0);
    *(u32*)t = (u32)&D_00350b70;
    ((f32*)t)[26] = 1.0f;
}

// hand-written: hardware register setup (DMA/VU0 control) then lq/sq copy
extern u32 D_00363ce0[];
void func_002f49c0(void) {
    asm volatile(
        ".set push\n\t.set noreorder\n\t.set noat\n\t"
        "lui $2,0x1000\n\t"
        "lui $4,0x1000\n\t"
        "ori $2,$2,0x3830\n\t"
        "ori $4,$4,0x3820\n\t"
        "sw $0,0($2)\n\t"
        "lui $3,0x1000\n\t"
        "sw $0,0($4)\n\t"
        "ori $3,$3,0x3810\n\t"
        "li $2,1\n\t"
        "sw $2,0($3)\n\t"
        "cfc2.ni $8,$28\n\t"
        "ori $8,$8,0x2\n\t"
        "ctc2.ni $8,$28\n\t"
        "sync.p\n\t"
        "lui $4,%hi(D_00363ce0)\n\t"
        "lui $5,0x1000\n\t"
        "addiu $4,$4,%lo(D_00363ce0)\n\t"
        "ori $5,$5,0x4000\n\t"
        "lq $2,0($4)\n\t"
        "sq $2,0($5)\n\t"
        "lq $3,16($4)\n\t"
        "jr $31\n\t"
        "sq $3,0($5)\n\t"
        ".set pop\n\t");
}

}
