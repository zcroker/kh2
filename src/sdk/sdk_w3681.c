typedef struct { int a; int b; int c; int d; } E;
extern E D_01e38780[32];
extern int D_00366170;
extern int func_00309be8(void);
extern int func_00305660(int);
extern int func_00305640(int);
E* func_00309cd8(void)
{
    E *e, *end;
    func_00309be8();
    func_00305660(D_00366170);
    e = D_01e38780;
    end = e + 32;
    for (; e < end; e++) {
        if (e->b == 0) {
            e->b = 0x10000000;
            func_00305640(D_00366170);
            return e;
        }
    }
    func_00305640(D_00366170);
    return 0;
}
