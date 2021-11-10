#include "hand_calculator.hpp"

int main()
{

  HandCalculator calc = HandCalculator();

  std::vector<Card> hand =
  {
    { CardSuit::CLUBS, CardValue::ACE, false },
    { CardSuit::DIAMONDS, CardValue::KING, false },
    { CardSuit::DIAMONDS, CardValue::JACK, false },
    { CardSuit::SPADES, CardValue::FIVE, true },
    { CardSuit::HEARTS, CardValue::THREE, false },
    { CardSuit::HEARTS, CardValue::THREE, true },
    { CardSuit::SPADES, CardValue::TWO, false }
  };

  Hand myHand;

  calc.calculateHand(hand, myHand);

  switch (myHand.handType)
  {
  case HandType::HIGH_CARD:
    std::cout << "High Card: " << myHand.highCard.value << " of "
              << myHand.highCard.suit << "\n";
    break;
  case HandType::PAIR:
    std::cout << "A pair of " << myHand.highCard.value
              << "s with " << myHand.kicker.value << " kicker.\n";
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
