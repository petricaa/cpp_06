#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <cmath>

bool ScalarConverter::isPseudoLiteral(const std::string &literal)
{
    if (literal == "nan" || literal == "nanf" ||
        literal == "+inf" || literal == "-inf" ||  //+inf->1e308 * 10(double); -> 42/0
        literal == "+inff" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;

        if (!literal.empty() && literal[literal.size() - 1] == 'f')
            std::cout << "float: " << literal << std::endl;
        else
            std::cout << "float: " << literal << "f" << std::endl;

        if (!literal.empty() && literal[literal.size() - 1] == 'f')
            std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
        else
            std::cout << "double: " << literal << std::endl;

        return true;
    }
    return false;
}

bool ScalarConverter::isChar(const std::string &literal)
{
    if (literal.size() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
    {
        char c = literal[0];
        int i = static_cast<int>(c);
        float f = static_cast<float>(c);
        double d = static_cast<double>(c);

        if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;

        std::cout << "int: " << i << std::endl;

        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << d << std::endl;

        return true;
    }
    return false;
}

bool ScalarConverter::isInt(const std::string &literal)
{
    char *endptr = nullptr;
    long val = std::strtol(literal.c_str(), &endptr, 10);

    if (*endptr != '\0')
        return false;

    if (val < INT_MIN || val > INT_MAX)
    {
        std::cout << "int: impossible" << std::endl;
        return true;
    }

    int i = static_cast<int>(val);

    if (i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else
    {
        if (!std::isprint(static_cast<char>(i)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    }

    std::cout << "int: " << i << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;

    return true;
}

bool ScalarConverter::isFloat(const std::string &literal)
{
    if (literal.back() != 'f')
        return false;

    std::string s = literal.substr(0, literal.size() - 1);
    char *endptr = nullptr;
    float f = std::strtof(s.c_str(), &endptr);

    if (*endptr != '\0')
        return false;

    if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
        std::cout << "char: impossible" << std::endl;
    else
    {
        if (!std::isprint(static_cast<char>(f)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    }

    if (f > INT_MAX || f < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(f) << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;

    return true;
}

bool ScalarConverter::isDouble(const std::string &literal)
{
    char *endptr = nullptr;
    double d = std::strtod(literal.c_str(), &endptr);

    if (*endptr != '\0')
        return false;

    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else
    {
        if (!std::isprint(static_cast<char>(d)))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    }

    if (d > INT_MAX || d < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;

    return true;
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &copy) { (void)copy; }
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) { (void)copy; return *this; }
ScalarConverter::~ScalarConverter() {}


void ScalarConverter::convert(const std::string &literal)
{
    if (isPseudoLiteral(literal))
        return;
    if (isChar(literal))
        return;
    if (isInt(literal))
        return;
    if (isFloat(literal))
        return;
    if (isDouble(literal))
        return;

    std::cerr << "Invalid literal!" << std::endl;
}


