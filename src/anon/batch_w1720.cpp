#include "../common/types.h"

struct W1720Rec { s32 w[5]; };
struct W1720Flags { u8 pad0[8]; u64 flags; };
struct W1720Owner { u8 pad0[0xb38]; W1720Flags* xb38; };
struct W1720Ent { u8 pad0[8]; u64 flags; u8 pad10[0x10]; u8 x20[4]; };
struct W1720Obj {
    s32 state;
    W1720Rec rec;
    s32 x18;
    f32 timer;
    u8 pad20[8];
    W1720Owner* owner;
};

extern "C" {
extern f32 D_00349e10;
void func_00190128(W1720Rec*);
s32 func_00190140(W1720Rec*);
void func_00190920(W1720Rec*, s32, W1720Owner*);
W1720Rec func_00190d10(f32, W1720Rec*, W1720Owner*);
W1720Rec func_001913d8(W1720Rec*, W1720Owner*, void*);
W1720Ent* func_00167bf0(s32);
s32 func_0019bb58(s32);
s32 func_0019bc38(s32);
void func_0019ca90(W1720Obj*, s32, W1720Rec*);
void func_0019cc20(W1720Obj*);
void func_0019cc88(W1720Obj*, W1720Rec*);
s32 func_0019d4a8(W1720Obj*);
void func_002ba2e8(s32, s32);
void func_002c0688(W1720Owner*, W1720Rec*);
void func_0015a6c8(W1720Rec*);

void func_0019ce48(W1720Obj* self) {
    W1720Flags* f = self->owner->xb38;
    s32 next = -1;
    W1720Rec rec;
    func_00190128(&rec);
    W1720Ent* ent = func_00167bf0(0);
    s32 state = self->state;
    switch (state) {
    case 0:
        if (f->flags & 0x800) {
            next = 4;
            state = 2;
        } else if (func_0019d4a8(self) == 0) {
            next = 6;
            state = 1;
        }
        break;
    case 1:
        if (f->flags & 0x800) {
            rec = self->rec;
            func_0019ca90(self, 2, &rec);
        } else if (self->timer > 0.0f && func_0019bb58(self->rec.w[0]) != 0) {
            self->timer -= D_00349e10;
        } else {
            func_00190920(&rec, 6, self->owner);
            if (func_00190140(&rec) != 0) {
                func_0019cc88(self, &rec);
            } else {
                func_0019cc20(self);
            }
        }
        break;
    case 2: {
        W1720Rec* cur = &self->rec;
        if (func_0019bc38(cur->w[0]) == 0 || (f->flags & 0x800)) {
            func_002ba2e8(8, 0);
            func_0019cc20(self);
        } else if (func_0019d4a8(self) != 0) {
            if (ent->flags & 0xf0000) {
                rec = func_001913d8(cur, self->owner, ent->x20);
                if (func_00190140(&rec) != 0) {
                    func_0019cc88(self, &rec);
                    func_002c0688(self->owner, &rec);
                }
            }
        } else {
            if (f->flags & (1ull << 36)) {
                rec = func_00190d10(-1.0f, cur, self->owner);
            } else if (f->flags & (1ull << 37)) {
                rec = func_00190d10(1.0f, cur, self->owner);
            } else {
                break;
            }
            if (func_00190140(&rec) != 0) {
                func_0019cc88(self, &rec);
                func_0015a6c8(&rec);
            }
        }
        break;
    }
    }
    if (next != -1) {
        func_00190920(&rec, next, self->owner);
        if (func_00190140(&rec) != 0) {
            if (state == self->state) {
                func_0019cc88(self, &rec);
            } else {
                func_0019ca90(self, state, &rec);
            }
        }
    }
}
}
