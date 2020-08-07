#include <iostream>
#include "io.h"

void showSizeofTypes() {
	std::cout << "bool:\t\t" << sizeof(bool) << " bytes\n";
	std::cout << "char:\t\t" << sizeof(char) << " bytes\n";
	std::cout << "wchar_t:\t" << sizeof(wchar_t) << " bytes\n";
	std::cout << "char16_t:\t" << sizeof(char16_t) << " bytes\n";
	std::cout << "char32_t:\t" << sizeof(char32_t) << " bytes\n";
	std::cout << "short:\t\t" << sizeof(short) << " bytes\n";
	std::cout << "int:\t\t" << sizeof(int) << " bytes\n";
	std::cout << "long:\t\t" << sizeof(long) << " bytes\n";
	std::cout << "long long:\t" << sizeof(long long) << " bytes\n";
	std::cout << "float:\t\t" << sizeof(float) << " bytes\n";
	std::cout << "double:\t\t" << sizeof(double) << " bytes\n";
	std::cout << "long double:\t" << sizeof(long double) << " bytes\n";
}

int readNumber() {
	std::cout << "You : ";

	// get number from command-line
	int x{};
	std::cin >> x;

	return x;
}

int writeAnswer(int user, int comp) {
	std::cout << "Me: ";

	if (user < comp) {
		std::cout << "Too low\n\n";
		return -1;
	}
	else if (user > comp) {
		std::cout << "Too high\n\n";
		return 1;
	}
	else {
		std::cout << "Correct!\n";
		return 0;
	}
}
