/* libcdvd (Sony PS2 Runtime Library 3.0.0): sceCdSearchFile */
typedef struct { unsigned int lsn; unsigned int size; char name[16]; unsigned char date[8]; unsigned int flag; } CdlFILE;
typedef struct { int pad[9]; void *serve; int pad2[6]; } CdClient;
typedef struct { int pad[9]; char name[256]; void *buf; int x128; } SearchArg;
extern void func_003080d0(const char *fmt, ...);
extern void func_002f69c8(void);
extern int func_00305670(int s);
extern int func_00305640(int s);
extern int func_002f71b0(int m);
extern void func_00308b30(int m);
extern int func_00308a80(void *p, int n);
extern int sceSifBindRpc(CdClient *cd, unsigned int rpc, int mode);
extern int sceSifCallRpc(CdClient *cd, int fno, int mode, void *sb, int ss, void *rb, int rs, void *ef, void *ea);
extern int D_00363d90;
extern int D_00363d9c;
extern volatile int D_00363da8;
extern int D_00363dcc;
extern SearchArg D_01e33240;
extern int D_01e33380[4];
extern CdClient D_01e333c0;

int sceCdSearchFile(CdlFILE *fp, const char *name, int x) asm("_Z15sceCdSearchFilejjjj");
int sceCdSearchFile(CdlFILE *fp, const char *name, int x);  // 0x002f6ca0: definition moved into src/sdk/libcdvd_002f6870.c
