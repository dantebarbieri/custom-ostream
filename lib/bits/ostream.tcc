/**
 * @file ostream.tcc
 * @author Dante Barbieri (dante@barbieri.dev)
 * @brief Implementation of the ostream.hpp file
 * @version 0.1
 * @date 2021-03-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _OSTREAM_TCC_
#define _OSTREAM_TCC_

#ifndef __MAX_DOUBLE_DIGITS__
#define __MAX_DOUBLE_DIGITS__ 256
#endif

namespace dvb
{
    template <typename CharT, typename Traits>
    basic_ostream<CharT, Traits>::sentry::sentry(basic_ostream<CharT, Traits> &os) : ok(false), os(os)
    {
        if (os.tie() && os.good())
            os.tie()->flush();
        if (os.good())
            ok = true;
        else
            os.setstate(ios_base::failbit);
    }

    template <typename CharT, typename Traits>
    basic_ostream<CharT, Traits> &basic_ostream<CharT, Traits>::operator<<(short value)
    {
        const ios_base::fmtflags fmt = this->flags() & ios_base::basefield;
        if (fmt == ios_base::oct || fmt == ios_base::hex)
            return _M_insert(static_cast<long>(static_cast<unsigned short>(value)));
        else
            return _M_insert(static_cast<long>(value));
    }

    template <typename CharT, typename Traits>
    basic_ostream<CharT, Traits> &basic_ostream<CharT, Traits>::operator<<(int value)
    {
        const ios_base::fmtflags fmt = this->flags() & ios_base::basefield;
        if (fmt == ios_base::oct || fmt == ios_base::hex)
            return _M_insert(static_cast<long>(static_cast<unsigned int>(value)));
        else
            return _M_insert(static_cast<long>(value));
    }

    template <typename CharT, typename Traits>
    basic_ostream<CharT, Traits> &basic_ostream<CharT, Traits>::put(char_type ch)
    {
        sentry cerb(*this);
        if (cerb)
        {
            ios_base::iostate err = ios_base::goodbit;
            const int_type p = this->rdbuf()->sputc(ch);
            if (traits_type::eq_int_type(p, traits_type::eof()))
                err |= ios_base::badbit;
            if (err)
                this->setstate(err);
        }
        return *this;
    }

    template <typename CharT, typename Traits>
    basic_ostream<CharT, Traits> &basic_ostream<CharT, Traits>::write(const CharT *s, streamsize count)
    {
        sentry cerb(*this);
        if (cerb)
        {
            _M_write(s, count);
        }
        return *this;
    }

    template <typename CharT, typename Traits>
    basic_ostream<CharT, Traits> &basic_ostream<CharT, Traits>::flush()
    {
        ios_base::iostate err = ios_base::goodbit;
        if (this->rdbuf() && this->rdbuf()->pubsync() == -1)
            err |= ios_base::badbit;
        this->setstate(err);
        return *this;
    }

    template <typename CharT, typename Traits>
    typename basic_ostream<CharT, Traits>::pos_type basic_ostream<CharT, Traits>::tellp()
    {
        pos_type ret = pos_type(-1);
        if (!this->fail())
        {
            ret = this->rdbuf()->pubseekoff(0, ios_base::cur, ios_base::out);
        }
        return ret;
    }

    template <typename CharT, typename Traits>
    basic_ostream<CharT, Traits> &basic_ostream<CharT, Traits>::seekp(pos_type pos)
    {
        ios_base::iostate err = ios_base::goodbit;
        if (!this->fail())
        {
            const pos_type p = this->rdbuf()->pubseekpos(pos, ios_base::out);
            if (p == pos_type(off_type(-1)))
                err |= ios_base::failbit;
        }
        if (err)
            this->setstate(err);
        return *this;
    }

    template <typename CharT, typename Traits>
    basic_ostream<CharT, Traits> &basic_ostream<CharT, Traits>::seekp(off_type off, ios_base::seekdir dir)
    {
        ios_base::iostate err = ios_base::goodbit;
        if (!this->fail())
        {
            const pos_type p = this->rdbuf()->pubseekoff(off, dir, ios_base::out);
            if (p == pos_type(off_type(-1)))
                err |= ios_base::failbit;
        }
        if (err)
            this->setstate(err);
        return *this;
    }

    template <typename CharT, typename Traits>
    basic_ostream<CharT, Traits> &operator<<(basic_ostream<CharT, Traits> &os, const char *s)
    {
        if (!s)
            os.setstate(ios::badbit);
        else
        {
            const size_t clen = char_traits<char>::length(s);
            ostream_insert(os, s, clen);
        }
        return os;
    }

    namespace dmath
    {
        unsigned short count_digits(unsigned long number, unsigned short base = 10)
        {
            unsigned short digits = 0;
            do
            {
                ++digits;
                number /= base;
            } while (number);
            return digits;
        }

        char *integer_to_string(char *buf, unsigned long number, unsigned short base = 10, size_t start = 0, bool uppercase = false, int min_digits = 0, bool fill_left = true)
        {
            unsigned short digits = count_digits(number, base);
            if(fill_left)
                digits = digits < min_digits ? min_digits : digits;
            char dig;
            for (unsigned short count_placed = 0; count_placed < digits; ++count_placed)
            {
                dig = char(number % base + '0');
                if (dig >= '0' + 10)
                    dig += (uppercase ? 'A' : 'a') - '0' - 10;
                number /= base;
                buf[start + digits - count_placed - 1] = dig;
            }
            start += digits;
            for(int i = digits; i < min_digits; ++i)
                buf[start++] = '0';
            buf[start] = '\0';
            return buf;
        }

        unsigned long round(long double number)
        {
            return (unsigned long)(number + 0.5);
        }

        char *decimal_to_string_fixed(char *buf, long double number, int precision = -1, size_t start = 0, int base = 10, bool uppercase = false, bool showpoint = true)
        {
            unsigned long magnitude = (unsigned long)number;
            long double mantissa = number - magnitude;
            unsigned short mag_digits = count_digits(magnitude, (unsigned short)base);
            for (unsigned short count_placed = 0; count_placed < mag_digits; ++count_placed)
            {
                buf[start + mag_digits - count_placed - 1] = magnitude % base + '0';
                if (buf[start + mag_digits - count_placed - 1] >= '0' + 10)
                    buf[start + mag_digits - count_placed - 1] += (uppercase ? 'A' : 'a') - '0' - 10;
                magnitude /= base;
            }
            start += mag_digits;
            if (showpoint || mantissa > 0)
                buf[start++] = '.';
            long double prod;
            char dig;
            for (unsigned short count_placed = 0; (precision == -1 || count_placed < precision) && mantissa > 0; ++count_placed)
            {
                prod = mantissa * base;
                dig = (unsigned long)prod + '0';
                if(dig >= '0' + 10)
                    dig += (uppercase ? 'A' : 'a') - '0' - 10;
                buf[start++] = dig;
                mantissa = prod - (unsigned long)prod;
            }
            buf[start] = '\0';
            return buf;
        }

        struct scientific
        {
            long double number;
            int exponent;
        };

        scientific number_to_scientific(long double number, int base = 10, int exp_base = -1)
        {
            if (exp_base == -1)
                exp_base = base;
            scientific ret;
            ret.number = number;
            ret.exponent = 0;
            if (ret.number >= base)
            {
                while (ret.number >= base)
                {
                    ret.number /= exp_base;
                    ++ret.exponent;
                }
            }
            else if (ret.number < 1)
            {
                while (ret.number < 1)
                {
                    ret.number *= exp_base;
                    --ret.exponent;
                }
            }
            return ret;
        }

        char *decimal_to_string_scientific(char *buf, long double number, int precision, size_t start = 0, bool uppercase = false, bool showpoint = true)
        {
            scientific sci = number_to_scientific(number, 10);
            decimal_to_string_fixed(buf, sci.number, precision, start, 10, uppercase, showpoint);
            start = char_traits<char>::length(buf);
            buf[start++] = uppercase ? 'E' : 'e';
            buf[start++] = sci.exponent < 0 ? '-' : '+';
            if(sci.exponent < 0) sci.exponent *= -1;
            return integer_to_string(buf, sci.exponent, 10, start, uppercase, 2);
        }

        char *decimal_to_string_hexfloat(char *buf, long double number, int precision, size_t start = 0, bool uppercase = false)
        {
            scientific sci = number_to_scientific(number, 16, 2);
            decimal_to_string_fixed(buf, sci.number, precision, start, 16, uppercase);
            start = char_traits<char>::length(buf);
            buf[start++] = uppercase ? 'P' : 'p';
            buf[start++] = sci.exponent < 0 ? '-' : '+';
            if(sci.exponent < 0) sci.exponent *= -1;
            return integer_to_string(buf, sci.exponent, 10, start, uppercase);
        }

        char *decimal_to_string_default(char *buf, long double number, int precision, bool showpoint, size_t start = 0, bool uppercase = false)
        {
            // I hate myself
            const long ten_to_five = 10 * 10 * 10 * 10 * 10;
            const long double ten_to_minus_five = 1. / ten_to_five;
            if (number > ten_to_five || number < ten_to_minus_five)
            {
                decimal_to_string_scientific(buf, number, (showpoint ? precision : 0) - 1, start, uppercase, showpoint);
            }
            else
            {
                decimal_to_string_fixed(buf, number, (showpoint ? precision : 0) - 1, start, 10, uppercase, showpoint);
            }
            return buf;
        }
    }

    template <typename CharT, typename Traits>
    void do_put(basic_ostream<CharT, Traits> &os, CharT fill, bool value)
    {
        const ios_base::fmtflags flags = os.flags();
        if ((flags & ios_base::boolalpha) == 0)
            do_put(os, fill, long(value));
        else
        {
            char v[6];
            if (value)
                Traits::copy(v, "true", 6);
            else
                Traits::copy(v, "false", 6);
            os << v;
            if ((flags & ios_base::unitbuf) != 0)
                os << flush;
        }
    }

    template <typename CharT, typename Traits>
    void do_put(basic_ostream<CharT, Traits> &os, typename Traits::char_type fill, long value)
    {
        (void)fill;
        const typename ios_base::fmtflags flags = os.flags();
        const unsigned max_num_size = sizeof(long) * CHAR_BIT + 1 + 2;
        char n[max_num_size];
        Traits::assign(n, max_num_size, 0);
        int index = 0;
        if (value < 0)
        {
            n[index++] = '-';
            value *= -1;
        }
        else if (value > 0 && (flags & ios_base::showpos) != 0)
            n[index++] = '+';
        if ((flags & ios_base::showbase) != 0)
            switch (flags & ios_base::basefield)
            {
            case ios_base::dec:
                break;
            case ios_base::oct:
                n[index++] = '0';
                break;
            case ios_base::hex:
                n[index++] = '0';
                n[index++] = (flags & ios_base::uppercase) != 0 ? 'X' : 'x';
                break;
            default:
                n[index++] = '0';
                n[index++] = (flags & ios_base::uppercase) != 0 ? 'B' : 'b';
            }
        switch (flags & ios_base::basefield)
        {
        case ios_base::dec:
            dmath::integer_to_string(n, value, 10, index, (flags & ios_base::uppercase) != 0);
            break;
        case ios_base::oct:
            dmath::integer_to_string(n, value, 8, index, (flags & ios_base::uppercase) != 0);
            break;
        case ios_base::hex:
            dmath::integer_to_string(n, value, 16, index, (flags & ios_base::uppercase) != 0);
            break;
        default:
            dmath::integer_to_string(n, value, 2, index, (flags & ios_base::uppercase) != 0);
        }
        os << n;
        if ((flags & ios_base::unitbuf) != 0)
            os << flush;
    }

    template <typename CharT, typename Traits>
    void do_put(basic_ostream<CharT, Traits> &os, typename Traits::char_type fill, unsigned long value)
    {
        const typename ios_base::fmtflags flags = os.flags();
        const unsigned max_num_size = sizeof(long) * CHAR_BIT + 1 + 2;
        char n[max_num_size];
        Traits::assign(n, max_num_size, 0);
        int index = 0;
        if (value > 0 && (flags & ios_base::showpos) != 0)
            n[index++] = '+';
        if ((flags & ios_base::showbase) != 0)
            switch (flags & ios_base::basefield)
            {
            case ios_base::dec:
                break;
            case ios_base::oct:
                n[index++] = '0';
                break;
            case ios_base::hex:
                n[index++] = '0';
                n[index++] = (flags & ios_base::uppercase) != 0 ? 'X' : 'x';
                break;
            default:
                n[index++] = '0';
                n[index++] = (flags & ios_base::uppercase) != 0 ? 'B' : 'b';
            }
        switch (flags & ios_base::basefield)
        {
        case ios_base::dec:
            dmath::integer_to_string(n, value, 10, index, (flags & ios_base::uppercase) != 0);
            break;
        case ios_base::oct:
            dmath::integer_to_string(n, value, 8, index, (flags & ios_base::uppercase) != 0);
            break;
        case ios_base::hex:
            dmath::integer_to_string(n, value, 16, index, (flags & ios_base::uppercase) != 0);
            break;
        default:
            dmath::integer_to_string(n, value, 2, index, (flags & ios_base::uppercase) != 0);
        }
        os << n;
        if ((flags & ios_base::unitbuf) != 0)
            os << flush;
    }

    template <typename CharT, typename Traits>
    void do_put(basic_ostream<CharT, Traits> &os, typename Traits::char_type fill, double value)
    {
        (void)fill;
        const typename ios_base::fmtflags flags = os.flags();
        char n[__MAX_DOUBLE_DIGITS__];
        Traits::assign(n, __MAX_DOUBLE_DIGITS__, 0);
        int index = 0;
        if (value < 0)
        {
            n[index++] = '-';
            value *= -1;
        }
        else if (value > 0 && (flags & ios_base::showpos) != 0)
            n[index++] = '+';
        switch (flags & ios_base::floatfield)
        {
        case ios_base::floatfield:
            n[index++] = '0';
            n[index++] = (flags & ios_base::uppercase) != 0 ? 'X' : 'x';
            dmath::decimal_to_string_hexfloat(n, value, numeric_limits<double>::digits10, index, (flags & ios_base::uppercase) != 0);
            break;
        case ios_base::fixed:
            dmath::decimal_to_string_fixed(n, value, os.precision(), index);
            break;
        case ios_base::scientific:
            dmath::decimal_to_string_scientific(n, value, os.precision(), index, (flags & ios_base::uppercase) != 0);
            break;
        default:
            dmath::decimal_to_string_default(n, value, os.precision(), (flags & ios_base::showpoint) != 0, index, (flags & ios_base::uppercase) != 0);
            break;
        }
        os << n;
        if ((flags & ios_base::unitbuf) != 0)
            os << flush;
    }

    template <typename CharT, typename Traits>
    void do_put(basic_ostream<CharT, Traits> &os, typename Traits::char_type fill, long double value)
    {
        const typename ios_base::fmtflags flags = os.flags();
        char n[__MAX_DOUBLE_DIGITS__];
        Traits::assign(n, __MAX_DOUBLE_DIGITS__, 0);
        int index = 0;
        if (value < 0)
        {
            n[index++] = '-';
            value *= -1;
        }
        else if (value > 0 && (flags & ios_base::showpos) != 0)
            n[index++] = '+';
        switch (flags & ios_base::floatfield)
        {
        case ios_base::floatfield:
            n[index++] = '0';
            n[index++] = (flags & ios_base::uppercase) != 0 ? 'X' : 'x';
            dmath::decimal_to_string_hexfloat(n, value, numeric_limits<long double>::digits10, index, (flags & ios_base::uppercase) != 0);
            break;
        case ios_base::fixed:
            dmath::decimal_to_string_fixed(n, value, os.precision(), index);
            break;
        case ios_base::scientific:
            dmath::decimal_to_string_scientific(n, value, os.precision(), index, (flags & ios_base::uppercase) != 0);
            break;
        default:
            dmath::decimal_to_string_default(n, value, os.precision(), (flags & ios_base::showpoint) != 0, index, (flags & ios_base::uppercase) != 0);
            break;
        }
        os << n;
        if ((flags & ios_base::unitbuf) != 0)
            os << flush;
    }

    template <typename CharT, typename Traits>
    void do_put(basic_ostream<CharT, Traits> &os, typename Traits::char_type fill, const void *value)
    {
        const typename ios_base::fmtflags flags = os.flags();
        const unsigned max_num_size = sizeof(value) * CHAR_BIT / 4;
        char n[max_num_size + 1 + 2];
        Traits::assign(n, max_num_size + 1 + 2, 0);
        int index = 0;
        n[index++] = '0';
        n[index++] = (flags & ios_base::uppercase) != 0 ? 'X' : 'x';
        dmath::integer_to_string(n, (unsigned long)value, 16, index, (flags & ios_base::uppercase) != 0, max_num_size);
        os << n;
        if ((flags & ios_base::unitbuf) != 0)
            os << flush;
    }

    template <typename CharT, typename Traits>
    template <typename ValueT>
    basic_ostream<CharT, Traits> &basic_ostream<CharT, Traits>::_M_insert(ValueT value)
    {
        sentry cerb(*this);
        if (cerb)
            do_put(*this, this->fill(), value);
        return *this;
    }
}

// template <streamsize CAPACITY>
// ostream<CAPACITY>::ostream() : size{0} {
//     memset(buf, 0, CAPACITY);
//     memset(tbuf, 0, CAPACITY);
// }

// template <streamsize CAPACITY>
// ostream<CAPACITY>& ostream<CAPACITY>::flush() {
//     Console::puts(buf);
//     memset(buf, 0, CAPACITY);
//     size = 0;
//     return *this;
// }

// template <streamsize CAPACITY>
// ostream<CAPACITY>& ostream<CAPACITY>::operator<<(ostream<CAPACITY>& (*func)(ostream<CAPACITY>& o)) {
//     return func(*this);
// }

// template <streamsize CAPACITY>
// template <typename T>
// ostream<CAPACITY>& ostream<CAPACITY>::operator<<(const T* object) {
//     size_t length = to_string(object);
//     if(size + length > CAPACITY) {
//         flush();
//     }
//     strcat(buf + size, tbuf);
//     size += length;
//     return *this;
// }

// template <streamsize CAPACITY>
// template <typename T>
// ostream<CAPACITY>& ostream<CAPACITY>::operator<<(T object) {
//     size_t length = to_string(object);
//     if(size + length > CAPACITY) {
//         flush();
//     }
//     strcat(buf + size, tbuf);
//     size += length;
//     return *this;
// }

// template <streamsize CAPACITY>
// size_t ostream<CAPACITY>::to_string(const bool& obj, size_t start) {
//     if(obj) {
//         strcpy(tbuf + start, "true");
//     } else {
//         strcpy(tbuf + start, "false");
//     }
//     return strlen(tbuf);
// }

// template <streamsize CAPACITY>
// size_t ostream<CAPACITY>::to_string(const char& obj, size_t start) {
//     tbuf[start] = obj;
//     if(obj) tbuf[start + 1] = '\0';
//     return strlen(tbuf);
// }

// template <streamsize CAPACITY>
// size_t ostream<CAPACITY>::to_string(const short& obj, size_t start) {
//     short dup = obj;
//     if(dup < 0) {
//         tbuf[start++] = '-';
//         dup *= -1;
//     }
//     return to_string((const unsigned long)dup, start);
// }

// template <streamsize CAPACITY>
// size_t ostream<CAPACITY>::to_string(const int& obj, size_t start) {
//     int dup = obj;
//     if(dup < 0) {
//         tbuf[start++] = '-';
//         dup *= -1;
//     }
//     return to_string((const unsigned long)dup, start);
// }

// template <streamsize CAPACITY>
// size_t ostream<CAPACITY>::to_string(const long& obj, size_t start) {
//     long dup = obj;
//     if(dup < 0) {
//         tbuf[start++] = '-';
//         dup *= -1;
//     }
//     return to_string((const unsigned long)dup, start);
// }

// template <streamsize CAPACITY>
// size_t ostream<CAPACITY>::to_string(const unsigned char& obj, size_t start) {
//     return to_string((const unsigned long)obj, start);
// }

// template <streamsize CAPACITY>
// size_t ostream<CAPACITY>::to_string(const unsigned short& obj, size_t start) {
//     return to_string((const unsigned long)obj, start);
// }

// template <streamsize CAPACITY>
// size_t ostream<CAPACITY>::to_string(const unsigned int& obj, size_t start) {
//     return to_string((const unsigned long)obj, start);
// }

// template <streamsize CAPACITY>
// size_t ostream<CAPACITY>::to_string(const unsigned long& obj, size_t start) {
//     dmath::integer_to_string(tbuf, obj, 10, start);
//     return strlen(tbuf);
// }

// template <streamsize CAPACITY>
// size_t ostream<CAPACITY>::to_string(const char*& obj, size_t start) {
//     strcpy(tbuf + start, obj);
//     return strlen(tbuf);
// }

// template <streamsize CAPACITY>
// template <typename T>
// size_t ostream<CAPACITY>::to_string(const T* obj, size_t start) {
//     return to_string((const void*)obj, start);
// }

// template <streamsize CAPACITY>
// size_t ostream<CAPACITY>::to_string(const void* obj, size_t start) {
//     tbuf[start++] = '0';
//     tbuf[start++] = 'x';
//     dmath::integer_to_string(tbuf, (size_t)obj, 16, start);
//     return strlen(tbuf);
// }

#endif