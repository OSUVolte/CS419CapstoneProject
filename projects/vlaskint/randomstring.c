tatyana vlaskin
i looked at the void testme() function and notices what letters need to be generated to
produce error message.
inputChar() needs to generate [,(, {,' ',a, x, },),]
inputString() needs to generate the null terminated string: 'reset\0'
After that I've used google to find out how to generate random character and random string
I came accross the following resources:
    //http://stackoverflow.com/questions/19724346/generate-random-characters-in-c
    and
    //http://codereview.stackexchange.com/questions/29198/random-string-generator-in-c

After that, I've added essential character [ those that we need to get to receive to get the error]
char randomletter = "abcdefghijklmnopqrstuvwxyz[]() {}"[random () % 34];
and
static char charset[] = "abcdefghijklmnopqrstuvwxyz\0";
for inputChar() when the correct character in the testme() function is encountered, we just move to the nextafter
line of the code
as for the inputString(), I just have a for loop for 6 character, the ternimation character is /0, which is the same thing
as null


