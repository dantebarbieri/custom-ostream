/**
 * @file basic_ios.hpp
 * @author Dante Barbieri (dante@barbieri.dev)
 * @brief Analogous to the <basic_ios> header
 * @version 0.1
 * @date 2021-03-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _BASIC_IOS_HPP_
#define _BASIC_IOS_HPP_

namespace dvb
{
    template <typename CharT, typename Traits>
    class basic_ios : public ios_base
    {
    public:
        typedef CharT char_type;
        typedef Traits traits_type;
        typedef typename traits_type::int_type int_type;
        typedef typename traits_type::pos_type pos_type;
        typedef typename traits_type::off_type off_type;

    protected:
        basic_ostream<CharT, Traits> *_M_tie;
        mutable char_type _M_fill;
        mutable bool _M_fill_init;
        basic_streambuf<CharT, Traits> *_M_streambuf;

    private:
        basic_ios(const basic_ios &);
        basic_ios &operator=(const basic_ios &);

    protected:
        basic_ios() : ios_base(), _M_tie(0), _M_fill(char_type()), _M_fill_init(false),
                      _M_streambuf(0) {}
        void init(basic_streambuf<CharT, Traits> *sb)
        {
            basic_ios::Init();
            _M_fill = CharT();
            _M_fill_init = false;

            _M_tie = 0;
            _M_streambuf = sb;
            _M_streambuf_state = sb ? (dvb::ios_base::iostate)0 : (dvb::ios_base::iostate)1;
            _M_flags = skipws | dec;
            _M_precision = 6;
            _M_width = 0;
        }
        void set_rdbuf(basic_streambuf<CharT, Traits> *sb);

    public:
        explicit basic_ios(dvb::basic_streambuf<CharT, Traits> *sb) : ios_base(), _M_tie(0), _M_fill(), _M_fill_init(false), _M_streambuf(0) { this->init(sb); }
        // virtual ~basic_ios() { }
        iostate rdstate() const { return _M_streambuf_state; }
        bool good() const { return this->rdstate() == 0; }
        bool eof() const { return (this->rdstate() & eofbit) != 0; }
        bool fail() const { return (this->rdstate() & (badbit | failbit)) != 0; }
        bool bad() const { return (this->rdstate() & badbit) != 0; }
        bool operator!() const { return this->fail(); }
        operator void *() const { return this->fail() ? 0 : const_cast<basic_ios*>(this); }
        basic_streambuf<CharT, Traits> *rdbuf() const { return _M_streambuf; }
        void clear(iostate state = goodbit)
        {
            if (this->rdbuf())
                _M_streambuf_state = state;
            else
                _M_streambuf_state = state | badbit;
        }
        void setstate(iostate state) { this->clear(this->rdstate() | state); }
        basic_ios &copyfmt(const basic_ios &other)
        {
            if (this != &other)
            {
                for (int i = 0; i < other._M_word_size; ++i)
                    _M_word[i] = other._M_word;
                _M_word_size = other._M_word_size;

                this->flags(other.flags());
                this->width(other.width());
                this->precision(other.precision());
                this->tie(other.tie());
                this->fill(other.fill());
            }
            return *this;
        }
        CharT fill() const
        {
            if (!_M_fill_init)
            {
                _M_fill = ' ';
                _M_fill_init = true;
            }
            return _M_fill;
        }
        CharT fill(CharT ch)
        {
            char_type old = this->fill();
            _M_fill = ch;
            return old;
        }
        basic_streambuf<CharT, Traits> *rdbuf(basic_streambuf<CharT, Traits> *sb)
        {
            basic_streambuf<CharT, Traits> *old = _M_streambuf;
            _M_streambuf = sb;
            this->clear();
            return old;
        }
        basic_ostream<CharT, Traits> *tie() const { return _M_tie; }
        basic_ostream<CharT, Traits> *tie(basic_ostream<CharT, Traits> *str)
        {
            basic_ostream<CharT, Traits> *old = _M_tie;
            _M_tie = str;
            return old;
        }
    };

    typedef basic_ios<char> ios;
    typedef basic_ios<wchar_t> wios;
}

#endif
