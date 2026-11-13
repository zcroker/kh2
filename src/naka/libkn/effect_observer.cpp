// kn::EffectObserver (0x135d78-0x1363a0): a list of up to 32 effects (pointer + the effect's id
// when it was added) that an owner watches. Update() drops the effects that ended or were reused.
#include "../../common/types.h"

struct AREA {
    static void* Alloc(u32 size);
    static void Free(void* p);
};
class EFFECT;
extern "C" s32 func_001dca20(EFFECT*);
u32 func_001dc5f0(void*);

namespace kn {

struct EffectEntry {
    EFFECT* obj;
    u32 id;
};

class EffectObserver {
public:
    EffectObserver** owner;
    EffectObserver* next;
    s32 entryNum;
    EffectEntry array[32];

    EffectObserver();
    virtual ~EffectObserver();

    static void Init();
    static void Update();
    static void Create(EffectObserver** p);
    void clear();
    void update();
    void addEntry(EFFECT* e);
    void removeEntry(EFFECT* e);
    s32 getEntryNum();
    s32 getIndex(EFFECT* e);
    EFFECT* getEntry(s32 i);

    static EffectObserver* top;

    static void* operator new(unsigned int n) { return AREA::Alloc(n); }
    static void operator delete(void* p) { AREA::Free(p); }
};

EffectObserver* EffectObserver::top;

void EffectObserver::Init() { top = 0; }

void EffectObserver::Update() {
    for (EffectObserver* p = top; p; p = p->next) p->update();
}

void EffectObserver::Create(EffectObserver** p) {
    EffectObserver* o = new EffectObserver;
    o->owner = p;
    *p = o;
}

EffectObserver::EffectObserver() {
    clear();
    next = top;
    top = this;
}

EffectObserver::~EffectObserver() {
    EffectObserver* prev = 0;
    for (EffectObserver* p = top; p && p != this; p = p->next) prev = p;
    if (prev) prev->next = next;
    else top = next;
    if (*owner == this) *owner = 0;
}

void EffectObserver::clear() {
    s32 i;
    u8* p = (u8*)this;
    entryNum = 0;
    for (i = 31; i >= 0; i--) {
        *(u32*)(p + 16) = 0;
        *(u32*)(p + 20) = 0;
        p += 8;
    }
}

void EffectObserver::update() {
    EffectEntry tmp[32];
    s32 n = 0;
    s32 i;
    for (i = 0; i < entryNum; i++) {
        EFFECT* o = array[i].obj;
        u32 id = array[i].id;
        if (o && !func_001dca20(o) && func_001dc5f0(o) == id) {
            tmp[n] = array[i];
            n++;
        }
    }
    for (i = 0; i < n; i++) array[i] = tmp[i];
    for (; i < 32; i++) {
        array[i].obj = 0;
        array[i].id = 0;
    }
    entryNum = n;
}

void EffectObserver::addEntry(EFFECT* e) {
    if (!e) return;
    removeEntry(e);
    s32 n = entryNum;
    if (n == 32) {
        update();
        if (entryNum == n) removeEntry(array[0].obj);
    }
    array[entryNum].obj = e;
    s32 i = entryNum;
    array[i].id = func_001dc5f0(e);
    entryNum++;
}

void EffectObserver::removeEntry(EFFECT* e) {
    for (s32 i = 0; i < entryNum; i++) {
        if (array[i].obj == e && array[i].id == func_001dc5f0(e)) {
            array[i].obj = 0;
            array[i].id = 0;
            break;
        }
    }
    update();
}

s32 EffectObserver::getEntryNum() { return entryNum; }

s32 EffectObserver::getIndex(EFFECT* e) {
    s32 i;
    for (i = 0; i < entryNum; i++) {
        if (array[i].obj == e && array[i].id == func_001dc5f0(e)) return i;
    }
    return -1;
}

EFFECT* EffectObserver::getEntry(s32 i) {
    s32 n = entryNum;
    if (n == 0) return 0;
    while (i < 0) i += n;
    while (i >= n) i -= n;
    return array[i].obj;
}

}  // namespace kn
