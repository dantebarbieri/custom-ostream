/**
 * @file char_traits.hpp
 * @author Dante Barbieri (dante@barbieri.dev)
 * @brief Analogous to the <char_traits> header
 * @version 0.1
 * @date 2021-03-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _CHAR_TRAITS_HPP_
#define _CHAR_TRAITS_HPP_

#include "postypes.hpp"
#include "../cwchar.hpp"

namespace my
{
    template <typename CharT>
    struct Char_types
    {
        typedef unsigned long int_type;
        typedef dvb::streampos pos_type;
        typedef dvb::streamoff off_type;
        typedef dvb::mbstate_t state_type;
    };

    template <typename CharT>
    struct char_traits
    {
        typedef CharT char_type;
        typedef typename Char_types<CharT>::int_type int_type;
        typedef typename Char_types<CharT>::pos_type pos_type;
        typedef typename Char_types<CharT>::state_type state_type;

        static void assign(char_type &a, const char_type &b) { a = b; }

        static bool eq(const char_type &a, const char_type &b) { return a == b; }

        static bool lt(const char_type &a, const char_type &b) { return a < b; }

        static int compare(const char_type *s1, const char_type *s2, dvb::size_t count);

        static dvb::size_t length(const char_type *s);

        static const char_type *find(const char_type *p, dvb::size_t count, const char_type &ch);

        static char_type *move(char_type *dest, const char_type *src, dvb::size_t count);

        static char_type *copy(char_type *dest, const char_type *src, dvb::size_t count);

        static char_type *assign(char_type *p, dvb::size_t count, char_type a);

        static char_type to_char_type(const int_type &c) { return static_cast<char_type>(c); }

        static int_type to_int_type(const char_type &c) { return static_cast<int_type>(c); }

        static bool eq_int_type(const int_type &c1, const int_type &c2) { return c1 == c2; }

        static int_type eof() { return static_cast<int_type>(-1); }

        static int_type not_eof(const int_type &c) { return !eq_int_type(c, eof()) ? c : to_int_type(char_type()); }
    };

    template <typename CharT>
    int char_traits<CharT>::compare(const char_type *s1, const char_type *s2, dvb::size_t count)
    {
        for (dvb::size_t i = 0; i < count; ++i)
            if (lt(s1[i], s2[i]))
                return -1;
            else if (lt(s2[i], s1[i]))
                return 1;
        return 0;
    }

    template <typename CharT>
    dvb::size_t char_traits<CharT>::length(const char_type *p)
    {
        dvb::size_t i = 0;
        while (!eq(p[i], char_type()))
            ++i;
        return i;
    }

    template <typename CharT>
    const typename char_traits<CharT>::char_type *char_traits<CharT>::find(const char_type *s, dvb::size_t count, const char_type &ch)
    {
        for (dvb::size_t i = 0; i < count; ++i)
            if (eq(s[i], ch))
                return s + i;
        return 0;
    }

    template <typename CharT>
    typename char_traits<CharT>::char_type *
    char_traits<CharT>::move(char_type *dest, const char_type *src, dvb::size_t count)
    {
        if (count != 0 && dest != src)
        {
            if (dest < src)
                for (dvb::size_t i = 1; i <= count; ++i)
                    assign(dest[count - i], src[count - i]);
            else
                for (dvb::size_t i = 0; i < count; ++i)
                    assign(dest[i], src[i]);
        }
        return dest;
    }

    template <typename CharT>
    typename char_traits<CharT>::char_type *
    char_traits<CharT>::copy(char_type *dest, const char_type *src, dvb::size_t count)
    {
        if (count != 0 && dest != src)
            for (dvb::size_t i = 0; i < count; ++i)
                assign(dest[i], src[i]);
        return dest;
    }

    template <typename CharT>
    typename char_traits<CharT>::char_type *
    char_traits<CharT>::assign(char_type *p, dvb::size_t count, char_type a)
    {
        if (count != 0)
            for (dvb::size_t i = 0; i < count; ++i)
                assign(p[i], a);
        return p;
    }
}

namespace dvb
{
    template <typename CharT>
    struct char_traits : public my::char_traits<CharT>
    {
    };

    template <>
    struct char_traits<char>
    {
        typedef char char_type;
        typedef int int_type;
        typedef streampos pos_type;
        typedef streamoff off_type;
        typedef mbstate_t state_type;

        static void assign(char_type &a, const char_type &b) { a = b; }

        static bool eq(const char_type &a, const char_type &b) { return a == b; }

        static bool lt(const char_type &c1, const char_type &c2) { return static_cast<unsigned char>(c1) < static_cast<unsigned char>(c2); }

        static int compare(const char_type *s1, const char_type *s2, size_t count)
        {
            for (dvb::size_t i = 0; i < count; ++i)
                if (lt(s1[i], s2[i]))
                    return -1;
                else if (lt(s2[i], s1[i]))
                    return 1;
            return 0;
        }

        static size_t length(const char_type *s)
        {
            dvb::size_t i = 0;
            while (!eq(s[i], char_type()))
                ++i;
            return i;
        }

        static const char_type *find(const char_type *s, size_t count, const char_type &ch)
        {
            for (dvb::size_t i = 0; i < count; ++i)
                if (eq(s[i], ch))
                    return s + i;
            return 0;
        }

        static char_type *move(char_type *dest, const char_type *src, size_t count)
        {
            if (count != 0 && dest != src)
            {
                if (dest < src)
                    for (size_t i = 1; i <= count; ++i)
                        assign(dest[count - i], src[count - i]);
                else
                    for (size_t i = 0; i < count; ++i)
                        assign(dest[i], src[i]);
            }
            return dest;
        }

        static char_type *copy(char_type *dest, const char_type *src, size_t count)
        {
            if (count != 0 && dest != src)
                for (size_t i = 0; i < count; ++i)
                    assign(dest[i], src[i]);
            return dest;
        }

        static char_type *assign(char_type *s, size_t count, char_type a)
        {
            if (count != 0)
                for (size_t i = 0; i < count; ++i)
                    assign(s[i], a);
            return s;
        }

        static char_type to_char_type(const int_type &c) { return static_cast<char_type>(c); }

        static int_type to_int_type(const char_type &c) { return static_cast<int_type>(static_cast<unsigned char>(c)); }

        static bool eq_int_type(const int_type &c1, const int_type &c2) { return c1 == c2; }

        static int_type eof() { return static_cast<int_type>(-1); }

        static int_type not_eof(const int_type &c) { return c == eof() ? 0 : c; }
    };
}

#endif