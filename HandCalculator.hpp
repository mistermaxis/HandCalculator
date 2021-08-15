#pragma once
#include <vector>
#include <algorithm>
#include "Card.hpp"

class CalculatorNode
{
private:
    CalculatorNode *left;
    CalculatorNode *right;

public:
    CalculatorNode(CalculatorNode *l = nullptr, CalculatorNode *r = nullptr) : left(l), right(r) {}
    virtual ~CalculatorNode();
    virtual bool calculate(const std::vector<Card> &cards, Hand &h) const = 0;
    bool isLeaf() const { return (left == nullptr && right == nullptr); }
    CalculatorNode *leftNode() const { return left; }
    CalculatorNode *rightNode() const { return right; }
};

CalculatorNode::~CalculatorNode()
{
    if (left != nullptr)
        delete left;
    if (right != nullptr)
        delete right;
}

class PairCalculator : public CalculatorNode
{
public:
    PairCalculator(CalculatorNode *l = nullptr, CalculatorNode *r = nullptr) : CalculatorNode(l, r) {}
    virtual bool calculate(const std::vector<Card> &cards, Hand &h) const;
};

bool PairCalculator::calculate(const std::vector<Card> &cards, Hand &h) const
{
    for (auto i = cards.cbegin(); i < (cards.cend() - 1); i++)
    {
        if ((*i).value == (*(i + 1)).value)
        {
            if (h.handType != HandType::PAIR)
            {
                h.handType = HandType::PAIR;
                h.highCard = *i;
                h.lowCard = *i;
                ++i;
                h.currentCard = (i + 1);
            }
        }
        else
        {
            if ((*i).value >= h.kicker.value)
            {
                h.kicker = *i;
            }
            if (h.handType == HandType::PAIR)
            {
                return true;
            }
        }
    }
    return false;
}

class TwoPairCalculator : public CalculatorNode
{
public:
    TwoPairCalculator(CalculatorNode *l = nullptr, CalculatorNode *r = nullptr) : CalculatorNode(l, r) {}
    virtual bool calculate(const std::vector<Card> &cards, Hand &h) const;
};

bool TwoPairCalculator::calculate(const std::vector<Card> &cards, Hand &h) const
{
    for (auto i = h.currentCard; i < (cards.cend() - 1); i++)
    {
        if ((*i).value == (*(i + 1)).value)
        {
            if ((*i).value == h.kicker.value) {
                h.kicker = { CardSuit::NO_SUIT, CardValue::ACE };
            }
            h.handType = HandType::TWO_PAIRS;
            h.lowCard = *i;
            ++i;
        }
        else
        {
            if ((*i).value >= h.kicker.value)
            {
                h.kicker = *i;
            }
            if (h.handType == HandType::TWO_PAIRS)
            {
                return true;
            }
        }
    }
    return false;
}

class TripsCalculator : public CalculatorNode
{
public:
    TripsCalculator(CalculatorNode *l = nullptr, CalculatorNode *r = nullptr) : CalculatorNode(l, r) {}
    virtual bool calculate(const std::vector<Card> &cards, Hand &h) const;
};

bool TripsCalculator::calculate(const std::vector<Card> &cards, Hand &h) const
{
    return true;
}

class HandCalculator
{
private:
    CalculatorNode *start;
    CalculatorNode *current;

public:
    HandCalculator(CalculatorNode *s = nullptr) : start(s), current(start) {}
    ~HandCalculator()
    {
        if (start != nullptr)
        {
            delete start;
        }
    }
    void calculateHands(const std::vector<Card> &c, Hand &h);
};

void HandCalculator::calculateHands(const std::vector<Card> &c, Hand &h)
{
    while (true)
    {
        if (current->calculate(c, h) == true)
        {
            if (current->leftNode() != nullptr)
            {
                current = current->leftNode();
            }
            else
            {
                return;
            }
        }
        else
        {
            if (current->rightNode() != nullptr)
            {
                current = current->rightNode();
            }
            else
            {
                return;
            }
        }
    }
}