// CS362 - Random Testing Quiz 2
// Joseph Cuellar

/*
inputChar() - randomizes a simple char string that contains one of each character checks in testme() and returns that character.
inputString() - randomly picks a letter from "reset" for each element position of the character string in a loop, and creates a random string that is then returned.

Functions:
char inputChar()
{
  // TODO: rewrite this function
  // Set random characters - limit to only 9 to save time - these are the only ones being checked in testme() anyways
  char randomCharacters[9] = "[](){} ax";
  return randomCharacters[rand() % sizeof(randomCharacters)]; // return random character
}

char *inputString()
{
  // TODO: rewrite this function
  // Vars
  char *randomString = malloc(5);
  char wordToScramble[5] = "reset";

  // Loop the length of the word reset and scramble them 
  int i;
  for(i = 0; i < 5; i++){
    randomString[i] = wordToScramble[rand() % 5];
  }
  randomString[5] = '\0'; // null terminator 

  return randomString;
}

How it finds the error message:
TestMe() Runs in iterations until all states have been met. At which point it checks to see if the random string is "reset"
There are 9 states, and each state represents the successful match of each character type.

The states in C code is below:
if (c == '[' && state == 0) state = 1;
if (c == '(' && state == 1) state = 2;
if (c == '{' && state == 2) state = 3;
if (c == ' '&& state == 3) state = 4;
if (c == 'a' && state == 4) state = 5;
if (c == 'x' && state == 5) state = 6;
if (c == '}' && state == 6) state = 7;
if (c == ')' && state == 7) state = 8;
if (c == ']' && state == 8) state = 9;

Once the program is at state 9, it waits until "reset" has been generated. When that is true, it finally prints out error and exits the program.

An example is below: 
Iteration 717: c =  , s = eeeee, state = 9
Iteration 718: c =  , s = tsees, state = 9
Iteration 719: c = [, s = eerre, state = 9
Iteration 720: c = }, s = eetee, state = 9
Iteration 721: c = ), s = etere, state = 9
Iteration 722: c = {, s = teeee, state = 9
Iteration 723: c = [, s = seste, state = 9
Iteration 724: c =  , s = rstss, state = 9
Iteration 725: c =  , s = resst, state = 9
Iteration 726: c = }, s = tssrt, state = 9
Iteration 727: c = [, s = reset, state = 9
*/
