#include "../common/types.h"
#include "../yasui/libys/target.hpp"

// 0x1a6a10-0x1a7588: a small buffer cache (8 entries keyed by id), field object
// helpers, menu flag bits, and two window "job" tasks that hold a target object while
// a window is open (job data in s_job, its YS::TARGET built by the static init).

struct V4 {
    f32 x, y, z, w;
    V4() {}
    V4& operator=(const V4& o) {
        if (this != &o) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(this), "r"(&o) : "$8", "memory");
        return *this;
    }
    V4 operator-(const V4& o) const {
        V4 r;
        asm volatile("lqc2 $vf1, 0(%1)\n\tlqc2 $vf2, 0(%2)\n\tvsub.wxyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%0)" : : "r"(&r), "r"(this), "r"(&o) : "memory");
        return r;
    }
} __attribute__((aligned(16)));

struct JobTask { u32 f0; u32 p; };
struct WinMsg { u16 type; u16 pad; u32 arg; };
struct WinTask { u8 pad[16]; u32 task; };
struct CacheEnt { u32 key; u8* buf; };
union U1a6a20 { u8* p; u32 u; };
struct S20 { u32 w[5]; };
struct Job { u8* obj; YS::TARGET tgt; };
struct JobW { u32 b; S20 s; };

static CacheEnt s_cache[8] asm("D_01c6cb30");
static s32 s_count asm("D_01c6cb70");
// The job's object pointer and its target are two file statics; the code reaches both
// through a Job view of the pointer's address.
static u8* s_job_obj asm("D_01c6cb78") __attribute__((aligned(8)));
static YS::TARGET s_job_tgt asm("D_01c6cb7c") __attribute__((aligned(4)));
#define s_job (*(Job*)((u8*)&s_job_tgt - 4))

extern u32 D_0032dec0[] asm("D_0032dec0");
extern u32 D_0034f240 asm("D_0034f240");
extern u8 D_0034fa78 asm("D_0034fa78");
extern void* D_00350910[] asm("D_00350910");

void* f_alloc(u32) asm("func_001050d8");
void f_free(u32) asm("func_00105110");
void f_memclr(void*, u32) asm("func_002fd310");
void f_btlobj_ctor(u8*, u32, u32, u32) asm("func_001b3b70");
void* f_get_serial(void*) asm("_ZN2YS3OBJ10get_serialEv");
void f_history_set(void*, void*) asm("func_001956d0");
u8 f_history_test(void*, void*) asm("func_00195700");
void f_menuflag_changed(void) asm("func_001d59b0");
void f_pool_free(u32) asm("func_001b86e0");
u32 f_pool_alive(u32, u32, u32, u32) asm("func_001b84b8");
u32 f_pool_alloc(u32, u32) asm("func_001b8680");
u8* f_task_start(s32, s32, u32, s32) asm("func_00102c48");
u32 f_rec_copy(u32) asm("func_001c1130");
void f_rec_restore(u32) asm("func_001c11a8");
void f_lock(u32) asm("func_001b9c28");
void f_unlock(u32) asm("func_001b9c58");
void f_task_wait(u32, s32) asm("func_00102448");
u8 f_win_busy(void) asm("func_001b8e88");
u8 f_win_wait(u8*, u32) asm("func_0019c218");

// ---- buffer cache ----

void func_001a6a10() asm("func_001a6a10");
void func_001a6a10() {
    s_count = 0;
}

u8* func_001a6a20(u32 key, u32 n) asm("func_001a6a20");
u8* func_001a6a20(u32 key, u32 n) {
    s32 i;
    CacheEnt* e;
    u8* b;
    for (i = 0; i < s_count; i++) {
        if (s_cache[i].key == key) {
            s_cache[i].buf[0] = 1;
            return s_cache[i].buf;
        }
    }
    n++;
    b = (u8*)f_alloc(n);
    f_memclr(b, n);
    e = &s_cache[s_count++];
    e->key = key;
    ((U1a6a20*)&e->buf)->u = (u32)b;
    return b;
}

void u_tail0_001a6ae8(void) {
    for (s32 i = 0; i < s_count; i++) f_free((u32)s_cache[i].buf);
    s_count = 0;
}

// ---- two object constructors ----

struct B600 { u32 lo : 3; u32 m : 4; u32 rest : 25; };
void func_001a6b58(u8* p, u32 a, u32 b) asm("func_001a6b58");
void func_001a6b58(u8* p, u32 a, u32 b) {
    f_btlobj_ctor(p, a, 4, b);
    *(void**)p = D_00350910;
    *(u32*)(p + 1416) |= 0x100;
    *(u32*)(p + 944) = 3;
    ((B600*)(p + 1536))->m = 1;
    *(u32*)(p + 2748) |= 4;
}

void func_001a6bc8(u8* p, u32 a, u32 b) asm("func_001a6bc8");
void func_001a6bc8(u8* p, u32 a, u32 b) {
    f_btlobj_ctor(p, a, 4, b);
    *(void**)p = D_00350910;
    *(u32*)(p + 1416) |= 0x100;
    *(u32*)(p + 944) = 3;
    ((B600*)(p + 1536))->m = 1;
    *(u32*)(p + 2748) |= 4;
}

// ---- field object history ----

void FIELDOBJ_mark_history(void*) asm("_ZN2YS8FIELDOBJ12mark_historyEv");
void FIELDOBJ_mark_history(void* o) {
    f_history_set(&D_0034fa78, f_get_serial(o));
}

u32 FIELDOBJ_is_mark_history(void*) asm("_ZN2YS8FIELDOBJ15is_mark_historyEv");
u32 FIELDOBJ_is_mark_history(void* o) {
    return f_history_test(&D_0034fa78, f_get_serial(o));
}

// ---- menu flags ----

void func_001a6c90(u32 n) asm("func_001a6c90");
void func_001a6c90(u32 n) {
    D_0032dec0[n >> 5] |= 1 << (n & 31);
    f_menuflag_changed();
}

void MENUFLAG_Reset(u32) asm("_ZN2YS8MENUFLAG5ResetEi");
void MENUFLAG_Reset(u32 n) {
    D_0032dec0[n >> 5] &= ~(1 << (n & 31));
}

u32 MENUFLAG_Check(u32) asm("_ZN2YS8MENUFLAG5CheckEi");
u32 MENUFLAG_Check(u32 n) {
    u32 idx = n >> 5;
    u32* p = (u32*)((u32)&D_0032dec0 + (idx << 2));
    u32 bit = n & 31;
    u32 val = *p;
    u32 mask = 1u << bit;
    return (val & mask) != 0;
}

// ---- job pool handle ----

void func_001a6d38(u32 a0) asm("func_001a6d38");
void func_001a6d38(u32 a0) {
    u32 p = *(u32*)(a0 + 4);
    if (p != 0u) f_pool_free(p);
}

void func_001a6d68(u32 a0) asm("func_001a6d68");
void func_001a6d68(u32 a0) {
    u32 p = *(u32*)(a0 + 4);
    if (p != 0u) f_pool_free(p);
}

void func_001a6d98(u32 a0, u32 a1, u32 a2, u32 a3) {
    if (f_pool_alive(*(u32*)(a0 + 4), a1, a2, a3) == 0u) {
        f_pool_free(*(u32*)(a0 + 4));
        *(u32*)(a0 + 4) = 0;
    }
}

void f_job_poll(u32, u32) asm("_Z13func_001a6d98jjjj");
void func_001a6dd8(u32* p, u32 b, S20* src, u32 d, u32 e) asm("func_001a6dd8");
void func_001a6dd8(u32* p, u32 b, S20* src, u32 d, u32 e) {
    if (!p[1]) p[1] = f_pool_alloc(p[0], e);
    ((JobW*)&s_job_obj)->b = b;
    ((JobW*)&s_job_obj)->s = *src;
    *(u32**)(f_task_start(1, 15000, d, 4096) + 4) = p;
}

void func_001a6ef0(JobTask* t) asm("func_001a6ef0");
s32 func_001a6fe8(WinMsg* m, WinTask* t) asm("func_001a6fe8");
void func_001a6e88(u32 a0, u32 a1, u32 a2) asm("func_001a6e88");
void func_001a6e88(u32 a0, u32 a1, u32 a2) {
    f_rec_copy(12);
    f_lock(0);
    func_001a6dd8((u32*)a0, a1, (S20*)a2, (u32)&func_001a6ef0, (u32)&func_001a6fe8);
}

// ---- job 1: hold the target while a window is open ----

V4 f_tgt_pos(YS::TARGET*) asm("func_00190388");
V4* f_obj_pos(void*) asm("func_0016c028");
void f_obj_look(void*, const V4&) asm("func_0016b010");
void f_npc_before(void*) asm("func_0018b200");
void f_npc_after(void*) asm("_ZN2YS3NPC11after_checkEv");
u32 f_event_exec(void) asm("_ZN2YS5EVENT6IsExecEv");

void func_001a6ef0(JobTask* t) asm("func_001a6ef0");
void func_001a6ef0(JobTask* t) {
    u32 p = t->p;
    YS::TARGET* tg = &s_job_tgt;
    u8* o = (u8*)tg->m_obj;
    V4 pos;
    pos = f_tgt_pos(tg);
    f_obj_look(((u8**)tg)[-1], pos - *f_obj_pos(((u8**)tg)[-1]));
    if (*(u32*)(o + 1416) & 8) f_npc_before(o);
    f_job_poll(p, (u32)t);
    if (*(u32*)(o + 1416) & 8) f_npc_after(o);
    if (!f_event_exec()) {
        f_unlock(0);
        f_rec_restore(12);
    }
}

// ---- job 1: window message handler ----

void* w_Alloc(u32) asm("_ZN4AREA5AllocEj");
struct Win;
struct WinVt { void* f[8]; void (*Close)(Win*); };
struct Win { WinVt* vt; u8 pad[0x6c]; s32 state; u8 pad2[0xb6c - 0x74]; };
void w_WinObj2D(void*, Win*) asm("_ZN2YS12WINDOW_OBJ2DC1EPNS_6WINDOWE");
s32 f_win_wait_arg(s32) asm("func_001a74f8");
void f_win_open_a(Win*, u32) asm("func_001ad228");
void f_win_open_b(Win*, u32) asm("func_001ad4a8");
static inline bool w_IsOpen(Win* w) { return w->state != 3; }

s32 func_001a6fe8(WinMsg* m, WinTask* t) asm("func_001a6fe8");
s32 func_001a6fe8(WinMsg* m, WinTask* t) {
    u32 task = t->task;
    if (m->type == 1) {
        u32 arg = m->arg;
        Win* w = (Win*)w_Alloc(0xb6c);
        f_win_open_a(w, arg);
        w_WinObj2D(w_Alloc(0x1c), w);
        while (w_IsOpen(w) && f_win_wait_arg(14)) f_task_wait(task, 0);
        w->vt->Close(w);
    }
    return 1;
}

// ---- job 2: party members face the target while the window is open ----

void func_001a7108(JobTask* t) asm("func_001a7108");
s32 func_001a7440(WinMsg* m, WinTask* t) asm("func_001a7440");

void func_001a70a0(u32 a0, u32 a1, u32 a2) asm("func_001a70a0");
void func_001a70a0(u32 a0, u32 a1, u32 a2) {
    f_rec_copy(12);
    f_lock(0);
    func_001a6dd8((u32*)a0, a1, (S20*)a2, (u32)&func_001a7108, (u32)&func_001a7440);
}

u8* f_party_get(s32) asm("_ZN2YS5PARTY3GetEi");
void f_member_face(u8*, f32, f32, f32) asm("_Z13func_001ad990jfff");
u32 f_npc_check(void*) asm("func_0018b1d8");
void f_tgt_lock(YS::TARGET*, u32) asm("func_00159b40");
void f_tgt_unlock(void) asm("func_00159c20");
V4 f_obj_dir(void*) asm("func_0016af58");
void f_npc_face(void*, V4*, f32) asm("func_0018b288");
void f_npc_end(void*) asm("func_0018b338");
void f_obj_set_dir(void*, const V4&) asm("_ZN2YS3OBJ7set_dirERKN2kn7FVectorE");
void f_motion_set(u8*, s32, f32, f32) asm("_Z13func_0017f488iiff");
void f_texanm_start(void*, s32) asm("_ZN2YS3OBJ12texanm_startEi");
void f_texanm_stop(void*, s32) asm("_ZN2YS3OBJ11texanm_stopEi");

void func_001a7108(JobTask* t) {
    u32 p = t->p;
    u8* o = (u8*)s_job_tgt.m_obj;
    V4 pos;
    V4 dir;
    s32 i;
    u8* m;
    *(u32*)(*(u8**)(s_job_obj + 2880) + 44) |= 1;
    D_0034f240 |= 0x100;
    *(u32*)((u8*)s_job_tgt.m_obj + 264) |= 4;
    pos = f_tgt_pos(&((Job*)&s_job_obj)->tgt);
    f_obj_look(s_job_obj, pos - *f_obj_pos(s_job_obj));
    f_tgt_lock(&s_job_tgt, !(*(u32*)(o + 1416) & 8) || f_npc_check(o));
    for (i = 0; i < 3; i++) {
        m = f_party_get(i);
        if (m && !(*(u32*)(m + 2040) & 0x10)) f_member_face(m + 2092, 1.0f, 0.0f, 10.0f);
    }
    dir = f_obj_dir(o);
    if (*(u32*)(o + 1416) & 8) {
        f_npc_face(o, f_obj_pos(s_job_obj), 0.0f);
    } else {
        f_obj_set_dir(o, *f_obj_pos(s_job_obj) - *f_obj_pos(o));
    }
    f_motion_set(o + 320, 50, 0.0f, 0.0f);
    f_texanm_start(o, 33);
    f_job_poll(p, (u32)t);
    if (!f_event_exec()) {
        f_obj_set_dir(o, dir);
        f_texanm_stop(o, 33);
        if (*(u32*)(o + 1416) & 8) f_npc_end(o);
        else f_motion_set(o + 320, 0, 0.0f, 0.0f);
        f_tgt_unlock();
        f_task_wait((u32)t, 0);
        for (i = 0; i < 3; i++) {
            m = f_party_get(i);
            if (m && !(*(u32*)(m + 2040) & 0x10)) f_member_face(m + 2092, 0.0f, 1.0f, 10.0f);
        }
        f_unlock(0);
        *(u32*)(*(u8**)(s_job_obj + 2880) + 44) &= ~1;
        D_0034f240 &= ~0x100;
        *(u32*)((u8*)s_job_tgt.m_obj + 264) &= ~4;
        f_rec_restore(12);
    }
}

// ---- job 2: window message handler ----

s32 func_001a7440(WinMsg* m, WinTask* t) {
    u32 task = t->task;
    if (m->type == 1) {
        u32 arg = m->arg;
        Win* w = (Win*)w_Alloc(0xb6c);
        f_win_open_b(w, arg);
        w_WinObj2D(w_Alloc(0x1c), w);
        while (w_IsOpen(w) && f_win_wait_arg(10)) f_task_wait(task, 0);
        w->vt->Close(w);
    }
    return 1;
}

u8 func_001a74f8(void) asm("func_001a74f8");
u8 func_001a74f8(void) {
    u32 v = f_win_busy();
    *(u8**)(s_job.obj + 2480) = 0;
    return f_win_wait(s_job.obj, v);
}
