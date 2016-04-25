In order to hit the error condition, I implemented the following functions:

inputChar()
	This function produces one of one hundred random characters with ASCII vaules between 31 (unit seperator) and 131 (an a with a carrot on top).
	This is wide range of inputs will generate very random characters
inputString()
	This function produces a string of length 5.
	Each character in the string is one the 26 lower case letter.

This configuration found the input string in 18,440,289 interations.

It finds it by hittng each correct character (c), progressing to the next stage.  Once it hit stage 9, it will run iterations until the string is "reset".
This is the time consuming state to hit since it needs to match all 5 characters in the same order.

I intially attempted to randomize the length of string in inputString to be between 0 and 10 and each character one of the 100 random characters, but after over 1.3 trillion iterations (and 9 hours) it did not hit the error message.
If I had more time and did not need to turn my computer off, I could have kept it running and it would have found the error stage eventually.
