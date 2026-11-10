/* libcdvd */
typedef struct { int pad[9]; void *serve; int pad2[6]; } CdClient;
extern int func_003080d0(const char *fmt, ...);
extern int DIntr(void);
extern int EIntr(void);
extern int func_002f69c8(void);
extern int func_00305670(int s);
extern int func_00305640(int s);
extern int func_002f7250(int m);
extern void func_00308b30(int m);
extern int func_00308a80(void *p, int n);
extern int sceSifBindRpc(CdClient *cd, unsigned int rpc, int mode);
extern int sceSifCallRpc(CdClient *cd, int fno, int mode, void *sb, int ss, void *rb, int rs, void *ef, void *ea);
extern int D_00363d90;
extern int D_00363dc0;
extern volatile int D_00363dac;
extern int D_00363dd0;
extern CdClient D_01e33410;
extern int D_01e33450[4];
extern int D_00364f80[4];

int func_002f77b0(int mode)
{
    int i;
    int r;
    if (D_00363d90 > 0)
        func_003080d0("OLD DiskReady Call\n");
    i = DIntr();
    D_00363dc0 = 1;
    if (i)
        EIntr();
    func_002f69c8();
    if (D_00363dac != func_00305670(D_00363dac))
        return 6;
    if (func_002f7250(1)) {
        func_00305640(D_00363dac);
        if (mode == 8)
            return -1;
        return 6;
    }
    func_00308b30(0);
    if (D_00363dd0 < 0) {
        while (1) {
            if (sceSifBindRpc(&D_01e33410, 0x8000059a, 0) < 0) {
                if (D_00363d90 > 0)
                    func_003080d0("Libcdvd bind err CdDiskReady\n");
                i = 0x100000;
                while (i--)
                    ;
                continue;
            }
            if (D_01e33410.serve != 0) {
                D_00363dd0 = 0;
                break;
            }
            i = 0x100000;
            while (i--)
                ;
        }
    }
    D_01e33450[0] = mode;
    func_00308a80(D_01e33450, 4);
    if (sceSifCallRpc(&D_01e33410, 0, 0, D_01e33450, 4, D_00364f80, 4, 0, 0) < 0) {
        func_00305640(D_00363dac);
        if (mode == 8)
            return -1;
        return 6;
    }
    if (D_00363d90 > 0)
        func_003080d0("DiskReady ended\n");
    r = *(int *)((unsigned int)D_00364f80 | 0x20000000);
    func_00305640(D_00363dac);
    return r;
}
