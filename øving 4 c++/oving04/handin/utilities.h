#pragma once
#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes);

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);

void swapNumbers(int& a, int& b);

struct Student{
    string name;
    string studyprogram;
    int age;
};

void printStudent(Student student);

int isInProgram(Student student, string parameter);

string randomizeString(int char_amount, char lower, char upper);

string readInputToString(int length, char lower, char upper);

int countChar(string input, char test);
