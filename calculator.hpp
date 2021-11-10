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
      Card pocketCards[2];

      for (auto pocket_card = cards.begin(); pocket_card != cards.end(); pocket_card++) {
        if ((*(pocket_card)).isPocketCard) {
          pocketCards[0] = *pocket_card;
          auto next_card = pocket_card + 1;
          pocketCards[1] = *next_card;
          break;
        }
      }
      std::cout 
        << pocketCards[0].value << " of " << pocketCards[0].suit << '\n'
        << pocketCards[1].value << " of " << pocketCards[1].suit << '\n';
      return;
    }
  }
  return;
}