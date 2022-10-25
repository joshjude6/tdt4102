#include "cannonball.h"
#include "std_lib_facilities.h"
#include "utilities.h"

//oppgave 1a - akselerasjon oppover
double acclY(){
    return -gravity;
}

//oppgave 1b - fart i y-retning (oppover)
double velY(double initvelocityY, double time){
    return initvelocityY + (acclY() * time);
}

//oppgave 1c - funksjon for posisjon i x og y-retning
// posisjon for x-retning

double posX(float initPosition, float initVelocity, float time){
    return initPosition + (initVelocity * time); // akselerasjon i x-retning er 0
}

//posisjon for y-retning
double posY(float initPosition, float initVelocity, float time){
    return initPosition + (initVelocity * time) + (acclY() * pow(time, 2))/2;
}

//oppgave 1d - print time
void printTime(double time){
    int timer = static_cast<int>(time) / 3600;
    int minutter = (static_cast<int>(time) - 3600 * timer) /60;
    int sekunder = static_cast<int>(time) - timer * 3600 - minutter * 60;
    cout << timer << " timer, " << minutter << "minutter, og " << sekunder << " sekunder." << endl;
}

//oppgave 1e - flyvetid
double flighttime(double initvelocityY) {
    return (-2 * initvelocityY) / acclY();
}

//oppgave 4a - getinputtheta
double getUserInputTheta() {
    double theta;
    cout << "Skriv inn ønsket verdi for theta i grader. " << endl;
    cin >> theta;
    return theta;
}

//oppgave 4a - absoluttfart
double getUserInputAbsVelocity() {
    double absvelocity;
    cout << "Skriv inn ønsket verdi for absoluttfarten. " << endl;
    cin >> absvelocity;
    return absvelocity;
}

//oppgave 4a - degtorad
double degtorad(double deg){
    double rad = deg * (pi/180);
    return rad;
}

//oppgave 4a - fart i vinkler
// Returnerer henholdsvis farten i x-, og y-retning, gitt en vinkel
// theta og en absoluttfart absVelocity.
double getVelocityX(double theta, double absVelocity) {
    double velocityx = absVelocity * cos(degtorad(theta));
    return velocityx;
}

double getVelocityY(double theta, double absVelocity) {
    double velocityY = absVelocity * sin(degtorad(theta));
    return velocityY;
}

//oppgave 4a - dekomponere vektor
vector<double> getVelocityVector(double theta, double absVelocity) {
    vector<double> velocity_vector;
    velocity_vector.push_back(getVelocityX(theta, absVelocity));
    velocity_vector.push_back(getVelocityY(theta, absVelocity));
    return velocity_vector;
}

//oppgave 4b - getdistancetraveled
double getDistanceTraveled(double velocityX, double velocityY) {
    return posX(0, velocityX, flighttime(velocityY)); //initposition = 0, startfart = velocityx, tid = flighttime med velocityy
}

//oppgave 4c - targetpractice
double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    double avvik = distanceToTarget - getDistanceTraveled(velocityX, velocityY);
    return abs(avvik);
}

//oppgave 3b og 3c
void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
	if (abs(compareOperand - toOperand) <= maxError) {
		cout << name << " divergerer ikke fra den maksimale feilverdien i stor grad. " << endl;
	} else {
		cout << name << " divergerer fra den maksimale feilverdien i stor grad. " << endl;
	}
}

//oppgave 5d - playtargetpractice
void playtargetpractice() {
    cout << "Velkommen til Target Practice! Du har ti forsøk. " << endl;
    int avstandblink = randomwithlimits(100, 1000);
    cout << "Blinken for dette forsøket er: " << avstandblink << " meter unna. Lykke til!" << endl;
    for(int i = 1; i < 10; i++) {
        cout << "Dette er forsøk nr. " << i << endl;
        cout << "Oppgi en vinkel i grader: " << endl;
        double vinkel = getUserInputTheta();
        double start_fart = getUserInputAbsVelocity();
        double vel_X = getVelocityX(degtorad(vinkel), start_fart);
        double vel_Y = getVelocityY(degtorad(vinkel), start_fart);
        double flight_time = flighttime(vel_Y);
        double error = {targetPractice(avstandblink, vel_X, vel_Y)};
        double avstandkastet = getDistanceTraveled(vel_X, vel_Y);
        cout << "Flytid: " << flight_time << " sekunder." <<endl;
        cout << "Du kastet: " << avstandkastet << " meter." << endl;
        cout << "Avstand fra blinken: " << error << " meter." << endl;
        if (error < 0) {
            cout << "Du kastet " << abs(error) << " meter for langt. " << endl;
        } else {
            cout << "Du kastet " << abs(error) << " meter for kort. " << endl;
        }

        if (abs(error) < 5) {
            cout << "Gratulerer! Du vant!" << endl;
            return;
        } else {
            cout << "Prøv igjen. " << endl;
        }
        }
        cout << "Det var gode forsøk, men dessverre tapte du. :( " << endl;
    }

    // 784 meter unna : 45 grader og 530 m/s



