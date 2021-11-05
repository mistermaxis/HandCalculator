#include "hand_calculator.hpp"

int main()
{

  HandCalculator calc = HandCalculator();

  std::vector<Card> hand =
  {
    { CardSuit::CLUBS, CardValue::KING },
    { CardSuit::DIAMONDS, CardValue::KING },
    // { CardSuit::DIAMONDS, CardValue::JACK },
    // { CardSuit::SPADES, CardValue::FIVE },
    // { CardSuit::HEARTS, CardValue::THREE },
    // { CardSuit::HEARTS, CardValue::THREE },
    // { CardSuit::SPADES, CardValue::ACE }
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
