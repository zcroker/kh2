/* Sony PS2 Runtime Library 3.0.0: libkernl (kernel alarm-list patch, sceSifRebootIop). ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { unsigned short id; short pad; int a, b, c, d; } E20;
extern int D_80076700;
extern E20 D_80076740[];
extern int func_00076038(int, int);
int func_003669c8(int arg0, int arg1) {
    int i, j;
    for (i = 0; i < D_80076700; i++) {
        if (arg1 < func_00076038(arg0, D_80076740[i].id)) {
            for (j = D_80076700 - 1; j >= i; j--)
                D_80076740[j + 1] = D_80076740[j];
            break;
        }
    }
    return i;
}

extern void func_003080d0(const char *, ...);
extern void func_00308b30(int);
extern void func_00308cd0(void);
extern int func_0030ead0(char *, int);
int func_0030eca0(char *img)
{
    char param[80];
    char *s = "rom0:UDNL ";
    char *d;
    char *p;
    p = img;
    while (*p) p++;
    if ((unsigned int)(p + 11 - img) > 80) {
        func_003080d0("too long parameter '%s'\n", img);
        return 0;
    }
    func_00308b30(0);
    func_00308cd0();
    d = param;
    while (*s) *d++ = *s++;
    while (*img) *d++ = *img++;
    *d = 0;
    return func_0030ead0(param, 0);
}

typedef struct { int a[9]; void *server; int b[22]; } CD;
typedef struct { int a; int b; int c; int size; int d; int e; void *buf; void *rdata; int pad[4]; } Send;
extern CD D_01e33480;
extern Send D_01e33500;
extern char D_01e33980[];
extern char D_01e34a40[];
extern int D_0036594c;
extern int D_00365948;
extern int func_00305670(int);
extern int func_00305640(int);
extern void func_00308a80(void *, int);
extern int func_003094b8(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
extern void func_002fc038(void *);
int func_002fc0e8(int a, void *buf, int size)
{
    if (D_01e33480.server == 0)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    D_01e33500.a = a;
    D_01e33500.buf = buf;
    D_01e33500.size = size;
    D_01e33500.rdata = D_01e33980;
    func_00308a80(buf, size);
    func_00308a80(D_01e33980, 192);
    if (func_003094b8(&D_01e33480, 5, 1, &D_01e33500, 48, D_01e34a40, 4, func_002fc038, D_01e33980)) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 5;
    return 0;
}

extern int D_003674b8;
extern int D_00366968[2];
extern void func_0030f280(int, int);
extern int func_0030f240(int, void *, int);
extern int func_002ff3fc(const char *);
int func_0030f290(const char *name, int argc, char **argv)
{
    int area = D_003674b8;
    int p = area + 64;
    int ret = p;
    int len;
    int i;
    func_0030f280(D_00366968[0], D_00366968[1]);
    if (argc >= 16)
        argc = 15;
    func_0030f240(area, &p, 4);
    area += 4;
    len = func_002ff3fc(name) + 1;
    func_0030f240(p, (void *)name, len);
    p += len;
    for (i = 0; i < argc; i++) {
        func_0030f240(area, &p, 4);
        area += 4;
        len = func_002ff3fc(argv[i]) + 1;
        func_0030f240(p, argv[i], len);
        p += len;
    }
    return ret;
}

typedef struct { int port; int slot; int c; int d; int e; char name[1024]; } SendDir;
extern SendDir D_01e33530;
extern char *func_002ff6f0(char *, const char *, int);
extern void func_002fbba8(void *);
int func_002fca78(int port, int slot, const char *name)
{
    if (D_01e33480.server == 0)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    if (name == 0 || *name == 0) {
        func_00305640(D_0036594c);
        return -210;
    }
    func_002ff6f0(D_01e33530.name, name, 1023);
    D_01e33530.port = port;
    D_01e33530.slot = slot;
    D_01e33530.name[1023] = 0;
    D_01e33530.c = 0;
    if (func_003094b8(&D_01e33480, 15, 1, &D_01e33530, 1044, D_01e34a40, 4, func_002fbba8, 0)) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 15;
    return 0;
}

int func_002fbd38(int port, int slot, const char *name, int mode)
{
    if (D_01e33480.server == 0)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    if (name == 0 || *name == 0) {
        func_00305640(D_0036594c);
        return -210;
    }
    func_002ff6f0(D_01e33530.name, name, 1023);
    D_01e33530.port = port;
    D_01e33530.c = mode;
    D_01e33530.slot = slot;
    D_01e33530.name[1023] = 0;
    if (func_003094b8(&D_01e33480, 2, 1, &D_01e33530, 1044, D_01e34a40, 4, func_002fbba8, 0)) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 2;
    return 0;
}

/* libdbc */
typedef struct { int a; int b; int size; unsigned char data[128]; int result; } DbcRecv;
extern int D_01e2fe40;
extern char D_01e2d980[];
extern DbcRecv D_01e2da80;
extern int func_00305660(int);
extern int func_00305640(int);
extern int func_002f5c48(const char *, ...);
int func_002f56e8(int a, int b, int *size, unsigned char *buf)
{
    DbcRecv *s;
    int r;
    int i;
    func_00305660(D_01e2fe40);
    s = &D_01e2da80;
    D_01e2da80.a = a;
    s->b = b;
    s->size = *size;
    for (i = 0; i < *size; i++)
        s->data[i] = buf[i];
    if (func_003094b8(D_01e2d980, 0x80001319, 0, &D_01e2da80, 144, &D_01e2da80, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcSendData: rpc error\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    if (s->result >= 0)
        *size = s->size;
    r = s->result;
    func_00305640(D_01e2fe40);
    return r;
}

int func_002f5b20(int a, int b, int *size, unsigned char *buf)
{
    DbcRecv *s;
    int r;
    int i;
    func_00305660(D_01e2fe40);
    s = &D_01e2da80;
    D_01e2da80.a = a;
    s->b = b;
    s->size = *size;
    if (func_003094b8(D_01e2d980, 0x8000131a, 0, &D_01e2da80, 144, &D_01e2da80, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcReceiveData: rpc error\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    if (s->result >= 0) {
        *size = s->size;
        for (i = 0; i < s->size; i++)
            buf[i] = s->data[i];
    }
    r = s->result;
    func_00305640(D_01e2fe40);
    return r;
}
