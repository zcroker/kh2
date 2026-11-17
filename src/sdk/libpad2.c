/* Sony PS2 Runtime Library 3.0.2: libpad2 (libpad2.a), 0x2f5c70-0x2f6524. Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv): the whole object is compiled as one file. Its strings are .rodata
 * at 0x376ae8 and its .data (version tag, init flag, state-name table) is at 0x363d18; the socket
 * table 0x1e2fe48 (16 x 820 bytes) stays retail data and is declared extern.
 * The socket table is seen with several struct types; those use asm-label aliases of the same symbol. */
typedef unsigned char u8;

typedef union {
    struct { unsigned long a:14; unsigned long b:2; unsigned long c:8; unsigned long d:8; } s;
    int i;
} PadCmd;

/* one button entry of the profile table (0x14 + 16 * n in a socket entry) */
typedef struct { int on; int kind; int x8; int xc; } Btn;

extern void *memcpy(void *, const void *, int);
/* strcpy is newlib's at 0x2ff2e8; the plain name keeps gcc's builtin strcpy (strcpy(s, "") is inlined). */
extern char *strcpy(char *, const char *);
asm("strcpy = func_002ff2e8");
extern void func_002fde18(void *, int, int);
extern void func_00305f18(void *, void *);
extern int func_003080d0(const char *, ...);
extern int sceDbcCreateSocket(void *, unsigned int, unsigned int);
extern int sceDbcDeleteSocket(int);
extern int sceDbcGetDepNumber(int);
extern int sceDbcReceiveData(int, int, int *, u8 *);

char D_00363d18[16] = "PsIIlibpad2 3020";
int D_00363d28 = 0;
int D_00363d2c = 0;
int D_00363d30 = 0;
int D_00363d34 = 0;

/* 0x2f5c70 scePad2Init */
typedef struct { int a, b, c, d; char pad[804]; } Ent_5c70;
extern Ent_5c70 D_01e2fe48_5c70[16] asm("D_01e2fe48");
int func_002f5c70(void)
{
    int i;
    D_00363d28 = 1;
    for (i = 0; i < 16; i++) {
        D_01e2fe48_5c70[i].a = 0;
        D_01e2fe48_5c70[i].b = 0;
        D_01e2fe48_5c70[i].c = 0;
        D_01e2fe48_5c70[i].d = 0;
    }
    return 1;
}

/* 0x2f5cb0 scePad2End */
extern int D_01e2fe48_5cb0[] asm("D_01e2fe48");
extern int func_002f5e20(int);
int func_002f5cb0(void)
{
    int i, r;
    int *p = D_01e2fe48_5cb0;
    D_00363d28 = 0;
    for (i = 0; i < 16; i++, p += 205) {
        if (*p) {
            r = func_002f5e20(i);
            if (r < 0)
                return r;
        }
    }
    return 1;
}

/* 0x2f5d18 scePad2CreateSocket: checks the 64-byte alignment of the buffer, copies the socket
   parameters (or zeroes them), opens the socket and records the buffer for the port. */
typedef struct { char s[16]; } Name_5d18;
typedef struct { int flag; int a; int b; int c; Name_5d18 n; } P1_5d18;
typedef struct { int flag; int one; int a; int b; int c; Name_5d18 n; } P2_5d18;
typedef struct { int a; int b; int c; int d; void *e; char pad[800]; } Pad_5d18;
extern Pad_5d18 D_01e2fe48_5d18[] asm("D_01e2fe48");
extern void func_002f6240(int);
int func_002f5d18(P1_5d18 *p, unsigned int buf) asm("_Z16ctarget_002f5d18jjjj");
int func_002f5d18(P1_5d18 *p, unsigned int buf)
{
    P2_5d18 q;
    int r;
    if (buf & 0x3f) {
        func_003080d0("libpad2: buffer addr is not 64 byte align. %08x\n", buf);
        return -1;
    }
    if (p) {
        q.flag = p->flag;
        q.a = p->a;
        q.b = p->b;
        q.c = p->c;
        q.n = p->n;
    } else {
        q.flag = 0;
        q.a = 0;
        q.b = 0;
        q.c = 0;
        q.n.s[0] = 0;
    }
    q.one = 1;
    q.flag |= 1;
    r = sceDbcCreateSocket(&q, buf, buf + 0x80);
    if (r < 0) return r;
    D_01e2fe48_5d18[r].a = 1;
    D_01e2fe48_5d18[r].e = (void *)buf;
    func_002f6240(r);
    return r;
}

/* 0x2f5e20 scePad2DeleteSocket */
typedef struct { int a; int b; int c; int d; char pad[804]; } Ent_5e20;
extern Ent_5e20 D_01e2fe48_5e20[] asm("D_01e2fe48");
int func_002f5e20(int port)
{
    int r = sceDbcDeleteSocket(port);
    if (r < 0)
        return r;
    D_01e2fe48_5e20[port].a = 0;
    D_01e2fe48_5e20[port].b = 0;
    D_01e2fe48_5e20[port].d = 0;
    return 1;
}

/* 0x2f5e78 scePad2Read */
typedef struct { int x0; int x4; int pad[3]; char x14[0x334 - 0x14]; } E_5e78;
typedef struct { unsigned char x0, x1, x2, x3; int x4; int pad[5]; unsigned char x1c[1]; } F_5e78;
extern E_5e78 D_01e2fe48_5e78[] asm("D_01e2fe48");
extern int func_002f62b8(int);
extern F_5e78 *func_002f6310_5e78(int) asm("func_002f6310");
extern int func_002f6440_5e78(void *, void *) asm("func_002f6440");
int func_002f5e78(int port, void *buf)
{
    F_5e78 *p;
    int n;
    if (D_01e2fe48_5e78[port].x0 == 0) return -1;
    if (D_01e2fe48_5e78[port].x4 == 0 && func_002f62b8(port) < 0) return -1;
    p = func_002f6310_5e78(port);
    n = p->x2;
    if (n != 0 && p->x1c != 0) {
        memcpy(buf, p->x1c, n);
        func_002f6440_5e78(p->x1c + p->x2, D_01e2fe48_5e78[port].x14);
    }
    if (p->x4 == 0) return -1;
    return p->x2;
}

/* 0x2f5f50 scePad2GetButtonProfile */
typedef struct { u8 b0, b1, off, len; int x4; int pad[5]; u8 data[1]; } Pkt_5f50;
typedef struct { int x0, x4, x8, xc, x10; u8 rest[800]; } Port_5f50;
extern Port_5f50 D_01e2fe48_5f50[] asm("D_01e2fe48");
extern void func_002f6020_5f50(int) asm("func_002f6020");
extern Pkt_5f50 *func_002f6378_5f50(int) asm("func_002f6378");
extern void func_002f6440_5f50(u8 *, void *) asm("func_002f6440");
int func_002f5f50(int port, void *buf)
{
    Pkt_5f50 *p;
    int n;
    func_002f6020_5f50(port);
    if (D_01e2fe48_5f50[port].x4 == 0) {
        if (func_002f62b8(port) < 0)
            return -1;
    }
    p = func_002f6378_5f50(port);
    n = p->len;
    if (n && p->data) {
        memcpy(buf, (u8 *)(p->off + (int)p) + 28, n);
        func_002f6440_5f50(p->data + p->off, &D_01e2fe48_5f50[port].x10 + 1);
    }
    if (p->x4 == 0)
        return -1;
    return p->len;
}

/* 0x2f6020 scePad2GetState */
typedef struct { int x0; int active; char pad[812]; } Ent_6020;
extern Ent_6020 D_01e2fe48_6020[] asm("D_01e2fe48");
extern int func_002f63e0(int);
extern u8 *func_002f6378_6020(int) asm("func_002f6378");
int func_002f6020(int port)
{
    PadCmd cmd;
    unsigned char res;
    int tmp;
    unsigned char *p;

    if (D_01e2fe48_6020[port].active == 0) {
        if (func_002f62b8(port) < 0)
            return 0;
    }
    if (func_002f63e0(port)) {
        p = func_002f6378_6020(port);
        if (((int *)p)[1] == 0) {
            if (func_002f62b8(port) < 0)
                goto fail;
        }
        res = *p;
        goto out;
    } else {
        cmd.s.a = 12;
        cmd.s.b = 2;
        cmd.s.c = 1;
        cmd.s.d = 1;
        if (sceDbcReceiveData(port, cmd.i, &tmp, &res) >= 0)
            goto out;
    }
fail:
    D_01e2fe48_6020[port].active = 0;
    func_002f6240(port);
    return 0;
out:
    return res;
}

/* 0x2f6160 (gap) scePad2GetButtonInfo: one button's state from read data, using the button table */
typedef struct { int x0, x4, x8, xc, x10; Btn btn[40]; char rest[820 - 20 - 640]; } Ent_6160;
extern Ent_6160 D_01e2fe48_6160[] asm("D_01e2fe48");
int func_002f6160(int port, u8 *data, int no)
{
    Btn b = D_01e2fe48_6160[port].btn[no];
    u8 v;
    if (b.on) {
        switch (b.kind) {
        case 1:
            if ((data[b.x8] >> b.xc) & 1)
                return 0;
            return 1;
        case 8:
            v = data[b.x8] >> b.xc;
            if (b.xc) {
                b.x8++;
                v |= data[b.x8] << (8 - b.xc);
            }
            return v;
        default:
            return -1;
        }
    }
    return -1;
}

/* 0x2f6240 clear the two read buffers of a socket */
typedef struct { unsigned char a, b, c, d; int x4; char pad[20]; char buf[96]; int x7c; } Ent_6240;
typedef struct { char pad[16]; Ent_6240 *ent; char pad2[820 - 20]; } Port_6240;
extern Port_6240 D_01e2fe48_6240[] asm("D_01e2fe48");
void func_002f6240(int n)
{
    int i;
    Ent_6240 *e = D_01e2fe48_6240[n].ent;
    for (i = 1; i >= 0; i--) {
        e->a = 0;
        e->x7c = 0;
        e->b = 0;
        e->d = 0;
        e->c = 0;
        e->x4 = 0;
        func_002fde18(e->buf, 0xff, 0x20);
        e++;
    }
}

/* 0x2f62b8 */
typedef struct { int a; int b; int c; int d; char pad[820 - 16]; } Ent_62b8;
extern Ent_62b8 D_01e2fe48_62b8[] asm("D_01e2fe48");
int func_002f62b8(int i)
{
    int r = sceDbcGetDepNumber(i);
    if (r < 0) return r;
    D_01e2fe48_62b8[i].d = r;
    D_01e2fe48_62b8[i].b = 1;
    return r;
}

/* 0x2f6310 / 0x2f6378: the newer of the two read buffers */
typedef struct { char pad[0x7c]; int x7c; } Pad_6310;
typedef struct { char pad0[8]; int f8; int pad1; Pad_6310 *f10; char rest[820 - 20]; } PortT_6310;
extern PortT_6310 D_01e2fe48_6310[] asm("D_01e2fe48");
Pad_6310* func_002f6310(int port)
{
    Pad_6310 *a[2];
    Pad_6310 *p = D_01e2fe48_6310[port].f10;
    a[0] = p;
    a[1] = p + 1;
    func_00305f18(p, (char *)p + 255);
    return a[a[0]->x7c < a[1]->x7c];
}

Pad_6310* func_002f6378(int port)
{
    Pad_6310 *a[2];
    Pad_6310 *p = D_01e2fe48_6310[port].f10;
    a[0] = p;
    a[1] = p + 1;
    func_00305f18(p, (char *)p + 256);
    return a[a[0]->x7c < a[1]->x7c];
}

int func_002f63e0(int port)
{
    int v = func_002f6310(port)->x7c;
    if (v == 0)
        return 0;
    if (v == D_01e2fe48_6310[port].f8)
        return 0;
    D_01e2fe48_6310[port].f8 = v;
    return 1;
}

/* 0x2f6440 build the button table from the profile bit mask */
int func_002f6440(unsigned char *bits, Btn *e)
{
    int i, bit = 0, t1 = 0, a3 = 0;
    for (i = 0; i < 40; i++, e++) {
        if ((*bits >> bit) & 1) {
            e->on = 1;
            e->x8 = t1;
            e->xc = a3;
            if ((i >= 16 && i < 32) || (i >= 35 && i < 39)) {
                e->kind = 8;
                t1++;
            } else {
                a3++;
                e->kind = 1;
                if ((a3 & 7) == 0) {
                    t1++;
                    a3 = 0;
                }
            }
        } else {
            e->on = 0;
            e->x8 = 0;
            e->xc = 0;
        }
        bit++;
        if ((bit & 7) == 0) {
            bits++;
            bit = 0;
        }
    }
    return 1;
}

/* 0x2f64f0 (gap) scePad2StateIntToStr */
char *D_00363d38[4] = { "NOLINK", "STABLE", "EXECCMD", "ERROR" };
void func_002f64f0(unsigned int state, char *str)
{
    if (state < 4)
        strcpy(str, D_00363d38[state]);
    else
        strcpy(str, "");
}
