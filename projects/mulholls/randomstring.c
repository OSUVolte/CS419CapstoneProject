

Author: Sean C. Mulholland
Assignment: randomstring.c/testme.c
Description: Implement inputChar() and inputString() in testme.c to produce random input variables.

inputChar(): 
I implemented random character in a pretty straightforward manner after I 
tried to implement a function to randomly assign bits to the variable c 
that represented the random character. After messing with some bit 
operators I was unfamiliar with, I realized that by picking a random 
character (i.e. a random Byte) the bits would be random already. So I used
the rand() function to produce a random character. After further reflection
, I realized the only range of numbers for a single byte is 2^8 and even 
though overflow wouldn't really affect the character, my final random 
character creation was rand() % 256 to produce a random character.

inputString():
I had originally planned on just calling inputChar(), and filling in a 
randomly lengthed string in generating the string but after my first run I
found that my program was reaching the hundreds of thousands of iterations
and wasn't terminating even though the possibility existed. I decided to 
define my string's max length to be 6, because the conditionals never 
checked any higher than string index 5. I promptly produced a segfault 
because my strings were more often too short than the correct length so the
program was checking for indices that weren't there. This could be a bug in
the test function (depending on the application used), so I noted it and 
set my random string length to always be 6. 
I was still getting really high counts and a non-terminating test because 
there were 256 options for each of the 6 characters creating 256^6 total 
possible test strings, where the test strings could be repeated. I decided 
that most of these tests would be unneccessary since our conditionals 
checked for 4 specific characters ("rest"). Since the conditionals were 
checking for state 9 and checked by character to see if the c-string was 
"reset" I decided using only the 4 possible letters 'r', 'e', 's', and 't' 
was a reasonable choice. If a single letter wasn't in order, the check 
would fail and the print statement wouldn't execute.
So to create a random string, I picked each character from "rest" one at a 
time randomly and put it at each index. When I ran the test this time, the 
iterations were down into the thousands and the test finally terminated.

gcov:
I compiled and ran the program with the coverage option and looked at the 
coverage with GCOV. The testme() function only executes once as expected, 
but every if statement gets run the same amount of times as the number of 
iterations shows on termination. Several lines of the last conditional are 
only checked a number of times, and the print statement and exit statement 
are only run once as expected.

I believe this is a worthwhile random test, because the conditionals 
evaluate false if the characters tested are not equal. So any character 
that's not equal should yield the same result. The conditionals to get to 
state 9 check a wide range of values, so I think generating any random 
character meets the intent. For the strings the constraints I put on the 
"randomness" still create a random string. It was limited to ensure the 
random string could be tested reasonably, and again each character is 
evaluated as true if the characters are equal, or false if they aren't 
equal. So by limiting the letters to only "rest" we still can check the 
simple condition of equal or not.
