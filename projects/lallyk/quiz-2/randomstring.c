/*
Kara Franco
cs.362-400
Quiz 2: Random Testing

For this quiz, I first inspected the function testme() to understand what it does and how it produces our wanted outcome,
an error message. From stepping through the function, I found that the error is not printed until the state reaches 9 and 
the string "reset" is returned from inputString(). 
 
The function inputChar() was implemented to randomly return printable ASCII character codes. Each of these characters, "[{( ax)}]",
are needed to get from one state to another. The final state 9 is acheived by c (the value returned from inputChar()) returning a "]". 
This is the ultimate goal of inputChar(). 

The function inputString() was implemented to randomly return a six chararacter string that contains the letters "etrs" in some 
random combination. The error message is printed when we are in state 9, and s (the value returned from inputString()) returns the 
word "reset". The ultimate goal of inputString is to return the word "reset".

When inputChar() and inputString() are implemented with the testme() function the desired outcome is acheieved, an error message that is 
printed and an exit code of 200. By typing echo $?, I saw that the exit code was 200. In the initial run, State 9 was reached at iteration 421
and the value of s was "reset" at iteration 1286. Out of curiousity, I ran the program again, and State 9 was reached at 773 and "reset" 
was returned at iteration 1624. From these results we can see that this implementation of inputChar() and inputString() produce the desired 
error message. 
*/  