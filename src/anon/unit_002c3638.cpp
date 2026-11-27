// 002c3638: dk::WM_LANDING update (entries[8] x448, Tz::Select lists, wrap search). Was whole asm
// (src/anon/batch_w3953.s). Own row: needs -fno-strict-aliasing and owns three floats at 0x375564.
// Notes on the shape (plain C++, no register pins, no asm):
//  - The two function-local static vectors are written as hand-made guards (guard byte, inline
//    set, atexit of the empty thunks 0x2c5378/0x2c5380 that live in unit_002c4ca8.cpp). The original
//    surely had `static V4 v(0, 200, 600, 0);` with an empty destructor: that compiles to the same
//    bytes here, but gcc would then emit its own __tcf thunks into this unit.
//  - The wrap search jumps between the two arms (goto fwd / goto back). cse copies the entry count
//    into a second register only for a loop that ends its arm, and picks that copy for all uses
//    only when the loop comes last, so the forward loop is last and the backward loop is entered
//    from both tests. A goto-free spelling with the same block order was not found.
#include "../common/types.h"
struct V2c3638 { f32 x, y, z, w; V2c3638(f32 a, f32 b, f32 c, f32 d) : x(a), y(b), z(c), w(d) {} ~V2c3638() {} };
typedef struct Loc2c3638 Loc2c3638;
struct Loc2c3638 { u8 a, b, c, pad; u16 x, y, z; };
typedef struct Inp2c3638 Inp2c3638;
struct Inp2c3638 { u8 pad[8]; u64 flags; };
typedef struct Spr2c3638 Spr2c3638;
struct Spr2c3638 { u8 pad[392]; s32 next; u8 pad2[36]; s32 f432; u8 pad3[4]; };
typedef struct Ent2c3638 Ent2c3638;
struct Ent2c3638 { s32 msg; u8 pad[428]; u32 flags; Loc2c3638 loc; u8 pad2[2]; };
typedef struct Item2c3638 Item2c3638;
struct Item2c3638 { u8 pad[408]; s32 f408; };
typedef struct Row2c3638 Row2c3638;
struct Row2c3638 { u8 pad[408]; };
typedef struct M2c3638 M2c3638;
struct M2c3638 {
    u8 pad0[24];
    u32 flags;
    u8 lay[160];
    u8 msg[684];
    s32 list;
    u8 pad1[8236 - 876];
    s32 course;
    s32 f8240;
    s32 mode;
    u8 pad2[12];
    s32 f8260;
    u8 pad3[8];
    Ent2c3638 ent[8];
    s32 nEnt;
    u8 pad5[12];
    u8 cur[436];
    u8 obj12308[52];
    s32 list2;
    s32 nList2;
    s32 nRows;
    Item2c3638* rowPtr[3];
    Row2c3638 rows[3];
    Loc2c3638 loc;
    u8 pad7[13640 - 13618];
    s32 img0;
    s32 img1;
    Spr2c3638 win;
};
extern s32 D_0037558c;
extern s32 D_00375590;
Inp2c3638* m2c3638_GetInputState(s32) asm("func_00167f18");
bool m2c3638_isEpisodeType(M2c3638*) asm("_ZN2dk10WM_LANDING13isEpisodeTypeEv");
void m2c3638_sePlay(s32) asm("_ZN2dk2SE4PlayEi");
s32 m2c3638_getBaseNum(M2c3638*, s32) asm("_ZN2dk10WM_LANDING10getBaseNumEi");
void m2c3638_setNum(void*, s32, s32) asm("_ZN2Tz6Layout6setNumEii");
void m2c3638_toJiminy(s32) asm("_ZN8worldmap4Menu8toJiminyEi");
s32 m2c3638_00139d78(void*) asm("_Z16u_call4_00139d78jjjj");
void m2c3638_sprSetNum(void*, s32) asm("_ZN2dk6Sprite6setNumEi");
s32 m2c3638_GetCurrent(s32) asm("_ZN2Tz6Select10GetCurrentEv");
s32 func_00289380(s32);
s32 m2c3638_isCursorMove(s32) asm("_ZN2Tz6Select12isCursorMoveEv");
void Tz__Select__SetCurrent(s32, s32, s32, s32, s32);
s32 func_0028b040(s32);
void Tz__ScrollBar__SetPos(void*, s32);
u32 func_002c2598(u32, s32);
u8 func_002c2688(u32, s32);
s32 m2c3638_00192048(s32) asm("_Z16u_tail4_00192048jjjj");
void m2c3638_msgCreate(void*, s32, s32, s32, s32, s32, s32) asm("_ZN2dk13SpriteMessage6createEiPvPN2YI5IMAGEEiPKN2YS7MESSAGEEii");
void m2c3638_getSeqColorOn(void*) asm("_ZN2dk5Obj2D13getSeqColorOnEv");
void m2c3638_resetSeqAlphaOnly(void*) asm("_ZN2dk5Obj2D17resetSeqAlphaOnlyEv");
void m2c3638_getSeqXYOff(void*) asm("_ZN2dk5Obj2D17getSeqPraramXYOffEv");
void m2c3638_fadeout(M2c3638*) asm("_ZN2dk10WM_LANDING7fadeoutEv");
void m2c3638_infoExit(void) asm("_ZN2dk15WM_LANDING_INFO4exitEv");
void m2c3638_setMsg(void*, s32) asm("_ZN2Tz6LayMsg6setMsgEPKN2YS7MESSAGEE");
inline void* operator new(unsigned int, void* p) { return p; }
extern char D_01e2bd50, D_01e2bd58;
extern V2c3638 D_01e2bd60, D_01e2bd70;
void func_002c5378() asm("func_002c5378");
void func_002c5380() asm("func_002c5380");
void func_002fd188(void (*)()) asm("func_002fd188");
static inline void vset(V2c3638& v, f32 a, f32 b, f32 c, f32 d) { v.x = a; v.y = b; v.z = c; v.w = d; }
static inline s32 m2c3638_f1(u32 f) { return f & 1; }
void func_002c3638(M2c3638* m) asm("func_002c3638");
void func_002c3638(M2c3638* m)
{
    Inp2c3638* in = m2c3638_GetInputState(0);
    if (!m2c3638_isEpisodeType(m)) {
        s32 one = 1;
        if (!(m2c3638_f1(m->flags))) {
            u64 f = in->flags;
            if (f & 0x100) {
                m2c3638_sePlay(2);
                if (!D_01e2bd50) { vset(D_01e2bd60, 0.0f, 200.0f, 600.0f, 0.0f); D_01e2bd50 = 1; func_002fd188(func_002c5378); }
                m->mode = 2;
                m2c3638_setNum(m->lay, m2c3638_getBaseNum(m, 0), m2c3638_getBaseNum(m, 2));
                m->f8260 = one;
                return;
            }
            if (f & 0x400) {
                m2c3638_toJiminy(m->course);
                return;
            }
        }
    } else {
        if (in->flags & 0x208) {
            m2c3638_sePlay(2);
            if (!D_01e2bd58) { vset(D_01e2bd70, 0.0f, 200.0f, -600.0f, 0.0f); D_01e2bd58 = 1; func_002fd188(func_002c5380); }
            m->mode = 3;
            m2c3638_setNum(m->lay, m2c3638_getBaseNum(m, 0), m2c3638_getBaseNum(m, 2));
            m->f8260 = 2;
            return;
        }
    }
    if (!m2c3638_isEpisodeType(m)) {
        s32 act = 1;
        if (m2c3638_f1(m->flags)) {
            if (in->flags & 0xfc) {
                Spr2c3638* w = &m->win;
                m->flags &= ~1;
                m2c3638_sprSetNum(w, 93);
                w->next = -1;
                m2c3638_sePlay(4);
                if (in->flags & 0xc) act = 0;
            }
        }
        if (m2c3638_f1(m->flags)) return;
        s32 prev = m2c3638_GetCurrent(m->list);
        s32 ret = func_00289380(m->list);
        s32 cur = m2c3638_GetCurrent(m->list);
        if (m2c3638_isCursorMove(m->list)) {
            s32 half = (m->nEnt - 1) & ~1;
            s32 i = cur;
            if (cur < prev) {
                if (prev - cur >= half) goto fwd;
            back:
                for (s32 k = 0; k < m->nEnt; ) {
                    { Ent2c3638* e = m->ent + i; if (e->flags & 2) break; }
                    k++;
                    i += m->nEnt - 1;
                    i %= m->nEnt;
                }
            } else {
                if (cur - prev >= half) goto back;
            fwd:
                for (s32 k = 0; k < m->nEnt; ) {
                    { Ent2c3638* e = m->ent + i; if (e->flags & 2) break; }
                    k++;
                    i++;
                    i %= m->nEnt;
                }
            }
            cur = i;
            if (prev != cur) m2c3638_sePlay(1);
            Tz__Select__SetCurrent(m->list, cur, 1, 0, 2);
        }
        if (act) {
            switch (ret) {
            case -2:
                m2c3638_sePlay(4);
                m->f8240 = 0;
                m2c3638_fadeout(m);
                break;
            case -1:
            case -4:
                break;
            default: {
                Ent2c3638* e = m->ent + cur;
                if (m2c3638_f1(e->flags)) {
                    Spr2c3638* w = &m->win;
                    m2c3638_sePlay(5);
                    m->flags |= 1;
                    if (m2c3638_00139d78(w)) {
                        m2c3638_sprSetNum(w, 91);
                        w->next = 92;
                    } else {
                        m2c3638_msgCreate(w, 30060, m->img0, m->img1, 91, m2c3638_00192048(19469), 0);
                        w->next = 92;
                        m2c3638_getSeqColorOn(w);
                        m2c3638_resetSeqAlphaOnly(w);
                        w->f432 = 2;
                        m2c3638_getSeqXYOff(w);
                    }
                } else if (e->flags & 2) {
                    m2c3638_sePlay(2);
                    m->f8240 = 1;
                    m->flags |= 2;
                    *(Loc2c3638*)((u8*)m + 13608) = *(Loc2c3638*)((u8*)e + 436);
                    m2c3638_fadeout(m);
                    m2c3638_infoExit();
                }
            }
            }
        }
        m2c3638_setMsg(m->msg, m->ent[cur].msg);
        return;
    }
    if (!m2c3638_00139d78(m->cur)) return;
    if (m->nRows != 3) return;
    if (!(m->nRows < m->nList2)) return;
    s32 i;
    func_00289380(m->list2);
    s32 moved = m2c3638_isCursorMove(m->list2);
    s32 top = func_0028b040(m->list2);
    if (moved) m2c3638_sePlay(1);
    if (!m2c3638_isCursorMove(m->list2)) return;
    Tz__Select__SetCurrent(m->list2, top, 1, 0, 2);
    Tz__ScrollBar__SetPos(m->obj12308, top);
    for (i = 0; i < m->nRows; i++) {
        s32 idx = top + i;
        if (idx < 0) return;
        if (idx >= m->nList2) return;
        m->rowPtr[i]->f408 = func_002c2598(m->course, idx);
        m2c3638_sprSetNum(&m->rows[i], func_002c2688(m->course, idx) ? D_0037558c : D_00375590);
    }
    return;
}
