//
//  main.cpp
//  War
//
//  Created by Aichinger,Julie on 2/25/19.
//  Copyright © 2019 Aichinger,Julie. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include "card.hpp"
#include "hand.hpp"
#include "game.hpp"
using std::cout;
using std::endl;

int main() {
    
    cout << "Setting as Ace of Hearts" << endl;
    Card standardCard(Ace, Hearts);
    cout << standardCard << endl;
    
    Joker jokerCardBlack(Black), jokerCardRed(Red);
    cout << "Making a black and red joker." << endl;
    cout << jokerCardBlack.getColor() << "   " << jokerCardRed.getColor() << endl;
    
    PlayingCard cardStandard(kindStandard), cardJoker(kindJoker);
    cout << "This card should be standard: " << cardStandard.getKind() << endl;
    cout << "This card should be a joker: " << cardJoker.getKind() << endl;
    
    return 0;
}
