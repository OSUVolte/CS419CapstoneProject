/*
 *
 * Quiz 2:
 *
 * C characters are represented as integers on the ASCII scale. Knowing this I assigned a random character between
 * "Space" (ASCII 32) and 255. I did this by the following line of code. This test was easy.
	c = (random() % 95) + 32;
 *
 *
 * For the string test I kept all letters as a string of 5. I had to modify the code on the testme.c document because
 * it would create a memory leak if I didn't (malloc was required to send a string back to main).
 *
 * I created a random lower-case string of 5 letters using 			string[len] = (random() % 26) + 'a';
 * after I malloced a string.
 *
 * Once I had generated a 5 letter string I sent it back to main to be tested. This is where I had to modify main
 * to free the memory of the string.
 *
 * These two functions satisfy the requirement for a random tester. The first one creates a random character.
 * The second one creates a random lower-case 5 letter string.
 * */
