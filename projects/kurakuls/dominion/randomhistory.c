By utilizing random testing, I was able to move the percent covered up to 33% of Dominion line code. 

This is a huge improvement because previously I was sticking in the 20% range. I am actually happy that the code
was better covered by random testing.

However, I do know that there are isssues with my code error checking. I really only checked for valid inputs.

I also only really checked for state changes in a few key areas. For example, my Smithy check only verified that 
the hand count changed by adding  more than two cards. Which is the bug that I implemented.

My randomtest adventurer was the same way. The bug I implemented only checked for the change in coin value because the 
bug that I implemented added only one coin instead of two, but still finished anyways. 

So really even though both of these tests did increase coverage with the randomness, the problem is that they aren't
thorough tests by any means because I specifically designed them to only test the bugs that I had implemented.

Nothing really other than me being lazy and having a lot of my plate as an excuse. If I had more time, I would verify
all the state changes of the hand, deck, and discard, especially with the adventurer. With Smithy, I would be more
inclined to check the state changes of the deck and hand.

Overall, I am happy. I think that these tests prove that random testing is a much better approach, but if you have
developer bias where you're only looking for successful input, or in this case, a bug you know exists, then you can EASILY
miss out on a lot of other bugs and that can have disasterous consequences. Not in this particular game for instance,
but in a ton of real world settings. 