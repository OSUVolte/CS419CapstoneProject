/*The inputChar function should return a random non-control ASCII character, so it uses the stdlib rand function to get a random number from 32 to 127 casted to the respective character at that index in the ASCII table. After it gets the ASCII char at that random number index it returns it as ‘c’.
 *
 * The inputString function should return a string of 5 random chars from lowercase letters in the ASCII tables plus a null terminating character. Specifically the rand function needs to pick a random integer between 0 and 25, the function needs to add 97 to get to the lowercase letters in ASCII table, and then it needs to be converted to respective ASCII char for storage in the current string index. Then it returns the string as 's'.
 *
 * To reach the error, the testme function needs to do two things. First, the inputChar needs to return the characters '[', '(', '{', ' ', 'a', 'x', '}', ')', and ']' in order - each time it hits one of the previous characters it increments the state. When the state gets to 9, this is the first step towards reaching the error. Next, the inputString function needs to return the string "reset" and then the error message is displayed. Thus the reason why we need to choose random numbers from the set of printable characters for inputChar and from the set of lowercase characters for inputString.
 *
 * The testme function creates variables and initializes for a counter(for displaying iteration number), a pointer to C string, a char, and an integer representing state. It starts a loop where the counter is incremented, a random char for ‘c’ is found by calling inputChar and a random string is found by calling inputString. Then it performs the series of if statements testing for the target characters listed above in that order and updates state on a match until state reaches 9, and finally keeps iterating until it is given the string “reset". The program will print an error message and exit the program. Since there's 1/95 chance of getting the correct target character on the first nine if statements, and there's 26^5 possible strings that could be returned from the last if statement, it would take many iterations for the program to get to the error message - in my case 7,150,666.*/

