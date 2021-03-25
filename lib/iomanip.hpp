#ifndef _IOMANIP_HPP_
#define _IOMANIP_HPP_

#include "bits/c++config.hpp"
#include "iosfwd.hpp"
#include "bits/ios_base.hpp"

namespace dvb
{
    struct Resetiosflags
    {
        ios_base::fmtflags _M_mask;
    };

    inline Resetiosflags resetiosflags(ios_base::fmtflags mask) { return {mask}; }

    template <typename CharT, typename Traits>
    inline basic_ostream<CharT, Traits> &
    operator<<(basic_ostream<CharT, Traits> &os, Resetiosflags f)
    {
        os.setf(ios_base::fmtflags(0), f._M_mask);
        return os;
    }

    struct Setiosflags
    {
        ios_base::fmtflags _M_mask;
    };

    inline Setiosflags setiosflags(ios_base::fmtflags mask) { return {mask}; }

    template <typename CharT, typename Traits>
    inline basic_ostream<CharT, Traits> &
    operator<<(basic_ostream<CharT, Traits> &os, Setiosflags f)
    {
        os.setf(f._M_mask);
        return os;
    }

    struct Setbase
    {
        int _M_base;
    };
    inline Setbase setbase(int base) { return {base}; }

    template <typename CharT, typename Traits>
    inline basic_ostream<CharT, Traits> &
    operator<<(basic_ostream<CharT, Traits> &os, Setbase f)
    {
        switch (f._M_base)
        {
        case 8:
            os.setf(ios_base::oct);
            break;
        case 10:
            os.setf(ios_base::dec);
            break;
        case 16:
            os.setf(ios_base::hex);
            break;
        default:
            os.setf(ios_base::fmtflags(0), ios_base::basefield);
        }
        return os;
    }

    template <typename CharT>
    struct Setfill
    {
        CharT _M_c;
    };

    template <typename CharT>
    inline Setfill<CharT> setfill(CharT c) { return {c}; }

    template <typename CharT, typename Traits>
    inline basic_ostream<CharT, Traits> &
    operator<<(basic_ostream<CharT, Traits> &os, Setfill<CharT> f)
    {
        os.fill(f._M_c);
        return os;
    }

    struct Setprecision
    {
        int _M_n;
    };
    inline Setprecision setprecision(int n) { return {n}; }

    template <typename CharT, typename Traits>
    inline basic_ostream<CharT, Traits> &
    operator<<(basic_ostream<CharT, Traits> &os, Setprecision f)
    {
        os.precision(f._M_n);
        return os;
    }

    struct Setw
    {
        int _M_n;
    };
    inline Setw setw(int n) { return {n}; }

    template <typename CharT, typename Traits>
    inline basic_ostream<CharT, Traits> &
    operator<<(basic_ostream<CharT, Traits> &os, Setw f)
    {
        os.width(f._M_n);
        return os;
    }

}

#endif