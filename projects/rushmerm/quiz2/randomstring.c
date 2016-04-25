/**************************************************************************************************
* Mark Rushmere
* CS 362
* Quiz 2
*
*
* The random character generator genrerates a random integer between 0 and 127.
* It then type casts the integer into a char so that all of the ASCII characters can
* be produced.
*
* The random string generator allocated space for a string of 6 characters.
* Then a random number between 101 and 116 is generated and cast into a char for 
* the lower case letters between 'e' and 't'. These lower case letters are put into the first 5 positions
* of the string and the last position is '\0'
*
* Finally, I added a second randomly gererated number between 0 and 2^20 
* If the number is equal to 0, I set the return string to reset to make sure that the test 
* will produce an error. The probability that the random string will be reset and that the second 
* random number is 0 are both 1 in 1048576.
**************************************************************************************************/
