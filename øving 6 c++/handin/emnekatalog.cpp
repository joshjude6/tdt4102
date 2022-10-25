#include "read.h"
#include "std_lib_facilities.h"
#include "tegnstatistikk.h"
#include "emnekatalog.h"

void CourseCatalog::addCourse(const string& code, const string& alias){
    courses.insert({code, alias});
}

void CourseCatalog::removeCourse(const string& code){
    courses.erase(code);
}

string CourseCatalog::getCourse(const string& code){
    cout << courses.at(code);
    return courses.at(code);
}

void CourseCatalog::saveCourse(){
    string filnavn{"courses.txt"};
    ofstream file{filnavn};
    if(!file){ 
		error("Fil kan ikke åpnes", filnavn);
	} else {
	for (const auto& p : courses){
        file << "Emnekode: " << p.first << " Emnenavn: " << p.second << endl;
	}
	}
}

void CourseCatalog::loadCourse(const string& filename){
    string line;
    ifstream readfile{filename};
    if(!readfile){
        cerr << "Fila kan ikke åpnes. " << endl;
    } else {
        while(getline(readfile, line)){
            cout << line << endl;
        }
    }
}

ostream& operator<<(ostream& os, const CourseCatalog& c){
    for (const auto& p : c.courses){
        os << "Emnekode: " << p.first << " Emnenavn: " << p.second << endl;
    }
    return os;
}