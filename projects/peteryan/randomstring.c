/*
Ryan Peters
04/23/16
Quiz 2

I started by implementing inputChar().  I created an array that contained the characters 
that testme() was testing for.  inputChar() returns a random character from the array, so
only characters that could advance the state would be returned.  I tried a similar approach
for inputString().  

First, I created a character array that was the string testme() is looking for.  Then I made 
another character array where each element was a random element from the first array, this 
ensured each element in the random string was from the original string.  The fuction returned 
a pointer to the random string.  Since the random string was declared in inputString() it was 
deleted when it finished executing.  testme() got stuck in an infinite loop because s pointed 
to nothing.  

Next I used malloc to create space on the heap for the random string.  This allowed the 
random string to presist after inputString finished executing.  With this implementation 
testme() was able to reach the error.  There was a memory leak, since the random string was
not removed from the heap.

In order to stop the memory leak, I changed s from a char* to a char array and passed it to
inputString().  In inputString() the random string was stored directly into s instead of 
return a pointer to s.

I ran the program ten times and got a average of 11113.5 iterations of the loop before the 
error was reached.  The lowest number of iterations was 155 and the highest was 43413.
*/