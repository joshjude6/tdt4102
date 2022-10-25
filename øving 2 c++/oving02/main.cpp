//
// This is example code from Chapter 2.2 "The classic first program" of
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
// 
// keep_window_open() added for TDT4102, excercise 0

// This program outputs the message "Hello, World!" to the monitor

#include "std_lib_facilities.h"
#include "Graph.h" 
#include "AnimationWindow.h"

//------------------------------------------------------------------------------'

// C++ programs start by executing the function main

//oppgave 1a - printinteger
void inputandprintinteger() {
	int x = 0;
	cout << "Skriv inn et heltall: " << endl;
	cin >> x;
	cout << "Du skrev: " << x << endl;
}

//oppgave 1b - inputinteger
int inputinteger() {
	int x = 0;
	cout << "Skriv inn et heltall: " << endl;
	cin >> x;
	return x;
}

//oppgave 1c - inputintegersandprintsum
void inputintegersandprintsum() {
	int number1 = inputinteger();
	int number2 = inputinteger();
	int sum = number1 + number2;
	cout << "Summen blir: " << sum << endl;
} 

//oppgave 1d
// Jeg valgte inputinteger siden jeg ville unngå "du skrev", og fordi den må returne tallene for å kunne bruke de i funksjonen til 1c

//oppgave 1e - isOdd
// kan teste med : cout << (isOdd(x) ? "true" : "false");
bool isOdd(int n) {
	if (n % 2 == 0) {
		return true;
	}
	return false;
}

//oppgave 1f - printHumanReadableTime
void printhumanreadabletime(int sec) {
		int min = sec / 60;
		int sec_1 = sec % 60;
		int timer = min / 60;
		int min_1 = min % 60;
		cout << sec << " sekunder tilsvarer: " << timer << " timer,  " << min_1 << " minutter, og " << sec_1 << " sekunder.\n" ;
}

//oppgave 2a - bestemt antall heltall
void antall_h() {
	int n = 0;
	cout << "Skriv inn ønskede antall heltall du vil summere: " << endl;
	cin >> n;
	cout << "-----" << endl;
	int sum = 0;
	int x = 0;
	for(int i = 0; i < n; i++) {
		cin >> x;
		sum += x;
	}
	cout << "Summen blir: " << sum << endl;
}

//oppgave 2b - heltall til null
void heltall_null() {
	int sum = 0;
	int x = 1;
	cout << "Skriv inn heltall du vil summere. Tast 0 for å stoppe. " << endl;
	while (x != 0) {
		cin >> x;
		sum += x;
	}
	sum -= 1;
	cout << "Summen blir: " << sum << endl;
}

//oppgave 2c: siden brukeren ønsker et spesifikt antall iterasjoner vil for-løkken passe best til 2a. for 2b passer
//while best siden brukeren bestemmer selv når de skal stoppe iterasjonene til løkken

//oppgave 2d - inputdouble
double inputdouble() {
	double x = 0;
	cout << "Skriv inn et tall: " << endl;
	cin >> x;
	return x;
}

//oppgave 2e - noktoeuro
void noktoeuro() {
	double nok = -1;
	while (nok < 0) {
		nok = inputdouble();		
	} 
	double eur = nok / 9.75;
	cout << nok << " norske kroner er " << setprecision(2) << fixed << eur << " euro." << endl;
	
}

//oppgave 3b - gangetabell
void gangetabell() {
	cout << "Hvilken bredde skal gangetabellen ha? " << endl;
	int b = inputinteger();
	cout << "Hvilken høyde skal gangetabellen ha? " << endl;
	int h = inputinteger();
	for (int x = 1; x <= h; x++) {
		for (int t = 1; t <= b; t++) {
			cout << setw(4) << x*t;
	}
	cout << endl;
	}
}

//oppgave 4a - discriminant
double disc(double a, double b, double c){
	double discriminant = b*b - 4*a*c;
	return discriminant;
}

void printrealroots(double a, double b, double c) {
	float discriminant = disc(a,b,c);
	if (discriminant < 0) {
		cout << "Funksjonen har ingen reelle røtter. " << endl;
	} else if (discriminant > 0) {
		double x_1 = ((-b + sqrt(discriminant))/(2*a));
		double x_2 = ((-b - sqrt(discriminant))/(2*a));
		cout << "Funksjonen har løsningene: " << "x: " << x_1 << " og" << "x: " << x_2 << endl;
	} else {
		double x_single = -b/(2*a);
		cout << "Funksjonen har den ene løsningen: " << "x: " << x_single << endl;
	}

}

void solvequadraticequation() {
	double a, b, c;
	cout << "Skriv inn tre desimaltall a, b og c: " << endl;
	cin >> a;
	cin >> b;
	cin >> c;
	printrealroots(a, b, c);
}

//oppgave 5a - pytagoras
void pythagoras() {
	using namespace Graph_lib;
	using namespace TDT4102;
	AnimationWindow win{100,100, 1000, 1000, "Pythagoras"}; 

	Point point1{200, 200};
	Point point2{200, 400};
	Point point3{300, 200};

	win.draw_triangle(point1, point2, point3, Color::red);
	// kvadrat på siden 200, 200 - 200, 400
	win.draw_quad(Point{200, 200}, Point{200, 400}, Point{0, 400}, Point{0, 200}, Color::green);
	// kvadrat på siden 300, 200 - 200, 200
	win.draw_quad(Point{200, 200}, Point{300, 200}, Point{300, 100}, Point{200, 100}, Color::blue);
	// kvadrat på siden 200, 400 - 300, 200
	win.draw_quad(Point{200, 400}, Point{300, 200}, Point{500, 300}, Point{400, 500}, Color::yellow);

	win.wait_for_close();

}

//oppgave 6a - calculatebalance
vector<int> calculatebalance(int innskudd, int rente, int år) {
	
	vector<int> totalsaldo {innskudd};
	for(int i = 1; i < år+1; i++) {
		int y_saldo = static_cast<double>(innskudd) * pow(1+(static_cast<double>(rente)/100.00), i); //konverterer til double
		int y_saldo_h = static_cast<int>(y_saldo); //konverterer tilbake til int
		totalsaldo.push_back(y_saldo_h);
	}
	return totalsaldo;
}

//oppgave 6b - printbalance
int printbalance(vector<int> totalsaldo) {
	cout << "År:" << setw(10) << "Saldo: " << endl;
	for (int i = 0; i < totalsaldo.size(); i++) {
		cout << i << setw(10) << totalsaldo.at(i) << endl;
	}
	return 0;
}

//oppgave 6c - glemt å inkludere include<string> øverst. når man skriver << brukes det til å 
// gi et output av en representasjon av vektoren, men cout kan ikke brukes til å skrive ut en vektor direkte

//oppgave 6d - jeg får ingen error, men koden som bruker [slike parenteser] prøver å aksessere tallverdier 
//utenfor det oppgitte intervallet,
//så den kommer til å gi 0 eller noe annet som ikke gir mening for disse verdiene over 10 - derfor det kommer
//en 0 på slutten. koden vet ikke at den må stoppe etter 9


int main() {
	/*cout << "Velg funksjon: " << endl;
	cout << "0) Avslutt" << endl;
	cout << "1) Summer to tall" << endl;
	cout << "2) Summer flere tall" << endl;
	cout << "3) Konverter NOK til EUR" << endl;
	cout << "4) Lag en gangetabell" << endl;
	cout << "5) Løs en andregradslikning" << endl;
	cout << "Angi valg (0-5): " << endl;
	int choice = 1000;
	while (choice !=0) {
		choice = inputinteger();
		switch(choice) {
			case 0: 
				cout << "Programmet avsluttes. " << endl;
				break;
			case 1:
				cout << "Funksjon 1 ble valgt. " << endl;
				inputintegersandprintsum();
				break;
			case 2: 
				cout << "Funksjon 2 ble valgt. " << endl;
				antall_h();
				break;
			case 3: 
				cout << "Funksjon 3 ble valgt. " << endl;
				noktoeuro();
				break;
			case 4:
				cout << "Funksjon 4 ble valgt. " << endl;
				gangetabell();
				break;
			case 5:
				cout << "Funksjon 5 ble valgt. " << endl;
				solvequadraticequation();
				break;
			default:
				break;
	}
	}

	 double disc = discriminant(1, 2, 4);
	cout << disc << endl; */

	/* vector<int> cal = calculatebalance(5000, 3, 2); {
		for (int i = 0; i < cal.size(); i++){
				cout << cal[i] << " ";
	} */
	
	/* printbalance(calculatebalance(5000, 3, 5)); */

	vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
		for (int i = 0; i <= v.size()+10; i++) {
			cout << v[i] << endl;
}
}










//------------------------------------------------------------------------------
