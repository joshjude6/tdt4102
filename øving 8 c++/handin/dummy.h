#pragma once
#include <iostream>
#include <string>

class Dummy {
public:
    int *num;
    Dummy() {
        num = new int{0};
    }
    Dummy(const Dummy &rhs) : Dummy{} {
        this->num = new int{};
        *num = *rhs.num;
    }
    Dummy& operator=(Dummy rhs){
        std::swap(num, rhs.num);
        return *this;
    }
    ~Dummy() {
        delete num;
    }
};

void dummyTest();
