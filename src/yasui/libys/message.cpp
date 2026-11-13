// YS::MESSAGE (0x191f20-0x193038): the 3 loaded message files (.bar), message lookup by id,
// walking the message text (control codes), text measuring, formatting with the game font
// codes, and the text style.
#include "../../common/types.h"
#include <stdarg.h>

namespace YS {
class MESSAGE {
public:
    u8 c;
    static void Read(int id, int arg);
    static void Init(int id, int slot);
    int get_size() const;
    int copy(char* out) const;
    int dup(char* out) const;
};
}  // namespace YS

// One loaded message file: the file and its message table.
struct MSGFILE {
    void* file;
    u8* data;
    MSGFILE() { file = 0; data = 0; }
};

struct MsgFont {
    u8 pad0[0x11];
    u8 height;          // 0x11
    u8 pad1[2];
    s32 x14;            // 0x14
};
// Text style: scale, width ratio, colour.
class MsgStyle {
public:
    s32 f0;
    f32 scale;          // 0x04
    f32 width;          // 0x08
    u32 color;          // 0x0c
    s32 f10;            // 0x10
    f32 base;           // 0x14
    MsgStyle();
};
struct MsgSize {
    union {
        s32 w;          // 0x00
        u8 b;           // (keeps loads/stores ordered like the original)
    };
    u32 h;              // 0x04
};

static MSGFILE s_files[3];

extern "C" {
u8* func_002fd248(u32, void*, u32, u32, void*);  // bsearch
extern u8 D_0031eec8;
struct Prop4 { u32 f0, f4, val; };
Prop4* func_00168b38(void*, u32, u32);  // entry_array_find_nth
void func_001aadb0(u32);
s32 func_001d96e8(s32, s32);
char* func_00105ee8(void);
s32 func_002fee78(char*, const char*, ...);
extern s32 D_0033caf4;
void func_00170518(char*, s32, s32);
u32 func_001708f8(char*, s32);
void func_00170950(void*);
void* func_001b1490(const char*);
s32 func_001aae80(MsgFont*, s32);       // glyph width
s32 func_001aae90(u8);
s32 func_001ab820(MsgFont*);
u32 __fixunssfsi(f32);
void* memcpy(void*, const void*, u32);
s32 func_00301550(char*, const char*, va_list);

u8* func_00191f20(u8* p, u32 key) {
    u32* r = (u32*)func_002fd248(key & 0xffff7fff, p + 8, *(u32*)(p + 4), 8, &D_0031eec8);
    if (r == 0) return 0;
    return p + r[1];
}

static inline bool has4(Prop4* p) { return p && p->val; }

void func_00191f78(s32 idx, void* obj) {
    MSGFILE* s = &s_files[idx];
    s->file = obj;
    Prop4* p = func_00168b38(obj, 2, 0);
    if (has4(p)) s->data = (u8*)p->val; else s->data = 0;
    p = func_00168b38(obj, 24, 0);
    if (has4(p)) func_001aadb0(p->val);
}

void func_00192028(s32 idx) {
    MSGFILE* s = &s_files[idx];
    s->file = 0;
    s->data = 0;
}

void func_001920f0(u8* msg);
}

struct NoTail { ~NoTail() {} };
void u_tail4_00192048(u32 id, u32, u32, u32) asm("_Z16u_tail4_00192048jjjj");
void u_tail4_00192048(u32 id, u32, u32, u32)
{
    NoTail g;
    u8* r = 0;
    for (s32 i = 0; i < 3; i++) {
        u8* o = s_files[i].data;
        if (o && (r = func_00191f20(o, id))) break;
    }
    if (!r) r = func_00191f20(s_files[1].data, 0x8adc);
    if (id - 19136 < 3) func_001920f0(r);
}

extern "C" {
char* func_00192cc0(char* buf, const char* fmt, ...);
char* func_00192e50(u8* s, char* out, s32 unused, ...);

static char s_text[256];
static char s_num[6][8];

void func_001920f0(u8* msg) {
    s32 i, j, k = 0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            func_00192cc0(s_num[k], "%d", func_001d96e8(i, j));
            k++;
        }
    }
    func_00192e50(msg, s_text, 256, s_num[0], s_num[1], s_num[2], s_num[3], s_num[4], s_num[5]);
}

static char s_path[40];

static inline const char* nm(s32 a) {
    switch (a) {
    case 101: return "jm";
    case 100: return "gumi";
    case 102: return "title";
    }
    return func_00105ee8();
}
char* func_001921d8(s32 a) {
    register const char* s asm("$7") = nm(a);
    func_002fee78(s_path, "msg/%s/%s.bar", D_0033caf4, s);
    return s_path;
}
}

namespace YS {

void MESSAGE::Read(int id, int arg) {
    func_00170518(func_001921d8(id), arg, 0);
}

void MESSAGE::Init(int id, int slot) {
    func_00191f78(slot, (void*)func_001708f8(func_001921d8(id), -1));
}

}  // namespace YS

extern "C" {
void func_001922c8(s32 i) {
    void* p = s_files[i].file;
    if (p) {
        func_00170950(p);
        func_00192028(i);
    }
}

void func_00192320(void) {
    char buf[48];
    for (s32 i = 0; i < 3; i++) s_files[i].file = 0;
    func_002fee78(buf, "msg/%s/sys.bar", D_0033caf4);
    func_00191f78(1, func_001b1490(buf));
}

static const u8 s_codelen[32] = {
    0, 1, 1, 1, 2, 7, 2, 5, 4, 2, 2, 2, 2, 1, 2, 6,
    1, 5, 3, 5, 3, 3, 2, 3, 0, 2, 2, 2, 2, 2, 2, 2,
};

// Advance past one message token (control codes < 0x20 have table lengths).
u8* func_00192388(u8* p) {
    u8 c = *p;
    if (c >= 32) {
        p++;
    } else {
        if (c == 0) return 0;
        p += s_codelen[c];
    }
    return p;
}

s32 func_00192440(u8* p, s32 i);

u8* func_001923c8(u8* p) {
    if (p == 0) return 0;
    while (1) {
        if (func_00192440(p, 0)) {
            if (*p == 16) return func_00192388(p);
        }
        u8* v = func_00192388(p);
        if (v == 0) return 0;
        p = v;
    }
}

s32 func_00192440(u8* p, s32 i) {
    return p[i] < 25;
}

// Decodes the text code at p[i]: plain codes >= 32, two-byte codes 25..31 + next byte, else -1.
s32 func_00192450(u8* p, s32 i) {
    u32 c = p[i];
    s32 r = c - 32;
    if (c < 32) {
        if ((u8)(c - 25) < 7) {
            i++;
            return ((c - 25) << 8) + p[i] + 0xe0;
        }
        return -1;
    }
    return r;
}

s32 func_00192498(u8* p, s32 i) {
    s32 j = i + 1;
    return (s16)(p[i] | p[j] << 8);
}

s32 func_001924c0(u8* p) {
    s32 n = 1;
    while (p != 0) {
        if (func_00192440(p, 0)) {
            if (*p == 0x10) n++;
        }
        p = func_00192388(p);
    }
    return n;
}

void func_00192f98(MsgStyle*);
f32 func_00192fb8(MsgStyle*);
}

u8* func_00192528(u8* p, MsgFont* font, MsgStyle* st, MsgSize* out) asm("_Z13func_00192528Pv");
u8* func_00192528(u8* p, MsgFont* font, MsgStyle* st, MsgSize* out) {
    out->w = 0;
    s32 prev = -1;
    s32 stop = 0;
    s32 adv;
    out->h = (s32)((f32)font->height * st->scale);
    while (p != 0 && *p != 0x10 && !stop) {
        if (func_00192440(p, 0)) {
            switch (*p) {
            case 1:
                adv = (s32)((f32)func_001ab820(font) * func_00192fb8(st) + 0.5f);
                out->w += adv;
                break;
            case 2:
                stop = 1;
                break;
            case 3:
                func_00192f98(st);
                break;
            case 9: {
                out->w += func_001aae90(p[1]);
                u32 h = __fixunssfsi((f32)font->height * st->scale);
                out->h = h < out->h ? out->h : h;
                break;
            }
            case 10:
                st->scale = (f32)p[1] / (f32)font->height;
                break;
            case 11:
                st->width = (f32)p[1] / 100.0f;
                break;
            case 12:
                st->color = p[1];
                break;
            case 21:
                out->w += 32;
                break;
            case 22: {
                out->w += 32;
                u32 h = __fixunssfsi((f32)font->height * st->scale);
                out->h = h < out->h ? out->h : h;
                break;
            }
            }
        } else {
            s32 c = func_00192450(p, 0);
            u32 w = func_001aae80(font, c);
            if (c == 0x46 && prev == c) {
                w -= 2;
            } else {
                prev = c;
            }
            f32 fw = (f32)w;
            f32 sw = fw * func_00192fb8(st);
            u32 h = (s32)((f32)font->height * st->scale);
            adv = (s32)(sw + 0.5f);
            out->w += adv;
            out->h = h < out->h ? out->h : h;
        }
        p = func_00192388(p);
    }
    return p;
}

extern "C" {
u8* func_00192800(u8* p, MsgFont* font, MsgStyle* st, MsgSize* out) {
    return func_00192528(p, font, st, out);
}

void func_00192818(u8* p, MsgFont* font, MsgStyle st, MsgSize* out) {
    func_00192800(p, font, &st, out);
}

struct R192868 { u32 max; s32 sum; };

// The original returns nothing here, but the caller below uses v0 (the last line pointer).
void func_00192868(u8* n, MsgFont* a, MsgStyle* b, R192868* out)
{
    R192868 tmp;
    s32 k;
    s32 k2;
    tmp.max = 0;
    tmp.sum = 0;
    out->max = 0;
    out->sum = 0;
    while (n != 0) {
        n = func_00192800(n, a, b, (MsgSize*)&tmp);
        out->max = (tmp.max < out->max) ? (out->max) : (tmp.max);
        k = b->color + a->x14;
        out->sum = (out->sum + tmp.sum) + k;
        if (n == 0) break;
        if ((*n) == 16) {
            if (a) {
                func_00192388(n);
                break;
            } else {
                func_00192388(n);
                break;
            }
        }
    }
    k2 = a->x14 + b->color;
    out->sum -= k2;
}

void func_00192940(u8* p, MsgFont* font, MsgStyle st, R192868* out) {
    func_00192868(p, font, &st, out);
}

struct P2 { u32 x, y; };
typedef u8* (*LineFn)(u8*, MsgFont*, MsgStyle*, R192868*);
void func_00192990(u8* a0, MsgFont* a1, MsgStyle c, P2* a3) {
    P2 l;
    l.x = 0; l.y = 0;
    a3->x = 0; a3->y = 0;
    while (a0) {
        a0 = ((LineFn)func_00192868)(a0, a1, &c, (R192868*)&l);
        a3->x = l.x < a3->x ? a3->x : l.x;
        a3->y = l.y < a3->y ? a3->y : l.y;
    }
    a3->x = (a3->x + 1) & ~1;
    a3->y = (a3->y + 1) & ~1;
}

s32 func_00192a80(u8* p) {
    s32 n = 0;
    for (; p; p = func_00192388(p)) {
        if (func_00192440(p, 0)) {
            switch (*p) {
            case 16: return n;
            case 2: return n;
            case 9: n++; break;
            }
        } else n++;
    }
    return n;
}
}

namespace YS {
int MESSAGE::get_size() const {
    u8* v = (u8*)this;
    u8* s = (u8*)this;
    int n = 0;
    if (v) {
        do {
            n = v - s;
            v = func_00192388(v);
        } while (v);
    }
    return n;
}
}  // namespace YS

extern "C" {
s32 func_00192b80(u8* n) {
    s32 depth = 1;
    if (n) {
        do {
            s32 prev = depth;
            if (func_00192440(n, 0)) {
                if (*n == 2) depth++;
                else if (*n == 0) return depth;
            }
            n = func_00192388(n);
            if (prev != depth) {
                if (!n || (func_00192440(n, 0) && *n == 0)) depth--;
            }
        } while (n);
    }
    return depth;
}
}

namespace YS {
int MESSAGE::copy(char* out) const {
    int n = get_size();
    memcpy(out, this, n);
    return n;
}

int MESSAGE::dup(char* out) const {
    int n = copy(out);
    out[n] = 0;
    return n + 1;
}
}  // namespace YS

extern "C" {
char* func_00192cc0(char* buf, const char* fmt, ...) {
    va_list ap;
    va_start(ap, fmt);
    s32 n = func_00301550(buf, fmt, ap);
    s32 i;
    for (i = 0; i < n; i++) {
        s8 c = buf[i];
        if ((u32)(c - '0') < 10) c = c - 15;
        else if ((u32)(c - 'A') < 26) c = c - 19;
        else switch (c) {
        case ' ': c = 1; break;
        case '!': c = 72; break;
        case '"': c = 97; break;
        case '%': c = 74; break;
        case '\'': c = 87; break;
        case '*': c = 45; break;
        case '+': c = 43; break;
        case '-': c = 44; break;
        case '.': c = 79; break;
        case '/': c = 75; break;
        case ':': c = 82; break;
        case '?': c = 73; break;
        default: c = 127; break;
        }
        buf[i] = c;
    }
    buf[n] = 0;
    return buf;
}

// Converts n 16-bit character codes to message text.
u8* func_00192de8(const u16* s, s32 n, u8* out) {
    u8* p = out;
    for (s32 i = 0; i < n; i++) {
        u16 c = *s++;
        if (c == 0) *p = 1;
        else if (c < 224) *p = c + 32;
        else {
            c -= 224;
            *p++ = (c >> 8) + 25;
            *p = c;
        }
        p++;
    }
    *p = 0;
    return out;
}

// Expands '\r' markers in a message with formatted varargs.
char* func_00192e50(u8* s, char* out, s32 unused, ...) {
    va_list ap;
    va_start(ap, unused);
    u8* start = s;
    char* ret = out;
    if (s) {
        do {
            if (func_00192440(s, 0)) {
                u8 c = *s;
                s32 n;
                if (c != 0) {
                    if (c == 13) {
                        n = s - start;
                        if (n > 0) {
                            memcpy(out, start, n);
                            out += n;
                        }
                        out += ((YS::MESSAGE*)va_arg(ap, s32))->copy(out);
                        start = s + 1;
                    }
                } else {
                    n = s - start + 1;
                    memcpy(out, start, n);
                    out += n;
                }
            }
        } while ((s = func_00192388(s)) != 0);
    }
    va_end(ap);
    return ret;
}
}

MsgStyle::MsgStyle() {
    color = 0;
    scale = 1.0f;
    width = 1.0f;
    base = 1.0f;
}

extern "C" {
void func_00192f98(MsgStyle* st) {
    st->scale = st->base;
    st->width = 1.0f;
}

f32 func_00192fb8(MsgStyle* st) {
    return st->scale * st->width;
}
}
