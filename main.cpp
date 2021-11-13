#include "hand_calculator.hpp"

int main()
{

  HandCalculator calc = HandCalculator();

  std::vector<Card> hand =
  {
    { CardSuit::CLUBS, CardValue::ACE },
    { CardSuit::DIAMONDS, CardValue::KING },
    { CardSuit::DIAMONDS, CardValue::JACK },
    { CardSuit::SPADES, CardValue::SEVEN },
    { CardSuit::HEARTS, CardValue::FIVE },
    { CardSuit::CLUBS, CardValue::THREE },
    { CardSuit::SPADES, CardValue::THREE }
  };

  Hand myHand;
  myHand.highPocket = hand[3];
  myHand.lowPocket = hand[4];

  calc.calculateHand(hand, myHand);

  switch (myHand.handType)
  {
  case HandType::HIGH_CARD:
    std::cout << myHand.highCard.value << " high";
    if(myHand.kicker.value != CardValue::NO_VALUE) {
      std:: cout << ", "
      << myHand.kicker.value << " kicker";
    }
    std::cout << "\n";
    break;
  case HandType::PAIR:
    std::cout << "A pair of " << myHand.highCard.value << "s";
    if (myHand.kicker.value != CardValue::NO_VALUE) {
      std::cout << ", " << myHand.kicker.value << " kicker.";
    }
    std::cout << "\n";
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
