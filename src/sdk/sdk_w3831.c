/* Sony PS2 Runtime Library 3.0.0: libdbc. Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License. */
typedef struct { int type; int unit; int a; int b; int c; char name[16]; } DbcSocketParam;
/* RPC packet: the send and receive buffers are pointers, so their stores do not alias the int
   parameter loads (that keeps the original store order). */
typedef struct {
    int type; int unit; int a; int b; int c; char name[16];
    int result; void *sbuf; void *rbuf; int pad[24];
} DbcSocketRpc;
extern int D_00363d10;
extern int D_01e2fe40;
extern char D_01e2d980[];
extern DbcSocketRpc D_01e2da80;
extern int func_00305660(int);
extern int func_00305640(int);
extern int func_003094b8(void *, int, int, void *, int, void *, int, void *, void *);
extern int func_002f5c48(const char *, ...);

/* sceDbcCreateSocket: copies the socket parameters into the RPC packet and calls the IOP. */
int func_002f4e30(DbcSocketParam *p, void *sbuf, void *rbuf)
{
    int i;
    int r;
    DbcSocketRpc *s;
    if (!D_00363d10)
        return 0;
    func_00305660(D_01e2fe40);
    D_01e2da80.type = p->type;
    s = &D_01e2da80;
    s->sbuf = sbuf;
    s->rbuf = rbuf;
    s->unit = p->unit;
    s->a = p->a;
    s->b = p->b;
    s->c = p->c;
    for (i = 0; i < 16; i++)
        s->name[i] = p->name[i];
    if (func_003094b8(D_01e2d980, 0x80001301, 0, &D_01e2da80, 144, &D_01e2da80, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcCreateSocket: rpc error\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    r = s->result;
    func_00305640(D_01e2fe40);
    return r;
}
