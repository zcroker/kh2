#include "../common/types.h"

// Batch w15: small wrappers, destructors, list searches and leaf helpers.

struct Q16 { u32 w[4]; } __attribute__((aligned(16)));

extern "C" {

struct Node38 { u32 key; u8 _4[52]; Node38* next; };
struct List8 { u32 _0; u32 _4; Node38* head; };
// 00102a38: moved to src/global/unit_001022c0.cpp

extern u8 D_00346b08;
void func_00113668(void*);
void func_00105110(void*);
void func_00114f38(void** self) {
    *self = &D_00346b08;
    func_00113668(self);
    func_00105110(self);
}

void func_0011b6a8_impl(void* dst) asm("_Z13func_0011b6a8Pv");
extern Q16 D_003478f0[4];
void func_0011b6a8_impl(void* dst) {
    asm volatile(".set noreorder\n\t"
                 "lq $8, 0(%1)\n\tlq $9, 16(%1)\n\tlq $10, 32(%1)\n\tlq $11, 48(%1)\n\t"
                 "sq $8, 0(%0)\n\tsq $9, 16(%0)\n\tsq $10, 32(%0)\n\tsq $11, 48(%0)\n\t"
                 ".set reorder"
                 : : "r"(dst), "r"(D_003478f0) : "$8", "$9", "$10", "$11", "memory");
}

extern u8 D_00347bd8;
void func_00124c08(void*);  // set_vtbl_347b88
void func_00106420(void*);
void func_00131770(void** self) {
    *self = &D_00347bd8;
    func_00124c08(self);  // set_vtbl_347b88
    func_00106420(self);
}

struct Chunk { s16 type; u16 _2; u32 _4; u32 offs[1]; };
void* func_00132068(Chunk* c, int i) {  // entry_get_by_index
    if (c != 0) {
        switch (c->type) {
        case -1: return (u8*)c + c->offs[i];
        case 0: return c;
        }
    }
    return 0;
}

int obj_is_exist_00139768(void*) asm("_Z13func_00139768jjjjjjjj");
void func_001394c0(void*);
void func_00102750(u32);
extern u32* D_00347f80;
void func_001394d8(void* p) {
    obj_is_exist_00139768(p);
    func_001394c0(p);
    func_00102750(*D_00347f80);
}

int func_00141970(void*, u32);  // vtable_get12
void func_001450e8(void*, int, u32);
void func_00142900(u8* p, u32 a, u32 b) {
    u8* q = *(u8**)(p + 4);
    int r = func_00141970(p, a);  // vtable_get12
    func_001450e8(q + 16, r, b);
}

int func_00139d78(void*);
void func_00151528(void*);
void func_0014f830(void* p) {
    if (func_00139d78(p)) func_00151528(p);
}

void func_001386e0(u8*, u32, u32, u32, u32, u32);
// 00158050: moved to src/anon/unit_00158050.cpp

void func_00144450(void*);
void func_001616d8(void*);
void func_001614e8(u8* p, u32 v) {
    *(u32*)(p + 68) = v;
    *(u32*)(p + 64) = 0;
    *(u32*)(p + 72) = 0;
    *(u32*)(p + 76) = 0;
    *(u32*)(p + 80) = 0;
    func_00144450(p + 84);
    func_001616d8(p);
}

void func_001666a0(void*);  // zero_fields_0_4_6_8
void func_00166930(u8* p) {
    func_001666a0(p);  // zero_fields_0_4_6_8
    *(u16*)(p + 12) = 0;
    *(u8*)(p + 14) = 1;
    *(u16*)(p + 10) = 0;
}

void* func_001dc670(u32);
void func_0016e500(u32* p) {
    void* d = func_001dc670(p[0]);
    void* s = (void*)p[1];
    if (d != s) {
        asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory");
    }
}

// 00180dc0: moved to src/anon/unit_00180408.cpp

struct Node2c { u32 _0; u32 _4; u32 flags; u8 _c[32]; Node2c* next; };
// 00180ef0: moved to src/anon/unit_00180408.cpp

void set_flag_impl(void* self, int) asm("_ZN2YS13TEST_PROGRESS8set_flagEi");
void func_00181178(u32);
extern u8 D_0032bb30[];
// 00181a90: moved to src/yasui/libys/progress.cpp

u32 func_001b58f0(u32, u32, u32, u32);
void func_0018fee8(u32* p) {
    p[0] = func_001b58f0(p[0], p[1], p[3], ((u32*)p[2])[1]);
}

struct Pair12 { u32 a; u32 b; u32 c; };
Pair12* func_0019f5d8(Pair12* e, u32 a, u32 b) {  // find_entry12_pair
    for (int i = 0; i < 8; i++) {
        if (e[i].a == a && e[i].b == b) return &e[i];
    }
    return 0;
}

void func_0016bd60(void*, u32);
// 001a2a18: moved to src/anon/unit_001a28f8.cpp

void* func_001a3a78(void*);
void func_001de168(void*, u32, u32, u32, u32, void*);  // scan_list_by_half
void func_001b7428(void* p) {
    func_001de168(func_001a3a78(p), 15, 1, 1, 10005, p);  // scan_list_by_half
}

extern u32 D_003511bc;
extern u8 D_003511c2;
extern u32 D_003511b8;
extern u32 D_01d48cb8;
void func_001b8258(void) {
    D_003511c2 = 1;
    D_003511bc = 0x70004000;
    D_003511b8 = 0x70000000;
    D_01d48cb8 = 0x70000000;
}

int func_001bb4a0(void);
u8* func_001bbcb0(void);
// 001bbec0: moved to src/yasui/libys/mission.cpp

void func_001c6fa8(u8*, u32, u32, u32, u32);
void func_001ca988(u8* p, u32 a1, u32 a2, u32 a3, u32 a4, u32 x) {
    func_001c6fa8(p, a1, a2, a3, a4);
    *(u32*)(p + 84) = x;
    *(u32*)(p + 88) = 0;
}

// Destructor: reset vtable, clear the global instance pointer, destroy base, free.
extern u8 D_00352060;
extern void* D_00352050;
void func_001a4e30(void*);
// 001cc0e8: moved to src/anon/unit_001cc048.cpp

u8 func_002fd248(u32, void*, u32, u32, void*);
extern u8* D_01d5ba00;
extern u8 D_00321688;
u8 func_001d22a8(u32 a) {
    u8* t = D_01d5ba00;
    return func_002fd248(a, t + 8, *(u32*)(t + 4), 16, &D_00321688);
}

extern u8* D_01d5ba70;
extern u8 D_003217a0;
u8 func_001d5b78(u32 a, u32 b);  // 0x001d5b78: definition moved into src/anon/unit_001d4f40.cpp

void wtarget_impl(u32, u32, u32, u32) asm("_Z16wtarget_001e0348jjjj");
struct W2 { u32 a; u32 b; };
extern W2 D_01d9e348;
void wtarget_impl(u32 a, u32 b, u32, u32) {
    if (b == 0xffff && a == 1) {
        D_01d9e348.b = 0;
        D_01d9e348.a = 0;
    }
}

void func_001e1988(void*);
void func_001e1ce0(u8* p) {
    func_001e1988(p);
    *(u32*)(p + 3520) = 1;
    *(u32*)(p + 3564) = *(u32*)(p + 3532);
    *(u32*)(p + 3560) = 0;
    *(u32*)(p + 3556) = 0;
}

void sceGsSyncPath(u32, u32);
u8 func_002f3918(u32, void*);
extern u32 D_003591c8;
extern u8 D_00359910;
u8 func_0020f150(void) {
    sceGsSyncPath(0, 0);
    return func_002f3918(D_003591c8, &D_00359910);
}

void func_00234460(u32, u32, u32, u32, u32, u32);
void func_002346f0(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4) {
    func_00234460(a0, 0, a1, a2, a3, a4);
}

struct Ent20 { u32 _0; u32 b; u32 _8; u32 c; u32 _10; };
struct Tbl { u32 _0; u32 _4; Ent20* ents; u32* idx; };
void func_002374c8(Tbl* t, int i, int j, u32 v) {  // entry20_accumulate_b
    Ent20* e = &t->ents[*(u16*)&t->idx[i] + j];
    e->c = v + e->c - e->b;
    e->b = v;
}

extern u32 D_0035eb88;
extern u32 D_0035eb8c;
extern u8 D_0035eb84;
void func_0023edb0(u32 x) {
    u32 cur = D_0035eb88;
    if (cur != x) {
        if (cur) D_0035eb8c = cur;
        D_0035eb88 = x;
        return;
    }
    D_0035eb84++;
}

void strlen(u32);  // strlen
void func_002346a0(s32, u32, u32);
extern u32 D_0035ec88;
extern s8* D_0035ec94;
void func_00241528(void) {
    strlen(D_0035ec88);  // strlen
    func_002346a0(*D_0035ec94, D_0035ec88, 0);
}

extern u32 D_0035ee80;
extern u32 D_0035ee5c;
u8 func_00139d78_u8(u32) asm("func_00139d78");
u8 func_0028acc8(u32);
int func_002519d0(void) {
    int r = func_00139d78_u8(D_0035ee80);
    if (!r) r = func_0028acc8(D_0035ee5c);
    return r;
}

typedef void (*VFn)(void*);
void func_002878c8(void*);
u8 func_0023f848(void*);
u8 func_00287760(u8* p) {
    func_002878c8(p);
    void** o = *(void***)p;
    (*(VFn*)((*(u8**)o) + 20))(o);
    return func_0023f848(p + 12);
}

extern u16 D_0035f470[3];
void func_0028f4a0(u16* src) {
    for (int i = 0; i < 3; i++) D_0035f470[i] = src[i];
}

void SetMsgId_impl(void* self, int id, int) asm("_ZN2Tz7SelHist8SetMsgIdEii");
u32 get_msg_00192048(int) asm("_Z16u_tail4_00192048jjjj");
void set_msg_0028fb68(void*, u32) asm("_ZN2Tz7SelHist6SetMsgEiPKN2YS7MESSAGEE");
void SetMsgId_impl(void* self, int id, int) {
    u32 m = 0;
    if (id >= 0) m = get_msg_00192048(id);
    set_msg_0028fb68(self, m);
}

u32 func_002c1b48(void*);
u32 func_001c2b58(u32);
void func_002c1b60(void*, u32);
void func_002c1c50(void* p) {
    func_002c1b60(p, func_001c2b58(func_002c1b48(p)));
}

extern u8 D_003621a0;
void func_002e7328(void*);  // to_2e7458
u8 func_002d2a08(void*);
u8 func_002d47a8(void** self) {
    *self = &D_003621a0;
    func_002e7328((u8*)self + 3208);  // to_2e7458
    return func_002d2a08(self);
}

void func_0016a9a0(void*);  // to_16a950
void func_002db610(void*, s32);
void func_002db7d0(u8* p) {
    func_0016a9a0(p);  // to_16a950
    func_002db610(p, (p[568] & 1) ? 0 : -1);
}

void func_002e9fe0(u32, u32, void*);
void func_002e8038(u32* p) {
    Q16 tmp;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&tmp), "r"(p[2]) : "$8", "memory");
    func_002e9fe0(p[0], ((u32*)p[1])[1], &tmp);
}

u8 func_0019bc38(void*);
u8 func_002e9c58(u8* a, u8* b) {
    if (*(u32*)(a + 12) != 2 && !(*(u32*)(b + 1416) & 4)) return func_0019bc38(b);
    return 1;
}

extern u8 D_00367860;
void func_003167f8(void*);  // set_vtbl_367910
u8 func_00106420_u8(void*) asm("func_00106420");
u8 func_00315678(void** self) {
    *self = &D_00367860;
    func_003167f8(self);  // set_vtbl_367910
    return func_00106420_u8(self);
}

extern u8 D_003512e8;
void func_0016a358(void*);
void func_003207c8(void** self) {
    *self = &D_003512e8;
    func_0016a358(self);
    func_00105110(self);
}

struct Ent8 { u16 id; u16 _2; u32 _4; };
Ent8* func_00320c18(u8* p, u32 id) {  // table_find_short
    int n = *(int*)(p + 4);
    Ent8* e = (Ent8*)(p + 8);
    for (int i = 0; i < n; i++, e++) {
        if (e->id == id) return e;
    }
    return 0;
}

}
