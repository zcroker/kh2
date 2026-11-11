#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"

class OBJ;

namespace YS {

    // An item's effect on an object: runs for 30 frames, then gives the item to the target.
    class ITEM_EFFECT {
    public:
        f32 time;            // 0
        u32 id;              // 4: item id (0: done)
        OBJ* obj;            // 8
        s32 kind;            // 12
        u32 target;          // 16
        ITEM_EFFECT* next;   // 20

        ITEM_EFFECT(OBJ* o, u32 item, u32 tgt);
        ~ITEM_EFFECT();
        void use(void);
        s32 exec(void);
        void hit(u32 item, u32 tgt);
        void end(void);
        static void Cast(OBJ* a0);
        static void Exec(TASK* a0);
        static void Init(void);
        static void ClearAll(void);
        static void* operator new(u32 n);
        static void operator delete(void* p);
    };

}  // namespace YS

// The intrusive list of active effects (next pointer in the element).
template <class T> struct LIST {
    T* head;
    T* tail;
    LIST() { tail = 0; head = 0; }
    void Append(T* n) {
        if (!tail) { tail = n; head = n; n->next = 0; }
        else { tail->next = n; n->next = 0; tail = n; }
    }
    void Remove(T* p) {
        T* prev;
        if (p == head) { head = p->next; prev = 0; }
        else { prev = head; while (prev->next != p) prev = prev->next; prev->next = p->next; }
        if (p == tail) tail = prev;
        p->next = 0;
    }
};
