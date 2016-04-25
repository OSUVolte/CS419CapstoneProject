/***************************************************************************************************************************
** filename randomstring.c
** author: Canids Pike
** date: April 22, 2016
** description: random testing quiz Quiz#2
**Description: Implement a random tester for the function testme() in testme.c that is capable of printing the error message. 
** You should implement inputChar() and inputString() to produce random values. 
**  Write up the development of your random tester and how it finds the error message as randomstring.c. 
Submit testme.c and randomstring.c under your onid directory in class github. (under your onid directory and not under dominion directory).
********************************************************************************************************************************/

inputChar()
Upon evaluation of the exisiting functions. It is apparent that the input domain of c comes from the domain of [{( ax)}] , therefore, when developing the char inputChar()
funtion, the available domain input to randomly chose from was limited to just those characters and not the set of all english characters.

*inputString()
For the char *inputString() function, it was not as obvious. When looking at the testme() function the string is coming from the domain set of low letter english 
language letters. When using that as the input domain to randomly chose from it is difficult to get the error message to trigger. The second attempt
was to limit the domain again, the second set was the low letter from e-t, again this domain input set was too large to trigger the error.
The final and most succesfull was to limit the input domain to the letters reset. These are the letters that are needed to trigger the error. 

It is noted that the error will not occur until state == 9. If the state, is 0-8 and s = reset the error will not trigger. It is possible for that 
situation to occur.

The error was triggered on itteration 2471 on run #1
Iteration 2471: c = ), s = reset, state = 9
Futher testing show the error is caught at a random itteration.
Results of 10 runs: 2471, 89, 909, 287, 137, 2219, 243, 153, 691, 19008

gcov analysis - the random test appears to give decent coverage
Lines executed:97.56% of 41  - retun 0; in main() is never executed.
Branches executed:100.00% of 52
Taken at least once:96.15% of 52 
Calls executed:100.00% of 10


