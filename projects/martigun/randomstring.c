//
//
// Gunnar Martin
// CS362
// Spring 2016
// Random Testing Quiz 2
//
// To develop my random testing script, I started by first carefully studying the function testMe().
// After studying the function for a while, I found that the different lines of code within the 
// function are run based on three variables: `c`, `s`, and `state`.The program runs in a loop
// until it exits. Each loop, `c` and `s` are reset, but `state` retains its value.
//
// The variable `c` is set using the function `inputChar()` and `s` is set using the function
// `inputString`. The variable `state` is changed when `c` is set to certain values.
// In order to be able to test all the lines in the program, I knew that I'd have to include in 
// `inputChar()` a way for `c` to be set to all of the certain values it needed within testMe() to
// update `state` and move through the function. To do this, I utilized a random number function.
// The design gerenates a random number then return a char to `c` based on that number.
// There are 9 different values of `c` that are needed to update `state` and move through the function.
// So as I chose the different values that could be returned, I made sure to include all 9 of those values.
// In addition to the 9 values ('[', ']', '(', ')', '{', '}', ' ', 'a', 'x'), I included 2 extra characters
// ('$', '#') to make sure the program does not crash when encountering an edge character. Each loop, when
// the function `inputChar()` is run, one of the 11 characters above is randomly returned and assigned to
// the variable `c`. This assures that sooner or later, all necessary values of `c` will be met and the 
// function will be able to move through all of its lines.
//
// The last peice of the puzzle with building this test was to make sure that the variable `s`, which is
// an array of chars, is set to "reset\0". So, within the function `inputString()`, I utilized another
// random number generator to set `s`. Knowing that one of the return values must be "reset\0", but also
// wanting to make sure to test edge cases, I included 3 different char arrays:
// "reset\0", "change\0", "continue\0". Using a random number, one of these 3 char arrays is selected
// every loop and pushed into `s`. Since there is a 1 in 3 chance of getting "reset\0", I knew that
// at some point after all of the certain `c` values had been met and progressed the `state` variable
// through the function, that at some point after that, `s` will eventually be set to "reset\0" and the 
// function will finally terminate.
//
// In my brief testing of my test, I found that after about 100 loops, the function testme() would
// typically have produced all of the correct random variables to terminate.