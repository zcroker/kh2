/* Sony PS2 Runtime Library 3.0.0: libkernl iopheap (EE side of the IOP heap RPC 0x80000003), 0x30d820-0x30dd70:
 * bind, alloc/free/load heap, query calls. Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv). No .rodata; globals (0x36617c, 0x1e38a80-0x1e38c40) stay retail data.
 * Each function keeps the declarations its old matched file used, with a _ADDR suffix and an asm
 * label to the real symbol, so their types do not clash. */
/* 0030d820 func_0030d820 (was src/sdk/sdk_w3698.c) */
typedef struct { int pad[9]; int p24; } R0030d820_0d820;
extern R0030d820_0d820 D_01e38a80_0d820 asm("D_01e38a80");
extern int D_0036617c_0d820 asm("D_0036617c");
extern int sceSifBindRpc_0d820(void *, int, int) asm("sceSifBindRpc");
int func_0030d820(void)
{
    int i;
    while (1) {
        if (sceSifBindRpc_0d820(&D_01e38a80_0d820, 0x80000003, 0) < 0) return -1;
        if (D_01e38a80_0d820.p24) {
            D_0036617c_0d820 = 0;
            break;
        }
        i = 0x100000;
        do {
            i--;

        } while (i != -1);
    }
    return 0;
}

/* 0030d8a8 func_0030d8a8 (was src/sdk/sdk_w525.c) */
extern int sceSifCallRpc_0d8a8(void *, int, int, void *, int, void *, int, void *, void *) asm("sceSifCallRpc");
extern int D_0036617c_0d8a8 asm("D_0036617c");
extern char D_01e38a80_0d8a8[] asm("D_01e38a80");
extern int D_01e38ac0_0d8a8 asm("D_01e38ac0"), D_01e38b00_0d8a8 asm("D_01e38b00");
int func_0030d8a8(int a)
{
    if (D_0036617c_0d8a8 < 0)
        return 0;
    D_01e38b00_0d8a8 = a;
    if (sceSifCallRpc_0d8a8(D_01e38a80_0d8a8, 1, 0, &D_01e38b00_0d8a8, 4, &D_01e38ac0_0d8a8, 4, 0, 0) < 0)
        return 0;
    return D_01e38ac0_0d8a8;
}

/* 0030d918 func_0030d918 (was src/sdk/sdk_w1056.c) */
extern int D_0036617c_0d918 asm("D_0036617c");
extern char D_01e38a80_0d918[] asm("D_01e38a80");
extern int D_01e38ac0_0d918 asm("D_01e38ac0");
extern int sceSifCallRpc_0d918(void *, int, int, void *, int, void *, int, void *, void *) asm("sceSifCallRpc");
typedef struct { int a, b, c; } Arg3_0d918;
extern Arg3_0d918 D_01e38b00x_0d918 asm("D_01e38b00");
int func_0030d918(int a, int b, int c)
{
    if (D_0036617c_0d918 < 0)
        return 0;
    D_01e38b00x_0d918.a = b;
    D_01e38b00x_0d918.b = a;
    D_01e38b00x_0d918.c = c;
    if (sceSifCallRpc_0d918(D_01e38a80_0d918, 4, 0, &D_01e38b00x_0d918, 12, &D_01e38ac0_0d918, 4, 0, 0) < 0)
        return 0;
    return D_01e38ac0_0d918;
}

/* 0030d998 u_call4_0030d998 (was src/sdk/sdk_w1055.c) */
extern int sceSifCallRpc_0d998(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp) asm("sceSifCallRpc");
extern int D_0036617c_0d998 asm("D_0036617c");
extern char D_01e38a80_0d998[] asm("D_01e38a80");
extern int D_01e38ac0_0d998[] asm("D_01e38ac0");
extern int D_01e38b00_0d998[] asm("D_01e38b00");
int u_call4_0030d998(int a) asm("_Z16u_call4_0030d998jjjj");
int u_call4_0030d998(int a)
{
    if (D_0036617c_0d998 < 0)
        return 0;
    D_01e38b00_0d998[0] = a;
    if (sceSifCallRpc_0d998(D_01e38a80_0d998, 2, 0, D_01e38b00_0d998, 4, D_01e38ac0_0d998, 4, 0, 0) < 0)
        return -1;
    return D_01e38ac0_0d998[0];
}

/* 0030da10 func_0030da10 (was src/anon/tiny_auto80_fptr4.cpp, gcc 3.2 copy; now C) */
extern int u_call4_0030d998_0da10(int a) asm("_Z16u_call4_0030d998jjjj");
int func_0030da10(int a)
{
    return u_call4_0030d998_0da10(a);
}

/* 0030da30 func_0030da30 (was src/sdk/sdk_w1329.c) */
extern int sceSifCallRpc_0da30(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp) asm("sceSifCallRpc");
extern int D_0036617c_0da30 asm("D_0036617c");
extern char D_01e38a80_0da30[] asm("D_01e38a80");
extern int D_01e38ac0_0da30[] asm("D_01e38ac0");
struct E_0da30 { int arg; char name[252]; };
extern struct E_0da30 D_01e38b40_0da30 asm("D_01e38b40");
int func_0030da30(const char *name, int arg)
{
    int i;
    if (D_0036617c_0da30 < 0)
        return 0;
    for (i = 0; i < 252; i++) {
        if ((D_01e38b40_0da30.name[i] = name[i]) == 0)
            break;
    }
    if (i == 252) {
        i = 251;
        D_01e38b40_0da30.name[251] = 0;
    }
    D_01e38b40_0da30.arg = arg;
    D_01e38b40_0da30.name[251] = 0;
    if (sceSifCallRpc_0da30(D_01e38a80_0da30, 3, 0, &D_01e38b40_0da30, i + 5, D_01e38ac0_0da30, 4, 0, 0) < 0)
        return -1;
    return D_01e38ac0_0da30[0];
}

/* 0030db20 func_0030db20 (was src/sdk/sdk_w525.c) */
extern int sceSifCallRpc_0db20(void *, int, int, void *, int, void *, int, void *, void *) asm("sceSifCallRpc");
extern int D_0036617c_0db20 asm("D_0036617c");
extern char D_01e38a80_0db20[] asm("D_01e38a80");
extern int D_01e38ac0_0db20 asm("D_01e38ac0"), D_01e38b00_0db20 asm("D_01e38b00");
unsigned int func_0030db20(void)
{
    if (D_0036617c_0db20 < 0)
        return 0;
    if (sceSifCallRpc_0db20(D_01e38a80_0db20, 5, 0, 0, 0, &D_01e38ac0_0db20, 4, 0, 0) < 0)
        return 0xffffffff;
    return D_01e38ac0_0db20;
}

/* 0030db90 func_0030db90 (was src/sdk/sdk_w525.c) */
extern int sceSifCallRpc_0db90(void *, int, int, void *, int, void *, int, void *, void *) asm("sceSifCallRpc");
extern int D_0036617c_0db90 asm("D_0036617c");
extern char D_01e38a80_0db90[] asm("D_01e38a80");
extern int D_01e38ac0_0db90 asm("D_01e38ac0"), D_01e38b00_0db90 asm("D_01e38b00");
unsigned int func_0030db90(void)
{
    if (D_0036617c_0db90 < 0)
        return 0;
    if (sceSifCallRpc_0db90(D_01e38a80_0db90, 6, 0, 0, 0, &D_01e38ac0_0db90, 4, 0, 0) < 0)
        return 0xffffffff;
    return D_01e38ac0_0db90;
}

/* 0030dc00 func_0030dc00 (was src/sdk/sdk_w525.c) */
extern int sceSifCallRpc_0dc00(void *, int, int, void *, int, void *, int, void *, void *) asm("sceSifCallRpc");
extern int D_0036617c_0dc00 asm("D_0036617c");
extern char D_01e38a80_0dc00[] asm("D_01e38a80");
extern int D_01e38ac0_0dc00 asm("D_01e38ac0"), D_01e38b00_0dc00 asm("D_01e38b00");
unsigned int func_0030dc00(void)
{
    if (D_0036617c_0dc00 < 0)
        return 0;
    if (sceSifCallRpc_0dc00(D_01e38a80_0dc00, 7, 0, 0, 0, &D_01e38ac0_0dc00, 4, 0, 0) < 0)
        return 0xffffffff;
    return D_01e38ac0_0dc00;
}

/* 0030dc70 func_0030dc70 (was src/sdk/sdk_w1056.c) */
typedef unsigned int u32_0dc70;
extern int D_0036617c_0dc70 asm("D_0036617c");
extern int D_01e38b00_0dc70 asm("D_01e38b00");
extern char D_01e38a80_0dc70[] asm("D_01e38a80");
extern int D_01e38ac0_0dc70 asm("D_01e38ac0");
extern int sceSifCallRpc_0dc70(void *, int, int, void *, int, void *, int, void *, void *) asm("sceSifCallRpc");
u32_0dc70 func_0030dc70(int a)
{
    if (D_0036617c_0dc70 < 0)
        return 0;
    D_01e38b00_0dc70 = a;
    if (sceSifCallRpc_0dc70(D_01e38a80_0dc70, 8, 0, &D_01e38b00_0dc70, 4, &D_01e38ac0_0dc70, 4, 0, 0) < 0)
        return 0xffffffff;
    return D_01e38ac0_0dc70;
}

/* 0030dcf0 func_0030dcf0 (was src/sdk/sdk_w1056.c) */
typedef unsigned int u32_0dcf0;
extern int D_0036617c_0dcf0 asm("D_0036617c");
extern int D_01e38b00_0dcf0 asm("D_01e38b00");
extern char D_01e38a80_0dcf0[] asm("D_01e38a80");
extern int D_01e38ac0_0dcf0 asm("D_01e38ac0");
extern int sceSifCallRpc_0dcf0(void *, int, int, void *, int, void *, int, void *, void *) asm("sceSifCallRpc");
u32_0dcf0 func_0030dcf0(int a)
{
    if (D_0036617c_0dcf0 < 0)
        return 0;
    D_01e38b00_0dcf0 = a;
    if (sceSifCallRpc_0dcf0(D_01e38a80_0dcf0, 9, 0, &D_01e38b00_0dcf0, 4, &D_01e38ac0_0dcf0, 4, 0, 0) < 0)
        return 0xffffffff;
    return D_01e38ac0_0dcf0;
}

