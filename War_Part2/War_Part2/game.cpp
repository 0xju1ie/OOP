//
//  game.cpp
//  War
//
//  Created by Aichinger,Julie.
//  Copyright © 2019 Aichinger,Julie. All rights reserved.
//

#include <stdio.h>
#include "card.hpp"
#include "game.hpp"
#include "hand.hpp"
#include <random>
#include <iostream>

int Game::rounds = 0;
int Game::maxRounds = 5000;
Hand Game::player1;
Hand Game::player2;
Hand treasureDeck;

Game::Game() {};

void Game::gameOfWar(){
    std::cout << "Starting a game of war, enjoy!!" << std::endl;
    
    //making the deck
    Hand d = Hand::makeDeck();
    
    //shuffle the deck
    d.shuffle();
    
    player1 = Hand();
    player2 = Hand();
    
    while(!d.isEmpty())
    {
        player1.putBottom(d.getTop());
        player2.putBottom(d.getTop());
    }
    
    while (!player1.isEmpty() && !player2.isEmpty())
    {
        play();
        rounds++;
        if (rounds > maxRounds)
        {
            std::cout << "This game of war is taking forever...this game of war ends in a tie." << std::endl << std::endl;
            break;
        }
    }
    
    if (player1.isEmpty())
    {
        std::cout << "Player 2 wins the game!" << std::endl << std::endl;
    }
    else if (player2.isEmpty())
    {
        std::cout << "Player 1 wins the game!" << std::endl << std::endl;
    }
    
}

void Game::play(){
    Card player1Plays = player1.getTop();
    Card player2Plays = player2.getTop();
    
    std::cout << "Player 1 plays " << "[" << player1.size() << "]: " << player1Plays << std::endl << "Player 2 plays " << "[" << player2.size() << "]: " << player2Plays << std::endl;
    
    if (player1Plays == player2Plays)
    {
        int chickenDinner = war();
        
        while(chickenDinner == 3)
        {
           chickenDinner = war();
        }
        if (chickenDinner == 1)
        {
            player1.putBottom(player1Plays);
            player1.putBottom(player2Plays);
            
            std::cout << std::endl << "Player 1 wins this round!" << std::endl << std::endl;
        }
        else if (chickenDinner == 2)
        {
            player2.putBottom(player1Plays);
            player2.putBottom(player2Plays);
            
            std::cout << std::endl << "Player 2 wins this round!" << std::endl << std::endl;
        }
        
    }
    else if (player1Plays > player2Plays)
    {
        player1.putBottom(player1Plays);
        player1.putBottom(player2Plays);
        std::cout << std::endl << "Player 1 wins this round!" << std::endl << std::endl;
    }
    else if (player2Plays > player1Plays)
    {
        player2.putBottom(player1Plays);
        player2.putBottom(player2Plays);
        std::cout << std::endl << "Player 2 wins this round!" << std::endl << std::endl;
    }

}

int Game::war(){
    Card player1Card, player2Card;
    int chickenDinner = 0;
    
    if(player1.isEmpty())
    {
        std::cout << "Player 1 has no cards left" << std::endl;
        chickenDinner = 2;
        return chickenDinner;
    }
    else if(player2.isEmpty())
    {
        std::cout << "Player 2 has no cards left" << std::endl;
        chickenDinner = 1;
        return chickenDinner;
    }
    
    //war has begun
    std::cout << std::endl << "WAR!!!" << std::endl << std::endl;
    
    for (int i = 0; i < 3; i++)
    {
        //Save one card for the comparison
        if (player1.size() > 1) treasureDeck.putBottom(player1.getTop());
        if (player2.size() > 1) treasureDeck.putBottom(player2.getTop());
    }
    
    //We'll compare the next two cards
    player1Card = player1.getTop();
    player2Card = player2.getTop();
    treasureDeck.putBottom(player1Card);
    treasureDeck.putBottom(player2Card);
    
    std::cout << "Player1 " << "[" << player1.size() << "]: " << player1Card << std::endl << "Player2 " << "[" << player2.size() << "]: " << player2Card << std::endl;

    int treasureDeckSize = treasureDeck.size();
    //double war, treasure deck is 18
    
    //Give the treasure deck to the winner
    if (player1Card > player2Card)
    {
        
        for (int i = 0; i < treasureDeckSize; i++)
            player1.putBottom(treasureDeck.getTop());
        //treasuredeck is 0 now
        chickenDinner = 1;
    }
    else if (player2Card > player1Card)
    {
        for (int i = 0; i < treasureDeckSize; i++)
            player2.putBottom(treasureDeck.getTop());
        //treasuredeck is 0 now
        chickenDinner = 2;
    }
    else if (player2Card == player1Card)
    {
        //treasuredeck is 8 now
        chickenDinner = 3;
    }
    return chickenDinner;
}
