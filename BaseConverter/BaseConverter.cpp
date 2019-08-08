 #include "BaseConverter.h"

namespace BaseConverter
{
    std::string decimal_to_base(UINT64 number, UINT64 radix, const std::string &prefix /*= ""*/, const UINT minLength /*= 0*/, const std::string &pad /*= "0"*/)
    {
        std::string retVal = number == 0 ? "0" : "";

        while (number != 0)
        {
            retVal = BASEDIGITS[number % radix] + retVal;
            number /= radix;
        }

        while (retVal.length() < minLength && pad.length() > 0)
            retVal = pad + retVal;

        if (!prefix.empty())
            retVal = prefix + retVal;

        return retVal;
    }
    
    std::wstring decimal_to_base(UINT64 number, UINT64 radix, const std::wstring &prefix /*= L""*/, const UINT minLength /*= 0*/, const std::wstring &pad /*= L"0"*/)
    {
        std::wstring retVal = number == 0 ? L"0" : L"";

        while (number != 0)
        {
            retVal = BASEDIGITSW[number % radix] + retVal;
            number /= radix;
        }

        while (retVal.length() < minLength && pad.length() > 0)
            retVal = pad + retVal;

        if (!prefix.empty())
            retVal = prefix + retVal;

        return retVal;
    }	
    
    UINT64 base_to_decimal(const std::string &numberString, const UINT64 radix)
    {
        using namespace std;

        auto iterator = numberString.length();
        UINT64 decimal = 0;
        UINT64 multiplier = 1;

        do 
        {
            if (const auto position = BASEDIGITS.find(numberString[iterator - 1]); position != string::npos)
            {
                decimal += (position * multiplier);
                multiplier *= radix;    
            }
            else
            {
                break;
            }
        } while (--iterator > 0);

        return decimal;
    }
    
    UINT64 base_to_decimal(const std::wstring &numberString, const UINT64 radix)
    {
        using namespace std;

        auto iterator = numberString.length();
        UINT64 decimal = 0;
        UINT64 multiplier = 1;

        do 
        {
            if (const auto position = BASEDIGITSW.find(numberString[iterator - 1]); position != string::npos)
            {
                decimal += (position * multiplier);
                multiplier *= radix;    
            }
            else
            {
                break;
            }
        } while (--iterator > 0);

        return decimal;
    }
}
