/**
 * @file limits.tcc
 * @author Dante Barbieri (dante@barbieri.dev)
 * @brief Implementations of the limits.hpp file
 * @version 0.1
 * @date 2021-03-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _LIMITS_TCC_
#define _LIMITS_TCC_

#include "limits.hpp"

// Since a numeric_limits<> is a bit tricky to get right, we rely on
// an interface composed of macros which should be defined in config/os
// or config/cpu when they differ from the generic (read arbitrary)
// definitions given here.
//

// These values can be overridden in the target configuration file.
// The default values are appropriate for many 32-bit targets.

// float
//

// Default values.  Should be overridden in configuration files if necessary.

// double

// Default values.  Should be overridden in configuration files if necessary.

// long double

// Default values.  Should be overridden in configuration files if necessary.

// You should not need to define any macros below this point.

#define __glibcxx_signed_b(T, B) ((T)(-1) < 0)

#define __glibcxx_min_b(T, B) \
    (__glibcxx_signed_b(T, B) ? -__glibcxx_max_b(T, B) - 1 : (T)0)

#define __glibcxx_max_b(T, B) \
    (__glibcxx_signed_b(T, B) ? (((((T)1 << (__glibcxx_digits_b(T, B) - 1)) - 1) << 1) + 1) : ~(T)0)

#define __glibcxx_digits_b(T, B) \
    (B - __glibcxx_signed_b(T, B))

// The fraction 643/2136 approximates log10(2) to 7 significant digits.
#define __glibcxx_digits10_b(T, B) \
    (__glibcxx_digits_b(T, B) * 643L / 2136)

#define __glibcxx_signed(T) \
    __glibcxx_signed_b(T, sizeof(T) * __CHAR_BIT__)
#define __glibcxx_min(T) \
    __glibcxx_min_b(T, sizeof(T) * __CHAR_BIT__)
#define __glibcxx_max(T) \
    __glibcxx_max_b(T, sizeof(T) * __CHAR_BIT__)
#define __glibcxx_digits(T) \
    __glibcxx_digits_b(T, sizeof(T) * __CHAR_BIT__)
#define __glibcxx_digits10(T) \
    __glibcxx_digits10_b(T, sizeof(T) * __CHAR_BIT__)

#define __glibcxx_max_digits10(T) \
    (2 + (T)*643L / 2136)

namespace dvb
{
    /**
   *  @brief Part of std::numeric_limits.
   *
   *  The @c static @c const members are usable as integral constant
   *  expressions.
   *
   *  @note This is a separate class for purposes of efficiency; you
   *        should only access these members as part of an instantiation
   *        of the std::numeric_limits class.
  */

    // _GLIBCXX_RESOLVE_LIB_DEFECTS
    // 559. numeric_limits<const T>

    template <typename _Tp>
    struct numeric_limits<const _Tp>
        : public numeric_limits<_Tp>
    {
    };

    template <typename _Tp>
    struct numeric_limits<volatile _Tp>
        : public numeric_limits<_Tp>
    {
    };

    template <typename _Tp>
    struct numeric_limits<const volatile _Tp>
        : public numeric_limits<_Tp>
    {
    };

    // Now there follow 16 explicit specializations.  Yes, 16.  Make sure
    // you get the count right. (18 in C++11 mode, with char16_t and char32_t.)
    // (+1 if char8_t is enabled.)

    // _GLIBCXX_RESOLVE_LIB_DEFECTS
    // 184. numeric_limits<bool> wording problems

    /// numeric_limits<bool> specialization.
    template <>
    struct numeric_limits<bool>
    {
        static const bool is_specialized = true;

        static bool
        min() { return false; }

        static bool
        max() { return true; }

        static bool
        lowest()
        {
            return min();
        }

        static const int digits = 1;
        static const int digits10 = 0;
        static const int max_digits10 = 0;
        static const bool is_signed = false;
        static const bool is_integer = true;
        static const bool is_exact = true;
        static const int radix = 2;

        static bool
        epsilon() { return false; }

        static bool
        round_error() { return false; }

        static const int min_exponent = 0;
        static const int min_exponent10 = 0;
        static const int max_exponent = 0;
        static const int max_exponent10 = 0;

        static const bool has_infinity = false;
        static const bool has_quiet_NaN = false;
        static const bool has_signaling_NaN = false;
        static const float_denorm_style has_denorm = denorm_absent;
        static const bool has_denorm_loss = false;

        static bool
        infinity() { return false; }

        static bool
        quiet_NaN() { return false; }

        static bool
        signaling_NaN() { return false; }

        static bool
        denorm_min() { return false; }

        static const bool is_iec559 = false;
        static const bool is_bounded = true;
        static const bool is_modulo = false;

        // It is not clear what it means for a boolean type to trap.
        // This is a DR on the LWG issue list.  Here, I use integer
        // promotion semantics.
        static const bool traps = true;
        static const bool tinyness_before = false;
        static const float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<char> specialization.
    template <>
    struct numeric_limits<char>
    {
        static const bool is_specialized = true;

        static char
        min() { return __glibcxx_min(char); }

        static char
        max() { return __glibcxx_max(char); }

        static char
        lowest()
        {
            return min();
        }

        static const int digits = __glibcxx_digits(char);
        static const int digits10 = __glibcxx_digits10(char);
        static const int max_digits10 = 0;
        static const bool is_signed = __glibcxx_signed(char);
        static const bool is_integer = true;
        static const bool is_exact = true;
        static const int radix = 2;

        static char
        epsilon() { return 0; }

        static char
        round_error() { return 0; }

        static const int min_exponent = 0;
        static const int min_exponent10 = 0;
        static const int max_exponent = 0;
        static const int max_exponent10 = 0;

        static const bool has_infinity = false;
        static const bool has_quiet_NaN = false;
        static const bool has_signaling_NaN = false;
        static const float_denorm_style has_denorm = denorm_absent;
        static const bool has_denorm_loss = false;

        static char infinity() { return char(); }

        static char
        quiet_NaN() { return char(); }

        static char
        signaling_NaN() { return char(); }

        static char
        denorm_min() { return static_cast<char>(0); }

        static const bool is_iec559 = false;
        static const bool is_bounded = true;
        static const bool is_modulo = !is_signed;

        static const bool traps = true;
        static const bool tinyness_before = false;
        static const float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<signed char> specialization.
    template <>
    struct numeric_limits<signed char>
    {
        static const bool is_specialized = true;

        static signed char
        min() { return -__SCHAR_MAX__ - 1; }

        static signed char
        max() { return __SCHAR_MAX__; }

        static signed char
        lowest()
        {
            return min();
        }

        static const int digits = __glibcxx_digits(signed char);
        static const int digits10 = __glibcxx_digits10(signed char);
        static const int max_digits10 = 0;
        static const bool is_signed = true;
        static const bool is_integer = true;
        static const bool is_exact = true;
        static const int radix = 2;

        static signed char
        epsilon() { return 0; }

        static signed char
        round_error() { return 0; }

        static const int min_exponent = 0;
        static const int min_exponent10 = 0;
        static const int max_exponent = 0;
        static const int max_exponent10 = 0;

        static const bool has_infinity = false;
        static const bool has_quiet_NaN = false;
        static const bool has_signaling_NaN = false;
        static const float_denorm_style has_denorm = denorm_absent;
        static const bool has_denorm_loss = false;

        static signed char
        infinity() { return static_cast<signed char>(0); }

        static signed char
        quiet_NaN() { return static_cast<signed char>(0); }

        static signed char
        signaling_NaN()
        {
            return static_cast<signed char>(0);
        }

        static signed char
        denorm_min()
        {
            return static_cast<signed char>(0);
        }

        static const bool is_iec559 = false;
        static const bool is_bounded = true;
        static const bool is_modulo = false;

        static const bool traps = true;
        static const bool tinyness_before = false;
        static const float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<unsigned char> specialization.
    template <>
    struct numeric_limits<unsigned char>
    {
        static const bool is_specialized = true;

        static unsigned char
        min() { return 0; }

        static unsigned char
        max() { return __SCHAR_MAX__ * 2U + 1; }

        static unsigned char
        lowest()
        {
            return min();
        }

        static const int digits = __glibcxx_digits(unsigned char);
        static const int digits10 = __glibcxx_digits10(unsigned char);
        static const int max_digits10 = 0;
        static const bool is_signed = false;
        static const bool is_integer = true;
        static const bool is_exact = true;
        static const int radix = 2;

        static unsigned char
        epsilon() { return 0; }

        static unsigned char
        round_error() { return 0; }

        static const int min_exponent = 0;
        static const int min_exponent10 = 0;
        static const int max_exponent = 0;
        static const int max_exponent10 = 0;

        static const bool has_infinity = false;
        static const bool has_quiet_NaN = false;
        static const bool has_signaling_NaN = false;
        static const float_denorm_style has_denorm = denorm_absent;
        static const bool has_denorm_loss = false;

        static unsigned char
        infinity()
        {
            return static_cast<unsigned char>(0);
        }

        static unsigned char
        quiet_NaN()
        {
            return static_cast<unsigned char>(0);
        }

        static unsigned char
        signaling_NaN()
        {
            return static_cast<unsigned char>(0);
        }

        static unsigned char
        denorm_min()
        {
            return static_cast<unsigned char>(0);
        }

        static const bool is_iec559 = false;
        static const bool is_bounded = true;
        static const bool is_modulo = true;

        static const bool traps = true;
        static const bool tinyness_before = false;
        static const float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<wchar_t> specialization.
    template <>
    struct numeric_limits<wchar_t>
    {
        static const bool is_specialized = true;

        static wchar_t
        min() { return __glibcxx_min(wchar_t); }

        static wchar_t
        max() { return __glibcxx_max(wchar_t); }

        static wchar_t
        lowest()
        {
            return min();
        }

        static const int digits = __glibcxx_digits(wchar_t);
        static const int digits10 = __glibcxx_digits10(wchar_t);
        static const int max_digits10 = 0;
        static const bool is_signed = __glibcxx_signed(wchar_t);
        static const bool is_integer = true;
        static const bool is_exact = true;
        static const int radix = 2;

        static wchar_t
        epsilon() { return 0; }

        static wchar_t
        round_error() { return 0; }

        static const int min_exponent = 0;
        static const int min_exponent10 = 0;
        static const int max_exponent = 0;
        static const int max_exponent10 = 0;

        static const bool has_infinity = false;
        static const bool has_quiet_NaN = false;
        static const bool has_signaling_NaN = false;
        static const float_denorm_style has_denorm = denorm_absent;
        static const bool has_denorm_loss = false;

        static wchar_t
        infinity() { return wchar_t(); }

        static wchar_t
        quiet_NaN() { return wchar_t(); }

        static wchar_t
        signaling_NaN() { return wchar_t(); }

        static wchar_t
        denorm_min() { return wchar_t(); }

        static const bool is_iec559 = false;
        static const bool is_bounded = true;
        static const bool is_modulo = !is_signed;

        static const bool traps = true;
        static const bool tinyness_before = false;
        static const float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<short> specialization.
    template <>
    struct numeric_limits<short>
    {
        static const bool is_specialized = true;

        static short
        min() { return -__SHRT_MAX__ - 1; }

        static short
        max() { return __SHRT_MAX__; }

        static short
        lowest()
        {
            return min();
        }

        static const int digits = __glibcxx_digits(short);
        static const int digits10 = __glibcxx_digits10(short);
        static const int max_digits10 = 0;
        static const bool is_signed = true;
        static const bool is_integer = true;
        static const bool is_exact = true;
        static const int radix = 2;

        static short
        epsilon() { return 0; }

        static short
        round_error() { return 0; }

        static const int min_exponent = 0;
        static const int min_exponent10 = 0;
        static const int max_exponent = 0;
        static const int max_exponent10 = 0;

        static const bool has_infinity = false;
        static const bool has_quiet_NaN = false;
        static const bool has_signaling_NaN = false;
        static const float_denorm_style has_denorm = denorm_absent;
        static const bool has_denorm_loss = false;

        static short
        infinity() { return short(); }

        static short
        quiet_NaN() { return short(); }

        static short
        signaling_NaN() { return short(); }

        static short
        denorm_min() { return short(); }

        static const bool is_iec559 = false;
        static const bool is_bounded = true;
        static const bool is_modulo = false;

        static const bool traps = true;
        static const bool tinyness_before = false;
        static const float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<unsigned short> specialization.
    template <>
    struct numeric_limits<unsigned short>
    {
        static const bool is_specialized = true;

        static unsigned short
        min() { return 0; }

        static unsigned short
        max() { return __SHRT_MAX__ * 2U + 1; }

        static unsigned short
        lowest()
        {
            return min();
        }

        static const int digits = __glibcxx_digits(unsigned short);
        static const int digits10 = __glibcxx_digits10(unsigned short);
        static const int max_digits10 = 0;
        static const bool is_signed = false;
        static const bool is_integer = true;
        static const bool is_exact = true;
        static const int radix = 2;

        static unsigned short
        epsilon() { return 0; }

        static unsigned short
        round_error() { return 0; }

        static const int min_exponent = 0;
        static const int min_exponent10 = 0;
        static const int max_exponent = 0;
        static const int max_exponent10 = 0;

        static const bool has_infinity = false;
        static const bool has_quiet_NaN = false;
        static const bool has_signaling_NaN = false;
        static const float_denorm_style has_denorm = denorm_absent;
        static const bool has_denorm_loss = false;

        static unsigned short
        infinity()
        {
            return static_cast<unsigned short>(0);
        }

        static unsigned short
        quiet_NaN()
        {
            return static_cast<unsigned short>(0);
        }

        static unsigned short
        signaling_NaN()
        {
            return static_cast<unsigned short>(0);
        }

        static unsigned short
        denorm_min()
        {
            return static_cast<unsigned short>(0);
        }

        static const bool is_iec559 = false;
        static const bool is_bounded = true;
        static const bool is_modulo = true;

        static const bool traps = true;
        static const bool tinyness_before = false;
        static const float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<int> specialization.
    template <>
    struct numeric_limits<int>
    {
        static const bool is_specialized = true;

        static int
        min() { return -__INT_MAX__ - 1; }

        static int
        max() { return __INT_MAX__; }

        static int
        lowest()
        {
            return min();
        }

        static const int digits = __glibcxx_digits(int);
        static const int digits10 = __glibcxx_digits10(int);
        static const int max_digits10 = 0;
        static const bool is_signed = true;
        static const bool is_integer = true;
        static const bool is_exact = true;
        static const int radix = 2;

        static int
        epsilon() { return 0; }

        static int
        round_error() { return 0; }

        static const int min_exponent = 0;
        static const int min_exponent10 = 0;
        static const int max_exponent = 0;
        static const int max_exponent10 = 0;

        static const bool has_infinity = false;
        static const bool has_quiet_NaN = false;
        static const bool has_signaling_NaN = false;
        static const float_denorm_style has_denorm = denorm_absent;
        static const bool has_denorm_loss = false;

        static int
        infinity() { return static_cast<int>(0); }

        static int
        quiet_NaN() { return static_cast<int>(0); }

        static int
        signaling_NaN() { return static_cast<int>(0); }

        static int
        denorm_min() { return static_cast<int>(0); }

        static const bool is_iec559 = false;
        static const bool is_bounded = true;
        static const bool is_modulo = false;

        static const bool traps = true;
        static const bool tinyness_before = false;
        static const float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<unsigned int> specialization.
    template <>
    struct numeric_limits<unsigned int>
    {
        static const bool is_specialized = true;

        static unsigned int
        min() { return 0; }

        static unsigned int
        max() { return __INT_MAX__ * 2U + 1; }

        static unsigned int
        lowest()
        {
            return min();
        }

        static const int digits = __glibcxx_digits(unsigned int);
        static const int digits10 = __glibcxx_digits10(unsigned int);
        static const int max_digits10 = 0;
        static const bool is_signed = false;
        static const bool is_integer = true;
        static const bool is_exact = true;
        static const int radix = 2;

        static unsigned int
        epsilon() { return 0; }

        static unsigned int
        round_error() { return 0; }

        static const int min_exponent = 0;
        static const int min_exponent10 = 0;
        static const int max_exponent = 0;
        static const int max_exponent10 = 0;

        static const bool has_infinity = false;
        static const bool has_quiet_NaN = false;
        static const bool has_signaling_NaN = false;
        static const float_denorm_style has_denorm = denorm_absent;
        static const bool has_denorm_loss = false;

        static unsigned int
        infinity() { return static_cast<unsigned int>(0); }

        static unsigned int
        quiet_NaN()
        {
            return static_cast<unsigned int>(0);
        }

        static unsigned int
        signaling_NaN()
        {
            return static_cast<unsigned int>(0);
        }

        static unsigned int
        denorm_min()
        {
            return static_cast<unsigned int>(0);
        }

        static const bool is_iec559 = false;
        static const bool is_bounded = true;
        static const bool is_modulo = true;

        static const bool traps = true;
        static const bool tinyness_before = false;
        static const float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<long> specialization.
    template <>
    struct numeric_limits<long>
    {
        static const bool is_specialized = true;

        static long
        min() { return -__LONG_MAX__ - 1; }

        static long
        max() { return __LONG_MAX__; }

        static long
        lowest()
        {
            return min();
        }

        static const int digits = __glibcxx_digits(long);
        static const int digits10 = __glibcxx_digits10(long);
        static const int max_digits10 = 0;
        static const bool is_signed = true;
        static const bool is_integer = true;
        static const bool is_exact = true;
        static const int radix = 2;

        static long
        epsilon() { return 0; }

        static long
        round_error() { return 0; }

        static const int min_exponent = 0;
        static const int min_exponent10 = 0;
        static const int max_exponent = 0;
        static const int max_exponent10 = 0;

        static const bool has_infinity = false;
        static const bool has_quiet_NaN = false;
        static const bool has_signaling_NaN = false;
        static const float_denorm_style has_denorm = denorm_absent;
        static const bool has_denorm_loss = false;

        static long
        infinity() { return static_cast<long>(0); }

        static long
        quiet_NaN() { return static_cast<long>(0); }

        static long
        signaling_NaN() { return static_cast<long>(0); }

        static long
        denorm_min() { return static_cast<long>(0); }

        static const bool is_iec559 = false;
        static const bool is_bounded = true;
        static const bool is_modulo = false;

        static const bool traps = true;
        static const bool tinyness_before = false;
        static const float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<unsigned long> specialization.
    template <>
    struct numeric_limits<unsigned long>
    {
        static const bool is_specialized = true;

        static unsigned long
        min() { return 0; }

        static unsigned long
        max() { return __LONG_MAX__ * 2UL + 1; }

        static unsigned long
        lowest()
        {
            return min();
        }

        static const int digits = __glibcxx_digits(unsigned long);
        static const int digits10 = __glibcxx_digits10(unsigned long);
        static const int max_digits10 = 0;
        static const bool is_signed = false;
        static const bool is_integer = true;
        static const bool is_exact = true;
        static const int radix = 2;

        static unsigned long
        epsilon() { return 0; }

        static unsigned long
        round_error() { return 0; }

        static const int min_exponent = 0;
        static const int min_exponent10 = 0;
        static const int max_exponent = 0;
        static const int max_exponent10 = 0;

        static const bool has_infinity = false;
        static const bool has_quiet_NaN = false;
        static const bool has_signaling_NaN = false;
        static const float_denorm_style has_denorm = denorm_absent;
        static const bool has_denorm_loss = false;

        static unsigned long
        infinity()
        {
            return static_cast<unsigned long>(0);
        }

        static unsigned long
        quiet_NaN()
        {
            return static_cast<unsigned long>(0);
        }

        static unsigned long
        signaling_NaN()
        {
            return static_cast<unsigned long>(0);
        }

        static unsigned long
        denorm_min()
        {
            return static_cast<unsigned long>(0);
        }

        static const bool is_iec559 = false;
        static const bool is_bounded = true;
        static const bool is_modulo = true;

        static const bool traps = true;
        static const bool tinyness_before = false;
        static const float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<float> specialization.
    template <>
    struct numeric_limits<float>
    {
        static const bool is_specialized = true;

        static float
        min() { return __FLT_MIN__; }

        static float
        max() { return __FLT_MAX__; }

        static float
        lowest()
        {
            return -__FLT_MAX__;
        }

        static const int digits = __FLT_MANT_DIG__;
        static const int digits10 = __FLT_DIG__;
        static const int max_digits10 = __glibcxx_max_digits10(__FLT_MANT_DIG__);
        static const bool is_signed = true;
        static const bool is_integer = false;
        static const bool is_exact = false;
        static const int radix = __FLT_RADIX__;

        static float
        epsilon() { return __FLT_EPSILON__; }

        static float
        round_error() { return 0.5F; }

        static const int min_exponent = __FLT_MIN_EXP__;
        static const int min_exponent10 = __FLT_MIN_10_EXP__;
        static const int max_exponent = __FLT_MAX_EXP__;
        static const int max_exponent10 = __FLT_MAX_10_EXP__;

        static const bool has_infinity = __FLT_HAS_INFINITY__;
        static const bool has_quiet_NaN = __FLT_HAS_QUIET_NAN__;
        static const bool has_signaling_NaN = has_quiet_NaN;
        static const float_denorm_style has_denorm = bool(__FLT_HAS_DENORM__) ? denorm_present : denorm_absent;
        static const bool has_denorm_loss = false;

        static float
        infinity() { return __builtin_huge_valf(); }

        static float
        quiet_NaN() { return __builtin_nanf(""); }

        static float
        signaling_NaN() { return __builtin_nansf(""); }

        static float
        denorm_min() { return __FLT_DENORM_MIN__; }

        static const bool is_iec559 = has_infinity && has_quiet_NaN && has_denorm == denorm_present;
        static const bool is_bounded = true;
        static const bool is_modulo = false;

        static const bool traps = false;
        static const bool tinyness_before = false;
        static const float_round_style round_style = round_to_nearest;
    };

    /// numeric_limits<double> specialization.
    template <>
    struct numeric_limits<double>
    {
        static const bool is_specialized = true;

        static double
        min() { return __DBL_MIN__; }

        static double
        max() { return __DBL_MAX__; }

        static double
        lowest()
        {
            return -__DBL_MAX__;
        }

        static const int digits = __DBL_MANT_DIG__;
        static const int digits10 = __DBL_DIG__;
        static const int max_digits10 = __glibcxx_max_digits10(__DBL_MANT_DIG__);
        static const bool is_signed = true;
        static const bool is_integer = false;
        static const bool is_exact = false;
        static const int radix = __FLT_RADIX__;

        static double
        epsilon() { return __DBL_EPSILON__; }

        static double
        round_error() { return 0.5; }

        static const int min_exponent = __DBL_MIN_EXP__;
        static const int min_exponent10 = __DBL_MIN_10_EXP__;
        static const int max_exponent = __DBL_MAX_EXP__;
        static const int max_exponent10 = __DBL_MAX_10_EXP__;

        static const bool has_infinity = __DBL_HAS_INFINITY__;
        static const bool has_quiet_NaN = __DBL_HAS_QUIET_NAN__;
        static const bool has_signaling_NaN = has_quiet_NaN;
        static const float_denorm_style has_denorm = bool(__DBL_HAS_DENORM__) ? denorm_present : denorm_absent;
        static const bool has_denorm_loss = false;

        static double
        infinity() { return __builtin_huge_val(); }

        static double
        quiet_NaN() { return __builtin_nan(""); }

        static double
        signaling_NaN() { return __builtin_nans(""); }

        static double
        denorm_min() { return __DBL_DENORM_MIN__; }

        static const bool is_iec559 = has_infinity && has_quiet_NaN && has_denorm == denorm_present;
        static const bool is_bounded = true;
        static const bool is_modulo = false;

        static const bool traps = false;
        static const bool tinyness_before = false;
        static const float_round_style round_style = round_to_nearest;
    };

    /// numeric_limits<long double> specialization.
    template <>
    struct numeric_limits<long double>
    {
        static const bool is_specialized = true;

        static long double
        min() { return __LDBL_MIN__; }

        static long double
        max() { return __LDBL_MAX__; }

        static long double
        lowest()
        {
            return -__LDBL_MAX__;
        }

        static const int digits = __LDBL_MANT_DIG__;
        static const int digits10 = __LDBL_DIG__;
        static const int max_digits10 = __glibcxx_max_digits10(__LDBL_MANT_DIG__);
        static const bool is_signed = true;
        static const bool is_integer = false;
        static const bool is_exact = false;
        static const int radix = __FLT_RADIX__;

        static long double
        epsilon() { return __LDBL_EPSILON__; }

        static long double
        round_error() { return 0.5L; }

        static const int min_exponent = __LDBL_MIN_EXP__;
        static const int min_exponent10 = __LDBL_MIN_10_EXP__;
        static const int max_exponent = __LDBL_MAX_EXP__;
        static const int max_exponent10 = __LDBL_MAX_10_EXP__;

        static const bool has_infinity = __LDBL_HAS_INFINITY__;
        static const bool has_quiet_NaN = __LDBL_HAS_QUIET_NAN__;
        static const bool has_signaling_NaN = has_quiet_NaN;
        static const float_denorm_style has_denorm = bool(__LDBL_HAS_DENORM__) ? denorm_present : denorm_absent;
        static const bool has_denorm_loss = false;

        static long double
        infinity() { return __builtin_huge_vall(); }

        static long double
        quiet_NaN() { return __builtin_nanl(""); }

        static long double
        signaling_NaN() { return __builtin_nansl(""); }

        static long double
        denorm_min() { return __LDBL_DENORM_MIN__; }

        static const bool is_iec559 = has_infinity && has_quiet_NaN && has_denorm == denorm_present;
        static const bool is_bounded = true;
        static const bool is_modulo = false;

        static const bool traps = false;
        static const bool tinyness_before =
            false;
        static const float_round_style round_style =
            round_to_nearest;
    };

} // namespace

#endif