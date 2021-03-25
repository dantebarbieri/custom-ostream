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