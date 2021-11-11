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
  h.highCard = *(cards.cbegin());
  for (auto card = cards.cbegin() + 1; card != cards.cend(); card++) {
    if ((*card).value == (*(card - 1)).value) {
      h.handType = HandType::PAIR;
      h.currentCard = (card + 1);
      h.highCard = *(card);

      if (h.highPocket.value != h.lowPocket.value) {
       if (h.highPocket.value == h.highCard.value) {
         h.kicker.value = h.lowPocket.value;
       }
       if (h.lowPocket.value == h.highCard.value) {
         h.kicker.value = h.highPocket.value;
       }
       else {
         h.kicker.value = h.highPocket.value;
       }
      }
      return;
    }
  }
  h.kicker = h.highPocket;
  return;
}