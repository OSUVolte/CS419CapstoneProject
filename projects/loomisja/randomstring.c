/*******************************************************************************
** Program Filename: randomstring.c
** Author: Jason Loomis
** Date: 4/24/16
** Description: CS 362, Quiz 2: Random Testing
*******************************************************************************/

Quiz 2 provides a simple state machine algorithm that changes state based on the value of a character provided to the algorithm; additionally, the algorithm inspects a sequence of characters in a string and halts on an error condition for a particular sequence of characters.

The objective of Quiz 2 was to implement the random character and string generators for use with the testme() function and, via random testing, produce the error message.


DEVELOPMENT

Inspecting the algorithm, the state machine has 9 states, 0 through 9. The algorithm is initialized to state 0. The change of state is triggered when the variable c contains a particular trigger character when the system is in a particular state. For the state transition from state 0 to state 1, the trigger character is '[' when the system state is 0. Subsequent trigger characters for each successive state are (, {, (space), a, x, }, ), and ].

The system also inspects a character string in variable s, looking for the null-terminated sequence "reset\0". If the algorithm finds this sequence and the system state is 9, an error message is printed and the algorithm exits.

Armed with this knowledge of the system under test, it would be very simple to define a fixed unit test sequence that would produce the error message. However, the purpose of the quiz was to implement random testing. To that end, I implemented the inputChar() and inputString() functions to populate the c and s variables, respectively, in a random fashion for the state machine algorithm.

inputChar() was defined to generate a random character, and inputString() was defined to generate a random null-terminated string of characters. Both functions make use of the rand() function to generate pseudo-random input values. The possible input space for the state machine algorithm could be all single-byte characters and single-byte character strings; however, for the sake of efficiency, I chose to limit the characters in the input space of the random tester to the specific set of characters that trigger the state changes within the algorithm (for both the characters used by inputChar() to generate the random character and by inputString() to generate the random string).

The characters from which inputChar() chooses are defined in the CHARSET constant character array. The characters chosen are the characters that trigger the state changes in the algorithm:

const char CHARSET[] = { ' ','(',')' ,'[' ,']' ,'a' ,'x' ,'{' ,'}' };

inputChar() simply generates a random number index between 0 and (one less than) the length of CHARSET and outputs whichever character is at the index.

inputString() is somewhat more complicated. inputString() generates a random string of the length specified by the #define STRINGLENGTH. For this testing, STRINGLENGTH was chosen to be 6 (the number of characters inspected by the state machine algorithm). inputString() selects STRINGLENGTH characters from those defined in the array STRINGSET. The STRINGSET array contains the 5 distinct characters that the algorithm is checking:

const char STRINGSET[] = { '\0','e','r','s','t' };

The characters are chosen by the same random fashion as they are in the inputChar() function.

A global character array randomString[], of length STRINGLENGTH+1 is defined and used by inputString() to contain the randomly generated character string. I chose to use the global variable instead of using malloc() to allocate a new buffer because the testme() function does not include a call to free() to deallocate strings allocated by inputString(). That being the case, if malloc were called repeatedly over the course of a long testing session, it is possible that the system running the test could exhaust its available memory. To avoid this condition, the global variable is reused with each testing iteration.

The random string generated to populate randomString[] consists of some permutation of the characters in STRINGSET, and is always terminated with a null-character to ensure that the test code has a valid string to be printed by the printf statement. Due to the nature of null-terminated strings, if inputString() generates a permutation of a string with nulls in it (i.e. prior to the end of the array), printf only prints the characters up to the null terminator.


FINDING THE ERROR MESSAGE

The random test values generated to test this algorithm are targeted at the specific trigger values used by the algorithm. Since the state ratchets up (i.e. increases monotonically) with each trigger character (that is, each trigger character associated with the particular state), inputChar() will eventually produce the sequence of characters to work through all 9 of the system states. The value of the random string is unimportant until the algorithm reaches state 9. Once the algorithm is in state 9, its inspection of the string generated by inputString() will allow it to hit the error message if the string contains the specific sequence "reset\0". The test code in inputString() generates permutations of 6-character strings containing only the specific characters found in "reset\0". There are 5^6 = 15625 possible permutations, a relatively small number; the random permutations find the appropriate sequence fairly quickly and thus produce the error message.