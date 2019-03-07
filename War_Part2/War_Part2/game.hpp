//
//  game.hpp
//  War
//
//  Created by Aichinger,Julie.
//  Copyright © 2019 Aichinger,Julie. All rights reserved.
//

#ifndef game_hpp
#define game_hpp
#include "hand.hpp"
#include "card.hpp"

class Game {
    
private:
    static Hand player1, player2;
    static int rounds;
    static int maxRounds;
    
    Game(); //constructor
    static int war();
    static void play();
    
public:
    static void gameOfWar();
};

#endif /* game_hpp */
