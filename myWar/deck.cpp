#include "deck.hpp"
#include <random>
#include <ctime>


int CreateRandom::generator() (int max)
{
    srand(static_cast<unsigned int>(time(NULL)));

    int num = rand();
    return (num % max);
}

Deck::Deck()
{
    int i = 0;
    for(int s = Hearts; s<= Spades; s++)
    {
        for(int v = Ace; v <= King; v++)
        {
            arrayOfCards[i].setValue;
            arrayOfCards[i].setSuite;
            i++;
        }
    }
}

Card Deck::getRandomCard()
{
    if(deckNotEmpty())
    {
        return arrayOfCards[--cardAmt];
    }
    else
    {
        Card defaultCard(Card::Hearts, 1);
        return defaultCard;
    }
    
}