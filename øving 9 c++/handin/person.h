#pragma once
#include "car.h"
#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
        string name;
        string email;
        unique_ptr<Car> car;
    public:
        Person(string n, string e, unique_ptr<Car> c = nullptr) : name{n}, email{e}, car(move(c)) {}   
        string getName();
        string getEmail();
        void setEmail(string newEmail);
        bool hasAvailableSeats() const;
        friend std::ostream& operator<<(std::ostream& os, const Person& person);
};