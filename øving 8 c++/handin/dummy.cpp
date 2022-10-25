#include "dummy.h"
using namespace std;

void dummyTest() {
    Dummy a;
    *a.num = 4;
    Dummy b{a};
    Dummy c;
    c = a;
    cout << "a: " << *a.num << '\n';
    cout << "b: " << *b.num << '\n';
    cout << "c: " << *c.num << '\n';

    *b.num = 3;
    *c.num = 5;

    cout << "a: " << *a.num << '\n';
    cout << "b: " << *b.num << '\n';
    cout << "c: " << *c.num << '\n';
}

//oppgave 3a: forventer a: 4, b: 4, c: 4
// og så a: 4, b: 3, c: 5

//oppgave 3b: 
/* a: 4
b: 4
c: 4
a: 5
b: 5
c: 5
*/

//setter b lik 3, men a er 4