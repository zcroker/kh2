#include "../../common/types.h"

extern "C" void* func_0017aab8(int id);

namespace YS {

// One singleton per action ID (table at 0x34e9f8, filled by the static
// constructor at 0x17aad0). Vtable slot 0 is start(obj), slot 1 end(obj),
// slot 2 jump(obj, vec), slot 3 jump_height(obj, h).
class ActionState {
public:
    virtual void start(void* obj);
};

class ACTION {
public:
    enum ID {};
    void Get(ID id);

private:
    u8 pad[0xc];
    ActionState* current;
};

// Enters action `id`: runs its start() on this object and makes it current.
void ACTION::Get(ID id) {
    ActionState* a = (ActionState*)func_0017aab8(id);
    a->start(this);
    current = a;
}

}  // namespace YS
