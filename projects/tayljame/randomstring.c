###########
#Author: James Taylor
#Quiz 2
#Date: 10/25/15
#Updated: 4/24/16
#

######
#inputChar()
	Function to produce random numbers for use in testme program. 
	It generates a number within the range of 32-127 to test subset of ascii
	characters as relevant input. 

######
#inputString()
		Function to produce random string for use in testme program.
		It loops through a string to add random letters in each position.
		After loop it adds a null character.
		
Recent successful iteration to "reset": time ranges between 5 mins to 17 mins. The longest taking 12 million
iterations to successfully reach the error condition.

Development of functions:
Original iterations included individual seeds for each function call. Runs through
the program resulted in terrible performance requiring millions of iterations just
to get to a state of 9 and I never was able to get a string to set to reset. I tried 
reducing the amount of inputs available for the random results but still had terrible 
performance. After researching the use of srand and random more thoroughly I came across
serveral posts/articles explaining that a seed for srand should only be called once for
function call. By re-initilizing srand I was worsening the random properties even further
and it was the culprit behind the terrible performance. Also the extensive research on exactly
how random is srand is interesting as well with several generally accepted algorythms being 
deveolped for different needs. Some focusing more distributions of the random results while
try to establish closer to actual random numbers vs. pseudo random numbers. Given the number
of members of my test set, the basic srand(time(NULL)) is considered acceptable. 