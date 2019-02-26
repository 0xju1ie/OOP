#include "player.hpp"

Card Players::getRandomCard()
{
    lost = randomNumber(3);
    return playersCards[lost];
}

void Players::swap(Deck &deck)
{
    playersCards[lost] = deck.getRandomCard();
}

Players::Players(Deck &deck)
{
    cardCount = 0;
    for(int i = 0; i < 3; ++i)
    {
        playersCards[i] = deck.getRandomCard();
    }
    lost = 0;
}