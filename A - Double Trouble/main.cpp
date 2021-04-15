//Dawid Urbanik
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {

    int number_of_sets;
    cin>>number_of_sets;

    double x0,x1;
    int n;
    double A,B;

    for(int i=0;i<number_of_sets;i++)
    {
        cin>>x0>>x1>>n;
        int k[n];
        for(int j=0;j<n;j++)
        {
            cin>>k[j];
        }

        A = (7.0*x1-x0)/48.0;
        B = x0 - A;

        for(int j=0;j<n;j++)
        {
            double xn = A*pow(7,k[j]) + B*pow(7,-k[j]);
            printf("%.15e\n",xn);
        }
        cout<<endl;

    }

    return 0;
}