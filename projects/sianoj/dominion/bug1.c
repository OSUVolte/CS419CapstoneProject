When I ran my tests, I noticed the bugs I expected in the cards that I had modified last time.  Smithy failed it's card count test because I switched it so that it would draw 3 cards instead of 2.  Adventurer failed it's card count test because I made it so that it draws 3 cards instead of 2.  Village failed its action count test because I made it so that only one action happens instead of 2.  Great Council did not fail the tests as the code had not been modified.

My unit tests for the functions didn't uncover any bugs.  

These could have been better if they were designed to cover a broader range of scenarios, possibly incuding random scenarios.    