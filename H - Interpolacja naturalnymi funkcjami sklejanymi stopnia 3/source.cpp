//Dawid Urbanik

#include <cmath>
#include "source.h"

spline::spline(int n)
{
    this->n = n;
}

int spline::interval(double var) const
{
    int i = n-1;
    for (; var < X[i]; i--)
    {
        if(i==0)
            break;
    }
    return i;
}

void spline::set_points(const double x[], const double y[])
{
    X = new double[n];
    Y = new double[n];
    h = new double[n];
    v = new double[n];
    u = new double[n];
    b = new double[n];
    z = new double[n];

    for (int i = 0; i < n; i++)
    {
        X[i] = x[i];
        Y[i] = y[i];
    }
    //Algo
    for (int i = 0; i < n - 1; i++)
    {
        h[i] = X[i + 1] - X[i];
        b[i] = 6 * (Y[i + 1] - Y[i]) / h[i];
    }

    u[1] = 2 * (h[0] + h[1]);
    v[1] = b[1] - b[0];

    for (int i = 2; i < n - 1; i++)
    {
        u[i] = 2 * (h[i - 1] + h[i]) - (h[i - 1] * h[i - 1]) / u[i - 1];
        v[i] = b[i] - b[i - 1] - (h[i - 1] * v[i - 1]) / u[i - 1];
    }
    z[n - 1] = 0;

    for (int i = n - 2; i > 0; i--)
    {
        z[i] = (v[i] - h[i] * z[i + 1]) / u[i];
    }
    z[0] = 0;
}

double spline::operator()(double var) const
{
    int i = interval(var);

    double S = (z[i] / (6 * h[i])) * pow(X[i + 1] - var, 3)
                + (z[i + 1] / (6 * h[i])) * pow(var - X[i], 3)
                + (Y[i + 1] / h[i] - (z[i + 1] * h[i]) / 6) * (var - X[i])
                + (Y[i] / h[i] - (z[i] * h[i]) / 6) * (X[i + 1] - var);

    return S;
}
