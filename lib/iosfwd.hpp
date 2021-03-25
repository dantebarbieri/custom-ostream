#ifndef _IOSFWD_HPP_
#define _IOSFWD_HPP_

#include "bits/c++config.hpp"
#include "bits/stringfwd.hpp"
#include "bits/postypes.hpp"

namespace dvb
{
    class ios_base;

    template <typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_ios;

    template <typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_streambuf;

    // template <typename _CharT, typename _Traits = char_traits<_CharT> >
    // class basic_istream;

    template <typename _CharT, typename _Traits = char_traits<_CharT> >
    class basic_ostream;

    // template <typename _CharT, typename _Traits = char_traits<_CharT> >
    // class basic_iostream;

    /// Base class for @c char streams.
    typedef basic_ios<char> ios;

    /// Base class for @c char buffers.
    typedef basic_streambuf<char> streambuf;

    // /// Base class for @c char input streams.
    // typedef basic_istream<char> istream;

    /// Base class for @c char output streams.
    typedef basic_ostream<char> ostream;

    // /// Base class for @c char mixed input and output streams.
    // typedef basic_iostream<char> iostream;

    // /// Class for @c char memory buffers.
    // typedef basic_stringbuf<char> stringbuf;

    // /// Class for @c char input memory streams.
    // typedef basic_istringstream<char> istringstream;

    // /// Class for @c char output memory streams.
    // typedef basic_ostringstream<char> ostringstream;

    // /// Class for @c char mixed input and output memory streams.
    // typedef basic_stringstream<char> stringstream;

    // /// Class for @c char file buffers.
    // typedef basic_filebuf<char> filebuf;

    // /// Class for @c char input file streams.
    // typedef basic_ifstream<char> ifstream;

    // /// Class for @c char output file streams.
    // typedef basic_ofstream<char> ofstream;

    // /// Class for @c char mixed input and output file streams.
    // typedef basic_fstream<char> fstream;
}

#endif