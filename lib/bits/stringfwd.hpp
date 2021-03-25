#ifndef _STRINGFWD_HPP_
#define _STRINGFWD_HPP_

#include "c++config.hpp"

namespace dvb {
    template<class _CharT>
    struct char_traits;

    template<> struct char_traits<char>;
}

#endif