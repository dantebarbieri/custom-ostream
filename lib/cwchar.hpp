/**
 * @file cwchar.hpp
 * @author Dante Barbieri (dante@barbieri.dev)
 * @brief Analogous to the <cwchar> header
 * @version 0.1
 * @date 2021-03-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _CWCHAR_HPP_
#define _CWCHAR_HPP_

// THIS FILE STOLEN FROM THE HEADER wchar.h on my MACHINE

#include "bits/c++config.hpp"
#include "bits/cwchar.hpp"

/* Integral type unchanged by default argument promotions that can
   hold any value corresponding to members of the extended character
   set, as well as at least one value that does not correspond to any
   member of the extended character set.  */
#ifndef __WINT_TYPE__
#define __WINT_TYPE__ unsigned int
#endif

#ifndef WCHAR_MIN
/* These constants might also be defined in <inttypes.h>.  */
# define WCHAR_MIN __WCHAR_MIN
# define WCHAR_MAX __WCHAR_MAX
#endif

#ifndef WEOF
# define WEOF (0xffffffffu)
#endif

namespace dvb
{
    /* Conversion state information.  */
    typedef struct
    {
        int __count;
        union
        {
            __WINT_TYPE__ __wch;
            char __wchb[4];
        } __value; /* Value so far.  */
    } __mbstate_t;

    typedef __mbstate_t mbstate_t;
}

#endif