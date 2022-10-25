#include "read.h"
#include "std_lib_facilities.h"

//oppgave 1a
void readWordToFile() {
	string filnavn{"minFil.txt"};
	ofstream file{filnavn}; //ofstream = skrive til fil, her danner vi en ny fil "file" som kan skrives til
	if(!file){ //denne linja betyr at om fila ikke finnes kommer en error
		error("Fil kan ikke åpnes", filnavn);
	}
	cout << "Skriv ønsket input, skriv quit for å stoppe. " << endl;
	for (string input; cin >> input && input != "quit";) {
		file << input << endl;
	}
}

//oppgave 1b
void readLineNumber() {
	string filnavn{"minFil.txt"};
    ifstream inFile{filnavn};
	if(!inFile){
		cerr << "Fil kan ikke åpnes!" << endl;
	} else {
	string line; // danner åpen string variabel for å kunne lese inFile linje for linje
	int lineNumber = 0;
	ofstream newfile{"newfile.txt"}; //danner en ny fil som ting skal skrives til
	while(getline(inFile, line)){
		lineNumber ++;
		cout << lineNumber << " " << line << endl;
		newfile << lineNumber << " " << line << endl; //skriver inn nye verdier til newfile fra inFile
	}
	}
}