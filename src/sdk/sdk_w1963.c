/* Sony PS2 Runtime Library 3.0.0: libmc (sceMcSetFileInfo). ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { int a[9]; void *server; int b[22]; } CD;
typedef struct { char b[64]; } McInfo;
typedef struct { int port; int slot; int c; int d; void *e; char name[1024]; } SendDir;
extern CD D_01e33480;
extern McInfo D_01e334c0;
extern SendDir D_01e33530;
extern char D_01e34a40[];
extern int D_0036594c;
extern int D_00365948;
extern int func_00305670(int);
extern int func_00305640(int);
extern void func_003058a0(int);
extern char *func_002ff6f0(char *, const char *, int);
extern void func_002fbba8(void *);
extern int func_003094b8(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
int func_002fcc58(int port, int slot, const char *name, McInfo *info, unsigned int flags)
{
    if (D_01e33480.server == 0)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    if (name == 0 || *name == 0) {
        func_00305640(D_0036594c);
        return -210;
    }
    flags &= 7;
    D_01e33530.port = port;
    D_01e33530.slot = slot;
    D_01e33530.c = flags;
    D_01e334c0 = *info;
    D_01e33530.e = &D_01e334c0;
    func_002ff6f0(D_01e33530.name, name, 1023);
    D_01e33530.name[1023] = 0;
    func_003058a0(0);
    if (func_003094b8(&D_01e33480, 14, 1, &D_01e33530, 1044, D_01e34a40, 4, func_002fbba8, 0)) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 14;
    return 0;
}
