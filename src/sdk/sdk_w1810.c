/* libpad2 (Sony PS2 Runtime Library): built with ee-gcc 2.9-991111 */
typedef unsigned long u64;
typedef struct { u64 a:14; u64 b:2; u64 c:8; u64 d:8; u64 e:32; } PadCmd1810;
typedef struct { int n1; int n2; char buf[40]; } PadPkt1810;
extern void func_002fdd68(void *, void *, int);
extern int func_002f5818(int, PadCmd1810, int *, PadPkt1810 *);

int func_002f65a8(int a, int n1, void *d1, int n2, void *d2)
{
    PadPkt1810 p;
    PadCmd1810 t;
    int sz;
    sz = 40;
    t.a = 11;
    t.b = 1;
    t.c = 3;
    t.d = 1;
    p.n2 = n2;
    func_002fdd68(p.buf, d2, n2);
    p.n1 = n1;
    func_002fdd68((char *)(n2 + (int)&p) + 8, d1, n1);
    return func_002f5818(a, t, &sz, &p);
}
