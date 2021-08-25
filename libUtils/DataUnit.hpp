#pragma once

#include <cstdint>
#include <cstddef>

using byte = uint8_t;
using hword = uint16_t;
using word = uint32_t;
using dword = uint64_t;

constexpr hword BytesToHword(const byte *input)
{
    return  (hword)input[0] << 8
        |   (hword)input[1];
}

constexpr word BytesToWord(const byte *input)
{
    return  (word)input[0] << 24
        |   (word)input[1] << 16
        |   (word)input[2] << 8
        |   (word)input[3];
}

constexpr dword BytesToDword(const byte *input)
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

constexpr void HwordToBytes(byte *output, hword value)
{
    output[0] = (byte)(value >> 8);
    output[1] = (byte)(value);
}

constexpr void WordToBytes(byte *output, word value)
{
    output[0] = (byte)(value >> 24);
    output[1] = (byte)(value >> 16);
    output[2] = (byte)(value >> 8);
    output[3] = (byte)(value);

}

constexpr void DwordToBytes(byte *output, dword value)
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