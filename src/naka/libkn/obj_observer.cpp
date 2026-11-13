// kn::ObjObserver (0x1357c8-0x135d78): a list of up to 32 objects that a Friend watches.
// Every observer is on one global list; Update() drops the dead objects from each of them.
#include "../../common/types.h"

struct AREA {
    static void* Alloc(u32 size);
    static void Free(void* p);
};
extern "C" s32 func_0019ba60(u32);

namespace kn {

class ObjObserver {
public:
    ObjObserver** owner;
    ObjObserver* next;
    s32 entryNum;
    u32 array[32];

    ObjObserver();
    virtual ~ObjObserver();

    static void Init();
    static void Update();
    static void Replace(u32 a, u32 b);
    static void Create(ObjObserver** p);
    void clear();
    void update();
    void addEntry(u32 v);
    void removeEntry(u32 v);
    s32 getEntryNum();
    s32 getIndex(u32 v);
    void replaceEntry(u32 a, u32 b);
    u32 getEntry(s32 i);

    static ObjObserver* top;

    static void* operator new(unsigned int n) { return AREA::Alloc(n); }
    static void operator delete(void* p) { AREA::Free(p); }
};

ObjObserver* ObjObserver::top;

void ObjObserver::Init() { top = 0; }

void ObjObserver::Update() {
    for (ObjObserver* p = top; p; p = p->next) p->update();
}

void ObjObserver::Replace(u32 a, u32 b) {
    for (ObjObserver* p = top; p; p = p->next) p->replaceEntry(a, b);
}

void ObjObserver::Create(ObjObserver** p) {
    ObjObserver* o = new ObjObserver;
    o->owner = p;
    *p = o;
}

ObjObserver::ObjObserver() {
    clear();
    next = top;
    top = this;
}

ObjObserver::~ObjObserver() {
    ObjObserver* prev = 0;
    for (ObjObserver* p = top; p && p != this; p = p->next) prev = p;
    if (prev) prev->next = next;
    else top = next;
    if (*owner == this) *owner = 0;
}

void ObjObserver::clear() {
    entryNum = 0;
    u32 i = 31;
    u32* p = array;
    do {
        *p++ = 0;
    } while ((s32)--i >= 0);
}

void ObjObserver::update() {
    u32 tmp[32];
    s32 n = 0;
    s32 i;
    for (i = 0; i < entryNum; i++) {
        if (array[i] && func_0019ba60(array[i]))
            tmp[n++] = array[i];
    }
    for (i = 0; i < n; i++) array[i] = tmp[i];
    for (; i < 32; i++) array[i] = 0;
    entryNum = n;
}

void ObjObserver::addEntry(u32 v) {
    removeEntry(v);
    s32 n = entryNum;
    if (n == 32) {
        update();
        if (entryNum == n) removeEntry(array[0]);
    }
    array[entryNum++] = v;
}

void ObjObserver::removeEntry(u32 v) {
    replaceEntry(v, 0);
    update();
}

s32 ObjObserver::getEntryNum() { return entryNum; }

s32 ObjObserver::getIndex(u32 v) {
    for (s32 i = 0; i < entryNum; i++) {
        if (array[i] == v) return i;
    }
    return -1;
}

void ObjObserver::replaceEntry(u32 a, u32 b) {
    for (s32 i = 0; i < entryNum; i++) {
        if (array[i] == a) { array[i] = b; return; }
    }
}

u32 ObjObserver::getEntry(s32 i) {
    s32 n = entryNum;
    if (n == 0) return 0;
    while (i < 0) i += n;
    while (i >= n) i -= n;
    return array[i];
}

}  // namespace kn
