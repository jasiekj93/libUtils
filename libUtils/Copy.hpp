#pragma once

/**
 * @file Copy.hpp
 * @author Adrian Szczepanski
 * @date 17-09-2021
 * @brief 
 * @details
 */

#include <cstring>

namespace Utils
{
    template<typename T>
    inline void Copy(T *dst, const T *src, size_t n)
    {
        std::memcpy(dst, src, n * sizeof(T));
    }

    template<typename T>
    inline void Move(T *dst, const T *src, size_t n)
    {
        std::memmove(dst, src, n * sizeof(T));
    }
}