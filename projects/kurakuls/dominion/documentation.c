I used this as my main resource:

http://wiki.dominionstrategy.com/index.php/Main_Page

Smithy Card:

    http://wiki.dominionstrategy.com/index.php/Smithy

    Cost: 4 Coins

    Usage: Used during action. This allows you to draw three cards from your deck. 
    The best is when you get coins, that you can use during that turn to purchase other cards. The only thing about the smithy is that you can't also get another action once you've played it. Like you would with marketplace.
    
    Code:
        Smithy invokes the drawCard() function three times and then invokes the discardCard() function.
        
        
Adventurer:
    
    http://wiki.dominionstrategy.com/index.php/Adventurer
    
    Cost: 6 coins
    
    Usage: Another action card. This card forces you to draw until you get two treasure cards.
    Then any of the cards that you drew have to be discarded. This is valuable near
    the end of the game when you know you've got some gold and silver in your deck
    and need to get to them in order to buy some last minute territory to increase
    your ending points. Say there's only one Province left and you know you have enough money for it. It's a bit of a gamble, but what isn't?
    
    Code: 
        Adventurer has a while loop with a terminating condition of less than two treasure cards. If the player has no more cards left in their deck,
        then they can shuffle the discard pile and draw from there. The indexes all get shifted between the deck or the discard deck.
        
        When player has two treasure cards, they then discard all of their tempHand. NOTE. If you reach the end of your deck, then all you get to keep is whatever treasure you had and your entire deck is discarded.

discardCard():

    This throws the card into the discard pile. Usually it's whatever has been played, or selected for discard.
    
    First the card checks if the card is being trashed, meaning permenantly removed from your hand instead of just back into your deck.
    
    Then it checks the hand you have and discards the last card. And reduces the count.
    
updateCoins():

    This code resets the coin count at each turn and then adds the total value of the coins from a players played treasure cards
    and then uses that as a coin count. This allows for a player to buy things with only their coin count and not
    the other players'.
    

    
    