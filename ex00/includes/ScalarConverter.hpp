#ifndef SCALARCONVERTERHPP

# define SCALARCONVERTERHPP

# include <string>

class ScalarConverter{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ~ScalarConverter();
        ScalarConverter &operator=(const ScalarConverter &copy);

    public:
        static void convert(const std::string str);
};

#endif