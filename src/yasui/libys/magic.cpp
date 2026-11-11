#include "magic.hpp"

// YS::MAGIC (0x1a5c08-0x1a6a10): the magic system. Six magic slots (scripts and PAX effects loaded
// from the magic table), the list of magics being cast, MP-drive flags and costs.

namespace ryj {
    struct PAX {
        u8 d[0x1c];
        PAX();
        ~PAX();
    };
}

struct W1626ScriptData {
    u8 type;            // 0x00
    u8 lenUnit;         // 0x01
    u8 pad02[0x24];
    u16 id;             // 0x26
    s16 motA;           // 0x28
    s16 blendA;         // 0x2a
    s16 motB;           // 0x2c
    s16 blendB;         // 0x2e
    s16 motC;           // 0x30
    s16 blendC;         // 0x32
    s8 seA;             // 0x34
    s8 seB;             // 0x35
    s8 seC;             // 0x36
};

struct W1626ScriptEntry {
    u32 m00;
    void* script;       // 0x04
    u32 m08;
    u8 arg0c[0x1c];     // 0x0c
    W1626ScriptData* data; // 0x28
};

struct W1626VObj;
struct W1626VObjVt {
    void* f[24];
};
struct W1626Sub {
    void** vt;
};
struct W1626Tune {
    u8 pad[0x48];
    f32 blendNormal;    // 0x48
    u8 pad4c[0xd0 - 0x4c];
    f32 blendSpecial;   // 0xd0
};
struct W1626Ability {
    u8 pad[0xc];
    u32 flags;          // 0x0c
};
struct W1626VObj {
    W1626VObjVt* vt;
    u8 pad04[8];
    W1626Sub* sub;      // 0x0c
    u8 pad10[0x140 - 0x10];
    u8 motion[0x448];   // 0x140
    u32 flags;          // 0x588
    u8 pad58c[0x9f4 - 0x58c];
    W1626VObj* target;  // 0x9f4
    u8 pad9f8[0xb50 - 0x9f8];
    s32 form;           // 0xb50
};
struct W1626Task {
    u32 vm;
};


// One magic slot (44 bytes).
struct MAGIC_ENT {
    s32 cache;                 // 0
    void* script;              // 4
    s32 res1;                  // 8
    ryj::PAX pax;              // 12
    W1626ScriptData* data;     // 40
    MAGIC_ENT() : cache(0) { data = 0; }
};

struct Res1a5f50 { u8 pad[8]; s32 val; };
struct Data1a5f50 { s32 id; char name[1]; };
struct Ent1a5f50 { s32 cache; s32 res[2]; u8 arg[0x1c]; Data1a5f50* data; };
struct Task1a5f50 { u8 pad[48]; void (*fin)(TASK*); };
struct Pair1a5f50 { u32 a; u32 b; };
struct W261En { u8 id; u8 lv; u8 kind; u8 pad[33]; u16 req; u8 pad2[18]; };
struct W261Tb { u32 x; s32 n; W261En e[1]; };

using YS::MAGIC;

static LIST<MAGIC> s_list;
static W261Tb* s_table;
#define D_01c6cb28 s_table
extern "C" {
MAGIC_ENT D_00350800[6];
extern u32 D_0032f274[];
extern u8 D_0032bae0;
extern W1626Tune* D_00352130;
extern f32 D_0036d5c0;

W1626Ability* W1626_get_ability(W1626VObj*) asm("_ZN2YS5PARTY11get_abilityEv");
void func_0017a600(W1626VObj*);
s32 func_0019c090(W1626VObj*);
void W1626_motion_set(void*, s32, f32, f32) asm("func_0017f488");
void W1626_motion_push(void*, s32, f32, f32, void*) asm("_ZN2YS6MOTION4pushEiffPFvPNS_3OBJEE");
W1626Task* W1626_area_alloc(u32) asm("_ZN4AREA5AllocEj");
u32 W1626_vm_start(void*, W1626VObj*) asm("_ZN2YS2VM5StartEPvPNS_3OBJE");
u32 func_001ce350(s32);
void W1626_vm_call(u32, s32, u32*, s32) asm("_ZN2YS2VM4callEiP8BD_VALUEi");


void* func_001050d8(u32);
void func_00105110(void*);
void func_001826c8(f32);       // YS::AREADATA::AddCost
f32 func_001826e0(void);
void func_0016cab8(void*);
void func_0016c7d8(void*);
void func_001de450(ryj::PAX*);
void func_001dde40(ryj::PAX*);
void func_00170950(s32);
void func_00170518(char*, s32, s32);
void func_001bdff0(void);
u32 func_0016cf00(u32, u32, u32, u32, u32);
void func_00177998(void*);
void func_0016cbc8(void*, s32, s32, s32);
s32 func_001a3570(u32);
u8* func_001b8e88(u32);
s32 func_0019ba60(void*);
Task1a5f50* t1a5f50_CreateTask(s32, s32, void (*)(TASK*)) asm("_ZN5FIELD10CreateTaskEiiPFvP4TASKE");
void func_001a5db8(TASK*);
W261En* func_001a6658(s32 id);
s32 t1a5f50_Alloc(const char*, s32) asm("_ZN2YS10CACHE_BUFF5AllocEPKci");
Res1a5f50* func_00168b38(s32, s32, s32);
void t1a5f50_001dddd0(void*, s32) asm("_Z16wtarget_001dddd0jjjj");
u32 func_001a6598(u32);
u32 func_001a67b0(u32);
}
static inline bool Has1a5f50(Res1a5f50* r) { return r && r->val != 0; }
static inline W261En* W261Find(s32 id) {
    W261Tb* t = D_01c6cb28;
    W261En* e = t->e;
    for (s32 i = 0; i < t->n; i++, e++) {
        if (e->id == id) return e;
    }
    return 0;
}

namespace YS {

inline void* MAGIC::operator new(u32 n) { return func_001050d8(n); }
inline void MAGIC::operator delete(void* p) { func_00105110(p); }

MAGIC::MAGIC(void* v, void* o) {
    vm = v;
    obj = o;
    cost = 0;
    s_list.Append(this);
}

MAGIC::~MAGIC() {
    if (0.0f < cost) func_001826c8(-cost);
    if (vm) {
        void* v = vm;
        func_0016cab8(v);
        func_0016c7d8(v);
    }
    s_list.Remove(this);
}

}  // namespace YS

extern "C" {

// The magic task: deletes the magics whose VM has ended.
void func_001a5db8(TASK*) {
    extern u32 D_0034f240 asm("D_0034f240");
    if (D_0034f240 & 0x20) return;
    MAGIC* p = s_list.head;
    if (!p) return;
    do {
        MAGIC* next = p->next;
        extern s32 func_0016cd48(void*, s32);
        if (func_0016cd48(p->vm, 0) == 1) delete p;
        p = next;
    } while (p);
}

}  // extern "C"

namespace YS {

void MAGIC::ClearAll(void) {
    MAGIC* n = s_list.head;
    if (n) {
        do {
            MAGIC* next = n->next;
            delete n;
            n = next;
        } while (n);
    }
    for (s32 i = 0; i < 6; i++) {
        if (*(u32*)D_00350800[i].pax.d) func_001de450(&D_00350800[i].pax);
    }
}

void MAGIC::Finalizer(TASK*) {
    ClearAll();
    s32 i = 5;
    u32 off = 0;
    u32 base = (u32)&D_00350800;
    u32 base2 = base + 12;
    while (1) {
        u32 p = off + base;
        if (*(u32*)p != 0) {
            u32 q = off + base2;
            if (*(u32*)q != 0) {
                func_001dde40((ryj::PAX*)q);
            }
            func_00170950(*(u32*)p);
        }
        i -= 1;
        if (i < 0) {
            return;
        }
        off += 44;
    }
}

}  // namespace YS

extern "C" {

void func_001a5f50(void)
{
    t1a5f50_CreateTask(1, 0x5014, func_001a5db8)->fin = YS::MAGIC::Finalizer;
    Pair1a5f50* z = (Pair1a5f50*)&s_list;
    z->b = 0;
    z->a = 0;
    Ent1a5f50* base = (Ent1a5f50*)D_00350800;
    u8* pa = base->arg;
    Ent1a5f50* pc = base;
    Data1a5f50** pd = &base->data;
    Ent1a5f50* pr = base;
    Ent1a5f50* pe = base;
    for (s32 i = 0; i < 6; i++) {
        Data1a5f50* d = (Data1a5f50*)func_001a6658(i);
        if (d) {
            s32 c = t1a5f50_Alloc(d->name, -1);
            pc->cache = c;
            s32* e = pr->res;
            for (s32 k = 0; k < 2; k++) {
                Res1a5f50* r = func_00168b38(c, 3, k);
                e[k] = Has1a5f50(r) ? r->val : 0;
            }
            t1a5f50_001dddd0(pa, func_00168b38(c, 18, 0)->val);
        } else {
            pe->cache = 0;
        }
        *pd = d;
        pa += 44; pd = (Data1a5f50**)((u8*)pd + 44); pe++; pc++; pr++;
    }
}


void func_001a60c8(void)
{
    for (s32 i = 0; i < 6; i++) D_00350800[i].data = (W1626ScriptData*)func_001a6658(i);
    func_001bdff0();
}

MAGIC* func_001a6118(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 vm = func_0016cf00(a0, 0, a1, a2, a3);
    return new MAGIC((void*)vm, 0);
}

W1626Task* func_001a6178(W1626VObj* obj, s32 id, u8 alt)
{
    u32 args[4];
    W1626ScriptEntry* e = (W1626ScriptEntry*)D_00350800;
    W1626ScriptData* d = 0;
    s32 i;
    s32 base;
    s32 len;
    s8 se;
    W1626Task* t;

    for (i = 0; i < 6; i++, e++) {
        if (e->data != 0 && e->data->id == id) {
            d = e->data;
            break;
        }
    }
    if (W1626_get_ability(obj)->flags & 0x80000) {
        switch (d->type) {
        case 0: case 1: case 2: case 4:
            func_0017a600(obj);
            break;
        }
    }
    se = d->seA;
    base = d->lenUnit * 2;
    len = base - 2;
    if (func_0019c090(obj) != 0) {
        if ((obj->flags & 0x80) && obj->form == 7) {
            ((void (*)(W1626Sub*, W1626VObj*, f32))obj->sub->vt[3])(obj->sub, obj, D_00352130->blendSpecial);
        } else {
            ((void (*)(W1626Sub*, W1626VObj*, f32))obj->sub->vt[3])(obj->sub, obj, D_00352130->blendNormal);
        }
        W1626_motion_set(obj->motion, d->motC, d->blendC, 0.0f);
        W1626_motion_push(obj->motion, 4, 8.0f, 0.0f, 0);
    } else {
        if (alt && d->motB >= 0) {
            len = base - 1;
            W1626_motion_set(obj->motion, d->motB, d->blendB, 0.0f);
            se = d->seB;
        } else {
            W1626_motion_set(obj->motion, d->motA, d->blendA, 0.0f);
        }
        W1626_motion_push(obj->motion, 0, 0.0f, 0.0f, 0);
    }
    if (obj->target == obj) {
        se = d->seC;
    }
    if (se >= 0) {
        ((void (*)(W1626VObj*, s32, s32))obj->vt->f[21])(obj, se, 0);
    }
    if (obj->flags & 0x80) {
        switch (obj->form) {
        case 2: len += 10; break;
        case 5: len += 30; break;
        case 4: len += 20; break;
        }
    }
    t = (W1626Task*)new (W1626_area_alloc(16)) YS::MAGIC((void*)W1626_vm_start(e->script, obj), obj);
    args[0] = (u32)obj;
    args[1] = (u32)e->arg0c;
    args[2] = len;
    args[3] = func_001ce350(len);
    W1626_vm_call(t->vm, 20, args, 4);
    return t;
}

void func_001a6440(MAGIC* p) {
    if (*(u32*)((u8*)p->obj + 1416) & 4) func_00177998(p->obj);
    func_0016cbc8(p->vm, 21, 0, 0);
}

void func_001a6490(f32 cost, MAGIC* p) {
    if (!(0.0f < cost)) return;
    p->cost = cost;
    func_001826c8(cost);
}

}  // extern "C"

namespace YS {

void MAGIC::Read(void) {
    s32 i = 0;
    do {
        W261En* p = func_001a6658(i);
        i += 1;
        if (p) func_00170518((char*)p + 4, 0x3f2, 0);
    } while (i < 6);
}

void MAGIC::MpDriveEnable(s32 a) {
    D_0032f274[(u32)a >> 5] &= ~(1 << (a & 31));
}

void MAGIC::MpDriveDisable(s32 a) {
    func_001a6598(a);
    D_0032f274[(u32)a >> 5] |= 1 << (a & 31);
}

u8 MAGIC::GetMpDriveStatus(s32 a) {
    u8* p = func_001b8e88(func_001a67b0(a));
    u32 mask = 1u << (a & 0x1f);
    if (p[28] >= 255) return 2;
    return (D_0032f274[(u32)a >> 5] & mask) == 0;
}

bool MAGIC::CanAddCost(f32 f) {
    return f <= func_001826e0() + 2.0f;
}

void MAGIC::SysInit(void* t) {
    s_table = (W261Tb*)t;
}

}  // namespace YS

extern "C" {

W261En* func_001a6658(s32 id) {
    W261En* e = W261Find(id);
    W261En* best = e;
    if (!e) return 0;
    s32 lv = 0;
    if (e->req) {
        lv = func_001a3570(e->req);
        if (!lv) return 0;
    }
    W261Tb* t = D_01c6cb28;
    W261En* end = &t->e[t->n];
    u8 k = D_0032bae0;
    W261En* p = e + 1;
    while (p < end && p->id == best->id && p->lv <= lv) {
        if (p->kind == 0 || p->kind == k) best = p;
        p++;
    }
    return best;
}

u8 func_001a6780(s32 i) {
    W1626ScriptData* d = D_00350800[i].data;
    if (!d) return 0;
    return d->lenUnit;
}

}  // extern "C"

namespace YS {

u16 MAGIC::GetCommand(s32 i) {
    W1626ScriptData* d = D_00350800[i].data;
    if (!d) return 0;
    return d->id;
}

void MAGIC::Delete(MAGIC* n) {
    if (!n) return;
    MAGIC* it = 0;
    while ((it = it ? it->next : s_list.head) != 0) {
        if (it == n) break;
    }
    delete n;
}

}  // namespace YS

extern "C" {

u32 func_001a6850(void) {
    for (MAGIC* n = s_list.head; n; n = n->next) {
        u8* o = (u8*)n->vm;
        if (*(u32*)(o + 28) & 4) continue;
        u8* a = *(u8**)(o + 56);
        if (!func_0019ba60(a)) continue;
        u32 fl = *(u32*)(a + 1416);
        if (!(fl & 0x4000)) continue;
        if (!(fl & 0x400000)) return 1;
    }
    return 0;
}

}  // extern "C"
