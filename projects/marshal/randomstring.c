/*
Alex Marsh
CS362 Quiz 2


After viewing the lectures and udacity course for this week, I felt that I had a good handle on random testing.  However, this quiz proved that one can never have a good grip until they try.  When approaching this quiz I found myself hung up on questions of how much randomness is enough or too much? 

When creating inputChar I initially thought I would simply select a random number from the ascii table (decimal 40 - 125).  After some more thought I assumed this would be over kill. Instead I opted to look further at the preconditions of the test.  In testme the characters needed from inputChar include the alphabet and the characters (,),[,],{, ' ',and }. Inorder to include more randomness I created an array of both capital and lower case alphabet letters.  On the end of the array I included the potentially needed characters. To introduce more randomness one could include other character such as ?, !, and &. 

inputChar then creates a random number from 0 to 58, which is exactly the indexes of the possibleChar array. The random number is then used to select a character from possibleChar and assign it to the variable randomChar which is returned. Though this approach may not give the most random input, it meets the preconditions and has quite a bit of randomness. 

inputString follows a similar approach.  I again thought I might select a random character from the ascii table, but chose against it.  It would have been possible to again create an array of all upper and lower case letters, but this would have had my computer running a long time.  Had I had more time, this might be a better approach.  Instead I opted to create an array with the accepted characters (r,e,s,t). I created a character array with the word 'reset'. I then created a string with the length of 6 characters to return.  Again, another approach for randomness might have been to create a string with a random length within a range. 

Within a for loop I created a random number within the range of 0 to 4 (the length of my array).  I used the random number as an index for my possibleChar array and assigned the character in that spot to the corresponding place in my string.  Here the randomness adds complexity as it must select the right random number in 0,1,2,3,4 order. 

At the end of my function I assign a null to the end of the string since c demands all strings include this. The string is then returned. Potentially I could have a flag indicating whether or not to include the null and thus allow the function to proceed, but this might just add complexity for complexities sake and not to benefit testing.

When I compiled and ran testme.c on flip the program was able to get an error between 1000 and 1500 iterations.  

*/