/* libkernl_00310fe0.c: Sony PS2 Runtime Library 3.0.0 libkernl: kernel-call wrappers and TLB exception handlers, 0x310fe0-0x3112fc.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */
extern int func_00305a50(int, void *);

/* ---- 0x310fe0 */
extern int D_01e3b508;
int func_00310fe0(unsigned int a, int b, int c)
{
    int s[4];
    s[0] = a & 0xffff; s[1] = b; s[2] = c;
    s[3] = (int)&D_01e3b508 | 0x20000000;
    return func_00305a50(1, s);
}

/* ---- 0x311028 */
int func_00311028(int a)
{
    int r;
    r = a;
    return func_00305a50(2, &r);
}

/* ---- 0x311050 */
int func_00311050(int a, char b) { int s[2]; s[0] = a; s[1] = b; return func_00305a50(3, s); }

/* ---- 0x311080 */
int func_00311080(int a)
{
    int r;
    r = a;
    return func_00305a50(4, &r);
}

/* ---- 0x3110a8 */
int func_003110a8(unsigned char a, int b, int c) { int s[8]; s[0] = a; s[1] = b; s[2] = c; return func_00305a50(0x20, s); }

/* ---- 0x3110d8 */
int func_003110d8(int a)
{
    int r;
    r = a;
    return func_00305a50(33, &r);
}

/* ---- 0x311100 */
struct A3 { int a; int b; int c; };
int func_00311100(int a, int b, unsigned short c)
{
    struct A3 s;
    s.a = a;
    s.b = b;
    s.c = c;
    return func_00305a50(-5, &s);
}

/* ---- 0x311138 */
int func_00311138(int a, int b, unsigned short c)
{
    struct A3 s;
    s.a = a;
    s.b = b;
    s.c = c;
    return func_00305a50(-6, &s);
}

/* ---- 0x311170 (gap) */
int func_00311170(int a, char b) { int s[2]; s[0] = a; s[1] = b; return func_00305a50(-7, s); }

/* ---- 0x3111a0 */
int func_003111a0(int a)
{
    int r;
    r = a;
    return func_00305a50(-8, &r);
}

/* ---- 0x3111c8 */
int func_003111c8(int a)
{
    int r;
    r = a;
    return func_00305a50(-9, &r);
}

/* ---- 0x3111f0 */
int func_003111f0(int a)
{
    int r;
    r = a;
    return func_00305a50(16, &r);
}

/* ---- 0x311218 */
extern int D_00367470;
extern void func_003052d0(int, void *);
extern void func_003052e0(int, void *);
extern void func_00311740(void);
extern void func_00311980(void);
int func_00311218(int a)
{
    D_00367470 = a;
    func_003052d0(1, func_00311740);
    func_003052d0(2, func_00311740);
    func_003052d0(3, func_00311740);
    return a;
}

/* ---- 0x311278 (gap) */
extern int D_00367478[];
unsigned int func_00311278(int code, int handler)
{
    unsigned int old;
    if ((unsigned int)(code - 1) >= 13)
        return 0xffffffff;
    old = D_00367478[code];
    D_00367478[code] = handler;
    if ((unsigned int)(code - 1) < 3)
        func_003052d0(code, func_00311980);
    else
        func_003052e0(code, func_00311980);
    return old;
}
