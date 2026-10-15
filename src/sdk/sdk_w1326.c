/* Sony PS2 SDK-style sif RPC client wrapper (IOP request with a 1 KB name string). ee-gcc 2.9-991111 -O2 -G0. */
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

struct SifClient { u8 pad[0x24]; void* serve; };            /* sceSifClientData */
struct RpcSend { s32 a; s32 b; u8 pad[12]; char name[1024]; };
extern struct SifClient D_01e33480;
extern struct RpcSend D_01e33530;
extern u8 D_01e34a40[];
extern s32 D_00365948;
extern s32 D_0036594c;
char* func_002ff6f0(char* d, const char* s, u32 n);     /* strncpy */
s32 SignalSema(s32 sid);
s32 PollSema(s32 sid);
s32 func_003094b8(struct SifClient* cd, s32 fno, u32 mode, void* send, s32 ssize,
                  void* recv, s32 rsize, void (*end)(void*), void* endp);   /* sceSifCallRpc */
void func_002fbba8(void*);

/* 002fd050: lock the client semaphore, send rpc 18 (a, b, name) asynchronously */
s32 func_002fd050(s32 a, s32 b, const char* name)
{
  if (D_01e33480.serve == 0) return -100;
  if (PollSema(D_0036594c) < 0) return -200;
  if (name == 0 || *name == 0) { SignalSema(D_0036594c); return -210; }
  D_01e33530.a = a;
  D_01e33530.b = b;
  func_002ff6f0(D_01e33530.name, name, 1023);
  D_01e33530.name[1023] = 0;
  if (func_003094b8(&D_01e33480, 18, 1, &D_01e33530, 1044, D_01e34a40, 4, func_002fbba8, 0) != 0) {
    SignalSema(D_0036594c);
    return -91;
  }
  D_00365948 = 18;
  return 0;
}
