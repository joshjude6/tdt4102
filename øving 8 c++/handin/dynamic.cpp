#include "dynamic.h"
#include <iostream>
#include <string>



void fillInFibonacciNumbers(int* result, int length) {
    int null{0};
    int first{1};
    int fib{0};
    for (int i = 0; i < length; i++){
        if (length == 0){
            result[0] = 0; //opprettet en array med lengde 0
        } else {
            fib = null + first;
            null = first;
            first = fib;
            result[i] = fib; //element "i" i arrayen result = fib
        }
    }
}

void printArray(int length){
    int* arr = new int[length];
    fillInFibonacciNumbers(arr, length);
    for(unsigned int i = 0; i < length; i++){
        std::cout << arr[i] << std::endl;
    }
}

void createFibonacci(){
    std::cout << "Hvor mange tall skal genereres?" << std::endl;
    int size;
    std::cin >> size;
    int* array = new int[size]; //allokerer minne til en tabell som heter "array" av størrelse "size"
    fillInFibonacciNumbers(array, size);
    printArray(size);
    delete[] array; //frigjør minnet vi har reservert
}