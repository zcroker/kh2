/* libkernl: SetAlarm */
typedef struct Alarm { struct Alarm *next; volatile int id; void *handler; void *arg; } Alarm;
extern Alarm *D_01e3b300;
extern int DIntr(void);
extern void EIntr(void);
extern int func_00310048(void);
extern void func_00310768(int, long, void *, void *);
extern void func_003102e0(int);
extern void func_003109e0(void);
static inline Alarm *alloc_alarm(void)
{
    Alarm *a = D_01e3b300;
    if (a)
        D_01e3b300 = a->next;
    return a;
}
static inline void free_alarm(Alarm *a)
{
    a->next = D_01e3b300;
    D_01e3b300 = a;
}
int func_00310a40(long time, void *handler, void *arg);  // 0x00310a40: definition moved into src/sdk/libkernl_00310048.c
