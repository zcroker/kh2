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
int func_0030eca0(char *img);  // 0x0030eca0: definition moved into src/sdk/iopreset.c

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
extern int sceSifCallRpc(void *cd, unsigned int fno, unsigned int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
extern void func_002fc038(void *);
int func_002fc0e8(int a, void *buf, int size);  // 0x002fc0e8: definition moved into src/sdk/libmc.c

extern int D_003674b8;
extern int D_00366968[2];
extern void func_0030f280(int, int);
extern int func_0030f240(int, void *, int);
extern int strlen(const char *);
int func_0030f290(const char *name, int argc, char **argv);  // 0x0030f290: definition moved into src/sdk/libkernl_0030f290.c

typedef struct { int port; int slot; int c; int d; int e; char name[1024]; } SendDir;
extern SendDir D_01e33530;
extern char *strncpy(char *, const char *, int);
extern void func_002fbba8(void *);
int func_002fca78(int port, int slot, const char *name);  // 0x002fca78: definition moved into src/sdk/libmc.c

int func_002fbd38(int port, int slot, const char *name, int mode);  // 0x002fbd38: definition moved into src/sdk/libmc.c

/* libdbc */
typedef struct { int a; int b; int size; unsigned char data[128]; int result; } DbcRecv;
extern int D_01e2fe40;
extern char D_01e2d980[];
extern DbcRecv D_01e2da80;
extern int func_00305660(int);
extern int func_00305640(int);
extern int func_002f5c48(const char *, ...);
int sceDbcSendData(int a, int b, int *size, unsigned char *buf);  // 0x002f56e8: definition moved into src/sdk/libdbc.c

int sceDbcReceiveData(int a, int b, int *size, unsigned char *buf);  // 0x002f5b20: definition moved into src/sdk/libdbc.c
