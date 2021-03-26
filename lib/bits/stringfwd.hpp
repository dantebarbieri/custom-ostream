/**
 * @file stringfwd.hpp
 * @author Dante Barbieri (dante@barbieri.dev)
 * @brief Analogous to the <stringfwd> header
 * @version 0.1
 * @date 2021-03-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _STRINGFWD_HPP_
#define _STRINGFWD_HPP_

#include "c++config.hpp"

namespace dvb {
    template<class _CharT>
    struct char_traits;

    template<> struct char_traits<char>;
}

#endif