#include "./types.h"

// AREA (0x104910-0x105400): the current world/area/entrance, the map jump task and thread,
// and the area heap. The file's static initialiser (0x105400, it clears the five AREA objects
// through a pointer to their id triple) and its _GLOBAL__I_ stub stay separate functions: gcc
// folds that pointer arithmetic, so the AREA objects are plain data here.

struct TASK;

class AREA {
public:
    u8 world;      // 0
    u8 area;       // 1
    u8 entrance;   // 2
    u8 pad3;
    u16 layout;    // 4
    u16 event;     // 6
    u16 btl;       // 8

    void init(u32 v) {
        world = v;
        area = v;
        entrance = v;
        layout = v;
        event = v;
        btl = v;
    }

    void start();
    char* get_area_name(char* buf) const;
    bool is_same_area(const AREA* a) const;
    static void MapJumpTask(TASK* task);
    static void* GetAllocator();
    static void* Alloc(u32 size);
    static void Free(void* p);
    static bool IsMapJumpExec();
    static void DestroyAllocator();
};

// The map jump task (created by MapJump).
struct MAPJUMP_TASK {
    u32 f0;
    s32 counter;   // 4: frames to wait
    u8 flag8;      // 8
    u32 id;        // 12
    u32 snd;       // 16
};

struct Jumper {
    u32 f0;
    AREA dest;
    u8 pad14[18];
    u32 f32;
    u8 pad36[12];
};

struct Allocator {
    struct VT {
        void* (*alloc)(Allocator*, u32, void*);
        void (*free)(Allocator*, void*);
    }* vt;
};

u8 D_0032bad8;                // 1 while an area runs
AREA D_0032bae0;              // current area
AREA D_0032baf0;              // next area
AREA D_0032bb00;
AREA D_0032bb10;
Allocator* D_0032bb1c;        // area heap
MAPJUMP_TASK* volatile D_0032bb20;

static u8 D_003a7b00;         // a map jump happens inside the thread
static AREA D_003a7b08;

extern "C" {
extern u8 D_0032bb30[];       // SAVERAM
extern u32 D_0032b968[];
extern u32 D_0032b96c;
extern s32 D_0034ecd0;
extern s32 D_0034ecd4;
extern u32 D_0034ecec;
extern u32 D_0034ecf0;
extern u64 D_0034ecc0;
extern char D_00351ec8[];

void func_001021f0(void);
void func_001cd168(void);
u32 func_0014ac08(void);
u32 func_0014abb8(void);
u32 func_0014abc8(void);
u32 func_0014abd8(void);
u32 func_0014abe8(void);
u32 func_0014abf8(void);
u32 func_0014aba8(void);
void func_0014aa80(u32, s32, s32);
void func_001de7d8(void*, u32, u32);
void func_001e06b8(void);
void func_00149c40(u64);
void func_00169210(void);
void func_00108068(void);
void func_00149cb8(void);
void func_00226a78(void);
void func_00136fa8(void);
void func_0013f0d0(void);
void func_001bb438(void);
void func_0019ef70(Jumper*);
void func_0019f070(Jumper*, s32);
void func_0014ce60(void);
void func_00109140(void);
void func_00169030(TASK*);
void func_0016fa98(s32, u32);
s32 func_001a84f0(void);
s32 func_001a8510(Jumper*);
void func_001382b8(s32);
void func_00102448(TASK*, s32);  // Tz::TaskYield
void func_00102688(u32, s32, s32);
void func_001de910(void);
void func_00182d80(void);
s32 func_002283b0(void);
void func_002b9f28(s32);
void func_00149ca0(void);
void func_001366b8(TASK*);
void func_00136fd0(void);
void func_00169148(TASK*);
void func_0013a8f8(void);
void func_00149c08(void);
s32 func_0013a9f8(void);
void func_001de7b0(s32);
void func_00169178(void);
void func_00170888(TASK*);
void func_00136878(void);
void func_00136d40(TASK*);
s32 func_0013ef80(void);
void func_00102c18(s32, s32, void (*)(TASK*));
void func_001024a8(TASK*);
void func_00102818(u32, s32, s32, void (*)(TASK*), s32);
void func_00167ea8(void);
void func_00169308(void);
void func_00108080(void);
void func_00149db8(void);
void func_00169350(void);
void func_00149ec0(AREA*);
void func_0013a958(AREA*);
void func_00181ba0(void);
void func_0013f050(u32);
s32 func_00103b38(void);
s32 func_002ee530(void);
void func_001ada38(u32);
void func_001cd388(void);
MAPJUMP_TASK* func_00102788(u32, u32, u32, void (*)(TASK*));
void func_001c8d80(char*, s32);
const char* func_00105ee8(u32);
s32 func_002fee78(char*, const char*, ...);
s32 strlen(const char*);
s32 func_001d50b8(AREA*, Jumper*);
s32 func_001d5a58(AREA*, Jumper*);
void* func_00106178(void*, u32);
u8* func_00170b30(u32);
void func_001091c8(void*, s32, u32);
void func_00109280(void*);
void func_00170c00(void*);
void func_00170320(s32);

void func_00104cc0(TASK* task);
void func_00104da0(AREA* a);
void func_00104e18(void);
void func_001050b8(void);
void func_001052a8(AREA* a);
s32 func_00105310(AREA* a, Jumper* j);
void func_00105370(u32 size, u32 a1);
}

void AREA::start() {
    D_0032bad8 = 1;
    func_001021f0();
    func_001cd168();
    func_0014aa80(func_0014ac08(), 0, 0);
    func_0014aa80(func_0014abb8(), 0, 0);
    func_0014aa80(func_0014abc8(), 0, 0);
    func_0014aa80(func_0014abe8(), 0, 0);
    func_0014aa80(func_0014abf8(), 0, 0);
    func_0014aa80(func_0014abd8(), 0, 0);
    func_0014aa80(func_0014aba8(), 0, 0);
    func_001de7d8(GetAllocator(), D_0034ecec, D_0034ecf0);
    func_001e06b8();
    func_00149c40(D_0034ecc0);
    func_00169210();
    func_00108068();
    func_00149cb8();
    func_00226a78();
    func_00136fa8();
    func_0013f0d0();
    func_001bb438();
}

extern "C" {

// The area thread: loads each area the map jumps ask for, then starts the field.
void func_00104a48(TASK* task) {
    Jumper j;

    j.dest.init(0xffff);
    j.f32 = 0;
    func_0019ef70(&j);
    func_0014ce60();
    func_00109140();
    for (;;) {
        func_00169030(task);
        if (!func_00105310(&D_0032bae0, &j)) break;
        func_0016fa98(6, 0x8c0000);
        func_00105370(0x380000, 0x100000);
        func_001de7d8(D_0032bb1c, 0x80000, 0x20000);
        while (!func_001a84f0()) {
            func_001382b8(func_001a8510(&j));
            func_00102448(task, 0);
        }
        D_003a7b08 = D_0032bae0;
        D_003a7b00 = 1;
        asm volatile("");  // sched2 barrier: keeps move a1,zero after the sb, for the jal delay slot
        func_0019f070(&j, 0);
        func_00102448(task, 0);
        D_003a7b00 = 0;
        func_00102688(D_0032b968[1], 8, 8);
        func_001de910();
        AREA::DestroyAllocator();
        func_0016fa98(6, 0xc0000);
        func_00182d80();
        func_001052a8(&D_003a7b08);
    }
    func_00105370(D_0034ecd0 + D_0034ecd4, D_0034ecd4);
    func_0016fa98(6, 0xc0000);
    func_002b9f28(func_002283b0());
    func_00149ca0();
    func_001366b8(task);
    func_00136fd0();
    func_00169148(task);
    func_0013a8f8();
    func_00149c08();
    func_001de7b0(func_0013a9f8());
    func_00169178();
    func_00170888(task);
    func_00136878();
    func_00136d40(task);
    while (!func_0013ef80()) {
        func_00102448(task, 0);
    }
    func_00102c18(0, 1000, func_00104cc0);
}

void func_00104cc0(TASK* task) {
    D_0032bae0.start();
    func_001024a8(task);
}

// Copies the entries of s that are set (not 0xffff).
void func_00104cf0(u16* d, u16* s) {
    if (s[0] != 0xffff) d[0] = s[0];
    if (s[1] != 0xffff) d[1] = s[1];
    if (s[2] != 0xffff) d[2] = s[2];
}

struct Cell104d30 { u8 pad[16]; u16 x, y, z; };

// d = s, with the layout/event/battle set from the save data's table where s leaves them unset.
void func_00104d30(AREA* d, AREA* s) {
    d->world = s->world;
    d->entrance = s->entrance;
    d->area = s->area;
    Cell104d30* t = (Cell104d30*)(D_0032bb30 + d->world * 384 + d->area * 6);
    u16 x = t->x, y = t->y, z = t->z;
    d->layout = x;
    d->event = y;
    d->btl = z;
    func_00104cf0(&d->layout, &s->layout);
}

void func_00104da0(AREA* a) {
    D_003a7b00 = 0;
    func_001052a8(a);
    func_00102818(D_0032b96c, 1, 5000, func_00104a48, 0x2000);
}

void func_00104de0(u32 world, u32 area, u32 entrance) {
    struct {
        u8 world, area, entrance, pad;
        u16 layout, event, btl;
    } s;
    u32 m = 0xffff;
    s.world = world;
    s.area = area;
    s.entrance = entrance;
    s.layout = m;
    s.event = m;
    s.btl = m;
    func_00104da0((AREA*)&s);
}

void func_00104e18(void) {
    D_0032bad8 = 0;
    func_00167ea8();
    func_00169308();
    func_00108080();
    func_00149db8();
    func_00102688(D_0032b96c, 1, 1);
    func_00169350();
    func_00149ec0(&D_0032baf0);
    func_001de910();
    func_0013a958(&D_0032baf0);
    func_00181ba0();
    AREA::DestroyAllocator();
}

}

void AREA::MapJumpTask(TASK* t) {
    MAPJUMP_TASK* self = (MAPJUMP_TASK*)t;
    s32 n = self->counter;
    if (n > 0) {
        n -= 1;
        self->counter = n;
        if (n > 0) return;
        func_0013f050(self->id);
    }
    if (func_00103b38() != 0) return;
    if (func_002ee530() != 0) return;
    if (self->snd != 0) func_001ada38(self->snd);
    func_00104e18();
    if (self->flag8 != 0) {
        func_001cd388();
        D_0032bb10.world = 0xff;
    }
    func_00104da0(&D_0032baf0);
    func_001050b8();
    func_001024a8(t);
}

extern "C" {

void func_00104f58(const AREA* pos, u32 id, u32 mode, u8 flag, u32 snd) {
    if (D_003a7b00) {
        func_0013f050(id | 0x80000000);
        D_003a7b08 = *pos;
        if (snd) func_001ada38(snd);
        return;
    }
    func_00167ea8();
    MAPJUMP_TASK* t = func_00102788(D_0032b96c, 0, 0x493e0, AREA::MapJumpTask);
    D_0032bb20 = t;
    t->counter = mode;
    D_0032bb20->flag8 = flag;
    D_0032bb20->id = id;
    if (mode == 0) {
        D_0032bb20->snd = snd;
        func_0013f050(id);
    } else {
        func_001ada38(snd);
        D_0032bb20->snd = 0;
    }
    func_001c8d80(D_00351ec8, 2);
    D_0032baf0 = *pos;
}

void func_001050b8(void) {
    D_0032bb20 = 0;
}

}

void* AREA::GetAllocator() {
    return D_0032bb1c;
}

void* AREA::Alloc(u32 size) {
    return D_0032bb1c->vt->alloc(D_0032bb1c, size, __builtin_return_address(0));
}

void AREA::Free(void* p) {
    D_0032bb1c->vt->free(D_0032bb1c, p);
}

char* AREA::get_area_name(char* buf) const {
    static char s_name[8];
    if (buf == 0) buf = s_name;
    func_002fee78(buf, "%s%02d", func_00105ee8(world), area);
    return buf;
}

bool AREA::is_same_area(const AREA* a) const {
    return *(u16*)this == *(u16*)a;
}

extern "C" {

char* func_001051b8(AREA* p) {
    static char s_str[64];
    func_002fee78(s_str, "%s(%d) ", p->get_area_name(0), p->entrance);
    if (p->layout < 25 && p->event < 25 && p->btl < 25) {
        func_002fee78(s_str + strlen(s_str), "%c/%c/%c", p->layout + 97, p->event + 97, p->btl + 97);
    } else {
        func_002fee78(s_str + strlen(s_str), "%d/%d/%d", p->layout, p->event, p->btl);
    }
    return s_str;
}

void func_001052a8(AREA* a) {
    func_00104d30(&D_0032bae0, a);
    D_0032bb30[12] = D_0032bae0.world;
    D_0032bb30[13] = D_0032bae0.area;
    D_0032bb30[14] = D_0032bae0.entrance;
}

}

bool AREA::IsMapJumpExec() {
    return D_0032bb20 != 0;
}

extern "C" {

s32 func_00105310(AREA* a, Jumper* j) {
    s32 r = 0;
    if (func_001d50b8(a, j) || func_001d5a58(a, j)) r = 1;
    return r;
}

void func_00105370(u32 size, u32 a1) {
    void* h = func_00106178(func_00170b30(size), size);
    D_0032bb1c = (Allocator*)h;
    func_001091c8(h, 256, a1);
}

}

void AREA::DestroyAllocator() {
    func_00109280(D_0032bb1c);
    func_00170c00(D_0032bb1c);
    func_00170320(0);
    D_0032bb1c = 0;
}
