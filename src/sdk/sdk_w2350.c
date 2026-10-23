/* Sony PS2 Runtime Library 3.0.0: libcdvd sceCdDiskReady (new RPC version; falls back to the old one). Built with ee-gcc 2.9-991111 -O2 -G0. */
typedef struct { int pad[9]; void *serve; int pad2[6]; } CdClient;
extern int func_003080d0(const char *fmt, ...);
extern int func_0030edb0(void);
extern int func_0030ee00(void);
extern int func_002f69c8(void);
extern int func_00305670(int s);
extern int func_00305640(int s);
extern int func_002f77b0(int m);
extern void func_00308b30(int m);
extern void func_00308a80(void *p, int n);
extern int func_003092d8(CdClient *cd, unsigned int rpc, int mode);
extern int func_003094b8(CdClient *cd, int fno, int mode, void *sb, int ss, void *rb, int rs, void *ef, void *ea);
extern int D_00363d90;
extern int D_00363dc0;
extern volatile int D_00363db0;
extern int D_00363dd0;
extern CdClient D_01e33410;
extern int D_01e33450[4];
extern int D_00365800[4];

int ctarget_002f79c8(int mode) asm("_Z16ctarget_002f79c8jjjj");
int ctarget_002f79c8(int mode)
{
    int i, cnt;
    int r;
    if (D_00363d90 > 0)
        func_003080d0("NEW DiskReady Call\n");
    func_002f69c8();
    if (D_00363db0 != func_00305670(D_00363db0)) {
        if (mode == 8)
            return -1;
        return 6;
    }
    func_00308b30(0);
    cnt = 0;
    if (D_00363dd0 < 0) {
        while (1) {
            if (func_003092d8(&D_01e33410, 0x8000059c, 0) < 0) {
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
            if (cnt >= 17) {
                func_00305640(D_00363db0);
                return func_002f77b0(mode);
            }
            i = 0x100000;
            while (i--)
                ;
            cnt++;
        }
    }
    i = func_0030edb0();
    D_00363dc0 = 0;
    if (i)
        func_0030ee00();
    D_01e33450[0] = mode;
    func_00308a80(D_01e33450, 4);
    if (func_003094b8(&D_01e33410, 0, 0, D_01e33450, 4, D_00365800, 4, 0, 0) < 0) {
        func_00305640(D_00363db0);
        if (mode == 8)
            return -1;
        return 6;
    }
    if (D_00363d90 > 0)
        func_003080d0("DiskReady ended\n");
    r = *(int *)((unsigned int)D_00365800 | 0x20000000);
    func_00305640(D_00363db0);
    return r;
}
