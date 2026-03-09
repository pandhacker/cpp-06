#include <iostream>

#include "ScalarConverter.hpp"

void	test_converter(std::string str) {
	std::cout << "--- Input: " << str << " ---" << std::endl;
	ScalarConverter::convert(str);
	std::cout << std::endl;
}

int main(int argc, char **argv) {

	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <string>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);

	return 0;
}