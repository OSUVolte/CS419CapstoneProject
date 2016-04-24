In this quiz we are making a random tester that satisifes of values until it unlocks a error message at the very end.  We are required to write the details for two functions 
to accomplish this. 

The first function was a input char function that would return a char. To unlock the error statement, this char had to equal a series of 10 values. I therefore created a array
with each of these 10 values. A random number generator would then pull a random char from this array and return Each value acted as a key that would be used to unlock a if statement
 to advance the state forward.  This worked well because the input domain was limited to key values. If it wasn't, the number of values would be much larger and it would take more 
time to process. 

The second function involved generating a random string. This was evaluated as the last of the if statements.  It was looking for a string of reset, and then it would access the error statement
and end the program. I originally called a random function on the letters from the alphabet but it took over 6 million simulations until I reached got a result value of reset. 
I restricted the input domain at this point to only letters with reset. The final char in this array was then set to \0.   This reduced the computation time to a few thousand simulations.

