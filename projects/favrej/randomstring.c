Jarrad Favre
Ranom Test Quiz
randomstring.c

For the inputChar function, I declared two variables. First was a character
array, chrArr, hardcoded with 9 the characters in the condition statements in 
the testme function. The second variable is an integer named rNum that is 
assigned a random number between 0-9. The function concludes by returning one of
the 9 characters in chrArr by invoking the element location according to the 
random number assigned in rNum.

For inputString, I again declared two variables. This time instead of a 
character array named wordArr, I created a string array hardcoded with 7 six-
letter words, one of those words being "reset". The second variable is also an 
integer named rNum, but is assigned a random number between 0-7. The function 
will conclude by returning one of the hardcoded words in wordArr by invoking
the element location according to the random number assigned in rNum.

In order to meet the condition to execute the error message, the state variable
must equal 9 and s, when calling inputString, must be assigned the string 
"reset". In order for s to be assigned "reset", the correct random number
must be produced in the inputString function to return and assign to s. For
state to be equal to 9, it will require a little more effort. At the beginning
of the testme function, state is assigned to 0 then enters in a while loop. In 
order for it to eventuallyget assigned 9, it must first way for c to be assigned 
'[' from inputCharfunction, where state where be assigned 1. Then c will have to 
wait tillc is assigned '(' for it to be assigned 2. This pattern continues in 
waiting for '{', then ' ' (space), then 'a', then 'x', then '}', then ')', and 
finally ']' to be assigned 9. Once it is assigned 9, it now has to wait for s to 
be assigned the string "reset" to print the error message and exit at a value of 
200.  
