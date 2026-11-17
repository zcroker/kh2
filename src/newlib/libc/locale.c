/* locale.c: newlib libc (libc/locale/locale.c, "C" locale only), the copy the game links from the toolchain's
 * libc.a. Linked unit 0x303728-0x303808 (.data __mb_cur_max 0x3660b4, .rodata 0x377cb8). Third-party code notice: rebuilt to match; not covered by this project's
 * MIT License. newlib, Cygnus Support. */
#include "newlib.h"
int strcmp(const char *, const char *);
#define CHAR_MAX 127
#define _REENT _impure_ptr

struct lconv {
    char *decimal_point;
    char *thousands_sep;
    char *grouping;
    char *int_curr_symbol;
    char *currency_symbol;
    char *mon_decimal_point;
    char *mon_thousands_sep;
    char *mon_grouping;
    char *positive_sign;
    char *negative_sign;
    char int_frac_digits;
    char frac_digits;
    char p_cs_precedes;
    char p_sep_by_space;
    char n_cs_precedes;
    char n_sep_by_space;
    char p_sign_posn;
    char n_sign_posn;
};

int __mb_cur_max = 1;

static const struct lconv lconv = {
    ".", "", "", "", "", "", "", "", "", "",
    CHAR_MAX, CHAR_MAX, CHAR_MAX, CHAR_MAX,
    CHAR_MAX, CHAR_MAX, CHAR_MAX, CHAR_MAX,
};

char *_setlocale_r(struct _reent *p, int category, const char *locale)
{
    if (locale) {
        if (strcmp(locale, "C") && strcmp(locale, ""))
            return 0;
        p->_current_category = category;
        p->_current_locale = locale;
    }
    return "C";
}

struct lconv *_localeconv_r(struct _reent *data)
{
    return (struct lconv *)&lconv;
}

char *setlocale(int category, const char *locale)
{
    return _setlocale_r(_REENT, category, locale);
}

struct lconv *localeconv(void)
{
    return _localeconv_r(_REENT);
}
