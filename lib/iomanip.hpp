/**
 * @file iomanip.hpp
 * @author Dante Barbieri (dante@barbieri.dev)
 * @brief Analogous to the <iomanip> header
 * @version 0.1
 * @date 2021-03-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _IOMANIP_HPP_
#define _IOMANIP_HPP_

#include "bits/c++config.hpp"
#include "iosfwd.hpp"
#include "bits/ios_base.hpp"

#include "../console.H"

namespace dvb
{
    struct Setforegroundcolor {
        COLOR_CODE fore;
        Setforegroundcolor(COLOR_CODE f) : fore(f) {}
    };

    inline Setforegroundcolor setforeground(COLOR_CODE color = WHITE) { return color; }

    template <typename CharT, typename Traits>
    inline basic_ostream<CharT, Traits> &
    operator<<(basic_ostream<CharT, Traits> &os, Setforegroundcolor foreground)
    {
        typename basic_ostream<CharT, Traits>::sentry cerb(os);
        (void)cerb;
        os.flush();
        Console::set_TextColor(foreground.fore, Console::get_BackColor());
        return os;
    }

    struct Setbackgroundcolor {
        COLOR_CODE back;
        Setbackgroundcolor(COLOR_CODE b) : back(b) {}
    };

    inline Setbackgroundcolor setbackground(COLOR_CODE color = BLACK) { return color; }

    template <typename CharT, typename Traits>
    inline basic_ostream<CharT, Traits> &
    operator<<(basic_ostream<CharT, Traits> &os, Setbackgroundcolor background)
    {
        typename basic_ostream<CharT, Traits>::sentry cerb(os);
        (void)cerb;
        os.flush();
        Console::set_TextColor(Console::get_ForeColor(), background.back);
        return os;
    }

    struct Setcolor {
        COLOR_CODE fore;
        COLOR_CODE back;
        Setcolor(COLOR_CODE f, COLOR_CODE b) : fore(f), back(b) {}
    };

    inline Setcolor setcolor(COLOR_CODE foreground = WHITE, COLOR_CODE background = BLACK) {
        Setcolor ret(COLOR_CODE(0), COLOR_CODE(0));
        ret.fore = foreground;
        ret.back = background;
        return ret;
    }

    template <typename CharT, typename Traits>
    inline basic_ostream<CharT, Traits> &
    operator<<(basic_ostream<CharT, Traits> &os, Setcolor colors)
    {
        typename basic_ostream<CharT, Traits>::sentry cerb(os);
        (void)cerb;
        os.flush();
        Console::set_TextColor(colors.fore, colors.back);
        return os;
    }

    struct Resetiosflags
    {
        ios_base::fmtflags _M_mask;
        Resetiosflags(ios_base::fmtflags mask) : _M_mask(mask) {}
    };

    inline Resetiosflags resetiosflags(ios_base::fmtflags mask) { return mask; }

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
        Setiosflags(ios_base::fmtflags mask) : _M_mask(mask) {}
    };

    inline Setiosflags setiosflags(ios_base::fmtflags mask) { return mask; }

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
        Setbase(int base) : _M_base(base) {}
    };
    inline Setbase setbase(int base) { return base; }

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
        Setfill(CharT c) : _M_c(c) {}
    };

    template <typename CharT>
    inline Setfill<CharT> setfill(CharT c) { return c; }

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
        Setprecision(int n) : _M_n(n) {}
    };
    inline Setprecision setprecision(int n) { return n; }

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
        Setw(int n) : _M_n(n) {}
    };
    inline Setw setw(int n) { return n; }

    template <typename CharT, typename Traits>
    inline basic_ostream<CharT, Traits> &
    operator<<(basic_ostream<CharT, Traits> &os, Setw f)
    {
        os.width(f._M_n);
        return os;
    }

}

#endif