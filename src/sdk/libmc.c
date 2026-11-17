/* Sony PS2 Runtime Library 3.0.2: libmc (libmc.a), 0x2fb928-0x2fd15c. Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv): the whole object is compiled as one file. Its strings are .rodata
 * at 0x377820; its globals (0x365948-0x365950, 0x1e33480-0x1e34a50) stay retail data and are declared extern.
 * The rpc send buffers are seen with several struct types; those use asm-label aliases of the same symbol. */
typedef unsigned char u8;

struct SemaParam { int currentCount; int maxCount; int initCount; int numWaitThreads; unsigned int attr; unsigned int option; };
/* sceSifClientData of the mcserv rpc server */
typedef struct { int pad[9]; int server; int rest[26]; } McCd;

extern int func_00305620(struct SemaParam *);
extern int func_00305630(int);
extern int func_00305640(int);
extern void func_00305650(int);
extern int func_00305660(int);
extern int func_00305670(int);
extern void func_003058a0(int);
extern int func_003080d0(const char *, ...);
extern void func_00308a80(void *, int);
extern void func_00308b30(int);
extern int sceSifBindRpc(McCd *, unsigned int, int);
extern int sceSifCallRpc(void *cd, int fno, int mode, void *send, int ssize, void *recv, int rsize, void *end, void *endp);
extern char *strncpy(char *, const char *, int);
extern unsigned int strlen(char *);
extern char *memcpy(char *, char *, unsigned int);

extern int D_00365948;
extern int D_0036594c;
extern int D_00365950;
extern McCd D_01e33480;
extern int D_01e33500[];
extern int D_01e34a40[];
extern char D_01e33980[];
extern char D_01e33a40[];

extern int func_002fc378(int, int *, int *);
extern void func_002fbba8(void *);

/* 0x2fb928 sceMcInit */
int sceMcInit(void)
{
    struct SemaParam sp;
    int i, j, r;
    i = 0;
    if (D_0036594c < 0) {
        sp.initCount = 1;
        sp.maxCount = 1;
        sp.option = (unsigned int)"sceMc_sema_regs";
        D_0036594c = func_00305620(&sp);
        if (D_0036594c == -1)
            return -101;
        sp.maxCount = 1;
        sp.initCount = 0;
        sp.option = (unsigned int)"sceMc_sema_timer";
        r = func_00305620(&sp);
        D_00365950 = r;
        if (r == -1) {
            func_00305630(D_0036594c);
            D_0036594c = r;
            return -101;
        }
    }
    func_002fc378(0, 0, 0);
    func_00305660(D_0036594c);
    func_00308b30(0);
    for (;;) {
        if (sceSifBindRpc(&D_01e33480, 0x80000400, 0) < 0) {
            func_003080d0("bind error libmc \n");
            while (1)
                ;
        }
        if (D_01e33480.server != 0)
            break;
        for (j = 0; j < 0x100000; j++)
            ;
        i++;
        if (i >= 512) {
            func_003080d0("bind error libmc \n");
            return -91;
        }
    }
    r = sceSifCallRpc(&D_01e33480, 254, 0, D_01e33500, 48, D_01e34a40, 12, 0, 0);
    func_00305640(D_0036594c);
    if (r < 0) {
        D_01e33480.server = 0;
        return -91;
    }
    if (D_01e34a40[1] < 522) {
        func_003080d0("libmc: too old release of mcserv.irx\n");
        D_01e33480.server = 0;
        return -120;
    }
    if (D_01e34a40[2] < 526) {
        func_003080d0("libmc: too old release of mcman.irx\n");
        D_01e33480.server = 0;
        return -121;
    }
    return D_01e34a40[0];
}

/* 0x2fbb50 sceMcEnd */
int func_002fbb50(void)
{
    if (D_0036594c >= 0) {
        func_002fc378(0, 0, 0);
        func_00305630(D_0036594c);
        D_0036594c = -1;
        func_00305630(D_00365950);
    }
    return 1;
}

/* 0x2fbba8 (gap) rpc end callback: wake sceMcSync */
void func_002fbba8(void *p)
{
    func_00305650(D_00365950);
}

/* 0x2fbbb8 (gap) rpc 20 */
typedef struct { int x0; int pad[3]; int x10; int x14; } K_fbbb8;
extern K_fbbb8 D_01e33500_k asm("D_01e33500");
int func_002fbbb8(int a)
{
    if (D_01e33480.server == 0) return -100;
    if (func_00305670(D_0036594c) < 0) return -200;
    D_01e33500_k.x14 = a;
    if (sceSifCallRpc(&D_01e33480, 20, 1, &D_01e33500_k, 48, D_01e34a40, 4, func_002fbba8, 0) != 0) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 20;
    return 0;
}

/* 0x2fbc78 rpc 21 (synchronous) */
int func_002fbc78(int x)
{
    if (!D_01e33480.server)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    D_01e33500[1] = x;
    if (sceSifCallRpc(&D_01e33480, 21, 0, D_01e33500, 48, D_01e34a40, 4, 0, 0)) {
        func_00305640(D_0036594c);
        return -91;
    }
    func_00305640(D_0036594c);
    return D_01e34a40[0];
}

/* 0x2fbd38 sceMcOpen */
typedef struct { int port; int slot; int c; int d; void *e; char name[1024]; } SendDir;
extern SendDir D_01e33530;
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
    strncpy(D_01e33530.name, name, 1023);
    D_01e33530.port = port;
    D_01e33530.c = mode;
    D_01e33530.slot = slot;
    D_01e33530.name[1023] = 0;
    if (sceSifCallRpc(&D_01e33480, 2, 1, &D_01e33530, 1044, D_01e34a40, 4, func_002fbba8, 0)) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 2;
    return 0;
}

/* 0x2fbe60 sceMcMkdir */
extern int func_002fbd38_i(int, int, int, int) asm("func_002fbd38");
int func_002fbe60(int a, int b, int c)
{
    int r = func_002fbd38_i(a, b, c, 64);
    if (!r)
        D_00365948 = 11;
    return r;
}

/* 0x2fbe98 sceMcClose */
int func_002fbe98(int x)
{
    if (!D_01e33480.server)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    D_01e33500[0] = x;
    if (sceSifCallRpc(&D_01e33480, 3, 1, D_01e33500, 48, D_01e34a40, 4, func_002fbba8, 0)) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 3;
    return 0;
}

/* 0x2fbf58 sceMcSeek */
int func_002fbf58(int a, int b, int c)
{
    if (D_01e33480.server == 0) return -100;
    if (func_00305670(D_0036594c) < 0) return -200;
    D_01e33500_k.x0 = a;
    D_01e33500_k.x10 = b;
    D_01e33500_k.x14 = c;
    if (sceSifCallRpc(&D_01e33480, 4, 1, &D_01e33500_k, 48, D_01e34a40, 4, func_002fbba8, 0) != 0) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 4;
    return 0;
}

/* 0x2fc038 (gap) sceMcRead end callback: copy the unaligned head and tail bytes to the caller's buffer
   (cached and uncached views), then wake sceMcSync */
typedef struct { int n1; int n2; u8 *d1; u8 *d2; u8 b1[64]; u8 b2[64]; } McRd;
void func_002fc038(void *arg)
{
    McRd *p = (McRd *)((unsigned int)arg | 0x20000000);
    int i;
    u8 *d, *u;
    if (p->n1) {
        d = p->d1;
        u = (u8 *)((unsigned int)d | 0x20000000);
        for (i = 0; i < p->n1; i++)
            *u++ = *d++ = p->b1[i];
    }
    if (p->n2) {
        d = p->d2;
        u = (u8 *)((unsigned int)d | 0x20000000);
        for (i = 0; i < p->n2; i++)
            *u++ = *d++ = p->b2[i];
    }
    func_00305650(D_00365950);
}

/* 0x2fc0e8 sceMcRead */
typedef struct { int a; int b; int c; int size; int d; int e; void *buf; void *rdata; int pad[4]; } Send_c0e8;
extern Send_c0e8 D_01e33500_s asm("D_01e33500");
int func_002fc0e8(int a, void *buf, int size)
{
    if (D_01e33480.server == 0)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    D_01e33500_s.a = a;
    D_01e33500_s.buf = buf;
    D_01e33500_s.size = size;
    D_01e33500_s.rdata = D_01e33980;
    func_00308a80(buf, size);
    func_00308a80(D_01e33980, 192);
    if (sceSifCallRpc(&D_01e33480, 5, 1, &D_01e33500_s, 48, D_01e34a40, 4, func_002fc038, D_01e33980)) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 5;
    return 0;
}

/* 0x2fc200 sceMcWrite */
struct StRq { int a; int x4; int x8; int rest; int x10; unsigned int n; u8 *ptr; int x1c; u8 data[16]; };
extern struct StRq D_01e33500_q asm("D_01e33500");
int func_002fc200(int a, u8 *buf, int size)
{
    unsigned int i;
    struct StRq *q;
    if (D_01e33480.server == 0) return -100;
    if (func_00305670(D_0036594c) < 0) return -200;
    q = &D_01e33500_q;
    D_01e33500_q.a = a;
    if (size <= 16) {
        q->n = size;
        q->rest = 0;
        q->ptr = 0;
    } else {
        int n = ((unsigned int)(buf - 1) & 0xfffffff0) + 16 - (unsigned int)buf;
        q->n = n;
        q->rest = size - n;
        q->ptr = buf + n;
    }
    for (i = 0; i < D_01e33500_q.n; i++)
        D_01e33500_q.data[i] = buf[i];
    func_003058a0(0);
    if (sceSifCallRpc(&D_01e33480, 6, 1, &D_01e33500_q, 48, D_01e34a40, 4, func_002fbba8, 0) != 0) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 6;
    return 0;
}

/* 0x2fc378 sceMcSync */
int func_002fc378(int mode, int *cmd, int *result)
{
    int busy;
    if (!D_00365948)
        return -1;
    busy = 0;
    if (func_00305670(D_00365950) < 0)
        busy = 1;
    if (mode == 0 && busy) {
        func_00305660(D_00365950);
        busy = 0;
    }
    busy = !busy;
    if (cmd)
        *cmd = D_00365948;
    if (busy) {
        D_00365948 = 0;
        if (result)
            *result = D_01e34a40[0];
        func_00305640(D_0036594c);
    }
    return busy;
}

/* 0x2fc440 (gap) sceMcGetInfo end callback: store type, free and format, then wake sceMcSync */
typedef struct { int type; int free; int pad[34]; int format; } McInfoRd;
extern int *D_01e334a8;
extern int *D_01e334ac;
extern int *D_01e334b0;
void func_002fc440(McInfoRd *p)
{
    p = (McInfoRd *)((unsigned int)p | 0x20000000);
    if (D_01e334a8) *D_01e334a8 = p->type;
    if (D_01e334ac) *D_01e334ac = p->free;
    if (D_01e334b0) *D_01e334b0 = p->format;
    func_00305650(D_00365950);
}

/* 0x2fc498 sceMcGetInfo */
typedef struct { int pad0; int a; int b; int c; int d; int e; int pad18; void *buf; } Rpc_c498;
extern Rpc_c498 D_01e33500_r asm("D_01e33500");
extern int D_01e334a8_i asm("D_01e334a8");
extern int D_01e334ac_i asm("D_01e334ac");
extern int D_01e334b0_i asm("D_01e334b0");
int func_002fc498(int a0, int a1, int a2, int a3, int a4)
{
    if (D_01e33480.server == 0)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    D_01e33500_r.a = a0;
    D_01e33500_r.b = a1;
    D_01e33500_r.buf = D_01e33980;
    if (a2) D_01e33500_r.e = 1; else D_01e33500_r.e = 0;
    if (a3) D_01e33500_r.d = 1; else D_01e33500_r.d = 0;
    if (a4) D_01e33500_r.c = 1; else D_01e33500_r.c = 0;
    D_01e334a8_i = a2;
    D_01e334ac_i = a3;
    D_01e334b0_i = a4;
    func_00308a80(D_01e33980, 192);
    if (sceSifCallRpc(&D_01e33480, 1, 1, &D_01e33500_r, 48, D_01e34a40, 4, func_002fc440, D_01e33980) != 0) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 1;
    return 0;
}

/* 0x2fc618 sceMcUdCheckNewCard */
int sceMcUdCheckNewCard(void)
{
    if (sceSifCallRpc(&D_01e33480, 0x35, 0, D_01e33500, 0x30, D_01e34a40, 4, func_002fbba8, 0) != 0) {
        func_003080d0("sceMcUdCheckNewCard RPC faild\n");
        return -91;
    }
    return D_01e34a40[0];
}

/* 0x2fc688 sceMcGetDir */
typedef struct { int port; int slot; int mode; int maxent; void *table; char name[1024]; } McArg;
extern McArg D_01e33530_m asm("D_01e33530");
extern void func_002fc7d8(char *);
int func_002fc688(int port, int slot, const char *name, int mode, int maxent, void *table)
{
    if (!D_01e33480.server)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    if (name == 0 || *name == 0) {
        func_00305640(D_0036594c);
        return -210;
    }
    D_01e33530_m.port = port;
    D_01e33530_m.slot = slot;
    D_01e33530_m.mode = mode;
    D_01e33530_m.maxent = maxent;
    D_01e33530_m.table = table;
    strncpy(D_01e33530_m.name, name, 1023);
    D_01e33530_m.name[1023] = 0;
    if (maxent >= 0)
        func_00308a80(table, maxent << 6);
    if (sceSifCallRpc(&D_01e33480, 13, 1, &D_01e33530_m, 1044, D_01e34a40, 4, func_002fbba8, 0)) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 13;
    return 0;
}

/* 0x2fc7d8 sceMcChdir end callback: copy the new path to the caller */
void func_002fc7d8(char *buf)
{
    unsigned int n;
    if (buf) {
        if (strlen((char *)((int)D_01e33a40 | 0x20000000)) < 0x400) n = strlen((char *)((int)D_01e33a40 | 0x20000000));
        else n = 0x3ff;
        memcpy(buf, (char *)((int)D_01e33a40 | 0x20000000), n);
        buf[n] = 0;
    }
    func_00305650(D_00365950);
}

/* 0x2fc868 sceMcChdir */
int func_002fc868(int port, int slot, const char *name, void *endp)
{
    if (!D_01e33480.server)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    if (name == 0 || *name == 0) {
        func_00305640(D_0036594c);
        return -210;
    }
    D_01e33530_m.port = port;
    D_01e33530_m.slot = slot;
    D_01e33530_m.table = D_01e33a40;
    strncpy(D_01e33530_m.name, name, 1023);
    D_01e33530_m.name[1023] = 0;
    func_00308a80(D_01e33a40, 1024);
    if (sceSifCallRpc(&D_01e33480, 12, 1, &D_01e33530_m, 1044, D_01e34a40, 4, func_002fc7d8, endp)) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 12;
    return 0;
}

/* 0x2fc9a8 sceMcFormat */
typedef struct { int x0, a, b; int pad[9]; } McArgAB;
extern McArgAB D_01e33500_ab asm("D_01e33500");
int func_002fc9a8(int a, int b)
{
    if (D_01e33480.server == 0)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    D_01e33500_ab.a = a;
    D_01e33500_ab.b = b;
    if (sceSifCallRpc(&D_01e33480, 16, 1, &D_01e33500_ab, 48, D_01e34a40, 4, func_002fbba8, 0) != 0) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 16;
    return 0;
}

/* 0x2fca78 sceMcDelete */
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
    strncpy(D_01e33530.name, name, 1023);
    D_01e33530.port = port;
    D_01e33530.slot = slot;
    D_01e33530.name[1023] = 0;
    D_01e33530.c = 0;
    if (sceSifCallRpc(&D_01e33480, 15, 1, &D_01e33530, 1044, D_01e34a40, 4, func_002fbba8, 0)) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 15;
    return 0;
}

/* 0x2fcb98 sceMcFlush */
int func_002fcb98(int x)
{
    if (!D_01e33480.server)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    D_01e33500[0] = x;
    if (sceSifCallRpc(&D_01e33480, 10, 1, D_01e33500, 48, D_01e34a40, 4, func_002fbba8, 0)) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 10;
    return 0;
}

/* 0x2fcc58 sceMcSetFileInfo */
typedef struct { char b[64]; } McInfo;
extern McInfo D_01e334c0;
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
    strncpy(D_01e33530.name, name, 1023);
    D_01e33530.name[1023] = 0;
    func_003058a0(0);
    if (sceSifCallRpc(&D_01e33480, 14, 1, &D_01e33530, 1044, D_01e34a40, 4, func_002fbba8, 0)) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 14;
    return 0;
}

/* 0x2fce28 sceMcRename */
struct RpcSend2 { int a; int b; int c; int pad; void *ptr; char name[1024]; };
struct Name32 { u8 pad[32]; char name[32]; };
extern struct RpcSend2 D_01e33530_r2 asm("D_01e33530");
extern struct Name32 D_01e334c0_n asm("D_01e334c0");
int func_002fce28(int a, int b, const char *name, const char *name2)
{
    McCd *cd = &D_01e33480;
    struct RpcSend2 *s;
    if (cd->server == 0) return -100;
    if (func_00305670(D_0036594c) < 0) return -200;
    if (name == 0 || *name == 0 || name2 == 0) { func_00305640(D_0036594c); return -210; }
    s = &D_01e33530_r2;
    D_01e33530_r2.a = a;
    s->b = b;
    s->c = 16;
    strncpy(s->name, name, 1023);
    s->name[1023] = 0;
    strncpy(D_01e334c0_n.name, name2, 32);
    s->ptr = &D_01e334c0_n;
    func_003058a0(0);
    if (sceSifCallRpc(cd, 14, 1, s, 1044, D_01e34a40, 4, func_002fbba8, 0) != 0) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 19;
    return 0;
}

/* 0x2fcf80 sceMcUnformat */
int func_002fcf80(int a, int b)
{
    if (D_01e33480.server == 0)
        return -100;
    if (func_00305670(D_0036594c) < 0)
        return -200;
    D_01e33500_ab.a = a;
    D_01e33500_ab.b = b;
    if (sceSifCallRpc(&D_01e33480, 17, 1, &D_01e33500_ab, 48, D_01e34a40, 4, func_002fbba8, 0) != 0) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 17;
    return 0;
}

/* 0x2fd050 sceMcGetEntSpace: rpc 18 (a, b, name) */
struct RpcSend { int a; int b; u8 pad[12]; char name[1024]; };
extern struct RpcSend D_01e33530_e asm("D_01e33530");
int func_002fd050(int a, int b, const char *name)
{
    if (D_01e33480.server == 0) return -100;
    if (func_00305670(D_0036594c) < 0) return -200;
    if (name == 0 || *name == 0) { func_00305640(D_0036594c); return -210; }
    D_01e33530_e.a = a;
    D_01e33530_e.b = b;
    strncpy(D_01e33530_e.name, name, 1023);
    D_01e33530_e.name[1023] = 0;
    if (sceSifCallRpc(&D_01e33480, 18, 1, &D_01e33530_e, 1044, D_01e34a40, 4, func_002fbba8, 0) != 0) {
        func_00305640(D_0036594c);
        return -91;
    }
    D_00365948 = 18;
    return 0;
}
