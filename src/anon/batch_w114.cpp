#include "../common/types.h"

extern "C" {
void func_0014b290(u8*);
}

// ---- 0014c5a0: constructor filling a 17-entry parameter table
struct ParamEnt { u16 type; u8 pad; u8 flag; void* ptr; u32 p8, pc; };
struct ParamObj { void* vt; u8 pad[28]; u8 data[224]; ParamEnt e[17]; };
extern "C" {
extern void* D_00349d78[];
extern u8 D_00349b50[]; extern u8 D_00349b70[]; extern u8 D_00349b90[]; extern u8 D_00349bb0[];
extern u8 D_00349bd0[]; extern u8 D_00349bf0[]; extern u8 D_00349c10[]; extern u8 D_00349c30[];
extern u8 D_00349d50[];
}
static inline void setEnt(ParamEnt* e, u8 f, void* q) { e->flag = f; e->ptr = q; }
extern "C" {
void func_0014c5a0(ParamObj* p);
}
void func_0014c5a0(ParamObj* p) {
    func_0014b290((u8*)p);
    p->vt = D_00349d78;
    setEnt(&p->e[0], 48, D_00349b50); p->e[0].type = 2;
    setEnt(&p->e[1], 48, &p->pad[28]); p->e[1].type = 13;
    setEnt(&p->e[2], 48, D_00349b70); p->e[2].type = 2;
    setEnt(&p->e[3], 48, &p->pad[28]); p->e[3].type = 13;
    setEnt(&p->e[4], 48, D_00349b90); p->e[4].type = 2;
    setEnt(&p->e[5], 48, &p->pad[28]); p->e[5].type = 13;
    setEnt(&p->e[6], 48, D_00349bb0); p->e[6].type = 2;
    setEnt(&p->e[7], 48, &p->pad[28]); p->e[7].type = 13;
    setEnt(&p->e[8], 48, D_00349bd0); p->e[8].type = 2;
    setEnt(&p->e[9], 48, &p->pad[28]); p->e[9].type = 13;
    setEnt(&p->e[10], 48, D_00349bf0); p->e[10].type = 2;
    setEnt(&p->e[11], 48, &p->pad[28]); p->e[11].type = 13;
    setEnt(&p->e[12], 48, D_00349c10); p->e[12].type = 2;
    setEnt(&p->e[13], 48, &p->pad[28]); p->e[13].type = 13;
    setEnt(&p->e[14], 48, D_00349c30); p->e[14].type = 2;
    setEnt(&p->e[15], 48, &p->pad[28]); p->e[15].type = 13;
    setEnt(&p->e[16], 0, D_00349d50); p->e[16].type = 2;
}

// ---- 00150be8
extern "C" {
void func_001396b0(u8*);
void func_0031a260(u8*, s32);
void func_00139660(u8*);
void func_00139688(u8*);
void func_00138c40(u8*, s32, u32);
void func_00138c68(u8*, s32, s32);
s32 func_0023aa98(u8*);
}
static inline void settle(u8* m) {
    func_001396b0(m);
    if (*(u32*)(m + 396)) {
        *(u32*)(m + 400) = 0;
        func_001396b0(m);
        if (*(u32*)(m + 400)) func_0031a260(m, 0);
    }
}
extern "C" {
void func_00150be8(u8* p);
}
void func_00150be8(u8* p) {
    u8* m = p + 496;
    u8* e;
    s32 i, off;
    *(u32*)(p + 6568) = 0;
    *(u32*)(m + 392) = 4;
    *(u32*)(p + 1296) = 10;
    e = m;
    for (i = 9; i >= 0; i--) {
        *(u8**)(e + 396) = m;
        settle(e);
        func_00139660(e);
        func_00139688(e);
        e += 408;
    }
    *(u32*)(m + 396) = 0;
    settle(m);
    func_00138c40(m, *(u32*)(p + 32), *(u32*)(p + 36));
    func_00138c68(p + 1312, 0, 0);
    off = func_0023aa98(p + 1336);
    func_00138c68(p + 1720, off, 0);
    off += func_0023aa98(p + 1744);
    func_00138c68(p + 3760, off, 0);
    off += func_0023aa98(p + 3784);
    func_00138c68(p + 2128, off, 0);
    off += func_0023aa98(p + 2152);
    func_00138c68(p + 2536, off, 0);
    off += func_0023aa98(p + 2560);
    func_00138c68(p + 4168, off, 0);
    off += func_0023aa98(p + 4192);
    func_00138c68(p + 2944, off, 0);
    off += func_0023aa98(p + 2968);
    func_00138c68(p + 3352, off, 0);
    *(s32*)(p + 6564) = -1;
}

// ---- 001379e0
extern "C" {
extern f32 D_00349e14;
void func_001396b0(u8*);
void func_0031a260(u8*, s32);
s32 func_001b1fc8(s32);
u32 func_001b1ff0(s32);
u32 func_001b1e70(void);
void func_00138650(u8*, s32, u32, s32);
void func_001386e0(u8*, s32, u32, u8*, s32, s32);
void func_00236410(u8*, s32);  // obj_set4_then_call
void func_00236428(u8*, s32);  // obj_set32_then_call
void func_002367c8(u8*);  // obj_dispatch_bitfield64
void func_00139598(u8*);
void func_001395a8(u8*);
void func_00138840(u8*);
u8* func_00167f18(s32);
void func_002ba2e8(s32, s32);
void func_00138c10(u8*, u32);
}
// Per-frame update: lazily loads the model on first use, then counts down a timer.
extern "C" {
void func_001379e0(u8* p);
}
void func_001379e0(u8* p) {
    if (*(s32*)(p + 440) != -1) {
        if (*(u32*)(p + 1304) == 0) {
            if (func_001b1fc8(*(s32*)(p + 440)) == 0) {
                func_00139598(p);
                return;
            }
            u8* m = p + 480;
            *(u32*)(p + 1304) = func_001b1ff0(*(s32*)(p + 440));
            u32 t = func_001b1e70();
            func_00138650(p + 448, 11100, *(u32*)(p + 1304), 0);
            u8* q = p + 896;
            func_001386e0(q, 11100, t, m, 2, 0);
            func_00236410(m, 14080);  // obj_set4_then_call
            func_00236428(m, 10752);  // obj_set32_then_call
            func_002367c8(m);  // obj_dispatch_bitfield64
            *(u8**)(q + 396) = p;
            settle(q);
        } else {
            f32 f = *(f32*)(p + 436);
            if (0.0f < f) {
                *(f32*)(p + 436) = f - D_00349e14;
            } else {
                u8* v = func_00167f18(0);
                if (*(s32*)(p + 388) != 78 && (*(u64*)(v + 8) & 0x40c)) {
                    func_002ba2e8(24, 0);
                    func_001395a8(p);
                    func_00138c10(p, 78);
                    func_00138c10(p + 896, 3);
                }
            }
        }
    }
    func_001395a8(p);
    func_00138840(p);
}

// ---- 00276888
extern "C" {
extern u8* D_0035f21c;
s32 func_00139d78(u8*);
s32 func_00276a90(void);
s32 func_00276b90(void);
}
// Returns nonzero while any of the menu models/effects is still busy.
extern "C" {
s32 func_00276888(void);
}
s32 func_00276888(void) {
    s32 r = 0, i;
    if (func_00139d78(D_0035f21c)) r = 1;
    if (r) return r;
    if (func_00139d78(D_0035f21c + 408)) r = 1;
    if (r) return r;
    r = func_00139d78(D_0035f21c + 816) != 0;
    if (r) return r;
    if (func_00139d78(D_0035f21c + 1224)) r = 1;
    if (r) return r;
    r = func_00139d78(D_0035f21c + 1632) != 0;
    if (r) return r;
    if (func_00139d78(D_0035f21c + 2068)) r = 1;
    if (r) return r;
    r = func_00139d78(D_0035f21c + 2504) != 0;
    if (r) return r;
    if (func_00139d78(D_0035f21c + 2940)) r = 1;
    if (r) return r;
    r = func_00139d78(D_0035f21c + 3376) != 0;
    if (r) return r;
    for (i = 0; i < 32; i++) {
        if (func_00139d78(D_0035f21c + i * 408 + 4248) || func_00139d78(D_0035f21c + i * 408 + 17304)) { r = 1; break; }
    }
    if (r) return r;
    r = func_00276a90();
    if (!r) r = func_00276b90();
    return r;
}

// ---- 0027e770
typedef void (*VFn10)(u8*);
extern "C" {
extern u8* D_0035f244;
extern u8* D_0035f248;
s32 func_00139d78(u8*);
void func_00139510(u8*);
}
static inline void vstop(u8* o) { (*(VFn10*)((*(u8**)o) + 20))(o); }
// Stops every active effect/model of the four panel groups.
extern "C" {
void func_0027e770(void);
}
void func_0027e770(void) {
    s32 g, j, off;
    if (func_00139d78(D_0035f244)) vstop(D_0035f244);
    for (g = 0; g < 4; g++) {
        if (func_00139d78(D_0035f248 + g * 5116)) func_00139510(D_0035f248 + g * 5116);
        if (func_00139d78(D_0035f248 + g * 5116 + 436)) func_00139510(D_0035f248 + g * 5116 + 436);
        for (j = 0, off = g * 5116; j < 2; j++, off += 408) {
            if (func_00139d78((u8*)(off + (u32)D_0035f248 + 844))) vstop((u8*)(off + (u32)D_0035f248 + 844));
            if (func_00139d78((u8*)(off + (u32)D_0035f248 + 1660))) vstop((u8*)(off + (u32)D_0035f248 + 1660));
        }
        for (j = 0, off = g * 5116; j < 3; j++, off += 436) {
            if (func_00139d78((u8*)(off + (u32)D_0035f248 + 2476))) vstop((u8*)(off + (u32)D_0035f248 + 2476));
            if (func_00139d78((u8*)(off + (u32)D_0035f248 + 3784))) vstop((u8*)(off + (u32)D_0035f248 + 3784));
        }
    }
}

// ---- 0023d820
struct SubT { u8 pad[12]; u32 items[16]; };
struct Slot11 {
    u8 pad0[48]; u8* handle; u8 pad52[60]; u8* obj; u8 pad116[76]; u32 f192; u8 pad196[12];
    SubT sub; u8 pad284[32]; u8 active; u8 pad317[3];
};
struct Mgr11 {
    void* vt; u8 pad4[1628]; Slot11 slots[4]; u8 pad2912[4]; u8 order[4]; u32 f2920; s32 count;
    u8 pad2928[2368]; u32 a[4]; u32 b[4]; u32 c[4]; u8 pad5344[0]; u8 busy; u8 f5345; u8 f5346;
};
typedef void (*VFn11)(Mgr11*);
typedef void (*VRel11)(u8*, u32, u8*);
extern "C" {
s32 func_00139d78(u8*);
u32 func_00103580(void);
void func_001dc920(u32);
void func_001dde40(u32*);
void func_001a9350(u8*);
void func_00106420(u8*);
void func_0023e738(Mgr11*, s32, s32, s32);  // store_2halfwords_2928
void func_001dda78(s32);
}
// Releases every active slot (handles, items, owned object) and resets the slot order.
extern "C" {
void func_0023d820(Mgr11* p);
}
void func_0023d820(Mgr11* p) {
    s32 any, i, k;
    if (p->busy) return;
    if (func_00139d78((u8*)p)) (*(VFn11*)((*(u8**)p) + 20))(p);
    any = 0;
    for (i = 0; i < p->count; i++) {
        if (!p->slots) break;
        Slot11* s = &p->slots[p->order[i]];
        if (s->active) {
            if (s->handle) {
                u8* h = *(u8**)(s->handle + 20);
                (*(VRel11*)((*(u8**)h) + 40))(h, func_00103580(), s->handle);
                s->handle = 0;
            }
            SubT* sb = &s->sub;
            for (k = 0; k < 16; k++) {
                if (sb->items[k]) {
                    func_001dc920(sb->items[k]);
                    sb->items[k] = 0;
                }
            }
            u32* q = &s->f192;
            if (*q) func_001dde40(q);
            u8* o = s->obj;
            if (o) {
                func_001a9350(o);
                func_00106420(o);
                s->obj = 0;
            }
            s->active = 0;
            any = 1;
        }
        func_0023e738(p, i, 0, 0);  // store_2halfwords_2928
    }
    if (any) {
        func_001dda78(0);
        func_001dda78(0);
    }
    for (i = 0; i < p->count; i++) {
        p->order[i] = i;
        p->a[i] = 0;
        p->b[i] = 0;
        p->c[i] = 0;
    }
    p->f5345 = 0;
    p->f5346 = 0;
    p->f2920 = 0;
}

// ---- 00298c60
struct List12 { s32 count; s16 items[1]; };
extern "C" {
extern s8 D_0035f5a0;
extern List12* D_0035f598;
u32 func_002983d8(s32);
s32 func_00294348(u32);
void func_00299290(void);
}
static inline s32 usable12(s32 i) { return func_00294348(func_002983d8(D_0035f598->items[i])); }
// Moves the list cursor to the next/previous usable entry (dir -10 = forward), wrapping around.
extern "C" {
void func_00298c60(s32 dir);
}
void func_00298c60(s32 dir) {
    s32 cur = D_0035f5a0;
    s32 i;
    if (dir == -10) {
        for (i = cur + 1; i < D_0035f598->count; i++) {
            if (usable12(i)) break;
        }
        if (i >= 8) {
            for (i = 0; i < cur; i++) {
                if (usable12(i)) break;
            }
        }
        cur = i;
        if (i >= D_0035f598->count) cur = 0;
    } else {
        for (i = cur - 1; i >= 0; i--) {
            if (usable12(i)) break;
        }
        if (i < 0) {
            for (i = D_0035f598->count - 1; cur < i; i--) {
                if (usable12(i)) break;
            }
        }
        cur = i >= 0 ? i : D_0035f598->count - 1;
    }
    D_0035f5a0 = cur;
    func_00299290();
}

// ---- 00273368
extern "C" {
extern s32 D_0035f3d4;
extern u32 D_0035ef68;
extern u32 D_0035ef64;
extern u32 D_0035f03c;
extern u32 D_0035f01c;
extern s16 D_00373a60[];
u8* func_00257770(void);
s32 func_00139d78(u8*);
s32 func_00287bc0(void);
s32 func_0028d008(u8*);
void func_00139510(u8*);
void func_00256c40(void);
u32 func_002570a0(s32);
s32 func_00272b60(u32);
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32);
void func_0028dcc0(u8*, u8*);
u8* func_0028d0e0(u8*);
void func_00138c78(u32, s32*, s32*);
void func_00138c68(u8*, s32, s32);
u32 func_0028b040(u32);
void func_00256bb0(u8*);
}
// Updates the target-cursor effect for the given actor and starts/stops the prompt.
extern "C" {
void func_00273368(u8* p, u8 flag);
}
void func_00273368(u8* p, u8 flag) {
    u8* m = func_00257770();
    u8* e = m + 816;
    s32 busy = func_00139d78(e);
    s32 mode = func_00287bc0();
    s32 x, y;
    if (func_0028d008(p)) {
        if (!busy) {
            s32 id = D_0035f3d4 + 2;
            s32 c = 249;
            if ((u32)(mode - 26) >= 2) c = D_00373a60[func_00272b60(func_002570a0(26)) + 5];
            func_0028d8c0(e, id, D_0035ef68, D_0035ef64, D_0035f03c, c, -1, 0);
            func_0028dcc0(e, m);
            func_00138c78(*(u32*)(func_0028d0e0(p) + 396), &x, &y);
            func_00138c68(e, x, y);
        }
        if (flag) {
            func_00138c78(*(u32*)(func_0028d0e0(p) + 396), &x, &y);
            func_00138c68(e, x, y);
        }
        if (func_00139d78(m + 2504) && !flag) return;
        if ((u32)(mode - 26) < 2 && func_00272b60(func_0028b040(D_0035f01c))) {
            func_00256bb0(func_0028d0e0(p));
            return;
        }
    } else if (busy) {
        func_00139510(e);
    }
    func_00256c40();
}
