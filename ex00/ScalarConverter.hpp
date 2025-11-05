#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <cctype>
#include <iomanip>

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator=(const ScalarConverter &copy);
    ~ScalarConverter();

    static void convert(const std::string &literal);

private:
    static bool isPseudoLiteral(const std::string &literal);
    static bool isChar(const std::string &literal);
    static bool isInt(const std::string &literal);
    static bool isFloat(const std::string &literal);
    static bool isDouble(const std::string &literal);
};

#endif
