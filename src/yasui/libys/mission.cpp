#include "../../common/types.h"

// YS::MISSION accessors (0x1bb270-0x1bc188): queries and signals on the current mission.
// The rest of the file (the MISSION constructors, its exec/parse code before 0x1bb270, and the
// static initialiser of the mission object) is not linked yet.

struct C1bb2c8 { u16 type; u16 pad; union { f32 f; s32 i; } a; s32 b; s32 c; u16 n; };
struct Info1bb { u8 pad0[4]; u16 flags; u8 pad6[7]; u8 snd; u8 pad14[6]; u32 f20; };
struct Obj1bb { u8 pad0[8]; Info1bb* info; u8 pad12[92]; u32 f104; u32 f108; u8 pad112[616]; u32 f728; u32 f732; u32 f736; u8 pad740[12]; u32 f752; };
struct Flags16 { u16 lo:9; u16 bit9:1; u16 hi:6; };
struct Flags1bc { u16 a : 14; u16 b : 1; u16 c : 1; };

extern "C" {
extern u8* D_01d49320;     // the current mission
struct S1bb { u32 f0; u32 flags; };
union U1bb { S1bb* p; u32 w; };
extern U1bb D_01d49320_u asm("D_01d49320");
extern u32 D_01d49320_w asm("D_01d49320");
extern u8** D_01d49320_pp asm("D_01d49320");
extern u8* D_01d49324;
extern u8 D_01d48de8[];    // the mission object
extern u8* D_0034e948;
extern u32 D_0034f240;
extern u8 D_00351ec8;
u32 func_001baa58(u8*, s32, const char*);
void func_001bae38(u8*);
void func_001bb020(u8*);
void func_001d5470_x8493(u8*, s32, C1bb2c8*) asm("func_001d5470");
void func_001d8248(u8*, C1bb2c8*);
void func_001d8550(u8*, C1bb2c8*);
void func_001d8b68(u8*, C1bb2c8*);
void func_001d9028(u8*, C1bb2c8*);
void func_001d93f0(u8*, C1bb2c8*);
void func_001d5370_x8499(u8*, s32, s32) asm("func_001d5370");
void func_001d4dc0(u8*, s32, s32, s32);
void func_0019ba60_x8501(u8*) asm("func_0019ba60");
void func_001a1aa0(u8*, s32);
void func_001c0890(u8);
s32 func_001d83c0(s32);
void func_001d4fd0(u32*);
void func_001d4ff0(u32*);
void func_001bbe18(void*);
void func_001bb890(void);
u32 func_00198d00(s32, s32);
void func_001d5518(void*, void*, u32);
void func_001bc0d0(void*);
void func_001bb630(u32, u32);
u8 func_001bba30_u8(void*) asm("func_001bba30");
void func_001bb4f0(Obj1bb*, u32, u32);
s32 func_001bbb50(void);
u32 func_001c10f8(s32);
void func_00253410(u32, s32);
s32 func_001991a8(u32, u32);
void func_001bbc30(void);
u32 func_001bc090(u32);
u32 func_00198bd0(s32, u32);
s32 func_00181500(u32);
s32 func_001bb7f8(void);
void func_0014ca20(void);
void func_001d6c58(void);
void func_001c11a8(s32);
void func_001c1130(s32);
void func_001af9f8(void);
void func_001919a8(void);
void func_001d6c88(void);
void func_001bbac0(void);
void func_002bc798(void);
void func_001c8d98(u8*, s32);
s32 w1758_ys_mission_isexec(void) asm("func_001bb4a0");
u32 w1758_tail4_192048(s32) asm("_Z16u_tail4_00192048jjjj");
void func_0014f578(u32);
void func_001d5370(u32*, u32, s32);
void func_002534e0(u32, u32);
s32 func_001d5460(u32);
void func_001d7940(void);
void func_001ada38(s32);
void func_00199098(u8*, s32);
void func_0019f070(u8*, u32);
void func_001af360(s32);
void func_001af2e8(void);
void func_001d4e50(u8*, u32);
void func_001d4ef0(u8*, u32);
void func_001d4fa8(u8*, u32);
void func_002bc1e8(void);
u32 func_001bb4a0(void);
u8* func_001bbcb0(void);
void func_001bb468(void);

void func_001bb270(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    D_01d49320 = 0;
    D_01d49324 = 0;
}

u32 func_001bb288(s32 id, const char* name) {
    u32 r = func_001baa58(D_01d48de8, id, name);
    D_01d49320 = D_01d48de8;
    return r;
}

s32 func_001bb2c8(C1bb2c8* c, u8* x) {
    switch (c->type) {
    case 1:
        func_001d5470_x8493(x + 76, *(s32*)(x + 72), c);
        break;
    case 2:
        func_001d5470_x8493(x + 104, *(s32*)(x + 72), c);
        break;
    case 3:
        func_001d5470_x8493(x + 160, *(s32*)(x + 72), c);
        break;
    case 4:
        func_001d8248(x, c);
        break;
    case 5:
        func_001d8550(x, c);
        break;
    case 6:
        func_001d8b68(x, c);
        break;
    case 7:
        func_001d9028(x, c);
        break;
    case 8: {
        u8* q = x + 740;
        func_001d5370_x8499(x + 744, *(s32*)(x + 72), c->n - 1);
        func_001d4dc0(q, c->a.i, c->b, c->c);
        break;
    }
    case 9:
        func_001d93f0(x, c);
        break;
    case 10:
        *(s32*)(x + 1324) = c->a.i;
        break;
    case 11:
        *(f32*)(x + 1328) = c->a.f;
        break;
    case 12: {
        u8* o = D_0034e948;
        func_0019ba60_x8501(o);
        if ((*(u8**)(o + 1164))[431] == 1) func_001a1aa0(*(u8**)(o + 1164), c->a.i);
        break;
    }
    case 13:
        func_001d5470_x8493(x + 132, *(s32*)(x + 72), c);
        break;
    }
    return 1;
}

void func_001bb438(void) {
    u8* p = D_01d49320;
    if (p) func_001bae38(p);
}

void func_001bb468(void) {
    u8* p = D_01d49320;
    if (p) {
        func_001bb020(p);
        D_01d49320 = 0;
    }
}

u32 func_001bb4a0(void) {
    return D_01d49320 != 0;
}

u32 func_001bb4b0(void) {
    u32 r = 0;
    if (func_001bb4a0()) { u32 m = *(u32*)(D_01d49320 + 4) & 4; r = m == 0; }
    return r;
}

void func_001bb4f0(Obj1bb* o, u32 id, u32 arg) {
    u8 snd = o->info->snd;
    if (snd) func_001c0890(snd);
    u32* q = (u32*)((u8*)o + 740);
    if (o->f752 & 4) {
        if (func_001d83c0(0) > 0) func_001d4fd0(q);
        func_001d4ff0(q);
    }
    func_001bbe18(o->info->f20);
    func_001bb890();
    u32* m = &o->f104;
    if (m[1]) {
        u32 v = func_00198d00(id, -1);
        if (id == 16 || id == 156 || (v && !(o->info->flags & 0x40))) {
            func_001d5518(m, (u8*)o + 12, 0);
            o->f728 = 2;
        } else {
            func_001d5518(m, (u8*)o + 12, v);
            func_001bc0d0(o);
        }
        o->f732 = id;
        o->f736 = arg;
    } else {
        func_001bb630(id, arg);
    }
}

void func_001bb630(u32 a0, u32 a1) {
    u32 s0 = a0;
    u32 s1 = a1;
    if (func_001bbb50() == 0) {  // type_is_2_or_25
        if (s0 != 156) {
            goto L001bb684;
        }
    }
L001bb660:
    {
        u32 v0 = func_001c10f8(26);  // request_pool_block64
        return func_00253410(v0, 0);
    }

L001bb684:
    if (func_001991a8(s0, s1) != 0) {
        return func_001bb468();
    }
    if (s0 == 8) {
        return func_001bbc30();
    }
    (void)s1;
}

void func_001bb6d0(u32 a0) {
    u32 s0 = a0;
    u32 a1_live = s0;
    u32 v0 = func_001bc090(a0);
    if (v0 != 0) {
        v0 = func_00198bd0(7, a1_live);
        if (v0 != 0) {
            u32 t6 = *(u32*)(v0 + 8);
            if (t6 != 0xffff) {
                if (func_00181500(t6) != 0) {
                    return func_001bb4f0((Obj1bb*)D_01d49320, 156, s0);
                }
            }
        }
    }

    return func_001bb4f0((Obj1bb*)D_01d49320, 7, s0);
}

void func_001bb740(s32 a) {
    func_001bb4f0((Obj1bb*)D_01d49320, 16, a);
}

void func_001bb768(void) {
    func_001bbe18(*(u32*)(*(u8**)(((u8*)D_01d49320_w) + 8) + 24));
    *(u32*)(((u8*)D_01d49320_w) + 180) = 2;
    func_001d5518(((u8*)D_01d49320_w) + 160, ((u8*)D_01d49320_w) + 12, 0);
    func_001bb890();
    if (func_001bb7f8()) {
        *(u32*)(((u8*)D_01d49320_w) + 732) = 8;
        *(s32*)(((u8*)D_01d49320_w) + 736) = -1;
        func_001bc0d0(((u8*)D_01d49320_w));
        return;
    }
    func_001bbc30();
}

s32 func_001bb7f8(void) {
    s32 r = 0;
    if (func_001bb4a0() && (func_00198d00(8, -1) || *(u32*)(D_01d49320 + 172))) r = 1;
    return r;
}

void func_001bb858(s32 a) {
    func_001bb890();
    func_001bb468();
    func_001991a8(15, a);
}

void func_001bb890(void) {
    D_01d49320_u.p->flags |= 4;
    D_01d49320_u.p->flags |= 0x10;
    func_0014ca20();
    D_0034f240 |= 2;
    func_001d6c58();
    func_001c11a8(8);
    func_001c1130(5);  // copy_record_block_to_table
    func_001af9f8();
}

void func_001bb8f0() {
    u32 g = D_01d49320;
    *(u32*)(g + 4) &= 0xffffffef;
    func_001919a8();

    D_0034f240 &= 0xfffffffd;
    func_001d6c88();
    func_001bbac0();
    func_002bc798();
    return func_001c8d98((u32)&D_00351ec8, 0);
}

void func_001bb958(s32 n) {
    if (n == 0) {
        if (!w1758_ys_mission_isexec()) return;
        n = *(u16*)(*(u8**)(D_01d49320 + 8) + 6);
    }
    if (n > 0) func_0014f578(w1758_tail4_192048(n));
}

s32 func_001bb9b0(void) {
    s32 r = 0;
    if (func_001bb4a0()) {
        u32 h = *(u16*)(*(u8**)(D_01d49320 + 8) + 4);
        r = (h >> 4) & 1;
    }
    return r;
}

u8 func_001bb9f0(void) {
    u8 r = 0;
    if (func_001bb4a0()) r = ((Flags16*)(*(u8**)(D_01d49320 + 8) + 4))->bit9;
    return r;
}

s32 func_001bba30(u8* o) {
    u32 buf[2];
    buf[0] = 0;
    buf[1] = 0;
    u32 a = *(u32*)(o + 72);
    u8 c;
    if (!a || (c = (*(u8**)(o + 8))[12]) == 0) return 0;
    func_001d5370(buf, a, c - 1);
    func_002534e0(buf[1], buf[0]);
    return 1;
}

u8 func_001bba88(void) {
    if (func_001bb4a0()) return func_001bba30_u8(D_01d49320);
    return 0;
}

void func_001bbac0(void) {
    if (func_001bb4a0()) {
        u8 c = *(*(u8**)(D_01d49320 + 8) + 8);
        if (c) func_001c11a8(c);
    }
}

u32 func_001bbb08(void) {
    u32* p = (u32*)D_01d49320;
    if (p == 0) return 0;
    return *p;
}

u32 func_001bbb28(void) {
    u8* p = D_01d49320;
    if (p == 0) return 0;
    if (*(u16*)(*(u8**)(p + 8) + 4) & 0x400) return 1;
    return 0;
}

s32 func_001bbb50(void) {  // type_is_2_or_25
    void* p = D_01d49320;
    if (!p) return 0;
    switch (*(u8*)(*(u8**)((u8*)p + 8) + 8)) {
    case 2:
    case 25:
    case 32:
        return 1;
    }
    return 0;
}

void func_001bbba8(s32 m) {
    s32 id = -1;
    u8 buf[48];
    switch (m) {
    case 3:
        if (func_001d5460(D_01d49324)) func_001d7940();
        id = 139;
        break;
    case 4:
        func_001ada38(9);
        id = 141;
        break;
    }
    func_001bb468();
    func_00199098(buf, id);
    func_0019f070(buf, 0x40000000);
}

void func_001bbc30(void) {
    u8 k = (*(u8**)(D_01d49320_pp + 2))[8];
    func_001bb468();
    switch (k) {
    case 2:
    case 30:
    case 35:
        func_001af360(0);
        break;
    default:
        func_001af2e8();
        break;
    }
}

u8* func_001bbcb0(void) {
    return D_01d49320;
}

s32 func_001bbcc0(void) {
    if (func_001bb4a0()) return *(*(u8**)((u8*)func_001bbcb0() + 8) + 14);
    return 1;
}

void func_001bbcf8(u32 a0) {
    u32 s0 = a0;
    if (func_001bb4a0() == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    if ((*(u32*)(v0 + 752) & 4) == 0) {
        return;
    }

    v0 = func_001bbcb0();
    return func_001d4e50(v0 + 740, s0);
}

void func_001bbd58(u32 a0) {
    u32 s0 = a0;
    if (func_001bb4a0() == 0) {
        return;
    }

    u32 v0 = func_001bbcb0();
    if ((*(u32*)(v0 + 752) & 4) == 0) {
        return;
    }

    v0 = func_001bbcb0();
    return func_001d4ef0(v0 + 740, s0);
}

s32 func_001bbdb8(u32 a0) {
    if (func_001bb4a0()) {
        if (*(u32*)(func_001bbcb0() + 752) & 4) {
            func_001d4fa8(func_001bbcb0() + 740, a0);
            return 1;
        }
    }
    return 0;
}

void func_001bbe18(void* a0) {
    if (a0 != 0) {
        func_002bc1e8();
    }
}

void func_001bbe38(u32 a0) {
    u32 s0 = a0;
    if (func_001bb4a0() != 0) {
        u32 v0 = func_001bbcb0();
        u32 t7 = *(u32*)(v0 + 1320);
        t7 |= s0;
        *(u32*)(v0 + 1320) = t7;
    }
}

void func_001bbe78(u32 a0) {
    u32 s0 = a0;
    if (func_001bb4a0() != 0) {
        u32 v0 = func_001bbcb0();
        u32 t7 = *(u32*)(v0 + 1320);
        u32 t6 = ~s0;
        t7 &= t6;
        *(u32*)(v0 + 1320) = t7;
    }
}

u32 func_001bbec0(void) {
    u32 r = 0;
    if (func_001bb4a0()) {
        u32 h = *(u16*)(*(u8**)(func_001bbcb0() + 8) + 4);
        r = (h >> 11) & 1;
    }
    return r;
}

u32 func_001bbf00(void) {
    if (!func_001bb4a0()) return 0;
    u32 v = *(u16*)(*(u8**)(func_001bbcb0() + 8) + 4);
    return (v >> 12) & 1;
}

u32 func_001bbf40(void) {
    u32 r = 0;
    if (func_001bb4a0()) {
        u8* v = func_001bbcb0();
        u32 x = *(u16*)(*(u8**)(v + 8) + 4);
        r = (x >> 1) & 1;
    }
    return r;
}

u32 func_001bbf80(u32 a0) {
    u32 s0 = a0;
    if (func_001bb4a0() != 0) {
        u32 p = func_001bbcb0();
        if (*(u32*)(p + 1324) != 0) {
            return *(u32*)(func_001bbcb0() + 1324);
        }
    }
    return s0;
}

f32 func_001bbfd0(void) {
    if (func_001bb4a0()) return *(f32*)(func_001bbcb0() + 1328);
    return 1.0f;
}

u32 func_001bc010(void) {
    u32 r = 0;
    if (func_001bb4a0()) { u32 h = *(u16*)(*(u8**)(func_001bbcb0() + 8) + 4); r = (h >> 13) & 1; }
    return r;
}

bool func_001bc050(void) {
    if (!func_001bb4a0()) return 0;
    return ((Flags1bc*)(*(u8**)((u8*)func_001bbcb0() + 8) + 4))->b;
}

u32 func_001bc090(u32) {
    u32 r = 0;
    if (func_001bb4a0()) r = 0 < (u32)func_001d5460(*(u32*)(func_001bbcb0() + 8));
    return r;
}

void func_001bc0d0(void* m) { *(u32*)((u8*)m + 728) = 4; }

s32 func_001bc0e0(void) {
    s32 r = 0;
    if (!func_001bb4a0() || !(*(u32*)(func_001bbcb0() + 4) & 0x10)) r = 1;
    return r;
}

s32 func_001bc130(void) {
    s32 r = 0;
    if (func_001bb4a0() == 0) goto yes;
    {
        u8 f = (*(u16*)(*(u8**)(func_001bbcb0() + 8) + 4) >> 2) & 1;
        if (!f) goto out;
    }
yes:
    r = 1;
out:
    return r;
}


}  // extern "C"
