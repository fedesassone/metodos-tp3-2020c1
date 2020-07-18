#pragma once

#include "types.h"

class LinearRegression {
public:
    LinearRegression(int n);

    void fit(Matrix X, Matrix y);

    Matrix predict(Matrix X);
private:
    Vector coefficients;
};
