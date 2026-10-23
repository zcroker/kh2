/* libcdvd (Sony PS2 Runtime Library 3.0.0): sceCdSearchFile */
typedef struct { unsigned int lsn; unsigned int size; char name[16]; unsigned char date[8]; unsigned int flag; } CdlFILE;
typedef struct { int pad[9]; void *serve; int pad2[6]; } CdClient;
typedef struct { int pad[9]; char name[256]; void *buf; int x128; } SearchArg;
extern void func_003080d0(const char *fmt, ...);
extern void func_002f69c8(void);
extern int func_00305670(int s);
extern int func_00305640(int s);
extern int func_002f71b0(int m);
extern void func_00308b30(int m);
extern int func_00308a80(void *p, int n);
extern int func_003092d8(CdClient *cd, unsigned int rpc, int mode);
extern int func_003094b8(CdClient *cd, int fno, int mode, void *sb, int ss, void *rb, int rs, void *ef, void *ea);
extern int D_00363d90;
extern int D_00363d9c;
extern volatile int D_00363da8;
extern int D_00363dcc;
extern SearchArg D_01e33240;
extern int D_01e33380[4];
extern CdClient D_01e333c0;

int u_call4_002f6ca0(CdlFILE *fp, const char *name, int x) asm("_Z16u_call4_002f6ca0jjjj");
int u_call4_002f6ca0(CdlFILE *fp, const char *name, int x)
{
    int i;
    int j;
    int r;
    func_002f69c8();
    if (D_00363da8 != func_00305670(D_00363da8))
        return 0;
    D_00363d9c = 1;
    if (func_002f71b0(1)) {
        func_00305640(D_00363da8);
        return 0;
    }
    func_00308b30(0);
    if (D_00363dcc < 0) {
        while (1) {
            if (func_003092d8(&D_01e333c0, 0x80000597, 0) < 0) {
                if (D_00363d90 > 0)
                    func_003080d0("Libcdvd bind err CdSearchFile\n");
                j = 0x100000;
                while (j--)
                    ;
                continue;
            }
            if (D_01e333c0.serve != 0) {
                D_00363dcc = 0;
                break;
            }
            j = 0x100000;
            while (j--)
                ;
        }
    }
    for (i = 0; i < 256; i++)
        if ((D_01e33240.name[i] = name[i]) == 0)
            break;
    if (i == 256)
        D_01e33240.name[255] = 0;
    if (D_00363d90 > 0)
        func_003080d0("ee call cmd search %s\n", D_01e33240.name);
    D_01e33240.x128 = x;
    D_01e33240.buf = &D_01e33240;
    func_00308a80(&D_01e33240, 300);
    if (func_003094b8(&D_01e333c0, 0, 0, &D_01e33240, 300, D_01e33380, 4, 0, 0) < 0) {
        func_00305640(D_00363da8);
        return 0;
    }
    __builtin_memcpy(fp, (void *)((unsigned int)&D_01e33240 | 0x20000000), sizeof(CdlFILE));
    if (D_00363d90 > 0)
        func_003080d0("search name %s\n", fp->name);
    if (D_00363d90 > 0)
        func_003080d0("search size %d\n", fp->size);
    if (D_00363d90 > 0)
        func_003080d0("search loc lbn %d\n", fp->lsn);
    r = *(int *)((unsigned int)D_01e33380 | 0x20000000);
    func_00305640(D_00363da8);
    return r;
}
