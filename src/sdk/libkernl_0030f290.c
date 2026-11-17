/* libkernl_0030f290.c: Sony PS2 Runtime Library 3.0.0 libkernl: LoadExecPS2/ExecPS2 argument copy, 0x30f290-0x30f4dc.
 * ee-gcc 2.9-991111 -O2 -G0, linked unit (part of an original object: the syscall stubs and hand-written
 * functions around it stay outside). Third-party code notice: this is a routine from Sony Computer
 * Entertainment's PlayStation 2 Runtime Library that the game links, rebuilt to match. It is not covered by
 * this project's MIT License. */

/* ---- 0x30f290 */
extern int D_003674b8;
extern int D_00366968[2];
extern void func_0030f280(int, int);
extern int func_0030f240(int, void *, int);
extern int strlen(const char *);
int func_0030f290(const char *name, int argc, char **argv)
{
    int area = D_003674b8;
    int p = area + 64;
    int ret = p;
    int len;
    int i;
    func_0030f280(D_00366968[0], D_00366968[1]);
    if (argc >= 16)
        argc = 15;
    func_0030f240(area, &p, 4);
    area += 4;
    len = strlen(name) + 1;
    func_0030f240(p, (void *)name, len);
    p += len;
    for (i = 0; i < argc; i++) {
        func_0030f240(area, &p, 4);
        area += 4;
        len = strlen(argv[i]) + 1;
        func_0030f240(p, argv[i], len);
        p += len;
    }
    return ret;
}

/* ---- 0x30f3a8 */
extern void func_003114f0(void);
void func_0030f3a8(void) { func_003114f0(); }

/* ---- 0x30f3b0 (gap) */
extern int func_00305270(void *, void *, int, char **);
int func_0030f3b0(void *entry, void *gp, int argc, char **argv)
{
    char *s = "";
    func_0030f290(s, argc, argv);
    func_0030f3a8();
    return func_00305270(entry, gp, argc, (char **)(D_003674b8 + 4));
}

/* ---- 0x30f420 */
extern void func_00305260(int, int, char **);
void func_0030f420(const char *name, int argc, char **argv)
{
    int r = func_0030f290(name, argc, argv);
    func_0030f3a8();
    func_00305260(r, argc, (char **)(D_003674b8 + 4));
}

/* ---- 0x30f468 */
extern void func_00305240(int);
void func_0030f468(int a) { func_0030f3a8(); func_00305240(a); }

/* ---- 0x30f490 */
extern void func_00305a40(int, char **);
void func_0030f490(int argc, char **argv)
{
    func_0030f290("", argc, argv);
    func_0030f3a8();
    func_00305a40(argc, (char **)(D_003674b8 + 4));
}
