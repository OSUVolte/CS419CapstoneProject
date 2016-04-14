/*
Brandon Swanson -- Random Testing Quiz 2

The development of the two random generations function began with a 'white-box' analysis of the testme() function.  Its behavior was affected by a character and a c-string.
I tried to establish what the range of those inputs was expected to be and what range of parameters could be tested in a reasonable amount of time.
These were my observations
  * The char 'c' was tested against not alphanumeric characters
  * The string ‘s’ was tested against a 5 character long c-string
    - A shorter string could cause undefined behaviour (array out of bounds)
    - A longer string will never trigger the true state
  * The error message will print when state == 9 and 's' == “reset”
  * state will unavoidably monotonically increase from 0 to 9 given random input within the ASCII range and once it reaches state 9 it will inextricably remain so.
    - Therefore the combination of the two variables (c,s) is irrelevant and there will be no need to bias towards specific combinations

With these observations in mind I decided to generate 'c' from the entirety of the ASCII range (0-255) and to only generate 5 char c-strings for 's'.  My first implementation I generated the string 's' across all possible ASCII values,  but this proved to be too exhaustive and it is likely an unimportant superset because the last conditional (s[n] == ‘x’ && … ) only test against lowercase alpha characters.  To bias towards valid inputs but not entirely omit the domain of strings containing values outside the range of ‘a’-’z’ I added a random bias value that provides a 5% chance on each character to choose from entire ASCII range.

This system produces the error message and gave good statement and branch coverage.  Its efficiency at testing randomly generated cases was severely limited by the speed at which it could output the iterations information to the console so during development of the test I either disable the print statement or only printed on iterations divisible by a specified constant

*/