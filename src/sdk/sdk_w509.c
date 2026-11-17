/* Sony PS2 Runtime Library 3.0.0: libkernl (EE kernel/SIO/libc helpers). Built with ee-gcc 2.9-991111 -O2 -G0. */
void func_002f35b0(char *p, int n);  // 0x002f35b0: definition moved into src/sdk/libdma.c

extern void func_002f3500(void *, unsigned int, int);
int func_002f3bf0(int *p, unsigned int a, int b, int c);  // 0x002f3bf0: definition moved into src/sdk/libdma.c

extern void func_002f3490(void *, int);
int func_002f3bb8(unsigned int *p, int a);  // 0x002f3bb8: definition moved into src/sdk/libdma.c

extern int func_002fbd38(int, int, int, int);
extern int D_00365948;
int func_002fbe60(int a, int b, int c);  // 0x002fbe60: definition moved into src/sdk/libmc.c

extern int func_00306e48(int);
void func_00306f30(int c)
{
    if (c == '\n') {
        func_00306e48('\r');
        func_00306e48('\n');
    } else
        func_00306e48(c);
}

extern int DisableDmac(int);
extern int func_00305350(int, int);
extern int D_01e357d4;
extern int D_003660d8;
void func_00308650(void)
{
    DisableDmac(5);
    func_00305350(5, D_01e357d4);
    D_003660d8 = 0;
}

extern int D_00366164;
extern char D_01e389a8[];
extern void func_002fde18(void *, int, int);
int func_0030a690(void);  // 0x0030a690: definition moved into src/sdk/filestub.c

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
