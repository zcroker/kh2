
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
void* __cxa_begin_catch(void*);                 /* __cxa_begin_catch */
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

int __gxx_personality_v0(int version, int actions, unsigned long exception_class,
                 W1627UnwindException* ue_header, void* context);  // 0x00314ee8: definition moved into src/libsupc++/eh_personality.cpp

}
