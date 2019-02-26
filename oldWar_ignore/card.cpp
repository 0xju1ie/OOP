#include "card.hpp"

#include <string>

using std::string;

string Card::valueToString(Value v)
{
    switch (v)
    {
        case Ace: return "Ace";
        case Two: return "Two";
        case Three: return "Three";
        case Four: return "Four";
        case Five: return "Five";
        case Six:  return "Six";
        case Seven: return "Seven";
        case Eight: return "Eight";
        case Nine: return "Nine";
        case Ten: return "Ten";
        case Jack: return "Jack";
        case Queen: return "Queen";
        case King: return "King";
        
    }
}

string Card::suitToString(Suit s) {
	switch(s) {
		case Hearts: return "Hearts";
		case Diamonds: return "Diamonds";
		case Clubs: return "Clubs";
		case Spades: return "Spades";
		
	}
}