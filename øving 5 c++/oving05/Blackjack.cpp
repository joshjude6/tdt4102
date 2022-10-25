#include "std_lib_facilities.h"
#include "CardDeck.h"
#include "Card.h"
#include "Blackjack.h"

Blackjack::Blackjack(){
    deck.shuffle();
    drawPlayerCard();
    drawPlayerCard();
    while (dealerHandSum < 17) { //siden dealeren skal kjøre automatisk, er det lurt å ha den i konstruktøren
    drawDealerCard();
    }
}


int Blackjack::getPlayerScore() {
    int score = 0;
    for (int i = 0; i < playerHand.size(); i++) {
        score += playerHand[i].getCardValue();
        if (playerHand[i].isAce()) {
            if (score + 11 <= 21) {
                score += 11;
            } else {
                score += 1;
            }
        }
    }
    return score;
}

int Blackjack::getDealerScore() {
    int score = 0;
    for (int i = 0; i < dealerHand.size(); i++) {
        score += dealerHand[i].getCardValue();
        if (dealerHand[i].isAce()) {
            if (score + 11 <= 21) {
                score += 11;
            } else {
                score += 1;
            }
        }
    }
    return score;
}

bool Blackjack::askPlayerDrawCard() {
    cout << "Vil du ha et nytt kort? (ja/nei)" << endl;
    string svar;
    cin >> svar;
    if (svar == "ja") {
        return true;
    } else {
        return false;
    }
}

void Blackjack::drawPlayerCard() {
    Card c = deck.drawCard();
    if (c.isAce()){
        cout << "Skal ess være 1 eller 11?" << endl;
        int svar;
        cin >> svar;
        playerHandSum += svar;
        playerHand.push_back(c);
        return;
    }
    playerHand.push_back(c);
    playerHandSum = getPlayerScore();
}

void Blackjack::drawDealerCard() {
    dealerHand.push_back(deck.drawCard());
    dealerHandSum = getDealerScore();
}

void Blackjack::playGame() {
    cout << "Velkommen til Blackjack :)" << endl;
    cout << "Player hand: 0" << endl;
    cout << "Dealer sin sum: " << dealerHandSum << endl;
    cout << "Spiller sin sum: " << playerHandSum << endl;
    while(askPlayerDrawCard()){ //mens spiller sier ja
    if (playerHandSum < 21) {
        cout << "Spiller trekker et kort: " << endl;
        drawPlayerCard();
        cout << "Spiller sin sum: " << playerHandSum << endl;
        }
    }

    cout << "Spillers kort: " << endl;
    for (auto c : playerHand) {
        cout << c.toString() << endl;
    }
    

    cout << "Dealers kort: " << endl;
    for (auto c : dealerHand) {
        cout << c.toString() << endl;
    }

    bool win = true;
    if (playerHandSum > 21) {
        win = false; }
    else if (dealerHandSum <= 21 && dealerHandSum >= playerHandSum) {
        cout << "Dealer slo spilleren!" << endl;
        win = false;
    } else {
        cout << "Spiller slo dealer!" << endl;
        win = true;
    } 

    if (win) {
        cout << "Du vant, gratulerer!" << endl;
    } else {
        cout << "Du tapte!" << endl;
    }
    }




 /* while (dealerHandSum < 17) {
        cout << "Dealer trekker et kort: " << endl;
        drawDealerCard();
        cout << "Dealer sin sum: " << dealerHandSum << endl;
    } */
/*
// if(dh <= ph && ph <= 21){
    vinner
} 
*/