#include "../common/types.h"

// ---- 0023c100 Tz::MenuBasic::SetMesRes: rebuild the message-resource item array (delete[] of a 344-byte class, new[] written out)
struct Elem1987;
extern "C" {
void* znaj1987(u32, u32) asm("_Znaj");
s32 getimg1987(s32, s32) asm("_ZN2YI12IMAGE_FREEZE8GetImageEi");
void func_00239700(Elem1987*);
void func_00239988(Elem1987*, u8*, s32);
}
struct Elem1987 { virtual ~Elem1987(); u8 pad[340]; };
extern "C" {
struct Res1987 { u8 pad[8]; s32 o8; s32 oc; s32 o10; s32 o14; s32 o18; s32 o1c; };
struct MB1987 {
    u32 f0; u32 heap; u8* res; s32 fc; u8* p10; u8* p14; s32* offs; s32 f1c; s32 f20; s32 n;
    s32 img; Elem1987* arr; Elem1987* arr2; s32 f34; s32 f38; s32 f3c; u8 pad40[8]; f32 f48;
};
void f23c598_1987(MB1987*) asm("_Z13func_0023c598Pv");
void setoff1987(MB1987*, s32, s32) asm("_ZN2YI6LAYOUT9SetOffsetEii");
void func_0023c6f8(MB1987*, s32);
s32 v1(MB1987* self, u8* res, s32 img, u32 heap) asm("_ZN2Tz9MenuBasic9SetMesResEz");
s32 v1(MB1987* self, u8* res, s32 img, u32 heap)
{
    Res1987* r = (Res1987*)res;
    s32 i;
    self->heap = heap;
    self->img = img;
    self->res = res;
    self->p10 = res + r->oc;
    self->p14 = res + r->o14;
    self->offs = (s32*)(res + r->o1c);
    self->f1c = r->o8;
    self->f20 = r->o10;
    self->n = r->o18;
    delete[] self->arr;
    {
        s32 n = self->n;
        s32* raw = (s32*)znaj1987(n * 344 + 4, self->heap);
        Elem1987* arr;
        *raw = n;
        arr = (Elem1987*)(raw + 1);
        {
            Elem1987* p = arr;
            s32 k = n - 1;
            if (__builtin_expect(n != 0, 1)) { do { func_00239700(p); p++; } while (--k != -1); }
        }
        self->arr = arr;
    }
    delete[] self->arr2;
    self->arr2 = 0;
    for (i = 0; i < self->n; i++) {
        func_00239988(&self->arr[i], res + self->offs[i], getimg1987(self->img, 0));
    }
    self->f3c = 0;
    self->f38 = 1;
    self->fc = 0;
    self->f48 = 1.0f;
    f23c598_1987(self);
    setoff1987(self, 0, 0);
    func_0023c6f8(self, 0);
    return 1;
}
}
