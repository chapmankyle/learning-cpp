#pragma once
#ifndef IO_H

/* Shows the size of some data types. */
void showSizeofTypes();

/*
 * Reads a number from the command-line.
 * @return The number that was read.
 */
int readNumber();

/*
 * Writes the given value to the standard output stream.
 * @param user The user-supplied value.
 * @param comp The computer generated value.
 * @return An integer denoting if the value is greater than (1), less than (-1) or equal to (0) the computer value.
 */
int writeAnswer(int user, int comp);

#endif // IO_H

