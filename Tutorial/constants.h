#pragma once
#ifndef CONSTANTS_H

#include <algorithm> // for std::min() and std::max()
#include <cmath>     // for std::abs()
#include <cstdint>   // for std::int_fast#_t

// use namespace for constants
namespace constants {
	/*
	 * Raises an integer base to a power.
	 * @param base The value to use as a base.
	 * @param exp The exponent to raise the base to.
	 * @return The value of base to-the-power-of exp.
	 */
	std::int_fast64_t pow(int base, int exp) {
		std::int_fast64_t result{ 1 };
		while (exp) {
			if (exp & 1) {
				result *= base;
			}

			exp >>= 1;
			base *= base;
		}

		return result;
	}

	/*
	 * Checks if the two given doubles are approximately equal.
	 * @param a The first double to check.
	 * @param b The second double to check against the first.
	 * @param absEpsilon The absolute difference.
	 * @param relEpsilon The relative difference.
	 * @return 1 if a and b are almost equal, 0 otherwise.
	*/
	inline bool approxEqual(double a, double b, double absEpsilon, double relEpsilon) {
		// check if the numbers are really close - needed when comparing numbers near zero.
		double diff{ std::abs(a - b) };
		if (diff <= absEpsilon) {
			return true;
		}

		// otherwise fall back to Knuth's algorithm
		return (diff <= (std::max(std::abs(a), std::abs(b)) * relEpsilon));
	}
}

#endif // CONSTANTS_H

