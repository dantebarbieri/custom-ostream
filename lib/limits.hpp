/**
 * @file limits.hpp
 * @author Dante Barbieri (dante@barbieri.dev)
 * @brief Analogous to the <limits> header
 * @version 0.1
 * @date 2021-03-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _LIMITS_HPP_
#define _LIMITS_HPP_

namespace dvb
{
    template <class T>
    class numeric_limits;

    /**
   *  @brief Describes the rounding style for floating-point types.
   *
   *  This is used in the std::numeric_limits class.
  */
    enum float_round_style
    {
        round_indeterminate = -1,     /// Intermediate.
        round_toward_zero = 0,        /// To zero.
        round_to_nearest = 1,         /// To the nearest representable value.
        round_toward_infinity = 2,    /// To infinity.
        round_toward_neg_infinity = 3 /// To negative infinity.
    };

    /**
   *  @brief Describes the denormalization for floating-point types.
   *
   *  These values represent the presence or absence of a variable number
   *  of exponent bits.  This type is used in the std::numeric_limits class.
  */
    enum float_denorm_style
    {
        /// Indeterminate at compile time whether denormalized values are allowed.
        denorm_indeterminate = -1,
        /// The type does not allow denormalized values.
        denorm_absent = 0,
        /// The type allows denormalized values.
        denorm_present = 1
    };

    template <>
    class numeric_limits<bool>;

    template <>
    class numeric_limits<char>;
    template <>
    class numeric_limits<signed char>;
    template <>
    class numeric_limits<unsigned char>;
    template <>
    class numeric_limits<wchar_t>;

    template <>
    class numeric_limits<short>;
    template <>
    class numeric_limits<int>;
    template <>
    class numeric_limits<long>;
    template <>
    class numeric_limits<unsigned short>;
    template <>
    class numeric_limits<unsigned int>;
    template <>
    class numeric_limits<unsigned long>;

    template <>
    class numeric_limits<float>;
    template <>
    class numeric_limits<double>;
    template <>
    class numeric_limits<long double>;

    struct __numeric_limits_base
    {
        /** This will be true for all fundamental types (which have
	specializations), and false for everything else.  */
        static const bool is_specialized = false;

        /** The number of @c radix digits that be represented without change:  for
	integer types, the number of non-sign bits in the mantissa; for
	floating types, the number of @c radix digits in the mantissa.  */
        static const int digits = 0;

        /** The number of base 10 digits that can be represented without change. */
        static const int digits10 = 0;

        /** The number of base 10 digits required to ensure that values which
	differ are always differentiated.  */
        static const int max_digits10 = 0;

        /** True if the type is signed.  */
        static const bool is_signed = false;

        /** True if the type is integer.  */
        static const bool is_integer = false;

        /** True if the type uses an exact representation. All integer types are
	exact, but not all exact types are integer.  For example, rational and
	fixed-exponent representations are exact but not integer. */
        static const bool is_exact = false;

        /** For integer types, specifies the base of the representation.  For
	floating types, specifies the base of the exponent representation.  */
        static const int radix = 0;

        /** The minimum negative integer such that @c radix raised to the power of
	(one less than that integer) is a normalized floating point number.  */
        static const int min_exponent = 0;

        /** The minimum negative integer such that 10 raised to that power is in
	the range of normalized floating point numbers.  */
        static const int min_exponent10 = 0;

        /** The maximum positive integer such that @c radix raised to the power of
	(one less than that integer) is a representable finite floating point
	number.  */
        static const int max_exponent = 0;

        /** The maximum positive integer such that 10 raised to that power is in
	the range of representable finite floating point numbers.  */
        static const int max_exponent10 = 0;

        /** True if the type has a representation for positive infinity.  */
        static const bool has_infinity = false;

        /** True if the type has a representation for a quiet (non-signaling)
	Not a Number.  */
        static const bool has_quiet_NaN = false;

        /** True if the type has a representation for a signaling
	Not a Number.  */
        static const bool has_signaling_NaN = false;

        /** See std::float_denorm_style for more information.  */
        static const float_denorm_style has_denorm = denorm_absent;

        /** True if loss of accuracy is detected as a denormalization loss,
	rather than as an inexact result. */
        static const bool has_denorm_loss = false;

        /** True if-and-only-if the type adheres to the IEC 559 standard, also
	known as IEEE 754.  (Only makes sense for floating point types.)  */
        static const bool is_iec559 = false;

        /** True if the set of values representable by the type is
	finite.  All built-in types are bounded, this member would be
	false for arbitrary precision types. */
        static const bool is_bounded = false;

        /** True if the type is @e modulo. A type is modulo if, for any
	operation involving +, -, or * on values of that type whose
	result would fall outside the range [min(),max()], the value
	returned differs from the true value by an integer multiple of
	max() - min() + 1. On most machines, this is false for floating
	types, true for unsigned integers, and true for signed integers.
	See PR22200 about signed integers.  */
        static const bool is_modulo = false;

        /** True if trapping is implemented for this type.  */
        static const bool traps = false;

        /** True if tininess is detected before rounding.  (see IEC 559)  */
        static const bool tinyness_before = false;

        /** See std::float_round_style for more information.  This is only
	meaningful for floating types; integer types will all be
	round_toward_zero.  */
        static const float_round_style round_style =
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
        static _Tp
        min() { return _Tp(); }

        /** The maximum finite value.  */
        static _Tp
        max() { return _Tp(); }

        /** A finite value x such that there is no other finite value y
       *  where y < x.  */
        static _Tp
        lowest() { return _Tp(); }

        /** The @e machine @e epsilon:  the difference between 1 and the least
	  value greater than 1 that is representable.  */
        static _Tp
        epsilon() { return _Tp(); }

        /** The maximum rounding error measurement (see LIA-1).  */
        static _Tp
        round_error() { return _Tp(); }

        /** The representation of positive infinity, if @c has_infinity.  */
        static _Tp
        infinity() { return _Tp(); }

        /** The representation of a quiet Not a Number,
	  if @c has_quiet_NaN. */
        static _Tp
        quiet_NaN() { return _Tp(); }

        /** The representation of a signaling Not a Number, if
	  @c has_signaling_NaN. */
        static _Tp
        signaling_NaN() { return _Tp(); }

        /** The minimum positive denormalized value.  For types where
	  @c has_denorm is false, this is the minimum positive normalized
	  value.  */
        static _Tp
        denorm_min() { return _Tp(); }
    };
}

#include "limits.tcc"

#endif