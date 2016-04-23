/*
Lauren Crees
CS 362
Quiz 2 - Random Testing

Rewriting inputChar()
	ASCII printable character codes: 32 - 126
	Choose a random number between and including 32 - 126 and return.

Rewriting inputString()
	Limiting the size of the string to 6, including the null character, because testme() only cares about the first 6 characters in a string.
	Take 1: Choose a random character for each letter in string using inputChar().
	Take 2: Choose a random character for each letter in string from the lowercase English alphabet.
	End string with the null character.

Testing testme()

What's being tested?
	How the program gets an error message.  The testme() function is expected to fail.

Random Tester
	The random inputs of a character and a string are expected to handle ASCII printable characters.  Looking at the testme() code, not all these values will be interesting. The various parentheses and the characters ' ', 'a', 'x', 'r', 'e', 's', 't', and '\0' seem to be of the most interest.  However, the function should be able to handle all English alphabet letters as well as many keyboard symbols.
	It may take many iterations, but the code should eventually stop and exit with an error message.
	In testme() I moved the line to print the iteration, character, string, and state to the line before the error message so that there wasn't overwhelming output while the function ran.

Running the Test
	Take 1: After attempting to find the bug randomly, it seems plausible that with enough iterations it would be found.  However, that seems to be a very high number of iterations.  Reaching a point where the state = 9 happened quickly, however, reaching the problem string would have taken significantly more iterations.

	Take 2: After adjusting inputString() it took fewer iteration to get to the error.  The possible variety of strings was severely limited when inputString() was adjusted.  However, if this program eventually took user input, the lowercase English alphabet would be a highly likely set of characters to use.  Perhaps also including the uppercase English alphabet would be a good test as well.
		Trial 1: Iteration: 1603363
		Trial 2: Iteration: 20662130
		Trial 3: Iteration: 4747089
		Trial 4: Iteration: 12101892
		Trial 5: Iteration: 3331825
		Trial 6: Iteration: 9835052
		Trial 7: Iteration: 398956
		Trial 8: Iteration: 12232328
		Trial 9: Iteration: 10299563
		Trial 10: Iteration: 1622303
		Average Iterations: 7683450
		
		String that causes error: "reset\0"
*/