#include "std_lib_facilities.h"
#include "CardDeck.h"
#include "Card.h"

CardDeck::CardDeck() {
    for (int i = 0; i < 4; i++) { //itererer gjennom kløver, diamant, spar og hjerter
        for (int f = 2; f < 15; f++) { //itererer gjennom to til ess
            Card card{static_cast<Suit>(i), static_cast<Rank>(f)};
            cards.push_back(card);
        }
    }
};

void CardDeck::swap(int a, int b) {
    Card temp = cards[a];
    cards[a] = cards[b];
    cards[b] = temp;
};

void CardDeck::print() {
    for (auto c : cards) {
        cout << c.toString() << endl;
    }
}

void CardDeck::shuffle() {
    for (int i = 0; i < cards.size(); i++) {
        swap(0, rand()%cards.size());
    }
}

Card CardDeck::drawCard() {
    Card last{cards.back()};
    cards.pop_back();
    return last;
}



