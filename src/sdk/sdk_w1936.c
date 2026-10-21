/* libkernl: SetAlarm */
typedef struct Alarm { struct Alarm *next; volatile int id; void *handler; void *arg; } Alarm;
extern Alarm *D_01e3b300;
extern int func_0030edb0(void);
extern void func_0030ee00(void);
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
int func_00310a40(long time, void *handler, void *arg)
{
    Alarm *a;
    int st;
    int id;
    if (handler == 0)
        return 0x80000016;
    st = func_0030edb0();
    a = alloc_alarm();
    if (a == 0) {
        if (st)
            func_0030ee00();
        return 0x80008005;
    }
    id = func_00310048();
    if (id < 0) {
        free_alarm(a);
        a->id = 0;
        if (st)
            func_0030ee00();
        return id;
    } else {
        a->handler = handler;
        a->arg = arg;
        a->id = id;
        func_00310768(id, time, func_003109e0, a);
        func_003102e0(id);
        if (st)
            func_0030ee00();
    }
    return ((int)a << 4) | (id & 0xfe) | 1;
}
