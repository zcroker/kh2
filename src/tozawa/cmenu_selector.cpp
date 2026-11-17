#include "cmenu_selector.hpp"
#include "cmenu_slbase.hpp"
#include "menu_sound.hpp"
#include "../tz/ui_accessors.hpp"

namespace Tz {

extern u32 D_0035f3fc asm("D_0035f3fc");
extern u32 D_0035f3f8 asm("D_0035f3f8");
extern u32 D_0035f40c asm("D_0035f40c");
extern u32 D_0035f124 asm("D_0035f124");
extern u32 D_0035f304 asm("D_0035f304");
extern "C" void func_001396b0(...);
extern "C" void func_0028dac8(...);
// 0028d0c8: moved to src/anon/unit_0028c878.cpp

// 0028d0e0: moved to src/anon/unit_0028c878.cpp

// 0028cbf8: moved to src/anon/unit_0028c878.cpp

// 0028cf98: moved to src/anon/unit_0028c878.cpp

u32 Selector::SelExit() { return SelExitImpl(); }

void Selector::SetState(s32 v) { D_0035f304 = (u32)v; }

u32 Selector::GetState() { return D_0035f304; }

// 00290738: moved to src/anon/unit_0028f1e0.cpp

void Selector::SetupHelpGra() {
    u32 a;
    u32 b;
    GetHelpGraPos((u32)&a, (u32)&b);
    SetHelpGraMsg(D_0035f124, 30027);
    CreateHelpGra(D_0035f124, a, b, 0);
    MenuBase::NextModeToMode(1, 0);
    SetState(1);
}

void Selector::Control(TASK*) {
    u32 s0 = MenuCursor::GetInputState(0);
    u32 v = GetState();
    if (v == 2) {
        if (HelpGraDone(D_0035f124) == 0) {
            MenuBase::NextModeToMode(0, 0);
            SetState(1);
        }
        return;
    }
    u64 f = *(u64*)(s0 + 8);
    if ((f & 0xC) == 0) {
        return;
    }
    MenuSound::PlaySE(9, true);
    func_0028dac8(D_0035f124, 1);
    SetState(2);
}

void Selector::PauseThread(TASK* task) {
    u32 s0 = (u32)task;
    PauseTaskSetup(s0);
    TaskYield(s0, 1);
    PauseTaskBegin();
    while (1) {
        if (PauseTaskIsDone(s0) != 0) {
            return;
        }
        PauseTaskUpdate();
        TaskYield(s0, 0);
    }
}

}  // namespace Tz
