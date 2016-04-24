/* Eric Walters */

/* For the inputChar() function I seeded a random character between ASCII 33
and 126 so that I could combine characters and numbers and include lowercase
so the string 'reset' could potentially be reached */

/* For inputString(), I had the function cycle through 5 times and call
inputChar 5 times to get the string and then I added a null character at 
the end so it could meet the error condition */

/* This test could run for a while in order to find the 'reset' call to
throw the error. Especially when the string is pulling from ASCII 33-126.
I had inputString() return 'reset' to ensure that the error would display and
it did. */