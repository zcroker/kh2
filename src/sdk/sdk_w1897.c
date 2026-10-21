/* Sony PS2 Runtime Library 3.0.0: libkernl (deci2 kputs). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { volatile int id; volatile int size; int x8; volatile int busy; char *buf; } Kp;
extern Kp D_01e353d0;
extern char D_01e35400[];
extern int func_0030edb0(void);
extern void func_0030ee00(void);
extern int func_00311050(int, char);
extern void func_00311080(int);
int func_00306b40(const char *src, int n)
{
    int cnt = 0;
    int i = 0;
    int s;
    char *buf;
    char *d;
    if (D_01e353d0.busy != 0)
        return -1;
    s = func_0030edb0();
    D_01e353d0.busy = 1;
    buf = (char *)((unsigned int)D_01e35400 | 0x20000000);
    D_01e353d0.buf = buf;
    d = buf + 12;
    while (--n != -1) {
        if (*src == '\n') {
            *d++ = '\r';
            i++;
            if (i >= 256)
                break;
        }
        *d++ = *src++;
        i++;
        cnt++;
        if (i >= 256)
            break;
    }
    D_01e353d0.size = i + 12;
    *(short *)buf = D_01e353d0.size;
    if (func_00311050(D_01e353d0.id, buf[7]) < 0) {
        D_01e353d0.busy = 0;
        if (s)
            func_0030ee00();
        return -1;
    }
    while (D_01e353d0.busy)
        func_00311080(D_01e353d0.id);
    if (s)
        func_0030ee00();
    return cnt;
}
