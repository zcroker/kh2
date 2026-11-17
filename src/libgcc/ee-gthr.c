/* Third-party code notice: this file contains functions rebuilt to match the GNU Compiler
 * Collection's runtime libraries (libgcc / libsupc++, GCC 3.2) that the game links.
 * Copyright (C) Free Software Foundation, Inc. That code is licensed under the GNU General
 * Public License, version 2 or later, with the GCC runtime library exception. It is not
 * covered by this project's MIT License. */
/* libgcc ee-gthr.o (gcc 3.2-ee-040921, the EE port's thread hooks for gthr-ee.h), 0x316e00-0x316e20:
 * the key and mutex tables (.data 0x367928, all zero) and the accessors that libsupc++'s eh_globals
 * uses. Linked unit (linked_units.tsv). */

/* Interrupt state saved by the inline mutex lock in gthr-ee.h.  */
static int interupt_was_enabled;

void *__gthread_ee_key_value[2048] = { 0 };
unsigned char __gthread_ee_key_use[32] = { 0 };
int __gthread_ee_mutex_waits[256] = { 0 };
int __gthread_ee_key_mutex = 0;

void *
__gthread_get_ee_key_value (void)
{
  return __gthread_ee_key_value;
}

void *
__gthread_get_ee_key_use (void)
{
  return __gthread_ee_key_use;
}
