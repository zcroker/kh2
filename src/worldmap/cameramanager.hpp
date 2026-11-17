#pragma once

#include "../common/types.h"

struct TASK;

namespace worldmap {

// A camera as the manager sees it: vtable slot 1 deletes it, slot 2 updates it and
// returns nonzero while it stays active.
struct ManagedCamera {
    s32 (**vt)(ManagedCamera*);
};

// One static instance (0x1e2bda0). The first four words are the task parameters that
// func_002ef8d0 reads (flag, priority, task function, task handle).
class CameraManager {
public:
    CameraManager();
    void clear();
    void removeAll();
    ManagedCamera* getCamera(s32 i);
    static void* get();
    void set(s32 i, ManagedCamera* cam);
    void remove(s32 i);
    s32 update();

private:
    s32 m_flag;
    s32 m_priority;
    void (*m_exec)(TASK*);
    TASK* m_task;
    ManagedCamera* m_cam[3];
    ManagedCamera* m_current;
};

}  // namespace worldmap
