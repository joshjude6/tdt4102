#include "cannonball.h"
#include "utilities.h"
#include "std_lib_facilities.h"

int randomwithlimits(int lower, int upper){
    int number;
    number = (rand() % (upper-lower+1)) + lower;
    return number;
}