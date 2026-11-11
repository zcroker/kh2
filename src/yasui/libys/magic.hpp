#pragma once

#include "../../common/types.h"
#include "../../common/task.hpp"

namespace YS {

    // A magic being cast: its script VM and its object; on the list until the VM ends.
    class MAGIC {
    public:
        void* vm;        // 0
        void* obj;       // 4
        f32 cost;        // 8: MP to refund if cancelled
        MAGIC* next;     // 12

        MAGIC(void* v, void* o);
        ~MAGIC();
        static void ClearAll(void);
        static void Finalizer(TASK* a0);
        static void SysInit(void* a0);
        static void Read(void);
        static u16 GetCommand(s32 a0);
        static void MpDriveEnable(s32 a0);
        static u8 GetMpDriveStatus(s32 a0);
        static void MpDriveDisable(s32 a0);
        static bool CanAddCost(f32 a0);
        static void Delete(MAGIC* a0);
        static void* operator new(u32 n);
        static void* operator new(u32, void* p) { return p; }
        static void operator delete(void* p);
    };

}  // namespace YS

#include "list.hpp"
