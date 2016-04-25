/**************
For inputChar(), I simply generated a random number and used modulus 9 to get a number between 0-8, which allowed me to assign each of the nine
characters that are utilized in testme(). This 'random' pool of characters would allow me to test the program much more efficiently than if I had 
included every character possible. 

For inputString(), I made a character array with each of the letters in 'reset', then randomly assigned them to a character string. The sixth element
of the string was set to '/0', which is necessary in testme() to trigger the error message.

In testme(), the while condition keeps running the program until the error message is printed and it's then able to exit. The random generators I wrote 
in inputChar() and inputString() will keep randomly assigning characters and letters to 'c' and 's' declared in testme(), which eventually result in the s
array holding 'reset\0' and the state being 9, where the error message can finally be printed. 
*************/