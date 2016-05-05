/*********************************************************************************************
 * Developer: Nick Martin (martinn6)
 * Date: 20160422
 * Project: Quiz 2
 * Description:  description of my testing
 * *******************************************************************************************/
 
 Description:
 
 My target: To make the code hit the error message utizling a 'random' generator. 
 
 Taking a look at the code, I knew I needed to hit a series of exact values for the code to
 hit the error message. Because there were predefined values that would trigger the error, 
 I wanted to put boundaries around my random genetor so that it would focus on only these triggers 
 instead of choosing random characters that would never hit the target. 
 
 I did this because I was trying to concern myself with the efficency of the code. If I just
 had a random character generator without set boundaries, it would take a lot longer 'on average' 
 to hit the error message becauese the more values it generates, the more of a chance it will
 not hit a specific target.
 
 The char generator had different targets then the string did; so for that, I created two differnt
 array values. There were 9 character targets and only 5 string targets. If I would combine them into
 one array, that would be 5 more values that would not hit the character targets and it would also be
 9 more values that would not hit a string target. 
 
 On average, it also took longer to hit a series of characters (the string) then it took just to hit
 one character (a single target). It would take less than 100 itterations to hit 9 single targets where 
 it could take 1000 to 10000 itterations to hit the correct series of targets needed for the string.
