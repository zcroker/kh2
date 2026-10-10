#include "../common/types.h"
struct W279Vq {
    f32 x, y, z, w;
    W279Vq& operator=(const W279Vq& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
} __attribute__((aligned(16)));
extern "C" {
// ---- func_00244708
s32 func_00287cd0(void*);
s32 func_00289310(void*);
s32 func_002891e8(void*);
void func_002890e0(void*, s32, s32, s32, s32);
void func_00289038(void*, s32, s32, s32, s32, s32, s32);
s32 func_00244ee8(s32);
void func_0023f070(void*, s32, s32);
s32 func_0028d008(void*);
s32 func_002891d0(void*);
void func_0028cf28(void*, s32);  // record408_set_and_refresh
void func_002b4388(void*, void*, s32);
void func_00244e28(void);
void func_00244b38(void);
extern void* D_0035ecf8;
extern void* D_0035ed08;
struct W279S6 { s16 a; s16 b; s16 c; };
extern W279S6 D_00371968[];
struct W279S36 { u8 x[36]; };
extern W279S36 D_003719a0[];
extern W279S36 D_003719e8[];
void func_00244708(void* a0, s32 a1, void* a2) {
  if (func_00287cd0(a0) != 1) return;
  if (!func_00289310(a0)) return;
  s32 s3 = func_002891e8(a0);
  func_002890e0(a0, 1, 2, 0, -1);
  func_00289038(a0, s3, 1, 1, 2, 0, -1);
  if (a1 == 0) {
    func_0023f070(D_0035ecf8, D_00371968[func_00244ee8(s3)].c, -1);
  }
  if (func_0028d008(a2)) {
    func_0028cf28(a2, func_002891d0(a0));  // record408_set_and_refresh
  }
  if (a1 == 0) {
    func_002b4388(D_0035ed08, &D_003719a0[func_00244ee8(s3)], 0);
    func_00244e28();
  } else {
    func_002b4388(D_0035ed08, &D_003719e8[s3], 0);
  }
  func_00244b38();
}

// ---- func_0026b2c0
u8* item_get_info(void*) asm("_ZN2Tz8ItemInfo7GetInfoEv");
s32 menu_get_mode(void) asm("_ZN2Tz8MenuBase7GetModeEv");
s32 cmtop_get_select_pos(s32) asm("_ZN2Tz5CmTop12GetSelectPosEi");
s32 cmtop_get_cur_pos(s32) asm("_ZN2Tz5CmTop9GetCurPosEi");
s32 jm_report_get_data(u32) asm("_ZN2Tz8JmReport7GetDataEj");
u8* party_get_sheet(void*, s32) asm("_ZN2Tz9PartyInfo8GetSheetEi");
u16* func_0026a178(s32, s32);
u8* func_001a80c8(s32);  // table24_find_by_id
u8* func_001a8190(u8*);
extern void* D_0035f0ec;
extern u32 D_0035f01c;
extern void* D_0035f010;
union W279Slot { u16 raw; struct { u16 id : 15; u16 on : 1; } b; };
static inline u8 w279_stat(u16 id) {
    if (id == 0) return 0;
    return func_001a8190(func_001a80c8(id))[7];
}
s32 func_0026b2c0(void) {
    u8* info = item_get_info(D_0035f0ec);
    u16 sel;
    u16 old;
    s32 sum;
    s32 i;
    W279Slot* p;
    if (menu_get_mode() != 8) return 0;
    sel = 0;
    u16* r = func_0026a178(cmtop_get_select_pos(2), 2);
    if (r) sel = *r;
    if (sel == 0) return 0;
    s32 k = jm_report_get_data(D_0035f01c);
    old = k ? *(u16*)(info + k * 6 - 6) : 0;
    sum = 0;
    s32 who = cmtop_get_cur_pos(1);
    p = (W279Slot*)(*(u8**)(party_get_sheet(D_0035f010, who) + 580) + 84);
    for (i = 0; i < 80; i++) {
        W279Slot x = *p++;
        if (x.b.id && (x.raw >> 15)) sum += func_001a80c8(x.b.id)[7];
    }
    u16 cap = *(u16*)(party_get_sheet(D_0035f010, who) + 398);
    s32 a;
    if (sel) a = func_001a8190(func_001a80c8(sel))[7];
    else a = 0;
    s32 d = a - w279_stat(old);
    if (cap - sum - d < 0) return 1;
    return 0;
}

// ---- func_00179718
s32 map_is_pax_exist(void) asm("_ZN2dk3Map10isPaxExistEv");
void* map_get_pax(void) asm("_ZN2dk3Map6getPaxEv");
s32 effect_is_alive(void*) asm("_ZN3ryj6EFFECT8is_aliveEv");
void effect_kill(void*) asm("_ZN3ryj6EFFECT4killEv");
W279Vq* effect_pos(void*) asm("_ZN3ryj6EFFECT3posEv");
W279Vq* effect_angle(void*) asm("_ZN3ryj6EFFECT5angleEv");
s32 pax_search_id(void*, u64) asm("_ZN3ryj3PAX9search_idEy");
void* func_001de168(void*, s32, s32, s32, s32, s32);  // scan_list_by_half
W279Vq octree_get_normal(u16, bool) asm("_ZN2dk6Octree9getNormalEtb");
W279Vq func_0017d050(const W279Vq&);
extern f32 D_00349e10;
typedef void (*W279VFn1)(u8*, s32);
void func_00179718(u8* o) {
    if (!map_is_pax_exist()) return;
    if (*(void**)(o + 2900)) {
        if (!effect_is_alive(*(void**)(o + 2900))) {
            effect_kill(*(void**)(o + 2900));
            *(void**)(o + 2900) = 0;
        }
    }
    u32 id = *(u16*)(o + 1522);
    if (id != 0xffff) {
        if (*(void**)(o + 2900) == 0 && id != *(s32*)(o + 2904)) {
            s32 k = pax_search_id(map_get_pax(), 1);
            if (k >= 0) {
                void* h = func_001de168(map_get_pax(), k, 0, 2, 40000, 0);  // scan_list_by_half
                *(void**)(o + 2900) = h;
                if (h) {
                    W279Vq n = octree_get_normal(id, 0);
                    *effect_pos(*(void**)(o + 2900)) = *(W279Vq*)(o + 1488);
                    *effect_angle(*(void**)(o + 2900)) = func_0017d050(n);
                }
            }
            s32 v = *(u16*)(o + 1522);
            *(s32*)(o + 2904) = v;
            (*(W279VFn1**)o)[37](o, v);
        }
        *(f32*)(o + 2908) = 30.0f;
    } else {
        f32 t = *(f32*)(o + 2908);
        if (0.0f < t) {
            f32 t2 = t - D_00349e10;
            *(f32*)(o + 2908) = t2;
            if (t2 <= 0.0f) *(s32*)(o + 2904) = id;
        }
    }
}

// ---- func_0022e818
s32 func_002282f0(s32);
s32 func_002282d8(void);  // limit_15000_or_25000
u8* sa_entry_work_get(s32) asm("_ZN2sa5EVENT14entry_work_getEi");
void func_001ba028(u32);  // list_contains_ptr
s32 func_00225b00(s32);  // flag_query_by_index
u8* field_create_task(s32, s32, void (*)(void*)) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
void* area_get_allocator(void) asm("_ZN4AREA12GetAllocatorEv");
f32* tz_load_data_alloc(u32, void*) asm("_ZN2Tz13LoadDataAllocEjj");
f32 sa_get_float(void*) asm("_ZN2sa5EVENT9get_floatEPv");
void func_0014f030(f32*, f32, f32, f32);  // obj_set_lerp_params
void func_0022e6b0(s32, u32, f32);
void func_0022e7e8(void*);
void func_0022e728(void*);
union W279H { s16 h; u8 c; };
union W279P { f32* p; u8 c; };
void func_0022e818(u8* s) {
    if (func_002282f0(*(s16*)(s + 4))) return;
    s32 a = func_002282d8();  // limit_15000_or_25000
    u8* b = sa_entry_work_get(*(s16*)(s + 6));
    func_001ba028(*(u32*)(b + 8));  // list_contains_ptr
    if (!func_00225b00(*(s16*)(s + 4))) {  // flag_query_by_index
        u8* t = field_create_task(1, a, func_0022e728);
        *(u32*)(t + 48) = (u32)func_0022e7e8;
        *(u32*)(t + 4) = *(u32*)(b + 8);
        f32* v = tz_load_data_alloc(12, area_get_allocator());
        v[0] = 0.0f;
        v[1] = 0.0f;
        v[2] = 1.0f;
        ((W279P*)(t + 8))->p = v;
        *(s32*)(t + 12) = ((W279H*)(s + 18))->h;
        f32 h = ((W279H*)(s + 16))->h;
        f32 x = sa_get_float(s + 8);
        h = h * 2.0f;
        f32 y = sa_get_float(s + 12);
        func_0014f030(v, x, y, h);  // obj_set_lerp_params
    } else {
        func_0022e6b0(*(s16*)(s + 18), *(u32*)(b + 8), sa_get_float(s + 12));
    }
}

// ---- func_00100ec8
s32 func_001009a0(u8*);
s32 func_00100920(u8, void*);  // classify_subtype
void func_001004c0(u8, s32, u32*, u32*);
u32 func_001003c8(u8);  // classify_arg_masked3
struct W279Obj { u32 min; u32 pad[3]; u64 lo : 2; u64 dirty : 1; u64 id : 8; u64 rest : 53; };
s32 func_00100ec8(W279Obj* obj, u32* list) {
    s32 id = 0;
    u8* last = 0;
    s32 cnt = 0;
    s32 h = 0;
    u32 out[4];
    if (list[0]) do {
        if (list[1]) {
            u8* key = (u8*)list - list[1] + 4;
            if (key != last) {
                last = key;
                id = func_001009a0(key);
                h = func_00100920(id, obj);  // classify_subtype
                s32 cur = obj->id;
                if (cur == 0xff) {
                    obj->id = id;
                } else if (cur != id) {
                    obj->dirty = 1;
                }
            }
            func_001004c0(id, h, list + 2, out);
            u32 n = func_001003c8(id);  // classify_arg_masked3
            u32 mask;
            if (n < 4) mask = (1LL << (n * 8)) - 1;
            else mask = -1;
            u32 v = out[0];
            if (v & mask) {
                cnt++;
                if (v < obj->min) obj->min = v;
            }
        }
        list = (u32*)((u8*)list + list[0] + 4);
    } while (list[0]);
    return cnt;
}

// ---- func_003048b8
struct W279Big { W279Big* next; s32 k, maxwds, sign, wds; u32 x[1]; };
W279Big* w279_balloc(void*, s32) asm("_Z16ctarget_00303b70jjjj");
s32 func_00303e80(u32);  // count_leading_zeros
s32 func_00303f00(u32*);
union W279Dbl { double d; u32 w[2]; };
W279Big* func_003048b8(void* ptr, double dd, s32* e, s32* bits) {
    W279Dbl d;
    W279Big* b;
    s32 de, i, k;
    u32* x;
    u32 y, z;
    d.d = dd;
    b = w279_balloc(ptr, 1);
    x = b->x;
    z = d.w[1] & 0xfffff;
    d.w[1] &= 0x7fffffff;
    if ((de = (s32)(d.w[1] >> 20)) != 0) z |= 0x100000;
    if (d.w[0] != 0) {
        y = d.w[0];
        if ((k = func_00303f00(&y)) != 0) {
            x[0] = y | z << (32 - k);
            z >>= k;
        } else
            x[0] = y;
        i = b->wds = (x[1] = z) ? 2 : 1;
    } else {
        k = func_00303f00(&z);
        x[0] = z;
        i = b->wds = 1;
        k += 32;
    }
    if (de) {
        *e = de - 1023 - 52 + k;
        *bits = 53 - k;
    } else {
        *e = de - 1023 - 52 + 1 + k;
        *bits = 32 * i - func_00303e80(x[i - 1]);
    }
    return b;
}
}
