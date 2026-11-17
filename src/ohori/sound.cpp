#include "../common/types.h"

namespace SOUND {
u32 isSeAlertPlay();
void SE3DDisable();
void SE3DEnable();
void seVoicePcmStop();
}

extern "C" void func_002b72e4(s32, s32, u32);
extern "C" void func_002baa60(void);
extern "C" u32 func_002b83b4(void);
extern "C" u32 func_002b70b8(u32, u32, u32, u32);
extern u8 D_003616f0;

namespace SOUND {

u32 isSeAlertPlay();  // 0x002ba358: definition moved into src/anon/unit_002b9ab8.cpp

// 0x002bc788 SE3DDisable, 0x002bc798 SE3DEnable: definitions moved into src/anon/unit_002bb8b0.cpp

void seVoicePcmStop();  // 0x002ba8e8: definition moved into src/anon/unit_002b9ab8.cpp

}  // namespace SOUND
