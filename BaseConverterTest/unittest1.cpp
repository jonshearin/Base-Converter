#include "stdafx.h"
#include "CppUnitTest.h"
#include "../BaseConverter/BaseConverter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace BaseConverter;

namespace BaseConverterTest
{		
	TEST_CLASS(UnitTest1)
	{
		public:

			TEST_METHOD(Test_DecimalToBase_string)
			{
				Assert::AreEqual(BinaryString, decimal_to_base(BinaryToDecimal, Radix::Binary, "", 8, "0"));
				Assert::AreEqual(OctalString, decimal_to_base(OctalToDecimal, Radix::Octal, ""));
				Assert::AreEqual("0" + OctalString, decimal_to_base(OctalToDecimal, Radix::Octal, "0"));
				Assert::AreEqual(HexString, decimal_to_base(HexToDecimal, Radix::Hexadecimal, ""));
				Assert::AreEqual("0x00" + HexString, decimal_to_base(HexToDecimal, Radix::Hexadecimal, "0x", 4, "0"));
				Assert::AreEqual(HexatridecimalString, decimal_to_base(HexatridecimalToDecimal, Radix::Hexatrigecimal, ""));
			}

			TEST_METHOD(Test_DecimalToBase_wstring)
			{
				Assert::AreEqual(BinaryWString, decimal_to_base(BinaryToDecimal, Radix::Binary, L"", 8, L"0"));
				Assert::AreEqual(OctalWString, decimal_to_base(OctalToDecimal, Radix::Octal, L""));
				Assert::AreEqual(L"0" + OctalWString, decimal_to_base(OctalToDecimal, Radix::Octal, L"0"));
				Assert::AreEqual(HexWString, decimal_to_base(HexToDecimal, Radix::Hexadecimal, L""));
				Assert::AreEqual(L"0x00" + HexWString, decimal_to_base(HexToDecimal, Radix::Hexadecimal, L"0x", 4, L"0"));
				Assert::AreEqual(HexatridecimalWString, decimal_to_base(HexatridecimalToDecimal, Radix::Hexatrigecimal, L""));
			}

			TEST_METHOD(Test_BaseToDecimal_string)
			{
				Assert::AreEqual(BinaryToDecimal, base_to_decimal(BinaryString, Radix::Binary));
				Assert::AreEqual(OctalToDecimal, base_to_decimal(OctalString, Radix::Octal));
				Assert::AreEqual(HexToDecimal, base_to_decimal(HexString, Radix::Hexadecimal));
				Assert::AreEqual(HexatridecimalToDecimal, base_to_decimal(HexatridecimalString, Radix::Hexatrigecimal));
			}

			TEST_METHOD(Test_BaseToDecimal_wstring)
			{
				Assert::AreEqual(BinaryToDecimal, base_to_decimal(BinaryWString, Radix::Binary));
				Assert::AreEqual(OctalToDecimal, base_to_decimal(OctalWString, Radix::Octal));
				Assert::AreEqual(HexToDecimal, base_to_decimal(HexWString, Radix::Hexadecimal));
				Assert::AreEqual(HexatridecimalToDecimal, base_to_decimal(HexatridecimalWString, Radix::Hexatrigecimal));
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