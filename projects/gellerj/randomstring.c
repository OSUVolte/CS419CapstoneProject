/*
 * In order to produce the error message, the random tester implements two functions to provide the
 * random values needed to trigger the error state. inputChar() returns single chars that are randomly
 * selected from the set of all chars that make up the first part of the error state. These chars are
 * [, {, (, a, x, ), }, ], and the space char. By restricting the set of random chars to only those that
 * can trigger the message in testme(), we make the tester more relevant to the application.
 *
 * In addition to a random char and state integer, testme() only triggers the error message when the
 * string s = "reset". inputStr() produces random null-terminated strings containing 5 characters, all
 * randomly selected from the set of chars r, e, s, and t. Again, we limit the number of characters
 * to choose from so that the tester is more relevant to the application.
 *
 * testme() invokes these functions continuously until the correct combination of random chars and a
 * random string are found, by chance.
 *
 */