#include "../common/types.h"
// libgcc unwind-dw2-fde.c (gcc 3.2, SN/EE build): FDE sorting and lookup.
extern "C" {
struct W1657Fde { u32 length; s32 CIE_delta; u32 pc_begin[1]; };
struct W1657FdeVec { void* orig_data; u32 count; W1657Fde* array[1]; };
struct W1657Obj {
    u32 pc_begin; u32 tbase; u32 dbase;
    union { W1657Fde* single; W1657Fde** array; W1657FdeVec* sort; } u;
    union { struct { unsigned long sorted:1; unsigned long from_array:1; unsigned long mixed_encoding:1; unsigned long encoding:8; unsigned long count:21; } b; u32 i; } s;
    W1657Obj* next;
};
struct W1657Accu { W1657FdeVec* linear; W1657FdeVec* erratic; };
typedef int (*W1657FdeCmp)(W1657Obj*, W1657Fde*, W1657Fde*);
u32 func_00100ec8(W1657Obj*, W1657Fde*);  // classify_object_over_fdes
void func_00101050(W1657Obj*, W1657Accu*, W1657Fde*);  // add_fdes
void func_00101b98(W1657Obj*, W1657FdeCmp, W1657FdeVec*, W1657FdeVec*);  // fde_split
int func_00100a78(W1657Obj*, W1657Fde*, W1657Fde*);  // fde_unencoded_compare
int func_00100aa0(W1657Obj*, W1657Fde*, W1657Fde*);  // fde_single_encoding_compare
int func_00100b70(W1657Obj*, W1657Fde*, W1657Fde*);  // fde_mixed_encoding_compare
void* func_002fd3e8(u32);  // malloc
void func_002fd408(void*);  // free
u32 func_00100920(u8, W1657Obj*);  // base_from_object
s32 func_001009a0(u8*);  // get_cie_encoding
u8* func_001004c0(u8, u32, void*, u32*);  // read_encoded_value_with_base
W1657Fde* func_001011e0(W1657Obj*, W1657Fde*, void*);  // linear_search_fdes
void func_00101848(W1657Obj*);  // init_object
__attribute__((noreturn)) void func_002fd160(void);  // abort

#define SWAP(x, y) do { W1657Fde* tmp = x; x = y; y = tmp; } while (0)
// frame_heapsort: heap-sort an FDE vector with the given compare function.
void func_00100c40(W1657Obj* ob, W1657FdeCmp fde_compare, W1657FdeVec* erratic)
{
    W1657Fde** a = erratic->array;
    u32 n = erratic->count;
    u32 m = n;
    u32 i;
    while (m > 0) {
        --m;
        for (i = m; 2 * i + 1 < n;) {
            if (2 * i + 2 < n
                && fde_compare(ob, a[2 * i + 2], a[2 * i + 1]) > 0
                && fde_compare(ob, a[2 * i + 2], a[i]) > 0) {
                SWAP(a[i], a[2 * i + 2]);
                i = 2 * i + 2;
            } else if (fde_compare(ob, a[2 * i + 1], a[i]) > 0) {
                SWAP(a[i], a[2 * i + 1]);
                i = 2 * i + 1;
            } else
                break;
        }
    }
    while (n > 1) {
        --n;
        SWAP(a[0], a[n]);
        for (i = 0; 2 * i + 1 < n;) {
            if (2 * i + 2 < n
                && fde_compare(ob, a[2 * i + 2], a[2 * i + 1]) > 0
                && fde_compare(ob, a[2 * i + 2], a[i]) > 0) {
                SWAP(a[i], a[2 * i + 2]);
                i = 2 * i + 2;
            } else if (fde_compare(ob, a[2 * i + 1], a[i]) > 0) {
                SWAP(a[i], a[2 * i + 1]);
                i = 2 * i + 1;
            } else
                break;
        }
    }
}
#undef SWAP

static inline __attribute__((always_inline)) W1657Fde* binary_search_unencoded_fdes(W1657Obj* ob, void* pc)
{
    W1657FdeVec* vec = ob->u.sort;
    u32 lo, hi;
    for (lo = 0, hi = vec->count; lo < hi;) {
        u32 i = (lo + hi) / 2;
        W1657Fde* f = vec->array[i];
        u32 pc_begin = f->pc_begin[0];
        u32 pc_range = f->pc_begin[1];
        if ((u32)pc < pc_begin) hi = i;
        else if ((u32)pc >= pc_begin + pc_range) lo = i + 1;
        else return f;
    }
    return 0;
}

static inline __attribute__((always_inline)) W1657Fde* binary_search_single_encoding_fdes(W1657Obj* ob, void* pc)
{
    W1657FdeVec* vec = ob->u.sort;
    int encoding = ob->s.b.encoding;
    u32 base = func_00100920(encoding, ob);
    u32 lo, hi;
    for (lo = 0, hi = vec->count; lo < hi;) {
        u32 i = (lo + hi) / 2;
        W1657Fde* f = vec->array[i];
        u32 pc_begin, pc_range;
        u8* p;
        p = func_001004c0(encoding, base, f->pc_begin, &pc_begin);
        func_001004c0(encoding & 0x0F, 0, p, &pc_range);
        if ((u32)pc < pc_begin) hi = i;
        else if ((u32)pc >= pc_begin + pc_range) lo = i + 1;
        else return f;
    }
    return 0;
}

static inline __attribute__((always_inline)) W1657Fde* binary_search_mixed_encoding_fdes(W1657Obj* ob, void* pc)
{
    W1657FdeVec* vec = ob->u.sort;
    u32 lo, hi;
    for (lo = 0, hi = vec->count; lo < hi;) {
        u32 i = (lo + hi) / 2;
        W1657Fde* f = vec->array[i];
        u32 pc_begin, pc_range;
        u8* p;
        int encoding;
        encoding = func_001009a0((u8*)&f->CIE_delta - f->CIE_delta);
        p = func_001004c0(encoding, func_00100920(encoding, ob), f->pc_begin, &pc_begin);
        func_001004c0(encoding & 0x0F, 0, p, &pc_range);
        if ((u32)pc < pc_begin) hi = i;
        else if ((u32)pc >= pc_begin + pc_range) lo = i + 1;
        else return f;
    }
    return 0;
}

// search_object: find the FDE of ob that covers pc (sorting the object first if possible).
W1657Fde* func_00101388(W1657Obj* ob, void* pc)
{
    if (!(int)ob->s.b.sorted) {
        func_00101848(ob);  // init_object
        if ((u32)pc < ob->pc_begin) return 0;
    }
    if ((int)ob->s.b.sorted) {
        if ((int)ob->s.b.mixed_encoding) return binary_search_mixed_encoding_fdes(ob, pc);
        else if ((int)ob->s.b.encoding == 0) return binary_search_unencoded_fdes(ob, pc);
        else return binary_search_single_encoding_fdes(ob, pc);
    } else {
        if ((int)ob->s.b.from_array) {
            W1657Fde** p;
            for (p = ob->u.array; *p; p++) {
                W1657Fde* f = func_001011e0(ob, *p, pc);
                if (f) return f;
            }
            return 0;
        } else
            return func_001011e0(ob, ob->u.single, pc);
    }
}

static inline __attribute__((always_inline)) int start_fde_sort(W1657Accu* accu, u32 count)
{
    u32 size;
    if (!count) return 0;
    size = sizeof(void*) + sizeof(u32) + sizeof(W1657Fde*) * count;
    if ((accu->linear = (W1657FdeVec*)func_002fd3e8(size))) {
        accu->linear->count = 0;
        if ((accu->erratic = (W1657FdeVec*)func_002fd3e8(size))) accu->erratic->count = 0;
        return 1;
    } else
        return 0;
}

static inline __attribute__((always_inline)) void fde_merge(W1657Obj* ob, W1657FdeCmp fde_compare, W1657FdeVec* v1, W1657FdeVec* v2)
{
    u32 i1, i2;
    W1657Fde* fde2;
    i2 = v2->count;
    if (i2 > 0) {
        i1 = v1->count;
        do {
            i2--;
            fde2 = v2->array[i2];
            while (i1 > 0 && fde_compare(ob, v1->array[i1 - 1], fde2) > 0) {
                v1->array[i1 + i2] = v1->array[i1 - 1];
                i1--;
            }
            v1->array[i1 + i2] = fde2;
        } while (i2 > 0);
        v1->count += v2->count;
    }
}

static inline __attribute__((always_inline)) void end_fde_sort(W1657Obj* ob, W1657Accu* accu, u32 count)
{
    W1657FdeCmp fde_compare;
    if (accu->linear && accu->linear->count != count) func_002fd160();  // abort
    if ((int)ob->s.b.mixed_encoding) fde_compare = func_00100b70;
    else if ((int)ob->s.b.encoding == 0) fde_compare = func_00100a78;
    else fde_compare = func_00100aa0;
    if (accu->erratic) {
        func_00101b98(ob, fde_compare, accu->linear, accu->erratic);  // fde_split
        if (accu->linear->count + accu->erratic->count != count) func_002fd160();  // abort
        func_00100c40(ob, fde_compare, accu->erratic);  // frame_heapsort
        fde_merge(ob, fde_compare, accu->linear, accu->erratic);
        func_002fd408(accu->erratic);  // free
    } else {
        func_00100c40(ob, fde_compare, accu->linear);  // frame_heapsort
    }
}

// init_object: count, collect and sort the FDEs of an object.
void func_00101848(W1657Obj* ob)
{
    W1657Accu accu;
    u32 count;
    count = (int)ob->s.b.count;
    if (count == 0) {
        if ((int)ob->s.b.from_array) {
            W1657Fde** p = ob->u.array;
            for (count = 0; *p; ++p) count += func_00100ec8(ob, *p);
        } else
            count = func_00100ec8(ob, ob->u.single);
        ob->s.b.count = count;
        if ((int)ob->s.b.count != count) ob->s.b.count = 0;
    }
    if (!start_fde_sort(&accu, count)) return;
    if ((int)ob->s.b.from_array) {
        W1657Fde** p;
        for (p = ob->u.array; *p; ++p) func_00101050(ob, &accu, *p);  // add_fdes
    } else
        func_00101050(ob, &accu, ob->u.single);  // add_fdes
    end_fde_sort(ob, &accu, count);
    accu.linear->orig_data = ob->u.single;
    ob->u.sort = accu.linear;
    ob->s.b.sorted = 1;
}
}
