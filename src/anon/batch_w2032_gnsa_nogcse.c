#include "../common/types.h"

/* Backwards LZ-style decompressor, in place: the stream ends with a key byte
   (after zero padding) and is read from the end towards buf. */
void func_002efcc0(u8 *buf, int outsize, int insize)
{
    u8 *src = buf + insize;
    u8 *dst;
    u32 key;
    u8 k, c, dist;
    u32 len, i;

    do {
        src--;
        k = *src;
    } while (k == 0);
    key = k;
    src -= 5;
    {
        int o = outsize - 1;
        dst = buf + o;
    }
    while (src >= buf) {
        c = *src--;
        if (c == key && (dist = *src--) != 0) {
            len = *src-- + 3;
            for (i = 0; i < len; i++) {
                *dst = dst[dist];
                dst--;
            }
        } else {
            *dst-- = c;
        }
    }
}
