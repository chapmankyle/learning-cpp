#include <iostream>
#include <cstdlib>  // for std::rand() and std::srand()
#include <ctime>    // for std::time()

#include "guess.h"
#include "io.h"

/*
 * Greets the user.
 * @param min The minimum number that it could be.
 * @param max The maximum number that it could be.
 */
void greeting(int min, int max) {
	std::cout << "Hello there!\n\nLet's play a guessing game, where you try to guess the number I am thinking ...\n";
	std::cout << "Hint: it's a number between " << min << " and " << max << " (inclusive)\n\n";
}

/*
 * Generates a random number between the min and max given.
 * @param min The minimum number.
 * @param max The maximum number.
 * @return A random number.
 */
int generateRandomNumber(int min, int max) {
	static constexpr double fraction { 1.0 / RAND_MAX };  // only calculates value once

	// throw away first random number (bug with Visual Studio)
	std::rand();

	return min + static_cast<int>((max - min + 1) * (std::rand() * fraction));
}

void start() {
	int minNum{ 10 };
	int maxNum{ 40 };

	// set seed
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	greeting(minNum, maxNum);

	int comp{ generateRandomNumber(minNum, maxNum) };
	int user{ readNumber() };

	int result{ writeAnswer(user, comp) };

	// repeat until the user guesses correctly
	while (result != 0) {
		user = readNumber();
		result = writeAnswer(user, comp);
	}
}
