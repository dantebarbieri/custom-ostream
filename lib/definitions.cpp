#include "../console.H"
#include "iostream.hpp"

int dvb::ios_base::index = 0;

int dvb::ios_base::Init::_S_refcount = 0;
bool dvb::ios_base::Init::_S_synced_with_stdio = false;

dvb::streambuf dvb::cout_buf;
dvb::streambuf dvb::cerr_buf;
dvb::streambuf dvb::clog_buf;

dvb::ostream dvb::cout(&cout_buf);
dvb::ostream dvb::cerr(&cerr_buf);
dvb::ostream dvb::clog(&clog_buf);
// ios_base::Init::~Init()
// {
//     --_S_refcount;
//     if (_S_refcount == 0)
//         cout.flush();
// }

// typename dvb::ios_base::Init init;