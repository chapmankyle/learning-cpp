#include <iostream>
#include "quizzes.h"

void chap4quiz3() {
	// declare two doubles
	double x{};
	double y{};

	std::cout << "Enter a double value: ";
	std::cin >> x;
	std::cout << "Enter a double value: ";
	std::cin >> y;

	// get operator
	char op{};

	std::cout << "Enter one of the following: +, -, *, or /: ";
	std::cin >> op;

	double result{};

	// check operator
	if (op == '+') {
		result = x + y;
	}
	else if (op == '-') {
		result = x - y;
	}
	else if (op == '*') {
		result = x * y;
	}
	else if (op == '/') {
		result = x / y;
	}
	else {
		return;
	}

	std::cout << x << ' ' << op << ' ' << y << " is " << result << '\n';
}

bool passOrFail() {
	static int passes{ 3 };

	// returns true the first 3 times the method is called, false thereafter
	return (--passes >= 0);
}

void chap6quiz1() {
	std::cout << "Enter a positive number: ";
	int num{};
	std::cin >> num;

	if (num < 0) {
		std::cout << "Negative number entered. Making positive.\n";
		num = -num;
	}

	std::cout << "You entered: " << num << '\n';
}

void chap6quiz3() {
	std::cout << "User #1: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #2: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #3: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #4: " << (passOrFail() ? "Pass\n" : "Fail\n");
	std::cout << "User #5: " << (passOrFail() ? "Pass\n" : "Fail\n");
}
