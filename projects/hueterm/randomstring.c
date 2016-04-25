/************************************************************************
Michael Hueter (hueterm@oregonstate.edu)
CS 362 Random Testing Quiz 2 -
23 April 2016

The first thing I did was figure out how the error message on line 72 gets called.
The conditions are: the int "state" has to equal 9, and the string of chars "s"
has to read "reset" (more specifically [r][e][s][e][t][\0]). The only way to get
to state 9 is by going through states 0 through 8 first, by having the character
at one point equal '[', '(', '{', ' ', 'a', 'x', '}', ')', and ']', respectively.

With these constraints in mind, I developed the two functions "inputChar()" and
"inputString()" to return a pseudo-random character and string, respectively.

inputChar() was relatively straightforward. I picked a subset of 43 ASCII values
and assigned "randomCharacter" to a random one each time. The list is mostly
arbitrary; I picked enough inputs to generate a diverse set of calls but I
excluded non-printable characters because they wouldn't be observable.

inputString() was a bit more complicated. At first I thought I would generate
strings of different lengths, but because the if statement in testme() tests for
a 6 character string, I thought it might be a justifiable constraint to only
generate random 6 character strings. Secondly, I decided to use inputChar() to
generate random characters in the string so I could reuse the functionality I
already wrote. So I made a for loop which assigns each character randomly; however,
when I tested it with all 5 letters randomly-generated, it seemed like the program
would never stop after many millions of iterations.

To make the test a bit shorter, I introduced an arbitrary constraint to limit
the number of test cases - I made the 0th character set to "r" each time. This
helpful constraint led the program to run between 400k and 6 million iterations
on average, which is a nice timely execution (about 2-4 minutes per run) before
reaching the "error" print statement.

Running gcov indicated I had 100% branch and call coverage and 97.37% of 38 lines
covered. This seems like a good target.

Depending on the requirements, I could improve my tests by letting inputChar()
test more ASCII values, such as everything from 33 to 127 (all printable chars).
I could also remove the 'r' constraint. The tests would take much longer on average,
but it would be more thorough of a random tester.














**************************************************************************/
