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
    Card(Rank r=Ace, Suit s=Spades): bits((unsigned)s << 4 | (unsigned)r){}
    
    Rank getRank() const { return (Rank) (0b00001111 & bits);}
    Suit getSuit() const { return (Suit) ((0b11110000 & bits) >> 4); }
    //bool operator==(Card c) { return bits == c.bits; }
    //bool operator!=(Card c) { return !(bits == c.bits); }
    friend bool operator<(Card a, Card b) { return a.getRank() < b.getRank(); }
    friend bool operator>(Card a, Card b) { return b.getRank() < a.getRank(); }
    friend bool operator==(Card a, Card b) { return a.getRank() == b.getRank(); }
    friend bool operator!=(Card a, Card b) { return !(a.getRank() == b.getRank()); }
private:
    Rank rank;
    Suit suit;
    unsigned char bits;
};

ostream& operator<<(ostream& os, Suit s);
ostream& operator<<(ostream& os, Rank r);
ostream& operator<<(ostream& os, Card c);

#endif /* card_h */
