/************************************************
* CS362                                         *
* Tatsiana Clifton                              *
* Random Testing Quiz 2                         *
*************************************************/

/*To implement random tester, the function testme() was analyzed.
This function compare a character got from the function inputChar with
the certain character. If a character got from the function inputChar 
matches this certain character and the variable state was not 
incremented yet, state is incremented. Once the variable state
equals 9, characters in the string got from the function inputString
are compared with 'r', 'e', 's', 'e', 't' accordingly. In other words,
if the string got from the function inputString is 'reset' and the 
variable state equals 9, 'error' is printed and program is exited.

inputChar()
This function generates and returns a random ASCII printable character.
It a character in range from 33 to 96. On the one hand,
it ensures that characters that are required to change the state
will be eventually generated. On the other hand, it ensures
that other characters may be generated also.

inputString()
This function generates and returns random string of five characters
terminated by the null character. However, the decision was to narrow
the choice of characters in order to ensure higher probability to 
get the string 'reset'. Thus, the possible characters include 27
characters with three times repeated 'reset' plus some other characters.

Results
The function testme() is capable of printing error message. Based on 10 runs
of the program the number of iterations varies from 971 to 15299. The first
run returned error after 3651 iterations. The test coverage showed 
the following results:

Lines executed:97.37% of 38
Branches executed:100.00% of 52
Taken at least once:96.15% of 52
Calls executed:100.00% of 10

We can see that 97.37% of 38 lines were executed. It means 37 lines were 
executed. The branch coverage is 100% that allows to make a conclusion
that the function was tested rather thoroughly.
*/
