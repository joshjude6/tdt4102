

#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"



/* //oppgave 4e
bool checkIfDistanceToTargetIsCorrect() {
	double error = targetPractice(100,0,0);
	if(error == 0) return true;
} */

int main() {

	/* cout << "Deviation tests:\n";
	testDeviation(acclY(), -9.81, 0.0001, "AcclY()");

	testDeviation(velY(25.0, 0.0), 25.0, 0.0001, "velY(0.0, 0.0)");
	testDeviation(velY(25.0, 2.5), 0.475, 0.0001, "velY(25.0, 2.5)");
	testDeviation(velY(25.0, 5.0), -24.05, 0.0001, "velY(25.0, 5.0)"); */

	/* srand(unsigned(time(nullptr)));
	for(unsigned int i = 0; i < 10; ++i){
		 cout << randomwithlimits(0, 20) << endl; */
	srand(unsigned(time(nullptr)));
	playtargetpractice();
}



//oppgave 4e - non-void function does not return a value in all control paths
// ingenting forskjellig skjedde når jeg bytta ut parameterne?
