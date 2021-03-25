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
}

#include "limits.tcc"

#endif