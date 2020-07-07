#include <algorithm>
//#include <chrono>
#include <pybind11/pybind11.h>
#include <iostream>
#include <exception>
#include "linear_regression.h"

using namespace std;
namespace py=pybind11;

LinearRegression::LinearRegression()
{
}

void LinearRegression::fit(Matrix X, Matrix y)
{
    // Me llegan los metros cuadrados en X y en Y los precios 
    int row_size_X = X.rows();
	int col_size_X = X.cols();

    int row_size_Y = Y.rows();
	int col_size_Y = Y.cols();


    // Calculo B
    Vector means_X = X.colwise().mean();
    Vector means_Y = Y.colwise().mean();

    X.rowwise() -= means_X;
    Y.rowwise() -= means_Y;

    Matrix squares = X.pow(2);
    Vector squareSums = squares.colwise().sum();
    double b1_denominator = squareSums[0];


    Matrix multiplicationSums = Y.transpose() * X;
    double b1_nominator = multiplicationSums[0];

    double b1 = b1_nominator/b1_denominator;

}


Matrix LinearRegression::predict(Matrix X)
{
    auto ret = MatrixXd::Zero(X.rows(), 1);

    return ret;
}
