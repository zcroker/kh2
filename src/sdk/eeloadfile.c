/* Sony PS2 Runtime Library 3.0.0: libkernl eeloadfile (EE side of the LOADFILE RPC 0x80000006), 0x30dd70-0x30eacc:
 * bind + version check, module/ELF load, IOP memory peek/poke calls. Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv). .data 0x366180 (bind state, version wildcard) and .rodata 0x3783b0 are
 * defined here; the RPC buffers (0x1e38c40-0x1e38e80) stay retail data.
 * Each function keeps the declarations its old matched file used, with a _ADDR suffix and an asm
 * label to the real symbol, so their types do not clash. */
int D_00366180 = -1;
char *D_00366184 = "....";

/* 0030dd70 func_0030dd70 (was src/sdk/sdk_w1329.c) */
extern int sceSifCallRpc_0dd70(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp) asm("sceSifCallRpc");
extern int sceSifBindRpc_0dd70(void *cd, unsigned int rpc, int mode) asm("sceSifBindRpc");
struct CD_0dd70 { int pad[9]; void *serve; int pad2[2]; };
struct B4_0dd70 { char b[4]; };
extern int D_00366180_0dd70 asm("D_00366180");
extern struct CD_0dd70 D_01e38e40_cd_0dd70 asm("D_01e38e40");
extern struct B4_0dd70 D_01e38c40_b4_0dd70 asm("D_01e38c40");
extern struct B4_0dd70 D_01e38e68_0dd70 asm("D_01e38e68");
int func_0030dd70(void)
{
    int i;
    if (D_00366180_0dd70 < 0) {
    retry:
        if (sceSifBindRpc_0dd70(&D_01e38e40_cd_0dd70, 0x80000006, 0) < 0)
            return -1;
        if (D_01e38e40_cd_0dd70.serve != 0) {
            D_00366180_0dd70 = 0;
            if (sceSifCallRpc_0dd70(&D_01e38e40_cd_0dd70, 255, 0, 0, 0, &D_01e38c40_b4_0dd70, 4, 0, 0) < 0)
                return 0xfffeffff;
            D_01e38e68_0dd70 = D_01e38c40_b4_0dd70;
            return 0;
        }
        i = 0x100000; do { i--; __asm__ volatile("nop"); __asm__ volatile("nop"); __asm__ volatile("nop"); __asm__ volatile("nop"); } while (i != -1);
        goto retry;
    }
    return 0;
}

/* 0030de70 func_0030de70 (was src/sdk/sdk_w1057.c) */
extern int memcmp_0de70(void *, void *, int) asm("memcmp");
extern char D_003660c4_0de70[] asm("D_003660c4");

extern char *D_00366184_0de70 asm("D_00366184");
extern char D_01e38e68_0de70[] asm("D_01e38e68");
int func_0030de70(void)
{
    int r = 0;
    char *q = D_003660c4_0de70; char *p = D_01e38e68_0de70;
    if (memcmp_0de70(p, q, 4) && memcmp_0de70(p, D_00366184_0de70, 4))
        r = memcmp_0de70(q, D_00366184_0de70, 4) != 0;
    return r;
}

/* 0030df00 func_0030df00 (was src/sdk/sdk_w513.c) */
extern int D_00366180_0df00 asm("D_00366180");
extern char D_01e38e68_0df00[] asm("D_01e38e68");
extern int func_002fde18_0df00(void *, int, int) asm("func_002fde18");
int func_0030df00(void)
{
    D_00366180_0df00 = -1;
    func_002fde18_0df00(D_01e38e68_0df00, 0, 4);
    return 0;
}

/* 0030df38 _Z16u_call4_0030df38jjjj (was src/sdk/sdk_w1334.c) */
typedef struct { char b[252]; } B252_0df38;
typedef struct { int v; int len; char pad[252]; char data[252]; } MP_0df38;
extern MP_0df38 D_01e38c40_0df38 asm("D_01e38c40");
extern char D_01e38e40_0df38[] asm("D_01e38e40");
extern int func_0030dd70_0df38(void) asm("func_0030dd70");
extern int func_0030de70_0df38(void) asm("func_0030de70");
extern int sceSifCallRpc_0df38(void *, int, int, void *, int, void *, int, void *, void *) asm("sceSifCallRpc");
extern void *memcpy_0df38(void *, const void *, int) asm("memcpy");

int u_call4_0030df38(int a, int len, void *data, int *out) asm("_Z16u_call4_0030df38jjjj");
int u_call4_0030df38(int a, int len, void *data, int *out)
{
    if (func_0030dd70_0df38() < 0) return 0xffff0000;
    if (func_0030de70_0df38()) return 0xfffefffc;
    D_01e38c40_0df38.v = a;
    if (data) {
        if (len > 252) {
            *(B252_0df38 *)D_01e38c40_0df38.data = *(B252_0df38 *)data;
            D_01e38c40_0df38.len = 252;
        } else {
            memcpy_0df38(D_01e38c40_0df38.data, data, len);
            D_01e38c40_0df38.len = len;
        }
    } else
        D_01e38c40_0df38.len = 0;
    if (sceSifCallRpc_0df38(D_01e38e40_0df38, 6, 0, &D_01e38c40_0df38, 512, &D_01e38c40_0df38, 8, 0, 0) < 0) return 0xfffeffff;
    {
        int r = D_01e38c40_0df38.v;
        *out = D_01e38c40_0df38.len;
        return r;
    }
}

/* 0030e140 func_0030e140 (was src/sdk/sdk_w1334.c) */
typedef struct { char b[252]; } B252_0e140;
typedef struct { int v; int len; char pad[252]; char data[252]; } MP_0e140;
extern MP_0e140 D_01e38c40_0e140 asm("D_01e38c40");
extern char D_01e38e40_0e140[] asm("D_01e38e40");
extern int func_0030dd70_0e140(void) asm("func_0030dd70");
extern int func_0030de70_0e140(void) asm("func_0030de70");
extern int sceSifCallRpc_0e140(void *, int, int, void *, int, void *, int, void *, void *) asm("sceSifCallRpc");
extern void *memcpy_0e140(void *, const void *, int) asm("memcpy");
int func_0030e140(int a, int len, void *data, int *out)
{
    if (func_0030dd70_0e140() < 0) return 0xffff0000;
    if (func_0030de70_0e140()) return 0xfffefffc;
    D_01e38c40_0e140.v = a;
    if (data) {
        if (len > 252) {
            *(B252_0e140 *)D_01e38c40_0e140.data = *(B252_0e140 *)data;
            D_01e38c40_0e140.len = 252;
        } else {
            memcpy_0e140(D_01e38c40_0e140.data, data, len);
            D_01e38c40_0e140.len = len;
        }
    } else
        D_01e38c40_0e140.len = 0;
    if (sceSifCallRpc_0e140(D_01e38e40_0e140, 7, 0, &D_01e38c40_0e140, 512, &D_01e38c40_0e140, 8, 0, 0) < 0) return 0xfffeffff;
    {
        int r = D_01e38c40_0e140.v;
        *out = D_01e38c40_0e140.len;
        return r;
    }
}

/* 0030e348 func_0030e348 (was src/sdk/sdk_w1057.c) */
extern int func_0030dd70_0e348(void) asm("func_0030dd70");
extern int sceSifCallRpc_0e348(void *, int, int, int *, int, int *, int, int, int) asm("sceSifCallRpc");
extern int D_01e38c40_0e348 asm("D_01e38c40");
extern char D_01e38e40_0e348[] asm("D_01e38e40");
int func_0030e348(int a)
{
    if (func_0030dd70_0e348() < 0) return 0xffff0000;
    if (func_0030de70()) return 0xfffefffc;
    D_01e38c40_0e348 = a;
    if (sceSifCallRpc_0e348(D_01e38e40_0e348, 8, 0, &D_01e38c40_0e348, 4, &D_01e38c40_0e348, 4, 0, 0) < 0) return 0xfffeffff;
    return D_01e38c40_0e348;
}

/* 0030e3d8 func_0030e3d8 (was src/sdk/sdk_w1260.c) */
extern int func_0030dd70_0e3d8(void) asm("func_0030dd70");
extern int func_0030de70_0e3d8(void) asm("func_0030de70");
extern char* strncpy_0e3d8(char *d, const char *s, int n) asm("strncpy");
extern int sceSifCallRpc_0e3d8(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp) asm("sceSifCallRpc");
typedef struct { int ret; int pad; char name[252]; } Buf_w1260_0e3d8;
extern Buf_w1260_0e3d8 D_01e38c40_0e3d8 asm("D_01e38c40");
extern char D_01e38e40_0e3d8[] asm("D_01e38e40");
int func_0030e3d8(const char *name)
{
    if (func_0030dd70_0e3d8() < 0)
        return 0xffff0000;
    if (func_0030de70_0e3d8() != 0)
        return 0xfffefffc;
    strncpy_0e3d8(D_01e38c40_0e3d8.name, name, 252);
    D_01e38c40_0e3d8.name[251] = 0;
    if (sceSifCallRpc_0e3d8(D_01e38e40_0e3d8, 9, 0, &D_01e38c40_0e3d8, 512, &D_01e38c40_0e3d8, 4, 0, 0) < 0)
        return 0xfffeffff;
    return D_01e38c40_0e3d8.ret;
}

/* 0030e478 func_0030e478 (was src/sdk/sdk_w1057.c) */
extern int func_0030dd70_0e478(void) asm("func_0030dd70");
extern int sceSifCallRpc_0e478(void *, int, int, int *, int, int *, int, int, int) asm("sceSifCallRpc");
extern int D_01e38c40_0e478 asm("D_01e38c40");
extern char D_01e38e40_0e478[] asm("D_01e38e40");
int func_0030e478(int a)
{
    if (func_0030dd70_0e478() < 0) return 0xffff0000;
    if (func_0030de70()) return 0xfffefffc;
    D_01e38c40_0e478 = a;
    if (sceSifCallRpc_0e478(D_01e38e40_0e478, 10, 0, &D_01e38c40_0e478, 4, &D_01e38c40_0e478, 4, 0, 0) < 0) return 0xfffeffff;
    return D_01e38c40_0e478;
}

/* 0030e508 func_0030e508 (was src/anon/tiny_auto80_queue.cpp) */
extern int u_call4_0030df38_0e508(const char *, int, const char *, int *) asm("_Z16u_call4_0030df38jjjj");
int func_0030e508(const char *path, int args, const char *argp)
{
    int result;
    return u_call4_0030df38_0e508(path, args, argp, &result);
}

/* 0030e528 func_0030e528 (was src/anon/tiny_auto80_fptr4.cpp) */
extern int u_call4_0030df38_0e528(const char *, int, const char *, int *) asm("_Z16u_call4_0030df38jjjj");
int func_0030e528(const char *path, int args, const char *argp, int *result)
{
    return u_call4_0030df38_0e528(path, args, argp, result);
}

/* 0030e548 func_0030e548 (was src/sdk/sdk_w1334.c) */
typedef struct { char b[252]; } B252_0e548;
typedef struct { int v; int len; char pad[252]; char data[252]; } MP_0e548;
extern MP_0e548 D_01e38c40_0e548 asm("D_01e38c40");
extern char D_01e38e40_0e548[] asm("D_01e38e40");
extern int func_0030dd70_0e548(void) asm("func_0030dd70");
extern int func_0030de70_0e548(void) asm("func_0030de70");
extern int sceSifCallRpc_0e548(void *, int, int, void *, int, void *, int, void *, void *) asm("sceSifCallRpc");
extern void *memcpy_0e548(void *, const void *, int) asm("memcpy");

extern char *strncpy_0e548(char *, const char *, int) asm("strncpy");
int func_0030e548(const char *name, int len, void *data, int *out, int fno)
{
    if (func_0030dd70_0e548() < 0) return 0xffff0000;
    if (func_0030de70_0e548()) return 0xfffefffc;
    strncpy_0e548(D_01e38c40_0e548.pad, name, 252);
    D_01e38c40_0e548.pad[251] = 0;
    if (data) {
        if (len > 252) {
            *(B252_0e548 *)D_01e38c40_0e548.data = *(B252_0e548 *)data;
            D_01e38c40_0e548.v = 252;
        } else {
            memcpy_0e548(D_01e38c40_0e548.data, data, len);
            D_01e38c40_0e548.v = len;
        }
    } else {
        D_01e38c40_0e548.data[0] = 0;
        D_01e38c40_0e548.v = 0;
    }
    if (sceSifCallRpc_0e548(D_01e38e40_0e548, fno, 0, &D_01e38c40_0e548, 512, &D_01e38c40_0e548, 8, 0, 0) < 0) return 0xfffeffff;
    {
        int r = D_01e38c40_0e548.v;
        *out = D_01e38c40_0e548.len;
        return r;
    }
}

/* 0030e770 func_0030e770 (was src/anon/tiny_auto80_queue.cpp) */
extern int func_0030e548_0e770(const char *, int, const char *, int *, int) asm("func_0030e548");
int func_0030e770(const char *path, int args, const char *argp)
{
    int result;
    return func_0030e548_0e770(path, args, argp, &result, 0);
}

/* 0030e790 func_0030e790 (was src/anon/tiny_auto80_solver.cpp) */
extern int func_0030e548_0e790(const char *, int, const char *, int *, int) asm("func_0030e548");
int func_0030e790(const char *path, int args, const char *argp, int *result)
{
    return func_0030e548_0e790(path, args, argp, result, 0);
}

/* 0030e7b0 _Z16u_call4_0030e7b0jjjj (was src/sdk/sdk_w1329.c) */
extern int func_0030dd70_0e7b0(void) asm("func_0030dd70");
extern int sceSifCallRpc_0e7b0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp) asm("sceSifCallRpc");
extern char D_01e38e40_0e7b0[] asm("D_01e38e40");
extern int func_0030de70_0e7b0(void) asm("func_0030de70");
extern char *strncpy_0e7b0(char *d, const char *s, int n) asm("strncpy");
struct FB_0e7b0 { int r0; int r1; char a[252]; char b[252]; };
extern struct FB_0e7b0 D_01e38c40_fb_0e7b0 asm("D_01e38c40");
extern char D_01e38e40_0e7b0[] asm("D_01e38e40");
int u_call4_0030e7b0(const char *s1, const char *s2, int *out, int fno) asm("_Z16u_call4_0030e7b0jjjj");
int u_call4_0030e7b0(const char *s1, const char *s2, int *out, int fno)
{
    if (func_0030dd70_0e7b0() < 0)
        return 0xffff0000;
    if (func_0030de70_0e7b0())
        return 0xfffefffc;
    strncpy_0e7b0(D_01e38c40_fb_0e7b0.a, s1, 252);
    D_01e38c40_fb_0e7b0.a[251] = 0;
    strncpy_0e7b0(D_01e38c40_fb_0e7b0.b, s2, 252);
    D_01e38c40_fb_0e7b0.b[251] = 0;
    if (sceSifCallRpc_0e7b0(D_01e38e40_0e7b0, fno, 0, &D_01e38c40_fb_0e7b0, 512, &D_01e38c40_fb_0e7b0, 16, 0, 0) < 0)
        return 0xfffeffff;
    if (D_01e38c40_fb_0e7b0.r0 == 0)
        return 0xfffefffd;
    out[0] = D_01e38c40_fb_0e7b0.r0;
    out[1] = D_01e38c40_fb_0e7b0.r1;
    return 0;
}

/* 0030e8b8 func_0030e8b8 (was src/anon/tiny_auto80_fptr4.cpp) */
extern int u_call4_0030e7b0_0e8b8(const char *, const char *, int *, int) asm("_Z16u_call4_0030e7b0jjjj");
int func_0030e8b8(const char *name, const char *section, int *data)
{
    return u_call4_0030e7b0_0e8b8(name, section, data, 1);
}

/* 0030e8d8 gap function (not in layout.tsv): load a whole ELF ("all" sections) */
extern int u_call4_0030e7b0_0e8d8(const char *, const char *, int *, int) asm("_Z16u_call4_0030e7b0jjjj");
int func_0030e8d8(const char *name, int *data)
{
    return u_call4_0030e7b0_0e8d8(name, "all", data, 1);
}

/* 0030e900 func_0030e900 (was src/sdk/sdk_w1329.c) */
extern int func_0030dd70_0e900(void) asm("func_0030dd70");
extern int sceSifCallRpc_0e900(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp) asm("sceSifCallRpc");
extern unsigned int D_01e38c40_u_0e900[] asm("D_01e38c40");
extern char D_01e38e40_0e900[] asm("D_01e38e40");
int func_0030e900(unsigned int addr, void *data, unsigned int size)
{
    if (func_0030dd70_0e900() < 0)
        return 0xffff0000;
    if (size >= 3)
        return 0xfffefffe;
    D_01e38c40_u_0e900[0] = addr;
    D_01e38c40_u_0e900[1] = size;
    if (sceSifCallRpc_0e900(D_01e38e40_0e900, 3, 0, D_01e38c40_u_0e900, 32, D_01e38c40_u_0e900, 32, 0, 0) < 0)
        return 0xfffeffff;
    if (size == 0) {
        *(unsigned char *)data = D_01e38c40_u_0e900[0];
    } else if (size == 1) {
        *(unsigned short *)data = D_01e38c40_u_0e900[0];
    } else if (size == 2) {
        *(unsigned int *)data = D_01e38c40_u_0e900[0];
    } else
        return 0xfffefffe;
    return 0;
}

/* 0030e9f0 func_0030e9f0 (was src/sdk/sdk_w1328.c) */
extern int sceSifCallRpc_0e9f0(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp) asm("sceSifCallRpc");
typedef struct { int a; int type; union { unsigned char b; unsigned short h; int w; } v; } I1328_0e9f0;
extern I1328_0e9f0 D_01e38c40_0e9f0 asm("D_01e38c40");
extern char D_01e38e40_0e9f0[] asm("D_01e38e40");
extern int func_0030dd70_0e9f0(void) asm("func_0030dd70");
extern int sceSifCallRpc_0e9f0(void *, int, int, void *, int, void *, int, void *, void *) asm("sceSifCallRpc");
int func_0030e9f0(int a, void *val, int type)
{
    if (func_0030dd70_0e9f0() < 0) return 0xffff0000;
    D_01e38c40_0e9f0.a = a;
    D_01e38c40_0e9f0.type = type;
    if (type == 0) D_01e38c40_0e9f0.v.b = *(unsigned char *)val;
    else if (type == 1) D_01e38c40_0e9f0.v.h = *(unsigned short *)val;
    else if (type == 2) D_01e38c40_0e9f0.v.w = *(int *)val;
    else return 0xfffefffe;
    if (sceSifCallRpc_0e9f0(D_01e38e40_0e9f0, 2, 0, &D_01e38c40_0e9f0, 32, &D_01e38c40_0e9f0, 16, 0, 0) < 0) return 0xfffeffff;
    return 0;
}
