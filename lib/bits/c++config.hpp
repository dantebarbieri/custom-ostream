/**
 * @file c++config.hpp
 * @author Dante Barbieri (dante@barbieri.dev)
 * @brief Analogous to the <stddef> or <c++config> header
 * @version 0.1
 * @date 2021-03-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _CXXCONFIG_HPP_
#define _CXXCONFIG_HPP_

#ifndef __SIZE_TYPE__
#define __SIZE_TYPE__ long unsigned int
#endif

#ifndef __PTRDIFF_TYPE__
#define __PTRDIFF_TYPE__ long int
#endif

namespace dvb {
    typedef __SIZE_TYPE__ size_t;
    typedef __PTRDIFF_TYPE__ ptrdiff_t;
}

#endif