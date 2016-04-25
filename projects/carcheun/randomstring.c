Carolyn Cheung
Quiz2

For the test me function, I first by trying to understand what it was supposed to do. I spent some time
looking it over before I finally figured out that it was supposed to print the 'error' message through
certain conditions. First, the random char given from the function inputChar was supposed cycle through
the letters '[({ ax})]', slowly increasing the 'state' variable each time a letter matched  until it 
reached state 9. Then, after state = 9 was reached, it would print the error message if and only if
the random string produced also said 'reset'.

For development, the inputChar() function was created by using an array of the needed letters '[({ ax})]',
then randomly selecting a number between 0 - the size of the letters array. The random number given would
be the index corresponding to the letter in the letters array. This letter was returned.

The inputString() function was created similarly to the inputChar. The only difference was that instead
of saving just 1 random letter, a string of letters was saved into a string of size 6. The final letter
in the string was '\0', which is the null terminator for c strings. After the randomly generated
string generated randomly per letter was created, it was returned and eventually compared within the
testMe() function.

Iterations ranged seemed to be anywhere from 300 - 2000.