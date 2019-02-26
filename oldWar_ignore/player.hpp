#pragma once
#include "deck.hpp"
#include "card.hpp"


class Players
{
    public:
        Players();
        Players(Deck &);
        void swap(Deck &);
        int totalCount() {return cardCount;}
        void addToScore(int increase) {cardCount += increase;}
        Card getRandomCard();

    private:
        int cardCount, lost;
        Card playersCards[3];

}