/*
	Rosa Tung
	CS362
	Description: 
		Implement a random tester for the function testme() in testme.c that is capable of printing the error message.  
		You should implement inputChar() and inputString() to produce random values. 
		Write up the development of your random tester and how it finds the error message as randomstring.c. 
*/

/*
	For my inputChar method I knew that I needed it to return '[]' , '()' , '{}' , ' ' , 'a' or 'x' to go through
	all the states. So therefore I set up a char* to the string "[](){} ax" in no particular order and set my random function to
	pick out a random index every time. I returned the character at that index. I saw that in this way it was able to return all
	the characters I needed eventually. 

	For my inpurString method I knew that if I drew from a pile of all letters of the alphabet it would take forever, so what
	I did instead was set up a char[] of a string that had all the letters containing the word 'reset' and then randomizing them
	within the string, and copying over the char[] to a char*. In this way I was given a wide variety of different inputs while 
	still keeping to a good amount of iterations. Given the nature of the way the functions were written and the fact that I needed
	to return my container, I free'd the memory outside of the function. 
	
*/

/****below is example run****/

E:\github\cs362sp16\cs362sp16\projects\tungr\quiz2>g++ testme.c
testme.c: In function 'char inputChar()':
testme.c:9:21: warning: deprecated conversion from string constant to 'char*' [-Wwrite-strings]
  char *characters = "[](){} ax";
                     ^
E:\github\cs362sp16\cs362sp16\projects\tungr\quiz2>ls
a.exe  randomstring.c  testme.c

E:\github\cs362sp16\cs362sp16\projects\tungr\quiz2>a.exe
Iteration 1: c =  , s = eetrs, state = 0
Iteration 2: c = x, s = tseer, state = 0
Iteration 3: c = }, s = seetr, state = 0
Iteration 4: c =  , s = eetrs, state = 0
Iteration 5: c = ], s = erset, state = 0
Iteration 6: c = ), s = seert, state = 0
Iteration 7: c = {, s = eetrs, state = 0
Iteration 8: c = [, s = srete, state = 0
Iteration 9: c = (, s = seetr, state = 1
Iteration 10: c = a, s = seert, state = 2
Iteration 11: c = }, s = esert, state = 2
Iteration 12: c = (, s = ester, state = 2
Iteration 13: c = }, s = seter, state = 2
Iteration 14: c = [, s = seert, state = 2
Iteration 15: c = [, s = erets, state = 2
Iteration 16: c = (, s = reste, state = 2
Iteration 17: c = [, s = sreet, state = 2
Iteration 18: c = }, s = reets, state = 2
Iteration 19: c = [, s = tsere, state = 2
Iteration 20: c = x, s = retes, state = 2
Iteration 21: c = (, s = teser, state = 2
Iteration 22: c = ), s = trsee, state = 2
Iteration 23: c = ), s = eetrs, state = 2
Iteration 24: c =  , s = rseet, state = 2
Iteration 25: c = ), s = rstee, state = 2
Iteration 26: c = {, s = rseet, state = 2
Iteration 27: c = (, s = eetrs, state = 3
Iteration 28: c =  , s = erset, state = 3
Iteration 29: c = {, s = rstee, state = 4
Iteration 30: c = [, s = teers, state = 4
Iteration 31: c = a, s = erset, state = 4
Iteration 32: c = (, s = esert, state = 5
Iteration 33: c = ), s = eetrs, state = 5
Iteration 34: c = ], s = erset, state = 5
Iteration 35: c = }, s = seter, state = 5
Iteration 36: c = ), s = erset, state = 5
Iteration 37: c = ), s = sreet, state = 5
Iteration 38: c = ), s = retes, state = 5
Iteration 39: c = ], s = setre, state = 5
Iteration 40: c = ), s = rseet, state = 5
Iteration 41: c = }, s = reset, state = 5
Iteration 42: c = (, s = reset, state = 5
Iteration 43: c =  , s = trees, state = 5
Iteration 44: c = ), s = reset, state = 5
Iteration 45: c = (, s = seter, state = 5
Iteration 46: c = }, s = esert, state = 5
Iteration 47: c = }, s = rseet, state = 5
Iteration 48: c = x, s = esert, state = 5
Iteration 49: c = {, s = teser, state = 6
Iteration 50: c = (, s = eestr, state = 6
Iteration 51: c = (, s = seter, state = 6
Iteration 52: c = ), s = erset, state = 6
Iteration 53: c = }, s = ester, state = 6
Iteration 54: c = {, s = erets, state = 7
Iteration 55: c = x, s = tsere, state = 7
Iteration 56: c = [, s = sreet, state = 7
Iteration 57: c = (, s = rseet, state = 7
Iteration 58: c = ), s = erets, state = 7
Iteration 59: c = (, s = erets, state = 8
Iteration 60: c =  , s = trsee, state = 8
Iteration 61: c = [, s = rseet, state = 8
Iteration 62: c = ), s = tsere, state = 8
Iteration 63: c =  , s = eetrs, state = 8
Iteration 64: c = [, s = sreet, state = 8
Iteration 65: c = ], s = reets, state = 8
Iteration 66: c = [, s = sreet, state = 9
Iteration 67: c = ), s = eetrs, state = 9
Iteration 68: c =  , s = trees, state = 9
Iteration 69: c = [, s = teser, state = 9
Iteration 70: c = x, s = reste, state = 9
Iteration 71: c = }, s = seetr, state = 9
Iteration 72: c = ), s = erets, state = 9
Iteration 73: c =  , s = tseer, state = 9
Iteration 74: c = }, s = eestr, state = 9
Iteration 75: c = {, s = erets, state = 9
Iteration 76: c =  , s = ester, state = 9
Iteration 77: c = {, s = teser, state = 9
Iteration 78: c = {, s = seter, state = 9
Iteration 79: c = [, s = tseer, state = 9
Iteration 80: c = ], s = rstee, state = 9
Iteration 81: c = [, s = erets, state = 9
Iteration 82: c = }, s = reets, state = 9
Iteration 83: c = }, s = setre, state = 9
Iteration 84: c = a, s = seetr, state = 9
Iteration 85: c = (, s = seter, state = 9
Iteration 86: c = ], s = rstee, state = 9
Iteration 87: c = ), s = teser, state = 9
Iteration 88: c = {, s = retes, state = 9
Iteration 89: c = {, s = rseet, state = 9
Iteration 90: c = (, s = reste, state = 9
Iteration 91: c = {, s = erset, state = 9
Iteration 92: c = x, s = esert, state = 9
Iteration 93: c = x, s = erset, state = 9
Iteration 94: c = a, s = eestr, state = 9
Iteration 95: c = }, s = sreet, state = 9
Iteration 96: c = a, s = reset, state = 9
error