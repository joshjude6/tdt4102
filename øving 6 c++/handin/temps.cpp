#include "temps.h"
#include "std_lib_facilities.h"



istream& operator>>(istream& is, Temps& t){
    return is >> t.max >> t.min; // den går linje for linje, gjennom linja - verdien lengst til venstre i linja = max
    // verdien lengst til høyre i linja = min, slik det står i selve dokumentet. leser alt fra "is"
}
    
vector <Temps> readTemps(string filename){
    ifstream file{filename};
    vector<Temps> temp;
    if(!file){
        cerr << "Filen kan ikke åpnes. " << endl;
    } else {
        for(Temps t; file >> t;){ // bruker operatoren
            temp.push_back(t); // struct i temps består av en max og min verdi, 
            //så ett element i vektoren inneholder den minste og største temperaturen den dagen
        }
    }
    return temp;
}

void tempStats(vector<Temps> vec){
    float highTemp = 0;
    float lowTemp = 0;
    int highDay = 0;
    int lowDay = 0;
    for (int i = 0; i < vec.size(); i++){
        if (vec.at(i).max > highTemp){ // i hver index i vektoren er det to verdier, t.max og t.min - her velger jeg den største av de to
            highTemp = vec.at(i).max; // om den finner en verdi som er større i neste index vil den automatisk bytte over til den
            highDay = i; //indeksen = dagen
        }
        if (vec.at(i).min < lowTemp){ // i hver index i vektoren er det to verdier, t.max og t.min - her velger jeg den minste av de to
            lowTemp = vec.at(i).min; // om den finner en verdi som er mindre i neste index vil den automatisk bytte over til den
            lowDay = i; //indeksen = dagen
    
    } 
    }
    cout << "Dag nr: " << highDay << " hadde høyest temperatur. Temperaturen var: " << highTemp << endl;
    cout << "Dag nr: " << lowDay << " hadde lavest temperatur. Temperaturen var: " << lowTemp << endl;
}