//
//  card.hpp
//  War
//
//  Created by Aichinger,Julie.
//  Copyright © 2019 Aichinger,Julie. All rights reserved.
//  Implemented using Dr.Sutton's notes

#ifndef card_h
#define card_h
#pragma once
#include <deque>
#include <iosfwd>
#include <assert.h>
using std::ostream;

enum Suit{
    Spades,
    Clubs,
    Diamonds,
    Hearts,
};

enum Rank{
    Ace,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
};

enum Color{
  Red,
  Black,
};

enum Kind{
    kindStandard,
    kindJoker,
};

class PlayingCard
{
    Kind kind;
    
public:
    PlayingCard();
    PlayingCard(Kind k) : kind(k) { }
    Kind getKind() const;
};

class Card:PlayingCard{
public:
    Card(Rank r=Ace, Suit s=Spades):rank(r),suit(s){}
    
    Rank getRank() const;
    Suit getSuit() const;
private:
    Rank rank;
    Suit suit;
};

class Joker : PlayingCard{
    Color color;
public:
    Joker(Color c): color(c){}
    Color getColor() const;
};

ostream& operator<<(ostream& os, Suit s);
ostream& operator<<(ostream& os, Rank r);
ostream& operator<<(ostream& os, Card c);
ostream& operator<<(ostream& os, Joker j);
ostream& operator<<(ostream& os, Color c);
ostream& operator<<(ostream& os, Kind k);
ostream& operator<<(ostream& os, PlayingCard c);

#endif /* card_h */
