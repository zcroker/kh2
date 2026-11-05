typedef struct { int x0, x4, x8, xc; } E;
extern E D_01e38780[];
extern int D_00366164;
extern int D_00366170;
extern int func_0030a2d0(int);
extern void func_0030a3f8(void);
extern void func_0030a300(void);
extern E *func_00309cd8(void);
extern int func_0030b9e0(int, int);
extern int func_00305660(int);
extern int func_00305640(int);
int func_0030c158(int a)
{
    int r;
    E *p;
    func_0030a2d0(9);
    if (D_00366164 == 0)
        func_0030a3f8();
    func_0030a300();
    p = func_00309cd8();
    if (p == 0)
        return -19;
    r = func_0030b9e0(a, 9);
    if (r < 0) {
        func_00305660(D_00366170);
        p->x4 = 0;
        func_00305640(D_00366170);
        return r;
    }
    func_00305660(D_00366170);
    p->x0 = r;
    r = p - D_01e38780;
    func_00305640(D_00366170);
    return r;
}
