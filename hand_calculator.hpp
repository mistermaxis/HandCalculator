#pragma once
#include "calculator.hpp"

class HandCalculator {
  private:
    std::vector<ICalculator*> calculators;
  public:
    HandCalculator() { calculators.push_back(new PairCalculator()); }
    ~HandCalculator() { for (auto c : calculators) { delete c; } }
    void calculateHand (std::vector<Card>& cards, Hand& hand) const
    {
      for (auto calculator : calculators) {
        calculator->calculate(cards, hand);
      }
    }
};