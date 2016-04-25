John Fodrocy
Quiz 2 - Random Testing
4/24/2016

The first step was to develop domain knowledge about the program I was working with.
This wasn't very difficult since it is just a few lines of code. It is easy to see that
if a random string of "reset" with a null terminator was produced then the program would crash.

To produce this I simply called rand() to generate the numbers on the ASCII chart. For inputChar(),
I needed to cover quite a lot of characters because it needs to encounter characters both high and low
on the ASCII chart to move to the next state. However, for inputString(), I could only focus on the lower-case alphabet.
This probably saved

My firt attempt was successful in crashing the program on iteration 2,168,510.
My second attempt was successful in crashing the program on iteration 1,2470,997.