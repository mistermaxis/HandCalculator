#pragma once
#include "card.hpp"

class ICalculator
{
  public:
    ICalculator() {}
    ~ICalculator() {};
    virtual bool calculate(const std::vector<Card> &cards, Hand &h) const = 0;
};

class PairCalculator : public ICalculator
{
  public:
    PairCalculator() {}
    ~PairCalculator() {};
    virtual bool calculate(const std::vector<Card> &cards, Hand &h) const;
};

bool PairCalculator::calculate(const std::vector<Card> &cards, Hand &h) const
{
  h.highCard = *(cards.cbegin());

  for (auto card = cards.cbegin() + 1; card != cards.cend(); card++) {
    if ((*card).value == (*(card - 1)).value) {
      h.handType = HandType::PAIR;
      h.currentCard = (card + 1);
      h.highCard = *(card);
      if (h.kicker.value < (*(card)).value) {
        h.kicker = *(card + 1);
      }
      std::cout << (*(h.currentCard)).value << " of " << (h.currentCard == cards.cend()) << '\n';
      return true;
    }
    else {
      if ((*(card - 1)).value > h.kicker.value) {
        h.kicker = *(card - 1);
      }
    }
  }
  return false;
}