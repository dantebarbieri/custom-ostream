#ifndef _CSTRING_TCC_
#define _CSTRING_TCC_

#include "string.hpp"

#define forever for (;;)

void *dvb::memcpy(void *dest, const void *src, size_t count)
{
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    if (count != 0 && d != s)
        for (size_t i = 0; i < count; ++i)
            d[i] = s[i];
    return dest;
}

void *dvb::memmove(void *dest, const void *src, size_t count)
{
    unsigned char *d = (unsigned char *)dest;
    const unsigned char *s = (const unsigned char *)src;
    if (count != 0 && d != s)
    {
        if (d < s || d >= count + s)
            memcpy(d, s, count);
        else
            for (size_t i = 1; i <= count; ++i)
                d[count - i] = s[count - i];
    }
    return dest;
}

void *dvb::memset(void *dest, int ch, size_t count)
{
    unsigned char *d = (unsigned char *)dest;
    unsigned char c = (unsigned char)ch;
    for (size_t i = 0; i < count; ++i)
        d[i] = c;
    return dest;
}

char *dvb::strcpy(char *dest, const char *src)
{
    size_t i = 0;
    while (src[i])
    {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return dest;
}

char *dvb::strncpy(char *dest, const char *src, size_t count)
{
    size_t i = 0;
    while (i < count && src[i])
    {
        dest[i] = src[i];
        ++i;
    }
    while (i < count)
        dest[i++] = '\0';
    return dest;
}

char *dvb::strcat(char *dest, const char *src)
{
    strcpy(dest + strlen(dest), src);
    return dest;
}

char *dvb::strncat(char *dest, const char *src, size_t count)
{
    strncpy(dest + strlen(dest), src, count);
    return dest;
}

dvb::size_t dvb::strlen(const char *str)
{
    size_t i = 0;
    while (str[i])
        ++i;
    return i;
}

int dvb::strcmp(const char *lhs, const char *rhs)
{
    size_t i = 0;
    int diff;
    forever
    {
        diff = (int)lhs[i] - (int)rhs[i];
        if (diff)
        {
            return diff;
        }
        if (!lhs[i++])
        {
            return 0;
        }
    }
    // Never reached, purely to please compiler
    return 0;
}

int dvb::strncmp(const char *lhs, const char *rhs, size_t count)
{

    int diff;
    for (size_t i = 0; i < count; ++i)
    {
        diff = (int)lhs[i] - (int)rhs[i];
        if (diff)
        {
            return diff;
        }
        if (!lhs[i])
        {
            return 0;
        }
    }
    // Never reached, purely to please compiler
    return 0;
}

const char *dvb::strchr(const char *str, int ch)
{
    size_t i = 0;
    while (str[i] && str[i] != ch)
        ++i;
    return str[i] ? str + i : NULL;
}

char *dvb::strchr(char *str, int ch)
{
    return (char *)strchr((const char *)str, ch);
}

const char *dvb::strrchr(const char *str, int ch)
{
    const char *location = NULL;
    for (size_t i = 0; str[i]; ++i)
        if (str[i] == ch)
            location = str + i;
    return location;
}

char *dvb::strrchr(char *str, int ch)
{
    return (char *)strrchr((const char *)str, ch);
}

const char *dvb::strstr(const char *haystack, const char *needle)
{
    size_t size_needle = strlen(needle);
    if (!size_needle)
        return haystack;
    size_t size_haystack = strlen(haystack);
    if (size_haystack < size_needle)
        return NULL;
    const size_t &diff = size_haystack - size_needle;
    for (size_t i = 0; i < diff; ++i)
        if (!strncmp(haystack + i, needle, size_needle))
            return haystack + i;
    return NULL;
}

char *dvb::strstr(char *haystack, const char *needle)
{
    return (char *)strstr((const char *)haystack, needle);
}

#endif