#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cmath>

ScalarConverter::ScalarConverter(){
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy){
    (void)copy;
}

ScalarConverter::~ScalarConverter(){
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy){
    (void)copy;
    return (*this);
}

std::string printChar(int i){
    std::string res[2];

    if (i < 0)
        return ("impossible, too low");
    else if (i < 32 || i == 127)
        return ("non printable char");
    else if (i > 127)
        return ("impossible, too high");
    std::cout << static_cast<char>(i);
    return ("");
}



void    printStrange(std::string str, int e){

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: "<< str << (e == 1?"f":"") << std::endl;
    if (e == 2)
        str.erase(str.size() - 1);
    std::cout << "double: "<< str << std::endl;
    
}

void    charHandle(std::string str){
    char c = str[0];

    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void    intHandle(std::string str){
    int i;
    std::stringstream ss(str);

    ss >> i;

    if (ss.fail()){
        std::cout << "Impossible Int detection" << std::endl;
        return ;
    }

    std::cout << "char: " << printChar(i) << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}


void    doubleHandle(std::string str){
    double d;
    
    std::stringstream ss(str);

    ss >> d;

    if (ss.fail()){
        std::cout << "Impossible Double detection" << std::endl;
        return ;
    }

    std::cout << "char: " << printChar(d) << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << static_cast<float>(d) << ((d - std::floor(d) != 0) ? "" : ".0") << "f" << std::endl;
    std::cout << "double: " << d << ((d - std::floor(d) != 0) ? "" : ".0") << std::endl;
}


void    floatHandle(std::string str){
    float f;
    
    str.erase(str.size() - 1);
    std::stringstream ss(str);

    ss >> f;

    if (ss.fail()){
        std::cout << "Impossible Float detection" << std::endl;
        return ;
    }

    std::cout << "char: " << printChar(f) << std::endl;
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << f << ((f - std::floor(f) != 0) ? "" : ".0") << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << ((f - std::floor(f) != 0) ? "" : ".0") << std::endl;
}

int isStrange(std::string str){
    if (str.compare("inf") == 0 || str.compare("-inf") == 0 || str.compare("nan") == 0)
        return (1);
    if (str.compare("inff") == 0 || str.compare("-inff") == 0 || str.compare("nanf") == 0){
        str.erase(str.size() - 1);
        return (2);
    }
    return (0);
}

void    ScalarConverter::convert(const std::string str){

    int e = isStrange(str);
    if (e)
        printStrange(str, e);
    else if (str.length() == 1 && !isdigit(str[0]))
        charHandle(str);
    else if (str[str.length() - 1] == 'f')
        floatHandle(str);
    else if (str.find('.') != std::string::npos)
        doubleHandle(str);
    else
        intHandle(str);
}
