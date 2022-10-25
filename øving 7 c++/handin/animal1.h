#pragma once
#include "std_lib_facilities.h"

class Animal{
    protected:
        string name;
        int age;  
    public:
        virtual ~Animal() {};
        virtual void toString();
        Animal(string name, int age) : name{name}, age{age} {};
};

class Cat : public Animal{
    public:
    Cat(string name, int age) : Animal{name, age} {};
    void toString() override;
};

class Dog : public Animal{
    public:
    Dog(string name, int age) : Animal{name, age} {};
    void toString() override;
};

void testAnimal();