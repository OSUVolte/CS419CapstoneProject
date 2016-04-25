/*
	Author:		Bryan Serif
	Class:		CS 362
	filename:	randomstring.c
	Date:		04/24/2016
	

	inputChar():
		inputChar was implemented by creating an array of the characters that 
		testMe() is searching for. It then randomly picks one of the
		characters and returns it to testme()

	inputString()
		inputString was implemented by creating a char array containing the
		characters that are used in the check by testMe. It then assigns these
		characters randomly to the s string. After the random assignemnt is done,
		the string is popultaed with the NULL terminator and returned to testMe


	Test results:
	
		Test 1: 1032 iterations
		Test 2: 628 iterations
		Test 3: 711 iterations
		Test 4: 814 iterations
		Test 5: 435 iterations
		Test 6: 692 iterations
		Test 7: 285 iterations
		Test 8: 1904 iterations
		Test 9: 1651 iterations
		Test 10: 319 iterations

		Mean Iterations: 847
		Median Iterations: 701 
*/