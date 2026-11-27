// Linked unit 0x00242478-0x00247ff0 (one namespace per old matched source; class methods in their own namespace).
#include "../common/types.h"
#include "../kn/fvector.hpp"
#include "./tiny_auto80_queue_structs.hpp"
#include "../yasui/libys/areadata.hpp"
#include "../yasui/libys/progress.hpp"
#include <stdarg.h>
#include "auto80_199_queue_decls.hpp"
#include "auto80_199_queue_structs.hpp"
#include "../harata/libdk/ft4.hpp"
#include "../harata/libdk/sprite.hpp"
#include "../harata/libdk/treasure_info.hpp"
#include "../tozawa/cmenu_top.hpp"
#include "../tozawa/help_gra.hpp"
#include "../tozawa/munny.hpp"
#include "tiny_auto80_solver_structs.hpp"
#include "../tozawa/menu_sound.hpp"
#include "../tozawa/config.hpp"
#include "../tozawa/sub_menu.hpp"
#include "../tozawa/smenu_he.hpp"
#include "../tozawa/smenu_heco.hpp"

// 00242478 (was src/anon/tiny_jal_wrappers_flex.cpp)
namespace n00242478 {
u32 getSaveRam(u32, u32, u32, u32) asm("_Z10getSaveRamv");
/*TARGET 00242478*/
u32 func_00242478(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00242478jjjj");
u32 func_00242478(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u, r16 = 0u;
    r16 = r4;
    r2 = getSaveRam(r4, r5, r6, r7);
    *(u32*)((u32)r2 + (s32)(9280)) = r16;
    return r2;
}
}  // namespace n00242478

// 002424a0 (was src/tozawa/munny.cpp)
namespace Tz { // method 002424a0
u32 getSaveRam() asm("_Z10getSaveRamv");
/*TARGET 002424a0*/
u32 Munny::Get() {
    u32 p = getSaveRam();
    return *(u32*)((u32)p + 9280);
}
}  // Tz

// 002424c0 (was src/anon/batch_w16.cpp)
namespace n002424c0 {
u8* func_001058e8(void) asm("func_001058e8");
/*TARGET 002424c0*/
// Whether adding a to the counter stays within 999999.
u32 func_002424c0(u32 a) asm("func_002424c0");
// Whether adding a to the counter stays within 999999.
u32 func_002424c0(u32 a) {
    return *(u32*)(func_001058e8() + 9280) + a <= 999999;
}
}  // namespace n002424c0

// 00242500 (was src/anon/batch_w43.cpp)
namespace n00242500 {
s32 func_002424c0(u32) asm("func_002424c0");
u8* func_001058e8(void) asm("func_001058e8");
/*TARGET 00242500*/
u32 Munny_Add(u32 n) asm("_ZN2Tz5Munny3AddEj");
u32 Munny_Add(u32 n) {
    if (func_002424c0(n)) *(u32*)(func_001058e8() + 9280) += n;
    else *(u32*)(func_001058e8() + 9280) = 999999;
    return *(u32*)(func_001058e8() + 9280);
}
}  // namespace n00242500

// 00242560 (was src/anon/tiny_auto80_solver.cpp)
namespace n00242560 {
u32 func_001058e8(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_001058e8jjjjjjjj");
// crc_byte_update
u32 func_00242560(u32, u32, u32, u32, u32, u32, u32, u32) asm("_Z13func_00242560jjjjjjjj");
/*TARGET 00242560*/
u32 func_00242560(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00242560jjjjjjjj");
u32 func_00242560(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r16;
    r16 = r4;
    r2 = ((u32(*)(u32,u32,u32,u32,u32,u32,u32,u32))func_001058e8)(r4, r5, r6, r7, r8, r9, r10, r11);
    r2 = *(u32*)((u32)r2 + (s32)(9280));
    return !((u32)r2 < (u32)r16);
}
}  // namespace n00242560

// 00242590 (was src/anon/tiny_auto80_solver.cpp)
namespace n00242590 {
u8* func_001058e8(void) asm("func_001058e8");
s32 func_00242560(u32) asm("_Z13func_00242560jjjjjjjj");
/*TARGET 00242590*/
u32 func_00242590(u32 n) asm("_Z13func_00242590jjjjjjjj");
u32 func_00242590(u32 n) {
    func_00242560(n);
    *(u32*)(func_001058e8() + 9280) -= n;
    return *(u32*)(func_001058e8() + 9280);
}
}  // namespace n00242590

// 002425d0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002425d0 {
extern u16 D_0035ecc8 asm("D_0035ecc8");
extern u8  D_003717e8 asm("D_003717e8");
/*TARGET 002425d0*/
void func_002425d0(u32 a0) asm("_Z13func_002425d0j");
void func_002425d0(u32 a0) {
    a0 = a0 * 12;
    u16* t6 = &D_0035ecc8;
    s32 t5 = 5;
    u16* t7 = (u16*)((u8*)&D_003717e8 + a0);
    do {
        u16 v = *t7;
        t5 -= 1;
        *t6 = v;
        t7 += 1;
        t6 += 1;
    } while (t5 >= 0);
}
}  // namespace n002425d0

// 00242618 (was src/tozawa/menu_sound.cpp)
namespace Tz { // method 00242618
extern void SOUND_systemSePlay(s32, s32) asm("_ZN5SOUND12systemSePlayEii");
/*TARGET 00242618*/
u32 MenuSound::PlaySE(s32 se, bool play) {
    u32 s0 = (u32)play & 0xFFu;
    u32 s1 = GetSeId(se);
    if (s0 != 0u) {
        SOUND_systemSePlay((s32)s1, 0);
    }
    return s1;
}
}  // Tz

// 00242660 (was src/tozawa/menu_sound.cpp)
namespace Tz { // method 00242660
extern void SOUND_systemSePlay(s32, s32) asm("_ZN5SOUND12systemSePlayEii");
/*TARGET 00242660*/
void MenuSound::PlaySEDirect(s32 se) { SOUND_systemSePlay(se, 0); }
}  // Tz

// 00242678 (was src/tozawa/menu_sound.cpp)
namespace Tz { // method 00242678
extern u32 D_0035ecd4 asm("D_0035ecd4");
/*TARGET 00242678*/
void MenuSound::PlayBgSE(s32) { D_0035ecd4 = GetBgSeHandle(); }
}  // Tz

// 002426a0 (was src/tozawa/menu_sound.cpp)
namespace Tz { // method 002426a0
extern u32 D_0035ecd4 asm("D_0035ecd4");
/*TARGET 002426a0*/
void MenuSound::StopBgSE(u32 which) {
    u32 s16 = which;
    u32 v0;
    if (s16 == 0) {
        s16 = D_0035ecd4;
        if (s16 == 0) {
            goto clear;
        }
    }
    v0 = isBgSePlaying(s16);
    if (v0 != 0) {
        StopBgSeHandle(s16, 0);
    }
clear:
    D_0035ecd4 = 0;
}
}  // Tz

// 00242708 (was src/anon/auto200_999.cpp)
namespace Tz { // method 00242708
extern s16 D_0035ecc8 asm("D_0035ecc8");
extern s16 D_003717c8 asm("D_003717c8");
/*TARGET 00242708*/
u32 MenuSound::GetSeId(s32 se) {
    if (se < 6) se = (&D_0035ecc8)[se];
    s16* t = &D_003717c8;
    return t[se - 6];
}
}  // Tz

// 00242740 (was src/anon/batch_w1589_g.cpp)
namespace n00242740 {
s32 func_00197920(void) asm("func_00197920");
void func_002ba978(s32) asm("func_002ba978");
s32 func_002ef7b8(void) asm("func_002ef7b8");
void func_002bd680(void) asm("func_002bd680");
/*TARGET 00242740*/
void Tz__MenuSound__SetPause(s32 a) asm("Tz__MenuSound__SetPause");
void Tz__MenuSound__SetPause(s32 a)
{
    if (a < 0) {
        a = func_00197920() ? 1 : 2;
    }
    func_002ba978(a);
    if (func_002ef7b8()) func_002bd680();
}
}  // namespace n00242740

// 00242790 (was src/tozawa/menu_sound.cpp)
namespace Tz { // method 00242790
/*TARGET 00242790*/
u32 MenuSound::ResetPause() {
    u32 r2 = isPauseActive();
    if (r2 != 0u) {
        r2 = ResetPauseImpl();
    }
    return ResetVoiceState();
}
}  // Tz

// 002427c0 (was src/tozawa/menu_sound.cpp)
namespace Tz { // method 002427c0
extern void SOUND_seVoicePcmStop(void) asm("_ZN5SOUND14seVoicePcmStopEv");
/*TARGET 002427c0*/
void MenuSound::AllStop() { SOUND_seVoicePcmStop(); }
}  // Tz

// 002427d8 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n002427d8 {
u32 func_00242708(u32, u32, u32, u32) asm("_Z13func_00242708jjjj");
/*TARGET 002427d8*/
u32 func_002427d8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002427d8jjjj");
u32 func_002427d8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15, r16;
    r15 = (u32)(0x0036u << 16);
    r16 = r4;
    r4 = (u32)(s32)(*(s16*)((u32)r15 + (s32)(-4916)));
    u32 (*fp_call4_00242708)(u32, u32, u32, u32) = func_00242708;
    r2 = fp_call4_00242708(r4, r5, r6, r7);
    r16 = (u32)(r16 ^ r2);
    r16 = ((u32)r16 < 0x00000001u);
    r2 = r16;
    return r2;
}
}  // namespace n002427d8

// 00242810 (was src/anon/tiny_auto80_fptr4.cpp)
namespace n00242810 {
u32 func_00242708(u32, u32, u32, u32) asm("_Z13func_00242708jjjj");
/*TARGET 00242810*/
u32 func_00242810(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00242810jjjj");
u32 func_00242810(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2, r15, r16;
    r15 = (u32)(0x0036u << 16);
    r16 = r4;
    r4 = (u32)(s32)(*(s16*)((u32)r15 + (s32)(-4914)));
    u32 (*fp_call4_00242708)(u32, u32, u32, u32) = func_00242708;
    r2 = fp_call4_00242708(r4, r5, r6, r7);
    r16 = (u32)(r16 ^ r2);
    r16 = ((u32)r16 < 0x00000001u);
    r2 = r16;
    return r2;
}
}  // namespace n00242810

// 00242848 (was src/tozawa/menu_sound.cpp)
namespace Tz { // method 00242848
/*TARGET 00242848*/
u32 MenuSound::isBeep(s32 which) {
    u32 r15 = (u32)(0x0036u << 16);
    u32 r16 = (u32)which;
    u32 r4 = (u32)(s32)(*(s16*)((u32)r15 + (s32)(-4912)));
    u32 r2 = GetSeId(r4);
    r16 = (u32)(r16 ^ r2);
    r16 = ((u32)r16 < 0x00000001u);
    return r16;
}
}  // Tz

// 00242880 (was src/anon/batch_w50.cpp)
namespace n00242880 {
struct Flags { u16 a; u16 b; u32 f0 : 1; u32 f1 : 2; u32 f3 : 1; u32 f4 : 1; u32 f5 : 1; u32 f6 : 1; u32 f7 : 1; u32 f8 : 1; u32 f9 : 2; };
u8* func_001058e8(void) asm("func_001058e8");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
extern u8 D_0035ecd8[] asm("D_0035ecd8");
/*TARGET 00242880*/
void func_00242880(void) asm("func_00242880");
void func_00242880(void) {
    Flags* p = (Flags*)(func_001058e8() + 16800);
    p->a = 0;
    p->b = 0;
    p->f0 = 1;
    p->f1 = 1;
    p->f3 = 1;
    p->f4 = 0;
    p->f5 = 0;
    p->f6 = 0;
    p->f7 = 0;
    p->f8 = 0;
    p->f9 = 2;
    func_002fde18(D_0035ecd8, 0, 4);
}
}  // namespace n00242880

// 00242908 (was src/anon/batch_w1528.cpp)
namespace n00242908 {
s32 func_00242a00() asm("func_00242a00");
void func_0023d1d0() asm("func_0023d1d0");
void func_0023d1e0() asm("func_0023d1e0");
s32 func_00242a68() asm("func_00242a68");
void func_002b6bc4(s32) asm("func_002b6bc4");
/*TARGET 00242908*/
// 0x00288f60: definition moved into src/anon/unit_00288b00.cpp

void func_00242908() asm("func_00242908");
// 0x00288f60: definition moved into src/anon/unit_00288b00.cpp

void func_00242908() {
    if (func_00242a00()) func_0023d1d0(); else func_0023d1e0();
    s32 a;
    switch (func_00242a68()) {
    case 0: a = 0; break;
    case 2: a = 2; break;
    case 1:
    default: a = 1; break;
    }
    func_002b6bc4(a);
}
}  // namespace n00242908

// 00242980 (was src/anon/batch_w20.cpp)
namespace n00242980 {
u8* func_001058e8(void) asm("func_001058e8");
// The pair is read as 16-bit bitfields: plain s16 loads get hoisted above the first store.
struct Pair16 { s32 x : 16; s32 y : 16; };
/*TARGET 00242980*/
void func_00242980(s32* a, s32* b) asm("func_00242980");
void func_00242980(s32* a, s32* b) {
    Pair16* v = (Pair16*)(func_001058e8() + 16800);
    *a = v->x;
    *b = v->y;
}
}  // namespace n00242980

// 002429c0 (was src/anon/batch_w17.cpp)
namespace n002429c0 {
u8* func_001058e8(void) asm("func_001058e8");
struct Pair16 { s16 a, b; };
/*TARGET 002429c0*/
void func_002429c0(s32 a, s32 b) asm("func_002429c0");
void func_002429c0(s32 a, s32 b) {
    Pair16* s = (Pair16*)(func_001058e8() + 16800);
    s->a = a;
    s->b = b;
}
}  // namespace n002429c0

// 00242a00 (was src/tozawa/config.cpp)
namespace Tz { // method 00242a00
u32 getSaveRam() asm("_Z10getSaveRamv");
/*TARGET 00242a00*/
u32 Config::isVibration() {
    u32 r2 = getSaveRam();
    r2 = *(u32*)((u32)r2 + 16804);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}
}  // Tz

// 00242a28 (was src/anon/batch_w21.cpp)
namespace n00242a28 {
u8* func_001058e8(void) asm("func_001058e8");
struct Flags { u32 a; u32 on : 1; };
/*TARGET 00242a28*/
void func_00242a28(u8 on) asm("func_00242a28");
void func_00242a28(u8 on) {
    Flags* f = (Flags*)(func_001058e8() + 16800);
    f->on = on != 0;
}
}  // namespace n00242a28

// 00242a68 (was src/anon/tiny_jal_wrappers.cpp)
namespace n00242a68 {
u32 func_001058e8(u32, u32, u32, u32) asm("_Z13func_001058e8jjjj");
/*TARGET 00242a68*/
u32 func_00242a68(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00242a68jjjj");
u32 func_00242a68(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001058e8(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(16804));
    r2 = (u32)(r2 >> 1);
    r2 = (u32)(r2 & 0x0003u);
    return r2;
}
}  // namespace n00242a68

// 00242a90 (was src/anon/batch_w24.cpp)
namespace n00242a90 {
// 0022cf18: moved to src/sasa/event_layout.cpp (linked unit)

struct Bits { u32 b0 : 1; u32 m : 2; u32 rest : 29; };
struct Blk { u32 _0; Bits f; };
u8* func_001058e8(void) asm("func_001058e8");
/*TARGET 00242a90*/
void func_00242a90(s32 a) asm("func_00242a90");
void func_00242a90(s32 a) {
    Blk* b = (Blk*)(func_001058e8() + 16800);
    s32 m = 0;
    if (a) m = a == 2 ? 2 : 1;
    b->f.m = m;
}
}  // namespace n00242a90

// 00242ae8 (was src/tozawa/config.cpp)
namespace Tz { // method 00242ae8
u32 getSaveRam() asm("_Z10getSaveRamv");
/*TARGET 00242ae8*/
u32 Config::isNaviOn() {
    u32 r2 = getSaveRam();
    r2 = *(u32*)((u32)r2 + 16804);
    r2 = (u32)((s32)r2 >> 3);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}
}  // Tz

// 00242b10 (was src/anon/batch_w208.cpp)
namespace n00242b10 {
struct S242 { u32 w0; u32 :3; u32 f:1; };
S242* func_001058e8(void) asm("func_001058e8");
/*TARGET 00242b10*/
void func_00242b10(u8 a) asm("func_00242b10");
void func_00242b10(u8 a) {
    S242* p = (S242*)((char*)func_001058e8() + 16800);
    p->f = a != 0;
}
}  // namespace n00242b10

// 00242b58 (was src/tozawa/config.cpp)
namespace Tz { // method 00242b58
u32 getSaveRam() asm("_Z10getSaveRamv");
/*TARGET 00242b58*/
u32 Config::isCameraAuto() {
    u32 r2 = getSaveRam();
    r2 = *(u32*)((u32)r2 + 16804);
    r2 = (u32)((s32)r2 >> 4);
    r2 = (u32)(r2 ^ 0x0001u);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}
}  // Tz

// 00242b88 (was src/anon/batch_w209.cpp)
namespace n00242b88 {
// --- 00242b88
extern u8* func_001058e8(void) asm("func_001058e8");
/*TARGET 00242b88*/
void func_00242b88(u8 a) asm("func_00242b88");
void func_00242b88(u8 a) {
    u8* p = func_001058e8() + 16800;
    u32 v = a == 0;
    *(u32*)(p + 4) = (*(u32*)(p + 4) & ~0x10u) | (v << 4);
}
}  // namespace n00242b88

// 00242bd0 (was src/tozawa/config.cpp)
namespace Tz { // method 00242bd0
u32 getSaveRam() asm("_Z10getSaveRamv");
/*TARGET 00242bd0*/
u32 Config::isRightStickCamera() {
    u32 r2 = getSaveRam();
    r2 = *(u32*)((u32)r2 + 16804);
    r2 = (u32)((s32)r2 >> 5);
    r2 = (u32)(r2 ^ 0x0001u);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}
}  // Tz

// 00242c00 (was src/anon/batch_w40.cpp)
namespace n00242c00 {
u8* func_001058e8(void) asm("func_001058e8");
s32 func_00242bd0(void) asm("func_00242bd0");
s32 func_00242b58(void) asm("func_00242b58");
void func_00242b88(u32) asm("func_00242b88");
struct F242 { u32 lo : 5; u32 b5 : 1; u32 rest : 26; };
/*TARGET 00242c00*/
void func_00242c00(u8 a) asm("func_00242c00");
void func_00242c00(u8 a) {
    u8* v = func_001058e8() + 16800;
    ((F242*)(v + 4))->b5 = a == 0;
    if (!func_00242bd0() && !func_00242b58()) func_00242b88(1);
}
}  // namespace n00242c00

// 00242c70 (was src/tozawa/config.cpp)
namespace Tz { // method 00242c70
u32 getSaveRam() asm("_Z10getSaveRamv");
/*TARGET 00242c70*/
u32 Config::isCommandKH2() {
    u32 r2 = getSaveRam();
    r2 = *(u32*)((u32)r2 + 16804);
    r2 = (u32)((s32)r2 >> 6);
    r2 = (u32)(r2 ^ 0x0001u);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}
}  // Tz

// 00242ca0 (was src/anon/batch_w33.cpp)
namespace n00242ca0 {
struct Bits242 { u32 pad; u32 lo : 6; u32 off : 1; };
void* func_001058e8(void) asm("func_001058e8");
/*TARGET 00242ca0*/
void func_00242ca0(u8 on) asm("func_00242ca0");
void func_00242ca0(u8 on) {
    Bits242* b = (Bits242*)((u8*)func_001058e8() + 16800);
    b->off = on == 0;
}
}  // namespace n00242ca0

// 00242ce8 (was src/anon/tiny_jal_wrappers.cpp)
namespace n00242ce8 {
u32 func_001058e8(u32, u32, u32, u32) asm("_Z13func_001058e8jjjj");
/*TARGET 00242ce8*/
u32 func_00242ce8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00242ce8jjjj");
u32 func_00242ce8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001058e8(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(16804));
    r2 = (u32)((s32)r2 >> 7);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}
}  // namespace n00242ce8

// 00242d10 (was src/anon/batch_w34.cpp)
namespace n00242d10 {
u8* func_001058e8(void) asm("func_001058e8");
struct BitWord {
    u32 lo : 7;
    u32 flag : 1;
    u32 hi : 24;
};
/*TARGET 00242d10*/
void func_00242d10(u8 on) asm("func_00242d10");
void func_00242d10(u8 on) {
    u8* p = func_001058e8() + 16800;
    ((BitWord*)(p + 4))->flag = on != 0;
}
}  // namespace n00242d10

// 00242d58 (was src/anon/tiny_jal_wrappers.cpp)
namespace n00242d58 {
u32 func_001058e8(u32, u32, u32, u32) asm("_Z13func_001058e8jjjj");
/*TARGET 00242d58*/
u32 func_00242d58(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00242d58jjjj");
u32 func_00242d58(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001058e8(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(16804));
    r2 = (u32)((s32)r2 >> 8);
    r2 = (u32)(r2 & 0x0001u);
    return r2;
}
}  // namespace n00242d58

// 00242d80 (was src/anon/batch_w35.cpp)
namespace n00242d80 {
struct BF242 { u32 lo : 8; u32 f : 1; u32 hi : 23; };
struct X242 { u32 a; BF242 b; };
u8* func_001058e8(void) asm("func_001058e8");
/*TARGET 00242d80*/
void func_00242d80(u8 f) asm("func_00242d80");
void func_00242d80(u8 f) {
    X242* x = (X242*)(func_001058e8() + 16800);
    x->b.f = f != 0;
}
}  // namespace n00242d80

// 00242dc8 (was src/anon/tiny_jal_wrappers.cpp)
namespace n00242dc8 {
u32 func_001058e8(u32, u32, u32, u32) asm("_Z13func_001058e8jjjj");
/*TARGET 00242dc8*/
u32 func_00242dc8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00242dc8jjjj");
u32 func_00242dc8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2 = 0u;
    r2 = func_001058e8(r4, r5, r6, r7);
    r2 = *(u32*)((u32)r2 + (s32)(16804));
    r2 = (u32)(r2 >> 9);
    r2 = (u32)(r2 & 0x0003u);
    return r2;
}
}  // namespace n00242dc8

// 00242df0 (was src/anon/batch_w25.cpp)
namespace n00242df0 {
// Sets a 2-bit mode field (bits 9-10).
u8* func_001058e8(void) asm("func_001058e8");
/*TARGET 00242df0*/
void Tz__Config__SetSummonEffect(s32 m) asm("Tz__Config__SetSummonEffect");
void Tz__Config__SetSummonEffect(s32 m) {
    u8* v = func_001058e8() + 16800;
    s32 x;
    if (m == 0) x = 0;
    else x = m == 2 ? 2 : 1;
    *(u32*)(v + 4) = (*(u32*)(v + 4) & ~0x600) | (x << 9);
}
}  // namespace n00242df0

// 00242e48 (was src/anon/tiny_more.cpp)
namespace n00242e48 {
extern u32 D_0035ecd8 asm("D_0035ecd8");
/*TARGET 00242e48*/
u32 func_00242e48(u32 a0,u32 a1,u32 a2,u32 a3) asm("_Z13func_00242e48jjjj");
u32 func_00242e48(u32 a0,u32 a1,u32 a2,u32 a3) { (void)a0; (void)a1; (void)a2; (void)a3; u32 v = D_0035ecd8; return v & 0x1u; }
}  // namespace n00242e48

// 00242e58 (was unwritten gap: Config bit setters)
namespace n00242e58 {
extern u32 D_0035ecd8 asm("D_0035ecd8");
void func_00242e58(bool b) asm("func_00242e58");
void func_00242e58(bool b) { D_0035ecd8 = (D_0035ecd8 & ~1) | (b != 0); }
void func_00242e80(bool b) asm("func_00242e80");
void func_00242e80(bool b) { u32 t = b != 0; D_0035ecd8 = (D_0035ecd8 & ~2) | (t << 1); }
}  // namespace n00242e58

// 00242ea8 (was src/tozawa/config.cpp)
namespace Tz { // method 00242ea8
extern u32 D_0035ecd8 asm("D_0035ecd8");
/*TARGET 00242ea8*/
u32 Config::isEventViewer() {
    u32 v = D_0035ecd8;
    v = (u32)((s32)v >> 1);
    return v & 0x1u;
}
}  // Tz

// 00242ec0 (was unwritten gap: Config bit setter)
namespace n00242ec0 {
extern u32 D_0035ecd8 asm("D_0035ecd8");
void func_00242ec0(bool b) asm("func_00242ec0");
void func_00242ec0(bool b) { u32 t = b != 0; D_0035ecd8 = (D_0035ecd8 & ~4) | (t << 2); }
}  // namespace n00242ec0

// 00242ee8 (was src/tozawa/config.cpp)
namespace Tz { // method 00242ee8
extern u32 D_0035ecd8 asm("D_0035ecd8");
/*TARGET 00242ee8*/
u32 Config::isChapterAll() {
    u32 v = D_0035ecd8;
    v = (u32)((s32)v >> 2);
    return v & 0x1u;
}
}  // Tz

// 00242f00 (was src/anon/batch_wcx2.cpp)
namespace n00242f00 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
// 001815d0: moved to src/yasui/libys/progress.cpp

// --------------------
extern s32 D_0035ece0 asm("D_0035ece0");
extern s32 D_003718d0[] asm("D_003718d0");
void func_0023d320(s32) asm("func_0023d320");
void Tz__MenuSound__SetPause(s32) asm("Tz__MenuSound__SetPause");
void func_00287910(s32, s32, s32) asm("func_00287910");
s32 func_00103570() asm("func_00103570");
void Tz__MenuCursor__Init(s32, s32) asm("Tz__MenuCursor__Init");
void func_002425d0(s32) asm("func_002425d0");
void func_00242fa0() asm("func_00242fa0");
struct VT242f00 { void* a; void (*b)(); };
VT242f00* func_00243150(s32) asm("func_00243150");
/*TARGET 00242f00*/
void func_00242f00(s32 n) asm("func_00242f00");
void func_00242f00(s32 n) {
    func_0023d320(n);
    Tz__MenuSound__SetPause(-1);
    func_00287910(n, 2, 0);
    Tz__MenuCursor__Init(func_00103570(), 2);
    func_002425d0(2);
    func_00242fa0();
    if (D_0035ece0 < 0) D_0035ece0 = D_003718d0[n];
    func_00243150(n)->b();
}
}  // namespace n00242f00

// 00242fa0 (was src/anon/tiny_wrappers_imp.cpp)
namespace n00242fa0 {
u32 func_0028d068(u32, u32, u32, u32) asm("_Z13func_0028d068jjjj");
/*TARGET 00242fa0*/
// 0022b948: moved to src/sasa/musical_2d.cpp (linked unit)

// 0022b9b8: moved to src/sasa/musical_2d.cpp (linked unit)

// 0022b9e0: moved to src/sasa/musical_2d.cpp (linked unit)

u32 func_00242fa0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00242fa0jjjj");
// 0022b948: moved to src/sasa/musical_2d.cpp (linked unit)

// 0022b9b8: moved to src/sasa/musical_2d.cpp (linked unit)

// 0022b9e0: moved to src/sasa/musical_2d.cpp (linked unit)

u32 func_00242fa0(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r14 = 0u, r15 = 0u;
    r14 = (u32)((s32)0u + (30012));
    r15 = (u32)(0x0036u << 16);
    *(u32*)((u32)r15 + (s32)(-3116)) = r14;
    r4 = (u32)((s32)0u + (30026));
    r5 = (u32)((s32)0u + (-1));
    return func_0028d068(r4, r5, r6, r7);
}
}  // namespace n00242fa0

// 00242fc8 (was src/tozawa/sub_menu.cpp)
namespace Tz { // method 00242fc8
u32 func_00243150(...) asm("func_00243150");
u32 func_0028ca78(...) asm("func_0028ca78");
u32 func_0023fad0(...) asm("func_0023fad0");
u32 Tz__MenuBase__Exit(...) asm("Tz__MenuBase__Exit");
u32 func_00242790(...) asm("func_00242790");
u32 func_0023d368(...) asm("func_0023d368");
extern s32 D_0035ece0 asm("D_0035ece0");
extern u8 D_0035f3a8 asm("D_0035f3a8");
/*TARGET 00242fc8*/
u32 SubMenu::Exit(s32) {
    D_0035ece0 = -1;
    u32 v0 = func_00243150();
    void (*fn)(void) = (void (*)(void))*(u32*)(v0 + 8);
    fn();
    func_0028ca78();
    func_0023fad0((void*)&D_0035f3a8);
    Tz__MenuBase__Exit();
    func_00242790();
    return func_0023d368();
}
}  // Tz

// 00243020 (was src/anon/batch_w51.cpp)
namespace n00243020 {
extern u8 D_0032bad8 asm("D_0032bad8");
s32 func_00103b38(void) asm("func_00103b38");
u32 func_00103550(void) asm("func_00103550");
s32 func_00103428(u32) asm("func_00103428");
u8* func_00243150(u32) asm("func_00243150");
void func_00103500(s16) asm("func_00103500");
void func_00253538(s16) asm("func_00253538");
/*TARGET 00243020*/
void func_00243020(u32 a0) asm("func_00243020");
void func_00243020(u32 a0) {
    if (!D_0032bad8) return;
    if (func_00103b38()) {
        if (func_00103428(func_00103550())) func_00103500(*(s16*)(func_00243150(a0) + 2));
    } else {
        func_00253538(*(s16*)(func_00243150(a0) + 2));
    }
}
}  // namespace n00243020

// 002430b0 (was src/anon/batch_w1587.cpp)
namespace n002430b0 {
extern s32 D_0035ece0 asm("D_0035ece0");
u32 func_00243190(s32) asm("func_00243190");
void func_00243020(u32 a0) asm("func_00243020");
// 0x00293500: definition moved into src/anon/unit_00292e60.cpp

void Tz_SubMenu_Start(s32 a) asm("_ZN2Tz7SubMenu5StartEi");
/*TARGET 002430b0*/
void Tz_SubMenu_Start(s32 a) asm("_ZN2Tz7SubMenu5StartEi");
void Tz_SubMenu_Start(s32 a) {
    D_0035ece0 = a;
    func_00243020(func_00243190(a));
}
}  // namespace n002430b0

// 002430d8 (was src/tozawa/sub_menu.cpp)
namespace Tz { // method 002430d8
u32 func_002fee78(...) asm("func_002fee78");
u32 func_0023fa90(...) asm("func_0023fa90");
u32 func_0023f900(...) asm("func_0023f900");
extern u32 D_0033caf4 asm("D_0033caf4");
extern u8 D_00371830 asm("D_00371830");
extern u8 D_0035f3a8 asm("D_0035f3a8");
/*TARGET 002430d8*/
void SubMenu::SetLeadData(const char* a0) {
    u8 spbuf[128];
    ((void (*)(void*, const void*, u32, const char*))(u32)&func_002fee78)(spbuf, &D_00371830,
                                                                           D_0033caf4, a0);
    ((void (*)(void*, const void*))(u32)&func_0023fa90)(&D_0035f3a8, spbuf);
    ((void (*)(void*))(u32)&func_0023f900)(&D_0035f3a8);
}
}  // Tz

// 00243130 (was src/anon/tiny_auto80_queue.cpp)
namespace n00243130 {
u32 func_00170950(...) asm("func_00170950");
/*TARGET 00243130*/
void func_00243130(u32 a0) asm("_Z13func_00243130j");
void func_00243130(u32 a0) {
    if (a0 != 0) {
        func_00170950(a0);
    }
}
}  // namespace n00243130

// 00243150 (was src/anon/batch_w22.cpp)
namespace n00243150 {
// --- 00243150
// Last table entry whose id matches (table ends with a negative id).
struct E243 { s16 id; s16 pad; u32 a, b; };
extern E243 D_00371840[] asm("D_00371840");
/*TARGET 00243150*/
E243* func_00243150(s32 id) asm("func_00243150");
E243* func_00243150(s32 id) {
    E243* r = 0;
    for (s32 i = 0; D_00371840[i].id >= 0; i++) {
        if (D_00371840[i].id == id) r = &D_00371840[i];
    }
    return r;
}
}  // namespace n00243150

// 00243190 (was src/anon/batch_w7.cpp)
namespace n00243190 {
extern u32 D_003718d0[11] asm("D_003718d0");
/*TARGET 00243190*/
// Index of v in an 11-entry table, or 11.
u32 func_00243190(u32 v) asm("func_00243190");
// Index of v in an 11-entry table, or 11.
u32 func_00243190(u32 v) {
    u32 i;
    for (i = 0; i < 11; i++)
        if (D_003718d0[i] == v) break;
    return i;
}
}  // namespace n00243190

// 002431c0 (was src/anon/tiny.cpp)
namespace n002431c0 {
/*TARGET 002431c0*/
u32 func_002431c0(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_002431c0jjjj");
u32 func_002431c0(u32 a0, u32 a1, u32 a2, u32 a3) {
    (void)a0;
    (void)a1;
    (void)a2;
    (void)a3;
    u32 b = (0x0036u << 16);
    return (u32)(*(u32*)((u32)b + (-4896)));
}
}  // namespace n002431c0

// 002431d0 (was src/anon/batch_w44.cpp)
namespace n002431d0 {
u8* func_001058e8(void) asm("func_001058e8");
/*TARGET 002431d0*/
// Bit test in the flag array at +18904.
s32 Tz__SubMenu__isSetNew(s32 a, s32 b) asm("Tz__SubMenu__isSetNew");
// Bit test in the flag array at +18904.
s32 Tz__SubMenu__isSetNew(s32 a, s32 b) {
    u8* v = func_001058e8();
    u32 i = a * 8 + b;
    v += (i >> 5) * 4;
    return (*(u32*)(v + 18904) & (1 << (i & 31))) != 0;
}
}  // namespace n002431d0

// 00243230 (was src/anon/batch_w45.cpp)
namespace n00243230 {
// list_contains_ptr
u8* func_001058e8(void) asm("func_001058e8");
/*TARGET 00243230*/
// set bit (a0 * 8 + a1) in a bit array
void func_00243230(s32 a0, s32 a1) asm("func_00243230");
// set bit (a0 * 8 + a1) in a bit array
void func_00243230(s32 a0, s32 a1) {
    u32 base = (u32)(func_001058e8() + 18904);
    u32 idx = a0 * 8 + a1;
    u32* p = (u32*)((idx >> 5) * 4 + base);
    u32 bit = 1 << (idx & 31);
    u32 v = *p;
    if (!(v & bit)) *p = v | bit;
}
}  // namespace n00243230

// 00243298 (was src/anon/batch_w3723_nsa.cpp)
namespace n00243298 {
struct Alloc { void* (**vt)(Alloc*, u32, void*); };
struct Holder { u8 pad[0x14]; Alloc* al; };
extern Holder* D_00347f80 asm("D_00347f80");
extern u8 D_00347e60 asm("D_00347e60");
extern u8 D_00347e40 asm("D_00347e40");
extern u8 D_00347f98 asm("D_00347f98");
extern s32 D_0035ece8 asm("D_0035ece8");
extern s32 D_0035ecec asm("D_0035ecec");
extern s32 D_0035ecf0 asm("D_0035ecf0");
extern s32 D_0035ecf4 asm("D_0035ecf4");
extern s32 D_0035ecf8 asm("D_0035ecf8");
extern void* D_0035ecfc asm("D_0035ecfc");
extern void* D_0035ed00 asm("D_0035ed00");
extern s32 D_0035ed10 asm("D_0035ed10");
extern u8* D_0035ed04 asm("D_0035ed04");
extern s8 D_0035ed14 asm("D_0035ed14");
void func_00287b18(s32, s32) asm("func_00287b18");
s32 func_00288be8(s32) asm("func_00288be8");
void func_002889f0(s32, s32, s32) asm("func_002889f0");
void func_00288f48(s32, s32, s32, s32, s32) asm("func_00288f48");
void func_002b3df8(s32) asm("func_002b3df8");
s32 func_00103570(void) asm("func_00103570");
s32 func_001063f0(s32, s32) asm("func_001063f0");
void func_002fde18(s32, s32, s32) asm("func_002fde18");
void func_00239700(void*) asm("func_00239700");
void func_0031a838(void*) asm("func_0031a838");
void func_0028d068(s32, s32) asm("func_0028d068");
s32* func_00103eb0(void) asm("func_00103eb0");
void TASK_MANAGER__create_thread(s32, s32, s32, void*, s32) asm("TASK_MANAGER__create_thread");
void PauseThread_243(void*) asm("_ZN2Tz4HEFT11PauseThreadEP4TASK");
typedef void* (*AF)(s32, u32, void*);
extern s32 D_0032ba14_i asm("D_0032ba14");
static inline void* Al(u32 n) { s32 a = D_0032ba14_i; return (*(AF*)*(s32*)a)(a, n, __builtin_return_address(0)); }
/*TARGET 00243298*/
void Tz__HEFT__Init(void) asm("Tz__HEFT__Init");
void Tz__HEFT__Init(void) {
    s32 v;
    u8* o;
    void* e60 = &D_00347e60;
    void* e40 = &D_00347e40;
    func_00287b18(2, 3);
    v = func_00288be8(0x38);
    func_002889f0(v, 2, 1);
    D_0035ece8 = v;
    v = func_00288be8(0x38);
    func_002889f0(v, 2, 0);
    D_0035ecec = v;
    func_00288f48(v, 0x40, 0x80, 0, 0);
    D_0035ecf0 = 0;
    D_0035ecf4 = 0;
    D_0035ecf8 = 0;
    v = (s32)Al(12);
    func_002b3df8(v);
    {
        u32 h1;
        u32 h;
        asm("lui %0,%%hi(D_0035ed08)" : "=r"(h1));
        asm("lui %0,%%hi(D_0035ed0c)" : "=r"(h) : "r"(h1));
        asm("" : "+r"(v) : "r"(h));
        *(s32*)(h1 - 4856) = v;
        *(s8*)(h - 4852) = 0;
    }
    {
        Alloc* al = D_00347f80->al;
        o = (u8*)(*al->vt)(al, 436, 0);
        *(void**)o = e60;
        *(s32*)(o + 12) = 0;
        func_00239700(o + 24);
        *(s32*)(o + 408) = 0;
        *(void**)o = e40;
        D_0035ecfc = o;
    }
    {
        Alloc* al = D_00347f80->al;
        o = (u8*)(*al->vt)(al, 436, 0);
        *(void**)o = &D_00347f98;
        func_0031a838(o + 12);
        *(void**)o = e60;
        func_00239700(o + 24);
        *(void**)o = e40;
        *(s32*)(o + 408) = 0;
        D_0035ed00 = o;
    }
    v = func_001063f0(0x20, func_00103570());
    D_0035ed10 = v;
    func_002fde18(v, 0, 0x20);
    {
        register Holder* hh asm("$15") = D_00347f80;
        Alloc* al = hh->al;
        s32* p = (s32*)(*al->vt)(al, 820, 0);
        u8* base = (u8*)(p + 1);
        u8* q = base;
        s32 i = 1;
        void* vt = e60;
        register s32 m1 asm("$22") = -1;
        *p = 2;
        do {
            *(s32*)(q + 12) = 0;
            *(void**)q = vt;
            i--;
            func_00239700(q + 0x18);
            q += 0x198;
        } while (i != m1);
        D_0035ed04 = base;
        D_0035ed14 = 0;
        // Same call in both arms: the arms merge after reload, but until then the argument
        // loads sit in their own blocks, so the two stores stay next to each other in the
        // first scheduling pass and their address halves get two registers (t7, t6).
        if (base) func_0028d068(30026, -1); else func_0028d068(30026, -1);
    }
    TASK_MANAGER__create_thread(func_00103eb0()[1], 0, 2000, (void*)PauseThread_243, 0x1000);
}
}  // namespace n00243298

// 00243500 (was unwritten gap: HE globals cleanup, like 0x2450c8)
namespace n00243500 {
struct AV { void* a; void (*free)(void*, void*); };
struct AO { AV* vt; };
struct AH { u8 pad[20]; AO* a; };
extern AH* D_00347f80 asm("D_00347f80");
struct El2 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~El2();
    u8 pad[404];
    static void operator delete[](void* p) { D_00347f80->a->vt->free(D_00347f80->a, p); }
};
struct DV { void* a[4]; void (*del)(void*); };
struct DO { DV* vt; };
extern void* D_0035ece8 asm("D_0035ece8");
extern void* D_0035ecec asm("D_0035ecec");
extern DO* D_0035ecf0 asm("D_0035ecf0");
extern DO* D_0035ecf4 asm("D_0035ecf4");
extern DO* D_0035ecf8 asm("D_0035ecf8");
extern DO* D_0035ecfc asm("D_0035ecfc");
extern DO* D_0035ed00 asm("D_0035ed00");
extern El2* D_0035ed04 asm("D_0035ed04");
extern void* D_0035ed08 asm("D_0035ed08");
extern void* D_0035ed10 asm("D_0035ed10");
extern AO* D_0032ba14 asm("D_0032ba14");
void func_00288b00(void*) asm("func_00288b00");
void func_00288c20(void*) asm("func_00288c20");
void func_002b3fb0(void*) asm("func_002b3fb0");
void func_00106450(void*) asm("func_00106450");
void func_00243500(void) asm("func_00243500");
void func_00243500(void) {
    void* p;
    if ((p = D_0035ece8) != 0) { func_00288b00(p); func_00288c20(p); D_0035ece8 = 0; }
    if ((p = D_0035ecec) != 0) { func_00288b00(p); func_00288c20(p); D_0035ecec = 0; }
    if (D_0035ecf0) { D_0035ecf0->vt->del(D_0035ecf0); D_0035ecf0 = 0; }
    if (D_0035ecf4) { D_0035ecf4->vt->del(D_0035ecf4); D_0035ecf4 = 0; }
    if (D_0035ecf8) { D_0035ecf8->vt->del(D_0035ecf8); D_0035ecf8 = 0; }
    if ((p = D_0035ed08) != 0) { func_002b3fb0(p); D_0032ba14->vt->free(D_0032ba14, p); D_0035ed08 = 0; }
    if (D_0035ecfc) { D_0035ecfc->vt->del(D_0035ecfc); D_0035ecfc = 0; }
    if (D_0035ed00) { D_0035ed00->vt->del(D_0035ed00); D_0035ed00 = 0; }
    if (D_0035ed10) { func_00106450(D_0035ed10); D_0035ed10 = 0; }
    if (D_0035ed04) {
        delete[] D_0035ed04;
        D_0035ed04 = 0;
    }
}
}  // namespace n00243500

// 002436d0 (was src/tozawa/smenu_he.cpp)
namespace Tz { // method 002436d0
extern u32 D_0035ece4 asm("D_0035ece4");
void func_002430d8(u32) asm("func_002430d8");
void func_00102448(u32, u32) asm("func_00102448");
void Tz__HEFT__Setup() asm("Tz__HEFT__Setup");
void YI__IMAGE_CACHE__Clear() asm("YI__IMAGE_CACHE__Clear");
// clear_64_entries_24
extern "C" u32 func_00244068() asm("func_00244068");
void Tz__HEFT__Draw() asm("Tz__HEFT__Draw");
/*TARGET 002436d0*/
void HEFT::PauseThread(TASK* a0) {
    u32 s16 = (u32)a0;
    func_002430d8(D_0035ece4);
    func_00102448(s16, 1);
    Tz__HEFT__Setup();
    while (1) {
        YI__IMAGE_CACHE__Clear();  // clear_64_entries_24
        if (func_00244068() != 0) {
            return;
        }
        Tz__HEFT__Draw();
        func_00102448(s16, 0);
    }
}
}  // Tz

// 00243740 (was src/anon/batch_w3902.cpp)
namespace n00243740 {
struct Ent36
{
  u8 pad0[8];
  u8 name[8];
  s8 f10;
  u8 pad11;
  u16 f12;
  u8 pad14[16];
};
struct VObj
{
  struct VT
  {
    u8 pad[24];
    void (*f18)(VObj *, s32, u32, s32, s32, s32, s32);
  } *vt;
};
u8 *func_0023ee30(u32) asm("func_0023ee30");
void func_0031a838(u8 *) asm("func_0031a838");
void YI__IMAGE_FREEZE__IMAGE_FREEZE(u8 *) asm("YI__IMAGE_FREEZE__IMAGE_FREEZE");
void YI__LAYOUT__LAYOUT(u8 *) asm("YI__LAYOUT__LAYOUT");
void Tz__MenuUtil__CreateLay(u8 *, s32, s32, s32, s32, s32, s32, s32, s32) asm("Tz__MenuUtil__CreateLay");
void Tz__Layout__SetImageCache(u8 *) asm("Tz__Layout__SetImageCache");
s32 func_00244938(s32) asm("func_00244938");
s32 Tz__SubMenu__isSetNew(s32, s32) asm("Tz__SubMenu__isSetNew");
void Tz__Select__SetItem(void *, s32, s32, s32, u8 *, s32, Ent36 *, u8 *) asm("Tz__Select__SetItem");
u8 *func_002891b8(void *, s32) asm("func_002891b8");
s32 func_0023aa98(u8 *) asm("func_0023aa98");
s32 func_0023aa78(u8 *) asm("func_0023aa78");
s32 func_0028dd90(s32) asm("func_0028dd90");
s32 func_0028ddd8(s32) asm("func_0028ddd8");
void func_001395f8(u8 *) asm("func_001395f8");
void func_00139620(u8 *) asm("func_00139620");
s32 func_002892f8(void *) asm("func_002892f8");
void func_00138c68(u8 *, s32, s32) asm("func_00138c68");
void Tz__Select__SetCurrent(void *, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void func_002449c0(void) asm("func_002449c0");
s32 func_002891e8(void *) asm("func_002891e8");
s32 func_00244ee8(s32) asm("func_00244ee8");
void func_002b4070(void *, s32, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, u8 *, s32, Ent36 *, s32, s32) asm("func_002b4070");
s32 func_001a6d08(s32) asm("func_001a6d08");
s32 func_00244a10(void) asm("func_00244a10");
void func_0028af40(void *, s32) asm("func_0028af40");
void func_0028d980(u8 *, s32, s32, s32, u8 *, s32, s32, s32, s32) asm("func_0028d980");
void func_00244a60(void) asm("func_00244a60");
VObj *func_00287dc0(void) asm("func_00287dc0");
void func_0023d808(VObj *, s32) asm("func_0023d808");
void func_0023e858(VObj *, s32, f32) asm("func_0023e858");
void func_0023e8b8(VObj *, s32, f32) asm("func_0023e8b8");
void func_0023e8d8(VObj *, s32, f32) asm("func_0023e8d8");
s32 func_00139d78(s32) asm("func_00139d78");
void func_0023e9b0(VObj *, s32, s32) asm("func_0023e9b0");
void func_0023e690(VObj *, s32, s32, s32) asm("func_0023e690");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_002887c8(void) asm("func_002887c8");
void Tz__HEFT__LoopAll(void) asm("Tz__HEFT__LoopAll");
void func_00288750(void (*)(void)) asm("func_00288750");
void func_00244058(void) asm("func_00244058");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern u8 D_0035ed0c asm("D_0035ed0c");
extern u8 D_0035ed14 asm("D_0035ed14");
extern u8 *D_0035ecf0 asm("D_0035ecf0");
extern u8 *D_0035ecf4 asm("D_0035ecf4");
extern u8 *D_0035ecf8 asm("D_0035ecf8");
extern u8 *D_0035ecfc asm("D_0035ecfc");
extern u8 *D_0035ed08 asm("D_0035ed08");
extern void *D_0035ece8 asm("D_0035ece8");
extern Ent36 D_003719a0[] asm("D_003719a0");
extern s16 D_00371968[][3] asm("D_00371968");
extern u8 D_00371960[] asm("D_00371960");
extern u8 D_00371978[] asm("D_00371978");
extern u8 D_00371980[] asm("D_00371980");
extern u8 D_00371988[] asm("D_00371988");
extern u8 D_00371990[] asm("D_00371990");
extern u8 D_00371998[] asm("D_00371998");
inline static u8 *NewLayout(void)
{
  u8 *o = func_0023ee30(160);
  *((u8 **) o) = D_00347f98;
  func_0031a838(o + 12);
  *((u8 **) o) = D_0035eb98;
  YI__IMAGE_FREEZE__IMAGE_FREEZE(o + 24);
  YI__LAYOUT__LAYOUT(o + 48);
  return o;
}
static inline s32 inline_fn(s32 arg0)
{
  return arg0;
}
/*TARGET 00243740*/
// Builds the slot-select layout: two entries, a centred column, then the
// header/title objects (w3892/w3902, helper).
void Tz__HEFT__Setup(void) asm("Tz__HEFT__Setup");
// Builds the slot-select layout: two entries, a centred column, then the
// header/title objects (w3892/w3902, helper).
void Tz__HEFT__Setup(void)
{
  s32 i;
  s32 n;
  s32 sel;
  s32 w;
  s32 half;
  s32 k;
  u8 *o;
  VObj *p;
  sel = 0;
  k = 0;
  D_0035ed0c = 0;
  D_0035ecf0 = NewLayout();
  Tz__MenuUtil__CreateLay(D_0035ecf0, 30002, 0, 0, 30, 32, 0, 0, 0);
  Tz__Layout__SetImageCache(D_0035ecf0);
  for (i = 0; i < 2; i++)
  {
    if (func_00244938(i))
    {
      if (Tz__SubMenu__isSetNew(3, i) == 0)
      {
        D_0035ed14 |= 1 << i;
      }
      if (D_003719a0[i].f10)
      {
        sel = i;
      }
      Tz__Select__SetItem(D_0035ece8, k, 0, 0, D_0035ecf0, D_003719a0[i].f12, &D_003719a0[i], D_003719a0[i].name);
      o = func_002891b8(D_0035ece8, k++);
      p = (VObj *) func_0023aa98(o + 24);
      *((s32 *) (o + 432)) = func_0028dd90((s32) p);
      *((s32 *) (o + 428)) = func_0028ddd8((s32) p);
      func_001395f8(o);
    }
  }

  n = func_002892f8(D_0035ece8);
  w = func_0023aa78(func_002891b8(D_0035ece8, 0) + 24);
  half = (w * n) / 2;
  for (i = 0; i < n; i++)
  {
    func_00138c68(func_002891b8(D_0035ece8, i), 0, i * w - half);
  }

  Tz__Select__SetCurrent(D_0035ece8, sel, 0, -1, -1);
  func_002449c0();
  sel = func_002891e8(D_0035ece8);
  Tz__Select__SetCurrent(D_0035ece8, sel, 1, 0, 2);
  half = func_00244ee8(sel);
  func_002b4070(D_0035ed08, 30003, D_0035ecf0, D_00371960, D_00371978, D_00371980, D_00371988, D_00371990, D_00371998, 0xcb96, &D_003719a0[half], 0, 0);
  D_0035ecf8 = NewLayout();
  Tz__MenuUtil__CreateLay(D_0035ecf8, 30002, 0, 0, D_00371968[half][0], D_00371968[half][2], 0, 0, 0);
  Tz__Layout__SetImageCache(D_0035ecf8);
  D_0035ecf4 = NewLayout();
  Tz__MenuUtil__CreateLay(D_0035ecf4, 30019, 0, 0, 33, 35, 0, 0, 0);
  Tz__Layout__SetImageCache(D_0035ecf4);
  if (func_001a6d08(10) && func_00244a10())
  {
    func_0028af40(D_0035ece8, 512);
    func_0028d980(D_0035ecfc, 30011, 0, 0, D_0035ecf0, 31, 33, 3971, 0);
    func_00139620(D_0035ecfc);
    func_001395f8(D_0035ecfc);
    D_0035ecfc[405] = 1;
    {
      u8 *q = D_0035ecfc + 24;
      *((u32 *) (q + 184)) |= 8;
    }
  }
  func_00244a60();
  p = func_00287dc0();
  func_0023d808(p, 30008);
  p->vt->f18(p, 0, 0x2000044d, 134, 2, 155, 221);
  func_0023e858(p, 0, -457.0f);
  func_0023e8b8(p, 0, 0.0f);
  func_0023e8d8(p, 0, 30.0f);
  {
    u8 *s = D_0035ed08;
    func_00139d78(*((s32 *) (s + 8)));
    func_0023e9b0(p, 0, inline_fn(*((s32 *) (s + 8))));
  }
  func_0023e690(p, 0, 135, -1);
  func_00287bd0(0, 0);
  func_00287cc0(0);
  n = func_002887c8();
  if (n)
  {
    Tz__HEFT__LoopAll();
    D_0035ed0c = 1;
    func_00288750(func_00244058);
  }
}
}  // namespace n00243740

// 00243cd8 (was src/anon/batch_w96.cpp)
namespace n00243cd8 {
u32 func_0023aa78(u32) asm("func_0023aa78");
s32 func_0023aa98(u32) asm("func_0023aa98");
struct Item36_w96 { u8 pad[8]; u8 name[8]; s8 sel; u8 pad17; u16 icon; u8 pad20[16]; };
extern Item36_w96 D_003719e8[] asm("D_003719e8");
extern u32 D_0035ecec asm("D_0035ecec");
extern u32 D_0035ecf0 asm("D_0035ecf0");
extern u32 D_0035ed08 asm("D_0035ed08");
void Tz__Select__SetItem(u32, s32, u32, u32, u32, u32, Item36_w96*, u8*) asm("Tz__Select__SetItem");
u8* func_002891b8(u32, s32) asm("func_002891b8");
void Tz__Select__SetExOffset(u32, s32, s32, u32) asm("Tz__Select__SetExOffset");
u32 func_0028dd90(s32) asm("func_0028dd90");
// mod10_classify_012
u32 func_0028ddd8(s32) asm("func_0028ddd8");
void func_001395f8(u8*) asm("func_001395f8");
void Tz__Select__SetCurrent(u32, s32, u32, u32, u32) asm("Tz__Select__SetCurrent");
void func_002b4388(u32, Item36_w96*, u32) asm("func_002b4388");
/*TARGET 00243cd8*/
// 0x001dd568: definition moved into src/anon/unit_001dd2b8.cpp

// Quicksort keys (descending) in [lo, hi], permuting the parallel ids array alongside.

// Builds the two-entry choice list and focuses the preselected entry.
void Tz__HEFT__SetupSel(void) asm("Tz__HEFT__SetupSel");
// 0x001dd568: definition moved into src/anon/unit_001dd2b8.cpp

// Quicksort keys (descending) in [lo, hi], permuting the parallel ids array alongside.

// Builds the two-entry choice list and focuses the preselected entry.
void Tz__HEFT__SetupSel(void) {
    s32 i;
    s32 sel = 0;
    for (i = 0; i < 2; i++) {
        u8* w;
        s32 h;
        if (D_003719e8[i].sel) sel = i;
        Tz__Select__SetItem(D_0035ecec, i, 0, 0, D_0035ecf0, D_003719e8[i].icon, &D_003719e8[i], D_003719e8[i].name);
        w = func_002891b8(D_0035ecec, i);
        Tz__Select__SetExOffset(D_0035ecec, i, func_0023aa78((u32)w + 24), 0);
        h = func_0023aa98((u32)w + 24);
        *(u32*)(w + 432) = func_0028dd90(h);
        *(u32*)(w + 428) = func_0028ddd8(h);
        func_001395f8(w);
    }
    Tz__Select__SetCurrent(D_0035ecec, sel, 1, 0, 2);
    func_002b4388(D_0035ed08, &D_003719e8[sel], 0);
}
}  // namespace n00243cd8

// 00243e30 (was src/anon/batch_w94.cpp)
namespace n00243e30 {
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0023f0c0(void*) asm("func_0023f0c0");
void func_0023f070(void*, s32, s32) asm("func_0023f070");
s32 func_0028acc8(void*) asm("func_0028acc8");
void func_0028ab20(void*) asm("func_0028ab20");
u32 func_002891e8(void*) asm("func_002891e8");
s32 func_00244ee8(u32) asm("func_00244ee8");
void func_0028da70(void*, s32) asm("func_0028da70");
extern void* D_0035ecf0 asm("D_0035ecf0");
extern void* D_0035ecf4 asm("D_0035ecf4");
extern void* D_0035ecf8 asm("D_0035ecf8");
extern void* D_0035ecfc asm("D_0035ecfc");
extern void* D_0035ed00 asm("D_0035ed00");
extern void* D_0035ece8 asm("D_0035ece8");
struct Ent243 { s16 a, b, mot; };
extern Ent243 D_00371968[] asm("D_00371968");
/*TARGET 00243e30*/
void Tz__HEFT__LoopAll(void) asm("Tz__HEFT__LoopAll");
void Tz__HEFT__LoopAll(void) {
    if (func_00139d78(D_0035ecf0) && func_0023f0c0(D_0035ecf0) != 32) func_0023f070(D_0035ecf0, 32, -1);
    if (func_0028acc8(D_0035ece8)) {
        func_0028ab20(D_0035ece8);
        s32 k = func_00244ee8(func_002891e8(D_0035ece8));
        if (func_00139d78(D_0035ecf8) && func_0023f0c0(D_0035ecf8) != D_00371968[k].mot)
            func_0023f070(D_0035ecf8, D_00371968[k].mot, -1);
    }
    if (func_00139d78(D_0035ecf4) && func_0023f0c0(D_0035ecf4) != 35) func_0023f070(D_0035ecf4, 35, -1);
    func_0028da70(D_0035ecfc, 33);
    func_0028da70(D_0035ed00, 41);
}
}  // namespace n00243e30

// 00243f48 (was src/anon/batch_w94.cpp)
namespace n00243f48 {
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028acc8(void*) asm("func_0028acc8");
void func_0028abe0(void*) asm("func_0028abe0");
void func_00244db8(void) asm("func_00244db8");
void func_0028ce38(void) asm("func_0028ce38");
extern void* D_0035ecf0 asm("D_0035ecf0");
extern void* D_0035ecf4 asm("D_0035ecf4");
extern void* D_0035ecf8 asm("D_0035ecf8");
extern void* D_0035ecfc asm("D_0035ecfc");
extern void* D_0035ed00 asm("D_0035ed00");
extern void* D_0035ece8 asm("D_0035ece8");
extern void* D_0035ecec asm("D_0035ecec");
typedef void (*VFn243)(void*);
#define VCALL20(o) (*(VFn243*)(*(u8**)(o) + 20))(o)
/*TARGET 00243f48*/
void func_00243f48(void) asm("func_00243f48");
void func_00243f48(void) {
    if (func_00139d78(D_0035ecf0)) VCALL20(D_0035ecf0);
    if (func_00139d78(D_0035ecf8)) VCALL20(D_0035ecf8);
    if (func_00139d78(D_0035ecf4)) VCALL20(D_0035ecf4);
    if (func_0028acc8(D_0035ece8)) func_0028abe0(D_0035ece8);
    if (func_0028acc8(D_0035ecec)) func_0028abe0(D_0035ecec);
    if (func_00139d78(D_0035ecfc)) VCALL20(D_0035ecfc);
    if (func_00139d78(D_0035ed00)) VCALL20(D_0035ed00);
    func_00244db8();
    func_0028ce38();
}
}  // namespace n00243f48

// 00244058 (was unwritten gap: pause callback)
namespace n00244058 {
extern u8 D_0035ed0c asm("D_0035ed0c");
void func_00244058(void) asm("func_00244058");
void func_00244058(void) { D_0035ed0c = 0; }
}  // namespace n00244058

// 00244068 (was src/anon/batch_w80.cpp)
namespace n00244068 {
// ---- unit 9 (good244.cpp)
extern u32 D_0035ece8 asm("D_0035ece8");
extern u32 D_0035ecec asm("D_0035ecec");
extern u32 D_0035ecf4 asm("D_0035ecf4");
extern u32 D_0035ecf8 asm("D_0035ecf8");
extern u32 D_0035ecf0 asm("D_0035ecf0");
s32 func_00287bc0(void) asm("func_00287bc0");
void Tz__MenuBase__SaveMode(void) asm("Tz__MenuBase__SaveMode");
// copy_globals_3words
s32 func_00287db0(void) asm("func_00287db0");
s32 func_0028acc8(u32) asm("func_0028acc8");
s32 func_00139d78(void*) asm("func_00139d78");
void func_00243f48(void) asm("func_00243f48");
void func_001039f8(void) asm("func_001039f8");
void func_00244148(void) asm("func_00244148");
void func_002442b8(void) asm("func_002442b8");
/*TARGET 00244068*/
s32 func_00244068(void) asm("func_00244068");
s32 func_00244068(void) {
    s32 m = func_00287bc0();
    Tz__MenuBase__SaveMode();  // copy_globals_3words
    if (func_00287db0()) {
        if (func_0028acc8(D_0035ece8) || func_0028acc8(D_0035ecec) || func_00139d78((void*)D_0035ecf0) || func_00139d78((void*)D_0035ecf4) || func_00139d78((void*)D_0035ecf8)) return 0;
        func_00243f48();
        func_001039f8();
        return 1;
    }
    switch (m) {
    case 0: func_00244148(); break;
    case 1: func_002442b8(); break;
    }
    return 0;
}
}  // namespace n00244068

// 00244148 (was src/anon/batch_wcx2.cpp)
namespace n00244148 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
extern u32 D_0035ece8 asm("D_0035ece8");
// 0022cc38: moved to src/sasa/event_layout.cpp (linked unit)

// --------------------
extern u8 D_0035ed0c asm("D_0035ed0c");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00289380_x8667(s32) asm("func_00289380");
s32 func_00289310_x8668(s32) asm("func_00289310");
s32 func_0028ae28_x8669(s32, s32) asm("func_0028ae28");
void Tz__HEFT__LoopAll() asm("Tz__HEFT__LoopAll");
void func_00287c90(s32) asm("func_00287c90");
void Tz__HEFT__CreateNewMark() asm("Tz__HEFT__CreateNewMark");
void func_00287df0_x8673(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_00244988() asm("func_00244988");
void func_002535b0(s32) asm("func_002535b0");
void func_00288658(s32, s32) asm("func_00288658");
void func_00243f48() asm("func_00243f48");
void func_00288670(void (*)()) asm("func_00288670");
void func_00287da0() asm("func_00287da0");
void Tz__HEFT__SetupSel() asm("Tz__HEFT__SetupSel");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 00244148*/
void func_00244148() asm("func_00244148");
void func_00244148() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x8667(D_0035ece8);
    if (D_0035ed0c) return;
    if (r != -1 || func_00289310_x8668(D_0035ece8)) {
        if (!func_0028ae28_x8669(D_0035ece8, 0)) Tz__HEFT__LoopAll();
    }
    if (!a && func_0028ae28_x8669(D_0035ece8, 0)) {
        func_00287c90(1);
        Tz__HEFT__CreateNewMark();
    }
    func_00287df0_x8673(r, func_00289310_x8668(D_0035ece8), 1, 0, 1);
    switch (r) {
    case -6:
        func_00244988();
        func_002535b0(3);
        func_00288658(2, 100);
        func_00288670(func_00243f48);
    case -4: case -2:
        func_00287da0();
        break;
    case 0: case 1:
        Tz__HEFT__SetupSel();
        func_00287bd0(1, 0);
        func_00287cc0(0);
        break;
    }
}
}  // namespace n00244148

// .rodata words read by other code (retail bytes, in place)
namespace r00371934 {
extern const u32 R_00371934[1] asm("D_00371934") __attribute__((aligned(4))) = { 0x0 };
extern const u32 R_00371938[1] asm("D_00371938") __attribute__((aligned(4))) = { 0x2f002e };
}  // namespace r00371934

// 002442b8 (was src/anon/batch_w1934_nsa.cpp)
namespace n002442b8 {
// w1934 retry batch (built with -fno-strict-aliasing).
struct W1934S36 { u8 b[36]; };
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00289380(u32) asm("func_00289380");
s32 func_00289310(u32) asm("func_00289310");
s32 func_0028acc8(u32) asm("func_0028acc8");
void func_0028abe0(u32) asm("func_0028abe0");
s32 func_002891e8(u32) asm("func_002891e8");
s32 func_00244ee8(s32) asm("func_00244ee8");
void func_002b4388(u32, W1934S36*, s32) asm("func_002b4388");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_0028ae28(u32, s32) asm("func_0028ae28");
void func_0028ab20(u32) asm("func_0028ab20");
void func_00287c90(s32) asm("func_00287c90");
s32 func_00287df0(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_0028aa40(u32) asm("func_0028aa40");
void func_00287b08(s16) asm("func_00287b08");
void func_00287da0(void) asm("func_00287da0");
extern u32 D_0035ecec asm("D_0035ecec");
extern u32 D_0035ece8 asm("D_0035ece8");
extern u32 D_0035ed08 asm("D_0035ed08");
extern W1934S36 D_003719a0[] asm("D_003719a0");
extern s16 D_00371938[] asm("D_00371938");
/*TARGET 002442b8*/
void func_002442b8(void) asm("func_002442b8");
void func_002442b8(void) {
    s32 i;
    s32 m = func_00287cd0();
    s32 r = func_00289380(D_0035ecec);
    if (m == 2) {
        if (func_0028acc8(D_0035ecec)) {
            if (r != -1 || func_00289310(D_0035ecec)) func_0028abe0(D_0035ecec);
        } else {
            i = func_00244ee8(func_002891e8(D_0035ece8));
            func_002b4388(D_0035ed08, &D_003719a0[i], 0);
            func_00287bd0(0, 0);
            func_00287cc0(1);
        }
        return;
    }
    if (r != -1 || func_00289310(D_0035ecec)) {
        if (!func_0028ae28(D_0035ecec, 0)) func_0028ab20(D_0035ecec);
    }
    if (m == 0) {
        if (func_0028ae28(D_0035ecec, 0)) func_00287c90(1);
    }
    func_00287df0(r, func_00289310(D_0035ecec), 0, 0, 1);
    switch (r) {
    case -4:
    case -3:
    case -1:
        break;
    case -2:
    case 1:
        func_0028aa40(D_0035ecec);
        func_00287c90(1);
        break;
    case 0:
        i = func_00244ee8(func_002891e8(D_0035ece8));
        func_00287b08(D_00371938[i]);
        func_00287da0();
        break;
    }
}
}  // namespace n002442b8

// 002444b8 (was src/anon/batch_w1579_g.cpp)
namespace n002444b8 {
struct T1968 { s16 a; s16 b; s16 c; };
extern T1968 D_00371968[] asm("D_00371968");
extern s32 D_0035ece8 asm("D_0035ece8");
extern s32 D_0035ecec asm("D_0035ecec");
extern s32 D_0035ecf0 asm("D_0035ecf0");
extern s32 D_0035ecf4 asm("D_0035ecf4");
extern s32 D_0035ecf8 asm("D_0035ecf8");
extern s32 D_0035ecfc asm("D_0035ecfc");
extern s32 D_0035ed00 asm("D_0035ed00");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00287cd0(void) asm("func_00287cd0");
s32 func_00287db0(void) asm("func_00287db0");
s32 func_002887c8(void) asm("func_002887c8");
void func_0028dae0(s32, s32) asm("func_0028dae0");
s32 func_0028acc8(s32) asm("func_0028acc8");
s32 func_0028acb8(s32) asm("func_0028acb8");
void func_0028aa40(s32) asm("func_0028aa40");
s32 func_00139d78(s32) asm("func_00139d78");
s32 func_002891e8(s32) asm("func_002891e8");
s32 func_00244ee8(s32) asm("func_00244ee8");
void func_0028dac8(s32, s32) asm("func_0028dac8");
void func_0028ce38(void) asm("func_0028ce38");
void func_00244db8(void) asm("func_00244db8");
void func_00244888(void) asm("func_00244888");
s32 func_0028d008(s32) asm("func_0028d008");
void Tz__MenuCursor__Create(s32, s32, s32, s32, s32, s32) asm("Tz__MenuCursor__Create");
s32 func_002891d0(s32) asm("func_002891d0");
void Tz__MenuCursor__SetParent(s32, s32) asm("Tz__MenuCursor__SetParent");
void func_0028cdb8(s32) asm("func_0028cdb8");
s32 func_00287c50(void) asm("func_00287c50");
void Tz__MenuCursor__SetType(s32, s32) asm("Tz__MenuCursor__SetType");
void Tz__HEFT__DrawSelector(s32, s32, s32) asm("Tz__HEFT__DrawSelector");
struct NoTail4b8 { ~NoTail4b8() {} };
/*TARGET 002444b8*/
void Tz__HEFT__Draw(void) asm("Tz__HEFT__Draw");
void Tz__HEFT__Draw(void) {
    NoTail4b8 nt;
    s32 mode = func_00287bc0();
    s32 sub = func_00287cd0();
    if (func_00287db0() != 0) {
        if (func_002887c8() == 0) {
            func_0028dae0(D_0035ecf0, 31);
            if (func_0028acc8(D_0035ece8) != 0 && func_00139d78(D_0035ecf8) != 0) {
                s32 i = func_00244ee8(func_002891e8(D_0035ece8));
                func_0028dae0(D_0035ecf8, D_00371968[i].b);
            }
            func_0028dae0(D_0035ecf4, 34);
            if (func_0028acc8(D_0035ece8) != 0 && func_0028acb8(D_0035ece8) == 0) {
                func_0028aa40(D_0035ece8);
            }
            if (func_0028acc8(D_0035ecec) != 0 && func_0028acb8(D_0035ecec) == 0) {
                func_0028aa40(D_0035ecec);
            }
            func_0028dac8(D_0035ecfc, 32);
            func_0028dac8(D_0035ed00, 40);
        }
        func_0028ce38();
        func_00244db8();
    }
    func_00244888();
    if (func_00287db0() == 0) {
        s32 obj = mode == 0 ? D_0035ece8 : D_0035ecec;
        s32 side = mode != 0;
        if (func_0028acc8(obj) != 0 && sub == 1) {
            if (func_0028d008(side) == 0) {
                Tz__MenuCursor__Create(side, 0, 0, D_0035ecf0, 15, 14);
                Tz__MenuCursor__SetParent(side, func_002891d0(obj));
            }
        } else if (sub == 2 && func_0028d008(side) != 0) {
            func_0028cdb8(side);
        }
        if (func_00287c50() != 0 && func_0028d008(0) != 0) {
            Tz__MenuCursor__SetType(0, side);
        }
        Tz__HEFT__DrawSelector(obj, mode, side);
    }
}
}  // namespace n002444b8

// 00244708 (was src/anon/batch_w279.cpp)
namespace n00244708 {
// ---- Tz__HEFT__DrawSelector
s32 func_00287cd0(void*) asm("func_00287cd0");
s32 func_00289310(void*) asm("func_00289310");
s32 func_002891e8(void*) asm("func_002891e8");
void func_002890e0(void*, s32, s32, s32, s32) asm("func_002890e0");
void func_00289038(void*, s32, s32, s32, s32, s32, s32) asm("func_00289038");
s32 func_00244ee8(s32) asm("func_00244ee8");
void func_0023f070(void*, s32, s32) asm("func_0023f070");
s32 func_0028d008(void*) asm("func_0028d008");
s32 func_002891d0(void*) asm("func_002891d0");
void Tz__MenuCursor__SetParent(void*, s32) asm("Tz__MenuCursor__SetParent");
// record408_set_and_refresh
void func_002b4388(void*, void*, s32) asm("func_002b4388");
void Tz__HEFT__UpdateNewMark(void) asm("Tz__HEFT__UpdateNewMark");
void func_00244b38(void) asm("func_00244b38");
extern void* D_0035ecf8 asm("D_0035ecf8");
extern void* D_0035ed08 asm("D_0035ed08");
struct W279S6 { s16 a; s16 b; s16 c; };
extern W279S6 D_00371968[] asm("D_00371968");
struct W279S36 { u8 x[36]; };
extern W279S36 D_003719a0[] asm("D_003719a0");
extern W279S36 D_003719e8[] asm("D_003719e8");
/*TARGET 00244708*/
void Tz__HEFT__DrawSelector(void* a0, s32 a1, void* a2) asm("Tz__HEFT__DrawSelector");
void Tz__HEFT__DrawSelector(void* a0, s32 a1, void* a2) {
  if (func_00287cd0(a0) != 1) return;
  if (!func_00289310(a0)) return;
  s32 s3 = func_002891e8(a0);
  func_002890e0(a0, 1, 2, 0, -1);
  func_00289038(a0, s3, 1, 1, 2, 0, -1);
  if (a1 == 0) {
    func_0023f070(D_0035ecf8, D_00371968[func_00244ee8(s3)].c, -1);
  }
  if (func_0028d008(a2)) {
    Tz__MenuCursor__SetParent(a2, func_002891d0(a0));  // record408_set_and_refresh
  }
  if (a1 == 0) {
    func_002b4388(D_0035ed08, &D_003719a0[func_00244ee8(s3)], 0);
    Tz__HEFT__UpdateNewMark();
  } else {
    func_002b4388(D_0035ed08, &D_003719e8[s3], 0);
  }
  func_00244b38();
}
}  // namespace n00244708

// 00244888 (was src/anon/batch_wcx.cpp)
namespace n00244888 {
extern u8* D_0035ece8 asm("D_0035ece8");
extern u8* D_0035ecec asm("D_0035ecec");
s32 func_002892f8(u8*) asm("func_002892f8");
s32 func_0028acc8(u8*) asm("func_0028acc8");
void func_00288e88(u8*) asm("func_00288e88");
/*TARGET 00244888*/
void func_00244888(void) asm("func_00244888");
void func_00244888(void)
{
    if (D_0035ece8) {
        s32 a = func_002892f8(D_0035ece8);
        if (!func_0028acc8(D_0035ece8) && a) func_00288e88(D_0035ece8);
    }
    if (D_0035ecec) {
        s32 a = func_002892f8(D_0035ecec);
        if (!func_0028acc8(D_0035ecec) && a) func_00288e88(D_0035ecec);
    }
}
}  // namespace n00244888

// 00244938 (was src/anon/batch_w212.cpp)
namespace n00244938 {
// obj_get_attach_or_alt
extern s32 func_001a6d08(s32) asm("_ZN2YS8MENUFLAG5CheckEi");
/*TARGET 00244938*/
// 0x001bff88: definition moved into src/anon/unit_001bff88.cpp

u32 func_00244938(u32 x) asm("func_00244938");
// 0x001bff88: definition moved into src/anon/unit_001bff88.cpp

u32 func_00244938(u32 x) {
    u32 r = 1;
    if (x == 0) { if (func_001a6d08(1) != 0) r = func_001a6d08(118); }
    else r = func_001a6d08(1);
    return r;
}
}  // namespace n00244938

// 00244988 (was src/anon/tiny_auto80_queue.cpp)
namespace n00244988 {
extern u32 D_0035ece8 asm("D_0035ece8");
void func_0023fc40(...) asm("func_0023fc40");
u32 func_0023fd30(...) asm("func_0023fd30");
u32 func_002891e8(...) asm("func_002891e8");
/*TARGET 00244988*/
void func_00244988() asm("_Z13func_00244988v");
void func_00244988() {
    func_0023fd30();  // global_flag_nonzero
    u32 v0 = func_002891e8(D_0035ece8);
    func_0023fc40(&v0, 4);
}
}  // namespace n00244988

// 002449c0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002449c0 {
extern u32 D_0035ece8 asm("D_0035ece8");
void func_0023fcd0(...) asm("func_0023fcd0");
u32 func_0023fd30(...) asm("func_0023fd30");
void Tz__Select__SetCurrent(...) asm("Tz__Select__SetCurrent");
/*TARGET 002449c0*/
void func_002449c0() asm("_Z13func_002449c0v");
void func_002449c0() {
    u32 sp0;
    if (func_0023fd30() != 0) {  // global_flag_nonzero
        func_0023fcd0(&sp0);
        Tz__Select__SetCurrent(D_0035ece8, sp0, 0, (u32)-1, (u32)-1);
        func_0023fd30();  // global_flag_nonzero
    }
}
}  // namespace n002449c0

// 00244a10 (was src/anon/batch_w25.cpp)
namespace n00244a10 {
u8* func_001d56c8(u32) asm("func_001d56c8");
s32 func_00276c18(void) asm("func_00276c18");
/*TARGET 00244a10*/
s32 func_00244a10(void) asm("func_00244a10");
s32 func_00244a10(void) {
    s32 r = 0;
    if (*func_001d56c8(8) >= 2 || func_00276c18()) r = 1;
    return r;
}
}  // namespace n00244a10

// 00244a60 (was src/anon/batch_w80.cpp)
namespace n00244a60 {
// ---- unit 10 (good244a.cpp)
struct U10_CurSub { u8 pad[184]; u32 f184; };
struct U10_CurObj { u8 pad[24]; U10_CurSub sub; u8 pad2[392 - 212]; u32 f392; u8 pad3[405 - 396]; u8 f405; u8 pad4[2]; u8* f408; u8 pad5[428 - 412]; u32 f428; u32 f432; };
extern union { U10_CurObj* p; u32 u; } U10_D_0035ed00_u asm("D_0035ed00");
#define U10_D_0035ed00 (U10_D_0035ed00_u.p)
extern u32 D_0035ecf0 asm("D_0035ecf0");
extern union { u8* p; u32 u; } U10_D_0035ed10_u asm("D_0035ed10");
#define U10_D_0035ed10 (U10_D_0035ed10_u.p)
s32 func_001a6d08(u32) asm("func_001a6d08");
void func_0028d980(...) asm("func_0028d980");
void func_00139620(U10_CurObj*) asm("func_00139620");
void func_001395f8(U10_CurObj*) asm("func_001395f8");
void func_002fde18(void*, s32, u32) asm("func_002fde18");
void func_00244b38(void) asm("func_00244b38");
static inline void U10_w80_cur_setflag(U10_CurSub* s, u32 f) { s->f184 |= f; }
/*TARGET 00244a60*/
void func_00244a60(void) asm("func_00244a60");
void func_00244a60(void) {
    if (!func_001a6d08(10)) return;
    func_0028d980(U10_D_0035ed00, 30011, 0, 0, D_0035ecf0, 39, 41, -1, 100);
    func_00139620(U10_D_0035ed00);
    func_001395f8(U10_D_0035ed00);
    U10_D_0035ed00->f432 = 2;
    U10_D_0035ed00->f405 = 1;
    U10_w80_cur_setflag(&U10_D_0035ed00->sub, 8);
    func_002fde18(U10_D_0035ed10, 0, 32);
    U10_D_0035ed00->f408 = U10_D_0035ed10;
    func_00244b38();
}
}  // namespace n00244a60

// 00244b38 (was src/anon/batch_w79.cpp)
namespace n00244b38 {
s32 func_00139d78(u32) asm("func_00139d78");
extern u32 D_0035ed00 asm("D_0035ed00");
extern u8* D_0035ed10 asm("D_0035ed10");
extern u32 D_0035ece8 asm("D_0035ece8");
void func_002fde18(void*, s32, u32) asm("func_002fde18");
u32 func_002891e8(u32) asm("func_002891e8");
s32 func_00244ee8(u32) asm("func_00244ee8");
void func_00139858(s32) asm("func_00139858");
void func_001398d0(s32) asm("func_001398d0");
u8* func_001d56c8(s32) asm("func_001d56c8");
u32 func_00192cc0(u8*, void*, u32) asm("func_00192cc0");
s32 func_00192b30(u32) asm("func_00192b30");
u32 func_00192048(u16) asm("func_00192048");
void func_00192c90(u32, u8*) asm("func_00192c90");
extern u8 D_00371958[] asm("D_00371958");
/*TARGET 00244b38*/
// 0x001ae4c0: definition moved into src/anon/unit_001ada38.cpp

void func_00244b38(void) asm("func_00244b38");
// 0x001ae4c0: definition moved into src/anon/unit_001ada38.cpp

void func_00244b38(void) {
    u8* buf;
    u8* p;
    if (func_00139d78(D_0035ed00) == 0) return;
    func_002fde18(D_0035ed10, 0, 32);
    if (func_00244ee8(func_002891e8(D_0035ece8)) == 0) func_001398d0(100);
    else func_00139858(100);
    buf = D_0035ed10;
    p = func_001d56c8(8);
    if (*p != 3) {
        func_00192c90(func_00192048(0xcb9b), buf);
    } else {
        s32 n = func_00192b30(func_00192cc0(buf, D_00371958, *(u32*)(p + 4)));
        func_00192c90(func_00192048(0xcb98), buf + n);
    }
}
}  // namespace n00244b38

// 00244c30 (was src/anon/batch_wcx2.cpp)
namespace n00244c30 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
extern s8 D_0035ed14 asm("D_0035ed14");
extern u8* D_0035ed04 asm("D_0035ed04");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern u32 D_0035ece8 asm("D_0035ece8");
extern u32 D_0035ecf0 asm("D_0035ecf0");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_00244938(s32) asm("func_00244938");
u8* func_002891b8(u32, s32) asm("func_002891b8");
void func_0028d8c0_110390(u8*, s32, s32, s32, u32, s32, s32, s32) asm("func_0028d8c0");
void func_0028dcc0_110390(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*) asm("func_00139648");
u32 func_0023aa18(u8*) asm("func_0023aa18");
u32 func_0023aa38(u8*) asm("func_0023aa38");
void func_00138c68(u8*, u32, u32) asm("func_00138c68");
void Tz__HEFT__UpdateNewMark(void) asm("Tz__HEFT__UpdateNewMark");
/*TARGET 00244c30*/
void Tz__HEFT__CreateNewMark(void) asm("Tz__HEFT__CreateNewMark");
void Tz__HEFT__CreateNewMark(void)
{
    if (!D_0035ed14) return;
    if (func_00139d78(D_0035ed04)) return;
    s32 id = D_0035f3d4 + 1;
    s32 k = 0;
    for (s32 i = 0; i < 2; i++) {
        if (!func_00244938(i)) continue;
        u8* o = func_002891b8(D_0035ece8, k);
        u8* a = o + 24;
        if ((u8)((D_0035ed14 >> i) & 1)) {
            func_0028d8c0_110390(D_0035ed04 + k * 408, id, 0, 0, D_0035ecf0, 38, -1, 0);
            func_0028dcc0_110390(D_0035ed04 + k * 408, o);
            func_00139648(D_0035ed04 + k * 408);
            u32 x = func_0023aa18(a);
            func_00138c68(D_0035ed04 + k * 408, x, func_0023aa38(a));
        }
        k++;
    }
    Tz__HEFT__UpdateNewMark();
}
}  // namespace n00244c30

// 00244db8 (was src/anon/batch_w41.cpp)
namespace n00244db8 {
struct W41VO2 { void** vt; };
extern u8* D_0035ed04 asm("D_0035ed04");
u32 func_00139d78(u8*) asm("func_00139d78");
/*TARGET 00244db8*/
void func_00244db8(void) asm("func_00244db8");
void func_00244db8(void) {
    for (s32 i = 0; i < 2; i++) {
        u32 off = i * 408;
        if (func_00139d78(D_0035ed04 + off)) {
            W41VO2* o = (W41VO2*)(off + (u32)D_0035ed04);
            ((void (*)(W41VO2*))o->vt[5])(o);
        }
    }
}
}  // namespace n00244db8

// 00244e28 (was src/anon/batch_w89.cpp)
namespace n00244e28 {
extern u32 D_0035ece8 asm("D_0035ece8");
extern s8 D_0035ed14 asm("D_0035ed14");
extern u8* D_0035ed04 asm("D_0035ed04");
s32 func_002891e8(u32) asm("func_002891e8");
s32 func_00244ee8(s32) asm("func_00244ee8");
s32 func_00139d78(void*) asm("func_00139d78");
void func_00138c10(u8*, s32) asm("func_00138c10");
void func_00243230(s32, s32) asm("func_00243230");
/*TARGET 00244e28*/
void Tz__HEFT__UpdateNewMark(void) asm("Tz__HEFT__UpdateNewMark");
void Tz__HEFT__UpdateNewMark(void) {
    s32 i = func_002891e8(D_0035ece8);
    s32 b = func_00244ee8(i);
    u8 off = !((D_0035ed14 >> b) & 1);
    if (off) return;
    if (func_00139d78(D_0035ed04 + i * 408)) {
        u8* e = D_0035ed04 + i * 408;
        if (*(s32*)(e + 388) != 37) func_00138c10(e, 37);
    }
    func_00243230(3, b);
}
}  // namespace n00244e28

// 00244ee8 (was src/anon/tiny_auto80_harvest_force0.cpp)
namespace n00244ee8 {
u32 func_00244938(u32, u32, u32, u32) asm("_Z13func_00244938jjjj");
/*TARGET 00244ee8*/
u32 func_00244ee8(u32 a0, u32 a1, u32 a2, u32 a3) asm("_Z13func_00244ee8jjjj");
u32 func_00244ee8(u32 a0, u32 a1, u32 a2, u32 a3) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r2;
    r2 = r4;
    if (r4 == 0u) {
    u32 (*fp_call0_00244938)() = (u32(*)())func_00244938;
        r2 = fp_call0_00244938();
        r2 = ((u32)r2 < 0x00000001u);
    }
    return r2;
}
}  // namespace n00244ee8

// 00244f10 (was src/anon/batch_w1576.cpp)
namespace n00244f10 {
struct Alloc { void* (**vt)(Alloc*, u32, void*); };
struct Holder { u8 pad[0x14]; Alloc* al; };
extern Holder* D_00347f80 asm("D_00347f80");
extern u8 D_00347e60 asm("D_00347e60");
extern s32 D_0035ed20 asm("D_0035ed20");
extern s32 D_0035ed24 asm("D_0035ed24");
extern s32 D_0035ed28 asm("D_0035ed28");
extern s32 D_0035ed2c asm("D_0035ed2c");
extern s32 D_0035ed30 asm("D_0035ed30");
extern void* D_0035ed34 asm("D_0035ed34");
extern s32 D_0035ed38 asm("D_0035ed38");
extern s8 D_0035ed3c asm("D_0035ed3c");
extern s32 D_0035ed40 asm("D_0035ed40");
extern s8 D_0035ed44 asm("D_0035ed44");
void func_00287b18(s32, s32) asm("func_00287b18");
s32 func_00288be8(s32) asm("func_00288be8");
void func_002889f0(s32, s32, s32) asm("func_002889f0");
void func_00288f48(s32, s32, s32, s32, s32) asm("func_00288f48");
void func_002b3df8(s32) asm("func_002b3df8");
s32 func_00103570(void) asm("func_00103570");
s32 func_001063c0(s32, s32) asm("func_001063c0");
void Tz__JmDic__Init(s32) asm("Tz__JmDic__Init");
void func_002fde18(s32, s32, s32) asm("func_002fde18");
void func_00239700(void*) asm("func_00239700");
s32* func_00103eb0(void) asm("func_00103eb0");
void TASK_MANAGER__create_thread(s32, s32, s32, void*, s32) asm("TASK_MANAGER__create_thread");
void PauseThread_(void*) asm("_ZN2Tz4HECO11PauseThreadEP4TASK");
typedef void* (*AF)(s32, u32, void*);
extern s32 D_0032ba14_i asm("D_0032ba14");
static inline void* Al(u32 n) { s32 a = D_0032ba14_i; return (*(AF*)*(s32*)a)(a, n, __builtin_return_address(0)); }
/*TARGET 00244f10*/
void Tz__HECO__Init(void) asm("Tz__HECO__Init");
void Tz__HECO__Init(void) {
    s32 v;
    func_00287b18(4, 3);
    v = func_00288be8(0x38);
    func_002889f0(v, 4, 1);
    D_0035ed20 = v;
    v = func_00288be8(0x38);
    func_002889f0(v, 2, 0);
    D_0035ed24 = v;
    func_00288f48(v, 0x40, 0x80, 0, 0);
    D_0035ed28 = 0;
    D_0035ed2c = 0;
    D_0035ed30 = 0;
    v = (s32)Al(12);
    func_002b3df8(v);
    D_0035ed38 = v;
    D_0035ed3c = 0;
    v = func_001063c0(0x394c, func_00103570());
    Tz__JmDic__Init(v);
    D_0035ed40 = v;
    v += 0x3948;
    func_002fde18(v, 0, 4);
    {
        Alloc* al = D_00347f80->al;
        s32* p = (s32*)(*al->vt)(al, 0x664, 0);
        u8* base = (u8*)(p + 1);
        u8* q = base;
        s32 i = 3;
        *p = 4;
        do {
            *(s32*)(q + 12) = 0;
            *(void**)q = &D_00347e60;
            i--;
            func_00239700(q + 0x18);
            q += 0x198;
        } while (i != -1);
        D_0035ed34 = base;
    }
    D_0035ed44 = 0;
    TASK_MANAGER__create_thread(func_00103eb0()[1], 0, 2000, (void*)PauseThread_, 0x1000);
}
}  // namespace n00244f10

// 002450c8 (was src/anon/batch_w1612.cpp)
namespace n002450c8 {
struct El {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~El();
    u8 pad[404];
};
struct Ek {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~Ek();
    u8 pad[432];
};
struct AV { void* a; void (*free)(void*, void*); };
struct AO { AV* vt; };
struct AH { u8 pad[20]; AO* a; };
extern AH* D_00347f80 asm("D_00347f80");
struct El2 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual ~El2();
    u8 pad[404];
    static void operator delete[](void* p) { D_00347f80->a->vt->free(D_00347f80->a, p); }
};
struct DV { void* a[4]; void (*del)(void*); };
struct DO { DV* vt; };
void func_0031acc0(void*) asm("func_0031acc0");
void func_00239870(void*) asm("func_00239870");
void func_00106420(void*) asm("func_00106420");
void func_0031a840(void*) asm("func_0031a840");
struct B0 { ~B0() { func_0031a840(this); } };
extern u8 D_00347e60[] asm("D_00347e60");
struct M24 { ~M24() { func_00239870(this); } };
struct B : B0 { u8 pad[24]; M24 m; u8 pad2[411]; ~B() { *(u8**)this = D_00347e60; } };
struct M436 { u8 pad[436]; ~M436() { func_0031acc0(this); } };
struct Big {
    B b; M436 m; Ek a[4]; Ek b2[4]; Ek c[4]; Ek d[4]; El e[4]; El f[4]; El g[4]; El h[4];
    static void operator delete(void* p) { func_00106420(p); }
};
extern void* D_0035ed20 asm("D_0035ed20");
extern void* D_0035ed24 asm("D_0035ed24");
extern DO* D_0035ed28 asm("D_0035ed28");
extern DO* D_0035ed2c asm("D_0035ed2c");
extern DO* D_0035ed30 asm("D_0035ed30");
extern El2* D_0035ed34 asm("D_0035ed34");
extern void* D_0035ed38 asm("D_0035ed38");
extern Big* D_0035ed40 asm("D_0035ed40");
extern AO* D_0032ba14 asm("D_0032ba14");
void func_00288b00(void*) asm("func_00288b00");
void func_00288c20(void*) asm("func_00288c20");
void func_002b3fb0(void*) asm("func_002b3fb0");
/*TARGET 002450c8*/
// Frees the module's globals; the big object's destructor and the array delete are inlined.
void Tz__HECO__Exit(void) asm("Tz__HECO__Exit");
// Frees the module's globals; the big object's destructor and the array delete are inlined.
void Tz__HECO__Exit(void) {
    void* p;
    if ((p = D_0035ed20) != 0) { func_00288b00(p); func_00288c20(p); D_0035ed20 = 0; }
    if ((p = D_0035ed24) != 0) { func_00288b00(p); func_00288c20(p); D_0035ed24 = 0; }
    if (D_0035ed28) { D_0035ed28->vt->del(D_0035ed28); D_0035ed28 = 0; }
    if (D_0035ed2c) { D_0035ed2c->vt->del(D_0035ed2c); D_0035ed2c = 0; }
    if (D_0035ed30) { D_0035ed30->vt->del(D_0035ed30); D_0035ed30 = 0; }
    if ((p = D_0035ed38) != 0) { func_002b3fb0(p); D_0032ba14->vt->free(D_0032ba14, p); D_0035ed38 = 0; }
    if (D_0035ed40) {
        delete D_0035ed40;
        D_0035ed40 = 0;
    }
    if (D_0035ed34) {
        delete[] D_0035ed34;
        D_0035ed34 = 0;
    }
}
}  // namespace n002450c8

// 00245400 (was src/tozawa/smenu_heco.cpp)
namespace Tz { // method 00245400
extern u32 D_0035ed18 asm("D_0035ed18");
extern u32 D_0035ed1c asm("D_0035ed1c");
u32 func_00246840(u32) asm("func_00246840");
void func_002430d8(u32) asm("func_002430d8");
void func_00102448(u32, u32) asm("func_00102448");
void Tz__HECO__Setup() asm("Tz__HECO__Setup");
void YI__IMAGE_CACHE__Clear() asm("YI__IMAGE_CACHE__Clear");
// clear_64_entries_24
extern "C" u32 Tz__HECO__Control() asm("Tz__HECO__Control");
void Tz__HECO__Draw() asm("Tz__HECO__Draw");
/*TARGET 00245400*/
void HECO::PauseThread(TASK* a0) {
    u32 s0 = (u32)a0;
    if (func_00246840((u32)a0) != 0) {
        func_002430d8(D_0035ed1c);
    } else {
        func_002430d8(D_0035ed18);
    }

    func_00102448(s0, 1);
    Tz__HECO__Setup();

    while (1) {
        YI__IMAGE_CACHE__Clear();  // clear_64_entries_24
        if (Tz__HECO__Control() != 0) {
            return;
        }
        Tz__HECO__Draw();
        func_00102448(s0, 0);
    }
}
}  // Tz

// 00245488 (was src/anon/batch_w3915.cpp)
namespace n00245488 {
void func_00139620(u8*) asm("func_00139620");
void func_001395f8(u8*) asm("func_001395f8");
void func_00287cc0(s32) asm("func_00287cc0");
struct Ent36 { u8 pad0[8]; u8 name[8]; s8 f10; u8 pad11; u16 f12; u8 pad14[16]; };
u8* func_0023ee30(u32) asm("func_0023ee30");
void func_0031a838(u8*) asm("func_0031a838");
void YI__IMAGE_FREEZE__IMAGE_FREEZE(u8*) asm("YI__IMAGE_FREEZE__IMAGE_FREEZE");
void YI__LAYOUT__LAYOUT(u8*) asm("YI__LAYOUT__LAYOUT");
void Tz__MenuUtil__CreateLay(u8*, s32, s32, s32, s32, s32, s32, s32, s32) asm("Tz__MenuUtil__CreateLay");
void Tz__Layout__SetImageCache(u8*) asm("Tz__Layout__SetImageCache");
Ent36* func_00246868(void) asm("func_00246868");
s32 func_00246968(s32) asm("func_00246968");
s32 func_00246840(void) asm("func_00246840");
s32 Tz__SubMenu__isSetNew(s32, s32) asm("Tz__SubMenu__isSetNew");
void func_00288d80_b(void*, s32, s32, s32, u8*, s32, Ent36*, u8*) asm("Tz__Select__SetItem");
u8* func_002891b8_b(void*, s32) asm("func_002891b8");
s32 func_0023aa98(u8*) asm("func_0023aa98");
s32 func_0023aa78(u8*) asm("func_0023aa78");
s32 func_0028dd90(s32) asm("func_0028dd90");
s32 func_0028ddd8(s32) asm("func_0028ddd8");
s32 func_002892f8(void*) asm("func_002892f8");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void Tz__Select__SetCurrent(void*, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void func_002467f0(void) asm("func_002467f0");
s32 func_002891e8(void*) asm("func_002891e8");
s32 func_002469a0(s32) asm("func_002469a0");
s16* func_002468a0(s32) asm("func_002468a0");
void func_002b4070(void*, s32, u8*, u8*, u8*, u8*, u8*, u8*, u8*, s32, Ent36*, s32, s32) asm("func_002b4070");
s32 func_00246a08(void) asm("func_00246a08");
void func_0028af40(void*, s32) asm("func_0028af40");
void func_0028d980_b(u8*, s32, s32, s32, u8*, s32, s32, s32, s32) asm("func_0028d980");
void Tz__HECO__CleateSelInfo(void) asm("Tz__HECO__CleateSelInfo");
void Tz__HECO__UpdateScore(void) asm("Tz__HECO__UpdateScore");
void Tz__HECO__UpdateMaker(s32) asm("Tz__HECO__UpdateMaker");
void func_00245968(void) asm("func_00245968");
void func_00287bd0(s32, s32) asm("func_00287bd0");
s32 func_002887c8(void) asm("func_002887c8");
void Tz__HECO__LoopAll(void) asm("Tz__HECO__LoopAll");
void func_00245dc0(void) asm("func_00245dc0");
void func_00288750(void (*)(void)) asm("func_00288750");
extern u8 D_00347f98[] asm("D_00347f98");
extern u8 D_0035eb98[] asm("D_0035eb98");
extern void* D_0035ed20 asm("D_0035ed20");
extern u8* D_0035ed28 asm("D_0035ed28");
extern u8* D_0035ed2c asm("D_0035ed2c");
extern u8* D_0035ed30 asm("D_0035ed30");
extern void* D_0035ed38 asm("D_0035ed38");
extern u8 D_0035ed3c asm("D_0035ed3c");
extern u8* D_0035ed40 asm("D_0035ed40");
extern u8 D_0035ed44 asm("D_0035ed44");
extern u8 D_00371ad0[] asm("D_00371ad0");
extern u8 D_00371b08[] asm("D_00371b08");
extern u8 D_00371b10[] asm("D_00371b10");
extern u8 D_00371b18[] asm("D_00371b18");
extern u8 D_00371b20[] asm("D_00371b20");
extern u8 D_00371b28[] asm("D_00371b28");
static inline u8* NewLayout(void) {
    u8* o = func_0023ee30(160);
    *(u8**)o = D_00347f98;
    func_0031a838(o + 12);
    *(u8**)o = D_0035eb98;
    YI__IMAGE_FREEZE__IMAGE_FREEZE(o + 24);
    YI__LAYOUT__LAYOUT(o + 48);
    return o;
}
/*TARGET 00245488*/
// 00245488: pure C++ (-O2). Loop 1 keeps the func_0023aa98 result in its own pointer p, and
// the tail block uses its own local, which gives the original register copies before loop 2.
void Tz__HECO__Setup(void) asm("Tz__HECO__Setup");
// 00245488: pure C++ (-O2). Loop 1 keeps the func_0023aa98 result in its own pointer p, and
// the tail block uses its own local, which gives the original register copies before loop 2.
void Tz__HECO__Setup(void) {
    s32 i;
    s32 n;
    s32 sel;
    s32 w;
    s32 half;
    s32 k;
    u8* o;
    u8* p;
    Ent36* tbl;

    sel = 0;
    k = 0;
    tbl = func_00246868();
    D_0035ed3c = 0;
    D_0035ed28 = NewLayout();
    Tz__MenuUtil__CreateLay(D_0035ed28, 30002, 0, 0, 30, 32, 0, 0, 0);
    Tz__Layout__SetImageCache(D_0035ed28);
    for (i = 0; i < 4; i++) {
        if (func_00246968(i)) {
            if (Tz__SubMenu__isSetNew(4, func_00246840() ? i + 4 : i) == 0) D_0035ed44 |= 1 << i;
            if (tbl[i].f10) sel = i;
            func_00288d80_b(D_0035ed20, k, 0, 0, D_0035ed28, tbl[i].f12, &tbl[i], tbl[i].name);
            o = func_002891b8_b(D_0035ed20, k++);
            p = (u8*)func_0023aa98(o + 24);
            *(s32*)(o + 432) = func_0028dd90((s32)p);
            *(s32*)(o + 428) = func_0028ddd8((s32)p);
            func_001395f8(o);
        }
    }
    func_002892f8(D_0035ed20);
    n = func_002892f8(D_0035ed20);
    w = func_0023aa78(func_002891b8_b(D_0035ed20, 0) + 24);
    half = (w * n) / 2;
    for (i = 0; i < n; i++) {
        func_00138c68(func_002891b8_b(D_0035ed20, i), 0, i * w - half);
    }
    Tz__Select__SetCurrent(D_0035ed20, sel, 0, -1, -1);
    func_002467f0();
    sel = func_002891e8(D_0035ed20);
    Tz__Select__SetCurrent(D_0035ed20, sel, 1, 0, 2);
    half = func_002469a0(sel);
    func_002b4070(D_0035ed38, 30003, D_0035ed28, D_00371ad0, D_00371b08, D_00371b10, D_00371b18, D_00371b20, D_00371b28, 0xcb96, &tbl[half], 0, 0);
    D_0035ed30 = NewLayout();
    {
        s16* pp = func_002468a0(half);
        Tz__MenuUtil__CreateLay(D_0035ed30, 30002, 0, 0, pp[0], pp[2], 0, 0, 0);
    }
    Tz__Layout__SetImageCache(D_0035ed30);
    D_0035ed2c = NewLayout();
    Tz__MenuUtil__CreateLay(D_0035ed2c, 30019, 0, 0, 33, 35, 0, 0, 0);
    Tz__Layout__SetImageCache(D_0035ed2c);
    if (func_00246a08()) {
        func_0028af40(D_0035ed20, 512);
        u8* t = D_0035ed40;
        func_0028d980_b(t, 30011, 0, 0, D_0035ed28, 77, 78, 3971, 0);
        func_00139620(t);
        func_001395f8(t);
        t[405] = 1;
        {
            u8* q = t + 24;
            *(u32*)(q + 184) |= 8;
        }
    }
    Tz__HECO__CleateSelInfo();
    Tz__HECO__UpdateScore();
    Tz__HECO__UpdateMaker(1);
    func_00245968();
    func_00287bd0(0, 0);
    func_00287cc0(0);
    n = func_002887c8();
    if (n) {
        Tz__HECO__LoopAll();
        D_0035ed3c = 1;
        func_00288750(func_00245dc0);
    }
}
}  // namespace n00245488

// .rodata words read by other code (retail bytes, in place)
namespace r00371954 {
extern const u32 R_00371954[1] asm("D_00371954") __attribute__((aligned(4))) = { 0x0 };
extern const u32 R_00371958[2] asm("D_00371958") __attribute__((aligned(4))) = { 0x6425, 0x0 };
extern const u32 R_00371960[2] asm("D_00371960") __attribute__((aligned(4))) = { 0x1f001e, 0x20 };
extern const u32 R_00371968[4] asm("D_00371968") __attribute__((aligned(4))) = { 0x20000, 0x30001, 0x40005, 0x0 };
extern const u32 R_00371978[2] asm("D_00371978") __attribute__((aligned(4))) = { 0x140013, 0x15 };
extern const u32 R_00371980[2] asm("D_00371980") __attribute__((aligned(4))) = { 0x3a0039, 0x3b };
extern const u32 R_00371988[2] asm("D_00371988") __attribute__((aligned(4))) = { 0x3d003c, 0x3e };
extern const u32 R_00371990[2] asm("D_00371990") __attribute__((aligned(4))) = { 0x40003f, 0x41 };
extern const u32 R_00371998[2] asm("D_00371998") __attribute__((aligned(4))) = { 0x230022, 0x24 };
extern const u32 R_003719a0[18] asm("D_003719a0") __attribute__((aligned(4))) = { 0x50004, 0xffff0006, 0x10000, 0x20003, 0xf840301, 0xf870f86, 0xf8e0f88, 0xffffffff, 0xffffffff, 0x50004, 0xffff0006, 0x10000, 0x20003, 0xf850300, 0xf8a0f89, 0xf8e0f8b, 0xffffff01, 0xffffffff };
extern const u32 R_003719e8[25] asm("D_003719e8") __attribute__((aligned(4))) = { 0x340033, 0xffff0035, 0x310030, 0xffff0032, 0xf8c0200, 0x0, 0xf8f0000, 0xffffffff, 0xffffffff, 0x340033, 0xffff0035, 0x310030, 0xffff0032, 0xf8d0201, 0x0, 0xf8f0000, 0xffffffff, 0xffffffff, 0x635f6568, 0x6c322e6f, 0x64, 0x0, 0x635f6568, 0x322e326f, 0x646c };
}  // namespace r00371954

// 00245968 (was src/anon/batch_w3753_g.cpp)
namespace n00245968 {
struct VO;
typedef void (*VFn6)(VO*, s32, s32, s32, s32, s32, s32);
struct VO { void** vt; };
struct Hd { u8 pad[8]; u32 f8; };
s32 func_00246840(void) asm("func_00246840");
VO* func_00287dc0(void) asm("func_00287dc0");
void func_0023d808(VO*, s32) asm("func_0023d808");
void func_0023e858(VO*, s32, f32) asm("func_0023e858");
void func_0023e8b8(VO*, s32, f32) asm("func_0023e8b8");
void func_0023e8d8(VO*, s32, f32) asm("func_0023e8d8");
s32 func_00139d78(u32) asm("func_00139d78");
void func_0023e9b0(VO*, s32, u32) asm("func_0023e9b0");
void func_0023e690(VO*, s32, s32, s32) asm("func_0023e690");
extern Hd* D_0035ed38 asm("D_0035ed38");
/*TARGET 00245968*/
void func_00245968(void) asm("func_00245968");
void func_00245968(void) {
    s32 id, x, y;
    f32 f;
    if (func_00246840()) {
        id = 1106; f = -149.0f; x = 204; y = 386;
    } else {
        id = 1105; f = -626.0f; x = 177; y = 163;
    }
    VO* o = func_00287dc0();
    func_0023d808(o, 30008);
    ((VFn6)o->vt[6])(o, 0, id | 0x20000000, 134, 2, x, y);
    func_0023e858(o, 0, f);
    func_0023e8b8(o, 0, 0.0f);
    func_0023e8d8(o, 0, 22.0f);
    register s32 r4 asm("$4");
    Hd* h;
    asm("" : "=r"(h) : "0"(D_0035ed38), "r"(r4));
    func_00139d78(h->f8);
    u32 v = h->f8;
    func_0023e9b0(o, 0, v);
    func_0023e690(o, 0, 135, -1);
}
}  // namespace n00245968

// 00245a90 (was src/anon/batch_w97.cpp)
namespace n00245a90 {
// ---- 00245a90
struct Ent245 { u8 f0[8]; u8 f8[8]; s8 active; u8 pad17; u16 f18; u8 pad20[16]; };
extern Ent245 D_00371c50[] asm("D_00371c50");
extern u32 D_0035ed24 asm("D_0035ed24");
extern u32 D_0035ed28 asm("D_0035ed28");
extern u32 D_0035ed38 asm("D_0035ed38");
void Tz__Select__SetItem(u32, s32, s32, s32, u32, u16, Ent245*, u8*) asm("Tz__Select__SetItem");
u8* func_002891b8(u32, s32) asm("func_002891b8");
u32 func_0023aa78(u8*) asm("func_0023aa78");
void Tz__Select__SetExOffset(u32, s32, u32, s32) asm("Tz__Select__SetExOffset");
u32 func_0023aa98(u8*) asm("func_0023aa98");
u32 func_0028dd90(u32) asm("func_0028dd90");
// mod10_classify_012
u32 func_0028ddd8(u32) asm("func_0028ddd8");
void func_001395f8(u8*) asm("func_001395f8");
void Tz__Select__SetCurrent(u32, s32, s32, s32, s32) asm("Tz__Select__SetCurrent");
void func_002b4388(u32, Ent245*, s32) asm("func_002b4388");
/*TARGET 00245a90*/
void Tz__HECO__SetupSel(void) asm("Tz__HECO__SetupSel");
void Tz__HECO__SetupSel(void) {
    s32 sel = 0;
    u32 off = 0;
    for (s32 i = 0; i < 2; i++) {
        Ent245* e = (Ent245*)(off + (u32)D_00371c50);
        if (e->active) sel = i;
        Tz__Select__SetItem(D_0035ed24, i, 0, 0, D_0035ed28, e->f18, e, (u8*)(off + (u32)D_00371c50[0].f8));
        off += 36;
        u8* m = func_002891b8(D_0035ed24, i);
        Tz__Select__SetExOffset(D_0035ed24, i, func_0023aa78(m + 24), 0);
        u32 h = func_0023aa98(m + 24);
        *(u32*)(m + 432) = func_0028dd90(h);
        *(u32*)(m + 428) = func_0028ddd8(h);
        func_001395f8(m);
    }
    Tz__Select__SetCurrent(D_0035ed24, sel, 1, 0, 2);
    func_002b4388(D_0035ed38, &D_00371c50[sel], 0);
}
}  // namespace n00245a90

// 00245be8 (was src/anon/batch_w86.cpp)
namespace n00245be8 {
struct Info { u8 p0[4]; s16 anim; };
extern void* D_0035ed28 asm("D_0035ed28");
extern void* D_0035ed20 asm("D_0035ed20");
extern void* D_0035ed30 asm("D_0035ed30");
extern void* D_0035ed2c asm("D_0035ed2c");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0023f0c0(void*) asm("func_0023f0c0");
void func_0023f070(void*, s32, s32) asm("func_0023f070");
s32 func_0028acc8(void*) asm("func_0028acc8");
void func_0028ab20(void*) asm("func_0028ab20");
void* func_002891e8(void*) asm("func_002891e8");
void* func_002469a0(void*) asm("func_002469a0");
Info* func_002468a0(void*) asm("func_002468a0");
/*TARGET 00245be8*/
void Tz__HECO__LoopAll(void) asm("Tz__HECO__LoopAll");
void Tz__HECO__LoopAll(void)
{
    if (func_00139d78(D_0035ed28) && func_0023f0c0(D_0035ed28) != 32) func_0023f070(D_0035ed28, 32, -1);
    if (func_0028acc8(D_0035ed20)) {
        func_0028ab20(D_0035ed20);
        Info* in = func_002468a0(func_002469a0(func_002891e8(D_0035ed20)));
        if (func_00139d78(D_0035ed30) && func_0023f0c0(D_0035ed30) != in->anim) func_0023f070(D_0035ed30, in->anim, -1);
    }
    if (func_00139d78(D_0035ed2c) && func_0023f0c0(D_0035ed2c) != 35) func_0023f070(D_0035ed2c, 35, -1);
}
}  // namespace n00245be8

// 00245ce8 (was src/anon/batch_w89.cpp)
namespace n00245ce8 {
struct VObj { void (**vt)(VObj*); };
extern VObj* D_0035ed28 asm("D_0035ed28");
extern VObj* D_0035ed2c asm("D_0035ed2c");
extern VObj* D_0035ed30 asm("D_0035ed30");
extern void* D_0035ed20 asm("D_0035ed20");
extern void* D_0035ed24 asm("D_0035ed24");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_0028acc8(void*) asm("func_0028acc8");
void func_0028abe0(void*) asm("func_0028abe0");
void func_00246f80(void) asm("func_00246f80");
u32 func_00287dc0(void) asm("func_00287dc0");
void func_0023d820(u32) asm("func_0023d820");
void func_00247bb0(void) asm("func_00247bb0");
/*TARGET 00245ce8*/
void func_00245ce8(void) asm("func_00245ce8");
void func_00245ce8(void) {
    if (func_00139d78(D_0035ed28)) D_0035ed28->vt[5](D_0035ed28);
    if (func_00139d78(D_0035ed30)) D_0035ed30->vt[5](D_0035ed30);
    if (func_00139d78(D_0035ed2c)) D_0035ed2c->vt[5](D_0035ed2c);
    if (func_0028acc8(D_0035ed20)) func_0028abe0(D_0035ed20);
    if (func_0028acc8(D_0035ed24)) func_0028abe0(D_0035ed24);
    func_00246f80();
    func_0023d820(func_00287dc0());
    func_00247bb0();
}
}  // namespace n00245ce8

// 00245dc0 (was unwritten gap: pause callback)
namespace n00245dc0 {
extern u8 D_0035ed3c asm("D_0035ed3c");
void func_00245dc0(void) asm("func_00245dc0");
void func_00245dc0(void) { D_0035ed3c = 0; }
}  // namespace n00245dc0

// 00245dd0 (was src/anon/batch_w1579_g.cpp)
namespace n00245dd0 {
extern s32 D_0035ed20 asm("D_0035ed20");
extern s32 D_0035ed24 asm("D_0035ed24");
extern s32 D_0035ed28 asm("D_0035ed28");
extern s32 D_0035ed2c asm("D_0035ed2c");
extern s32 D_0035ed30 asm("D_0035ed30");
s32 func_00287bc0(void) asm("func_00287bc0");
void Tz__MenuBase__SaveMode(void) asm("Tz__MenuBase__SaveMode");
void func_00246708(void) asm("func_00246708");
s32 func_00287db0(void) asm("func_00287db0");
s32 func_0028acc8(s32) asm("func_0028acc8");
s32 func_00139d78(s32) asm("func_00139d78");
void func_00246f80(void) asm("func_00246f80");
void func_001039f8(void) asm("func_001039f8");
void func_00246070(void) asm("func_00246070");
void func_00245eb8(void) asm("func_00245eb8");
/*TARGET 00245dd0*/
u32 Tz__HECO__Control(void) asm("Tz__HECO__Control");
u32 Tz__HECO__Control(void) {
    s32 mode = func_00287bc0();
    Tz__MenuBase__SaveMode();
    func_00246708();
    if (func_00287db0() != 0) {
        if (func_0028acc8(D_0035ed20) == 0 && func_0028acc8(D_0035ed24) == 0 &&
            func_00139d78(D_0035ed28) == 0 && func_00139d78(D_0035ed2c) == 0 &&
            func_00139d78(D_0035ed30) == 0) {
            func_00246f80();
            func_001039f8();
            return 1;
        }
        return 0;
    }
    switch (mode) {
    case 0: func_00245eb8(); break;
    case 1: func_00246070(); break;
    }
    return 0;
}
}  // namespace n00245dd0

// 00245eb8 (was src/anon/batch_wcx2.cpp)
namespace n00245eb8 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
// --------------------
extern u32 D_0035ed20 asm("D_0035ed20");
extern u8 D_0035ed3c asm("D_0035ed3c");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00289380_x9401(s32) asm("func_00289380");
s32 func_00289310_x9402(s32) asm("func_00289310");
s32 func_0028ae28_x9403(s32, s32) asm("func_0028ae28");
void Tz__HECO__LoopAll() asm("Tz__HECO__LoopAll");
void func_00287c90(s32) asm("func_00287c90");
void Tz__HECO__CreateNewMark() asm("Tz__HECO__CreateNewMark");
void func_00287df0_x9407(s32, s32, s32, s32, s32) asm("func_00287df0");
s32 Tz__HECO__MoveMaker(s32) asm("Tz__HECO__MoveMaker");
void func_00242618(s32, s32) asm("func_00242618");
void Tz__HECO__UpdateMaker(s32) asm("Tz__HECO__UpdateMaker");
void func_002467b8() asm("func_002467b8");
void func_002535b0(s32) asm("func_002535b0");
void func_00288658(s32, s32) asm("func_00288658");
void func_00245ce8() asm("func_00245ce8");
void func_00288670(void (*)()) asm("func_00288670");
void func_00287da0() asm("func_00287da0");
void Tz__HECO__SetupSel() asm("Tz__HECO__SetupSel");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
/*TARGET 00245eb8*/
void func_00245eb8() asm("func_00245eb8");
void func_00245eb8() {
    s32 a = func_00287cd0();
    s32 r = func_00289380_x9401(D_0035ed20);
    if (D_0035ed3c) return;
    if (r != -1 || func_00289310_x9402(D_0035ed20)) {
        if (!func_0028ae28_x9403(D_0035ed20, 0)) Tz__HECO__LoopAll();
    }
    if (!a && func_0028ae28_x9403(D_0035ed20, 0)) {
        func_00287c90(1);
        Tz__HECO__CreateNewMark();
    }
    if (r != -13 && r != -12) func_00287df0_x9407(r, func_00289310_x9402(D_0035ed20), 1, 0, 1);
    switch (r) {
    case -6:
        func_002467b8();
        func_002535b0(3);
        func_00288658(2, 101);
        func_00288670(func_00245ce8);
    case -4: case -2:
        func_00287da0();
        break;
    case -13: case -12:
        if (Tz__HECO__MoveMaker(r == -12)) {
            func_00242618(7, 1);
            Tz__HECO__UpdateMaker(0);
        }
        break;
    case -11: case -10: case -9: case -8: case -7: case -5: case -3: case -1:
        break;
    case 0: case 1: case 2: case 3:
        Tz__HECO__SetupSel();
        func_00287bd0(1, 0);
        func_00287cc0(0);
        break;
    }
}
}  // namespace n00245eb8

// 00246070 (was src/anon/batch_wcx2.cpp)
namespace n00246070 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
// --------------------
struct S246070 { u8 b[26]; u16 h26; u8 c[8]; };
extern s32 D_0035ed24_246 asm("D_0035ed24");
extern s32 D_0035ed20_246 asm("D_0035ed20");
extern s32 D_0035ed38_246 asm("D_0035ed38");
extern u8* D_0035ed40_246 asm("D_0035ed40");
extern u8 D_00371ca8[] asm("D_00371ca8");
extern u8 D_00371cb0[] asm("D_00371cb0");
s32 func_00287cd0() asm("func_00287cd0");
s32 func_00289380_x10618(s32) asm("func_00289380");
s32 func_0028acc8_x10619(s32) asm("func_0028acc8");
s32 func_00289310_x10620(s32) asm("func_00289310");
void func_0028abe0_x10621(s32) asm("func_0028abe0");
u8* func_00246868() asm("func_00246868");
s32 func_002891e8_x10623(s32) asm("func_002891e8");
s32 func_002469a0(s32) asm("func_002469a0");
s32 func_002474e0(s32) asm("func_002474e0");
s32 func_00246840() asm("func_00246840");
void func_002b4388_x10627(s32, void*, s32) asm("func_002b4388");
void func_00287bd0(s32, s32) asm("func_00287bd0");
void func_00287cc0(s32) asm("func_00287cc0");
s32 func_0028ae28_x10630(s32, s32) asm("func_0028ae28");
void func_0028ab20_x10631(s32) asm("func_0028ab20");
void func_00287c90(s32) asm("func_00287c90");
void func_00287df0_x10633(s32, s32, s32, s32, s32) asm("func_00287df0");
void func_0028aa40(s32) asm("func_0028aa40");
void func_002468e8(s32, s32) asm("func_002468e8");
void YS__HE_COLOSSEUM__Start() asm("YS__HE_COLOSSEUM__Start");
void func_00287da0() asm("func_00287da0");
/*TARGET 00246070*/
void func_00246070() asm("func_00246070");
void func_00246070() {
    s32 n;
    s32 a = func_00287cd0();
    s32 r = func_00289380_x10618(D_0035ed24_246);
    if (a == 2) {
        if (func_0028acc8_x10619(D_0035ed24_246)) {
            if (r != -1 || func_00289310_x10620(D_0035ed24_246)) func_0028abe0_x10621(D_0035ed24_246);
            return;
        }
        u8* base = func_00246868();
        n = func_002891e8_x10623(D_0035ed20_246);
        S246070 tmp = *(S246070*)(func_002469a0(n) * 36 + (u32)base);
        if (func_002474e0(n)) {
            s32 k = func_002469a0(n);
            u8 v = (func_00246840() ? D_00371cb0 : D_00371ca8)[k];
            tmp.h26 = v == 7 ? 4044 : 4045;
        }
        func_002b4388_x10627(D_0035ed38_246, &tmp, 0);
        func_00287bd0(0, 0);
        func_00287cc0(1);
        return;
    }
    if (r != -1 || func_00289310_x10620(D_0035ed24_246)) {
        if (!func_0028ae28_x10630(D_0035ed24_246, 0)) func_0028ab20_x10631(D_0035ed24_246);
    }
    if (!a && func_0028ae28_x10630(D_0035ed24_246, 0)) func_00287c90(1);
    func_00287df0_x10633(r, func_00289310_x10620(D_0035ed24_246), 0, 0, 1);
    switch (r) {
    case -2: case 1:
        func_0028aa40(D_0035ed24_246);
        func_00287c90(1);
        break;
    case 0: {
        n = func_002891e8_x10623(D_0035ed20_246);
        func_002468e8(func_002469a0(n), *(s8*)((u32)n + (u32)D_0035ed40_246 + 14664) + 1);
        YS__HE_COLOSSEUM__Start();
        func_00287da0();
        break;
    }
    case -4: case -3: case -1:
        break;
    }
}
}  // namespace n00246070

// 00246328 (was src/anon/batch_w8010.cpp)
namespace n00246328 {
// ---- 00246328
extern s32 D_0035ed20 asm("D_0035ed20");
extern s32 D_0035ed24 asm("D_0035ed24");
extern s32 D_0035ed28 asm("D_0035ed28");
extern s32 D_0035ed2c asm("D_0035ed2c");
extern s32 D_0035ed30 asm("D_0035ed30");
extern s32 D_0035ed40 asm("D_0035ed40");
s32 func_00287bc0(void) asm("func_00287bc0");
s32 func_00287db0(void) asm("func_00287db0");
s32 func_002887c8(void) asm("func_002887c8");
void func_0028dae0(s32, s32) asm("func_0028dae0");
void func_0028dac8(s32, s32) asm("func_0028dac8");
s32 func_0028acc8(s32) asm("func_0028acc8");
s32 func_0028acb8(s32) asm("func_0028acb8");
void func_0028aa40(s32) asm("func_0028aa40");
s32 func_00139d78(s32) asm("func_00139d78");
s32 func_002891e8(s32) asm("func_002891e8");
s16* func_002468a0(s32) asm("func_002468a0");
void func_00247bb0(void) asm("func_00247bb0");
void func_00246708(void) asm("func_00246708");
void func_00246490(s32, s32, s32) asm("func_00246490");
struct NoTail246328 { ~NoTail246328() {} };
/*TARGET 00246328*/
void Tz__HECO__Draw(void) asm("Tz__HECO__Draw");
void Tz__HECO__Draw(void)
{
    NoTail246328 nt;
    s32 on = func_00287bc0();
    s32 t = func_00287db0();
    if (t) {
        if (!func_002887c8()) {
            func_0028dae0(D_0035ed28, 31);
            if (func_0028acc8(D_0035ed20) && func_00139d78(D_0035ed30))
                func_0028dae0(D_0035ed30, func_002468a0(func_002891e8(D_0035ed20))[1]);
            func_0028dae0(D_0035ed2c, 34);
            if (func_0028acc8(D_0035ed20) && !func_0028acb8(D_0035ed20)) func_0028aa40(D_0035ed20);
            if (func_0028acc8(D_0035ed24) && !func_0028acb8(D_0035ed24)) func_0028aa40(D_0035ed24);
        }
        func_0028dac8(D_0035ed40, 76);
        func_00247bb0();
    }
    func_00246708();
    t = func_00287db0();
    if (!t) {
        s32 a = !on ? D_0035ed20 : D_0035ed24;
        t = on != 0;
        func_00246490(a, on, t);
    }
}
}  // namespace n00246328

// 00246490 (was src/anon/batch_w2406.cpp)
namespace n00246490 {
struct Msg246 { u8 pad[26]; s16 id; u8 pad2[8]; };
struct Ent246 { u8 pad[4]; s16 f4; };
extern s32 D_0035ed30 asm("D_0035ed30");
extern s32 D_0035ed38 asm("D_0035ed38");
extern Msg246 D_00371c50[] asm("D_00371c50");
extern u8 D_00371ca8[] asm("D_00371ca8");
extern u8 D_00371cb0[] asm("D_00371cb0");
s32 func_00287cd0(s32) asm("func_00287cd0");
s32 func_00289310(s32) asm("func_00289310");
s32 func_002891e8(s32) asm("func_002891e8");
void func_002890e0(s32, s32, s32, s32, s32) asm("func_002890e0");
void func_00289038(s32, s32, s32, s32, s32, s32, s32) asm("func_00289038");
s32 func_002469a0(s32) asm("func_002469a0");
Ent246* func_002468a0(s32) asm("func_002468a0");
void func_0023f070(s32, s32, s32) asm("func_0023f070");
void Tz__HECO__UpdateMaker(s32) asm("Tz__HECO__UpdateMaker");
void func_00247c20(void) asm("func_00247c20");
Msg246* func_00246868(void) asm("func_00246868");
s32 func_002474e0(s32) asm("func_002474e0");
s32 func_00246840(void) asm("func_00246840");
void func_002b4388(s32, void*, s32) asm("func_002b4388");
static inline u8 w2406_menuFlag(s32 k) { if (func_00246840()) return D_00371cb0[k]; return D_00371ca8[k]; }
/*TARGET 00246490*/
void func_00246490(s32 a, s32 b) asm("func_00246490");
void func_00246490(s32 a, s32 b) {
    Msg246 m;
    s32 sel;
    if (func_00287cd0(a) != 1) return;
    if (func_00289310(a) == 0) return;
    sel = func_002891e8(a);
    func_002890e0(a, 1, 2, 0, -1);
    func_00289038(a, sel, 1, 1, 2, 0, -1);
    s32 nb = b == 0;
    if (nb) {
        func_0023f070(D_0035ed30, func_002468a0(func_002469a0(sel))->f4, -1);
        Tz__HECO__UpdateMaker(1);
        func_00247c20();
    }
    Msg246* l;
    s32 i;
    if (b == 0) {
        l = func_00246868();
        i = func_002469a0(sel);
        m = l[i];
    } else {
        l = D_00371c50;
        i = sel;
        m = l[i];
    }
    if (b == 0 && func_002474e0(sel)) {
        s32 k = func_002469a0(sel);
        s32 c = w2406_menuFlag(k) != 7;
        m.id = c + 4044;
    }
    func_002b4388(D_0035ed38, &m, 0);
}
}  // namespace n00246490

// 00246708 (was src/anon/batch_wcx.cpp)
namespace n00246708 {
extern u8* D_0035ed20 asm("D_0035ed20");
extern u8* D_0035ed24 asm("D_0035ed24");
s32 func_002892f8(u8*) asm("func_002892f8");
s32 func_0028acc8(u8*) asm("func_0028acc8");
void func_00288e88(u8*) asm("func_00288e88");
/*TARGET 00246708*/
void func_00246708(void) asm("func_00246708");
void func_00246708(void)
{
    if (D_0035ed20) {
        s32 a = func_002892f8(D_0035ed20);
        if (!func_0028acc8(D_0035ed20) && a) func_00288e88(D_0035ed20);
    }
    if (D_0035ed24) {
        s32 a = func_002892f8(D_0035ed24);
        if (!func_0028acc8(D_0035ed24) && a) func_00288e88(D_0035ed24);
    }
}
}  // namespace n00246708

// 002467b8 (was src/anon/tiny_auto80_queue.cpp)
namespace n002467b8 {
extern u32 D_0035ed20 asm("D_0035ed20");
void func_0023fc40(...) asm("func_0023fc40");
u32 func_0023fd30(...) asm("func_0023fd30");
u32 func_002891e8(...) asm("func_002891e8");
/*TARGET 002467b8*/
void func_002467b8() asm("_Z13func_002467b8v");
void func_002467b8() {  // queue_push_word
    func_0023fd30();  // global_flag_nonzero
    u32 v0 = func_002891e8(D_0035ed20);
    func_0023fc40(&v0, 4);
}
}  // namespace n002467b8

// 002467f0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002467f0 {
extern u32 D_0035ed20 asm("D_0035ed20");
void func_0023fcd0(...) asm("func_0023fcd0");
u32 func_0023fd30(...) asm("func_0023fd30");
void Tz__Select__SetCurrent(...) asm("Tz__Select__SetCurrent");
/*TARGET 002467f0*/
void func_002467f0() asm("_Z13func_002467f0v");
void func_002467f0() {
    u32 sp0;
    if (func_0023fd30() != 0) {  // global_flag_nonzero
        func_0023fcd0(&sp0);
        Tz__Select__SetCurrent(D_0035ed20, sp0, 0, (u32)-1, (u32)-1);
        func_0023fd30();  // global_flag_nonzero
    }
}
}  // namespace n002467f0

// 00246840 (was src/tozawa/sub_menu.cpp)
namespace Tz { // method 00246840
u32 func_002431c0(...) asm("func_002431c0");
/*TARGET 00246840*/
u32 SubMenu::GetCallSignal() {
    u32 r2 = func_002431c0();
    r2 = (u32)(r2 ^ 0x0016u);
    r2 = ((u32)r2 < 0x00000001u);
    return r2;
}
}  // Tz

// 00246868 (was src/anon/tiny_auto80_queue.cpp)
namespace n00246868 {
u32 func_00246840(...) asm("func_00246840");
extern u8 D_00371b30 asm("D_00371b30");
extern u8 D_00371bc0 asm("D_00371bc0");
/*TARGET 00246868*/
u32 func_00246868(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) asm("_Z13func_00246868jjjjjjjj");
u32 func_00246868(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7) {
    u32 r4 = a0, r5 = a1, r6 = a2, r7 = a3, r8 = a4, r9 = a5, r10 = a6, r11 = a7, r2, r15;
    r2 = ((u32(*)())func_00246840)();
    r15 = (u32)&D_00371bc0;
    if (r2 == 0u) {
    r15 = (u32)&D_00371b30;
    }
    r2 = r15;
    return r2;
}
}  // namespace n00246868

// 002468a0 (was src/anon/tiny_auto80_queue.cpp)
namespace n002468a0 {
extern u8  D_00371ad8 asm("D_00371ad8");
extern u8  D_00371af0 asm("D_00371af0");
u32 func_00246840(...) asm("func_00246840");
/*TARGET 002468a0*/
u32 func_002468a0(u32 a0) asm("_Z13func_002468a0j");
u32 func_002468a0(u32 a0) {
    u32 s0 = a0;
    if (func_00246840(s0) != 0) {
        return (u32)((u8*)&D_00371af0 + s0 * 6);
    }
    return (u32)((u8*)&D_00371ad8 + s0 * 6);
}
}  // namespace n002468a0

// 002468e8 (was src/anon/auto80_199_queue.cpp)
namespace n002468e8 {
/*TARGET 002468e8*/
void func_002468e8(u32 a0, u32 a1) asm("_Z13func_002468e8jj");
void func_002468e8(u32 a0, u32 a1) {
    u8 sp_buf[16];
    u8 v;

    if (func_00246840(a0) == 0) {
        v = *((u8*)((u32)&D_00371c98 + a0));
    } else {
        v = *((u8*)((u32)&D_00371ca0 + a0));
    }

    func_00199718(sp_buf, v, -1);
    sp_buf[2] = a1;
    AREA__MapJump(sp_buf, 1, 0, 0, 12);
}
}  // namespace n002468e8

// 00246968 (was src/anon/batch_w17.cpp)
namespace n00246968 {
u8* func_00246868(s32) asm("func_00246868");
u8 func_001a6d08(s32) asm("func_001a6d08");
u8 Cur2SelPos(s32 i) asm("_ZN2Tz4HECO10Cur2SelPosEi");
/*TARGET 00246968*/
u8 Cur2SelPos(s32 i) asm("_ZN2Tz4HECO10Cur2SelPosEi");
u8 Cur2SelPos(s32 i) {
    u8* v = func_00246868(i);
    return func_001a6d08(*(s8*)(v + i * 36 + 28));
}
}  // namespace n00246968

// 002469a0 (was src/anon/auto80_199_queue.cpp)
namespace n002469a0 {
/*TARGET 002469a0*/
u32 func_002469a0(u32 a0) asm("_Z13func_002469a0j");
u32 func_002469a0(u32 a0) {
    s32 s0 = 0;
    s32 s1 = 0;

    while (s0 < 4) {
        if (func_00246968(s0) != 0) {
            if (s1 == a0) {
                s1 = s1 + 1;
                break;
            }
            s1 = s1 + 1;
        }
        s0 = s0 + 1;
    }

    return (u32)s0;
}
}  // namespace n002469a0

// 00246a08 (was src/anon/auto80_199_queue.cpp)
namespace n00246a08 {
/*TARGET 00246a08*/
u32 func_00246a08(void) asm("_Z13func_00246a08v");
u32 func_00246a08(void) {
    if (func_00276c18() != 0) {
        return 1;
    }

    u32 s3 = 0;
    s32 s0 = 0;
    while (s0 < 4) {
        u32 a0;
        if (func_00246840() != 0) {
            a0 = *((u8*)((u32)&D_00371cb0 + s0));
        } else {
            a0 = *((u8*)((u32)&D_00371ca8 + s0));
        }

        u8* p = func_001d56c8(a0);
        if ((u32)p[0] >= 2) {
            s3 = 1;
            break;
        }
        s0 = s0 + 1;
    }
    return s3;
}
}  // namespace n00246a08

// 00246ab8 (was src/anon/batch_w2466_nsa.cpp)
namespace n00246ab8 {
struct O6ab8 {
    u8 pad[24];
    u8 sub[384];
    u32 f198;
    u8 pad19c[20];
    s32 f1b0;
};
struct Q6ab8 { u8 d[408]; };
struct R6ab8 { u8 d[32]; };
struct M6ab8 {
    O6ab8 o[18];
    Q6ab8 q[16];
    R6ab8 r[9];
};
union U6ab8 { M6ab8* p; s32 i; u32 u; };
extern U6ab8 D_0035ed40 asm("D_0035ed40");
extern void* D_0035ed20 asm("D_0035ed20");
extern s32 D_0035ed28 asm("D_0035ed28");
extern s32 D_0035f3d4 asm("D_0035f3d4");
extern s16 D_00371cc8[] asm("D_00371cc8");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
s32 func_00246968(s32) asm("func_00246968");
void* func_002891b8(void*, s32) asm("func_002891b8");
s32 func_002891e8(void*) asm("func_002891e8");
void func_0028d8c0(void*, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d8c0");
void func_0028d980(void*, s32, s32, s32, s32, s32, s32, s32, s32) asm("func_0028d980");
void func_0028dcc0(void*, void*) asm("func_0028dcc0");
void func_00139620(void*) asm("func_00139620");
void func_001395f8(void*) asm("func_001395f8");
u32 func_00192048(s32) asm("func_00192048");
s32 func_0023aa18(void*) asm("func_0023aa18");
s32 func_0023aa38(void*) asm("func_0023aa38");
void func_00138c68(void*, s32, s32) asm("func_00138c68");
/*TARGET 00246ab8*/
void Tz__HECO__CleateSelInfo(void) asm("Tz__HECO__CleateSelInfo");
void Tz__HECO__CleateSelInfo(void) {
    s32 i;
    s32 j;
    s32 a;
    s32 b;
    s32 r32;
    s16* hp;
    void* obj;
    O6ab8* o;
    Q6ab8* q;
    s32 x;
    s32 y;

    i = 0;
    j = 0;
    func_002fde18(&D_0035ed40.p->r[0], 0, 128);
    func_002fde18(&D_0035ed40.p->r[4], 0, 128);
    func_002fde18(&D_0035ed40.p->r[8], 0, 32);
    a = D_0035f3d4 + 1;
    b = D_0035f3d4 + 2;
    for (; i < 4; i++) {
        if (func_00246968(i)) {
            r32 = j * 32;
            obj = func_002891b8(D_0035ed20, j);
            q = &D_0035ed40.p->q[j];
            func_0028d8c0(q, a, 0, 0, D_0035ed28, 30, -1, 0);
            func_0028dcc0(q, obj);
            q = &D_0035ed40.p->q[4 + j];
            func_0028d8c0(q, b, 0, 0, D_0035ed28, D_00371cc8[i], -1, 0);
            func_0028dcc0(q, &D_0035ed40.p->q[j]);
            o = &D_0035ed40.p->o[2 + j];
            func_0028d980(o, a, 0, 0, D_0035ed28, 38, -1, -1, 0);
            func_0028dcc0(o, obj);
            func_00139620(o);
            func_001395f8(o);
            o->f198 = func_00192048(0xcc0a);
            x = func_0023aa18(o->sub);
            y = func_0023aa38(o->sub);
            o = &D_0035ed40.p->o[6 + j];
            func_0028d980(o, a, 0, 0, D_0035ed28, 96, -1, -1, 0);
            func_0028dcc0(o, &D_0035ed40.p->o[2 + j]);
            func_00139620(o);
            func_001395f8(o);
            func_00138c68(o, x, y);
            o->f198 = (u32)((u8*)D_0035ed40.p + r32) + 14376;
            o->f1b0 = 1;
            o = &D_0035ed40.p->o[10 + j];
            func_0028d980(o, a, 0, 0, D_0035ed28, 39, -1, -1, 0);
            func_0028dcc0(o, obj);
            func_00139620(o);
            func_001395f8(o);
            o->f1b0 = 2;
            x = func_0023aa18(o->sub);
            y = func_0023aa38(o->sub);
            o = &D_0035ed40.p->o[14 + j];
            func_0028d980(o, a, 0, 0, D_0035ed28, 96, -1, -1, 0);
            func_0028dcc0(o, &D_0035ed40.p->o[10 + j]);
            func_00139620(o);
            func_001395f8(o);
            func_00138c68(o, x, y);
            o->f198 = (u32)((u8*)D_0035ed40.p + r32) + 14504;
            o->f1b0 = 2;
            q = &D_0035ed40.p->q[12 + j];
            func_0028d8c0(q, a, 0, 0, D_0035ed28, 96, -1, 0);
            func_0028dcc0(q, obj);
            q = &D_0035ed40.p->q[8 + j];
            func_0028d8c0(q, b, 0, 0, D_0035ed28, 31, -1, 0);
            func_0028dcc0(q, &D_0035ed40.p->q[j]);
            j++;
        }
    }
    o = &D_0035ed40.p->o[1];
    func_0028d980(o, a + 2, 0, 0, D_0035ed28, 96, -1, -1, 0);
    func_0028dcc0(o, &D_0035ed40.p->q[8 + func_002891e8(D_0035ed20)]);
    func_00139620(o);
    func_001395f8(o);
    o->f198 = (u32)&D_0035ed40.p->r[8];
    o->f1b0 = 2;
}
}  // namespace n00246ab8

// 00246f80 (was src/anon/batch_w317.cpp)
namespace n00246f80 {
struct W317Obj;
struct W317VT { void* f[5]; void (*f20)(W317Obj*); };
struct W317Obj { W317VT* vt; };
struct W317A { u8 d[408]; };
struct W317B { u8 d[436]; };
struct W317G { W317B b0; W317B b1; W317B b[4][4]; u8 pad[7848 - 872 - 436 * 16]; W317A a[4][4]; };
// 0x0013cbb8: definition moved into src/anon/unit_0013a8b8.cpp

s32 func_00139d78(W317Obj*) asm("func_00139d78");
extern W317G* D_0035ed40 asm("D_0035ed40");
static inline void w317upd(void* p) {
    W317Obj* o = (W317Obj*)p;
    if (func_00139d78(o)) o->vt->f20(o);
}
/*TARGET 00246f80*/
void func_00246f80(void) asm("func_00246f80");
void func_00246f80(void) {
    w317upd(&D_0035ed40->b0);
    w317upd(&D_0035ed40->b1);
    s32 k = 0;
    s32 ob = 0;
    s32 oa = 0;
    do {
        w317upd((u8*)D_0035ed40 + oa + 7848);
        w317upd((u8*)D_0035ed40 + oa + 9480);
        w317upd((u8*)D_0035ed40 + oa + 11112);
        w317upd((u8*)D_0035ed40 + oa + 12744);
        w317upd((u8*)D_0035ed40 + ob + 872);
        w317upd((u8*)D_0035ed40 + ob + 2616);
        w317upd((u8*)D_0035ed40 + ob + 4360);
        w317upd((u8*)D_0035ed40 + ob + 6104);
        k++;
        __asm__("" : "+r"(k));
        ob += 436;
        oa += 408;
    } while (k < 4);
}
}  // namespace n00246f80

// .rodata words read by other code (retail bytes, in place)
namespace r00371ab4 {
extern const u32 R_00371ab4[1] asm("D_00371ab4") __attribute__((aligned(4))) = { 0x16 };
extern const u32 R_00371ab8[1] asm("D_00371ab8") __attribute__((aligned(4))) = { 0x6425 };
}  // namespace r00371ab4

// 00247198 (was src/anon/batch_w3699_nsa.cpp)
namespace n00247198 {
struct El { u8 pad[408]; };
struct Ek { u8 pad[408]; s32 f408; u8 pad2[24]; };
struct Tx { u8 pad[32]; };
struct Big {
    u8 pad[4360]; Ek c[4]; u8 pad2[7848 - 4360 - 4 * 436];
    El e[4]; El f[4]; El g[4]; El h[4]; Tx t[4]; Tx u[4];
};
struct Inf { u8 kind; u8 pad[3]; u32 n; };
extern Big* D_0035ed40 asm("D_0035ed40");
extern u8 D_00371ca8[] asm("D_00371ca8");
extern u8 D_00371cb0[] asm("D_00371cb0");
extern u8 D_00371cb8[] asm("D_00371cb8");
extern u8 D_00371cc0[] asm("D_00371cc0");
extern s16 D_00371cd0[] asm("D_00371cd0");
extern char D_00371ab8[] asm("D_00371ab8");
extern s32 D_00371ac4 asm("D_00371ac4");
extern s32 D_00371ac8 asm("D_00371ac8");
s32 func_00246968(s32) asm("func_00246968");
s32 func_00246840(void) asm("func_00246840");
Inf* func_001d56c8(u8) asm("func_001d56c8");
void YI__SEQUENCE__SetScaleX(f32, void*) asm("YI__SEQUENCE__SetScaleX");
void* func_00192048(s32) asm("func_00192048");
void func_00192c90(void*, void*) asm("func_00192c90");
s32 func_00192c40(void*, void*) asm("func_00192c40");
void* func_00192cc0(void*, char*, u32) asm("func_00192cc0");
s32 func_00192b30(void*) asm("func_00192b30");
s32 func_002474e0(s32) asm("func_002474e0");
void func_00138c10(void*, s32) asm("func_00138c10");
s32 func_00105c30(void) asm("func_00105c30");
static inline void* fmt247198(void* s, char* f, u32 n) { return func_00192cc0(s, f, n); }
/*TARGET 00247198*/
void Tz__HECO__UpdateScore(void) asm("Tz__HECO__UpdateScore");
void Tz__HECO__UpdateScore(void) {
    s32 i;
    s32 k = 0;
    s16* sp = D_00371cd0;
    for (i = 0; i < 4; i++, sp++) {
        if (func_00246968(i)) {
            Inf* inf = func_001d56c8((func_00246840() ? D_00371cb0 : D_00371ca8)[i]);
            u8* s2;
            u8* e;
            s32 d;
            s32 flag;
            if (inf->kind < 2) {
                YI__SEQUENCE__SetScaleX(0.0f, (u8*)&D_0035ed40->f[k] + 24);
                s2 = (u8*)&D_0035ed40->t[k];
                func_00192c90(func_00192048(0xcb9b), s2);
            } else if (inf->kind == 2) {
                e = (u8*)&D_0035ed40->f[k];
                d = (func_00246840() ? D_00371cc0 : D_00371cb8)[i];
                d--;
                YI__SEQUENCE__SetScaleX((f32)inf->n / (f32)d, e + 24);
                flag = 0;
                Ek* ck = &D_0035ed40->c[k];
                ck->f408 = (s32)func_00192048(0xcc0b);
                s2 = (u8*)&D_0035ed40->u[k];
                if (func_00105c30() == 1 || func_00105c30() == 8) flag = 1;
                if ((u8)flag) {
                    e = (u8*)func_00192b30(fmt247198(s2, D_00371ab8, inf->n));
                    func_00192c90(func_00192048(0xcb9a), s2 + (s32)e);
                } else {
                    func_00192cc0(s2 + func_00192c40(func_00192048(0xcb9a), s2), D_00371ab8, inf->n);
                }
                s2 = (u8*)&D_0035ed40->t[k];
                func_00192c90(func_00192048(0xcb9b), s2);
            } else if (inf->kind == 3) {
                YI__SEQUENCE__SetScaleX(1.0f, (u8*)&D_0035ed40->f[k] + 24);
                s2 = (u8*)&D_0035ed40->t[k];
                func_00192cc0(s2, D_00371ab8, inf->n);
                e = (u8*)&D_0035ed40->h[k];
                func_00138c10(e, *sp);
            }
            El* g = &D_0035ed40->g[k];
            func_00138c10(g, func_002474e0(k) ? D_00371ac4 : D_00371ac8);
            k++;
        }
    }
}
}  // namespace n00247198

// 002474e0 (was src/anon/auto80_199_queue.cpp)
namespace n002474e0 {
u32 func_002469a0(u32 a0) asm("_Z13func_002469a0j");
/*TARGET 002474e0*/
u32 func_002474e0(u32 a0) asm("_Z13func_002474e0j");
u32 func_002474e0(u32 a0) {
    u32 s1 = 0;
    u32 s0 = func_002469a0(a0);
    if (func_00246840() != 0) {
        s0 = *((u8*)((u32)&D_00371cb0 + s0));
    } else {
        s0 = *((u8*)((u32)&D_00371ca8 + s0));
    }

    u8* p = func_001d56c8(s0);
    u32 t = p[0];
    if (t == 3) {
        s1 = 1;
    }
    else if (t == 2) {
        if (s0 == 7) {
            u32 t0 = *(u32*)(p + 4);
            t0 = (u32)(t0 < 10);
            s1 = (u32)(t0 < 1);
        }
    }

    return s1;
}
}  // namespace n002474e0

// 00247580 (was src/anon/batch_w3816.cpp)
namespace n00247580 {
s32 func_002892f8(s32) asm("func_002892f8");
void func_00138c10(u8*, s32) asm("func_00138c10");
s32 func_00192048(u32) asm("func_00192048");
// 0x00271ee8: definition moved into src/anon/unit_00271e08.cpp

extern s32 D_0035ed20 asm("D_0035ed20");
extern u8* D_0035ed40 asm("D_0035ed40");
extern u8 D_00371ab8[] asm("D_00371ab8");
extern u8 D_00371ac0[] asm("D_00371ac0");
extern u8 D_00371cb8[] asm("D_00371cb8");
extern u8 D_00371cc0[] asm("D_00371cc0");
s32 func_002891e8(s32) asm("func_002891e8");
s32 func_002474e0(s32) asm("func_002474e0");
void func_0028dcc0(void*, void*) asm("func_0028dcc0");
void func_002fde18(void*, s32, s32) asm("func_002fde18");
s32 func_00105c30(void) asm("func_00105c30");
s32 func_00192cc0(u8*, u8*, s32) asm("func_00192cc0");
s32 func_00192b30(s32) asm("func_00192b30");
void func_00192c90(s32, u8*) asm("func_00192c90");
s32 func_00192c40(s32, u8*) asm("func_00192c40");
s32 func_0023aa98(void*) asm("func_0023aa98");
s32 func_002469a0(s32) asm("func_002469a0");
s32 func_00246840(void) asm("func_00246840");
void func_00138c68(void*, s32, s32) asm("func_00138c68");
u32 func_0028af88(s32) asm("func_0028af88");
void func_0028af18(s32, u32) asm("func_0028af18");
// true for the Japanese-style layouts (system language 1 or 8)
static inline u8 isjp() { u8 r = 0; if (func_00105c30() == 1 || func_00105c30() == 8) r = 1; return r; }
/*TARGET 00247580*/
// Refreshes the selection rows and the gauge/caption of the selected entry.
void Tz__HECO__UpdateMaker(u8 flag) asm("Tz__HECO__UpdateMaker");
// Refreshes the selection rows and the gauge/caption of the selected entry.
void Tz__HECO__UpdateMaker(u8 flag) {
    s32 cnt;
    s32 k;
    s32 sel = func_002891e8(D_0035ed20);
    cnt = func_002892f8(D_0035ed20);
    u8* e;
    s32 c;
    if (flag) {
        for (s32 i = 0; i < cnt; i++) {
            e = D_0035ed40 + i * 408 + 11112;
            c = func_002474e0(i) ? 31 : 96;
            func_00138c10(e, c);
        }
    }
    u8* cap = D_0035ed40 + 436;
    if (func_002474e0(sel)) {
        e = D_0035ed40 + sel * 408 + 11112;
        if (flag) {
            func_00138c10(cap, 33);
            func_00138c10(e, 32);
            func_0028dcc0(cap, D_0035ed40 + func_002891e8(D_0035ed20) * 408 + 11112);
        }
        u8* buf = D_0035ed40 + 14632;
        c = ((s8*)(sel + (u32)D_0035ed40))[14664];
        if (isjp()) {
            k = func_00192b30(func_00192cc0(buf, D_00371ab8, c + 1));
            func_00192c90(func_00192048(19468), buf + k);
        } else {
            func_00192cc0(buf + func_00192c40(func_00192048(19468), buf), D_00371ac0, c + 1);
        }
        s32 v = func_0023aa98(D_0035ed40 + sel * 408 + 7872);
        k = func_002469a0(sel);
        cnt = (func_00246840() ? D_00371cc0 : D_00371cb8)[k];
        func_00138c68(e, (s32)((f32)v / (f32)(cnt - 1) * (f32)c), 0);
    } else {
        func_00138c10(cap, 96);
        func_002fde18(D_0035ed40 + 14632, 0, 32);
    }
    u32 f = func_0028af88(D_0035ed20);
    if (func_002474e0(sel)) f |= 0xc0000;
    else f &= 0xfff3ffff;
    func_0028af18(D_0035ed20, f);
}
}  // namespace n00247580

// 00247870 (was src/anon/batch_w111.cpp)
namespace n00247870 {
struct Pad24 { u8 pad[8]; u64 trig; };
struct Info24 { u8 kind; u8 pad[3]; s32 count; };
struct Sel24 { u8 pad[14664]; s8 cur; };
struct Sub24 { u8 pad[8]; s8 cur; };
extern void* D_0035ed20 asm("D_0035ed20");
extern u8* D_0035ed40 asm("D_0035ed40");
extern u8 D_00371ca8[] asm("D_00371ca8");
extern u8 D_00371cb0[] asm("D_00371cb0");
extern u8 D_00371cb8[] asm("D_00371cb8");
extern u8 D_00371cc0[] asm("D_00371cc0");
Pad24* func_00167f18(s32) asm("func_00167f18");
s32 func_002891e8(void*) asm("func_002891e8");
s32 func_002474e0(s32) asm("func_002474e0");
s32 func_002469a0(s32) asm("func_002469a0");
s32 func_00246840(void) asm("func_00246840");
Info24* func_001d56c8(u32) asm("func_001d56c8");
/*TARGET 00247870*/
// Steps the current selection up/down (wrapping on a fresh press); returns whether it changed.
bool Tz__HECO__MoveMaker(u8 down) asm("Tz__HECO__MoveMaker");
// Steps the current selection up/down (wrapping on a fresh press); returns whether it changed.
bool Tz__HECO__MoveMaker(u8 down)
{
    Pad24* pad = func_00167f18(0);
    s32 h = func_002891e8(D_0035ed20);
    if (!func_002474e0(h)) return 0;
    s32 i = func_002469a0(h);
    u32 id = (func_00246840() ? D_00371cb0 : D_00371ca8)[i];
    Info24* info = func_001d56c8(id);
    s32 max = (func_00246840() ? D_00371cc0 : D_00371cb8)[i];
    s32 step = 1;
    if (info->kind == 2 && id == 7) {
        max = info->count;
        max /= 10;
        max *= 10;
        max++;
        step = 10;
    }
    s32 cur = ((Sel24*)(h + (u32)D_0035ed40))->cur;
    if (down) {
        if (cur <= 0) {
            if (pad->trig & 0x40) cur = max - 1;
        } else {
            cur -= step;
            if (cur < 0) cur = 0;
        }
    } else {
        if (cur + 1 >= max) {
            if (pad->trig & 0x80) cur = 0;
        } else {
            cur += step;
            cur = cur < max ? cur : max - 1;
        }
    }
    Sub24* s = (Sub24*)(h + (u32)D_0035ed40 + 14656);
    s32 old = s->cur;
    s->cur = cur;
    return old != cur;
}
}  // namespace n00247870

// 00247a20 (was src/anon/batch_w110.cpp)
namespace n00247a20 {
s32 func_00139d78(u8*) asm("func_00139d78");
void func_0028d8c0(u8*, s32, u32, u32, u32, s32, s32, s32) asm("func_0028d8c0");
extern s8 D_0035ed44 asm("D_0035ed44");
extern u8* D_0035ed34 asm("D_0035ed34");
extern void* D_0035ed20 asm("D_0035ed20");
extern u32 D_0035ed28 asm("D_0035ed28");
extern s32 D_0035f3d4 asm("D_0035f3d4");
s32 func_0028afa8(void*) asm("func_0028afa8");
u8* func_002891b8(void*, s32) asm("func_002891b8");
s32 func_002469a0(s32) asm("func_002469a0");
void func_0028dcc0(u8*, u8*) asm("func_0028dcc0");
void func_00139648(u8*) asm("func_00139648");
s32 func_0023aa18(u8*) asm("func_0023aa18");
s32 func_0023aa38(u8*) asm("func_0023aa38");
void func_00138c68(u8*, s32, s32) asm("func_00138c68");
void func_00247c20(void) asm("func_00247c20");
/*TARGET 00247a20*/
// Re-creates the enabled entry widgets of the list (bit per entry in D_0035ed44).
void Tz__HECO__CreateNewMark(void) asm("Tz__HECO__CreateNewMark");
// Re-creates the enabled entry widgets of the list (bit per entry in D_0035ed44).
void Tz__HECO__CreateNewMark(void) {
    if (!D_0035ed44) return;
    if (func_00139d78(D_0035ed34)) return;
    s32 id = D_0035f3d4 + 1;
    s32 n = func_0028afa8(D_0035ed20);
    for (s32 i = 0; i < n; i++) {
        u8* nd = func_002891b8(D_0035ed20, i);
        u8* sub = nd + 24;
        s32 m = D_0035ed44;
        u8 on = (m >> func_002469a0(i)) & 1;
        if (on) {
            func_0028d8c0(D_0035ed34 + i * 408, id, 0, 0, D_0035ed28, 83, -1, 0);
            func_0028dcc0(D_0035ed34 + i * 408, nd);
            func_00139648(D_0035ed34 + i * 408);
            s32 x = func_0023aa18(sub);
            s32 y = func_0023aa38(sub);
            func_00138c68(D_0035ed34 + i * 408, x, y);
        }
    }
    func_00247c20();
}
}  // namespace n00247a20

// 00247bb0 (was src/anon/batch_w42.cpp)
namespace n00247bb0 {
u8 u_call4_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
// 00242418: moved to src/tozawa/crc.cpp (linked unit)

// 00247bb0: update the four active entries
extern u8* D_0035ed34 asm("D_0035ed34");
/*TARGET 00247bb0*/
void func_00247bb0(void) asm("func_00247bb0");
void func_00247bb0(void)
{
    for (s32 i = 0; i < 4; i++) {
        if (u_call4_00139d78(D_0035ed34 + i * 408)) {
            u8* o = (u8*)(i * 408 + (u32)D_0035ed34);
            ((void (*)(void*))(*(void***)o)[5])(o);
        }
    }
}
}  // namespace n00247bb0

// 00247c20 (was src/anon/batch_w87.cpp)
namespace n00247c20 {
// ---- 0x154c10 ----
void func_00138c10(void*, s32) asm("func_00138c10");
// ---- 0x247c20 ----
extern void* D_0035ed20 asm("D_0035ed20");
extern s8 D_0035ed44 asm("D_0035ed44");
struct E408 { u8 pad[388]; s32 st; u8 pad2[16]; };
extern E408* D_0035ed34 asm("D_0035ed34");
s32 func_002891e8(void*) asm("func_002891e8");
s32 func_002469a0(s32) asm("func_002469a0");
s32 func_00139d78(void*) asm("func_00139d78");
s32 func_00246840(void) asm("func_00246840");
void func_00243230(s32, s32) asm("func_00243230");
/*TARGET 00247c20*/
void func_00247c20(void) asm("func_00247c20");
void func_00247c20(void) {
    s32 a = func_002891e8(D_0035ed20);
    s32 b = func_002469a0(a);
    bool off = !((D_0035ed44 >> b) & 1);
    if (off) return;
    if (func_00139d78(&D_0035ed34[a])) {
        E408* e = &D_0035ed34[a];
        if (e->st != 82) func_00138c10(e, 82);
    }
    func_00243230(4, func_00246840() ? b + 4 : b);
}
}  // namespace n00247c20

// 00247cf0 (was src/anon/batch_w1947_nsa.cpp)
namespace n00247cf0 {
struct AllocVt7cf0 { void* (*alloc)(void* self, u32 size, void* ra); };
struct AllocObj7cf0 { union { AllocVt7cf0* vt; u8 c; }; };
struct Holder7cf0 { u8 pad[20]; union { AllocObj7cf0* al; u8 c; }; };
struct Ret7cf0 { u8 pad[4]; s32 f4; };
extern AllocObj7cf0* D_0032ba14 asm("D_0032ba14");
extern Holder7cf0* D_00347f80 asm("D_00347f80");
extern s32 D_0035ed4c asm("D_0035ed4c");
extern s32 D_0035ed50 asm("D_0035ed50");
extern s32 D_0035ed54 asm("D_0035ed54");
extern s32 D_0035ed58 asm("D_0035ed58");
extern s32 D_0035ed5c asm("D_0035ed5c");
extern void* D_0035ed60 asm("D_0035ed60");
extern u8 D_00347e60[] asm("D_00347e60");
void func_00239700(void*) asm("func_00239700");
struct Elem7cf0 {
    void* vt; u8 pad4[8]; s32 f12; u8 pad16[8]; u8 sub[408 - 24];
    static void* operator new[](unsigned int sz, AllocObj7cf0* a) { return a->vt->alloc(a, sz, 0); }
    Elem7cf0() { f12 = 0; vt = D_00347e60; func_00239700(sub); }
    ~Elem7cf0();
};
extern Elem7cf0* D_0035ed64 asm("D_0035ed64");
extern u8 D_0035ed68 asm("D_0035ed68");
extern u8 D_0035ed69 asm("D_0035ed69");
void func_00287b18(s32, s32) asm("func_00287b18");
s32 func_00288be8(s32) asm("func_00288be8");
void func_002889f0(s32, s32, s32) asm("func_002889f0");
void func_00288f48(s32, s32, s32, s32, s32) asm("func_00288f48");
void func_002b3df8(void*) asm("func_002b3df8");
void func_0028d068(s32, s32) asm("func_0028d068");
Ret7cf0* func_00103eb0(void) asm("func_00103eb0");
void func_00247ff0(void) asm("func_00247ff0");
void TASK_MANAGER__create_thread(s32, s32, s32, void (*)(void), s32) asm("TASK_MANAGER__create_thread");
/*TARGET 00247cf0*/
void Tz__MUMI__Init(void) asm("Tz__MUMI__Init");
void Tz__MUMI__Init(void) {
    s32 h;
    void* p;
    func_00287b18(2, 3);
    h = func_00288be8(56);
    func_002889f0(h, 3, 1);
    D_0035ed4c = h;
    h = func_00288be8(56);
    func_002889f0(h, 2, 0);
    D_0035ed50 = h;
    func_00288f48(h, 64, 128, 0, 0);
    D_0035ed54 = 0;
    D_0035ed58 = 0;
    D_0035ed5c = 0;
    p = D_0032ba14->vt->alloc(D_0032ba14, 12, __builtin_return_address(0));
    func_002b3df8(p);
    D_0035ed60 = p;
    D_0035ed68 = 0;
    D_0035ed64 = new (D_00347f80->al) Elem7cf0[3];
    D_0035ed69 = 0;
    func_0028d068(30026, -1);
    TASK_MANAGER__create_thread(func_00103eb0()->f4, 0, 2000, func_00247ff0, 4096);
}
}  // namespace n00247cf0

// 00247e80 (was src/anon/batch_wcx2.cpp)
namespace n00247e80 {
#define QCOPY(d, s) asm volatile("lq $8, 0(%1)\n\tsq $8, 0(%0)" : : "r"(d), "r"(s) : "$8", "memory")
struct VecD { f32 x, y, z, w; ~VecD() {} } __attribute__((aligned(16)));
struct VA14 {
    f32 x, y, z, w;
    VA14& operator=(const VA14& s) { if (this != &s) QCOPY(this, &s); return *this; }
} __attribute__((aligned(16)));
static inline VA14 operator-(const VecD& a, const VecD& b)
{
    VA14 r;
    asm volatile(".set noreorder\n\tlqc2 $vf1, 0(%0)\n\tlqc2 $vf2, 0(%1)\n\tvsub.xyzw $vf1, $vf1, $vf2\n\tsqc2 $vf1, 0(%2)\n\t.set reorder"
                 : : "r"(&a), "r"(&b), "r"(&r) : "memory");
    return r;
}
// --------------------
// Menu teardown: free the windows, delete the helper objects and the item panel array.
struct VObj00247e80 { struct { void* f0; void* f4; void* f8; void (*dtor)(VObj00247e80*); void (*del)(VObj00247e80*); }* vt; };
struct Panel00247e80 { struct { void* f0; void* f4; void* f8; void (*dtor)(Panel00247e80*); }* vt; u8 pad[404]; };
struct Alloc00247e80 { struct { void* f0; void (*free)(Alloc00247e80*, void*); }* vt; };
struct Heap00247e80 { u8 pad[20]; Alloc00247e80* a; };
extern void* D_0035ed4c_x15274 asm("D_0035ed4c");
extern void* D_0035ed50 asm("D_0035ed50");
extern VObj00247e80* D_0035ed54_x15276 asm("D_0035ed54");
extern VObj00247e80* D_0035ed58 asm("D_0035ed58");
extern VObj00247e80* D_0035ed5c asm("D_0035ed5c");
extern void* D_0035ed60 asm("D_0035ed60");
extern Panel00247e80* D_0035ed64_x15280 asm("D_0035ed64");
extern Alloc00247e80* D_0032ba14_x15281 asm("D_0032ba14");
extern Heap00247e80* D_00347f80_x15282 asm("D_00347f80");
void func_00288b00(void* w) asm("func_00288b00");
void func_00288c20(void* w) asm("func_00288c20");
void func_002b3fb0(void* o) asm("func_002b3fb0");
/*TARGET 00247e80*/
void func_00247e80(void) asm("func_00247e80");
void func_00247e80(void)
{
    void* w;
    if ((w = D_0035ed4c_x15274) != 0) { func_00288b00(w); func_00288c20(w); D_0035ed4c_x15274 = 0; }
    if ((w = D_0035ed50) != 0) { func_00288b00(w); func_00288c20(w); D_0035ed50 = 0; }
    if (D_0035ed54_x15276) { D_0035ed54_x15276->vt->del(D_0035ed54_x15276); D_0035ed54_x15276 = 0; }
    if (D_0035ed58) { D_0035ed58->vt->del(D_0035ed58); D_0035ed58 = 0; }
    if (D_0035ed5c) { D_0035ed5c->vt->del(D_0035ed5c); D_0035ed5c = 0; }
    if ((w = D_0035ed60) != 0) { func_002b3fb0(w); D_0032ba14_x15281->vt->free(D_0032ba14_x15281, w); D_0035ed60 = 0; }
    if (D_0035ed64_x15280) {
        Panel00247e80* e = D_0035ed64_x15280 + ((s32*)D_0035ed64_x15280)[-1];
        Panel00247e80* q;
        for (;;) {
            q = D_0035ed64_x15280;
            if (q == e) break;
            e--;
            e->vt->dtor(e);
        }
        D_00347f80_x15282->a->vt->free(D_00347f80_x15282->a, (s32*)q - 1);
        D_0035ed64_x15280 = 0;
    }
}
}  // namespace n00247e80

