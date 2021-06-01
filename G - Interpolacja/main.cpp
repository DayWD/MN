//Dawid Urbanik
#include <iostream>

using namespace std;

long int fact(int n){

    return (n==0) || (n==1) ? 1 : n* fact(n-1);
}

int find_derivative(const double x[],const int j, const int i)
{
    int curr=i;
    for(;x[curr]==x[i];curr--){}
    return curr+j+1;
}

double horner(const double d[],const int m,const double x_point,const double x[])
{
    double result = d[m-1];

    for(int i=m-2;i>=0;i--)
        result = result * (x_point - x[i]) + d[i];

    return result;
}

int main()
{
    cout.precision(16);
    int m;
    int n;

    cin>>m>>n;

    double x[m];
    double y[m];
    double t[n];

    for(int i=0;i<m;i++)
    {
        cin>>x[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>y[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>t[i];
    }

    double d[m];

    d[0]=y[0];
    int last_significant_x=0;

    //  Hermite Interpolation

        for(int i=1;i<m;i++)
        {
            if(x[i] == x[i-1])
                d[i]=y[last_significant_x];
            else
            {
                last_significant_x=i;
                d[i]=y[i];
            }
        }

        for(int j=1;j<m;j++)
        {
            for(int i=m-1;i>=j;i--)
            {
                if(x[i]!=x[i-j])
                    d[i]= (d[i]-d[i-1])/(x[i]-x[i-j]);
                else
                    d[i]=y[find_derivative(x,j,i)]/fact(j);
            }
        }
    //  End of Hermite Interpolation

    for(int i=0;i<m;i++)
    {
        cout<<d[i]<<" ";
    }
    cout<<endl;

    double result;
    // Horner method for n choosen points.
    for(int k=0;k<n;k++)
    {
        cout<<horner(d,m,t[k],x)<<" ";
    }

    return 0;
}