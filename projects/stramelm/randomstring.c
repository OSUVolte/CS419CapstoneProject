Cash Stramel
CS362
Spring 2016
Quiz #2

ERROR MESSAGE FINDING:

The function testme() repeatedly calls inputChar() and inputString()
to generate a single random character and a random string of length 6
including the null terminator.  Additionally, prior to the testme()
call, counter and state variables are initialized with values of 0.

For each iteration, testme() compares the randomly generated characters
to a specifically targeted character for the current state.  When found,
the state is incremented.

Additionally, in each iteration, testme() compares the randomly generated
string to the string "reset".  If the current state is 9 and the string is
"reset", then the error message is printed to the screen and execution
is halted.

TESTER DEVELOPMENT:

For the random character, I used the rand() function to generate a value and
then determined the remainder when dividing that value by 95.  I added that
remainder to 32 for a random integer generation in the range of 32 through 126
which equates to the printable ascii characters.  I cast the integer to a
char and returned it.

For the random string, the random character generation was effectively the same.
The difference is that I targeted only the lower case ascii character range for
no other reason that to speed up test execution.  I could have used the same
range as that used above for the single character.  Even with this reduced range
of characters, my test took ~1.5 MIL iterations.  The key iterations are shown
below.

TEST EXECUTION RESULTS:

Iteration 104: c = [, s = jwomv, state = 0
Iteration 105: c =  , s = chimc, state = 1

Iteration 151: c = (, s = pmsom, state = 1
Iteration 152: c = _, s = lgyux, state = 2

Iteration 227: c = {, s = apifh, state = 2
Iteration 228: c = \, s = hvzul, state = 3

Iteration 275: c =  , s = hcafl, state = 3
Iteration 276: c = 8, s = avynq, state = 4

Iteration 409: c = a, s = thkmz, state = 4
Iteration 410: c = Z, s = hpqdx, state = 5

Iteration 411: c = x, s = jxkoe, state = 5
Iteration 412: c = P, s = fxxkt, state = 6

Iteration 515: c = }, s = mzyqh, state = 6
Iteration 516: c = N, s = kgdpz, state = 7

Iteration 794: c = ), s = upoif, state = 7
Iteration 795: c = r, s = tlxnh, state = 8

Iteration 1026: c = ], s = twpda, state = 8
Iteration 1027: c = 6, s = xgipe, state = 9

Iteration 1463753: c = 7, s = nmsir, state = 9
Iteration 1463754: c = >, s = reset, state = 9
error
