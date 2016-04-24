/*
                          RANDOM TESTER FOR TESTME()


The general architecture of the testme() function consists of a while loop that
iterates over random test cases, i.e. one test case per iteration,  until a
specified sequence of test cases have been generated which causes the error
message to print and the function to exit.  The test cases are organized into
two general categories, a character sequence test suite and a string pattern test
suite.  The character sequence test suite must be completed before the string pattern
test suite is enabled.

Character Sequence Test Suite:
This test suite consists of 9 test conditions that must be completed in a specific
order.  Each test condition defines a target character that a randomly chosen
character must be equal in order to satisfy the test condition.  The random character
is chosen from a set of 9 possible characters, each with an equal probability of getting
chosen.  Therefore, for the test condition that is currently active there is
a 1 in 9 probability that the test condition will be satisfied. Once satisfied, the
next test condition that looks for a different target character is enabled.  This
continues until all 9 test conditions are completed.   On average, this will take
9*9 = 81 iterations.  Once completed, the string pattern test suite is activated.

String Pattern Test Suite
The string pattern test suite consists of only one test condition, i.e. a string
of five randomly generated characters must be equal to "reset".  Since only 4 unique
characters are in reset {'r', 'e', 's', 't' }, each character in the string is
randomly chosen from 1 of 4 characters.  Since the characters in the string are
not independent from each other, the probability of generating the string "reset"
is 4*4*4*4*4 = 1024.   Therefore, on average reset will be generated once in every
1024 loop generations.

The average number of iterations required to generate the error message will be
81+1024 = 1105 iterations.

 */


