//
//  hand.hpp
//  War
//
//  Created by Aichinger,Julie.
//  Copyright © 2019 Aichinger,Julie. All rights reserved.
//

#ifndef hand_hpp
#define hand_hpp

#include <stdio.h>
#include "card.hpp"
#include <vector>

class Hand {
    
public:
    Hand(); //constructor
    static Hand makeDeck(); //makes the full deck
    void shuffle(); //shuffle alllll those cards
    bool isEmpty(); //true if deck is empty
    int size(); //get amount of cards in hand
    void putBottom(Card a); //put card on bottom
    void putTop(Card a); //put card on top
    Card getBottom(); //gets the card at the bottom
    Card getTop(); //gets card at the top
    
private:
    std::vector<Card> cards;
};

#endif /* hand_hpp */
