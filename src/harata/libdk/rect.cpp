#include "../../common/types.h"

// dk::RectBase GS register setters (0x14b5e0-0x14b638), the end of the rectangle file. The start
// of the file is src/anon/unit_0014b150.cpp; 0x14b518 between them stays a separate function.

// 14b5e0 .. 14b638: RectBase GS register setters
namespace dk {
struct RectBaseGsPrimLayout { char _pad0[192]; u64 gs_prim; };
struct RectBaseGsFrameLayout { char _pad0[64]; u64 gs_frame; };
struct RectBaseGsZbufLayout { char _pad0[80]; u64 gs_zbuf; };
struct RectBaseGsTestLayout { char _pad0[128]; u64 gs_test; };
struct RectBaseGsAlphaLayout { char _pad0[144]; u64 gs_alpha; };
struct RectBaseGsTex0Layout { char _pad0[96]; u64 gs_tex0; };
struct RectBaseGsTex1Layout { char _pad0[112]; u64 gs_tex1; };
class RectBase {
public:
    void setGsPrim(u64 v);
    void setGsUV(u64 a0, u64 a1);
    void setGsFrame(u64 v);
    void setGsZbuf(u64 v);
    void setGsTest(u64 v);
    void setGsAlpha(u64 v);
    void setGsTex0(u64 v);
    void setGsTex1(u64 v);
};
void RectBase::setGsPrim(u64 v) { reinterpret_cast<RectBaseGsPrimLayout*>(this)->gs_prim = v; }
void RectBase::setGsUV(u64 a0, u64 a1) {
    *(volatile u64 *)((u8 *)this + 208) = a0;
    *(volatile u64 *)((u8 *)this + 224) = a1;
}
// 14b5f8 (never written before): the second UV register pair
void func_0014b5f8(u8* p, u64 a0, u64 a1) asm("func_0014b5f8");
void func_0014b5f8(u8* p, u64 a0, u64 a1) {
    *(volatile u64 *)(p + 216) = a0;
    *(volatile u64 *)(p + 232) = a1;
}
void RectBase::setGsFrame(u64 v) { reinterpret_cast<RectBaseGsFrameLayout*>(this)->gs_frame = v; }
void RectBase::setGsZbuf(u64 v) { reinterpret_cast<RectBaseGsZbufLayout*>(this)->gs_zbuf = v; }
void RectBase::setGsTest(u64 v) { reinterpret_cast<RectBaseGsTestLayout*>(this)->gs_test = v; }
void RectBase::setGsAlpha(u64 v) { reinterpret_cast<RectBaseGsAlphaLayout*>(this)->gs_alpha = v; }
void RectBase::setGsTex0(u64 v) { reinterpret_cast<RectBaseGsTex0Layout*>(this)->gs_tex0 = v; }
void RectBase::setGsTex1(u64 v) { reinterpret_cast<RectBaseGsTex1Layout*>(this)->gs_tex1 = v; }
}  // namespace dk
