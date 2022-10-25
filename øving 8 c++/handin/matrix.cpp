#include "matrix.h"
#include <iostream>
#include <string>

Matrix::Matrix(int nRows, int nColumns) : row{nRows}, col{nColumns} {
    assert(nRows > 0 && nColumns > 0); 
    matrix = new double* [nRows]; //lager en double-array med valgt antall rader
    for (int i = 0; i < nRows; i++){
        matrix[i] = new double[nColumns]; //i hvert element i den forrige arrayen legges det til en array 
        for (int j = 0; j < nColumns; j++){
            matrix[i][j] = 0; //setter alle elementene lik null
        }
    }
}; //nullmatrise

Matrix::Matrix(int nRows){
    assert(nRows > 0);
    for (int i = 0; i < nRows; i++){
        matrix[i][i] = 1;
    }
};

Matrix:: ~Matrix(){
    for(int i = 0; i < row; i++) {
        delete[] matrix[i]; //sletter hver kolonne
    }
    delete[] matrix; //frigjør minnet
};

double Matrix::get(int row, int col) const{
    return matrix[row-1][col-1];
};

void Matrix::set(int row, int col, double value){
    matrix[row-1][col-1] = value;
};

int Matrix::getRows() const{
    return row;
}

int Matrix::getColumns() const{
    return col;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for(int i = 0; i < matrix.getRows(); i++){
        for(int j = 0; j < matrix.getColumns(); j++){
            os << matrix.matrix[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
};


Matrix::Matrix(const Matrix &rhs) : row{rhs.row}, col{rhs.col}, matrix{nullptr} {
    assert(row > 0 && col > 0); 
    matrix = new double* [row]; 
    for (int i = 0; i < row; i++){
        matrix[i] = new double[col]; 
        for (int j = 0; j < col; j++){
            matrix[i][j] = rhs.matrix[i][j]; 
        }
    }
};


Matrix &Matrix::operator=(Matrix rhs){
        std::swap(this->row, rhs.row);
        std::swap(this->col, rhs.col);
        std::swap(this->matrix, rhs.matrix);
        return *this;
};

Matrix &Matrix::operator+=(Matrix rhs){
    assert(row > 0 && col > 0); 
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
            matrix[i][j] = matrix[i][j]+rhs.matrix[i][j]; 
        }
    }
};


