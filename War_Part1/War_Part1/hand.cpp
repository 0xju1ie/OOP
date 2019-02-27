//
//  hand.cpp
//  War
//
//  Created by Aichinger,Julie on 2/25/19.
//  Copyright © 2019 Aichinger,Julie. All rights reserved.
//

#include "hand.hpp"
#include <ctime>
#include <cstdlib>
#include <random>
#include <algorithm>
#include "hand.hpp"
#include "card.hpp"
#include <iostream>

Hand::Hand() {}

Hand Hand::makeDeck(){
    Hand d;
    
    const int numberOfRanks = 13;
    const int numberOfSuits = 4;
    Rank rank[numberOfRanks] = {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};
    Suit suit[numberOfSuits] = {Spades, Clubs, Diamonds, Hearts};
    
    for(int i = 0; i < numberOfSuits; i++)
    {
        for(int j = 0; j < numberOfRanks; j++)
        {
            d.putBottom(Card(rank[j],suit[i]));
        }
    }
    std::cout << std::endl << "deck size: " << d.size() << std::endl << std::endl;
    return d;
}

bool Hand::isEmpty(){
    bool empty = cards.empty();
    return empty;
}

int Hand::size(){
    int amt = cards.size();
    return amt;
}

void Hand::putBottom(Card a){
    cards.push_back(a);
}

void Hand::putTop(Card a){
    cards.insert(cards.begin(), a);
}

Card Hand::getBottom(){
    Card bottomCard = cards.back();
    cards.erase(cards.end());
    return bottomCard;
}

Card Hand::getTop(){
    Card topCard = cards.front();
    cards.erase(cards.begin());
    return topCard;
}

void Hand::shuffle()
{
    
    srand(time(0) + size());
    for (int i = 0; i < size(); i++)
    {
        int tracker = rand()%size();
        cards.insert(cards.begin() + tracker, cards.at(i));
        cards.erase(cards.begin() + i);
    }
}
