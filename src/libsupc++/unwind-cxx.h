/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libsupc++ unwind-cxx.h (gcc 3.2-ee-040921) with the parts of unwind.h, cxxabi.h and the EE
 * thread hooks (gthr-ee.h) that the linked libsupc++ units (src/libsupc++/*.cc) need. */
#ifndef LIBSUPCXX_UNWIND_CXX_H
#define LIBSUPCXX_UNWIND_CXX_H

#include <typeinfo>
#include <exception>
#include <cstddef>

extern "C" {
/* unwind.h */
typedef unsigned _Unwind_Word __attribute__((__mode__(__word__)));
typedef signed _Unwind_Sword __attribute__((__mode__(__word__)));
typedef unsigned _Unwind_Ptr __attribute__((__mode__(__pointer__)));
typedef unsigned _Unwind_Internal_Ptr __attribute__((__mode__(__pointer__)));
typedef unsigned _Unwind_Exception_Class __attribute__((__mode__(__DI__)));

typedef enum
{
  _URC_NO_REASON = 0,
  _URC_FOREIGN_EXCEPTION_CAUGHT = 1,
  _URC_FATAL_PHASE2_ERROR = 2,
  _URC_FATAL_PHASE1_ERROR = 3,
  _URC_NORMAL_STOP = 4,
  _URC_END_OF_STACK = 5,
  _URC_HANDLER_FOUND = 6,
  _URC_INSTALL_CONTEXT = 7,
  _URC_CONTINUE_UNWIND = 8
} _Unwind_Reason_Code;

struct _Unwind_Exception;

typedef void (*_Unwind_Exception_Cleanup_Fn) (_Unwind_Reason_Code,
					      struct _Unwind_Exception *);

struct _Unwind_Exception
{
  _Unwind_Exception_Class exception_class;
  _Unwind_Exception_Cleanup_Fn exception_cleanup;
  _Unwind_Word private_1;
  _Unwind_Word private_2;
} __attribute__((__aligned__));

typedef int _Unwind_Action;
#define _UA_SEARCH_PHASE	1
#define _UA_CLEANUP_PHASE	2
#define _UA_HANDLER_FRAME	4
#define _UA_FORCE_UNWIND	8

struct _Unwind_Context;

extern _Unwind_Reason_Code _Unwind_RaiseException (struct _Unwind_Exception *);
extern void _Unwind_DeleteException (struct _Unwind_Exception *);
extern void _Unwind_Resume (struct _Unwind_Exception *);
extern _Unwind_Word _Unwind_GetGR (struct _Unwind_Context *, int);
extern void _Unwind_SetGR (struct _Unwind_Context *, int, _Unwind_Word);
extern _Unwind_Ptr _Unwind_GetIP (struct _Unwind_Context *);
extern void _Unwind_SetIP (struct _Unwind_Context *, _Unwind_Ptr);
extern void *_Unwind_GetLanguageSpecificData (struct _Unwind_Context *);
extern _Unwind_Ptr _Unwind_GetRegionStart (struct _Unwind_Context *);
extern _Unwind_Ptr _Unwind_GetDataRelBase (struct _Unwind_Context *);
extern _Unwind_Ptr _Unwind_GetTextRelBase (struct _Unwind_Context *);
}

namespace __cxxabiv1
{

// A C++ exception object consists of a header, which is a wrapper around
// an unwind object header with additional C++ specific information,
// followed by the exception object itself.

struct __cxa_exception
{
  // Manage the exception object itself.
  std::type_info *exceptionType;
  void (*exceptionDestructor)(void *);

  // The C++ standard has entertaining rules wrt calling set_terminate
  // and set_unexpected in the middle of the exception cleanup process.
  std::unexpected_handler unexpectedHandler;
  std::terminate_handler terminateHandler;

  // The caught exception stack threads through here.
  __cxa_exception *nextException;

  // How many nested handlers have caught this exception.
  int handlerCount;

  // Cache parsed handler data from the personality routine Phase 1
  // for Phase 2 and __cxa_call_unexpected.
  int handlerSwitchValue;
  const unsigned char *actionRecord;
  const unsigned char *languageSpecificData;
  _Unwind_Ptr catchTemp;
  void *adjustedPtr;

  // The generic exception header.  Must be last.
  _Unwind_Exception unwindHeader;
};

// Each thread in a C++ program has access to a __cxa_eh_globals object.
struct __cxa_eh_globals
{
  __cxa_exception *caughtExceptions;
  unsigned int uncaughtExceptions;
};

// The __cxa_eh_globals for the current thread can be obtained by using
// either of the following functions.  The "fast" version assumes at least
// one prior call of __cxa_get_globals has been made from the current
// thread, so no initialization is necessary.
// Their callers see them as nothrow; eh_globals.cc itself is built without the
// specification (like the original), so it defines CXA_GLOBALS_THROW empty.
#ifndef CXA_GLOBALS_THROW
#define CXA_GLOBALS_THROW throw()
#endif
extern "C" __cxa_eh_globals *__cxa_get_globals () CXA_GLOBALS_THROW;
extern "C" __cxa_eh_globals *__cxa_get_globals_fast () CXA_GLOBALS_THROW;

// Allocate memory for the exception plus the thown object.
extern "C" void *__cxa_allocate_exception(std::size_t thrown_size);

// Free the space allocated for the exception.
extern "C" void __cxa_free_exception(void *thrown_exception);

// Throw the exception.
extern "C" void __cxa_throw (void *obj, std::type_info *tinfo,
			     void (*dest) (void *))
     __attribute__((noreturn));

// Used to implement exception handlers.
extern "C" void *__cxa_begin_catch (void *);
extern "C" void __cxa_end_catch ();
extern "C" void __cxa_rethrow () __attribute__((noreturn));

// These facilitate code generation for recurring situations.
extern "C" void __cxa_bad_cast ();
extern "C" void __cxa_bad_typeid ();

// @@@ These are not directly specified by the IA-64 C++ ABI.

// Handles re-checking the exception specification if unexpectedHandler
// throws, and if bad_exception needs to be thrown.  Called from the
// compiler.
extern "C" void __cxa_call_unexpected (void *) __attribute__((noreturn));

// Invokes given handler, dying appropriately if the user handler was
// so inconsiderate as to return.
extern void __terminate(std::terminate_handler) __attribute__((noreturn));
extern void __unexpected(std::unexpected_handler) __attribute__((noreturn));

// The current installed user handlers.
extern std::terminate_handler __terminate_handler;
extern std::unexpected_handler __unexpected_handler;

// These are explicitly GNU C++ specific.

// This is the exception class we report -- "GNUCC++\0".
const _Unwind_Exception_Class __gxx_exception_class
= ((((((((_Unwind_Exception_Class) 'G'
	 << 8 | (_Unwind_Exception_Class) 'N')
	<< 8 | (_Unwind_Exception_Class) 'U')
       << 8 | (_Unwind_Exception_Class) 'C')
      << 8 | (_Unwind_Exception_Class) 'C')
     << 8 | (_Unwind_Exception_Class) '+')
    << 8 | (_Unwind_Exception_Class) '+')
   << 8 | (_Unwind_Exception_Class) '\0');

// GNU C++ personality routine, Version 0.
extern "C" _Unwind_Reason_Code __gxx_personality_v0
     (int, _Unwind_Action, _Unwind_Exception_Class,
      struct _Unwind_Exception *, struct _Unwind_Context *);

// Acquire the C++ exception header from the C++ object.
static inline __cxa_exception *
__get_exception_header_from_obj (void *ptr)
{
  return reinterpret_cast<__cxa_exception *>(ptr) - 1;
}

// Acquire the C++ exception header from the generic exception header.
static inline __cxa_exception *
__get_exception_header_from_ue (_Unwind_Exception *exc)
{
  return reinterpret_cast<__cxa_exception *>(exc + 1) - 1;
}

} /* namespace __cxxabiv1 */

/* Outside callees the game links under other names: libc's memset, the kernel's QueryIntrContext,
   newlib's _impure_ptr and the game's own operator delete (0x106420).  */
asm ("memset = func_002fde18");
asm ("QueryIntrContext = func_003060f0");
asm ("_impure_ptr = D_00365c48");
asm ("_ZdlPv = func_00106420");

/* gthr-ee.h: EE kernel calls and the thread-specific key tables of ee-gthr.o. */
extern "C" {
int DIntr (void);
int EIntr (void);
int QueryIntrContext (void);
int GetThreadId (void);
void *__gthread_get_ee_key_value (void);
void *__gthread_get_ee_key_use (void);
}

#define __GTHREADS 1
#define __GTHREAD_KEYS_MAX 8
typedef int __gthread_key_t;
typedef int __gthread_once_t;
typedef int __gthread_mutex_t;
#define __GTHREAD_ONCE_INIT 0
#define __GTHREAD_MUTEX_INIT 0

static int interupt_was_enabled;

static inline int
__gthread_active_p (void)
{
  return 1;
}

static inline int
__gthread_self_id (void)
{
  int id = 0;
  if (QueryIntrContext () != 1)
    id = GetThreadId ();
  return id;
}

static inline int
__gthread_once (__gthread_once_t *once, void (*func) ())
{
  int run = 0;
  int ie = DIntr ();
  if (*once == 0)
    {
      *once = 1;
      run = 1;
    }
  if (ie)
    EIntr ();
  if (run)
    func ();
  return 0;
}

static inline int
__gthread_key_create (__gthread_key_t *key, void (*dtor) (void *))
{
  int *use = (int *) __gthread_get_ee_key_use ();
  int i;
  int ie = DIntr ();
  for (i = 0; i < __GTHREAD_KEYS_MAX; i++)
    if (!use[i] && dtor)
      {
	use[i] = 1;
	if (ie)
	  EIntr ();
	*key = i;
	return 0;
      }
  if (ie)
    EIntr ();
  return -1;
}

static inline void *
__gthread_getspecific (__gthread_key_t key)
{
  void **value = (void **) __gthread_get_ee_key_value ();
  int *use = (int *) __gthread_get_ee_key_use ();
  if (key > __GTHREAD_KEYS_MAX || !use[key])
    return 0;
  return value[__gthread_self_id () * __GTHREAD_KEYS_MAX + key];
}

static inline int
__gthread_setspecific (__gthread_key_t key, const void *ptr)
{
  void **value = (void **) __gthread_get_ee_key_value ();
  int *use = (int *) __gthread_get_ee_key_use ();
  if (key > __GTHREAD_KEYS_MAX || !use[key])
    return -1;
  value[__gthread_self_id () * __GTHREAD_KEYS_MAX + key] = (void *) ptr;
  return 0;
}

static inline int
__gthread_key_dtor (__gthread_key_t key, void *ptr)
{
  if (ptr)
    return __gthread_setspecific (key, 0);
  else
    return 0;
}

static inline int
__gthread_mutex_lock (__gthread_mutex_t *)
{
  interupt_was_enabled = DIntr ();
  return 0;
}

static inline int
__gthread_mutex_unlock (__gthread_mutex_t *)
{
  if (interupt_was_enabled)
    EIntr ();
  return 0;
}

#endif
