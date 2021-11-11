#pragma once
#include <iostream>
#include <vector>

enum class HandType
{
  HIGH_CARD, PAIR, TWO_PAIRS, TRIPS, STRAIGHT,
  FLUSH, FULL_HOUSE, POKER, STRAIGHT_FLUSH, ROYAL_FLUSH
};

enum class CardSuit
{
  CLUBS,
  DIAMONDS,
  SPADES,
  HEARTS,
  NO_SUIT
};

enum class CardValue
{
  NO_VALUE, TWO, THREE, FOUR, FIVE, SIX, SEVEN,
  EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};

class Card
{
public:
  friend std::ostream& operator <<(std::ostream& o, const CardSuit& cs);
  friend std::ostream& operator <<(std::ostream& o, const CardValue& cv);
  Card(CardSuit &&cs, CardValue &&cv) : suit(cs), value(cv) {}
  Card() : value(CardValue::NO_VALUE), suit(CardSuit::NO_SUIT) {}
  CardSuit suit;
  CardValue value;
};

class Hand
{
public:
  Hand(HandType h = HandType::HIGH_CARD) : handType(h){};
  HandType handType;
  Card highCard;
  Card lowCard;
  Card kicker;
  Card highPocket;
  Card lowPocket;
  std::vector<Card>::const_iterator currentCard;
};

std::ostream& operator <<(std::ostream& o, const CardSuit& cs)
{
  switch (cs)
  {
  case CardSuit::CLUBS:
    o << "Clubs";
    return o;
  case CardSuit::DIAMONDS:
    o << "Diamonds";
    return o;
  case CardSuit::SPADES:
    o << "Spades";
    return o;
  case CardSuit::HEARTS:
    o << "Hearts";
    return o;
  default:
    return o;
  }
}

std::ostream& operator <<(std::ostream& o, const CardValue& cv)
{
  switch (cv)
  {
  case CardValue::ACE:
    o << "Ace";
    return o;
  case CardValue::TWO:
    o << "Two";
    return o;
  case CardValue::THREE:
    o << "Three";
    return o;
  case CardValue::FOUR:
    o << "Four";
    return o;
  case CardValue::FIVE:
    o << "Five";
    return o;
  case CardValue::SIX:
    o << "Six";
    return o;
  case CardValue::SEVEN:
    o << "Seven";
    return o;
  case CardValue::EIGHT:
    o << "Eight";
    return o;
  case CardValue::NINE:
    o << "Nine";
    return o;
  case CardValue::TEN:
    o << "Ten";
    return o;
  case CardValue::JACK:
    o << "Jack";
    return o;
  case CardValue::QUEEN:
    o << "Queen";
    return o;
  case CardValue::KING:
    o << "King";
    return o;
  case CardValue::NO_VALUE:
  default:
    o << "no";
    return o;
  }
}