//
//  card.cpp
//  War
//
//  Created by Aichinger,Julie.
//  Copyright © 2019 Aichinger,Julie. All rights reserved.
//  Implemented using Dr.Sutton's notes

#include <stdio.h>
#include <iostream>
#include "card.hpp"


std::ostream& operator<<(std::ostream& out, Suit s)
{
    switch(s)
    {
        case Diamonds:
            return out << "D";
        case Clubs:
            return out << "C";
        case Hearts:
            return out << "H";
        case Spades:
            return out << "S";
    }
}

std::ostream& operator<<(std::ostream& out, Rank r)
{
    switch(r)
    {
        case Ace:
            return out << "A";
        case Two:
            return out << "2";
        case Three:
            return out << "3";
        case Four:
            return out << "4";
        case Five:
            return out << "5";
        case Six:
            return out << "6";
        case Seven:
            return out << "7";
        case Eight:
            return out << "8";
        case Nine:
            return out << "9";
        case Ten:
            return out << "T";
        case Jack:
            return out << "J";
        case Queen:
            return out << "Q";
        case King:
            return out << "K";
    }
}

std::ostream& operator<<(std::ostream& out, Card c)
{
    return out << c.getRank() << c.getSuit();
}
