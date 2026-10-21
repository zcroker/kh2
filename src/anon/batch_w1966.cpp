#include "../common/types.h"

struct W1966Hdr {
    s16 f0, f2;
    s16 count;
    s16 start;
    s16 end;
    s16 fa;
};
struct W1966Cmd {
    u16 op;
    s16 size;
    s16 a4, a6, a8;
};
struct W1966CmdU {
    u16 op;
    u16 size;
    s16 a4, a6, a8;
};


#define W1966_QCOPY4(d, s) asm volatile("lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\tsq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)" : : "r"(d), "r"(s) : "$8", "$9", "$10", "$11", "memory")
#define W1966_QCOPY1(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")

struct W1966Mat {
    f32 m[4][4];
    W1966Mat& operator=(const W1966Mat& o) { if (this != &o) W1966_QCOPY4(this, &o); return *this; }
} __attribute__((aligned(16)));

struct W1966Vec {
    f32 v[4];
    W1966Vec& operator=(const W1966Vec& o) { if (this != &o) W1966_QCOPY1(this, &o); return *this; }
} __attribute__((aligned(16)));

struct W1966Pad {
    u8 b[16];
    W1966Pad& operator=(const W1966Pad&) { return *this; }
} __attribute__((aligned(16)));

struct W1966I3 { s32 a, b, c; };
struct W1966Pair { void* a; void* b; } __attribute__((aligned(8)));

struct W1966A {
    W1966Mat m0;
    f32 f40;
    s32 i44, i48;
    W1966I3 t4c;
    W1966Pair p58;
    void* p60;
    f32 f64, f68, f6c, f70, f74, f78;
    W1966Mat m80;
    W1966Mat mc0;
};

struct W1966B {
    W1966Pad e0;
    W1966Mat m10;
    W1966Vec v50, v60, v70;
    f32 f80;
};

extern W1966A D_003a7b70[2];
extern W1966B D_003a7f70[2];
extern W1966A D_003a81b0[2];
extern W1966B D_003a83b0[2];

extern "C" {
extern s32 D_0035daf0;
extern u32 D_0035dd04;
extern W1966Hdr* D_0035dd08[64];
extern s32 D_0035de20;
extern s32 D_0035de28;
extern u32 D_0035de60;
void func_00170888(s32);
void func_00226268(void);
void func_0022c508(void*);
void func_0022e1f8(void*, s32);
void func_0022f5a0(void*, s32, s32);
void func_00232510(void*, s32);
void func_002331a0(void*, s32, s32, s32, s32);

void func_00226090(void) {
    W1966Hdr* h;
    W1966Cmd* c;
    s32 i, n, odd;
    u32 next;
    if (D_0035dd04 >= 64) return;
    h = D_0035dd08[D_0035dd04];
    if (h != 0) {
    if (D_0035de20 < h->start) return;
    if (h->end < D_0035de20) return;
    n = h->count;
    odd = D_0035dd04 & 1;
    c = (W1966Cmd*)(h + 1);
    for (i = 0; i < n; i++) {
        switch ((s32)(u16)(c->op - 37)) {
        case 0:
            func_002331a0((u8*)c + 10, odd, c->a4, c->a6, c->a8);
            c = (W1966Cmd*)((u8*)c + c->size);
            break;
        case 1:
            func_00232510((u8*)c + 4, odd);
            c = (W1966Cmd*)((u8*)c + c->size);
            break;
        case 19:
            func_0022f5a0((u8*)c + 8, c->a4, c->a6);
            c = (W1966Cmd*)((u8*)c + c->size);
            break;
        case 20:
            func_0022e1f8((u8*)c + 6, c->a4);
            c = (W1966Cmd*)((u8*)c + ((W1966CmdU*)c)->size);
            break;
        case 25:
            func_0022c508((u8*)c + 4);
            c = (W1966Cmd*)((u8*)c + ((W1966CmdU*)c)->size);
            break;
        }
    }
    D_0035daf0 = D_0035dd08[D_0035dd04]->end - 1;
    if (D_0035daf0 < 0) D_0035daf0 = D_0035de28;
    next = D_0035dd04 + 1;
    D_0035dd04 = next;
    D_0035de60 = next;
    if (next != 1) func_00170888(0);
    } else {
        func_00226268();
    }
}

void func_001065d8(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        D_003a81b0[i] = D_003a7b70[i];
        D_003a83b0[i] = D_003a7f70[i];
    }
}

void func_001067b8(void) {
    s32 i;
    for (i = 0; i < 2; i++) {
        D_003a7b70[i] = D_003a81b0[i];
        D_003a7f70[i] = D_003a83b0[i];
    }
}
}
