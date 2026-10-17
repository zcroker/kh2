
#include "../common/types.h"

/* libsupc++ eh_personality.cc (gcc 3.2-ee-040921): __gxx_personality_v0, byte-identical to the
 * toolchain's own libsupc++.a (eh_personality.o, .text+0x500). The object starts at 0x3149e8 with
 * its static helpers (size_of_encoded_value 0x3149e8, base_of_encoded_value 0x314a50,
 * read_uleb128 0x314b00, read_sleb128 0x314b38, read_encoded_value_with_base 0x314b90,
 * parse_lsda_header 0x314ce8, get_ttype_entry 0x314dd8, check_exception_spec 0x314e48).
 * 0x474e5543432b2b00 is __gxx_exception_class ("GNUCC++\0"). */

typedef unsigned int W1627UnwindPtr;
typedef unsigned long W1627UnwindWord;
typedef long W1627UnwindSword;

struct W1627UnwindException {
    unsigned long exception_class;
    void (*exception_cleanup)(int, W1627UnwindException*);
    W1627UnwindWord private_1;
    W1627UnwindWord private_2;
};

class W1627TypeInfo {
public:
    virtual ~W1627TypeInfo();
    virtual bool __is_pointer_p() const;
    virtual bool __is_function_p() const;
    virtual bool __do_catch(const W1627TypeInfo* thr_type, void** thr_obj, unsigned outer) const;
};

struct W1627CxaException {
    W1627TypeInfo* exceptionType;
    void (*exceptionDestructor)(void*);
    void (*unexpectedHandler)();
    void (*terminateHandler)();
    W1627CxaException* nextException;
    int handlerCount;
    int handlerSwitchValue;
    const unsigned char* actionRecord;
    const unsigned char* languageSpecificData;
    void* catchTemp;
    void* adjustedPtr;
    W1627UnwindException unwindHeader;
};

struct W1627LsdaHeaderInfo {
    W1627UnwindPtr Start;
    W1627UnwindPtr LPStart;
    W1627UnwindPtr ttype_base;
    const unsigned char* TType;
    const unsigned char* action_table;
    unsigned char ttype_encoding;
    unsigned char call_site_encoding;
};

void* func_00317120(void*);                 /* _Unwind_GetLanguageSpecificData */
W1627UnwindPtr func_003191e8(void*);        /* _Unwind_GetIP */

extern "C" {
void* func_003166f0(void*);                 /* __cxa_begin_catch */
void func_003191d0(void*, int, W1627UnwindWord); /* _Unwind_SetGR */
void func_003191f0(void*, W1627UnwindPtr);  /* _Unwind_SetIP */
W1627UnwindPtr func_00314a50(unsigned char, void*); /* base_of_encoded_value */
const unsigned char* func_00314b00(const unsigned char*, W1627UnwindWord*); /* read_uleb128 */
const unsigned char* func_00314b38(const unsigned char*, W1627UnwindSword*); /* read_sleb128 */
const unsigned char* func_00314b90(unsigned char, W1627UnwindPtr, const unsigned char*, W1627UnwindPtr*);
const unsigned char* func_00314ce8(void*, const unsigned char*, W1627LsdaHeaderInfo*);
const W1627TypeInfo* func_00314dd8(W1627LsdaHeaderInfo*, W1627UnwindWord);
bool func_00314e48(W1627LsdaHeaderInfo*, const W1627TypeInfo*, W1627UnwindSword);
void func_00315418(void (*)()) __attribute__((noreturn));             /* __cxxabiv1::__terminate */

static inline const unsigned char* read_encoded_value(void* context, unsigned char encoding,
                                                      const unsigned char* p, W1627UnwindPtr* val)
{
    return func_00314b90(encoding, func_00314a50(encoding, context), p, val);
}

int func_00314ee8(int version, int actions, unsigned long exception_class,
                 W1627UnwindException* ue_header, void* context)
{
    W1627CxaException* xh = (W1627CxaException*)(ue_header + 1) - 1;

    enum { found_nothing, found_terminate, found_cleanup, found_handler } found_type;

    W1627LsdaHeaderInfo info;
    const unsigned char* language_specific_data;
    const unsigned char* action_record;
    const unsigned char* p;
    W1627UnwindPtr landing_pad, ip;
    int handler_switch_value;
    void* thrown_ptr = xh + 1;

    if (version != 1)
        return 3;

    if (actions == (2 | 4) && exception_class == 0x474e5543432b2b00UL) {
        handler_switch_value = xh->handlerSwitchValue;
        landing_pad = (W1627UnwindPtr)xh->catchTemp;
        found_type = (landing_pad == 0 ? found_terminate : found_handler);
        goto install_context;
    }

    language_specific_data = (const unsigned char*)func_00317120(context);

    if (!language_specific_data)
        return 8;

    p = func_00314ce8(context, language_specific_data, &info);
    info.ttype_base = func_00314a50(info.ttype_encoding, context);
    ip = func_003191e8(context) - 1;
    landing_pad = 0;
    action_record = 0;
    handler_switch_value = 0;

    while (p < info.action_table) {
        W1627UnwindPtr cs_start, cs_len, cs_lp;
        W1627UnwindWord cs_action;

        p = read_encoded_value(0, info.call_site_encoding, p, &cs_start);
        p = read_encoded_value(0, info.call_site_encoding, p, &cs_len);
        p = read_encoded_value(0, info.call_site_encoding, p, &cs_lp);
        p = func_00314b00(p, &cs_action);

        if (ip < info.Start + cs_start)
            p = info.action_table;
        else if (ip < info.Start + cs_start + cs_len) {
            if (cs_lp)
                landing_pad = info.LPStart + cs_lp;
            if (cs_action)
                action_record = info.action_table + cs_action - 1;
            goto found_something;
        }
    }

    found_type = (actions & 8 ? found_nothing : found_terminate);
    goto do_something;

found_something:
    if (landing_pad == 0) {
        found_type = found_nothing;
    } else if (action_record == 0) {
        found_type = found_cleanup;
    } else {
        W1627UnwindSword ar_filter, ar_disp;
        const W1627TypeInfo* throw_type;
        const W1627TypeInfo* catch_type;
        bool saw_cleanup = false;
        bool saw_handler = false;

        if ((actions & 8) || exception_class != 0x474e5543432b2b00UL)
            throw_type = 0;
        else
            throw_type = xh->exceptionType;

        while (1) {
            p = action_record;
            p = func_00314b38(p, &ar_filter);
            func_00314b38(p, &ar_disp);

            if (ar_filter == 0) {
                saw_cleanup = true;
            } else if (ar_filter > 0) {
                catch_type = func_00314dd8(&info, ar_filter);
                thrown_ptr = xh + 1;

                if (!catch_type) {
                    if (!(actions & 8)) {
                        saw_handler = true;
                        break;
                    }
                } else if (throw_type) {
                    if (throw_type->__is_pointer_p())
                        thrown_ptr = *(void**)thrown_ptr;

                    if (catch_type->__do_catch(throw_type, &thrown_ptr, 1)) {
                        saw_handler = true;
                        break;
                    }
                }
            } else {
                if (throw_type && !func_00314e48(&info, throw_type, ar_filter)) {
                    saw_handler = true;
                    break;
                }
            }

            if (ar_disp == 0)
                break;
            action_record = p + ar_disp;
        }

        if (saw_handler) {
            handler_switch_value = ar_filter;
            found_type = found_handler;
        } else
            found_type = (saw_cleanup ? found_cleanup : found_nothing);
    }

do_something:
    if (found_type == found_nothing)
        return 8;

    if (actions & 1) {
        if (found_type == found_cleanup)
            return 8;

        if (exception_class == 0x474e5543432b2b00UL) {
            xh->handlerSwitchValue = handler_switch_value;
            xh->actionRecord = action_record;
            xh->languageSpecificData = language_specific_data;
            xh->adjustedPtr = thrown_ptr;
            xh->catchTemp = (void*)landing_pad;
        }
        return 6;
    }

install_context:
    if (found_type == found_terminate) {
        func_003166f0(&xh->unwindHeader);
        func_00315418(xh->terminateHandler);
    }

    if (handler_switch_value < 0) {
        func_00314ce8(context, xh->languageSpecificData, &info);
        xh->catchTemp = (void*)func_00314a50(info.ttype_encoding, context);
    }

    func_003191d0(context, 4, (W1627UnwindPtr)&xh->unwindHeader);
    func_003191d0(context, 5, handler_switch_value);
    func_003191f0(context, landing_pad);
    return 7;
}

}
