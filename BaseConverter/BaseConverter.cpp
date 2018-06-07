#include "BaseConverter.h"

namespace BaseConverter
{
	std::string BaseConverter::DecimalToBase(UINT64 number, UINT64 radix, const std::string &prefix /*= ""*/, UINT minLength /*= 0*/, const std::string &pad /*= "0"*/)
	{
		std::string retVal = number == 0 ? "0" : "";
		UINT64 mod = 0;

		while (number != 0)
		{
			mod = number % radix;
			retVal = BASEDIGITS[mod] + retVal;
			number /= radix;
		}

		while (retVal.length() < minLength && pad.length() > 0)
			retVal = pad + retVal;

		if (!prefix.empty())
			retVal = prefix + retVal;

		return retVal;
	}
	
	std::wstring BaseConverter::DecimalToBase(UINT64 number, UINT64 radix, const std::wstring &prefix /*= L""*/, UINT minLength /*= 0*/, const std::wstring &pad /*= L"0"*/)
	{
		std::wstring retVal = number == 0 ? L"0" : L"";
		UINT64 mod = 0;

		while (number != 0)
		{
			mod = number % radix;
			retVal = BASEDIGITSW[mod] + retVal;
			number /= radix;
		}

		while (retVal.length() < minLength && pad.length() > 0)
			retVal = pad + retVal;

        if (!prefix.empty())
            retVal = prefix + retVal;

		return retVal;
	}	
	
	UINT64 BaseConverter::BaseToDecimal(const std::string &numberString, UINT64 radix)
	{
		using namespace std;

		size_t iterator = numberString.length();
		size_t position = 0;
		UINT64 decimal = 0;
		UINT64 multiplier = 1;

		do 
		{
			position = BASEDIGITS.find(numberString[iterator - 1]);
			if (position == string::npos)
				break;

			decimal += (position * multiplier);
			multiplier *= radix;
		} while (--iterator > 0);

		return decimal;
	}
	
	UINT64 BaseConverter::BaseToDecimal(const std::wstring &numberString, UINT64 radix)
	{
		using namespace std;

		UINT iterator = numberString.length();
		size_t position = 0;
		UINT64 decimal = 0;
		UINT64 multiplier = 1;
		do
		{
			position = BASEDIGITSW.find(numberString[iterator - 1]);
			if (position == string::npos)
				break;

			decimal += (position * multiplier);
			multiplier *= radix;
		} while (--iterator > 0);

		return decimal;
	}
	

}
