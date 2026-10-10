#include "../common/types.h"

struct QE { u8 pad[1312]; s32 a; s32 b; u8 pad2[8]; };
struct Q { s32 head; s32 tail; u8 pad[8]; QE e[8]; };
struct QG { u8 pad[48]; Q q; };

// singly linked list node / list header (next at +24)
struct Lnk { u32 f0; u32 f4; u32 f8; u32 f12; f32 f16; void* f20; struct Lnk* next; };
struct LList { Lnk* head; Lnk* tail; };

// singly linked list node / list header (next at +20)
struct Lnk2 { u32 f0; u32 f4; u8 pad[12]; struct Lnk2* next; };
struct LList2 { Lnk2* head; Lnk2* tail; };

struct BF { u32 f0; u32 flag : 1; };
struct Tk { u32 f0; s32 id; };
struct E16 { s32 id; u32 flag : 1; u32 pad[2]; };

typedef void (*VFn)(u8*);
typedef void (*VFn3)(u8*, u32, u32);

extern "C" {
u8* func_00132c68(u8*);
s32 func_001325c8(u8*, u32, u32);
void func_001391c8(u32, u32, u32);
void func_00138748(u32);
void func_001387f8(u32, u32, u32, u32);
s32 func_00146c08(u8*, u32);
u32 func_0016cf00(u32, u32, u32, u32*, u32);
void func_00177460(u32, u32);
extern u32 D_0034d8a0;
void func_001dc840(u32);
extern f32 D_00349e10;
f32 func_0016c460(u8*, void*);
void func_0017c4c8(u8*, void*);
void func_0017f488(u8*, u32, f32, f32);
u32 func_001a97b8(u32, s32);
s32 func_0019a9e0(u8*, u8*);
void func_0019ab80(u8*);
void func_001a1db8(u8*);
u32 func_001b1490(u32);
u8* func_00168b38(u32, u32, s32);  // entry_array_find_nth
extern u32 D_00350de8;
extern u32 D_01c94040[];
void func_001b08e8(u8*, u32);
void func_001ad990(u8*, f32, f32, f32);
void* func_00102818(u32, u32, u32, void*, u32);
Tk* func_00102818_t(u32, u32, u32, void*, u32) asm("func_00102818");
extern s32 D_00350f1c;
extern u32 D_0032b91c;
extern Tk* D_01d48c44;
void func_001b1ee8(void);
void* func_001050d8(u32);
extern LList D_01d48c80;
s32 func_001c8ab0(void);
extern u32 D_01d49968;
extern u8 D_0032f055;
extern u32 D_00351214;
void func_001c89a8(void);
void func_001c8a70(void);
void func_001c1748(u8*, u32, void*, void*);  // obj_init_from_src
void func_001dbd38(void);
void func_001dc010(u8*, u8*);
extern LList2 D_01d9e348;
u8* func_00102788(u32, u32, u32, void*);
void func_001de690(void);
void func_001de6d0(void);
void func_001de710(void);
void func_002f4000(f32*);  // vu_store_w_splat
void func_002f3d08(u8*, f32*, u8*);
extern u8* D_01d9e6e0;
extern u8* D_01d9e6e8;
f32 func_00207260(void);
u32 func_001de4b0(u32, u32, u32);
extern u32 D_0035de84;
extern u32 D_0035de88;
void func_001ba028(u8*);  // list_contains_ptr
u8* func_001058e8(void);
s32 func_00139d78(u8*);
void func_00139510(u8*);
extern u8* D_0035edbc;
extern u8* D_0035f20c;
void func_00288f48(u8*, u32, u32, u32, u32);
void func_0028af18(u8*, u32);
void func_0028b1b0(u8*, u32);
extern u32* D_0035f408;
extern s16* D_0035f400;
extern u8* D_0035f3fc;
void func_00138c10(u8*, s32);
extern u8* D_0035f5e4;
extern s32 D_0035f4d0;
extern E16* D_0035f4d4;
s32 func_00287bc0(s32);
s32 func_0028b040(u32);
extern u32 D_0035f200;
extern u8* D_0035f5ec;
u32 func_002a6368(s32);
s32 func_002944d0(u32);
extern u8* D_0035f60c;
void func_00276a18(void);
void func_00276b10(void);
s32 func_00181500(u32);
u32 func_001c3748(u32, u32);
u8 func_001c3888(u32);
void func_00184540(void*, u32, f32, f32);
void func_002cbf08(void*, u32);
extern u8 D_01e2be20[];
void func_00190128(void*);
void func_002e9d08(u8*, void*, void*, void*, u32, u32, u32);
extern void* D_003486b0[];
extern void* D_00347e60[];
extern void* D_00347f98[];
void func_00239870(u8*);
extern void* D_00363860[];
extern void* D_003637e0[];
u8* func_001a93e8(u8*);
void func_00106ac8(u8*);
void func_001a9350(u8*);

void func_00132f38(u8* a0) {
    u8* v = func_00132c68(a0);
    s32 r = func_001325c8(a0, 0, *(u32*)(v + 36));
    if (r >= 0) {
        *(u8**)(a0 + 628) = v + *(s32*)(v + *(s32*)(v + 28) + r * 4);
    }
}

void func_001386e0(u32 a0, u32 a1, u32 a2, u32 a3, u32 t0, u32 t1) {
    func_001391c8(a0, a1, t1);
    func_00138748(a0);
    func_001387f8(a0, a2, a3, t0);
}

// true if any of the a0+624 entries (stride 80) accepts a1
s32 func_00146088(u8* a0, u32 a1) {
    s32 n = *(s32*)(a0 + 1904);
    for (s32 i = 0; i < n; i++) {
        if (func_00146c08(a0 + 624 + i * 80, a1)) return 1;
    }
    return 0;
}

void func_00171fa8(u32* a0) {
    u32 buf[2];
    u32 n = 1;
    u32 s = *(u32*)(a0[0] + 4);
    buf[0] = s;
    if (a0[2]) {
        buf[1] = a0[2];
        n = 2;
    }
    func_00177460(s, func_0016cf00(D_0034d8a0, 0, a0[1], buf, n));
}

// count down a timer; release the handle when it expires (or when forced by flag 0x4000)
void func_00176c68(u8* a0) {
    u32 h = *(u32*)(a0 + 2788);
    if (h) {
        f32 t = *(f32*)(a0 + 2792) - D_00349e10;
        *(f32*)(a0 + 2792) = t;
        if ((*(u32*)(a0 + 352) & 0x4000) || t <= 0.0f) {
            func_001dc840(h);
            *(u32*)(a0 + 2788) = 0;
        }
    }
}

u8* func_0017c030(u8* out, u8* obj, void* a2, u8 flag) {
    u8* src = obj + 16;
    if (out != src) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(out), "r"(src) : "$8", "memory");
    *(f32*)(out + 4) = func_0016c460(obj, a2);
    if (flag) *(u32*)(obj + 264) |= 0x10000;
    return out;
}

void func_0017c0a0(u32 a0, u8* obj, u8 flag) {
    u8 tmp[16] __attribute__((aligned(16)));
    u8 v[16] __attribute__((aligned(16)));
    u32 w;
    func_0017c030(tmp, obj, &w, flag);
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(v), "r"(tmp) : "$8", "memory");
    func_0017c4c8(obj, v);
    func_0017f488(obj + 320, w, 0.0f, 0.0f);
    *(u32*)(obj + 256) = 4;
    *(u32*)(obj + 260) = 5;
}

u32 func_0017edf0(u32* a0, s32 a1) {
    if (a1 < 0 || a0[0] == 0) return 0;
    if (a0[1]) {
        u32 r = func_001a97b8(a0[1], a1);
        if (r) return r;
    }
    return func_001a97b8(a0[0], a1);
}

void func_0019aa00(BF* a0, u8* a1) {
    if ((u8)a0->flag) return;
    if (!(*(u32*)(a1 + 1416) & 0x800)) return;
    if (func_0019a9e0((u8*)a0, a1)) return;
    func_0019ab80((u8*)a0);
}

// add d to the value at +444, clamped to [0, max at +448]; notify when it reaches 0
void func_001a1d50(u8* a0, f32 d) {
    f32 max = *(f32*)(a0 + 448);
    if (0.0f < max) {
        f32 v = *(f32*)(a0 + 444) + d;
        f32 r = v < 0.0f ? 0.0f : (max < v ? max : v);
        *(f32*)(a0 + 444) = r;
        if (r == 0.0f) func_001a1db8(a0);
    }
}

void func_001aeb80(void) {
    u32 v = func_001b1490(D_00350de8);
    for (s32 i = 0; i < 19; i++) {
        D_01c94040[i] = *(u32*)(func_00168b38(v, 2, i) + 8);  // entry_array_find_nth
    }
}

void func_001b0858(u8* a0, f32 f, u32 a1, u32 a2) {
    if (*(s32*)(a0 + 12) >= 0) {
        *(u32*)(a0 + 4) = 3;
        func_001b08e8(a0, a1);
        func_001ad990(a0 + 16, 0.0f, 1.0f, f);
        *(u32*)(a0 + 8) = a2;
    }
}

// start the task for id unless it is invalid or already current
void func_001b1e80(s32 id) {
    if (id == -1 || id == D_00350f1c) return;
    Tk* t = func_00102818_t(D_0032b91c, 0, 0x55730, (void*)func_001b1ee8, 4096);
    D_01d48c44 = t;
    asm volatile("" ::: "memory");
    t->id = id;
}

// init a node and append it to the global list
void func_001b2308(Lnk* a0, u32 n) {
    a0->f4 = 0;
    a0->f0 = n;
    a0->f16 = 50.0f;
    a0->f8 = 0;
    a0->f12 = 0;
    a0->f20 = func_001050d8(n << 4);
    asm volatile("" ::: "memory");
    LList* l = &D_01d48c80;
    if (l->tail == 0) {
        l->tail = a0;
        l->head = a0;
        a0->next = 0;
    } else {
        l->tail->next = a0;
        a0->next = 0;
        l->tail = a0;
    }
}

void ctarget_001c8948(u32, u32, u32, u32) asm("_Z16ctarget_001c8948jjjj");
void ctarget_001c8948(u32, u32, u32, u32) {
    if (func_001c8ab0()) {
        D_01d49968 = 3;
        D_0032f055 = 0;
        u8* t = (u8*)func_00102818(D_00351214, 0, 3, (void*)func_001c89a8, 8192);
        *(void**)(t + 48) = (void*)func_001c8a70;
    }
}

void func_001dbc58(u8* a0, u32 a1, u8* a2, u8* a3) {
    func_001c1748(a0, a1, a2, (void*)func_001dbd38);  // obj_init_from_src
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(a0 + 48), "r"(a2) : "$8", "memory");
    a0[80] = 0;
    *(u8**)(a0 + 92) = a3;
    a0[22] = 0xff;
    a0[81] = 0;
    *(u32*)(a0 + 84) = 0;
    *(u32*)(a0 + 88) = 0;
    a0[20] = *a3;
}

// init a node from a data block and append it to the global list
void wtarget_001dddd0(u32, u32, u32, u32) asm("_Z16wtarget_001dddd0jjjj");
void wtarget_001dddd0(u32 x0, u32 x1, u32, u32) {
    Lnk2* a0 = (Lnk2*)x0;
    u8* a1 = (u8*)x1;
    a0->f0 = (u32)a1;
    a0->f4 = (u32)(a1 + 16);
    func_001dc010((u8*)a0 + 8, (u8*)(*(u32*)(a1 + 12) + (u32)a1));
    LList2* l = &D_01d9e348;
    if (l->tail == 0) {
        l->tail = a0;
        l->head = a0;
        a0->next = 0;
    } else {
        l->tail->next = a0;
        a0->next = 0;
        l->tail = a0;
    }
}

void func_001de8a8(u32 a0, u32 a1, u32 a2, u32 a3) {
    func_00102788(a0, a1, a2, (void*)func_001de690);
    u8* t = func_00102788(a0, a1, a3, (void*)func_001de6d0);
    *(void**)(t + 48) = (void*)func_001de710;
}

// scale matrix (clamped) applied to the global transform
void func_001eb228(u32 a0, f32* a1) {
    f32 m[16] __attribute__((aligned(16)));
    func_002f4000(m);  // vu_store_w_splat
    f32 s = *(f32*)(D_01d9e6e0 + 64);
    f32 v = s + s * a1[1];
    m[0] = v;
    if (a1[2] < v) m[0] = a1[2];
    m[10] = m[0];
    m[5] = m[0];
    u8* p = D_01d9e6e8 + 16;
    func_002f3d08(p, m, p);
}

// random value in about [-n/2, 3n/2)
s8 func_002072a8(u8 n) {
    func_00207260();
    return (s8)(s32)((f32)(n * 2) * func_00207260() - (f32)(n >> 1));
}

// Hand-written VU0 macro code: d = ftoi4/ftoi0 of (a + b) with an overflow-flag fix-up
void func_00222790(void* d, const void* a, const void* b) {  // vec2_add_round_pack
    asm volatile(
        ".set noreorder\n\t"
        "lqc2 $vf1, 0($5)\n\t"
        "lqc2 $vf2, 0($6)\n\t"
        "vadd.xy $vf1, $vf1, $vf2\n\t"
        "vftoi4.xy $vf31, $vf1\n\t"
        "vftoi0.zw $vf31, $vf1\n\t"
        "lui $2, 0x4580\n\t"
        "dsll $2, $2, 16\n\t"
        "ori $2, $2, 0x4580\n\t"
        "dsll $2, $2, 16\n\t"
        "qmtc2 $2, $vf29\n\t"
        "ctc2 $0, $vi16\n\t"
        "vsub.xyw $vf0, $vf1, $vf0\n\t"
        "vsub.xy $vf0, $vf29, $vf1\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "vnop\n\t"
        "cfc2 $2, $vi16\n\t"
        "andi $2, $2, 0xc0\n\t"
        "beqz $2, 1f\n\t"
        "nop\n\t"
        "addiu $2, $0, 0\n\t"
        "ori $2, $0, 0x8000\n\t"
        "ctc2 $2, $vi1\n\t"
        "vmfir.w $vf31, $vi1\n"
        "1:\n\t"
        "sqc2 $vf31, 0($4)\n\t"
        ".set reorder"
        : : "r"(d), "r"(a), "r"(b) : "$2", "memory");
}

s32 func_0022c758(void) {
    u32 v = 0;
    while ((v = func_001de4b0(D_0035de84, 0, v)) != 0) {
        if (D_0035de88 == v) return 1;
    }
    return 0;
}

void func_0022e6b0(s32 which, u8* a1, f32 f) {
    func_001ba028(a1);  // list_contains_ptr
    switch (which) {
    case 0: *(f32*)(a1 + 52) = f; break;
    case 1: *(f32*)(a1 + 56) = f; break;
    case 2: *(f32*)(a1 + 48) = f; break;
    }
}

// set bit (a0 * 8 + a1) in a bit array
void func_00243230(s32 a0, s32 a1) {
    u32 base = (u32)(func_001058e8() + 18904);
    u32 idx = a0 * 8 + a1;
    u32* p = (u32*)((idx >> 5) * 4 + base);
    u32 bit = 1 << (idx & 31);
    u32 v = *p;
    if (!(v & bit)) *p = v | bit;
}

void func_0024c828(void) {
    u32 off = 0;
    for (s32 i = 2; i >= 0; i--) {
        if (func_00139d78(D_0035edbc + off)) {
            u8* o = (u8*)(off + (u32)D_0035edbc);
            (*(VFn*)(*(u8**)o + 20))(o);
        }
        off += 408;
    }
}

void func_00275e08(void) {
    if (func_00139d78(D_0035f20c)) func_00139510(D_0035f20c);
    if (func_00139d78(D_0035f20c + 436)) func_00139510(D_0035f20c + 436);
}

void func_0028b078(u8* a0, s32 a1, s32 a2) {  // obj_setup_from_args
    a0[38] = 0;
    a0[37] = 1;
    *(s16*)(a0 + 24) = a1;
    *(s16*)(a0 + 26) = a2;
    func_00288f48(a0, 16, 32, 64, 128);
    func_0028af18(a0, 127);
    func_0028b1b0(a0, 0);
}

void func_0028ce98(s32 i, u32 v) {  // slot_set_and_refresh
    u32* p = (u32*)(i * 4 + (u32)D_0035f408);
    if (*p == v) return;
    *p = v;
    s32 x;
    if (!v) x = D_0035f400[i * 2];
    else x = D_0035f400[i * 2 + 1];
    func_00138c10(D_0035f3fc + i * 408, x);
}

s32 func_00292a90(s32 id) {
    s32 r = 0;
    for (s32 i = 0; i < D_0035f4d0; i++) {
        E16* e = &D_0035f4d4[i];
        if ((u8)e->flag && e->id == id) { r = 1; break; }
    }
    return r;
}

s32 func_002a4990(s32 a0) {
    if (a0 < 0) a0 = *(s32*)(D_0035f5e4 + 4228) + *(s32*)(D_0035f5e4 + 4232) / 8;
    s32 sum = 0;
    s32 i;
    for (i = 0; i < 15; i++) {
        u8 c = D_0035f5e4[4097 + i * 8];
        if (c) {
            sum += c;
            if (a0 < sum) break;
        }
    }
    return i;
}

s32 func_002a6878(s32 a0) {
    if (a0 < 0) return 1;
    s32 r = func_00287bc0(a0);
    s32 ok;
    switch (r) {
    case 37: ok = func_002944d0(func_002a6368(*(s8*)(D_0035f5ec + func_0028b040(D_0035f200) + 6))) != 0; break;
    case 38: ok = 1; break;
    default: ok = 0; break;
    }
    return ok;
}

void func_002a94f8(void) {
    u32 off = 0;
    for (s32 i = 9; i >= 0; i--) {
        if (func_00139d78(D_0035f60c + off)) {
            u8* o = (u8*)(off + (u32)D_0035f60c);
            (*(VFn*)(*(u8**)o + 20))(o);
        }
        off += 436;
    }
    func_00276a18();
    func_00276b10();
}

// count the nonzero ids (u16 at +4, +8, +12) accepted by func_00181500
s32 func_002c22f0(u8* a0) {
    s32 n = 0;
    u16* p = (u16*)(a0 + 4);
    for (s32 i = 2; i >= 0; i--) {
        u16 h = *p;
        p += 2;
        if (h && func_00181500(h)) n++;
    }
    return n;
}

// the a1-th element of an iteration
u8 func_002c2688(u32 a0, s32 a1) {
    u32 v = 0;
    s32 i = 0;
    while ((v = func_001c3748(a0, v)) != 0) {
        if (i == a1) return func_001c3888(v);
        i++;
    }
    return 0;
}

u8* func_002d6ec8(u8* out, u32 a1, u32 a2) {
    u8 tmp[16] __attribute__((aligned(16)));
    func_00184540(tmp, a2, 0.8f, 0.0f);
    if (out != tmp) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(out), "r"(tmp) : "$8", "memory");
    *(f32*)(out + 8) = 0.0f;
    return out;
}

void func_002e3a78(u8** a0) {
    u8* t = *(u8**)(a0[0] + 4);
    if (t) {
        u32 x = *(u32*)(t + 1288);
        if (x) {
            u8 tmp[16] __attribute__((aligned(16)));
            func_002cbf08(tmp, x);
            if (D_01e2be20 != tmp) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(D_01e2be20), "r"(tmp) : "$8", "memory");
            a0[0] = D_01e2be20;
        }
    }
}

void func_002e7f80(u32* a0) {
    u8 m[32] __attribute__((aligned(16)));
    u8 v1[16] __attribute__((aligned(16)));
    u8 v2[16] __attribute__((aligned(16)));
    func_00190128(m);
    u8* s = (u8*)a0[0];
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(v1), "r"(a0[2]) : "$8", "memory");
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(v2), "r"(a0[1]) : "$8", "memory");
    func_002e9d08(s, m, v2, v1, 1, a0[3] != 0, 0);
    a0[0] = s[5];
}

void u_call4_002eec58(u32, u32, u32, u32) asm("_Z16u_call4_002eec58jjjj");
void u_call4_002eec58(u32 x, u32, u32, u32) {
    u8* a0 = (u8*)x;
    *(void**)a0 = D_00363860;
    u8* o = func_001a93e8(a0 + 44);
    (*(VFn3*)(*(u8**)o + 40))(o, *(u32*)(a0 + 40), *(u32*)(a0 + 68));
    func_00106ac8(a0 + 80);
    func_001a9350(a0 + 44);
    *(void**)a0 = D_003637e0;
}

void func_002f0640(u32 a0, u8* obj, u8 flag) {
    u8 tmp[16] __attribute__((aligned(16)));
    u8 v[16] __attribute__((aligned(16)));
    u32 w;
    func_0017c030(tmp, obj, &w, flag);
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(v), "r"(tmp) : "$8", "memory");
    func_0017c4c8(obj, v);
    obj[1300] = 9;
    func_0017f488(obj + 320, w, 0.0f, 0.0f);
    *(u32*)(obj + 256) = 4;
    *(u32*)(obj + 260) = 5;
}

// destructor chain: three vtables, two embedded members
void func_0031b7e8(u8* a0) {
    *(void**)a0 = D_003486b0;
    *(void**)(a0 + 448) = D_00347e60;
    func_00239870(a0 + 472);
    *(void**)a0 = D_00347e60;
    *(void**)(a0 + 448) = D_00347f98;
    func_00239870(a0 + 24);
    *(void**)a0 = D_00347f98;
}
}
