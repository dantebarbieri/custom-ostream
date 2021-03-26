/**
 * @file ostream_insert.hpp
 * @author Dante Barbieri (dante@barbieri.dev)
 * @brief Provides helpers for the ostream, seen in GNU implementations of CXX
 * @version 0.1
 * @date 2021-03-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _OSTREAM_INSERT_HPP_
#define _OSTREAM_INSERT_HPP_

#include "../iosfwd.hpp"

namespace dvb
{
    template <typename CharT, typename Traits>
    inline void ostream_write(basic_ostream<CharT, Traits> &out, const CharT *s, streamsize count)
    {
        const streamsize put = out.rdbuf()->sputn(s, count);
        if (put != count)
            out.setstate(basic_ostream<CharT, Traits>::ios_base::badbit);
    }

    template <typename CharT, typename Traits>
    inline void ostream_fill(basic_ostream<CharT, Traits> &out, streamsize count)
    {
        const CharT c = out.fill();
        for (; count > 0; --count)
        {
            const typename Traits::int_type put = out.rdbuf()->sputc(c);
            if (Traits::eq_int_type(put, Traits::eof()))
            {
                out.setstate(basic_ostream<CharT, Traits>::ios_base::badbit);
            }
        }
    }

    template <typename CharT, typename Traits>
    basic_ostream<CharT, Traits> &ostream_insert(basic_ostream<CharT, Traits> &out, const CharT *s, streamsize count)
    {
        typename basic_ostream<CharT, Traits>::sentry cerb(out);
        if (cerb)
        {
            const streamsize w = out.width();
            if (w > count)
            {
                const bool left = ((out.flags() & basic_ostream<CharT, Traits>::ios_base::adjustfield) == basic_ostream<CharT, Traits>::ios_base::left);
                if (!left)
                    ostream_fill(out, w - count);
                if (out.good())
                    ostream_write(out, s, count);
                if (left && out.good())
                    ostream_fill(out, w - count);
            }
            else
                ostream_write(out, s, count);
            out.width(0);
        }
        return out;
    }
}

#endif
