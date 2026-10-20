#include "../common/types.h"
extern "C" {
struct W1718Select {
    s16 cur;        // 0x00 cursor inside the visible page
    s16 pad2;
    s16 last;       // 0x04
    s16 keyUp;      // 0x06
    s16 keyDown;    // 0x08
    s16 keyLeft;    // 0x0a
    s16 keyRight;   // 0x0c
    s16 padE[2];
    s16 top;        // 0x12 first item of the visible page
    s16 pad14;
    s16 count;      // 0x16 item count
    s16 cols;       // 0x18 items per row
    s16 rows;       // 0x1a visible rows
    u8 pad1c[8];
    u8 loop;        // 0x24 wrap around
};
struct W1718Pad {
    u64 pad0;
    u64 trig;       // 0x08
    u64 pad10;
    u64 rep;        // 0x18
};
s32 func_0028af78(W1718Select*, s32);
void func_0028b120(W1718Select*, s32*, s32*, s32);
u8 W1718_IsCenter(void*) asm("_Z13func_0028b210Pv");
s32 func_0028a5a8(W1718Select*, W1718Pad*);

// Tz::Select: move the cursor on a grid of items from the pad input.
// Returns 1 if a direction key was handled, 0 if the move is blocked.
s32 func_00289ef8(W1718Select* sel, W1718Pad* pad)
{
    s32 col, row;
    s32 w, prow;
    s32 span;       // columns on the cursor's row, later the centering offset of a short last row
    s32 nrows;
    s32 ret;
    u64 rep;

    func_0028b120(sel, &col, &row, -1);
    func_0028b120(sel, &w, &prow, sel->cur);
    rep = pad->rep;
    if ((sel->keyLeft | sel->keyRight) & rep) {
        w = sel->count / sel->cols * sel->cols;
        span = (sel->cur + sel->top < w) ? sel->cols : sel->count - w;
    } else {
        span = sel->cols;
    }
    nrows = sel->count / sel->cols;
    if ((w = sel->count % sel->cols) != 0) nrows++;

    if ((rep & sel->keyUp) && func_0028af78(sel, 1)) {
        if (row == 0 && !(pad->trig & sel->keyUp)) return 0;
        if (nrows == 1 && (pad->trig & sel->keyUp)) return 0;
    } else if ((pad->rep & sel->keyDown) && func_0028af78(sel, 2)) {
        if (row >= nrows - 1 && !(pad->trig & sel->keyDown)) return 0;
        if (nrows == 1 && (pad->trig & sel->keyDown)) return 0;
    }
    if (W1718_IsCenter(sel)) {
        if ((pad->rep & sel->keyLeft) && func_0028af78(sel, 4)) {
            if (col == 0 && !(pad->trig & sel->keyLeft)) return 0;
            if (span == 1 && (pad->trig & sel->keyLeft)) return 0;
        } else if ((pad->rep & sel->keyRight) && func_0028af78(sel, 8)) {
            if (col >= span - 1 && !(pad->trig & sel->keyRight)) return 0;
            if (span == 1 && (pad->trig & sel->keyRight)) return 0;
        }
    }

    if ((pad->rep & sel->keyUp) && func_0028af78(sel, 1)) {
        ret = 1;
        span = 0;
        if ((row >= nrows - 1 || row == 0) && W1718_IsCenter(sel)) {
            if (sel->count % sel->cols != 0) span = (sel->cols - sel->count % sel->cols) / 2;
        }
        if (prow > 0) {
            sel->cur -= sel->cols;
            // The original tests both orders, so the result is always span.
            sel->cur += (span < col && col < span) ? col : span;
            goto end;
        } else if (sel->top > 0) {
            sel->top -= sel->cols;
            sel->cur += (span < col && col < span) ? col : span;
            goto end;
        } else {
            if (!sel->loop) goto end;
            if (sel->cols * sel->rows < sel->count) {
                sel->top = sel->count - sel->cols * sel->rows;
                if (sel->top % sel->cols != 0) sel->top += sel->cols - sel->top % sel->cols;
                sel->cur = col + sel->cols * (sel->rows - 1);
            } else {
                sel->cur = col + sel->cols * (nrows - 1);
            }
            sel->cur -= (col < span) ? col : span;
            if (sel->top + sel->cur >= sel->count) sel->cur = sel->count - sel->top - 1;
            goto end;
        }
    }
    if ((pad->rep & sel->keyDown) && func_0028af78(sel, 2)) {
        s32 vrows;
        ret = 1;
        span = 0;
        if (row >= nrows - 2 && W1718_IsCenter(sel)) {
            if (sel->count % sel->cols != 0) span = (sel->cols - sel->count % sel->cols) / 2;
        }
        if (sel->last < sel->count) {
            vrows = sel->rows;
        } else {
            vrows = sel->count / sel->cols;
            if ((w = sel->last % sel->cols) != 0) vrows++;
        }
        if (row < nrows - 1) {
            if (prow >= vrows - 1 && sel->rows < nrows) {
                sel->top += sel->cols;
            } else {
                sel->cur += sel->cols;
            }
            sel->cur -= (col < span) ? col : span;
            if (sel->top + sel->cur >= sel->count) sel->cur = sel->count - sel->top - 1;
            goto end;
        }
        if (sel->loop) {
            sel->top = 0;
            sel->cur = col + span;
        }
        goto end;
    }
    if ((pad->rep & sel->keyLeft) && func_0028af78(sel, 4)) {
        ret = 1;
        if (col > 0) sel->cur = sel->cur - 1;
        else sel->cur = sel->cur + span - 1;
        goto end;
    }
    if ((pad->rep & sel->keyRight) && func_0028af78(sel, 8)) {
        ret = 1;
        if (col < span - 1) sel->cur = sel->cur + 1;
        else sel->cur = sel->cur - span + 1;
        goto end;
    }
    ret = func_0028a5a8(sel, pad);
end:
    return ret;
}
}
