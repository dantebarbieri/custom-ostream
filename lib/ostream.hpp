/**
 * @file ostream.hpp
 * @author Dante Barbieri (dante@barbieri.dev)
 * @brief Analogous to the <ostream> header
 * @version 0.1
 * @date 2021-03-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _OSTREAM_HPP_
#define _OSTREAM_HPP_

// #include <ostream>
#include "ios.hpp"
#include "bits/ostream_insert.hpp"
#include "limits.hpp"

namespace dvb
{
    template <typename CharT, typename Traits>
    class basic_ostream : virtual public basic_ios<CharT, Traits>
    {
    public:
        typedef CharT char_type;
        typedef Traits traits_type;
        typedef typename traits_type::int_type int_type;
        typedef typename traits_type::pos_type pos_type;
        typedef typename traits_type::off_type off_type;

        friend class ios_base::Init;

    private:
        basic_ostream &operator=(const basic_ostream &rhs);

    protected:
        basic_ostream() : basic_ios<CharT, Traits>() { this->init(0); }
        template <typename ValueT>
        basic_ostream<CharT, Traits> &
        _M_insert(ValueT value);
        void _M_write(const char_type *s, streamsize count)
        {
            const streamsize put = this->rdbuf()->sputn(s, count);
            if (put != count)
            {
                this->setstate(ios_base::badbit);
            }
        }

    public:
        class sentry;
        friend class sentry;
        explicit basic_ostream(basic_streambuf<CharT, Traits> *sb) : basic_ios<CharT, Traits>() { this->init(sb); }
        // virtual ~basic_ostream() {}
        // inserts formatted data
        basic_ostream &operator<<(short value);
        // inserts formatted data
        basic_ostream &operator<<(unsigned short value) { return _M_insert(static_cast<unsigned long>(value)); }
        // inserts formatted data
        basic_ostream &operator<<(int value);
        // inserts formatted data
        basic_ostream &operator<<(unsigned int value) { return _M_insert(static_cast<unsigned long>(value)); }
        // inserts formatted data
        basic_ostream &operator<<(long value) { return _M_insert(value); }
        // inserts formatted data
        basic_ostream &operator<<(unsigned long value) { return _M_insert(value); }
        // inserts formatted data
        basic_ostream &operator<<(float value) { return _M_insert(static_cast<double>(value)); }
        // inserts formatted data
        basic_ostream &operator<<(double value) { return _M_insert(value); }
        // inserts formatted data
        basic_ostream &operator<<(long double value) { return _M_insert(value); }
        // inserts formatted data
        basic_ostream &operator<<(bool value) { return _M_insert(value); }
        // inserts formatted data
        basic_ostream &operator<<(const void *value) { return _M_insert(value); }
        // inserts formatted data
        basic_ostream &operator<<(basic_streambuf<CharT, Traits> *sb);
        // inserts formatted data
        basic_ostream &operator<<(ios_base &(*func)(ios_base &))
        {
            func(*this);
            return *this;
        }
        // inserts formatted data
        basic_ostream &operator<<(basic_ios<CharT, Traits> &(*func)(basic_ios<CharT, Traits> &))
        {
            func(*this);
            return *this;
        }
        // inserts formatted data
        basic_ostream &operator<<(basic_ostream<CharT, Traits> &(*func)(basic_ostream<CharT, Traits> &)) { return func(*this); }
        basic_ostream &put(char_type ch);
        basic_ostream &write(const char_type *s, streamsize count);
        pos_type tellp();
        basic_ostream &seekp(pos_type pos);
        basic_ostream &seekp(off_type off, ios_base::seekdir dir);
        basic_ostream &flush();
    };

    template <typename CharT, typename Traits>
    class basic_ostream<CharT, Traits>::sentry
    {
        bool ok;
        basic_ostream<CharT, Traits> &os;

    public:
        explicit sentry(basic_ostream<CharT, Traits> &os);

        ~sentry()
        {
            if (bool(os.flags() & ios_base::unitbuf))
            {
                if (os.rdbuf() && os.rdbuf()->pubsync() == -1)
                    os.setstate(ios_base::badbit);
            }
        }

        operator bool() const { return ok; }
    };

    template <typename CharT, typename Traits>
    inline basic_ostream<CharT, Traits> &operator<<(basic_ostream<CharT, Traits> &os, CharT ch) { return ostream_insert(os, &ch, 1); }

    template <class Traits>
    inline basic_ostream<char, Traits> &operator<<(basic_ostream<char, Traits> &os, char ch) { return ostream_insert(os, &ch, 1); }

    template <class Traits>
    inline basic_ostream<char, Traits> &operator<<(basic_ostream<char, Traits> &os, signed char ch) { return os << static_cast<char>(ch); }

    template <class Traits>
    inline basic_ostream<char, Traits> &operator<<(basic_ostream<char, Traits> &os, unsigned char ch) { return os << static_cast<char>(ch); }

    template <class CharT, class Traits>
    inline basic_ostream<CharT, Traits> &operator<<(basic_ostream<CharT, Traits> &os, const CharT *s)
    {
        if (!s)
            os.setstate(ios_base::badbit);
        else
            ostream_insert(os, s, static_cast<streamsize>(Traits::length(s)));
        return os;
    }

    template <class CharT, class Traits>
    basic_ostream<CharT, Traits> &operator<<(basic_ostream<CharT, Traits> &os, const char *s);

    template <class Traits>
    inline basic_ostream<char, Traits> &operator<<(basic_ostream<char, Traits> &os, const char *s)
    {
        if (!s)
            os.setstate(ios_base::badbit);
        else
            ostream_insert(os, s, static_cast<streamsize>(Traits::length(s)));
        return os;
    }

    template <class Traits>
    inline basic_ostream<char, Traits> &operator<<(basic_ostream<char, Traits> &os, const signed char *s) { return os << reinterpret_cast<const char *>(s); }

    template <class Traits>
    inline basic_ostream<char, Traits> &operator<<(basic_ostream<char, Traits> &os, const unsigned char *s) { return os << reinterpret_cast<const char *>(s); }

    template <typename CharT, typename Traits>
    inline basic_ostream<CharT, Traits> &endl(basic_ostream<CharT, Traits> &os) { return flush(os.put(CharT('\n'))); }

    template <typename CharT, typename Traits>
    inline basic_ostream<CharT, Traits> &ends(basic_ostream<CharT, Traits> &os) { return os.put(CharT()); }

    template <typename CharT, typename Traits>
    inline basic_ostream<CharT, Traits> &flush(basic_ostream<CharT, Traits> &os) { return os.flush(); }

    typedef basic_ostream<char> ostream;
    typedef basic_ostream<wchar_t> wostream;
}

#include "bits/ostream.tcc"

#endif