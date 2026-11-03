/* Sony PS2 Runtime Library 3.0.0: libpad2 create-socket helper (scePad2CreateSocket style).
   Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License. */
typedef struct { char s[16]; } Name;
typedef struct { int flag; int a; int b; int c; Name n; } P1;
typedef struct { int flag; int one; int a; int b; int c; Name n; } P2;
typedef struct { int a; int b; int c; int d; void *e; char pad[800]; } Pad;
extern Pad D_01e2fe48[];
extern int func_002f4e30(P2 *, unsigned int, unsigned int);
extern void func_002f6240(int);
extern void func_003080d0(const char *, ...);

/* Checks the 64-byte alignment of the buffer, copies the socket parameters (or zeroes them),
   opens the socket and records the buffer for the port. */
int ctarget_002f5d18(P1 *p, unsigned int buf) asm("_Z16ctarget_002f5d18jjjj");
int ctarget_002f5d18(P1 *p, unsigned int buf)
{
    P2 q;
    int r;
    if (buf & 0x3f) {
        func_003080d0("libpad2: buffer addr is not 64 byte align. %08x\n", buf);
        return -1;
    }
    if (p) {
        q.flag = p->flag;
        q.a = p->a;
        q.b = p->b;
        q.c = p->c;
        q.n = p->n;
    } else {
        q.flag = 0;
        q.a = 0;
        q.b = 0;
        q.c = 0;
        q.n.s[0] = 0;
    }
    q.one = 1;
    q.flag |= 1;
    r = func_002f4e30(&q, buf, buf + 0x80);
    if (r < 0) return r;
    D_01e2fe48[r].a = 1;
    D_01e2fe48[r].e = (void *)buf;
    func_002f6240(r);
    return r;
}
