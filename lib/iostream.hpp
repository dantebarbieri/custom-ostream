#ifndef _IOSTREAM_HPP_
#define _IOSTREAM_HPP_

#include "bits/c++config.hpp"
#include "ostream.hpp"

namespace dvb
{
    extern streambuf cout_buf;
    extern streambuf cerr_buf;
    extern streambuf clog_buf;

    extern ostream cout;
    extern ostream cerr;
    extern ostream clog;

    streambuf cout_buf;
    streambuf cerr_buf;
    streambuf clog_buf;

    ostream cout(&cout_buf);
    ostream cerr(&cerr_buf);
    ostream clog(&clog_buf);

    ios_base::Init::Init()
    {
        ++_S_refcount;
        if (_S_refcount == 1)
        {
            cout.flags(dec | left);
            cerr.flags(cout.flags() | unitbuf);
            clog.flags(cout.flags());

            cerr.tie(&cout);
            clog.tie(&cout);
        }
    }
    ios_base::Init::~Init()
    {
        --_S_refcount;
        if (_S_refcount == 0)
            cout.flush();
    }

    static ios_base::Init __ioinit;

}

#endif