/**
 * @file iostream.hpp
 * @author Dante Barbieri (dante@barbieri.dev)
 * @brief Analogous to the <iostream> header
 * @version 0.1
 * @date 2021-03-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _IOSTREAM_HPP_
#define _IOSTREAM_HPP_

#include "bits/c++config.hpp"
#include "ostream.hpp"

#include "../console.H"

namespace dvb
{
    extern streambuf cout_buf;
    extern streambuf cerr_buf;
    extern streambuf clog_buf;

    extern ostream cout;
    extern ostream cerr;
    extern ostream clog;

    inline dvb::ios_base::Init::Init()
    {
        if (++_S_refcount >= 1)
        {
            Console::init();

            cerr.setf(unitbuf);

            cerr.tie(&cout);
        }
    }

    static ios_base::Init __ioinit;
}

#endif