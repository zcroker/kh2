/* Sony PS2 Runtime Library 3.0.0: libcdvd sceCdDiskReady (new RPC version; falls back to the old one). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { int pad[9]; void *serve; int pad2[6]; } CdClient;
extern int func_003080d0(const char *fmt, ...);
extern int DIntr(void);
extern int EIntr(void);
extern int func_002f69c8(void);
extern int func_00305670(int s);
extern int func_00305640(int s);
extern int func_002f77b0(int m);
extern void func_00308b30(int m);
extern void func_00308a80(void *p, int n);
extern int sceSifBindRpc(CdClient *cd, unsigned int rpc, int mode);
extern int sceSifCallRpc(CdClient *cd, int fno, int mode, void *sb, int ss, void *rb, int rs, void *ef, void *ea);
extern int D_00363d90;
extern int D_00363dc0;
extern volatile int D_00363db0;
extern int D_00363dd0;
extern CdClient D_01e33410;
extern int D_01e33450[4];
extern int D_00365800[4];

int ctarget_002f79c8(int mode) asm("_Z16ctarget_002f79c8jjjj");
int ctarget_002f79c8(int mode);  // 0x002f79c8: definition moved into src/sdk/libcdvd_002f77b0.c
