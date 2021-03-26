/**
 * @file postypes.hpp
 * @author Dante Barbieri (dante@barbieri.dev)
 * @brief Analogous to the <postypes> header
 * @version 0.1
 * @date 2021-03-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _POSTYPES_HPP_
#define _POSTYPES_HPP_

#include "../cwchar.hpp"

namespace dvb
{
    typedef long streamoff;

    typedef ptrdiff_t streamsize;

    template <typename State>
    class fpos
    {
        streamoff offset;
        State state_;

    public:
        State state() const { return state_; }
        void state(State st) { state_ = st; }
        fpos() : offset(0), state_() {}
        fpos(streamoff offset) : offset(offset), state_() {}
        operator streamoff() const { return offset; }

        fpos &operator+=(streamoff off)
        {
            offset += off;
            return *this;
        }

        fpos &operator-=(streamoff off)
        {
            offset -= off;
            return *this;
        }

        fpos operator+(streamoff off) const
        {
            fpos pos(*this);
            pos += off;
            return pos;
        }

        fpos operator-(streamoff off) const
        {
            fpos pos(*this);
            pos -= off;
            return pos;
        }

        streamoff operator-(const fpos &other) const
        {
            return offset - other.offset;
        }
    };

    template <typename _StateT>
    inline bool operator==(const fpos<_StateT> &lhs, const fpos<_StateT> &rhs)
    {
        return streamoff(lhs) == streamoff(rhs);
    }

    template <typename _StateT>
    inline bool operator!=(const fpos<_StateT> &lhs, const fpos<_StateT> &rhs)
    {
        return streamoff(lhs) != streamoff(rhs);
    }

    typedef fpos<mbstate_t> streampos;
    typedef fpos<mbstate_t> wstreampos;
}

#endif