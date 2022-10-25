#pragma once
#include "std_lib_facilities.h"

enum class Suit {clubs, diamonds, hearts, spades};
enum class Rank {two=2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

string suitToString(Suit s);
string rankToString(Rank r);

const map<Rank, int> blackjack_val {
	{Rank::two, 2},
	{Rank::three, 3},
	{Rank::four, 4},
	{Rank::five, 5},
	{Rank::six, 6},
	{Rank::seven, 7},
	{Rank::eight, 8},
	{Rank::nine, 9},
	{Rank::ten, 10},
	{Rank::jack, 10},
	{Rank::queen, 10},
	{Rank::king, 10},
	{Rank::ace, 11}
    
    };



//1e - symboler kommer ikke til å kunne endre seg ved et uhell, og er lettere å se i koden generelt

class Card {
    private:
        Suit s;
        Rank r;
    public:
        Card(Suit suit, Rank rank) :s(suit), r(rank) {};
        Suit getSuit();
        Rank getRank();
        string toString();
        bool isAce();
        int getCardValue();
};