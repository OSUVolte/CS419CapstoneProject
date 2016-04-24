/********************************************************************************************************************************************************
*** Filename: testme.c
*** Author: Aleksandr Balab
*** Class: CS362-400
*** Due date: 4/21/2016
*** Random testing quiz 2
*** Description:  Implement a random tester for the function testme() in testme.c that is capable of printing the error message.
***               You should implement inputChar() and inputString() to produce random values. Write up the development of your random tester
***                and how it finds the error message as randomstring.c.
********************************************************************************************************************************************************/


/*

inputChar()
Creates an array of characters as a c string and randomly selects one of these characters returns that selected character. 

inputString()
Creates an array of characters as a c string and randomly selects 5 of these characters and places them in the array of characters.
It randomizes the chance of characters spelling out "reset" and therefore printing "error" from the testme(). 

The testme() function will call inputChar() and inputString() to receive random characters and strings. It will then check them for specific characters to
be returned in a certain order which will be state 9. Once, state 9 been reached, it will check for a string to be returned as "reset" and print out the error 

State 0 was reached fast, but reaching the "reset" took a while. 

Iteration 9416566: c = z, s = mfqkv, state = 9
Iteration 9416567: c = [, s = udtgf, state = 9
Iteration 9416568: c = k, s = iilng, state = 9
Iteration 9416569: c = d, s = lwmip, state = 9
Iteration 9416570: c = h, s = axwjv, state = 9
Iteration 9416571: c = }, s = ahcst, state = 9
Iteration 9416572: c = y, s = dpcwv, state = 9
Iteration 9416573: c = q, s = reset, state = 9
error flip3 ~/362/4week 161%


*/