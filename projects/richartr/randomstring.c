/***********************************
* Name: Trent Richardson
* Ransom Testing Quiz 2 - randomString.c
* CS362-400
***********************************/
Test Runs:
#1
Iteration 4095653: c = l, s = pshil, state = 9
Iteration 4095654: c = `, s = syudt, state = 9
Iteration 4095655: c = B, s = okayd, state = 9
Iteration 4095656: c = H, s = vsmxz, state = 9
Iteration 4095657: c = /, s = ajyfc, state = 9
Iteration 4095658: c = :, s = jdmhb, state = 9
Iteration 4095659: c = ;, s = xtbsy, state = 9
Iteration 4095660: c = I, s = emqch, state = 9
Iteration 4095661: c = -, s = doxjw, state = 9
Iteration 4095662: c = \, s = slbsv, state = 9
Iteration 4095663: c = A, s = reset, state = 9
error

#2
Iteration 44636: c = ,, s = kpqcz, state = 9
Iteration 44637: c = -, s = qgqmz, state = 9
Iteration 44638: c = P, s = azlyc, state = 9
Iteration 44639: c = ^, s = bxwod, state = 9
Iteration 44640: c = N, s = jyppy, state = 9
Iteration 44641: c = X, s = baawq, state = 9
Iteration 44642: c =  , s = jquvs, state = 9
Iteration 44643: c = +, s = dttmz, state = 9
Iteration 44644: c = t, s = ncihs, state = 9
Iteration 44645: c = Q, s = reset, state = 9
error

inputChar() - This function returns a random character between 32 and 126 (ASCII character).

inputString() - This function creates a character array to make a five letter string with a null terminator.
                Only lowercase characters are used to spell to randomize and spell 'reset' to produce the error
                message.


testme() - calls inputChar() and inputString() to receive random characters and strings. The function checks
            the characters to ensure a certain order and a state of 9.  Once this state is reached, the
            function checks the string for 'reset'.  Once 'reset' is randomly generated, the error occurs.

State 9 was reached very fast, but the 'reset' took anywhere from fairly quick to extremely long.  The random
testing is a great tool to run a ton of tests and inputs; however, time-wise, it can be quite consuming.
