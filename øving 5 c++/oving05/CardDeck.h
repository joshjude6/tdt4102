#pragma once
#include "std_lib_facilities.h"
#include "Card.h"

class CardDeck {
    private:
        vector<Card> cards; // en vektor som kan holde Card-objekter
        void swap(int a, int b); // privat medlemsfunksjon som bytter plass på to kort ved å bytte på verdien til indeksen
    public:
        CardDeck(); //konstruktør uten parametere (default-konstruktør)
        void print(); 
        void shuffle();
        Card drawCard();
};