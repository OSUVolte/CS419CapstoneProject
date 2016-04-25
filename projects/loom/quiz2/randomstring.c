//
// Created by Michael Loo on 4/24/16.
//

/*
 * Random String for quiz 2:
 *
 * in testme.c:
 *
 * Input Char:
 * Creates an array of acceptable characters, and then randomly chooses a number and takes on of those variables
 *
 * Input String:
 * First creates a string pointer of a specific length, then follows inputChar by generating an array of "acceptable"
 * values and randomly selects on of those, adding them together
 *
 * testme:
 *
 * The program works by first generating strings and chars, but only checking the char.  If the right char is created,
 * the state advances by one.  After this has occured 9 times, the program then instead starts checking the string, for
 * the correct character array in the correct order.  For me, I have had the program running over 3000000 iterations and
 * it still has not hit the correct string.
 */
