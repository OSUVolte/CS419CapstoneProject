// Gunnar Martin
// CS362
// Spring 2016
//
// Assignment 4: Random Testing
//
// Test #1: randomtestcard.c
// card: smithy
//
// Note: Change the NBR_OF_TESTS constant in order to run more tests
//		 I left it at 10 for my submission
// 
// For my first random test, I decided to test the `smithy` card.
// I started by creating a main() function, where I initialized the gamestate
// and seed the random number generator. Next, completely randomized the gamestate
// by filling the entire struct with random characters between 0 and 255.
// Then, came the tricky part: "controllably" randomizing key members of the gamestate
// that the function cardEffect (and all dependent functions) will be expecting.
// I made sure that the number of players was 2, 3, or 4. I made sure that
// the current player was not outside the range of possible players.
// I made sure that the deckCount, discardCount, handCount, and playedCardCount
// was not outside of their possible values. I made sure that the handPos was
// within the range of handCount. Now that the gamestate was in a "controlled" random 
// state, I called my new function checkSmithy() from here, passing in the gamestate `post`,
// current player number `player_nbr`, and hand position of the card `handPos`.
//
// Inside checkSmithy(), I started by creating a new gamestate called `pre`. Since
// I passed in `post`, which will be the gamestate to be run through cardEffect, I set `pre`
// to be completely equal to `post`, which I passed in. Later, I will compare `pre` and `post`.
// Next, I ran cardEffect(), passing in `smithy` as the card, `post` as the gamestate and `handPos`
// as the arguments. After running cardEffect(), I asserted the the function did not fail.
// I then set `handCount` for `pre` to be `pre.handCount` + 2, since the handCount should 
// increase by 2 after using smithy. I set `pre.deckCount` to be -3 and `pre.playedCardCount` to
// be +1. My last step in preparing `pre` was to completely copy the card arrays of 
// `post->hand`, `post->deck`, `post->discard`, and `post->playedCards` onto their `pre`
// counterparts. Since the exact cards in these arrays are random, there is no way to predict
// what they will be. Now that `pre` was all prepared, I finally ran my final assert() to compare
// `pre` vs `post` as the final check.
//
// My first few hundred tests went off without a hitch. Then my final assert failed!
// Digging in, I realized that my assumption of deckCount changing by -3 was incorrect.
// When the deck is smaller than 3, a shuffle takes place, in which case the deckCount
// actually increases, by whatever the discardCount was. A shuffle situation also messed with 
// my assumptions of handCount changing by +2 in the case where there wasn't 3 cards in the
// combined discard and deck piles. To fix this, I added an if statement after 
// the cardEffect() that checked for a shuffle situation
// and simply sets `pre` to `post` for `deckCount` and `handCount`. If there is no shuffle,
// my original assumptions were valid.
//
// To help understand when my final assert was failing, I wrote the function compareStates(),
// which takes 2 arguments: `state1` and `state2`, which are pointers to gamestates. This function
// goes through every single member of the gamestate and compares two gamestates to show if and where
// they have differences. This function was super helpful in determining where my test assumptions
// were incorrect.
//
// After fixing the shuffle situation, I ran a couple thousand more tests, before hitting another
// problem on my final assert. This time, I dug and found that the cardEffect() had called
// drawCard() when the handCount was already equal to MAX_HAND. This caused an overflow on the array
// hand, which corrupted the entire gamestate. Combing through the code, I could not find any
// evidence in cardEffect() or drawCard() that made sure this didn't happen. This was a valid bug,
// not just an issue of my test being wrong. So, immediately after cardEffect(), I added a check to
// see if handCount was greater than MAX_HAND. If it was, I printed it out, said the test failed
// and ended the checkSmithy function.
//
// After this adjustment, I ran a tens of thousands of tests with no assertion violations.
// 
// Test #2: randomtestadventurer.c
// card: adventurer
//
// Note: Change the NBR_OF_TESTS constant in order to run more tests
//		 I left it at 10 for my submission
//
// Before breaking down my testing for the adventurer card, I want to point out what
// I believe to be a bug that I found before I even started testing. In the adventurer
// code within cardEffect, there is no call to discard() the adventurer card, like there
// is with every other action card. This caused the card to stay in the hand after being playedCardCount
// and does not cause the playedCard count to increase. Instead of just saying that adventurer
// fails every test, I decided to document it here and in my code and proceed to try to
// catch all the other bugs there could be with adventurer, not related to the lack of discard.
//
// For testing the adventurer card, I took a very similar approach that I used
// when testing the smithy card. I created a main() function, initialized a
// gamestate, seeded the random number, randomized the gamestate, "controllably"
// randomized key members of the gamestate. For this part, I also filled out the
// deck[] member and the discard[] member with valid (but random) card, since
// the adventurer card is looking for certain values of cards that would not happen
// very frequently without some measure of control in instantiation of the cards.
// I created the function checkAdventurer along with a `pre` gamestate and filled
// `pre` with `post` data. After running cardEffect(), I asserted that the function
// did not fail. I then set `pre.handCount` to be +2, since I expect this card to increase
// the handCount by 2. I then copied the card arrays hand, deck, discard, and played from
// the `post` onto `pre`, since we can't predict the randomness of those arrays.
// Finally, I made a final assert to make sure that `pre` equals `post`.
//
// I ran few tests before hitting problems with my final assert. After much research, I made
// a number of findings about bugs in this code. First, if the number of combined treasures
// in the deck and discard piles is 1 or 0, then adventurer within cardEffect() will just keep
// looping until the discard[] array overflows. I put in a check before cardEffect() and 
// output a failure for the too few treasure cards bug. Second, if discard[] is already at its
// MAX_DECK amount, then adventurer within cardEffect() will continue discarding past MAX_DECK
// and overflow discard[]. I put in a check after cardEffect() for discardCount > MAX_DECK and
// output a failure for overflow of discard[]. Third, if hand[] is already at MAX_HAND, there
// is nothing to stop adventurer within cardEffect() to add more cards to the hand, causing
// an overflow of hand[]. I put a check in for this after cardEffect() and output a failure
// of this test case. Finally, there is a case where adventurer can cause discard[] to overflow
// (like the first case), but then get shuffled, so the `post` count of discard[] is valid,
// but the gamestate is still corrupted since it overflowed during the test. So I put in a final
// check to see if the `pre.discardCount` + decrease in deckCount was greater than MAX_DECK.
// 
// After coding to catch all the bugs, I was able to run tens of thousands of tests 
// with no no assertion violations.










































//		//"controllably" fill out deck with valid cards