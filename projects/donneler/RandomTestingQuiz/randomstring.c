/********************************************************************************
* Erin Donnelly
* CS362 Software Engineering II
* Description: Implement a random tester for the function testme() in testme.c 
* that is capable of printing the error message.  You should implement inputChar() 
* and inputString() to produce random values. Write up the development of your 
* random tester and how it finds the error message as randomstring.c. Submit 
* testme.c and randomstring.c under your onid directory in class github. (under 
* your onid directory and not under dominion directory).
*
* Documentation:
*
* inputChar() returns a random character from the string 
* " []{}()abcdefghijklmnopqrstuvwxyz"
*
* inputString() returns a null terminated string with 5 random lower case
* characters.
*
* testme() calls inputChar() function to get a random character and the inputString() 
* function to get a random null terminatedstring of 5 chars. Each iteration it prints
* the iteration number, the character recieved and the string received, as well
* as the current state. Depending on the random character and current state, the 
* state will continue to the next state until it reaches state 8. In order to
* proceed to state 9, many iterations must be run as the random string received
* must be "reset\0". Once this occurs, the program prints an error message and 
* exits. As expected, the iteration at which the error message printed varied 
* from run to run. For the transition of the first few states, there is a
* 1/33 chance of printing the character needed to advance. On the other hand,
* each time a random string is generated there are 26^5 or 11,881,376 possible 
* strings, thus the chance of producing the error condition is very slim. Yet
* the code does produce the reset string in a varying number of iterations
* thus indicating the program is indeed printing random strings.
* 
* Sample run results:
* 1 - Iteration 3466745: c = h, s = reset, state = 9
* 2 - Iteration 2271705: c = d, s = reset, state = 9
* 3 - Iteration 22428732: c = h, s = reset, state = 9
* 4 - Iteration 780772: c = ), s = reset, state = 9
* 5 - Iteration 53972035: c = r, s = reset, state = 9
********************************************************************************/

