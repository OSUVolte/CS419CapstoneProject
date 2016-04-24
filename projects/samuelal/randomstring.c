Random Testing Quiz 2
Alex Samuel

I initially implemented inputChar() by generating a random value between 0 and 125 using the built in 
rand() function. This value was then assigned to a char variable and the program would assign the 
character corresponding to the numerical representation of the ASCII code. For example, if the random 
number generated was 97, the 'a' character would be assigned to the char variable. The inputChar() 
function would then return the character generated. But this implementation would take over 1 billion
iterations to print the error message so I modified the inputChar() function further. I created a char 
array with the characters I wanted to randomly generate with the exception of the '\0' character. I then
randomly generated a value between 0 and the max length + 1 of the char array. If the value exceeded the 
length of the array, then the '/0' character was returned by the function. If the random value created was 
smaller than the length of the array, the character at that particular index location was returned by the 
function. 

I implemented the inputString() function by allocating memory for a array of 6 characters and then 
using a for loop to cycle through the character positions. At each character position, the inputChar() 
is called to generate a random character and store it in the array. After 6 iterations, the character 
array of 6 characters is returned.

I executed the program several times and the program took between 481,362 and 5,349,226 iterations to print 
the error message using an inputChar() function that just generates only the 14 characters used to trigger 
the error message ('r','e','s','t','a','x','[','(','{','}',')',']',' ','/0').  When I added two more characters 
that the inputChar() function could generate ('b' and 'c'), the number of iterations increased to between 
4,113,270 and 8,552,750 iterations. I feel this level of coverage of possible characters is adequate because it 
covers all of the characters that are needed to generate the error message as well as some characters that would 
not trigger the error message. In addition, the number of iterations required to trigger the error message and 
end the test is not so large that it would require more computing resources to run in a reasonable time. 