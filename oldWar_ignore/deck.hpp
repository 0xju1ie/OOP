#pragma once
#include "card.hpp"

#include <array>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <random>
using namespace std;

class CreateRandom
{
    public:
        int generator() (int);
  
} randomNumber;

class Deck
{
    public:
        Deck(); 
        bool deckNotEmpty(){return (cardAmt > 0);} //want true for the most time
        Card getRandomCard();
        void shuffle()
        {
            std::random_shuffle(&arrayOfCards[0], &arrayOfCards[52], randomNumber);
        } 

    private:
        int cardAmt;
        Card arrayOfCards[52];

};