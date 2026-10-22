/* libkernl LoadExecPS2/ExecOSD-style argument wrappers (Sony PS2 Runtime Library 3.0.0), built with ee-gcc 2.9 */
extern int D_003674b8;
extern int func_0030f290(const char *name, int argc, char **argv);
extern void func_0030f3a8(void);
extern void func_00305260(int, int, char **);
extern void func_00305a40(int, char **);

void func_0030f420(const char *name, int argc, char **argv)
{
    int r = func_0030f290(name, argc, argv);
    func_0030f3a8();
    func_00305260(r, argc, (char **)(D_003674b8 + 4));
}

void func_0030f490(int argc, char **argv)
{
    func_0030f290("", argc, argv);
    func_0030f3a8();
    func_00305a40(argc, (char **)(D_003674b8 + 4));
}
