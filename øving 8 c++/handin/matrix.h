#pragma once
#include <iostream>
#include <string>

class Matrix {
    public:
        int row; //M
        int col; //N
        double** matrix; //dynamisk allokert minne i konstruktøren til Matrix
        Matrix(int nRows, int nColumns); //skal lage nullmatrisen
        explicit Matrix(int nRows); //skal lage identitetsmatrisen (1 på diagonalen)
        ~Matrix(); //destruktør
        double get(int row, int col) const;
        void set(int row, int col, double value);
        int getRows() const;
        int getColumns() const;
        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
        Matrix& operator=(Matrix rhs);
        Matrix& operator+=(Matrix rhs);
        Matrix(const Matrix & rhs);
        
};

/*
Matrix(const Matrix & rhs) : row{rhs.row}, col{rhs.row} {};
        Matrix& operator=(Matrix rhs);
*/