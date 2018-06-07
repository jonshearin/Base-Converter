#pragma once
#ifndef BaseConverter_h__
#define BaseConverter_h__

#include <Windows.h>
#include <string>

namespace BaseConverter
{
    const std::string  BASEDIGITS  =  "0123456789abcdefghijklmnopqrstuvwxyz";
    const std::wstring BASEDIGITSW = L"0123456789abcdefghijklmnopqrstuvwxyz";


    enum Radix : UINT64
    {
        Binary          =  2,
        Ternary         =  3,
        Quaternary      =  4,
        Quinary         =  5,
        Senary          =  6,
        Septenary       =  7,
        Octal           =  8,
        Nonary          =  9,
        Decimal         = 10,
        Undecimal       = 11,
        Duodecimal      = 12,
        Tredecimal      = 13,
        Tetradecimal    = 14,
        Pentadecimal    = 15,
        Hexadecimal     = 16,
        Heptadecimal    = 17,
        Octodecimal     = 18,
        Nonadecimal     = 19,
        Vigesimal       = 20,
        Unvigesimal     = 21,
        Duovigesimal    = 22,
        Trivigesimal    = 23,
        Tetravigesimal  = 24,
        Pentavigesimal  = 25,
        Hexavigesimal   = 26,
        Septevigesimal  = 27,
        Octovigesimal   = 28,
        Nonavigesimal   = 29,
        Trigesimal      = 30,
        Untrigesimal    = 31,
        Duotrigesimal   = 32,
        Tritrigesimal   = 33,
        Tetratrigesimal = 34,
        Pentatrigesimal = 35,
        Hexatrigecimal  = 36
    };

	std::string DecimalToBase(UINT64 number, UINT64 radix, const std::string &prefix = "", UINT minLength = 0, const std::string &pad = "0");
	std::wstring DecimalToBase(UINT64 number, UINT64 radix, const std::wstring &prefix = L"", UINT minLength = 0, const std::wstring &pad = L"0");
	UINT64 BaseToDecimal(const std::string &numberString, UINT64 radix);
	UINT64 BaseToDecimal(const std::wstring &numberString, UINT64 radix);

}
#endif // BaseConverter_h__