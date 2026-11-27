#include "menu.hpp"

namespace MENU {
void DestoryAllocator();
}

namespace Tz {
namespace CampMenu {
u32 StartJiminy(s32, s32);
}
namespace Jiminy {
void WMExit();
}
namespace MenuCursor {
void Exit();
}
namespace MenuItem {
void update();
}
namespace Select {
void End();
}
}

namespace YS {
namespace CACHE_BUFF {
void FixFree(void*);
}
}

namespace worldmap {
extern "C" u32 Tz__Jiminy__AreaWorld2JmWorld(u32);

// 0x002c24a8: definition moved into src/anon/unit_002c2228.cpp

// 0x002c2458: definition moved into src/anon/unit_002c2228.cpp
}  // namespace worldmap
