/* Sony PS2 Runtime Library 3.0.0: libdbc. Built with ee-gcc 2.9-991111 -O2 -G0. */
extern int D_00363d10;
extern int D_01e2fe40;
extern int func_00305630(int);
int func_002f4d18(void)
{
    if (!D_00363d10)
        return 0;
    D_00363d10 = 0;
    if (D_01e2fe40 >= 0)
        func_00305630(D_01e2fe40);
    return 1;
}

extern int func_003094b8(void *, int, int, void *, int, void *, int, void *, void *);
extern int func_002f5c48(const char *, ...);
extern char D_01e2d980[];
extern int D_01e2da80[];
int func_002f4dc0(int x)
{
    D_01e2da80[1] = x;
    if (func_003094b8(D_01e2d980, 0x80001304, 0, D_01e2da80, 144, D_01e2da80, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcSetWorkAddr: rpc error\n");
        return 0;
    }
    return D_01e2da80[0];
}
