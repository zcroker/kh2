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
int func_003063f8(void)
{
    struct ThreadParam tp;
    struct SemaParam sp;
    if (D_003660d0 > 0)
        return -1;
    sp.maxCount = 255;
    sp.initCount = 0;
    sp.option = (unsigned int)"SceKerneltopThread";
    D_01e34e80 = func_00305620(&sp);
    if (D_01e34e80 < 0)
        return -1;
    tp.entry = func_00306320;
    tp.stack = D_01e34a80;
    tp.stackSize = 0x400;
    tp.gpReg = D_0037a800;
    tp.option = (unsigned int)"SceKerneltopThread";
    tp.initPriority = 0;
    D_003660d0 = func_00305420(&tp);
    if (D_003660d0 < 0) {
        func_00305630(D_01e34e80);
        return -1;
    }
    D_01e34e88[0] = 0;
    D_01e34e88[1] = 0;
    func_00306760(D_003660d0, D_01e34e88);
    func_003054b0(func_00305510(), 1);
    return D_003660d0;
}

extern int func_003094b8(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
extern int func_00306698(int);
int func_00309d60(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp, int noretry)
{
    int i, d, r;
    i = 0;
    d = 1;
    do {
        r = (unsigned int)func_003094b8(cd, fno, mode, send, ssize, recv, rsize, end, endp) >> 31;
        if (r == 0)
            break;
        if (noretry)
            break;
        func_00306698(d * 1000);
        if (d < 127)
            d *= 2;
        i++;
    } while (i < 101);
    return r;
}

extern unsigned int D_01e38c40_u[] asm("D_01e38c40");
extern char D_01e38e40[];
int func_0030e900(unsigned int addr, void *data, unsigned int size)
{
    if (func_0030dd70() < 0)
        return 0xffff0000;
    if (size >= 3)
        return 0xfffefffe;
    D_01e38c40_u[0] = addr;
    D_01e38c40_u[1] = size;
    if (func_003094b8(D_01e38e40, 3, 0, D_01e38c40_u, 32, D_01e38c40_u, 32, 0, 0) < 0)
        return 0xfffeffff;
    if (size == 0) {
        *(unsigned char *)data = D_01e38c40_u[0];
    } else if (size == 1) {
        *(unsigned short *)data = D_01e38c40_u[0];
    } else if (size == 2) {
        *(unsigned int *)data = D_01e38c40_u[0];
    } else
        return 0xfffefffe;
    return 0;
}

extern int func_00309c58(void);
extern int func_0030a2d0(int);
extern void func_0030a300(void);
extern void func_0030a3f8(void);
extern int func_0030a600(void);
extern int D_00366164;
extern int D_01e37280[];
extern char D_01e37ec0[];
extern char D_01e38980[];
int func_0030a808(int arg)
{
    int r;
    r = func_0030a2d0(0xfd);
    if (D_00366164 == 0)
        func_0030a3f8();
    if (func_0030a600()) {
        func_0030a300();
        return 0xfffefffc;
    }
    if (func_00309c58()) {
        func_0030a300();
        return -16;
    }
    D_01e37280[0] = arg;
    if (func_00309d60(D_01e38980, 0xfd, 0, D_01e37280, 8, D_01e37ec0, 4, 0, 0, 0) < 0) {
        func_0030a300();
        return -11;
    }
    r = *(int *)((unsigned int)D_01e37ec0 | 0x20000000);
    func_0030a300();
    return r;
}

extern int D_0036617c;
extern char D_01e38a80[];
extern int D_01e38ac0[];
struct E { int arg; char name[252]; };
extern struct E D_01e38b40;
int func_0030da30(const char *name, int arg)
{
    int i;
    if (D_0036617c < 0)
        return 0;
    for (i = 0; i < 252; i++) {
        if ((D_01e38b40.name[i] = name[i]) == 0)
            break;
    }
    if (i == 252) {
        i = 251;
        D_01e38b40.name[251] = 0;
    }
    D_01e38b40.arg = arg;
    D_01e38b40.name[251] = 0;
    if (func_003094b8(D_01e38a80, 3, 0, &D_01e38b40, i + 5, D_01e38ac0, 4, 0, 0) < 0)
        return -1;
    return D_01e38ac0[0];
}

struct AL { int pad0[2]; int id; unsigned int flags; int pad1[4]; long long time; void (*handler)(); void *gp; void *arg; };
extern int func_0030fa10(int);
extern void func_0030fba0(struct AL *);
extern void func_0030fc28(struct AL *);
extern int func_0030ff08(void);
struct KS { int pad[7]; int cur; };
extern struct KS D_00367118;
int func_00310670(int id, long long time, void (*handler)(), void *arg)
{
    struct AL *p = (struct AL *)(((unsigned int)id >> 10) << 6);
    if (id < 0 || (id & 0x3ff) != p->id)
        return 0x80008002;
    if (((volatile struct KS *)&D_00367118)->cur == id)
        return 0x80000010;
    if (p->flags & 2)
        func_0030fc28(p);
    p->handler = handler;
    if (handler == 0) {
        p->flags &= ~2U;
    } else {
        p->time = time;
        p->flags |= 2;
        asm volatile("sw $gp,%0" : "=m"(p->gp) : : "memory");
        p->arg = arg;
        if (p->flags & 1)
            func_0030fba0(p);
    }
    func_0030fa10(func_0030ff08());
    return 0;
}

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
int func_00310b70(int a0, int a1, int a2)
{
    struct MC *p;
    int id;
    if (a1 == 0)
        return 0x80000016;
    p = mc_alloc();
    if (p == 0)
        return 0x80008005;
    id = func_0030ffd8();
    if (id < 0) {
        mc_free(p);
        return id;
    }
    p->a = a1;
    p->b = a2;
    p->id = id;
    func_00310670(id, a0, func_003109e0, p);
    func_00310230(id);
    return ((int)p << 4) | (id & 0xfe) | 1;
}

struct B64 { unsigned char b[64]; };
extern void func_00305f18(void *, void *);
extern int func_0030edb0(void);
extern void func_0030ee00(void);
extern struct B64 D_01e2fd80;
extern struct B64 D_01e2fe00;
int func_002f5190(int port)
{
    func_00305f18(&D_01e2fd80, (char *)&D_01e2fd80 + 128);
    func_0030edb0();
    D_01e2fe00 = D_01e2fd80;
    func_0030ee00();
    return ((int *)&D_01e2fe00)[port] == 1 ? 1 : 3;
}

extern unsigned int func_0030ef10(unsigned int, unsigned int, void *);
extern void func_0030f058(int, int);
extern int D_0030eed0[];
extern int D_0030ee98[];
extern int D_00366190[4];
extern unsigned int D_00366188;
void func_0030ef58(void)
{
    unsigned int a, b, pa, pb;
    func_0030f058(D_00366190[0], D_00366190[1]);
    func_0030f058(D_00366190[2], D_00366190[3]);
    a = func_0030ef10(0x80000000, 0x80080000, D_0030eed0);
    b = func_0030ef10(0x80000000, 0x80080000, D_0030ee98);
    pa = a - 0x20c;
    pb = b - 0x168;
    while (pa != pb) {
        if (pa < pb) {
            a = func_0030ef10(a + 4, 0x80080000, D_0030eed0);
            pa = a - 0x20c;
        } else {
            b = func_0030ef10(b + 4, 0x80080000, D_0030ee98);
            pb = b - 0x168;
        }
    }
    D_00366188 = pa;
}

extern int func_003092d8(void *cd, unsigned int rpc, int mode);
struct CD { int pad[9]; void *serve; int pad2[2]; };
struct B4 { char b[4]; };
extern int D_00366180;
extern struct CD D_01e38e40_cd asm("D_01e38e40");
extern struct B4 D_01e38c40_b4 asm("D_01e38c40");
extern struct B4 D_01e38e68;
int func_0030dd70(void)
{
    int i;
    if (D_00366180 < 0) {
    retry:
        if (func_003092d8(&D_01e38e40_cd, 0x80000006, 0) < 0)
            return -1;
        if (D_01e38e40_cd.serve != 0) {
            D_00366180 = 0;
            if (func_003094b8(&D_01e38e40_cd, 255, 0, 0, 0, &D_01e38c40_b4, 4, 0, 0) < 0)
                return 0xfffeffff;
            D_01e38e68 = D_01e38c40_b4;
            return 0;
        }
        i = 0x100000; do { i--; __asm__ volatile("nop"); __asm__ volatile("nop"); __asm__ volatile("nop"); __asm__ volatile("nop"); } while (i != -1);
        goto retry;
    }
    return 0;
}

extern int func_0030de70(void);
extern char *func_002ff6f0(char *d, const char *s, int n);
struct FB { int r0; int r1; char a[252]; char b[252]; };
extern struct FB D_01e38c40_fb asm("D_01e38c40");
extern char D_01e38e40[];
int u_call4_0030e7b0(const char *s1, const char *s2, int *out, int fno) asm("_Z16u_call4_0030e7b0jjjj");
int u_call4_0030e7b0(const char *s1, const char *s2, int *out, int fno)
{
    if (func_0030dd70() < 0)
        return 0xffff0000;
    if (func_0030de70())
        return 0xfffefffc;
    func_002ff6f0(D_01e38c40_fb.a, s1, 252);
    D_01e38c40_fb.a[251] = 0;
    func_002ff6f0(D_01e38c40_fb.b, s2, 252);
    D_01e38c40_fb.b[251] = 0;
    if (func_003094b8(D_01e38e40, fno, 0, &D_01e38c40_fb, 512, &D_01e38c40_fb, 16, 0, 0) < 0)
        return 0xfffeffff;
    if (D_01e38c40_fb.r0 == 0)
        return 0xfffefffd;
    out[0] = D_01e38c40_fb.r0;
    out[1] = D_01e38c40_fb.r1;
    return 0;
}
