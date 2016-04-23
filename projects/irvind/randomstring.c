/*---------------------------------------
# Brett Irvin
# 4/22/16
# CS362_400 Software Engineering II
# Quiz 2--randomstring.c
*---------------------------------------*/

The testme() function that we were asked to generate random input for is designed to run until
both the 'c'/state and 's' variables contain certain values.  For an error to be triggered, the state
needs to reach 9 and the 's' variable must contain a string that spells "reset"; only when these 
two conditions are met will the error trigger and the loop end.  Since the state increments automatically
based on 'c's value, my main focus in producing values for both 'c' and 's'.

inputChar() function
Looking at the testme() function, I looked at all of the possible values for 'c'.  In test me(), the state only 
increments when c is equal to [({ ax})], so that's what I based my random input on for inputChar.  

inputString()
Again, looking at testme(), the 's' variable needs to spell "reset" to successfully flag an error and end the
loop.  Working from that condition, I set up a simple random string generator to generate 5-character strings, 
with the characters 'rtes' as the potential values to use when constructing a string, since those are the letters 
needed to eventually spell 'reset.' The final addition to the string generator was a null terminator for the c string.

Overall thoughts:
I tested this code a total of 10 times on flip, with the results listed below.  This design seems to end the loop fairly quickly,
which might actually be a bad thing.  It would be easy to force testme() to run through more iterations by adding additional
characters into the test arrays for 'c' and 's'.

Test, and number of iterations:
------------------------------
Test 1: 354 
Test 2: 2744
Test 3: 683
Test 4: 397
Test 5: 7891
Test 6: 1114
Test 7: 4013
Test 8: 2520
Test 9: 4594
Test 10: 1315

