In an effor to randomize the card tests I changed the number of players to be a random number rather than only 2.
I also changed the seed to be a random number, rather than a set seed. The actual number of tests that are run
have been randomized, which should create more randomized values as new values are picked for the randomized
variables with each run. deckCount, discardCount, and handCount were randomized for each player. All
of these changes have been applied to randomTestCard.c and randomTestAdventurer.c

The result of these random tests is that coverage is now 100% for statement coverage.
With regard to the branch option, coverage is 100% for lines executed, 100% for branches executed,
and 77.78% for taken at least once.