#pragma once

/**
 * @file DataUnit.hpp
 * @author Adrian Szczepanski
 * @date 24-09-2021
 * @brief 
 * @details
 */

#include <cstdint>
#include <cstddef>
#include <cstring>
#include <array>
#include <algorithm>

using byte = uint8_t;
using hword = uint16_t;
using word = uint32_t;
using dword = uint64_t;

using uint8 = uint8_t;

static constexpr byte BYTE_MAX = UINT8_MAX;
static constexpr hword HWORD_MAX = UINT16_MAX;
static constexpr word WORD_MAX = UINT32_MAX;
static constexpr dword DWORD_MAX = UINT64_MAX;

namespace Utils
{
    template<class T>
    inline std::array<byte, sizeof(T)> ToBytes(const T &object)
    {
        std::array<byte, sizeof(T)> result;
        std::memcpy(result.data(), &object, sizeof(T));
        return result;
    }

    template<class T>
    inline void ToBytes(byte *out, const T &object)
    {
        std::memcpy(out, &object, sizeof(T));
    }

    template<class T>
    inline std::array<byte, sizeof(T)> ToBytesReversed(const T &object)
    {
        std::array<byte, sizeof(T)> result;
        std::memcpy(result.data(), &object, sizeof(T));
        std::reverse(result.begin(), result.end());

        return result;
    }

    template<class T>
    inline void ToBytesReversed(byte *out, const T &object)
    {
        std::memcpy(out, &object, sizeof(T));
        std::reverse(out, out + sizeof(T));
    }

    template<class T>
    inline T FromBytes(const byte *buffer)
    {
        T result;
        std::memcpy(&result, buffer, sizeof(T));
        return result;
    }

    template<class T>
    inline T FromBytes(const std::array<byte, sizeof(T)> &buffer)
    {
        T result;
        std::memcpy(&result, buffer.data(), sizeof(T));
        return result;
    }
    
    template<class T>
    inline T FromBytesReversed(const byte *buffer)
    {
        T result;
        auto pointer = (byte *)&result;
        std::memcpy(pointer, buffer, sizeof(T));
        std::reverse(pointer, pointer + sizeof(T));
        return result;
    }

    template<class T>
    inline T FromBytesReversed(const std::array<byte, sizeof(T)> &buffer)
    {
        T result;
        auto pointer = (byte *)&result;
        std::memcpy(pointer, buffer.data(), sizeof(T));
        std::reverse(pointer, pointer + sizeof(T));
        return result;
    }
    
    inline auto BytesToHword(const byte *b) { return FromBytesReversed<hword>(b); }
    inline auto BytesToHword(const std::array<byte, sizeof(hword)> &b) { return FromBytesReversed<hword>(b); }
    inline auto BytesToWord(const byte *b) { return FromBytesReversed<word>(b); }
    inline auto BytesToWord(const std::array<byte, sizeof(word)> &b) { return FromBytesReversed<word>(b); }
    inline auto BytesToDword(const byte *b) { return FromBytesReversed<dword>(b); }
    inline auto BytesToDword(const std::array<byte, sizeof(dword)> &b) { return FromBytesReversed<dword>(b); }

    inline auto HwordToBytes(hword v) { return ToBytesReversed<hword>(v); }
    inline auto HwordToBytes(byte *b, hword v) { return ToBytesReversed<hword>(b, v); }
    inline auto WordToBytes(word v) { return ToBytesReversed<word>(v); }
    inline auto WordToBytes(byte *b, word v) { return ToBytesReversed<word>(b, v); }
    inline auto DwordToBytes(dword v) { return ToBytesReversed<dword>(v); }
    inline auto DwordToBytes(byte *b, dword v) { return ToBytesReversed<dword>(b, v); }
}