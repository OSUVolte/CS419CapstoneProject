Peter Murphy
randomstring.c

I sort of used a white box form of testing to figure out the quiz. I first noticed the different char combinations to get to state 9. I first implemented a random char for all possible chars on the ascii chart in inputChar(). The system beep overwhelmed my windows/code blocks home system so I increased the amount to only include typically printable characters. 
For inputString() I initialize a cstring with all lower case letters. During my whitebox look I noticed that the string needed to be all lower case. Mod 26 to fill an empty cstring and hardcoding the null character at the end of the string. 
I would have been possible to random the string length and fill with completely random chars, however the more randomness adds more chances for it to never match the reset\0 string. I believe both approaches to be valid

Eventually inputString comes up with the correct string the error message is displayed. 
