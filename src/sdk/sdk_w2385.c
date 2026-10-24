/* Sony PS2 Runtime Library: libkernl kernel-mode TLB helper (0x367xxx). ee-gcc 2.9-991111 -O2 -G0. */
typedef struct {
    unsigned int mask;
    unsigned int lo0;
    unsigned int lo1;
} TlbEnt;

extern int func_00075158(unsigned int hi, unsigned int *mask, unsigned int *lo0, unsigned int *lo1);

#define MFC0(r, v) asm volatile(".set noreorder\n\tmfc0 %0,$" #r "\n\t.set reorder" : "=r"(v))
#define MTC0(r, v) asm volatile(".set noreorder\n\tmtc0 %0,$" #r "\n\t.set reorder" : : "r"(v))
#define SYNCP() asm volatile(".set noreorder\n\tsync.p\n\t.set reorder")
#define TLBWI() asm volatile(".set noreorder\n\tsync.p\n\ttlbwi\n\tsync.p\n\t.set reorder")

/* Maps the 4 KB-aligned page pair at addr into a wired TLB entry (EntryHi 0x70004000), reusing the
 * entry func_00075158 finds or taking a new wired slot; addr 0 removes the entry and unwires it. */
int func_003672e8(unsigned int addr)
{
    unsigned int hi;
    unsigned int wired;
    int idx;
    TlbEnt e;

    if ((addr & 0xfff) != 0 || addr - 1 < 0xfffff)
        return -1;
    idx = func_00075158(0x70004000, &e.mask, &e.lo0, &e.lo1);
    if (idx < 0) {
        if (addr == 0)
            return 0;
        MFC0(6, wired);
        idx = wired++;
        MTC0(6, wired);
        SYNCP();
    } else if (addr == 0) {
        hi = ((idx - 1) << 13) + 0xe0010000;
        MFC0(6, wired);
        wired--;
        MTC0(6, wired);
        MTC0(0, idx);
        asm volatile(".set noreorder\n\tmtc0 $0,$5\n\t.set reorder");
        MTC0(10, hi);
        asm volatile(".set noreorder\n\tmtc0 $0,$2\n\tmtc0 $0,$3\n\t.set reorder");
        TLBWI();
        return 0;
    }
    e.mask = 0;
    hi = 0x70004000;
    e.lo0 = ((addr & 0xfffff000) >> 6) | 0x1f;
    e.lo1 = (((addr + 0x1000) & 0xfffff000) >> 6) | 0x1f;
    MTC0(0, idx);
    MTC0(5, e.mask);
    MTC0(10, hi);
    MTC0(2, e.lo0);
    MTC0(3, e.lo1);
    TLBWI();
    return idx;
}
