#include "playmastermind.h"
#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"

int checkCharactersAndPosition(string code, string guess){
    int telle = 0;
    for (int i = 0; i < code.length(); i++) {
        if (code[i] == guess[i]) {
            ++telle;
        }
    }
    return telle;
}

int checkCharacters(string code, string guess) {
    int correct = 0;
    for (char ch: "ABCDEF"){
        correct += min(countChar(guess, ch), countChar(code, ch));
    }
    return correct;
}

void playmastermind(){
    cout << "Velkommen til Mastermind!" << endl;
    constexpr int size = 4;
    constexpr int letters = 6;
    int runde = 0;
    string code = randomizeString(size, 'A', ('A'+(letters-1)));
    cout << code << endl;
    string guess;
    while (guess != code && runde != 6) {
        cout << "Du har: " << (6 - runde) << " forsøk igjen." << endl;
        guess = readInputToString(size, 'A', ('A'+(letters-1)));
        runde++;
        cout << "Du har gjettet: " << checkCharacters(code, guess) << " antall bokstaver riktig." << endl;
        cout << checkCharactersAndPosition(code, guess) << " bokstaver er riktig gjettet og i riktig posisjon. " << endl;
    }

    if (guess == code) {
        cout << "Du knakk koden! Gratulerer! :)" << endl;
    } else {
        cout << "Godt forsøk, men du klarte ikke å knekke koden. Bedre lykke neste gang! "<< endl;
    }

}

