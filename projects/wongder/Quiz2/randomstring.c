// Derek Wong
// CS362
// Random Testing Quiz 2

inputChar()
In this function I created a char array. My char array holds "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz(){}[] ". I included A-Z uppercase and lowercase including the special characters that testme() was looking for. Then I used a random generator to generate a number between 0 and length of my array. This number is used as an index to what character I am going to return. The more characters I include the more iteration it will take to find correct character and vice versa.

inputString()
I created a char array and gave it the space of char * 6; It is char * 6 because I need to put 6 char elements in this array. The if statement in testme() is looking for a string called "reset". This contains 5 elements but we also have to include the null character because it is looking for a null-termianted string which makes it 6 elements. I used a for loop to randomly generate a string calling my inputChar() function. Each loop will add a character onto my string and the for loop, loops 5 times. Once the for loop ends I add the null character at the end of my string. After my char array gets populated it returns a string.

When inputChar() is called it will return a random character. This random character will be used in a 9 if statement in testme(). inputChar() is being called inside a while loop so it will keep generating a random character until the loop breaks. Once it generates a match, the state will increase by 1. When the state equals to 9 there is another if statement that looks for a null-termianted string, "reset". The inputString() is also inside the same while loop and it will keep on generating 5 character strings until it matches reset. Once it generates the string reset it will hit the print statement which prints out "error" and exits the program. State became 9 really fast because it was only comparing a single character. It took a lot of iterations to get the string "reset" because my character pool was very long ("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz(){}[] ").
