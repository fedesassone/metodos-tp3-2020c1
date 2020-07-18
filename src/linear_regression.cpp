#include <algorithm>
//#include <chrono>
#include <pybind11/pybind11.h>
#include <iostream>
#include <exception>
#include "linear_regression.h"
#include <iostream>
#include <Eigen/Core>


using namespace std;
namespace py=pybind11;

LinearRegression::LinearRegression(int n){
    this->coefficients = Vector::Zero(n,1); 
}

void LinearRegression::fit(Matrix X, Matrix Y) {
    // Me llegan los metros cuadrados en X y en Y los precios 
    //int row_size_X = X.rows();
	//int col_size_X = X.cols();

    //int row_size_Y = Y.rows();
	//int col_size_Y = Y.cols();

//   cout << "X" << endl << X << endl << "Y =" << Y << endl << endl;
    // Calculo B
    Vector means_X = X.colwise().mean();
    Vector means_Y = Y.colwise().mean();

 //   cout << "X" << endl << means_X << endl << "Y =" << means_Y << endl << endl;
    X.rowwise() -= means_X.transpose();
    Y.rowwise() -= means_Y.transpose();

//    cout << "X" << endl << X << endl << "Y =" << Y << endl << endl;
    Matrix XtX = X.transpose()*X;
    Matrix XtY = X.transpose()*Y;

 //   cout << "X" << endl << XtX << endl << "Y =" << XtY << endl << endl;

    //y1 = b1*x1 + b2*x2 + b3*x3 + ... + bn*xn
    this->coefficients = XtX.fullPivLu().solve(XtY);

    cout << "B" << endl << this->coefficients << endl;
}

Matrix LinearRegression::predict(Matrix X)  {
    cout << "B" << endl << this->coefficients << endl;

    return X*this->coefficients;
}
