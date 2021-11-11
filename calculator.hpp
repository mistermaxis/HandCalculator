#pragma once
#include "card.hpp"

class ICalculator
{
  public:
    ICalculator() {}
    ~ICalculator() {};
    virtual void calculate(const std::vector<Card> &cards, Hand &h) const = 0;
};

class PairCalculator : public ICalculator
{
  public:
    PairCalculator() {}
    ~PairCalculator() {};
    virtual void calculate(const std::vector<Card> &cards, Hand &h) const;
};

void PairCalculator::calculate(const std::vector<Card> &cards, Hand &h) const
{
  for (auto card = cards.cbegin() + 1; card != cards.cend(); card++) {
    if ((*card).value == (*(card - 1)).value) {
      h.handType = HandType::PAIR;
      h.currentCard = (card + 1);
      h.highCard = *(card);
      if (h.pocketLeft.value != h.pocketRight.value) {
       if (h.pocketLeft.value == h.highCard.value) {
         h.kicker.value = h.pocketRight.value;
       }
       if (h.pocketRight.value == h.highCard.value) {
         h.kicker.value = h.pocketLeft.value;
       }
      }
      return;
    }
  }
  return;
}