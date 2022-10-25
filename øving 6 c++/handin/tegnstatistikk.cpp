#include "read.h"
#include "std_lib_facilities.h"
#include "tegnstatistikk.h"

void characterCount() {
    ifstream file;
    file.open("grunnlov.txt");
    map<char, int> chars;
    if(!file){
        cerr << "Finner ikke fil!" << endl;
    } else {
        for (char c = 'a'; c < 'z'; c++) { //itererer gjennom små bokstaver
            chars[c] = 0; //legger til små bokstaver i char i map, og int-verdien til alle blir null
        }
        for (unsigned char c; file >> c;) { //file >> c; betyr at den leser av c i grunnlov.text, unsigned: aldri negativ verdi
            if (isalpha(c)) {
                chars[tolower(c)]++; //adderer 1 i int-verdien til tolower.c-verdien i map
            }
        }
        for (auto c : chars){
            cout << c.first << " : " << c.second << endl;
        }
    }
}