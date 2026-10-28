#include "../common/types.h"
extern "C" {
union BdVal { s32 i; u32 u; f32 f; };
struct BdOpF { u16 code : 4; u16 type : 2; u16 arg : 10; };
struct BdProg { u8 hdr[16]; u16 code[1]; };
union BdOp { u16 raw; BdOpF f; };
struct BdBytes4 { u8 b[4]; };
struct BdVM {
    BdProg* prog;
    s32 pc;
    s32* csp;
};
struct BdFunc { void (*fn)(BdVal*); u32 info; };
typedef void (*BdHook)(BdVM*, s32, void*);
void func_001da3d8(BdVM*, BdVal*);
void func_001da3f8(BdVM*, BdVal*);
u32 func_001da4d8(BdVM*, BdOpF);
void func_002fdd68(void*, void*, u32); // memcpy
static inline void BdCopy(void* d, void* s, u32 n) { func_002fdd68(d, s, n); }
f32 func_002f8b00(f32, f32); // fmodf
f32 func_002f8960(f32);
f32 func_002f87c0(f32);
// Bytecode interpreter: fetch a 16-bit opcode (code:4 type:2 arg:10) and run it on the VM
// value stack (001da3d8 push, 001da3f8 pop, 001da4d8 operand address); hook runs after every op.
s32 BdExecVM(BdVM* vm, BdFunc** fns, BdHook hook, void* arg)
{
    s32 st = 0;
    BdVal v[4];
    BdVal args[16];
    BdVal tmp;
    s32 off; u32 n;
    do {
        BdOp op;
        op.raw = *(u16*)((u32)vm->prog->code + vm->pc++ * 2);
        switch (op.f.code) {
        case 0:
            switch (op.f.type) {
            case 0:
            case 1:
                func_001da3d8(vm, (BdVal*)&vm->prog->code[vm->pc]);
                vm->pc += 2;
                break;
            case 3:
                tmp.u = func_001da4d8(vm, op.f);
                func_001da3d8(vm, (BdVal*)tmp.u);
                break;
            case 2:
                tmp.u = func_001da4d8(vm, op.f);
                func_001da3d8(vm, &tmp);
                break;
            default:
                st = 5;
                break;
            }
            break;
        case 1:
            tmp.u = func_001da4d8(vm, op.f);
            func_001da3f8(vm, (BdVal*)tmp.u);
            break;
        case 2: {
            func_001da3f8(vm, &tmp);
            n = vm->prog->code[vm->pc++];
            func_002fdd68((void*)func_001da4d8(vm, op.f), (void*)tmp.u, n);
            break;
        }
        case 3:
            func_001da3f8(vm, &tmp);
            tmp.u += vm->prog->code[vm->pc++];
            func_001da3d8(vm, (BdVal*)tmp.u);
            break;
        case 4:
            func_001da3f8(vm, &v[0]);
            func_001da3f8(vm, &tmp);
            if (!op.f.arg) __builtin_memcpy((void*)tmp.u, &v[0], 4);
            else BdCopy((void*)tmp.u, (void*)v[0].u, op.f.arg);
            break;
        case 5:
            func_001da3f8(vm, &v[0]);
            switch (op.f.type) {
            case 0:
                switch (op.f.arg) {
                case 0: v[0].f = (f32)v[0].i; break;
                case 2: v[0].i = -v[0].i; break;
                case 3: v[0].i = ~v[0].i; break;
                case 4: v[0].i = !v[0].i; break;
                case 5: v[0].i = __builtin_abs(v[0].i); break;
                case 6: v[0].i = v[0].i < 0; break;
                case 7: v[0].i = v[0].i <= 0; break;
                case 8: v[0].i = v[0].i == 0; break;
                case 9: v[0].i = v[0].i != 0; break;
                case 10: v[0].i = v[0].i >= 0; break;
                case 11: v[0].i = v[0].i > 0; break;
                default: st = 5; break;
                }
                break;
            case 1:
                switch (op.f.arg) {
                case 1: v[0].i = (s32)v[0].f; break;
                case 2: v[0].f = -v[0].f; break;
                case 5: v[0].f = __builtin_fabsf(v[0].f); break;
                case 6: v[0].i = v[0].f < 0.0f; break;
                case 7: v[0].i = v[0].f <= 0.0f; break;
                case 8: v[0].i = v[0].f == 0.0f; break;
                case 9: v[0].i = v[0].f != 0.0f; break;
                case 10: v[0].i = v[0].f >= 0.0f; break;
                case 11: v[0].i = v[0].f > 0.0f; break;
                default: st = 5; break;
                }
                break;
            default:
                st = 5;
                break;
            }
            func_001da3d8(vm, &v[0]);
            break;
        case 6:
            func_001da3f8(vm, &v[1]);
            func_001da3f8(vm, &v[0]);
            switch (op.f.type) {
            case 0:
                switch (op.f.arg) {
                case 0: v[0].i = v[0].i + v[1].i; break;
                case 1: v[0].i = v[0].i - v[1].i; break;
                case 2: v[0].i = v[0].i * v[1].i; break;
                case 3: v[0].i = v[0].i / v[1].i; break;
                case 4: v[0].i = v[0].i % v[1].i; break;
                case 5: v[0].i = v[0].i & v[1].i; break;
                case 6: v[0].i = v[0].i | v[1].i; break;
                case 7: v[0].i = v[0].i ^ v[1].i; break;
                case 8: v[0].i = v[0].i << v[1].i; break;
                case 9: v[0].i = v[0].i >> v[1].i; break;
                case 10: v[0].i = v[0].i && v[1].i; break;
                case 11: v[0].i = v[0].i || v[1].i; break;
                }
                break;
            case 1:
                switch (op.f.arg) {
                case 0: v[0].f = v[0].f + v[1].f; break;
                case 1: v[0].f = v[0].f - v[1].f; break;
                case 2: v[0].f = v[0].f * v[1].f; break;
                case 3: v[0].f = v[0].f / v[1].f; break;
                case 4: v[0].f = func_002f8b00(v[0].f, v[1].f); break;
                default: st = 5; break;
                }
                break;
            default:
                st = 5;
                break;
            }
            func_001da3d8(vm, &v[0]);
            break;
        case 7:
            off = (s16)vm->prog->code[vm->pc++];
            switch (op.f.arg) {
            case 0:
                vm->pc += off;
                break;
            case 1:
                func_001da3f8(vm, &v[0]);
                if (!v[0].i) vm->pc += off;
                break;
            case 2:
                func_001da3f8(vm, &v[0]);
                if (v[0].i) vm->pc += off;
                break;
            default:
                st = 5;
                break;
            }
            break;
        case 11: {
            u32 n = op.f.arg;
            *(BdBytes4*)&off = *(BdBytes4*)&vm->prog->code[vm->pc];
            vm->pc += 2;
            vm->csp += n;
            vm->csp[-1] = vm->pc;
            vm->csp[-2] = n;
            vm->pc += off;
            break;
        }
        case 8: {
            u32 n = op.f.arg;
            off = (s16)vm->prog->code[vm->pc++];
            vm->csp += n;
            vm->csp[-1] = vm->pc;
            vm->csp[-2] = n;
            vm->pc += off;
            break;
        }
        case 9:
            switch (op.f.arg) {
            case 0: st = 1; break;
            case 1: st = 2; break;
            case 2: {
                s32* csp = vm->csp;
                vm->pc = csp[-1];
                n = csp[-2]; vm->csp = csp - n;
                if (!vm->pc) st = 3;
                break;
            }
            case 3:
                func_001da3f8(vm, &v[0]);
                break;
            case 5:
                func_001da3f8(vm, &v[0]);
                func_001da3d8(vm, &v[0]);
                func_001da3d8(vm, &v[0]);
                break;
            case 6:
                func_001da3f8(vm, &v[0]);
                v[0].f = func_002f8960(func_002f8b00(v[0].f + 3.1415925f, 6.283185f) - 3.1415925f);
                func_001da3d8(vm, &v[0]);
                break;
            case 7:
                func_001da3f8(vm, &v[0]);
                v[0].f = func_002f87c0(func_002f8b00(v[0].f + 3.1415925f, 6.283185f) - 3.1415925f);
                func_001da3d8(vm, &v[0]);
                break;
            case 8:
                func_001da3f8(vm, &v[0]);
                v[0].f = func_002f8b00(v[0].f * 3.1415925f / 180.0f + 3.1415925f, 6.283185f) - 3.1415925f;
                func_001da3d8(vm, &v[0]);
                break;
            case 9:
                func_001da3f8(vm, &v[0]);
                v[0].f = v[0].f * 180.0f / 3.1415925f;
                func_001da3d8(vm, &v[0]);
                break;
            default:
                st = 5;
                break;
            }
            break;
        case 10: {
            BdFunc* f = fns[op.f.arg]; f += vm->prog->code[vm->pc++];
            s32 i = (u16)f->info; for (i--; i >= 0; i--) func_001da3f8(vm, &args[i]);
            f->fn(args);
            if (f->info & 0x40000000) func_001da3d8(vm, args);
            break;
        }
        default:
            st = 5;
            break;
        }
        if (hook) hook(vm, st, arg);
    } while (!st);
    return st;
}
}
