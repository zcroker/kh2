#include "../common/types.h"

extern "C" {

struct Vec4 { f32 x, y, z, w; } __attribute__((aligned(16)));

extern void* D_0032b9ec;
u32 func_00102818(void*, u32, u32, u32, u32);
u32 func_00103b78(u32 a, u32 b, u32 c, u32 d) {
    return func_00102818(D_0032b9ec, a, b, c, d);
}

struct Obj109 { u8 pad[16]; u32 f16; };
extern Obj109* D_0033cc90[];
extern u32 D_0033cc78[];
void func_00109cc0(s32 i, u32 v) {
    if (!D_0033cc90[i]) D_0033cc78[i] = v;
    else D_0033cc90[i]->f16 = v;
    D_0033cc90[i] = (Obj109*)v;
}

extern u32 D_00347050;
void func_00113668(void*);
void func_00105110(void*);
void func_001153e8(void** p) {
    *p = &D_00347050;
    func_00113668(p);
    func_00105110(p);
}

extern u8 D_00347c88[];
void func_00133bb8(void*, u32, u32, u32);  // forward_sub24_to_133848
void func_001344b8(u32 a) {
    func_00133bb8(D_00347c88, 0, a | 0x3000000, ((1024 - a) >> 1) | 0x2000000);  // forward_sub24_to_133848
}

void func_00135cc8(u8* p, u32 a, u32 b) {
    s32 n = *(s32*)(p + 12);
    for (s32 i = 0; i < n; i++) {
        if (*(u32*)(p + 16) == a) { *(u32*)(p + 16) = b; return; }
        p += 4;
    }
}

extern u8 D_00348700;
extern void* D_0032b96c;
void func_0013ef90(void);
void func_00102788(void*, u32, u32, void*);
void func_0013efe8(void) {
    D_00348700 = 0;
    func_00102788(D_0032b96c, 0, 300000, (void*)func_0013ef90);
}

extern void* D_00349ef8;
void func_003058a0(u32);
void func_002f25a0(u32, u32);
void func_002f3918(void*, void*);
void func_0014d8d0(void* p) {
    func_003058a0(0);
    func_002f25a0(0, 0);
    func_002f3918(D_00349ef8, p);
}

u32 func_00139d78(void*);
void func_00151bf0(void*);
void func_0014fb00(void* p) {
    if (func_00139d78(p)) func_00151bf0(p);
}

extern u8 D_0034d3c0[];
u8 func_001678f0(void*);
u8 func_00167b60(void) {
    func_001678f0(D_0034d3c0);
    return func_001678f0(D_0034d3c0 + 384);
}

void func_0016adc8(void*, Vec4*);
void func_0016aeb8(void*, f32);
void func_0016ae18(u8* p) {
    Vec4 v;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&v), "r"(p + 2192) : "$8", "memory");
    func_0016adc8(p, &v);
    func_0016aeb8(p, *(f32*)(p + 2204));
}

typedef u32 (*VFn3)(void*, u32, void*);
extern void* D_004f6288;
u32 func_0016c7a0(u32 a) {
    void* o = D_004f6288;
    return (**(VFn3**)o)(o, a, __builtin_return_address(0));
}

void func_0016b010(void*, Vec4*);  // obj_set_float1644_from_pair
void func_00171930(u8** p) {
    Vec4 v;
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&v), "r"(p[1]) : "$8", "memory");
    func_0016b010(*(void**)(p[0] + 4), &v);  // obj_set_float1644_from_pair
}

void func_0019ba60(void*);
void func_00172e48(u8** p) {
    func_0019ba60(*(void**)(p[0] + 4));
    *(u32*)p = *(u32*)(*(u8**)(p[0] + 4) + 2760);
}

Vec4* func_0016c028(void*);  // obj_get_attach_or_alt
Vec4 func_0018d808(u8* b) {
    Vec4 r;
    Vec4* s = func_0016c028(*(void**)(b + 8));  // obj_get_attach_or_alt
    asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(&r), "r"(s) : "$8", "memory");
    return r;
}

struct Arg18f { void* a; u32 b; u32 c; f32 d; f32 e; };
void func_001a4d40(void*, u32, u32, f32, f32);
void func_0018f9b8(Arg18f* p) {
    void* a = p->a;
    func_001a4d40(a, p->b, p->c, p->d, p->e);
}

struct Node1995 { u8 pad[12]; u32 key; u32 pad2; Node1995* next; };
extern Node1995* D_01c62140;
void func_001995b8(u32 a, u32 b) {
    for (Node1995* n = 0; (n = !n ? *(Node1995* volatile*)&D_01c62140 : n->next) != 0; ) {
        if (n->key == a) n->key = b;
    }
}

void func_001a9350(void*);
void func_001a9218(void*);
void func_001a93b0(u32* p, u32 v) {
    func_001a9350(p);
    *p = v;
    func_001a9218(p);
}

extern u8 D_01c6cd20[];
void func_002362b0(void*, u32);
void func_002367c8(void*);  // obj_dispatch_bitfield64
void func_001aadb0(u32 a) {
    func_002362b0(D_01c6cd20, a);
    func_002367c8(D_01c6cd20);  // obj_dispatch_bitfield64
}

u32 func_001b0320(u32, u32, u32, u32);  // is_field16_set
void func_002bc358(u32, u32);
void u_call4_001b0330(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16u_call4_001b0330jjjj");
void u_call4_001b0330(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32* p = (u32*)a0;
    if (func_001b0320(a0, a1, a2, a3)) {  // is_field16_set
        func_002bc358(p[4], 0);
        p[4] = 0;
    }
    p[2] = (u32)-1;
}

extern u8* D_01d49320;
u32 func_001bb4a0(void);
u32 func_001bb4b0(void) {
    u32 r = 0;
    if (func_001bb4a0()) { u32 m = *(u32*)(D_01d49320 + 4) & 4; r = m == 0; }
    return r;
}

u8 func_001bba30(void*);
u8 func_001bba88(void) {
    if (func_001bb4a0()) return func_001bba30(D_01d49320);
    return 0;
}

u8* func_001bbcb0(void);
u32 func_001bc010(void) {
    u32 r = 0;
    if (func_001bb4a0()) { u32 h = *(u16*)(*(u8**)(func_001bbcb0() + 8) + 4); r = (h >> 13) & 1; }
    return r;
}

extern void* D_00352678;
extern void* D_00352668;
void func_001a4e30(void*);
void func_001d28f0(void** p) {
    *p = &D_00352678;
    D_00352668 = 0;
    func_001a4e30(p);
    func_00105110(p);
}

u8* func_001d3498(u8* p, u8* cur) {
    if (!cur) return p + 8;
    if (cur == p + 8 + (*(s32*)(p + 4) - 1) * 96) return 0;
    return cur + 96;
}

struct Ent1d7 { u32 a; u32 b; };
struct Obj1d7 { u32 hdr; Ent1d7 e[4]; };
void func_001d7b10(u32, u32, u32, u32);
void wtarget_001d7a50(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16wtarget_001d7a50jjjj");
void wtarget_001d7a50(u32 a0, u32 a1, u32 a2, u32 a3) {
    Obj1d7* o = (Obj1d7*)a0;
    for (s32 i = 3; i >= 0; i--) o->e[3 - i].a = 0;
    func_001d7b10(a0, a1, a2, a3);
}

extern u32 D_00352908;
void func_001980d0(void*, u32, u32, u32);
void func_001d9eb0(u8* p, u32 a, u32 b) {
    func_001980d0(p, a, 10, b);
    *(u32*)(p + 2552) = 0;
    *(u32*)(p + 2548) = 0;
    *(void**)p = &D_00352908;
}

extern void* D_01d9e6e4;
void func_002fde18(void*, u32, u32);
u8 func_001e7798(void*, void*);
u8 func_001e6c00(void* p) {  // alloc_336_align_171
    func_002fde18(p, 171, 336);
    return func_001e7798(D_01d9e6e4, p);
}

extern u32 D_0035db10;
extern u8 D_0035de27;
extern u32 D_0035de30;
extern u32 D_0035de34;
extern u32 D_0035de38;
extern u32 D_0035de3c;
void func_00226a78(void) {
    D_0035db10 = 0;
    D_0035de27 = 0;
    D_0035de30 = 0;
    D_0035de34 = 0;
    D_0035de38 = 0;
    D_0035de3c = 0;
}

void func_0023f688(u8* p, u32 v) {
    func_00139d78(p);
    *(u32*)(p + 40) = v;
}

void* func_001708f8(const char*, s32);
void func_0023fa08(void*, void*);
void LayFile_alloc(u8* self, const char* name) asm("_ZN2Tz7LayFile5allocEPKc");
void LayFile_alloc(u8* self, const char* name) {
    func_0023fa08(self, func_001708f8(name, -1));
    self[24] = 1;
}

u8 func_0031acc0(void*);
u8 func_00258158(u8* p) {
    func_0031acc0(p + 872);
    func_0031acc0(p + 436);
    return func_0031acc0(p);
}

u8* func_00103eb0(void);
void func_00263db0(void);
void func_00263d70(void) {
    func_00102818(*(void**)(func_00103eb0() + 4), 0, 2000, (u32)func_00263db0, 4096);
}


extern u8 D_0035f3a8[];
void* func_002537c8(u32);
void PauseTaskSetup(...) asm("_ZN2Tz14PauseTaskSetupEz");
void PauseTaskSetup(...) {
    func_0023fa08(D_0035f3a8, func_002537c8(0));
}

extern void* D_0035f574;
void func_00290940(void*);
u32 func_00293db8(u32, u32);
void func_00290960(void*, u32, u32);
void func_00293fc0(void) {
    func_00290940(D_0035f574);
    func_00290960(D_0035f574, func_00293db8(0, 0), 43);
}

u8* func_002766d0(void);
void func_0028da70(void*, u32);
void func_0029e3a0(s32 i) {
    u8* v = func_002766d0();
    i++;
    func_0028da70((u8*)v + i * 408 + 17304, 8);
}

u8* func_00294000(u32);
u8* func_002a01c8(s32 i) {  // obj4_entry_by_index
    u8* b = func_00294000(4) + 16;
    return b + i * 8;
}


extern u32 D_00362158;
void func_002cea28(void*);
void func_002d1840(void** p) {
    *p = &D_00362158;
    func_002cea28(p);
    func_00105110(p);
}

extern u32 D_00362428;
void func_002cfeb0(void*, u32, u32, u32);  // obj_init_field1416_bit800
void func_002e7308(void*);
void func_002d5d50(u8* p, u32 a, u32 b) {
    func_002cfeb0(p, a, 1, b);  // obj_init_field1416_bit800
    *(void**)p = &D_00362428;
    func_002e7308(p + 2872);
}

extern u8* D_00361f60;
void func_002ceb08(void);
u32 GetCurrentPoint(void* self) asm("_ZN2Ti12MG_EHSidecar15GetCurrentPointEv");
u32 GetCurrentPoint(void* self) {
    u8* s = D_00361f60;
    if (s) func_002ceb08();
    return *(u32*)(s + 264);
}

void* func_001050d8(u32);
void* func_0016e920(u32);
void func_002ed300(void*, void*, u32);
void TrinityShot_Init(void* self) asm("_ZN2Ts16TRINITY_SHOT_OBJ4InitEv");
void TrinityShot_Init(void* self) {
    void* v = func_001050d8(2560);
    func_002ed300(v, func_0016e920(1475), 256);
}

void* func_0010c7e8(void*);
void func_00119e60(void*, u32);
void trap_genie_change_form(u8** v) asm("_ZN2kn22trap_genie_change_formEP8BD_VALUE");
void trap_genie_change_form(u8** v) {
    func_00119e60(func_0010c7e8(*(void**)(v[0] + 4)), (u32)v[1]);
}

extern u32 D_003677b8;
void func_00315768(void*);
void func_00106420(void*);
void func_003158c8(void** p) {
    *p = &D_003677b8;
    func_00315768(p);
    func_00106420(p);
}

extern u32 D_00351228;
void func_001d48b0(void*);
void func_003206f0(u8* p) {
    *(void**)p = &D_00351228;
    func_001d48b0(p + 2496);
    func_00106420(p);
}

struct Node321 { u8 pad[20]; Node321* next; };
u32 u_call4_00321cb0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z16u_call4_00321cb0jjjj");
u32 u_call4_00321cb0(u32 a0, u32 a1, u32 a2, u32 a3) {
    Node321* n = 0;
    while ((n = !n ? *(Node321**)a0 : n->next) != 0) {
        if (n == (Node321*)a1) return 1;
    }
    return 0;
}

}
