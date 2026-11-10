// func_00202ce0: particle trail update (sibling of 00201d60 in batch_w3853b_nsa.c). C, -fno-strict-aliasing.
// Partial asm: an empty asm reading i twice after the key-point loop (raises i's allocation priority, i keeps s1),
// and "+r" on c (keeps step = c copy), as in the sibling. Closest pure C: s1/s2 swapped for i and cnt-1.
#include "../common/types.h"
typedef struct { f32 x, y, z, w; } Vq __attribute__((aligned(16)));
typedef struct { u32 cur; u8 cnt; u8 on; u8 pad[2]; Vq (*key)[2]; } TrSt;
typedef struct { u8 pad[8]; s32 n; u8 pad2[8]; s16 (*out)[2][3]; u8 pad3[4]; s32* poly; } TrObj;
typedef struct { u8 pad0; s8 type; s16 count; u8 pad[12]; } PolyHdr;
void sceVu0CopyVector(Vq* d, Vq* s);
void sceVu0SubVector(Vq* d, Vq* a, Vq* b);
void func_002029e8(Vq* in, s32 n, Vq* out);
void func_00202ba0(Vq* o, Vq* a, Vq* b, f32 t);
void sceVu0InterVector(Vq* d, Vq* a, Vq* b, f32 t);
void func_00202c20(u8* prm, s32* x, s32* w, s32* y, s32* h);
void puts(const char*);
extern Vq* D_00354680;
extern s32 D_01d9ea9c;
typedef struct { u8 pad[168]; u64 flags; } PCam;
extern PCam* D_01d9e6e0;
void func_002233f0(const char*, const char*, s32);
extern char D_00370378[];
extern char D_00370390[];
extern char D_00370398[];

void func_00202ce0(TrObj* obj, u8* prm, TrSt* st)
{
    Vq tmp[128];
    Vq coef[128];
    Vq res;
    Vq v[2];
    s32 x, w, y, h;
    s32 cur = st->cur;
    Vq (*key)[2] = st->key;
    s32 n = obj->n;
    u32 cnt = st->cnt;
    s32 dup = 0;
    s16 (*out)[2][3];
    s32 i, k, off;
    Vq* p;
    sceVu0CopyVector(key[cur], D_00354680);
    sceVu0CopyVector(&key[cur][1], D_00354680 + 1);
    out = obj->out;
    for (k = 0, off = 0; k < 2; k++) {
        for (i = 0; i < cnt; ) {
            s32 idx = cur - i;
            if (idx < 0) idx += cnt;
            sceVu0SubVector(&tmp[i++], &(*key)[idx * 2 + k], D_00354680);
        }
        asm("" :: "r"(i), "r"(i));
        func_002029e8(tmp, cnt, coef);
        for (i = 0; i < n + 1; i++) {
            s16* o = (s16*)(off + (u32)out) + i * 6;
            func_00202ba0(&res, tmp, coef, (f32)i / (f32)n * (f32)(cnt - 1));
            o[0] = res.x;
            o[1] = res.y;
            o[2] = res.z;
        }
        off += 6;
    }
    if (st->on) {
        s16 (*o)[2][3] = obj->out;
        for (i = n; i > 0; i--) {
            if (o[i][0][0] != o[i - 1][0][0]) break;
            if (o[i][0][1] != o[i - 1][0][1]) break;
            if (o[i][0][2] != o[i - 1][0][2]) break;
            dup++;
        }
    }
    if (prm[15]) {
        f32 a = 1.0f;
        f32 da = a;
        s16 (*o)[2][3] = obj->out;
        if (n - dup > 0) da = a / (f32)(dup > 0 ? n - dup : n);
        for (i = 0; i < n + 1; i++) {
            for (k = 0; k < 2; k++) {
                v[k].x = o[i][k][0];
                v[k].y = o[i][k][1];
                v[k].z = o[i][k][2];
            }
            sceVu0InterVector(&v[0], &v[0], &v[1], a);
            a -= da;
            o[i][0][0] = v[0].x;
            o[i][0][1] = v[0].y;
            o[i][0][2] = v[0].z;
            if (a <= 0.0f) a = 0.0f;
        }
    }
    if (st->on) {
        f32 a = 128.0f;
        f32 da = 0.0f;
        s32* hd = obj->poly;
        PolyHdr* rec = (PolyHdr*)((u8*)hd + hd[1]);
        s32 m, pos, step, sz, c;
        func_00202c20(prm, &x, &w, &y, &h);
        m = n - dup;
        c = 0;
        if (m <= 0) {
            a = da;
            pos = 0;
            asm("" : "+r"(c));
            step = c;
        } else {
            pos = x;
            step = (w - x) / m;
            da = a / (f32)m;
        }
        while (rec->type != -1) {
            sz = 0;
            switch (rec->type) {
            case 0: case 1: case 2: case 3: case 5: case 7:
                puts(D_00370378);
                func_002233f0(D_00370390, D_00370398, 448);
                return;
            case 4: {
                u8* e = (u8*)(rec + 1);
                for (i = 0; i < rec->count; i++, e += 24, c++) {
                    if (c >= m) {
                        e[3] = e[7] = e[11] = e[15] = 0;
                    } else {
                        s32 ai = (s32)a;
                        e[7] = ai;
                        e[3] = ai;
                        e[11] = e[15] = (f32)(u8)ai - da;
                    }
                    a -= da;
                    pos += step;
                    if (w < pos) pos = w;
                    if (a < 0.0f) a = 0.0f;
                }
                sz = 24;
                break;
            }
            case 6: {
                u8* e = (u8*)(rec + 1);
                for (i = 0; i < rec->count; i++, e += 40, c++) {
                    s32 np;
                    if (c >= m) {
                        e[3] = e[7] = e[11] = e[15] = 0;
                    } else {
                        s32 ai = (s32)a;
                        e[7] = ai;
                        e[3] = ai;
                        e[11] = e[15] = (f32)(u8)ai - da;
                    }
                    np = pos + step;
                    *(s16*)(e + 24) = pos;
                    *(s16*)(e + 28) = pos;
                    a -= da;
                    e[2] = e[6] = e[10] = e[14] = 0xff;
                    e[1] = e[5] = e[9] = e[13] = 0xff;
                    e[0] = e[4] = e[8] = e[12] = 0xff;
                    *(s16*)(e + 36) = np - 1;
                    *(s16*)(e + 32) = np - 1;
                    pos = np;
                    *(s16*)(e + 26) = *(s16*)(e + 34) = h;
                    *(s16*)(e + 30) = *(s16*)(e + 38) = y;
                    if (w < pos) pos = w;
                    if (a < 0.0f) a = 0.0f;
                }
                sz = 40;
                break;
            }
            }
            rec = (PolyHdr*)((u8*)rec + sz * rec->count);
            rec++;
        }
    }
    if (prm[13] == 0) {
        if (D_01d9ea9c == 0 && !(D_01d9e6e0->flags & 0xff0000ff00ULL)) {
            if (++st->cur >= st->cnt) {
                st->on = 0;
                st->cur = 0;
            }
        }
        sceVu0CopyVector((Vq*)D_01d9e6e0, D_00354680);
    }
}
