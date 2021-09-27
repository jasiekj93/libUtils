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
#include <array>

using byte = uint8_t;
using hword = uint16_t;
using word = uint32_t;
using dword = uint64_t;

static constexpr byte BYTE_MAX = UINT8_MAX;
static constexpr hword HWORD_MAX = UINT16_MAX;
static constexpr word WORD_MAX = UINT32_MAX;
static constexpr dword DWORD_MAX = UINT64_MAX;

inline hword BytesToHword(const byte *input)
{
    return  (hword)input[0] << 8
        |   (hword)input[1];
}

inline word BytesToWord(const byte *input)
{
    return  (word)input[0] << 24
        |   (word)input[1] << 16
        |   (word)input[2] << 8
        |   (word)input[3];
}

inline dword BytesToDword(const byte *input)
{
    return  (dword)input[0] << 56 
        |   (dword)input[1] << 48 
        |   (dword)input[2] << 40
        |   (dword)input[3] << 32
        |   (dword)input[4] << 24
        |   (dword)input[5] << 16
        |   (dword)input[6] << 8
        |   (dword)input[7];
}

inline hword BytesToHword(const std::array<byte, sizeof(hword)> &array)
{
    return BytesToHword(array.data());
}

inline word BytesToWord(const std::array<byte, sizeof(word)> &array)
{
    return BytesToWord(array.data());
}

inline dword BytesToDword(const std::array<byte, sizeof(dword)> &array)
{
    return BytesToDword(array.data());
}

inline void HwordToBytes(byte *output, hword value)
{
    output[0] = (byte)(value >> 8);
    output[1] = (byte)(value);
}

inline void WordToBytes(byte *output, word value)
{
    output[0] = (byte)(value >> 24);
    output[1] = (byte)(value >> 16);
    output[2] = (byte)(value >> 8);
    output[3] = (byte)(value);

}

inline void DwordToBytes(byte *output, dword value)
{
    output[0] = (byte)(value >> 56);
    output[1] = (byte)(value >> 48);
    output[2] = (byte)(value >> 40);
    output[3] = (byte)(value >> 32);
    output[4] = (byte)(value >> 24);
    output[5] = (byte)(value >> 16);
    output[6] = (byte)(value >> 8);
    output[7] = (byte)(value);
}

inline std::array<byte, sizeof(hword)> HwordToBytes(hword value)
{
    std::array<byte, sizeof(hword)> output;
    HwordToBytes(output.data(), value);
    return output;
}

inline std::array<byte, sizeof(word)> WordToBytes(word value)
{
    std::array<byte, sizeof(word)> output;
    WordToBytes(output.data(), value);
    return output;
}

inline std::array<byte, sizeof(dword)> DwordToBytes(dword value)
{
    std::array<byte, sizeof(dword)> output;
    DwordToBytes(output.data(), value);
    return output;
}