//Dawid Urbanik
#include <iostream>
#include <cmath>
#include "funkcja.h"

using namespace std;

class FAD {
public:
    double f[6];

    FAD(double a, int is_x) //  true - 1, false - 0,  not necessary - 3,4
    {
        f[0] = a;
        for (int i = 1; i < 6; i++) {
            f[i] = 0;
        }
        if (is_x == 1)
            f[1] = 1;
        else if (is_x == 0)
            f[2] = 1;
    }

};

//!  OVERLOADS BETWEEN OBJECTS

FAD operator+(FAD left, const FAD &right) {
    for (int k = 0; k < 6; k++)
        left.f[k] += right.f[k];
    return left;
}

FAD operator-(FAD left, const FAD &right) {
    for (int k = 0; k < 6; k++)
        left.f[k] -= right.f[k];
    return left;
}

FAD operator*(const FAD &left, const FAD &right) {
    FAD temp(0, 4);
    temp.f[0] = left.f[0] * right.f[0]; //  f
    temp.f[1] = left.f[0] * right.f[1] + left.f[1] * right.f[0]; // fx
    temp.f[2] = left.f[0] * right.f[2] + left.f[2] * right.f[0]; // fy
    temp.f[3] = 2 * left.f[1] * right.f[1] + left.f[3] * right.f[0] + left.f[0] * right.f[3];  //  fxx
    temp.f[4] = left.f[1] * right.f[2] + left.f[2] * right.f[1] + left.f[4] * right.f[0] +
                left.f[0] * right.f[4];    //  fxy
    temp.f[5] = 2 * left.f[2] * right.f[2] + left.f[5] * right.f[0] + left.f[0] * right.f[5];    //  fyy
    return temp;
}

FAD operator/(const FAD &left, const FAD &right) {
    double fraction = (pow(right.f[0], 3));
    FAD temp(0, 4);
    temp.f[0] = left.f[0] / right.f[0];    //  f
    temp.f[1] = (left.f[1] * right.f[0] - left.f[0] * right.f[1]) / pow(right.f[0], 2);    // fx
    temp.f[2] = (left.f[2] * right.f[0] - left.f[0] * right.f[2]) / pow(right.f[0], 2);    // fy
    temp.f[3] = (-right.f[0] * (2 * left.f[1] * right.f[1] + left.f[0] * right.f[3]) + left.f[3] * pow(right.f[0], 2) +
                 2 * left.f[0] * pow(right.f[1], 2)) / fraction;    //  fxx
    temp.f[4] = (-right.f[0] * (left.f[1] * right.f[2] + left.f[2] * right.f[1] + left.f[0] * right.f[4]) +
                 left.f[4] * pow(right.f[0], 2) + 2 * left.f[0] * right.f[2] * right.f[1]) / fraction;    //  fxy
    temp.f[5] = (-right.f[0] * (2 * left.f[2] * right.f[2] + left.f[0] * right.f[5]) +
                 (left.f[5] * pow(right.f[0], 2) + 2 * left.f[0] * pow(right.f[2], 2))) / fraction;    //  fyy
    return temp;
}

//! BETWEEN VALUE AND OBJECT

FAD operator+(FAD left, double value) {

    left.f[0] += value;
    return left;
}

FAD operator+(double value, FAD right) {
    right.f[0] += value;
    return right;
}

FAD operator-(FAD left, double value) {
    left.f[0] -= value;
    return left;
}

FAD operator-(double value, FAD right) {
    FAD left(value,3);
    left = left - right;
    return left;
}

FAD operator*(FAD left, double value) {
    for (int k = 0; k < 6; k++)
        left.f[k] *= value;
    return left;
}

FAD operator*(double value, FAD right) {
    for (int k = 0; k < 6; k++)
        right.f[k] *= value;
    return right;
}

FAD operator/(FAD left, double value) {
    for (int k = 0; k < 6; k++)
        left.f[k] /= value;
    return left;
}

FAD operator/(double value, FAD right) {
    FAD left(value, 3);
    left = left / right;
    return left;
}

//! NEGATION

FAD operator-(FAD left) {
    for (int k = 0; k < 6; k++)
        left.f[k] *= -1;
    return left;
}

//! ELEMENTARY FUNCTIONS

FAD sin(FAD left) {
    FAD temp(0, 4);
    temp.f[0] = sin(left.f[0]);   // f
    temp.f[1] = left.f[1] * cos(left.f[0]);    // fx
    temp.f[2] = left.f[2] * cos(left.f[0]);    // fy
    temp.f[3] = left.f[3] * cos(left.f[0]) - pow(left.f[1], 2) * sin(left.f[0]);    //  fxx
    temp.f[4] = left.f[4] * cos(left.f[0]) - left.f[2] * left.f[1] * sin(left.f[0]);    //  fxy
    temp.f[5] = left.f[5] * cos(left.f[0]) - pow(left.f[2], 2) * sin(left.f[0]);    //  fyy
    return temp;
}

FAD cos(FAD left) {
    FAD temp(0, 4);
    temp.f[0] = cos(left.f[0]);
    temp.f[1] = left.f[1] * (-sin(left.f[0]));    // fx
    temp.f[2] = left.f[2] * (-sin(left.f[0]));    // fy
    temp.f[3] = pow(left.f[1], 2) * (-cos(left.f[0])) - left.f[3] * sin(left.f[0]);    //  fxx
    temp.f[4] = left.f[2] * left.f[1] * (-cos(left.f[0])) - left.f[4] * sin(left.f[0]);     //  fxy
    temp.f[5] = pow(left.f[2], 2) * (-cos(left.f[0])) - left.f[5] * sin(left.f[0]);    //  fyy
    return temp;
}

FAD exp(FAD left) {
    FAD temp(0, 4);
    temp.f[0] = exp(left.f[0]);
    temp.f[1] = exp(left.f[0]) * left.f[1];    // fx
    temp.f[2] = exp(left.f[0]) * left.f[2];    // fy
    temp.f[3] = exp(left.f[0]) * (pow(left.f[1], 2) + left.f[3]);    //  fxx
    temp.f[4] = exp(left.f[0]) * (left.f[2] * left.f[1] + left.f[4]);     //  fxy
    temp.f[5] = exp(left.f[0]) * (pow(left.f[2], 2) + left.f[5]);    //  fyy
    return temp;
}

//! PRINT FUNCTION

void print(const FAD &func) {
    for (int k = 0; k < 6; k++)
        cout << func.f[k] << " ";
    cout << endl;
}


int main() {
    cout.precision(17);
    int M;
    cin >> M;
    double x, y;

    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        FAD X(x, 1);
        FAD Y(y, 0);

        print(funkcja(X, Y));
    }

    return 0;
}