#include <algorithm>
//#include <chrono>
#include <pybind11/pybind11.h>
#include <iostream>
#include <exception>
#include "linear_regression.h"

using namespace std;
namespace py=pybind11;

LinearRegression::LinearRegression(){}

void LinearRegression::fit(Matrix X, Matrix Y) {
    // Me llegan los metros cuadrados en X y en Y los precios 
    //int row_size_X = X.rows();
	//int col_size_X = X.cols();

    //int row_size_Y = Y.rows();
	//int col_size_Y = Y.cols();


    // Calculo B
    Vector means_X = X.colwise().mean();
    Vector means_Y = Y.colwise().mean();

    X.rowwise() -= means_X.transpose();
    Y.rowwise() -= means_Y.transpose();


    Matrix XtX = X.transpose()*X;
    Matrix XtY = X.transpose()*Y;

    //y1 = b1*x1 + b2*x2 + b3*x3 + ... + bn*xn
    Vector b = XtX.fullPivLu().solve(XtY);
}

Matrix LinearRegression::predict(Matrix X)  {
    return X*b;
}
