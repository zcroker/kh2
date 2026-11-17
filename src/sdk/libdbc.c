/* Sony PS2 Runtime Library 3.0.2: libdbc (libdbc.a), 0x2f4a20-0x2f5c70. Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv): the whole object is compiled as one file. Its strings are .rodata
 * at 0x376840; its globals (0x363d10, 0x1e2d980-0x1e2fe48) stay retail data and are declared extern.
 * Some globals are seen with several struct types; those use asm-label aliases of the same symbol. */
typedef struct {
    int command;
    void *buff;
    void *cbuff;
    void (*func)(void *);
    void *para;
    void *paddr;
    int size;
    int sema;
    int mode;
    void *serve;
} DbcClient;
struct DbcSema {
    int currentCount;
    int maxCount;
    int initCount;
    int numWaitThreads;
    unsigned int attr;
    unsigned int option;
};
struct B64 { unsigned char b[64]; };

extern int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
extern int sceSifBindRpc(DbcClient *, unsigned int, int);
extern int func_002f5c48(const char *, ...);
extern int func_003080d0(const char *, ...);
extern int func_00305620(struct DbcSema *);
extern int func_00305630(int);
extern int func_00305640(int);
extern int func_00305660(int);
extern void func_00305f18(void *, void *);
extern int func_00308b30(int);
extern int func_003096b8(void *);
extern int DIntr(void);
extern int EIntr(void);
extern int sceDbcSetWorkAddr(void *);

extern int D_00363d10;
extern int D_00363d14;
extern int D_01e2fe40;
extern char D_01e2d980[];
extern int D_01e2da80[];

int func_002f4a20(void)
{
    sceSifCallRpc(D_01e2d980, 0x80001363, 0, D_01e2da80, 144, D_01e2da80, 144, 0, 0);
    return D_01e2da80[0];
}

extern DbcClient D_01e2d980_c asm("D_01e2d980");
extern DbcClient D_01e2d9d0_c asm("D_01e2d9d0");
extern DbcClient D_01e2d9f8_c[2] asm("D_01e2d9f8");
extern int D_01e2fe00_i[16] asm("D_01e2fe00");
extern char D_01e2fd80_c[] asm("D_01e2fd80");
/* sceDbcInit: bind the dbcman RPC servers, check the module version, create the semaphore. */
int sceDbcInit(void)
{
    struct DbcSema s;
    int i;
    int v;
    int j;
    if (D_00363d10 == 1)
        return 1;
    D_01e2fe40 = 0;
    func_00308b30(0);
    while (1) {
        if (sceSifBindRpc(&D_01e2d980_c, 0x80001300, 0) < 0)
            {
                func_002f5c48("libdbc: bind failed\n");
                return 0;
            }
        if (D_01e2d980_c.serve != 0)
            break;
        i = 0x10000;
        while (i--)
            ;
    }
    v = func_002f4a20();
    if ((v >> 4) != 0x31) {
        func_003080d0("libdbc: Module version mismatch ");
        func_003080d0("[libdbc.a = %d.%02x, dbcman.irx = %d.%02x]\n", 3, 0x10, v >> 8, v & 0xff);
        return 0;
    }
    while (1) {
        if (sceSifBindRpc(&D_01e2d9d0_c, 0x8000131c, 0) < 0)
            {
                func_002f5c48("libdbc: bind failed\n");
                return 0;
            }
        if (D_01e2d9d0_c.serve != 0)
            break;
        i = 0x10000;
        while (i--)
            ;
    }
    for (j = 0; j < 2; j++) {
        while (1) {
            if (sceSifBindRpc(&D_01e2d9f8_c[j], 0x8000131e + j, 0) < 0)
                {
                func_002f5c48("libdbc: bind failed\n");
                return 0;
            }
            if (D_01e2d9f8_c[j].serve != 0)
                break;
            i = 0x10000;
            while (i--)
                ;
        }
    }
    s.initCount = 1;
    s.maxCount = 127;
    s.option = (unsigned int)"sceDbc_sema";
    D_01e2fe40 = func_00305620(&s);
    if (D_01e2fe40 < 0)
        return 0;
    for (i = 15; i >= 0; i--)
        D_01e2fe00_i[i] = 0;
    func_002f5c48("libdbc: SifDmaAddr %08x\n", D_01e2fd80_c);
    sceDbcSetWorkAddr(D_01e2fd80_c);
    D_00363d10 = 1;
    return 1;
}

int func_002f4d18(void)
{
    if (!D_00363d10)
        return 0;
    D_00363d10 = 0;
    if (D_01e2fe40 >= 0)
        func_00305630(D_01e2fe40);
    return 1;
}

int func_002f4d60(void)
{
    if (sceSifCallRpc(D_01e2d980, 0x80001305, 0, D_01e2da80, 144, D_01e2da80, 144, 0, 0) < 0)
        return 0;
    return D_01e2da80[1];
}

int sceDbcSetWorkAddr(void *x)
{
    D_01e2da80[1] = (int)x;
    if (sceSifCallRpc(D_01e2d980, 0x80001304, 0, D_01e2da80, 144, D_01e2da80, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcSetWorkAddr: rpc error\n");
        return 0;
    }
    return D_01e2da80[0];
}

typedef struct { int type; int unit; int a; int b; int c; char name[16]; } DbcSocketParam;
/* RPC packet: the send and receive buffers are pointers, so their stores do not alias the int
   parameter loads (that keeps the original store order). */
typedef struct {
    int type; int unit; int a; int b; int c; char name[16];
    int result; void *sbuf; void *rbuf; int pad[24];
} DbcSocketRpc;
extern DbcSocketRpc D_01e2da80_s asm("D_01e2da80");

/* sceDbcCreateSocket: copies the socket parameters into the RPC packet and calls the IOP. */
int sceDbcCreateSocket(DbcSocketParam *p, void *sbuf, void *rbuf)
{
    int i;
    int r;
    DbcSocketRpc *s;
    if (!D_00363d10)
        return 0;
    func_00305660(D_01e2fe40);
    D_01e2da80_s.type = p->type;
    s = &D_01e2da80_s;
    s->sbuf = sbuf;
    s->rbuf = rbuf;
    s->unit = p->unit;
    s->a = p->a;
    s->b = p->b;
    s->c = p->c;
    for (i = 0; i < 16; i++)
        s->name[i] = p->name[i];
    if (sceSifCallRpc(D_01e2d980, 0x80001301, 0, &D_01e2da80_s, 144, &D_01e2da80_s, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcCreateSocket: rpc error\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    r = s->result;
    func_00305640(D_01e2fe40);
    return r;
}

int sceDbcDeleteSocket(int x)
{
    int r;
    if (!D_00363d10)
        return 0;
    func_00305660(D_01e2fe40);
    D_01e2da80[0] = x;
    if (sceSifCallRpc(D_01e2d980, 0x80001302, 0, D_01e2da80, 144, D_01e2da80, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcDeleteSocket: rpc error\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    r = D_01e2da80[1];
    func_00305640(D_01e2fe40);
    return r;
}

extern struct B64 D_01e2fd80;
extern struct B64 D_01e2fe00;
int sceDbcGetDepNumber(int port)
{
    int r;
    func_00305f18(&D_01e2fd80, (char *)&D_01e2fd80 + 128);
    DIntr();
    D_01e2fe00 = D_01e2fd80;
    EIntr();
    if (((int *)&D_01e2fe00)[port] != 1)
        return -12;
    func_00305660(D_01e2fe40);
    D_01e2da80[0] = port;
    if (sceSifCallRpc(D_01e2d980, 0x80001303, 0, D_01e2da80, 144, D_01e2da80, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcGetDepNumber: rpc error\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    r = D_01e2da80[1];
    func_00305640(D_01e2fe40);
    return r;
}

int func_002f5190(int port)
{
    func_00305f18(&D_01e2fd80, (char *)&D_01e2fd80 + 128);
    DIntr();
    D_01e2fe00 = D_01e2fd80;
    EIntr();
    return ((int *)&D_01e2fe00)[port] == 1 ? 1 : 3;
}

int sceDbcInitSocket(int x)
{
    int r;
    func_00305660(D_01e2fe40);
    D_01e2da80[0] = x;
    if (sceSifCallRpc(D_01e2d980, 0x80001315, 0, D_01e2da80, 144, D_01e2da80, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcInitSocket: rpc error\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    r = D_01e2da80[1];
    func_00305640(D_01e2fe40);
    return r;
}

int sceDbcResetSocket(int x)
{
    int r;
    func_00305660(D_01e2fe40);
    D_01e2da80[0] = x;
    if (sceSifCallRpc(D_01e2d980, 0x80001316, 0, D_01e2da80, 144, D_01e2da80, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcResetSocket: rpc error\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    r = D_01e2da80[1];
    func_00305640(D_01e2fe40);
    return r;
}

int sceDbcGetDeviceStatus(int x)
{
    int r;
    func_00305660(D_01e2fe40);
    D_01e2da80[0] = x;
    if (sceSifCallRpc(D_01e2d980, 0x80001317, 0, D_01e2da80, 144, D_01e2da80, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcGetDeviceStatus: rpc error\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    r = D_01e2da80[1];
    func_00305640(D_01e2fe40);
    return r;
}

int func_002f5498(int *p)
{
    int r;
    func_00305660(D_01e2fe40);
    D_01e2da80[2] = 2;
    D_01e2da80[4] = p[2];
    D_01e2da80[5] = p[3];
    if (sceSifCallRpc(D_01e2d980, 0x8000131d, 0, D_01e2da80, 144, D_01e2da80, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcGetDeviceStatus: rpc error\n");
        func_00305640(D_01e2fe40);
        return -1;
    }
    r = D_01e2da80[1];
    func_00305640(D_01e2fe40);
    return r;
}

typedef struct { int a; int b; int n1; int n2; char s[128]; char r[128]; int res; } Pk;
extern Pk D_01e2da80_p asm("D_01e2da80");
int sceDbcSRData(int a, int b, int *n1, char *s, int *n2, char *r)
{
    int i;
    int res;
    Pk *p;
    func_00305660(D_01e2fe40);
    p = &D_01e2da80_p;
    p->a = a;
    p->b = b;
    p->n1 = *n1;
    p->n2 = *n2;
    for (i = 0; i < *n1; i++)
        p->s[i] = s[i];
    if (sceSifCallRpc(D_01e2d980, 0x80001318, 0, &D_01e2da80_p, 144, &D_01e2da80_p, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcSRData: rpc error\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    if (p->res >= 0) {
        *n1 = p->n1;
        *n2 = p->n2;
        for (i = 0; i < p->n2; i++)
            r[i] = p->r[i];
    }
    res = p->res;
    func_00305640(D_01e2fe40);
    return res;
}

typedef struct { int a; int b; int size; unsigned char data[128]; int result; } DbcRecv;
extern DbcRecv D_01e2da80_r asm("D_01e2da80");
int sceDbcSendData(int a, int b, int *size, unsigned char *buf)
{
    DbcRecv *s;
    int r;
    int i;
    func_00305660(D_01e2fe40);
    s = &D_01e2da80_r;
    D_01e2da80_r.a = a;
    s->b = b;
    s->size = *size;
    for (i = 0; i < *size; i++)
        s->data[i] = buf[i];
    if (sceSifCallRpc(D_01e2d980, 0x80001319, 0, &D_01e2da80_r, 144, &D_01e2da80_r, 144, 0, 0) < 0) {
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

typedef struct { int a; int b; int n; char buf[180]; } Pkt1951;
extern Pkt1951 D_01e2fc00[];
extern char D_01e2d9f8[][40];
int sceDbcSendData2(int a, int t, int *sz, char *data)
{
    Pkt1951 *p;
    int i;
    if (*sz > 128) {
        func_002f5c48("libdbc: SendData2 data length too long [%d]\n", *sz);
        return 0;
    }
    func_00305660(D_01e2fe40);
    if (++D_00363d14 >= 2)
        D_00363d14 = 0;
    p = &D_01e2fc00[D_00363d14];
    p->a = a;
    p->b = t;
    p->n = *sz;
    for (i = 0; i < *sz; i++)
        p->buf[i] = data[i];
    if (func_003096b8(D_01e2d9f8[D_00363d14]) == 1) {
        func_002f5c48("dbcman : SendData2 BUSY\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    if (sceSifCallRpc(D_01e2d9f8[D_00363d14], D_00363d14, 1, &D_01e2fc00[D_00363d14], 144, &D_01e2fc00[D_00363d14], 144, 0, 0) < 0) {
        func_002f5c48("sceDbcSendData2: rpc error\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    func_00305640(D_01e2fe40);
    return 1;
}

extern char D_01e2d9d0[];
typedef struct { int a; int b; int size; unsigned char data[8324]; } DbcSend3;
extern DbcSend3 D_01e2db40;
int sceDbcSendData3(int a, int b, int *size, unsigned char *buf, void *end)
{
    DbcSend3 *s;
    int i;
    if (*size > 8320) {
        func_002f5c48("libdbc: SendData3 data length too long [%d]\n", *size);
        return 0;
    }
    func_00305660(D_01e2fe40);
    if (func_003096b8(D_01e2d9d0) == 1) {
        func_002f5c48("dbcman : SendData3 BUSY\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    s = &D_01e2db40;
    D_01e2db40.a = a;
    s->b = b;
    s->size = *size;
    for (i = 0; i < *size; i++)
        s->data[i] = buf[i];
    if (sceSifCallRpc(D_01e2d9d0, 0x8000131c, 1, &D_01e2db40, 8336, &D_01e2db40, 8336, end, 0) < 0) {
        func_00305640(D_01e2fe40);
        return 0;
    }
    func_00305640(D_01e2fe40);
    return 1;
}

int sceDbcReceiveData(int a, int b, int *size, unsigned char *buf)
{
    DbcRecv *s;
    int r;
    int i;
    func_00305660(D_01e2fe40);
    s = &D_01e2da80_r;
    D_01e2da80_r.a = a;
    s->b = b;
    s->size = *size;
    if (sceSifCallRpc(D_01e2d980, 0x8000131a, 0, &D_01e2da80_r, 144, &D_01e2da80_r, 144, 0, 0) < 0) {
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

/* The library's debug print: compiled out, so it only takes its arguments. */
int func_002f5c48(const char *fmt, ...)
{
}
