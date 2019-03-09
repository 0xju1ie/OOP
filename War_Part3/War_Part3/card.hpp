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

class Joker{
    Color color;
public:
    Joker(Color c): color(c){}
    Color getColor(){ return color;}
};

union PlayingCardData{
    Card standard;
    Joker joker;
    
    PlayingCardData(Rank r, Suit s) : standard(r, s) { }
    PlayingCardData(Color c) : joker(c) { }
};

class PlayingCard
{
    Kind kind;
    PlayingCardData playingCardData;
    
public:
    PlayingCard(Rank r, Suit s) : kind(kindStandard), playingCardData(r, s) { }
    PlayingCard(Color c) : kind(kindJoker), playingCardData(c) { }
    bool isStandard() const { return kind == kindStandard; }
    bool isJoker() const { return kind == kindJoker; }
    //Get function for rank
    Rank getRank() const
    {
        assert(isStandard());
        
        return playingCardData.standard.getRank();
    }
    
    Suit getSuit() const
    {
        assert(isStandard());
        
        return playingCardData.standard.getSuit();
    }
    
    Color getColor()
    {
        assert(isJoker());
        
        return playingCardData.joker.getColor();
    }
    
    Card getStandardCard() const
    {
        assert(isStandard());
        
        return playingCardData.standard;
    }
    
    Joker getJokerCard() const
    {
        assert(isJoker());
        
        return playingCardData.joker;
    }
};


#endif /* card_h */
