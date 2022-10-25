//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "read.h"
#include "tegnstatistikk.h"
#include "emnekatalog.h"
#include "temps.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main

/*
//oppgave 2b:

const map<string, string> capitalsMap {
    {"Norway", "Oslo"},
    {"Sweden", "Stockholm"},
    {"Denmark", "Copenhagen"}
};

string getCapital(const string& country) {
    return capitalsMap.at(country); //feilen ligger i denne linja: return capitalsMap[country]; kan ikke bruke [], bruker .at istedenfor
}

cout << "Capitals:\n";
    for (auto& elem : capitalsMap) {
    cout << getCapital(elem.first) << endl;
*/

/*
CourseCatalog d;
    d.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    d.addCourse("TMA4100", "Matematikk 1");
    d.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    
    d.saveCourse(); */

/*
CourseCatalog d;
    d.loadCourse("courses.txt");
    */

int main()

{
    
    tempStats(readTemps("temperatures.txt"));
    

}
	


//------------------------------------------------------------------------------
