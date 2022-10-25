#include "utilities.h"
#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
}

void swapNumbers(int& a, int& b) { 
    cout << "A: " << a << " B: " << b << " - før " << endl;
    int temp = a;
    a = b;
    b = temp;
    cout << "A: " << a << " B: " << b << " - etter " << endl;
}

//hvis man vil endre på variablenes verdi burde man vel bruke pass-by-reference siden vi vil at 
//endringen skal gjenspeiles i originalverdien

void printStudent(Student student) {
    cout << "Name: " << student.name << endl;
    cout << "Study program: " << student.studyprogram << endl;
    cout << "Age: " << student.age << endl;
   
}

int isInProgram(Student student, string program) {
    if (student.studyprogram == program) {
        cout << "Studenten går på dette studiet. " << endl;
    } else {
        cout << "Studenten går ikke på dette studiet. " << endl;
    }
    return 0;
}


string randomizeString(int char_amount, char lower, char upper) {
    string output = "";
    for (int i=0; i < char_amount; i++) {
        output += rand() % (upper - lower + 1) + lower;
    }
    return output;
}

string readInputToString(int length, char lower, char upper) {
    lower = tolower(lower);
    upper = tolower(upper);
    string output = "";
    char ch;
    for (int i = 0; i < length; i++) {
        cin >> ch;
        while (tolower(ch) < lower or tolower(ch) > upper) {
            cout << "Trenger ny input." << endl;
            cin >> ch;
        }
        output.push_back(ch);
        }
        cout << output << endl;
        return output;
    }

int countChar(string input, char test) {
    int amount = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == test) amount++;
    }
    return amount;
}

/*  cout << "Strengen kan være: " << length << " karakterer lang. " << endl;
    cout << "Øvre grense: " << upper << endl;
    cout << "Nedre grense: " << lower << endl; */