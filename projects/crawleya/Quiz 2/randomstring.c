/* Alisha Crawley-Davis
 * CS 362 Quiz 2
 * Write up of development of random tester
 * and how it finds the error message
 * 4/22/2016
 */

/* inputChar() was implemented to produce random characters. Becuase the assignment was focused on making
 * input that was capable of printing the error message, I limited the input domain of possible characters
 * to just the lower case letters and the brackets and the space. The function returns a random character
 * from one of the following characters: abcdefghijklmnopqrstuvwxy z{}[]()
 */

/* inputString() was impemented to produce a random string of length 6 (5 characters and the null
 * terminator). The characters were randomly chosen from the lower-case letters -
 * abcdefghijklmnopqrstuvwxyz. Further, I only tested strings of length 6 (including the null
 * terminator). Again, I limited the input domain to strings of length 6 with lower-case characters 
 * because the assignment was focused on input that would return the error message.
 */

/* Running the program with gcov showed that there was 100% line coverage of the functions and
 * 97.14% line coverage of the entire program. (This is because the line in main "return 0;" could never
 * run, as testme() either remains in an infinite loop or exits the program.)
 */

/* The random input was good enough to get full coverage of the testme() function. It quickly
 * arrived at state = 9. There was a 1 in 33 chance that each iteration would produce the input to get
 * from the current state to the next state. Note that this probability would have increased if I had
 * limited the input domain even further, say to just the characters {}(){} ax.
 */

/* Once state was equal to 9, then the value of s started to matter. If it was not "reset\0" then 
 * the while loop would just increment. If it was "reset\0" the error message would display and 
 * the program would exit. I limited the input domain of s in order for the program to run quickly 
 * and still meet the requirements of the assignment. I could have also tested different lengths of s
 * and increased the number of possible characters each part of s could be.
 */

