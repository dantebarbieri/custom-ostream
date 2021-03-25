#ifndef _STREAMBUF_HPP_
#define _STREAMBUF_HPP_

/***************************
 * THE  IMPLEMENTATION  OF *
 * STREAMBUF IS STATICALLY *
 * ALLOCATED AND  DOES NOT *
 * FOLLOW   THE  STANDARDS *
 * CLOSELY.   IT   IS   AN *
 * INCOMPLETE     VERSION, *
 * BECAUSE ANYTHING  TO DO *
 * WITH   INPUT   IS   NOT *
 * WRITTEN.                *
****************************/

#include "bits/c++config.hpp"
#include "iosfwd.hpp"
#include "bits/ios_base.hpp"
#include "climits.hpp"
// Used for testing outside of VM
// #include <iostream>

#define __STREAMBUF_SIZE__ USHRT_MAX

// #include <streambuf>
// #include "string.hpp"

namespace dvb
{
    template <typename CharT, typename Traits>
    class basic_streambuf
    {
    public:
        typedef CharT char_type;
        typedef Traits traits_type;
        typedef typename traits_type::int_type int_type;
        typedef typename traits_type::pos_type pos_type;
        typedef typename traits_type::off_type off_type;

        friend class basic_ios<char_type, traits_type>;
        friend class basic_ostream<char_type, traits_type>;

        friend class ios_base::Init;

    private:
        // Associated Character Sequence (source/sink)
        char_type acs[__STREAMBUF_SIZE__];

    protected:
        /*
        *  This is based on _IO_FILE, just reordered to be more consistent,
        *  and is intended to be the most minimal abstraction for an
        *  internal buffer.
        *  -  get == input == read
        *  -  put == output == write
        */
        // char_type *_M_in_beg;  ///< Start of get area.
        // char_type *_M_in_cur;  ///< Current read area.
        // char_type *_M_in_end;  ///< End of get area.
        char_type *_M_out_beg; ///< Start of put area.
        char_type *_M_out_cur; ///< Current put area.
        char_type *_M_out_end; ///< End of put area.

    protected:
        // Positioning

        virtual basic_streambuf<CharT, Traits> *setbuf(char_type *s, streamsize n)
        {
            (void)s;
            (void)n;
            return this;
        }

        virtual pos_type seekoff(off_type off, ios_base::seekdir dir, ios_base::openmode which = ios_base::in | ios_base::out)
        {
            (void)off;
            (void)dir;
            (void)which;
            return pos_type(off_type(-1));
        }

        virtual pos_type seekpos(pos_type pos, ios_base::openmode which = ios_base::in | ios_base::out)
        {
            (void)pos;
            (void)which;
            return pos_type(off_type(-1));
        }

        void setp(char_type *pbeg, char_type *pend)
        {
            _M_out_beg = _M_out_cur = pbeg;
            _M_out_end = pend;
        }

        virtual int sync()
        {
            // Safety
            *_M_out_cur = char_type();
            // std::cout << _M_out_beg << std::flush;
            setp(acs, acs + __STREAMBUF_SIZE__);
            return 0;
        }

        // Get Area

        // virtual streamsize showmanyc();

        // virtual int_type underflow();

        // virtual int_type uflow();

        // virtual streamsize xsgetn(char_type *s, streamsize count);

        // char_type *eback() const;

        // char_type *gptr() const;

        // char_type *egptr() const;

        // void gbump(int count);

        // void setg(char_type *gbeg, char_type *gcurr, char_type *gend);

        // Put Area

        virtual streamsize xsputn(const char_type *s, streamsize count)
        {
            streamsize ret = 0;
            while (ret < count)
            {
                const streamsize buf_len = epptr() - pptr();
                if (buf_len)
                {
                    const streamsize remaining = count - ret;
                    const streamsize len = buf_len < remaining ? buf_len : remaining;
                    traits_type::copy(pptr(), s, len);
                    ret += len;
                    s += len;
                    pbump(len);
                }

                if (ret < count)
                {
                    int_type c = overflow(traits_type::to_int_type(*s));
                    if (!traits_type::eq_int_type(c, traits_type::eof()))
                    {
                        ++ret;
                        ++s;
                    }
                    else
                        break;
                }
            }
            return ret;
        }

        virtual int_type overflow(int_type ch = Traits::eof())
        {
            (void)ch;
            return traits_type::eof();
        }

        char_type *pbase() const { return _M_out_beg; }

        char_type *pptr() const { return _M_out_cur; }

        char_type *epptr() const { return _M_out_end; }

        void pbump(int count) { _M_out_cur += count; }

        // Putback

        // virtual int_type pbackfail(int_type c = Traits::eof());
    public:
        virtual ~basic_streambuf() {}

        // Positioning

        basic_streambuf<CharT, Traits> *pubsetbuf(char_type *s, streamsize n) { return setbuf(s, n); }

        pos_type pubseekoff(off_type off, ios_base::seekdir dir, ios_base::openmode which = ios_base::in | ios_base::out) { return seekoff(off, dir, which); }

        pos_type pubseekpos(pos_type pos, ios_base::openmode which = ios_base::in | ios_base::out) { return seekpos(pos, which); }

        int pubsync() { return this->sync(); }

        char_type *pubgetbuf() { return _M_out_beg; }

        // Get area

        // streamsize in_avail();

        // int_type snextc();

        // int_type sbumpc();

        // int_type sgetc();

        // streamsize sgetn(char_type *s, streamsize count);

        // Put area

        int_type sputc(char_type ch)
        {
            if (pptr() < epptr())
            {
                *pptr() = ch;
                pbump(1);
                return traits_type::to_int_type(ch);
            }
            else
                return overflow(traits_type::to_int_type(ch));
        }

        streamsize sputn(const char_type *s, streamsize count) { return xsputn(s, count); }

        // Putback

        // int_type sputbackc(char_type c);

        // int_type sungetc();

        basic_streambuf() : /*_M_in_beg(0), _M_in_cur(0), _M_in_end(0),*/ _M_out_beg(acs), _M_out_cur(acs), _M_out_end(acs + __STREAMBUF_SIZE__) {}
    };
}

#endif