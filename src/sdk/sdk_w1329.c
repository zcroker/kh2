/* libkernl / sifrpc / libmc / libcdvd / deci2 misc (Sony PS2 Runtime Library 3.0.0) */
extern int func_0030dd70(void);

struct ThreadParam { int status; void (*entry)(void*); void *stack; int stackSize; void *gpReg; int initPriority; int currentPriority; unsigned int attr; unsigned int option; int waitType; int waitId; int wakeupCount; };
struct SemaParam { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; };
extern int func_00305420(struct ThreadParam *);
extern int func_003054b0(int, int);
extern int func_00305510(void);
extern int func_00305620(struct SemaParam *);
extern int func_00305630(int);
extern int func_00306760(int, void *);
extern void func_00306320(void *);
extern int D_003660d0;
extern char D_0037a800[];
extern int D_01e34e80;
extern int D_01e34e88[2];
extern char D_01e34a80[];
int func_003063f8(void);  // 0x003063f8: definition moved into src/sdk/libkernl_00306058.c

extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
extern int func_00306698(int);
int func_00309d60(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry);  // 0x00309d60: definition moved into src/sdk/libkernl_00309860.c

extern unsigned int D_01e38c40_u[] asm("D_01e38c40");
extern char D_01e38e40[];
int func_0030e900(unsigned int addr, void *data, unsigned int size);  // 0x0030e900: definition moved into src/sdk/eeloadfile.c

extern int func_00309c58(void);
extern int func_0030a2d0(int);
extern void func_0030a300(void);
extern void func_0030a3f8(void);
extern int func_0030a600(void);
extern int D_00366164;
extern int D_01e37280[];
extern char D_01e37ec0[];
extern char D_01e38980[];
int func_0030a808(int arg);  // 0x0030a808: definition moved into src/sdk/filestub.c

extern int D_0036617c;
extern char D_01e38a80[];
extern int D_01e38ac0[];
struct E { int arg; char name[252]; };
extern struct E D_01e38b40;
int func_0030da30(const char *name, int arg);  // 0x0030da30: definition moved into src/sdk/iopheap.c

struct AL { int pad0[2]; int id; unsigned int flags; int pad1[4]; long long time; void (*handler)(); void *gp; void *arg; };
extern int func_0030fa10(int);
extern void func_0030fba0(struct AL *);
extern void func_0030fc28(struct AL *);
extern int func_0030ff08(void);
struct KS { int pad[7]; int cur; };
extern struct KS D_00367118;
int func_00310670(int id, long long time, void (*handler)(), void *arg);  // 0x00310670: definition moved into src/sdk/libkernl_00310048.c

struct MC { struct MC *next; volatile int id; int a; int b; };
extern int func_0030ffd8(void);
extern int func_00310230(int);
extern void func_003109e0(void);
extern struct MC *D_01e3b300;
static __inline__ struct MC *mc_alloc(void)
{
    struct MC *p = D_01e3b300;
    if (p)
        D_01e3b300 = p->next;
    return p;
}
static __inline__ void mc_free(struct MC *p)
{
    struct MC *h = D_01e3b300;
    D_01e3b300 = p;
    p->next = h;
    p->id = 0;
}
int func_00310b70(int a0, int a1, int a2);  // 0x00310b70: definition moved into src/sdk/libkernl_00310048.c

struct B64 { unsigned char b[64]; };
extern void func_00305f18(void *, void *);
extern int DIntr(void);
extern void EIntr(void);
extern struct B64 D_01e2fd80;
extern struct B64 D_01e2fe00;
int func_002f5190(int port);  // 0x002f5190: definition moved into src/sdk/libdbc.c

extern unsigned int func_0030ef10(unsigned int, unsigned int, void *);
extern void func_0030f058(int, int);
extern int D_0030eed0[];
extern int D_0030ee98[];
extern int D_00366190[4];
extern unsigned int D_00366188;
void func_0030ef58(void);  // 0x0030ef58: definition moved into src/sdk/libkernl_0030ef20.c

extern int sceSifBindRpc(void *cd, unsigned int rpc, int mode);
struct CD { int pad[9]; void *serve; int pad2[2]; };
struct B4 { char b[4]; };
extern int D_00366180;
extern struct CD D_01e38e40_cd asm("D_01e38e40");
extern struct B4 D_01e38c40_b4 asm("D_01e38c40");
extern struct B4 D_01e38e68;
int func_0030dd70(void);  // 0x0030dd70: definition moved into src/sdk/eeloadfile.c

extern int func_0030de70(void);
extern char *strncpy(char *d, const char *s, int n);
struct FB { int r0; int r1; char a[252]; char b[252]; };
extern struct FB D_01e38c40_fb asm("D_01e38c40");
extern char D_01e38e40[];
int u_call4_0030e7b0(const char *s1, const char *s2, int *out, int fno) asm("_Z16u_call4_0030e7b0jjjj");
int u_call4_0030e7b0(const char *s1, const char *s2, int *out, int fno);  // 0x0030e7b0: definition moved into src/sdk/eeloadfile.c
