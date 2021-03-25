/**
 * @file ios_base.hpp
 * @author Dante Barbieri (dante@barbieri.dev)
 * @brief Analogous to the <ios_base> header
 * @version 0.1
 * @date 2021-03-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _IOS_BASE_HPP_
#define _IOS_BASE_HPP_

#include "../climits.hpp"

namespace dvb
{
    enum _Ios_Fmtflags
    {
        _S_boolalpha = 1L << 0,
        _S_dec = 1L << 1,
        _S_fixed = 1L << 2,
        _S_hex = 1L << 3,
        _S_internal = 1L << 4,
        _S_left = 1L << 5,
        _S_oct = 1L << 6,
        _S_right = 1L << 7,
        _S_scientific = 1L << 8,
        _S_showbase = 1L << 9,
        _S_showpoint = 1L << 10,
        _S_showpos = 1L << 11,
        _S_skipws = 1L << 12,
        _S_unitbuf = 1L << 13,
        _S_uppercase = 1L << 14,
        _S_adjustfield = _S_left | _S_right | _S_internal,
        _S_basefield = _S_dec | _S_oct | _S_hex,
        _S_floatfield = _S_scientific | _S_fixed,
        _S_ios_fmtflags_end = 1L << 16,
        _S_ios_fmtflags_max = __INT_MAX__,
        _S_ios_fmtflags_min = ~__INT_MAX__
    };

    inline _Ios_Fmtflags
    operator&(_Ios_Fmtflags __a, _Ios_Fmtflags __b)
    {
        return _Ios_Fmtflags(static_cast<int>(__a) & static_cast<int>(__b));
    }

    inline _Ios_Fmtflags
    operator|(_Ios_Fmtflags __a, _Ios_Fmtflags __b)
    {
        return _Ios_Fmtflags(static_cast<int>(__a) | static_cast<int>(__b));
    }

    inline _Ios_Fmtflags
    operator^(_Ios_Fmtflags __a, _Ios_Fmtflags __b)
    {
        return _Ios_Fmtflags(static_cast<int>(__a) ^ static_cast<int>(__b));
    }

    inline _Ios_Fmtflags
    operator~(_Ios_Fmtflags __a)
    {
        return _Ios_Fmtflags(~static_cast<int>(__a));
    }

    inline const _Ios_Fmtflags &
    operator|=(_Ios_Fmtflags &__a, _Ios_Fmtflags __b)
    {
        return __a = __a | __b;
    }

    inline const _Ios_Fmtflags &
    operator&=(_Ios_Fmtflags &__a, _Ios_Fmtflags __b)
    {
        return __a = __a & __b;
    }

    inline const _Ios_Fmtflags &
    operator^=(_Ios_Fmtflags &__a, _Ios_Fmtflags __b)
    {
        return __a = __a ^ __b;
    }

    enum _Ios_Openmode
    {
        _S_app = 1L << 0,
        _S_ate = 1L << 1,
        _S_bin = 1L << 2,
        _S_in = 1L << 3,
        _S_out = 1L << 4,
        _S_trunc = 1L << 5,
        _S_ios_openmode_end = 1L << 16,
        _S_ios_openmode_max = __INT_MAX__,
        _S_ios_openmode_min = ~__INT_MAX__
    };

    inline _Ios_Openmode
    operator&(_Ios_Openmode __a, _Ios_Openmode __b)
    {
        return _Ios_Openmode(static_cast<int>(__a) & static_cast<int>(__b));
    }

    inline _Ios_Openmode
    operator|(_Ios_Openmode __a, _Ios_Openmode __b)
    {
        return _Ios_Openmode(static_cast<int>(__a) | static_cast<int>(__b));
    }

    inline _Ios_Openmode
    operator^(_Ios_Openmode __a, _Ios_Openmode __b)
    {
        return _Ios_Openmode(static_cast<int>(__a) ^ static_cast<int>(__b));
    }

    inline _Ios_Openmode
    operator~(_Ios_Openmode __a)
    {
        return _Ios_Openmode(~static_cast<int>(__a));
    }

    inline const _Ios_Openmode &
    operator|=(_Ios_Openmode &__a, _Ios_Openmode __b)
    {
        return __a = __a | __b;
    }

    inline const _Ios_Openmode &
    operator&=(_Ios_Openmode &__a, _Ios_Openmode __b)
    {
        return __a = __a & __b;
    }

    inline const _Ios_Openmode &
    operator^=(_Ios_Openmode &__a, _Ios_Openmode __b)
    {
        return __a = __a ^ __b;
    }

    enum _Ios_Iostate
    {
        _S_goodbit = 0,
        _S_badbit = 1L << 0,
        _S_eofbit = 1L << 1,
        _S_failbit = 1L << 2,
        _S_ios_iostate_end = 1L << 16,
        _S_ios_iostate_max = __INT_MAX__,
        _S_ios_iostate_min = ~__INT_MAX__
    };

    inline _Ios_Iostate
    operator&(_Ios_Iostate __a, _Ios_Iostate __b)
    {
        return _Ios_Iostate(static_cast<int>(__a) & static_cast<int>(__b));
    }

    inline _Ios_Iostate
    operator|(_Ios_Iostate __a, _Ios_Iostate __b)
    {
        return _Ios_Iostate(static_cast<int>(__a) | static_cast<int>(__b));
    }

    inline _Ios_Iostate
    operator^(_Ios_Iostate __a, _Ios_Iostate __b)
    {
        return _Ios_Iostate(static_cast<int>(__a) ^ static_cast<int>(__b));
    }

    inline _Ios_Iostate
    operator~(_Ios_Iostate __a)
    {
        return _Ios_Iostate(~static_cast<int>(__a));
    }

    inline const _Ios_Iostate &
    operator|=(_Ios_Iostate &__a, _Ios_Iostate __b)
    {
        return __a = __a | __b;
    }

    inline const _Ios_Iostate &
    operator&=(_Ios_Iostate &__a, _Ios_Iostate __b)
    {
        return __a = __a & __b;
    }

    inline const _Ios_Iostate &
    operator^=(_Ios_Iostate &__a, _Ios_Iostate __b)
    {
        return __a = __a ^ __b;
    }

    enum _Ios_Seekdir
    {
        _S_beg = 0,
        _S_cur = 1L << 0,
        _S_end = 1L << 1,
        _S_ios_seekdir_end = 1L << 16
    };

    class ios_base
    {
    public:
        class Init;
        typedef _Ios_Fmtflags fmtflags;
        typedef _Ios_Openmode openmode;
        typedef _Ios_Iostate iostate;
        typedef _Ios_Seekdir seekdir;

    private:
        static const unsigned short WORD_SIZE_MAX = USHRT_MAX;
        static int index;
        ios_base(const ios_base &);
        ios_base &operator=(const ios_base &);

    protected:
        streamsize _M_precision;
        streamsize _M_width;
        fmtflags _M_flags;
        iostate _M_streambuf_state;

        // 27.4.2.5  Members for iword/pword storage
        struct _Words
        {
            void *_M_pword;
            long _M_iword;
            _Words() : _M_pword(0), _M_iword(0) {}
        };

        // Only for failed iword/pword calls.
        _Words _M_word_zero;

        // Guaranteed storage.
        // The first 5 iword and pword slots are reserved for internal use.
        enum
        {
            _S_local_word_size = 8
        };
        _Words _M_local_word[_S_local_word_size];

        // Allocated storage.
        int _M_word_size;
        _Words *_M_word;

        _Words &
        _M_grow_words(int __index, bool __iword)
        {
            (void)__iword;
            if (__index > WORD_SIZE_MAX)
                return _M_word_zero;
            return _M_word[__index];
        }
        ios_base() {}

    public:
        // virtual ~ios_base() {}
        fmtflags flags() const { return _M_flags; }
        fmtflags flags(fmtflags flags)
        {
            fmtflags old = _M_flags;
            _M_flags = flags;
            return old;
        }
        fmtflags setf(fmtflags flags)
        {
            fmtflags old = _M_flags;
            _M_flags |= flags;
            return old;
        }
        fmtflags setf(fmtflags flags, fmtflags mask)
        {
            fmtflags old = _M_flags;
            _M_flags &= ~mask;
            _M_flags |= flags & mask;
            return old;
        }
        void unsetf(fmtflags flags) { _M_flags &= ~flags; }
        streamsize precision() const { return _M_precision; }
        streamsize precision(streamsize new_precision)
        {
            streamsize old = _M_precision;
            _M_precision = new_precision;
            return old;
        }
        streamsize width() const { return _M_width; }
        streamsize width(streamsize new_width)
        {
            streamsize old = _M_width;
            _M_width = new_width;
            return old;
        }
        static int xalloc() { return index++; }
        long &iword(int index)
        {
            _Words &word = ((unsigned)index < (unsigned)_M_word_size) ? _M_word[index] : _M_grow_words(index, true);
            return word._M_iword;
        }
        void *&pword(int index)
        {
            _Words &word = ((unsigned)index < (unsigned)_M_word_size) ? _M_word[index] : _M_grow_words(index, false);
            return word._M_pword;
        }
        static const openmode app = _S_app;
        static const openmode binary = _S_bin;
        static const openmode in = _S_in;
        static const openmode out = _S_out;
        static const openmode trunc = _S_trunc;
        static const openmode ate = _S_ate;
        static const fmtflags dec = _S_dec;
        static const fmtflags oct = _S_oct;
        static const fmtflags hex = _S_hex;
        static const fmtflags basefield = _S_basefield;
        static const fmtflags left = _S_left;
        static const fmtflags right = _S_right;
        static const fmtflags internal = _S_internal;
        static const fmtflags adjustfield = _S_adjustfield;
        static const fmtflags scientific = _S_scientific;
        static const fmtflags fixed = _S_fixed;
        static const fmtflags floatfield = _S_floatfield;
        static const fmtflags boolalpha = _S_boolalpha;
        static const fmtflags showbase = _S_showbase;
        static const fmtflags showpoint = _S_showpoint;
        static const fmtflags showpos = _S_showpos;
        static const fmtflags skipws = _S_skipws;
        static const fmtflags unitbuf = _S_unitbuf;
        static const fmtflags uppercase = _S_uppercase;
        static const iostate goodbit = _S_goodbit;
        static const iostate badbit = _S_badbit;
        static const iostate failbit = _S_failbit;
        static const iostate eofbit = _S_eofbit;
        static const seekdir beg = _S_beg;
        static const seekdir end = _S_end;
        static const seekdir cur = _S_cur;
    };

    int ios_base::index = 0;
}

namespace dvb
{

    class ios_base::Init
    {
        friend class ios_base;

    public:
        Init();
        // ~Init();

    private:
        static int _S_refcount;
        static bool _S_synced_with_stdio;
    };

    int ios_base::Init::_S_refcount = 0;
    bool ios_base::Init::_S_synced_with_stdio = false;
}

namespace dvb
{
    // [27.4.5.1] fmtflags manipulators
    /// Calls base.setf(ios_base::boolalpha).
    inline ios_base &boolalpha(ios_base &base)
    {
        base.setf(ios_base::boolalpha);
        return base;
    }

    /// Calls base.unsetf(ios_base::boolalpha).
    inline ios_base &noboolalpha(ios_base &base)
    {
        base.unsetf(ios_base::boolalpha);
        return base;
    }

    /// Calls base.setf(ios_base::showbase).
    inline ios_base &showbase(ios_base &base)
    {
        base.setf(ios_base::showbase);
        return base;
    }

    /// Calls base.unsetf(ios_base::showbase).
    inline ios_base &noshowbase(ios_base &base)
    {
        base.unsetf(ios_base::showbase);
        return base;
    }

    /// Calls base.setf(ios_base::showpoint).
    inline ios_base &showpoint(ios_base &base)
    {
        base.setf(ios_base::showpoint);
        return base;
    }

    /// Calls base.unsetf(ios_base::showpoint).
    inline ios_base &noshowpoint(ios_base &base)
    {
        base.unsetf(ios_base::showpoint);
        return base;
    }

    /// Calls base.setf(ios_base::showpos).
    inline ios_base &showpos(ios_base &base)
    {
        base.setf(ios_base::showpos);
        return base;
    }

    /// Calls base.unsetf(ios_base::showpos).
    inline ios_base &noshowpos(ios_base &base)
    {
        base.unsetf(ios_base::showpos);
        return base;
    }

    /// Calls base.setf(ios_base::skipws).
    inline ios_base &skipws(ios_base &base)
    {
        base.setf(ios_base::skipws);
        return base;
    }

    /// Calls base.unsetf(ios_base::skipws).
    inline ios_base &noskipws(ios_base &base)
    {
        base.unsetf(ios_base::skipws);
        return base;
    }

    /// Calls base.setf(ios_base::uppercase).
    inline ios_base &uppercase(ios_base &base)
    {
        base.setf(ios_base::uppercase);
        return base;
    }

    /// Calls base.unsetf(ios_base::uppercase).
    inline ios_base &nouppercase(ios_base &base)
    {
        base.unsetf(ios_base::uppercase);
        return base;
    }

    /// Calls base.setf(ios_base::unitbuf).
    inline ios_base &unitbuf(ios_base &base)
    {
        base.setf(ios_base::unitbuf);
        return base;
    }

    /// Calls base.unsetf(ios_base::unitbuf).
    inline ios_base &nounitbuf(ios_base &base)
    {
        base.unsetf(ios_base::unitbuf);
        return base;
    }

    // [27.4.5.2] adjustfield manipulators
    /// Calls base.setf(ios_base::internal, ios_base::adjustfield).
    inline ios_base &internal(ios_base &base)
    {
        base.setf(ios_base::internal, ios_base::adjustfield);
        return base;
    }

    /// Calls base.setf(ios_base::left, ios_base::adjustfield).
    inline ios_base &left(ios_base &base)
    {
        base.setf(ios_base::left, ios_base::adjustfield);
        return base;
    }

    /// Calls base.setf(ios_base::right, ios_base::adjustfield).
    inline ios_base &right(ios_base &base)
    {
        base.setf(ios_base::right, ios_base::adjustfield);
        return base;
    }

    // [27.4.5.3] basefield manipulators
    /// Calls base.setf(ios_base::dec, ios_base::basefield).
    inline ios_base &dec(ios_base &base)
    {
        base.setf(ios_base::dec, ios_base::basefield);
        return base;
    }

    /// Calls base.setf(ios_base::hex, ios_base::basefield).
    inline ios_base &hex(ios_base &base)
    {
        base.setf(ios_base::hex, ios_base::basefield);
        return base;
    }

    /// Calls base.setf(ios_base::oct, ios_base::basefield).
    inline ios_base &oct(ios_base &base)
    {
        base.setf(ios_base::oct, ios_base::basefield);
        return base;
    }

    // [27.4.5.4] floatfield manipulators
    /// Calls base.setf(ios_base::fixed, ios_base::floatfield).
    inline ios_base &fixed(ios_base &base)
    {
        base.setf(ios_base::fixed, ios_base::floatfield);
        return base;
    }

    /// Calls base.setf(ios_base::scientific, ios_base::floatfield).
    inline ios_base &scientific(ios_base &base)
    {
        base.setf(ios_base::scientific, ios_base::floatfield);
        return base;
    }

    // New C++11 floatfield manipulators

    /// Calls
    /// base.setf(ios_base::fixed|ios_base::scientific, ios_base::floatfield)
    inline ios_base &hexfloat(ios_base &base)
    {
        base.setf(ios_base::fixed | ios_base::scientific, ios_base::floatfield);
        return base;
    }

    /// Calls @c base.unsetf(ios_base::floatfield)
    inline ios_base &defaultfloat(ios_base &base)
    {
        base.unsetf(ios_base::floatfield);
        return base;
    }
}

#endif