#pragma once
#include "CardDeck.h"




class Blackjack {
    private:
        CardDeck deck;
        vector<Card> playerHand;
        vector<Card> dealerHand;
        int playerHandSum;
        int dealerHandSum;
    public:
        Blackjack();
        void playGame();
        int getPlayerScore();
        int getDealerScore();
        bool askPlayerDrawCard();
        void drawPlayerCard();
        void drawDealerCard();

    
};