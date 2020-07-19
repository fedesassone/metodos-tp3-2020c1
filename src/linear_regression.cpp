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
    // Calculo B
    Vector means_X = X.colwise().mean();
    Vector means_Y = Y.colwise().mean();

    X.rowwise() -= means_X.transpose();
    Y.rowwise() -= means_Y.transpose();

    Matrix XtX = X.transpose()*X;
    Matrix XtY = X.transpose()*Y;

    //y1 = b1*x1 + b2*x2 + b3*x3 + ... + bn*xn
    this->coefficients = XtX.fullPivLu().solve(XtY);

    cout << "B" << endl << this->coefficients << endl;
}

Matrix LinearRegression::predict(Matrix X)  {
    cout << "B" << endl << this->coefficients << endl;

    return X*this->coefficients;
}
