## Notes

- Before moving on with checking double pairs, I should take care of the situation with the pair where the kicker gets assigned the highest non-pair card on the hand. It should instead be assigned as follows:

### If the pair is made with the \<TWO\> pocket cards:

- It shouldn't be assigned (it should be assigned the non-value card).

### If the pair is made with \<ONE\> of the pocket cards:

- The kicker should be assigned the other pocket card, only if the other pocket card is within the top five cards of the hand. Otherwise it shouldn't be assigned.

### If the pair is made with \<NO\> pocket cards:

- It should be assigned the highest of the two pocket cards, only if the high pocket card is within the top five cards of the hand. Otherwise it shouldn't be assigned.

### If the pocket cards are pushed to outside the top 5 cards in the hand:

- The hand will have to be setup as it would stand if no other hands are present down the line. Otherwise, if the pair is made with table cards and is at the bottom of the seven card hands when those cards get push to the top they might push the pocket cards out of the top 5 card hand invalidating the assigned kicker.

For example: if the hand is Ace, King, Jack, Seven(p), Five(p), Three, Three and the cards marked with (p) are the pocket cards, in the current state, the Seven would be assigned to the kicker as it at the moment is in the top 5 cards.

However, after rearranging the cards to set the actual hand, it would look like this:

Three, Three, Ace, King, Jack and the Seven (and Five) would be pushed out not being part of the hand anymore.

I'm thinking of adding a 5 card container to the hand where I can set up the actual hand and against which I can compare the pocket hands to make sure that is their final position.