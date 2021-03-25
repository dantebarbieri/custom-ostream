#ifndef _LIMITS_TCC_
#define _LIMITS_TCC_

#include "limits.hpp"
#include "stddef.hpp"

// Since a numeric_limits<> is a bit tricky to get right, we rely on
// an interface composed of macros which should be defined in config/os
// or config/cpu when they differ from the generic (read arbitrary)
// definitions given here.
//

// These values can be overridden in the target configuration file.
// The default values are appropriate for many 32-bit targets.

// GCC only intrinsically supports modulo integral types.  The only remaining
// integral exceptional values is division by zero.  Only targets that do not
// signal division by zero in some "hard to ignore" way should use false.
#ifndef __glibcxx_integral_traps
#define __glibcxx_integral_traps true
#endif

// float
//

// Default values.  Should be overridden in configuration files if necessary.

#ifndef __glibcxx_float_has_denorm_loss
#define __glibcxx_float_has_denorm_loss false
#endif
#ifndef __glibcxx_float_traps
#define __glibcxx_float_traps false
#endif
#ifndef __glibcxx_float_tinyness_before
#define __glibcxx_float_tinyness_before false
#endif

// double

// Default values.  Should be overridden in configuration files if necessary.

#ifndef __glibcxx_double_has_denorm_loss
#define __glibcxx_double_has_denorm_loss false
#endif
#ifndef __glibcxx_double_traps
#define __glibcxx_double_traps false
#endif
#ifndef __glibcxx_double_tinyness_before
#define __glibcxx_double_tinyness_before false
#endif

// long double

// Default values.  Should be overridden in configuration files if necessary.

#ifndef __glibcxx_long_double_has_denorm_loss
#define __glibcxx_long_double_has_denorm_loss false
#endif
#ifndef __glibcxx_long_double_traps
#define __glibcxx_long_double_traps false
#endif
#ifndef __glibcxx_long_double_tinyness_before
#define __glibcxx_long_double_tinyness_before false
#endif

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
    struct __numeric_limits_base
    {
        /** This will be true for all fundamental types (which have
	specializations), and false for everything else.  */
        static _GLIBCXX_USE_CONSTEXPR bool is_specialized = false;

        /** The number of @c radix digits that be represented without change:  for
	integer types, the number of non-sign bits in the mantissa; for
	floating types, the number of @c radix digits in the mantissa.  */
        static _GLIBCXX_USE_CONSTEXPR int digits = 0;

        /** The number of base 10 digits that can be represented without change. */
        static _GLIBCXX_USE_CONSTEXPR int digits10 = 0;

#if __cplusplus >= 201103L
        /** The number of base 10 digits required to ensure that values which
	differ are always differentiated.  */
        static constexpr int max_digits10 = 0;
#endif

        /** True if the type is signed.  */
        static _GLIBCXX_USE_CONSTEXPR bool is_signed = false;

        /** True if the type is integer.  */
        static _GLIBCXX_USE_CONSTEXPR bool is_integer = false;

        /** True if the type uses an exact representation. All integer types are
	exact, but not all exact types are integer.  For example, rational and
	fixed-exponent representations are exact but not integer. */
        static _GLIBCXX_USE_CONSTEXPR bool is_exact = false;

        /** For integer types, specifies the base of the representation.  For
	floating types, specifies the base of the exponent representation.  */
        static _GLIBCXX_USE_CONSTEXPR int radix = 0;

        /** The minimum negative integer such that @c radix raised to the power of
	(one less than that integer) is a normalized floating point number.  */
        static _GLIBCXX_USE_CONSTEXPR int min_exponent = 0;

        /** The minimum negative integer such that 10 raised to that power is in
	the range of normalized floating point numbers.  */
        static _GLIBCXX_USE_CONSTEXPR int min_exponent10 = 0;

        /** The maximum positive integer such that @c radix raised to the power of
	(one less than that integer) is a representable finite floating point
	number.  */
        static _GLIBCXX_USE_CONSTEXPR int max_exponent = 0;

        /** The maximum positive integer such that 10 raised to that power is in
	the range of representable finite floating point numbers.  */
        static _GLIBCXX_USE_CONSTEXPR int max_exponent10 = 0;

        /** True if the type has a representation for positive infinity.  */
        static _GLIBCXX_USE_CONSTEXPR bool has_infinity = false;

        /** True if the type has a representation for a quiet (non-signaling)
	Not a Number.  */
        static _GLIBCXX_USE_CONSTEXPR bool has_quiet_NaN = false;

        /** True if the type has a representation for a signaling
	Not a Number.  */
        static _GLIBCXX_USE_CONSTEXPR bool has_signaling_NaN = false;

        /** See std::float_denorm_style for more information.  */
        static _GLIBCXX_USE_CONSTEXPR float_denorm_style has_denorm = denorm_absent;

        /** True if loss of accuracy is detected as a denormalization loss,
	rather than as an inexact result. */
        static _GLIBCXX_USE_CONSTEXPR bool has_denorm_loss = false;

        /** True if-and-only-if the type adheres to the IEC 559 standard, also
	known as IEEE 754.  (Only makes sense for floating point types.)  */
        static _GLIBCXX_USE_CONSTEXPR bool is_iec559 = false;

        /** True if the set of values representable by the type is
	finite.  All built-in types are bounded, this member would be
	false for arbitrary precision types. */
        static _GLIBCXX_USE_CONSTEXPR bool is_bounded = false;

        /** True if the type is @e modulo. A type is modulo if, for any
	operation involving +, -, or * on values of that type whose
	result would fall outside the range [min(),max()], the value
	returned differs from the true value by an integer multiple of
	max() - min() + 1. On most machines, this is false for floating
	types, true for unsigned integers, and true for signed integers.
	See PR22200 about signed integers.  */
        static _GLIBCXX_USE_CONSTEXPR bool is_modulo = false;

        /** True if trapping is implemented for this type.  */
        static _GLIBCXX_USE_CONSTEXPR bool traps = false;

        /** True if tininess is detected before rounding.  (see IEC 559)  */
        static _GLIBCXX_USE_CONSTEXPR bool tinyness_before = false;

        /** See std::float_round_style for more information.  This is only
	meaningful for floating types; integer types will all be
	round_toward_zero.  */
        static _GLIBCXX_USE_CONSTEXPR float_round_style round_style =
            round_toward_zero;
    };

    /**
   *  @brief Properties of fundamental types.
   *
   *  This class allows a program to obtain information about the
   *  representation of a fundamental type on a given platform.  For
   *  non-fundamental types, the functions will return 0 and the data
   *  members will all be @c false.
  */
    template <typename _Tp>
    struct numeric_limits : public __numeric_limits_base
    {
        /** The minimum finite value, or for floating types with
	  denormalization, the minimum positive normalized value.  */
        static _GLIBCXX_CONSTEXPR _Tp
        min() _GLIBCXX_USE_NOEXCEPT { return _Tp(); }

        /** The maximum finite value.  */
        static _GLIBCXX_CONSTEXPR _Tp
        max() _GLIBCXX_USE_NOEXCEPT { return _Tp(); }

#if __cplusplus >= 201103L
        /** A finite value x such that there is no other finite value y
       *  where y < x.  */
        static constexpr _Tp
        lowest() noexcept { return _Tp(); }
#endif

        /** The @e machine @e epsilon:  the difference between 1 and the least
	  value greater than 1 that is representable.  */
        static _GLIBCXX_CONSTEXPR _Tp
        epsilon() _GLIBCXX_USE_NOEXCEPT { return _Tp(); }

        /** The maximum rounding error measurement (see LIA-1).  */
        static _GLIBCXX_CONSTEXPR _Tp
        round_error() _GLIBCXX_USE_NOEXCEPT { return _Tp(); }

        /** The representation of positive infinity, if @c has_infinity.  */
        static _GLIBCXX_CONSTEXPR _Tp
        infinity() _GLIBCXX_USE_NOEXCEPT { return _Tp(); }

        /** The representation of a quiet Not a Number,
	  if @c has_quiet_NaN. */
        static _GLIBCXX_CONSTEXPR _Tp
        quiet_NaN() _GLIBCXX_USE_NOEXCEPT { return _Tp(); }

        /** The representation of a signaling Not a Number, if
	  @c has_signaling_NaN. */
        static _GLIBCXX_CONSTEXPR _Tp
        signaling_NaN() _GLIBCXX_USE_NOEXCEPT { return _Tp(); }

        /** The minimum positive denormalized value.  For types where
	  @c has_denorm is false, this is the minimum positive normalized
	  value.  */
        static _GLIBCXX_CONSTEXPR _Tp
        denorm_min() _GLIBCXX_USE_NOEXCEPT { return _Tp(); }
    };

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
        static _GLIBCXX_USE_CONSTEXPR bool is_specialized = true;

        static _GLIBCXX_CONSTEXPR bool
        min() _GLIBCXX_USE_NOEXCEPT { return false; }

        static _GLIBCXX_CONSTEXPR bool
        max() _GLIBCXX_USE_NOEXCEPT { return true; }

#if __cplusplus >= 201103L
        static constexpr bool
        lowest() noexcept
        {
            return min();
        }
#endif
        static _GLIBCXX_USE_CONSTEXPR int digits = 1;
        static _GLIBCXX_USE_CONSTEXPR int digits10 = 0;
#if __cplusplus >= 201103L
        static constexpr int max_digits10 = 0;
#endif
        static _GLIBCXX_USE_CONSTEXPR bool is_signed = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_integer = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_exact = true;
        static _GLIBCXX_USE_CONSTEXPR int radix = 2;

        static _GLIBCXX_CONSTEXPR bool
        epsilon() _GLIBCXX_USE_NOEXCEPT { return false; }

        static _GLIBCXX_CONSTEXPR bool
        round_error() _GLIBCXX_USE_NOEXCEPT { return false; }

        static _GLIBCXX_USE_CONSTEXPR int min_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int min_exponent10 = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent10 = 0;

        static _GLIBCXX_USE_CONSTEXPR bool has_infinity = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_quiet_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_signaling_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR float_denorm_style has_denorm = denorm_absent;
        static _GLIBCXX_USE_CONSTEXPR bool has_denorm_loss = false;

        static _GLIBCXX_CONSTEXPR bool
        infinity() _GLIBCXX_USE_NOEXCEPT { return false; }

        static _GLIBCXX_CONSTEXPR bool
        quiet_NaN() _GLIBCXX_USE_NOEXCEPT { return false; }

        static _GLIBCXX_CONSTEXPR bool
        signaling_NaN() _GLIBCXX_USE_NOEXCEPT { return false; }

        static _GLIBCXX_CONSTEXPR bool
        denorm_min() _GLIBCXX_USE_NOEXCEPT { return false; }

        static _GLIBCXX_USE_CONSTEXPR bool is_iec559 = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_bounded = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_modulo = false;

        // It is not clear what it means for a boolean type to trap.
        // This is a DR on the LWG issue list.  Here, I use integer
        // promotion semantics.
        static _GLIBCXX_USE_CONSTEXPR bool traps = __glibcxx_integral_traps;
        static _GLIBCXX_USE_CONSTEXPR bool tinyness_before = false;
        static _GLIBCXX_USE_CONSTEXPR float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<char> specialization.
    template <>
    struct numeric_limits<char>
    {
        static _GLIBCXX_USE_CONSTEXPR bool is_specialized = true;

        static _GLIBCXX_CONSTEXPR char
        min() _GLIBCXX_USE_NOEXCEPT { return __glibcxx_min(char); }

        static _GLIBCXX_CONSTEXPR char
        max() _GLIBCXX_USE_NOEXCEPT { return __glibcxx_max(char); }

#if __cplusplus >= 201103L
        static constexpr char
        lowest() noexcept
        {
            return min();
        }
#endif

        static _GLIBCXX_USE_CONSTEXPR int digits = __glibcxx_digits(char);
        static _GLIBCXX_USE_CONSTEXPR int digits10 = __glibcxx_digits10(char);
#if __cplusplus >= 201103L
        static constexpr int max_digits10 = 0;
#endif
        static _GLIBCXX_USE_CONSTEXPR bool is_signed = __glibcxx_signed(char);
        static _GLIBCXX_USE_CONSTEXPR bool is_integer = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_exact = true;
        static _GLIBCXX_USE_CONSTEXPR int radix = 2;

        static _GLIBCXX_CONSTEXPR char
        epsilon() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_CONSTEXPR char
        round_error() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_USE_CONSTEXPR int min_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int min_exponent10 = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent10 = 0;

        static _GLIBCXX_USE_CONSTEXPR bool has_infinity = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_quiet_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_signaling_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR float_denorm_style has_denorm = denorm_absent;
        static _GLIBCXX_USE_CONSTEXPR bool has_denorm_loss = false;

        static _GLIBCXX_CONSTEXPR char infinity() _GLIBCXX_USE_NOEXCEPT { return char(); }

        static _GLIBCXX_CONSTEXPR char
        quiet_NaN() _GLIBCXX_USE_NOEXCEPT { return char(); }

        static _GLIBCXX_CONSTEXPR char
        signaling_NaN() _GLIBCXX_USE_NOEXCEPT { return char(); }

        static _GLIBCXX_CONSTEXPR char
        denorm_min() _GLIBCXX_USE_NOEXCEPT { return static_cast<char>(0); }

        static _GLIBCXX_USE_CONSTEXPR bool is_iec559 = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_bounded = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_modulo = !is_signed;

        static _GLIBCXX_USE_CONSTEXPR bool traps = __glibcxx_integral_traps;
        static _GLIBCXX_USE_CONSTEXPR bool tinyness_before = false;
        static _GLIBCXX_USE_CONSTEXPR float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<signed char> specialization.
    template <>
    struct numeric_limits<signed char>
    {
        static _GLIBCXX_USE_CONSTEXPR bool is_specialized = true;

        static _GLIBCXX_CONSTEXPR signed char
        min() _GLIBCXX_USE_NOEXCEPT { return -__SCHAR_MAX__ - 1; }

        static _GLIBCXX_CONSTEXPR signed char
        max() _GLIBCXX_USE_NOEXCEPT { return __SCHAR_MAX__; }

#if __cplusplus >= 201103L
        static constexpr signed char
        lowest() noexcept
        {
            return min();
        }
#endif

        static _GLIBCXX_USE_CONSTEXPR int digits = __glibcxx_digits(signed char);
        static _GLIBCXX_USE_CONSTEXPR int digits10 = __glibcxx_digits10(signed char);
#if __cplusplus >= 201103L
        static constexpr int max_digits10 = 0;
#endif
        static _GLIBCXX_USE_CONSTEXPR bool is_signed = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_integer = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_exact = true;
        static _GLIBCXX_USE_CONSTEXPR int radix = 2;

        static _GLIBCXX_CONSTEXPR signed char
        epsilon() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_CONSTEXPR signed char
        round_error() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_USE_CONSTEXPR int min_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int min_exponent10 = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent10 = 0;

        static _GLIBCXX_USE_CONSTEXPR bool has_infinity = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_quiet_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_signaling_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR float_denorm_style has_denorm = denorm_absent;
        static _GLIBCXX_USE_CONSTEXPR bool has_denorm_loss = false;

        static _GLIBCXX_CONSTEXPR signed char
        infinity() _GLIBCXX_USE_NOEXCEPT { return static_cast<signed char>(0); }

        static _GLIBCXX_CONSTEXPR signed char
        quiet_NaN() _GLIBCXX_USE_NOEXCEPT { return static_cast<signed char>(0); }

        static _GLIBCXX_CONSTEXPR signed char
        signaling_NaN() _GLIBCXX_USE_NOEXCEPT
        {
            return static_cast<signed char>(0);
        }

        static _GLIBCXX_CONSTEXPR signed char
        denorm_min() _GLIBCXX_USE_NOEXCEPT
        {
            return static_cast<signed char>(0);
        }

        static _GLIBCXX_USE_CONSTEXPR bool is_iec559 = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_bounded = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_modulo = false;

        static _GLIBCXX_USE_CONSTEXPR bool traps = __glibcxx_integral_traps;
        static _GLIBCXX_USE_CONSTEXPR bool tinyness_before = false;
        static _GLIBCXX_USE_CONSTEXPR float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<unsigned char> specialization.
    template <>
    struct numeric_limits<unsigned char>
    {
        static _GLIBCXX_USE_CONSTEXPR bool is_specialized = true;

        static _GLIBCXX_CONSTEXPR unsigned char
        min() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_CONSTEXPR unsigned char
        max() _GLIBCXX_USE_NOEXCEPT { return __SCHAR_MAX__ * 2U + 1; }

#if __cplusplus >= 201103L
        static constexpr unsigned char
        lowest() noexcept
        {
            return min();
        }
#endif

        static _GLIBCXX_USE_CONSTEXPR int digits = __glibcxx_digits(unsigned char);
        static _GLIBCXX_USE_CONSTEXPR int digits10 = __glibcxx_digits10(unsigned char);
#if __cplusplus >= 201103L
        static constexpr int max_digits10 = 0;
#endif
        static _GLIBCXX_USE_CONSTEXPR bool is_signed = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_integer = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_exact = true;
        static _GLIBCXX_USE_CONSTEXPR int radix = 2;

        static _GLIBCXX_CONSTEXPR unsigned char
        epsilon() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_CONSTEXPR unsigned char
        round_error() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_USE_CONSTEXPR int min_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int min_exponent10 = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent10 = 0;

        static _GLIBCXX_USE_CONSTEXPR bool has_infinity = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_quiet_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_signaling_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR float_denorm_style has_denorm = denorm_absent;
        static _GLIBCXX_USE_CONSTEXPR bool has_denorm_loss = false;

        static _GLIBCXX_CONSTEXPR unsigned char
        infinity() _GLIBCXX_USE_NOEXCEPT
        {
            return static_cast<unsigned char>(0);
        }

        static _GLIBCXX_CONSTEXPR unsigned char
        quiet_NaN() _GLIBCXX_USE_NOEXCEPT
        {
            return static_cast<unsigned char>(0);
        }

        static _GLIBCXX_CONSTEXPR unsigned char
        signaling_NaN() _GLIBCXX_USE_NOEXCEPT
        {
            return static_cast<unsigned char>(0);
        }

        static _GLIBCXX_CONSTEXPR unsigned char
        denorm_min() _GLIBCXX_USE_NOEXCEPT
        {
            return static_cast<unsigned char>(0);
        }

        static _GLIBCXX_USE_CONSTEXPR bool is_iec559 = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_bounded = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_modulo = true;

        static _GLIBCXX_USE_CONSTEXPR bool traps = __glibcxx_integral_traps;
        static _GLIBCXX_USE_CONSTEXPR bool tinyness_before = false;
        static _GLIBCXX_USE_CONSTEXPR float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<wchar_t> specialization.
    template <>
    struct numeric_limits<wchar_t>
    {
        static _GLIBCXX_USE_CONSTEXPR bool is_specialized = true;

        static _GLIBCXX_CONSTEXPR wchar_t
        min() _GLIBCXX_USE_NOEXCEPT { return __glibcxx_min(wchar_t); }

        static _GLIBCXX_CONSTEXPR wchar_t
        max() _GLIBCXX_USE_NOEXCEPT { return __glibcxx_max(wchar_t); }

#if __cplusplus >= 201103L
        static constexpr wchar_t
        lowest() noexcept
        {
            return min();
        }
#endif

        static _GLIBCXX_USE_CONSTEXPR int digits = __glibcxx_digits(wchar_t);
        static _GLIBCXX_USE_CONSTEXPR int digits10 = __glibcxx_digits10(wchar_t);
#if __cplusplus >= 201103L
        static constexpr int max_digits10 = 0;
#endif
        static _GLIBCXX_USE_CONSTEXPR bool is_signed = __glibcxx_signed(wchar_t);
        static _GLIBCXX_USE_CONSTEXPR bool is_integer = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_exact = true;
        static _GLIBCXX_USE_CONSTEXPR int radix = 2;

        static _GLIBCXX_CONSTEXPR wchar_t
        epsilon() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_CONSTEXPR wchar_t
        round_error() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_USE_CONSTEXPR int min_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int min_exponent10 = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent10 = 0;

        static _GLIBCXX_USE_CONSTEXPR bool has_infinity = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_quiet_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_signaling_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR float_denorm_style has_denorm = denorm_absent;
        static _GLIBCXX_USE_CONSTEXPR bool has_denorm_loss = false;

        static _GLIBCXX_CONSTEXPR wchar_t
        infinity() _GLIBCXX_USE_NOEXCEPT { return wchar_t(); }

        static _GLIBCXX_CONSTEXPR wchar_t
        quiet_NaN() _GLIBCXX_USE_NOEXCEPT { return wchar_t(); }

        static _GLIBCXX_CONSTEXPR wchar_t
        signaling_NaN() _GLIBCXX_USE_NOEXCEPT { return wchar_t(); }

        static _GLIBCXX_CONSTEXPR wchar_t
        denorm_min() _GLIBCXX_USE_NOEXCEPT { return wchar_t(); }

        static _GLIBCXX_USE_CONSTEXPR bool is_iec559 = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_bounded = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_modulo = !is_signed;

        static _GLIBCXX_USE_CONSTEXPR bool traps = __glibcxx_integral_traps;
        static _GLIBCXX_USE_CONSTEXPR bool tinyness_before = false;
        static _GLIBCXX_USE_CONSTEXPR float_round_style round_style = round_toward_zero;
    };

#if _GLIBCXX_USE_CHAR8_T
    /// numeric_limits<char8_t> specialization.
    template <>
    struct numeric_limits<char8_t>
    {
        static _GLIBCXX_USE_CONSTEXPR bool is_specialized = true;

        static _GLIBCXX_CONSTEXPR char8_t
        min() _GLIBCXX_USE_NOEXCEPT { return __glibcxx_min(char8_t); }

        static _GLIBCXX_CONSTEXPR char8_t
        max() _GLIBCXX_USE_NOEXCEPT { return __glibcxx_max(char8_t); }

        static _GLIBCXX_CONSTEXPR char8_t
        lowest() _GLIBCXX_USE_NOEXCEPT { return min(); }

        static _GLIBCXX_USE_CONSTEXPR int digits = __glibcxx_digits(char8_t);
        static _GLIBCXX_USE_CONSTEXPR int digits10 = __glibcxx_digits10(char8_t);
        static _GLIBCXX_USE_CONSTEXPR int max_digits10 = 0;
        static _GLIBCXX_USE_CONSTEXPR bool is_signed = __glibcxx_signed(char8_t);
        static _GLIBCXX_USE_CONSTEXPR bool is_integer = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_exact = true;
        static _GLIBCXX_USE_CONSTEXPR int radix = 2;

        static _GLIBCXX_CONSTEXPR char8_t
        epsilon() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_CONSTEXPR char8_t
        round_error() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_USE_CONSTEXPR int min_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int min_exponent10 = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent10 = 0;

        static _GLIBCXX_USE_CONSTEXPR bool has_infinity = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_quiet_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_signaling_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR float_denorm_style has_denorm = denorm_absent;
        static _GLIBCXX_USE_CONSTEXPR bool has_denorm_loss = false;

        static _GLIBCXX_CONSTEXPR char8_t
        infinity() _GLIBCXX_USE_NOEXCEPT { return char8_t(); }

        static _GLIBCXX_CONSTEXPR char8_t
        quiet_NaN() _GLIBCXX_USE_NOEXCEPT { return char8_t(); }

        static _GLIBCXX_CONSTEXPR char8_t
        signaling_NaN() _GLIBCXX_USE_NOEXCEPT { return char8_t(); }

        static _GLIBCXX_CONSTEXPR char8_t
        denorm_min() _GLIBCXX_USE_NOEXCEPT { return char8_t(); }

        static _GLIBCXX_USE_CONSTEXPR bool is_iec559 = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_bounded = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_modulo = !is_signed;

        static _GLIBCXX_USE_CONSTEXPR bool traps = __glibcxx_integral_traps;
        static _GLIBCXX_USE_CONSTEXPR bool tinyness_before = false;
        static _GLIBCXX_USE_CONSTEXPR float_round_style round_style = round_toward_zero;
    };
#endif

#if __cplusplus >= 201103L
    /// numeric_limits<char16_t> specialization.
    template <>
    struct numeric_limits<char16_t>
    {
        static constexpr bool is_specialized = true;

        static constexpr char16_t
        min() noexcept { return __glibcxx_min(char16_t); }

        static constexpr char16_t
        max() noexcept { return __glibcxx_max(char16_t); }

        static constexpr char16_t
        lowest() noexcept { return min(); }

        static constexpr int digits = __glibcxx_digits(char16_t);
        static constexpr int digits10 = __glibcxx_digits10(char16_t);
        static constexpr int max_digits10 = 0;
        static constexpr bool is_signed = __glibcxx_signed(char16_t);
        static constexpr bool is_integer = true;
        static constexpr bool is_exact = true;
        static constexpr int radix = 2;

        static constexpr char16_t
        epsilon() noexcept { return 0; }

        static constexpr char16_t
        round_error() noexcept { return 0; }

        static constexpr int min_exponent = 0;
        static constexpr int min_exponent10 = 0;
        static constexpr int max_exponent = 0;
        static constexpr int max_exponent10 = 0;

        static constexpr bool has_infinity = false;
        static constexpr bool has_quiet_NaN = false;
        static constexpr bool has_signaling_NaN = false;
        static constexpr float_denorm_style has_denorm = denorm_absent;
        static constexpr bool has_denorm_loss = false;

        static constexpr char16_t
        infinity() noexcept { return char16_t(); }

        static constexpr char16_t
        quiet_NaN() noexcept { return char16_t(); }

        static constexpr char16_t
        signaling_NaN() noexcept { return char16_t(); }

        static constexpr char16_t
        denorm_min() noexcept { return char16_t(); }

        static constexpr bool is_iec559 = false;
        static constexpr bool is_bounded = true;
        static constexpr bool is_modulo = !is_signed;

        static constexpr bool traps = __glibcxx_integral_traps;
        static constexpr bool tinyness_before = false;
        static constexpr float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<char32_t> specialization.
    template <>
    struct numeric_limits<char32_t>
    {
        static constexpr bool is_specialized = true;

        static constexpr char32_t
        min() noexcept { return __glibcxx_min(char32_t); }

        static constexpr char32_t
        max() noexcept { return __glibcxx_max(char32_t); }

        static constexpr char32_t
        lowest() noexcept { return min(); }

        static constexpr int digits = __glibcxx_digits(char32_t);
        static constexpr int digits10 = __glibcxx_digits10(char32_t);
        static constexpr int max_digits10 = 0;
        static constexpr bool is_signed = __glibcxx_signed(char32_t);
        static constexpr bool is_integer = true;
        static constexpr bool is_exact = true;
        static constexpr int radix = 2;

        static constexpr char32_t
        epsilon() noexcept { return 0; }

        static constexpr char32_t
        round_error() noexcept { return 0; }

        static constexpr int min_exponent = 0;
        static constexpr int min_exponent10 = 0;
        static constexpr int max_exponent = 0;
        static constexpr int max_exponent10 = 0;

        static constexpr bool has_infinity = false;
        static constexpr bool has_quiet_NaN = false;
        static constexpr bool has_signaling_NaN = false;
        static constexpr float_denorm_style has_denorm = denorm_absent;
        static constexpr bool has_denorm_loss = false;

        static constexpr char32_t
        infinity() noexcept { return char32_t(); }

        static constexpr char32_t
        quiet_NaN() noexcept { return char32_t(); }

        static constexpr char32_t
        signaling_NaN() noexcept { return char32_t(); }

        static constexpr char32_t
        denorm_min() noexcept { return char32_t(); }

        static constexpr bool is_iec559 = false;
        static constexpr bool is_bounded = true;
        static constexpr bool is_modulo = !is_signed;

        static constexpr bool traps = __glibcxx_integral_traps;
        static constexpr bool tinyness_before = false;
        static constexpr float_round_style round_style = round_toward_zero;
    };
#endif

    /// numeric_limits<short> specialization.
    template <>
    struct numeric_limits<short>
    {
        static _GLIBCXX_USE_CONSTEXPR bool is_specialized = true;

        static _GLIBCXX_CONSTEXPR short
        min() _GLIBCXX_USE_NOEXCEPT { return -__SHRT_MAX__ - 1; }

        static _GLIBCXX_CONSTEXPR short
        max() _GLIBCXX_USE_NOEXCEPT { return __SHRT_MAX__; }

#if __cplusplus >= 201103L
        static constexpr short
        lowest() noexcept
        {
            return min();
        }
#endif

        static _GLIBCXX_USE_CONSTEXPR int digits = __glibcxx_digits(short);
        static _GLIBCXX_USE_CONSTEXPR int digits10 = __glibcxx_digits10(short);
#if __cplusplus >= 201103L
        static constexpr int max_digits10 = 0;
#endif
        static _GLIBCXX_USE_CONSTEXPR bool is_signed = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_integer = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_exact = true;
        static _GLIBCXX_USE_CONSTEXPR int radix = 2;

        static _GLIBCXX_CONSTEXPR short
        epsilon() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_CONSTEXPR short
        round_error() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_USE_CONSTEXPR int min_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int min_exponent10 = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent10 = 0;

        static _GLIBCXX_USE_CONSTEXPR bool has_infinity = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_quiet_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_signaling_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR float_denorm_style has_denorm = denorm_absent;
        static _GLIBCXX_USE_CONSTEXPR bool has_denorm_loss = false;

        static _GLIBCXX_CONSTEXPR short
        infinity() _GLIBCXX_USE_NOEXCEPT { return short(); }

        static _GLIBCXX_CONSTEXPR short
        quiet_NaN() _GLIBCXX_USE_NOEXCEPT { return short(); }

        static _GLIBCXX_CONSTEXPR short
        signaling_NaN() _GLIBCXX_USE_NOEXCEPT { return short(); }

        static _GLIBCXX_CONSTEXPR short
        denorm_min() _GLIBCXX_USE_NOEXCEPT { return short(); }

        static _GLIBCXX_USE_CONSTEXPR bool is_iec559 = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_bounded = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_modulo = false;

        static _GLIBCXX_USE_CONSTEXPR bool traps = __glibcxx_integral_traps;
        static _GLIBCXX_USE_CONSTEXPR bool tinyness_before = false;
        static _GLIBCXX_USE_CONSTEXPR float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<unsigned short> specialization.
    template <>
    struct numeric_limits<unsigned short>
    {
        static _GLIBCXX_USE_CONSTEXPR bool is_specialized = true;

        static _GLIBCXX_CONSTEXPR unsigned short
        min() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_CONSTEXPR unsigned short
        max() _GLIBCXX_USE_NOEXCEPT { return __SHRT_MAX__ * 2U + 1; }

#if __cplusplus >= 201103L
        static constexpr unsigned short
        lowest() noexcept
        {
            return min();
        }
#endif

        static _GLIBCXX_USE_CONSTEXPR int digits = __glibcxx_digits(unsigned short);
        static _GLIBCXX_USE_CONSTEXPR int digits10 = __glibcxx_digits10(unsigned short);
#if __cplusplus >= 201103L
        static constexpr int max_digits10 = 0;
#endif
        static _GLIBCXX_USE_CONSTEXPR bool is_signed = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_integer = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_exact = true;
        static _GLIBCXX_USE_CONSTEXPR int radix = 2;

        static _GLIBCXX_CONSTEXPR unsigned short
        epsilon() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_CONSTEXPR unsigned short
        round_error() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_USE_CONSTEXPR int min_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int min_exponent10 = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent10 = 0;

        static _GLIBCXX_USE_CONSTEXPR bool has_infinity = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_quiet_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_signaling_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR float_denorm_style has_denorm = denorm_absent;
        static _GLIBCXX_USE_CONSTEXPR bool has_denorm_loss = false;

        static _GLIBCXX_CONSTEXPR unsigned short
        infinity() _GLIBCXX_USE_NOEXCEPT
        {
            return static_cast<unsigned short>(0);
        }

        static _GLIBCXX_CONSTEXPR unsigned short
        quiet_NaN() _GLIBCXX_USE_NOEXCEPT
        {
            return static_cast<unsigned short>(0);
        }

        static _GLIBCXX_CONSTEXPR unsigned short
        signaling_NaN() _GLIBCXX_USE_NOEXCEPT
        {
            return static_cast<unsigned short>(0);
        }

        static _GLIBCXX_CONSTEXPR unsigned short
        denorm_min() _GLIBCXX_USE_NOEXCEPT
        {
            return static_cast<unsigned short>(0);
        }

        static _GLIBCXX_USE_CONSTEXPR bool is_iec559 = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_bounded = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_modulo = true;

        static _GLIBCXX_USE_CONSTEXPR bool traps = __glibcxx_integral_traps;
        static _GLIBCXX_USE_CONSTEXPR bool tinyness_before = false;
        static _GLIBCXX_USE_CONSTEXPR float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<int> specialization.
    template <>
    struct numeric_limits<int>
    {
        static _GLIBCXX_USE_CONSTEXPR bool is_specialized = true;

        static _GLIBCXX_CONSTEXPR int
        min() _GLIBCXX_USE_NOEXCEPT { return -__INT_MAX__ - 1; }

        static _GLIBCXX_CONSTEXPR int
        max() _GLIBCXX_USE_NOEXCEPT { return __INT_MAX__; }

#if __cplusplus >= 201103L
        static constexpr int
        lowest() noexcept
        {
            return min();
        }
#endif

        static _GLIBCXX_USE_CONSTEXPR int digits = __glibcxx_digits(int);
        static _GLIBCXX_USE_CONSTEXPR int digits10 = __glibcxx_digits10(int);
#if __cplusplus >= 201103L
        static constexpr int max_digits10 = 0;
#endif
        static _GLIBCXX_USE_CONSTEXPR bool is_signed = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_integer = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_exact = true;
        static _GLIBCXX_USE_CONSTEXPR int radix = 2;

        static _GLIBCXX_CONSTEXPR int
        epsilon() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_CONSTEXPR int
        round_error() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_USE_CONSTEXPR int min_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int min_exponent10 = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent10 = 0;

        static _GLIBCXX_USE_CONSTEXPR bool has_infinity = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_quiet_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_signaling_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR float_denorm_style has_denorm = denorm_absent;
        static _GLIBCXX_USE_CONSTEXPR bool has_denorm_loss = false;

        static _GLIBCXX_CONSTEXPR int
        infinity() _GLIBCXX_USE_NOEXCEPT { return static_cast<int>(0); }

        static _GLIBCXX_CONSTEXPR int
        quiet_NaN() _GLIBCXX_USE_NOEXCEPT { return static_cast<int>(0); }

        static _GLIBCXX_CONSTEXPR int
        signaling_NaN() _GLIBCXX_USE_NOEXCEPT { return static_cast<int>(0); }

        static _GLIBCXX_CONSTEXPR int
        denorm_min() _GLIBCXX_USE_NOEXCEPT { return static_cast<int>(0); }

        static _GLIBCXX_USE_CONSTEXPR bool is_iec559 = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_bounded = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_modulo = false;

        static _GLIBCXX_USE_CONSTEXPR bool traps = __glibcxx_integral_traps;
        static _GLIBCXX_USE_CONSTEXPR bool tinyness_before = false;
        static _GLIBCXX_USE_CONSTEXPR float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<unsigned int> specialization.
    template <>
    struct numeric_limits<unsigned int>
    {
        static _GLIBCXX_USE_CONSTEXPR bool is_specialized = true;

        static _GLIBCXX_CONSTEXPR unsigned int
        min() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_CONSTEXPR unsigned int
        max() _GLIBCXX_USE_NOEXCEPT { return __INT_MAX__ * 2U + 1; }

#if __cplusplus >= 201103L
        static constexpr unsigned int
        lowest() noexcept
        {
            return min();
        }
#endif

        static _GLIBCXX_USE_CONSTEXPR int digits = __glibcxx_digits(unsigned int);
        static _GLIBCXX_USE_CONSTEXPR int digits10 = __glibcxx_digits10(unsigned int);
#if __cplusplus >= 201103L
        static constexpr int max_digits10 = 0;
#endif
        static _GLIBCXX_USE_CONSTEXPR bool is_signed = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_integer = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_exact = true;
        static _GLIBCXX_USE_CONSTEXPR int radix = 2;

        static _GLIBCXX_CONSTEXPR unsigned int
        epsilon() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_CONSTEXPR unsigned int
        round_error() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_USE_CONSTEXPR int min_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int min_exponent10 = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent10 = 0;

        static _GLIBCXX_USE_CONSTEXPR bool has_infinity = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_quiet_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_signaling_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR float_denorm_style has_denorm = denorm_absent;
        static _GLIBCXX_USE_CONSTEXPR bool has_denorm_loss = false;

        static _GLIBCXX_CONSTEXPR unsigned int
        infinity() _GLIBCXX_USE_NOEXCEPT { return static_cast<unsigned int>(0); }

        static _GLIBCXX_CONSTEXPR unsigned int
        quiet_NaN() _GLIBCXX_USE_NOEXCEPT
        {
            return static_cast<unsigned int>(0);
        }

        static _GLIBCXX_CONSTEXPR unsigned int
        signaling_NaN() _GLIBCXX_USE_NOEXCEPT
        {
            return static_cast<unsigned int>(0);
        }

        static _GLIBCXX_CONSTEXPR unsigned int
        denorm_min() _GLIBCXX_USE_NOEXCEPT
        {
            return static_cast<unsigned int>(0);
        }

        static _GLIBCXX_USE_CONSTEXPR bool is_iec559 = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_bounded = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_modulo = true;

        static _GLIBCXX_USE_CONSTEXPR bool traps = __glibcxx_integral_traps;
        static _GLIBCXX_USE_CONSTEXPR bool tinyness_before = false;
        static _GLIBCXX_USE_CONSTEXPR float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<long> specialization.
    template <>
    struct numeric_limits<long>
    {
        static _GLIBCXX_USE_CONSTEXPR bool is_specialized = true;

        static _GLIBCXX_CONSTEXPR long
        min() _GLIBCXX_USE_NOEXCEPT { return -__LONG_MAX__ - 1; }

        static _GLIBCXX_CONSTEXPR long
        max() _GLIBCXX_USE_NOEXCEPT { return __LONG_MAX__; }

#if __cplusplus >= 201103L
        static constexpr long
        lowest() noexcept
        {
            return min();
        }
#endif

        static _GLIBCXX_USE_CONSTEXPR int digits = __glibcxx_digits(long);
        static _GLIBCXX_USE_CONSTEXPR int digits10 = __glibcxx_digits10(long);
#if __cplusplus >= 201103L
        static constexpr int max_digits10 = 0;
#endif
        static _GLIBCXX_USE_CONSTEXPR bool is_signed = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_integer = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_exact = true;
        static _GLIBCXX_USE_CONSTEXPR int radix = 2;

        static _GLIBCXX_CONSTEXPR long
        epsilon() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_CONSTEXPR long
        round_error() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_USE_CONSTEXPR int min_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int min_exponent10 = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent10 = 0;

        static _GLIBCXX_USE_CONSTEXPR bool has_infinity = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_quiet_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_signaling_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR float_denorm_style has_denorm = denorm_absent;
        static _GLIBCXX_USE_CONSTEXPR bool has_denorm_loss = false;

        static _GLIBCXX_CONSTEXPR long
        infinity() _GLIBCXX_USE_NOEXCEPT { return static_cast<long>(0); }

        static _GLIBCXX_CONSTEXPR long
        quiet_NaN() _GLIBCXX_USE_NOEXCEPT { return static_cast<long>(0); }

        static _GLIBCXX_CONSTEXPR long
        signaling_NaN() _GLIBCXX_USE_NOEXCEPT { return static_cast<long>(0); }

        static _GLIBCXX_CONSTEXPR long
        denorm_min() _GLIBCXX_USE_NOEXCEPT { return static_cast<long>(0); }

        static _GLIBCXX_USE_CONSTEXPR bool is_iec559 = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_bounded = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_modulo = false;

        static _GLIBCXX_USE_CONSTEXPR bool traps = __glibcxx_integral_traps;
        static _GLIBCXX_USE_CONSTEXPR bool tinyness_before = false;
        static _GLIBCXX_USE_CONSTEXPR float_round_style round_style = round_toward_zero;
    };

    /// numeric_limits<unsigned long> specialization.
    template <>
    struct numeric_limits<unsigned long>
    {
        static _GLIBCXX_USE_CONSTEXPR bool is_specialized = true;

        static _GLIBCXX_CONSTEXPR unsigned long
        min() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_CONSTEXPR unsigned long
        max() _GLIBCXX_USE_NOEXCEPT { return __LONG_MAX__ * 2UL + 1; }

#if __cplusplus >= 201103L
        static constexpr unsigned long
        lowest() noexcept
        {
            return min();
        }
#endif

        static _GLIBCXX_USE_CONSTEXPR int digits = __glibcxx_digits(unsigned long);
        static _GLIBCXX_USE_CONSTEXPR int digits10 = __glibcxx_digits10(unsigned long);
#if __cplusplus >= 201103L
        static constexpr int max_digits10 = 0;
#endif
        static _GLIBCXX_USE_CONSTEXPR bool is_signed = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_integer = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_exact = true;
        static _GLIBCXX_USE_CONSTEXPR int radix = 2;

        static _GLIBCXX_CONSTEXPR unsigned long
        epsilon() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_CONSTEXPR unsigned long
        round_error() _GLIBCXX_USE_NOEXCEPT { return 0; }

        static _GLIBCXX_USE_CONSTEXPR int min_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int min_exponent10 = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent = 0;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent10 = 0;

        static _GLIBCXX_USE_CONSTEXPR bool has_infinity = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_quiet_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR bool has_signaling_NaN = false;
        static _GLIBCXX_USE_CONSTEXPR float_denorm_style has_denorm = denorm_absent;
        static _GLIBCXX_USE_CONSTEXPR bool has_denorm_loss = false;

        static _GLIBCXX_CONSTEXPR unsigned long
        infinity() _GLIBCXX_USE_NOEXCEPT
        {
            return static_cast<unsigned long>(0);
        }

        static _GLIBCXX_CONSTEXPR unsigned long
        quiet_NaN() _GLIBCXX_USE_NOEXCEPT
        {
            return static_cast<unsigned long>(0);
        }

        static _GLIBCXX_CONSTEXPR unsigned long
        signaling_NaN() _GLIBCXX_USE_NOEXCEPT
        {
            return static_cast<unsigned long>(0);
        }

        static _GLIBCXX_CONSTEXPR unsigned long
        denorm_min() _GLIBCXX_USE_NOEXCEPT
        {
            return static_cast<unsigned long>(0);
        }

        static _GLIBCXX_USE_CONSTEXPR bool is_iec559 = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_bounded = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_modulo = true;

        static _GLIBCXX_USE_CONSTEXPR bool traps = __glibcxx_integral_traps;
        static _GLIBCXX_USE_CONSTEXPR bool tinyness_before = false;
        static _GLIBCXX_USE_CONSTEXPR float_round_style round_style = round_toward_zero;
    };

#if !defined(__STRICT_ANSI__)

#define __INT_N(TYPE, BITSIZE, EXT, UEXT)                                                \
    template <>                                                                          \
    struct numeric_limits<TYPE>                                                          \
    {                                                                                    \
        static _GLIBCXX_USE_CONSTEXPR bool is_specialized = true;                        \
                                                                                         \
        static _GLIBCXX_CONSTEXPR TYPE                                                   \
        min() _GLIBCXX_USE_NOEXCEPT { return __glibcxx_min_b(TYPE, BITSIZE); }           \
                                                                                         \
        static _GLIBCXX_CONSTEXPR TYPE                                                   \
        max() _GLIBCXX_USE_NOEXCEPT { return __glibcxx_max_b(TYPE, BITSIZE); }           \
                                                                                         \
        static _GLIBCXX_USE_CONSTEXPR int digits = BITSIZE - 1;                          \
        static _GLIBCXX_USE_CONSTEXPR int digits10 = (BITSIZE - 1) * 643L / 2136;        \
                                                                                         \
        static _GLIBCXX_USE_CONSTEXPR bool is_signed = true;                             \
        static _GLIBCXX_USE_CONSTEXPR bool is_integer = true;                            \
        static _GLIBCXX_USE_CONSTEXPR bool is_exact = true;                              \
        static _GLIBCXX_USE_CONSTEXPR int radix = 2;                                     \
                                                                                         \
        static _GLIBCXX_CONSTEXPR TYPE                                                   \
        epsilon() _GLIBCXX_USE_NOEXCEPT { return 0; }                                    \
                                                                                         \
        static _GLIBCXX_CONSTEXPR TYPE                                                   \
        round_error() _GLIBCXX_USE_NOEXCEPT { return 0; }                                \
                                                                                         \
        EXT                                                                              \
                                                                                         \
            static _GLIBCXX_USE_CONSTEXPR int min_exponent = 0;                          \
        static _GLIBCXX_USE_CONSTEXPR int min_exponent10 = 0;                            \
        static _GLIBCXX_USE_CONSTEXPR int max_exponent = 0;                              \
        static _GLIBCXX_USE_CONSTEXPR int max_exponent10 = 0;                            \
                                                                                         \
        static _GLIBCXX_USE_CONSTEXPR bool has_infinity = false;                         \
        static _GLIBCXX_USE_CONSTEXPR bool has_quiet_NaN = false;                        \
        static _GLIBCXX_USE_CONSTEXPR bool has_signaling_NaN = false;                    \
        static _GLIBCXX_USE_CONSTEXPR float_denorm_style has_denorm = denorm_absent;     \
        static _GLIBCXX_USE_CONSTEXPR bool has_denorm_loss = false;                      \
                                                                                         \
        static _GLIBCXX_CONSTEXPR TYPE                                                   \
        infinity() _GLIBCXX_USE_NOEXCEPT                                                 \
        {                                                                                \
            return static_cast<TYPE>(0);                                                 \
        }                                                                                \
                                                                                         \
        static _GLIBCXX_CONSTEXPR TYPE                                                   \
        quiet_NaN() _GLIBCXX_USE_NOEXCEPT                                                \
        {                                                                                \
            return static_cast<TYPE>(0);                                                 \
        }                                                                                \
                                                                                         \
        static _GLIBCXX_CONSTEXPR TYPE                                                   \
        signaling_NaN() _GLIBCXX_USE_NOEXCEPT                                            \
        {                                                                                \
            return static_cast<TYPE>(0);                                                 \
        }                                                                                \
                                                                                         \
        static _GLIBCXX_CONSTEXPR TYPE                                                   \
        denorm_min() _GLIBCXX_USE_NOEXCEPT                                               \
        {                                                                                \
            return static_cast<TYPE>(0);                                                 \
        }                                                                                \
                                                                                         \
        static _GLIBCXX_USE_CONSTEXPR bool is_iec559 = false;                            \
        static _GLIBCXX_USE_CONSTEXPR bool is_bounded = true;                            \
        static _GLIBCXX_USE_CONSTEXPR bool is_modulo = false;                            \
                                                                                         \
        static _GLIBCXX_USE_CONSTEXPR bool traps = __glibcxx_integral_traps;             \
        static _GLIBCXX_USE_CONSTEXPR bool tinyness_before = false;                      \
        static _GLIBCXX_USE_CONSTEXPR float_round_style round_style = round_toward_zero; \
    };                                                                                   \
                                                                                         \
    template <>                                                                          \
    struct numeric_limits<unsigned TYPE>                                                 \
    {                                                                                    \
        static _GLIBCXX_USE_CONSTEXPR bool is_specialized = true;                        \
                                                                                         \
        static _GLIBCXX_CONSTEXPR unsigned TYPE                                          \
        min() _GLIBCXX_USE_NOEXCEPT { return 0; }                                        \
                                                                                         \
        static _GLIBCXX_CONSTEXPR unsigned TYPE                                          \
        max() _GLIBCXX_USE_NOEXCEPT                                                      \
        {                                                                                \
            return __glibcxx_max_b(unsigned TYPE, BITSIZE);                              \
        }                                                                                \
                                                                                         \
        UEXT                                                                             \
                                                                                         \
            static _GLIBCXX_USE_CONSTEXPR int digits = BITSIZE;                          \
        static _GLIBCXX_USE_CONSTEXPR int digits10 = BITSIZE * 643L / 2136;              \
        static _GLIBCXX_USE_CONSTEXPR bool is_signed = false;                            \
        static _GLIBCXX_USE_CONSTEXPR bool is_integer = true;                            \
        static _GLIBCXX_USE_CONSTEXPR bool is_exact = true;                              \
        static _GLIBCXX_USE_CONSTEXPR int radix = 2;                                     \
                                                                                         \
        static _GLIBCXX_CONSTEXPR unsigned TYPE                                          \
        epsilon() _GLIBCXX_USE_NOEXCEPT { return 0; }                                    \
                                                                                         \
        static _GLIBCXX_CONSTEXPR unsigned TYPE                                          \
        round_error() _GLIBCXX_USE_NOEXCEPT { return 0; }                                \
                                                                                         \
        static _GLIBCXX_USE_CONSTEXPR int min_exponent = 0;                              \
        static _GLIBCXX_USE_CONSTEXPR int min_exponent10 = 0;                            \
        static _GLIBCXX_USE_CONSTEXPR int max_exponent = 0;                              \
        static _GLIBCXX_USE_CONSTEXPR int max_exponent10 = 0;                            \
                                                                                         \
        static _GLIBCXX_USE_CONSTEXPR bool has_infinity = false;                         \
        static _GLIBCXX_USE_CONSTEXPR bool has_quiet_NaN = false;                        \
        static _GLIBCXX_USE_CONSTEXPR bool has_signaling_NaN = false;                    \
        static _GLIBCXX_USE_CONSTEXPR float_denorm_style has_denorm = denorm_absent;     \
        static _GLIBCXX_USE_CONSTEXPR bool has_denorm_loss = false;                      \
                                                                                         \
        static _GLIBCXX_CONSTEXPR unsigned TYPE                                          \
        infinity() _GLIBCXX_USE_NOEXCEPT                                                 \
        {                                                                                \
            return static_cast<unsigned TYPE>(0);                                        \
        }                                                                                \
                                                                                         \
        static _GLIBCXX_CONSTEXPR unsigned TYPE                                          \
        quiet_NaN() _GLIBCXX_USE_NOEXCEPT                                                \
        {                                                                                \
            return static_cast<unsigned TYPE>(0);                                        \
        }                                                                                \
                                                                                         \
        static _GLIBCXX_CONSTEXPR unsigned TYPE                                          \
        signaling_NaN() _GLIBCXX_USE_NOEXCEPT                                            \
        {                                                                                \
            return static_cast<unsigned TYPE>(0);                                        \
        }                                                                                \
                                                                                         \
        static _GLIBCXX_CONSTEXPR unsigned TYPE                                          \
        denorm_min() _GLIBCXX_USE_NOEXCEPT                                               \
        {                                                                                \
            return static_cast<unsigned TYPE>(0);                                        \
        }                                                                                \
                                                                                         \
        static _GLIBCXX_USE_CONSTEXPR bool is_iec559 = false;                            \
        static _GLIBCXX_USE_CONSTEXPR bool is_bounded = true;                            \
        static _GLIBCXX_USE_CONSTEXPR bool is_modulo = true;                             \
                                                                                         \
        static _GLIBCXX_USE_CONSTEXPR bool traps = __glibcxx_integral_traps;             \
        static _GLIBCXX_USE_CONSTEXPR bool tinyness_before = false;                      \
        static _GLIBCXX_USE_CONSTEXPR float_round_style round_style = round_toward_zero; \
    };

#if __cplusplus >= 201103L

#define __INT_N_201103(TYPE)            \
    static constexpr TYPE               \
    lowest() noexcept { return min(); } \
    static constexpr int max_digits10 = 0;

#define __INT_N_U201103(TYPE)           \
    static constexpr unsigned TYPE      \
    lowest() noexcept { return min(); } \
    static constexpr int max_digits10 = 0;

#else
#define __INT_N_201103(TYPE)
#define __INT_N_U201103(TYPE)
#endif

#ifdef __GLIBCXX_TYPE_INT_N_0
    __INT_N(__GLIBCXX_TYPE_INT_N_0, __GLIBCXX_BITSIZE_INT_N_0,
            __INT_N_201103(__GLIBCXX_TYPE_INT_N_0), __INT_N_U201103(__GLIBCXX_TYPE_INT_N_0))
#endif
#ifdef __GLIBCXX_TYPE_INT_N_1
    __INT_N(__GLIBCXX_TYPE_INT_N_1, __GLIBCXX_BITSIZE_INT_N_1,
            __INT_N_201103(__GLIBCXX_TYPE_INT_N_1), __INT_N_U201103(__GLIBCXX_TYPE_INT_N_1))
#endif
#ifdef __GLIBCXX_TYPE_INT_N_2
    __INT_N(__GLIBCXX_TYPE_INT_N_2, __GLIBCXX_BITSIZE_INT_N_2,
            __INT_N_201103(__GLIBCXX_TYPE_INT_N_2), __INT_N_U201103(__GLIBCXX_TYPE_INT_N_2))
#endif
#ifdef __GLIBCXX_TYPE_INT_N_3
    __INT_N(__GLIBCXX_TYPE_INT_N_3, __GLIBCXX_BITSIZE_INT_N_3,
            __INT_N_201103(__GLIBCXX_TYPE_INT_N_3), __INT_N_U201103(__GLIBCXX_TYPE_INT_N_3))
#endif

#undef __INT_N
#undef __INT_N_201103
#undef __INT_N_U201103

#endif

    /// numeric_limits<float> specialization.
    template <>
    struct numeric_limits<float>
    {
        static _GLIBCXX_USE_CONSTEXPR bool is_specialized = true;

        static _GLIBCXX_CONSTEXPR float
        min() _GLIBCXX_USE_NOEXCEPT { return __FLT_MIN__; }

        static _GLIBCXX_CONSTEXPR float
        max() _GLIBCXX_USE_NOEXCEPT { return __FLT_MAX__; }

#if __cplusplus >= 201103L
        static constexpr float
        lowest() noexcept
        {
            return -__FLT_MAX__;
        }
#endif

        static _GLIBCXX_USE_CONSTEXPR int digits = __FLT_MANT_DIG__;
        static _GLIBCXX_USE_CONSTEXPR int digits10 = __FLT_DIG__;
#if __cplusplus >= 201103L
        static constexpr int max_digits10 = __glibcxx_max_digits10(__FLT_MANT_DIG__);
#endif
        static _GLIBCXX_USE_CONSTEXPR bool is_signed = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_integer = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_exact = false;
        static _GLIBCXX_USE_CONSTEXPR int radix = __FLT_RADIX__;

        static _GLIBCXX_CONSTEXPR float
        epsilon() _GLIBCXX_USE_NOEXCEPT { return __FLT_EPSILON__; }

        static _GLIBCXX_CONSTEXPR float
        round_error() _GLIBCXX_USE_NOEXCEPT { return 0.5F; }

        static _GLIBCXX_USE_CONSTEXPR int min_exponent = __FLT_MIN_EXP__;
        static _GLIBCXX_USE_CONSTEXPR int min_exponent10 = __FLT_MIN_10_EXP__;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent = __FLT_MAX_EXP__;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent10 = __FLT_MAX_10_EXP__;

        static _GLIBCXX_USE_CONSTEXPR bool has_infinity = __FLT_HAS_INFINITY__;
        static _GLIBCXX_USE_CONSTEXPR bool has_quiet_NaN = __FLT_HAS_QUIET_NAN__;
        static _GLIBCXX_USE_CONSTEXPR bool has_signaling_NaN = has_quiet_NaN;
        static _GLIBCXX_USE_CONSTEXPR float_denorm_style has_denorm = bool(__FLT_HAS_DENORM__) ? denorm_present : denorm_absent;
        static _GLIBCXX_USE_CONSTEXPR bool has_denorm_loss = __glibcxx_float_has_denorm_loss;

        static _GLIBCXX_CONSTEXPR float
        infinity() _GLIBCXX_USE_NOEXCEPT { return __builtin_huge_valf(); }

        static _GLIBCXX_CONSTEXPR float
        quiet_NaN() _GLIBCXX_USE_NOEXCEPT { return __builtin_nanf(""); }

        static _GLIBCXX_CONSTEXPR float
        signaling_NaN() _GLIBCXX_USE_NOEXCEPT { return __builtin_nansf(""); }

        static _GLIBCXX_CONSTEXPR float
        denorm_min() _GLIBCXX_USE_NOEXCEPT { return __FLT_DENORM_MIN__; }

        static _GLIBCXX_USE_CONSTEXPR bool is_iec559 = has_infinity && has_quiet_NaN && has_denorm == denorm_present;
        static _GLIBCXX_USE_CONSTEXPR bool is_bounded = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_modulo = false;

        static _GLIBCXX_USE_CONSTEXPR bool traps = __glibcxx_float_traps;
        static _GLIBCXX_USE_CONSTEXPR bool tinyness_before = __glibcxx_float_tinyness_before;
        static _GLIBCXX_USE_CONSTEXPR float_round_style round_style = round_to_nearest;
    };

#undef __glibcxx_float_has_denorm_loss
#undef __glibcxx_float_traps
#undef __glibcxx_float_tinyness_before

    /// numeric_limits<double> specialization.
    template <>
    struct numeric_limits<double>
    {
        static _GLIBCXX_USE_CONSTEXPR bool is_specialized = true;

        static _GLIBCXX_CONSTEXPR double
        min() _GLIBCXX_USE_NOEXCEPT { return __DBL_MIN__; }

        static _GLIBCXX_CONSTEXPR double
        max() _GLIBCXX_USE_NOEXCEPT { return __DBL_MAX__; }

#if __cplusplus >= 201103L
        static constexpr double
        lowest() noexcept
        {
            return -__DBL_MAX__;
        }
#endif

        static _GLIBCXX_USE_CONSTEXPR int digits = __DBL_MANT_DIG__;
        static _GLIBCXX_USE_CONSTEXPR int digits10 = __DBL_DIG__;
#if __cplusplus >= 201103L
        static constexpr int max_digits10 = __glibcxx_max_digits10(__DBL_MANT_DIG__);
#endif
        static _GLIBCXX_USE_CONSTEXPR bool is_signed = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_integer = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_exact = false;
        static _GLIBCXX_USE_CONSTEXPR int radix = __FLT_RADIX__;

        static _GLIBCXX_CONSTEXPR double
        epsilon() _GLIBCXX_USE_NOEXCEPT { return __DBL_EPSILON__; }

        static _GLIBCXX_CONSTEXPR double
        round_error() _GLIBCXX_USE_NOEXCEPT { return 0.5; }

        static _GLIBCXX_USE_CONSTEXPR int min_exponent = __DBL_MIN_EXP__;
        static _GLIBCXX_USE_CONSTEXPR int min_exponent10 = __DBL_MIN_10_EXP__;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent = __DBL_MAX_EXP__;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent10 = __DBL_MAX_10_EXP__;

        static _GLIBCXX_USE_CONSTEXPR bool has_infinity = __DBL_HAS_INFINITY__;
        static _GLIBCXX_USE_CONSTEXPR bool has_quiet_NaN = __DBL_HAS_QUIET_NAN__;
        static _GLIBCXX_USE_CONSTEXPR bool has_signaling_NaN = has_quiet_NaN;
        static _GLIBCXX_USE_CONSTEXPR float_denorm_style has_denorm = bool(__DBL_HAS_DENORM__) ? denorm_present : denorm_absent;
        static _GLIBCXX_USE_CONSTEXPR bool has_denorm_loss = __glibcxx_double_has_denorm_loss;

        static _GLIBCXX_CONSTEXPR double
        infinity() _GLIBCXX_USE_NOEXCEPT { return __builtin_huge_val(); }

        static _GLIBCXX_CONSTEXPR double
        quiet_NaN() _GLIBCXX_USE_NOEXCEPT { return __builtin_nan(""); }

        static _GLIBCXX_CONSTEXPR double
        signaling_NaN() _GLIBCXX_USE_NOEXCEPT { return __builtin_nans(""); }

        static _GLIBCXX_CONSTEXPR double
        denorm_min() _GLIBCXX_USE_NOEXCEPT { return __DBL_DENORM_MIN__; }

        static _GLIBCXX_USE_CONSTEXPR bool is_iec559 = has_infinity && has_quiet_NaN && has_denorm == denorm_present;
        static _GLIBCXX_USE_CONSTEXPR bool is_bounded = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_modulo = false;

        static _GLIBCXX_USE_CONSTEXPR bool traps = __glibcxx_double_traps;
        static _GLIBCXX_USE_CONSTEXPR bool tinyness_before = __glibcxx_double_tinyness_before;
        static _GLIBCXX_USE_CONSTEXPR float_round_style round_style = round_to_nearest;
    };

#undef __glibcxx_double_has_denorm_loss
#undef __glibcxx_double_traps
#undef __glibcxx_double_tinyness_before

    /// numeric_limits<long double> specialization.
    template <>
    struct numeric_limits<long double>
    {
        static _GLIBCXX_USE_CONSTEXPR bool is_specialized = true;

        static _GLIBCXX_CONSTEXPR long double
        min() _GLIBCXX_USE_NOEXCEPT { return __LDBL_MIN__; }

        static _GLIBCXX_CONSTEXPR long double
        max() _GLIBCXX_USE_NOEXCEPT { return __LDBL_MAX__; }

#if __cplusplus >= 201103L
        static constexpr long double
        lowest() noexcept
        {
            return -__LDBL_MAX__;
        }
#endif

        static _GLIBCXX_USE_CONSTEXPR int digits = __LDBL_MANT_DIG__;
        static _GLIBCXX_USE_CONSTEXPR int digits10 = __LDBL_DIG__;
#if __cplusplus >= 201103L
        static _GLIBCXX_USE_CONSTEXPR int max_digits10 = __glibcxx_max_digits10(__LDBL_MANT_DIG__);
#endif
        static _GLIBCXX_USE_CONSTEXPR bool is_signed = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_integer = false;
        static _GLIBCXX_USE_CONSTEXPR bool is_exact = false;
        static _GLIBCXX_USE_CONSTEXPR int radix = __FLT_RADIX__;

        static _GLIBCXX_CONSTEXPR long double
        epsilon() _GLIBCXX_USE_NOEXCEPT { return __LDBL_EPSILON__; }

        static _GLIBCXX_CONSTEXPR long double
        round_error() _GLIBCXX_USE_NOEXCEPT { return 0.5L; }

        static _GLIBCXX_USE_CONSTEXPR int min_exponent = __LDBL_MIN_EXP__;
        static _GLIBCXX_USE_CONSTEXPR int min_exponent10 = __LDBL_MIN_10_EXP__;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent = __LDBL_MAX_EXP__;
        static _GLIBCXX_USE_CONSTEXPR int max_exponent10 = __LDBL_MAX_10_EXP__;

        static _GLIBCXX_USE_CONSTEXPR bool has_infinity = __LDBL_HAS_INFINITY__;
        static _GLIBCXX_USE_CONSTEXPR bool has_quiet_NaN = __LDBL_HAS_QUIET_NAN__;
        static _GLIBCXX_USE_CONSTEXPR bool has_signaling_NaN = has_quiet_NaN;
        static _GLIBCXX_USE_CONSTEXPR float_denorm_style has_denorm = bool(__LDBL_HAS_DENORM__) ? denorm_present : denorm_absent;
        static _GLIBCXX_USE_CONSTEXPR bool has_denorm_loss = __glibcxx_long_double_has_denorm_loss;

        static _GLIBCXX_CONSTEXPR long double
        infinity() _GLIBCXX_USE_NOEXCEPT { return __builtin_huge_vall(); }

        static _GLIBCXX_CONSTEXPR long double
        quiet_NaN() _GLIBCXX_USE_NOEXCEPT { return __builtin_nanl(""); }

        static _GLIBCXX_CONSTEXPR long double
        signaling_NaN() _GLIBCXX_USE_NOEXCEPT { return __builtin_nansl(""); }

        static _GLIBCXX_CONSTEXPR long double
        denorm_min() _GLIBCXX_USE_NOEXCEPT { return __LDBL_DENORM_MIN__; }

        static _GLIBCXX_USE_CONSTEXPR bool is_iec559 = has_infinity && has_quiet_NaN && has_denorm == denorm_present;
        static _GLIBCXX_USE_CONSTEXPR bool is_bounded = true;
        static _GLIBCXX_USE_CONSTEXPR bool is_modulo = false;

        static _GLIBCXX_USE_CONSTEXPR bool traps = __glibcxx_long_double_traps;
        static _GLIBCXX_USE_CONSTEXPR bool tinyness_before =
            __glibcxx_long_double_tinyness_before;
        static _GLIBCXX_USE_CONSTEXPR float_round_style round_style =
            round_to_nearest;
    };

#undef __glibcxx_long_double_has_denorm_loss
#undef __glibcxx_long_double_traps
#undef __glibcxx_long_double_tinyness_before

} // namespace

#undef __glibcxx_signed
#undef __glibcxx_min
#undef __glibcxx_max
#undef __glibcxx_digits
#undef __glibcxx_digits10
#undef __glibcxx_max_digits10

#endif