/* Sony PS2 Runtime Library 3.0.0: libvib (libvib.a), 0x2f6528-0x2f6694. Built with ee-gcc 2.9-991111 -O2 -G0.
 * Third-party code notice: rebuilt to match Sony Computer Entertainment's PS2 SDK library code that
 * the game links. It is not covered by this project's MIT License.
 * Linked unit (linked_units.tsv): the whole object is compiled as one file. It has no strings; its
 * .data (version tag at 0x363d48) is not referenced and stays retail data. */
typedef unsigned char u8;
typedef unsigned long u64;
/* libdbc command word, passed by value in one register */
typedef struct { u64 a:14; u64 b:2; u64 c:8; u64 d:8; u64 e:32; } VibCmd;
typedef struct { int n1; int n2; char buf[40]; } VibPkt;
extern void memcpy(void *, void *, int);
extern int sceDbcReceiveData(int, VibCmd, int *, u8 *);
extern int sceDbcSendData2(int, VibCmd, int *, VibPkt *);

/* 0x2f6528 (gap) sceVibGetProfile: reads the actuator profile of a socket, returns its size */
int func_002f6528(int socket, u8 *profile)
{
    VibCmd cmd;
    int size;
    int r;
    cmd.a = 2;
    cmd.b = 2;
    cmd.c = 3;
    cmd.d = 1;
    r = sceDbcReceiveData(socket, cmd, &size, profile);
    if (r >= 0)
        return size;
    return r;
}

/* 0x2f65a8 sceVibSetActParam */
int func_002f65a8(int a, int n1, void *d1, int n2, void *d2)
{
    VibPkt p;
    VibCmd t;
    int sz;
    sz = 40;
    t.a = 11;
    t.b = 1;
    t.c = 3;
    t.d = 1;
    p.n2 = n2;
    memcpy(p.buf, d2, n2);
    p.n1 = n1;
    memcpy((char *)(n2 + (int)&p) + 8, d1, n1);
    return sceDbcSendData2(a, t, &sz, &p);
}
