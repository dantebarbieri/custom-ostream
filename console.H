/**
 * @file console.H
 * @author Dante Barbieri (dante@barbieri.dev)
 * @brief A dummy file to declare the functions needed by ostream in Dr. Bettati's implementation.
 * @version 0.1
 * @date 2021-03-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <iostream>

typedef enum
{
    BLACK = 0,
    BLUE = 1,
    GREEN = 2,
    CYAN = 3,
    RED = 4,
    MAGENTA = 5,
    BROWN = 6,
    LIGHT_GREY = 7,
    DARK_GREY = 8,
    LIGHT_BLUE = 9,
    LIGHT_GREEN = 10,
    LIGHT_CYAN = 11,
    LIGHT_RED = 12,
    LIGHT_MAGENTA = 13,
    LIGHT_BROWN = 14,
    WHITE = 15
} COLOR_CODE;

class Console
{
public:
    static void init() {}

    static void puts(const char * _s) { std::cout << _s << std::flush; }

    static void set_TextColor(unsigned char, unsigned char) {}

    static unsigned char get_ForeColor() { return 0; }

    static unsigned char get_BackColor() { return 0; }
};

#endif