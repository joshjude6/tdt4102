//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"
#include "Blackjack.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main
int main()
{
	srand(time(nullptr));
	Blackjack bj;
	bj.playGame();
	
	
}

//------------------------------------------------------------------------------

/* Rank r = Rank::king;
	Suit s = Suit::hearts;
	string suit = suitToString(s);
	string rank = rankToString(r);
	cout << "Rank: " << rank << endl;
	cout << "Suit: " << suit << endl; 
	
	srand(time(nullptr));
	CardDeck stokk; //lager en kortstokk
	stokk.shuffle();
	cout << stokk.drawCard().toString() << endl;
	cout << "Er siste kortet under her?" << endl;
	cout << "----" << endl;
	stokk.print();

	Card c {Suit::spades, Rank::ten};
	cout << c.isAce() << endl;
	cout << c.getCardValue() << endl;

	*/



 


