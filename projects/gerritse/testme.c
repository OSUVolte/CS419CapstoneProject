#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
	
	char usableCharacters[] = " qwertyuiopasdfghjklzxcvbnm([{)]}";   //all characters that can be used including a space

	char randomChar = usableCharacters[rand() % 33];    //randomizes the return value 

	return randomChar;
}

char *inputString()
{
	
	char *randomString = malloc(sizeof(char) * 6);  //since it needs to be a 5 characters + null term
	int count = 0;

	randomString[5] = '\0';  //add on the \0 at end of randomString
	while (count != 5){
		char tempC = inputChar();

		//This following section can be ommitted if you truly wanted a random experience. The following statement just removes non-alphabet characters since we are using inputChar to pull in our chars
		while (tempC == '[' || tempC == '{' || tempC == '(' || tempC == ']' || tempC == '}' || tempC == ')'|| tempC == ' '){
			tempC = inputChar();
		}
		randomString[count] = tempC;
		count++; 
	}
	return randomString;
}

void testme()
{
	int tcCount = 0;
	char *s;
	char c;
	int state = 0;
	while (1)
	{
		tcCount++;
		c = inputChar();
		s = inputString();
		printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

		if (c == '[' && state == 0) state = 1;
		if (c == '(' && state == 1) state = 2;
		if (c == '{' && state == 2) state = 3;
		if (c == ' '&& state == 3) state = 4;
		if (c == 'a' && state == 4) state = 5;
		if (c == 'x' && state == 5) state = 6;
		if (c == '}' && state == 6) state = 7;
		if (c == ')' && state == 7) state = 8;
		if (c == ']' && state == 8) state = 9;
		if (s[0] == 'r' && s[1] == 'e'
			&& s[2] == 's' && s[3] == 'e'
			&& s[4] == 't' && s[5] == '\0'
			&& state == 9)
		{
			printf("error ");
			exit(200);
		}
	}
}


int main(int argc, char *argv[])
{
	srand(time(NULL));
	testme();
	return 0;
}
