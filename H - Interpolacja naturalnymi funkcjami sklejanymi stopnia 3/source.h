//Dawid Urbanik
#include <iostream>
#include <vector>

class spline{

private:
    int n;
    double *X;
    double *Y;
    double *h;
    double *v;
    double *u;
    double *b;
    double *z;
public:

    spline(int n);

    void set_points(const double x[],const double y[]);

    double operator() (double var) const;

    int interval(double var) const;
};