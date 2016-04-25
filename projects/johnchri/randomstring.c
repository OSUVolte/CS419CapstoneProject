/*
    To test the testme() function in testme.c I made the inputChar function generate random characters between the
    space character and the tilda character. This increased the state level very quickly. To make it slightly faster I
    just decreased the range to characters between the space character and the lowercase x. In order for the string to
    randomly generate reset\0 in a amount of time I first tried decreasing the range of characters to characters in the
    range 'e' to 'r', and an added chance for the '\0' character at the end. This still lead to a 1 in 16^5 * 17 chance
    of randomly generating the specific string. I had to keep the last character at '\0' to bring the odds back up to
    about 1 in a million.

*/