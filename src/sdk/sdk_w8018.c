/* libdbc (Sony PS2 Runtime Library) */
struct B64 { unsigned char b[64]; };
extern void func_00305f18(void *, void *);
extern int func_0030edb0(void);
extern int func_0030ee00(void);
extern struct B64 D_01e2fd80;
extern struct B64 D_01e2fe00;
extern int func_003094b8(void *, int, int, void *, int, void *, int, void *, void *);
extern int func_002f5c48(const char *, ...);
extern int func_00305660(int);
extern int func_00305640(int);
extern int D_01e2fe40;
extern char D_01e2d980[];
extern int D_01e2da80[];
int func_002f5020(int port)
{
    int r;
    func_00305f18(&D_01e2fd80, (char *)&D_01e2fd80 + 128);
    func_0030edb0();
    D_01e2fe00 = D_01e2fd80;
    func_0030ee00();
    if (((int *)&D_01e2fe00)[port] != 1)
        return -12;
    func_00305660(D_01e2fe40);
    D_01e2da80[0] = port;
    if (func_003094b8(D_01e2d980, 0x80001303, 0, D_01e2da80, 144, D_01e2da80, 144, 0, 0) < 0) {
        func_002f5c48("sceDbcGetDepNumber: rpc error\n");
        func_00305640(D_01e2fe40);
        return 0;
    }
    r = D_01e2da80[1];
    func_00305640(D_01e2fe40);
    return r;
}
