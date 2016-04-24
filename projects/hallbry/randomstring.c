My tester involved me writing two functions.  the first was a input char function that required me to select 10 unique
values. Each value acted as a key that would be used to unlock a if statement to advance the state forward.  I used a pointer to a char array with each of these 10 values inside.  I limited the input domain because the number of combinations involved would be massive and take up a considerable amount of computing time

The second function involved generating a random string.  This would be called until finally the string was equal to reset at which point the program would terminate. 
I originally called a random function on the letters from the alphabet but it took over 6 million simulations until i reached got a result value of reset. I restricted the input domain at this point to only letters with reset. The final char in this array was then set to \0.   This reduced the computation time to a few thousand simulations.
