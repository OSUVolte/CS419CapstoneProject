/*
	Rosa Tung
	Assignment 2 task 3
*/

//Task 3:  
//Pick five cards implemented in dominion.c (2 must be smithy and adventurer) and siphon their implementation part to their own functions.
//Check in your changes, with appropriate git commit messages and documetn them in a text file called refactor.c
//Your implementation of at least 4 of these 5 cards should be incorrect in some way, i.e., you should introduce subtle bugs that are hard to catch in your changes. 
//Introducing bugs in smithy and adventurer is mandatory.  Write information of your bugs also in refactor.c 

/* * * * * * * * * * * * *
Documentation of Changes:
 * * * * * * * * * * * * */
 
//cards chosen and their function declarations
int playAdventurer(struct gameState *state);
int playSmithy(struct gameState *state, int handPos);
int playVillage(struct gameState *state, int handPos);
int playFeast(struct gameState *state, int choice1);
int playCouncil_Room(struct gameState *state, int handPos);

//Steps I took to make the changes 
	//1. Cut and paste out entire case section of the code into its appropriate function
	//2. Declare appropriate variables needed for the function to run 
	//3. Call the function inside it's case section 
	//4. Add a break after it before the next case section 
	
//subtle bugs I introduced:
	//playAdventurer line 677: commented out break statement 
	//playSmithy line 722: commented out break statement
	//playVillage line 1090: changed counter to + 4
	//playFeast line: left alone
	//playCouncil_Room line 1110: changed != to ==