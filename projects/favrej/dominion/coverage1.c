********************************************************************************
* coverage1.c
*
* Jarrad Favre
*
* CS 362
*
* 4-24-2016
********************************************************************************

File 'unittest1.c' - discardCard() Function
Lines executed:85.53% of 76
Branches executed:100.00% of 10
Taken at least once:50.00% of 10
Calls executed:68.75% of 32

   Though I would love to see 100% coverage, I'm content with the 85.53% line coverage that 
I received. I was able to get 100% of braches exected; however, I was only able to get 50%
of the path taken at least once. For someone who has been programming for over a year and
a half now and studying testing material for the first time, I believe these to be decent
results, with obvious room for improvement. There is obviously coverage that I am missing,
and I am perhaps missing some test cases that I should implement to eventually achieve 
100% coverage.


File 'unittest2.c' - updateCoins() Function
Lines executed:87.23% of 47
Branches executed:100.00% of 6
Taken at least once:50.00% of 6
Calls executed:70.00% of 20

   Out of all my test files, this one achieve the most success in all coverage from 87.23% in 
line coverage and 100% in branch. However, I was only able to get 50% path at least once 
coverage for this test. I'm actually very happy with the results with this, as I felt that
this is one of my weakers tests and this was one that I could have added more test cases to.
Implementation for this test did not require much as I wanted to make sure that I could get
a decent combination of scores from only 3 different treasure cards and wanted to make sure
that the math was executing correctly in the function, as well as sure that I invoked the
usage of bonus. Again, I'm obviously missing a few things and will need to examine more
closely what I need to test.  


File 'unittest3.c' - isGameOver() Function
Lines executed:83.33% of 48
Branches executed:100.00% of 8
Taken at least once:50.00% of 8
Calls executed:69.23% of 26

   I was a little disappointed in these results as I thought that this was my best test file,
believing that I had at least covered a great portion of what needed to be tested. Often 
examining my test code and looking over the function code again, I possibly could have added
more supply combinations that would look loop a few times to make sure that we get the correct
boolean value returned. As a consolation to myself, I was able to get 100% branch coverage, 
which gives me encouragement that I am on the right track and will soon improve.


File 'unittest4.c' - scoreFor() Function
Lines executed:85.53% of 76
Branches executed:92.86% of 28
Taken at least once:78.57% of 28
Calls executed:64.29% of 28

   Upon reviewing both the function and my test code, I know that I can possibly accomplish more
coverage by creating more hand, discard pile, and deck combinations with the various cards that
have victory points. Though I did not set out for it to be so, my test case look like that it 
was striving for minimal combinations; yet, my code was still able to find an important bug that
is present in the scoreFor() function.  


File 'cardtest1.c' - Smithy Card
Lines executed:80.39% of 51
Branches executed:100.00% of 10
Taken at least once:50.00% of 10
Calls executed:62.96% of 27

   We're now into the examining the card tests. For the first one, I wrote test cases for Smithy. 
As there is not so much "action" going on with the Smithy card, I felt like that I did a great
job with the test cases I wrote to try to coverage all much as possible, and I believe that my 
80.39% coverage backs that up, especially with my 100% in braches coverage. With that said, there 
is obviously room for improvement, but I believe that my tests for Smithy, unless otherwise
noted, are efficient and well coded. 


Lines executed:70.00% of 90 - Adventurer Card
Branches executed:57.14% of 42
Taken at least once:30.95% of 42
Calls executed:52.50% of 40

  When I saw the results for this test file, my heart sunk a little, as I believe that I did an
efficient job. Out of all my test files, this one returned the worst coverage and was the only
file that did not achive 100% branch coverage, and a lowly 30.95% path of taken at least once.
To say I need to improve this test file is an understatement. An obivous solution to this poor
performance is implement more deck combination for the function to shift through, and add loops
into my tests to test these combinations multiple times. 


Lines executed:79.66% of 59 - Council Room Card
Branches executed:100.00% of 12
Taken at least once:58.33% of 12
Calls executed:64.52% of 31

   I was extremely happen to see that I had achieved 100% branch coverage again and to see that
this is one of two cards were I was able to get more than 50% on path taken at least once. Though
I'm happy that my 79.66% coverage is not as low as what was in my test for the Adventurer card,
I would hesitate to say that I was satisfied with it. I felt that the Council Room would be
very easy to implement test code for, but with my results I'm obviously missing a few things and/or
not getting the total picture of what I need to get accomplished. Once I have fresh eyes, I need
to examine the function code and my code more closely. 


Lines executed:79.66% of 59 - Sea Hag Card
Branches executed:100.00% of 12
Taken at least once:58.33% of 12
Calls executed:64.52% of 31

   This is another test file that I felt would be easy to implement test cases for and would 
return exceptional coverage results. Of all the card test files, this one has the least test
cases and that is perhaps a great starting point for me to examine why I was only to accomplish
79.66% coverage. It is perhaps possible that I was more concerned about trying to expose the 
major bug that I found right away in this function than making sure that I was able to test all 
possible cases and outcomes, which is obviously not a strategy I should be taking as I should
be more worried about the whole function than just a buggy part of it.

File 'dominion.c'
Lines executed:33.21% of 560
Branches executed:40.24% of 415
Taken at least once:29.88% of 415
Calls executed:17.89% of 95

   Above is the total coverage results that is found at end of the test files in the file,
unittestresults.out. The results speak for themselves, but it unfortunately has to be said
that is a lot of work and improvement that needs to be done. Considering that all my 8 test
files average to 81.42% of coverage, which I'm proud of but obviously want to improve on, 
on a small fraction of functions that are implemented in dominion.c, I would argue that I'm
on a great starting track to eventually getting, if not great coverage, than acceptable 
coverage if I were, or will soon, implement testing for a great major of the action cards
and functions present in dominion.c file. Overall, I'm not discouraged by my results; they 
only make me want to strive to be better and learn from what I missed to not only be a
better programmer, but a better tester also.
