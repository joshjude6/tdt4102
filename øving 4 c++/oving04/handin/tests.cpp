#include "tests.h"
#include "std_lib_facilities.h"
#include "utilities.h"

void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0 << " increment: " << increment << " iterations: " << iterations << " result: " << result << endl;
}

void testCallByReference() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, increment, iterations);
    cout << "v0: " << v0 << " increment: " << increment << " iterations: " << iterations << " result: " << v0 << endl;
}

void testString(){
    string grades = randomizeString(6, 'A', 'F');
    cout << "Karakterer: " << grades << endl;
    vector<int> gradeCount(6);
    int sum = 0;
    for (int i = 0; i < 6; i++) {
		gradeCount[i] = countChar(grades, 'A' + i);
		sum += (5 - i) * gradeCount[i];
	}
    double snitt = (static_cast<double>(sum))/6.0;
    cout << "Snitt: " << setprecision(3) << snitt << endl;
    
}