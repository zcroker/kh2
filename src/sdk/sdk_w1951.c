/* libdbc (Sony PS2 Runtime Library 3.0.0): built with ee-gcc 2.9-991111 -O2 -G0 */
typedef unsigned long u64;
typedef struct { int a; int b; int n; char buf[180]; } Pkt1951;
extern int D_00363d14;
extern int D_01e2fe40;
extern Pkt1951 D_01e2fc00[];
extern char D_01e2d9f8[][40];
extern int func_002f5c48(const char *, ...);
extern int func_00305660(int);
extern int func_00305640(int);
extern int func_003096b8(void *);
extern int func_003094b8(void *, int, int, void *, int, void *, int, void *, void *);

int func_002f5818(int a, int t, int *sz, char *data)
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
    if (func_003094b8(D_01e2d9f8[D_00363d14], D_00363d14, 1, &D_01e2fc00[D_00363d14], 144, &D_01e2fc00[D_00363d14], 144, 0, 0) < 0) {
        func_002f5c48("sceDbcSendData2: rpc error\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    func_00305640(D_01e2fe40);
    return 1;
}
