//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "tests.h"
#include "std_lib_facilities.h"
#include "utilities.h"
#include "playmastermind.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main

//2e - error kommer av at man inkluderer headerfilen i en annen headerfil

/*
	int a = 10;
	int b = 20;
	swapNumbers(a, b);

	Student josh;
	josh.name = "Josh";
	josh.studyprogram = "MTENERG";
	josh.age = 20;
	printStudent(josh);

    cout << "Testcallbyvalue" << endl;
	testCallByValue();
	cout << "Testcallbyreference" << endl;
	testCallByReference();

	isInProgram(josh, "MTENERG");

	srand(unsigned(time(nullptr)));
	randomizeString1(5,'A','G');
	testString();
	readInputToString(4, 'A', 'H'); 

	srand(time(0));
	testString();

		cout << countChar("abcabcsbdaa", 'a') << endl;
*/


int main()
{
	srand(time(nullptr));
	playmastermind();

	
}

//------------------------------------------------------------------------------
