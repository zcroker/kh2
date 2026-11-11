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

#include "list.hpp"
