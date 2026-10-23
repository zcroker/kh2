/* Sony PS2 Runtime Library 3.0.0: libdbc. Built with ee-gcc 2.9-991111 -O2 -G0. */
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
extern int D_00363d10;
extern int D_01e2fe40;
extern int D_01e2fe00[16];
extern char D_01e2fd80[];
extern DbcClient D_01e2d980;
extern DbcClient D_01e2d9d0;
extern DbcClient D_01e2d9f8[2];
extern int func_00308b30(int);
extern int func_003092d8(DbcClient *, unsigned int, int);
extern int func_002f4a20(void);
extern int func_003080d0(const char *, ...);
extern int func_002f5c48(const char *, ...);
extern int func_00305620(struct DbcSema *);
extern int func_002f4dc0(void *);
/* sceDbcInit: bind the dbcman RPC servers, check the module version, create the semaphore. */
int func_002f4a78(void)
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
        if (func_003092d8(&D_01e2d980, 0x80001300, 0) < 0)
            {
                func_002f5c48("libdbc: bind failed\n");
                return 0;
            }
        if (D_01e2d980.serve != 0)
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
        if (func_003092d8(&D_01e2d9d0, 0x8000131c, 0) < 0)
            {
                func_002f5c48("libdbc: bind failed\n");
                return 0;
            }
        if (D_01e2d9d0.serve != 0)
            break;
        i = 0x10000;
        while (i--)
            ;
    }
    for (j = 0; j < 2; j++) {
        while (1) {
            if (func_003092d8(&D_01e2d9f8[j], 0x8000131e + j, 0) < 0)
                {
                func_002f5c48("libdbc: bind failed\n");
                return 0;
            }
            if (D_01e2d9f8[j].serve != 0)
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
        D_01e2fe00[i] = 0;
    func_002f5c48("libdbc: SifDmaAddr %08x\n", D_01e2fd80);
    func_002f4dc0(D_01e2fd80);
    D_00363d10 = 1;
    return 1;
}
