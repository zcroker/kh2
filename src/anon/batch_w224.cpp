#include "../common/types.h"
extern "C" {
extern u32 func_002ff1a4(u32, u32);
u32 ctarget_00187ab8(u32* t, u32 b, u32 c, u32 d) asm("_Z16ctarget_00187ab8jjjj");
u32 ctarget_00187ab8(u32* t, u32 b, u32 c, u32 d) {
  u32 r = 0;
  if (t) {
    u32* p = t;
    for (int i = 0; i < 128; i++, p += 8) {
      r = *p;
      if (r && !func_002ff1a4(b, r)) { r = (u32)p; goto out; }
    }
    r = 0;
  }
out:
  return r;
}
}
