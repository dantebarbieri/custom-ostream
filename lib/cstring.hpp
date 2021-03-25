/**
 * @file cstring.hpp
 * @author Dante Barbieri (dante@barbieri.dev)
 * @brief Analogous to a subset of the <cstring> header
 * @version 0.1
 * @date 2021-03-25
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef _CSTRING_HPP_
#define _CSTRING_HPP_

namespace dvb
{
    /* String Manipulation */
    /**
     * @brief copies one buffer to another
     * 
     * @param dest 
     * @param src 
     * @param count 
     * @return void* 
     */
    void *memcpy(void *dest, const void *src, size_t count);
    /**
     * @brief fills a buffer with a character
     * 
     * @param dest 
     * @param ch 
     * @param count 
     * @return void* 
     */
    void *memmove(void *dest, const void* src, size_t count);
    /**
     * @brief fills a buffer with a character
     * 
     * @param dest 
     * @param ch 
     * @param count 
     * @return void* 
     */
    void *memset(void *dest, int ch, size_t count);
    /**
     * @brief copies one string to another
     * 
     * @param dest 
     * @param src 
     * @return char* 
     */
    char *strcpy(char *dest, const char *src);
    /**
     * @brief copies a certain amount of characters from one string to another
     * 
     * @param dest 
     * @param src 
     * @param count 
     * @return char* 
     */
    char *strncpy(char *dest, const char *src, size_t count);
    /**
     * @brief concatenates two strings
     * 
     * @param dest 
     * @param src 
     * @return char* 
     */
    char *strcat(char *dest, const char *src);
    /**
     * @brief concatenates a certain amount of characters of two strings
     * 
     * @param dest 
     * @param src 
     * @param count 
     * @return char* 
     */
    char *strncat(char *dest, const char *src, size_t count);
    /* String Examination */
    /**
     * @brief returns the length of a given string
     * 
     * @param str 
     * @return size_t 
     */
    size_t strlen(const char *str);
    /**
     * @brief compares two strings
     * 
     * @param lhs 
     * @param rhs 
     * @return int 
     */
    int strcmp(const char *lhs, const char *rhs);
    /**
     * @brief compares a certain number of characters from two strings
     * 
     * @param lhs 
     * @param rhs 
     * @param count 
     * @return int 
     */
    int strncmp(const char *lhs, const char *rhs, size_t count);
    /**
     * @brief finds the first occurence of a character
     * 
     * @param str 
     * @param ch 
     * @return const char* 
     */
    const char *strchr(const char *str, int ch);
    /**
     * @brief finds the first occurence of a character
     * 
     * @param str 
     * @param ch 
     * @return char* 
     */
    char *strchr(char *str, int ch);
    /**
     * @brief finds the last occurrence of a character
     * 
     * @param str 
     * @param ch 
     * @return const char* 
     */
    const char *strrchr(const char *str, int ch);
    /**
     * @brief finds the last occurrence of a character
     * 
     * @param str 
     * @param ch 
     * @return char* 
     */
    char *strrchr(char *str, int ch);
    /**
     * @brief finds the first occurrence of a substring of characters
     * 
     * @param haystack 
     * @param needle 
     * @return const char* 
     */
    const char *strstr(const char *haystack, const char *needle);
    /**
     * @brief finds the first occurrence of a substring of characters
     * 
     * @param haystack 
     * @param needle 
     * @return char* 
     */
    char *strstr(char *haystack, const char *needle);
}

#include "cstring.tcc"

#endif