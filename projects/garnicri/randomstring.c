//Rick Garnica
//Random testing quiz2
//CS 362

//inputChar function:  generates a random character from an array of characters, a-z, as well as brackets and parentheses 

//inputString function:  generates a random five-letter string of lower case values

To get to the error message, the test runs through a series of checks, first checking the char value and the current state.  When I ran the test, the char function generated the left bracket first and thus the next state was entered.

Each time the char value changes, the state changes until state 9 is reached.  The only way for the error message to occur is when the string spells out the word “reset.”  In this case, it took over 1.11 billion iterations to finally reach the end.

//end result:
Iteration 11198413: c = b, s = reris, state = 9
Iteration 11198414: c = ), s = htmus, state = 9
Iteration 11198415: c = y, s = asnpb, state = 9
Iteration 11198416: c = a, s = qemkp, state = 9
Iteration 11198417: c = g, s = btowx, state = 9
Iteration 11198418: c = }, s = pqujy, state = 9
Iteration 11198419: c = r, s = dhhpe, state = 9
Iteration 11198420: c = t, s = reset, state = 9
error flip3 ~/SE2 136% 
