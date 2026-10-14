/* Sony PS2 Runtime Library 3.0.0: libkernl (EE kernel/SIO/libc helpers). Built with ee-gcc 2.9-991111 -O2 -G0. */
void func_002f35b0(char *p, int n)
{
    while (n--)
        *p++ = 0;
}

extern void func_002f3500(void *, unsigned int, int);
int func_002f3bf0(int *p, unsigned int a, int b, int c)
{
    if (b == 1)
        return (unsigned int)p[4] < a;
    func_002f3500(p, a, c);
    return 0;
}

extern void func_002f3490(void *, int);
int func_002f3bb8(unsigned int *p, int a)
{
    if (a == 1)
        return (*p >> 8) & 1;
    func_002f3490(p, a);
    return 0;
}

extern int func_002fbd38(int, int, int, int);
extern int D_00365948;
int func_002fbe60(int a, int b, int c)
{
    int r = func_002fbd38(a, b, c, 64);
    if (!r)
        D_00365948 = 11;
    return r;
}

extern int func_00306e48(int);
void func_00306f30(int c)
{
    if (c == '\n') {
        func_00306e48('\r');
        func_00306e48('\n');
    } else
        func_00306e48(c);
}

extern int func_003061d0(int);
extern int func_00305350(int, int);
extern int D_01e357d4;
extern int D_003660d8;
void func_00308650(void)
{
    func_003061d0(5);
    func_00305350(5, D_01e357d4);
    D_003660d8 = 0;
}

extern int D_00366164;
extern char D_01e389a8[];
extern void func_002fde18(void *, int, int);
int func_0030a690(void)
{
    D_00366164 = 0;
    func_002fde18(D_01e389a8, 0, 4);
    return 0;
}

extern int *D_00366188;
extern void func_0030ee88(void *, void *, int);
int func_0030ef20(int i)
{
    int v;
    func_0030ee88(&v, D_00366188 + i, 4);
    return v;
}

extern int func_00305a50(int, void *);
struct A3 { int a; int b; int c; };
int func_00311100(int a, int b, unsigned short c)
{
    struct A3 s;
    s.a = a;
    s.b = b;
    s.c = c;
    return func_00305a50(-5, &s);
}
int func_00311138(int a, int b, unsigned short c)
{
    struct A3 s;
    s.a = a;
    s.b = b;
    s.c = c;
    return func_00305a50(-6, &s);
}

extern int func_00307ee8();
extern int func_003071d0(void *, void *, int, int, int);
int func_00307fe0(int a, int b, int c, int d)
{
    int x = a;
    return func_003071d0(func_00307ee8, &x, b, c, d);
}
