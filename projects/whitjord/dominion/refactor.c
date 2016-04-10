/*

# Modifications to dominion

The following cards were refractored into their own functions
* adventurer
* smithy
* village
* great_hall
* steward

## Bugs introduced

### adventurerEffect

`int z = 0;// this is the counter for the temp hand`

... is now ...

`int z = 1;// this is the counter for the temp hand`

### smithyEffect

removed following lines...

```
//discard card from hand
discardCard(handPos, currentPlayer, state, 0);
```
  
### villageEffect

`state->numActions = state->numActions + 2;`

... is now ...

`state->numActions = state->numActions;`

### great_hall

no bug introduced

### stewardEffect

swapped `choice1` and `choice3` inside of function

*/
