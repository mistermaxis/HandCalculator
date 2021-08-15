#include <iostream>
#include "HandCalculator.hpp"

int main()
{

  HandCalculator calc = HandCalculator(new PairCalculator(new TwoPairCalculator()));

  std::vector<Card> hand =
  {
    { CardSuit::CLUBS, CardValue::JACK },
    { CardSuit::DIAMONDS, CardValue::NINE },
    { CardSuit::DIAMONDS, CardValue::SEVEN },
    { CardSuit::SPADES, CardValue::FIVE },
    { CardSuit::HEARTS, CardValue::THREE },
    { CardSuit::HEARTS, CardValue::TWO },
    { CardSuit::SPADES, CardValue::TWO }
  };

  Hand myHand;

  myHand.currentCard = hand.cbegin();
  myHand.highCard = hand[0];

  calc.calculateHands(hand, myHand);

  switch (myHand.handType)
  {
  case HandType::HIGH_CARD:
    std::cout << "High Card: " << myHand.highCard.value << " of "
              << myHand.highCard.suit << "\n";
    break;
  case HandType::PAIR:
    std::cout << "A pair of " << myHand.highCard.value
              << "s with a " << myHand.kicker.value << " kicker.\n";
    break;
  case HandType::TWO_PAIRS:
    std::cout << "Two pairs: "
              << myHand.highCard.value << "s and "
              << myHand.lowCard.value << "s"
              << " with a " << myHand.kicker.value << " kicker.\n";
    break;
  }
  return 0;
}
