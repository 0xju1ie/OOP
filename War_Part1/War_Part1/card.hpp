//
//  card.hpp
//  War
//
//  Created by Aichinger,Julie on 2/25/19.
//  Copyright © 2019 Aichinger,Julie. All rights reserved.
//  Implemented using Dr.Sutton's notes

#ifndef card_h
#define card_h
#pragma once
#include <deque>
#include <iosfwd>
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

class Card {
public:
    Card(Rank r=Ace, Suit s=Spades):rank(r),suit(s){}
    
    Rank getRank() const { return rank;}
    Suit getSuit() const { return suit; }
private:
    Rank rank;
    Suit suit;
};

ostream& operator<<(ostream& os, Suit s);
ostream& operator<<(ostream& os, Rank r);
ostream& operator<<(ostream& os, Card c);

#endif /* card_h */
