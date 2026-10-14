/* Sony PS2 Runtime Library 3.0.0: libpad2. Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { int a; int b; int c; int d; char pad[804]; } Pad;
extern Pad D_01e2fe48[];
extern int func_002f4f60(int);
int func_002f5e20(int port)
{
    int r = func_002f4f60(port);
    if (r < 0)
        return r;
    D_01e2fe48[port].a = 0;
    D_01e2fe48[port].b = 0;
    D_01e2fe48[port].d = 0;
    return 1;
}
