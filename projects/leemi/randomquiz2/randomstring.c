// The program testme.c prints out an error message under very distinct conditions
// it loops inifinitely until it does this, and only works when char c 
// passes each distinct value that its looking for 9 times before it checks
// string s for a correctness.
//
//
//
// it has a series of if statements, the first 9 if statements check for
// matching with character 'c' and a state number.
// this state number is only incremented when the previous if statement succeeds
// from this we can see that in order to produce the error message we must
// step through each of the if statements. In order, c must be [({ ax})]
// once it goes through each of those then it will check for the string resetwith a null char at the end
//
//
// to create the inputChar i simply took all the values c must eventually
// take one [({ ax})] and put it to a character array. Then I returned a random
// index of that character array depending on a random number.
//
// to created the inputString I did essentially the same thing except I looked at the characters
// within reset instead and came up with 'r','e','s','t' and '\0'
// the values are randomly chosen and stored in an array of the proper length and then returned as a string
// 
// So long as these functions contain all of the possible characters needed to pass the 
// testme function then it will work. For time sake I only included characters within the bounds
// of what I need
//
//
// running this function will repeatedly return random values until each individual test passes
// when the test passes the next test will be up as the state is updated.
// this continues until finally the last test is passed where s[] = reset and state == 9
//
// then the program will output error and exit.
