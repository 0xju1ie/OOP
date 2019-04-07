//
//  card.cpp
//  War
//
//  Created by Aichinger,Julie on 2/25/19.
//  Copyright © 2019 Aichinger,Julie. All rights reserved.
//  Implemented using Dr.Sutton's notes

#include <stdio.h>
#include <iostream>
#include "card.hpp"


ostream& operator<<(ostream& os, Suit s)
{
    switch(s)
    {
        case Diamonds:
            return os << "D";
        case Clubs:
            return os << "C";
        case Hearts:
            return os << "H";
        case Spades:
            return os << "S";
    }
}

ostream& operator<<(ostream& os, Rank r)
{
    switch(r)
    {
        case Ace:
            return os << "A";
        case Two:
            return os << "2";
        case Three:
            return os << "3";
        case Four:
            return os << "4";
        case Five:
            return os << "5";
        case Six:
            return os << "6";
        case Seven:
            return os << "7";
        case Eight:
            return os << "8";
        case Nine:
            return os << "9";
        case Ten:
            return os << "T";
        case Jack:
            return os << "J";
        case Queen:
            return os << "Q";
        case King:
            return os << "K";
    }
}

Kind PlayingCard::getKind() const
{
    return kind;
}


Rank Card::getRank() const
{
    return rank;
}


Suit Card::getSuit() const
{
    return suit;
}


PlayingCard::PlayingCard() { }


Color Joker::getColor() const
{
    return color;
}

ostream& operator<<(ostream& os, Card c)
{
    return os << c.getRank() << c.getSuit();
}

ostream& operator<<(ostream& os, Joker j)
{
    return os << j.getColor();
}

ostream& operator<<(ostream& os, Color c)
{
    if(c == Black)
        return os << "Black Joker";
    else
        return os << "Red Joker";
}

ostream& operator<<(ostream& os, Kind k)
{
    if(k == kindStandard)
        return os << "Standard Card";
    else
        return os << "Joker Card";
}




