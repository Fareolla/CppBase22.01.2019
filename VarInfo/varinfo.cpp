#include <iostream>
#include <limits>
#include "varinfo.h"

namespace VarInfo {

void Info (int key)
{
    switch (key)
    {
    case 1:
        std::cout << "bool info:" << std::endl;
        std::cout << "Size of bool : " << sizeof(bool) << " byte" <<  std::endl;
        std::cout << "Minimal bool value is: "<< std::numeric_limits<bool>::min() << std::endl;
        std::cout << "Maximum bool value is: " <<std::numeric_limits<bool>::max() << std::endl;
        break;
    case 2:
        std::cout << "char info:" << std::endl;
        std::cout << "Size of char : " << sizeof(char) << " byte" <<  std::endl;
        std::cout << "Minimal char value is: "<< std::numeric_limits<char>::min() << std::endl;
        std::cout << "Maximum char value is: " <<std::numeric_limits<char>::max() << std::endl;
        break;
    case 3:
        std::cout << "short info:" << std::endl;
        std::cout << "Size of short : " << sizeof(short) << " bytes" <<  std::endl;
        std::cout << "Minimal short value is: "<< std::numeric_limits<short>::min() << std::endl;
        std::cout << "Maximum short value is: " <<std::numeric_limits<short>::max() << std::endl;
        break;
    case 4:
        std::cout << "int info:" << std::endl;
        std::cout << "Size of int : " << sizeof(int) << " bytes" <<  std::endl;
        std::cout << "Minimal int value is: "<< std::numeric_limits<int>::min() << std::endl;
        std::cout << "Maximum int value is: " <<std::numeric_limits<int>::max() << std::endl;
        break;
    case 5:
        std::cout << "long info:" << std::endl;
        std::cout << "Size of long : " << sizeof(long) << " bytes" << std::endl;
        std::cout << "Minimal long value is: "<< std::numeric_limits<long>::min() << std::endl;
        std::cout << "Maximum long value is: " <<std::numeric_limits<long>::max() << std::endl;
        break;
    case 6:
        std::cout << "float info:" << std::endl;
        std::cout << "Size of float : " << sizeof(float) << " bytes" << std::endl;
        std::cout << "Minimal float value is: "<< std::numeric_limits<float>::min() << std::endl;
        std::cout << "Maximum float value is: " <<std::numeric_limits<float>::max() << std::endl;
        break;
    case 7:
        std::cout << "double info:" << std::endl;
        std::cout << "Size of double : " << sizeof(double) << " bytes" << std::endl;
        std::cout << "Minimal double value is: "<< std::numeric_limits<double>::min() << std::endl;
        std::cout << "Maximum double value is: " <<std::numeric_limits<double>::max() << std::endl;
        break;
    default:
        std::cout << "Wrong number selected!" <<std::endl;

    }
}
} // namespace VarInfo
