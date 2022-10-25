#include "Card.h"
#include "std_lib_facilities.h"
#include "Blackjack.h"

string suitToString(Suit s){
    switch(s) {
        case Suit::spades: return "Spades";
        case Suit::clubs: return "Clubs";
        case Suit::hearts: return "Hearts";
        case Suit::diamonds: return "Diamonds";
    }
}


string rankToString(Rank r){
    switch(r) {
        case Rank::two: return "Two";
        case Rank::three: return "Three";
        case Rank::four: return "Four";
        case Rank::five: return "Five";
        case Rank::six: return "Six";
        case Rank::seven: return "Seven";
        case Rank::eight: return "Eight";
        case Rank::nine: return "Nine";
        case Rank::ten: return "Ten";
        case Rank::jack: return "Jack";
        case Rank::queen: return "Queen";
        case Rank::king: return "King";
        case Rank::ace: return "Ace";
    }
}


Suit Card::getSuit(){ // Suit på starten er en TYPE, akkurat som string og int osv
    return s;
}

Rank Card::getRank(){
    return r;
}

string Card::toString(){
    return rankToString(r) + " of " + suitToString(s);
}

bool Card::isAce() {
    return r == Rank::ace;
}

int Card::getCardValue() {
    int value = blackjack_val.at(getRank());
    return value;
}
