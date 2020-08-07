#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "io.h"

/*
 * Greets the user.
 * @param min The minimum number that it could be.
 * @param max The maximum number that it could be.
 */
void greeting(int min, int max) {
	std::cout << "Hello there!\n\nLet's play a guessing game, where you try to guess the number I am thinking ...\n";
	std::cout << "Hint: it's a number between " << min << " and " << max << " (inclusive)\n\n";
	srand(time(nullptr));
}

/*
 * Generates a random number between the min and max given.
 * @param min The minimum number.
 * @param max The maximum number.
 * @return A random number.
 */
int generateRandomNumber(int min, int max) {
	return rand() % (max - min + 1) + min;
}

/*
 * Starts the guessing game.
 */
void start() {
	int minNum{ 10 };
	int maxNum{ 40 };

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
