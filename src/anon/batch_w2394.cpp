#include "../common/types.h"
#define QCOPY4_W(d, s) asm volatile(".set noreorder\n\tlq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t.set reorder" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
struct WM {
    f32 m[4][4];
    WM() {}
    WM(const WM& o) { QCOPY4_W(this, &o); }
    WM& operator=(const WM& o) { if (this != &o) QCOPY4_W(this, &o); return *this; }
    void invOrtho() {
        asm volatile("lq $8, 0(%0)\n\tlq $9, 16(%0)\n\tlq $10, 32(%0)\n\tqmfc2 $11, $vf0\n\tlqc2 $vf4, 48(%0)\n\t"
            "pextlw $12, $9, $8\n\tpextuw $13, $9, $8\n\tpextlw $14, $11, $10\n\tpextuw $15, $11, $10\n\t"
            "pcpyld $8, $14, $12\n\tpcpyud $9, $12, $14\n\tpcpyld $10, $15, $13\n\t"
            "qmtc2 $8, $vf1\n\tqmtc2 $9, $vf2\n\tqmtc2 $10, $vf3\n\t"
            "vmulax.xyz ACC, $vf1, $vf4x\n\tvmadday.xyz ACC, $vf2, $vf4y\n\tvmaddz.xyz $vf4, $vf3, $vf4z\n\tvsub.xyz $vf4, $vf0, $vf4\n\t"
            "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsqc2 $vf4, 48(%0)" : : "r"(this) : "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "memory");
    }
} __attribute__((aligned(16)));
struct WCamHead { u8 pad[16]; };
struct WCam : WCamHead, WM {};
struct WTgt {
    u8 pad0[0x64];
    f32 f64;
    u8 pad68[0xb4 - 0x68];
    u8 bB4;
    u8 padB5[0xc9 - 0xb5];
    u8 bC9;
    u8 padCA[0x190 - 0xca];
    WM mat;
};
extern "C" {
WCam* func_00106a60(s32);
void* func_00106a18(void);
void func_00106de8(void*, s32, f32);
void func_00106c08(void*);

void wtarget_002d78a8(u32 a0, u32, u32, u32) asm("_Z16wtarget_002d78a8jjjj");
/* 002d78a8: target matrix update. One variable c holds both call results (camera in the first branch,
   object in the second), which gives the original's saved-register order. */
void wtarget_002d78a8(u32 a0, u32, u32, u32) {
    WTgt* t = (WTgt*)a0;
    WM* pm;
    WCam* c;
    if (t->bC9) {
        pm = &t->mat;
        c = func_00106a60(1);
        WM m = *c;
        *pm = m;
        pm->invOrtho();
    } else {
        c = (WCam*)func_00106a18();
        func_00106de8(c, 1, t->f64);
        func_00106c08(c);
        WM m = t->mat;
        m.invOrtho();
        func_00106a60(1)->WM::operator=(m);
        t->bB4 = 1;
    }
}
}
