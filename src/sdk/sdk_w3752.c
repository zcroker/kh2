/* 00306f68: double bits -> int, clamped to [0, 9999], rounded. The empty asm stops combine
   merging the two shifts into one 8-byte truncate, which could not fill the jr delay slot. */
typedef unsigned long u64;

long func_00306f68(u64 a)
{
    long e;
    e = (a << 1) >> 53;
    e -= 1075;
    if (e < -53) return 0;
    if (e >= 13) return 9999;
    a = (a << 12) >> 12;
    a |= (1UL << 52);
    if (e < 0) {
        e = -e;
        a >>= e - 2;
        if ((a & 3) == 3) a = (a >> 2) + 1;
        else a >>= 2;
    } else {
        a <<= e;
    }
    {
        long t = a << 32;
        asm("" : "+r"(t));
        return t >> 32;
    }
}
