#include "stdafx.h"
#include "CppUnitTest.h"
#include "..\BaseConverter\BaseConverter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace BaseConverter;

namespace BaseConverterTest
{		
	TEST_CLASS(UnitTest1)
	{
		public:

			TEST_METHOD(Test_DecimalToBase_string)
			{
				Assert::AreEqual(BinaryString, DecimalToBase(BinaryToDecimal, Radix::Binary, "", 8, "0"));
				Assert::AreEqual(OctalString, DecimalToBase(OctalToDecimal, Radix::Octal, ""));
				Assert::AreEqual("0" + OctalString, DecimalToBase(OctalToDecimal, Radix::Octal, "0"));
				Assert::AreEqual(HexString, DecimalToBase(HexToDecimal, Radix::Hexadecimal, ""));
				Assert::AreEqual("0x00" + HexString, DecimalToBase(HexToDecimal, Radix::Hexadecimal, "0x", 4, "0"));
				Assert::AreEqual(HexatridecimalString, DecimalToBase(HexatridecimalToDecimal, Radix::Hexatrigecimal, ""));
			}

			TEST_METHOD(Test_DecimalToBase_wstring)
			{
				Assert::AreEqual(BinaryWString, DecimalToBase(BinaryToDecimal, Radix::Binary, L"", 8, L"0"));
				Assert::AreEqual(OctalWString, DecimalToBase(OctalToDecimal, Radix::Octal, L""));
				Assert::AreEqual(L"0" + OctalWString, DecimalToBase(OctalToDecimal, Radix::Octal, L"0"));
				Assert::AreEqual(HexWString, DecimalToBase(HexToDecimal, Radix::Hexadecimal, L""));
				Assert::AreEqual(L"0x00" + HexWString, DecimalToBase(HexToDecimal, Radix::Hexadecimal, L"0x", 4, L"0"));
				Assert::AreEqual(HexatridecimalWString, DecimalToBase(HexatridecimalToDecimal, Radix::Hexatrigecimal, L""));
			}

			TEST_METHOD(Test_BaseToDecimal_string)
			{
				Assert::AreEqual(BinaryToDecimal, BaseToDecimal(BinaryString, Radix::Binary));
				Assert::AreEqual(OctalToDecimal, BaseToDecimal(OctalString, Radix::Octal));
				Assert::AreEqual(HexToDecimal, BaseToDecimal(HexString, Radix::Hexadecimal));
				Assert::AreEqual(HexatridecimalToDecimal, BaseToDecimal(HexatridecimalString, Radix::Hexatrigecimal));
			}

			TEST_METHOD(Test_BaseToDecimal_wstring)
			{
				Assert::AreEqual(BinaryToDecimal, BaseToDecimal(BinaryWString, Radix::Binary));
				Assert::AreEqual(OctalToDecimal, BaseToDecimal(OctalWString, Radix::Octal));
				Assert::AreEqual(HexToDecimal, BaseToDecimal(HexWString, Radix::Hexadecimal));
				Assert::AreEqual(HexatridecimalToDecimal, BaseToDecimal(HexatridecimalWString, Radix::Hexatrigecimal));
			}

		private:
			UINT64 HexToDecimal = 26;
			std::string HexString = "1a";
			std::wstring HexWString = L"1a";

			UINT64 BinaryToDecimal = 26;
			std::string BinaryString = "00011010";
			std::wstring BinaryWString = L"00011010";

			UINT64 OctalToDecimal = 71;
			std::string OctalString = "107";
			std::wstring OctalWString = L"107";

			UINT64 HexatridecimalToDecimal = 4283;
			std::string HexatridecimalString = "3az";
			std::wstring HexatridecimalWString = L"3az";
	};
}