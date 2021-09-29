/**
 * @file DataUnit.test.cpp
 * @author Adrian Szczepanski
 * @date 11-08-2021
 * @brief 
 * @details
 */

#include <libUtils/DataUnit.hpp>

#include <CppUTest/CommandLineTestRunner.h>

using namespace Utils;

TEST_GROUP(DataUnitTest)
{
    
};

TEST(DataUnitTest, Hword)
{
    byte buffer[sizeof(hword)];
    byte expected[] = { 0x12, 0x34 };
    hword number = 0x1234;

    HwordToBytes(buffer, number);
    auto result = BytesToHword(buffer);

    CHECK_EQUAL(number, result);
    MEMCMP_EQUAL(expected, buffer, sizeof(expected));
}

TEST(DataUnitTest, Word)
{
    byte buffer[sizeof(word)];
    byte expected[] = { 0x12, 0x34, 0x56, 0x78 };
    word number = 0x12345678;

    WordToBytes(buffer, number);
    auto result = BytesToWord(buffer);

    CHECK_EQUAL(number, result);
    MEMCMP_EQUAL(expected, buffer, sizeof(expected));
}

TEST(DataUnitTest, Dword)
{
    byte buffer[sizeof(dword)];
    byte expected[] = { 0x12, 0x34, 0x56, 0x78, 0x90, 0xab, 0xcd, 0xef };
    dword number = 0x1234567890abcdef;

    DwordToBytes(buffer, number);
    auto result = BytesToDword(buffer);

    CHECK(number == result);
    MEMCMP_EQUAL(expected, buffer, sizeof(expected));
}