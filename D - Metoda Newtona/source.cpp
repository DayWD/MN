//Dawid Urbanik
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

void printVector(const double *x, unsigned N)
{
    for (unsigned i = 0; i < N; ++i)
        printf("%17.17f ", x[i]);
    printf("\n");
}

typedef void (*FuncPointer)(const double *x, double *y, double *Df);

inline double *Matrix_Inversion_2x2(double a, double b, double c, double d)
{
    double det = (a * d - b * c);
    return new double[4]{d / det, -b / det, -c / det, a / det};
}

int findCurve(FuncPointer f, double *x, unsigned k, double h)
{
    double Df[6];

    for (int i = 1; i <= k; i++)
    {
        double y[2] = {1};
        double next_iteration[3] = {x[0], x[1], x[2] + i * h};
        int go_back = 0;

        while (max(abs(y[0]), abs(y[1])) >= 1e-14)
        {
            f(next_iteration, y, Df);

            if (go_back++ > 15)
                return i;

            double *Dfc = Matrix_Inversion_2x2(Df[0], Df[1], Df[3], Df[4]);
            next_iteration[0] -= Dfc[0] * y[0] + Dfc[1] * y[1];
            next_iteration[1] -= Dfc[2] * y[0] + Dfc[3] * y[1];
            delete[] Dfc;
        }
        printVector(next_iteration, 3);
    }
    return 0;
}

int findSurface(FuncPointer f, double *x, unsigned k1, unsigned k2, double h1, double h2)
{
    double Df[3];

    for (int i = 1; i <= k1; i++)
    {
        for (int j = 1; j <= k2; j++)
        {

            double y = 1;
            double next_iteration[3] = {x[0], x[1] + i * h1, x[2] + j * h2};
            int go_back = 0;

            while (abs(y) >= 1e-14)
            {
                f(next_iteration, &y, Df);

                if (go_back > 30)
                    return i * static_cast<int>(k1) + j;

                next_iteration[0] = next_iteration[0] - (y / Df[0]);
            }
            printVector(next_iteration, 3);
        }
        printf("\n");
    }
    return 0;
}

int findFixedPoints(FuncPointer f, double *x, unsigned k1, unsigned k2, double h1, double h2)
{
    double Df[8];

    for (int i = 1; i <= k1; i++)
    {
        for (int j = 1; j <= k2; j++)
        {
            double y[2] = {1};
            double next_iteration[4] = {x[0], x[1], x[2] + i * h1, x[3] + j * h2};
            int go_back = 0;
            while (max(abs(y[0]), abs(y[1])) >= 1e-14)
            {
                f(next_iteration, y, Df);

                if (go_back > 30)
                    return i * static_cast<int>(k1) + j;

                double *Dfc = Matrix_Inversion_2x2(Df[0] - 1, Df[1], Df[4], Df[5] - 1);
                y[0] -= next_iteration[0];
                y[1] -= next_iteration[1];
                next_iteration[0] -= Dfc[0] * y[0] + Dfc[1] * y[1];
                next_iteration[1] -= Dfc[2] * y[0] + Dfc[3] * y[1];
                delete[] Dfc;
            }
            printVector(next_iteration, 4);
        }
        printf("\n");
    }
    return 0;
}

