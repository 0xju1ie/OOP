#ifndef ___CARD_HPP
#define ___CARD_HPP

#include "card.cpp"

// The 'Rank' of a card is the value it represents
enum Value {
    Ace = 1,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
};

// The 'Suit' represents the suit of a card
enum Suit {
    Hearts,
    Diamonds,
    Clubs,
    Spades,
};


class Card
{
    public:
        //Card(Value v, Suit s): value(v), suit(s){}
        void setValue(int v){ value = static_cast<Value>(v); }
	    void setSuite(int s){ suit = static_cast<Suit>(s); }
        

        Value getValue() const{return value;}
        Suit getSuit() const{return suit;}

        static string valueToString(Value v);
        static string suitToString(Suit s);

    private:
        Value value;
        Suit suit;

}; 


#endif