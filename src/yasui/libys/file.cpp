#include "file.hpp"

// YS::FILE (0x168218-0x168aa0): the file loader. Requests (read, read part, read bar, load overlay)
// go on one list; a worker thread reads them from the disc one at a time, and a task calls each
// request's callback when its read is done, then frees it.

struct TASK;

// The allocator object (0x32b91c): vtable slot 0 allocates, slot 1 frees.
struct ALLOC;
struct ALLOC_VT {
    void* (*Alloc)(ALLOC*, u32, void*);
    void (*Free)(ALLOC*, void*);
};
struct ALLOC { ALLOC_VT* vt; };

extern "C" {
extern ALLOC* D_0032b91c;
extern u8 D_01f18000[];
extern u8 D_01fc0000[];
void DIntr(void);
void EIntr(void);
void func_003058a0(s32);         // FlushCache
u32 func_001ae1e0(const char*);
u32 func_001adf00(const char*, void*);
u32 func_001ae0a0(const char*, void*, u32, u32);
u32 func_001ae4b8(void);
void func_00168be8(void*);
void func_002fde18(void*, s32, u32);  // memset
void func_01f1801c(void);
void func_0014d358(void*, u32, void (*)(void), u32);
void func_0014d430(void);
void func_00102788(ALLOC*, u32, u32, void (*)(TASK*));
void func_001adcf8(s32);
void func_001adea8(void*);
u32 func_001ae1b0(const char*);
u32 func_002ff3fc(const char*);       // strlen
void func_002ff2e8(char*, const char*);  // strcpy
void* func_001ae6a8(void);
void func_001ae788(void*);
u32 func_001ae7d0(void*, void*, u32);
void func_001ae8d8(void*, u32, u32, u32, u32);
}

typedef void (*REQ_CB)(void*, u32, u32);

// One request (76 bytes).
struct REQ {
    REQ* next;       // 0
    s32 state;       // 4: 0 waiting, 1 reading, 2 done
    char name[40];   // 8
    s32 mode;        // 48: 0 read, 1 read bar, 2 overlay
    void* buf;       // 52
    REQ_CB cb;       // 56
    u32 arg;         // 60
    u32 size;        // 64: bytes read
    u32 ofs;         // 68
    u16 pad72;
    u16 n;           // 74: sectors to read (0: whole file)
    REQ(u32 m, const char* s);
    static void* operator new(u32 sz, void* ra) { return D_0032b91c->vt->Alloc(D_0032b91c, sz, ra); }
};

struct REQ_LIST {
    REQ* head;
    REQ* tail;
    REQ_LIST() { tail = 0; head = 0; }
    REQ* Next(REQ* p) { if (!p) return head; return p->next; }
};

struct DRIVE { u32 a, b, c, d; };

extern "C" {
DRIVE D_0034d800[4] = {};
}
REQ_LIST D_0034d840;
#define s_list D_0034d840
static u8 s_stack[0x1000] __attribute__((aligned(16)));

extern "C" {

// The waiting request with the lowest disc position.
REQ* func_00168218(void) {
    REQ* best = 0;
    REQ* n = 0;
    u32 bestv = -1;
    DIntr();
    while ((n = s_list.Next(n))) {
        u32 v = func_001ae1e0(n->name);
        if (n->state) continue;
        if (best == 0 || v < bestv) { bestv = v; best = n; }
    }
    EIntr();
    return best;
}

u32 func_001682b8(const char* name, void* buf) {
    u32 r = func_001adf00(name, buf);
    func_003058a0(0);
    return r;
}

u32 func_001682f0(const char* name, void* buf, u32 ofs, u16 n) {
    u32 r = func_001ae0a0(name, buf, ofs, n);
    func_003058a0(0);
    return r;
}

}  // extern "C"

namespace YS {

u32 FILE::ReadBar(const char* name, void* buf) {
    u32 r = func_001682b8(name, buf);
    if (r) func_00168be8(buf);
    return r;
}

}  // namespace YS

extern "C" {

u32 func_00168370(void) {
    return func_001ae4b8();
}

void func_00168388(const char* name, void* buf, REQ_CB cb, u32 arg) {
    REQ* r = new (__builtin_return_address(0)) REQ(0, name);
    r->buf = buf;
    r->cb = cb;
    r->arg = arg;
}

void func_00168410(const char* name, void* buf, u32 ofs, u16 n, REQ_CB cb, u32 arg) {
    REQ* r = new (__builtin_return_address(0)) REQ(0, name);
    r->buf = buf;
    r->cb = cb;
    r->arg = arg;
    r->ofs = ofs;
    r->n = n;
}

void func_001684c0(const char* name, void* buf, REQ_CB cb, u32 arg) {
    REQ* r = new (__builtin_return_address(0)) REQ(1, name);
    r->buf = buf;
    r->cb = cb;
    r->arg = arg;
}

void func_00168548(const char* name, REQ_CB cb, u32 arg) {
    func_002fde18(D_01f18000, 0, D_01fc0000 - D_01f18000);
    REQ* r = new (__builtin_return_address(0)) REQ(2, name);
    r->buf = D_01f18000;
    r->cb = cb;
    r->arg = arg;
}

// The reader thread.
void func_001685f0(void) {
    for (;;) {
        func_003058a0(0);
        REQ* j;
        while ((j = func_00168218()) != 0) {
            j->state = 1;
            if (j->n) j->size = func_001682f0(j->name, j->buf, j->ofs, j->n);
            else j->size = func_001682b8(j->name, j->buf);
            j->state = 2;
        }
        func_0014d430();
    }
}

// The task: runs the callbacks of the finished requests and frees them.
void func_00168678(TASK*) {
    REQ* p = s_list.head;
    while (p) {
        REQ* next = p->next;
        if (p->state == 2) {
            func_003058a0(0);
            switch (p->mode) {
            case 0:
                if (p->cb) p->cb(p->buf, p->size, p->arg);
                break;
            case 1:
                if (p->size) func_00168be8(p->buf);
                else p->buf = 0;
                if (p->cb) p->cb(p->buf, p->size, p->arg);
                break;
            case 2:
                func_003058a0(2);
                func_01f1801c();
                if (p->cb) ((void (*)(u32))p->cb)(p->arg);
                break;
            }
            REQ* prev;
            if (p == s_list.head) {
                s_list.head = p->next;
                prev = 0;
            } else {
                prev = s_list.head;
                while (prev->next != p) prev = prev->next;
                prev->next = p->next;
            }
            if (p == s_list.tail) s_list.tail = prev;
            p->next = 0;
            D_0032b91c->vt->Free(D_0032b91c, p);
        }
        p = next;
    }
}

void func_00168808(s32 a) {
    if (a == -1) {
        func_0014d358(s_stack, 4096, func_001685f0, 0);
        func_00102788(D_0032b91c, 0, 0x61a80, func_00168678);
        for (s32 i = 0; i < 4; i++) D_0034d800[i].c = 0;
    }
    func_001adcf8(a);
}

void func_001688a0(void* bd) {
    func_001adea8(bd);
}

}  // extern "C"

namespace YS {

u32 FILE::IsReading(void) {
    return s_list.head != 0;
}

u32 FILE::GetSize(const char* name) {
    return func_001ae1b0(name);
}

}  // namespace YS

REQ::REQ(u32 m, const char* s) {
    mode = m;
    state = 0;
    ofs = 0;
    n = 0;
    func_002ff3fc(s);
    func_002ff2e8(name, s);
    if (!s_list.head) {
        s_list.tail = this;
        s_list.head = this;
        next = 0;
    } else {
        next = s_list.head;
        s_list.head = this;
    }
}

extern "C" {

void* func_001689d0(void) { return func_001ae6a8(); }
void func_001689e8(void* p) { func_001ae788(p); }
u32 func_00168a00(void* p, void* buf, u32 size) { return func_001ae7d0(p, buf, size); }
void func_00168a18(void* p, u32 buf, u32 size, u32 a, u32 e) { func_001ae8d8(p, buf, size, a, e); }

void func_00168a30(void) {
    for (REQ* p = 0; (p = s_list.Next(p)); ) {
    }
}

}  // extern "C"
